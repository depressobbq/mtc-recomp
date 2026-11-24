#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80058258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005825C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80058260: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80058264: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80058268: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8005826C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80058270: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80058274: addiu       $a0, $a0, 0x5FA0
    ctx->r4 = ADD32(ctx->r4, 0X5FA0);
    // 0x80058278: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8005827C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80058280: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80058284: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80058288: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8005828C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80058290: bne         $v0, $a3, L_800582E4
    if (ctx->r2 != ctx->r7) {
        // 0x80058294: ori         $v1, $v1, 0x2
        ctx->r3 = ctx->r3 | 0X2;
            goto L_800582E4;
    }
    // 0x80058294: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80058298: sra         $v0, $a2, 6
    ctx->r2 = S32(SIGNED(ctx->r6) >> 6);
    // 0x8005829C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800582A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800582A4: ori         $v0, $v0, 0x7
    ctx->r2 = ctx->r2 | 0X7;
    // 0x800582A8: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800582AC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800582B0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800582B4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800582B8: sra         $v0, $v0, 6
    ctx->r2 = S32(SIGNED(ctx->r2) >> 6);
    // 0x800582BC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800582C0: ori         $v0, $v0, 0x7
    ctx->r2 = ctx->r2 | 0X7;
    // 0x800582C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800582C8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800582CC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800582D0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800582D4: jal         0x80057E74
    // 0x800582D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80057E74(rdram, ctx);
        goto after_0;
    // 0x800582D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800582DC: j           L_800582E8
    // 0x800582E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800582E8;
    // 0x800582E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800582E4:
    // 0x800582E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800582E8:
    // 0x800582E8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800582EC: jr          $ra
    // 0x800582F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800582F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80058300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058300: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058304: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058308: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005830C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058310: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058314: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058318: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x8005831C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058320: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80058324: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058328: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x8005832C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058330: sh          $zero, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = 0;
    // 0x80058334: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058338: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x8005833C: j           L_80058344
    // 0x80058340: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80058344;
    // 0x80058340: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80058344:
    // 0x80058344: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058348: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005834C: jr          $ra
    // 0x80058350: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058350: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058354: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058358: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005835C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058360: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058364: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058368: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005836C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058370: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058374: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058378: sh          $v0, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r2;
    // 0x8005837C: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x80058380: andi        $v1, $v0, 0x80
    ctx->r3 = ctx->r2 & 0X80;
    // 0x80058384: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80058388: beq         $v0, $zero, L_800583C4
    if (ctx->r2 == 0) {
        // 0x8005838C: nop
    
            goto L_800583C4;
    }
    // 0x8005838C: nop

    // 0x80058390: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x80058394: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80058398: sh          $v1, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r3;
    // 0x8005839C: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x800583A0: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x800583A4: sh          $v1, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r3;
    // 0x800583A8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x800583AC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800583B0: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x800583B4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800583B8: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x800583BC: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x800583C0: sh          $v0, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r2;
L_800583C4:
    // 0x800583C4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800583C8: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x800583CC: sh          $v1, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r3;
    // 0x800583D0: j           L_800583D8
    // 0x800583D4: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_800583D8;
    // 0x800583D4: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_800583D8:
    // 0x800583D8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800583DC: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x800583E0: jr          $ra
    // 0x800583E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800583E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800583E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800583E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800583EC: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800583F0: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800583F4: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800583F8: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800583FC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058400: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80058404: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058408: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x8005840C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058410: sb          $v1, 0xB0($v0)
    MEM_B(0XB0, ctx->r2) = ctx->r3;
    // 0x80058414: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058418: lbu         $v1, 0xB0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB0);
    // 0x8005841C: beq         $v1, $zero, L_80058434
    if (ctx->r3 == 0) {
        // 0x80058420: nop
    
            goto L_80058434;
    }
    // 0x80058420: nop

    // 0x80058424: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058428: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005842C: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80058430: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
L_80058434:
    // 0x80058434: j           L_8005843C
    // 0x80058438: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_8005843C;
    // 0x80058438: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_8005843C:
    // 0x8005843C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058440: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058444: jr          $ra
    // 0x80058448: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058448: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005844C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005844C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058450: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058454: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058458: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x8005845C: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058460: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058464: sb          $zero, 0xB0($v0)
    MEM_B(0XB0, ctx->r2) = 0;
    // 0x80058468: j           L_80058470
    // 0x8005846C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058470;
    // 0x8005846C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058470:
    // 0x80058470: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058474: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058478: jr          $ra
    // 0x8005847C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005847C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058480: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058484: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058488: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005848C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058490: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058494: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058498: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005849C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x800584A0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800584A4: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x800584A8: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x800584AC: bne         $v0, $zero, L_800584BC
    if (ctx->r2 != 0) {
        // 0x800584B0: nop
    
            goto L_800584BC;
    }
    // 0x800584B0: nop

    // 0x800584B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800584B8: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
L_800584BC:
    // 0x800584BC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800584C0: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x800584C4: sb          $v1, 0xB7($v0)
    MEM_B(0XB7, ctx->r2) = ctx->r3;
    // 0x800584C8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800584CC: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x800584D0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x800584D4: div         $zero, $a0, $v1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r3)));
    // 0x800584D8: bne         $v1, $zero, L_800584E4
    if (ctx->r3 != 0) {
        // 0x800584DC: nop
    
            goto L_800584E4;
    }
    // 0x800584DC: nop

    // 0x800584E0: break       7
    do_break(2147845344);
L_800584E4:
    // 0x800584E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800584E8: bne         $v1, $at, L_800584FC
    if (ctx->r3 != ctx->r1) {
        // 0x800584EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800584FC;
    }
    // 0x800584EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800584F0: bne         $a0, $at, L_800584FC
    if (ctx->r4 != ctx->r1) {
        // 0x800584F4: nop
    
            goto L_800584FC;
    }
    // 0x800584F4: nop

    // 0x800584F8: break       6
    do_break(2147845368);
L_800584FC:
    // 0x800584FC: mflo        $v1
    ctx->r3 = lo;
    // 0x80058500: sw          $v1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r3;
    // 0x80058504: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058508: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005850C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058510: sw          $a0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r4;
    // 0x80058514: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058518: sb          $v1, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r3;
    // 0x8005851C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058520: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058524: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058528: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005852C: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x80058530: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058534: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80058538: sb          $v1, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r3;
    // 0x8005853C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058540: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x80058544: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058548: sw          $a0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r4;
    // 0x8005854C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058550: sb          $v1, 0xB9($v0)
    MEM_B(0XB9, ctx->r2) = ctx->r3;
    // 0x80058554: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058558: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005855C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80058560: nop

    // 0x80058564: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058568: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005856C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80058570: ldc1        $f4, -0x12D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12D0);
    // 0x80058574: div.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80058578: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005857C: lbu         $v1, 0xB9($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XB9);
    // 0x80058580: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80058584: lbu         $a1, 0xB8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0XB8);
    // 0x80058588: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8005858C: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x80058590: nop

    // 0x80058594: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80058598: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005859C: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800585A0: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x800585A4: swc1        $f2, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f2.u32l;
    // 0x800585A8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x800585AC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800585B0: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x800585B4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800585B8: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x800585BC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800585C0: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x800585C4: sb          $v1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r3;
    // 0x800585C8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800585CC: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x800585D0: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800585D4: sw          $a0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r4;
    // 0x800585D8: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800585DC: sb          $v1, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = ctx->r3;
    // 0x800585E0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800585E4: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x800585E8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800585EC: nop

    // 0x800585F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800585F4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800585F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800585FC: ldc1        $f4, -0x12C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12C8);
    // 0x80058600: div.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80058604: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80058608: lbu         $v1, 0xBA($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XBA);
    // 0x8005860C: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80058610: lbu         $a1, 0xB9($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0XB9);
    // 0x80058614: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80058618: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8005861C: nop

    // 0x80058620: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80058624: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80058628: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x8005862C: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x80058630: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80058634: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058638: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005863C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058640: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058644: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x80058648: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005864C: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80058650: sb          $v1, 0xC0($v0)
    MEM_B(0XC0, ctx->r2) = ctx->r3;
    // 0x80058654: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058658: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005865C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80058660: nop

    // 0x80058664: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058668: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005866C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80058670: ldc1        $f4, -0x12C0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12C0);
    // 0x80058674: div.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80058678: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005867C: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80058680: j           L_80058688
    // 0x80058684: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80058688;
    // 0x80058684: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80058688:
    // 0x80058688: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005868C: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80058690: jr          $ra
    // 0x80058694: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80058694: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80058698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058698: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005869C: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x800586A0: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800586A4: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x800586A8: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x800586AC: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x800586B0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800586B4: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x800586B8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800586BC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800586C0: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800586C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800586C8: sll         $v0, $v1, 13
    ctx->r2 = S32(ctx->r3 << 13);
    // 0x800586CC: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x800586D0: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x800586D4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800586D8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800586DC: sw          $a2, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r6;
    // 0x800586E0: lw          $a2, 0x14($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X14);
    // 0x800586E4: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x800586E8: sra         $a0, $v1, 6
    ctx->r4 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800586EC: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800586F0: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x800586F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800586F8: lw          $v1, -0x42C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X42C4);
    // 0x800586FC: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80058700: bne         $v1, $zero, L_8005870C
    if (ctx->r3 != 0) {
        // 0x80058704: nop
    
            goto L_8005870C;
    }
    // 0x80058704: nop

    // 0x80058708: break       7
    do_break(2147845896);
