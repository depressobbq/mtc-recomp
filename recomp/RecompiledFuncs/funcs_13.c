#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80040EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040EC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80040EC8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80040ECC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80040ED0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80040ED4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80040ED8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80040EDC: beq         $v0, $zero, L_80041094
    if (ctx->r2 == 0) {
        // 0x80040EE0: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80041094;
    }
    // 0x80040EE0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80040EE4: lbu         $a3, 0x1($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X1);
    // 0x80040EE8: bne         $a3, $zero, L_80041018
    if (ctx->r7 != 0) {
        // 0x80040EEC: nop
    
            goto L_80041018;
    }
    // 0x80040EEC: nop

    // 0x80040EF0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80040EF4: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80040EF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040EFC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80040F00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80040F04: lw          $v0, -0x6ECC($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6ECC);
    // 0x80040F08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040F0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040F10: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80040F14: addiu       $v0, $v0, 0x152
    ctx->r2 = ADD32(ctx->r2, 0X152);
    // 0x80040F18: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80040F1C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80040F20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80040F24: lw          $v1, -0x6EC8($at)
    ctx->r3 = MEM_W(ctx->r1, -0X6EC8);
    // 0x80040F28: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80040F2C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80040F30: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80040F34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80040F38: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x80040F3C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80040F40: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x80040F44: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80040F48: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80040F4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80040F50: beq         $v1, $v0, L_80041014
    if (ctx->r3 == ctx->r2) {
        // 0x80040F54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80041014;
    }
    // 0x80040F54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040F58: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80040F5C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80040F60: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80040F64: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80040F68: slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80040F6C: beq         $v0, $zero, L_80040FB4
    if (ctx->r2 == 0) {
        // 0x80040F70: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80040FB4;
    }
    // 0x80040F70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80040F74: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80040F78: addiu       $t0, $t0, -0x6E34
    ctx->r8 = ADD32(ctx->r8, -0X6E34);
    // 0x80040F7C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80040F80: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_80040F84:
    // 0x80040F84: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80040F88: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80040F8C: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80040F90: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80040F94: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80040F98: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80040F9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80040FA0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80040FA4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80040FA8: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80040FAC: bne         $v0, $zero, L_80040F84
    if (ctx->r2 != 0) {
        // 0x80040FB0: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_80040F84;
    }
    // 0x80040FB0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
L_80040FB4:
    // 0x80040FB4: sll         $v1, $a2, 24
    ctx->r3 = S32(ctx->r6 << 24);
    // 0x80040FB8: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80040FBC: sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3 << 7);
    // 0x80040FC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040FC4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80040FC8: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x80040FCC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80040FD0: addiu       $v1, $v1, 0x3A40
    ctx->r3 = ADD32(ctx->r3, 0X3A40);
    // 0x80040FD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040FD8: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80040FDC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80040FE0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80040FE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80040FE8: lb          $v0, -0x6F10($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X6F10);
    // 0x80040FEC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80040FF0: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x80040FF4: lb          $a2, -0x6F0F($a2)
    ctx->r6 = MEM_B(ctx->r6, -0X6F0F);
    // 0x80040FF8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80040FFC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80041000: lb          $a1, 0x70EC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70EC);
    // 0x80041004: jal         0x80053254
    // 0x80041008: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_80053254(rdram, ctx);
        goto after_0;
    // 0x80041008: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_0:
    // 0x8004100C: j           L_80041018
    // 0x80041010: nop

        goto L_80041018;
    // 0x80041010: nop

L_80041014:
    // 0x80041014: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80041018:
    // 0x80041018: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8004101C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80041020: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041024: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041028: lw          $v0, -0x6ECC($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6ECC);
    // 0x8004102C: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80041030: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80041034: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041038: beq         $v0, $zero, L_80041044
    if (ctx->r2 == 0) {
        // 0x8004103C: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_80041044;
    }
    // 0x8004103C: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x80041040: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_80041044:
    // 0x80041044: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
    // 0x80041048: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004104C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80041050: bne         $v0, $v1, L_8004108C
    if (ctx->r2 != ctx->r3) {
        // 0x80041054: nop
    
            goto L_8004108C;
    }
    // 0x80041054: nop

    // 0x80041058: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8004105C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80041060: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041064: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80041068: lb          $v1, -0x6F10($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X6F10);
    // 0x8004106C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80041070: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80041074: lb          $a2, -0x6F0F($a2)
    ctx->r6 = MEM_B(ctx->r6, -0X6F0F);
    // 0x80041078: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8004107C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80041080: lb          $a1, 0x70EC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70EC);
    // 0x80041084: jal         0x80053234
    // 0x80041088: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_80053234(rdram, ctx);
        goto after_1;
    // 0x80041088: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_1:
L_8004108C:
    // 0x8004108C: jal         0x80051C7C
    // 0x80041090: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_80051C7C(rdram, ctx);
        goto after_2;
    // 0x80041090: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_2:
L_80041094:
    // 0x80041094: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80041098: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8004109C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800410A0: jr          $ra
    // 0x800410A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800410A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800410A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800410A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800410AC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x800410B0: sra         $a2, $a0, 24
    ctx->r6 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800410B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800410B8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800410BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800410C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800410C4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800410C8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800410CC: lb          $v0, -0x6EE8($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X6EE8);
    // 0x800410D0: blez        $v0, L_80041134
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800410D4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80041134;
    }
    // 0x800410D4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800410D8: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x800410DC: addiu       $s2, $s2, -0x7A70
    ctx->r18 = ADD32(ctx->r18, -0X7A70);
    // 0x800410E0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800410E4: sll         $a1, $s0, 24
    ctx->r5 = S32(ctx->r16 << 24);
L_800410E8:
    // 0x800410E8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800410EC: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x800410F0: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800410F4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800410F8: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800410FC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80041100: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80041104: jal         0x80040EC4
    // 0x80041108: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80040EC4(rdram, ctx);
        goto after_0;
    // 0x80041108: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8004110C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80041110: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80041114: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041118: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x8004111C: lb          $v1, -0x6EE8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X6EE8);
    // 0x80041120: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80041124: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041128: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004112C: bne         $v0, $zero, L_800410E8
    if (ctx->r2 != 0) {
        // 0x80041130: sll         $a1, $s0, 24
        ctx->r5 = S32(ctx->r16 << 24);
            goto L_800410E8;
    }
    // 0x80041130: sll         $a1, $s0, 24
    ctx->r5 = S32(ctx->r16 << 24);
L_80041134:
    // 0x80041134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041138: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004113C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80041140: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041144: jr          $ra
    // 0x80041148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004114C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004114C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80041150: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041154: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80041158: sb          $a0, 0x17($sp)
    MEM_B(0X17, ctx->r29) = ctx->r4;
    // 0x8004115C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80041160: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x80041164: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80041168: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004116C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80041170: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80041174: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80041178: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004117C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80041180: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80041184: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041188: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x8004118C: addu        $s4, $s4, $a0
    ctx->r20 = ADD32(ctx->r20, ctx->r4);
    // 0x80041190: lw          $s4, -0x7100($s4)
    ctx->r20 = MEM_W(ctx->r20, -0X7100);
    // 0x80041194: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80041198: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004119C: addu        $a2, $s4, $v1
    ctx->r6 = ADD32(ctx->r20, ctx->r3);
    // 0x800411A0: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x800411A4: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x800411A8: addu        $s3, $s3, $a0
    ctx->r19 = ADD32(ctx->r19, ctx->r4);
    // 0x800411AC: lw          $s3, -0x6F20($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X6F20);
    // 0x800411B0: blez        $v0, L_80041274
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800411B4: addu        $s6, $a1, $zero
        ctx->r22 = ADD32(ctx->r5, 0);
            goto L_80041274;
    }
    // 0x800411B4: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800411B8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800411BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800411C0: sll         $fp, $v0, 1
    ctx->r30 = S32(ctx->r2 << 1);
    // 0x800411C4: lui         $s5, 0x801E
    ctx->r21 = S32(0X801E << 16);
    // 0x800411C8: addiu       $s5, $s5, -0x78D0
    ctx->r21 = ADD32(ctx->r21, -0X78D0);
    // 0x800411CC: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x800411D0: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_800411D4:
    // 0x800411D4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800411D8: addu        $v0, $fp, $v0
    ctx->r2 = ADD32(ctx->r30, ctx->r2);
    // 0x800411DC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800411E0: lb          $v1, 0x1($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1);
    // 0x800411E4: slti        $v0, $v1, 0x16
    ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // 0x800411E8: bne         $v0, $zero, L_80041258
    if (ctx->r2 != 0) {
        // 0x800411EC: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_80041258;
    }
    // 0x800411EC: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800411F0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800411F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800411F8: lb          $v0, -0x72B2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X72B2);
    // 0x800411FC: blez        $v0, L_80041254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80041200: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80041254;
    }
    // 0x80041200: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80041204: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x80041208: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004120C:
    // 0x8004120C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041210: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80041214: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80041218: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8004121C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80041220: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80041224: jal         0x8003FCD4
    // 0x80041228: addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    func_8003FCD4(rdram, ctx);
        goto after_0;
    // 0x80041228: addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    after_0:
    // 0x8004122C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80041230: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80041234: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041238: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8004123C: lb          $v1, -0x72B2($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X72B2);
    // 0x80041240: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80041244: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041248: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004124C: bne         $v0, $zero, L_8004120C
    if (ctx->r2 != 0) {
        // 0x80041250: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004120C;
    }
    // 0x80041250: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_80041254:
    // 0x80041254: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_80041258:
    // 0x80041258: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8004125C: lb          $v1, 0x0($s7)
    ctx->r3 = MEM_B(ctx->r23, 0X0);
    // 0x80041260: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80041264: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041268: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004126C: bne         $v0, $zero, L_800411D4
    if (ctx->r2 != 0) {
        // 0x80041270: sll         $v0, $s1, 24
        ctx->r2 = S32(ctx->r17 << 24);
            goto L_800411D4;
    }
    // 0x80041270: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_80041274:
    // 0x80041274: sll         $a0, $s6, 24
    ctx->r4 = S32(ctx->r22 << 24);
    // 0x80041278: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004127C: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x80041280: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80041284: blez        $v0, L_80041338
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80041288: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80041338;
    }
    // 0x80041288: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004128C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80041290: addiu       $s0, $s0, -0x7A70
    ctx->r16 = ADD32(ctx->r16, -0X7A70);
    // 0x80041294: sra         $v1, $a0, 24
    ctx->r3 = S32(SIGNED(ctx->r4) >> 24);
L_80041298:
    // 0x80041298: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
    // 0x8004129C: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800412A0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800412A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800412A8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800412AC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800412B0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800412B4: lb          $v0, 0x1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1);
    // 0x800412B8: slti        $v0, $v0, 0x16
    ctx->r2 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x800412BC: beq         $v0, $zero, L_80041310
    if (ctx->r2 == 0) {
        // 0x800412C0: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_80041310;
    }
    // 0x800412C0: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800412C4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800412C8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800412CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800412D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800412D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800412D8: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800412DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800412E0: beq         $v0, $zero, L_80041310
    if (ctx->r2 == 0) {
        // 0x800412E4: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_80041310;
    }
    // 0x800412E4: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800412E8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800412EC: beq         $v0, $zero, L_80041304
    if (ctx->r2 == 0) {
        // 0x800412F0: nop
    
            goto L_80041304;
    }
    // 0x800412F0: nop

    // 0x800412F4: jal         0x800359CC
    // 0x800412F8: nop

    func_800359CC(rdram, ctx);
        goto after_1;
    // 0x800412F8: nop

    after_1:
    // 0x800412FC: j           L_80041310
    // 0x80041300: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
        goto L_80041310;
    // 0x80041300: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_80041304:
    // 0x80041304: jal         0x800356BC
    // 0x80041308: nop

    func_800356BC(rdram, ctx);
        goto after_2;
    // 0x80041308: nop

    after_2:
    // 0x8004130C: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_80041310:
    // 0x80041310: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80041314: sll         $a0, $s6, 24
    ctx->r4 = S32(ctx->r22 << 24);
    // 0x80041318: sra         $v1, $a0, 24
    ctx->r3 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004131C: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x80041320: lb          $v1, 0x0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X0);
    // 0x80041324: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80041328: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004132C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041330: bne         $v0, $zero, L_80041298
    if (ctx->r2 != 0) {
        // 0x80041334: sra         $v1, $a0, 24
        ctx->r3 = S32(SIGNED(ctx->r4) >> 24);
            goto L_80041298;
    }
    // 0x80041334: sra         $v1, $a0, 24
    ctx->r3 = S32(SIGNED(ctx->r4) >> 24);
L_80041338:
    // 0x80041338: sll         $v0, $s6, 24
    ctx->r2 = S32(ctx->r22 << 24);
    // 0x8004133C: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041340: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80041344: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041348: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x8004134C: addu        $v0, $a0, $s3
    ctx->r2 = ADD32(ctx->r4, ctx->r19);
    // 0x80041350: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80041354: beq         $v0, $zero, L_800413D4
    if (ctx->r2 == 0) {
        // 0x80041358: addu        $v1, $s4, $v1
        ctx->r3 = ADD32(ctx->r20, ctx->r3);
            goto L_800413D4;
    }
    // 0x80041358: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8004135C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80041360: blez        $v0, L_800413D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80041364: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800413D4;
    }
    // 0x80041364: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80041368: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8004136C: lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // 0x80041370: addiu       $s4, $s4, -0x79A0
    ctx->r20 = ADD32(ctx->r20, -0X79A0);
    // 0x80041374: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x80041378: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_8004137C:
    // 0x8004137C: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041380: addu        $v0, $s2, $a1
    ctx->r2 = ADD32(ctx->r18, ctx->r5);
    // 0x80041384: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80041388: lb          $v0, 0x1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1);
    // 0x8004138C: slti        $v0, $v0, 0x16
    ctx->r2 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x80041390: beq         $v0, $zero, L_800413B8
    if (ctx->r2 == 0) {
        // 0x80041394: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_800413B8;
    }
    // 0x80041394: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x80041398: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8004139C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800413A0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800413A4: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800413A8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800413AC: jal         0x8003FBBC
    // 0x800413B0: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    func_8003FBBC(rdram, ctx);
        goto after_3;
    // 0x800413B0: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    after_3:
    // 0x800413B4: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_800413B8:
    // 0x800413B8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800413BC: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800413C0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800413C4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800413C8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800413CC: bne         $v0, $zero, L_8004137C
    if (ctx->r2 != 0) {
        // 0x800413D0: sll         $v0, $s1, 24
        ctx->r2 = S32(ctx->r17 << 24);
            goto L_8004137C;
    }
    // 0x800413D0: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_800413D4:
    // 0x800413D4: lbu         $a3, 0x17($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X17);
    // 0x800413D8: sll         $v1, $s6, 24
    ctx->r3 = S32(ctx->r22 << 24);
    // 0x800413DC: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800413E0: sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7 << 24);
    // 0x800413E4: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800413E8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800413EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800413F0: lw          $a0, -0x774C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X774C);
    // 0x800413F4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800413F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800413FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80041400: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80041404: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80041408: blez        $v0, L_80041460
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004140C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80041460;
    }
    // 0x8004140C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80041410: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x80041414: addiu       $s2, $s2, -0x7764
    ctx->r18 = ADD32(ctx->r18, -0X7764);
    // 0x80041418: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x8004141C: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_80041420:
    // 0x80041420: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041424: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80041428: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004142C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80041430: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80041434: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80041438: jal         0x8003F804
    // 0x8004143C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    func_8003F804(rdram, ctx);
        goto after_4;
    // 0x8004143C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_4:
    // 0x80041440: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x80041444: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80041448: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004144C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80041450: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80041454: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80041458: bne         $v0, $zero, L_80041420
    if (ctx->r2 != 0) {
        // 0x8004145C: sll         $v0, $s1, 24
        ctx->r2 = S32(ctx->r17 << 24);
            goto L_80041420;
    }
    // 0x8004145C: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
L_80041460:
    // 0x80041460: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041464: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80041468: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004146C: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80041470: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041474: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041478: lb          $v0, -0x6E20($at)
    ctx->r2 = MEM_B(ctx->r1, -0X6E20);
    // 0x8004147C: beq         $v1, $v0, L_80041490
    if (ctx->r3 == ctx->r2) {
        // 0x80041480: nop
    
            goto L_80041490;
    }
    // 0x80041480: nop

    // 0x80041484: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80041488: jal         0x8003F804
    // 0x8004148C: addiu       $a0, $a0, -0x7694
    ctx->r4 = ADD32(ctx->r4, -0X7694);
    func_8003F804(rdram, ctx);
        goto after_5;
    // 0x8004148C: addiu       $a0, $a0, -0x7694
    ctx->r4 = ADD32(ctx->r4, -0X7694);
    after_5:
L_80041490:
    // 0x80041490: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80041494: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80041498: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004149C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800414A0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800414A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800414A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800414AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800414B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800414B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800414B8: jr          $ra
    // 0x800414BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800414BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800414C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800414C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800414C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800414C8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800414CC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800414D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800414D4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800414D8: beq         $v0, $zero, L_80041654
    if (ctx->r2 == 0) {
        // 0x800414DC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80041654;
    }
    // 0x800414DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800414E0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800414E4: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800414E8: bne         $v1, $v0, L_80041514
    if (ctx->r3 != ctx->r2) {
        // 0x800414EC: nop
    
            goto L_80041514;
    }
    // 0x800414EC: nop

    // 0x800414F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800414F4: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x800414F8: bne         $v0, $zero, L_80041514
    if (ctx->r2 != 0) {
        // 0x800414FC: nop
    
            goto L_80041514;
    }
    // 0x800414FC: nop

    // 0x80041500: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80041504: slti        $v0, $v1, -0x63
    ctx->r2 = SIGNED(ctx->r3) < -0X63 ? 1 : 0;
    // 0x80041508: bne         $v0, $zero, L_80041514
    if (ctx->r2 != 0) {
        // 0x8004150C: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_80041514;
    }
    // 0x8004150C: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x80041510: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80041514:
    // 0x80041514: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80041518: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004151C: bne         $v1, $v0, L_80041570
    if (ctx->r3 != ctx->r2) {
        // 0x80041520: sh          $zero, 0x10($s1)
        MEM_H(0X10, ctx->r17) = 0;
            goto L_80041570;
    }
    // 0x80041520: sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
    // 0x80041524: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041528: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8004152C: bne         $v0, $zero, L_800415C8
    if (ctx->r2 != 0) {
        // 0x80041530: nop
    
            goto L_800415C8;
    }
    // 0x80041530: nop

    // 0x80041534: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80041538: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004153C: ldc1        $f0, -0x24C8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24C8);
    // 0x80041540: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80041544: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80041548: nop

    // 0x8004154C: bc1f        L_80041628
    if (!c1cs) {
        // 0x80041550: nop
    
            goto L_80041628;
    }
    // 0x80041550: nop

    // 0x80041554: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041558: ldc1        $f0, -0x24C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24C0);
    // 0x8004155C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80041560: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80041564: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80041568: j           L_80041600
    // 0x8004156C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
        goto L_80041600;
    // 0x8004156C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80041570:
    // 0x80041570: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80041574: bne         $v1, $v0, L_80041614
    if (ctx->r3 != ctx->r2) {
        // 0x80041578: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80041614;
    }
    // 0x80041578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004157C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80041580: lh          $v1, 0x7B76($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7B76);
    // 0x80041584: bne         $v1, $v0, L_800415C8
    if (ctx->r3 != ctx->r2) {
        // 0x80041588: nop
    
            goto L_800415C8;
    }
    // 0x80041588: nop

    // 0x8004158C: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80041590: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041594: ldc1        $f0, -0x24B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24B8);
    // 0x80041598: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004159C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800415A0: nop

    // 0x800415A4: bc1f        L_80041628
    if (!c1cs) {
        // 0x800415A8: nop
    
            goto L_80041628;
    }
    // 0x800415A8: nop

    // 0x800415AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800415B0: ldc1        $f0, -0x24B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24B0);
    // 0x800415B4: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800415B8: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x800415BC: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800415C0: j           L_80041600
    // 0x800415C4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
        goto L_80041600;
    // 0x800415C4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_800415C8:
    // 0x800415C8: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800415CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800415D0: ldc1        $f0, -0x24A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24A8);
    // 0x800415D4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800415D8: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800415DC: nop

    // 0x800415E0: bc1f        L_80041628
    if (!c1cs) {
        // 0x800415E4: nop
    
            goto L_80041628;
    }
    // 0x800415E4: nop

    // 0x800415E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800415EC: ldc1        $f0, -0x24A0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24A0);
    // 0x800415F0: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800415F4: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x800415F8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800415FC: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
L_80041600:
    // 0x80041600: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80041604: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80041608: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004160C: j           L_80041628
    // 0x80041610: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
        goto L_80041628;
    // 0x80041610: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80041614:
    // 0x80041614: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041618: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004161C: nop

    // 0x80041620: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80041624: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80041628:
    // 0x80041628: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x8004162C: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80041630: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80041634: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80041638: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x8004163C: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80041640: jal         0x80053234
    // 0x80041644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80041644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80041648: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004164C: jal         0x80051C7C
    // 0x80041650: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80041650: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
L_80041654:
    // 0x80041654: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80041658: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004165C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041660: jr          $ra
    // 0x80041664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80041668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041668: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004166C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80041670: addiu       $t3, $t3, 0x70F4
    ctx->r11 = ADD32(ctx->r11, 0X70F4);
    // 0x80041674: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80041678: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004167C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041680: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041684: addiu       $v0, $v0, -0x6E0C
    ctx->r2 = ADD32(ctx->r2, -0X6E0C);
    // 0x80041688: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x8004168C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80041690: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80041694: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    // 0x80041698: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004169C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x800416A0: addiu       $a3, $a3, -0x6E1C
    ctx->r7 = ADD32(ctx->r7, -0X6E1C);
L_800416A4:
    // 0x800416A4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800416A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800416AC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800416B0: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x800416B4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800416B8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800416BC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x800416C0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x800416C4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800416C8: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x800416CC: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x800416D0: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x800416D4: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x800416D8: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x800416DC: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800416E0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800416E4: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800416E8: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800416EC: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x800416F0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800416F4: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800416F8: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800416FC: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80041700: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x80041704: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80041708: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004170C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80041710: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041714: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80041718: sw          $v0, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r2;
    // 0x8004171C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80041720: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80041724: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80041728: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004172C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80041730: sw          $v0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r2;
    // 0x80041734: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80041738: bne         $v0, $zero, L_800416A4
    if (ctx->r2 != 0) {
        // 0x8004173C: addiu       $a1, $a1, 0x34
        ctx->r5 = ADD32(ctx->r5, 0X34);
            goto L_800416A4;
    }
    // 0x8004173C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    // 0x80041740: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041744: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041748: lui         $at, 0x3F19
    ctx->r1 = S32(0X3F19 << 16);
    // 0x8004174C: ori         $at, $at, 0x999A
    ctx->r1 = ctx->r1 | 0X999A;
    // 0x80041750: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80041754: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041758: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x8004175C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041760: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x80041764: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041768: swc1        $f2, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f2.u32l;
    // 0x8004176C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041770: jr          $ra
    // 0x80041774: swc1        $f2, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f2.u32l;
    return;
    // 0x80041774: swc1        $f2, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_80041778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004177C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80041780: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80041784: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80041788: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x8004178C: addiu       $s1, $s1, -0x7A70
    ctx->r17 = ADD32(ctx->r17, -0X7A70);
    // 0x80041790: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80041794: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_80041798:
    // 0x80041798: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004179C: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800417A0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800417A4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800417A8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800417AC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800417B0: jal         0x800414C0
    // 0x800417B4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_800414C0(rdram, ctx);
        goto after_0;
    // 0x800417B4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_0:
    // 0x800417B8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x800417BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800417C0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800417C4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800417C8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800417CC: bne         $v0, $zero, L_80041798
    if (ctx->r2 != 0) {
        // 0x800417D0: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_80041798;
    }
    // 0x800417D0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x800417D4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800417D8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800417DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800417E0: jr          $ra
    // 0x800417E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800417E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800417E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800417E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800417EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800417F0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800417F4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800417F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800417FC: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80041800: beq         $v0, $zero, L_800418FC
    if (ctx->r2 == 0) {
        // 0x80041804: nop
    
            goto L_800418FC;
    }
    // 0x80041804: nop

    // 0x80041808: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8004180C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80041810: bne         $v0, $zero, L_800418C0
    if (ctx->r2 != 0) {
        // 0x80041814: nop
    
            goto L_800418C0;
    }
    // 0x80041814: nop

    // 0x80041818: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004181C: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80041820: andi        $a0, $v0, 0x1F
    ctx->r4 = ctx->r2 & 0X1F;
    // 0x80041824: slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x80041828: beq         $v0, $zero, L_80041844
    if (ctx->r2 == 0) {
        // 0x8004182C: slti        $v0, $a0, 0x8
        ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_80041844;
    }
    // 0x8004182C: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80041830: bne         $v0, $zero, L_80041864
    if (ctx->r2 != 0) {
        // 0x80041834: srl         $v0, $a0, 31
        ctx->r2 = S32(U32(ctx->r4) >> 31);
            goto L_80041864;
    }
    // 0x80041834: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80041838: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8004183C: j           L_80041860
    // 0x80041840: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
        goto L_80041860;
    // 0x80041840: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
L_80041844:
    // 0x80041844: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80041848: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8004184C: bnel        $v0, $zero, L_80041860
    if (ctx->r2 != 0) {
        // 0x80041850: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_80041860;
    }
    goto skip_0;
    // 0x80041850: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    skip_0:
    // 0x80041854: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80041858: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8004185C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80041860:
    // 0x80041860: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
L_80041864:
    // 0x80041864: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80041868: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8004186C: beq         $v1, $zero, L_8004187C
    if (ctx->r3 == 0) {
        // 0x80041870: sra         $a0, $v0, 1
        ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004187C;
    }
    // 0x80041870: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80041874: j           L_80041880
    // 0x80041878: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
        goto L_80041880;
    // 0x80041878: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
L_8004187C:
    // 0x8004187C: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
L_80041880:
    // 0x80041880: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80041884: addiu       $v1, $v1, 0x7B76
    ctx->r3 = ADD32(ctx->r3, 0X7B76);
    // 0x80041888: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8004188C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80041890: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041894: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041898: lw          $v0, -0x6DCC($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6DCC);
    // 0x8004189C: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x800418A0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x800418A4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800418A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800418AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800418B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800418B4: lw          $v0, -0x6DC8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6DC8);
    // 0x800418B8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800418BC: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_800418C0:
    // 0x800418C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800418C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800418C8: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800418CC: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x800418D0: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800418D4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800418D8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800418DC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800418E0: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x800418E4: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800418E8: jal         0x80053234
    // 0x800418EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x800418EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800418F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800418F4: jal         0x80051C7C
    // 0x800418F8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x800418F8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
L_800418FC:
    // 0x800418FC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80041900: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041908: jr          $ra
    // 0x8004190C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004190C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80041910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041910: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041914: lw          $v0, -0x6DEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DEC);
    // 0x80041918: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004191C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041920: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041924: lw          $v1, -0x6DDC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DDC);
    // 0x80041928: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004192C: lw          $a0, -0x6DD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6DD8);
    // 0x80041930: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041934: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80041938: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004193C: lbu         $a1, 0x70F7($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X70F7);
    // 0x80041940: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041944: lw          $v0, -0x6DE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DE8);
    // 0x80041948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004194C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041950: sb          $a2, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r6;
    // 0x80041954: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041958: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x8004195C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041960: sb          $zero, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = 0;
    // 0x80041964: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041968: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x8004196C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041970: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x80041974: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041978: sb          $zero, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = 0;
    // 0x8004197C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041980: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80041984: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041988: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x8004198C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041990: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x80041994: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041998: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x8004199C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419A0: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x800419A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419A8: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x800419AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419B0: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x800419B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419B8: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x800419BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419C0: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x800419C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419C8: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x800419CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419D0: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x800419D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419D8: sw          $v1, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r3;
    // 0x800419DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419E0: sw          $a0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r4;
    // 0x800419E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800419E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800419EC: sb          $a1, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r5;
    // 0x800419F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800419F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800419F8: lbu         $v0, 0x70F7($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X70F7);
    // 0x800419FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A00: sb          $a2, -0x7A3C($at)
    MEM_B(-0X7A3C, ctx->r1) = ctx->r6;
    // 0x80041A04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A08: sb          $zero, -0x7A3B($at)
    MEM_B(-0X7A3B, ctx->r1) = 0;
    // 0x80041A0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A10: sb          $zero, -0x7A3A($at)
    MEM_B(-0X7A3A, ctx->r1) = 0;
    // 0x80041A14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A18: sb          $zero, -0x7A38($at)
    MEM_B(-0X7A38, ctx->r1) = 0;
    // 0x80041A1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A20: sb          $a2, -0x7A37($at)
    MEM_B(-0X7A37, ctx->r1) = ctx->r6;
    // 0x80041A24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A28: sb          $a2, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = ctx->r6;
    // 0x80041A2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A30: sb          $v0, -0x7A39($at)
    MEM_B(-0X7A39, ctx->r1) = ctx->r2;
    // 0x80041A34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A38: sh          $zero, -0x7A34($at)
    MEM_H(-0X7A34, ctx->r1) = 0;
    // 0x80041A3C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041A40: lw          $v0, -0x6DD4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DD4);
    // 0x80041A44: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041A48: lw          $v1, -0x6DD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DD0);
    // 0x80041A4C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80041A50: lb          $a0, 0x25A0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X25A0);
    // 0x80041A54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A58: sb          $zero, -0x7A35($at)
    MEM_B(-0X7A35, ctx->r1) = 0;
    // 0x80041A5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A60: sw          $zero, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = 0;
    // 0x80041A64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A68: sw          $zero, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = 0;
    // 0x80041A6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A70: sh          $zero, -0x7A2A($at)
    MEM_H(-0X7A2A, ctx->r1) = 0;
    // 0x80041A74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A78: sh          $zero, -0x7A2C($at)
    MEM_H(-0X7A2C, ctx->r1) = 0;
    // 0x80041A7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A80: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x80041A84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A88: swc1        $f0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->f0.u32l;
    // 0x80041A8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A90: sw          $zero, -0x7A0C($at)
    MEM_W(-0X7A0C, ctx->r1) = 0;
    // 0x80041A94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041A98: sw          $zero, -0x7A10($at)
    MEM_W(-0X7A10, ctx->r1) = 0;
    // 0x80041A9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AA0: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x80041AA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AA8: sw          $v1, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = ctx->r3;
    // 0x80041AAC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80041AB0: addiu       $v1, $v1, 0x70F4
    ctx->r3 = ADD32(ctx->r3, 0X70F4);
    // 0x80041AB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AB8: sw          $v0, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = ctx->r2;
    // 0x80041ABC: beq         $a0, $zero, L_80041B18
    if (ctx->r4 == 0) {
        // 0x80041AC0: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80041B18;
    }
    // 0x80041AC0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80041AC4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041AC8: lw          $v0, -0x6DE4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DE4);
    // 0x80041ACC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80041AD0: lw          $a0, -0x6DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6DC8);
    // 0x80041AD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041AD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041ADC: lbu         $a1, 0x3($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3);
    // 0x80041AE0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041AE4: lw          $v1, -0x6DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DCC);
    // 0x80041AE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AEC: sb          $a2, -0x7A08($at)
    MEM_B(-0X7A08, ctx->r1) = ctx->r6;
    // 0x80041AF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AF4: sb          $zero, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = 0;
    // 0x80041AF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041AFC: sb          $zero, -0x7A06($at)
    MEM_B(-0X7A06, ctx->r1) = 0;
    // 0x80041B00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B04: sb          $zero, -0x7A04($at)
    MEM_B(-0X7A04, ctx->r1) = 0;
    // 0x80041B08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B0C: sb          $zero, -0x7A03($at)
    MEM_B(-0X7A03, ctx->r1) = 0;
    // 0x80041B10: j           L_80041B68
    // 0x80041B14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80041B68;
    // 0x80041B14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80041B18:
    // 0x80041B18: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80041B1C: lw          $v0, -0x6DE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DE0);
    // 0x80041B20: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80041B24: lw          $a0, -0x6DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6DC8);
    // 0x80041B28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041B2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041B30: lbu         $a1, 0x3($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3);
    // 0x80041B34: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80041B38: lw          $v1, -0x6DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DCC);
    // 0x80041B3C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80041B40: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B44: sb          $a2, -0x7A08($at)
    MEM_B(-0X7A08, ctx->r1) = ctx->r6;
    // 0x80041B48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B4C: sb          $zero, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = 0;
    // 0x80041B50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B54: sb          $zero, -0x7A06($at)
    MEM_B(-0X7A06, ctx->r1) = 0;
    // 0x80041B58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B5C: sb          $zero, -0x7A04($at)
    MEM_B(-0X7A04, ctx->r1) = 0;
    // 0x80041B60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B64: sb          $a2, -0x7A03($at)
    MEM_B(-0X7A03, ctx->r1) = ctx->r6;
L_80041B68:
    // 0x80041B68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B6C: sb          $v0, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r2;
    // 0x80041B70: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B74: sh          $zero, -0x7A00($at)
    MEM_H(-0X7A00, ctx->r1) = 0;
    // 0x80041B78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B7C: sb          $zero, -0x7A01($at)
    MEM_B(-0X7A01, ctx->r1) = 0;
    // 0x80041B80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B84: sw          $zero, -0x79F0($at)
    MEM_W(-0X79F0, ctx->r1) = 0;
    // 0x80041B88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B8C: sw          $zero, -0x79F4($at)
    MEM_W(-0X79F4, ctx->r1) = 0;
    // 0x80041B90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B94: sh          $zero, -0x79F6($at)
    MEM_H(-0X79F6, ctx->r1) = 0;
    // 0x80041B98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041B9C: sh          $zero, -0x79F8($at)
    MEM_H(-0X79F8, ctx->r1) = 0;
    // 0x80041BA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BA4: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x80041BA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BAC: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x80041BB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BB4: sw          $zero, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = 0;
    // 0x80041BB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BBC: sw          $zero, -0x79DC($at)
    MEM_W(-0X79DC, ctx->r1) = 0;
    // 0x80041BC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BC4: sw          $zero, -0x79E4($at)
    MEM_W(-0X79E4, ctx->r1) = 0;
    // 0x80041BC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BCC: sw          $a0, -0x79F0($at)
    MEM_W(-0X79F0, ctx->r1) = ctx->r4;
    // 0x80041BD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BD4: sw          $v1, -0x79F4($at)
    MEM_W(-0X79F4, ctx->r1) = ctx->r3;
    // 0x80041BD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041BDC: sb          $a1, -0x7A05($at)
    MEM_B(-0X7A05, ctx->r1) = ctx->r5;
    // 0x80041BE0: jr          $ra
    // 0x80041BE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80041BE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80041BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041BEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80041BF0: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80041BF4: addiu       $s0, $s0, -0x7A08
    ctx->r16 = ADD32(ctx->r16, -0X7A08);
    // 0x80041BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041BFC: jal         0x800417E8
    // 0x80041C00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800417E8(rdram, ctx);
        goto after_0;
    // 0x80041C00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80041C04: jal         0x800417E8
    // 0x80041C08: addiu       $a0, $s0, -0x68
    ctx->r4 = ADD32(ctx->r16, -0X68);
    func_800417E8(rdram, ctx);
        goto after_1;
    // 0x80041C08: addiu       $a0, $s0, -0x68
    ctx->r4 = ADD32(ctx->r16, -0X68);
    after_1:
    // 0x80041C0C: jal         0x800417E8
    // 0x80041C10: addiu       $a0, $s0, -0x34
    ctx->r4 = ADD32(ctx->r16, -0X34);
    func_800417E8(rdram, ctx);
        goto after_2;
    // 0x80041C10: addiu       $a0, $s0, -0x34
    ctx->r4 = ADD32(ctx->r16, -0X34);
    after_2:
    // 0x80041C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041C18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041C1C: jr          $ra
    // 0x80041C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041C24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041C28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041C2C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80041C30: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80041C34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041C38: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80041C3C: beq         $v0, $zero, L_80041E60
    if (ctx->r2 == 0) {
        // 0x80041C40: nop
    
            goto L_80041E60;
    }
    // 0x80041C40: nop

    // 0x80041C44: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80041C48: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80041C4C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041C50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041C54: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80041C58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041C5C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80041C60: lw          $v1, -0x6DA0($at)
    ctx->r3 = MEM_W(ctx->r1, -0X6DA0);
    // 0x80041C64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041C68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041C6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041C70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041C74: sw          $v1, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r3;
    // 0x80041C78: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80041C7C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80041C80: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041C84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041C88: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80041C8C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041C90: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80041C94: lw          $v1, -0x6D9C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X6D9C);
    // 0x80041C98: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041C9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041CA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041CA4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041CA8: sw          $v1, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r3;
    // 0x80041CAC: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80041CB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80041CB4: bne         $v1, $a0, L_80041CEC
    if (ctx->r3 != ctx->r4) {
        // 0x80041CB8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80041CEC;
    }
    // 0x80041CB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80041CBC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041CC0: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x80041CC4: bne         $v0, $zero, L_80041DD4
    if (ctx->r2 != 0) {
        // 0x80041CC8: nop
    
            goto L_80041DD4;
    }
    // 0x80041CC8: nop

    // 0x80041CCC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041CD0: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80041CD4: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x80041CD8: slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80041CDC: bne         $v0, $zero, L_80041D1C
    if (ctx->r2 != 0) {
        // 0x80041CE0: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80041D1C;
    }
    // 0x80041CE0: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80041CE4: j           L_80041D30
    // 0x80041CE8: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
        goto L_80041D30;
    // 0x80041CE8: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
L_80041CEC:
    // 0x80041CEC: bne         $v1, $v0, L_80041E20
    if (ctx->r3 != ctx->r2) {
        // 0x80041CF0: nop
    
            goto L_80041E20;
    }
    // 0x80041CF0: nop

    // 0x80041CF4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041CF8: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x80041CFC: bne         $v0, $a0, L_80041DD4
    if (ctx->r2 != ctx->r4) {
        // 0x80041D00: nop
    
            goto L_80041DD4;
    }
    // 0x80041D00: nop

    // 0x80041D04: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80041D08: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80041D0C: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x80041D10: slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80041D14: beq         $v0, $zero, L_80041D2C
    if (ctx->r2 == 0) {
        // 0x80041D18: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80041D2C;
    }
    // 0x80041D18: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_80041D1C:
    // 0x80041D1C: bne         $v0, $zero, L_80041D48
    if (ctx->r2 != 0) {
        // 0x80041D20: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80041D48;
    }
    // 0x80041D20: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80041D24: j           L_80041D48
    // 0x80041D28: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
        goto L_80041D48;
    // 0x80041D28: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80041D2C:
    // 0x80041D2C: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
L_80041D30:
    // 0x80041D30: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80041D34: bnel        $v0, $zero, L_80041D48
    if (ctx->r2 != 0) {
        // 0x80041D38: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_80041D48;
    }
    goto skip_0;
    // 0x80041D38: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_0:
    // 0x80041D3C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80041D40: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // 0x80041D44: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80041D48:
    // 0x80041D48: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80041D4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041D50: ldc1        $f0, -0x2498($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2498);
    // 0x80041D54: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80041D58: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80041D5C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80041D60: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80041D64: nop

    // 0x80041D68: bc1f        L_80041D98
    if (!c1cs) {
        // 0x80041D6C: sra         $a1, $v0, 1
        ctx->r5 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80041D98;
    }
    // 0x80041D6C: sra         $a1, $v0, 1
    ctx->r5 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80041D70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041D74: ldc1        $f0, -0x2490($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2490);
    // 0x80041D78: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80041D7C: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80041D80: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80041D84: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x80041D88: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80041D8C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80041D90: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80041D94: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80041D98:
    // 0x80041D98: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80041D9C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80041DA0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041DA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041DA8: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80041DAC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80041DB0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80041DB4: lw          $v1, -0x6D9C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X6D9C);
    // 0x80041DB8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041DBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041DC0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80041DC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041DC8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041DCC: j           L_80041E34
    // 0x80041DD0: sw          $v1, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r3;
        goto L_80041E34;
    // 0x80041DD0: sw          $v1, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r3;
L_80041DD4:
    // 0x80041DD4: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80041DD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041DDC: ldc1        $f0, -0x2488($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2488);
    // 0x80041DE0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80041DE4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80041DE8: nop

    // 0x80041DEC: bc1f        L_80041E34
    if (!c1cs) {
        // 0x80041DF0: nop
    
            goto L_80041E34;
    }
    // 0x80041DF0: nop

    // 0x80041DF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041DF8: ldc1        $f0, -0x2480($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2480);
    // 0x80041DFC: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80041E00: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x80041E04: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80041E08: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80041E0C: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80041E10: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80041E14: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80041E18: j           L_80041E34
    // 0x80041E1C: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
        goto L_80041E34;
    // 0x80041E1C: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80041E20:
    // 0x80041E20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041E24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041E28: nop

    // 0x80041E2C: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80041E30: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80041E34:
    // 0x80041E34: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80041E38: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80041E3C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80041E40: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80041E44: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80041E48: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80041E4C: jal         0x80053234
    // 0x80041E50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80041E50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80041E54: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80041E58: jal         0x80051C7C
    // 0x80041E5C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80041E5C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
L_80041E60:
    // 0x80041E60: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80041E64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041E68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041E6C: jr          $ra
    // 0x80041E70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80041E70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80041E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80041E78: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80041E7C: addiu       $t4, $t4, -0x6DAC
    ctx->r12 = ADD32(ctx->r12, -0X6DAC);
    // 0x80041E80: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80041E84: addiu       $t3, $t3, 0x70F4
    ctx->r11 = ADD32(ctx->r11, 0X70F4);
    // 0x80041E88: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x80041E8C: addiu       $t2, $t2, -0x7A70
    ctx->r10 = ADD32(ctx->r10, -0X7A70);
    // 0x80041E90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80041E94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041E98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041E9C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80041EA0: addiu       $a3, $a3, -0x6DA0
    ctx->r7 = ADD32(ctx->r7, -0X6DA0);
    // 0x80041EA4: addiu       $t0, $a3, 0x4
    ctx->r8 = ADD32(ctx->r7, 0X4);
    // 0x80041EA8: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
L_80041EAC:
    // 0x80041EAC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80041EB0: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80041EB4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80041EB8: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80041EBC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80041EC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80041EC4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80041EC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80041ECC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041ED0: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80041ED4: lbu         $a1, 0x3($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3);
    // 0x80041ED8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80041EDC: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x80041EE0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80041EE4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80041EE8: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x80041EEC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80041EF0: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80041EF4: sb          $a2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r6;
    // 0x80041EF8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80041EFC: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x80041F00: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80041F04: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80041F08: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x80041F0C: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x80041F10: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80041F14: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80041F18: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80041F1C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80041F20: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80041F24: sb          $a1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r5;
    // 0x80041F28: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x80041F2C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80041F30: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80041F34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041F38: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80041F3C: sw          $v0, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r2;
    // 0x80041F40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80041F44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80041F48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041F4C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80041F50: sw          $v0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r2;
    // 0x80041F54: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80041F58: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80041F5C: bnel        $v0, $zero, L_80041EAC
    if (ctx->r2 != 0) {
        // 0x80041F60: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_80041EAC;
    }
    goto skip_0;
    // 0x80041F60: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    skip_0:
    // 0x80041F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041F68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041F6C: lui         $at, 0x3F19
    ctx->r1 = S32(0X3F19 << 16);
    // 0x80041F70: ori         $at, $at, 0x999A
    ctx->r1 = ctx->r1 | 0X999A;
    // 0x80041F74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80041F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041F7C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80041F80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041F84: sb          $v0, -0x79D4($at)
    MEM_B(-0X79D4, ctx->r1) = ctx->r2;
    // 0x80041F88: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80041F8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041F90: sb          $zero, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = 0;
    // 0x80041F94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041F98: sb          $v1, -0x79D2($at)
    MEM_B(-0X79D2, ctx->r1) = ctx->r3;
    // 0x80041F9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FA0: sb          $zero, -0x79D0($at)
    MEM_B(-0X79D0, ctx->r1) = 0;
    // 0x80041FA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FA8: sb          $zero, -0x79D1($at)
    MEM_B(-0X79D1, ctx->r1) = 0;
    // 0x80041FAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FB0: sb          $zero, -0x79CF($at)
    MEM_B(-0X79CF, ctx->r1) = 0;
    // 0x80041FB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FB8: sb          $v0, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r2;
    // 0x80041FBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FC0: sh          $zero, -0x79CC($at)
    MEM_H(-0X79CC, ctx->r1) = 0;
    // 0x80041FC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FC8: sb          $zero, -0x79CD($at)
    MEM_B(-0X79CD, ctx->r1) = 0;
    // 0x80041FCC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FD0: sw          $zero, -0x79BC($at)
    MEM_W(-0X79BC, ctx->r1) = 0;
    // 0x80041FD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FD8: sw          $zero, -0x79C0($at)
    MEM_W(-0X79C0, ctx->r1) = 0;
    // 0x80041FDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FE0: sh          $zero, -0x79C2($at)
    MEM_H(-0X79C2, ctx->r1) = 0;
    // 0x80041FE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FE8: sh          $zero, -0x79C4($at)
    MEM_H(-0X79C4, ctx->r1) = 0;
    // 0x80041FEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FF0: sw          $zero, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = 0;
    // 0x80041FF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80041FF8: sw          $zero, -0x79A8($at)
    MEM_W(-0X79A8, ctx->r1) = 0;
    // 0x80041FFC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042000: sw          $zero, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = 0;
    // 0x80042004: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042008: sb          $v1, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = ctx->r3;
    // 0x8004200C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042010: swc1        $f0, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f0.u32l;
    // 0x80042014: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042018: swc1        $f0, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x8004201C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042020: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x80042024: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042028: swc1        $f0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->f0.u32l;
    // 0x8004202C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042030: swc1        $f2, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f2.u32l;
    // 0x80042034: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042038: jr          $ra
    // 0x8004203C: swc1        $f2, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f2.u32l;
    return;
    // 0x8004203C: swc1        $f2, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_80042040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042044: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042048: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004204C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042050: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x80042054: addiu       $s1, $s1, -0x7A70
    ctx->r17 = ADD32(ctx->r17, -0X7A70);
    // 0x80042058: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004205C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_80042060:
    // 0x80042060: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80042064: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042068: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8004206C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042070: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80042074: jal         0x80041C24
    // 0x80042078: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_80041C24(rdram, ctx);
        goto after_0;
    // 0x80042078: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_0:
    // 0x8004207C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042080: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80042084: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80042088: bne         $v0, $zero, L_80042060
    if (ctx->r2 != 0) {
        // 0x8004208C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_80042060;
    }
    // 0x8004208C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80042090: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80042094: jal         0x8003F804
    // 0x80042098: addiu       $a0, $a0, -0x79D4
    ctx->r4 = ADD32(ctx->r4, -0X79D4);
    func_8003F804(rdram, ctx);
        goto after_1;
    // 0x80042098: addiu       $a0, $a0, -0x79D4
    ctx->r4 = ADD32(ctx->r4, -0X79D4);
    after_1:
    // 0x8004209C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800420A0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800420A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800420A8: jr          $ra
    // 0x800420AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800420AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800420B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800420B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800420B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800420B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800420BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420C0: sb          $v0, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r2;
    // 0x800420C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800420C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420CC: sb          $v0, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = ctx->r2;
    // 0x800420D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800420D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420D8: sb          $v0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r2;
    // 0x800420DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800420E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420E4: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x800420E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420EC: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x800420F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420F4: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
    // 0x800420F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800420FC: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x80042100: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042104: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80042108: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004210C: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80042110: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042114: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x80042118: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004211C: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80042120: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042124: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x80042128: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004212C: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80042130: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042134: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x80042138: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004213C: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80042140: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042144: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80042148: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004214C: sb          $v0, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = ctx->r2;
    // 0x80042150: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042154: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x80042158: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004215C: jr          $ra
    // 0x80042160: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x80042160: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80042164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042168: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004216C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80042170: jal         0x8003F804
    // 0x80042174: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    func_8003F804(rdram, ctx);
        goto after_0;
    // 0x80042174: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    after_0:
    // 0x80042178: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004217C: jr          $ra
    // 0x80042180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80042180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80042184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042188: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004218C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042190: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042194: sb          $v0, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r2;
    // 0x80042198: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004219C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421A0: sb          $v0, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = ctx->r2;
    // 0x800421A4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800421A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421AC: sb          $v0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r2;
    // 0x800421B0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800421B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421B8: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x800421BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421C0: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x800421C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421C8: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
    // 0x800421CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421D0: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x800421D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421D8: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x800421DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421E0: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x800421E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421E8: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x800421EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421F0: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x800421F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800421F8: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x800421FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042200: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80042204: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042208: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x8004220C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042210: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80042214: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042218: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x8004221C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042220: sb          $v0, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = ctx->r2;
    // 0x80042224: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042228: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x8004222C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042230: jr          $ra
    // 0x80042234: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x80042234: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80042238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004223C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80042240: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80042244: jal         0x8003F804
    // 0x80042248: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    func_8003F804(rdram, ctx);
        goto after_0;
    // 0x80042248: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    after_0:
    // 0x8004224C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80042250: jr          $ra
    // 0x80042254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80042254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80042258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042258: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004225C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80042260: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80042264: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80042268: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8004226C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80042270: beq         $v0, $zero, L_80042940
    if (ctx->r2 == 0) {
        // 0x80042274: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80042940;
    }
    // 0x80042274: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80042278: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004227C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80042280: beq         $v1, $v0, L_800422FC
    if (ctx->r3 == ctx->r2) {
        // 0x80042284: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_800422FC;
    }
    // 0x80042284: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80042288: beq         $v0, $zero, L_800422A0
    if (ctx->r2 == 0) {
        // 0x8004228C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800422A0;
    }
    // 0x8004228C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80042290: beq         $v1, $v0, L_800422B4
    if (ctx->r3 == ctx->r2) {
        // 0x80042294: nop
    
            goto L_800422B4;
    }
    // 0x80042294: nop

    // 0x80042298: j           L_800428D4
    // 0x8004229C: nop

        goto L_800428D4;
    // 0x8004229C: nop

L_800422A0:
    // 0x800422A0: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800422A4: beq         $v0, $zero, L_800428D4
    if (ctx->r2 == 0) {
        // 0x800422A8: nop
    
            goto L_800428D4;
    }
    // 0x800422A8: nop

    // 0x800422AC: j           L_80042568
    // 0x800422B0: nop

        goto L_80042568;
    // 0x800422B0: nop

L_800422B4:
    // 0x800422B4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800422B8: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x800422BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800422C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800422C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800422C8: lw          $v0, -0x6D48($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D48);
    // 0x800422CC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800422D0: addiu       $a0, $a0, -0x6D48
    ctx->r4 = ADD32(ctx->r4, -0X6D48);
    // 0x800422D4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800422D8: beq         $v0, $zero, L_800422E4
    if (ctx->r2 == 0) {
        // 0x800422DC: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_800422E4;
    }
    // 0x800422DC: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x800422E0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800422E4:
    // 0x800422E4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800422E8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800422EC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800422F0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800422F4: j           L_80042914
    // 0x800422F8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x800422F8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_800422FC:
    // 0x800422FC: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80042300: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80042304: bne         $v0, $zero, L_80042530
    if (ctx->r2 != 0) {
        // 0x80042308: sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3 << 3);
            goto L_80042530;
    }
    // 0x80042308: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8004230C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80042310: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80042314: andi        $a0, $v0, 0x1F
    ctx->r4 = ctx->r2 & 0X1F;
    // 0x80042318: slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x8004231C: beq         $v0, $zero, L_80042334
    if (ctx->r2 == 0) {
        // 0x80042320: slti        $v0, $a0, 0x8
        ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_80042334;
    }
    // 0x80042320: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80042324: bne         $v0, $zero, L_80042350
    if (ctx->r2 != 0) {
        // 0x80042328: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80042350;
    }
    // 0x80042328: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8004232C: j           L_80042350
    // 0x80042330: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
        goto L_80042350;
    // 0x80042330: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
L_80042334:
    // 0x80042334: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80042338: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8004233C: bnel        $v0, $zero, L_80042350
    if (ctx->r2 != 0) {
        // 0x80042340: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_80042350;
    }
    goto skip_0;
    // 0x80042340: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    skip_0:
    // 0x80042344: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80042348: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8004234C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80042350:
    // 0x80042350: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80042354: srl         $v1, $a0, 31
    ctx->r3 = S32(U32(ctx->r4) >> 31);
    // 0x80042358: lbu         $a1, 0x6($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X6);
    // 0x8004235C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80042360: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042364: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80042368: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004236C: lw          $v0, -0x6D48($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D48);
    // 0x80042370: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80042374: addiu       $a2, $a2, -0x6D48
    ctx->r6 = ADD32(ctx->r6, -0X6D48);
    // 0x80042378: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8004237C: sltiu       $v0, $a1, 0x5
    ctx->r2 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80042380: beq         $v0, $zero, L_8004245C
    if (ctx->r2 == 0) {
        // 0x80042384: sra         $a0, $v1, 1
        ctx->r4 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8004245C;
    }
    // 0x80042384: sra         $a0, $v1, 1
    ctx->r4 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80042388: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004238C: lh          $v1, 0x7B76($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7B76);
    // 0x80042390: addiu       $v0, $a1, -0x2
    ctx->r2 = ADD32(ctx->r5, -0X2);
    // 0x80042394: bne         $v0, $v1, L_800423FC
    if (ctx->r2 != ctx->r3) {
        // 0x80042398: nop
    
            goto L_800423FC;
    }
    // 0x80042398: nop

    // 0x8004239C: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800423A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800423A4: ldc1        $f0, -0x2478($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2478);
    // 0x800423A8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800423AC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800423B0: nop

    // 0x800423B4: bc1f        L_800423E4
    if (!c1cs) {
        // 0x800423B8: nop
    
            goto L_800423E4;
    }
    // 0x800423B8: nop

    // 0x800423BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800423C0: ldc1        $f0, -0x2470($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2470);
    // 0x800423C4: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800423C8: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x800423CC: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800423D0: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800423D4: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x800423D8: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800423DC: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800423E0: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_800423E4:
    // 0x800423E4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800423E8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800423EC: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800423F0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800423F4: j           L_80042910
    // 0x800423F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80042910;
    // 0x800423F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_800423FC:
    // 0x800423FC: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80042400: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042404: ldc1        $f0, -0x2468($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2468);
    // 0x80042408: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004240C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80042410: nop

    // 0x80042414: bc1f        L_80042444
    if (!c1cs) {
        // 0x80042418: nop
    
            goto L_80042444;
    }
    // 0x80042418: nop

    // 0x8004241C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042420: ldc1        $f0, -0x2460($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2460);
    // 0x80042424: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80042428: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x8004242C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80042430: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80042434: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80042438: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8004243C: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80042440: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80042444:
    // 0x80042444: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80042448: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004244C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80042450: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80042454: j           L_80042914
    // 0x80042458: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x80042458: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_8004245C:
    // 0x8004245C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80042460: lh          $v1, 0x7B76($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7B76);
    // 0x80042464: addiu       $v0, $a1, -0x5
    ctx->r2 = ADD32(ctx->r5, -0X5);
    // 0x80042468: bne         $v0, $v1, L_800424D0
    if (ctx->r2 != ctx->r3) {
        // 0x8004246C: nop
    
            goto L_800424D0;
    }
    // 0x8004246C: nop

    // 0x80042470: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80042474: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042478: ldc1        $f0, -0x2458($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2458);
    // 0x8004247C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80042480: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80042484: nop

    // 0x80042488: bc1f        L_800424B8
    if (!c1cs) {
        // 0x8004248C: nop
    
            goto L_800424B8;
    }
    // 0x8004248C: nop

    // 0x80042490: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042494: ldc1        $f0, -0x2450($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2450);
    // 0x80042498: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004249C: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x800424A0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800424A4: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x800424A8: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x800424AC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800424B0: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800424B4: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_800424B8:
    // 0x800424B8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800424BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800424C0: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800424C4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800424C8: j           L_80042910
    // 0x800424CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80042910;
    // 0x800424CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_800424D0:
    // 0x800424D0: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800424D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800424D8: ldc1        $f0, -0x2448($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2448);
    // 0x800424DC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800424E0: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800424E4: nop

    // 0x800424E8: bc1f        L_80042518
    if (!c1cs) {
        // 0x800424EC: nop
    
            goto L_80042518;
    }
    // 0x800424EC: nop

    // 0x800424F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800424F4: ldc1        $f0, -0x2440($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2440);
    // 0x800424F8: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800424FC: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x80042500: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80042504: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80042508: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8004250C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80042510: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80042514: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80042518:
    // 0x80042518: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8004251C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042520: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80042524: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80042528: j           L_80042914
    // 0x8004252C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x8004252C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042530:
    // 0x80042530: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80042534: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042538: lw          $v1, -0x6D48($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D48);
    // 0x8004253C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80042540: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042544: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042548: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004254C: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x80042550: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80042554: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80042558: lw          $v0, -0x6D44($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D44);
    // 0x8004255C: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80042560: j           L_80042910
    // 0x80042564: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80042910;
    // 0x80042564: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80042568:
    // 0x80042568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004256C: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x80042570: beq         $v0, $zero, L_800425AC
    if (ctx->r2 == 0) {
        // 0x80042574: nop
    
            goto L_800425AC;
    }
    // 0x80042574: nop

    // 0x80042578: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8004257C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042580: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80042584: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042588: lw          $v1, -0x6D48($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D48);
    // 0x8004258C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80042590: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042594: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x80042598: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004259C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800425A0: lw          $v0, -0x6D44($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D44);
    // 0x800425A4: j           L_80042914
    // 0x800425A8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x800425A8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_800425AC:
    // 0x800425AC: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x800425B0: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x800425B4: bne         $v0, $zero, L_8004289C
    if (ctx->r2 != 0) {
        // 0x800425B8: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004289C;
    }
    // 0x800425B8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800425BC: sltiu       $v0, $a0, 0x5
    ctx->r2 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x800425C0: beq         $v0, $zero, L_80042730
    if (ctx->r2 == 0) {
        // 0x800425C4: addiu       $v0, $a0, -0x2
        ctx->r2 = ADD32(ctx->r4, -0X2);
            goto L_80042730;
    }
    // 0x800425C4: addiu       $v0, $a0, -0x2
    ctx->r2 = ADD32(ctx->r4, -0X2);
    // 0x800425C8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800425CC: lh          $v1, 0x7B76($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7B76);
    // 0x800425D0: bne         $v0, $v1, L_80042684
    if (ctx->r2 != ctx->r3) {
        // 0x800425D4: nop
    
            goto L_80042684;
    }
    // 0x800425D4: nop

    // 0x800425D8: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800425DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800425E0: ldc1        $f0, -0x2438($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2438);
    // 0x800425E4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800425E8: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800425EC: nop

    // 0x800425F0: bc1f        L_80042620
    if (!c1cs) {
        // 0x800425F4: nop
    
            goto L_80042620;
    }
    // 0x800425F4: nop

    // 0x800425F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800425FC: ldc1        $f0, -0x2430($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2430);
    // 0x80042600: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80042604: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80042608: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8004260C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x80042610: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80042614: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80042618: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004261C: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80042620:
    // 0x80042620: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80042624: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80042628: lw          $a1, -0x6D08($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D08);
    // 0x8004262C: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80042630: bgez        $a0, L_8004263C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80042634: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8004263C;
    }
    // 0x80042634: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80042638: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_8004263C:
    // 0x8004263C: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80042640: beq         $a0, $zero, L_80042650
    if (ctx->r4 == 0) {
        // 0x80042644: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042650;
    }
    // 0x80042644: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80042648: j           L_80042654
    // 0x8004264C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80042654;
    // 0x8004264C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80042650:
    // 0x80042650: sw          $a1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r5;
L_80042654:
    // 0x80042654: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80042658: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004265C: lw          $a1, -0x6D04($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D04);
    // 0x80042660: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80042664: bgez        $a0, L_80042670
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80042668: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80042670;
    }
    // 0x80042668: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8004266C: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_80042670:
    // 0x80042670: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80042674: beq         $a0, $zero, L_80042894
    if (ctx->r4 == 0) {
        // 0x80042678: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042894;
    }
    // 0x80042678: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8004267C: j           L_80042914
    // 0x80042680: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x80042680: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042684:
    // 0x80042684: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80042688: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004268C: ldc1        $f0, -0x2428($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2428);
    // 0x80042690: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80042694: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80042698: nop

    // 0x8004269C: bc1f        L_800426CC
    if (!c1cs) {
        // 0x800426A0: nop
    
            goto L_800426CC;
    }
    // 0x800426A0: nop

    // 0x800426A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800426A8: ldc1        $f0, -0x2420($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2420);
    // 0x800426AC: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800426B0: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x800426B4: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800426B8: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x800426BC: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x800426C0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800426C4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800426C8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_800426CC:
    // 0x800426CC: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800426D0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800426D4: lw          $a1, -0x6D00($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D00);
    // 0x800426D8: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x800426DC: bgez        $a0, L_800426E8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800426E0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800426E8;
    }
    // 0x800426E0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800426E4: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_800426E8:
    // 0x800426E8: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800426EC: beq         $a0, $zero, L_800426FC
    if (ctx->r4 == 0) {
        // 0x800426F0: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_800426FC;
    }
    // 0x800426F0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800426F4: j           L_80042700
    // 0x800426F8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80042700;
    // 0x800426F8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800426FC:
    // 0x800426FC: sw          $a1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r5;
L_80042700:
    // 0x80042700: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80042704: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80042708: lw          $a1, -0x6CFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6CFC);
    // 0x8004270C: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80042710: bgez        $a0, L_8004271C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80042714: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8004271C;
    }
    // 0x80042714: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80042718: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_8004271C:
    // 0x8004271C: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80042720: beq         $a0, $zero, L_80042894
    if (ctx->r4 == 0) {
        // 0x80042724: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042894;
    }
    // 0x80042724: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80042728: j           L_80042914
    // 0x8004272C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x8004272C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042730:
    // 0x80042730: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80042734: lh          $v1, 0x7B76($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7B76);
    // 0x80042738: addiu       $v0, $a0, -0x5
    ctx->r2 = ADD32(ctx->r4, -0X5);
    // 0x8004273C: bne         $v0, $v1, L_800427F0
    if (ctx->r2 != ctx->r3) {
        // 0x80042740: nop
    
            goto L_800427F0;
    }
    // 0x80042740: nop

    // 0x80042744: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80042748: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004274C: ldc1        $f0, -0x2418($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2418);
    // 0x80042750: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80042754: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80042758: nop

    // 0x8004275C: bc1f        L_8004278C
    if (!c1cs) {
        // 0x80042760: nop
    
            goto L_8004278C;
    }
    // 0x80042760: nop

    // 0x80042764: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042768: ldc1        $f0, -0x2410($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2410);
    // 0x8004276C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80042770: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80042774: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80042778: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8004277C: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80042780: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80042784: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80042788: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_8004278C:
    // 0x8004278C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80042790: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80042794: lw          $a1, -0x6D08($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D08);
    // 0x80042798: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x8004279C: bgez        $a0, L_800427A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800427A0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800427A8;
    }
    // 0x800427A0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800427A4: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_800427A8:
    // 0x800427A8: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800427AC: beq         $a0, $zero, L_800427BC
    if (ctx->r4 == 0) {
        // 0x800427B0: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_800427BC;
    }
    // 0x800427B0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800427B4: j           L_800427C0
    // 0x800427B8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_800427C0;
    // 0x800427B8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800427BC:
    // 0x800427BC: sw          $a1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r5;
L_800427C0:
    // 0x800427C0: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800427C4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800427C8: lw          $a1, -0x6D04($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D04);
    // 0x800427CC: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x800427D0: bgez        $a0, L_800427DC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800427D4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800427DC;
    }
    // 0x800427D4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800427D8: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_800427DC:
    // 0x800427DC: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800427E0: beq         $a0, $zero, L_80042894
    if (ctx->r4 == 0) {
        // 0x800427E4: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042894;
    }
    // 0x800427E4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800427E8: j           L_80042914
    // 0x800427EC: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042914;
    // 0x800427EC: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_800427F0:
    // 0x800427F0: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800427F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800427F8: ldc1        $f0, -0x2408($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2408);
    // 0x800427FC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80042800: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80042804: nop

    // 0x80042808: bc1f        L_80042838
    if (!c1cs) {
        // 0x8004280C: nop
    
            goto L_80042838;
    }
    // 0x8004280C: nop

    // 0x80042810: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042814: ldc1        $f0, -0x2400($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2400);
    // 0x80042818: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004281C: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x80042820: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80042824: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80042828: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8004282C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80042830: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80042834: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80042838:
    // 0x80042838: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8004283C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80042840: lw          $a1, -0x6D00($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6D00);
    // 0x80042844: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80042848: bgez        $a0, L_80042854
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004284C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80042854;
    }
    // 0x8004284C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80042850: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_80042854:
    // 0x80042854: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80042858: beq         $a0, $zero, L_80042868
    if (ctx->r4 == 0) {
        // 0x8004285C: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042868;
    }
    // 0x8004285C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80042860: j           L_8004286C
    // 0x80042864: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8004286C;
    // 0x80042864: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80042868:
    // 0x80042868: sw          $a1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r5;
L_8004286C:
    // 0x8004286C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80042870: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80042874: lw          $a1, -0x6CFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6CFC);
    // 0x80042878: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x8004287C: bgez        $a0, L_80042888
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80042880: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80042888;
    }
    // 0x80042880: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80042884: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
L_80042888:
    // 0x80042888: sra         $a0, $v1, 2
    ctx->r4 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004288C: bne         $a0, $zero, L_80042910
    if (ctx->r4 != 0) {
        // 0x80042890: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80042910;
    }
    // 0x80042890: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_80042894:
    // 0x80042894: j           L_80042914
    // 0x80042898: sw          $a1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r5;
        goto L_80042914;
    // 0x80042898: sw          $a1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r5;
L_8004289C:
    // 0x8004289C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800428A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800428A4: lw          $v1, -0x6D48($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D48);
    // 0x800428A8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800428AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800428B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800428B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800428B8: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x800428BC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800428C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800428C4: lw          $v0, -0x6D44($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D44);
    // 0x800428C8: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800428CC: j           L_80042910
    // 0x800428D0: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80042910;
    // 0x800428D0: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800428D4:
    // 0x800428D4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800428D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800428DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800428E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800428E4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800428E8: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800428EC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800428F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800428F4: lw          $v1, -0x6D48($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D48);
    // 0x800428F8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800428FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80042900: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x80042904: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80042908: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004290C: lw          $v0, -0x6D44($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6D44);
L_80042910:
    // 0x80042910: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042914:
    // 0x80042914: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80042918: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x8004291C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80042920: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80042924: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80042928: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x8004292C: jal         0x80053234
    // 0x80042930: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80042930: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80042934: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80042938: jal         0x80051C7C
    // 0x8004293C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x8004293C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
L_80042940:
    // 0x80042940: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80042944: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80042948: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8004294C: jr          $ra
    // 0x80042950: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80042950: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80042954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042954: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80042958: lbu         $v0, 0x7B98($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B98);
    // 0x8004295C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042960: beq         $v0, $v1, L_8004297C
    if (ctx->r2 == ctx->r3) {
        // 0x80042964: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8004297C;
    }
    // 0x80042964: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80042968: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004296C: lb          $v0, 0x25FA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25FA);
    // 0x80042970: bne         $v0, $v1, L_80042A5C
    if (ctx->r2 != ctx->r3) {
        // 0x80042974: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80042A5C;
    }
    // 0x80042974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80042978: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8004297C:
    // 0x8004297C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80042980: addiu       $t3, $t3, 0x70F4
    ctx->r11 = ADD32(ctx->r11, 0X70F4);
    // 0x80042984: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80042988: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004298C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042990: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80042994: addiu       $v0, $v0, -0x6D48
    ctx->r2 = ADD32(ctx->r2, -0X6D48);
    // 0x80042998: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x8004299C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800429A0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800429A4: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    // 0x800429A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800429AC: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x800429B0: addiu       $a3, $a3, -0x6D88
    ctx->r7 = ADD32(ctx->r7, -0X6D88);
L_800429B4:
    // 0x800429B4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800429B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800429BC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800429C0: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x800429C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800429C8: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800429CC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x800429D0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x800429D4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800429D8: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x800429DC: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x800429E0: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x800429E4: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x800429E8: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x800429EC: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800429F0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800429F4: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800429F8: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800429FC: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80042A00: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80042A04: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80042A08: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80042A0C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80042A10: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x80042A14: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80042A18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80042A1C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80042A20: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x80042A24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042A28: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80042A2C: sw          $v0, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r2;
    // 0x80042A30: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80042A34: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80042A38: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80042A3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042A40: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80042A44: sw          $v0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r2;
    // 0x80042A48: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80042A4C: bne         $v0, $zero, L_800429B4
    if (ctx->r2 != 0) {
        // 0x80042A50: addiu       $a2, $a2, 0x34
        ctx->r6 = ADD32(ctx->r6, 0X34);
            goto L_800429B4;
    }
    // 0x80042A50: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    // 0x80042A54: j           L_80042B30
    // 0x80042A58: nop

        goto L_80042B30;
    // 0x80042A58: nop

L_80042A5C:
    // 0x80042A5C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80042A60: addiu       $t3, $t3, 0x70F4
    ctx->r11 = ADD32(ctx->r11, 0X70F4);
    // 0x80042A64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042A6C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80042A70: addiu       $v0, $v0, -0x6D48
    ctx->r2 = ADD32(ctx->r2, -0X6D48);
    // 0x80042A74: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x80042A78: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80042A7C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80042A80: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    // 0x80042A84: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80042A88: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80042A8C: addiu       $a3, $a3, -0x6D68
    ctx->r7 = ADD32(ctx->r7, -0X6D68);
L_80042A90:
    // 0x80042A90: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80042A94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042A98: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80042A9C: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x80042AA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80042AA4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80042AA8: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80042AAC: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80042AB0: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80042AB4: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80042AB8: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80042ABC: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x80042AC0: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80042AC4: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80042AC8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80042ACC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80042AD0: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80042AD4: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80042AD8: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80042ADC: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80042AE0: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80042AE4: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80042AE8: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80042AEC: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x80042AF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80042AF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80042AF8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80042AFC: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x80042B00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B04: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80042B08: sw          $v0, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r2;
    // 0x80042B0C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80042B10: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80042B14: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80042B18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B1C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80042B20: sw          $v0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r2;
    // 0x80042B24: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80042B28: bne         $v0, $zero, L_80042A90
    if (ctx->r2 != 0) {
        // 0x80042B2C: addiu       $a2, $a2, 0x34
        ctx->r6 = ADD32(ctx->r6, 0X34);
            goto L_80042A90;
    }
    // 0x80042B2C: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
L_80042B30:
    // 0x80042B30: lui         $at, 0x3F0C
    ctx->r1 = S32(0X3F0C << 16);
    // 0x80042B34: ori         $at, $at, 0xCCCD
    ctx->r1 = ctx->r1 | 0XCCCD;
    // 0x80042B38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042B40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80042B44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B48: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x80042B4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B50: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x80042B54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B58: swc1        $f2, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f2.u32l;
    // 0x80042B5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B60: swc1        $f2, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f2.u32l;
    // 0x80042B64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B68: swc1        $f0, -0x7980($at)
    MEM_W(-0X7980, ctx->r1) = ctx->f0.u32l;
    // 0x80042B6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B70: swc1        $f0, -0x7984($at)
    MEM_W(-0X7984, ctx->r1) = ctx->f0.u32l;
    // 0x80042B74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B78: swc1        $f0, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->f0.u32l;
    // 0x80042B7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B80: swc1        $f0, -0x7950($at)
    MEM_W(-0X7950, ctx->r1) = ctx->f0.u32l;
    // 0x80042B84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B88: swc1        $f2, -0x7918($at)
    MEM_W(-0X7918, ctx->r1) = ctx->f2.u32l;
    // 0x80042B8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B90: swc1        $f2, -0x791C($at)
    MEM_W(-0X791C, ctx->r1) = ctx->f2.u32l;
    // 0x80042B94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042B98: swc1        $f0, -0x78E4($at)
    MEM_W(-0X78E4, ctx->r1) = ctx->f0.u32l;
    // 0x80042B9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80042BA0: jr          $ra
    // 0x80042BA4: swc1        $f0, -0x78E8($at)
    MEM_W(-0X78E8, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x80042BA4: swc1        $f0, -0x78E8($at)
    MEM_W(-0X78E8, ctx->r1) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80042BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042BA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042BAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042BB0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80042BB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042BB8: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x80042BBC: addiu       $s1, $s1, -0x7A70
    ctx->r17 = ADD32(ctx->r17, -0X7A70);
    // 0x80042BC0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80042BC4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_80042BC8:
    // 0x80042BC8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80042BCC: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80042BD0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042BD4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80042BD8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042BDC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80042BE0: jal         0x80042258
    // 0x80042BE4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_80042258(rdram, ctx);
        goto after_0;
    // 0x80042BE4: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_0:
    // 0x80042BE8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80042BEC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80042BF0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80042BF4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80042BF8: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80042BFC: bne         $v0, $zero, L_80042BC8
    if (ctx->r2 != 0) {
        // 0x80042C00: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_80042BC8;
    }
    // 0x80042C00: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x80042C04: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80042C08: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042C0C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042C10: jr          $ra
    // 0x80042C14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80042C14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80042C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042C18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042C1C: ldc1        $f0, -0x23E8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X23E8);
    // 0x80042C20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042C24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80042C28: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80042C2C: addiu       $s1, $s1, -0x23F8
    ctx->r17 = ADD32(ctx->r17, -0X23F8);
    // 0x80042C30: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80042C34: mtc1        $a0, $f20
    ctx->f20.u32l = ctx->r4;
    // 0x80042C38: nop

    // 0x80042C3C: cvt.d.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.d = CVT_D_W(ctx->f20.u32l);
    // 0x80042C40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80042C44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80042C48: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x80042C4C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80042C50: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80042C54: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80042C58: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80042C5C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80042C60: nop

    // 0x80042C64: jal         0x8004EC44
    // 0x80042C68: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_0;
    // 0x80042C68: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80042C6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042C70: ldc1        $f0, -0x23E0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X23E0);
    // 0x80042C74: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80042C78: addiu       $s0, $s0, -0x23F4
    ctx->r16 = ADD32(ctx->r16, -0X23F4);
    // 0x80042C7C: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x80042C80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80042C84: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80042C88: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80042C8C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80042C90: nop

    // 0x80042C94: jal         0x8004EC44
    // 0x80042C98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_1;
    // 0x80042C98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x80042C9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042CA0: ldc1        $f0, -0x23D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X23D8);
    // 0x80042CA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80042CA8: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    // 0x80042CAC: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x80042CB0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80042CB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80042CB8: ldc1        $f22, -0x23D0($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0X23D0);
    // 0x80042CBC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80042CC0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80042CC4: nop

    // 0x80042CC8: jal         0x8004EC44
    // 0x80042CCC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_2;
    // 0x80042CCC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x80042CD0: sub.d       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f22.d); 
    ctx->f0.d = ctx->f20.d - ctx->f22.d;
    // 0x80042CD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80042CD8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80042CDC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80042CE0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80042CE4: nop

    // 0x80042CE8: jal         0x8004EC44
    // 0x80042CEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_3;
    // 0x80042CEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x80042CF0: add.d       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = ctx->f20.d + ctx->f22.d;
    // 0x80042CF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80042CF8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80042CFC: trunc.w.d   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_D(ctx->f20.d);
    // 0x80042D00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042D04: nop

    // 0x80042D08: jal         0x8004EC44
    // 0x80042D0C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_4;
    // 0x80042D0C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x80042D10: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80042D14: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80042D18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80042D1C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80042D20: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80042D24: jr          $ra
    // 0x80042D28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80042D28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80042D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80042D30: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80042D34: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80042D38: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80042D3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80042D40: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80042D44: beq         $v0, $zero, L_800434EC
    if (ctx->r2 == 0) {
        // 0x80042D48: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800434EC;
    }
    // 0x80042D48: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80042D4C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80042D50: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80042D54: bne         $v1, $v0, L_80042DA8
    if (ctx->r3 != ctx->r2) {
        // 0x80042D58: nop
    
            goto L_80042DA8;
    }
    // 0x80042D58: nop

    // 0x80042D5C: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80042D60: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80042D64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042D68: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80042D6C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042D70: lw          $v1, -0x6CF8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6CF8);
    // 0x80042D74: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042D78: beq         $v0, $zero, L_80042D88
    if (ctx->r2 == 0) {
        // 0x80042D7C: addiu       $v0, $a0, -0x6
        ctx->r2 = ADD32(ctx->r4, -0X6);
            goto L_80042D88;
    }
    // 0x80042D7C: addiu       $v0, $a0, -0x6
    ctx->r2 = ADD32(ctx->r4, -0X6);
    // 0x80042D80: j           L_80042D8C
    // 0x80042D84: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80042D8C;
    // 0x80042D84: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80042D88:
    // 0x80042D88: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
L_80042D8C:
    // 0x80042D8C: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80042D90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042D94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80042D98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80042D9C: lw          $v0, -0x6CF0($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6CF0);
    // 0x80042DA0: j           L_80042E00
    // 0x80042DA4: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042E00;
    // 0x80042DA4: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042DA8:
    // 0x80042DA8: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80042DAC: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x80042DB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042DB4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80042DB8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80042DBC: lw          $a0, -0x6CF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CF0);
    // 0x80042DC0: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x80042DC4: bgez        $v0, L_80042DD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042DC8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80042DD0;
    }
    // 0x80042DC8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80042DCC: addiu       $v1, $v0, 0x3
    ctx->r3 = ADD32(ctx->r2, 0X3);
L_80042DD0:
    // 0x80042DD0: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80042DD4: beq         $v0, $zero, L_80042DE4
    if (ctx->r2 == 0) {
        // 0x80042DD8: subu        $v0, $a1, $v0
        ctx->r2 = SUB32(ctx->r5, ctx->r2);
            goto L_80042DE4;
    }
    // 0x80042DD8: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80042DDC: j           L_80042DE8
    // 0x80042DE0: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
        goto L_80042DE8;
    // 0x80042DE0: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_80042DE4:
    // 0x80042DE4: sw          $a0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r4;
L_80042DE8:
    // 0x80042DE8: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80042DEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042DF0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80042DF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80042DF8: lw          $v0, -0x6CF8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6CF8);
    // 0x80042DFC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80042E00:
    // 0x80042E00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042E04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042E08: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80042E0C: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80042E10: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80042E14: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80042E18: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80042E1C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80042E20: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80042E24: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80042E28: jal         0x80053234
    // 0x80042E2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80042E2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80042E30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80042E34: jal         0x80051C7C
    // 0x80042E38: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80042E38: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
    // 0x80042E3C: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80042E40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80042E44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042E48: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80042E4C: bne         $v0, $zero, L_80042FB8
    if (ctx->r2 != 0) {
        // 0x80042E50: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80042FB8;
    }
    // 0x80042E50: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80042E54: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80042E58: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80042E5C: bne         $a0, $v0, L_80042FB0
    if (ctx->r4 != ctx->r2) {
        // 0x80042E60: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80042FB0;
    }
    // 0x80042E60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80042E64: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80042E68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042E6C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80042E70: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80042E74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042E78: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x80042E7C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x80042E80: beq         $v0, $zero, L_80042EA0
    if (ctx->r2 == 0) {
        // 0x80042E84: andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
            goto L_80042EA0;
    }
    // 0x80042E84: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x80042E88: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80042E8C: beq         $v0, $zero, L_80042EC8
    if (ctx->r2 == 0) {
        // 0x80042E90: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80042EC8;
    }
    // 0x80042E90: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80042E94: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80042E98: j           L_80042EC0
    // 0x80042E9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_80042EC0;
    // 0x80042E9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80042EA0:
    // 0x80042EA0: beq         $v0, $zero, L_80042EC8
    if (ctx->r2 == 0) {
        // 0x80042EA4: nop
    
            goto L_80042EC8;
    }
    // 0x80042EA4: nop

    // 0x80042EA8: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80042EAC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80042EB0: beq         $v0, $zero, L_80042EC8
    if (ctx->r2 == 0) {
        // 0x80042EB4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80042EC8;
    }
    // 0x80042EB4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80042EB8: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80042EBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80042EC0:
    // 0x80042EC0: jal         0x8000637C
    // 0x80042EC4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80042EC4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    after_2:
L_80042EC8:
    // 0x80042EC8: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80042ECC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80042ED0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80042ED4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80042ED8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80042EDC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80042EE0: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x80042EE4: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80042EE8: beq         $v0, $zero, L_800432C0
    if (ctx->r2 == 0) {
        // 0x80042EEC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_800432C0;
    }
    // 0x80042EEC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80042EF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042EF4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80042EF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80042EFC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80042F00: lbu         $a0, 0x447C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X447C);
    // 0x80042F04: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80042F08: bne         $a0, $v0, L_800432C0
    if (ctx->r4 != ctx->r2) {
        // 0x80042F0C: nop
    
            goto L_800432C0;
    }
    // 0x80042F0C: nop

    // 0x80042F10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80042F14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042F18: lbu         $v0, 0x447B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447B);
    // 0x80042F1C: bne         $v0, $a0, L_800432C0
    if (ctx->r2 != ctx->r4) {
        // 0x80042F20: nop
    
            goto L_800432C0;
    }
    // 0x80042F20: nop

    // 0x80042F24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80042F28: addiu       $v1, $v1, 0x7B76
    ctx->r3 = ADD32(ctx->r3, 0X7B76);
    // 0x80042F2C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80042F30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80042F34: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80042F38: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80042F3C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80042F40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042F44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042F48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042F4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80042F50: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80042F54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80042F58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80042F5C: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80042F60: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80042F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042F68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042F6C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80042F70: sb          $v0, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = ctx->r2;
    // 0x80042F74: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80042F78: bne         $v0, $zero, L_80042F94
    if (ctx->r2 != 0) {
        // 0x80042F7C: nop
    
            goto L_80042F94;
    }
    // 0x80042F7C: nop

    // 0x80042F80: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80042F84: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80042F88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80042F8C: j           L_80042FA4
    // 0x80042F90: sb          $v0, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r2;
        goto L_80042FA4;
    // 0x80042F90: sb          $v0, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r2;
L_80042F94:
    // 0x80042F94: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80042F98: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80042F9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80042FA0: sb          $v0, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r2;
L_80042FA4:
    // 0x80042FA4: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80042FA8: j           L_800432B8
    // 0x80042FAC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
        goto L_800432B8;
    // 0x80042FAC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80042FB0:
    // 0x80042FB0: bne         $a0, $v0, L_800432C0
    if (ctx->r4 != ctx->r2) {
        // 0x80042FB4: nop
    
            goto L_800432C0;
    }
    // 0x80042FB4: nop

L_80042FB8:
    // 0x80042FB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80042FBC: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x80042FC0: bne         $v0, $zero, L_800432C0
    if (ctx->r2 != 0) {
        // 0x80042FC4: nop
    
            goto L_800432C0;
    }
    // 0x80042FC4: nop

    // 0x80042FC8: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80042FCC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80042FD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042FD4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80042FD8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042FDC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80042FE0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80042FE4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80042FE8: lbu         $a0, 0x447C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X447C);
    // 0x80042FEC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80042FF0: bne         $a0, $v0, L_80043098
    if (ctx->r4 != ctx->r2) {
        // 0x80042FF4: nop
    
            goto L_80043098;
    }
    // 0x80042FF4: nop

    // 0x80042FF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80042FFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043000: lbu         $v0, 0x447B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447B);
    // 0x80043004: bne         $v0, $a0, L_80043098
    if (ctx->r2 != ctx->r4) {
        // 0x80043008: nop
    
            goto L_80043098;
    }
    // 0x80043008: nop

    // 0x8004300C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80043010: addiu       $v1, $v1, 0x7B76
    ctx->r3 = ADD32(ctx->r3, 0X7B76);
    // 0x80043014: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80043018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004301C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80043020: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80043024: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80043028: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004302C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043030: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043034: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043038: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8004303C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043040: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80043044: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80043048: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x8004304C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043050: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043054: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80043058: sb          $v0, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = ctx->r2;
    // 0x8004305C: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80043060: bne         $v0, $zero, L_8004307C
    if (ctx->r2 != 0) {
        // 0x80043064: nop
    
            goto L_8004307C;
    }
    // 0x80043064: nop

    // 0x80043068: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x8004306C: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80043070: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043074: j           L_8004308C
    // 0x80043078: sb          $v0, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r2;
        goto L_8004308C;
    // 0x80043078: sb          $v0, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r2;
L_8004307C:
    // 0x8004307C: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80043080: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80043084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043088: sb          $v0, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r2;
L_8004308C:
    // 0x8004308C: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80043090: jal         0x8000637C
    // 0x80043094: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80043094: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_3:
L_80043098:
    // 0x80043098: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004309C: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x800430A0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800430A4: beq         $v0, $zero, L_8004311C
    if (ctx->r2 == 0) {
        // 0x800430A8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8004311C;
    }
    // 0x800430A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800430AC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x800430B0: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800430B4: lw          $t0, -0xBF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XBF0);
    // 0x800430B8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800430BC: addiu       $a0, $a0, -0x2F50
    ctx->r4 = ADD32(ctx->r4, -0X2F50);
    // 0x800430C0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800430C4: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800430C8: sra         $v1, $v1, 19
    ctx->r3 = S32(SIGNED(ctx->r3) >> 19);
    // 0x800430CC: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x800430D0: sll         $v0, $v0, 25
    ctx->r2 = S32(ctx->r2 << 25);
    // 0x800430D4: sra         $a2, $v0, 20
    ctx->r6 = S32(SIGNED(ctx->r2) >> 20);
L_800430D8:
    // 0x800430D8: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x800430DC: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800430E0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800430E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800430E8: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x800430EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800430F0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800430F4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800430F8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800430FC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80043100: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80043104: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80043108: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x8004310C: bne         $a0, $zero, L_800430D8
    if (ctx->r4 != 0) {
        // 0x80043110: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_800430D8;
    }
    // 0x80043110: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80043114: j           L_8004318C
    // 0x80043118: nop

        goto L_8004318C;
    // 0x80043118: nop

L_8004311C:
    // 0x8004311C: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80043120: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80043124: lw          $t0, -0xBF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XBF0);
    // 0x80043128: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004312C: addiu       $a0, $a0, -0x2F50
    ctx->r4 = ADD32(ctx->r4, -0X2F50);
    // 0x80043130: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80043134: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x80043138: sra         $v1, $v1, 19
    ctx->r3 = S32(SIGNED(ctx->r3) >> 19);
    // 0x8004313C: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x80043140: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80043144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80043148: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004314C: sra         $a2, $v0, 20
    ctx->r6 = S32(SIGNED(ctx->r2) >> 20);
L_80043150:
    // 0x80043150: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80043154: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80043158: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8004315C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80043160: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80043164: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80043168: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004316C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80043170: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043174: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80043178: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8004317C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80043180: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80043184: bne         $a0, $zero, L_80043150
    if (ctx->r4 != 0) {
        // 0x80043188: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_80043150;
    }
    // 0x80043188: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004318C:
    // 0x8004318C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80043190: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80043194: beq         $v0, $zero, L_800431AC
    if (ctx->r2 == 0) {
        // 0x80043198: nop
    
            goto L_800431AC;
    }
    // 0x80043198: nop

    // 0x8004319C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800431A0: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x800431A4: bne         $v0, $zero, L_800432C0
    if (ctx->r2 != 0) {
        // 0x800431A8: nop
    
            goto L_800432C0;
    }
    // 0x800431A8: nop

L_800431AC:
    // 0x800431AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800431B0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800431B4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800431B8: bne         $v1, $v0, L_800432C0
    if (ctx->r3 != ctx->r2) {
        // 0x800431BC: nop
    
            goto L_800432C0;
    }
    // 0x800431BC: nop

    // 0x800431C0: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x800431C4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800431C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800431CC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800431D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800431D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800431D8: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x800431DC: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x800431E0: beq         $v0, $zero, L_800432C0
    if (ctx->r2 == 0) {
        // 0x800431E4: nop
    
            goto L_800432C0;
    }
    // 0x800431E4: nop

    // 0x800431E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800431EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800431F0: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x800431F4: beq         $v0, $zero, L_800432C0
    if (ctx->r2 == 0) {
        // 0x800431F8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800432C0;
    }
    // 0x800431F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800431FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043200: lhu         $v0, 0x7B76($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7B76);
    // 0x80043204: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80043208: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004320C: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
    // 0x80043210: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80043214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043218: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004321C: sb          $zero, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = 0;
    // 0x80043220: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x80043224: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80043228: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004322C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043230: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043234: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043238: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x8004323C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043240: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80043244: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80043248: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x8004324C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80043250: addiu       $a0, $a0, -0x2F50
    ctx->r4 = ADD32(ctx->r4, -0X2F50);
    // 0x80043254: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80043258: lw          $t0, -0xBF4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XBF4);
    // 0x8004325C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80043260: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80043264: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80043268: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x8004326C: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x80043270: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
L_80043274:
    // 0x80043274: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80043278: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x8004327C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80043280: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80043284: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80043288: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004328C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80043290: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80043294: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043298: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8004329C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800432A0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800432A4: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x800432A8: bne         $a0, $zero, L_80043274
    if (ctx->r4 != 0) {
        // 0x800432AC: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_80043274;
    }
    // 0x800432AC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800432B0: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x800432B4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800432B8:
    // 0x800432B8: jal         0x8000637C
    // 0x800432BC: nop

    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x800432BC: nop

    after_4:
L_800432C0:
    // 0x800432C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800432C4: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800432C8: sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // 0x800432CC: bne         $v0, $zero, L_800434EC
    if (ctx->r2 != 0) {
        // 0x800432D0: nop
    
            goto L_800434EC;
    }
    // 0x800432D0: nop

    // 0x800432D4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x800432D8: bne         $v0, $zero, L_800433E4
    if (ctx->r2 != 0) {
        // 0x800432DC: addiu       $a1, $zero, 0xE0
        ctx->r5 = ADD32(0, 0XE0);
            goto L_800433E4;
    }
    // 0x800432DC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x800432E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800432E4: addiu       $a0, $a0, -0x23F8
    ctx->r4 = ADD32(ctx->r4, -0X23F8);
    // 0x800432E8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x800432EC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x800432F0: jal         0x8004EC44
    // 0x800432F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_5;
    // 0x800432F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x800432F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800432FC: addiu       $a0, $a0, -0x23F4
    ctx->r4 = ADD32(ctx->r4, -0X23F4);
    // 0x80043300: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x80043304: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043308: jal         0x8004EC44
    // 0x8004330C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_6;
    // 0x8004330C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x80043310: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043314: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    // 0x80043318: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8004331C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043320: jal         0x8004EC44
    // 0x80043324: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_7;
    // 0x80043324: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x80043328: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004332C: addiu       $a0, $a0, -0x23F4
    ctx->r4 = ADD32(ctx->r4, -0X23F4);
    // 0x80043330: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80043334: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043338: jal         0x8004EC44
    // 0x8004333C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_8;
    // 0x8004333C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // 0x80043340: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043344: addiu       $a0, $a0, -0x23F8
    ctx->r4 = ADD32(ctx->r4, -0X23F8);
    // 0x80043348: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8004334C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043350: jal         0x8004EC44
    // 0x80043354: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_9;
    // 0x80043354: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // 0x80043358: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x8004335C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80043360: bne         $v0, $s0, L_80043378
    if (ctx->r2 != ctx->r16) {
        // 0x80043364: sltiu       $v0, $v0, 0x4
        ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
            goto L_80043378;
    }
    // 0x80043364: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80043368: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004336C: addiu       $a0, $a0, -0x23C8
    ctx->r4 = ADD32(ctx->r4, -0X23C8);
    // 0x80043370: j           L_800434E0
    // 0x80043374: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
        goto L_800434E0;
    // 0x80043374: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
L_80043378:
    // 0x80043378: bne         $v0, $zero, L_800433AC
    if (ctx->r2 != 0) {
        // 0x8004337C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800433AC;
    }
    // 0x8004337C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80043380: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80043384: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80043388: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x8004338C: jal         0x8004EBF4
    // 0x80043390: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EBF4(rdram, ctx);
        goto after_10;
    // 0x80043390: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_10:
    // 0x80043394: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    // 0x80043398: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004339C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800433A0: addiu       $a1, $a1, -0x23C4
    ctx->r5 = ADD32(ctx->r5, -0X23C4);
    // 0x800433A4: j           L_800433D0
    // 0x800433A8: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
        goto L_800433D0;
    // 0x800433A8: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
L_800433AC:
    // 0x800433AC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x800433B0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800433B4: jal         0x8004EBF4
    // 0x800433B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EBF4(rdram, ctx);
        goto after_11;
    // 0x800433B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x800433BC: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    // 0x800433C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800433C4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800433C8: addiu       $a1, $a1, -0x23C4
    ctx->r5 = ADD32(ctx->r5, -0X23C4);
    // 0x800433CC: subu        $a2, $s0, $a2
    ctx->r6 = SUB32(ctx->r16, ctx->r6);
L_800433D0:
    // 0x800433D0: jal         0x80066CA0
    // 0x800433D4: nop

    func_80066CA0(rdram, ctx);
        goto after_12;
    // 0x800433D4: nop

    after_12:
    // 0x800433D8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800433DC: j           L_800434E0
    // 0x800433E0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
        goto L_800434E0;
    // 0x800433E0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
L_800433E4:
    // 0x800433E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800433E8: addiu       $a0, $a0, -0x23F8
    ctx->r4 = ADD32(ctx->r4, -0X23F8);
    // 0x800433EC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x800433F0: jal         0x8004EC44
    // 0x800433F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_13;
    // 0x800433F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_13:
    // 0x800433F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800433FC: addiu       $a0, $a0, -0x23F4
    ctx->r4 = ADD32(ctx->r4, -0X23F4);
    // 0x80043400: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x80043404: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043408: jal         0x8004EC44
    // 0x8004340C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_14;
    // 0x8004340C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_14:
    // 0x80043410: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043414: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    // 0x80043418: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8004341C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043420: jal         0x8004EC44
    // 0x80043424: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_15;
    // 0x80043424: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_15:
    // 0x80043428: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004342C: addiu       $a0, $a0, -0x23F4
    ctx->r4 = ADD32(ctx->r4, -0X23F4);
    // 0x80043430: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x80043434: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043438: jal         0x8004EC44
    // 0x8004343C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_16;
    // 0x8004343C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_16:
    // 0x80043440: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043444: addiu       $a0, $a0, -0x23F8
    ctx->r4 = ADD32(ctx->r4, -0X23F8);
    // 0x80043448: addiu       $a1, $zero, 0x114
    ctx->r5 = ADD32(0, 0X114);
    // 0x8004344C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80043450: jal         0x8004EC44
    // 0x80043454: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_17;
    // 0x80043454: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_17:
    // 0x80043458: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x8004345C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80043460: bne         $v0, $s0, L_80043478
    if (ctx->r2 != ctx->r16) {
        // 0x80043464: sltiu       $v0, $v0, 0x4
        ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
            goto L_80043478;
    }
    // 0x80043464: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80043468: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004346C: addiu       $a0, $a0, -0x23C8
    ctx->r4 = ADD32(ctx->r4, -0X23C8);
    // 0x80043470: j           L_800434E0
    // 0x80043474: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
        goto L_800434E0;
    // 0x80043474: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
L_80043478:
    // 0x80043478: bne         $v0, $zero, L_800434AC
    if (ctx->r2 != 0) {
        // 0x8004347C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800434AC;
    }
    // 0x8004347C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80043480: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80043484: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    // 0x80043488: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x8004348C: jal         0x8004EBF4
    // 0x80043490: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EBF4(rdram, ctx);
        goto after_18;
    // 0x80043490: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_18:
    // 0x80043494: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    // 0x80043498: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004349C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800434A0: addiu       $a1, $a1, -0x23C4
    ctx->r5 = ADD32(ctx->r5, -0X23C4);
    // 0x800434A4: j           L_800434D0
    // 0x800434A8: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
        goto L_800434D0;
    // 0x800434A8: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
L_800434AC:
    // 0x800434AC: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    // 0x800434B0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800434B4: jal         0x8004EBF4
    // 0x800434B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EBF4(rdram, ctx);
        goto after_19;
    // 0x800434B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
    // 0x800434BC: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    // 0x800434C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800434C4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800434C8: addiu       $a1, $a1, -0x23C4
    ctx->r5 = ADD32(ctx->r5, -0X23C4);
    // 0x800434CC: subu        $a2, $s0, $a2
    ctx->r6 = SUB32(ctx->r16, ctx->r6);
L_800434D0:
    // 0x800434D0: jal         0x80066CA0
    // 0x800434D4: nop

    func_80066CA0(rdram, ctx);
        goto after_20;
    // 0x800434D4: nop

    after_20:
    // 0x800434D8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800434DC: addiu       $a1, $zero, 0x106
    ctx->r5 = ADD32(0, 0X106);
L_800434E0:
    // 0x800434E0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800434E4: jal         0x8004EC44
    // 0x800434E8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_21;
    // 0x800434E8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_21:
L_800434EC:
    // 0x800434EC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800434F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800434F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800434F8: jr          $ra
    // 0x800434FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800434FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80043500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043504: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80043508: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8004350C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043510: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80043514: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80043518: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8004351C: beq         $a0, $zero, L_800436D8
    if (ctx->r4 == 0) {
        // 0x80043520: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800436D8;
    }
    // 0x80043520: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80043524: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80043528: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8004352C: bne         $v1, $v0, L_80043570
    if (ctx->r3 != ctx->r2) {
        // 0x80043530: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80043570;
    }
    // 0x80043530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043534: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x80043538: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8004353C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043540: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80043544: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043548: lw          $v1, -0x6CC8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6CC8);
    // 0x8004354C: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043550: beq         $v0, $zero, L_80043560
    if (ctx->r2 == 0) {
        // 0x80043554: addiu       $v0, $a0, -0x6
        ctx->r2 = ADD32(ctx->r4, -0X6);
            goto L_80043560;
    }
    // 0x80043554: addiu       $v0, $a0, -0x6
    ctx->r2 = ADD32(ctx->r4, -0X6);
    // 0x80043558: j           L_800435A4
    // 0x8004355C: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
        goto L_800435A4;
    // 0x8004355C: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
L_80043560:
    // 0x80043560: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80043564: sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // 0x80043568: j           L_800435A4
    // 0x8004356C: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
        goto L_800435A4;
    // 0x8004356C: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
L_80043570:
    // 0x80043570: bne         $a0, $v0, L_800435A4
    if (ctx->r4 != ctx->r2) {
        // 0x80043574: nop
    
            goto L_800435A4;
    }
    // 0x80043574: nop

    // 0x80043578: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x8004357C: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x80043580: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043584: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80043588: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004358C: lw          $a0, -0x6CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC8);
    // 0x80043590: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80043594: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80043598: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // 0x8004359C: sb          $v1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r3;
    // 0x800435A0: sw          $a0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r4;
L_800435A4:
    // 0x800435A4: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x800435A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800435AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800435B0: lb          $v1, 0x5($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X5);
    // 0x800435B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800435B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800435BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800435C0: lw          $v0, -0x6CC4($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6CC4);
    // 0x800435C4: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x800435C8: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800435CC: beq         $v1, $zero, L_800435E8
    if (ctx->r3 == 0) {
        // 0x800435D0: sw          $v0, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r2;
            goto L_800435E8;
    }
    // 0x800435D0: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x800435D4: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x800435D8: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x800435DC: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
    // 0x800435E0: j           L_800435F4
    // 0x800435E4: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
        goto L_800435F4;
    // 0x800435E4: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
L_800435E8:
    // 0x800435E8: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x800435EC: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x800435F0: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_800435F4:
    // 0x800435F4: lbu         $v1, 0x6($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X6);
    // 0x800435F8: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x800435FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80043600: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80043604: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80043608: lw          $a0, 0x7060($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7060);
    // 0x8004360C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043610: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80043614: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80043618: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8004361C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80043620: lw          $v1, 0x70D0($at)
    ctx->r3 = MEM_W(ctx->r1, 0X70D0);
    // 0x80043624: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x80043628: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x8004362C: lbu         $a0, 0x2($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X2);
    // 0x80043630: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80043634: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043638: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8004363C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80043640: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80043644: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80043648: addiu       $s1, $s2, 0xC
    ctx->r17 = ADD32(ctx->r18, 0XC);
    // 0x8004364C: jal         0x80053234
    // 0x80043650: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80043650: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80043654: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80043658: jal         0x80051C7C
    // 0x8004365C: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x8004365C: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    after_1:
    // 0x80043660: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x80043664: lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X7);
    // 0x80043668: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004366C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80043670: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80043674: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80043678: beq         $v0, $zero, L_80043688
    if (ctx->r2 == 0) {
        // 0x8004367C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80043688;
    }
    // 0x8004367C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80043680: j           L_800436BC
    // 0x80043684: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
        goto L_800436BC;
    // 0x80043684: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80043688:
    // 0x80043688: lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8);
    // 0x8004368C: sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
    // 0x80043690: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80043694: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80043698: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8004369C: addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // 0x800436A0: sh          $v1, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r3;
    // 0x800436A4: lb          $v0, 0x1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1);
    // 0x800436A8: beq         $v0, $zero, L_800436BC
    if (ctx->r2 == 0) {
        // 0x800436AC: nop
    
            goto L_800436BC;
    }
    // 0x800436AC: nop

    // 0x800436B0: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800436B4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800436B8: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
L_800436BC:
    // 0x800436BC: lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3);
    // 0x800436C0: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x800436C4: beq         $v1, $v0, L_800436D8
    if (ctx->r3 == ctx->r2) {
        // 0x800436C8: nop
    
            goto L_800436D8;
    }
    // 0x800436C8: nop

    // 0x800436CC: sb          $v1, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r3;
    // 0x800436D0: sh          $zero, 0x8($s2)
    MEM_H(0X8, ctx->r18) = 0;
    // 0x800436D4: sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
L_800436D8:
    // 0x800436D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800436DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800436E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800436E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800436E8: jr          $ra
    // 0x800436EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800436EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800436F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800436F4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800436F8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800436FC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80043700: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80043704: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80043708: beq         $v0, $zero, L_800437E8
    if (ctx->r2 == 0) {
        // 0x8004370C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800437E8;
    }
    // 0x8004370C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80043710: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80043714: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80043718: bne         $v1, $v0, L_8004374C
    if (ctx->r3 != ctx->r2) {
        // 0x8004371C: nop
    
            goto L_8004374C;
    }
    // 0x8004371C: nop

    // 0x80043720: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043724: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80043728: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004372C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043730: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80043734: lw          $v0, -0x6C94($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6C94);
    // 0x80043738: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004373C: beq         $v0, $zero, L_80043764
    if (ctx->r2 == 0) {
        // 0x80043740: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_80043764;
    }
    // 0x80043740: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x80043744: j           L_80043764
    // 0x80043748: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80043764;
    // 0x80043748: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_8004374C:
    // 0x8004374C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043750: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043754: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043758: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004375C: lw          $v0, -0x6C94($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6C94);
    // 0x80043760: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80043764:
    // 0x80043764: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043768: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004376C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80043770: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043774: lw          $v1, -0x6C90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6C90);
    // 0x80043778: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8004377C: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80043780: bne         $v0, $zero, L_800437A0
    if (ctx->r2 != 0) {
        // 0x80043784: sw          $v1, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r3;
            goto L_800437A0;
    }
    // 0x80043784: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
    // 0x80043788: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004378C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80043790: nop

    // 0x80043794: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80043798: j           L_800437BC
    // 0x8004379C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_800437BC;
    // 0x8004379C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800437A0:
    // 0x800437A0: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x800437A4: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x800437A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800437AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800437B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800437B4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800437B8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_800437BC:
    // 0x800437BC: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800437C0: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x800437C4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800437C8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800437CC: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x800437D0: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800437D4: jal         0x80053234
    // 0x800437D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x800437D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800437DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800437E0: jal         0x80051C7C
    // 0x800437E4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x800437E4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
L_800437E8:
    // 0x800437E8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800437EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800437F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800437F4: jr          $ra
    // 0x800437F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800437F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800437FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800437FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80043800: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80043804: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043808: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004380C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043810: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80043814: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80043818: addiu       $s6, $zero, 0xD
    ctx->r22 = ADD32(0, 0XD);
    // 0x8004381C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80043820: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80043824: addiu       $s5, $s5, 0x707C
    ctx->r21 = ADD32(ctx->r21, 0X707C);
    // 0x80043828: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004382C: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x80043830: addiu       $s2, $s2, 0x4478
    ctx->r18 = ADD32(ctx->r18, 0X4478);
    // 0x80043834: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80043838: addiu       $v0, $v0, -0x6CC8
    ctx->r2 = ADD32(ctx->r2, -0X6CC8);
    // 0x8004383C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043840: addiu       $s4, $v0, 0x4
    ctx->r20 = ADD32(ctx->r2, 0X4);
    // 0x80043844: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043848: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8004384C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043850: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80043854: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_80043858:
    // 0x80043858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004385C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043860: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043864: sb          $v0, 0x4478($at)
    MEM_B(0X4478, ctx->r1) = ctx->r2;
    // 0x80043868: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004386C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043870: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043874: sb          $zero, 0x4479($at)
    MEM_B(0X4479, ctx->r1) = 0;
    // 0x80043878: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004387C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043880: sb          $v0, 0x447A($at)
    MEM_B(0X447A, ctx->r1) = ctx->r2;
    // 0x80043884: sb          $s6, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r22;
    // 0x80043888: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004388C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043890: sb          $s6, 0x447C($at)
    MEM_B(0X447C, ctx->r1) = ctx->r22;
    // 0x80043894: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043898: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004389C: beq         $s1, $zero, L_800438C0
    if (ctx->r17 == 0) {
        // 0x800438A0: sb          $s1, 0x447D($at)
        MEM_B(0X447D, ctx->r1) = ctx->r17;
            goto L_800438C0;
    }
    // 0x800438A0: sb          $s1, 0x447D($at)
    MEM_B(0X447D, ctx->r1) = ctx->r17;
    // 0x800438A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800438A8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800438AC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800438B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800438B4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800438B8: j           L_800438D4
    // 0x800438BC: sb          $v0, 0x447E($at)
    MEM_B(0X447E, ctx->r1) = ctx->r2;
        goto L_800438D4;
    // 0x800438BC: sb          $v0, 0x447E($at)
    MEM_B(0X447E, ctx->r1) = ctx->r2;
L_800438C0:
    // 0x800438C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800438C4: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800438C8: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800438CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800438D0: sb          $v0, 0x447E($at)
    MEM_B(0X447E, ctx->r1) = ctx->r2;
L_800438D4:
    // 0x800438D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800438D8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800438DC: sh          $zero, 0x4480($at)
    MEM_H(0X4480, ctx->r1) = 0;
    // 0x800438E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800438E4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800438E8: sb          $zero, 0x447F($at)
    MEM_B(0X447F, ctx->r1) = 0;
    // 0x800438EC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800438F0: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x800438F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800438F8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800438FC: sw          $v0, 0x448C($at)
    MEM_W(0X448C, ctx->r1) = ctx->r2;
    // 0x80043900: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80043904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043908: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004390C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043910: sw          $v0, 0x4490($at)
    MEM_W(0X4490, ctx->r1) = ctx->r2;
    // 0x80043914: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
    // 0x80043918: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004391C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043920: sh          $zero, 0x4488($at)
    MEM_H(0X4488, ctx->r1) = 0;
    // 0x80043924: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80043928: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004392C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043930: swc1        $f20, 0x4494($at)
    MEM_W(0X4494, ctx->r1) = ctx->f20.u32l;
    // 0x80043934: sw          $zero, 0x30($s2)
    MEM_W(0X30, ctx->r18) = 0;
    // 0x80043938: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004393C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80043940: sw          $zero, 0x44A4($at)
    MEM_W(0X44A4, ctx->r1) = 0;
    // 0x80043944: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043948: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004394C: sw          $zero, 0x449C($at)
    MEM_W(0X449C, ctx->r1) = 0;
    // 0x80043950: lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X6);
    // 0x80043954: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80043958: lw          $a0, -0x6350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6350);
    // 0x8004395C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80043960: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80043964: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80043968: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004396C: jal         0x8005334C
    // 0x80043970: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80043970: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_0:
    // 0x80043974: beq         $s1, $zero, L_800439A0
    if (ctx->r17 == 0) {
        // 0x80043978: nop
    
            goto L_800439A0;
    }
    // 0x80043978: nop

    // 0x8004397C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043980: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80043984: lbu         $v0, 0x447E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447E);
    // 0x80043988: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004398C: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80043990: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80043994: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x80043998: j           L_800439BC
    // 0x8004399C: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
        goto L_800439BC;
    // 0x8004399C: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
L_800439A0:
    // 0x800439A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800439A4: lbu         $v0, 0x447E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447E);
    // 0x800439A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800439AC: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800439B0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800439B4: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x800439B8: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_800439BC:
    // 0x800439BC: jal         0x80006D98
    // 0x800439C0: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x800439C0: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    after_1:
    // 0x800439C4: addiu       $s2, $s2, 0x34
    ctx->r18 = ADD32(ctx->r18, 0X34);
    // 0x800439C8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800439CC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800439D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800439D4: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800439D8: bne         $v0, $zero, L_80043858
    if (ctx->r2 != 0) {
        // 0x800439DC: addiu       $s0, $s0, 0x34
        ctx->r16 = ADD32(ctx->r16, 0X34);
            goto L_80043858;
    }
    // 0x800439DC: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x800439E0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800439E4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800439E8: addiu       $t2, $t2, 0x70F4
    ctx->r10 = ADD32(ctx->r10, 0X70F4);
    // 0x800439EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800439F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800439F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800439F8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800439FC: addiu       $v0, $v0, -0x6C94
    ctx->r2 = ADD32(ctx->r2, -0X6C94);
    // 0x80043A00: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x80043A04: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80043A08: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80043A0C: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    // 0x80043A10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80043A14: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80043A18: addiu       $a2, $a2, -0x6CB8
    ctx->r6 = ADD32(ctx->r6, -0X6CB8);
    // 0x80043A1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A20: sb          $zero, 0x515D($at)
    MEM_B(0X515D, ctx->r1) = 0;
    // 0x80043A24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A28: sb          $zero, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = 0;
L_80043A2C:
    // 0x80043A2C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80043A30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043A34: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80043A38: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x80043A3C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80043A40: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80043A44: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80043A48: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80043A4C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80043A50: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80043A54: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80043A58: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x80043A5C: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80043A60: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80043A64: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80043A68: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80043A6C: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80043A70: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80043A74: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80043A78: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80043A7C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80043A80: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80043A84: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80043A88: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x80043A8C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80043A90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80043A94: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80043A98: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x80043A9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043AA0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80043AA4: sw          $v0, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r2;
    // 0x80043AA8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80043AAC: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80043AB0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80043AB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043AB8: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80043ABC: sw          $v0, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r2;
    // 0x80043AC0: slti        $v0, $s1, 0x7
    ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x80043AC4: bne         $v0, $zero, L_80043A2C
    if (ctx->r2 != 0) {
        // 0x80043AC8: addiu       $a1, $a1, 0x34
        ctx->r5 = ADD32(ctx->r5, 0X34);
            goto L_80043A2C;
    }
    // 0x80043AC8: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    // 0x80043ACC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80043AD0: lw          $v0, -0x6C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C9C);
    // 0x80043AD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043AD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80043ADC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80043AE0: lw          $v1, -0x6C5C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6C5C);
    // 0x80043AE4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80043AE8: lw          $a0, -0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C58);
    // 0x80043AEC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80043AF0: lbu         $a3, 0x7BA4($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7BA4);
    // 0x80043AF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043AF8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80043AFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043B00: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80043B04: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80043B08: lbu         $a1, 0x70F7($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X70F7);
    // 0x80043B0C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80043B10: addiu       $v1, $v1, 0x140
    ctx->r3 = ADD32(ctx->r3, 0X140);
    // 0x80043B14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B18: sw          $zero, -0x78F0($at)
    MEM_W(-0X78F0, ctx->r1) = 0;
    // 0x80043B1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B20: sw          $v1, -0x78F0($at)
    MEM_W(-0X78F0, ctx->r1) = ctx->r3;
    // 0x80043B24: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80043B28: addiu       $v1, $v1, 0x70F4
    ctx->r3 = ADD32(ctx->r3, 0X70F4);
    // 0x80043B2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B30: sb          $a2, -0x7904($at)
    MEM_B(-0X7904, ctx->r1) = ctx->r6;
    // 0x80043B34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B38: sb          $zero, -0x7903($at)
    MEM_B(-0X7903, ctx->r1) = 0;
    // 0x80043B3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B40: sb          $zero, -0x7902($at)
    MEM_B(-0X7902, ctx->r1) = 0;
    // 0x80043B44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B48: sb          $zero, -0x7900($at)
    MEM_B(-0X7900, ctx->r1) = 0;
    // 0x80043B4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B50: sb          $zero, -0x78FF($at)
    MEM_B(-0X78FF, ctx->r1) = 0;
    // 0x80043B54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B58: sb          $v0, -0x78FE($at)
    MEM_B(-0X78FE, ctx->r1) = ctx->r2;
    // 0x80043B5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B60: sh          $zero, -0x78FC($at)
    MEM_H(-0X78FC, ctx->r1) = 0;
    // 0x80043B64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B68: sb          $zero, -0x78FD($at)
    MEM_B(-0X78FD, ctx->r1) = 0;
    // 0x80043B6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B70: sw          $zero, -0x78EC($at)
    MEM_W(-0X78EC, ctx->r1) = 0;
    // 0x80043B74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B78: sh          $zero, -0x78F2($at)
    MEM_H(-0X78F2, ctx->r1) = 0;
    // 0x80043B7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B80: sh          $zero, -0x78F4($at)
    MEM_H(-0X78F4, ctx->r1) = 0;
    // 0x80043B84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B88: swc1        $f0, -0x78E4($at)
    MEM_W(-0X78E4, ctx->r1) = ctx->f0.u32l;
    // 0x80043B8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B90: swc1        $f0, -0x78E8($at)
    MEM_W(-0X78E8, ctx->r1) = ctx->f0.u32l;
    // 0x80043B94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043B98: sw          $zero, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = 0;
    // 0x80043B9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BA0: sw          $zero, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = 0;
    // 0x80043BA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BA8: sw          $zero, -0x78E0($at)
    MEM_W(-0X78E0, ctx->r1) = 0;
    // 0x80043BAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BB0: sw          $a0, -0x78EC($at)
    MEM_W(-0X78EC, ctx->r1) = ctx->r4;
    // 0x80043BB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BB8: sb          $t0, -0x7903($at)
    MEM_B(-0X7903, ctx->r1) = ctx->r8;
    // 0x80043BBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BC0: beq         $a3, $zero, L_80043BDC
    if (ctx->r7 == 0) {
        // 0x80043BC4: sb          $a1, -0x7901($at)
        MEM_B(-0X7901, ctx->r1) = ctx->r5;
            goto L_80043BDC;
    }
    // 0x80043BC4: sb          $a1, -0x7901($at)
    MEM_B(-0X7901, ctx->r1) = ctx->r5;
    // 0x80043BC8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043BCC: lbu         $v0, 0x25F6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25F6);
    // 0x80043BD0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80043BD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043BD8: sb          $v0, -0x7903($at)
    MEM_B(-0X7903, ctx->r1) = ctx->r2;
L_80043BDC:
    // 0x80043BDC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80043BE0: lw          $v0, -0x6C98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C98);
    // 0x80043BE4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80043BE8: lw          $a0, -0x6C50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6C50);
    // 0x80043BEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043BF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043BF4: lbu         $a1, 0x3($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3);
    // 0x80043BF8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80043BFC: lw          $v1, -0x6C54($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6C54);
    // 0x80043C00: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80043C04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C08: sb          $a2, -0x78D0($at)
    MEM_B(-0X78D0, ctx->r1) = ctx->r6;
    // 0x80043C0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C10: sb          $zero, -0x78CF($at)
    MEM_B(-0X78CF, ctx->r1) = 0;
    // 0x80043C14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C18: sb          $zero, -0x78CE($at)
    MEM_B(-0X78CE, ctx->r1) = 0;
    // 0x80043C1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C20: sb          $zero, -0x78CC($at)
    MEM_B(-0X78CC, ctx->r1) = 0;
    // 0x80043C24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C28: sb          $a2, -0x78CB($at)
    MEM_B(-0X78CB, ctx->r1) = ctx->r6;
    // 0x80043C2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C30: sb          $v0, -0x78CA($at)
    MEM_B(-0X78CA, ctx->r1) = ctx->r2;
    // 0x80043C34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C38: sh          $zero, -0x78C8($at)
    MEM_H(-0X78C8, ctx->r1) = 0;
    // 0x80043C3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C40: sb          $zero, -0x78C9($at)
    MEM_B(-0X78C9, ctx->r1) = 0;
    // 0x80043C44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C48: sw          $zero, -0x78B8($at)
    MEM_W(-0X78B8, ctx->r1) = 0;
    // 0x80043C4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C50: sw          $zero, -0x78BC($at)
    MEM_W(-0X78BC, ctx->r1) = 0;
    // 0x80043C54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C58: sh          $zero, -0x78BE($at)
    MEM_H(-0X78BE, ctx->r1) = 0;
    // 0x80043C5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C60: sh          $zero, -0x78C0($at)
    MEM_H(-0X78C0, ctx->r1) = 0;
    // 0x80043C64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C68: swc1        $f0, -0x78B0($at)
    MEM_W(-0X78B0, ctx->r1) = ctx->f0.u32l;
    // 0x80043C6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C70: swc1        $f0, -0x78B4($at)
    MEM_W(-0X78B4, ctx->r1) = ctx->f0.u32l;
    // 0x80043C74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C78: sw          $zero, -0x78A0($at)
    MEM_W(-0X78A0, ctx->r1) = 0;
    // 0x80043C7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C80: sw          $zero, -0x78A4($at)
    MEM_W(-0X78A4, ctx->r1) = 0;
    // 0x80043C84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C88: sw          $zero, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = 0;
    // 0x80043C8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C90: sw          $a0, -0x78B8($at)
    MEM_W(-0X78B8, ctx->r1) = ctx->r4;
    // 0x80043C94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043C98: sb          $t0, -0x78CF($at)
    MEM_B(-0X78CF, ctx->r1) = ctx->r8;
    // 0x80043C9C: addiu       $v1, $v1, 0x140
    ctx->r3 = ADD32(ctx->r3, 0X140);
    // 0x80043CA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043CA4: sw          $v1, -0x78BC($at)
    MEM_W(-0X78BC, ctx->r1) = ctx->r3;
    // 0x80043CA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043CAC: beq         $a3, $zero, L_80043CC8
    if (ctx->r7 == 0) {
        // 0x80043CB0: sb          $a1, -0x78CD($at)
        MEM_B(-0X78CD, ctx->r1) = ctx->r5;
            goto L_80043CC8;
    }
    // 0x80043CB0: sb          $a1, -0x78CD($at)
    MEM_B(-0X78CD, ctx->r1) = ctx->r5;
    // 0x80043CB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043CB8: lbu         $v0, 0x7A46($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A46);
    // 0x80043CBC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80043CC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80043CC4: sb          $v0, -0x78CF($at)
    MEM_B(-0X78CF, ctx->r1) = ctx->r2;
L_80043CC8:
    // 0x80043CC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80043CCC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80043CD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80043CD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043CD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043CDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043CE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043CE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043CE8: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80043CEC: jr          $ra
    // 0x80043CF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80043CF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80043CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043CF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80043CF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80043CFC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80043D00: addiu       $s0, $s0, 0x4478
    ctx->r16 = ADD32(ctx->r16, 0X4478);
    // 0x80043D04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043D08: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80043D0C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80043D10: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80043D14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80043D18: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80043D1C: jal         0x80043500
    // 0x80043D20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80043500(rdram, ctx);
        goto after_0;
    // 0x80043D20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80043D24: jal         0x80043500
    // 0x80043D28: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_80043500(rdram, ctx);
        goto after_1;
    // 0x80043D28: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_1:
    // 0x80043D2C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80043D30: addiu       $s0, $s0, -0x7904
    ctx->r16 = ADD32(ctx->r16, -0X7904);
    // 0x80043D34: jal         0x80042D2C
    // 0x80043D38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80042D2C(rdram, ctx);
        goto after_2;
    // 0x80043D38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80043D3C: jal         0x80042D2C
    // 0x80043D40: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_80042D2C(rdram, ctx);
        goto after_3;
    // 0x80043D40: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_3:
    // 0x80043D44: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80043D48: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80043D4C: addiu       $s3, $s3, -0x6C94
    ctx->r19 = ADD32(ctx->r19, -0X6C94);
    // 0x80043D50: addiu       $s4, $s3, 0x4
    ctx->r20 = ADD32(ctx->r19, 0X4);
    // 0x80043D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043D58: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80043D5C: sll         $v1, $s2, 24
    ctx->r3 = S32(ctx->r18 << 24);
L_80043D60:
    // 0x80043D60: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80043D64: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80043D68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043D6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043D70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043D74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043D78: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x80043D7C: addiu       $v1, $v1, -0x7A70
    ctx->r3 = ADD32(ctx->r3, -0X7A70);
    // 0x80043D80: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80043D84: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80043D88: beq         $v0, $zero, L_80043E50
    if (ctx->r2 == 0) {
        // 0x80043D8C: addiu       $v0, $s2, 0x1
        ctx->r2 = ADD32(ctx->r18, 0X1);
            goto L_80043E50;
    }
    // 0x80043D8C: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x80043D90: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80043D94: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80043D98: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80043D9C: bne         $v1, $v0, L_80043DCC
    if (ctx->r3 != ctx->r2) {
        // 0x80043DA0: nop
    
            goto L_80043DCC;
    }
    // 0x80043DA0: nop

    // 0x80043DA4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043DA8: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80043DAC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043DB0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80043DB4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80043DB8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043DBC: beq         $v0, $zero, L_80043DE0
    if (ctx->r2 == 0) {
        // 0x80043DC0: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_80043DE0;
    }
    // 0x80043DC0: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x80043DC4: j           L_80043DE0
    // 0x80043DC8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80043DE0;
    // 0x80043DC8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80043DCC:
    // 0x80043DCC: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043DD0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043DD4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80043DD8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80043DDC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80043DE0:
    // 0x80043DE0: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043DE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043DE8: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80043DEC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80043DF0: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80043DF4: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80043DF8: bne         $v0, $zero, L_80043E0C
    if (ctx->r2 != 0) {
        // 0x80043DFC: sw          $v1, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r3;
            goto L_80043E0C;
    }
    // 0x80043DFC: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
    // 0x80043E00: swc1        $f20, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f20.u32l;
    // 0x80043E04: j           L_80043E20
    // 0x80043E08: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
        goto L_80043E20;
    // 0x80043E08: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
L_80043E0C:
    // 0x80043E0C: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80043E10: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x80043E14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80043E18: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
    // 0x80043E1C: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
L_80043E20:
    // 0x80043E20: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80043E24: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80043E28: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80043E2C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80043E30: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80043E34: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80043E38: jal         0x80053234
    // 0x80043E3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_4;
    // 0x80043E3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80043E40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80043E44: jal         0x80051C7C
    // 0x80043E48: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_5;
    // 0x80043E48: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_5:
    // 0x80043E4C: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
L_80043E50:
    // 0x80043E50: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80043E54: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80043E58: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80043E5C: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80043E60: bne         $v0, $zero, L_80043D60
    if (ctx->r2 != 0) {
        // 0x80043E64: sll         $v1, $s2, 24
        ctx->r3 = S32(ctx->r18 << 24);
            goto L_80043D60;
    }
    // 0x80043E64: sll         $v1, $s2, 24
    ctx->r3 = S32(ctx->r18 << 24);
    // 0x80043E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80043E6C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80043E70: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80043E74: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80043E78: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80043E7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80043E80: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80043E84: jr          $ra
    // 0x80043E88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80043E88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80043E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E90: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043E94: jr          $ra
    // 0x80043E98: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    return;
    // 0x80043E98: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80043E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043EA0: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80043EA4: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x80043EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043EAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80043EB0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80043EB4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80043EB8: lw          $v0, -0x4760($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4760);
    // 0x80043EBC: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80043EC0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80043EC4: addu        $s0, $v0, $a1
    ctx->r16 = ADD32(ctx->r2, ctx->r5);
    // 0x80043EC8: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80043ECC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80043ED0: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x80043ED4: beq         $v1, $v0, L_80043EFC
    if (ctx->r3 == ctx->r2) {
        // 0x80043ED8: nop
    
            goto L_80043EFC;
    }
    // 0x80043ED8: nop

    // 0x80043EDC: jal         0x80006944
    // 0x80043EE0: nop

    func_80006944(rdram, ctx);
        goto after_0;
    // 0x80043EE0: nop

    after_0:
    // 0x80043EE4: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80043EE8: jal         0x800067C8
    // 0x80043EEC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x80043EEC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_1:
    // 0x80043EF0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80043EF4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043EF8: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80043EFC:
    // 0x80043EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043F00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80043F04: jr          $ra
    // 0x80043F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80043F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80043F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043F0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043F10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043F14: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80043F18: addiu       $s1, $s1, 0x6AC9
    ctx->r17 = ADD32(ctx->r17, 0X6AC9);
    // 0x80043F1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043F20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043F24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043F28: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80043F2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043F30: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x80043F34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80043F38: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80043F3C: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // 0x80043F40: lw          $s2, -0x4AB8($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4AB8);
    // 0x80043F44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043F48: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80043F4C: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x80043F50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043F54: sb          $zero, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = 0;
    // 0x80043F58: jal         0x80017760
    // 0x80043F5C: addiu       $a0, $s1, -0x29
    ctx->r4 = ADD32(ctx->r17, -0X29);
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x80043F5C: addiu       $a0, $s1, -0x29
    ctx->r4 = ADD32(ctx->r17, -0X29);
    after_0:
    // 0x80043F60: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80043F64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043F68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043F6C: sb          $v0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r2;
    // 0x80043F70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043F74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043F78: sb          $v0, 0x6AB7($at)
    MEM_B(0X6AB7, ctx->r1) = ctx->r2;
    // 0x80043F7C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043F80: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x80043F84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043F88: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x80043F8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80043F90: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x80043F94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043F98: sh          $zero, 0x6AB8($at)
    MEM_H(0X6AB8, ctx->r1) = 0;
    // 0x80043F9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043FA0: sw          $zero, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = 0;
    // 0x80043FA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043FA8: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x80043FAC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80043FB0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80043FB4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80043FB8: lw          $v1, -0x4868($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4868);
    // 0x80043FBC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80043FC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043FC4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80043FC8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80043FCC: bne         $s0, $zero, L_80043FE4
    if (ctx->r16 != 0) {
        // 0x80043FD0: addiu       $v0, $zero, -0x20
        ctx->r2 = ADD32(0, -0X20);
            goto L_80043FE4;
    }
    // 0x80043FD0: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x80043FD4: addiu       $v0, $zero, -0x140
    ctx->r2 = ADD32(0, -0X140);
    // 0x80043FD8: sh          $zero, -0x25($s1)
    MEM_H(-0X25, ctx->r17) = 0;
    // 0x80043FDC: j           L_80043FF4
    // 0x80043FE0: sh          $v0, -0x1D($s1)
    MEM_H(-0X1D, ctx->r17) = ctx->r2;
        goto L_80043FF4;
    // 0x80043FE0: sh          $v0, -0x1D($s1)
    MEM_H(-0X1D, ctx->r17) = ctx->r2;
L_80043FE4:
    // 0x80043FE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043FE8: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
    // 0x80043FEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80043FF0: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
L_80043FF4:
    // 0x80043FF4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80043FF8: addiu       $a0, $a0, 0x6AC8
    ctx->r4 = ADD32(ctx->r4, 0X6AC8);
    // 0x80043FFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80044000: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80044004: ori         $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 | 0XFF;
    // 0x80044008: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004400C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80044010: bne         $v0, $v1, L_80044030
    if (ctx->r2 != ctx->r3) {
        // 0x80044014: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80044030;
    }
    // 0x80044014: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80044018: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8004401C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044020: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
    // 0x80044024: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044028: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x8004402C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
L_80044030:
    // 0x80044030: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80044034: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044038: sh          $v0, 0x6AA6($at)
    MEM_H(0X6AA6, ctx->r1) = ctx->r2;
    // 0x8004403C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044040: sh          $v0, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r2;
    // 0x80044044: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044048: sh          $v1, 0x6AAE($at)
    MEM_H(0X6AAE, ctx->r1) = ctx->r3;
    // 0x8004404C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044050: sh          $v1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r3;
    // 0x80044054: jal         0x80066D30
    // 0x80044058: addiu       $a0, $a0, -0x28
    ctx->r4 = ADD32(ctx->r4, -0X28);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x80044058: addiu       $a0, $a0, -0x28
    ctx->r4 = ADD32(ctx->r4, -0X28);
    after_1:
    // 0x8004405C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044060: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x80044064: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044068: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004406C: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80044070: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80044074: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x80044078: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004407C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044080: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044084: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044088: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8004408C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80044090: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80044094: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80044098: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004409C: addiu       $a1, $a1, -0x2338
    ctx->r5 = ADD32(ctx->r5, -0X2338);
    // 0x800440A0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800440A4: jal         0x80053078
    // 0x800440A8: addiu       $a2, $a2, 0x3040
    ctx->r6 = ADD32(ctx->r6, 0X3040);
    func_80053078(rdram, ctx);
        goto after_2;
    // 0x800440A8: addiu       $a2, $a2, 0x3040
    ctx->r6 = ADD32(ctx->r6, 0X3040);
    after_2:
    // 0x800440AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800440B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800440B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800440B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800440BC: jr          $ra
    // 0x800440C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800440C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800440C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800440C8: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x800440CC: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x800440D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800440D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800440D8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800440DC: lw          $a0, -0x6368($at)
    ctx->r4 = MEM_W(ctx->r1, -0X6368);
    // 0x800440E0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800440E4: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x800440E8: jal         0x8005334C
    // 0x800440EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x800440EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_0:
    // 0x800440F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800440F4: jr          $ra
    // 0x800440F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800440F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800440FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044100: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80044104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044108: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004410C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80044110: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044114: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x80044118: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004411C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80044120: lw          $v1, -0x4AB8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4AB8);
    // 0x80044124: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044128: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004412C: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x80044130: bne         $a2, $zero, L_80044150
    if (ctx->r6 != 0) {
        // 0x80044134: sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6 << 2);
            goto L_80044150;
    }
    // 0x80044134: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80044138: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004413C: lw          $a0, -0x6350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6350);
    // 0x80044140: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80044144: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80044148: j           L_80044190
    // 0x8004414C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
        goto L_80044190;
    // 0x8004414C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_80044150:
    // 0x80044150: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80044154: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80044158: lw          $v1, -0x4C70($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C70);
    // 0x8004415C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80044160: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80044164: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044168: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004416C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80044170: lw          $v1, -0x4C4C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C4C);
    // 0x80044174: lw          $v0, -0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4);
    // 0x80044178: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004417C: lw          $a0, 0x6AE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6AE4);
    // 0x80044180: addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // 0x80044184: lb          $a2, -0x1($v1)
    ctx->r6 = MEM_B(ctx->r3, -0X1);
    // 0x80044188: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8004418C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
L_80044190:
    // 0x80044190: jal         0x8005334C
    // 0x80044194: nop

    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80044194: nop

    after_0:
    // 0x80044198: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004419C: jr          $ra
    // 0x800441A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800441A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800441A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800441A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800441A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800441AC: addiu       $v0, $v0, 0x6B3A
    ctx->r2 = ADD32(ctx->r2, 0X6B3A);
    // 0x800441B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800441B4: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x800441B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800441BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800441C0: jal         0x80017760
    // 0x800441C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x800441C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x800441C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800441CC: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x800441D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800441D4: sh          $v0, 0x6B1A($at)
    MEM_H(0X6B1A, ctx->r1) = ctx->r2;
    // 0x800441D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800441DC: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x800441E0: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x800441E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800441E8: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x800441EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800441F0: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x800441F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800441F8: jal         0x80066D30
    // 0x800441FC: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x800441FC: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_1:
    // 0x80044200: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80044204: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80044208: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004420C: jal         0x80006D98
    // 0x80044210: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_2;
    // 0x80044210: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_2:
    // 0x80044214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044218: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004421C: jr          $ra
    // 0x80044220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80044220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80044224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044224: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80044228: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004422C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80044230: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044234: addiu       $v0, $v0, 0x6BAA
    ctx->r2 = ADD32(ctx->r2, 0X6BAA);
    // 0x80044238: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8004423C: addiu       $s1, $v0, -0x2A
    ctx->r17 = ADD32(ctx->r2, -0X2A);
    // 0x80044240: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80044244: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80044248: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8004424C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80044250: jal         0x80017760
    // 0x80044254: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x80044254: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x80044258: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004425C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044260: sb          $v0, 0x6B96($at)
    MEM_B(0X6B96, ctx->r1) = ctx->r2;
    // 0x80044264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044268: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8004426C: addiu       $s3, $s3, -0x2538
    ctx->r19 = ADD32(ctx->r19, -0X2538);
    // 0x80044270: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x80044274: addiu       $s2, $s2, -0x1DC0
    ctx->r18 = ADD32(ctx->r18, -0X1DC0);
    // 0x80044278: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8004427C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80044280: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x80044284: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044288: sb          $v0, 0x6B97($at)
    MEM_B(0X6B97, ctx->r1) = ctx->r2;
    // 0x8004428C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044290: sh          $zero, 0x6B98($at)
    MEM_H(0X6B98, ctx->r1) = 0;
    // 0x80044294: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044298: sw          $s3, 0x6BB0($at)
    MEM_W(0X6BB0, ctx->r1) = ctx->r19;
    // 0x8004429C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800442A0: sw          $s2, 0x6B90($at)
    MEM_W(0X6B90, ctx->r1) = ctx->r18;
    // 0x800442A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800442A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800442AC: lw          $v0, -0x4728($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4728);
    // 0x800442B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800442B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800442B8: sh          $v0, 0x6B84($at)
    MEM_H(0X6B84, ctx->r1) = ctx->r2;
    // 0x800442BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800442C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800442C4: lw          $v0, -0x4724($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4724);
    // 0x800442C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800442CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800442D0: sh          $v0, 0x6B8C($at)
    MEM_H(0X6B8C, ctx->r1) = ctx->r2;
    // 0x800442D4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800442D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800442DC: lw          $v0, -0x4748($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4748);
    // 0x800442E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800442E4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800442E8: lw          $v1, -0x4744($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4744);
    // 0x800442EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800442F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800442F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800442F8: sh          $v0, 0x6B86($at)
    MEM_H(0X6B86, ctx->r1) = ctx->r2;
    // 0x800442FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044300: sh          $v0, 0x6B82($at)
    MEM_H(0X6B82, ctx->r1) = ctx->r2;
    // 0x80044304: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044308: sh          $v1, 0x6B8E($at)
    MEM_H(0X6B8E, ctx->r1) = ctx->r3;
    // 0x8004430C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044310: sh          $v1, 0x6B8A($at)
    MEM_H(0X6B8A, ctx->r1) = ctx->r3;
    // 0x80044314: jal         0x80066D30
    // 0x80044318: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x80044318: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8004431C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80044320: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80044324: lb          $v1, -0x474C($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X474C);
    // 0x80044328: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8004432C: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x80044330: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80044334: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044338: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004433C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044340: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80044344: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80044348: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8004434C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80044350: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80044354: jal         0x80053078
    // 0x80044358: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80053078(rdram, ctx);
        goto after_2;
    // 0x80044358: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_2:
    // 0x8004435C: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80044360: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80044364: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80044368: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8004436C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80044370: jr          $ra
    // 0x80044374: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80044374: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80044378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044378: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004437C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80044380: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80044384: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80044388: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004438C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80044390: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80044394: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80044398: sll         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2 << 4);
    // 0x8004439C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800443A0: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800443A4: addiu       $s1, $s1, 0x6AA0
    ctx->r17 = ADD32(ctx->r17, 0X6AA0);
    // 0x800443A8: addu        $s1, $s3, $s1
    ctx->r17 = ADD32(ctx->r19, ctx->r17);
    // 0x800443AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800443B0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800443B4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800443B8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800443BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800443C0: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800443C4: sb          $s0, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = ctx->r16;
    // 0x800443C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800443CC: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800443D0: sb          $v0, 0x6ACF($at)
    MEM_B(0X6ACF, ctx->r1) = ctx->r2;
    // 0x800443D4: jal         0x80017760
    // 0x800443D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x800443D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800443DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800443E0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800443E4: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x800443E8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800443EC: addiu       $a2, $a2, -0x1DC0
    ctx->r6 = ADD32(ctx->r6, -0X1DC0);
    // 0x800443F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800443F4: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800443F8: sb          $v0, 0x6AB7($at)
    MEM_B(0X6AB7, ctx->r1) = ctx->r2;
    // 0x800443FC: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x80044400: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044404: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044408: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
    // 0x8004440C: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x80044410: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044414: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044418: sb          $s0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r16;
    // 0x8004441C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044420: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044424: sh          $zero, 0x6AB8($at)
    MEM_H(0X6AB8, ctx->r1) = 0;
    // 0x80044428: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004442C: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044430: sw          $a1, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r5;
    // 0x80044434: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044438: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8004443C: sw          $a2, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r6;
    // 0x80044440: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044444: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044448: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x8004444C: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80044450: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044454: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044458: sh          $v0, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r2;
    // 0x8004445C: addiu       $v0, $zero, 0x2A0
    ctx->r2 = ADD32(0, 0X2A0);
    // 0x80044460: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80044464: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x80044468: sh          $v0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r2;
    // 0x8004446C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044470: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80044474: sh          $v0, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r2;
    // 0x80044478: bne         $s2, $zero, L_800444A4
    if (ctx->r18 != 0) {
        // 0x8004447C: addiu       $v0, $zero, 0x2AA
        ctx->r2 = ADD32(0, 0X2AA);
            goto L_800444A4;
    }
    // 0x8004447C: addiu       $v0, $zero, 0x2AA
    ctx->r2 = ADD32(0, 0X2AA);
    // 0x80044480: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80044484: lw          $v0, -0x6448($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6448);
    // 0x80044488: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8004448C: lw          $a0, -0x6450($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6450);
    // 0x80044490: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80044494: lw          $a3, -0x644C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X644C);
    // 0x80044498: jal         0x80053078
    // 0x8004449C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80053078(rdram, ctx);
        goto after_1;
    // 0x8004449C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800444A0: addiu       $v0, $zero, 0x2AA
    ctx->r2 = ADD32(0, 0X2AA);
L_800444A4:
    // 0x800444A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800444A8: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800444AC: sh          $v0, 0x6ABC($at)
    MEM_H(0X6ABC, ctx->r1) = ctx->r2;
    // 0x800444B0: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800444B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800444B8: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800444BC: sh          $v0, 0x6ABE($at)
    MEM_H(0X6ABE, ctx->r1) = ctx->r2;
    // 0x800444C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800444C4: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800444C8: sb          $zero, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = 0;
    // 0x800444CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800444D0: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800444D4: sb          $s0, 0x6ACC($at)
    MEM_B(0X6ACC, ctx->r1) = ctx->r16;
    // 0x800444D8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800444DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800444E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800444E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800444E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800444EC: jr          $ra
    // 0x800444F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800444F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800444F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800444F8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800444FC: sll         $v1, $a0, 24
    ctx->r3 = S32(ctx->r4 << 24);
    // 0x80044500: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80044504: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80044508: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004450C: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
    // 0x80044510: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044514: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80044518: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x8004451C: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x80044520: beq         $v1, $zero, L_8004453C
    if (ctx->r3 == 0) {
        // 0x80044524: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_8004453C;
    }
    // 0x80044524: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80044528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004452C: beq         $v1, $v0, L_800445B4
    if (ctx->r3 == ctx->r2) {
        // 0x80044530: sll         $v1, $t0, 24
        ctx->r3 = S32(ctx->r8 << 24);
            goto L_800445B4;
    }
    // 0x80044530: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
    // 0x80044534: j           L_80044774
    // 0x80044538: nop

        goto L_80044774;
    // 0x80044538: nop

L_8004453C:
    // 0x8004453C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80044540: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80044544: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80044548: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004454C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044550: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80044554: sb          $zero, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = 0;
    // 0x80044558: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004455C: addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // 0x80044560: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044564: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80044568: sw          $zero, 0x4A00($at)
    MEM_W(0X4A00, ctx->r1) = 0;
    // 0x8004456C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044570: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80044574: sw          $v1, 0x4A08($at)
    MEM_W(0X4A08, ctx->r1) = ctx->r3;
    // 0x80044578: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004457C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80044580: swc1        $f0, 0x49F0($at)
    MEM_W(0X49F0, ctx->r1) = ctx->f0.u32l;
    // 0x80044584: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044588: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004458C: swc1        $f0, 0x49F8($at)
    MEM_W(0X49F8, ctx->r1) = ctx->f0.u32l;
    // 0x80044590: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044594: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80044598: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x8004459C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800445A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800445A4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800445A8: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    // 0x800445AC: j           L_80044774
    // 0x800445B0: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
        goto L_80044774;
    // 0x800445B0: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
L_800445B4:
    // 0x800445B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800445B8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800445BC: lbu         $v0, 0x6ACC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACC);
    // 0x800445C0: beq         $v0, $zero, L_80044694
    if (ctx->r2 == 0) {
        // 0x800445C4: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_80044694;
    }
    // 0x800445C4: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x800445C8: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800445CC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800445D0: addiu       $v0, $v0, 0x49F0
    ctx->r2 = ADD32(ctx->r2, 0X49F0);
    // 0x800445D4: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800445D8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800445DC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800445E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800445E4: ldc1        $f0, -0x23C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X23C0);
    // 0x800445E8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800445EC: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800445F0: nop

    // 0x800445F4: bc1f        L_80044674
    if (!c1cs) {
        // 0x800445F8: nop
    
            goto L_80044674;
    }
    // 0x800445F8: nop

    // 0x800445FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80044600: ldc1        $f2, -0x23B8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X23B8);
    // 0x80044604: sub.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d - ctx->f2.d;
    // 0x80044608: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8004460C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80044610: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80044614: addiu       $v0, $v0, 0x49F8
    ctx->r2 = ADD32(ctx->r2, 0X49F8);
    // 0x80044618: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8004461C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80044620: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80044624: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x80044628: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8004462C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80044630: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80044634: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044638: lb          $v0, 0x4A10($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A10);
    // 0x8004463C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80044640: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80044644: bne         $v0, $zero, L_8004471C
    if (ctx->r2 != 0) {
        // 0x80044648: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004471C;
    }
    // 0x80044648: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004464C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80044650: addiu       $v1, $v1, 0x4A00
    ctx->r3 = ADD32(ctx->r3, 0X4A00);
    // 0x80044654: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80044658: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004465C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80044660: sb          $zero, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = 0;
    // 0x80044664: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80044668: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004466C: j           L_80044770
    // 0x80044670: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80044770;
    // 0x80044670: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80044674:
    // 0x80044674: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044678: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004467C: sb          $zero, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = 0;
    // 0x80044680: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044684: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80044688: sb          $zero, 0x6ACC($at)
    MEM_B(0X6ACC, ctx->r1) = 0;
    // 0x8004468C: j           L_80044774
    // 0x80044690: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
        goto L_80044774;
    // 0x80044690: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
L_80044694:
    // 0x80044694: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80044698: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004469C: addiu       $v0, $v0, 0x49F0
    ctx->r2 = ADD32(ctx->r2, 0X49F0);
    // 0x800446A0: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800446A4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800446A8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800446AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800446B0: ldc1        $f0, -0x23B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X23B0);
    // 0x800446B4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800446B8: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800446BC: nop

    // 0x800446C0: nop

    // 0x800446C4: bc1fl       L_80044758
    if (!c1cs) {
        // 0x800446C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044758;
    }
    goto skip_0;
    // 0x800446C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800446CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800446D0: ldc1        $f2, -0x23A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X23A8);
    // 0x800446D4: add.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d + ctx->f2.d;
    // 0x800446D8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800446DC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800446E0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800446E4: addiu       $v0, $v0, 0x49F8
    ctx->r2 = ADD32(ctx->r2, 0X49F8);
    // 0x800446E8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800446EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800446F0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800446F4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800446F8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800446FC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80044700: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80044704: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044708: lb          $v0, 0x4A10($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A10);
    // 0x8004470C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80044710: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80044714: beq         $v0, $zero, L_80044730
    if (ctx->r2 == 0) {
        // 0x80044718: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80044730;
    }
    // 0x80044718: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8004471C:
    // 0x8004471C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044720: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80044724: sb          $v0, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = ctx->r2;
    // 0x80044728: j           L_80044774
    // 0x8004472C: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
        goto L_80044774;
    // 0x8004472C: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
L_80044730:
    // 0x80044730: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80044734: addiu       $v1, $v1, 0x4A00
    ctx->r3 = ADD32(ctx->r3, 0X4A00);
    // 0x80044738: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x8004473C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044740: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80044744: sb          $zero, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = 0;
    // 0x80044748: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8004474C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80044750: j           L_80044770
    // 0x80044754: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80044770;
    // 0x80044754: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80044758:
    // 0x80044758: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004475C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80044760: sb          $zero, 0x4A10($at)
    MEM_B(0X4A10, ctx->r1) = 0;
    // 0x80044764: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044768: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8004476C: sb          $v0, 0x6ACC($at)
    MEM_B(0X6ACC, ctx->r1) = ctx->r2;
L_80044770:
    // 0x80044770: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
L_80044774:
    // 0x80044774: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80044778: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x8004477C: sll         $a1, $a3, 24
    ctx->r5 = S32(ctx->r7 << 24);
    // 0x80044780: sra         $a1, $a1, 22
    ctx->r5 = S32(SIGNED(ctx->r5) >> 22);
    // 0x80044784: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80044788: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004478C: lw          $v0, 0x4A00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4A00);
    // 0x80044790: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80044794: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80044798: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004479C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800447A0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800447A4: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x800447A8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800447AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800447B0: lw          $v0, 0x4A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4A08);
    // 0x800447B4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800447B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800447BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800447C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800447C4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800447C8: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
    // 0x800447CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800447D0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800447D4: lwc1        $f2, 0x49F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X49F0);
    // 0x800447D8: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800447DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800447E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800447E4: nop

    // 0x800447E8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800447EC: nop

    // 0x800447F0: nop

    // 0x800447F4: bc1tl       L_80044810
    if (c1cs) {
        // 0x800447F8: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80044810;
    }
    goto skip_1;
    // 0x800447F8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x800447FC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80044800: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80044804: nop

    // 0x80044808: j           L_80044824
    // 0x8004480C: sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7 << 24);
        goto L_80044824;
    // 0x8004480C: sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7 << 24);
L_80044810:
    // 0x80044810: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80044814: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80044818: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004481C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80044820: sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7 << 24);
L_80044824:
    // 0x80044824: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80044828: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004482C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80044830: sh          $v1, 0x6ABC($at)
    MEM_H(0X6ABC, ctx->r1) = ctx->r3;
    // 0x80044834: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80044838: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004483C: lwc1        $f2, 0x49F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X49F8);
    // 0x80044840: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80044844: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80044848: nop

    // 0x8004484C: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80044850: sll         $v1, $t0, 24
    ctx->r3 = S32(ctx->r8 << 24);
    // 0x80044854: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80044858: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004485C: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80044860: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80044864: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80044868: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004486C: nop

    // 0x80044870: bc1t        L_80044888
    if (c1cs) {
        // 0x80044874: sll         $a0, $v0, 4
        ctx->r4 = S32(ctx->r2 << 4);
            goto L_80044888;
    }
    // 0x80044874: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80044878: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004487C: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80044880: j           L_8004489C
    // 0x80044884: nop

        goto L_8004489C;
    // 0x80044884: nop

L_80044888:
    // 0x80044888: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004488C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80044890: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80044894: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80044898: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8004489C:
    // 0x8004489C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800448A0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800448A4: sh          $v1, 0x6ABE($at)
    MEM_H(0X6ABE, ctx->r1) = ctx->r3;
    // 0x800448A8: jr          $ra
    // 0x800448AC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800448AC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800448B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800448B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800448B4: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800448B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800448BC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x800448C0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800448C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800448C8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800448CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800448D0: bne         $a0, $zero, L_8004494C
    if (ctx->r4 != 0) {
        // 0x800448D4: lw          $v1, -0x47C8($v1)
        ctx->r3 = MEM_W(ctx->r3, -0X47C8);
            goto L_8004494C;
    }
    // 0x800448D4: lw          $v1, -0x47C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X47C8);
    // 0x800448D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800448DC: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x800448E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800448E4: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800448E8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800448EC: beq         $v0, $zero, L_800449B4
    if (ctx->r2 == 0) {
        // 0x800448F0: nop
    
            goto L_800449B4;
    }
    // 0x800448F0: nop

    // 0x800448F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800448F8: lw          $v1, 0x6AE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6AE8);
    // 0x800448FC: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80044900: bne         $v0, $zero, L_8004497C
    if (ctx->r2 != 0) {
        // 0x80044904: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004497C;
    }
    // 0x80044904: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80044908: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004490C: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x80044910: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80044914: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80044918: lw          $a0, 0x6AE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6AE4);
    // 0x8004491C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80044920: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80044924: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80044928: lh          $v0, -0x47BA($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X47BA);
    // 0x8004492C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80044930: addiu       $v1, $v1, -0x47BA
    ctx->r3 = ADD32(ctx->r3, -0X47BA);
    // 0x80044934: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80044938: bne         $v0, $zero, L_800449A4
    if (ctx->r2 != 0) {
        // 0x8004493C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800449A4;
    }
    // 0x8004493C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80044940: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x80044944: j           L_800449A4
    // 0x80044948: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
        goto L_800449A4;
    // 0x80044948: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
L_8004494C:
    // 0x8004494C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044950: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x80044954: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044958: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004495C: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80044960: beq         $v0, $zero, L_800449B4
    if (ctx->r2 == 0) {
        // 0x80044964: nop
    
            goto L_800449B4;
    }
    // 0x80044964: nop

    // 0x80044968: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004496C: lw          $v1, 0x6AE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6AE8);
    // 0x80044970: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80044974: beq         $v0, $zero, L_80044988
    if (ctx->r2 == 0) {
        // 0x80044978: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80044988;
    }
    // 0x80044978: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8004497C:
    // 0x8004497C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044980: j           L_800449B4
    // 0x80044984: sw          $v0, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r2;
        goto L_800449B4;
    // 0x80044984: sw          $v0, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r2;
L_80044988:
    // 0x80044988: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004498C: lw          $v1, 0x6AE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6AE4);
    // 0x80044990: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044994: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x80044998: slti        $v0, $v1, 0x1F
    ctx->r2 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x8004499C: beq         $v0, $zero, L_800449AC
    if (ctx->r2 == 0) {
        // 0x800449A0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800449AC;
    }
    // 0x800449A0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800449A4:
    // 0x800449A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800449A8: sw          $v0, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = ctx->r2;
L_800449AC:
    // 0x800449AC: jal         0x800440FC
    // 0x800449B0: nop

    func_800440FC(rdram, ctx);
        goto after_0;
    // 0x800449B0: nop

    after_0:
L_800449B4:
    // 0x800449B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800449B8: jr          $ra
    // 0x800449BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800449BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800449C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800449C0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800449C4: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x800449C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800449CC: lbu         $v0, 0x6ACB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACB);
    // 0x800449D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800449D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800449D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800449DC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800449E0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800449E4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800449E8: lw          $a0, -0x69F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X69F8);
    // 0x800449EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800449F0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x800449F4: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x800449F8: lw          $s0, -0xDBC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0XDBC);
    // 0x800449FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044A00: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80044A04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A08: sh          $a0, 0x2FA0($at)
    MEM_H(0X2FA0, ctx->r1) = ctx->r4;
    // 0x80044A0C: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x80044A10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A14: sh          $a0, 0x2FA2($at)
    MEM_H(0X2FA2, ctx->r1) = ctx->r4;
    // 0x80044A18: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80044A1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A20: sh          $v1, 0x2FA4($at)
    MEM_H(0X2FA4, ctx->r1) = ctx->r3;
    // 0x80044A24: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x80044A28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A2C: sh          $v1, 0x2FA8($at)
    MEM_H(0X2FA8, ctx->r1) = ctx->r3;
    // 0x80044A30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A34: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80044A38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A3C: sh          $zero, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = 0;
    // 0x80044A40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A44: sh          $zero, 0x2FAE($at)
    MEM_H(0X2FAE, ctx->r1) = 0;
    // 0x80044A48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A4C: beq         $a0, $zero, L_80044B08
    if (ctx->r4 == 0) {
        // 0x80044A50: sh          $v0, 0x2FA6($at)
        MEM_H(0X2FA6, ctx->r1) = ctx->r2;
            goto L_80044B08;
    }
    // 0x80044A50: sh          $v0, 0x2FA6($at)
    MEM_H(0X2FA6, ctx->r1) = ctx->r2;
    // 0x80044A54: jal         0x8005357C
    // 0x80044A58: nop

    func_8005357C(rdram, ctx);
        goto after_0;
    // 0x80044A58: nop

    after_0:
    // 0x80044A5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A60: sw          $v0, 0x5030($at)
    MEM_W(0X5030, ctx->r1) = ctx->r2;
    // 0x80044A64: beq         $v0, $zero, L_80044B08
    if (ctx->r2 == 0) {
        // 0x80044A68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044B08;
    }
    // 0x80044A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044A6C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044A70: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044A74: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80044A78: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044A7C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044A80: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x80044A84: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80044A88: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044A8C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044A90: addiu       $v0, $zero, 0xA8
    ctx->r2 = ADD32(0, 0XA8);
    // 0x80044A94: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80044A98: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044A9C: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044AA0: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80044AA4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044AA8: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044AB0: sh          $v0, 0x66($v1)
    MEM_H(0X66, ctx->r3) = ctx->r2;
    // 0x80044AB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044AB8: lh          $v0, 0x2FA8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA8);
    // 0x80044ABC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044AC0: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044AC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044AC8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044ACC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044AD0: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80044AD4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044AD8: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044ADC: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80044AE0: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80044AE4: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80044AE8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044AEC: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80044AF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80044AF4: bne         $v1, $v0, L_80044B08
    if (ctx->r3 != ctx->r2) {
        // 0x80044AF8: nop
    
            goto L_80044B08;
    }
    // 0x80044AF8: nop

    // 0x80044AFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044B00: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044B04: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
L_80044B08:
    // 0x80044B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044B0C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80044B10: jr          $ra
    // 0x80044B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80044B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80044B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044B18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044B1C: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80044B20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80044B24: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80044B28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044B2C: sll         $a2, $v1, 1
    ctx->r6 = S32(ctx->r3 << 1);
    // 0x80044B30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044B34: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80044B38: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80044B3C: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80044B40: beq         $v0, $zero, L_80044B58
    if (ctx->r2 == 0) {
        // 0x80044B44: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80044B58;
    }
    // 0x80044B44: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80044B48: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044B4C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044B54: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
L_80044B58:
    // 0x80044B58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044B5C: lh          $v0, 0x2FA0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA0);
    // 0x80044B60: bne         $v0, $zero, L_80044C74
    if (ctx->r2 != 0) {
        // 0x80044B64: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80044C74;
    }
    // 0x80044B64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044B68: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80044B6C: lw          $a3, 0x5030($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5030);
    // 0x80044B70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044B74: sh          $a1, 0x2FAE($at)
    MEM_H(0X2FAE, ctx->r1) = ctx->r5;
    // 0x80044B78: lw          $v0, 0x68($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X68);
    // 0x80044B7C: beq         $v0, $zero, L_80044C6C
    if (ctx->r2 == 0) {
        // 0x80044B80: nop
    
            goto L_80044C6C;
    }
    // 0x80044B80: nop

    // 0x80044B84: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044B88: lh          $v0, 0x2FA2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA2);
    // 0x80044B8C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80044B90: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80044B94: bne         $v0, $zero, L_80044C20
    if (ctx->r2 != 0) {
        // 0x80044B98: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80044C20;
    }
    // 0x80044B98: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80044B9C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044BA0: lhu         $v0, 0x2FA8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2FA8);
    // 0x80044BA4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044BA8: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80044BAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044BB0: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80044BB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044BB8: sh          $a0, 0x2FA2($at)
    MEM_H(0X2FA2, ctx->r1) = ctx->r4;
    // 0x80044BBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80044BC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80044BC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044BC8: sh          $v0, 0x2FA8($at)
    MEM_H(0X2FA8, ctx->r1) = ctx->r2;
    // 0x80044BCC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80044BD0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80044BD4: lw          $a0, -0xDBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDBC);
    // 0x80044BD8: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80044BDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044BE0: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044BE4: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80044BE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044BEC: lh          $v0, 0x2FA8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA8);
    // 0x80044BF0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044BF4: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044BF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044BFC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044C00: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044C04: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80044C08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044C0C: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044C10: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80044C14: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80044C18: j           L_80044C6C
    // 0x80044C1C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
        goto L_80044C6C;
    // 0x80044C1C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_80044C20:
    // 0x80044C20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044C24: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80044C28: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80044C2C: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80044C30: bne         $v0, $zero, L_80044C50
    if (ctx->r2 != 0) {
        // 0x80044C34: nop
    
            goto L_80044C50;
    }
    // 0x80044C34: nop

    // 0x80044C38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044C3C: lh          $v0, 0x2FAA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAA);
    // 0x80044C40: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80044C44: slti        $v0, $v0, 0x78
    ctx->r2 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80044C48: bne         $v0, $zero, L_80044C64
    if (ctx->r2 != 0) {
        // 0x80044C4C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80044C64;
    }
    // 0x80044C4C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80044C50:
    // 0x80044C50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044C54: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80044C58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044C5C: j           L_80044C74
    // 0x80044C60: sh          $a1, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = ctx->r5;
        goto L_80044C74;
    // 0x80044C60: sh          $a1, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = ctx->r5;
L_80044C64:
    // 0x80044C64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044C68: sh          $v0, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = ctx->r2;
L_80044C6C:
    // 0x80044C6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044C70: sh          $zero, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = 0;
L_80044C74:
    // 0x80044C74: jr          $ra
    // 0x80044C78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80044C78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80044C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044C7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044C80: lh          $v0, 0x2FA0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA0);
    // 0x80044C84: bne         $v0, $zero, L_80044D64
    if (ctx->r2 != 0) {
        // 0x80044C88: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80044D64;
    }
    // 0x80044C88: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80044C8C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80044C90: lw          $a1, 0x5030($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5030);
    // 0x80044C94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80044C98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044C9C: sh          $v1, 0x2FAE($at)
    MEM_H(0X2FAE, ctx->r1) = ctx->r3;
    // 0x80044CA0: lw          $v0, 0x68($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X68);
    // 0x80044CA4: beq         $v0, $zero, L_80044D5C
    if (ctx->r2 == 0) {
        // 0x80044CA8: nop
    
            goto L_80044D5C;
    }
    // 0x80044CA8: nop

    // 0x80044CAC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044CB0: lh          $v0, 0x2FA2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA2);
    // 0x80044CB4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80044CB8: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80044CBC: bne         $v0, $zero, L_80044D48
    if (ctx->r2 != 0) {
        // 0x80044CC0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80044D48;
    }
    // 0x80044CC0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80044CC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044CC8: lhu         $v0, 0x2FA8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2FA8);
    // 0x80044CCC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044CD0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80044CD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044CD8: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80044CDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044CE0: sh          $a0, 0x2FA2($at)
    MEM_H(0X2FA2, ctx->r1) = ctx->r4;
    // 0x80044CE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80044CE8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80044CEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044CF0: sh          $v0, 0x2FA8($at)
    MEM_H(0X2FA8, ctx->r1) = ctx->r2;
    // 0x80044CF4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80044CF8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80044CFC: lw          $a0, -0xDBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDBC);
    // 0x80044D00: sw          $zero, 0x68($a1)
    MEM_W(0X68, ctx->r5) = 0;
    // 0x80044D04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044D08: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044D0C: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80044D10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044D14: lh          $v0, 0x2FA8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FA8);
    // 0x80044D18: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80044D1C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x80044D20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044D24: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044D28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044D2C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80044D30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044D34: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80044D38: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80044D3C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80044D40: j           L_80044D5C
    // 0x80044D44: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
        goto L_80044D5C;
    // 0x80044D44: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_80044D48:
    // 0x80044D48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044D4C: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80044D50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044D54: j           L_80044D64
    // 0x80044D58: sh          $v1, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = ctx->r3;
        goto L_80044D64;
    // 0x80044D58: sh          $v1, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = ctx->r3;
L_80044D5C:
    // 0x80044D5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044D60: sh          $zero, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = 0;
L_80044D64:
    // 0x80044D64: jr          $ra
    // 0x80044D68: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80044D68: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80044D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044D6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044D70: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80044D74: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80044D78: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80044D7C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80044D80: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80044D84: beq         $v0, $zero, L_80044F20
    if (ctx->r2 == 0) {
        // 0x80044D88: sdc1        $f20, 0x60($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
            goto L_80044F20;
    }
    // 0x80044D88: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x80044D8C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80044D90: lbu         $v0, -0x4708($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4708);
    // 0x80044D94: bne         $v0, $zero, L_80044F20
    if (ctx->r2 != 0) {
        // 0x80044D98: nop
    
            goto L_80044F20;
    }
    // 0x80044D98: nop

    // 0x80044D9C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044DA0: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80044DA4: beq         $v0, $zero, L_80044EB8
    if (ctx->r2 == 0) {
        // 0x80044DA8: nop
    
            goto L_80044EB8;
    }
    // 0x80044DA8: nop

    // 0x80044DAC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044DB0: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80044DB4: beq         $v0, $zero, L_80044E60
    if (ctx->r2 == 0) {
        // 0x80044DB8: nop
    
            goto L_80044E60;
    }
    // 0x80044DB8: nop

    // 0x80044DBC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044DC0: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80044DC4: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80044DC8: beq         $v0, $zero, L_80044E24
    if (ctx->r2 == 0) {
        // 0x80044DCC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044E24;
    }
    // 0x80044DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044DD0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044DD4: lbu         $v1, 0x7B8F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8F);
    // 0x80044DD8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044DDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044DE0: sb          $v0, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r2;
    // 0x80044DE4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80044DE8: beq         $v0, $zero, L_80044E14
    if (ctx->r2 == 0) {
        // 0x80044DEC: nop
    
            goto L_80044E14;
    }
    // 0x80044DEC: nop

    // 0x80044DF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044DF4: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x80044DF8: jal         0x80006A78
    // 0x80044DFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80006A78(rdram, ctx);
        goto after_0;
    // 0x80044DFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80044E00: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80044E04: jal         0x8000637C
    // 0x80044E08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x80044E08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80044E0C: j           L_80044E24
    // 0x80044E10: nop

        goto L_80044E24;
    // 0x80044E10: nop

L_80044E14:
    // 0x80044E14: jal         0x80006A78
    // 0x80044E18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80006A78(rdram, ctx);
        goto after_2;
    // 0x80044E18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80044E1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044E20: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_80044E24:
    // 0x80044E24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044E28: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x80044E2C: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80044E30: beq         $v0, $zero, L_80044F20
    if (ctx->r2 == 0) {
        // 0x80044E34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044F20;
    }
    // 0x80044E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044E38: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80044E3C: addiu       $a0, $a0, 0x7B8F
    ctx->r4 = ADD32(ctx->r4, 0X7B8F);
    // 0x80044E40: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80044E44: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044E48: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80044E4C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80044E50: beq         $v0, $zero, L_80044F10
    if (ctx->r2 == 0) {
        // 0x80044E54: nop
    
            goto L_80044F10;
    }
    // 0x80044E54: nop

    // 0x80044E58: j           L_80044EEC
    // 0x80044E5C: nop

        goto L_80044EEC;
    // 0x80044E5C: nop

L_80044E60:
    // 0x80044E60: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044E64: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80044E68: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80044E6C: beq         $v0, $zero, L_80044F20
    if (ctx->r2 == 0) {
        // 0x80044E70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044F20;
    }
    // 0x80044E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044E74: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044E78: lbu         $v1, 0x7B8F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8F);
    // 0x80044E7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044E80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044E84: sb          $v0, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r2;
    // 0x80044E88: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80044E8C: beq         $v0, $zero, L_80044F10
    if (ctx->r2 == 0) {
        // 0x80044E90: nop
    
            goto L_80044F10;
    }
    // 0x80044E90: nop

    // 0x80044E94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044E98: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x80044E9C: jal         0x80006A78
    // 0x80044EA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80006A78(rdram, ctx);
        goto after_3;
    // 0x80044EA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80044EA4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80044EA8: jal         0x8000637C
    // 0x80044EAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80044EAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80044EB0: j           L_80044F20
    // 0x80044EB4: nop

        goto L_80044F20;
    // 0x80044EB4: nop

L_80044EB8:
    // 0x80044EB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044EBC: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x80044EC0: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80044EC4: beq         $v0, $zero, L_80044F20
    if (ctx->r2 == 0) {
        // 0x80044EC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044F20;
    }
    // 0x80044EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044ECC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80044ED0: lbu         $v1, 0x7B8F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8F);
    // 0x80044ED4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044ED8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044EDC: sb          $v0, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r2;
    // 0x80044EE0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80044EE4: beq         $v0, $zero, L_80044F10
    if (ctx->r2 == 0) {
        // 0x80044EE8: nop
    
            goto L_80044F10;
    }
    // 0x80044EE8: nop

L_80044EEC:
    // 0x80044EEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044EF0: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x80044EF4: jal         0x80006A78
    // 0x80044EF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80006A78(rdram, ctx);
        goto after_5;
    // 0x80044EF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80044EFC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80044F00: jal         0x8000637C
    // 0x80044F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000637C(rdram, ctx);
        goto after_6;
    // 0x80044F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80044F08: j           L_80044F20
    // 0x80044F0C: nop

        goto L_80044F20;
    // 0x80044F0C: nop

L_80044F10:
    // 0x80044F10: jal         0x80006A78
    // 0x80044F14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80006A78(rdram, ctx);
        goto after_7;
    // 0x80044F14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80044F18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044F1C: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_80044F20:
    // 0x80044F20: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80044F24: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80044F28: beq         $v0, $zero, L_8004553C
    if (ctx->r2 == 0) {
        // 0x80044F2C: lui         $a1, 0xF650
        ctx->r5 = S32(0XF650 << 16);
            goto L_8004553C;
    }
    // 0x80044F2C: lui         $a1, 0xF650
    ctx->r5 = S32(0XF650 << 16);
    // 0x80044F30: ori         $a1, $a1, 0x3C0
    ctx->r5 = ctx->r5 | 0X3C0;
    // 0x80044F34: lui         $a3, 0xF63C
    ctx->r7 = S32(0XF63C << 16);
    // 0x80044F38: ori         $a3, $a3, 0x260
    ctx->r7 = ctx->r7 | 0X260;
    // 0x80044F3C: lui         $a2, 0x14
    ctx->r6 = S32(0X14 << 16);
    // 0x80044F40: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044F44: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80044F48: ori         $a2, $a2, 0x160
    ctx->r6 = ctx->r6 | 0X160;
    // 0x80044F4C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80044F50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80044F54: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x80044F58: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80044F5C: lui         $a0, 0xFA00
    ctx->r4 = S32(0XFA00 << 16);
    // 0x80044F60: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80044F64: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80044F68: addiu       $v1, $v1, 0x6D70
    ctx->r3 = ADD32(ctx->r3, 0X6D70);
    // 0x80044F6C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80044F70: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x80044F74: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80044F78: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x80044F7C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80044F80: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x80044F84: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80044F88: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    // 0x80044F8C: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80044F90: sw          $a3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r7;
    // 0x80044F94: sw          $a2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r6;
    // 0x80044F98: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80044F9C: lbu         $a2, 0x7B72($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B72);
    // 0x80044FA0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80044FA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044FA8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80044FAC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80044FB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044FB4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80044FB8: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80044FBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044FC0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80044FC4: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80044FC8: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80044FCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044FD0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80044FD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044FD8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80044FDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044FE0: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80044FE4: beq         $v1, $v0, L_80045074
    if (ctx->r3 == ctx->r2) {
        // 0x80044FE8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80045074;
    }
    // 0x80044FE8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80044FEC: beql        $v0, $zero, L_80045004
    if (ctx->r2 == 0) {
        // 0x80044FF0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80045004;
    }
    goto skip_0;
    // 0x80044FF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80044FF4: beq         $v1, $zero, L_8004501C
    if (ctx->r3 == 0) {
        // 0x80044FF8: nop
    
            goto L_8004501C;
    }
    // 0x80044FF8: nop

    // 0x80044FFC: j           L_8004553C
    // 0x80045000: nop

        goto L_8004553C;
    // 0x80045000: nop

L_80045004:
    // 0x80045004: beq         $v1, $v0, L_800450C8
    if (ctx->r3 == ctx->r2) {
        // 0x80045008: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800450C8;
    }
    // 0x80045008: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004500C: beq         $v1, $v0, L_800453DC
    if (ctx->r3 == ctx->r2) {
        // 0x80045010: nop
    
            goto L_800453DC;
    }
    // 0x80045010: nop

    // 0x80045014: j           L_8004553C
    // 0x80045018: nop

        goto L_8004553C;
    // 0x80045018: nop

L_8004501C:
    // 0x8004501C: jal         0x8002D378
    // 0x80045020: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_8;
    // 0x80045020: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x80045024: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80045028: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004502C: addiu       $a0, $a0, 0x4A12
    ctx->r4 = ADD32(ctx->r4, 0X4A12);
    // 0x80045030: sll         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3 << 24);
L_80045034:
    // 0x80045034: sra         $v0, $v0, 23
    ctx->r2 = S32(SIGNED(ctx->r2) >> 23);
    // 0x80045038: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004503C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80045040: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80045044: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80045048: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004504C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80045050: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80045054: bne         $v0, $zero, L_80045034
    if (ctx->r2 != 0) {
        // 0x80045058: sll         $v0, $v1, 24
        ctx->r2 = S32(ctx->r3 << 24);
            goto L_80045034;
    }
    // 0x80045058: sll         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3 << 24);
    // 0x8004505C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045060: addiu       $v1, $v1, 0x7B72
    ctx->r3 = ADD32(ctx->r3, 0X7B72);
    // 0x80045064: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80045068: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004506C: j           L_8004553C
    // 0x80045070: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8004553C;
    // 0x80045070: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80045074:
    // 0x80045074: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80045078: addiu       $a0, $a0, 0x4A1C
    ctx->r4 = ADD32(ctx->r4, 0X4A1C);
    // 0x8004507C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80045080: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80045084: slti        $v0, $v0, 0x12C
    ctx->r2 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80045088: beq         $v0, $zero, L_80045098
    if (ctx->r2 == 0) {
        // 0x8004508C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80045098;
    }
    // 0x8004508C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80045090: j           L_800450B0
    // 0x80045094: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_800450B0;
    // 0x80045094: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80045098:
    // 0x80045098: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8004509C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800450A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800450A4: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x800450A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800450AC: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
L_800450B0:
    // 0x800450B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800450B4: addiu       $a0, $a0, -0x23A0
    ctx->r4 = ADD32(ctx->r4, -0X23A0);
    // 0x800450B8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800450BC: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x800450C0: j           L_80045534
    // 0x800450C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80045534;
    // 0x800450C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800450C8:
    // 0x800450C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800450CC: lbu         $a0, 0x7B73($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B73);
    // 0x800450D0: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800450D4: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800450D8: beq         $v0, $zero, L_80045140
    if (ctx->r2 == 0) {
        // 0x800450DC: nop
    
            goto L_80045140;
    }
    // 0x800450DC: nop

    // 0x800450E0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800450E4: lh          $v1, 0x4A14($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4A14);
    // 0x800450E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800450EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800450F0: lbu         $v0, -0x46D4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X46D4);
    // 0x800450F4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800450F8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800450FC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045100: sh          $v0, 0x4A12($at)
    MEM_H(0X4A12, ctx->r1) = ctx->r2;
    // 0x80045104: blez        $v1, L_8004511C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80045108: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8004511C;
    }
    // 0x80045108: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8004510C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80045110: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045114: j           L_8004518C
    // 0x80045118: sh          $v0, 0x4A14($at)
    MEM_H(0X4A14, ctx->r1) = ctx->r2;
        goto L_8004518C;
    // 0x80045118: sh          $v0, 0x4A14($at)
    MEM_H(0X4A14, ctx->r1) = ctx->r2;
L_8004511C:
    // 0x8004511C: sltiu       $v0, $a1, 0xF
    ctx->r2 = ctx->r5 < 0XF ? 1 : 0;
    // 0x80045120: bne         $v0, $zero, L_80045184
    if (ctx->r2 != 0) {
        // 0x80045124: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80045184;
    }
    // 0x80045124: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80045128: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8004512C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045130: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
    // 0x80045134: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045138: j           L_8004518C
    // 0x8004513C: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
        goto L_8004518C;
    // 0x8004513C: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
L_80045140:
    // 0x80045140: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80045144: lh          $v1, 0x4A14($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4A14);
    // 0x80045148: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004514C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045150: lbu         $v0, -0x46D4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X46D4);
    // 0x80045154: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80045158: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004515C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045160: sh          $v0, 0x4A12($at)
    MEM_H(0X4A12, ctx->r1) = ctx->r2;
    // 0x80045164: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80045168: slti        $v1, $v1, 0xC
    ctx->r3 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // 0x8004516C: beq         $v1, $zero, L_80045180
    if (ctx->r3 == 0) {
        // 0x80045170: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80045180;
    }
    // 0x80045170: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045174: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80045178: j           L_8004518C
    // 0x8004517C: sh          $v0, 0x4A14($at)
    MEM_H(0X4A14, ctx->r1) = ctx->r2;
        goto L_8004518C;
    // 0x8004517C: sh          $v0, 0x4A14($at)
    MEM_H(0X4A14, ctx->r1) = ctx->r2;
L_80045180:
    // 0x80045180: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_80045184:
    // 0x80045184: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045188: sb          $v0, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = ctx->r2;
L_8004518C:
    // 0x8004518C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045190: lbu         $v0, 0x7B73($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B73);
    // 0x80045194: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80045198: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004519C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800451A0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800451A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800451A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800451AC: lb          $v0, -0x4704($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4704);
    // 0x800451B0: beq         $v0, $zero, L_800451C4
    if (ctx->r2 == 0) {
        // 0x800451B4: nop
    
            goto L_800451C4;
    }
    // 0x800451B4: nop

    // 0x800451B8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800451BC: j           L_800451D0
    // 0x800451C0: lhu         $v0, 0x4A12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4A12);
        goto L_800451D0;
    // 0x800451C0: lhu         $v0, 0x4A12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4A12);
L_800451C4:
    // 0x800451C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800451C8: lhu         $v0, 0x4A12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4A12);
    // 0x800451CC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800451D0:
    // 0x800451D0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800451D4: sh          $v0, 0x4A16($at)
    MEM_H(0X4A16, ctx->r1) = ctx->r2;
    // 0x800451D8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800451DC: addiu       $s1, $s1, 0x7B73
    ctx->r17 = ADD32(ctx->r17, 0X7B73);
    // 0x800451E0: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x800451E4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800451E8: addiu       $s0, $s0, 0x4A16
    ctx->r16 = ADD32(ctx->r16, 0X4A16);
    // 0x800451EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800451F0: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x800451F4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800451F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800451FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045200: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045204: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045208: lb          $v0, -0x4703($at)
    ctx->r2 = MEM_B(ctx->r1, -0X4703);
    // 0x8004520C: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045210: mflo        $a0
    ctx->r4 = lo;
    // 0x80045214: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045218: ldc1        $f2, -0x2380($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2380);
    // 0x8004521C: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80045220: nop

    // 0x80045224: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80045228: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8004522C: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80045230: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045234: addiu       $a0, $a0, -0x2398
    ctx->r4 = ADD32(ctx->r4, -0X2398);
    // 0x80045238: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8004523C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80045240: nop

    // 0x80045244: jal         0x8004EC44
    // 0x80045248: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_9;
    // 0x80045248: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // 0x8004524C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80045250: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80045254: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80045258: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004525C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045260: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045264: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045268: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004526C: lb          $v0, -0x4702($at)
    ctx->r2 = MEM_B(ctx->r1, -0X4702);
    // 0x80045270: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045274: mflo        $a0
    ctx->r4 = lo;
    // 0x80045278: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004527C: ldc1        $f2, -0x2378($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2378);
    // 0x80045280: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80045284: nop

    // 0x80045288: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8004528C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80045290: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80045294: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045298: addiu       $a0, $a0, -0x2394
    ctx->r4 = ADD32(ctx->r4, -0X2394);
    // 0x8004529C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800452A0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800452A4: nop

    // 0x800452A8: jal         0x8004EC44
    // 0x800452AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_10;
    // 0x800452AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_10:
    // 0x800452B0: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x800452B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800452B8: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x800452BC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800452C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800452C4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800452C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800452CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800452D0: lb          $v0, -0x4701($at)
    ctx->r2 = MEM_B(ctx->r1, -0X4701);
    // 0x800452D4: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800452D8: mflo        $a0
    ctx->r4 = lo;
    // 0x800452DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800452E0: ldc1        $f2, -0x2370($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2370);
    // 0x800452E4: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800452E8: nop

    // 0x800452EC: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800452F0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800452F4: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x800452F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800452FC: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    // 0x80045300: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80045304: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80045308: nop

    // 0x8004530C: jal         0x8004EC44
    // 0x80045310: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_11;
    // 0x80045310: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x80045314: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80045318: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004531C: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80045320: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80045324: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045328: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004532C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045330: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045334: lb          $v0, -0x4700($at)
    ctx->r2 = MEM_B(ctx->r1, -0X4700);
    // 0x80045338: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004533C: mflo        $a0
    ctx->r4 = lo;
    // 0x80045340: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045344: ldc1        $f2, -0x2368($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2368);
    // 0x80045348: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8004534C: nop

    // 0x80045350: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80045354: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80045358: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x8004535C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045360: addiu       $a0, $a0, -0x238C
    ctx->r4 = ADD32(ctx->r4, -0X238C);
    // 0x80045364: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80045368: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004536C: nop

    // 0x80045370: jal         0x8004EC44
    // 0x80045374: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_12;
    // 0x80045374: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // 0x80045378: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8004537C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80045380: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80045384: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80045388: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004538C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045390: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045394: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045398: lb          $v0, -0x46FF($at)
    ctx->r2 = MEM_B(ctx->r1, -0X46FF);
    // 0x8004539C: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800453A0: mflo        $a0
    ctx->r4 = lo;
    // 0x800453A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800453A8: ldc1        $f2, -0x2360($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2360);
    // 0x800453AC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800453B0: nop

    // 0x800453B4: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800453B8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800453BC: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x800453C0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800453C4: addiu       $a0, $a0, -0x2388
    ctx->r4 = ADD32(ctx->r4, -0X2388);
    // 0x800453C8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800453CC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800453D0: nop

    // 0x800453D4: j           L_80045534
    // 0x800453D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80045534;
    // 0x800453D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800453DC:
    // 0x800453DC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800453E0: addiu       $a0, $a0, 0x4A1C
    ctx->r4 = ADD32(ctx->r4, 0X4A1C);
    // 0x800453E4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800453E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800453EC: slti        $v0, $v0, 0x12C
    ctx->r2 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800453F0: beq         $v0, $zero, L_80045400
    if (ctx->r2 == 0) {
        // 0x800453F4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80045400;
    }
    // 0x800453F4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800453F8: j           L_80045418
    // 0x800453FC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80045418;
    // 0x800453FC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80045400:
    // 0x80045400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045404: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80045408: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004540C: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x80045410: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045414: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
L_80045418:
    // 0x80045418: jal         0x800346F4
    // 0x8004541C: nop

    func_800346F4(rdram, ctx);
        goto after_13;
    // 0x8004541C: nop

    after_13:
    // 0x80045420: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045424: addiu       $a0, $a0, -0x2398
    ctx->r4 = ADD32(ctx->r4, -0X2398);
    // 0x80045428: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8004542C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80045430: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045434: ldc1        $f20, -0x2358($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X2358);
    // 0x80045438: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004543C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80045440: nop

    // 0x80045444: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80045448: add.d       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f0.d + ctx->f20.d;
    // 0x8004544C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80045450: addiu       $s0, $s0, 0x4A12
    ctx->r16 = ADD32(ctx->r16, 0X4A12);
    // 0x80045454: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80045458: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8004545C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80045460: nop

    // 0x80045464: jal         0x8004EC44
    // 0x80045468: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_14;
    // 0x80045468: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_14:
    // 0x8004546C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80045470: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80045474: nop

    // 0x80045478: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8004547C: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x80045480: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045484: addiu       $a0, $a0, -0x2394
    ctx->r4 = ADD32(ctx->r4, -0X2394);
    // 0x80045488: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x8004548C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80045490: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80045494: nop

    // 0x80045498: jal         0x8004EC44
    // 0x8004549C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_15;
    // 0x8004549C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_15:
    // 0x800454A0: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800454A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800454A8: nop

    // 0x800454AC: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800454B0: add.d       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f0.d + ctx->f20.d;
    // 0x800454B4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800454B8: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    // 0x800454BC: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x800454C0: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800454C4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800454C8: nop

    // 0x800454CC: jal         0x8004EC44
    // 0x800454D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_16;
    // 0x800454D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_16:
    // 0x800454D4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800454D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800454DC: nop

    // 0x800454E0: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800454E4: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x800454E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800454EC: addiu       $a0, $a0, -0x238C
    ctx->r4 = ADD32(ctx->r4, -0X238C);
    // 0x800454F0: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    // 0x800454F4: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800454F8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800454FC: nop

    // 0x80045500: jal         0x8004EC44
    // 0x80045504: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_17;
    // 0x80045504: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_17:
    // 0x80045508: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8004550C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80045510: nop

    // 0x80045514: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80045518: add.d       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f0.d + ctx->f20.d;
    // 0x8004551C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045520: addiu       $a0, $a0, -0x2388
    ctx->r4 = ADD32(ctx->r4, -0X2388);
    // 0x80045524: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x80045528: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004552C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80045530: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80045534:
    // 0x80045534: jal         0x8004EC44
    // 0x80045538: nop

    func_8004EC44(rdram, ctx);
        goto after_18;
    // 0x80045538: nop

    after_18:
L_8004553C:
    // 0x8004553C: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x80045540: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80045544: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80045548: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x8004554C: jr          $ra
    // 0x80045550: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80045550: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80045554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045554: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045558: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8004555C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80045560: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80045564: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80045568: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8004556C: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x80045570: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80045B14;
    }
    // 0x80045570: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80045574: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80045578: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004557C: addu        $at, $at, $v0
    gpr jr_addend_80045584 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045580: lw          $v0, -0x2350($at)
    ctx->r2 = ADD32(ctx->r1, -0X2350);
    // 0x80045584: jr          $v0
    // 0x80045588: nop

    switch (jr_addend_80045584 >> 2) {
        case 0: goto L_8004558C; break;
        case 1: goto L_8004574C; break;
        case 2: goto L_80045964; break;
        case 3: goto L_8004579C; break;
        case 4: goto L_800458F4; break;
        case 5: goto L_80045964; break;
        case 6: goto L_80045A00; break;
        default: switch_error(__func__, 0x80045584, 0x800ADCB0);
    }
    // 0x80045588: nop

L_8004558C:
    // 0x8004558C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045590: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80045594: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80045598: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004559C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800455A0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x800455A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800455A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800455AC: sb          $zero, 0x4A1E($at)
    MEM_B(0X4A1E, ctx->r1) = 0;
    // 0x800455B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800455B4: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x800455B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800455BC: sb          $zero, -0x474F($at)
    MEM_B(-0X474F, ctx->r1) = 0;
    // 0x800455C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800455C4: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800455C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800455CC: jal         0x8000BB3C
    // 0x800455D0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_8000BB3C(rdram, ctx);
        goto after_0;
    // 0x800455D0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_0:
    // 0x800455D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800455D8: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x800455DC: beq         $v0, $zero, L_800455F4
    if (ctx->r2 == 0) {
        // 0x800455E0: nop
    
            goto L_800455F4;
    }
    // 0x800455E0: nop

    // 0x800455E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800455E8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800455EC: j           L_80045600
    // 0x800455F0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80045600;
    // 0x800455F0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_800455F4:
    // 0x800455F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800455F8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800455FC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80045600:
    // 0x80045600: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045604: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80045608: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004560C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80045610: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80045614: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045618: lbu         $v1, -0x46C4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X46C4);
    // 0x8004561C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80045620: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x80045624: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80045628: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8004562C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045630: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045634: lw          $v0, -0x4BE8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X4BE8);
    // 0x80045638: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004563C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045640: jal         0x80043F0C
    // 0x80045644: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_1;
    // 0x80045644: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_1:
    // 0x80045648: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004564C: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80045650: jal         0x80017760
    // 0x80045654: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_2;
    // 0x80045654: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_2:
    // 0x80045658: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8004565C: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80045660: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80045664: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045668: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x8004566C: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80045670: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80045674: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x80045678: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004567C: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80045680: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045684: jal         0x80066D30
    // 0x80045688: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_3;
    // 0x80045688: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_3:
    // 0x8004568C: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80045690: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80045694: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80045698: jal         0x80006D98
    // 0x8004569C: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x8004569C: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_4:
    // 0x800456A0: jal         0x80053390
    // 0x800456A4: nop

    func_80053390(rdram, ctx);
        goto after_5;
    // 0x800456A4: nop

    after_5:
    // 0x800456A8: jal         0x800449C0
    // 0x800456AC: nop

    func_800449C0(rdram, ctx);
        goto after_6;
    // 0x800456AC: nop

    after_6:
    // 0x800456B0: jal         0x800440FC
    // 0x800456B4: nop

    func_800440FC(rdram, ctx);
        goto after_7;
    // 0x800456B4: nop

    after_7:
    // 0x800456B8: jal         0x80031BEC
    // 0x800456BC: nop

    func_80031BEC(rdram, ctx);
        goto after_8;
    // 0x800456BC: nop

    after_8:
    // 0x800456C0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800456C4: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800456C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800456CC: jal         0x80040558
    // 0x800456D0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_9;
    // 0x800456D0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_9:
    // 0x800456D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800456D8: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800456DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800456E0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800456E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800456E8: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800456EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800456F0: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800456F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800456F8: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x800456FC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80045700: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80045704: beq         $v0, $zero, L_8004572C
    if (ctx->r2 == 0) {
        // 0x80045708: nop
    
            goto L_8004572C;
    }
    // 0x80045708: nop

    // 0x8004570C: jal         0x80006944
    // 0x80045710: nop

    func_80006944(rdram, ctx);
        goto after_10;
    // 0x80045710: nop

    after_10:
    // 0x80045714: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80045718: jal         0x800067C8
    // 0x8004571C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_11;
    // 0x8004571C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_11:
    // 0x80045720: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80045724: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045728: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_8004572C:
    // 0x8004572C: jal         0x8002CFB8
    // 0x80045730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_12;
    // 0x80045730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80045734: jal         0x8002D378
    // 0x80045738: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_13;
    // 0x80045738: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x8004573C: jal         0x8002D0D4
    // 0x80045740: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_14;
    // 0x80045740: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x80045744: j           L_80045B14
    // 0x80045748: nop

        goto L_80045B14;
    // 0x80045748: nop

L_8004574C:
    // 0x8004574C: jal         0x80008CDC
    // 0x80045750: nop

    func_80008CDC(rdram, ctx);
        goto after_15;
    // 0x80045750: nop

    after_15:
    // 0x80045754: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045758: nop
    
            goto L_80045B14;
    }
    // 0x80045758: nop

    // 0x8004575C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045760: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045764: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045768: nop
    
            goto L_80045B14;
    }
    // 0x80045768: nop

    // 0x8004576C: jal         0x8002CFB8
    // 0x80045770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_16;
    // 0x80045770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80045774: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x80045778: nop
    
            goto L_80045B14;
    }
    // 0x80045778: nop

    // 0x8004577C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045780: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80045784: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045788: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x8004578C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045790: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045794: j           L_80045B14
    // 0x80045798: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80045B14;
    // 0x80045798: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8004579C:
    // 0x8004579C: jal         0x80008CDC
    // 0x800457A0: nop

    func_80008CDC(rdram, ctx);
        goto after_17;
    // 0x800457A0: nop

    after_17:
    // 0x800457A4: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x800457A8: nop
    
            goto L_80045B14;
    }
    // 0x800457A8: nop

    // 0x800457AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800457B0: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800457B4: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x800457B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045B14;
    }
    // 0x800457B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800457BC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800457C0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x800457C4: beq         $v1, $v0, L_800457DC
    if (ctx->r3 == ctx->r2) {
        // 0x800457C8: nop
    
            goto L_800457DC;
    }
    // 0x800457C8: nop

    // 0x800457CC: jal         0x8002CFB8
    // 0x800457D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_18;
    // 0x800457D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_18:
    // 0x800457D4: j           L_800457E4
    // 0x800457D8: nop

        goto L_800457E4;
    // 0x800457D8: nop

L_800457DC:
    // 0x800457DC: jal         0x8002D0D4
    // 0x800457E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_19;
    // 0x800457E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
L_800457E4:
    // 0x800457E4: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x800457E8: nop
    
            goto L_80045B14;
    }
    // 0x800457E8: nop

    // 0x800457EC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800457F0: jal         0x800535B0
    // 0x800457F4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_20;
    // 0x800457F4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_20:
    // 0x800457F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800457FC: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x80045800: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80045804: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80045808: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004580C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80045810: beq         $v0, $zero, L_80045A4C
    if (ctx->r2 == 0) {
        // 0x80045814: nop
    
            goto L_80045A4C;
    }
    // 0x80045814: nop

    // 0x80045818: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004581C: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80045820: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80045824: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045828: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x8004582C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045830: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80045834: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80045838: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004583C: jal         0x80043F0C
    // 0x80045840: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_21;
    // 0x80045840: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_21:
    // 0x80045844: jal         0x800449C0
    // 0x80045848: nop

    func_800449C0(rdram, ctx);
        goto after_22;
    // 0x80045848: nop

    after_22:
    // 0x8004584C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045850: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80045854: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80045858: bne         $v1, $v0, L_80045874
    if (ctx->r3 != ctx->r2) {
        // 0x8004585C: addiu       $v0, $zero, 0x1C0
        ctx->r2 = ADD32(0, 0X1C0);
            goto L_80045874;
    }
    // 0x8004585C: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x80045860: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045864: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x80045868: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8004586C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045870: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
L_80045874:
    // 0x80045874: jal         0x800440FC
    // 0x80045878: nop

    func_800440FC(rdram, ctx);
        goto after_23;
    // 0x80045878: nop

    after_23:
    // 0x8004587C: jal         0x80031BEC
    // 0x80045880: nop

    func_80031BEC(rdram, ctx);
        goto after_24;
    // 0x80045880: nop

    after_24:
    // 0x80045884: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045888: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004588C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80045890: jal         0x80040558
    // 0x80045894: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_25;
    // 0x80045894: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_25:
    // 0x80045898: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004589C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800458A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800458A4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800458A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800458AC: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800458B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800458B4: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800458B8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800458BC: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800458C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800458C4: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x800458C8: beq         $v1, $v0, L_80045B14
    if (ctx->r3 == ctx->r2) {
        // 0x800458CC: nop
    
            goto L_80045B14;
    }
    // 0x800458CC: nop

    // 0x800458D0: jal         0x80006944
    // 0x800458D4: nop

    func_80006944(rdram, ctx);
        goto after_26;
    // 0x800458D4: nop

    after_26:
    // 0x800458D8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800458DC: jal         0x800067C8
    // 0x800458E0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_27;
    // 0x800458E0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_27:
    // 0x800458E4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800458E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800458EC: j           L_80045B14
    // 0x800458F0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80045B14;
    // 0x800458F0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_800458F4:
    // 0x800458F4: jal         0x80008CDC
    // 0x800458F8: nop

    func_80008CDC(rdram, ctx);
        goto after_28;
    // 0x800458F8: nop

    after_28:
    // 0x800458FC: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045900: nop
    
            goto L_80045B14;
    }
    // 0x80045900: nop

    // 0x80045904: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045908: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004590C: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045910: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045B14;
    }
    // 0x80045910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045914: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045918: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x8004591C: beq         $v1, $v0, L_80045934
    if (ctx->r3 == ctx->r2) {
        // 0x80045920: nop
    
            goto L_80045934;
    }
    // 0x80045920: nop

    // 0x80045924: jal         0x8002CFB8
    // 0x80045928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_29;
    // 0x80045928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x8004592C: j           L_8004593C
    // 0x80045930: nop

        goto L_8004593C;
    // 0x80045930: nop

L_80045934:
    // 0x80045934: jal         0x8002D0D4
    // 0x80045938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_30;
    // 0x80045938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
L_8004593C:
    // 0x8004593C: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x80045940: nop
    
            goto L_80045B14;
    }
    // 0x80045940: nop

    // 0x80045944: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045948: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8004594C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80045950: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045954: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80045958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004595C: j           L_80045B14
    // 0x80045960: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80045B14;
    // 0x80045960: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80045964:
    // 0x80045964: jal         0x80008CDC
    // 0x80045968: nop

    func_80008CDC(rdram, ctx);
        goto after_31;
    // 0x80045968: nop

    after_31:
    // 0x8004596C: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045970: nop
    
            goto L_80045B14;
    }
    // 0x80045970: nop

    // 0x80045974: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045978: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004597C: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045980: nop
    
            goto L_80045B14;
    }
    // 0x80045980: nop

    // 0x80045984: jal         0x80044B18
    // 0x80045988: nop

    func_80044B18(rdram, ctx);
        goto after_32;
    // 0x80045988: nop

    after_32:
    // 0x8004598C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80045990: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80045994: beq         $v0, $zero, L_800459C0
    if (ctx->r2 == 0) {
        // 0x80045998: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800459C0;
    }
    // 0x80045998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004599C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800459A0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800459A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800459A8: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800459AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800459B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800459B4: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x800459B8: jal         0x800064C0
    // 0x800459BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_33;
    // 0x800459BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_33:
L_800459C0:
    // 0x800459C0: jal         0x8000B840
    // 0x800459C4: nop

    func_8000B840(rdram, ctx);
        goto after_34;
    // 0x800459C4: nop

    after_34:
    // 0x800459C8: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800459CC: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x800459D0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80045B14;
    }
    // 0x800459D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800459D4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800459D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800459DC: sb          $v1, 0x4A1E($at)
    MEM_B(0X4A1E, ctx->r1) = ctx->r3;
    // 0x800459E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800459E4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800459E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800459EC: sb          $v1, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r3;
    // 0x800459F0: jal         0x800064C0
    // 0x800459F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_35;
    // 0x800459F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_35:
    // 0x800459F8: j           L_80045B14
    // 0x800459FC: nop

        goto L_80045B14;
    // 0x800459FC: nop

L_80045A00:
    // 0x80045A00: jal         0x80008CDC
    // 0x80045A04: nop

    func_80008CDC(rdram, ctx);
        goto after_36;
    // 0x80045A04: nop

    after_36:
    // 0x80045A08: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045A0C: nop
    
            goto L_80045B14;
    }
    // 0x80045A0C: nop

    // 0x80045A10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045A14: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045A18: bne         $v0, $zero, L_80045B14
    if (ctx->r2 != 0) {
        // 0x80045A1C: nop
    
            goto L_80045B14;
    }
    // 0x80045A1C: nop

    // 0x80045A20: jal         0x8002CFB8
    // 0x80045A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_37;
    // 0x80045A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_37:
    // 0x80045A28: beq         $v0, $zero, L_80045B14
    if (ctx->r2 == 0) {
        // 0x80045A2C: nop
    
            goto L_80045B14;
    }
    // 0x80045A2C: nop

    // 0x80045A30: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80045A34: lbu         $v0, 0x4A1E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A1E);
    // 0x80045A38: bne         $v0, $zero, L_80045AA0
    if (ctx->r2 != 0) {
        // 0x80045A3C: nop
    
            goto L_80045AA0;
    }
    // 0x80045A3C: nop

    // 0x80045A40: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80045A44: jal         0x800535B0
    // 0x80045A48: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_38;
    // 0x80045A48: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_38:
L_80045A4C:
    // 0x80045A4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045A50: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80045A54: beq         $v0, $zero, L_80045A64
    if (ctx->r2 == 0) {
        // 0x80045A58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045A64;
    }
    // 0x80045A58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045A5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045A60: sb          $v0, 0x260D($at)
    MEM_B(0X260D, ctx->r1) = ctx->r2;
L_80045A64:
    // 0x80045A64: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045A68: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80045A6C: beq         $v0, $zero, L_80045A7C
    if (ctx->r2 == 0) {
        // 0x80045A70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045A7C;
    }
    // 0x80045A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045A74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045A78: sb          $v0, 0x7A5D($at)
    MEM_B(0X7A5D, ctx->r1) = ctx->r2;
L_80045A7C:
    // 0x80045A7C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80045A80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045A84: sb          $s0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r16;
    // 0x80045A88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045A8C: jal         0x80031BEC
    // 0x80045A90: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_39;
    // 0x80045A90: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    after_39:
    // 0x80045A94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045A98: j           L_80045B14
    // 0x80045A9C: sb          $s0, -0x474F($at)
    MEM_B(-0X474F, ctx->r1) = ctx->r16;
        goto L_80045B14;
    // 0x80045A9C: sb          $s0, -0x474F($at)
    MEM_B(-0X474F, ctx->r1) = ctx->r16;
L_80045AA0:
    // 0x80045AA0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80045AA4: jal         0x800535B0
    // 0x80045AA8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_40;
    // 0x80045AA8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_40:
    // 0x80045AAC: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80045AB0: addiu       $s1, $s1, 0x25A0
    ctx->r17 = ADD32(ctx->r17, 0X25A0);
    // 0x80045AB4: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x80045AB8: beq         $v0, $zero, L_80045AC8
    if (ctx->r2 == 0) {
        // 0x80045ABC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045AC8;
    }
    // 0x80045ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045AC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045AC4: sb          $v0, 0x260D($at)
    MEM_B(0X260D, ctx->r1) = ctx->r2;
L_80045AC8:
    // 0x80045AC8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80045ACC: addiu       $s0, $s0, 0x79F0
    ctx->r16 = ADD32(ctx->r16, 0X79F0);
    // 0x80045AD0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80045AD4: beq         $v0, $zero, L_80045AE4
    if (ctx->r2 == 0) {
        // 0x80045AD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045AE4;
    }
    // 0x80045AD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045ADC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045AE0: sb          $v0, 0x7A5D($at)
    MEM_B(0X7A5D, ctx->r1) = ctx->r2;
L_80045AE4:
    // 0x80045AE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80045AE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045AEC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80045AF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045AF4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80045AF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045AFC: jal         0x80031BEC
    // 0x80045B00: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_41;
    // 0x80045B00: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    after_41:
    // 0x80045B04: jal         0x80016AB4
    // 0x80045B08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016AB4(rdram, ctx);
        goto after_42;
    // 0x80045B08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_42:
    // 0x80045B0C: jal         0x80016AB4
    // 0x80045B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016AB4(rdram, ctx);
        goto after_43;
    // 0x80045B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_43:
L_80045B14:
    // 0x80045B14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045B18: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80045B1C: bne         $v0, $zero, L_80045B58
    if (ctx->r2 != 0) {
        // 0x80045B20: nop
    
            goto L_80045B58;
    }
    // 0x80045B20: nop

    // 0x80045B24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045B28: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045B2C: bne         $v0, $zero, L_80045B58
    if (ctx->r2 != 0) {
        // 0x80045B30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80045B58;
    }
    // 0x80045B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045B34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045B38: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80045B3C: beq         $v1, $v0, L_80045B58
    if (ctx->r3 == ctx->r2) {
        // 0x80045B40: nop
    
            goto L_80045B58;
    }
    // 0x80045B40: nop

    // 0x80045B44: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045B48: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80045B4C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80045B50: jal         0x8004114C
    // 0x80045B54: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_44;
    // 0x80045B54: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_44:
L_80045B58:
    // 0x80045B58: jal         0x800448B0
    // 0x80045B5C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_45;
    // 0x80045B5C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_45:
    // 0x80045B60: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80045B64: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x80045B68: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80045B6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045B70: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80045B74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80045B78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045B7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045B80: lw          $v0, -0x47C8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X47C8);
    // 0x80045B84: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80045B88: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045B8C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80045B90: bne         $v0, $zero, L_80045BB8
    if (ctx->r2 != 0) {
        // 0x80045B94: nop
    
            goto L_80045BB8;
    }
    // 0x80045B94: nop

    // 0x80045B98: jal         0x80017D38
    // 0x80045B9C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_46;
    // 0x80045B9C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_46:
    // 0x80045BA0: jal         0x80017D38
    // 0x80045BA4: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_47;
    // 0x80045BA4: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_47:
    // 0x80045BA8: jal         0x80051D6C
    // 0x80045BAC: nop

    func_80051D6C(rdram, ctx);
        goto after_48;
    // 0x80045BAC: nop

    after_48:
    // 0x80045BB0: j           L_80045BD0
    // 0x80045BB4: nop

        goto L_80045BD0;
    // 0x80045BB4: nop

L_80045BB8:
    // 0x80045BB8: jal         0x80017D38
    // 0x80045BBC: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_49;
    // 0x80045BBC: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_49:
    // 0x80045BC0: jal         0x80051D6C
    // 0x80045BC4: nop

    func_80051D6C(rdram, ctx);
        goto after_50;
    // 0x80045BC4: nop

    after_50:
    // 0x80045BC8: jal         0x80017D38
    // 0x80045BCC: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_51;
    // 0x80045BCC: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_51:
L_80045BD0:
    // 0x80045BD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045BD4: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045BD8: bne         $v0, $zero, L_80045BF8
    if (ctx->r2 != 0) {
        // 0x80045BDC: nop
    
            goto L_80045BF8;
    }
    // 0x80045BDC: nop

    // 0x80045BE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80045BE4: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x80045BE8: beq         $v0, $zero, L_80045BF8
    if (ctx->r2 == 0) {
        // 0x80045BEC: nop
    
            goto L_80045BF8;
    }
    // 0x80045BEC: nop

    // 0x80045BF0: jal         0x800533F0
    // 0x80045BF4: nop

    func_800533F0(rdram, ctx);
        goto after_52;
    // 0x80045BF4: nop

    after_52:
L_80045BF8:
    // 0x80045BF8: jal         0x80044D6C
    // 0x80045BFC: nop

    func_80044D6C(rdram, ctx);
        goto after_53;
    // 0x80045BFC: nop

    after_53:
    // 0x80045C00: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80045C04: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80045C08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80045C0C: jr          $ra
    // 0x80045C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80045C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80045C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045C18: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80045C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045C20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80045C24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80045C28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045C2C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80045C30: lw          $v0, -0x46C4($at)
    ctx->r2 = MEM_W(ctx->r1, -0X46C4);
    // 0x80045C34: jalr        $v0
    // 0x80045C38: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80045C38: nop

    after_0:
    // 0x80045C3C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80045C40: jr          $ra
    // 0x80045C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80045C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80045C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C48: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80045C4C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80045C50: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80045C54: addiu       $s0, $s0, 0x7B71
    ctx->r16 = ADD32(ctx->r16, 0X7B71);
    // 0x80045C58: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80045C5C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80045C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045C64: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80045C68: beq         $v1, $v0, L_80045E60
    if (ctx->r3 == ctx->r2) {
        // 0x80045C6C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80045E60;
    }
    // 0x80045C6C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80045C70: beql        $v0, $zero, L_80045C88
    if (ctx->r2 == 0) {
        // 0x80045C74: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80045C88;
    }
    goto skip_0;
    // 0x80045C74: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80045C78: beq         $v1, $zero, L_80045CA0
    if (ctx->r3 == 0) {
        // 0x80045C7C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80045CA0;
    }
    // 0x80045C7C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80045C80: j           L_80045FB4
    // 0x80045C84: nop

        goto L_80045FB4;
    // 0x80045C84: nop

L_80045C88:
    // 0x80045C88: beq         $v1, $v0, L_80045EA8
    if (ctx->r3 == ctx->r2) {
        // 0x80045C8C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80045EA8;
    }
    // 0x80045C8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80045C90: beq         $v1, $v0, L_80045F30
    if (ctx->r3 == ctx->r2) {
        // 0x80045C94: nop
    
            goto L_80045F30;
    }
    // 0x80045C94: nop

    // 0x80045C98: j           L_80045FB4
    // 0x80045C9C: nop

        goto L_80045FB4;
    // 0x80045C9C: nop

L_80045CA0:
    // 0x80045CA0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045CA4: lb          $v1, 0x25A0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25A0);
    // 0x80045CA8: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80045CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045CB0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045CB4: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80045CB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80045CBC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045CC0: beq         $v1, $zero, L_80045CD8
    if (ctx->r3 == 0) {
        // 0x80045CC4: sb          $v0, 0x7B8D($at)
        MEM_B(0X7B8D, ctx->r1) = ctx->r2;
            goto L_80045CD8;
    }
    // 0x80045CC4: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80045CC8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045CCC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80045CD0: j           L_80045CE4
    // 0x80045CD4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80045CE4;
    // 0x80045CD4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_80045CD8:
    // 0x80045CD8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045CDC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80045CE0: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80045CE4:
    // 0x80045CE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045CE8: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80045CEC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045CF0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80045CF4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80045CF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045CFC: lbu         $v0, -0x46A8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X46A8);
    // 0x80045D00: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80045D04: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x80045D08: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80045D0C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80045D10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045D14: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80045D18: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80045D1C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80045D20: lw          $a0, -0x4BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BE8);
    // 0x80045D24: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80045D28: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80045D2C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80045D30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045D34: jal         0x80043F0C
    // 0x80045D38: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80045D38: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x80045D3C: jal         0x80053390
    // 0x80045D40: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80045D40: nop

    after_1:
    // 0x80045D44: jal         0x800449C0
    // 0x80045D48: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80045D48: nop

    after_2:
    // 0x80045D4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045D50: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80045D54: jal         0x80017760
    // 0x80045D58: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80045D58: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x80045D5C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80045D60: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80045D64: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80045D68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045D6C: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80045D70: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80045D74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80045D78: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x80045D7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045D80: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80045D84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045D88: jal         0x80066D30
    // 0x80045D8C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x80045D8C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x80045D90: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80045D94: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80045D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80045D9C: jal         0x80006D98
    // 0x80045DA0: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x80045DA0: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x80045DA4: jal         0x800440FC
    // 0x80045DA8: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x80045DA8: nop

    after_6:
    // 0x80045DAC: jal         0x80031BEC
    // 0x80045DB0: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x80045DB0: nop

    after_7:
    // 0x80045DB4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045DB8: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80045DBC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80045DC0: jal         0x80040558
    // 0x80045DC4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x80045DC4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x80045DC8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80045DCC: lb          $v0, -0x474F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X474F);
    // 0x80045DD0: bne         $v0, $zero, L_80045DE0
    if (ctx->r2 != 0) {
        // 0x80045DD4: nop
    
            goto L_80045DE0;
    }
    // 0x80045DD4: nop

    // 0x80045DD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045DDC: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
L_80045DE0:
    // 0x80045DE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045DE4: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80045DE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80045DEC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80045DF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045DF4: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80045DF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045DFC: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80045E00: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045E04: sb          $zero, -0x474F($at)
    MEM_B(-0X474F, ctx->r1) = 0;
    // 0x80045E08: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80045E0C: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80045E10: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80045E14: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x80045E18: beq         $v1, $v0, L_80045E40
    if (ctx->r3 == ctx->r2) {
        // 0x80045E1C: nop
    
            goto L_80045E40;
    }
    // 0x80045E1C: nop

    // 0x80045E20: jal         0x80006944
    // 0x80045E24: nop

    func_80006944(rdram, ctx);
        goto after_9;
    // 0x80045E24: nop

    after_9:
    // 0x80045E28: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80045E2C: jal         0x800067C8
    // 0x80045E30: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_10;
    // 0x80045E30: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_10:
    // 0x80045E34: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80045E38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045E3C: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80045E40:
    // 0x80045E40: jal         0x8002CFB8
    // 0x80045E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80045E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80045E48: jal         0x8002D378
    // 0x80045E4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_12;
    // 0x80045E4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80045E50: jal         0x8002D0D4
    // 0x80045E54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_13;
    // 0x80045E54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80045E58: j           L_80045FB4
    // 0x80045E5C: nop

        goto L_80045FB4;
    // 0x80045E5C: nop

L_80045E60:
    // 0x80045E60: jal         0x80008CDC
    // 0x80045E64: nop

    func_80008CDC(rdram, ctx);
        goto after_14;
    // 0x80045E64: nop

    after_14:
    // 0x80045E68: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045E6C: nop
    
            goto L_80045FB4;
    }
    // 0x80045E6C: nop

    // 0x80045E70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045E74: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045E78: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045E7C: nop
    
            goto L_80045FB4;
    }
    // 0x80045E7C: nop

    // 0x80045E80: jal         0x8002CFB8
    // 0x80045E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_15;
    // 0x80045E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80045E88: beq         $v0, $zero, L_80045FB4
    if (ctx->r2 == 0) {
        // 0x80045E8C: nop
    
            goto L_80045FB4;
    }
    // 0x80045E8C: nop

    // 0x80045E90: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80045E94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045E98: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80045E9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045EA0: j           L_80045FB4
    // 0x80045EA4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_80045FB4;
    // 0x80045EA4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80045EA8:
    // 0x80045EA8: jal         0x80008CDC
    // 0x80045EAC: nop

    func_80008CDC(rdram, ctx);
        goto after_16;
    // 0x80045EAC: nop

    after_16:
    // 0x80045EB0: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045EB4: nop
    
            goto L_80045FB4;
    }
    // 0x80045EB4: nop

    // 0x80045EB8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045EBC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045EC0: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045EC4: nop
    
            goto L_80045FB4;
    }
    // 0x80045EC4: nop

    // 0x80045EC8: jal         0x80044B18
    // 0x80045ECC: nop

    func_80044B18(rdram, ctx);
        goto after_17;
    // 0x80045ECC: nop

    after_17:
    // 0x80045ED0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80045ED4: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80045ED8: beq         $v0, $zero, L_80045EFC
    if (ctx->r2 == 0) {
        // 0x80045EDC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80045EFC;
    }
    // 0x80045EDC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80045EE0: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80045EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045EE8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045EEC: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80045EF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80045EF4: jal         0x800064C0
    // 0x80045EF8: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    func_800064C0(rdram, ctx);
        goto after_18;
    // 0x80045EF8: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    after_18:
L_80045EFC:
    // 0x80045EFC: jal         0x8000B840
    // 0x80045F00: nop

    func_8000B840(rdram, ctx);
        goto after_19;
    // 0x80045F00: nop

    after_19:
    // 0x80045F04: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80045F08: beq         $v0, $zero, L_80045FB4
    if (ctx->r2 == 0) {
        // 0x80045F0C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80045FB4;
    }
    // 0x80045F0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80045F10: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80045F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045F18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80045F1C: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80045F20: jal         0x800064C0
    // 0x80045F24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_20;
    // 0x80045F24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_20:
    // 0x80045F28: j           L_80045FB4
    // 0x80045F2C: nop

        goto L_80045FB4;
    // 0x80045F2C: nop

L_80045F30:
    // 0x80045F30: jal         0x80008CDC
    // 0x80045F34: nop

    func_80008CDC(rdram, ctx);
        goto after_21;
    // 0x80045F34: nop

    after_21:
    // 0x80045F38: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045F3C: nop
    
            goto L_80045FB4;
    }
    // 0x80045F3C: nop

    // 0x80045F40: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045F44: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045F48: bne         $v0, $zero, L_80045FB4
    if (ctx->r2 != 0) {
        // 0x80045F4C: nop
    
            goto L_80045FB4;
    }
    // 0x80045F4C: nop

    // 0x80045F50: jal         0x8002CFB8
    // 0x80045F54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_22;
    // 0x80045F54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
    // 0x80045F58: beq         $v0, $zero, L_80045FB4
    if (ctx->r2 == 0) {
        // 0x80045F5C: nop
    
            goto L_80045FB4;
    }
    // 0x80045F5C: nop

    // 0x80045F60: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80045F64: jal         0x800535B0
    // 0x80045F68: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_23;
    // 0x80045F68: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_23:
    // 0x80045F6C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045F70: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x80045F74: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80045F78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80045F7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045F80: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80045F84: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80045F88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80045F8C: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80045F90: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80045F94: jal         0x80031BEC
    // 0x80045F98: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80031BEC(rdram, ctx);
        goto after_24;
    // 0x80045F98: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_24:
    // 0x80045F9C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045FA0: jal         0x80016AB4
    // 0x80045FA4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_25;
    // 0x80045FA4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_25:
    // 0x80045FA8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045FAC: jal         0x80016AB4
    // 0x80045FB0: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_26;
    // 0x80045FB0: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_26:
L_80045FB4:
    // 0x80045FB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045FB8: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80045FBC: bne         $v0, $zero, L_80045FF8
    if (ctx->r2 != 0) {
        // 0x80045FC0: nop
    
            goto L_80045FF8;
    }
    // 0x80045FC0: nop

    // 0x80045FC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80045FC8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80045FCC: bne         $v0, $zero, L_80045FF8
    if (ctx->r2 != 0) {
        // 0x80045FD0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80045FF8;
    }
    // 0x80045FD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80045FD4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80045FD8: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80045FDC: beq         $v1, $v0, L_80045FF8
    if (ctx->r3 == ctx->r2) {
        // 0x80045FE0: nop
    
            goto L_80045FF8;
    }
    // 0x80045FE0: nop

    // 0x80045FE4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80045FE8: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80045FEC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80045FF0: jal         0x8004114C
    // 0x80045FF4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_27;
    // 0x80045FF4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_27:
L_80045FF8:
    // 0x80045FF8: jal         0x800448B0
    // 0x80045FFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_28;
    // 0x80045FFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_28:
    // 0x80046000: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80046004: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x80046008: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004600C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046010: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046014: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046018: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004601C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80046020: lw          $a0, -0x47C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X47C8);
    // 0x80046024: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80046028: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004602C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80046030: bne         $v0, $zero, L_80046058
    if (ctx->r2 != 0) {
        // 0x80046034: nop
    
            goto L_80046058;
    }
    // 0x80046034: nop

    // 0x80046038: jal         0x80017D38
    // 0x8004603C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_29;
    // 0x8004603C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_29:
    // 0x80046040: jal         0x80017D38
    // 0x80046044: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_30;
    // 0x80046044: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_30:
    // 0x80046048: jal         0x80051D6C
    // 0x8004604C: nop

    func_80051D6C(rdram, ctx);
        goto after_31;
    // 0x8004604C: nop

    after_31:
    // 0x80046050: j           L_80046070
    // 0x80046054: nop

        goto L_80046070;
    // 0x80046054: nop

L_80046058:
    // 0x80046058: jal         0x80017D38
    // 0x8004605C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_32;
    // 0x8004605C: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_32:
    // 0x80046060: jal         0x80051D6C
    // 0x80046064: nop

    func_80051D6C(rdram, ctx);
        goto after_33;
    // 0x80046064: nop

    after_33:
    // 0x80046068: jal         0x80017D38
    // 0x8004606C: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_34;
    // 0x8004606C: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_34:
L_80046070:
    // 0x80046070: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046074: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046078: bne         $v0, $zero, L_80046098
    if (ctx->r2 != 0) {
        // 0x8004607C: nop
    
            goto L_80046098;
    }
    // 0x8004607C: nop

    // 0x80046080: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80046084: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x80046088: beq         $v0, $zero, L_80046098
    if (ctx->r2 == 0) {
        // 0x8004608C: nop
    
            goto L_80046098;
    }
    // 0x8004608C: nop

    // 0x80046090: jal         0x800533F0
    // 0x80046094: nop

    func_800533F0(rdram, ctx);
        goto after_35;
    // 0x80046094: nop

    after_35:
L_80046098:
    // 0x80046098: jal         0x80044D6C
    // 0x8004609C: nop

    func_80044D6C(rdram, ctx);
        goto after_36;
    // 0x8004609C: nop

    after_36:
    // 0x800460A0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800460A4: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800460A8: jr          $ra
    // 0x800460AC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800460AC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800460B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800460B0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800460B4: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800460B8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800460BC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800460C0: sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // 0x800460C4: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x800460C8: sw          $s0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r16;
            goto L_80046A5C;
    }
    // 0x800460C8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800460CC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800460D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800460D4: addu        $at, $at, $v0
    gpr jr_addend_800460DC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800460D8: lw          $v0, -0x2330($at)
    ctx->r2 = ADD32(ctx->r1, -0X2330);
    // 0x800460DC: jr          $v0
    // 0x800460E0: nop

    switch (jr_addend_800460DC >> 2) {
        case 0: goto L_800460E4; break;
        case 1: goto L_80046904; break;
        case 2: goto L_80046294; break;
        case 3: goto L_80046310; break;
        case 4: goto L_80046408; break;
        case 5: goto L_80046440; break;
        case 6: goto L_800464B4; break;
        case 7: goto L_80046648; break;
        case 8: goto L_80046294; break;
        case 9: goto L_80046698; break;
        case 10: goto L_80046790; break;
        case 11: goto L_80046954; break;
        case 12: goto L_80046800; break;
        case 13: goto L_80046904; break;
        case 14: goto L_80046954; break;
        case 15: goto L_800469E8; break;
        default: switch_error(__func__, 0x800460DC, 0x800ADCD0);
    }
    // 0x800460E0: nop

L_800460E4:
    // 0x800460E4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800460E8: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x800460EC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800460F0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800460F4: lb          $a1, 0x25A0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X25A0);
    // 0x800460F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800460FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046100: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80046104: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80046108: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004610C: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80046110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046114: beq         $a1, $zero, L_8004612C
    if (ctx->r5 == 0) {
        // 0x80046118: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_8004612C;
    }
    // 0x80046118: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8004611C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046120: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80046124: j           L_80046138
    // 0x80046128: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80046138;
    // 0x80046128: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_8004612C:
    // 0x8004612C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046130: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80046134: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80046138:
    // 0x80046138: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004613C: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80046140: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046144: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046148: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004614C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046150: lbu         $v0, -0x46A4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X46A4);
    // 0x80046154: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80046158: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x8004615C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80046160: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80046164: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046168: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x8004616C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80046170: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80046174: lw          $a0, -0x4BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BE8);
    // 0x80046178: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004617C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80046180: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80046184: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046188: jal         0x80043F0C
    // 0x8004618C: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x8004618C: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x80046190: jal         0x80053390
    // 0x80046194: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80046194: nop

    after_1:
    // 0x80046198: jal         0x800449C0
    // 0x8004619C: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x8004619C: nop

    after_2:
    // 0x800461A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800461A4: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x800461A8: jal         0x80017760
    // 0x800461AC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x800461AC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x800461B0: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800461B4: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x800461B8: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x800461BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800461C0: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x800461C4: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x800461C8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800461CC: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x800461D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800461D4: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x800461D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800461DC: jal         0x80066D30
    // 0x800461E0: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x800461E0: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x800461E4: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x800461E8: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x800461EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800461F0: jal         0x80006D98
    // 0x800461F4: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x800461F4: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x800461F8: jal         0x800440FC
    // 0x800461FC: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x800461FC: nop

    after_6:
    // 0x80046200: jal         0x80031BEC
    // 0x80046204: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x80046204: nop

    after_7:
    // 0x80046208: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004620C: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80046210: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046214: jal         0x80040558
    // 0x80046218: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x80046218: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x8004621C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046220: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80046224: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046228: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004622C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80046230: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80046234: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046238: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x8004623C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046240: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x80046244: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80046248: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004624C: beq         $v0, $zero, L_80046274
    if (ctx->r2 == 0) {
        // 0x80046250: nop
    
            goto L_80046274;
    }
    // 0x80046250: nop

    // 0x80046254: jal         0x80006944
    // 0x80046258: nop

    func_80006944(rdram, ctx);
        goto after_9;
    // 0x80046258: nop

    after_9:
    // 0x8004625C: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80046260: jal         0x800067C8
    // 0x80046264: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_10;
    // 0x80046264: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_10:
    // 0x80046268: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004626C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046270: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80046274:
    // 0x80046274: jal         0x8002CFB8
    // 0x80046278: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80046278: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8004627C: jal         0x8002D378
    // 0x80046280: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_12;
    // 0x80046280: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80046284: jal         0x8002D0D4
    // 0x80046288: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_13;
    // 0x80046288: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x8004628C: j           L_80046A5C
    // 0x80046290: nop

        goto L_80046A5C;
    // 0x80046290: nop

L_80046294:
    // 0x80046294: jal         0x80008CDC
    // 0x80046298: nop

    func_80008CDC(rdram, ctx);
        goto after_14;
    // 0x80046298: nop

    after_14:
    // 0x8004629C: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800462A0: nop
    
            goto L_80046A5C;
    }
    // 0x800462A0: nop

    // 0x800462A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800462A8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800462AC: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800462B0: nop
    
            goto L_80046A5C;
    }
    // 0x800462B0: nop

    // 0x800462B4: jal         0x80044B18
    // 0x800462B8: nop

    func_80044B18(rdram, ctx);
        goto after_15;
    // 0x800462B8: nop

    after_15:
    // 0x800462BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800462C0: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x800462C4: beq         $v0, $zero, L_800469B0
    if (ctx->r2 == 0) {
        // 0x800462C8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800469B0;
    }
    // 0x800462C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800462CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800462D0: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800462D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800462D8: sb          $v1, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r3;
    // 0x800462DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800462E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800462E4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800462E8: jal         0x800064C0
    // 0x800462EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_16;
    // 0x800462EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_16:
    // 0x800462F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800462F4: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800462F8: beq         $v0, $zero, L_80046688
    if (ctx->r2 == 0) {
        // 0x800462FC: nop
    
            goto L_80046688;
    }
    // 0x800462FC: nop

L_80046300:
    // 0x80046300: jal         0x8002D378
    // 0x80046304: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_17;
    // 0x80046304: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_17:
    // 0x80046308: j           L_800469B0
    // 0x8004630C: nop

        goto L_800469B0;
    // 0x8004630C: nop

L_80046310:
    // 0x80046310: jal         0x80008CDC
    // 0x80046314: nop

    func_80008CDC(rdram, ctx);
        goto after_18;
    // 0x80046314: nop

    after_18:
    // 0x80046318: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004631C: nop
    
            goto L_80046A5C;
    }
    // 0x8004631C: nop

    // 0x80046320: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046324: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046328: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004632C: nop
    
            goto L_80046A5C;
    }
    // 0x8004632C: nop

    // 0x80046330: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046334: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80046338: beq         $v0, $zero, L_80046350
    if (ctx->r2 == 0) {
        // 0x8004633C: nop
    
            goto L_80046350;
    }
    // 0x8004633C: nop

    // 0x80046340: jal         0x8002CFB8
    // 0x80046344: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_19;
    // 0x80046344: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
    // 0x80046348: j           L_80046358
    // 0x8004634C: nop

        goto L_80046358;
    // 0x8004634C: nop

L_80046350:
    // 0x80046350: jal         0x8002D378
    // 0x80046354: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_20;
    // 0x80046354: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
L_80046358:
    // 0x80046358: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x8004635C: nop
    
            goto L_80046A5C;
    }
    // 0x8004635C: nop

    // 0x80046360: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046364: jal         0x800535B0
    // 0x80046368: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_21;
    // 0x80046368: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_21:
    // 0x8004636C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80046370: addiu       $a2, $a2, 0x7B71
    ctx->r6 = ADD32(ctx->r6, 0X7B71);
    // 0x80046374: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80046378: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004637C: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80046380: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80046384: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046388: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x8004638C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80046390: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046394: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046398: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x8004639C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800463A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800463A4: jal         0x80043F0C
    // 0x800463A8: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_22;
    // 0x800463A8: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_22:
    // 0x800463AC: jal         0x800449C0
    // 0x800463B0: nop

    func_800449C0(rdram, ctx);
        goto after_23;
    // 0x800463B0: nop

    after_23:
    // 0x800463B4: jal         0x800440FC
    // 0x800463B8: nop

    func_800440FC(rdram, ctx);
        goto after_24;
    // 0x800463B8: nop

    after_24:
    // 0x800463BC: jal         0x80031BEC
    // 0x800463C0: nop

    func_80031BEC(rdram, ctx);
        goto after_25;
    // 0x800463C0: nop

    after_25:
    // 0x800463C4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800463C8: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800463CC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800463D0: jal         0x80040558
    // 0x800463D4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_26;
    // 0x800463D4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_26:
    // 0x800463D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800463DC: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800463E0: beq         $v0, $zero, L_800463F8
    if (ctx->r2 == 0) {
        // 0x800463E4: nop
    
            goto L_800463F8;
    }
    // 0x800463E4: nop

    // 0x800463E8: jal         0x8002D378
    // 0x800463EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_27;
    // 0x800463EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_27:
    // 0x800463F0: j           L_800468A8
    // 0x800463F4: nop

        goto L_800468A8;
    // 0x800463F4: nop

L_800463F8:
    // 0x800463F8: jal         0x8002CFB8
    // 0x800463FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_28;
    // 0x800463FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_28:
    // 0x80046400: j           L_800468A8
    // 0x80046404: nop

        goto L_800468A8;
    // 0x80046404: nop

L_80046408:
    // 0x80046408: jal         0x80008CDC
    // 0x8004640C: nop

    func_80008CDC(rdram, ctx);
        goto after_29;
    // 0x8004640C: nop

    after_29:
    // 0x80046410: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046414: nop
    
            goto L_80046A5C;
    }
    // 0x80046414: nop

    // 0x80046418: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004641C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046420: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046424: nop
    
            goto L_80046A5C;
    }
    // 0x80046424: nop

    // 0x80046428: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004642C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80046430: beq         $v0, $zero, L_800467D0
    if (ctx->r2 == 0) {
        // 0x80046434: nop
    
            goto L_800467D0;
    }
    // 0x80046434: nop

    // 0x80046438: j           L_800467C0
    // 0x8004643C: nop

        goto L_800467C0;
    // 0x8004643C: nop

L_80046440:
    // 0x80046440: jal         0x80008CDC
    // 0x80046444: nop

    func_80008CDC(rdram, ctx);
        goto after_30;
    // 0x80046444: nop

    after_30:
    // 0x80046448: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004644C: nop
    
            goto L_80046A5C;
    }
    // 0x8004644C: nop

    // 0x80046450: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046454: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046458: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004645C: nop
    
            goto L_80046A5C;
    }
    // 0x8004645C: nop

    // 0x80046460: jal         0x80044B18
    // 0x80046464: nop

    func_80044B18(rdram, ctx);
        goto after_31;
    // 0x80046464: nop

    after_31:
    // 0x80046468: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004646C: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80046470: beq         $v0, $zero, L_800469B0
    if (ctx->r2 == 0) {
        // 0x80046474: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800469B0;
    }
    // 0x80046474: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80046478: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004647C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80046480: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046484: sb          $v1, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r3;
    // 0x80046488: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004648C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046490: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80046494: jal         0x800064C0
    // 0x80046498: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_32;
    // 0x80046498: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_32:
    // 0x8004649C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800464A0: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800464A4: beq         $v0, $zero, L_80046688
    if (ctx->r2 == 0) {
        // 0x800464A8: nop
    
            goto L_80046688;
    }
    // 0x800464A8: nop

    // 0x800464AC: j           L_80046300
    // 0x800464B0: nop

        goto L_80046300;
    // 0x800464B0: nop

L_800464B4:
    // 0x800464B4: jal         0x80008CDC
    // 0x800464B8: nop

    func_80008CDC(rdram, ctx);
        goto after_33;
    // 0x800464B8: nop

    after_33:
    // 0x800464BC: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800464C0: nop
    
            goto L_80046A5C;
    }
    // 0x800464C0: nop

    // 0x800464C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800464C8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800464CC: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800464D0: nop
    
            goto L_80046A5C;
    }
    // 0x800464D0: nop

    // 0x800464D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800464D8: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800464DC: beq         $v0, $zero, L_800464F4
    if (ctx->r2 == 0) {
        // 0x800464E0: nop
    
            goto L_800464F4;
    }
    // 0x800464E0: nop

    // 0x800464E4: jal         0x8002CFB8
    // 0x800464E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_34;
    // 0x800464E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_34:
    // 0x800464EC: j           L_800464FC
    // 0x800464F0: nop

        goto L_800464FC;
    // 0x800464F0: nop

L_800464F4:
    // 0x800464F4: jal         0x8002D0D4
    // 0x800464F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_35;
    // 0x800464F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_35:
L_800464FC:
    // 0x800464FC: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x80046500: nop
    
            goto L_80046A5C;
    }
    // 0x80046500: nop

    // 0x80046504: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046508: jal         0x800535B0
    // 0x8004650C: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_36;
    // 0x8004650C: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_36:
    // 0x80046510: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046514: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x80046518: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004651C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046520: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80046524: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80046528: beq         $v0, $zero, L_800465E4
    if (ctx->r2 == 0) {
        // 0x8004652C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800465E4;
    }
    // 0x8004652C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80046530: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046534: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80046538: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8004653C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046540: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046544: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046548: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004654C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80046550: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046554: jal         0x80043F0C
    // 0x80046558: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_37;
    // 0x80046558: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_37:
    // 0x8004655C: jal         0x800449C0
    // 0x80046560: nop

    func_800449C0(rdram, ctx);
        goto after_38;
    // 0x80046560: nop

    after_38:
    // 0x80046564: jal         0x800440FC
    // 0x80046568: nop

    func_800440FC(rdram, ctx);
        goto after_39;
    // 0x80046568: nop

    after_39:
    // 0x8004656C: jal         0x80031BEC
    // 0x80046570: nop

    func_80031BEC(rdram, ctx);
        goto after_40;
    // 0x80046570: nop

    after_40:
    // 0x80046574: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046578: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004657C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046580: jal         0x80040558
    // 0x80046584: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_41;
    // 0x80046584: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_41:
    // 0x80046588: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004658C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80046590: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046594: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80046598: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004659C: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800465A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800465A4: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800465A8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800465AC: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800465B0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800465B4: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x800465B8: beq         $v1, $v0, L_80046618
    if (ctx->r3 == ctx->r2) {
        // 0x800465BC: nop
    
            goto L_80046618;
    }
    // 0x800465BC: nop

    // 0x800465C0: jal         0x80006944
    // 0x800465C4: nop

    func_80006944(rdram, ctx);
        goto after_42;
    // 0x800465C4: nop

    after_42:
    // 0x800465C8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800465CC: jal         0x800067C8
    // 0x800465D0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_43;
    // 0x800465D0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_43:
    // 0x800465D4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800465D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800465DC: j           L_80046618
    // 0x800465E0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80046618;
    // 0x800465E0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_800465E4:
    // 0x800465E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800465E8: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800465EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800465F0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800465F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800465F8: jal         0x80031BEC
    // 0x800465FC: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_44;
    // 0x800465FC: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    after_44:
    // 0x80046600: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046604: jal         0x80016AB4
    // 0x80046608: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_45;
    // 0x80046608: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_45:
    // 0x8004660C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046610: jal         0x80016AB4
    // 0x80046614: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_46;
    // 0x80046614: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_46:
L_80046618:
    // 0x80046618: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004661C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80046620: beq         $v0, $zero, L_80046638
    if (ctx->r2 == 0) {
        // 0x80046624: nop
    
            goto L_80046638;
    }
    // 0x80046624: nop

    // 0x80046628: jal         0x8002D378
    // 0x8004662C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_47;
    // 0x8004662C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_47:
    // 0x80046630: j           L_80046A5C
    // 0x80046634: nop

        goto L_80046A5C;
    // 0x80046634: nop

L_80046638:
    // 0x80046638: jal         0x8002CFB8
    // 0x8004663C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_48;
    // 0x8004663C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_48:
    // 0x80046640: j           L_80046A5C
    // 0x80046644: nop

        goto L_80046A5C;
    // 0x80046644: nop

L_80046648:
    // 0x80046648: jal         0x80008CDC
    // 0x8004664C: nop

    func_80008CDC(rdram, ctx);
        goto after_49;
    // 0x8004664C: nop

    after_49:
    // 0x80046650: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046654: nop
    
            goto L_80046A5C;
    }
    // 0x80046654: nop

    // 0x80046658: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004665C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046660: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046664: nop
    
            goto L_80046A5C;
    }
    // 0x80046664: nop

    // 0x80046668: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004666C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80046670: bne         $v0, $zero, L_800467C0
    if (ctx->r2 != 0) {
        // 0x80046674: nop
    
            goto L_800467C0;
    }
    // 0x80046674: nop

    // 0x80046678: jal         0x8002D0D4
    // 0x8004667C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_50;
    // 0x8004667C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_50:
    // 0x80046680: j           L_800467D8
    // 0x80046684: nop

        goto L_800467D8;
    // 0x80046684: nop

L_80046688:
    // 0x80046688: jal         0x8002CFB8
    // 0x8004668C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_51;
    // 0x8004668C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_51:
    // 0x80046690: j           L_800469B0
    // 0x80046694: nop

        goto L_800469B0;
    // 0x80046694: nop

L_80046698:
    // 0x80046698: jal         0x80008CDC
    // 0x8004669C: nop

    func_80008CDC(rdram, ctx);
        goto after_52;
    // 0x8004669C: nop

    after_52:
    // 0x800466A0: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800466A4: nop
    
            goto L_80046A5C;
    }
    // 0x800466A4: nop

    // 0x800466A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800466AC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800466B0: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800466B4: nop
    
            goto L_80046A5C;
    }
    // 0x800466B4: nop

    // 0x800466B8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800466BC: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800466C0: beq         $v0, $zero, L_800466D8
    if (ctx->r2 == 0) {
        // 0x800466C4: nop
    
            goto L_800466D8;
    }
    // 0x800466C4: nop

    // 0x800466C8: jal         0x8002CFB8
    // 0x800466CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_53;
    // 0x800466CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_53:
    // 0x800466D0: j           L_800466E0
    // 0x800466D4: nop

        goto L_800466E0;
    // 0x800466D4: nop

L_800466D8:
    // 0x800466D8: jal         0x8002D378
    // 0x800466DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_54;
    // 0x800466DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_54:
L_800466E0:
    // 0x800466E0: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x800466E4: nop
    
            goto L_80046A5C;
    }
    // 0x800466E4: nop

    // 0x800466E8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800466EC: jal         0x800535B0
    // 0x800466F0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_55;
    // 0x800466F0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_55:
    // 0x800466F4: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800466F8: addiu       $a2, $a2, 0x7B71
    ctx->r6 = ADD32(ctx->r6, 0X7B71);
    // 0x800466FC: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80046700: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046704: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80046708: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8004670C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046710: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046714: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80046718: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004671C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046720: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80046724: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80046728: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004672C: jal         0x80043F0C
    // 0x80046730: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_56;
    // 0x80046730: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_56:
    // 0x80046734: jal         0x800449C0
    // 0x80046738: nop

    func_800449C0(rdram, ctx);
        goto after_57;
    // 0x80046738: nop

    after_57:
    // 0x8004673C: jal         0x800440FC
    // 0x80046740: nop

    func_800440FC(rdram, ctx);
        goto after_58;
    // 0x80046740: nop

    after_58:
    // 0x80046744: jal         0x80031BEC
    // 0x80046748: nop

    func_80031BEC(rdram, ctx);
        goto after_59;
    // 0x80046748: nop

    after_59:
    // 0x8004674C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046750: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80046754: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046758: jal         0x80040558
    // 0x8004675C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_60;
    // 0x8004675C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_60:
    // 0x80046760: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046764: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80046768: beq         $v0, $zero, L_80046780
    if (ctx->r2 == 0) {
        // 0x8004676C: nop
    
            goto L_80046780;
    }
    // 0x8004676C: nop

    // 0x80046770: jal         0x8002D378
    // 0x80046774: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_61;
    // 0x80046774: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_61:
    // 0x80046778: j           L_800468A8
    // 0x8004677C: nop

        goto L_800468A8;
    // 0x8004677C: nop

L_80046780:
    // 0x80046780: jal         0x8002CFB8
    // 0x80046784: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_62;
    // 0x80046784: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_62:
    // 0x80046788: j           L_800468A8
    // 0x8004678C: nop

        goto L_800468A8;
    // 0x8004678C: nop

L_80046790:
    // 0x80046790: jal         0x80008CDC
    // 0x80046794: nop

    func_80008CDC(rdram, ctx);
        goto after_63;
    // 0x80046794: nop

    after_63:
    // 0x80046798: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004679C: nop
    
            goto L_80046A5C;
    }
    // 0x8004679C: nop

    // 0x800467A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800467A4: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800467A8: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800467AC: nop
    
            goto L_80046A5C;
    }
    // 0x800467AC: nop

    // 0x800467B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800467B4: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800467B8: beq         $v0, $zero, L_800467D0
    if (ctx->r2 == 0) {
        // 0x800467BC: nop
    
            goto L_800467D0;
    }
    // 0x800467BC: nop

L_800467C0:
    // 0x800467C0: jal         0x8002CFB8
    // 0x800467C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_64;
    // 0x800467C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x800467C8: j           L_800467D8
    // 0x800467CC: nop

        goto L_800467D8;
    // 0x800467CC: nop

L_800467D0:
    // 0x800467D0: jal         0x8002D378
    // 0x800467D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D378(rdram, ctx);
        goto after_65;
    // 0x800467D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_65:
L_800467D8:
    // 0x800467D8: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x800467DC: nop
    
            goto L_80046A5C;
    }
    // 0x800467DC: nop

    // 0x800467E0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800467E4: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x800467E8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800467EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800467F0: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x800467F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800467F8: j           L_80046A5C
    // 0x800467FC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80046A5C;
    // 0x800467FC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80046800:
    // 0x80046800: jal         0x80008CDC
    // 0x80046804: nop

    func_80008CDC(rdram, ctx);
        goto after_66;
    // 0x80046804: nop

    after_66:
    // 0x80046808: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004680C: nop
    
            goto L_80046A5C;
    }
    // 0x8004680C: nop

    // 0x80046810: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046814: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046818: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x8004681C: nop
    
            goto L_80046A5C;
    }
    // 0x8004681C: nop

    // 0x80046820: jal         0x8002CFB8
    // 0x80046824: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_67;
    // 0x80046824: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_67:
    // 0x80046828: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x8004682C: nop
    
            goto L_80046A5C;
    }
    // 0x8004682C: nop

    // 0x80046830: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046834: jal         0x800535B0
    // 0x80046838: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_68;
    // 0x80046838: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_68:
    // 0x8004683C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046840: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80046844: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046848: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x8004684C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80046850: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046854: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046858: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004685C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046860: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046868: sb          $a0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r4;
    // 0x8004686C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80046870: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046874: jal         0x80043F0C
    // 0x80046878: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_69;
    // 0x80046878: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_69:
    // 0x8004687C: jal         0x800449C0
    // 0x80046880: nop

    func_800449C0(rdram, ctx);
        goto after_70;
    // 0x80046880: nop

    after_70:
    // 0x80046884: jal         0x800440FC
    // 0x80046888: nop

    func_800440FC(rdram, ctx);
        goto after_71;
    // 0x80046888: nop

    after_71:
    // 0x8004688C: jal         0x80031BEC
    // 0x80046890: nop

    func_80031BEC(rdram, ctx);
        goto after_72;
    // 0x80046890: nop

    after_72:
    // 0x80046894: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046898: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004689C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800468A0: jal         0x80040558
    // 0x800468A4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_73;
    // 0x800468A4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_73:
L_800468A8:
    // 0x800468A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800468AC: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800468B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800468B4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800468B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800468BC: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800468C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800468C4: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800468C8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800468CC: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800468D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800468D4: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x800468D8: beq         $v1, $v0, L_80046A5C
    if (ctx->r3 == ctx->r2) {
        // 0x800468DC: nop
    
            goto L_80046A5C;
    }
    // 0x800468DC: nop

    // 0x800468E0: jal         0x80006944
    // 0x800468E4: nop

    func_80006944(rdram, ctx);
        goto after_74;
    // 0x800468E4: nop

    after_74:
    // 0x800468E8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800468EC: jal         0x800067C8
    // 0x800468F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_75;
    // 0x800468F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_75:
    // 0x800468F4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800468F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800468FC: j           L_80046A5C
    // 0x80046900: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80046A5C;
    // 0x80046900: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80046904:
    // 0x80046904: jal         0x80008CDC
    // 0x80046908: nop

    func_80008CDC(rdram, ctx);
        goto after_76;
    // 0x80046908: nop

    after_76:
    // 0x8004690C: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046910: nop
    
            goto L_80046A5C;
    }
    // 0x80046910: nop

    // 0x80046914: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046918: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004691C: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046920: nop
    
            goto L_80046A5C;
    }
    // 0x80046920: nop

    // 0x80046924: jal         0x8002CFB8
    // 0x80046928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_77;
    // 0x80046928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_77:
    // 0x8004692C: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x80046930: nop
    
            goto L_80046A5C;
    }
    // 0x80046930: nop

    // 0x80046934: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046938: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004693C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046940: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80046944: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046948: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004694C: j           L_80046A5C
    // 0x80046950: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80046A5C;
    // 0x80046950: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80046954:
    // 0x80046954: jal         0x80008CDC
    // 0x80046958: nop

    func_80008CDC(rdram, ctx);
        goto after_78;
    // 0x80046958: nop

    after_78:
    // 0x8004695C: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046960: nop
    
            goto L_80046A5C;
    }
    // 0x80046960: nop

    // 0x80046964: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046968: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004696C: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046970: nop
    
            goto L_80046A5C;
    }
    // 0x80046970: nop

    // 0x80046974: jal         0x80044B18
    // 0x80046978: nop

    func_80044B18(rdram, ctx);
        goto after_79;
    // 0x80046978: nop

    after_79:
    // 0x8004697C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80046980: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80046984: beq         $v0, $zero, L_800469B0
    if (ctx->r2 == 0) {
        // 0x80046988: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800469B0;
    }
    // 0x80046988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004698C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046990: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80046994: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046998: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x8004699C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800469A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800469A4: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x800469A8: jal         0x800064C0
    // 0x800469AC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_80;
    // 0x800469AC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_80:
L_800469B0:
    // 0x800469B0: jal         0x8000B840
    // 0x800469B4: nop

    func_8000B840(rdram, ctx);
        goto after_81;
    // 0x800469B4: nop

    after_81:
    // 0x800469B8: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800469BC: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x800469C0: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80046A5C;
    }
    // 0x800469C0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800469C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800469C8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800469CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800469D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800469D4: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800469D8: jal         0x800064C0
    // 0x800469DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_82;
    // 0x800469DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_82:
    // 0x800469E0: j           L_80046A5C
    // 0x800469E4: nop

        goto L_80046A5C;
    // 0x800469E4: nop

L_800469E8:
    // 0x800469E8: jal         0x80008CDC
    // 0x800469EC: nop

    func_80008CDC(rdram, ctx);
        goto after_83;
    // 0x800469EC: nop

    after_83:
    // 0x800469F0: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x800469F4: nop
    
            goto L_80046A5C;
    }
    // 0x800469F4: nop

    // 0x800469F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800469FC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046A00: bne         $v0, $zero, L_80046A5C
    if (ctx->r2 != 0) {
        // 0x80046A04: nop
    
            goto L_80046A5C;
    }
    // 0x80046A04: nop

    // 0x80046A08: jal         0x8002CFB8
    // 0x80046A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_84;
    // 0x80046A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_84:
    // 0x80046A10: beq         $v0, $zero, L_80046A5C
    if (ctx->r2 == 0) {
        // 0x80046A14: nop
    
            goto L_80046A5C;
    }
    // 0x80046A14: nop

    // 0x80046A18: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046A1C: jal         0x800535B0
    // 0x80046A20: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_85;
    // 0x80046A20: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_85:
    // 0x80046A24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80046A28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046A2C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80046A30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046A34: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80046A38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046A3C: jal         0x80031BEC
    // 0x80046A40: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_86;
    // 0x80046A40: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    after_86:
    // 0x80046A44: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046A48: jal         0x80016AB4
    // 0x80046A4C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_87;
    // 0x80046A4C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_87:
    // 0x80046A50: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046A54: jal         0x80016AB4
    // 0x80046A58: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_88;
    // 0x80046A58: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_88:
L_80046A5C:
    // 0x80046A5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046A60: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80046A64: bne         $v0, $zero, L_80046AA0
    if (ctx->r2 != 0) {
        // 0x80046A68: nop
    
            goto L_80046AA0;
    }
    // 0x80046A68: nop

    // 0x80046A6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046A70: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046A74: bne         $v0, $zero, L_80046AA0
    if (ctx->r2 != 0) {
        // 0x80046A78: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80046AA0;
    }
    // 0x80046A78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80046A7C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046A80: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80046A84: beq         $v1, $v0, L_80046AA0
    if (ctx->r3 == ctx->r2) {
        // 0x80046A88: nop
    
            goto L_80046AA0;
    }
    // 0x80046A88: nop

    // 0x80046A8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046A90: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80046A94: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046A98: jal         0x8004114C
    // 0x80046A9C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_89;
    // 0x80046A9C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_89:
L_80046AA0:
    // 0x80046AA0: jal         0x800448B0
    // 0x80046AA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_90;
    // 0x80046AA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_90:
    // 0x80046AA8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80046AAC: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x80046AB0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80046AB4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046AB8: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046ABC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046AC0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80046AC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80046AC8: lw          $a0, -0x47C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X47C8);
    // 0x80046ACC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80046AD0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80046AD4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80046AD8: bne         $v0, $zero, L_80046B00
    if (ctx->r2 != 0) {
        // 0x80046ADC: nop
    
            goto L_80046B00;
    }
    // 0x80046ADC: nop

    // 0x80046AE0: jal         0x80017D38
    // 0x80046AE4: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_91;
    // 0x80046AE4: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_91:
    // 0x80046AE8: jal         0x80017D38
    // 0x80046AEC: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_92;
    // 0x80046AEC: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_92:
    // 0x80046AF0: jal         0x80051D6C
    // 0x80046AF4: nop

    func_80051D6C(rdram, ctx);
        goto after_93;
    // 0x80046AF4: nop

    after_93:
    // 0x80046AF8: j           L_80046B18
    // 0x80046AFC: nop

        goto L_80046B18;
    // 0x80046AFC: nop

L_80046B00:
    // 0x80046B00: jal         0x80017D38
    // 0x80046B04: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_94;
    // 0x80046B04: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_94:
    // 0x80046B08: jal         0x80051D6C
    // 0x80046B0C: nop

    func_80051D6C(rdram, ctx);
        goto after_95;
    // 0x80046B0C: nop

    after_95:
    // 0x80046B10: jal         0x80017D38
    // 0x80046B14: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_96;
    // 0x80046B14: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_96:
L_80046B18:
    // 0x80046B18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046B1C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046B20: bne         $v0, $zero, L_80046B40
    if (ctx->r2 != 0) {
        // 0x80046B24: nop
    
            goto L_80046B40;
    }
    // 0x80046B24: nop

    // 0x80046B28: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80046B2C: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x80046B30: beq         $v0, $zero, L_80046B40
    if (ctx->r2 == 0) {
        // 0x80046B34: nop
    
            goto L_80046B40;
    }
    // 0x80046B34: nop

    // 0x80046B38: jal         0x800533F0
    // 0x80046B3C: nop

    func_800533F0(rdram, ctx);
        goto after_97;
    // 0x80046B3C: nop

    after_97:
L_80046B40:
    // 0x80046B40: jal         0x80044D6C
    // 0x80046B44: nop

    func_80044D6C(rdram, ctx);
        goto after_98;
    // 0x80046B44: nop

    after_98:
    // 0x80046B48: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80046B4C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80046B50: jr          $ra
    // 0x80046B54: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80046B54: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80046B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046B58: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046B5C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80046B60: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80046B64: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80046B68: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x80046B6C: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046B70: sw          $s0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r16;
            goto L_80047280;
    }
    // 0x80046B70: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80046B74: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80046B78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80046B7C: addu        $at, $at, $v0
    gpr jr_addend_80046B84 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80046B80: lw          $v0, -0x22F0($at)
    ctx->r2 = ADD32(ctx->r1, -0X22F0);
    // 0x80046B84: jr          $v0
    // 0x80046B88: nop

    switch (jr_addend_80046B84 >> 2) {
        case 0: goto L_80046B8C; break;
        case 1: goto L_80046EA4; break;
        case 2: goto L_80047160; break;
        case 3: goto L_80046D3C; break;
        case 4: goto L_80046DD0; break;
        case 5: goto L_80047160; break;
        case 6: goto L_80046E08; break;
        case 7: goto L_80046EA4; break;
        case 8: goto L_80046EF4; break;
        case 9: goto L_80046FA4; break;
        case 10: goto L_800470F0; break;
        case 11: goto L_80047160; break;
        case 12: goto L_800471F4; break;
        default: switch_error(__func__, 0x80046B84, 0x800ADD10);
    }
    // 0x80046B88: nop

L_80046B8C:
    // 0x80046B8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046B90: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80046B94: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80046B98: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046B9C: lb          $a1, 0x25A0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X25A0);
    // 0x80046BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046BA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046BA8: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80046BAC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80046BB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046BB4: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80046BB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046BBC: beq         $a1, $zero, L_80046BD4
    if (ctx->r5 == 0) {
        // 0x80046BC0: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_80046BD4;
    }
    // 0x80046BC0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80046BC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046BC8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80046BCC: j           L_80046BE0
    // 0x80046BD0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80046BE0;
    // 0x80046BD0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_80046BD4:
    // 0x80046BD4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046BD8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80046BDC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80046BE0:
    // 0x80046BE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046BE4: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80046BE8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046BEC: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046BF0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80046BF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80046BF8: lbu         $v0, -0x46A0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X46A0);
    // 0x80046BFC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80046C00: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x80046C04: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80046C08: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80046C0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046C10: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80046C14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80046C18: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80046C1C: lw          $a0, -0x4BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BE8);
    // 0x80046C20: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80046C24: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80046C28: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80046C2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046C30: jal         0x80043F0C
    // 0x80046C34: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80046C34: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x80046C38: jal         0x80053390
    // 0x80046C3C: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80046C3C: nop

    after_1:
    // 0x80046C40: jal         0x800449C0
    // 0x80046C44: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80046C44: nop

    after_2:
    // 0x80046C48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046C4C: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80046C50: jal         0x80017760
    // 0x80046C54: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80046C54: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x80046C58: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80046C5C: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80046C60: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80046C64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046C68: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80046C6C: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80046C70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80046C74: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x80046C78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046C7C: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80046C80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046C84: jal         0x80066D30
    // 0x80046C88: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x80046C88: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x80046C8C: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80046C90: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80046C94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80046C98: jal         0x80006D98
    // 0x80046C9C: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x80046C9C: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x80046CA0: jal         0x800440FC
    // 0x80046CA4: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x80046CA4: nop

    after_6:
    // 0x80046CA8: jal         0x80031BEC
    // 0x80046CAC: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x80046CAC: nop

    after_7:
    // 0x80046CB0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80046CB4: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80046CB8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046CBC: jal         0x80040558
    // 0x80046CC0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x80046CC0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x80046CC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046CC8: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80046CCC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80046CD0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80046CD4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80046CD8: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80046CDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046CE0: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80046CE4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046CE8: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x80046CEC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80046CF0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80046CF4: beq         $v0, $zero, L_80046D1C
    if (ctx->r2 == 0) {
        // 0x80046CF8: nop
    
            goto L_80046D1C;
    }
    // 0x80046CF8: nop

    // 0x80046CFC: jal         0x80006944
    // 0x80046D00: nop

    func_80006944(rdram, ctx);
        goto after_9;
    // 0x80046D00: nop

    after_9:
    // 0x80046D04: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80046D08: jal         0x800067C8
    // 0x80046D0C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_10;
    // 0x80046D0C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_10:
    // 0x80046D10: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80046D14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046D18: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80046D1C:
    // 0x80046D1C: jal         0x8002CFB8
    // 0x80046D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80046D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80046D24: jal         0x8002D378
    // 0x80046D28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_12;
    // 0x80046D28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80046D2C: jal         0x8002D0D4
    // 0x80046D30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_13;
    // 0x80046D30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80046D34: j           L_80047280
    // 0x80046D38: nop

        goto L_80047280;
    // 0x80046D38: nop

L_80046D3C:
    // 0x80046D3C: jal         0x80008CDC
    // 0x80046D40: nop

    func_80008CDC(rdram, ctx);
        goto after_14;
    // 0x80046D40: nop

    after_14:
    // 0x80046D44: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046D48: nop
    
            goto L_80047280;
    }
    // 0x80046D48: nop

    // 0x80046D4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046D50: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046D54: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046D58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047280;
    }
    // 0x80046D58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046D5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046D60: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046D64: beq         $v1, $v0, L_80046D7C
    if (ctx->r3 == ctx->r2) {
        // 0x80046D68: nop
    
            goto L_80046D7C;
    }
    // 0x80046D68: nop

    // 0x80046D6C: jal         0x8002CFB8
    // 0x80046D70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_15;
    // 0x80046D70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x80046D74: j           L_80046D84
    // 0x80046D78: nop

        goto L_80046D84;
    // 0x80046D78: nop

L_80046D7C:
    // 0x80046D7C: jal         0x8002D0D4
    // 0x80046D80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_16;
    // 0x80046D80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
L_80046D84:
    // 0x80046D84: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046D88: nop
    
            goto L_80047280;
    }
    // 0x80046D88: nop

    // 0x80046D8C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046D90: jal         0x800535B0
    // 0x80046D94: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_17;
    // 0x80046D94: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_17:
    // 0x80046D98: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80046D9C: addiu       $a2, $a2, 0x7B71
    ctx->r6 = ADD32(ctx->r6, 0X7B71);
    // 0x80046DA0: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80046DA4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80046DA8: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80046DAC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80046DB0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046DB4: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046DB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80046DBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046DC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046DC4: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80046DC8: j           L_80047040
    // 0x80046DCC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80047040;
    // 0x80046DCC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80046DD0:
    // 0x80046DD0: jal         0x80008CDC
    // 0x80046DD4: nop

    func_80008CDC(rdram, ctx);
        goto after_18;
    // 0x80046DD4: nop

    after_18:
    // 0x80046DD8: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046DDC: nop
    
            goto L_80047280;
    }
    // 0x80046DDC: nop

    // 0x80046DE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046DE4: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046DE8: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046DEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047280;
    }
    // 0x80046DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046DF0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046DF4: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046DF8: beq         $v1, $v0, L_80047130
    if (ctx->r3 == ctx->r2) {
        // 0x80046DFC: nop
    
            goto L_80047130;
    }
    // 0x80046DFC: nop

    // 0x80046E00: j           L_80047120
    // 0x80046E04: nop

        goto L_80047120;
    // 0x80046E04: nop

L_80046E08:
    // 0x80046E08: jal         0x80008CDC
    // 0x80046E0C: nop

    func_80008CDC(rdram, ctx);
        goto after_19;
    // 0x80046E0C: nop

    after_19:
    // 0x80046E10: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046E14: nop
    
            goto L_80047280;
    }
    // 0x80046E14: nop

    // 0x80046E18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046E1C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046E20: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046E24: nop
    
            goto L_80047280;
    }
    // 0x80046E24: nop

    // 0x80046E28: jal         0x8002CFB8
    // 0x80046E2C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_20;
    // 0x80046E2C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // 0x80046E30: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046E34: nop
    
            goto L_80047280;
    }
    // 0x80046E34: nop

    // 0x80046E38: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046E3C: jal         0x800535B0
    // 0x80046E40: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_21;
    // 0x80046E40: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_21:
    // 0x80046E44: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046E48: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x80046E4C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80046E50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80046E54: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80046E58: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80046E5C: beq         $v0, $zero, L_80046E88
    if (ctx->r2 == 0) {
        // 0x80046E60: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80046E88;
    }
    // 0x80046E60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80046E64: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046E68: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80046E6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046E70: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80046E74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046E78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046E7C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80046E80: j           L_80047040
    // 0x80046E84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80047040;
    // 0x80046E84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80046E88:
    // 0x80046E88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046E8C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80046E90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046E94: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80046E98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046E9C: j           L_80047260
    // 0x80046EA0: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
        goto L_80047260;
    // 0x80046EA0: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
L_80046EA4:
    // 0x80046EA4: jal         0x80008CDC
    // 0x80046EA8: nop

    func_80008CDC(rdram, ctx);
        goto after_22;
    // 0x80046EA8: nop

    after_22:
    // 0x80046EAC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046EB0: nop
    
            goto L_80047280;
    }
    // 0x80046EB0: nop

    // 0x80046EB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046EB8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046EBC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046EC0: nop
    
            goto L_80047280;
    }
    // 0x80046EC0: nop

    // 0x80046EC4: jal         0x8002CFB8
    // 0x80046EC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_23;
    // 0x80046EC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_23:
    // 0x80046ECC: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046ED0: nop
    
            goto L_80047280;
    }
    // 0x80046ED0: nop

    // 0x80046ED4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046ED8: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80046EDC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046EE0: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80046EE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046EE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046EEC: j           L_80047280
    // 0x80046EF0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80047280;
    // 0x80046EF0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80046EF4:
    // 0x80046EF4: jal         0x80008CDC
    // 0x80046EF8: nop

    func_80008CDC(rdram, ctx);
        goto after_24;
    // 0x80046EF8: nop

    after_24:
    // 0x80046EFC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046F00: nop
    
            goto L_80047280;
    }
    // 0x80046F00: nop

    // 0x80046F04: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046F08: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046F0C: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046F10: nop
    
            goto L_80047280;
    }
    // 0x80046F10: nop

    // 0x80046F14: jal         0x80044B18
    // 0x80046F18: nop

    func_80044B18(rdram, ctx);
        goto after_25;
    // 0x80046F18: nop

    after_25:
    // 0x80046F1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80046F20: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80046F24: beq         $v0, $zero, L_80046F50
    if (ctx->r2 == 0) {
        // 0x80046F28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80046F50;
    }
    // 0x80046F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046F2C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046F30: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80046F34: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046F38: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80046F3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80046F40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046F44: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x80046F48: jal         0x800064C0
    // 0x80046F4C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_26;
    // 0x80046F4C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_26:
L_80046F50:
    // 0x80046F50: jal         0x8000B840
    // 0x80046F54: nop

    func_8000B840(rdram, ctx);
        goto after_27;
    // 0x80046F54: nop

    after_27:
    // 0x80046F58: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80046F5C: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046F60: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80047280;
    }
    // 0x80046F60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80046F64: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046F68: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046F6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80046F70: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80046F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046F78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80046F7C: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80046F80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046F84: bne         $v1, $v0, L_80046F94
    if (ctx->r3 != ctx->r2) {
        // 0x80046F88: nop
    
            goto L_80046F94;
    }
    // 0x80046F88: nop

    // 0x80046F8C: jal         0x80006708
    // 0x80046F90: nop

    func_80006708(rdram, ctx);
        goto after_28;
    // 0x80046F90: nop

    after_28:
L_80046F94:
    // 0x80046F94: jal         0x800064C0
    // 0x80046F98: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_29;
    // 0x80046F98: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_29:
    // 0x80046F9C: j           L_80047280
    // 0x80046FA0: nop

        goto L_80047280;
    // 0x80046FA0: nop

L_80046FA4:
    // 0x80046FA4: jal         0x80008CDC
    // 0x80046FA8: nop

    func_80008CDC(rdram, ctx);
        goto after_30;
    // 0x80046FA8: nop

    after_30:
    // 0x80046FAC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046FB0: nop
    
            goto L_80047280;
    }
    // 0x80046FB0: nop

    // 0x80046FB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80046FB8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80046FBC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80046FC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047280;
    }
    // 0x80046FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80046FC4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80046FC8: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80046FCC: beq         $v1, $v0, L_80046FE4
    if (ctx->r3 == ctx->r2) {
        // 0x80046FD0: nop
    
            goto L_80046FE4;
    }
    // 0x80046FD0: nop

    // 0x80046FD4: jal         0x8002CFB8
    // 0x80046FD8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_31;
    // 0x80046FD8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_31:
    // 0x80046FDC: j           L_80046FEC
    // 0x80046FE0: nop

        goto L_80046FEC;
    // 0x80046FE0: nop

L_80046FE4:
    // 0x80046FE4: jal         0x8002D0D4
    // 0x80046FE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_32;
    // 0x80046FE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_32:
L_80046FEC:
    // 0x80046FEC: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80046FF0: nop
    
            goto L_80047280;
    }
    // 0x80046FF0: nop

    // 0x80046FF4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80046FF8: jal         0x800535B0
    // 0x80046FFC: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_33;
    // 0x80046FFC: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_33:
    // 0x80047000: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047004: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x80047008: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004700C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80047010: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80047014: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80047018: beq         $v0, $zero, L_800470D4
    if (ctx->r2 == 0) {
        // 0x8004701C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800470D4;
    }
    // 0x8004701C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80047020: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047024: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80047028: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8004702C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047030: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047034: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047038: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004703C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80047040:
    // 0x80047040: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047044: jal         0x80043F0C
    // 0x80047048: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_34;
    // 0x80047048: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_34:
    // 0x8004704C: jal         0x800449C0
    // 0x80047050: nop

    func_800449C0(rdram, ctx);
        goto after_35;
    // 0x80047050: nop

    after_35:
    // 0x80047054: jal         0x800440FC
    // 0x80047058: nop

    func_800440FC(rdram, ctx);
        goto after_36;
    // 0x80047058: nop

    after_36:
    // 0x8004705C: jal         0x80031BEC
    // 0x80047060: nop

    func_80031BEC(rdram, ctx);
        goto after_37;
    // 0x80047060: nop

    after_37:
    // 0x80047064: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047068: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004706C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047070: jal         0x80040558
    // 0x80047074: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_38;
    // 0x80047074: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_38:
    // 0x80047078: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004707C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80047080: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047084: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80047088: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004708C: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80047090: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047094: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80047098: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004709C: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800470A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800470A4: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x800470A8: beq         $v1, $v0, L_80047280
    if (ctx->r3 == ctx->r2) {
        // 0x800470AC: nop
    
            goto L_80047280;
    }
    // 0x800470AC: nop

    // 0x800470B0: jal         0x80006944
    // 0x800470B4: nop

    func_80006944(rdram, ctx);
        goto after_39;
    // 0x800470B4: nop

    after_39:
    // 0x800470B8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800470BC: jal         0x800067C8
    // 0x800470C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_40;
    // 0x800470C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_40:
    // 0x800470C4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800470C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800470CC: j           L_80047280
    // 0x800470D0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80047280;
    // 0x800470D0: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_800470D4:
    // 0x800470D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800470D8: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800470DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800470E0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800470E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800470E8: j           L_80047260
    // 0x800470EC: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
        goto L_80047260;
    // 0x800470EC: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
L_800470F0:
    // 0x800470F0: jal         0x80008CDC
    // 0x800470F4: nop

    func_80008CDC(rdram, ctx);
        goto after_41;
    // 0x800470F4: nop

    after_41:
    // 0x800470F8: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x800470FC: nop
    
            goto L_80047280;
    }
    // 0x800470FC: nop

    // 0x80047100: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047104: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047108: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x8004710C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047280;
    }
    // 0x8004710C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047110: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047114: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80047118: beq         $v1, $v0, L_80047130
    if (ctx->r3 == ctx->r2) {
        // 0x8004711C: nop
    
            goto L_80047130;
    }
    // 0x8004711C: nop

L_80047120:
    // 0x80047120: jal         0x8002CFB8
    // 0x80047124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_42;
    // 0x80047124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_42:
    // 0x80047128: j           L_80047138
    // 0x8004712C: nop

        goto L_80047138;
    // 0x8004712C: nop

L_80047130:
    // 0x80047130: jal         0x8002D0D4
    // 0x80047134: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_43;
    // 0x80047134: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_43:
L_80047138:
    // 0x80047138: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x8004713C: nop
    
            goto L_80047280;
    }
    // 0x8004713C: nop

    // 0x80047140: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047144: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80047148: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004714C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047150: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80047154: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047158: j           L_80047280
    // 0x8004715C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80047280;
    // 0x8004715C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80047160:
    // 0x80047160: jal         0x80008CDC
    // 0x80047164: nop

    func_80008CDC(rdram, ctx);
        goto after_44;
    // 0x80047164: nop

    after_44:
    // 0x80047168: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x8004716C: nop
    
            goto L_80047280;
    }
    // 0x8004716C: nop

    // 0x80047170: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047174: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047178: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x8004717C: nop
    
            goto L_80047280;
    }
    // 0x8004717C: nop

    // 0x80047180: jal         0x80044B18
    // 0x80047184: nop

    func_80044B18(rdram, ctx);
        goto after_45;
    // 0x80047184: nop

    after_45:
    // 0x80047188: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004718C: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80047190: beq         $v0, $zero, L_800471BC
    if (ctx->r2 == 0) {
        // 0x80047194: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800471BC;
    }
    // 0x80047194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047198: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004719C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800471A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800471A4: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800471A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800471AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800471B0: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x800471B4: jal         0x800064C0
    // 0x800471B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_46;
    // 0x800471B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_46:
L_800471BC:
    // 0x800471BC: jal         0x8000B840
    // 0x800471C0: nop

    func_8000B840(rdram, ctx);
        goto after_47;
    // 0x800471C0: nop

    after_47:
    // 0x800471C4: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800471C8: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x800471CC: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80047280;
    }
    // 0x800471CC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800471D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800471D4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800471D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800471DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800471E0: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800471E4: jal         0x800064C0
    // 0x800471E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_48;
    // 0x800471E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_48:
    // 0x800471EC: j           L_80047280
    // 0x800471F0: nop

        goto L_80047280;
    // 0x800471F0: nop

L_800471F4:
    // 0x800471F4: jal         0x80008CDC
    // 0x800471F8: nop

    func_80008CDC(rdram, ctx);
        goto after_49;
    // 0x800471F8: nop

    after_49:
    // 0x800471FC: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80047200: nop
    
            goto L_80047280;
    }
    // 0x80047200: nop

    // 0x80047204: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047208: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004720C: bne         $v0, $zero, L_80047280
    if (ctx->r2 != 0) {
        // 0x80047210: nop
    
            goto L_80047280;
    }
    // 0x80047210: nop

    // 0x80047214: jal         0x8002CFB8
    // 0x80047218: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_50;
    // 0x80047218: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_50:
    // 0x8004721C: beq         $v0, $zero, L_80047280
    if (ctx->r2 == 0) {
        // 0x80047220: nop
    
            goto L_80047280;
    }
    // 0x80047220: nop

    // 0x80047224: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047228: jal         0x800535B0
    // 0x8004722C: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_51;
    // 0x8004722C: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_51:
    // 0x80047230: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047234: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x80047238: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8004723C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80047240: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047244: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80047248: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004724C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80047250: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047254: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80047258: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004725C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_80047260:
    // 0x80047260: jal         0x80031BEC
    // 0x80047264: nop

    func_80031BEC(rdram, ctx);
        goto after_52;
    // 0x80047264: nop

    after_52:
    // 0x80047268: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004726C: jal         0x80016AB4
    // 0x80047270: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_53;
    // 0x80047270: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_53:
    // 0x80047274: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047278: jal         0x80016AB4
    // 0x8004727C: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_54;
    // 0x8004727C: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_54:
L_80047280:
    // 0x80047280: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047284: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80047288: bne         $v0, $zero, L_800472C4
    if (ctx->r2 != 0) {
        // 0x8004728C: nop
    
            goto L_800472C4;
    }
    // 0x8004728C: nop

    // 0x80047290: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047294: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047298: bne         $v0, $zero, L_800472C4
    if (ctx->r2 != 0) {
        // 0x8004729C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800472C4;
    }
    // 0x8004729C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800472A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800472A4: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x800472A8: beq         $v1, $v0, L_800472C4
    if (ctx->r3 == ctx->r2) {
        // 0x800472AC: nop
    
            goto L_800472C4;
    }
    // 0x800472AC: nop

    // 0x800472B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800472B4: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800472B8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800472BC: jal         0x8004114C
    // 0x800472C0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_55;
    // 0x800472C0: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_55:
L_800472C4:
    // 0x800472C4: jal         0x800448B0
    // 0x800472C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_56;
    // 0x800472C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_56:
    // 0x800472CC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800472D0: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x800472D4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800472D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800472DC: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x800472E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800472E4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800472E8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800472EC: lw          $a0, -0x47C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X47C8);
    // 0x800472F0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800472F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800472F8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800472FC: bne         $v0, $zero, L_80047324
    if (ctx->r2 != 0) {
        // 0x80047300: nop
    
            goto L_80047324;
    }
    // 0x80047300: nop

    // 0x80047304: jal         0x80017D38
    // 0x80047308: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_57;
    // 0x80047308: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_57:
    // 0x8004730C: jal         0x80017D38
    // 0x80047310: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_58;
    // 0x80047310: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_58:
    // 0x80047314: jal         0x80051D6C
    // 0x80047318: nop

    func_80051D6C(rdram, ctx);
        goto after_59;
    // 0x80047318: nop

    after_59:
    // 0x8004731C: j           L_8004733C
    // 0x80047320: nop

        goto L_8004733C;
    // 0x80047320: nop

L_80047324:
    // 0x80047324: jal         0x80017D38
    // 0x80047328: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_60;
    // 0x80047328: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_60:
    // 0x8004732C: jal         0x80051D6C
    // 0x80047330: nop

    func_80051D6C(rdram, ctx);
        goto after_61;
    // 0x80047330: nop

    after_61:
    // 0x80047334: jal         0x80017D38
    // 0x80047338: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_62;
    // 0x80047338: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_62:
L_8004733C:
    // 0x8004733C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047340: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047344: bne         $v0, $zero, L_80047364
    if (ctx->r2 != 0) {
        // 0x80047348: nop
    
            goto L_80047364;
    }
    // 0x80047348: nop

    // 0x8004734C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80047350: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x80047354: beq         $v0, $zero, L_80047364
    if (ctx->r2 == 0) {
        // 0x80047358: nop
    
            goto L_80047364;
    }
    // 0x80047358: nop

    // 0x8004735C: jal         0x800533F0
    // 0x80047360: nop

    func_800533F0(rdram, ctx);
        goto after_63;
    // 0x80047360: nop

    after_63:
L_80047364:
    // 0x80047364: jal         0x80044D6C
    // 0x80047368: nop

    func_80044D6C(rdram, ctx);
        goto after_64;
    // 0x80047368: nop

    after_64:
    // 0x8004736C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80047370: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80047374: jr          $ra
    // 0x80047378: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80047378: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004737C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004737C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047380: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80047384: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80047388: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8004738C: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80047390: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x80047394: sw          $s0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r16;
            goto L_80047900;
    }
    // 0x80047394: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80047398: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004739C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800473A0: addu        $at, $at, $v0
    gpr jr_addend_800473A8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800473A4: lw          $v0, -0x22B8($at)
    ctx->r2 = ADD32(ctx->r1, -0X22B8);
    // 0x800473A8: jr          $v0
    // 0x800473AC: nop

    switch (jr_addend_800473A8 >> 2) {
        case 0: goto L_800473B0; break;
        case 1: goto L_8004778C; break;
        case 2: goto L_80047560; break;
        case 3: goto L_800475EC; break;
        case 4: goto L_8004778C; break;
        case 5: goto L_800477DC; break;
        case 6: goto L_80047660; break;
        case 7: goto L_8004778C; break;
        case 8: goto L_800477DC; break;
        case 9: goto L_80047874; break;
        default: switch_error(__func__, 0x800473A8, 0x800ADD48);
    }
    // 0x800473AC: nop

L_800473B0:
    // 0x800473B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800473B4: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x800473B8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800473BC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800473C0: lb          $a1, 0x25A0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X25A0);
    // 0x800473C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800473C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800473CC: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800473D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800473D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800473D8: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x800473DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800473E0: beq         $a1, $zero, L_800473F8
    if (ctx->r5 == 0) {
        // 0x800473E4: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_800473F8;
    }
    // 0x800473E4: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x800473E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800473EC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800473F0: j           L_80047404
    // 0x800473F4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80047404;
    // 0x800473F4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_800473F8:
    // 0x800473F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800473FC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80047400: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80047404:
    // 0x80047404: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047408: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x8004740C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047410: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80047414: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80047418: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004741C: lbu         $v0, -0x469C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X469C);
    // 0x80047420: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80047424: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x80047428: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004742C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80047430: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047434: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80047438: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004743C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80047440: lw          $a0, -0x4BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BE8);
    // 0x80047444: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80047448: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004744C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80047450: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047454: jal         0x80043F0C
    // 0x80047458: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80047458: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x8004745C: jal         0x80053390
    // 0x80047460: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80047460: nop

    after_1:
    // 0x80047464: jal         0x800449C0
    // 0x80047468: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80047468: nop

    after_2:
    // 0x8004746C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047470: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80047474: jal         0x80017760
    // 0x80047478: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80047478: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x8004747C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80047480: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80047484: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80047488: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004748C: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80047490: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80047494: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80047498: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x8004749C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800474A0: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x800474A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800474A8: jal         0x80066D30
    // 0x800474AC: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x800474AC: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x800474B0: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x800474B4: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x800474B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800474BC: jal         0x80006D98
    // 0x800474C0: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x800474C0: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x800474C4: jal         0x800440FC
    // 0x800474C8: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x800474C8: nop

    after_6:
    // 0x800474CC: jal         0x80031BEC
    // 0x800474D0: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x800474D0: nop

    after_7:
    // 0x800474D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800474D8: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800474DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800474E0: jal         0x80040558
    // 0x800474E4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x800474E4: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x800474E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800474EC: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800474F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800474F4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800474F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800474FC: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80047500: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047504: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80047508: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004750C: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x80047510: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80047514: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80047518: beq         $v0, $zero, L_80047540
    if (ctx->r2 == 0) {
        // 0x8004751C: nop
    
            goto L_80047540;
    }
    // 0x8004751C: nop

    // 0x80047520: jal         0x80006944
    // 0x80047524: nop

    func_80006944(rdram, ctx);
        goto after_9;
    // 0x80047524: nop

    after_9:
    // 0x80047528: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x8004752C: jal         0x800067C8
    // 0x80047530: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_10;
    // 0x80047530: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_10:
    // 0x80047534: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80047538: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004753C: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80047540:
    // 0x80047540: jal         0x8002CFB8
    // 0x80047544: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80047544: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80047548: jal         0x8002D378
    // 0x8004754C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_12;
    // 0x8004754C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80047550: jal         0x8002D0D4
    // 0x80047554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_13;
    // 0x80047554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80047558: j           L_80047900
    // 0x8004755C: nop

        goto L_80047900;
    // 0x8004755C: nop

L_80047560:
    // 0x80047560: jal         0x80008CDC
    // 0x80047564: nop

    func_80008CDC(rdram, ctx);
        goto after_14;
    // 0x80047564: nop

    after_14:
    // 0x80047568: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x8004756C: nop
    
            goto L_80047900;
    }
    // 0x8004756C: nop

    // 0x80047570: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047574: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047578: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x8004757C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047900;
    }
    // 0x8004757C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047580: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047584: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80047588: bne         $v1, $v0, L_800475B0
    if (ctx->r3 != ctx->r2) {
        // 0x8004758C: nop
    
            goto L_800475B0;
    }
    // 0x8004758C: nop

    // 0x80047590: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047594: lh          $v0, 0x6AA4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA4);
    // 0x80047598: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004759C: slti        $v0, $v0, -0x33F
    ctx->r2 = SIGNED(ctx->r2) < -0X33F ? 1 : 0;
    // 0x800475A0: bne         $v0, $zero, L_800475B0
    if (ctx->r2 != 0) {
        // 0x800475A4: addiu       $v0, $v1, -0x2
        ctx->r2 = ADD32(ctx->r3, -0X2);
            goto L_800475B0;
    }
    // 0x800475A4: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
    // 0x800475A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800475AC: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
L_800475B0:
    // 0x800475B0: jal         0x80044B18
    // 0x800475B4: nop

    func_80044B18(rdram, ctx);
        goto after_15;
    // 0x800475B4: nop

    after_15:
    // 0x800475B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800475BC: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x800475C0: beq         $v0, $zero, L_8004783C
    if (ctx->r2 == 0) {
        // 0x800475C4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8004783C;
    }
    // 0x800475C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800475C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800475CC: addiu       $a1, $a1, 0x7B71
    ctx->r5 = ADD32(ctx->r5, 0X7B71);
    // 0x800475D0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800475D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800475D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800475DC: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800475E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800475E4: j           L_80047834
    // 0x800475E8: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
        goto L_80047834;
    // 0x800475E8: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
L_800475EC:
    // 0x800475EC: jal         0x80008CDC
    // 0x800475F0: nop

    func_80008CDC(rdram, ctx);
        goto after_16;
    // 0x800475F0: nop

    after_16:
    // 0x800475F4: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x800475F8: nop
    
            goto L_80047900;
    }
    // 0x800475F8: nop

    // 0x800475FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047600: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047604: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x80047608: nop
    
            goto L_80047900;
    }
    // 0x80047608: nop

    // 0x8004760C: jal         0x8002CFB8
    // 0x80047610: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_17;
    // 0x80047610: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // 0x80047614: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x80047618: nop
    
            goto L_80047900;
    }
    // 0x80047618: nop

    // 0x8004761C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047620: jal         0x800535B0
    // 0x80047624: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_18;
    // 0x80047624: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_18:
    // 0x80047628: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004762C: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80047630: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047634: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80047638: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8004763C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047640: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047644: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80047648: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004764C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047650: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047654: sb          $a0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r4;
    // 0x80047658: j           L_800476DC
    // 0x8004765C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800476DC;
    // 0x8004765C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80047660:
    // 0x80047660: jal         0x80008CDC
    // 0x80047664: nop

    func_80008CDC(rdram, ctx);
        goto after_19;
    // 0x80047664: nop

    after_19:
    // 0x80047668: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x8004766C: nop
    
            goto L_80047900;
    }
    // 0x8004766C: nop

    // 0x80047670: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047674: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047678: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x8004767C: nop
    
            goto L_80047900;
    }
    // 0x8004767C: nop

    // 0x80047680: jal         0x8002CFB8
    // 0x80047684: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_20;
    // 0x80047684: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // 0x80047688: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x8004768C: nop
    
            goto L_80047900;
    }
    // 0x8004768C: nop

    // 0x80047690: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047694: jal         0x800535B0
    // 0x80047698: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_21;
    // 0x80047698: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_21:
    // 0x8004769C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800476A0: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x800476A4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800476A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800476AC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800476B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800476B4: beq         $v0, $zero, L_80047770
    if (ctx->r2 == 0) {
        // 0x800476B8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80047770;
    }
    // 0x800476B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800476BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800476C0: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800476C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800476C8: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x800476CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800476D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800476D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800476D8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_800476DC:
    // 0x800476DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800476E0: jal         0x80043F0C
    // 0x800476E4: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_22;
    // 0x800476E4: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_22:
    // 0x800476E8: jal         0x800449C0
    // 0x800476EC: nop

    func_800449C0(rdram, ctx);
        goto after_23;
    // 0x800476EC: nop

    after_23:
    // 0x800476F0: jal         0x800440FC
    // 0x800476F4: nop

    func_800440FC(rdram, ctx);
        goto after_24;
    // 0x800476F4: nop

    after_24:
    // 0x800476F8: jal         0x80031BEC
    // 0x800476FC: nop

    func_80031BEC(rdram, ctx);
        goto after_25;
    // 0x800476FC: nop

    after_25:
    // 0x80047700: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047704: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80047708: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004770C: jal         0x80040558
    // 0x80047710: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_26;
    // 0x80047710: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_26:
    // 0x80047714: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047718: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x8004771C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047720: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80047724: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047728: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x8004772C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047730: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80047734: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80047738: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8004773C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80047740: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x80047744: beq         $v1, $v0, L_80047900
    if (ctx->r3 == ctx->r2) {
        // 0x80047748: nop
    
            goto L_80047900;
    }
    // 0x80047748: nop

    // 0x8004774C: jal         0x80006944
    // 0x80047750: nop

    func_80006944(rdram, ctx);
        goto after_27;
    // 0x80047750: nop

    after_27:
    // 0x80047754: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80047758: jal         0x800067C8
    // 0x8004775C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_28;
    // 0x8004775C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_28:
    // 0x80047760: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80047764: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047768: j           L_80047900
    // 0x8004776C: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80047900;
    // 0x8004776C: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80047770:
    // 0x80047770: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047774: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80047778: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004777C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80047780: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047784: j           L_800478E0
    // 0x80047788: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
        goto L_800478E0;
    // 0x80047788: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
L_8004778C:
    // 0x8004778C: jal         0x80008CDC
    // 0x80047790: nop

    func_80008CDC(rdram, ctx);
        goto after_29;
    // 0x80047790: nop

    after_29:
    // 0x80047794: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x80047798: nop
    
            goto L_80047900;
    }
    // 0x80047798: nop

    // 0x8004779C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800477A0: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800477A4: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x800477A8: nop
    
            goto L_80047900;
    }
    // 0x800477A8: nop

    // 0x800477AC: jal         0x8002CFB8
    // 0x800477B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_30;
    // 0x800477B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
    // 0x800477B4: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x800477B8: nop
    
            goto L_80047900;
    }
    // 0x800477B8: nop

    // 0x800477BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800477C0: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800477C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800477C8: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x800477CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800477D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800477D4: j           L_80047900
    // 0x800477D8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80047900;
    // 0x800477D8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_800477DC:
    // 0x800477DC: jal         0x80008CDC
    // 0x800477E0: nop

    func_80008CDC(rdram, ctx);
        goto after_31;
    // 0x800477E0: nop

    after_31:
    // 0x800477E4: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x800477E8: nop
    
            goto L_80047900;
    }
    // 0x800477E8: nop

    // 0x800477EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800477F0: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800477F4: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x800477F8: nop
    
            goto L_80047900;
    }
    // 0x800477F8: nop

    // 0x800477FC: jal         0x80044B18
    // 0x80047800: nop

    func_80044B18(rdram, ctx);
        goto after_32;
    // 0x80047800: nop

    after_32:
    // 0x80047804: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80047808: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x8004780C: beq         $v0, $zero, L_8004783C
    if (ctx->r2 == 0) {
        // 0x80047810: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8004783C;
    }
    // 0x80047810: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80047814: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047818: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8004781C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047820: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047824: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80047828: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004782C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047830: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
L_80047834:
    // 0x80047834: jal         0x800064C0
    // 0x80047838: nop

    func_800064C0(rdram, ctx);
        goto after_33;
    // 0x80047838: nop

    after_33:
L_8004783C:
    // 0x8004783C: jal         0x8000B840
    // 0x80047840: nop

    func_8000B840(rdram, ctx);
        goto after_34;
    // 0x80047840: nop

    after_34:
    // 0x80047844: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80047848: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x8004784C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80047900;
    }
    // 0x8004784C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80047850: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047854: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80047858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004785C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047860: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80047864: jal         0x800064C0
    // 0x80047868: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_35;
    // 0x80047868: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_35:
    // 0x8004786C: j           L_80047900
    // 0x80047870: nop

        goto L_80047900;
    // 0x80047870: nop

L_80047874:
    // 0x80047874: jal         0x80008CDC
    // 0x80047878: nop

    func_80008CDC(rdram, ctx);
        goto after_36;
    // 0x80047878: nop

    after_36:
    // 0x8004787C: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x80047880: nop
    
            goto L_80047900;
    }
    // 0x80047880: nop

    // 0x80047884: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047888: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004788C: bne         $v0, $zero, L_80047900
    if (ctx->r2 != 0) {
        // 0x80047890: nop
    
            goto L_80047900;
    }
    // 0x80047890: nop

    // 0x80047894: jal         0x8002CFB8
    // 0x80047898: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_37;
    // 0x80047898: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_37:
    // 0x8004789C: beq         $v0, $zero, L_80047900
    if (ctx->r2 == 0) {
        // 0x800478A0: nop
    
            goto L_80047900;
    }
    // 0x800478A0: nop

    // 0x800478A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800478A8: jal         0x800535B0
    // 0x800478AC: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_38;
    // 0x800478AC: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_38:
    // 0x800478B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800478B4: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x800478B8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800478BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800478C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800478C4: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800478C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800478CC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800478D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800478D4: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x800478D8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800478DC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_800478E0:
    // 0x800478E0: jal         0x80031BEC
    // 0x800478E4: nop

    func_80031BEC(rdram, ctx);
        goto after_39;
    // 0x800478E4: nop

    after_39:
    // 0x800478E8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800478EC: jal         0x80016AB4
    // 0x800478F0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_40;
    // 0x800478F0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_40:
    // 0x800478F4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800478F8: jal         0x80016AB4
    // 0x800478FC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_41;
    // 0x800478FC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_41:
L_80047900:
    // 0x80047900: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047904: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80047908: bne         $v0, $zero, L_80047944
    if (ctx->r2 != 0) {
        // 0x8004790C: nop
    
            goto L_80047944;
    }
    // 0x8004790C: nop

    // 0x80047910: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047914: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047918: bne         $v0, $zero, L_80047944
    if (ctx->r2 != 0) {
        // 0x8004791C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80047944;
    }
    // 0x8004791C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80047920: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047924: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80047928: beq         $v1, $v0, L_80047944
    if (ctx->r3 == ctx->r2) {
        // 0x8004792C: nop
    
            goto L_80047944;
    }
    // 0x8004792C: nop

    // 0x80047930: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047934: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80047938: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004793C: jal         0x8004114C
    // 0x80047940: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_42;
    // 0x80047940: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_42:
L_80047944:
    // 0x80047944: jal         0x800448B0
    // 0x80047948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_43;
    // 0x80047948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_43:
    // 0x8004794C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80047950: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x80047954: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80047958: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004795C: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047960: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047964: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80047968: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004796C: lw          $a0, -0x47C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X47C8);
    // 0x80047970: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80047974: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80047978: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8004797C: bne         $v0, $zero, L_800479A4
    if (ctx->r2 != 0) {
        // 0x80047980: nop
    
            goto L_800479A4;
    }
    // 0x80047980: nop

    // 0x80047984: jal         0x80017D38
    // 0x80047988: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_44;
    // 0x80047988: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_44:
    // 0x8004798C: jal         0x80017D38
    // 0x80047990: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_45;
    // 0x80047990: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_45:
    // 0x80047994: jal         0x80051D6C
    // 0x80047998: nop

    func_80051D6C(rdram, ctx);
        goto after_46;
    // 0x80047998: nop

    after_46:
    // 0x8004799C: j           L_800479BC
    // 0x800479A0: nop

        goto L_800479BC;
    // 0x800479A0: nop

L_800479A4:
    // 0x800479A4: jal         0x80017D38
    // 0x800479A8: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_47;
    // 0x800479A8: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_47:
    // 0x800479AC: jal         0x80051D6C
    // 0x800479B0: nop

    func_80051D6C(rdram, ctx);
        goto after_48;
    // 0x800479B0: nop

    after_48:
    // 0x800479B4: jal         0x80017D38
    // 0x800479B8: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_49;
    // 0x800479B8: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_49:
L_800479BC:
    // 0x800479BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800479C0: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800479C4: bne         $v0, $zero, L_800479E4
    if (ctx->r2 != 0) {
        // 0x800479C8: nop
    
            goto L_800479E4;
    }
    // 0x800479C8: nop

    // 0x800479CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800479D0: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x800479D4: beq         $v0, $zero, L_800479E4
    if (ctx->r2 == 0) {
        // 0x800479D8: nop
    
            goto L_800479E4;
    }
    // 0x800479D8: nop

    // 0x800479DC: jal         0x800533F0
    // 0x800479E0: nop

    func_800533F0(rdram, ctx);
        goto after_50;
    // 0x800479E0: nop

    after_50:
L_800479E4:
    // 0x800479E4: jal         0x80044D6C
    // 0x800479E8: nop

    func_80044D6C(rdram, ctx);
        goto after_51;
    // 0x800479E8: nop

    after_51:
    // 0x800479EC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800479F0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800479F4: jr          $ra
    // 0x800479F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800479F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800479FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800479FC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047A00: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80047A04: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80047A08: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80047A0C: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x80047A10: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047A14: sw          $s0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r16;
            goto L_800480F4;
    }
    // 0x80047A14: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80047A18: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80047A1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80047A20: addu        $at, $at, $v0
    gpr jr_addend_80047A28 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80047A24: lw          $v0, -0x2290($at)
    ctx->r2 = ADD32(ctx->r1, -0X2290);
    // 0x80047A28: jr          $v0
    // 0x80047A2C: nop

    switch (jr_addend_80047A28 >> 2) {
        case 0: goto L_80047A30; break;
        case 1: goto L_80047F7C; break;
        case 2: goto L_80047FD4; break;
        case 3: goto L_80047BF0; break;
        case 4: goto L_80047F7C; break;
        case 5: goto L_80047DC8; break;
        case 6: goto L_80047C98; break;
        case 7: goto L_80047D54; break;
        case 8: goto L_80047DC8; break;
        case 9: goto L_80047E70; break;
        case 10: goto L_80047F7C; break;
        case 11: goto L_80047FD4; break;
        case 12: goto L_80048068; break;
        default: switch_error(__func__, 0x80047A28, 0x800ADD70);
    }
    // 0x80047A2C: nop

L_80047A30:
    // 0x80047A30: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047A34: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80047A38: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80047A3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047A40: lb          $a1, 0x25A0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X25A0);
    // 0x80047A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047A48: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047A4C: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80047A50: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80047A54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047A58: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80047A5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047A60: beq         $a1, $zero, L_80047A78
    if (ctx->r5 == 0) {
        // 0x80047A64: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_80047A78;
    }
    // 0x80047A64: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80047A68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047A6C: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80047A70: j           L_80047A84
    // 0x80047A74: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_80047A84;
    // 0x80047A74: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_80047A78:
    // 0x80047A78: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047A7C: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80047A80: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80047A84:
    // 0x80047A84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047A88: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80047A8C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047A90: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80047A94: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80047A98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047A9C: lbu         $v0, -0x4698($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4698);
    // 0x80047AA0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80047AA4: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x80047AA8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80047AAC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80047AB0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047AB4: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80047AB8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047ABC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80047AC0: lw          $v1, -0x4BE8($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4BE8);
    // 0x80047AC4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80047AC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80047ACC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80047AD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047AD4: jal         0x80043F0C
    // 0x80047AD8: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80047AD8: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x80047ADC: jal         0x80053390
    // 0x80047AE0: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80047AE0: nop

    after_1:
    // 0x80047AE4: jal         0x800449C0
    // 0x80047AE8: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80047AE8: nop

    after_2:
    // 0x80047AEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047AF0: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80047AF4: jal         0x80017760
    // 0x80047AF8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80047AF8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x80047AFC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80047B00: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80047B04: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80047B08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047B0C: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80047B10: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80047B14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80047B18: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x80047B1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047B20: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80047B24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047B28: jal         0x80066D30
    // 0x80047B2C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x80047B2C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x80047B30: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80047B34: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80047B38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80047B3C: jal         0x80006D98
    // 0x80047B40: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x80047B40: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x80047B44: jal         0x800440FC
    // 0x80047B48: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x80047B48: nop

    after_6:
    // 0x80047B4C: jal         0x80031BEC
    // 0x80047B50: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x80047B50: nop

    after_7:
    // 0x80047B54: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047B58: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80047B5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047B60: jal         0x80040558
    // 0x80047B64: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x80047B64: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x80047B68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047B6C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80047B70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047B74: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80047B78: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047B7C: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80047B80: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047B84: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80047B88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047B8C: sb          $zero, 0x4A1F($at)
    MEM_B(0X4A1F, ctx->r1) = 0;
    // 0x80047B90: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047B94: sb          $zero, 0x4A20($at)
    MEM_B(0X4A20, ctx->r1) = 0;
    // 0x80047B98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047B9C: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x80047BA0: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80047BA4: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80047BA8: beq         $v0, $zero, L_80047BD0
    if (ctx->r2 == 0) {
        // 0x80047BAC: nop
    
            goto L_80047BD0;
    }
    // 0x80047BAC: nop

    // 0x80047BB0: jal         0x80006944
    // 0x80047BB4: nop

    func_80006944(rdram, ctx);
        goto after_9;
    // 0x80047BB4: nop

    after_9:
    // 0x80047BB8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80047BBC: jal         0x800067C8
    // 0x80047BC0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_10;
    // 0x80047BC0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_10:
    // 0x80047BC4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80047BC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047BCC: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80047BD0:
    // 0x80047BD0: jal         0x8002CFB8
    // 0x80047BD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80047BD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80047BD8: jal         0x8002D378
    // 0x80047BDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_12;
    // 0x80047BDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80047BE0: jal         0x8002D0D4
    // 0x80047BE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_13;
    // 0x80047BE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80047BE8: j           L_800480F4
    // 0x80047BEC: nop

        goto L_800480F4;
    // 0x80047BEC: nop

L_80047BF0:
    // 0x80047BF0: jal         0x80008CDC
    // 0x80047BF4: nop

    func_80008CDC(rdram, ctx);
        goto after_14;
    // 0x80047BF4: nop

    after_14:
    // 0x80047BF8: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047BFC: nop
    
            goto L_800480F4;
    }
    // 0x80047BFC: nop

    // 0x80047C00: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047C04: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047C08: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047C0C: nop
    
            goto L_800480F4;
    }
    // 0x80047C0C: nop

    // 0x80047C10: jal         0x8002CFB8
    // 0x80047C14: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_15;
    // 0x80047C14: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x80047C18: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047C1C: nop
    
            goto L_800480F4;
    }
    // 0x80047C1C: nop

    // 0x80047C20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047C24: jal         0x800535B0
    // 0x80047C28: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_16;
    // 0x80047C28: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_16:
    // 0x80047C2C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047C30: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80047C34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047C38: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80047C3C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80047C40: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047C44: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047C48: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80047C4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80047C50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047C54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047C58: sb          $a0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r4;
    // 0x80047C5C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80047C60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047C64: jal         0x80043F0C
    // 0x80047C68: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_17;
    // 0x80047C68: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_17:
    // 0x80047C6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047C70: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80047C74: bne         $v0, $zero, L_80047EEC
    if (ctx->r2 != 0) {
        // 0x80047C78: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80047EEC;
    }
    // 0x80047C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80047C7C: jal         0x80044378
    // 0x80047C80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80044378(rdram, ctx);
        goto after_18;
    // 0x80047C80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // 0x80047C84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80047C88: jal         0x80044378
    // 0x80047C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80044378(rdram, ctx);
        goto after_19;
    // 0x80047C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80047C90: j           L_80047EEC
    // 0x80047C94: nop

        goto L_80047EEC;
    // 0x80047C94: nop

L_80047C98:
    // 0x80047C98: jal         0x80008CDC
    // 0x80047C9C: nop

    func_80008CDC(rdram, ctx);
        goto after_20;
    // 0x80047C9C: nop

    after_20:
    // 0x80047CA0: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047CA4: nop
    
            goto L_800480F4;
    }
    // 0x80047CA4: nop

    // 0x80047CA8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047CAC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047CB0: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047CB4: nop
    
            goto L_800480F4;
    }
    // 0x80047CB4: nop

    // 0x80047CB8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047CBC: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80047CC0: beq         $v0, $zero, L_80047CD8
    if (ctx->r2 == 0) {
        // 0x80047CC4: nop
    
            goto L_80047CD8;
    }
    // 0x80047CC4: nop

    // 0x80047CC8: jal         0x8002CFB8
    // 0x80047CCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_21;
    // 0x80047CCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // 0x80047CD0: j           L_80047CE0
    // 0x80047CD4: nop

        goto L_80047CE0;
    // 0x80047CD4: nop

L_80047CD8:
    // 0x80047CD8: jal         0x8002D0D4
    // 0x80047CDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_22;
    // 0x80047CDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
L_80047CE0:
    // 0x80047CE0: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047CE4: nop
    
            goto L_800480F4;
    }
    // 0x80047CE4: nop

    // 0x80047CE8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047CEC: jal         0x800535B0
    // 0x80047CF0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_23;
    // 0x80047CF0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_23:
    // 0x80047CF4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047CF8: addiu       $v1, $v1, 0x6ACC
    ctx->r3 = ADD32(ctx->r3, 0X6ACC);
    // 0x80047CFC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80047D00: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80047D04: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80047D08: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80047D0C: beq         $v0, $zero, L_80047D38
    if (ctx->r2 == 0) {
        // 0x80047D10: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80047D38;
    }
    // 0x80047D10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80047D14: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047D18: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80047D1C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80047D20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047D24: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047D28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047D2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047D30: j           L_80047EE0
    // 0x80047D34: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_80047EE0;
    // 0x80047D34: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80047D38:
    // 0x80047D38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047D3C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80047D40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047D44: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80047D48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047D4C: j           L_800480D4
    // 0x80047D50: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
        goto L_800480D4;
    // 0x80047D50: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
L_80047D54:
    // 0x80047D54: jal         0x80008CDC
    // 0x80047D58: nop

    func_80008CDC(rdram, ctx);
        goto after_24;
    // 0x80047D58: nop

    after_24:
    // 0x80047D5C: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047D60: nop
    
            goto L_800480F4;
    }
    // 0x80047D60: nop

    // 0x80047D64: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047D68: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047D6C: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047D70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800480F4;
    }
    // 0x80047D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047D74: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047D78: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80047D7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047D80: beq         $v1, $zero, L_80047D98
    if (ctx->r3 == 0) {
        // 0x80047D84: sb          $v0, 0x4A1F($at)
        MEM_B(0X4A1F, ctx->r1) = ctx->r2;
            goto L_80047D98;
    }
    // 0x80047D84: sb          $v0, 0x4A1F($at)
    MEM_B(0X4A1F, ctx->r1) = ctx->r2;
    // 0x80047D88: jal         0x8002CFB8
    // 0x80047D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_25;
    // 0x80047D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
    // 0x80047D90: j           L_80047DA0
    // 0x80047D94: nop

        goto L_80047DA0;
    // 0x80047D94: nop

L_80047D98:
    // 0x80047D98: jal         0x8002D0D4
    // 0x80047D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_26;
    // 0x80047D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_26:
L_80047DA0:
    // 0x80047DA0: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047DA4: nop
    
            goto L_800480F4;
    }
    // 0x80047DA4: nop

    // 0x80047DA8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047DAC: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80047DB0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80047DB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047DB8: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80047DBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047DC0: j           L_800480F4
    // 0x80047DC4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_800480F4;
    // 0x80047DC4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80047DC8:
    // 0x80047DC8: jal         0x80008CDC
    // 0x80047DCC: nop

    func_80008CDC(rdram, ctx);
        goto after_27;
    // 0x80047DCC: nop

    after_27:
    // 0x80047DD0: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047DD4: nop
    
            goto L_800480F4;
    }
    // 0x80047DD4: nop

    // 0x80047DD8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047DDC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047DE0: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047DE4: nop
    
            goto L_800480F4;
    }
    // 0x80047DE4: nop

    // 0x80047DE8: jal         0x80044B18
    // 0x80047DEC: nop

    func_80044B18(rdram, ctx);
        goto after_28;
    // 0x80047DEC: nop

    after_28:
    // 0x80047DF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80047DF4: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80047DF8: beq         $v0, $zero, L_80047E24
    if (ctx->r2 == 0) {
        // 0x80047DFC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80047E24;
    }
    // 0x80047DFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047E00: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047E04: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80047E08: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047E0C: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80047E10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047E14: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047E18: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x80047E1C: jal         0x800064C0
    // 0x80047E20: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_29;
    // 0x80047E20: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_29:
L_80047E24:
    // 0x80047E24: jal         0x8000B840
    // 0x80047E28: nop

    func_8000B840(rdram, ctx);
        goto after_30;
    // 0x80047E28: nop

    after_30:
    // 0x80047E2C: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80047E30: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047E34: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800480F4;
    }
    // 0x80047E34: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80047E38: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80047E3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047E40: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80047E44: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047E48: sb          $s0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r16;
    // 0x80047E4C: jal         0x800064C0
    // 0x80047E50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_31;
    // 0x80047E50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_31:
    // 0x80047E54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047E58: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80047E5C: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047E60: nop
    
            goto L_800480F4;
    }
    // 0x80047E60: nop

    // 0x80047E64: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047E68: j           L_800480F4
    // 0x80047E6C: sb          $s0, 0x4A20($at)
    MEM_B(0X4A20, ctx->r1) = ctx->r16;
        goto L_800480F4;
    // 0x80047E6C: sb          $s0, 0x4A20($at)
    MEM_B(0X4A20, ctx->r1) = ctx->r16;
L_80047E70:
    // 0x80047E70: jal         0x80008CDC
    // 0x80047E74: nop

    func_80008CDC(rdram, ctx);
        goto after_32;
    // 0x80047E74: nop

    after_32:
    // 0x80047E78: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047E7C: nop
    
            goto L_800480F4;
    }
    // 0x80047E7C: nop

    // 0x80047E80: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047E84: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047E88: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047E8C: nop
    
            goto L_800480F4;
    }
    // 0x80047E8C: nop

    // 0x80047E90: jal         0x8002CFB8
    // 0x80047E94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_33;
    // 0x80047E94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_33:
    // 0x80047E98: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047E9C: nop
    
            goto L_800480F4;
    }
    // 0x80047E9C: nop

    // 0x80047EA0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80047EA4: jal         0x800535B0
    // 0x80047EA8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_34;
    // 0x80047EA8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_34:
    // 0x80047EAC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047EB0: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80047EB4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047EB8: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80047EBC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80047EC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80047EC4: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80047EC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80047ECC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80047ED0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80047ED4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047ED8: sb          $a0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r4;
    // 0x80047EDC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80047EE0:
    // 0x80047EE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047EE4: jal         0x80043F0C
    // 0x80047EE8: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_35;
    // 0x80047EE8: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_35:
L_80047EEC:
    // 0x80047EEC: jal         0x800449C0
    // 0x80047EF0: nop

    func_800449C0(rdram, ctx);
        goto after_36;
    // 0x80047EF0: nop

    after_36:
    // 0x80047EF4: jal         0x800440FC
    // 0x80047EF8: nop

    func_800440FC(rdram, ctx);
        goto after_37;
    // 0x80047EF8: nop

    after_37:
    // 0x80047EFC: jal         0x80031BEC
    // 0x80047F00: nop

    func_80031BEC(rdram, ctx);
        goto after_38;
    // 0x80047F00: nop

    after_38:
    // 0x80047F04: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80047F08: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80047F0C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80047F10: jal         0x80040558
    // 0x80047F14: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_39;
    // 0x80047F14: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_39:
    // 0x80047F18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047F1C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80047F20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80047F24: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80047F28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80047F2C: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80047F30: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047F34: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80047F38: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047F3C: sb          $zero, 0x4A1F($at)
    MEM_B(0X4A1F, ctx->r1) = 0;
    // 0x80047F40: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80047F44: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80047F48: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80047F4C: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x80047F50: beq         $v1, $v0, L_800480F4
    if (ctx->r3 == ctx->r2) {
        // 0x80047F54: nop
    
            goto L_800480F4;
    }
    // 0x80047F54: nop

    // 0x80047F58: jal         0x80006944
    // 0x80047F5C: nop

    func_80006944(rdram, ctx);
        goto after_40;
    // 0x80047F5C: nop

    after_40:
    // 0x80047F60: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80047F64: jal         0x800067C8
    // 0x80047F68: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_41;
    // 0x80047F68: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_41:
    // 0x80047F6C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80047F70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047F74: j           L_800480F4
    // 0x80047F78: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_800480F4;
    // 0x80047F78: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80047F7C:
    // 0x80047F7C: jal         0x80008CDC
    // 0x80047F80: nop

    func_80008CDC(rdram, ctx);
        goto after_42;
    // 0x80047F80: nop

    after_42:
    // 0x80047F84: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047F88: nop
    
            goto L_800480F4;
    }
    // 0x80047F88: nop

    // 0x80047F8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047F90: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047F94: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047F98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800480F4;
    }
    // 0x80047F98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80047F9C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80047FA0: sb          $v0, 0x4A1F($at)
    MEM_B(0X4A1F, ctx->r1) = ctx->r2;
    // 0x80047FA4: jal         0x8002CFB8
    // 0x80047FA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_43;
    // 0x80047FA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_43:
    // 0x80047FAC: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80047FB0: nop
    
            goto L_800480F4;
    }
    // 0x80047FB0: nop

    // 0x80047FB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047FB8: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80047FBC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80047FC0: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80047FC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80047FC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80047FCC: j           L_800480F4
    // 0x80047FD0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_800480F4;
    // 0x80047FD0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80047FD4:
    // 0x80047FD4: jal         0x80008CDC
    // 0x80047FD8: nop

    func_80008CDC(rdram, ctx);
        goto after_44;
    // 0x80047FD8: nop

    after_44:
    // 0x80047FDC: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047FE0: nop
    
            goto L_800480F4;
    }
    // 0x80047FE0: nop

    // 0x80047FE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80047FE8: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80047FEC: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80047FF0: nop
    
            goto L_800480F4;
    }
    // 0x80047FF0: nop

    // 0x80047FF4: jal         0x80044B18
    // 0x80047FF8: nop

    func_80044B18(rdram, ctx);
        goto after_45;
    // 0x80047FF8: nop

    after_45:
    // 0x80047FFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80048000: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x80048004: beq         $v0, $zero, L_80048030
    if (ctx->r2 == 0) {
        // 0x80048008: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80048030;
    }
    // 0x80048008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004800C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048010: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80048014: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048018: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x8004801C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048020: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048024: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x80048028: jal         0x800064C0
    // 0x8004802C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_46;
    // 0x8004802C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_46:
L_80048030:
    // 0x80048030: jal         0x8000B840
    // 0x80048034: nop

    func_8000B840(rdram, ctx);
        goto after_47;
    // 0x80048034: nop

    after_47:
    // 0x80048038: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8004803C: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80048040: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800480F4;
    }
    // 0x80048040: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80048044: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048048: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8004804C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048050: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048054: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80048058: jal         0x800064C0
    // 0x8004805C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_48;
    // 0x8004805C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_48:
    // 0x80048060: j           L_800480F4
    // 0x80048064: nop

        goto L_800480F4;
    // 0x80048064: nop

L_80048068:
    // 0x80048068: jal         0x80008CDC
    // 0x8004806C: nop

    func_80008CDC(rdram, ctx);
        goto after_49;
    // 0x8004806C: nop

    after_49:
    // 0x80048070: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80048074: nop
    
            goto L_800480F4;
    }
    // 0x80048074: nop

    // 0x80048078: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004807C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80048080: bne         $v0, $zero, L_800480F4
    if (ctx->r2 != 0) {
        // 0x80048084: nop
    
            goto L_800480F4;
    }
    // 0x80048084: nop

    // 0x80048088: jal         0x8002CFB8
    // 0x8004808C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_50;
    // 0x8004808C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_50:
    // 0x80048090: beq         $v0, $zero, L_800480F4
    if (ctx->r2 == 0) {
        // 0x80048094: nop
    
            goto L_800480F4;
    }
    // 0x80048094: nop

    // 0x80048098: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004809C: jal         0x800535B0
    // 0x800480A0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_51;
    // 0x800480A0: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_51:
    // 0x800480A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800480A8: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x800480AC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800480B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800480B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800480B8: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800480BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800480C0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800480C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800480C8: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x800480CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800480D0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_800480D4:
    // 0x800480D4: jal         0x80031BEC
    // 0x800480D8: nop

    func_80031BEC(rdram, ctx);
        goto after_52;
    // 0x800480D8: nop

    after_52:
    // 0x800480DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800480E0: jal         0x80016AB4
    // 0x800480E4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_53;
    // 0x800480E4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_53:
    // 0x800480E8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800480EC: jal         0x80016AB4
    // 0x800480F0: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_54;
    // 0x800480F0: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_54:
L_800480F4:
    // 0x800480F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800480F8: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x800480FC: bne         $v0, $zero, L_80048148
    if (ctx->r2 != 0) {
        // 0x80048100: nop
    
            goto L_80048148;
    }
    // 0x80048100: nop

    // 0x80048104: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048108: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8004810C: bne         $v0, $zero, L_80048148
    if (ctx->r2 != 0) {
        // 0x80048110: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80048148;
    }
    // 0x80048110: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80048114: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048118: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x8004811C: beq         $v1, $v0, L_80048148
    if (ctx->r3 == ctx->r2) {
        // 0x80048120: nop
    
            goto L_80048148;
    }
    // 0x80048120: nop

    // 0x80048124: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80048128: lb          $v0, 0x4A1F($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A1F);
    // 0x8004812C: beq         $v0, $zero, L_80048148
    if (ctx->r2 == 0) {
        // 0x80048130: nop
    
            goto L_80048148;
    }
    // 0x80048130: nop

    // 0x80048134: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048138: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004813C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048140: jal         0x8004114C
    // 0x80048144: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_55;
    // 0x80048144: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_55:
L_80048148:
    // 0x80048148: jal         0x800448B0
    // 0x8004814C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_56;
    // 0x8004814C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_56:
    // 0x80048150: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80048154: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x80048158: jal         0x80017D38
    // 0x8004815C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_57;
    // 0x8004815C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_57:
    // 0x80048160: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048164: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80048168: bne         $v0, $zero, L_800481C4
    if (ctx->r2 != 0) {
        // 0x8004816C: nop
    
            goto L_800481C4;
    }
    // 0x8004816C: nop

    // 0x80048170: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048174: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80048178: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8004817C: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80048180: bne         $v0, $zero, L_800481A4
    if (ctx->r2 != 0) {
        // 0x80048184: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_800481A4;
    }
    // 0x80048184: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80048188: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8004818C: bne         $v1, $v0, L_800481C4
    if (ctx->r3 != ctx->r2) {
        // 0x80048190: nop
    
            goto L_800481C4;
    }
    // 0x80048190: nop

    // 0x80048194: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80048198: lb          $v0, 0x4A20($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A20);
    // 0x8004819C: beq         $v0, $zero, L_800481C4
    if (ctx->r2 == 0) {
        // 0x800481A0: nop
    
            goto L_800481C4;
    }
    // 0x800481A0: nop

L_800481A4:
    // 0x800481A4: jal         0x800444F4
    // 0x800481A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800444F4(rdram, ctx);
        goto after_58;
    // 0x800481A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_58:
    // 0x800481AC: jal         0x800444F4
    // 0x800481B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800444F4(rdram, ctx);
        goto after_59;
    // 0x800481B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_59:
    // 0x800481B4: jal         0x80017D38
    // 0x800481B8: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    func_80017D38(rdram, ctx);
        goto after_60;
    // 0x800481B8: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    after_60:
    // 0x800481BC: jal         0x80017D38
    // 0x800481C0: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    func_80017D38(rdram, ctx);
        goto after_61;
    // 0x800481C0: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    after_61:
L_800481C4:
    // 0x800481C4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800481C8: jal         0x80017D38
    // 0x800481CC: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    func_80017D38(rdram, ctx);
        goto after_62;
    // 0x800481CC: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    after_62:
    // 0x800481D0: jal         0x80051D6C
    // 0x800481D4: nop

    func_80051D6C(rdram, ctx);
        goto after_63;
    // 0x800481D4: nop

    after_63:
    // 0x800481D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800481DC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800481E0: bne         $v0, $zero, L_80048200
    if (ctx->r2 != 0) {
        // 0x800481E4: nop
    
            goto L_80048200;
    }
    // 0x800481E4: nop

    // 0x800481E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800481EC: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x800481F0: beq         $v0, $zero, L_80048200
    if (ctx->r2 == 0) {
        // 0x800481F4: nop
    
            goto L_80048200;
    }
    // 0x800481F4: nop

    // 0x800481F8: jal         0x800533F0
    // 0x800481FC: nop

    func_800533F0(rdram, ctx);
        goto after_64;
    // 0x800481FC: nop

    after_64:
L_80048200:
    // 0x80048200: jal         0x80044D6C
    // 0x80048204: nop

    func_80044D6C(rdram, ctx);
        goto after_65;
    // 0x80048204: nop

    after_65:
    // 0x80048208: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8004820C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80048210: jr          $ra
    // 0x80048214: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80048214: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80048218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048218: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8004821C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80048220: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80048224: addiu       $s0, $s0, 0x7B71
    ctx->r16 = ADD32(ctx->r16, 0X7B71);
    // 0x80048228: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8004822C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80048230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048234: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80048238: beq         $v1, $v0, L_80048428
    if (ctx->r3 == ctx->r2) {
        // 0x8004823C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80048428;
    }
    // 0x8004823C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80048240: beql        $v0, $zero, L_80048258
    if (ctx->r2 == 0) {
        // 0x80048244: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80048258;
    }
    goto skip_0;
    // 0x80048244: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80048248: beq         $v1, $zero, L_80048270
    if (ctx->r3 == 0) {
        // 0x8004824C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80048270;
    }
    // 0x8004824C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80048250: j           L_8004858C
    // 0x80048254: nop

        goto L_8004858C;
    // 0x80048254: nop

L_80048258:
    // 0x80048258: beq         $v1, $v0, L_80048470
    if (ctx->r3 == ctx->r2) {
        // 0x8004825C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80048470;
    }
    // 0x8004825C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80048260: beq         $v1, $v0, L_80048508
    if (ctx->r3 == ctx->r2) {
        // 0x80048264: nop
    
            goto L_80048508;
    }
    // 0x80048264: nop

    // 0x80048268: j           L_8004858C
    // 0x8004826C: nop

        goto L_8004858C;
    // 0x8004826C: nop

L_80048270:
    // 0x80048270: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048274: lb          $v1, 0x25A0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25A0);
    // 0x80048278: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8004827C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048280: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048284: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x80048288: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004828C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048290: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80048294: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048298: sb          $zero, -0x4690($at)
    MEM_B(-0X4690, ctx->r1) = 0;
    // 0x8004829C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800482A0: beq         $v1, $zero, L_800482B8
    if (ctx->r3 == 0) {
        // 0x800482A4: sb          $zero, 0x4A21($at)
        MEM_B(0X4A21, ctx->r1) = 0;
            goto L_800482B8;
    }
    // 0x800482A4: sb          $zero, 0x4A21($at)
    MEM_B(0X4A21, ctx->r1) = 0;
    // 0x800482A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800482AC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800482B0: j           L_800482C4
    // 0x800482B4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_800482C4;
    // 0x800482B4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_800482B8:
    // 0x800482B8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800482BC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800482C0: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_800482C4:
    // 0x800482C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800482C8: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x800482CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800482D0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x800482D4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800482D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800482DC: lbu         $v0, -0x4694($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4694);
    // 0x800482E0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800482E4: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x800482E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800482EC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800482F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800482F4: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x800482F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800482FC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80048300: lw          $v1, -0x4BE8($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4BE8);
    // 0x80048304: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048308: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004830C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80048310: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048314: jal         0x80043F0C
    // 0x80048318: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80048318: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x8004831C: jal         0x80053390
    // 0x80048320: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80048320: nop

    after_1:
    // 0x80048324: jal         0x800449C0
    // 0x80048328: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80048328: nop

    after_2:
    // 0x8004832C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048330: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80048334: jal         0x80017760
    // 0x80048338: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80048338: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x8004833C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80048340: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80048344: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80048348: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004834C: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80048350: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80048354: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80048358: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x8004835C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048360: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80048364: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048368: jal         0x80066D30
    // 0x8004836C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x8004836C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x80048370: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80048374: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80048378: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004837C: jal         0x80006D98
    // 0x80048380: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x80048380: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x80048384: jal         0x80044224
    // 0x80048388: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80044224(rdram, ctx);
        goto after_6;
    // 0x80048388: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // 0x8004838C: jal         0x800440FC
    // 0x80048390: nop

    func_800440FC(rdram, ctx);
        goto after_7;
    // 0x80048390: nop

    after_7:
    // 0x80048394: jal         0x80031BEC
    // 0x80048398: nop

    func_80031BEC(rdram, ctx);
        goto after_8;
    // 0x80048398: nop

    after_8:
    // 0x8004839C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800483A0: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800483A4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800483A8: jal         0x80040558
    // 0x800483AC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_9;
    // 0x800483AC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_9:
    // 0x800483B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800483B4: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800483B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800483BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800483C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800483C4: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800483C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800483CC: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800483D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800483D4: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x800483D8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800483DC: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800483E0: beq         $v0, $zero, L_80048408
    if (ctx->r2 == 0) {
        // 0x800483E4: nop
    
            goto L_80048408;
    }
    // 0x800483E4: nop

    // 0x800483E8: jal         0x80006944
    // 0x800483EC: nop

    func_80006944(rdram, ctx);
        goto after_10;
    // 0x800483EC: nop

    after_10:
    // 0x800483F0: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800483F4: jal         0x800067C8
    // 0x800483F8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_11;
    // 0x800483F8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_11:
    // 0x800483FC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80048400: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048404: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80048408:
    // 0x80048408: jal         0x8002CFB8
    // 0x8004840C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_12;
    // 0x8004840C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80048410: jal         0x8002D378
    // 0x80048414: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_13;
    // 0x80048414: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80048418: jal         0x8002D0D4
    // 0x8004841C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_14;
    // 0x8004841C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x80048420: j           L_8004858C
    // 0x80048424: nop

        goto L_8004858C;
    // 0x80048424: nop

L_80048428:
    // 0x80048428: jal         0x80008CDC
    // 0x8004842C: nop

    func_80008CDC(rdram, ctx);
        goto after_15;
    // 0x8004842C: nop

    after_15:
    // 0x80048430: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x80048434: nop
    
            goto L_8004858C;
    }
    // 0x80048434: nop

    // 0x80048438: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004843C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80048440: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x80048444: nop
    
            goto L_8004858C;
    }
    // 0x80048444: nop

    // 0x80048448: jal         0x8002CFB8
    // 0x8004844C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_16;
    // 0x8004844C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80048450: beq         $v0, $zero, L_8004858C
    if (ctx->r2 == 0) {
        // 0x80048454: nop
    
            goto L_8004858C;
    }
    // 0x80048454: nop

    // 0x80048458: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004845C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048460: sb          $zero, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = 0;
    // 0x80048464: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80048468: j           L_8004858C
    // 0x8004846C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8004858C;
    // 0x8004846C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80048470:
    // 0x80048470: jal         0x80008CDC
    // 0x80048474: nop

    func_80008CDC(rdram, ctx);
        goto after_17;
    // 0x80048474: nop

    after_17:
    // 0x80048478: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x8004847C: nop
    
            goto L_8004858C;
    }
    // 0x8004847C: nop

    // 0x80048480: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048484: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80048488: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x8004848C: nop
    
            goto L_8004858C;
    }
    // 0x8004848C: nop

    // 0x80048490: jal         0x80044B18
    // 0x80048494: nop

    func_80044B18(rdram, ctx);
        goto after_18;
    // 0x80048494: nop

    after_18:
    // 0x80048498: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004849C: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x800484A0: beq         $v0, $zero, L_800484CC
    if (ctx->r2 == 0) {
        // 0x800484A4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800484CC;
    }
    // 0x800484A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800484A8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800484AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800484B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800484B4: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800484B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800484BC: jal         0x800064C0
    // 0x800484C0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    func_800064C0(rdram, ctx);
        goto after_19;
    // 0x800484C0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    after_19:
    // 0x800484C4: jal         0x800064C0
    // 0x800484C8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800064C0(rdram, ctx);
        goto after_20;
    // 0x800484C8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_20:
L_800484CC:
    // 0x800484CC: jal         0x8000B840
    // 0x800484D0: nop

    func_8000B840(rdram, ctx);
        goto after_21;
    // 0x800484D0: nop

    after_21:
    // 0x800484D4: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800484D8: beq         $v0, $zero, L_8004858C
    if (ctx->r2 == 0) {
        // 0x800484DC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004858C;
    }
    // 0x800484DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800484E0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800484E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800484E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800484EC: sb          $v0, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r2;
    // 0x800484F0: jal         0x800064C0
    // 0x800484F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_22;
    // 0x800484F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
    // 0x800484F8: jal         0x800064C0
    // 0x800484FC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800064C0(rdram, ctx);
        goto after_23;
    // 0x800484FC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_23:
    // 0x80048500: j           L_8004858C
    // 0x80048504: nop

        goto L_8004858C;
    // 0x80048504: nop

L_80048508:
    // 0x80048508: jal         0x80008CDC
    // 0x8004850C: nop

    func_80008CDC(rdram, ctx);
        goto after_24;
    // 0x8004850C: nop

    after_24:
    // 0x80048510: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x80048514: nop
    
            goto L_8004858C;
    }
    // 0x80048514: nop

    // 0x80048518: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004851C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80048520: bne         $v0, $zero, L_8004858C
    if (ctx->r2 != 0) {
        // 0x80048524: nop
    
            goto L_8004858C;
    }
    // 0x80048524: nop

    // 0x80048528: jal         0x8002D378
    // 0x8004852C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_25;
    // 0x8004852C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_25:
    // 0x80048530: beq         $v0, $zero, L_8004858C
    if (ctx->r2 == 0) {
        // 0x80048534: nop
    
            goto L_8004858C;
    }
    // 0x80048534: nop

    // 0x80048538: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004853C: jal         0x800535B0
    // 0x80048540: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_26;
    // 0x80048540: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_26:
    // 0x80048544: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048548: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x8004854C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80048550: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80048554: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048558: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8004855C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80048560: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048564: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80048568: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004856C: jal         0x80031BEC
    // 0x80048570: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80031BEC(rdram, ctx);
        goto after_27;
    // 0x80048570: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_27:
    // 0x80048574: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048578: jal         0x80016AB4
    // 0x8004857C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80016AB4(rdram, ctx);
        goto after_28;
    // 0x8004857C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_28:
    // 0x80048580: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048584: jal         0x80016AB4
    // 0x80048588: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80016AB4(rdram, ctx);
        goto after_29;
    // 0x80048588: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_29:
L_8004858C:
    // 0x8004858C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048590: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80048594: bne         $v0, $zero, L_800485D0
    if (ctx->r2 != 0) {
        // 0x80048598: nop
    
            goto L_800485D0;
    }
    // 0x80048598: nop

    // 0x8004859C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800485A0: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800485A4: bne         $v0, $zero, L_800485D0
    if (ctx->r2 != 0) {
        // 0x800485A8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800485D0;
    }
    // 0x800485A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800485AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800485B0: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x800485B4: beq         $v1, $v0, L_800485D0
    if (ctx->r3 == ctx->r2) {
        // 0x800485B8: nop
    
            goto L_800485D0;
    }
    // 0x800485B8: nop

    // 0x800485BC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800485C0: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800485C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800485C8: jal         0x8004114C
    // 0x800485CC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_30;
    // 0x800485CC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_30:
L_800485D0:
    // 0x800485D0: jal         0x800448B0
    // 0x800485D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800448B0(rdram, ctx);
        goto after_31;
    // 0x800485D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_31:
    // 0x800485D8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800485DC: addiu       $s0, $s0, 0x6B10
    ctx->r16 = ADD32(ctx->r16, 0X6B10);
    // 0x800485E0: jal         0x80017D38
    // 0x800485E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_32;
    // 0x800485E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_32:
    // 0x800485E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800485EC: lb          $v0, -0x4690($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4690);
    // 0x800485F0: beq         $v0, $zero, L_80048664
    if (ctx->r2 == 0) {
        // 0x800485F4: nop
    
            goto L_80048664;
    }
    // 0x800485F4: nop

    // 0x800485F8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800485FC: lb          $v0, 0x4A21($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A21);
    // 0x80048600: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80048604: slti        $v0, $v0, 0x78
    ctx->r2 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80048608: beq         $v0, $zero, L_80048618
    if (ctx->r2 == 0) {
        // 0x8004860C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80048618;
    }
    // 0x8004860C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80048610: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80048614: sb          $v0, 0x4A21($at)
    MEM_B(0X4A21, ctx->r1) = ctx->r2;
L_80048618:
    // 0x80048618: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x8004861C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80048620: lb          $v0, 0x4A21($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A21);
    // 0x80048624: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x80048628: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8004862C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048630: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048634: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048638: lhu         $a0, 0x7BC0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X7BC0);
    // 0x8004863C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80048640: mfhi        $a3
    ctx->r7 = hi;
    // 0x80048644: sra         $v0, $a3, 2
    ctx->r2 = S32(SIGNED(ctx->r7) >> 2);
    // 0x80048648: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004864C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048650: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80048654: lb          $v0, -0x468C($at)
    ctx->r2 = MEM_B(ctx->r1, -0X468C);
    // 0x80048658: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8004865C: beq         $a0, $zero, L_80048674
    if (ctx->r4 == 0) {
        // 0x80048660: nop
    
            goto L_80048674;
    }
    // 0x80048660: nop

L_80048664:
    // 0x80048664: jal         0x80017D38
    // 0x80048668: addiu       $a0, $s0, -0x70
    ctx->r4 = ADD32(ctx->r16, -0X70);
    func_80017D38(rdram, ctx);
        goto after_33;
    // 0x80048668: addiu       $a0, $s0, -0x70
    ctx->r4 = ADD32(ctx->r16, -0X70);
    after_33:
    // 0x8004866C: j           L_80048684
    // 0x80048670: nop

        goto L_80048684;
    // 0x80048670: nop

L_80048674:
    // 0x80048674: jal         0x80017D38
    // 0x80048678: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_34;
    // 0x80048678: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_34:
    // 0x8004867C: jal         0x800064C0
    // 0x80048680: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800064C0(rdram, ctx);
        goto after_35;
    // 0x80048680: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_35:
L_80048684:
    // 0x80048684: jal         0x80051D6C
    // 0x80048688: nop

    func_80051D6C(rdram, ctx);
        goto after_36;
    // 0x80048688: nop

    after_36:
    // 0x8004868C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048690: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80048694: bne         $v0, $zero, L_800486B4
    if (ctx->r2 != 0) {
        // 0x80048698: nop
    
            goto L_800486B4;
    }
    // 0x80048698: nop

    // 0x8004869C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800486A0: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x800486A4: beq         $v0, $zero, L_800486B4
    if (ctx->r2 == 0) {
        // 0x800486A8: nop
    
            goto L_800486B4;
    }
    // 0x800486A8: nop

    // 0x800486AC: jal         0x800533F0
    // 0x800486B0: nop

    func_800533F0(rdram, ctx);
        goto after_37;
    // 0x800486B0: nop

    after_37:
L_800486B4:
    // 0x800486B4: jal         0x80044D6C
    // 0x800486B8: nop

    func_80044D6C(rdram, ctx);
        goto after_38;
    // 0x800486B8: nop

    after_38:
    // 0x800486BC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800486C0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800486C4: jr          $ra
    // 0x800486C8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800486C8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800486CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800486CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800486D0: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x800486D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800486D8: bne         $v0, $zero, L_800486F0
    if (ctx->r2 != 0) {
        // 0x800486DC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800486F0;
    }
    // 0x800486DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800486E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800486E4: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x800486E8: beq         $v0, $zero, L_80048708
    if (ctx->r2 == 0) {
        // 0x800486EC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80048708;
    }
    // 0x800486EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800486F0:
    // 0x800486F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800486F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800486F8: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800486FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048700: j           L_80048810
    // 0x80048704: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
        goto L_80048810;
    // 0x80048704: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_80048708:
    // 0x80048708: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004870C: lbu         $v0, 0x7B98($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B98);
    // 0x80048710: beq         $v0, $v1, L_80048728
    if (ctx->r2 == ctx->r3) {
        // 0x80048714: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80048728;
    }
    // 0x80048714: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80048718: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004871C: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80048720: bne         $v0, $v1, L_80048750
    if (ctx->r2 != ctx->r3) {
        // 0x80048724: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80048750;
    }
    // 0x80048724: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80048728:
    // 0x80048728: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004872C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80048730: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048734: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80048738: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004873C: jal         0x80031BEC
    // 0x80048740: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_0;
    // 0x80048740: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    after_0:
    // 0x80048744: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048748: j           L_80048800
    // 0x8004874C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
        goto L_80048800;
    // 0x8004874C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
L_80048750:
    // 0x80048750: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048754: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
    // 0x80048758: beq         $v1, $zero, L_800487C4
    if (ctx->r3 == 0) {
        // 0x8004875C: nop
    
            goto L_800487C4;
    }
    // 0x8004875C: nop

    // 0x80048760: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048764: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80048768: beq         $v0, $zero, L_800487C4
    if (ctx->r2 == 0) {
        // 0x8004876C: nop
    
            goto L_800487C4;
    }
    // 0x8004876C: nop

    // 0x80048770: bne         $v1, $v0, L_800487C4
    if (ctx->r3 != ctx->r2) {
        // 0x80048774: nop
    
            goto L_800487C4;
    }
    // 0x80048774: nop

    // 0x80048778: lw          $v0, 0xD0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD0);
    // 0x8004877C: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80048780: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80048784: beq         $v0, $zero, L_800487A0
    if (ctx->r2 == 0) {
        // 0x80048788: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800487A0;
    }
    // 0x80048788: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8004878C: lbu         $v0, 0x6D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6D);
    // 0x80048790: bne         $v0, $zero, L_800487E8
    if (ctx->r2 != 0) {
        // 0x80048794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800487E8;
    }
    // 0x80048794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048798: j           L_800487E8
    // 0x8004879C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800487E8;
    // 0x8004879C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800487A0:
    // 0x800487A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800487A4: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800487A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800487AC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800487B0: lw          $v0, 0xD0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD0);
    // 0x800487B4: sb          $zero, 0x53($v0)
    MEM_B(0X53, ctx->r2) = 0;
    // 0x800487B8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800487BC: j           L_80048800
    // 0x800487C0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
        goto L_80048800;
    // 0x800487C0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
L_800487C4:
    // 0x800487C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800487C8: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x800487CC: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x800487D0: beq         $v0, $zero, L_800487E8
    if (ctx->r2 == 0) {
        // 0x800487D4: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800487E8;
    }
    // 0x800487D4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800487D8: lbu         $v0, 0x6D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6D);
    // 0x800487DC: bne         $v0, $zero, L_800487E8
    if (ctx->r2 != 0) {
        // 0x800487E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800487E8;
    }
    // 0x800487E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800487E4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800487E8:
    // 0x800487E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800487EC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x800487F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800487F4: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x800487F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800487FC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_80048800:
    // 0x80048800: lw          $v1, 0xD0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XD0);
    // 0x80048804: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80048808: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x8004880C: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
L_80048810:
    // 0x80048810: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80048814: jr          $ra
    // 0x80048818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80048818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004881C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004881C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048820: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80048824: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80048828: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004882C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80048830: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80048834: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x80048838: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x8004883C: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80049290;
    }
    // 0x8004883C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80048840: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80048844: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80048848: addu        $at, $at, $v0
    gpr jr_addend_80048850 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004884C: lw          $v0, -0x2258($at)
    ctx->r2 = ADD32(ctx->r1, -0X2258);
    // 0x80048850: jr          $v0
    // 0x80048854: nop

    switch (jr_addend_80048850 >> 2) {
        case 0: goto L_80048858; break;
        case 1: goto L_800489F0; break;
        case 2: goto L_80048A20; break;
        case 3: goto L_80048A80; break;
        case 4: goto L_80048B9C; break;
        case 5: goto L_80048C18; break;
        case 6: goto L_80048D64; break;
        case 7: goto L_80048E8C; break;
        case 8: goto L_80048F2C; break;
        case 9: goto L_80049060; break;
        case 10: goto L_8004912C; break;
        case 11: goto L_800491E8; break;
        case 12: goto L_80049248; break;
        default: switch_error(__func__, 0x80048850, 0x800ADDA8);
    }
    // 0x80048854: nop

L_80048858:
    // 0x80048858: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004885C: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x80048860: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80048864: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048868: lb          $a1, 0x25A0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X25A0);
    // 0x8004886C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80048870: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048874: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x80048878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004887C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048880: sb          $v0, 0x7BA1($at)
    MEM_B(0X7BA1, ctx->r1) = ctx->r2;
    // 0x80048884: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048888: sb          $zero, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = 0;
    // 0x8004888C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048890: beq         $a1, $zero, L_800488A8
    if (ctx->r5 == 0) {
        // 0x80048894: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_800488A8;
    }
    // 0x80048894: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80048898: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004889C: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800488A0: j           L_800488B4
    // 0x800488A4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
        goto L_800488B4;
    // 0x800488A4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_800488A8:
    // 0x800488A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800488AC: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x800488B0: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_800488B4:
    // 0x800488B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800488B8: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x800488BC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800488C0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x800488C4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800488C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800488CC: lbu         $v0, -0x4680($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4680);
    // 0x800488D0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800488D4: addiu       $s0, $s0, 0x6ACC
    ctx->r16 = ADD32(ctx->r16, 0X6ACC);
    // 0x800488D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800488DC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800488E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800488E4: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x800488E8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800488EC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800488F0: lw          $a0, -0x4BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BE8);
    // 0x800488F4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800488F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800488FC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80048900: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048904: jal         0x80043F0C
    // 0x80048908: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    func_80043F0C(rdram, ctx);
        goto after_0;
    // 0x80048908: sb          $v0, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r2;
    after_0:
    // 0x8004890C: jal         0x80053390
    // 0x80048910: nop

    func_80053390(rdram, ctx);
        goto after_1;
    // 0x80048910: nop

    after_1:
    // 0x80048914: jal         0x800449C0
    // 0x80048918: nop

    func_800449C0(rdram, ctx);
        goto after_2;
    // 0x80048918: nop

    after_2:
    // 0x8004891C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048920: sb          $zero, 0x6B3A($at)
    MEM_B(0X6B3A, ctx->r1) = 0;
    // 0x80048924: jal         0x80017760
    // 0x80048928: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_80017760(rdram, ctx);
        goto after_3;
    // 0x80048928: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x8004892C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80048930: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80048934: sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // 0x80048938: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004893C: sh          $v0, 0x6B1E($at)
    MEM_H(0X6B1E, ctx->r1) = ctx->r2;
    // 0x80048940: addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // 0x80048944: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80048948: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x8004894C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048950: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
    // 0x80048954: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048958: jal         0x80066D30
    // 0x8004895C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    func_80066D30(rdram, ctx);
        goto after_4;
    // 0x8004895C: sw          $s0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r16;
    after_4:
    // 0x80048960: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80048964: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80048968: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004896C: jal         0x80006D98
    // 0x80048970: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x80048970: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_5:
    // 0x80048974: jal         0x800440FC
    // 0x80048978: nop

    func_800440FC(rdram, ctx);
        goto after_6;
    // 0x80048978: nop

    after_6:
    // 0x8004897C: jal         0x80031BEC
    // 0x80048980: nop

    func_80031BEC(rdram, ctx);
        goto after_7;
    // 0x80048980: nop

    after_7:
    // 0x80048984: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048988: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x8004898C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048990: jal         0x80040558
    // 0x80048994: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_8;
    // 0x80048994: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_8:
    // 0x80048998: jal         0x8002CFB8
    // 0x8004899C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_9;
    // 0x8004899C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x800489A0: jal         0x8002D378
    // 0x800489A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_10;
    // 0x800489A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x800489A8: jal         0x8002D0D4
    // 0x800489AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_11;
    // 0x800489AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x800489B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800489B4: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x800489B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800489BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800489C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800489C4: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x800489C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800489CC: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x800489D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800489D4: sb          $zero, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = 0;
    // 0x800489D8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800489DC: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800489E0: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x800489E4: nop
    
            goto L_80049290;
    }
    // 0x800489E4: nop

    // 0x800489E8: j           L_80048E68
    // 0x800489EC: nop

        goto L_80048E68;
    // 0x800489EC: nop

L_800489F0:
    // 0x800489F0: jal         0x8002CFB8
    // 0x800489F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_12;
    // 0x800489F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x800489F8: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x800489FC: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80049290;
    }
    // 0x800489FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80048A00: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048A04: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80048A08: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80048A0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048A10: sb          $a0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r4;
    // 0x80048A14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048A18: j           L_80049290
    // 0x80048A1C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_80049290;
    // 0x80048A1C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80048A20:
    // 0x80048A20: jal         0x80044C7C
    // 0x80048A24: nop

    func_80044C7C(rdram, ctx);
        goto after_13;
    // 0x80048A24: nop

    after_13:
    // 0x80048A28: jal         0x8000B840
    // 0x80048A2C: nop

    func_8000B840(rdram, ctx);
        goto after_14;
    // 0x80048A2C: nop

    after_14:
    // 0x80048A30: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80048A34: lh          $v1, 0x2FAC($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X2FAC);
    // 0x80048A38: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80048A3C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80048A40: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80048A44: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80049290;
    }
    // 0x80048A44: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80048A48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048A4C: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80048A50: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80048A54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048A58: jal         0x800064C0
    // 0x80048A5C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_800064C0(rdram, ctx);
        goto after_15;
    // 0x80048A5C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_15:
    // 0x80048A60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048A64: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80048A68: bne         $v0, $zero, L_80049290
    if (ctx->r2 != 0) {
        // 0x80048A6C: nop
    
            goto L_80049290;
    }
    // 0x80048A6C: nop

    // 0x80048A70: jal         0x8002D378
    // 0x80048A74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_16;
    // 0x80048A74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80048A78: j           L_80049290
    // 0x80048A7C: nop

        goto L_80049290;
    // 0x80048A7C: nop

L_80048A80:
    // 0x80048A80: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048A84: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80048A88: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80048A8C: bne         $v0, $zero, L_80048AA4
    if (ctx->r2 != 0) {
        // 0x80048A90: nop
    
            goto L_80048AA4;
    }
    // 0x80048A90: nop

    // 0x80048A94: jal         0x8002CFB8
    // 0x80048A98: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_17;
    // 0x80048A98: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // 0x80048A9C: j           L_80048AC4
    // 0x80048AA0: nop

        goto L_80048AC4;
    // 0x80048AA0: nop

L_80048AA4:
    // 0x80048AA4: bne         $v1, $zero, L_80048ABC
    if (ctx->r3 != 0) {
        // 0x80048AA8: nop
    
            goto L_80048ABC;
    }
    // 0x80048AA8: nop

    // 0x80048AAC: jal         0x8002D378
    // 0x80048AB0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_18;
    // 0x80048AB0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_18:
    // 0x80048AB4: j           L_80048AC4
    // 0x80048AB8: nop

        goto L_80048AC4;
    // 0x80048AB8: nop

L_80048ABC:
    // 0x80048ABC: jal         0x8002D0D4
    // 0x80048AC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_19;
    // 0x80048AC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
L_80048AC4:
    // 0x80048AC4: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80048AC8: nop
    
            goto L_80049290;
    }
    // 0x80048AC8: nop

    // 0x80048ACC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80048AD0: jal         0x800535B0
    // 0x80048AD4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_20;
    // 0x80048AD4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_20:
    // 0x80048AD8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80048ADC: addiu       $a2, $a2, 0x7B71
    ctx->r6 = ADD32(ctx->r6, 0X7B71);
    // 0x80048AE0: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80048AE4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048AE8: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80048AEC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80048AF0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048AF4: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80048AF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80048AFC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80048B00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048B04: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80048B08: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80048B0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048B10: jal         0x80043F0C
    // 0x80048B14: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_21;
    // 0x80048B14: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_21:
    // 0x80048B18: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048B1C: lbu         $a0, 0x6AC9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6AC9);
    // 0x80048B20: bnel        $a0, $zero, L_80048B44
    if (ctx->r4 != 0) {
        // 0x80048B24: sll         $a0, $a0, 24
        ctx->r4 = S32(ctx->r4 << 24);
            goto L_80048B44;
    }
    goto skip_0;
    // 0x80048B24: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    skip_0:
    // 0x80048B28: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x80048B2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048B30: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x80048B34: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // 0x80048B38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048B3C: j           L_80048B4C
    // 0x80048B40: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
        goto L_80048B4C;
    // 0x80048B40: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
L_80048B44:
    // 0x80048B44: jal         0x80044224
    // 0x80048B48: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    func_80044224(rdram, ctx);
        goto after_22;
    // 0x80048B48: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_22:
L_80048B4C:
    // 0x80048B4C: jal         0x800449C0
    // 0x80048B50: nop

    func_800449C0(rdram, ctx);
        goto after_23;
    // 0x80048B50: nop

    after_23:
    // 0x80048B54: jal         0x800440FC
    // 0x80048B58: nop

    func_800440FC(rdram, ctx);
        goto after_24;
    // 0x80048B58: nop

    after_24:
    // 0x80048B5C: jal         0x80031BEC
    // 0x80048B60: nop

    func_80031BEC(rdram, ctx);
        goto after_25;
    // 0x80048B60: nop

    after_25:
    // 0x80048B64: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80048B68: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x80048B6C: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80048B70: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048B74: jal         0x80040558
    // 0x80048B78: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_26;
    // 0x80048B78: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_26:
    // 0x80048B7C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80048B80: beq         $v0, $zero, L_80048B8C
    if (ctx->r2 == 0) {
        // 0x80048B84: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80048B8C;
    }
    // 0x80048B84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80048B88: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80048B8C:
    // 0x80048B8C: jal         0x8002D378
    // 0x80048B90: nop

    func_8002D378(rdram, ctx);
        goto after_27;
    // 0x80048B90: nop

    after_27:
    // 0x80048B94: j           L_80048E30
    // 0x80048B98: nop

        goto L_80048E30;
    // 0x80048B98: nop

L_80048B9C:
    // 0x80048B9C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048BA0: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80048BA4: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80048BA8: bne         $v0, $zero, L_80048BC0
    if (ctx->r2 != 0) {
        // 0x80048BAC: nop
    
            goto L_80048BC0;
    }
    // 0x80048BAC: nop

    // 0x80048BB0: jal         0x8002CFB8
    // 0x80048BB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_28;
    // 0x80048BB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x80048BB8: j           L_80048BE0
    // 0x80048BBC: nop

        goto L_80048BE0;
    // 0x80048BBC: nop

L_80048BC0:
    // 0x80048BC0: bne         $v1, $zero, L_80048BD8
    if (ctx->r3 != 0) {
        // 0x80048BC4: nop
    
            goto L_80048BD8;
    }
    // 0x80048BC4: nop

    // 0x80048BC8: jal         0x8002D378
    // 0x80048BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D378(rdram, ctx);
        goto after_29;
    // 0x80048BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x80048BD0: j           L_80048BE0
    // 0x80048BD4: nop

        goto L_80048BE0;
    // 0x80048BD4: nop

L_80048BD8:
    // 0x80048BD8: jal         0x8002D0D4
    // 0x80048BDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_30;
    // 0x80048BDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
L_80048BE0:
    // 0x80048BE0: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80048BE4: nop
    
            goto L_80049290;
    }
    // 0x80048BE4: nop

    // 0x80048BE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048BEC: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80048BF0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80048BF4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048BF8: lbu         $a0, 0x6AC9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6AC9);
    // 0x80048BFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048C00: bne         $a0, $zero, L_80048F18
    if (ctx->r4 != 0) {
        // 0x80048C04: sb          $v1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r3;
            goto L_80048F18;
    }
    // 0x80048C04: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80048C08: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80048C0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048C10: j           L_80048F18
    // 0x80048C14: sw          $v0, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = ctx->r2;
        goto L_80048F18;
    // 0x80048C14: sw          $v0, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = ctx->r2;
L_80048C18:
    // 0x80048C18: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80048C1C: addiu       $a0, $a0, 0x2FAA
    ctx->r4 = ADD32(ctx->r4, 0X2FAA);
    // 0x80048C20: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80048C24: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80048C28: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x80048C2C: beq         $v0, $zero, L_80048C3C
    if (ctx->r2 == 0) {
        // 0x80048C30: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80048C3C;
    }
    // 0x80048C30: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80048C34: j           L_80048C48
    // 0x80048C38: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80048C48;
    // 0x80048C38: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80048C3C:
    // 0x80048C3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048C40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048C44: sh          $v0, 0x2FAC($at)
    MEM_H(0X2FAC, ctx->r1) = ctx->r2;
L_80048C48:
    // 0x80048C48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048C4C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80048C50: beq         $v0, $zero, L_80048D00
    if (ctx->r2 == 0) {
        // 0x80048C54: nop
    
            goto L_80048D00;
    }
    // 0x80048C54: nop

    // 0x80048C58: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80048C5C: lhu         $v1, 0x2FAA($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2FAA);
    // 0x80048C60: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80048C64: sra         $a0, $a1, 16
    ctx->r4 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80048C68: slti        $v0, $a0, 0x3D
    ctx->r2 = SIGNED(ctx->r4) < 0X3D ? 1 : 0;
    // 0x80048C6C: beql        $v0, $zero, L_80048C74
    if (ctx->r2 == 0) {
        // 0x80048C70: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80048C74;
    }
    goto skip_1;
    // 0x80048C70: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_1:
L_80048C74:
    // 0x80048C74: addiu       $v0, $v1, -0x46
    ctx->r2 = ADD32(ctx->r3, -0X46);
    // 0x80048C78: sltiu       $v0, $v0, 0x47
    ctx->r2 = ctx->r2 < 0X47 ? 1 : 0;
    // 0x80048C7C: beq         $v0, $zero, L_80048CCC
    if (ctx->r2 == 0) {
        // 0x80048C80: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_80048CCC;
    }
    // 0x80048C80: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x80048C84: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x80048C88: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048C8C: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80048C90: mfhi        $a3
    ctx->r7 = hi;
    // 0x80048C94: sra         $v1, $a3, 2
    ctx->r3 = S32(SIGNED(ctx->r7) >> 2);
    // 0x80048C98: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80048C9C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80048CA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80048CA4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80048CA8: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80048CAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80048CB0: bne         $v0, $zero, L_80048CD0
    if (ctx->r2 != 0) {
        // 0x80048CB4: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_80048CD0;
    }
    // 0x80048CB4: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80048CB8: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80048CBC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80048CC0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048CC4: jal         0x8001D670
    // 0x80048CC8: addiu       $a0, $a0, -0x2538
    ctx->r4 = ADD32(ctx->r4, -0X2538);
    func_8001D670(rdram, ctx);
        goto after_31;
    // 0x80048CC8: addiu       $a0, $a0, -0x2538
    ctx->r4 = ADD32(ctx->r4, -0X2538);
    after_31:
L_80048CCC:
    // 0x80048CCC: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80048CD0:
    // 0x80048CD0: beq         $v0, $zero, L_80049000
    if (ctx->r2 == 0) {
        // 0x80048CD4: nop
    
            goto L_80049000;
    }
    // 0x80048CD4: nop

    // 0x80048CD8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80048CDC: lb          $v0, -0x467C($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X467C);
    // 0x80048CE0: bne         $v0, $zero, L_80049000
    if (ctx->r2 != 0) {
        // 0x80048CE4: nop
    
            goto L_80049000;
    }
    // 0x80048CE4: nop

    // 0x80048CE8: jal         0x800064C0
    // 0x80048CEC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800064C0(rdram, ctx);
        goto after_32;
    // 0x80048CEC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_32:
    // 0x80048CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048CF4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048CF8: j           L_80049000
    // 0x80048CFC: sb          $v0, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = ctx->r2;
        goto L_80049000;
    // 0x80048CFC: sb          $v0, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = ctx->r2;
L_80048D00:
    // 0x80048D00: jal         0x8002D378
    // 0x80048D04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_33;
    // 0x80048D04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_33:
    // 0x80048D08: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80048D0C: lb          $v0, -0x467C($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X467C);
    // 0x80048D10: bne         $v0, $zero, L_80048D28
    if (ctx->r2 != 0) {
        // 0x80048D14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80048D28;
    }
    // 0x80048D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80048D18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048D1C: sb          $v0, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = ctx->r2;
    // 0x80048D20: jal         0x800064C0
    // 0x80048D24: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    func_800064C0(rdram, ctx);
        goto after_34;
    // 0x80048D24: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_34:
L_80048D28:
    // 0x80048D28: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80048D2C: lb          $v0, -0x467B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X467B);
    // 0x80048D30: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80048D34: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80048D38: beq         $v0, $zero, L_80048D4C
    if (ctx->r2 == 0) {
        // 0x80048D3C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80048D4C;
    }
    // 0x80048D3C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80048D40: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048D44: j           L_80049000
    // 0x80048D48: sb          $v0, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = ctx->r2;
        goto L_80049000;
    // 0x80048D48: sb          $v0, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = ctx->r2;
L_80048D4C:
    // 0x80048D4C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048D50: sb          $zero, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = 0;
    // 0x80048D54: jal         0x8002D378
    // 0x80048D58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002D378(rdram, ctx);
        goto after_35;
    // 0x80048D58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_35:
    // 0x80048D5C: j           L_80049000
    // 0x80048D60: nop

        goto L_80049000;
    // 0x80048D60: nop

L_80048D64:
    // 0x80048D64: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048D68: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80048D6C: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80048D70: bne         $v0, $zero, L_80048D88
    if (ctx->r2 != 0) {
        // 0x80048D74: nop
    
            goto L_80048D88;
    }
    // 0x80048D74: nop

    // 0x80048D78: jal         0x8002CFB8
    // 0x80048D7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_36;
    // 0x80048D7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_36:
    // 0x80048D80: j           L_80048DA8
    // 0x80048D84: nop

        goto L_80048DA8;
    // 0x80048D84: nop

L_80048D88:
    // 0x80048D88: bne         $v1, $zero, L_80048DA0
    if (ctx->r3 != 0) {
        // 0x80048D8C: nop
    
            goto L_80048DA0;
    }
    // 0x80048D8C: nop

    // 0x80048D90: jal         0x8002D378
    // 0x80048D94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_37;
    // 0x80048D94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_37:
    // 0x80048D98: j           L_80048DA8
    // 0x80048D9C: nop

        goto L_80048DA8;
    // 0x80048D9C: nop

L_80048DA0:
    // 0x80048DA0: jal         0x8002D0D4
    // 0x80048DA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_38;
    // 0x80048DA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_38:
L_80048DA8:
    // 0x80048DA8: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80048DAC: nop
    
            goto L_80049290;
    }
    // 0x80048DAC: nop

    // 0x80048DB0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80048DB4: jal         0x800535B0
    // 0x80048DB8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_39;
    // 0x80048DB8: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_39:
    // 0x80048DBC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80048DC0: addiu       $a2, $a2, 0x7B71
    ctx->r6 = ADD32(ctx->r6, 0X7B71);
    // 0x80048DC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048DC8: sh          $zero, 0x2FAA($at)
    MEM_H(0X2FAA, ctx->r1) = 0;
    // 0x80048DCC: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80048DD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048DD4: addiu       $a1, $a1, 0x6ACC
    ctx->r5 = ADD32(ctx->r5, 0X6ACC);
    // 0x80048DD8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80048DDC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048DE0: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x80048DE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80048DE8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80048DEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048DF0: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80048DF4: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80048DF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048DFC: jal         0x80043F0C
    // 0x80048E00: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_40;
    // 0x80048E00: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_40:
    // 0x80048E04: jal         0x800449C0
    // 0x80048E08: nop

    func_800449C0(rdram, ctx);
        goto after_41;
    // 0x80048E08: nop

    after_41:
    // 0x80048E0C: jal         0x800440FC
    // 0x80048E10: nop

    func_800440FC(rdram, ctx);
        goto after_42;
    // 0x80048E10: nop

    after_42:
    // 0x80048E14: jal         0x80031BEC
    // 0x80048E18: nop

    func_80031BEC(rdram, ctx);
        goto after_43;
    // 0x80048E18: nop

    after_43:
    // 0x80048E1C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048E20: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80048E24: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80048E28: jal         0x80040558
    // 0x80048E2C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_44;
    // 0x80048E2C: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_44:
L_80048E30:
    // 0x80048E30: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048E34: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80048E38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80048E3C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80048E40: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048E44: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80048E48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048E4C: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80048E50: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80048E54: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80048E58: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80048E5C: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x80048E60: beq         $v1, $v0, L_80049290
    if (ctx->r3 == ctx->r2) {
        // 0x80048E64: nop
    
            goto L_80049290;
    }
    // 0x80048E64: nop

L_80048E68:
    // 0x80048E68: jal         0x80006944
    // 0x80048E6C: nop

    func_80006944(rdram, ctx);
        goto after_45;
    // 0x80048E6C: nop

    after_45:
    // 0x80048E70: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80048E74: jal         0x800067C8
    // 0x80048E78: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_46;
    // 0x80048E78: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_46:
    // 0x80048E7C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80048E80: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048E84: j           L_80049290
    // 0x80048E88: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
        goto L_80049290;
    // 0x80048E88: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_80048E8C:
    // 0x80048E8C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80048E90: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80048E94: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80048E98: bne         $v0, $zero, L_80048EB0
    if (ctx->r2 != 0) {
        // 0x80048E9C: nop
    
            goto L_80048EB0;
    }
    // 0x80048E9C: nop

    // 0x80048EA0: jal         0x8002CFB8
    // 0x80048EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_47;
    // 0x80048EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_47:
    // 0x80048EA8: j           L_80048ED0
    // 0x80048EAC: nop

        goto L_80048ED0;
    // 0x80048EAC: nop

L_80048EB0:
    // 0x80048EB0: bne         $v1, $zero, L_80048EC8
    if (ctx->r3 != 0) {
        // 0x80048EB4: nop
    
            goto L_80048EC8;
    }
    // 0x80048EB4: nop

    // 0x80048EB8: jal         0x8002D378
    // 0x80048EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D378(rdram, ctx);
        goto after_48;
    // 0x80048EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_48:
    // 0x80048EC0: j           L_80048ED0
    // 0x80048EC4: nop

        goto L_80048ED0;
    // 0x80048EC4: nop

L_80048EC8:
    // 0x80048EC8: jal         0x8002D0D4
    // 0x80048ECC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_49;
    // 0x80048ECC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_49:
L_80048ED0:
    // 0x80048ED0: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80048ED4: nop
    
            goto L_80049290;
    }
    // 0x80048ED4: nop

    // 0x80048ED8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048EDC: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80048EE0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80048EE4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80048EE8: lbu         $a0, 0x6AC9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6AC9);
    // 0x80048EEC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048EF0: sb          $zero, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = 0;
    // 0x80048EF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048EF8: bne         $a0, $zero, L_80048F18
    if (ctx->r4 != 0) {
        // 0x80048EFC: sb          $v1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r3;
            goto L_80048F18;
    }
    // 0x80048EFC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80048F00: jal         0x80040438
    // 0x80048F04: nop

    func_80040438(rdram, ctx);
        goto after_50;
    // 0x80048F04: nop

    after_50:
    // 0x80048F08: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048F0C: lh          $v0, 0x6AA4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA4);
    // 0x80048F10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80048F14: sw          $v0, 0x4A24($at)
    MEM_W(0X4A24, ctx->r1) = ctx->r2;
L_80048F18:
    // 0x80048F18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048F1C: sb          $zero, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = 0;
    // 0x80048F20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048F24: j           L_80049290
    // 0x80048F28: sb          $zero, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = 0;
        goto L_80049290;
    // 0x80048F28: sb          $zero, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = 0;
L_80048F2C:
    // 0x80048F2C: jal         0x80044C7C
    // 0x80048F30: nop

    func_80044C7C(rdram, ctx);
        goto after_51;
    // 0x80048F30: nop

    after_51:
    // 0x80048F34: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80048F38: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80048F3C: bne         $v0, $zero, L_80049000
    if (ctx->r2 != 0) {
        // 0x80048F40: nop
    
            goto L_80049000;
    }
    // 0x80048F40: nop

    // 0x80048F44: jal         0x8002D378
    // 0x80048F48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_52;
    // 0x80048F48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_52:
    // 0x80048F4C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80048F50: lb          $v1, -0x467C($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X467C);
    // 0x80048F54: bne         $v1, $zero, L_80048F6C
    if (ctx->r3 != 0) {
        // 0x80048F58: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80048F6C;
    }
    // 0x80048F58: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80048F5C: jal         0x800064C0
    // 0x80048F60: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800064C0(rdram, ctx);
        goto after_53;
    // 0x80048F60: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_53:
    // 0x80048F64: j           L_80048F98
    // 0x80048F68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80048F98;
    // 0x80048F68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80048F6C:
    // 0x80048F6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80048F70: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x80048F74: lb          $v0, 0x4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4);
    // 0x80048F78: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80048F7C: bne         $v0, $zero, L_80048FA0
    if (ctx->r2 != 0) {
        // 0x80048F80: slti        $v0, $v1, 0x28
        ctx->r2 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
            goto L_80048FA0;
    }
    // 0x80048F80: slti        $v0, $v1, 0x28
    ctx->r2 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
    // 0x80048F84: bne         $v0, $zero, L_80048F98
    if (ctx->r2 != 0) {
        // 0x80048F88: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80048F98;
    }
    // 0x80048F88: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80048F8C: jal         0x800067B0
    // 0x80048F90: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800067B0(rdram, ctx);
        goto after_54;
    // 0x80048F90: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_54:
    // 0x80048F94: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80048F98:
    // 0x80048F98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048F9C: sb          $v0, -0x467C($at)
    MEM_B(-0X467C, ctx->r1) = ctx->r2;
L_80048FA0:
    // 0x80048FA0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80048FA4: lb          $v0, -0x467B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X467B);
    // 0x80048FA8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80048FAC: slti        $v0, $v0, 0x28
    ctx->r2 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80048FB0: beq         $v0, $zero, L_80048FC4
    if (ctx->r2 == 0) {
        // 0x80048FB4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80048FC4;
    }
    // 0x80048FB4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80048FB8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048FBC: j           L_80048FD4
    // 0x80048FC0: sb          $v0, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = ctx->r2;
        goto L_80048FD4;
    // 0x80048FC0: sb          $v0, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = ctx->r2;
L_80048FC4:
    // 0x80048FC4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80048FC8: sb          $zero, -0x467B($at)
    MEM_B(-0X467B, ctx->r1) = 0;
    // 0x80048FCC: jal         0x8002D378
    // 0x80048FD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002D378(rdram, ctx);
        goto after_55;
    // 0x80048FD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_55:
L_80048FD4:
    // 0x80048FD4: jal         0x800346F4
    // 0x80048FD8: nop

    func_800346F4(rdram, ctx);
        goto after_56;
    // 0x80048FD8: nop

    after_56:
    // 0x80048FDC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80048FE0: lw          $a0, 0x4A24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4A24);
    // 0x80048FE4: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x80048FE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80048FEC: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80048FF0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80048FF4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80048FF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80048FFC: sh          $a0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r4;
L_80049000:
    // 0x80049000: jal         0x8000B840
    // 0x80049004: nop

    func_8000B840(rdram, ctx);
        goto after_57;
    // 0x80049004: nop

    after_57:
    // 0x80049008: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004900C: lh          $v1, 0x2FAC($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X2FAC);
    // 0x80049010: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80049014: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80049018: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x8004901C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80049290;
    }
    // 0x8004901C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80049020: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049024: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80049028: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004902C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80049030: jal         0x8002D378
    // 0x80049034: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_8002D378(rdram, ctx);
        goto after_58;
    // 0x80049034: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_58:
    // 0x80049038: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004903C: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80049040: bne         $v0, $zero, L_80049050
    if (ctx->r2 != 0) {
        // 0x80049044: nop
    
            goto L_80049050;
    }
    // 0x80049044: nop

    // 0x80049048: jal         0x80006708
    // 0x8004904C: nop

    func_80006708(rdram, ctx);
        goto after_59;
    // 0x8004904C: nop

    after_59:
L_80049050:
    // 0x80049050: jal         0x800064C0
    // 0x80049054: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_60;
    // 0x80049054: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_60:
    // 0x80049058: j           L_80049290
    // 0x8004905C: nop

        goto L_80049290;
    // 0x8004905C: nop

L_80049060:
    // 0x80049060: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049064: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80049068: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8004906C: bne         $v0, $zero, L_80049084
    if (ctx->r2 != 0) {
        // 0x80049070: nop
    
            goto L_80049084;
    }
    // 0x80049070: nop

    // 0x80049074: jal         0x8002CFB8
    // 0x80049078: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_61;
    // 0x80049078: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_61:
    // 0x8004907C: j           L_800490A4
    // 0x80049080: nop

        goto L_800490A4;
    // 0x80049080: nop

L_80049084:
    // 0x80049084: bne         $v1, $zero, L_8004909C
    if (ctx->r3 != 0) {
        // 0x80049088: nop
    
            goto L_8004909C;
    }
    // 0x80049088: nop

    // 0x8004908C: jal         0x8002D378
    // 0x80049090: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D378(rdram, ctx);
        goto after_62;
    // 0x80049090: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_62:
    // 0x80049094: j           L_800490A4
    // 0x80049098: nop

        goto L_800490A4;
    // 0x80049098: nop

L_8004909C:
    // 0x8004909C: jal         0x8002D0D4
    // 0x800490A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002D0D4(rdram, ctx);
        goto after_63;
    // 0x800490A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_63:
L_800490A4:
    // 0x800490A4: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x800490A8: nop
    
            goto L_80049290;
    }
    // 0x800490A8: nop

    // 0x800490AC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800490B0: jal         0x800535B0
    // 0x800490B4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_64;
    // 0x800490B4: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_64:
    // 0x800490B8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800490BC: addiu       $a2, $a2, 0x6ACC
    ctx->r6 = ADD32(ctx->r6, 0X6ACC);
    // 0x800490C0: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x800490C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800490C8: addiu       $a1, $a1, 0x7B71
    ctx->r5 = ADD32(ctx->r5, 0X7B71);
    // 0x800490CC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800490D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800490D4: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x800490D8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800490DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800490E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800490E4: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x800490E8: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800490EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800490F0: jal         0x80043F0C
    // 0x800490F4: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    func_80043F0C(rdram, ctx);
        goto after_65;
    // 0x800490F4: sb          $v1, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = ctx->r3;
    after_65:
    // 0x800490F8: jal         0x800449C0
    // 0x800490FC: nop

    func_800449C0(rdram, ctx);
        goto after_66;
    // 0x800490FC: nop

    after_66:
    // 0x80049100: jal         0x800440FC
    // 0x80049104: nop

    func_800440FC(rdram, ctx);
        goto after_67;
    // 0x80049104: nop

    after_67:
    // 0x80049108: jal         0x80031BEC
    // 0x8004910C: nop

    func_80031BEC(rdram, ctx);
        goto after_68;
    // 0x8004910C: nop

    after_68:
    // 0x80049110: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049114: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x80049118: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004911C: jal         0x80040558
    // 0x80049120: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_80040558(rdram, ctx);
        goto after_69;
    // 0x80049120: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_69:
    // 0x80049124: j           L_80049290
    // 0x80049128: nop

        goto L_80049290;
    // 0x80049128: nop

L_8004912C:
    // 0x8004912C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049130: lbu         $v1, 0x6AC9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6AC9);
    // 0x80049134: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80049138: bne         $v0, $zero, L_80049150
    if (ctx->r2 != 0) {
        // 0x8004913C: nop
    
            goto L_80049150;
    }
    // 0x8004913C: nop

    // 0x80049140: jal         0x8002CFB8
    // 0x80049144: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_70;
    // 0x80049144: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_70:
    // 0x80049148: j           L_80049170
    // 0x8004914C: nop

        goto L_80049170;
    // 0x8004914C: nop

L_80049150:
    // 0x80049150: bne         $v1, $zero, L_80049168
    if (ctx->r3 != 0) {
        // 0x80049154: nop
    
            goto L_80049168;
    }
    // 0x80049154: nop

    // 0x80049158: jal         0x8002D378
    // 0x8004915C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D378(rdram, ctx);
        goto after_71;
    // 0x8004915C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_71:
    // 0x80049160: j           L_80049170
    // 0x80049164: nop

        goto L_80049170;
    // 0x80049164: nop

L_80049168:
    // 0x80049168: jal         0x8002D0D4
    // 0x8004916C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D0D4(rdram, ctx);
        goto after_72;
    // 0x8004916C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_72:
L_80049170:
    // 0x80049170: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80049174: nop
    
            goto L_80049290;
    }
    // 0x80049174: nop

    // 0x80049178: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004917C: lb          $v0, 0x6AC9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC9);
    // 0x80049180: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049184: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80049188: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004918C: lw          $v1, -0x4760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4760);
    // 0x80049190: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049194: lb          $v0, 0x6ACB($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6ACB);
    // 0x80049198: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x8004919C: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800491A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800491A4: lb          $v0, -0x4750($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4750);
    // 0x800491A8: beq         $v1, $v0, L_800491D0
    if (ctx->r3 == ctx->r2) {
        // 0x800491AC: nop
    
            goto L_800491D0;
    }
    // 0x800491AC: nop

    // 0x800491B0: jal         0x80006944
    // 0x800491B4: nop

    func_80006944(rdram, ctx);
        goto after_73;
    // 0x800491B4: nop

    after_73:
    // 0x800491B8: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800491BC: jal         0x800067C8
    // 0x800491C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800067C8(rdram, ctx);
        goto after_74;
    // 0x800491C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_74:
    // 0x800491C4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800491C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800491CC: sb          $v0, -0x4750($at)
    MEM_B(-0X4750, ctx->r1) = ctx->r2;
L_800491D0:
    // 0x800491D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800491D4: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x800491D8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800491DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800491E0: j           L_80049290
    // 0x800491E4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80049290;
    // 0x800491E4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800491E8:
    // 0x800491E8: jal         0x80044C7C
    // 0x800491EC: nop

    func_80044C7C(rdram, ctx);
        goto after_75;
    // 0x800491EC: nop

    after_75:
    // 0x800491F0: jal         0x8000B840
    // 0x800491F4: nop

    func_8000B840(rdram, ctx);
        goto after_76;
    // 0x800491F4: nop

    after_76:
    // 0x800491F8: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800491FC: bne         $v0, $zero, L_80049214
    if (ctx->r2 != 0) {
        // 0x80049200: nop
    
            goto L_80049214;
    }
    // 0x80049200: nop

    // 0x80049204: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80049208: lh          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAC);
    // 0x8004920C: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80049210: nop
    
            goto L_80049290;
    }
    // 0x80049210: nop

L_80049214:
    // 0x80049214: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049218: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
    // 0x8004921C: bne         $v0, $zero, L_80049290
    if (ctx->r2 != 0) {
        // 0x80049220: nop
    
            goto L_80049290;
    }
    // 0x80049220: nop

    // 0x80049224: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049228: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004922C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80049230: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049234: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80049238: jal         0x800064C0
    // 0x8004923C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_77;
    // 0x8004923C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_77:
    // 0x80049240: j           L_80049290
    // 0x80049244: nop

        goto L_80049290;
    // 0x80049244: nop

L_80049248:
    // 0x80049248: jal         0x8002CFB8
    // 0x8004924C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_78;
    // 0x8004924C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_78:
    // 0x80049250: beq         $v0, $zero, L_80049290
    if (ctx->r2 == 0) {
        // 0x80049254: nop
    
            goto L_80049290;
    }
    // 0x80049254: nop

    // 0x80049258: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004925C: jal         0x800535B0
    // 0x80049260: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    func_800535B0(rdram, ctx);
        goto after_79;
    // 0x80049260: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    after_79:
    // 0x80049264: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049268: addiu       $a0, $a0, 0x6ACC
    ctx->r4 = ADD32(ctx->r4, 0X6ACC);
    // 0x8004926C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80049270: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80049274: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049278: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8004927C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049280: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80049284: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80049288: jal         0x80031BEC
    // 0x8004928C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80031BEC(rdram, ctx);
        goto after_80;
    // 0x8004928C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_80:
L_80049290:
    // 0x80049290: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049294: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80049298: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8004929C: beq         $v1, $v0, L_800492E0
    if (ctx->r3 == ctx->r2) {
        // 0x800492A0: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800492E0;
    }
    // 0x800492A0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800492A4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800492A8: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800492AC: bne         $v1, $v0, L_800492CC
    if (ctx->r3 != ctx->r2) {
        // 0x800492B0: nop
    
            goto L_800492CC;
    }
    // 0x800492B0: nop

    // 0x800492B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800492B8: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x800492BC: bne         $v0, $zero, L_800492CC
    if (ctx->r2 != 0) {
        // 0x800492C0: nop
    
            goto L_800492CC;
    }
    // 0x800492C0: nop

    // 0x800492C4: jal         0x800404F4
    // 0x800492C8: nop

    func_800404F4(rdram, ctx);
        goto after_81;
    // 0x800492C8: nop

    after_81:
L_800492CC:
    // 0x800492CC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800492D0: lb          $a0, 0x6AC9($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6AC9);
    // 0x800492D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800492D8: jal         0x8004114C
    // 0x800492DC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    func_8004114C(rdram, ctx);
        goto after_82;
    // 0x800492DC: lb          $a1, 0x6ACB($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6ACB);
    after_82:
L_800492E0:
    // 0x800492E0: jal         0x800448B0
    // 0x800492E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800448B0(rdram, ctx);
        goto after_83;
    // 0x800492E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_83:
    // 0x800492E8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800492EC: addiu       $s0, $s0, 0x6AC9
    ctx->r16 = ADD32(ctx->r16, 0X6AC9);
    // 0x800492F0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800492F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800492F8: lbu         $v1, 0x6ACB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6ACB);
    // 0x800492FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049300: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80049304: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80049308: lw          $a0, -0x47C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X47C8);
    // 0x8004930C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049310: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80049314: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80049318: bne         $v0, $zero, L_80049340
    if (ctx->r2 != 0) {
        // 0x8004931C: nop
    
            goto L_80049340;
    }
    // 0x8004931C: nop

    // 0x80049320: jal         0x80017D38
    // 0x80049324: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_84;
    // 0x80049324: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_84:
    // 0x80049328: jal         0x80017D38
    // 0x8004932C: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_85;
    // 0x8004932C: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_85:
    // 0x80049330: jal         0x80051D6C
    // 0x80049334: nop

    func_80051D6C(rdram, ctx);
        goto after_86;
    // 0x80049334: nop

    after_86:
    // 0x80049338: j           L_80049358
    // 0x8004933C: nop

        goto L_80049358;
    // 0x8004933C: nop

L_80049340:
    // 0x80049340: jal         0x80017D38
    // 0x80049344: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    func_80017D38(rdram, ctx);
        goto after_87;
    // 0x80049344: addiu       $a0, $s0, 0x47
    ctx->r4 = ADD32(ctx->r16, 0X47);
    after_87:
    // 0x80049348: jal         0x80051D6C
    // 0x8004934C: nop

    func_80051D6C(rdram, ctx);
        goto after_88;
    // 0x8004934C: nop

    after_88:
    // 0x80049350: jal         0x80017D38
    // 0x80049354: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    func_80017D38(rdram, ctx);
        goto after_89;
    // 0x80049354: addiu       $a0, $s0, -0x29
    ctx->r4 = ADD32(ctx->r16, -0X29);
    after_89:
L_80049358:
    // 0x80049358: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004935C: addiu       $a0, $a0, 0x6AC9
    ctx->r4 = ADD32(ctx->r4, 0X6AC9);
    // 0x80049360: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80049364: beq         $v0, $zero, L_8004938C
    if (ctx->r2 == 0) {
        // 0x80049368: nop
    
            goto L_8004938C;
    }
    // 0x80049368: nop

    // 0x8004936C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049370: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80049374: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80049378: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004937C: beq         $v0, $zero, L_8004938C
    if (ctx->r2 == 0) {
        // 0x80049380: nop
    
            goto L_8004938C;
    }
    // 0x80049380: nop

    // 0x80049384: jal         0x80017D38
    // 0x80049388: addiu       $a0, $a0, 0xB7
    ctx->r4 = ADD32(ctx->r4, 0XB7);
    func_80017D38(rdram, ctx);
        goto after_90;
    // 0x80049388: addiu       $a0, $a0, 0xB7
    ctx->r4 = ADD32(ctx->r4, 0XB7);
    after_90:
L_8004938C:
    // 0x8004938C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80049390: lh          $v0, 0x2FAE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2FAE);
    // 0x80049394: beq         $v0, $zero, L_800493A4
    if (ctx->r2 == 0) {
        // 0x80049398: nop
    
            goto L_800493A4;
    }
    // 0x80049398: nop

    // 0x8004939C: jal         0x800533F0
    // 0x800493A0: nop

    func_800533F0(rdram, ctx);
        goto after_91;
    // 0x800493A0: nop

    after_91:
L_800493A4:
    // 0x800493A4: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800493A8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800493AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800493B0: jr          $ra
    // 0x800493B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800493B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800493C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493C0: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800493C4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800493C8: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x800493CC: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800493D0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800493D4: addiu       $v1, $v1, 0x4A38
    ctx->r3 = ADD32(ctx->r3, 0X4A38);
    // 0x800493D8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800493DC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800493E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800493E4: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800493E8: addiu       $a3, $zero, -0x140
    ctx->r7 = ADD32(0, -0X140);
    // 0x800493EC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x800493F0: andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
L_800493F4:
    // 0x800493F4: beq         $v0, $zero, L_8004940C
    if (ctx->r2 == 0) {
        // 0x800493F8: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_8004940C;
    }
    // 0x800493F8: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x800493FC: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80049400: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049404: j           L_80049418
    // 0x80049408: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
        goto L_80049418;
    // 0x80049408: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
L_8004940C:
    // 0x8004940C: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80049410: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049414: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80049418:
    // 0x80049418: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8004941C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80049420: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80049424: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049428: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004942C: bne         $v0, $zero, L_800493F4
    if (ctx->r2 != 0) {
        // 0x80049430: andi        $v0, $a2, 0x1
        ctx->r2 = ctx->r6 & 0X1;
            goto L_800493F4;
    }
    // 0x80049430: andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // 0x80049434: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80049438: sll         $v0, $t0, 24
    ctx->r2 = S32(ctx->r8 << 24);
    // 0x8004943C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049440: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049444: addiu       $v1, $v1, 0x4A68
    ctx->r3 = ADD32(ctx->r3, 0X4A68);
    // 0x80049448: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x8004944C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80049450: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80049454: addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // 0x80049458: sll         $v1, $a1, 24
    ctx->r3 = S32(ctx->r5 << 24);
    // 0x8004945C: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80049460: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049464: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049468: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8004946C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049470: addiu       $v0, $v0, 0x4A98
    ctx->r2 = ADD32(ctx->r2, 0X4A98);
    // 0x80049474: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x80049478: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8004947C: addiu       $a3, $a3, 0x984
    ctx->r7 = ADD32(ctx->r7, 0X984);
    // 0x80049480: addiu       $t3, $a3, 0x4
    ctx->r11 = ADD32(ctx->r7, 0X4);
L_80049484:
    // 0x80049484: sll         $a0, $a2, 24
    ctx->r4 = S32(ctx->r6 << 24);
    // 0x80049488: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004948C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80049490: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80049494: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80049498: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x8004949C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800494A0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800494A4: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x800494A8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800494AC: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800494B0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800494B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800494B8: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800494BC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800494C0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800494C4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800494C8: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800494CC: bne         $v0, $zero, L_80049484
    if (ctx->r2 != 0) {
        // 0x800494D0: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_80049484;
    }
    // 0x800494D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800494D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800494D8: jr          $ra
    // 0x800494DC: sb          $zero, 0x4A34($at)
    MEM_B(0X4A34, ctx->r1) = 0;
    return;
    // 0x800494DC: sb          $zero, 0x4A34($at)
    MEM_B(0X4A34, ctx->r1) = 0;
;}