L_8005870C:
    // 0x8005870C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058710: bne         $v1, $at, L_80058724
    if (ctx->r3 != ctx->r1) {
        // 0x80058714: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80058724;
    }
    // 0x80058714: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80058718: bne         $v0, $at, L_80058724
    if (ctx->r2 != ctx->r1) {
        // 0x8005871C: nop
    
            goto L_80058724;
    }
    // 0x8005871C: nop

    // 0x80058720: break       6
    do_break(2147845920);
L_80058724:
    // 0x80058724: mflo        $v0
    ctx->r2 = lo;
    // 0x80058728: sw          $v0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r2;
    // 0x8005872C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80058730: lh          $v1, 0x90($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X90);
    // 0x80058734: lw          $a0, 0x8($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X8);
    // 0x80058738: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005873C: mflo        $v0
    ctx->r2 = lo;
    // 0x80058740: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80058744: sw          $v1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r3;
    // 0x80058748: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005874C: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x80058750: beq         $v1, $zero, L_80058768
    if (ctx->r3 == 0) {
        // 0x80058754: nop
    
            goto L_80058768;
    }
    // 0x80058754: nop

    // 0x80058758: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005875C: lhu         $v1, 0xA($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XA);
    // 0x80058760: j           L_800587EC
    // 0x80058764: sh          $v1, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r3;
        goto L_800587EC;
    // 0x80058764: sh          $v1, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r3;
L_80058768:
    // 0x80058768: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005876C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80058770: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x80058774: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_80058778:
    // 0x80058778: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005877C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80058780: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x80058784: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058788: bne         $v0, $zero, L_80058798
    if (ctx->r2 != 0) {
        // 0x8005878C: nop
    
            goto L_80058798;
    }
    // 0x8005878C: nop

    // 0x80058790: j           L_800587EC
    // 0x80058794: nop

        goto L_800587EC;
    // 0x80058794: nop

L_80058798:
    // 0x80058798: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005879C: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x800587A0: lw          $v0, 0x70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70);
    // 0x800587A4: lw          $v1, 0x70($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X70);
    // 0x800587A8: bne         $v0, $v1, L_800587C8
    if (ctx->r2 != ctx->r3) {
        // 0x800587AC: nop
    
            goto L_800587C8;
    }
    // 0x800587AC: nop

    // 0x800587B0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800587B4: lhu         $v1, 0xA($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XA);
    // 0x800587B8: sh          $v1, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r3;
    // 0x800587BC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800587C0: lhu         $v1, 0xE($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XE);
    // 0x800587C4: sh          $v1, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r3;
L_800587C8:
    // 0x800587C8: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x800587CC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800587D0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800587D4: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x800587D8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800587DC: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x800587E0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800587E4: j           L_80058778
    // 0x800587E8: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_80058778;
    // 0x800587E8: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_800587EC:
    // 0x800587EC: j           L_800587F4
    // 0x800587F0: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
        goto L_800587F4;
    // 0x800587F0: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
L_800587F4:
    // 0x800587F4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800587F8: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x800587FC: jr          $ra
    // 0x80058800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80058800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80058804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058804: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058808: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x8005880C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058810: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058814: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058818: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005881C: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80058820: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058824: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80058828: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8005882C: sh          $v1, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r3;
    // 0x80058830: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058834: sh          $zero, 0xAA($v0)
    MEM_H(0XAA, ctx->r2) = 0;
    // 0x80058838: j           L_80058840
    // 0x8005883C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058840;
    // 0x8005883C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058840:
    // 0x80058840: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058844: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058848: jr          $ra
    // 0x8005884C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005884C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058850: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058854: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058858: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005885C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058860: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058864: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058868: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005886C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058870: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058874: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x80058878: sh          $v1, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r3;
    // 0x8005887C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058880: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058884: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058888: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005888C: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x80058890: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x80058894: sh          $v0, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r2;
    // 0x80058898: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005889C: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x800588A0: sh          $v1, 0xAA($v0)
    MEM_H(0XAA, ctx->r2) = ctx->r3;
    // 0x800588A4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800588A8: sh          $zero, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = 0;
    // 0x800588AC: j           L_800588B4
    // 0x800588B0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_800588B4;
    // 0x800588B0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_800588B4:
    // 0x800588B4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800588B8: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x800588BC: jr          $ra
    // 0x800588C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800588C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800588C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800588C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800588C8: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800588CC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800588D0: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800588D4: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800588D8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800588DC: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800588E0: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800588E4: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x800588E8: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800588EC: sb          $v1, 0xAE($v0)
    MEM_B(0XAE, ctx->r2) = ctx->r3;
    // 0x800588F0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800588F4: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800588F8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800588FC: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80058900: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058904: sb          $v1, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r3;
    // 0x80058908: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005890C: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80058910: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058914: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80058918: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8005891C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80058920: nop

    // 0x80058924: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058928: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005892C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80058930: ldc1        $f4, -0x12B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12B8);
    // 0x80058934: div.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = DIV_D(ctx->f2.d, ctx->f4.d);
    // 0x80058938: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005893C: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80058940: j           L_80058948
    // 0x80058944: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058948;
    // 0x80058944: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058948:
    // 0x80058948: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005894C: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058950: jr          $ra
    // 0x80058954: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058954: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058958: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005895C: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058960: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058964: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058968: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x8005896C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058970: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80058974: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058978: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x8005897C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058980: sb          $v1, 0xAE($v0)
    MEM_B(0XAE, ctx->r2) = ctx->r3;
    // 0x80058984: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058988: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005898C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058990: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80058994: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058998: sb          $v1, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r3;
    // 0x8005899C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800589A0: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800589A4: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800589A8: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x800589AC: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800589B0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800589B4: nop

    // 0x800589B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800589BC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800589C0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800589C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800589C8: ldc1        $f2, -0x12B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X12B0);
    // 0x800589CC: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x800589D0: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x800589D4: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x800589D8: j           L_800589E0
    // 0x800589DC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800589E0;
    // 0x800589DC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800589E0:
    // 0x800589E0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800589E4: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800589E8: jr          $ra
    // 0x800589EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800589EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800589F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800589F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800589F4: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800589F8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800589FC: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058A00: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058A04: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058A08: sb          $zero, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = 0;
    // 0x80058A0C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058A10: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x80058A14: j           L_80058A1C
    // 0x80058A18: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058A1C;
    // 0x80058A18: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058A1C:
    // 0x80058A1C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058A20: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058A24: jr          $ra
    // 0x80058A28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058A28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058A2C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058A30: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058A34: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058A38: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058A3C: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058A40: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058A44: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058A48: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058A4C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058A50: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x80058A54: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x80058A58: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x80058A5C: beq         $v1, $zero, L_80058A74
    if (ctx->r3 == 0) {
        // 0x80058A60: nop
    
            goto L_80058A74;
    }
    // 0x80058A60: nop

    // 0x80058A64: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058A68: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80058A6C: j           L_80058AB4
    // 0x80058A70: sh          $v1, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r3;
        goto L_80058AB4;
    // 0x80058A70: sh          $v1, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r3;
L_80058A74:
    // 0x80058A74: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058A78: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80058A7C: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x80058A80: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80058A84: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058A88: sll         $v1, $a0, 8
    ctx->r3 = S32(ctx->r4 << 8);
    // 0x80058A8C: sh          $v1, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r3;
    // 0x80058A90: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058A94: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058A98: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x80058A9C: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x80058AA0: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058AA4: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x80058AA8: lhu         $v1, 0xA4($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0XA4);
    // 0x80058AAC: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x80058AB0: sh          $a0, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r4;
L_80058AB4:
    // 0x80058AB4: j           L_80058ABC
    // 0x80058AB8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80058ABC;
    // 0x80058AB8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80058ABC:
    // 0x80058ABC: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058AC0: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80058AC4: jr          $ra
    // 0x80058AC8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80058AC8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80058ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058ACC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058AD0: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058AD4: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058AD8: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058ADC: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058AE0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058AE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80058AE8: sb          $v1, 0xAF($v0)
    MEM_B(0XAF, ctx->r2) = ctx->r3;
    // 0x80058AEC: j           L_80058AF4
    // 0x80058AF0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058AF4;
    // 0x80058AF0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058AF4:
    // 0x80058AF4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058AF8: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058AFC: jr          $ra
    // 0x80058B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058B08: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058B0C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058B10: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058B14: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058B18: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058B1C: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80058B20: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058B24: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80058B28: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058B2C: sb          $v1, 0xB1($v0)
    MEM_B(0XB1, ctx->r2) = ctx->r3;
    // 0x80058B30: j           L_80058B38
    // 0x80058B34: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058B38;
    // 0x80058B34: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058B38:
    // 0x80058B38: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058B3C: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058B40: jr          $ra
    // 0x80058B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058B44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058B4C: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058B50: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058B54: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058B58: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058B5C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058B60: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80058B64: sb          $v1, 0xB2($v0)
    MEM_B(0XB2, ctx->r2) = ctx->r3;
    // 0x80058B68: j           L_80058B70
    // 0x80058B6C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058B70;
    // 0x80058B6C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058B70:
    // 0x80058B70: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058B74: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058B78: jr          $ra
    // 0x80058B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B80: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058B84: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058B88: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058B8C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058B90: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058B94: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058B98: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058B9C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80058BA0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058BA4: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x80058BA8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058BAC: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80058BB0: beq         $v0, $zero, L_80058BC8
    if (ctx->r2 == 0) {
        // 0x80058BB4: nop
    
            goto L_80058BC8;
    }
    // 0x80058BB4: nop

    // 0x80058BB8: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x80058BBC: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x80058BC0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80058BC4: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_80058BC8:
    // 0x80058BC8: lwc1        $f0, 0x0($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80058BCC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058BD0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80058BD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80058BD8: ldc1        $f4, -0x12A8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12A8);
    // 0x80058BDC: div.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = DIV_D(ctx->f2.d, ctx->f4.d);
    // 0x80058BE0: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x80058BE4: swc1        $f2, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->f2.u32l;
    // 0x80058BE8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058BEC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058BF0: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80058BF4: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80058BF8: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80058BFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80058C00: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80058C04: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058C08: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058C0C: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80058C10: lwc1        $f2, 0x4($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X4);
    // 0x80058C14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80058C18: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80058C1C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058C20: lwc1        $f0, 0x4($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X4);
    // 0x80058C24: swc1        $f0, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f0.u32l;
    // 0x80058C28: j           L_80058C30
    // 0x80058C2C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80058C30;
    // 0x80058C2C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80058C30:
    // 0x80058C30: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058C34: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80058C38: jr          $ra
    // 0x80058C3C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80058C3C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80058C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058C40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058C48: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x80058C4C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058C50: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x80058C54: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x80058C58: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80058C5C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058C60: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x80058C64: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058C68: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x80058C6C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058C70: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80058C74: beq         $v0, $zero, L_80058CB0
    if (ctx->r2 == 0) {
        // 0x80058C78: nop
    
            goto L_80058CB0;
    }
    // 0x80058C78: nop

    // 0x80058C7C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058C80: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80058C84: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
    // 0x80058C88: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058C8C: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x80058C90: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
    // 0x80058C94: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80058C98: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80058C9C: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x80058CA0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80058CA4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058CA8: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x80058CAC: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_80058CB0:
    // 0x80058CB0: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x80058CB4: lw          $v0, 0x70($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X70);
    // 0x80058CB8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058CBC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80058CC0: sll         $a0, $a1, 3
    ctx->r4 = S32(ctx->r5 << 3);
    // 0x80058CC4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80058CC8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80058CCC: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x80058CD0: lw          $a0, 0x20($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X20);
    // 0x80058CD4: jal         0x80058480
    // 0x80058CD8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80058480(rdram, ctx);
        goto after_0;
    // 0x80058CD8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80058CDC: j           L_80058CE4
    // 0x80058CE0: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
        goto L_80058CE4;
    // 0x80058CE0: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
L_80058CE4:
    // 0x80058CE4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058CEC: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x80058CF0: jr          $ra
    // 0x80058CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80058CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80058CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058CF8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058CFC: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058D00: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058D04: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058D08: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058D0C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058D10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80058D14: sb          $v1, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r3;
    // 0x80058D18: j           L_80058D20
    // 0x80058D1C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058D20;
    // 0x80058D1C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058D20:
    // 0x80058D20: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058D24: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058D28: jr          $ra
    // 0x80058D2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058D2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058D34: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058D38: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058D3C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058D40: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058D44: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058D48: sb          $zero, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = 0;
    // 0x80058D4C: j           L_80058D54
    // 0x80058D50: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058D54;
    // 0x80058D50: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058D54:
    // 0x80058D54: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058D58: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058D5C: jr          $ra
    // 0x80058D60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058D60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D64: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058D68: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058D6C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058D70: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058D74: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058D78: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058D7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80058D80: sb          $v1, 0xCF($v0)
    MEM_B(0XCF, ctx->r2) = ctx->r3;
    // 0x80058D84: j           L_80058D8C
    // 0x80058D88: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058D8C;
    // 0x80058D88: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058D8C:
    // 0x80058D8C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058D90: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058D94: jr          $ra
    // 0x80058D98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058D98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D9C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80058DA0: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80058DA4: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058DA8: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80058DAC: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80058DB0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80058DB4: sb          $zero, 0xCF($v0)
    MEM_B(0XCF, ctx->r2) = 0;
    // 0x80058DB8: j           L_80058DC0
    // 0x80058DBC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80058DC0;
    // 0x80058DBC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80058DC0:
    // 0x80058DC0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058DC4: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80058DC8: jr          $ra
    // 0x80058DCC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80058DCC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80058DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058DD0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058DD4: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058DD8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058DDC: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058DE0: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058DE4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058DE8: lbu         $v1, 0xD3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD3);
    // 0x80058DEC: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x80058DF0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058DF4: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80058DF8: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80058DFC: addiu       $v0, $v1, 0x114
    ctx->r2 = ADD32(ctx->r3, 0X114);
    // 0x80058E00: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x80058E04: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80058E08: sw          $a0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r4;
    // 0x80058E0C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80058E10: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80058E14: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058E18: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058E1C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058E20: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80058E24: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80058E28: addiu       $v1, $v0, 0xD4
    ctx->r3 = ADD32(ctx->r2, 0XD4);
    // 0x80058E2C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80058E30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80058E34: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058E38: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058E3C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058E40: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80058E44: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80058E48: addiu       $v0, $a0, 0xE4
    ctx->r2 = ADD32(ctx->r4, 0XE4);
    // 0x80058E4C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058E50: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x80058E54: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80058E58: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058E5C: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058E60: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058E64: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80058E68: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80058E6C: addiu       $v0, $a0, 0xF4
    ctx->r2 = ADD32(ctx->r4, 0XF4);
    // 0x80058E70: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058E74: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
    // 0x80058E78: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80058E7C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058E80: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80058E84: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80058E88: addiu       $v0, $v1, 0x118
    ctx->r2 = ADD32(ctx->r3, 0X118);
    // 0x80058E8C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058E90: lbu         $a0, 0xB4($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB4);
    // 0x80058E94: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80058E98: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058E9C: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80058EA0: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80058EA4: addiu       $v0, $v1, 0x11C
    ctx->r2 = ADD32(ctx->r3, 0X11C);
    // 0x80058EA8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058EAC: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x80058EB0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80058EB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80058EB8: nop

    // 0x80058EBC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80058EC0: nop

    // 0x80058EC4: bc1t        L_80058EDC
    if (c1cs) {
        // 0x80058EC8: nop
    
            goto L_80058EDC;
    }
    // 0x80058EC8: nop

    // 0x80058ECC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058ED0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80058ED4: j           L_80058EF4
    // 0x80058ED8: nop

        goto L_80058EF4;
    // 0x80058ED8: nop

L_80058EDC:
    // 0x80058EDC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80058EE0: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80058EE4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058EE8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80058EEC: nop

    // 0x80058EF0: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
L_80058EF4:
    // 0x80058EF4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80058EF8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058EFC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058F00: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058F04: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80058F08: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80058F0C: addiu       $v0, $a0, 0x104
    ctx->r2 = ADD32(ctx->r4, 0X104);
    // 0x80058F10: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058F14: lhu         $a0, 0x9A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9A);
    // 0x80058F18: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80058F1C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058F20: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058F24: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058F28: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80058F2C: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80058F30: addiu       $v0, $a0, 0x10C
    ctx->r2 = ADD32(ctx->r4, 0X10C);
    // 0x80058F34: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058F38: lhu         $a0, 0x9C($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9C);
    // 0x80058F3C: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80058F40: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058F44: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058F48: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058F4C: lbu         $a0, 0xD3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD3);
    // 0x80058F50: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80058F54: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80058F58: sb          $a0, 0xD3($v0)
    MEM_B(0XD3, ctx->r2) = ctx->r4;
    // 0x80058F5C: j           L_80058F64
    // 0x80058F60: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80058F64;
    // 0x80058F60: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80058F64:
    // 0x80058F64: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80058F68: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80058F6C: jr          $ra
    // 0x80058F70: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80058F70: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80058F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058F74: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80058F78: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80058F7C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80058F80: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80058F84: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80058F88: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058F8C: lbu         $v1, 0xD3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD3);
    // 0x80058F90: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80058F94: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x80058F98: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058F9C: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80058FA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80058FA4: addiu       $v1, $v0, 0x114
    ctx->r3 = ADD32(ctx->r2, 0X114);
    // 0x80058FA8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80058FAC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80058FB0: beq         $v0, $v1, L_80059018
    if (ctx->r2 == ctx->r3) {
        // 0x80058FB4: nop
    
            goto L_80059018;
    }
    // 0x80058FB4: nop

    // 0x80058FB8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80058FBC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80058FC0: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80058FC4: addiu       $v0, $v1, 0x114
    ctx->r2 = ADD32(ctx->r3, 0X114);
    // 0x80058FC8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058FCC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x80058FD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80058FD4: addiu       $v0, $v1, 0x114
    ctx->r2 = ADD32(ctx->r3, 0X114);
    // 0x80058FD8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80058FDC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80058FE0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80058FE4: addiu       $a0, $v1, 0x114
    ctx->r4 = ADD32(ctx->r3, 0X114);
    // 0x80058FE8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80058FEC: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x80058FF0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80058FF4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80058FF8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80058FFC: bne         $v0, $zero, L_80059018
    if (ctx->r2 != 0) {
        // 0x80059000: nop
    
            goto L_80059018;
    }
    // 0x80059000: nop

    // 0x80059004: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059008: lbu         $v1, 0x3($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X3);
    // 0x8005900C: sb          $v1, 0xD3($v0)
    MEM_B(0XD3, ctx->r2) = ctx->r3;
    // 0x80059010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80059014: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_80059018:
    // 0x80059018: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005901C: slti        $v1, $v0, 0x0
    ctx->r3 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80059020: bne         $v1, $zero, L_80059138
    if (ctx->r3 != 0) {
        // 0x80059024: nop
    
            goto L_80059138;
    }
    // 0x80059024: nop

    // 0x80059028: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005902C: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80059030: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80059034: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80059038: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8005903C: addiu       $v1, $v0, 0xD4
    ctx->r3 = ADD32(ctx->r2, 0XD4);
    // 0x80059040: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80059044: sw          $v0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r2;
    // 0x80059048: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005904C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059050: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80059054: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80059058: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005905C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80059060: addiu       $a0, $v1, 0xE4
    ctx->r4 = ADD32(ctx->r3, 0XE4);
    // 0x80059064: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059068: sw          $v1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r3;
    // 0x8005906C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059070: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059074: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80059078: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005907C: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80059080: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80059084: addiu       $a0, $v1, 0xF4
    ctx->r4 = ADD32(ctx->r3, 0XF4);
    // 0x80059088: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005908C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80059090: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059094: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059098: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x8005909C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800590A0: addiu       $a0, $v1, 0x118
    ctx->r4 = ADD32(ctx->r3, 0X118);
    // 0x800590A4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800590A8: sb          $v1, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r3;
    // 0x800590AC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800590B0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x800590B4: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800590B8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800590BC: addiu       $a0, $v1, 0x11C
    ctx->r4 = ADD32(ctx->r3, 0X11C);
    // 0x800590C0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800590C4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800590C8: nop

    // 0x800590CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800590D0: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x800590D4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800590D8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x800590DC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800590E0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800590E4: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x800590E8: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800590EC: addiu       $a0, $v1, 0x104
    ctx->r4 = ADD32(ctx->r3, 0X104);
    // 0x800590F0: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800590F4: sh          $v1, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r3;
    // 0x800590F8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800590FC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059100: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80059104: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80059108: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8005910C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80059110: addiu       $a0, $v1, 0x10C
    ctx->r4 = ADD32(ctx->r3, 0X10C);
    // 0x80059114: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80059118: sh          $v1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r3;
    // 0x8005911C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059120: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059124: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059128: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8005912C: lwc1        $f2, 0x68($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80059130: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059134: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
L_80059138:
    // 0x80059138: j           L_80059140
    // 0x8005913C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80059140;
    // 0x8005913C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80059140:
    // 0x80059140: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059144: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80059148: jr          $ra
    // 0x8005914C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005914C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80059150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059150: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059154: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059158: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005915C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059160: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059164: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059168: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005916C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059170: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80059174: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059178: sb          $v1, 0xD0($v0)
    MEM_B(0XD0, ctx->r2) = ctx->r3;
    // 0x8005917C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059180: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80059184: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059188: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x8005918C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059190: sb          $v1, 0xC6($v0)
    MEM_B(0XC6, ctx->r2) = ctx->r3;
    // 0x80059194: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059198: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005919C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800591A0: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x800591A4: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800591A8: sb          $v1, 0xC7($v0)
    MEM_B(0XC7, ctx->r2) = ctx->r3;
    // 0x800591AC: j           L_800591B4
    // 0x800591B0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800591B4;
    // 0x800591B0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800591B4:
    // 0x800591B4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800591B8: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800591BC: jr          $ra
    // 0x800591C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800591C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800591C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800591C8: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800591CC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800591D0: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800591D4: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800591D8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800591DC: sb          $zero, 0xC6($v0)
    MEM_B(0XC6, ctx->r2) = 0;
    // 0x800591E0: j           L_800591E8
    // 0x800591E4: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800591E8;
    // 0x800591E4: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800591E8:
    // 0x800591E8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800591EC: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800591F0: jr          $ra
    // 0x800591F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800591F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800591F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800591FC: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059200: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059204: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059208: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x8005920C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059210: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80059214: sb          $v1, 0xCA($v0)
    MEM_B(0XCA, ctx->r2) = ctx->r3;
    // 0x80059218: j           L_80059220
    // 0x8005921C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059220;
    // 0x8005921C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059220:
    // 0x80059220: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059224: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059228: jr          $ra
    // 0x8005922C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005922C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059230: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059234: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059238: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005923C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059240: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059244: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059248: sb          $zero, 0xCA($v0)
    MEM_B(0XCA, ctx->r2) = 0;
    // 0x8005924C: j           L_80059254
    // 0x80059250: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059254;
    // 0x80059250: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059254:
    // 0x80059254: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059258: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005925C: jr          $ra
    // 0x80059260: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059260: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059264: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059268: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x8005926C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059270: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059274: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059278: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005927C: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x80059280: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059284: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80059288: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8005928C: sb          $v1, 0xCB($v0)
    MEM_B(0XCB, ctx->r2) = ctx->r3;
    // 0x80059290: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059294: sb          $zero, 0xCA($v0)
    MEM_B(0XCA, ctx->r2) = 0;
    // 0x80059298: j           L_800592A0
    // 0x8005929C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800592A0;
    // 0x8005929C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800592A0:
    // 0x800592A0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800592A4: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800592A8: jr          $ra
    // 0x800592AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800592AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800592B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800592B0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800592B4: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800592B8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800592BC: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800592C0: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800592C4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800592C8: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800592CC: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800592D0: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x800592D4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800592D8: srl         $v1, $a0, 1
    ctx->r3 = S32(U32(ctx->r4) >> 1);
    // 0x800592DC: sb          $v1, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r3;
    // 0x800592E0: j           L_800592E8
    // 0x800592E4: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800592E8;
    // 0x800592E4: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800592E8:
    // 0x800592E8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800592EC: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800592F0: jr          $ra
    // 0x800592F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800592F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800592F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800592F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800592FC: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059300: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059304: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059308: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x8005930C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x80059310: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x80059314: j           L_8005931C
    // 0x80059318: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005931C;
    // 0x80059318: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005931C:
    // 0x8005931C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059320: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059324: jr          $ra
    // 0x80059328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005932C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005932C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80059330: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80059334: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059338: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x8005933C: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80059340: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059344: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059348: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    // 0x8005934C: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x80059350: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x80059354: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80059358: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x8005935C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80059360: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80059364: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x80059368: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005936C: lw          $v0, 0x70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70);
    // 0x80059370: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80059374: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059378: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005937C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059380: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80059384: sw          $v1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r3;
    // 0x80059388: j           L_80059390
    // 0x8005938C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80059390;
    // 0x8005938C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80059390:
    // 0x80059390: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059394: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80059398: jr          $ra
    // 0x8005939C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005939C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800593A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800593A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800593A4: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800593A8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800593AC: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800593B0: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800593B4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800593B8: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x800593BC: j           L_800593C4
    // 0x800593C0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_800593C4;
    // 0x800593C0: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_800593C4:
    // 0x800593C4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800593C8: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x800593CC: jr          $ra
    // 0x800593D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800593D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800593D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800593D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800593D8: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800593DC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800593E0: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800593E4: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800593E8: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800593EC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800593F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800593F4: sw          $v1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r3;
    // 0x800593F8: j           L_80059400
    // 0x800593FC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059400;
    // 0x800593FC: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059400:
    // 0x80059400: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059404: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059408: jr          $ra
    // 0x8005940C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005940C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059410: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80059414: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x80059418: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005941C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x80059420: sw          $a1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r5;
    // 0x80059424: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80059428: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005942C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80059430: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80059434: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x80059438: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005943C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80059440: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059444: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80059448: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005944C: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x80059450: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80059454: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x80059458: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005945C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059460: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x80059464: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80059468: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8005946C: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x80059470: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x80059474: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059478: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x8005947C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80059480: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80059484: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80059488: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005948C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059490: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059494: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80059498: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005949C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800594A0: sw          $a0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r4;
    // 0x800594A4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800594A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800594AC: sh          $v1, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r3;
    // 0x800594B0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x800594B4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800594B8: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x800594BC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800594C0: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x800594C4: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x800594C8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x800594CC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800594D0: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
    // 0x800594D4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800594D8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800594DC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800594E0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x800594E4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x800594E8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x800594EC: lw          $a0, 0x80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X80);
    // 0x800594F0: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800594F4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800594F8: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x800594FC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059500: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80059504: sh          $v1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r3;
    // 0x80059508: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005950C: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
    // 0x80059510: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x80059514: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059518: j           L_80059520
    // 0x8005951C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059520;
    // 0x8005951C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80059520:
    // 0x80059520: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059524: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x80059528: jr          $ra
    // 0x8005952C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005952C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80059530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059530: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059534: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059538: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005953C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059540: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059544: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059548: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005954C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059550: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80059554: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059558: sb          $v1, 0xC2($v0)
    MEM_B(0XC2, ctx->r2) = ctx->r3;
    // 0x8005955C: j           L_80059564
    // 0x80059560: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059564;
    // 0x80059560: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059564:
    // 0x80059564: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059568: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005956C: jr          $ra
    // 0x80059570: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059570: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005957C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80059580: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059584: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x80059588: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005958C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059590: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059594: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
    // 0x80059598: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005959C: jal         0x8005CAF0
    // 0x800595A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005CAF0(rdram, ctx);
        goto after_0;
    // 0x800595A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x800595A4: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x800595A8: sb          $v0, 0xB1($v1)
    MEM_B(0XB1, ctx->r3) = ctx->r2;
    // 0x800595AC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x800595B0: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x800595B4: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x800595B8: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x800595BC: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x800595C0: lbu         $v1, 0xB1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB1);
    // 0x800595C4: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x800595C8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800595CC: sb          $v1, 0xB1($v0)
    MEM_B(0XB1, ctx->r2) = ctx->r3;
    // 0x800595D0: j           L_800595D8
    // 0x800595D4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
        goto L_800595D8;
    // 0x800595D4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
L_800595D8:
    // 0x800595D8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800595DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800595E0: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x800595E4: jr          $ra
    // 0x800595E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800595E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800595EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800595EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800595F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800595F4: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800595F8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800595FC: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x80059600: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x80059604: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059608: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005960C: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
    // 0x80059610: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80059614: jal         0x8005CAF0
    // 0x80059618: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005CAF0(rdram, ctx);
        goto after_0;
    // 0x80059618: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x8005961C: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x80059620: sb          $v0, 0xB4($v1)
    MEM_B(0XB4, ctx->r3) = ctx->r2;
    // 0x80059624: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059628: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005962C: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x80059630: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x80059634: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x80059638: lbu         $v1, 0xB4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB4);
    // 0x8005963C: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x80059640: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80059644: sb          $v1, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r3;
    // 0x80059648: j           L_80059650
    // 0x8005964C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
        goto L_80059650;
    // 0x8005964C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
L_80059650:
    // 0x80059650: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059658: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005965C: jr          $ra
    // 0x80059660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80059664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005966C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80059670: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059674: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x80059678: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005967C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059680: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059684: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
    // 0x80059688: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005968C: jal         0x8005CAF0
    // 0x80059690: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005CAF0(rdram, ctx);
        goto after_0;
    // 0x80059690: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80059694: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x80059698: sb          $v0, 0xB5($v1)
    MEM_B(0XB5, ctx->r3) = ctx->r2;
    // 0x8005969C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x800596A0: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x800596A4: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x800596A8: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x800596AC: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x800596B0: lbu         $v1, 0xB5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB5);
    // 0x800596B4: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x800596B8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800596BC: sb          $v1, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r3;
    // 0x800596C0: j           L_800596C8
    // 0x800596C4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
        goto L_800596C8;
    // 0x800596C4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
L_800596C8:
    // 0x800596C8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x800596CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800596D0: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x800596D4: jr          $ra
    // 0x800596D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800596D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800596DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800596DC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800596E0: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800596E4: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800596E8: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800596EC: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800596F0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800596F4: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800596F8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800596FC: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80059700: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059704: sb          $v1, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r3;
    // 0x80059708: j           L_80059710
    // 0x8005970C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059710;
    // 0x8005970C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059710:
    // 0x80059710: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059714: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059718: jr          $ra
    // 0x8005971C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005971C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059720: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059724: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80059728: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8005972C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059730: sw          $a0, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r4;
    // 0x80059734: sw          $a1, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r5;
    // 0x80059738: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005973C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059740: sw          $v1, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r3;
    // 0x80059744: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80059748: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
    // 0x8005974C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059750: slti        $v1, $v0, 0x80
    ctx->r3 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80059754: bne         $v1, $zero, L_80059780
    if (ctx->r3 != 0) {
        // 0x80059758: nop
    
            goto L_80059780;
    }
    // 0x80059758: nop

    // 0x8005975C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059760: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80059764: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x80059768: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x8005976C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059770: sw          $a0, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r4;
    // 0x80059774: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059778: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005977C: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_80059780:
    // 0x80059780: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x80059784: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x80059788: sw          $v1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r3;
    // 0x8005978C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x80059790: lh          $v0, 0x96($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X96);
    // 0x80059794: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x80059798: lh          $v1, 0xA8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XA8);
    // 0x8005979C: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x800597A0: lw          $a1, 0x44($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X44);
    // 0x800597A4: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x800597A8: sw          $a2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r6;
    // 0x800597AC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800597B0: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x800597B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800597B8: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800597BC: jal         0x80059FF8
    // 0x800597C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80059FF8(rdram, ctx);
        goto after_0;
    // 0x800597C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x800597C4: sw          $v0, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r2;
    // 0x800597C8: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x800597CC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x800597D0: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x800597D4: lw          $a0, 0x44($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X44);
    // 0x800597D8: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800597DC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800597E0: sw          $a0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r4;
    // 0x800597E4: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x800597E8: bne         $v0, $zero, L_800597F8
    if (ctx->r2 != 0) {
        // 0x800597EC: nop
    
            goto L_800597F8;
    }
    // 0x800597EC: nop

    // 0x800597F0: j           L_8005988C
    // 0x800597F4: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
        goto L_8005988C;
    // 0x800597F4: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
L_800597F8:
    // 0x800597F8: nop

    // 0x800597FC: sw          $zero, 0x18($fp)
    MEM_W(0X18, ctx->r30) = 0;
    // 0x80059800: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059804: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x80059808: sw          $v0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r2;
L_8005980C:
    // 0x8005980C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059810: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059814: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x80059818: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005981C: bne         $v0, $zero, L_8005982C
    if (ctx->r2 != 0) {
        // 0x80059820: nop
    
            goto L_8005982C;
    }
    // 0x80059820: nop

    // 0x80059824: j           L_80059884
    // 0x80059828: nop

        goto L_80059884;
    // 0x80059828: nop

L_8005982C:
    // 0x8005982C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059830: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x80059834: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059838: bne         $v1, $v0, L_80059860
    if (ctx->r3 != ctx->r2) {
        // 0x8005983C: nop
    
            goto L_80059860;
    }
    // 0x8005983C: nop

    // 0x80059840: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059844: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x80059848: lw          $a0, 0x40($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X40);
    // 0x8005984C: sw          $a0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r4;
    // 0x80059850: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059854: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x80059858: lw          $a0, 0x74($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X74);
    // 0x8005985C: sw          $a0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r4;
L_80059860:
    // 0x80059860: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x80059864: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80059868: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005986C: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
    // 0x80059870: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x80059874: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x80059878: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005987C: j           L_8005980C
    // 0x80059880: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
        goto L_8005980C;
    // 0x80059880: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
L_80059884:
    // 0x80059884: j           L_8005988C
    // 0x80059888: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
        goto L_8005988C;
    // 0x80059888: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
L_8005988C:
    // 0x8005988C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059890: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80059894: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80059898: jr          $ra
    // 0x8005989C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005989C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800598A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800598A4: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x800598A8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x800598AC: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x800598B0: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x800598B4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800598B8: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x800598BC: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800598C0: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x800598C4: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800598C8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800598CC: nop

    // 0x800598D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800598D4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800598D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800598DC: ldc1        $f4, -0x12A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X12A0);
    // 0x800598E0: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x800598E4: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x800598E8: swc1        $f2, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f2.u32l;
    // 0x800598EC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x800598F0: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x800598F4: lw          $a0, 0x8($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X8);
    // 0x800598F8: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x800598FC: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80059900: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059904: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80059908: j           L_80059910
    // 0x8005990C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059910;
    // 0x8005990C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059910:
    // 0x80059910: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059914: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059918: jr          $ra
    // 0x8005991C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005991C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059920: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059924: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059928: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005992C: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059930: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059934: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x80059938: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005993C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80059940: sw          $a0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r4;
    // 0x80059944: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80059948: sb          $v1, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r3;
    // 0x8005994C: j           L_80059954
    // 0x80059950: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_80059954;
    // 0x80059950: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_80059954:
    // 0x80059954: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059958: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005995C: jr          $ra
    // 0x80059960: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059960: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059964: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80059968: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005996C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80059970: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059974: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x80059978: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005997C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80059980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059984: sw          $v1, 0x4944($at)
    MEM_W(0X4944, ctx->r1) = ctx->r3;
    // 0x80059988: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005998C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80059990: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059994: sw          $v1, 0x7664($at)
    MEM_W(0X7664, ctx->r1) = ctx->r3;
    // 0x80059998: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005999C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x800599A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800599A4: sw          $v1, -0x43AC($at)
    MEM_W(-0X43AC, ctx->r1) = ctx->r3;
    // 0x800599A8: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x800599AC: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800599B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800599B4: sw          $v1, -0x4FAC($at)
    MEM_W(-0X4FAC, ctx->r1) = ctx->r3;
    // 0x800599B8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800599BC: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x800599C0: bne         $v0, $zero, L_800599D8
    if (ctx->r2 != 0) {
        // 0x800599C4: nop
    
            goto L_800599D8;
    }
    // 0x800599C4: nop

    // 0x800599C8: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x800599CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800599D0: j           L_800599E4
    // 0x800599D4: sw          $v0, -0x42C4($at)
    MEM_W(-0X42C4, ctx->r1) = ctx->r2;
        goto L_800599E4;
    // 0x800599D4: sw          $v0, -0x42C4($at)
    MEM_W(-0X42C4, ctx->r1) = ctx->r2;
L_800599D8:
    // 0x800599D8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800599DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800599E0: sw          $v0, -0x42C4($at)
    MEM_W(-0X42C4, ctx->r1) = ctx->r2;
L_800599E4:
    // 0x800599E4: lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // 0x800599E8: ori         $v0, $v0, 0x4240
    ctx->r2 = ctx->r2 | 0X4240;
    // 0x800599EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800599F0: lw          $v1, -0x42C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X42C4);
    // 0x800599F4: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800599F8: bne         $v1, $zero, L_80059A04
    if (ctx->r3 != 0) {
        // 0x800599FC: nop
    
            goto L_80059A04;
    }
    // 0x800599FC: nop

    // 0x80059A00: break       7
    do_break(2147850752);
L_80059A04:
    // 0x80059A04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059A08: bne         $v1, $at, L_80059A1C
    if (ctx->r3 != ctx->r1) {
        // 0x80059A0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059A1C;
    }
    // 0x80059A0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059A10: bne         $v0, $at, L_80059A1C
    if (ctx->r2 != ctx->r1) {
        // 0x80059A14: nop
    
            goto L_80059A1C;
    }
    // 0x80059A14: nop

    // 0x80059A18: break       6
    do_break(2147850776);
L_80059A1C:
    // 0x80059A1C: mflo        $v0
    ctx->r2 = lo;
    // 0x80059A20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059A24: sw          $v0, -0x4430($at)
    MEM_W(-0X4430, ctx->r1) = ctx->r2;
    // 0x80059A28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059A2C: lw          $v0, 0x7664($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7664);
    // 0x80059A30: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059A34: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059A38: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80059A3C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059A40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80059A44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80059A48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059A4C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80059A50: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x80059A54: jal         0x800655B0
    // 0x80059A58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x80059A58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80059A5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059A60: sw          $v0, 0x7660($at)
    MEM_W(0X7660, ctx->r1) = ctx->r2;
    // 0x80059A64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059A68: lw          $v0, 0x7664($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7664);
    // 0x80059A6C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059A70: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059A74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059A78: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80059A7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80059A80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80059A84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059A88: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80059A8C: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x80059A90: jal         0x800655B0
    // 0x80059A94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x80059A94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80059A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059A9C: sw          $v0, -0x42C0($at)
    MEM_W(-0X42C0, ctx->r1) = ctx->r2;
    // 0x80059AA0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059AA4: lw          $v0, 0x7664($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7664);
    // 0x80059AA8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059AAC: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059AB0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80059AB4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059AB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80059ABC: lw          $a0, 0x7660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7660);
    // 0x80059AC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059AC4: jal         0x8005D0F4
    // 0x80059AC8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_8005D0F4(rdram, ctx);
        goto after_2;
    // 0x80059AC8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80059ACC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059AD0: lw          $v0, 0x7664($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7664);
    // 0x80059AD4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059AD8: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059ADC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059AE0: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80059AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80059AE8: lw          $a0, -0x42C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X42C0);
    // 0x80059AEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059AF0: jal         0x8005D0F4
    // 0x80059AF4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_8005D0F4(rdram, ctx);
        goto after_3;
    // 0x80059AF4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_3:
    // 0x80059AF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80059AFC: jal         0x80059C48
    // 0x80059B00: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_80059C48(rdram, ctx);
        goto after_4;
    // 0x80059B00: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_4:
    // 0x80059B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80059B08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B0C: sw          $v0, -0x2AF0($at)
    MEM_W(-0X2AF0, ctx->r1) = ctx->r2;
    // 0x80059B10: lui         $v0, 0x1234
    ctx->r2 = S32(0X1234 << 16);
    // 0x80059B14: ori         $v0, $v0, 0x5678
    ctx->r2 = ctx->r2 | 0X5678;
    // 0x80059B18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059B1C: sw          $v0, -0x42C8($at)
    MEM_W(-0X42C8, ctx->r1) = ctx->r2;
    // 0x80059B20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B24: sw          $zero, 0x2FC8($at)
    MEM_W(0X2FC8, ctx->r1) = 0;
    // 0x80059B28: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80059B2C: addiu       $v0, $v0, -0x5320
    ctx->r2 = ADD32(ctx->r2, -0X5320);
    // 0x80059B30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B34: sw          $v0, 0x2FD0($at)
    MEM_W(0X2FD0, ctx->r1) = ctx->r2;
    // 0x80059B38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059B3C: addiu       $v0, $v0, 0x2FC8
    ctx->r2 = ADD32(ctx->r2, 0X2FC8);
    // 0x80059B40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B44: sw          $v0, 0x2FCC($at)
    MEM_W(0X2FCC, ctx->r1) = ctx->r2;
    // 0x80059B48: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80059B4C: jal         0x8005D370
    // 0x80059B50: addiu       $a0, $a0, 0x2FC8
    ctx->r4 = ADD32(ctx->r4, 0X2FC8);
    func_8005D370(rdram, ctx);
        goto after_5;
    // 0x80059B50: addiu       $a0, $a0, 0x2FC8
    ctx->r4 = ADD32(ctx->r4, 0X2FC8);
    after_5:
    // 0x80059B54: sw          $zero, 0x20($fp)
    MEM_W(0X20, ctx->r30) = 0;
L_80059B58:
    // 0x80059B58: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059B5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059B60: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x80059B64: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059B68: bne         $v0, $zero, L_80059B78
    if (ctx->r2 != 0) {
        // 0x80059B6C: nop
    
            goto L_80059B78;
    }
    // 0x80059B6C: nop

    // 0x80059B70: j           L_80059C18
    // 0x80059B74: nop

        goto L_80059C18;
    // 0x80059B74: nop

L_80059B78:
    // 0x80059B78: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059B7C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059B80: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059B84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059B88: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80059B8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059B90: lw          $v1, -0x42C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X42C0);
    // 0x80059B94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059B98: sb          $zero, 0xC1($v0)
    MEM_B(0XC1, ctx->r2) = 0;
    // 0x80059B9C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059BA0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059BA4: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059BA8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059BAC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80059BB0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059BB4: lw          $v1, -0x42C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X42C0);
    // 0x80059BB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059BBC: jal         0x8005CC00
    // 0x80059BC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005CC00(rdram, ctx);
        goto after_6;
    // 0x80059BC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_6:
    // 0x80059BC4: sb          $zero, 0x1C($fp)
    MEM_B(0X1C, ctx->r30) = 0;
    // 0x80059BC8: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x80059BCC: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    // 0x80059BD0: sh          $v1, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r3;
    // 0x80059BD4: sh          $zero, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = 0;
    // 0x80059BD8: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059BDC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059BE0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059BE4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80059BE8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059BEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059BF0: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x80059BF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059BF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059BFC: jal         0x8005D3D0
    // 0x80059C00: addiu       $a1, $fp, 0x18
    ctx->r5 = ADD32(ctx->r30, 0X18);
    func_8005D3D0(rdram, ctx);
        goto after_7;
    // 0x80059C00: addiu       $a1, $fp, 0x18
    ctx->r5 = ADD32(ctx->r30, 0X18);
    after_7:
    // 0x80059C04: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x80059C08: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80059C0C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059C10: j           L_80059B58
    // 0x80059C14: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
        goto L_80059B58;
    // 0x80059C14: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
L_80059C18:
    // 0x80059C18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059C1C: lw          $v0, -0x346C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X346C);
    // 0x80059C20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80059C24: lw          $a0, -0x3470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3470);
    // 0x80059C28: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x80059C2C: j           L_80059C34
    // 0x80059C30: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059C34;
    // 0x80059C30: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80059C34:
    // 0x80059C34: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059C38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80059C3C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80059C40: jr          $ra
    // 0x80059C44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80059C44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80059C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059C4C: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x80059C50: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059C54: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x80059C58: sw          $a1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r5;
    // 0x80059C5C: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x80059C60: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80059C64: beq         $v0, $zero, L_80059C78
    if (ctx->r2 == 0) {
        // 0x80059C68: nop
    
            goto L_80059C78;
    }
    // 0x80059C68: nop

    // 0x80059C6C: lhu         $v0, 0xE($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0XE);
    // 0x80059C70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059C74: sh          $v0, -0x381C($at)
    MEM_H(-0X381C, ctx->r1) = ctx->r2;
L_80059C78:
    // 0x80059C78: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x80059C7C: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80059C80: beq         $v0, $zero, L_80059C94
    if (ctx->r2 == 0) {
        // 0x80059C84: nop
    
            goto L_80059C94;
    }
    // 0x80059C84: nop

    // 0x80059C88: lhu         $v0, 0xE($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0XE);
    // 0x80059C8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059C90: sh          $v0, 0x74A8($at)
    MEM_H(0X74A8, ctx->r1) = ctx->r2;
L_80059C94:
    // 0x80059C94: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059C98: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x80059C9C: jr          $ra
    // 0x80059CA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059CA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059CA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80059CA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80059CAC: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80059CB0: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059CB4: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x80059CB8: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x80059CBC: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x80059CC0: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x80059CC4: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
    // 0x80059CC8: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059CCC: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80059CD0: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
    // 0x80059CD4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80059CD8: sw          $v0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r2;
    // 0x80059CDC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059CE0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80059CE4: sltiu       $v0, $v1, 0x400
    ctx->r2 = ctx->r3 < 0X400 ? 1 : 0;
    // 0x80059CE8: beq         $v0, $zero, L_80059D3C
    if (ctx->r2 == 0) {
        // 0x80059CEC: nop
    
            goto L_80059D3C;
    }
    // 0x80059CEC: nop

    // 0x80059CF0: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x80059CF4: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x80059CF8: jal         0x8005D164
    // 0x80059CFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8005D164(rdram, ctx);
        goto after_0;
    // 0x80059CFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x80059D00: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059D04: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80059D08: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x80059D0C: jal         0x8005D164
    // 0x80059D10: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    func_8005D164(rdram, ctx);
        goto after_1;
    // 0x80059D10: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    after_1:
    // 0x80059D14: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059D18: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80059D1C: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x80059D20: jal         0x8005D164
    // 0x80059D24: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    func_8005D164(rdram, ctx);
        goto after_2;
    // 0x80059D24: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    after_2:
    // 0x80059D28: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059D2C: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80059D30: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x80059D34: jal         0x8005D164
    // 0x80059D38: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    func_8005D164(rdram, ctx);
        goto after_3;
    // 0x80059D38: lw          $a2, 0x20($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X20);
    after_3:
L_80059D3C:
    // 0x80059D3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80059D40: lw          $v0, -0x2AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AF0);
    // 0x80059D44: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059D48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059D4C: sw          $v1, -0x2AF0($at)
    MEM_W(-0X2AF0, ctx->r1) = ctx->r3;
    // 0x80059D50: sw          $v0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r2;
    // 0x80059D54: sw          $zero, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = 0;
L_80059D58:
    // 0x80059D58: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x80059D5C: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x80059D60: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059D64: bne         $v0, $zero, L_80059D74
    if (ctx->r2 != 0) {
        // 0x80059D68: nop
    
            goto L_80059D74;
    }
    // 0x80059D68: nop

    // 0x80059D6C: j           L_80059E7C
    // 0x80059D70: nop

        goto L_80059E7C;
    // 0x80059D70: nop

L_80059D74:
    // 0x80059D74: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x80059D78: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x80059D7C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80059D80: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80059D84: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80059D88: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80059D8C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80059D90: beq         $v1, $zero, L_80059E68
    if (ctx->r3 == 0) {
        // 0x80059D94: nop
    
            goto L_80059E68;
    }
    // 0x80059D94: nop

    // 0x80059D98: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059D9C: jal         0x8005CE50
    // 0x80059DA0: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    func_8005CE50(rdram, ctx);
        goto after_4;
    // 0x80059DA0: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    after_4:
    // 0x80059DA4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80059DA8: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059DAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059DB0: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80059DB4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059DB8: lw          $v1, -0x42C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X42C0);
    // 0x80059DBC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80059DC0: sw          $v0, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r2;
    // 0x80059DC4: jal         0x8005CC00
    // 0x80059DC8: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    func_8005CC00(rdram, ctx);
        goto after_5;
    // 0x80059DC8: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    after_5:
    // 0x80059DCC: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059DD0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x80059DD4: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x80059DD8: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059DDC: lw          $v1, 0x24($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X24);
    // 0x80059DE0: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059DE4: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    // 0x80059DE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80059DEC: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x80059DF0: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80059DF4: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x80059DF8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80059DFC: sw          $a1, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r5;
    // 0x80059E00: sw          $a1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r5;
    // 0x80059E04: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059E08: lw          $v1, 0x24($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X24);
    // 0x80059E0C: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059E10: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    // 0x80059E14: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80059E18: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x80059E1C: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80059E20: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x80059E24: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80059E28: sw          $a1, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r5;
    // 0x80059E2C: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x80059E30: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059E34: lw          $v1, 0x24($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X24);
    // 0x80059E38: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x80059E3C: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    // 0x80059E40: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80059E44: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x80059E48: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x80059E4C: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x80059E50: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80059E54: sw          $a1, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r5;
    // 0x80059E58: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80059E5C: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059E60: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x80059E64: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
L_80059E68:
    // 0x80059E68: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x80059E6C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80059E70: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059E74: j           L_80059D58
    // 0x80059E78: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
        goto L_80059D58;
    // 0x80059E78: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
L_80059E7C:
    // 0x80059E7C: j           L_80059E84
    // 0x80059E80: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
        goto L_80059E84;
    // 0x80059E80: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
L_80059E84:
    // 0x80059E84: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059E88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80059E8C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80059E90: jr          $ra
    // 0x80059E94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80059E94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80059E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059E9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80059EA0: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80059EA4: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x80059EA8: sw          $a0, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r4;
    // 0x80059EAC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x80059EB0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059EB4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059EB8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059EBC: lw          $v1, -0x4FAC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4FAC);
    // 0x80059EC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059EC4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80059EC8: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x80059ECC: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059ED0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80059ED4: sw          $v1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r3;
    // 0x80059ED8: sw          $zero, 0x20($fp)
    MEM_W(0X20, ctx->r30) = 0;
    // 0x80059EDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80059EE0: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x80059EE4: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
L_80059EE8:
    // 0x80059EE8: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x80059EEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80059EF0: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x80059EF4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059EF8: bne         $v0, $zero, L_80059F08
    if (ctx->r2 != 0) {
        // 0x80059EFC: nop
    
            goto L_80059F08;
    }
    // 0x80059EFC: nop

    // 0x80059F00: j           L_80059FA0
    // 0x80059F04: nop

        goto L_80059FA0;
    // 0x80059F04: nop

L_80059F08:
    // 0x80059F08: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059F0C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80059F10: bne         $v1, $zero, L_80059F40
    if (ctx->r3 != 0) {
        // 0x80059F14: nop
    
            goto L_80059F40;
    }
    // 0x80059F14: nop

    // 0x80059F18: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059F1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80059F20: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x80059F24: lw          $a1, 0x38($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X38);
    // 0x80059F28: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80059F2C: jal         0x8005D228
    // 0x80059F30: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_8005D228(rdram, ctx);
        goto after_0;
    // 0x80059F30: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80059F34: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059F38: j           L_80059FE4
    // 0x80059F3C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059FE4;
    // 0x80059F3C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80059F40:
    // 0x80059F40: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059F44: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x80059F48: beq         $v1, $zero, L_80059F7C
    if (ctx->r3 == 0) {
        // 0x80059F4C: nop
    
            goto L_80059F7C;
    }
    // 0x80059F4C: nop

    // 0x80059F50: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059F54: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80059F58: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x80059F5C: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80059F60: beq         $v1, $zero, L_80059F7C
    if (ctx->r3 == 0) {
        // 0x80059F64: nop
    
            goto L_80059F7C;
    }
    // 0x80059F64: nop

    // 0x80059F68: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059F6C: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80059F70: sw          $v1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r3;
    // 0x80059F74: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x80059F78: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_80059F7C:
    // 0x80059F7C: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x80059F80: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80059F84: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059F88: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
    // 0x80059F8C: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x80059F90: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x80059F94: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059F98: j           L_80059EE8
    // 0x80059F9C: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
        goto L_80059EE8;
    // 0x80059F9C: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
L_80059FA0:
    // 0x80059FA0: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x80059FA4: lw          $v1, 0x24($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X24);
    // 0x80059FA8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059FAC: beq         $v0, $zero, L_80059FDC
    if (ctx->r2 == 0) {
        // 0x80059FB0: nop
    
            goto L_80059FDC;
    }
    // 0x80059FB0: nop

    // 0x80059FB4: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x80059FB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80059FBC: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x80059FC0: lw          $a1, 0x38($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X38);
    // 0x80059FC4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80059FC8: jal         0x8005D228
    // 0x80059FCC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_8005D228(rdram, ctx);
        goto after_1;
    // 0x80059FCC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x80059FD0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80059FD4: j           L_80059FE4
    // 0x80059FD8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059FE4;
    // 0x80059FD8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80059FDC:
    // 0x80059FDC: j           L_80059FE4
    // 0x80059FE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80059FE4;
    // 0x80059FE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80059FE4:
    // 0x80059FE4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x80059FE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80059FEC: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80059FF0: jr          $ra
    // 0x80059FF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80059FF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80059FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059FF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80059FFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005A000: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8005A004: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A008: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x8005A00C: sw          $a1, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r5;
    // 0x8005A010: sw          $a2, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r6;
    // 0x8005A014: sw          $a3, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r7;
    // 0x8005A018: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005A01C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005A020: bne         $v0, $v1, L_8005A048
    if (ctx->r2 != ctx->r3) {
        // 0x8005A024: nop
    
            goto L_8005A048;
    }
    // 0x8005A024: nop

    // 0x8005A028: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005A02C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A030: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005A034: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A038: lw          $v1, -0x4FAC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4FAC);
    // 0x8005A03C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A040: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005A044: sw          $v1, 0x40($fp)
    MEM_W(0X40, ctx->r30) = ctx->r3;
L_8005A048:
    // 0x8005A048: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005A04C: beq         $v0, $zero, L_8005A0E4
    if (ctx->r2 == 0) {
        // 0x8005A050: nop
    
            goto L_8005A0E4;
    }
    // 0x8005A050: nop

    // 0x8005A054: sw          $zero, 0x20($fp)
    MEM_W(0X20, ctx->r30) = 0;
    // 0x8005A058: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A05C: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A060: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
L_8005A064:
    // 0x8005A064: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005A068: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A06C: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A070: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A074: bne         $v0, $zero, L_8005A084
    if (ctx->r2 != 0) {
        // 0x8005A078: nop
    
            goto L_8005A084;
    }
    // 0x8005A078: nop

    // 0x8005A07C: j           L_8005A0E4
    // 0x8005A080: nop

        goto L_8005A0E4;
    // 0x8005A080: nop

L_8005A084:
    // 0x8005A084: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A088: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A08C: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005A090: bne         $v1, $v0, L_8005A0C0
    if (ctx->r3 != ctx->r2) {
        // 0x8005A094: nop
    
            goto L_8005A0C0;
    }
    // 0x8005A094: nop

    // 0x8005A098: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005A09C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005A0A0: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005A0A4: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x8005A0A8: lw          $a2, 0x34($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X34);
    // 0x8005A0AC: jal         0x8005D228
    // 0x8005A0B0: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    func_8005D228(rdram, ctx);
        goto after_0;
    // 0x8005A0B0: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    after_0:
    // 0x8005A0B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A0B8: j           L_8005A1FC
    // 0x8005A0BC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005A1FC;
    // 0x8005A0BC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005A0C0:
    // 0x8005A0C0: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005A0C4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A0C8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A0CC: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
    // 0x8005A0D0: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A0D4: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A0D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A0DC: j           L_8005A064
    // 0x8005A0E0: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
        goto L_8005A064;
    // 0x8005A0E0: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
L_8005A0E4:
    // 0x8005A0E4: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005A0E8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005A0EC: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x8005A0F0: sw          $zero, 0x20($fp)
    MEM_W(0X20, ctx->r30) = 0;
    // 0x8005A0F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A0F8: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A0FC: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
L_8005A100:
    // 0x8005A100: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005A104: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A108: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A10C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A110: bne         $v0, $zero, L_8005A120
    if (ctx->r2 != 0) {
        // 0x8005A114: nop
    
            goto L_8005A120;
    }
    // 0x8005A114: nop

    // 0x8005A118: j           L_8005A1B8
    // 0x8005A11C: nop

        goto L_8005A1B8;
    // 0x8005A11C: nop

L_8005A120:
    // 0x8005A120: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A124: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005A128: bne         $v1, $zero, L_8005A158
    if (ctx->r3 != 0) {
        // 0x8005A12C: nop
    
            goto L_8005A158;
    }
    // 0x8005A12C: nop

    // 0x8005A130: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005A134: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005A138: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005A13C: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x8005A140: lw          $a2, 0x34($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X34);
    // 0x8005A144: jal         0x8005D228
    // 0x8005A148: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    func_8005D228(rdram, ctx);
        goto after_1;
    // 0x8005A148: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    after_1:
    // 0x8005A14C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A150: j           L_8005A1FC
    // 0x8005A154: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005A1FC;
    // 0x8005A154: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005A158:
    // 0x8005A158: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A15C: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A160: beq         $v1, $zero, L_8005A194
    if (ctx->r3 == 0) {
        // 0x8005A164: nop
    
            goto L_8005A194;
    }
    // 0x8005A164: nop

    // 0x8005A168: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A16C: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8005A170: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x8005A174: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005A178: beq         $v1, $zero, L_8005A194
    if (ctx->r3 == 0) {
        // 0x8005A17C: nop
    
            goto L_8005A194;
    }
    // 0x8005A17C: nop

    // 0x8005A180: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A184: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8005A188: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x8005A18C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A190: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_8005A194:
    // 0x8005A194: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005A198: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A19C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A1A0: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
    // 0x8005A1A4: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A1A8: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A1AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A1B0: j           L_8005A100
    // 0x8005A1B4: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
        goto L_8005A100;
    // 0x8005A1B4: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
L_8005A1B8:
    // 0x8005A1B8: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x8005A1BC: lw          $v1, 0x40($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X40);
    // 0x8005A1C0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A1C4: beq         $v0, $zero, L_8005A1F4
    if (ctx->r2 == 0) {
        // 0x8005A1C8: nop
    
            goto L_8005A1F4;
    }
    // 0x8005A1C8: nop

    // 0x8005A1CC: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005A1D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005A1D4: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A1D8: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x8005A1DC: lw          $a2, 0x34($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X34);
    // 0x8005A1E0: jal         0x8005D228
    // 0x8005A1E4: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    func_8005D228(rdram, ctx);
        goto after_2;
    // 0x8005A1E4: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    after_2:
    // 0x8005A1E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A1EC: j           L_8005A1FC
    // 0x8005A1F0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005A1FC;
    // 0x8005A1F0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005A1F4:
    // 0x8005A1F4: j           L_8005A1FC
    // 0x8005A1F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A1FC;
    // 0x8005A1F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A1FC:
    // 0x8005A1FC: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A204: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8005A208: jr          $ra
    // 0x8005A20C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005A20C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005A210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A214: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A218: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A21C: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A220: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A224: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A228: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A22C: bne         $v1, $zero, L_8005A238
    if (ctx->r3 != 0) {
        // 0x8005A230: nop
    
            goto L_8005A238;
    }
    // 0x8005A230: nop

    // 0x8005A234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A238:
    // 0x8005A238: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x8005A23C: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8005A240: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A244: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A248: sw          $v0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r2;
L_8005A24C:
    // 0x8005A24C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A250: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A254: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A258: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A25C: bne         $v0, $zero, L_8005A26C
    if (ctx->r2 != 0) {
        // 0x8005A260: nop
    
            goto L_8005A26C;
    }
    // 0x8005A260: nop

    // 0x8005A264: j           L_8005A2F8
    // 0x8005A268: nop

        goto L_8005A2F8;
    // 0x8005A268: nop

L_8005A26C:
    // 0x8005A26C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A270: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A274: beq         $v1, $zero, L_8005A294
    if (ctx->r3 == 0) {
        // 0x8005A278: nop
    
            goto L_8005A294;
    }
    // 0x8005A278: nop

    // 0x8005A27C: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A280: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8005A284: bne         $v0, $zero, L_8005A2BC
    if (ctx->r2 != 0) {
        // 0x8005A288: nop
    
            goto L_8005A2BC;
    }
    // 0x8005A288: nop

    // 0x8005A28C: j           L_8005A294
    // 0x8005A290: nop

        goto L_8005A294;
    // 0x8005A290: nop

L_8005A294:
    // 0x8005A294: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A298: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A29C: bne         $v1, $zero, L_8005A2D4
    if (ctx->r3 != 0) {
        // 0x8005A2A0: nop
    
            goto L_8005A2D4;
    }
    // 0x8005A2A0: nop

    // 0x8005A2A4: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A2A8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8005A2AC: bne         $v0, $zero, L_8005A2BC
    if (ctx->r2 != 0) {
        // 0x8005A2B0: nop
    
            goto L_8005A2BC;
    }
    // 0x8005A2B0: nop

    // 0x8005A2B4: j           L_8005A2D4
    // 0x8005A2B8: nop

        goto L_8005A2D4;
    // 0x8005A2B8: nop

L_8005A2BC:
    // 0x8005A2BC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A2C0: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A2C4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8005A2C8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A2CC: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A2D0: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
L_8005A2D4:
    // 0x8005A2D4: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A2D8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A2DC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A2E0: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x8005A2E4: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A2E8: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A2EC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A2F0: j           L_8005A24C
    // 0x8005A2F4: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
        goto L_8005A24C;
    // 0x8005A2F4: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A2F8:
    // 0x8005A2F8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A2FC: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A300: jr          $ra
    // 0x8005A304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A30C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A310: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A314: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A318: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8005A31C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A320: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A324: sw          $v0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r2;
    // 0x8005A328: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
L_8005A32C:
    // 0x8005A32C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A330: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A334: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A338: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A33C: bne         $v0, $zero, L_8005A34C
    if (ctx->r2 != 0) {
        // 0x8005A340: nop
    
            goto L_8005A34C;
    }
    // 0x8005A340: nop

    // 0x8005A344: j           L_8005A3E0
    // 0x8005A348: nop

        goto L_8005A3E0;
    // 0x8005A348: nop

L_8005A34C:
    // 0x8005A34C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A350: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005A354: beq         $v1, $zero, L_8005A3BC
    if (ctx->r3 == 0) {
        // 0x8005A358: nop
    
            goto L_8005A3BC;
    }
    // 0x8005A358: nop

    // 0x8005A35C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A360: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A364: beq         $v1, $zero, L_8005A384
    if (ctx->r3 == 0) {
        // 0x8005A368: nop
    
            goto L_8005A384;
    }
    // 0x8005A368: nop

    // 0x8005A36C: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A370: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8005A374: bne         $v0, $zero, L_8005A3AC
    if (ctx->r2 != 0) {
        // 0x8005A378: nop
    
            goto L_8005A3AC;
    }
    // 0x8005A378: nop

    // 0x8005A37C: j           L_8005A384
    // 0x8005A380: nop

        goto L_8005A384;
    // 0x8005A380: nop

L_8005A384:
    // 0x8005A384: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005A388: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005A38C: bne         $v1, $zero, L_8005A3BC
    if (ctx->r3 != 0) {
        // 0x8005A390: nop
    
            goto L_8005A3BC;
    }
    // 0x8005A390: nop

    // 0x8005A394: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005A398: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8005A39C: bne         $v0, $zero, L_8005A3AC
    if (ctx->r2 != 0) {
        // 0x8005A3A0: nop
    
            goto L_8005A3AC;
    }
    // 0x8005A3A0: nop

    // 0x8005A3A4: j           L_8005A3BC
    // 0x8005A3A8: nop

        goto L_8005A3BC;
    // 0x8005A3A8: nop

L_8005A3AC:
    // 0x8005A3AC: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A3B0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A3B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A3B8: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
L_8005A3BC:
    // 0x8005A3BC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A3C0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A3C4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A3C8: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x8005A3CC: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A3D0: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A3D4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A3D8: j           L_8005A32C
    // 0x8005A3DC: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
        goto L_8005A32C;
    // 0x8005A3DC: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A3E0:
    // 0x8005A3E0: j           L_8005A3E8
    // 0x8005A3E4: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
        goto L_8005A3E8;
    // 0x8005A3E4: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
L_8005A3E8:
    // 0x8005A3E8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A3EC: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A3F0: jr          $ra
    // 0x8005A3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
