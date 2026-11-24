#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80027698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002769C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800276A0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800276A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800276A8: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800276AC: lb          $a0, 0x124($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X124);
    // 0x800276B0: jal         0x8000637C
    // 0x800276B4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x800276B4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
    // 0x800276B8: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x800276BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800276C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800276C4: jr          $ra
    // 0x800276C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800276C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800276CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800276CC: lb          $v1, 0x124($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X124);
    // 0x800276D0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800276D4: bne         $v0, $v1, L_800276FC
    if (ctx->r2 != ctx->r3) {
        // 0x800276D8: nop
    
            goto L_800276FC;
    }
    // 0x800276D8: nop

    // 0x800276DC: lb          $v1, 0x125($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X125);
    // 0x800276E0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800276E4: bne         $v0, $v1, L_800276FC
    if (ctx->r2 != ctx->r3) {
        // 0x800276E8: nop
    
            goto L_800276FC;
    }
    // 0x800276E8: nop

    // 0x800276EC: lb          $v1, 0x126($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X126);
    // 0x800276F0: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x800276F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800276F8: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
L_800276FC:
    // 0x800276FC: jr          $ra
    // 0x80027700: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80027700: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80027704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027704: lb          $v0, 0x5D($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5D);
    // 0x80027708: beq         $v0, $zero, L_80027720
    if (ctx->r2 == 0) {
        // 0x8002770C: nop
    
            goto L_80027720;
    }
    // 0x8002770C: nop

    // 0x80027710: lb          $v1, 0x124($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X124);
    // 0x80027714: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80027718: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002771C: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
L_80027720:
    // 0x80027720: jr          $ra
    // 0x80027724: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80027724: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80027728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027728: lbu         $v0, 0x72($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X72);
    // 0x8002772C: beq         $v0, $zero, L_80027744
    if (ctx->r2 == 0) {
        // 0x80027730: nop
    
            goto L_80027744;
    }
    // 0x80027730: nop

    // 0x80027734: lb          $v1, 0x124($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X124);
    // 0x80027738: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x8002773C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027740: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
L_80027744:
    // 0x80027744: jr          $ra
    // 0x80027748: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80027748: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8002774C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002774C: lb          $v1, 0x124($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X124);
    // 0x80027750: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80027754: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x80027758: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002775C: jr          $ra
    // 0x80027760: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    return;
    // 0x80027760: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80027764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027764: lbu         $v0, 0x124($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X124);
    // 0x80027768: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x8002776C: jr          $ra
    // 0x80027770: sb          $v0, 0x129($a0)
    MEM_B(0X129, ctx->r4) = ctx->r2;
    return;
    // 0x80027770: sb          $v0, 0x129($a0)
    MEM_B(0X129, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80027774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027774: lbu         $v0, 0x129($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X129);
    // 0x80027778: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x8002777C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027780: jr          $ra
    // 0x80027784: sb          $v0, 0x129($a0)
    MEM_B(0X129, ctx->r4) = ctx->r2;
    return;
    // 0x80027784: sb          $v0, 0x129($a0)
    MEM_B(0X129, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80027788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027788: lb          $v1, 0x129($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X129);
    // 0x8002778C: lb          $v0, 0x124($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X124);
    // 0x80027790: bne         $v1, $v0, L_800277A8
    if (ctx->r3 != ctx->r2) {
        // 0x80027794: nop
    
            goto L_800277A8;
    }
    // 0x80027794: nop

    // 0x80027798: lb          $v1, 0x125($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X125);
    // 0x8002779C: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x800277A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800277A4: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
L_800277A8:
    // 0x800277A8: jr          $ra
    // 0x800277AC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800277AC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800277B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800277B0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800277B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800277B8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800277BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800277C0: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x800277C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800277C8: sw          $a0, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->r4;
    // 0x800277CC: jr          $ra
    // 0x800277D0: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800277D0: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800277D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800277D4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x800277D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800277DC: jr          $ra
    // 0x800277E0: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    return;
    // 0x800277E0: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800277E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800277E4: lw          $v1, 0xD0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XD0);
    // 0x800277E8: lb          $v0, 0x124($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X124);
    // 0x800277EC: sw          $v0, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = ctx->r2;
    // 0x800277F0: lw          $v0, 0xD0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD0);
    // 0x800277F4: sb          $zero, 0x11E($v0)
    MEM_B(0X11E, ctx->r2) = 0;
    // 0x800277F8: jr          $ra
    // 0x800277FC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800277FC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80027800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027800: sb          $zero, 0x5D($a0)
    MEM_B(0X5D, ctx->r4) = 0;
    // 0x80027804: jr          $ra
    // 0x80027808: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80027808: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8002780C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002780C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80027810: bgtzl       $v0, L_80027818
    if (SIGNED(ctx->r2) > 0) {
        // 0x80027814: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_80027818;
    }
    goto skip_0;
    // 0x80027814: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_80027818:
    // 0x80027818: jr          $ra
    // 0x8002781C: nop

    return;
    // 0x8002781C: nop

;}
RECOMP_FUNC void func_80027820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027820: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80027824: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80027828: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002782C: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x80027830: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80027834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80027838: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002783C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80027840: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80027844: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80027848: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002784C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80027850: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x80027854: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80027858: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8002785C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80027860: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80027864: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80027868: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002786C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80027870: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027874: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    // 0x80027878: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002787C: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x80027880: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027884: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, 0X1230);
    // 0x80027888: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002788C: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x80027890: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80027894: addiu       $v0, $v0, -0x7540
    ctx->r2 = ADD32(ctx->r2, -0X7540);
    // 0x80027898: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002789C: addu        $s4, $a0, $v0
    ctx->r20 = ADD32(ctx->r4, ctx->r2);
    // 0x800278A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800278A4: addiu       $v0, $v0, 0x26E0
    ctx->r2 = ADD32(ctx->r2, 0X26E0);
    // 0x800278A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800278AC: slti        $a1, $a1, 0x4C
    ctx->r5 = SIGNED(ctx->r5) < 0X4C ? 1 : 0;
    // 0x800278B0: beq         $a1, $zero, L_80027FA4
    if (ctx->r5 == 0) {
        // 0x800278B4: addu        $s3, $a0, $v1
        ctx->r19 = ADD32(ctx->r4, ctx->r3);
            goto L_80027FA4;
    }
    // 0x800278B4: addu        $s3, $a0, $v1
    ctx->r19 = ADD32(ctx->r4, ctx->r3);
    // 0x800278B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800278BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800278C0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800278C4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x800278C8: jal         0x800178E0
    // 0x800278CC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800178E0(rdram, ctx);
        goto after_0;
    // 0x800278CC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x800278D0: lbu         $a1, 0xB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB);
    // 0x800278D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800278D8: jal         0x80018514
    // 0x800278DC: sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5 << 8);
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x800278DC: sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5 << 8);
    after_1:
    // 0x800278E0: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800278E4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800278E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800278EC: nop

    // 0x800278F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800278F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800278F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800278FC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80027900: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80027904: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027908: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002790C: nop

    // 0x80027910: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027914: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80027918: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8002791C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80027920: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80027924: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80027928: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002792C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027930: nop

    // 0x80027934: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027938: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x8002793C: lwc1        $f2, 0x5C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80027940: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80027944: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80027948: nop

    // 0x8002794C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80027950: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027954: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027958: nop

    // 0x8002795C: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x80027960: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80027964: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027968: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002796C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027970: nop

    // 0x80027974: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027978: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // 0x8002797C: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027980: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027984: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027988: nop

    // 0x8002798C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027990: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x80027994: lb          $v0, 0x66($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X66);
    // 0x80027998: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8002799C: addiu       $v1, $v1, -0x9E0
    ctx->r3 = ADD32(ctx->r3, -0X9E0);
    // 0x800279A0: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x800279A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800279A8: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x800279AC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800279B0: bne         $v0, $zero, L_800279BC
    if (ctx->r2 != 0) {
        // 0x800279B4: addiu       $v0, $v1, 0xA20
        ctx->r2 = ADD32(ctx->r3, 0XA20);
            goto L_800279BC;
    }
    // 0x800279B4: addiu       $v0, $v1, 0xA20
    ctx->r2 = ADD32(ctx->r3, 0XA20);
    // 0x800279B8: addiu       $v0, $v1, 0xA00
    ctx->r2 = ADD32(ctx->r3, 0XA00);
L_800279BC:
    // 0x800279BC: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800279C0: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x800279C4: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x800279C8: lui         $a2, 0xB900
    ctx->r6 = S32(0XB900 << 16);
    // 0x800279CC: ori         $a2, $a2, 0x31D
    ctx->r6 = ctx->r6 | 0X31D;
    // 0x800279D0: lui         $a1, 0xF0A
    ctx->r5 = S32(0XF0A << 16);
    // 0x800279D4: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x800279D8: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800279DC: ori         $t5, $t5, 0xE02
    ctx->r13 = ctx->r13 | 0XE02;
    // 0x800279E0: lui         $a0, 0xC100
    ctx->r4 = S32(0XC100 << 16);
    // 0x800279E4: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x800279E8: lui         $a3, 0xF500
    ctx->r7 = S32(0XF500 << 16);
    // 0x800279EC: ori         $a3, $a3, 0x100
    ctx->r7 = ctx->r7 | 0X100;
    // 0x800279F0: lui         $t0, 0x703
    ctx->r8 = S32(0X703 << 16);
    // 0x800279F4: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800279F8: lui         $t1, 0x70E
    ctx->r9 = S32(0X70E << 16);
    // 0x800279FC: ori         $t1, $t1, 0xF400
    ctx->r9 = ctx->r9 | 0XF400;
    // 0x80027A00: lui         $t2, 0xF540
    ctx->r10 = S32(0XF540 << 16);
    // 0x80027A04: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x80027A08: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80027A0C: lw          $t4, 0x2FE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2FE4);
    // 0x80027A10: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x80027A14: ori         $t3, $t3, 0xC074
    ctx->r11 = ctx->r11 | 0XC074;
    // 0x80027A18: addiu       $v0, $t4, 0x8
    ctx->r2 = ADD32(ctx->r12, 0X8);
    // 0x80027A1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A24: addiu       $v0, $t4, 0x10
    ctx->r2 = ADD32(ctx->r12, 0X10);
    // 0x80027A28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A30: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80027A34: sw          $v0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r2;
    // 0x80027A38: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80027A3C: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x80027A40: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x80027A44: addiu       $v0, $t4, 0x18
    ctx->r2 = ADD32(ctx->r12, 0X18);
    // 0x80027A48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A50: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x80027A54: sw          $v0, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r2;
    // 0x80027A58: addiu       $v0, $t4, 0x20
    ctx->r2 = ADD32(ctx->r12, 0X20);
    // 0x80027A5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A60: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A64: addiu       $v0, $t4, 0x28
    ctx->r2 = ADD32(ctx->r12, 0X28);
    // 0x80027A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A70: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80027A74: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    // 0x80027A78: addiu       $v0, $t4, 0x30
    ctx->r2 = ADD32(ctx->r12, 0X30);
    // 0x80027A7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A84: addiu       $v0, $t4, 0x38
    ctx->r2 = ADD32(ctx->r12, 0X38);
    // 0x80027A88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A8C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A90: addiu       $v0, $t4, 0x40
    ctx->r2 = ADD32(ctx->r12, 0X40);
    // 0x80027A94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027A98: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027A9C: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x80027AA0: sw          $v0, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r2;
    // 0x80027AA4: addiu       $v0, $t4, 0x48
    ctx->r2 = ADD32(ctx->r12, 0X48);
    // 0x80027AA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027AAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027AB0: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80027AB4: sw          $v0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->r2;
    // 0x80027AB8: addiu       $v0, $t4, 0x50
    ctx->r2 = ADD32(ctx->r12, 0X50);
    // 0x80027ABC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027AC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027AC4: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80027AC8: sw          $v1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r3;
    // 0x80027ACC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80027AD0: addiu       $v1, $v1, 0x240
    ctx->r3 = ADD32(ctx->r3, 0X240);
    // 0x80027AD4: sw          $v0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->r2;
    // 0x80027AD8: addiu       $v0, $t4, 0x58
    ctx->r2 = ADD32(ctx->r12, 0X58);
    // 0x80027ADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027AE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027AE4: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80027AE8: sw          $v0, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r2;
    // 0x80027AEC: addiu       $v0, $t4, 0x60
    ctx->r2 = ADD32(ctx->r12, 0X60);
    // 0x80027AF0: sw          $a2, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r6;
    // 0x80027AF4: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80027AF8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80027AFC: sw          $zero, 0x14($t4)
    MEM_W(0X14, ctx->r12) = 0;
    // 0x80027B00: sw          $a1, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r5;
    // 0x80027B04: sw          $t5, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r13;
    // 0x80027B08: sw          $a0, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r4;
    // 0x80027B0C: sw          $s3, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->r19;
    // 0x80027B10: sw          $a0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r4;
    // 0x80027B14: sw          $s4, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r20;
    // 0x80027B18: sw          $s2, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r18;
    // 0x80027B1C: sw          $s1, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r17;
    // 0x80027B20: sw          $v1, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->r3;
    // 0x80027B24: sw          $zero, 0x54($t4)
    MEM_W(0X54, ctx->r12) = 0;
    // 0x80027B28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B30: addiu       $v0, $t4, 0x68
    ctx->r2 = ADD32(ctx->r12, 0X68);
    // 0x80027B34: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x80027B38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B40: addiu       $v0, $t4, 0x70
    ctx->r2 = ADD32(ctx->r12, 0X70);
    // 0x80027B44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B4C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80027B50: sw          $v0, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r2;
    // 0x80027B54: addiu       $v0, $t4, 0x78
    ctx->r2 = ADD32(ctx->r12, 0X78);
    // 0x80027B58: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x80027B5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B60: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B64: addiu       $v0, $t4, 0x80
    ctx->r2 = ADD32(ctx->r12, 0X80);
    // 0x80027B68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B70: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80027B74: addiu       $v1, $v1, -0x1E0
    ctx->r3 = ADD32(ctx->r3, -0X1E0);
    // 0x80027B78: sw          $v0, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->r2;
    // 0x80027B7C: addiu       $v0, $t4, 0x88
    ctx->r2 = ADD32(ctx->r12, 0X88);
    // 0x80027B80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B88: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80027B8C: sw          $v0, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r2;
    // 0x80027B90: addiu       $v0, $t4, 0x90
    ctx->r2 = ADD32(ctx->r12, 0X90);
    // 0x80027B94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027B98: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027B9C: addiu       $v0, $t4, 0x98
    ctx->r2 = ADD32(ctx->r12, 0X98);
    // 0x80027BA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027BA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027BA8: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80027BAC: sw          $v0, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->r2;
    // 0x80027BB0: addiu       $v0, $t4, 0xA0
    ctx->r2 = ADD32(ctx->r12, 0XA0);
    // 0x80027BB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027BB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027BBC: addiu       $v0, $t4, 0xA8
    ctx->r2 = ADD32(ctx->r12, 0XA8);
    // 0x80027BC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027BC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027BC8: addiu       $v0, $t4, 0xB0
    ctx->r2 = ADD32(ctx->r12, 0XB0);
    // 0x80027BCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027BD0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027BD4: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80027BD8: sw          $a3, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->r7;
    // 0x80027BDC: sw          $a2, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->r6;
    // 0x80027BE0: sw          $a1, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->r5;
    // 0x80027BE4: sw          $zero, 0x64($t4)
    MEM_W(0X64, ctx->r12) = 0;
    // 0x80027BE8: sw          $t0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->r8;
    // 0x80027BEC: sw          $a0, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->r4;
    // 0x80027BF0: sw          $zero, 0x74($t4)
    MEM_W(0X74, ctx->r12) = 0;
    // 0x80027BF4: sw          $v1, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->r3;
    // 0x80027BF8: sw          $a2, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r6;
    // 0x80027BFC: sw          $a1, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->r5;
    // 0x80027C00: sw          $zero, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = 0;
    // 0x80027C04: sw          $t1, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->r9;
    // 0x80027C08: sw          $a0, 0x98($t4)
    MEM_W(0X98, ctx->r12) = ctx->r4;
    // 0x80027C0C: sw          $zero, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = 0;
    // 0x80027C10: sw          $t2, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->r10;
    // 0x80027C14: sw          $zero, 0xA4($t4)
    MEM_W(0XA4, ctx->r12) = 0;
    // 0x80027C18: sw          $v0, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->r2;
    // 0x80027C1C: sw          $t3, 0xAC($t4)
    MEM_W(0XAC, ctx->r12) = ctx->r11;
    // 0x80027C20: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x80027C24: lbu         $v1, 0xD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XD);
    // 0x80027C28: lb          $a0, 0x31($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X31);
    // 0x80027C2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027C30: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80027C34: slti        $t2, $t1, 0x2
    ctx->r10 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80027C38: bne         $t2, $zero, L_80027D34
    if (ctx->r10 != 0) {
        // 0x80027C3C: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_80027D34;
    }
    // 0x80027C3C: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x80027C40: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027C44: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027C48: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80027C4C: nop

    // 0x80027C50: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80027C54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027C58: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C5C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027C60: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80027C64: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027C68: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027C6C: nop

    // 0x80027C70: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80027C74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027C78: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027C7C: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80027C80: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80027C84: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80027C88: sw          $v1, 0xB0($t4)
    MEM_W(0XB0, ctx->r12) = ctx->r3;
    // 0x80027C8C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027C90: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C94: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x80027C98: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80027C9C: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
    // 0x80027CA0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027CA4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80027CA8: nop

    // 0x80027CAC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80027CB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027CB4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027CB8: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80027CBC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80027CC0: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80027CC4: nop

    // 0x80027CC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027CCC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027CD0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80027CD4: sw          $v0, 0xB4($t4)
    MEM_W(0XB4, ctx->r12) = ctx->r2;
    // 0x80027CD8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80027CDC: lb          $a0, 0x29F4($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X29F4);
    // 0x80027CE0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80027CE4: lb          $v1, 0x29F5($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X29F5);
    // 0x80027CE8: ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    // 0x80027CEC: addiu       $v0, $t4, 0xB8
    ctx->r2 = ADD32(ctx->r12, 0XB8);
    // 0x80027CF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027CF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027CF8: addiu       $v0, $t4, 0xC0
    ctx->r2 = ADD32(ctx->r12, 0XC0);
    // 0x80027CFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027D00: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027D04: addiu       $v0, $t4, 0xC8
    ctx->r2 = ADD32(ctx->r12, 0XC8);
    // 0x80027D08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027D0C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027D10: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80027D14: sw          $v0, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r2;
    // 0x80027D18: sw          $a1, 0xC4($t4)
    MEM_W(0XC4, ctx->r12) = ctx->r5;
    // 0x80027D1C: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x80027D20: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80027D24: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80027D28: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80027D2C: sw          $a0, 0xBC($t4)
    MEM_W(0XBC, ctx->r12) = ctx->r4;
    // 0x80027D30: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
L_80027D34:
    // 0x80027D34: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x80027D38: mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027D3C: sra         $v0, $t1, 31
    ctx->r2 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80027D40: mfhi        $t6
    ctx->r14 = hi;
    // 0x80027D44: sra         $v1, $t6, 2
    ctx->r3 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80027D48: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x80027D4C: beq         $t0, $zero, L_80027E5C
    if (ctx->r8 == 0) {
        // 0x80027D50: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80027E5C;
    }
    // 0x80027D50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80027D54: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027D58: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x80027D5C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80027D60: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80027D64: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027D68: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80027D6C: nop

    // 0x80027D70: addiu       $v1, $v1, 0x1A
    ctx->r3 = ADD32(ctx->r3, 0X1A);
    // 0x80027D74: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027D78: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027D7C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027D80: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80027D84: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027D88: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027D8C: nop

    // 0x80027D90: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80027D94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027D98: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027D9C: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80027DA0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80027DA4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80027DA8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80027DAC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027DB0: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027DB4: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80027DB8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80027DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027DC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027DC4: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80027DC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027DCC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027DD0: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80027DD4: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80027DD8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027DDC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80027DE0: nop

    // 0x80027DE4: addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // 0x80027DE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027DEC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027DF0: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80027DF4: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80027DF8: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80027DFC: nop

    // 0x80027E00: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027E04: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027E08: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80027E0C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80027E10: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80027E14: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80027E18: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80027E1C: lb          $a0, 0x29E0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X29E0);
    // 0x80027E20: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80027E24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027E28: lb          $v1, 0x29E1($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X29E1);
    // 0x80027E2C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80027E30: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80027E34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027E38: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027E3C: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80027E40: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80027E44: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    // 0x80027E48: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x80027E4C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80027E50: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80027E54: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80027E58: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_80027E5C:
    // 0x80027E5C: bne         $t2, $zero, L_80027F74
    if (ctx->r10 != 0) {
        // 0x80027E60: lui         $a2, 0x400
        ctx->r6 = S32(0X400 << 16);
            goto L_80027F74;
    }
    // 0x80027E60: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x80027E64: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027E68: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80027E6C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80027E70: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027E74: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80027E78: addiu       $v0, $a3, 0x1A
    ctx->r2 = ADD32(ctx->r7, 0X1A);
    // 0x80027E7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027E80: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027E84: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027E88: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027E8C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80027E90: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027E94: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80027E98: nop

    // 0x80027E9C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80027EA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027EA4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027EA8: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80027EAC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80027EB0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80027EB4: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80027EB8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027EBC: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027EC0: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80027EC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027EC8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027ECC: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80027ED0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027ED4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027ED8: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80027EDC: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80027EE0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027EE4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80027EE8: addiu       $v0, $a3, 0x12
    ctx->r2 = ADD32(ctx->r7, 0X12);
    // 0x80027EEC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027EF0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80027EF4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80027EF8: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80027EFC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80027F00: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80027F04: nop

    // 0x80027F08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027F0C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027F10: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80027F14: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80027F18: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80027F1C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027F20: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x80027F24: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027F28: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80027F2C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80027F30: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80027F34: lb          $a0, 0x29E0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X29E0);
    // 0x80027F38: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80027F3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80027F40: lb          $v1, 0x29E1($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X29E1);
    // 0x80027F44: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80027F48: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80027F4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027F50: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80027F54: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80027F58: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80027F5C: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    // 0x80027F60: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x80027F64: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80027F68: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80027F6C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80027F70: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_80027F74:
    // 0x80027F74: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80027F78: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80027F7C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80027F80: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x80027F84: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80027F88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80027F8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80027F90: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80027F94: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80027F98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80027F9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80027FA0: sw          $a0, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r4;
L_80027FA4:
    // 0x80027FA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80027FA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80027FAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80027FB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80027FB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80027FB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80027FBC: jr          $ra
    // 0x80027FC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80027FC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80027FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027FC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80027FCC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80027FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027FD4: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80027FD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80027FDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80027FE0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80027FE4: lw          $v0, 0x29F8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X29F8);
    // 0x80027FE8: jalr        $v0
    // 0x80027FEC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80027FEC: nop

    after_0:
    // 0x80027FF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027FF4: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80027FF8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80027FFC: beq         $v0, $zero, L_80028010
    if (ctx->r2 == 0) {
        // 0x80028000: nop
    
            goto L_80028010;
    }
    // 0x80028000: nop

    // 0x80028004: lbu         $v0, 0xB($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB);
    // 0x80028008: j           L_80028018
    // 0x8002800C: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
        goto L_80028018;
    // 0x8002800C: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
L_80028010:
    // 0x80028010: lbu         $v0, 0xB($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB);
    // 0x80028014: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
L_80028018:
    // 0x80028018: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x8002801C: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80028020: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028024: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x80028028: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8002802C: beq         $v0, $zero, L_8002804C
    if (ctx->r2 == 0) {
        // 0x80028030: nop
    
            goto L_8002804C;
    }
    // 0x80028030: nop

    // 0x80028034: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80028038: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002803C: ldc1        $f2, -0x2A70($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A70);
    // 0x80028040: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80028044: j           L_80028060
    // 0x80028048: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
        goto L_80028060;
    // 0x80028048: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
L_8002804C:
    // 0x8002804C: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80028050: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028054: ldc1        $f2, -0x2A68($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A68);
    // 0x80028058: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002805C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
L_80028060:
    // 0x80028060: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80028064: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80028068: jal         0x800293DC
    // 0x8002806C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800293DC(rdram, ctx);
        goto after_1;
    // 0x8002806C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80028070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028074: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80028078: jr          $ra
    // 0x8002807C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002807C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80028080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028084: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80028088: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002808C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028090: lb          $v0, 0x1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1);
    // 0x80028094: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80028098: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002809C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800280A0: lw          $v0, 0x2A04($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2A04);
    // 0x800280A4: jalr        $v0
    // 0x800280A8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800280A8: nop

    after_0:
    // 0x800280AC: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x800280B0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800280B4: bne         $v0, $zero, L_800281B4
    if (ctx->r2 != 0) {
        // 0x800280B8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800281B4;
    }
    // 0x800280B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800280BC: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800280C0: beq         $v1, $v0, L_800281B4
    if (ctx->r3 == ctx->r2) {
        // 0x800280C4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800281B4;
    }
    // 0x800280C4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800280C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800280CC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800280D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800280D4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800280D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800280DC: addiu       $a0, $a0, -0x2C50
    ctx->r4 = ADD32(ctx->r4, -0X2C50);
    // 0x800280E0: lw          $v1, 0x54($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X54);
    // 0x800280E4: lbu         $a1, 0xA($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA);
    // 0x800280E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800280EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800280F0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x800280F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800280F8: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
    // 0x800280FC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80028100: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80028104: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80028108: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002810C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80028110: nop

    // 0x80028114: bc1t        L_80028130
    if (c1cs) {
        // 0x80028118: addiu       $a1, $v0, 0x22
        ctx->r5 = ADD32(ctx->r2, 0X22);
            goto L_80028130;
    }
    // 0x80028118: addiu       $a1, $v0, 0x22
    ctx->r5 = ADD32(ctx->r2, 0X22);
    // 0x8002811C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80028120: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80028124: nop

    // 0x80028128: j           L_80028148
    // 0x8002812C: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
        goto L_80028148;
    // 0x8002812C: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80028130:
    // 0x80028130: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80028134: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80028138: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8002813C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80028140: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80028144: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80028148:
    // 0x80028148: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002814C: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80028150: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80028154: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028158: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002815C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80028160: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80028164: nop

    // 0x80028168: bc1t        L_80028184
    if (c1cs) {
        // 0x8002816C: addiu       $a0, $v0, 0x62
        ctx->r4 = ADD32(ctx->r2, 0X62);
            goto L_80028184;
    }
    // 0x8002816C: addiu       $a0, $v0, 0x62
    ctx->r4 = ADD32(ctx->r2, 0X62);
    // 0x80028170: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80028174: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80028178: nop

    // 0x8002817C: j           L_8002819C
    // 0x80028180: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_8002819C;
    // 0x80028180: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_80028184:
    // 0x80028184: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80028188: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002818C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80028190: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80028194: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80028198: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8002819C:
    // 0x8002819C: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800281A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800281A4: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x800281A8: slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800281AC: beql        $v0, $zero, L_800281B4
    if (ctx->r2 == 0) {
        // 0x800281B0: sw          $zero, 0x54($s0)
        MEM_W(0X54, ctx->r16) = 0;
            goto L_800281B4;
    }
    goto skip_0;
    // 0x800281B0: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    skip_0:
L_800281B4:
    // 0x800281B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800281B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800281BC: jr          $ra
    // 0x800281C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800281C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800281C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800281C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800281C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800281CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800281D0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800281D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800281D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800281DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800281E0: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x800281E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800281E8: beq         $v1, $v0, L_80028390
    if (ctx->r3 == ctx->r2) {
        // 0x800281EC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80028390;
    }
    // 0x800281EC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800281F0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800281F4: beql        $v0, $zero, L_8002820C
    if (ctx->r2 == 0) {
        // 0x800281F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002820C;
    }
    goto skip_0;
    // 0x800281F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800281FC: beq         $v1, $zero, L_8002821C
    if (ctx->r3 == 0) {
        // 0x80028200: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002821C;
    }
    // 0x80028200: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80028204: j           L_800284C0
    // 0x80028208: nop

        goto L_800284C0;
    // 0x80028208: nop

L_8002820C:
    // 0x8002820C: beq         $v1, $v0, L_800283DC
    if (ctx->r3 == ctx->r2) {
        // 0x80028210: nop
    
            goto L_800283DC;
    }
    // 0x80028210: nop

    // 0x80028214: j           L_800284C0
    // 0x80028218: nop

        goto L_800284C0;
    // 0x80028218: nop

L_8002821C:
    // 0x8002821C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80028220: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028224: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80028228: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002822C: addiu       $v0, $v0, 0x2A14
    ctx->r2 = ADD32(ctx->r2, 0X2A14);
    // 0x80028230: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80028234: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80028238: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8002823C: sb          $s1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r17;
    // 0x80028240: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x80028244: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80028248: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
    // 0x8002824C: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x80028250: jal         0x8006CEB0
    // 0x80028254: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x80028254: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x80028258: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x8002825C: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x80028260: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028264: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80028268: mfhi        $a2
    ctx->r6 = hi;
    // 0x8002826C: subu        $a0, $a2, $a0
    ctx->r4 = SUB32(ctx->r6, ctx->r4);
    // 0x80028270: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80028274: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80028278: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002827C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028280: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80028284: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80028288: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8002828C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80028290: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80028294: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80028298: lw          $v1, -0x45CC($at)
    ctx->r3 = MEM_W(ctx->r1, -0X45CC);
    // 0x8002829C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800282A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800282A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800282A8: jal         0x800293BC
    // 0x800282AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800293BC(rdram, ctx);
        goto after_1;
    // 0x800282AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800282B0: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x800282B4: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800282B8: bne         $v0, $zero, L_800284C0
    if (ctx->r2 != 0) {
        // 0x800282BC: nop
    
            goto L_800284C0;
    }
    // 0x800282BC: nop

    // 0x800282C0: jal         0x800294E8
    // 0x800282C4: nop

    func_800294E8(rdram, ctx);
        goto after_2;
    // 0x800282C4: nop

    after_2:
    // 0x800282C8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x800282CC: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800282D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800282D4: beq         $v1, $v0, L_800284C0
    if (ctx->r3 == ctx->r2) {
        // 0x800282D8: sw          $zero, 0x54($s0)
        MEM_W(0X54, ctx->r16) = 0;
            goto L_800284C0;
    }
    // 0x800282D8: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x800282DC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800282E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800282E4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800282E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800282EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800282F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800282F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800282F8: sb          $s1, -0x2C50($at)
    MEM_B(-0X2C50, ctx->r1) = ctx->r17;
    // 0x800282FC: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x80028300: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80028304: beql        $v0, $s1, L_8002830C
    if (ctx->r2 == ctx->r17) {
        // 0x80028308: addiu       $s1, $zero, 0x2
        ctx->r17 = ADD32(0, 0X2);
            goto L_8002830C;
    }
    goto skip_1;
    // 0x80028308: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    skip_1:
L_8002830C:
    // 0x8002830C: beq         $s1, $zero, L_800284C0
    if (ctx->r17 == 0) {
        // 0x80028310: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800284C0;
    }
    // 0x80028310: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80028314: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80028318:
    // 0x80028318: jal         0x80012D30
    // 0x8002831C: nop

    func_80012D30(rdram, ctx);
        goto after_3;
    // 0x8002831C: nop

    after_3:
    // 0x80028320: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80028324: beql        $v1, $zero, L_80028380
    if (ctx->r3 == 0) {
        // 0x80028328: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80028380;
    }
    goto skip_2;
    // 0x80028328: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x8002832C: sb          $s3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r19;
    // 0x80028330: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80028334: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80028338: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8002833C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80028340: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80028344: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80028348: sb          $s2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r18;
    // 0x8002834C: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x80028350: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80028354: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x80028358: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x8002835C: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x80028360: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x80028364: sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // 0x80028368: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8002836C: sw          $v0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r2;
    // 0x80028370: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80028374: sw          $s1, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r17;
    // 0x80028378: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8002837C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80028380:
    // 0x80028380: beq         $s1, $zero, L_800284C0
    if (ctx->r17 == 0) {
        // 0x80028384: nop
    
            goto L_800284C0;
    }
    // 0x80028384: nop

    // 0x80028388: j           L_80028318
    // 0x8002838C: nop

        goto L_80028318;
    // 0x8002838C: nop

L_80028390:
    // 0x80028390: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80028394: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80028398: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002839C: nop

    // 0x800283A0: slti        $v0, $v0, 0xD8
    ctx->r2 = SIGNED(ctx->r2) < 0XD8 ? 1 : 0;
    // 0x800283A4: bne         $v0, $zero, L_800283C0
    if (ctx->r2 != 0) {
        // 0x800283A8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800283C0;
    }
    // 0x800283A8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800283AC: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x800283B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800283B4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800283B8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x800283BC: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_800283C0:
    // 0x800283C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800283C4: ldc1        $f2, -0x2A60($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A60);
    // 0x800283C8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800283CC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800283D0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800283D4: j           L_800284C0
    // 0x800283D8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
        goto L_800284C0;
    // 0x800283D8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_800283DC:
    // 0x800283DC: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x800283E0: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x800283E4: lw          $a0, 0xD0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XD0);
    // 0x800283E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800283EC: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800283F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800283F4: bne         $v0, $zero, L_800284A0
    if (ctx->r2 != 0) {
        // 0x800283F8: nop
    
            goto L_800284A0;
    }
    // 0x800283F8: nop

    // 0x800283FC: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80028400: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80028404: bnel        $v1, $zero, L_80028464
    if (ctx->r3 != 0) {
        // 0x80028408: sb          $v1, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r3;
            goto L_80028464;
    }
    goto skip_3;
    // 0x80028408: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    skip_3:
    // 0x8002840C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028410: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80028414: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80028418: lbu         $v1, 0x74($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X74);
    // 0x8002841C: lb          $a0, 0x8($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X8);
    // 0x80028420: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80028424: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80028428: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002842C: lb          $v0, -0x39AF($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X39AF);
    // 0x80028430: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80028434: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80028438: lb          $v1, -0x39B0($at)
    ctx->r3 = MEM_B(ctx->r1, -0X39B0);
    // 0x8002843C: subu        $s1, $a0, $v0
    ctx->r17 = SUB32(ctx->r4, ctx->r2);
    // 0x80028440: nor         $v0, $zero, $s1
    ctx->r2 = ~(0 | ctx->r17);
    // 0x80028444: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80028448: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x8002844C: mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028450: mflo        $v1
    ctx->r3 = lo;
    // 0x80028454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028458: nop

    // 0x8002845C: j           L_800284D8
    // 0x80028460: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
        goto L_800284D8;
    // 0x80028460: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
L_80028464:
    // 0x80028464: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80028468: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8002846C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80028470: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80028474: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80028478: beq         $v0, $zero, L_80028488
    if (ctx->r2 == 0) {
        // 0x8002847C: nop
    
            goto L_80028488;
    }
    // 0x8002847C: nop

    // 0x80028480: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80028484: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80028488:
    // 0x80028488: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8002848C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80028490: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80028494: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80028498: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x8002849C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_800284A0:
    // 0x800284A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800284A4: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800284A8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800284AC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800284B0: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800284B4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800284B8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800284BC: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
L_800284C0:
    // 0x800284C0: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x800284C4: sltiu       $v0, $v1, 0xC9
    ctx->r2 = ctx->r3 < 0XC9 ? 1 : 0;
    // 0x800284C8: bne         $v0, $zero, L_800284D4
    if (ctx->r2 != 0) {
        // 0x800284CC: addiu       $v0, $v1, 0x8
        ctx->r2 = ADD32(ctx->r3, 0X8);
            goto L_800284D4;
    }
    // 0x800284CC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800284D0: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_800284D4:
    // 0x800284D4: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
L_800284D8:
    // 0x800284D8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800284DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800284E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800284E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800284E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800284EC: jr          $ra
    // 0x800284F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800284F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800284F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800284F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800284F8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800284FC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80028500: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80028504: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80028508: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002850C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80028510: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x80028514: lb          $v1, 0x4($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X4);
    // 0x80028518: lw          $s0, 0xD0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XD0);
    // 0x8002851C: bne         $v1, $zero, L_8002860C
    if (ctx->r3 != 0) {
        // 0x80028520: lui         $s3, 0x3B9A
        ctx->r19 = S32(0X3B9A << 16);
            goto L_8002860C;
    }
    // 0x80028520: lui         $s3, 0x3B9A
    ctx->r19 = S32(0X3B9A << 16);
    // 0x80028524: ori         $s3, $s3, 0xC9FF
    ctx->r19 = ctx->r19 | 0XC9FF;
L_80028528:
    // 0x80028528: jal         0x80029348
    // 0x8002852C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80029348(rdram, ctx);
        goto after_0;
    // 0x8002852C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80028530: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80028534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028538: beq         $s2, $v0, L_80028720
    if (ctx->r18 == ctx->r2) {
        // 0x8002853C: nop
    
            goto L_80028720;
    }
    // 0x8002853C: nop

    // 0x80028540: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x80028544: beq         $v0, $zero, L_80028554
    if (ctx->r2 == 0) {
        // 0x80028548: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80028554;
    }
    // 0x80028548: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002854C: j           L_80028564
    // 0x80028550: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
        goto L_80028564;
    // 0x80028550: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
L_80028554:
    // 0x80028554: lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD);
    // 0x80028558: beq         $v0, $zero, L_8002880C
    if (ctx->r2 == 0) {
        // 0x8002855C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8002880C;
    }
    // 0x8002855C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028560: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
L_80028564:
    // 0x80028564: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80028568: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x8002856C: jal         0x8000637C
    // 0x80028570: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x80028570: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
    // 0x80028574: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x80028578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002857C: sb          $v0, 0x5D($s0)
    MEM_B(0X5D, ctx->r16) = ctx->r2;
    // 0x80028580: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80028584: sw          $v1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r3;
    // 0x80028588: sltu        $v1, $s3, $v1
    ctx->r3 = ctx->r19 < ctx->r3 ? 1 : 0;
    // 0x8002858C: bnel        $v1, $zero, L_80028594
    if (ctx->r3 != 0) {
        // 0x80028590: sw          $s3, 0x104($s0)
        MEM_W(0X104, ctx->r16) = ctx->r19;
            goto L_80028594;
    }
    goto skip_0;
    // 0x80028590: sw          $s3, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r19;
    skip_0:
L_80028594:
    // 0x80028594: lbu         $a0, 0x70($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X70);
    // 0x80028598: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002859C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800285A0: beq         $v1, $v0, L_800285AC
    if (ctx->r3 == ctx->r2) {
        // 0x800285A4: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800285AC;
    }
    // 0x800285A4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800285A8: sb          $v0, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r2;
L_800285AC:
    // 0x800285AC: lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X31);
    // 0x800285B0: addu        $a0, $s0, $s2
    ctx->r4 = ADD32(ctx->r16, ctx->r18);
    // 0x800285B4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800285B8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800285BC: sb          $v1, 0x31($s1)
    MEM_B(0X31, ctx->r17) = ctx->r3;
    // 0x800285C0: lbu         $v1, 0xBC($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XBC);
    // 0x800285C4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800285C8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800285CC: sb          $v1, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r3;
    // 0x800285D0: lhu         $v0, 0x8A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8A);
    // 0x800285D4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800285D8: sh          $v0, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r2;
    // 0x800285DC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800285E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800285E4: slti        $v0, $v0, 0x2711
    ctx->r2 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x800285E8: bnel        $v0, $zero, L_800285FC
    if (ctx->r2 != 0) {
        // 0x800285EC: sb          $zero, 0xBC($a0)
        MEM_B(0XBC, ctx->r4) = 0;
            goto L_800285FC;
    }
    goto skip_1;
    // 0x800285EC: sb          $zero, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = 0;
    skip_1:
    // 0x800285F0: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x800285F4: sh          $v0, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r2;
    // 0x800285F8: sb          $zero, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = 0;
L_800285FC:
    // 0x800285FC: jal         0x80029448
    // 0x80028600: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80029448(rdram, ctx);
        goto after_2;
    // 0x80028600: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80028604: j           L_80028528
    // 0x80028608: nop

        goto L_80028528;
    // 0x80028608: nop

L_8002860C:
    // 0x8002860C: ori         $s3, $s3, 0xC9FF
    ctx->r19 = ctx->r19 | 0XC9FF;
L_80028610:
    // 0x80028610: jal         0x80029348
    // 0x80028614: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80029348(rdram, ctx);
        goto after_3;
    // 0x80028614: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80028618: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8002861C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028620: beq         $s2, $v0, L_80028720
    if (ctx->r18 == ctx->r2) {
        // 0x80028624: nop
    
            goto L_80028720;
    }
    // 0x80028624: nop

    // 0x80028628: lbu         $a0, 0xC($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XC);
    // 0x8002862C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80028630: beq         $a2, $zero, L_80028668
    if (ctx->r6 == 0) {
        // 0x80028634: addu        $a1, $s0, $s2
        ctx->r5 = ADD32(ctx->r16, ctx->r18);
            goto L_80028668;
    }
    // 0x80028634: addu        $a1, $s0, $s2
    ctx->r5 = ADD32(ctx->r16, ctx->r18);
    // 0x80028638: lb          $v0, 0xBC($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XBC);
    // 0x8002863C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80028640: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028644: beq         $v0, $zero, L_80028658
    if (ctx->r2 == 0) {
        // 0x80028648: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_80028658;
    }
    // 0x80028648: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x8002864C: sb          $v0, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = ctx->r2;
    // 0x80028650: j           L_800286BC
    // 0x80028654: sb          $zero, 0xC($s1)
    MEM_B(0XC, ctx->r17) = 0;
        goto L_800286BC;
    // 0x80028654: sb          $zero, 0xC($s1)
    MEM_B(0XC, ctx->r17) = 0;
L_80028658:
    // 0x80028658: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x8002865C: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // 0x80028660: j           L_800286BC
    // 0x80028664: sb          $zero, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = 0;
        goto L_800286BC;
    // 0x80028664: sb          $zero, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = 0;
L_80028668:
    // 0x80028668: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8002866C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80028670: beq         $a2, $zero, L_800286A8
    if (ctx->r6 == 0) {
        // 0x80028674: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800286A8;
    }
    // 0x80028674: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80028678: lb          $v0, 0xBC($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XBC);
    // 0x8002867C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80028680: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028684: beq         $v0, $zero, L_80028698
    if (ctx->r2 == 0) {
        // 0x80028688: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_80028698;
    }
    // 0x80028688: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x8002868C: sb          $v0, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = ctx->r2;
    // 0x80028690: j           L_800286BC
    // 0x80028694: sb          $zero, 0xD($s1)
    MEM_B(0XD, ctx->r17) = 0;
        goto L_800286BC;
    // 0x80028694: sb          $zero, 0xD($s1)
    MEM_B(0XD, ctx->r17) = 0;
L_80028698:
    // 0x80028698: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x8002869C: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x800286A0: j           L_800286BC
    // 0x800286A4: sb          $zero, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = 0;
        goto L_800286BC;
    // 0x800286A4: sb          $zero, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = 0;
L_800286A8:
    // 0x800286A8: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800286AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800286B0: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    // 0x800286B4: j           L_80028720
    // 0x800286B8: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
        goto L_80028720;
    // 0x800286B8: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
L_800286BC:
    // 0x800286BC: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x800286C0: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // 0x800286C4: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    // 0x800286C8: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800286CC: bnel        $v0, $zero, L_800286D4
    if (ctx->r2 != 0) {
        // 0x800286D0: sw          $s3, 0x104($s0)
        MEM_W(0X104, ctx->r16) = ctx->r19;
            goto L_800286D4;
    }
    goto skip_2;
    // 0x800286D0: sw          $s3, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r19;
    skip_2:
L_800286D4:
    // 0x800286D4: lbu         $a0, 0x70($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X70);
    // 0x800286D8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800286DC: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800286E0: beq         $v1, $v0, L_800286EC
    if (ctx->r3 == ctx->r2) {
        // 0x800286E4: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800286EC;
    }
    // 0x800286E4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800286E8: sb          $v0, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r2;
L_800286EC:
    // 0x800286EC: lhu         $v0, 0x8A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8A);
    // 0x800286F0: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800286F4: sh          $v0, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r2;
    // 0x800286F8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800286FC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80028700: slti        $v0, $v0, 0x2711
    ctx->r2 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80028704: bne         $v0, $zero, L_80028710
    if (ctx->r2 != 0) {
        // 0x80028708: addiu       $v0, $zero, 0x2710
        ctx->r2 = ADD32(0, 0X2710);
            goto L_80028710;
    }
    // 0x80028708: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x8002870C: sh          $v0, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r2;
L_80028710:
    // 0x80028710: jal         0x80029448
    // 0x80028714: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80029448(rdram, ctx);
        goto after_4;
    // 0x80028714: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80028718: j           L_80028610
    // 0x8002871C: nop

        goto L_80028610;
    // 0x8002871C: nop

L_80028720:
    // 0x80028720: lbu         $v0, 0x9($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X9);
    // 0x80028724: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028728: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // 0x8002872C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80028730: bne         $v0, $zero, L_80028834
    if (ctx->r2 != 0) {
        // 0x80028734: nop
    
            goto L_80028834;
    }
    // 0x80028734: nop

    // 0x80028738: lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD);
    // 0x8002873C: beq         $v0, $zero, L_800287AC
    if (ctx->r2 == 0) {
        // 0x80028740: nop
    
            goto L_800287AC;
    }
    // 0x80028740: nop

    // 0x80028744: jal         0x80012D30
    // 0x80028748: nop

    func_80012D30(rdram, ctx);
        goto after_5;
    // 0x80028748: nop

    after_5:
    // 0x8002874C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80028750: beq         $v1, $zero, L_800287A8
    if (ctx->r3 == 0) {
        // 0x80028754: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800287A8;
    }
    // 0x80028754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028758: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8002875C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80028760: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80028764: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80028768: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002876C: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80028770: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80028774: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x80028778: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8002877C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80028780: sw          $s0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r16;
    // 0x80028784: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x80028788: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
    // 0x8002878C: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x80028790: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x80028794: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x80028798: sb          $zero, 0x31($v1)
    MEM_B(0X31, ctx->r3) = 0;
    // 0x8002879C: sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // 0x800287A0: lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD);
    // 0x800287A4: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
L_800287A8:
    // 0x800287A8: sb          $zero, 0xD($s1)
    MEM_B(0XD, ctx->r17) = 0;
L_800287AC:
    // 0x800287AC: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x800287B0: bne         $v0, $zero, L_8002881C
    if (ctx->r2 != 0) {
        // 0x800287B4: nop
    
            goto L_8002881C;
    }
    // 0x800287B4: nop

    // 0x800287B8: lb          $v0, 0x31($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X31);
    // 0x800287BC: bne         $v0, $zero, L_8002881C
    if (ctx->r2 != 0) {
        // 0x800287C0: nop
    
            goto L_8002881C;
    }
    // 0x800287C0: nop

    // 0x800287C4: lb          $v0, 0x8($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X8);
    // 0x800287C8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800287CC: bne         $v0, $zero, L_800287FC
    if (ctx->r2 != 0) {
        // 0x800287D0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800287FC;
    }
    // 0x800287D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800287D4: lw          $v1, 0x50($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X50);
    // 0x800287D8: beq         $v1, $v0, L_800287FC
    if (ctx->r3 == ctx->r2) {
        // 0x800287DC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800287FC;
    }
    // 0x800287DC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800287E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800287E4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800287E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800287EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800287F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800287F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800287F8: sb          $zero, -0x2C50($at)
    MEM_B(-0X2C50, ctx->r1) = 0;
L_800287FC:
    // 0x800287FC: jal         0x80012D78
    // 0x80028800: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80012D78(rdram, ctx);
        goto after_6;
    // 0x80028800: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x80028804: j           L_80028834
    // 0x80028808: nop

        goto L_80028834;
    // 0x80028808: nop

L_8002880C:
    // 0x8002880C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80028810: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80028814: j           L_80028720
    // 0x80028818: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
        goto L_80028720;
    // 0x80028818: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
L_8002881C:
    // 0x8002881C: lb          $v0, 0x4($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X4);
    // 0x80028820: bne         $v0, $zero, L_8002882C
    if (ctx->r2 != 0) {
        // 0x80028824: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002882C;
    }
    // 0x80028824: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028828: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8002882C:
    // 0x8002882C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80028830: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
L_80028834:
    // 0x80028834: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80028838: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002883C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80028840: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80028844: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80028848: jr          $ra
    // 0x8002884C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002884C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80028850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028858: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002885C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80028860: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80028864: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x80028868: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8002886C: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80028870: beq         $v0, $zero, L_80028CA4
    if (ctx->r2 == 0) {
        // 0x80028874: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028CA4;
    }
    // 0x80028874: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028878: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002887C: addu        $at, $at, $v0
    gpr jr_addend_80028884 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028880: lw          $v0, -0x2A58($at)
    ctx->r2 = ADD32(ctx->r1, -0X2A58);
    // 0x80028884: jr          $v0
    // 0x80028888: nop

    switch (jr_addend_80028884 >> 2) {
        case 0: goto L_8002888C; break;
        case 1: goto L_800288AC; break;
        case 2: goto L_80028938; break;
        case 3: goto L_800289E0; break;
        case 4: goto L_80028BA8; break;
        case 5: goto L_80028C4C; break;
        default: switch_error(__func__, 0x80028884, 0x800AD5A8);
    }
    // 0x80028888: nop

L_8002888C:
    // 0x8002888C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80028890: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80028894: addiu       $v1, $v1, 0x2A74
    ctx->r3 = ADD32(ctx->r3, 0X2A74);
    // 0x80028898: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x8002889C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800288A0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800288A4: j           L_80028BCC
    // 0x800288A8: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
        goto L_80028BCC;
    // 0x800288A8: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
L_800288AC:
    // 0x800288AC: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x800288B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800288B4: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800288B8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800288BC: bne         $v0, $zero, L_80028914
    if (ctx->r2 != 0) {
        // 0x800288C0: nop
    
            goto L_80028914;
    }
    // 0x800288C0: nop

    // 0x800288C4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800288C8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800288CC: beq         $v1, $zero, L_80028BC8
    if (ctx->r3 == 0) {
        // 0x800288D0: nop
    
            goto L_80028BC8;
    }
    // 0x800288D0: nop

    // 0x800288D4: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // 0x800288D8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800288DC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800288E0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800288E4: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800288E8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800288EC: beq         $v0, $zero, L_800288FC
    if (ctx->r2 == 0) {
        // 0x800288F0: nop
    
            goto L_800288FC;
    }
    // 0x800288F0: nop

    // 0x800288F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800288F8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_800288FC:
    // 0x800288FC: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80028900: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80028904: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80028908: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8002890C: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80028910: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80028914:
    // 0x80028914: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80028918: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8002891C: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80028920: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80028924: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80028928: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8002892C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80028930: j           L_80028CA4
    // 0x80028934: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
        goto L_80028CA4;
    // 0x80028934: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
L_80028938:
    // 0x80028938: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8002893C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028940: jal         0x8006CEB0
    // 0x80028944: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x80028944: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    after_0:
    // 0x80028948: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002894C: bltzl       $a0, L_80028954
    if (SIGNED(ctx->r4) < 0) {
        // 0x80028950: addiu       $v0, $a0, 0x3
        ctx->r2 = ADD32(ctx->r4, 0X3);
            goto L_80028954;
    }
    goto skip_0;
    // 0x80028950: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    skip_0:
L_80028954:
    // 0x80028954: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80028958: lb          $v1, 0x8($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X8);
    // 0x8002895C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80028960: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80028964: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80028968: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002896C: slti        $v1, $v1, 0x2
    ctx->r3 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80028970: bne         $v1, $zero, L_80028CA4
    if (ctx->r3 != 0) {
        // 0x80028974: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028CA4;
    }
    // 0x80028974: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80028978: jal         0x80012D30
    // 0x8002897C: nop

    func_80012D30(rdram, ctx);
        goto after_1;
    // 0x8002897C: nop

    after_1:
    // 0x80028980: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80028984: beq         $a0, $zero, L_80028CA4
    if (ctx->r4 == 0) {
        // 0x80028988: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80028CA4;
    }
    // 0x80028988: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002898C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80028990: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80028994: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80028998: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8002899C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800289A0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800289A4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800289A8: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
    // 0x800289AC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800289B0: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800289B4: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x800289B8: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800289BC: sw          $v0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r2;
    // 0x800289C0: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800289C4: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // 0x800289C8: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x800289CC: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x800289D0: sb          $zero, 0x31($a0)
    MEM_B(0X31, ctx->r4) = 0;
    // 0x800289D4: sb          $v1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r3;
    // 0x800289D8: j           L_80028CA4
    // 0x800289DC: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
        goto L_80028CA4;
    // 0x800289DC: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
L_800289E0:
    // 0x800289E0: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x800289E4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800289E8: bne         $v0, $zero, L_80028CA4
    if (ctx->r2 != 0) {
        // 0x800289EC: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028CA4;
    }
    // 0x800289EC: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x800289F0: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x800289F4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800289F8: bne         $v0, $zero, L_80028A10
    if (ctx->r2 != 0) {
        // 0x800289FC: sw          $v1, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r3;
            goto L_80028A10;
    }
    // 0x800289FC: sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
    // 0x80028A00: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80028A04: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x80028A08: j           L_80028BCC
    // 0x80028A0C: sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
        goto L_80028BCC;
    // 0x80028A0C: sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
L_80028A10:
    // 0x80028A10: lhu         $v0, 0x8A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8A);
    // 0x80028A14: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80028A18: sh          $v0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r2;
    // 0x80028A1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80028A20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80028A24: slti        $v0, $v0, -0x2710
    ctx->r2 = SIGNED(ctx->r2) < -0X2710 ? 1 : 0;
    // 0x80028A28: beq         $v0, $zero, L_80028A34
    if (ctx->r2 == 0) {
        // 0x80028A2C: addiu       $v0, $zero, -0x2710
        ctx->r2 = ADD32(0, -0X2710);
            goto L_80028A34;
    }
    // 0x80028A2C: addiu       $v0, $zero, -0x2710
    ctx->r2 = ADD32(0, -0X2710);
    // 0x80028A30: sh          $v0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r2;
L_80028A34:
    // 0x80028A34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80028A38: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80028A3C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80028A40: beq         $v1, $v0, L_80028B40
    if (ctx->r3 == ctx->r2) {
        // 0x80028A44: nop
    
            goto L_80028B40;
    }
    // 0x80028A44: nop

    // 0x80028A48: lb          $v1, 0x8($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X8);
    // 0x80028A4C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80028A50: bne         $v1, $v0, L_80028A68
    if (ctx->r3 != ctx->r2) {
        // 0x80028A54: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80028A68;
    }
    // 0x80028A54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80028A58: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80028A5C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80028A60: j           L_80028A7C
    // 0x80028A64: addiu       $v1, $v1, 0x2AFC
    ctx->r3 = ADD32(ctx->r3, 0X2AFC);
        goto L_80028A7C;
    // 0x80028A64: addiu       $v1, $v1, 0x2AFC
    ctx->r3 = ADD32(ctx->r3, 0X2AFC);
L_80028A68:
    // 0x80028A68: bne         $v1, $v0, L_80028A90
    if (ctx->r3 != ctx->r2) {
        // 0x80028A6C: addiu       $s1, $v1, -0x1
        ctx->r17 = ADD32(ctx->r3, -0X1);
            goto L_80028A90;
    }
    // 0x80028A6C: addiu       $s1, $v1, -0x1
    ctx->r17 = ADD32(ctx->r3, -0X1);
    // 0x80028A70: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80028A74: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80028A78: addiu       $v1, $v1, 0x2ABC
    ctx->r3 = ADD32(ctx->r3, 0X2ABC);
L_80028A7C:
    // 0x80028A7C: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80028A80: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80028A84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028A88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80028A8C: lb          $s1, 0x0($v0)
    ctx->r17 = MEM_B(ctx->r2, 0X0);
L_80028A90:
    // 0x80028A90: bltz        $s1, L_80028B34
    if (SIGNED(ctx->r17) < 0) {
        // 0x80028A94: nop
    
            goto L_80028B34;
    }
    // 0x80028A94: nop

    // 0x80028A98: jal         0x8006CEB0
    // 0x80028A9C: nop

    func_8006CEB0(rdram, ctx);
        goto after_2;
    // 0x80028A9C: nop

    after_2:
    // 0x80028AA0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80028AA4: bltzl       $a0, L_80028AAC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80028AA8: addiu       $v0, $a0, 0xF
        ctx->r2 = ADD32(ctx->r4, 0XF);
            goto L_80028AAC;
    }
    goto skip_1;
    // 0x80028AA8: addiu       $v0, $a0, 0xF
    ctx->r2 = ADD32(ctx->r4, 0XF);
    skip_1:
L_80028AAC:
    // 0x80028AAC: sra         $a1, $v0, 4
    ctx->r5 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80028AB0: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80028AB4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80028AB8: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80028ABC: subu        $a1, $a0, $v0
    ctx->r5 = SUB32(ctx->r4, ctx->r2);
    // 0x80028AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028AC4: bne         $v1, $v0, L_80028AFC
    if (ctx->r3 != ctx->r2) {
        // 0x80028AC8: nop
    
            goto L_80028AFC;
    }
    // 0x80028AC8: nop

    // 0x80028ACC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80028AD0: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80028AD4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80028AD8: beq         $v0, $zero, L_80028AFC
    if (ctx->r2 == 0) {
        // 0x80028ADC: sll         $v1, $s1, 4
        ctx->r3 = S32(ctx->r17 << 4);
            goto L_80028AFC;
    }
    // 0x80028ADC: sll         $v1, $s1, 4
    ctx->r3 = S32(ctx->r17 << 4);
    // 0x80028AE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80028AE4: addiu       $v0, $v0, -0x2448
    ctx->r2 = ADD32(ctx->r2, -0X2448);
    // 0x80028AE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028AEC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80028AF0: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80028AF4: j           L_80028B90
    // 0x80028AF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80028B90;
    // 0x80028AF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80028AFC:
    // 0x80028AFC: lb          $v1, 0x7($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X7);
    // 0x80028B00: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80028B04: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    // 0x80028B08: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028B0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028B10: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80028B14: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80028B18: sll         $v1, $s1, 4
    ctx->r3 = S32(ctx->r17 << 4);
    // 0x80028B1C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80028B20: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80028B24: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80028B28: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80028B2C: j           L_80028B90
    // 0x80028B30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80028B90;
    // 0x80028B30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80028B34:
    // 0x80028B34: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80028B38: j           L_80028B90
    // 0x80028B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80028B90;
    // 0x80028B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80028B40:
    // 0x80028B40: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80028B44: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x80028B48: lb          $v0, 0x11F($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X11F);
    // 0x80028B4C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80028B50: addiu       $a0, $a0, 0x558A
    ctx->r4 = ADD32(ctx->r4, 0X558A);
    // 0x80028B54: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80028B58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80028B5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80028B60: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028B64: lw          $v0, 0x2348($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2348);
    // 0x80028B68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028B6C: lbu         $s1, 0x0($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X0);
    // 0x80028B70: beq         $s1, $zero, L_80028B84
    if (ctx->r17 == 0) {
        // 0x80028B74: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80028B84;
    }
    // 0x80028B74: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80028B78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028B7C: j           L_80028B88
    // 0x80028B80: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80028B88;
    // 0x80028B80: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80028B84:
    // 0x80028B84: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
L_80028B88:
    // 0x80028B88: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80028B8C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_80028B90:
    // 0x80028B90: jal         0x80016804
    // 0x80028B94: nop

    func_80016804(rdram, ctx);
        goto after_3;
    // 0x80028B94: nop

    after_3:
    // 0x80028B98: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x80028B9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028BA0: j           L_80028CA4
    // 0x80028BA4: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
        goto L_80028CA4;
    // 0x80028BA4: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_80028BA8:
    // 0x80028BA8: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x80028BAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028BB0: bne         $v0, $zero, L_80028CA4
    if (ctx->r2 != 0) {
        // 0x80028BB4: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028CA4;
    }
    // 0x80028BB4: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80028BB8: lb          $v1, 0x31($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X31);
    // 0x80028BBC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028BC0: bne         $v1, $zero, L_80028BD8
    if (ctx->r3 != 0) {
        // 0x80028BC4: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028BD8;
    }
    // 0x80028BC4: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
L_80028BC8:
    // 0x80028BC8: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80028BCC:
    // 0x80028BCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028BD0: j           L_80028CA4
    // 0x80028BD4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
        goto L_80028CA4;
    // 0x80028BD4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80028BD8:
    // 0x80028BD8: lhu         $v0, 0x8A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8A);
    // 0x80028BDC: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80028BE0: sh          $v0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r2;
    // 0x80028BE4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80028BE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80028BEC: slti        $v0, $v0, -0x2710
    ctx->r2 = SIGNED(ctx->r2) < -0X2710 ? 1 : 0;
    // 0x80028BF0: beq         $v0, $zero, L_80028BFC
    if (ctx->r2 == 0) {
        // 0x80028BF4: addiu       $v0, $zero, -0x2710
        ctx->r2 = ADD32(0, -0X2710);
            goto L_80028BFC;
    }
    // 0x80028BF4: addiu       $v0, $zero, -0x2710
    ctx->r2 = ADD32(0, -0X2710);
    // 0x80028BF8: sh          $v0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r2;
L_80028BFC:
    // 0x80028BFC: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x80028C00: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80028C04: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80028C08: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80028C0C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80028C10: sb          $v1, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r3;
    // 0x80028C14: lb          $a1, 0x20($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X20);
    // 0x80028C18: slti        $v0, $a1, 0x1F
    ctx->r2 = SIGNED(ctx->r5) < 0X1F ? 1 : 0;
    // 0x80028C1C: beq         $v0, $zero, L_80028C30
    if (ctx->r2 == 0) {
        // 0x80028C20: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80028C30;
    }
    // 0x80028C20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028C24: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80028C28: j           L_80028C34
    // 0x80028C2C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
        goto L_80028C34;
    // 0x80028C2C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
L_80028C30:
    // 0x80028C30: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80028C34:
    // 0x80028C34: jal         0x80016804
    // 0x80028C38: nop

    func_80016804(rdram, ctx);
        goto after_4;
    // 0x80028C38: nop

    after_4:
    // 0x80028C3C: lbu         $v0, 0x31($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X31);
    // 0x80028C40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028C44: j           L_80028CA4
    // 0x80028C48: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
        goto L_80028CA4;
    // 0x80028C48: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
L_80028C4C:
    // 0x80028C4C: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x80028C50: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80028C54: bne         $v0, $zero, L_80028C64
    if (ctx->r2 != 0) {
        // 0x80028C58: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_80028C64;
    }
    // 0x80028C58: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x80028C5C: j           L_80028CA4
    // 0x80028C60: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
        goto L_80028CA4;
    // 0x80028C60: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
L_80028C64:
    // 0x80028C64: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x80028C68: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80028C6C: bne         $v0, $zero, L_80028C9C
    if (ctx->r2 != 0) {
        // 0x80028C70: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80028C9C;
    }
    // 0x80028C70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028C74: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80028C78: beq         $v1, $v0, L_80028C9C
    if (ctx->r3 == ctx->r2) {
        // 0x80028C7C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028C9C;
    }
    // 0x80028C7C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028C80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028C84: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80028C88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028C8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80028C90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80028C94: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028C98: sb          $zero, -0x2C50($at)
    MEM_B(-0X2C50, ctx->r1) = 0;
L_80028C9C:
    // 0x80028C9C: jal         0x80012D78
    // 0x80028CA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80012D78(rdram, ctx);
        goto after_5;
    // 0x80028CA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_80028CA4:
    // 0x80028CA4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80028CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028CAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028CB0: jr          $ra
    // 0x80028CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80028CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80028CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028CB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80028CBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028CC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80028CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028CC8: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x80028CCC: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80028CD0: beq         $v0, $zero, L_80028F20
    if (ctx->r2 == 0) {
        // 0x80028CD4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028F20;
    }
    // 0x80028CD4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028CD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028CDC: addu        $at, $at, $v0
    gpr jr_addend_80028CE4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028CE0: lw          $v0, -0x2A40($at)
    ctx->r2 = ADD32(ctx->r1, -0X2A40);
    // 0x80028CE4: jr          $v0
    // 0x80028CE8: nop

    switch (jr_addend_80028CE4 >> 2) {
        case 0: goto L_80028CEC; break;
        case 1: goto L_80028D0C; break;
        case 2: goto L_80028D98; break;
        case 3: goto L_80028E20; break;
        case 4: goto L_80028E6C; break;
        case 5: goto L_80028EC8; break;
        default: switch_error(__func__, 0x80028CE4, 0x800AD5C0);
    }
    // 0x80028CE8: nop

L_80028CEC:
    // 0x80028CEC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80028CF0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80028CF4: addiu       $v1, $v1, 0x2B3C
    ctx->r3 = ADD32(ctx->r3, 0X2B3C);
    // 0x80028CF8: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80028CFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80028D00: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80028D04: j           L_80028E94
    // 0x80028D08: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
        goto L_80028E94;
    // 0x80028D08: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
L_80028D0C:
    // 0x80028D0C: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x80028D10: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028D14: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x80028D18: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80028D1C: bne         $v0, $zero, L_80028D74
    if (ctx->r2 != 0) {
        // 0x80028D20: nop
    
            goto L_80028D74;
    }
    // 0x80028D20: nop

    // 0x80028D24: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80028D28: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80028D2C: beq         $v1, $zero, L_80028E90
    if (ctx->r3 == 0) {
        // 0x80028D30: nop
    
            goto L_80028E90;
    }
    // 0x80028D30: nop

    // 0x80028D34: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // 0x80028D38: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80028D3C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80028D40: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80028D44: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80028D48: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80028D4C: beq         $v0, $zero, L_80028D5C
    if (ctx->r2 == 0) {
        // 0x80028D50: nop
    
            goto L_80028D5C;
    }
    // 0x80028D50: nop

    // 0x80028D54: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80028D58: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80028D5C:
    // 0x80028D5C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80028D60: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80028D64: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80028D68: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80028D6C: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80028D70: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80028D74:
    // 0x80028D74: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80028D78: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80028D7C: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80028D80: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80028D84: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80028D88: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80028D8C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80028D90: j           L_80028F20
    // 0x80028D94: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
        goto L_80028F20;
    // 0x80028D94: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
L_80028D98:
    // 0x80028D98: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80028D9C: lb          $a0, 0x8($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X8);
    // 0x80028DA0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80028DA4: sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
    // 0x80028DA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028DAC: slti        $a0, $a0, 0x2
    ctx->r4 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80028DB0: bne         $a0, $zero, L_80028F20
    if (ctx->r4 != 0) {
        // 0x80028DB4: sb          $v0, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r2;
            goto L_80028F20;
    }
    // 0x80028DB4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80028DB8: jal         0x80012D30
    // 0x80028DBC: nop

    func_80012D30(rdram, ctx);
        goto after_0;
    // 0x80028DBC: nop

    after_0:
    // 0x80028DC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80028DC4: beq         $a0, $zero, L_80028F20
    if (ctx->r4 == 0) {
        // 0x80028DC8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80028F20;
    }
    // 0x80028DC8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80028DCC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80028DD0: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80028DD4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80028DD8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80028DDC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80028DE0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80028DE4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80028DE8: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
    // 0x80028DEC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80028DF0: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80028DF4: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x80028DF8: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80028DFC: sw          $v0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r2;
    // 0x80028E00: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80028E04: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // 0x80028E08: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x80028E0C: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x80028E10: sb          $zero, 0x31($a0)
    MEM_B(0X31, ctx->r4) = 0;
    // 0x80028E14: sb          $v1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r3;
    // 0x80028E18: j           L_80028F20
    // 0x80028E1C: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
        goto L_80028F20;
    // 0x80028E1C: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
L_80028E20:
    // 0x80028E20: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x80028E24: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028E28: bne         $v0, $zero, L_80028F20
    if (ctx->r2 != 0) {
        // 0x80028E2C: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028F20;
    }
    // 0x80028E2C: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80028E30: lbu         $v1, 0xC($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XC);
    // 0x80028E34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80028E38: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x80028E3C: bne         $a1, $zero, L_80028E50
    if (ctx->r5 != 0) {
        // 0x80028E40: sw          $a0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r4;
            goto L_80028E50;
    }
    // 0x80028E40: sw          $a0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r4;
    // 0x80028E44: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80028E48: j           L_80028E98
    // 0x80028E4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80028E98;
    // 0x80028E4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80028E50:
    // 0x80028E50: sltiu       $v0, $a1, 0x4
    ctx->r2 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x80028E54: bnel        $v0, $zero, L_80028EB8
    if (ctx->r2 != 0) {
        // 0x80028E58: sb          $zero, 0xC($s0)
        MEM_B(0XC, ctx->r16) = 0;
            goto L_80028EB8;
    }
    goto skip_0;
    // 0x80028E58: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    skip_0:
    // 0x80028E5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80028E60: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x80028E64: j           L_80028EB8
    // 0x80028E68: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
        goto L_80028EB8;
    // 0x80028E68: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_80028E6C:
    // 0x80028E6C: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x80028E70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80028E74: bne         $v0, $zero, L_80028F20
    if (ctx->r2 != 0) {
        // 0x80028E78: sw          $v0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r2;
            goto L_80028F20;
    }
    // 0x80028E78: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80028E7C: lb          $a1, 0x31($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X31);
    // 0x80028E80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028E84: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80028E88: bne         $a1, $zero, L_80028EA0
    if (ctx->r5 != 0) {
        // 0x80028E8C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_80028EA0;
    }
    // 0x80028E8C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80028E90:
    // 0x80028E90: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80028E94:
    // 0x80028E94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80028E98:
    // 0x80028E98: j           L_80028F20
    // 0x80028E9C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
        goto L_80028F20;
    // 0x80028E9C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80028EA0:
    // 0x80028EA0: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80028EA4: bnel        $v0, $zero, L_80028EB8
    if (ctx->r2 != 0) {
        // 0x80028EA8: sb          $zero, 0x31($s0)
        MEM_B(0X31, ctx->r16) = 0;
            goto L_80028EB8;
    }
    goto skip_1;
    // 0x80028EA8: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    skip_1:
    // 0x80028EAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80028EB0: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x80028EB4: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
L_80028EB8:
    // 0x80028EB8: jal         0x80016804
    // 0x80028EBC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80016804(rdram, ctx);
        goto after_1;
    // 0x80028EBC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80028EC0: j           L_80028F20
    // 0x80028EC4: nop

        goto L_80028F20;
    // 0x80028EC4: nop

L_80028EC8:
    // 0x80028EC8: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x80028ECC: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80028ED0: bne         $v0, $zero, L_80028EE0
    if (ctx->r2 != 0) {
        // 0x80028ED4: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_80028EE0;
    }
    // 0x80028ED4: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x80028ED8: j           L_80028F20
    // 0x80028EDC: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
        goto L_80028F20;
    // 0x80028EDC: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
L_80028EE0:
    // 0x80028EE0: lb          $v0, 0x8($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X8);
    // 0x80028EE4: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80028EE8: bne         $v0, $zero, L_80028F18
    if (ctx->r2 != 0) {
        // 0x80028EEC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80028F18;
    }
    // 0x80028EEC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028EF0: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80028EF4: beq         $v1, $v0, L_80028F18
    if (ctx->r3 == ctx->r2) {
        // 0x80028EF8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80028F18;
    }
    // 0x80028EF8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80028EFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028F00: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80028F04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80028F08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80028F0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80028F10: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028F14: sb          $zero, -0x2C50($at)
    MEM_B(-0X2C50, ctx->r1) = 0;
L_80028F18:
    // 0x80028F18: jal         0x80012D78
    // 0x80028F1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80012D78(rdram, ctx);
        goto after_2;
    // 0x80028F1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80028F20:
    // 0x80028F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028F28: jr          $ra
    // 0x80028F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80028F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80028F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80028F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028F3C: lb          $v1, 0x1($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1);
    // 0x80028F40: lw          $s0, 0x34($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X34);
    // 0x80028F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028F48: beq         $v1, $v0, L_80028FD0
    if (ctx->r3 == ctx->r2) {
        // 0x80028F4C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80028FD0;
    }
    // 0x80028F4C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80028F50: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80028F54: beql        $v0, $zero, L_80028F6C
    if (ctx->r2 == 0) {
        // 0x80028F58: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80028F6C;
    }
    goto skip_0;
    // 0x80028F58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80028F5C: beq         $v1, $zero, L_80028F84
    if (ctx->r3 == 0) {
        // 0x80028F60: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80028F84;
    }
    // 0x80028F60: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80028F64: j           L_80029150
    // 0x80028F68: nop

        goto L_80029150;
    // 0x80028F68: nop

L_80028F6C:
    // 0x80028F6C: beq         $v1, $v0, L_8002905C
    if (ctx->r3 == ctx->r2) {
        // 0x80028F70: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002905C;
    }
    // 0x80028F70: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80028F74: beq         $v1, $v0, L_80029130
    if (ctx->r3 == ctx->r2) {
        // 0x80028F78: nop
    
            goto L_80029130;
    }
    // 0x80028F78: nop

    // 0x80028F7C: j           L_80029150
    // 0x80028F80: nop

        goto L_80029150;
    // 0x80028F80: nop

L_80028F84:
    // 0x80028F84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80028F88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028F8C: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x80028F90: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x80028F94: sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
    // 0x80028F98: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    // 0x80028F9C: sb          $zero, 0xB($a0)
    MEM_B(0XB, ctx->r4) = 0;
    // 0x80028FA0: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
    // 0x80028FA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80028FA8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80028FAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80028FB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80028FB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80028FB8: lw          $v0, -0x45CC($at)
    ctx->r2 = MEM_W(ctx->r1, -0X45CC);
    // 0x80028FBC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80028FC0: jal         0x800293BC
    // 0x80028FC4: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    func_800293BC(rdram, ctx);
        goto after_0;
    // 0x80028FC4: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    after_0:
    // 0x80028FC8: j           L_80029150
    // 0x80028FCC: nop

        goto L_80029150;
    // 0x80028FCC: nop

L_80028FD0:
    // 0x80028FD0: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80028FD4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80028FD8: beq         $v0, $zero, L_8002900C
    if (ctx->r2 == 0) {
        // 0x80028FDC: addiu       $a1, $zero, 0x126
        ctx->r5 = ADD32(0, 0X126);
            goto L_8002900C;
    }
    // 0x80028FDC: addiu       $a1, $zero, 0x126
    ctx->r5 = ADD32(0, 0X126);
    // 0x80028FE0: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80028FE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80028FE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028FEC: nop

    // 0x80028FF0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80028FF4: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80028FF8: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80028FFC: nop

    // 0x80029000: slti        $v0, $v1, 0x126
    ctx->r2 = SIGNED(ctx->r3) < 0X126 ? 1 : 0;
    // 0x80029004: j           L_80029034
    // 0x80029008: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
        goto L_80029034;
    // 0x80029008: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
L_8002900C:
    // 0x8002900C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80029010: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80029014: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029018: nop

    // 0x8002901C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80029020: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80029024: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80029028: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8002902C: nop

    // 0x80029030: slti        $v1, $v1, 0x1B
    ctx->r3 = SIGNED(ctx->r3) < 0X1B ? 1 : 0;
L_80029034:
    // 0x80029034: beq         $v1, $zero, L_80029150
    if (ctx->r3 == 0) {
        // 0x80029038: swc1        $f2, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
            goto L_80029150;
    }
    // 0x80029038: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8002903C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80029040: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80029044: nop

    // 0x80029048: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002904C: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80029050: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029054: j           L_80029150
    // 0x80029058: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
        goto L_80029150;
    // 0x80029058: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
L_8002905C:
    // 0x8002905C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029060: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80029064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029068: nop

    // 0x8002906C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80029070: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80029074: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x80029078: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x8002907C: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80029080: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80029084: nop

    // 0x80029088: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002908C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80029090: nop

    // 0x80029094: bc1f        L_80029150
    if (!c1cs) {
        // 0x80029098: nop
    
            goto L_80029150;
    }
    // 0x80029098: nop

    // 0x8002909C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800290A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800290A4: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800290A8: lbu         $v1, 0x63($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X63);
    // 0x800290AC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800290B0: sb          $v0, 0x51($s0)
    MEM_B(0X51, ctx->r16) = ctx->r2;
    // 0x800290B4: subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // 0x800290B8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800290BC: nop

    // 0x800290C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800290C4: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800290C8: lbu         $v0, 0xD($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD);
    // 0x800290CC: lbu         $v1, 0x63($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X63);
    // 0x800290D0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800290D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800290D8: sb          $v1, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r3;
    // 0x800290DC: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800290E0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800290E4: jal         0x8000637C
    // 0x800290E8: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x800290E8: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
    // 0x800290EC: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x800290F0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800290F4: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x800290F8: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x800290FC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80029100: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029104: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029108: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002910C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80029110: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029114: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80029118: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x8002911C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80029120: bnel        $v0, $zero, L_80029150
    if (ctx->r2 != 0) {
        // 0x80029124: sb          $v1, 0x63($s0)
        MEM_B(0X63, ctx->r16) = ctx->r3;
            goto L_80029150;
    }
    goto skip_1;
    // 0x80029124: sb          $v1, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r3;
    skip_1:
    // 0x80029128: j           L_80029150
    // 0x8002912C: nop

        goto L_80029150;
    // 0x8002912C: nop

L_80029130:
    // 0x80029130: lbu         $v1, 0xA($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XA);
    // 0x80029134: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80029138: bne         $v0, $zero, L_80029148
    if (ctx->r2 != 0) {
        // 0x8002913C: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_80029148;
    }
    // 0x8002913C: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x80029140: j           L_80029150
    // 0x80029144: sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
        goto L_80029150;
    // 0x80029144: sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
L_80029148:
    // 0x80029148: jal         0x80012D78
    // 0x8002914C: nop

    func_80012D78(rdram, ctx);
        goto after_2;
    // 0x8002914C: nop

    after_2:
L_80029150:
    // 0x80029150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029158: jr          $ra
    // 0x8002915C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002915C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80029160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029168: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002916C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029170: lb          $v1, 0x1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1);
    // 0x80029174: beq         $v1, $zero, L_80029190
    if (ctx->r3 == 0) {
        // 0x80029178: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80029190;
    }
    // 0x80029178: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8002917C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029180: beq         $v1, $v0, L_80029220
    if (ctx->r3 == ctx->r2) {
        // 0x80029184: nop
    
            goto L_80029220;
    }
    // 0x80029184: nop

    // 0x80029188: j           L_80029338
    // 0x8002918C: nop

        goto L_80029338;
    // 0x8002918C: nop

L_80029190:
    // 0x80029190: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029194: ldc1        $f2, -0x2A28($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A28);
    // 0x80029198: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002919C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x800291A0: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800291A4: lw          $v1, 0x58($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X58);
    // 0x800291A8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800291AC: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800291B0: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800291B4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800291B8: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x800291BC: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x800291C0: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x800291C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800291C8: ldc1        $f2, -0x2A20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A20);
    // 0x800291CC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800291D0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800291D4: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x800291D8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800291DC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800291E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800291E4: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800291E8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800291EC: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x800291F0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800291F4: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x800291F8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800291FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80029200: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80029204: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80029208: lw          $v1, -0x45CC($at)
    ctx->r3 = MEM_W(ctx->r1, -0X45CC);
    // 0x8002920C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029210: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029214: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80029218: jal         0x800293BC
    // 0x8002921C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800293BC(rdram, ctx);
        goto after_0;
    // 0x8002921C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_80029220:
    // 0x80029220: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80029224: bltz        $a1, L_80029320
    if (SIGNED(ctx->r5) < 0) {
        // 0x80029228: nop
    
            goto L_80029320;
    }
    // 0x80029228: nop

    // 0x8002922C: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80029230: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80029234: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029238: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8002923C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029240: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80029244: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80029248: addiu       $v1, $v1, -0x2C50
    ctx->r3 = ADD32(ctx->r3, -0X2C50);
    // 0x8002924C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80029250: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80029254: bne         $v0, $zero, L_8002926C
    if (ctx->r2 != 0) {
        // 0x80029258: addu        $v0, $a1, $a0
        ctx->r2 = ADD32(ctx->r5, ctx->r4);
            goto L_8002926C;
    }
    // 0x80029258: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x8002925C: jal         0x80012D78
    // 0x80029260: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80012D78(rdram, ctx);
        goto after_1;
    // 0x80029260: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80029264: j           L_80029338
    // 0x80029268: nop

        goto L_80029338;
    // 0x80029268: nop

L_8002926C:
    // 0x8002926C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029270: ldc1        $f2, -0x2A18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A18);
    // 0x80029274: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80029278: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002927C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80029280: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029284: ldc1        $f2, -0x2A10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2A10);
    // 0x80029288: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x8002928C: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80029290: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80029294: nop

    // 0x80029298: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002929C: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800292A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800292A4: ldc1        $f0, -0x2A08($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2A08);
    // 0x800292A8: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x800292AC: nop

    // 0x800292B0: nop

    // 0x800292B4: bc1tl       L_800292CC
    if (c1cs) {
        // 0x800292B8: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_800292CC;
    }
    goto skip_0;
    // 0x800292B8: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_0:
    // 0x800292BC: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800292C0: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x800292C4: j           L_800292DC
    // 0x800292C8: nop

        goto L_800292DC;
    // 0x800292C8: nop

L_800292CC:
    // 0x800292CC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800292D0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x800292D4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800292D8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800292DC:
    // 0x800292DC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800292E0: sb          $v1, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r3;
    // 0x800292E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800292E8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800292EC: lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X22);
    // 0x800292F0: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800292F4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800292F8: nop

    // 0x800292FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80029300: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80029304: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029308: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8002930C: lhu         $v0, 0x62($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X62);
    // 0x80029310: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80029314: nop

    // 0x80029318: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002931C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_80029320:
    // 0x80029320: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80029324: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029328: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8002932C: slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80029330: beql        $v0, $zero, L_80029338
    if (ctx->r2 == 0) {
        // 0x80029334: sw          $zero, 0x54($s0)
        MEM_W(0X54, ctx->r16) = 0;
            goto L_80029338;
    }
    goto skip_1;
    // 0x80029334: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    skip_1:
L_80029338:
    // 0x80029338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002933C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029340: jr          $ra
    // 0x80029344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80029344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80029348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002934C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80029350: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80029354: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80029358: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002935C: lb          $a0, 0xCD($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XCD);
L_80029360:
    // 0x80029360: jal         0x800293B0
    // 0x80029364: nop

    func_800293B0(rdram, ctx);
        goto after_0;
    // 0x80029364: nop

    after_0:
    // 0x80029368: lb          $a0, 0xCC($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XCC);
    // 0x8002936C: jal         0x800293B0
    // 0x80029370: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_800293B0(rdram, ctx);
        goto after_1;
    // 0x80029370: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80029374: beq         $s0, $v0, L_80029398
    if (ctx->r16 == ctx->r2) {
        // 0x80029378: addu        $v0, $s1, $s0
        ctx->r2 = ADD32(ctx->r17, ctx->r16);
            goto L_80029398;
    }
    // 0x80029378: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x8002937C: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x80029380: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80029384: slti        $v0, $v0, 0x22
    ctx->r2 = SIGNED(ctx->r2) < 0X22 ? 1 : 0;
    // 0x80029388: bne         $v0, $zero, L_8002939C
    if (ctx->r2 != 0) {
        // 0x8002938C: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8002939C;
    }
    // 0x8002938C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80029390: j           L_80029360
    // 0x80029394: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80029360;
    // 0x80029394: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80029398:
    // 0x80029398: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002939C:
    // 0x8002939C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800293A0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800293A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800293A8: jr          $ra
    // 0x800293AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800293AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800293B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293B0: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800293B4: jr          $ra
    // 0x800293B8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    return;
    // 0x800293B8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
;}
RECOMP_FUNC void func_800293BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293BC: sw          $a1, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r5;
    // 0x800293C0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800293C4: sb          $v0, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r2;
    // 0x800293C8: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800293CC: sb          $v0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r2;
    // 0x800293D0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800293D4: jr          $ra
    // 0x800293D8: sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
    return;
    // 0x800293D8: sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800293DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293DC: lbu         $v0, 0x64($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X64);
    // 0x800293E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800293E4: sb          $v0, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r2;
    // 0x800293E8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800293EC: bne         $v0, $zero, L_80029440
    if (ctx->r2 != 0) {
        // 0x800293F0: nop
    
            goto L_80029440;
    }
    // 0x800293F0: nop

    // 0x800293F4: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x800293F8: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x800293FC: sw          $a1, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r5;
    // 0x80029400: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x80029404: bgez        $v0, L_8002941C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80029408: nop
    
            goto L_8002941C;
    }
    // 0x80029408: nop

    // 0x8002940C: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x80029410: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029414: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80029418: sw          $v0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r2;
L_8002941C:
    // 0x8002941C: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80029420: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80029424: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80029428: sb          $v0, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r2;
    // 0x8002942C: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80029430: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80029434: sb          $v0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r2;
    // 0x80029438: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8002943C: sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
L_80029440:
    // 0x80029440: jr          $ra
    // 0x80029444: nop

    return;
    // 0x80029444: nop

;}
RECOMP_FUNC void func_80029448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029448: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8002944C: lb          $a1, 0xCC($a2)
    ctx->r5 = MEM_B(ctx->r6, 0XCC);
    // 0x80029450: lb          $v0, 0xCD($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XCD);
    // 0x80029454: lbu         $a0, 0xCD($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XCD);
    // 0x80029458: beq         $a1, $v0, L_800294DC
    if (ctx->r5 == ctx->r2) {
        // 0x8002945C: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_800294DC;
    }
    // 0x8002945C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029460: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
L_80029464:
    // 0x80029464: lb          $v0, 0xBC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XBC);
    // 0x80029468: bne         $v0, $zero, L_800294C8
    if (ctx->r2 != 0) {
        // 0x8002946C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_800294C8;
    }
    // 0x8002946C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80029470: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80029474: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80029478: beq         $a1, $v0, L_800294AC
    if (ctx->r5 == ctx->r2) {
        // 0x8002947C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800294AC;
    }
    // 0x8002947C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80029480: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80029484: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_80029488:
    // 0x80029488: lb          $v0, 0xBC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XBC);
    // 0x8002948C: bne         $v0, $zero, L_800294A0
    if (ctx->r2 != 0) {
        // 0x80029490: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800294A0;
    }
    // 0x80029490: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80029494: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x80029498: bne         $v1, $a0, L_80029488
    if (ctx->r3 != ctx->r4) {
        // 0x8002949C: addu        $v0, $a2, $v1
        ctx->r2 = ADD32(ctx->r6, ctx->r3);
            goto L_80029488;
    }
    // 0x8002949C: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_800294A0:
    // 0x800294A0: lb          $v0, 0xCD($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XCD);
    // 0x800294A4: bne         $v1, $v0, L_800294B4
    if (ctx->r3 != ctx->r2) {
        // 0x800294A8: addu        $a0, $a2, $v1
        ctx->r4 = ADD32(ctx->r6, ctx->r3);
            goto L_800294B4;
    }
    // 0x800294A8: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
L_800294AC:
    // 0x800294AC: j           L_800294DC
    // 0x800294B0: sb          $a1, 0xCD($a2)
    MEM_B(0XCD, ctx->r6) = ctx->r5;
        goto L_800294DC;
    // 0x800294B0: sb          $a1, 0xCD($a2)
    MEM_B(0XCD, ctx->r6) = ctx->r5;
L_800294B4:
    // 0x800294B4: lbu         $v1, 0xBC($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XBC);
    // 0x800294B8: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x800294BC: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
    // 0x800294C0: sb          $zero, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = 0;
    // 0x800294C4: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_800294C8:
    // 0x800294C8: lb          $v1, 0xCD($a2)
    ctx->r3 = MEM_B(ctx->r6, 0XCD);
    // 0x800294CC: andi        $a1, $v0, 0xF
    ctx->r5 = ctx->r2 & 0XF;
    // 0x800294D0: lbu         $a0, 0xCD($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XCD);
    // 0x800294D4: bne         $a1, $v1, L_80029464
    if (ctx->r5 != ctx->r3) {
        // 0x800294D8: addu        $v0, $a2, $a1
        ctx->r2 = ADD32(ctx->r6, ctx->r5);
            goto L_80029464;
    }
    // 0x800294D8: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
L_800294DC:
    // 0x800294DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800294E0: jr          $ra
    // 0x800294E4: nop

    return;
    // 0x800294E4: nop

;}
RECOMP_FUNC void func_800294E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800294E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800294EC: addiu       $v1, $v1, -0x2C50
    ctx->r3 = ADD32(ctx->r3, -0X2C50);
    // 0x800294F0: addiu       $a1, $v1, 0x510
    ctx->r5 = ADD32(ctx->r3, 0X510);
    // 0x800294F4: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800294F8: beq         $v0, $zero, L_80029520
    if (ctx->r2 == 0) {
        // 0x800294FC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80029520;
    }
    // 0x800294FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80029500:
    // 0x80029500: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80029504: bnel        $v0, $zero, L_80029514
    if (ctx->r2 != 0) {
        // 0x80029508: addiu       $v1, $v1, 0xA2
        ctx->r3 = ADD32(ctx->r3, 0XA2);
            goto L_80029514;
    }
    goto skip_0;
    // 0x80029508: addiu       $v1, $v1, 0xA2
    ctx->r3 = ADD32(ctx->r3, 0XA2);
    skip_0:
    // 0x8002950C: j           L_80029524
    // 0x80029510: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_80029524;
    // 0x80029510: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_80029514:
    // 0x80029514: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80029518: bne         $v0, $zero, L_80029500
    if (ctx->r2 != 0) {
        // 0x8002951C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80029500;
    }
    // 0x8002951C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80029520:
    // 0x80029520: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029524:
    // 0x80029524: jr          $ra
    // 0x80029528: nop

    return;
    // 0x80029528: nop

;}
RECOMP_FUNC void func_80029530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029534: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80029538: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002953C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029540: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80029544: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80029548: lw          $v0, 0x2B90($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2B90);
    // 0x8002954C: jalr        $v0
    // 0x80029550: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80029550: nop

    after_0:
    // 0x80029554: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80029558: jr          $ra
    // 0x8002955C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002955C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80029560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029564: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029568: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002956C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029570: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80029574: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80029578: bne         $v0, $zero, L_80029588
    if (ctx->r2 != 0) {
        // 0x8002957C: addiu       $a3, $a3, 0x79F0
        ctx->r7 = ADD32(ctx->r7, 0X79F0);
            goto L_80029588;
    }
    // 0x8002957C: addiu       $a3, $a3, 0x79F0
    ctx->r7 = ADD32(ctx->r7, 0X79F0);
    // 0x80029580: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80029584: addiu       $a3, $a3, 0x25A0
    ctx->r7 = ADD32(ctx->r7, 0X25A0);
L_80029588:
    // 0x80029588: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8002958C: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80029590: beq         $v0, $zero, L_80029B94
    if (ctx->r2 == 0) {
        // 0x80029594: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80029B94;
    }
    // 0x80029594: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80029598: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002959C: addu        $at, $at, $v0
    gpr jr_addend_800295A4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800295A0: lw          $v0, -0x2A00($at)
    ctx->r2 = ADD32(ctx->r1, -0X2A00);
    // 0x800295A4: jr          $v0
    // 0x800295A8: nop

    switch (jr_addend_800295A4 >> 2) {
        case 0: goto L_800295AC; break;
        case 1: goto L_80029630; break;
        case 2: goto L_80029694; break;
        case 3: goto L_800297AC; break;
        case 4: goto L_800297D8; break;
        case 5: goto L_80029874; break;
        case 6: goto L_80029958; break;
        case 7: goto L_80029A54; break;
        case 8: goto L_80029AD8; break;
        case 9: goto L_80029B74; break;
        default: switch_error(__func__, 0x800295A4, 0x800AD600);
    }
    // 0x800295A8: nop

L_800295AC:
    // 0x800295AC: lui         $at, 0x438F
    ctx->r1 = S32(0X438F << 16);
    // 0x800295B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800295B4: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800295B8: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x800295BC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800295C0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800295C4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800295C8: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x800295CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800295D0: bne         $v1, $zero, L_800295E4
    if (ctx->r3 != 0) {
        // 0x800295D4: sb          $v0, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r2;
            goto L_800295E4;
    }
    // 0x800295D4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800295D8: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x800295DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800295E0: nop

L_800295E4:
    // 0x800295E4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800295E8: lbu         $v1, 0x74($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X74);
    // 0x800295EC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800295F0: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x800295F4: lbu         $a0, 0x64($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X64);
    // 0x800295F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800295FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029600: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029604: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029608: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8002960C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029610: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80029614: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x80029618: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002961C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80029620: nop

    // 0x80029624: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80029628: j           L_80029B94
    // 0x8002962C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
        goto L_80029B94;
    // 0x8002962C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
L_80029630:
    // 0x80029630: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80029634: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80029638: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8002963C: slti        $v0, $v0, 0xF1
    ctx->r2 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x80029640: bne         $v0, $zero, L_80029B94
    if (ctx->r2 != 0) {
        // 0x80029644: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_80029B94;
    }
    // 0x80029644: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80029648: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8002964C: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x80029650: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80029654: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80029658: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x8002965C: lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // 0x80029660: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80029664: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80029668: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002966C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80029670: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80029674: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80029678: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8002967C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80029680: sb          $a2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r6;
    // 0x80029684: jal         0x8000637C
    // 0x80029688: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x80029688: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    after_0:
    // 0x8002968C: j           L_80029B94
    // 0x80029690: nop

        goto L_80029B94;
    // 0x80029690: nop

L_80029694:
    // 0x80029694: lui         $at, 0x477F
    ctx->r1 = S32(0X477F << 16);
    // 0x80029698: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8002969C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800296A0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800296A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800296A8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800296AC: lh          $v0, 0x24($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X24);
    // 0x800296B0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800296B4: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x800296B8: bltzl       $v0, L_800296C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800296BC: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_800296C0;
    }
    goto skip_0;
    // 0x800296BC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_800296C0:
    // 0x800296C0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800296C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800296C8: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800296CC: slti        $v1, $v1, 0x2
    ctx->r3 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800296D0: bne         $v1, $zero, L_80029748
    if (ctx->r3 != 0) {
        // 0x800296D4: swc1        $f2, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
            goto L_80029748;
    }
    // 0x800296D4: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x800296D8: jal         0x80012D8C
    // 0x800296DC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    func_80012D8C(rdram, ctx);
        goto after_1;
    // 0x800296DC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    after_1:
    // 0x800296E0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800296E4: beq         $a0, $zero, L_80029748
    if (ctx->r4 == 0) {
        // 0x800296E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029748;
    }
    // 0x800296E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800296EC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800296F0: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800296F4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800296F8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800296FC: bnel        $v0, $zero, L_80029718
    if (ctx->r2 != 0) {
        // 0x80029700: swc1        $f2, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
            goto L_80029718;
    }
    goto skip_1;
    // 0x80029700: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x80029704: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80029708: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002970C: nop

    // 0x80029710: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80029714: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
L_80029718:
    // 0x80029718: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002971C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80029720: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029724: nop

    // 0x80029728: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002972C: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80029730: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80029734: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80029738: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8002973C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80029740: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80029744: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
L_80029748:
    // 0x80029748: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8002974C: bne         $v0, $zero, L_80029770
    if (ctx->r2 != 0) {
        // 0x80029750: nop
    
            goto L_80029770;
    }
    // 0x80029750: nop

    // 0x80029754: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80029758: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8002975C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029760: nop

    // 0x80029764: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80029768: j           L_8002978C
    // 0x8002976C: nop

        goto L_8002978C;
    // 0x8002976C: nop

L_80029770:
    // 0x80029770: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80029774: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x80029778: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002977C: nop

    // 0x80029780: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80029784: nop

    // 0x80029788: nop

L_8002978C:
    // 0x8002978C: bc1t        L_80029798
    if (c1cs) {
        // 0x80029790: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029798;
    }
    // 0x80029790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029794: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80029798:
    // 0x80029798: beq         $v0, $zero, L_80029B94
    if (ctx->r2 == 0) {
        // 0x8002979C: addiu       $v1, $zero, 0x1E
        ctx->r3 = ADD32(0, 0X1E);
            goto L_80029B94;
    }
    // 0x8002979C: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x800297A0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800297A4: j           L_80029B30
    // 0x800297A8: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
        goto L_80029B30;
    // 0x800297A8: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
L_800297AC:
    // 0x800297AC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800297B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800297B4: bne         $v0, $zero, L_800297C8
    if (ctx->r2 != 0) {
        // 0x800297B8: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_800297C8;
    }
    // 0x800297B8: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800297BC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800297C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800297C4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_800297C8:
    // 0x800297C8: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800297CC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800297D0: j           L_80029B94
    // 0x800297D4: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
        goto L_80029B94;
    // 0x800297D4: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_800297D8:
    // 0x800297D8: lb          $v1, 0x59($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X59);
    // 0x800297DC: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x800297E0: bne         $v1, $v0, L_80029B94
    if (ctx->r3 != ctx->r2) {
        // 0x800297E4: nop
    
            goto L_80029B94;
    }
    // 0x800297E4: nop

    // 0x800297E8: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800297EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800297F0: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800297F4: lbu         $v1, 0x74($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X74);
    // 0x800297F8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800297FC: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80029800: lbu         $a0, 0x64($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X64);
    // 0x80029804: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80029808: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002980C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029810: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029814: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80029818: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002981C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80029820: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x80029824: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029828: bltzl       $v0, L_80029830
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002982C: addiu       $v0, $v0, 0x7
        ctx->r2 = ADD32(ctx->r2, 0X7);
            goto L_80029830;
    }
    goto skip_2;
    // 0x8002982C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    skip_2:
L_80029830:
    // 0x80029830: sra         $a1, $v0, 3
    ctx->r5 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80029834: blez        $a1, L_80029B94
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80029838: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80029B94;
    }
    // 0x80029838: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8002983C:
    // 0x8002983C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80029840:
    // 0x80029840: lw          $v0, 0xB0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB0);
    // 0x80029844: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80029848: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002984C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029850: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x80029854: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80029858: bne         $v0, $zero, L_80029840
    if (ctx->r2 != 0) {
        // 0x8002985C: nop
    
            goto L_80029840;
    }
    // 0x8002985C: nop

    // 0x80029860: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80029864: bgtz        $a1, L_8002983C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80029868: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_8002983C;
    }
    // 0x80029868: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x8002986C: j           L_80029B94
    // 0x80029870: nop

        goto L_80029B94;
    // 0x80029870: nop

L_80029874:
    // 0x80029874: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80029878: bne         $v0, $zero, L_800298EC
    if (ctx->r2 != 0) {
        // 0x8002987C: nop
    
            goto L_800298EC;
    }
    // 0x8002987C: nop

    // 0x80029880: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80029884: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x80029888: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002988C: nop

    // 0x80029890: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80029894: nop

    // 0x80029898: bc1f        L_800298B4
    if (!c1cs) {
        // 0x8002989C: nop
    
            goto L_800298B4;
    }
    // 0x8002989C: nop

    // 0x800298A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800298A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800298A8: nop

    // 0x800298AC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800298B0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_800298B4:
    // 0x800298B4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800298B8: addiu       $v0, $v0, -0x2D8
    ctx->r2 = ADD32(ctx->r2, -0X2D8);
    // 0x800298BC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800298C0: slti        $v0, $v0, -0x3FFF
    ctx->r2 = SIGNED(ctx->r2) < -0X3FFF ? 1 : 0;
    // 0x800298C4: beq         $v0, $zero, L_80029B94
    if (ctx->r2 == 0) {
        // 0x800298C8: nop
    
            goto L_80029B94;
    }
    // 0x800298C8: nop

    // 0x800298CC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800298D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800298D4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800298D8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800298DC: sb          $v0, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r2;
    // 0x800298E0: addiu       $v0, $zero, -0x3FFF
    ctx->r2 = ADD32(0, -0X3FFF);
    // 0x800298E4: j           L_80029B94
    // 0x800298E8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_80029B94;
    // 0x800298E8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800298EC:
    // 0x800298EC: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800298F0: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    // 0x800298F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800298F8: nop

    // 0x800298FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80029900: nop

    // 0x80029904: bc1f        L_80029920
    if (!c1cs) {
        // 0x80029908: nop
    
            goto L_80029920;
    }
    // 0x80029908: nop

    // 0x8002990C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80029910: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029914: nop

    // 0x80029918: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8002991C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_80029920:
    // 0x80029920: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80029924: addiu       $v0, $v0, 0x2D8
    ctx->r2 = ADD32(ctx->r2, 0X2D8);
    // 0x80029928: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8002992C: slti        $v0, $v0, 0x4000
    ctx->r2 = SIGNED(ctx->r2) < 0X4000 ? 1 : 0;
    // 0x80029930: bne         $v0, $zero, L_80029B94
    if (ctx->r2 != 0) {
        // 0x80029934: nop
    
            goto L_80029B94;
    }
    // 0x80029934: nop

    // 0x80029938: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8002993C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029940: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80029944: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80029948: sb          $v0, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r2;
    // 0x8002994C: addiu       $v0, $zero, 0x3FFF
    ctx->r2 = ADD32(0, 0X3FFF);
    // 0x80029950: j           L_80029B94
    // 0x80029954: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_80029B94;
    // 0x80029954: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80029958:
    // 0x80029958: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002995C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80029960: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029964: nop

    // 0x80029968: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002996C: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80029970: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029974: nop

    // 0x80029978: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002997C: nop

    // 0x80029980: nop

    // 0x80029984: bc1f        L_80029B94
    if (!c1cs) {
        // 0x80029988: swc1        $f0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
            goto L_80029B94;
    }
    // 0x80029988: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8002998C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029990: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80029994: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029998: bne         $v1, $zero, L_800299B8
    if (ctx->r3 != 0) {
        // 0x8002999C: sb          $v0, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r2;
            goto L_800299B8;
    }
    // 0x8002999C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800299A0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800299A4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800299A8: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x800299AC: nop

    // 0x800299B0: j           L_800299C8
    // 0x800299B4: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_800299C8;
    // 0x800299B4: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_800299B8:
    // 0x800299B8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800299BC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800299C0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x800299C4: addiu       $v0, $zero, 0x126
    ctx->r2 = ADD32(0, 0X126);
L_800299C8:
    // 0x800299C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800299CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800299D0: bltzl       $v0, L_800299D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800299D4: addiu       $v0, $v0, 0x1F
        ctx->r2 = ADD32(ctx->r2, 0X1F);
            goto L_800299D8;
    }
    goto skip_3;
    // 0x800299D4: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    skip_3:
L_800299D8:
    // 0x800299D8: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800299DC: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800299E0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800299E4: lbu         $v1, 0x74($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X74);
    // 0x800299E8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800299EC: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x800299F0: lbu         $a0, 0x64($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X64);
    // 0x800299F4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800299F8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800299FC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80029A00: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029A04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029A08: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029A0C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80029A10: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029A14: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80029A18: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x80029A1C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80029A20: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029A24: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80029A28: bltzl       $v0, L_80029A30
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029A2C: addiu       $v0, $v0, 0x1F
        ctx->r2 = ADD32(ctx->r2, 0X1F);
            goto L_80029A30;
    }
    goto skip_4;
    // 0x80029A2C: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    skip_4:
L_80029A30:
    // 0x80029A30: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80029A34: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80029A38: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80029A3C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80029A40: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80029A44: jal         0x8000637C
    // 0x80029A48: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80029A48: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    after_2:
    // 0x80029A4C: j           L_80029B94
    // 0x80029A50: nop

        goto L_80029B94;
    // 0x80029A50: nop

L_80029A54:
    // 0x80029A54: lui         $at, 0x477F
    ctx->r1 = S32(0X477F << 16);
    // 0x80029A58: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80029A5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029A60: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80029A64: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80029A68: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80029A6C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80029A70: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029A74: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80029A78: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80029A7C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80029A80: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80029A84: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80029A88: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80029A8C: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x80029A90: bne         $v0, $zero, L_80029AA4
    if (ctx->r2 != 0) {
        // 0x80029A94: swc1        $f0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
            goto L_80029AA4;
    }
    // 0x80029A94: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80029A98: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80029A9C: j           L_80029AAC
    // 0x80029AA0: addiu       $v0, $v0, -0x71C
    ctx->r2 = ADD32(ctx->r2, -0X71C);
        goto L_80029AAC;
    // 0x80029AA0: addiu       $v0, $v0, -0x71C
    ctx->r2 = ADD32(ctx->r2, -0X71C);
L_80029AA4:
    // 0x80029AA4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80029AA8: addiu       $v0, $v0, 0x71C
    ctx->r2 = ADD32(ctx->r2, 0X71C);
L_80029AAC:
    // 0x80029AAC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80029AB0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80029AB4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029AB8: bne         $v0, $zero, L_80029B94
    if (ctx->r2 != 0) {
        // 0x80029ABC: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80029B94;
    }
    // 0x80029ABC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80029AC0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029AC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029AC8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80029ACC: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x80029AD0: j           L_80029B94
    // 0x80029AD4: sb          $v0, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r2;
        goto L_80029B94;
    // 0x80029AD4: sb          $v0, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r2;
L_80029AD8:
    // 0x80029AD8: lbu         $v1, 0x66($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X66);
    // 0x80029ADC: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x80029AE0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029AE4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80029AE8: nop

    // 0x80029AEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80029AF0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80029AF4: lbu         $v1, 0x74($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X74);
    // 0x80029AF8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80029AFC: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80029B00: lbu         $a0, 0x64($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X64);
    // 0x80029B04: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80029B08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80029B0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029B10: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80029B14: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80029B18: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80029B1C: lbu         $v1, 0x66($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X66);
    // 0x80029B20: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80029B24: bne         $v1, $v0, L_80029B3C
    if (ctx->r3 != ctx->r2) {
        // 0x80029B28: nop
    
            goto L_80029B3C;
    }
    // 0x80029B28: nop

    // 0x80029B2C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80029B30:
    // 0x80029B30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029B34: j           L_80029B94
    // 0x80029B38: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
        goto L_80029B94;
    // 0x80029B38: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80029B3C:
    // 0x80029B3C: lw          $v0, 0xD0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XD0);
    // 0x80029B40: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80029B44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80029B48: bne         $v1, $v0, L_80029B94
    if (ctx->r3 != ctx->r2) {
        // 0x80029B4C: nop
    
            goto L_80029B94;
    }
    // 0x80029B4C: nop

    // 0x80029B50: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029B54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80029B58: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80029B5C: lbu         $v1, 0x64($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X64);
    // 0x80029B60: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80029B64: bne         $v0, $zero, L_80029B94
    if (ctx->r2 != 0) {
        // 0x80029B68: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80029B94;
    }
    // 0x80029B68: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80029B6C: j           L_80029B94
    // 0x80029B70: sb          $v0, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r2;
        goto L_80029B94;
    // 0x80029B70: sb          $v0, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r2;
L_80029B74:
    // 0x80029B74: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80029B78: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80029B7C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80029B80: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80029B84: beq         $v0, $zero, L_80029B94
    if (ctx->r2 == 0) {
        // 0x80029B88: nop
    
            goto L_80029B94;
    }
    // 0x80029B88: nop

    // 0x80029B8C: jal         0x80012DD4
    // 0x80029B90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80012DD4(rdram, ctx);
        goto after_3;
    // 0x80029B90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_80029B94:
    // 0x80029B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029B98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029B9C: jr          $ra
    // 0x80029BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80029BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80029BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029BA8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80029BAC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80029BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029BB4: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x80029BB8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80029BBC: beq         $v0, $zero, L_80029C6C
    if (ctx->r2 == 0) {
        // 0x80029BC0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80029C6C;
    }
    // 0x80029BC0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80029BC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029BC8: addu        $at, $at, $v0
    gpr jr_addend_80029BD0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80029BCC: lw          $v0, -0x29D8($at)
    ctx->r2 = ADD32(ctx->r1, -0X29D8);
    // 0x80029BD0: jr          $v0
    // 0x80029BD4: nop

    switch (jr_addend_80029BD0 >> 2) {
        case 0: goto L_80029BD8; break;
        case 1: goto L_80029BF8; break;
        case 2: goto L_80029C1C; break;
        case 3: goto L_80029C38; break;
        case 4: goto L_80029C64; break;
        default: switch_error(__func__, 0x80029BD0, 0x800AD628);
    }
    // 0x80029BD4: nop

L_80029BD8:
    // 0x80029BD8: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80029BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029BE0: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80029BE4: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80029BE8: sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // 0x80029BEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80029BF0: j           L_80029C6C
    // 0x80029BF4: sb          $v1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r3;
        goto L_80029C6C;
    // 0x80029BF4: sb          $v1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r3;
L_80029BF8:
    // 0x80029BF8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80029BFC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80029C00: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80029C04: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x80029C08: bne         $v0, $zero, L_80029C6C
    if (ctx->r2 != 0) {
        // 0x80029C0C: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_80029C6C;
    }
    // 0x80029C0C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80029C10: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029C14: j           L_80029C58
    // 0x80029C18: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
        goto L_80029C58;
    // 0x80029C18: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
L_80029C1C:
    // 0x80029C1C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80029C20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029C24: bne         $v0, $zero, L_80029C6C
    if (ctx->r2 != 0) {
        // 0x80029C28: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80029C6C;
    }
    // 0x80029C28: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80029C2C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029C30: j           L_80029C5C
    // 0x80029C34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80029C5C;
    // 0x80029C34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80029C38:
    // 0x80029C38: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80029C3C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80029C40: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80029C44: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80029C48: beq         $v0, $zero, L_80029C6C
    if (ctx->r2 == 0) {
        // 0x80029C4C: nop
    
            goto L_80029C6C;
    }
    // 0x80029C4C: nop

    // 0x80029C50: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80029C54: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_80029C58:
    // 0x80029C58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80029C5C:
    // 0x80029C5C: j           L_80029C6C
    // 0x80029C60: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
        goto L_80029C6C;
    // 0x80029C60: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80029C64:
    // 0x80029C64: jal         0x80012DD4
    // 0x80029C68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x80029C68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_80029C6C:
    // 0x80029C6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80029C70: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80029C74: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80029C78: beq         $v0, $zero, L_80029C98
    if (ctx->r2 == 0) {
        // 0x80029C7C: nop
    
            goto L_80029C98;
    }
    // 0x80029C7C: nop

    // 0x80029C80: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80029C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80029C88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029C8C: nop

    // 0x80029C90: j           L_80029CAC
    // 0x80029C94: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80029CAC;
    // 0x80029C94: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_80029C98:
    // 0x80029C98: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80029C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80029CA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029CA4: nop

    // 0x80029CA8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80029CAC:
    // 0x80029CAC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80029CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029CB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80029CB8: jr          $ra
    // 0x80029CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80029CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80029CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CC0: jr          $ra
    // 0x80029CC4: nop

    return;
    // 0x80029CC4: nop

;}
RECOMP_FUNC void func_80029CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CC8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80029CCC: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80029CD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80029CD4: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x80029CD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029CDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029CE0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80029CE4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80029CE8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80029CEC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80029CF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80029CF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80029CF8: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x80029CFC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80029D00: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80029D04: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80029D08: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80029D0C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80029D10: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80029D14: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80029D18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80029D1C: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    // 0x80029D20: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80029D24: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x80029D28: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80029D2C: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, 0X1230);
    // 0x80029D30: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80029D34: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x80029D38: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80029D3C: addiu       $v0, $v0, -0x7540
    ctx->r2 = ADD32(ctx->r2, -0X7540);
    // 0x80029D40: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80029D44: addu        $s4, $a0, $v0
    ctx->r20 = ADD32(ctx->r4, ctx->r2);
    // 0x80029D48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80029D4C: addiu       $v0, $v0, 0x26E0
    ctx->r2 = ADD32(ctx->r2, 0X26E0);
    // 0x80029D50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80029D54: slti        $a1, $a1, 0x4C
    ctx->r5 = SIGNED(ctx->r5) < 0X4C ? 1 : 0;
    // 0x80029D58: beq         $a1, $zero, L_80029F78
    if (ctx->r5 == 0) {
        // 0x80029D5C: addu        $s3, $a0, $v1
        ctx->r19 = ADD32(ctx->r4, ctx->r3);
            goto L_80029F78;
    }
    // 0x80029D5C: addu        $s3, $a0, $v1
    ctx->r19 = ADD32(ctx->r4, ctx->r3);
    // 0x80029D60: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80029D64: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80029D68: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80029D6C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x80029D70: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029D74: jal         0x800178E0
    // 0x80029D78: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    func_800178E0(rdram, ctx);
        goto after_0;
    // 0x80029D78: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    after_0:
    // 0x80029D7C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80029D80: jal         0x80018514
    // 0x80029D84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x80029D84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80029D88: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80029D8C: beq         $v0, $zero, L_80029D9C
    if (ctx->r2 == 0) {
        // 0x80029D90: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80029D9C;
    }
    // 0x80029D90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80029D94: j           L_80029DA0
    // 0x80029D98: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
        goto L_80029DA0;
    // 0x80029D98: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
L_80029D9C:
    // 0x80029D9C: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
L_80029DA0:
    // 0x80029DA0: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80029DA4: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x80029DA8: lui         $t0, 0xFC11
    ctx->r8 = S32(0XFC11 << 16);
    // 0x80029DAC: ori         $t0, $t0, 0x9623
    ctx->r8 = ctx->r8 | 0X9623;
    // 0x80029DB0: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x80029DB4: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80029DB8: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80029DBC: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x80029DC0: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x80029DC4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80029DC8: ori         $t1, $t1, 0x4240
    ctx->r9 = ctx->r9 | 0X4240;
    // 0x80029DCC: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x80029DD0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029DD4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80029DD8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80029DDC: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80029DE0: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x80029DE4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029DE8: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // 0x80029DEC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80029DF0: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x80029DF4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80029DF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029DFC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E00: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80029E04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E08: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E0C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80029E10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E18: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80029E1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E24: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80029E28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E30: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029E34: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80029E38: nop

    // 0x80029E3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029E40: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80029E44: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
    // 0x80029E48: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80029E4C: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x80029E50: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80029E54: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x80029E58: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80029E5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80029E60: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80029E64: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80029E68: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80029E6C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80029E70: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x80029E74: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
    // 0x80029E78: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x80029E7C: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80029E80: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    // 0x80029E84: ori         $a2, $a2, 0x17
    ctx->r6 = ctx->r6 | 0X17;
    // 0x80029E88: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80029E8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E90: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029E94: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x80029E98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029E9C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029EA0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80029EA4: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x80029EA8: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x80029EAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029EB0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029EB4: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x80029EB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029EBC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029EC0: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x80029EC4: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x80029EC8: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x80029ECC: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x80029ED0: sw          $a2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r6;
    // 0x80029ED4: sw          $s3, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r19;
    // 0x80029ED8: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
    // 0x80029EDC: sw          $s4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r20;
    // 0x80029EE0: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80029EE4: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x80029EE8: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // 0x80029EEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029EF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029EF4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80029EF8: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x80029EFC: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x80029F00: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x80029F04: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x80029F08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029F0C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029F10: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80029F14: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x80029F18: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x80029F1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029F20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029F24: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x80029F28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029F2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029F30: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80029F34: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x80029F38: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x80029F3C: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x80029F40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029F44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80029F48: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80029F4C: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x80029F50: sw          $s1, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r17;
    // 0x80029F54: sw          $s2, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r18;
    // 0x80029F58: sw          $t3, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r11;
    // 0x80029F5C: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x80029F60: sw          $a1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r5;
    // 0x80029F64: sw          $a1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r5;
    // 0x80029F68: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x80029F6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029F70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80029F74: sw          $a0, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r4;
L_80029F78:
    // 0x80029F78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80029F7C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80029F80: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80029F84: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029F88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029F90: jr          $ra
    // 0x80029F94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80029F94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80029FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029FA4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80029FA8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80029FAC: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80029FB0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80029FB4: bne         $v0, $zero, L_80029FC4
    if (ctx->r2 != 0) {
        // 0x80029FB8: addiu       $a2, $a2, 0x79F0
        ctx->r6 = ADD32(ctx->r6, 0X79F0);
            goto L_80029FC4;
    }
    // 0x80029FB8: addiu       $a2, $a2, 0x79F0
    ctx->r6 = ADD32(ctx->r6, 0X79F0);
    // 0x80029FBC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80029FC0: addiu       $a2, $a2, 0x25A0
    ctx->r6 = ADD32(ctx->r6, 0X25A0);
L_80029FC4:
    // 0x80029FC4: lb          $v1, 0x2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X2);
    // 0x80029FC8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80029FCC: beq         $v0, $zero, L_8002A0E8
    if (ctx->r2 == 0) {
        // 0x80029FD0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8002A0E8;
    }
    // 0x80029FD0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80029FD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029FD8: addu        $at, $at, $v0
    gpr jr_addend_80029FE0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80029FDC: lw          $v0, -0x29C0($at)
    ctx->r2 = ADD32(ctx->r1, -0X29C0);
    // 0x80029FE0: jr          $v0
    // 0x80029FE4: nop

    switch (jr_addend_80029FE0 >> 2) {
        case 0: goto L_80029FE8; break;
        case 1: goto L_80029FFC; break;
        case 2: goto L_8002A07C; break;
        case 3: goto L_8002A094; break;
        case 4: goto L_8002A0E0; break;
        default: switch_error(__func__, 0x80029FE0, 0x800AD640);
    }
    // 0x80029FE4: nop

L_80029FE8:
    // 0x80029FE8: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x80029FEC: sw          $zero, 0x20($a1)
    MEM_W(0X20, ctx->r5) = 0;
    // 0x80029FF0: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x80029FF4: j           L_8002A0D4
    // 0x80029FF8: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
        goto L_8002A0D4;
    // 0x80029FF8: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
L_80029FFC:
    // 0x80029FFC: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x8002A000: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    // 0x8002A004: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002A008: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A00C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8002A010: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x8002A014: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002A018: nop

    // 0x8002A01C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A020: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8002A024: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8002A028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A02C: nop

    // 0x8002A030: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8002A034: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
    // 0x8002A038: nop

    // 0x8002A03C: bc1f        L_8002A0E8
    if (!c1cs) {
        // 0x8002A040: sw          $a0, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r4;
            goto L_8002A0E8;
    }
    // 0x8002A040: sw          $a0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r4;
    // 0x8002A044: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002A048: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8002A04C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002A050: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A054: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x8002A058: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002A05C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002A060: nop

    // 0x8002A064: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A068: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8002A06C: lbu         $v0, 0x59($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X59);
    // 0x8002A070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A074: j           L_8002A0E8
    // 0x8002A078: sb          $v0, 0x59($a2)
    MEM_B(0X59, ctx->r6) = ctx->r2;
        goto L_8002A0E8;
    // 0x8002A078: sb          $v0, 0x59($a2)
    MEM_B(0X59, ctx->r6) = ctx->r2;
L_8002A07C:
    // 0x8002A07C: lb          $v1, 0x59($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X59);
    // 0x8002A080: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8002A084: beq         $v1, $v0, L_8002A0D0
    if (ctx->r3 == ctx->r2) {
        // 0x8002A088: nop
    
            goto L_8002A0D0;
    }
    // 0x8002A088: nop

    // 0x8002A08C: j           L_8002A0E8
    // 0x8002A090: nop

        goto L_8002A0E8;
    // 0x8002A090: nop

L_8002A094:
    // 0x8002A094: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002A098: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002A09C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A0A0: nop

    // 0x8002A0A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002A0A8: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8002A0AC: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002A0B0: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8002A0B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002A0B8: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x8002A0BC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8002A0C0: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x8002A0C4: nop

    // 0x8002A0C8: bc1f        L_8002A0E8
    if (!c1cs) {
        // 0x8002A0CC: sw          $v0, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r2;
            goto L_8002A0E8;
    }
    // 0x8002A0CC: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
L_8002A0D0:
    // 0x8002A0D0: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
L_8002A0D4:
    // 0x8002A0D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A0D8: j           L_8002A0E8
    // 0x8002A0DC: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
        goto L_8002A0E8;
    // 0x8002A0DC: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
L_8002A0E0:
    // 0x8002A0E0: jal         0x80012DD4
    // 0x8002A0E4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002A0E4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_8002A0E8:
    // 0x8002A0E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A0EC: jr          $ra
    // 0x8002A0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002A0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002A0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0F4: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x8002A0F8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8002A0FC: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x8002A100: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x8002A104: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8002A108: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8002A10C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002A110: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x8002A114: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8002A118: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x8002A11C: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x8002A120: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8002A124: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x8002A128: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x8002A12C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A130: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8002A134: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8002A138: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002A13C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A140: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002A144: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8002A148: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A14C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A150: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002A154: lw          $v0, -0x4038($at)
    ctx->r2 = MEM_W(ctx->r1, -0X4038);
    // 0x8002A158: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x8002A15C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A160: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8002A164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002A168: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002A16C: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8002A170: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002A174: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002A178: addiu       $v0, $a2, 0x18
    ctx->r2 = ADD32(ctx->r6, 0X18);
    // 0x8002A17C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8002A180: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002A184: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002A188: addiu       $v0, $a2, 0x20
    ctx->r2 = ADD32(ctx->r6, 0X20);
    // 0x8002A18C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002A190: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002A194: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002A198: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8002A19C: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A1A0: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8002A1A4: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8002A1A8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002A1AC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002A1B0: nop

    // 0x8002A1B4: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8002A1B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A1BC: lui         $a1, 0xF600
    ctx->r5 = S32(0XF600 << 16);
    // 0x8002A1C0: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8002A1C4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002A1C8: sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    // 0x8002A1CC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8002A1D0: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A1D4: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A1D8: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8002A1DC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002A1E0: nop

    // 0x8002A1E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A1E8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8002A1EC: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002A1F0: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8002A1F4: nop

    // 0x8002A1F8: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8002A1FC: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8002A200: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002A204: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002A208: nop

    // 0x8002A20C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8002A210: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A214: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002A218: jr          $ra
    // 0x8002A21C: sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
    return;
    // 0x8002A21C: sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void func_8002A220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A224: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A228: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002A22C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A230: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A234: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002A238: lw          $v0, 0x2BA0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2BA0);
    // 0x8002A23C: jalr        $v0
    // 0x8002A240: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002A240: nop

    after_0:
    // 0x8002A244: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A248: jr          $ra
    // 0x8002A24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002A24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002A250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A250: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002A254: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002A258: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8002A25C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002A260: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002A264: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002A268: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002A26C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002A270: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002A274: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002A278: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002A27C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002A280: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x8002A284: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x8002A288: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8002A28C: lb          $v1, 0x3($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X3);
    // 0x8002A290: beq         $v1, $zero, L_8002A2AC
    if (ctx->r3 == 0) {
        // 0x8002A294: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8002A2AC;
    }
    // 0x8002A294: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8002A298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A29C: beq         $v1, $v0, L_8002A308
    if (ctx->r3 == ctx->r2) {
        // 0x8002A2A0: addiu       $s4, $zero, 0x2A
        ctx->r20 = ADD32(0, 0X2A);
            goto L_8002A308;
    }
    // 0x8002A2A0: addiu       $s4, $zero, 0x2A
    ctx->r20 = ADD32(0, 0X2A);
    // 0x8002A2A4: j           L_8002A540
    // 0x8002A2A8: nop

        goto L_8002A540;
    // 0x8002A2A8: nop

L_8002A2AC:
    // 0x8002A2AC: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8002A2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A2B4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8002A2B8: jal         0x80066C48
    // 0x8002A2BC: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x8002A2BC: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    after_0:
    // 0x8002A2C0: blez        $v0, L_8002A2F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002A2C4: sw          $v0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r2;
            goto L_8002A2F4;
    }
    // 0x8002A2C4: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8002A2C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8002A2CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002A2D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8002A2D4: addiu       $v1, $v1, -0x32D0
    ctx->r3 = ADD32(ctx->r3, -0X32D0);
L_8002A2D8:
    // 0x8002A2D8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8002A2DC: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
    // 0x8002A2E0: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x8002A2E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002A2E8: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002A2EC: bne         $v0, $zero, L_8002A2D8
    if (ctx->r2 != 0) {
        // 0x8002A2F0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8002A2D8;
    }
    // 0x8002A2F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8002A2F4:
    // 0x8002A2F4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8002A2F8: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x8002A2FC: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x8002A300: j           L_8002A540
    // 0x8002A304: sb          $zero, 0x8($s2)
    MEM_B(0X8, ctx->r18) = 0;
        goto L_8002A540;
    // 0x8002A304: sb          $zero, 0x8($s2)
    MEM_B(0X8, ctx->r18) = 0;
L_8002A308:
    // 0x8002A308: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A30C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A310: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002A314: lui         $at, 0x3F19
    ctx->r1 = S32(0X3F19 << 16);
    // 0x8002A318: ori         $at, $at, 0x999A
    ctx->r1 = ctx->r1 | 0X999A;
    // 0x8002A31C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002A320: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A324: lw          $s6, 0x18($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X18);
    // 0x8002A328: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8002A32C: beq         $v0, $zero, L_8002A348
    if (ctx->r2 == 0) {
        // 0x8002A330: addiu       $fp, $zero, 0x6
        ctx->r30 = ADD32(0, 0X6);
            goto L_8002A348;
    }
    // 0x8002A330: addiu       $fp, $zero, 0x6
    ctx->r30 = ADD32(0, 0X6);
    // 0x8002A334: lui         $at, 0x3FE6
    ctx->r1 = S32(0X3FE6 << 16);
    // 0x8002A338: ori         $at, $at, 0x6667
    ctx->r1 = ctx->r1 | 0X6667;
    // 0x8002A33C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002A340: addiu       $s4, $zero, 0x7E
    ctx->r20 = ADD32(0, 0X7E);
    // 0x8002A344: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8002A348:
    // 0x8002A348: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x8002A34C: blez        $v0, L_8002A440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002A350: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8002A440;
    }
    // 0x8002A350: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8002A354: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A358: ldc1        $f20, -0x29A0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X29A0);
    // 0x8002A35C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A360: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002A364: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x8002A368: subu        $s7, $s5, $s4
    ctx->r23 = SUB32(ctx->r21, ctx->r20);
    // 0x8002A36C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8002A370: addiu       $s0, $s0, -0x32D0
    ctx->r16 = ADD32(ctx->r16, -0X32D0);
    // 0x8002A374: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
L_8002A378:
    // 0x8002A378: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A37C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002A380: c.eq.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d == ctx->f20.d;
    // 0x8002A384: nop

    // 0x8002A388: bc1t        L_8002A3E8
    if (c1cs) {
        // 0x8002A38C: nop
    
            goto L_8002A3E8;
    }
    // 0x8002A38C: nop

    // 0x8002A390: sub.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f22.fl;
    // 0x8002A394: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002A398: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    // 0x8002A39C: nop

    // 0x8002A3A0: nop

    // 0x8002A3A4: bc1f        L_8002A3E8
    if (!c1cs) {
        // 0x8002A3A8: swc1        $f2, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
            goto L_8002A3E8;
    }
    // 0x8002A3A8: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x8002A3AC: swc1        $f24, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f24.u32l;
    // 0x8002A3B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002A3B4: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8002A3B8: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x8002A3BC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A3C0: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002A3C4: bne         $v0, $zero, L_8002A3E8
    if (ctx->r2 != 0) {
        // 0x8002A3C8: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8002A3E8;
    }
    // 0x8002A3C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8002A3CC: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8002A3D0: beq         $v1, $v0, L_8002A3E8
    if (ctx->r3 == ctx->r2) {
        // 0x8002A3D4: nop
    
            goto L_8002A3E8;
    }
    // 0x8002A3D4: nop

    // 0x8002A3D8: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x8002A3DC: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8002A3E0: jal         0x8000637C
    // 0x8002A3E4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8002A3E4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
L_8002A3E8:
    // 0x8002A3E8: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8002A3EC: slt         $v0, $s7, $v1
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002A3F0: beq         $v0, $zero, L_8002A400
    if (ctx->r2 == 0) {
        // 0x8002A3F4: addu        $v0, $v1, $s4
        ctx->r2 = ADD32(ctx->r3, ctx->r20);
            goto L_8002A400;
    }
    // 0x8002A3F4: addu        $v0, $v1, $s4
    ctx->r2 = ADD32(ctx->r3, ctx->r20);
    // 0x8002A3F8: j           L_8002A404
    // 0x8002A3FC: sb          $s5, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r21;
        goto L_8002A404;
    // 0x8002A3FC: sb          $s5, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r21;
L_8002A400:
    // 0x8002A400: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
L_8002A404:
    // 0x8002A404: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A408: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A40C: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002A410: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A414: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002A418: beql        $v0, $zero, L_8002A42C
    if (ctx->r2 == 0) {
        // 0x8002A41C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8002A42C;
    }
    goto skip_0;
    // 0x8002A41C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x8002A420: swc1        $f24, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f24.u32l;
    // 0x8002A424: sb          $s5, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r21;
    // 0x8002A428: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002A42C:
    // 0x8002A42C: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x8002A430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002A434: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002A438: bne         $v0, $zero, L_8002A378
    if (ctx->r2 != 0) {
        // 0x8002A43C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002A378;
    }
    // 0x8002A43C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8002A440:
    // 0x8002A440: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x8002A444: bne         $v0, $zero, L_8002A468
    if (ctx->r2 != 0) {
        // 0x8002A448: nop
    
            goto L_8002A468;
    }
    // 0x8002A448: nop

    // 0x8002A44C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A450: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A454: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002A458: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A45C: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002A460: beq         $v0, $zero, L_8002A470
    if (ctx->r2 == 0) {
        // 0x8002A464: nop
    
            goto L_8002A470;
    }
    // 0x8002A464: nop

L_8002A468:
    // 0x8002A468: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x8002A46C: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
L_8002A470:
    // 0x8002A470: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x8002A474: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x8002A478: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002A47C: beq         $v0, $zero, L_8002A4B8
    if (ctx->r2 == 0) {
        // 0x8002A480: nop
    
            goto L_8002A4B8;
    }
    // 0x8002A480: nop

    // 0x8002A484: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x8002A488: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002A48C: bne         $v0, $zero, L_8002A4B8
    if (ctx->r2 != 0) {
        // 0x8002A490: sw          $v0, 0x24($s2)
        MEM_W(0X24, ctx->r18) = ctx->r2;
            goto L_8002A4B8;
    }
    // 0x8002A490: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x8002A494: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
    // 0x8002A498: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8002A49C:
    // 0x8002A49C: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x8002A4A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A4A4: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x8002A4A8: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x8002A4AC: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x8002A4B0: beq         $v0, $v1, L_8002A49C
    if (ctx->r2 == ctx->r3) {
        // 0x8002A4B4: nop
    
            goto L_8002A49C;
    }
    // 0x8002A4B4: nop

L_8002A4B8:
    // 0x8002A4B8: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x8002A4BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8002A4C0: addiu       $v1, $v1, -0x32D0
    ctx->r3 = ADD32(ctx->r3, -0X32D0);
    // 0x8002A4C4: addiu       $s1, $v0, -0x1
    ctx->r17 = ADD32(ctx->r2, -0X1);
    // 0x8002A4C8: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8002A4CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002A4D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002A4D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A4D8: ldc1        $f2, -0x2998($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2998);
    // 0x8002A4DC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A4E0: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x8002A4E4: nop

    // 0x8002A4E8: bc1f        L_8002A540
    if (!c1cs) {
        // 0x8002A4EC: nop
    
            goto L_8002A540;
    }
    // 0x8002A4EC: nop

    // 0x8002A4F0: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x8002A4F4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002A4F8: bne         $v1, $v0, L_8002A540
    if (ctx->r3 != ctx->r2) {
        // 0x8002A4FC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002A540;
    }
    // 0x8002A4FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002A500: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8002A504: sb          $v1, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r3;
    // 0x8002A508: sw          $v0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r2;
    // 0x8002A50C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002A510: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8002A514: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x8002A518: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A51C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002A520: sb          $v1, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = ctx->r3;
    // 0x8002A524: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002A528: beq         $v0, $zero, L_8002A540
    if (ctx->r2 == 0) {
        // 0x8002A52C: nop
    
            goto L_8002A540;
    }
    // 0x8002A52C: nop

    // 0x8002A530: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x8002A534: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8002A538: jal         0x8000637C
    // 0x8002A53C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x8002A53C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_2:
L_8002A540:
    // 0x8002A540: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A544: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002A548: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002A54C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002A550: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A554: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002A558: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002A55C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002A560: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A564: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002A568: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x8002A56C: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x8002A570: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8002A574: jr          $ra
    // 0x8002A578: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002A578: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002A57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A57C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002A580: lbu         $v1, 0x7B93($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B93);
    // 0x8002A584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A588: bne         $v1, $v0, L_8002A5A8
    if (ctx->r3 != ctx->r2) {
        // 0x8002A58C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002A5A8;
    }
    // 0x8002A58C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002A590: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x8002A594: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8002A598: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8002A59C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002A5A0: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8002A5A4: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
L_8002A5A8:
    // 0x8002A5A8: jr          $ra
    // 0x8002A5AC: nop

    return;
    // 0x8002A5AC: nop

;}
RECOMP_FUNC void func_8002A5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A5B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A5B4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8002A5B8: lb          $v1, 0x3($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X3);
    // 0x8002A5BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A5C0: beq         $v1, $v0, L_8002A60C
    if (ctx->r3 == ctx->r2) {
        // 0x8002A5C4: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8002A60C;
    }
    // 0x8002A5C4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8002A5C8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002A5CC: beql        $v0, $zero, L_8002A5E4
    if (ctx->r2 == 0) {
        // 0x8002A5D0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002A5E4;
    }
    goto skip_0;
    // 0x8002A5D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002A5D4: beq         $v1, $zero, L_8002A5F4
    if (ctx->r3 == 0) {
        // 0x8002A5D8: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8002A5F4;
    }
    // 0x8002A5D8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002A5DC: j           L_8002A674
    // 0x8002A5E0: nop

        goto L_8002A674;
    // 0x8002A5E0: nop

L_8002A5E4:
    // 0x8002A5E4: beq         $v1, $v0, L_8002A668
    if (ctx->r3 == ctx->r2) {
        // 0x8002A5E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002A668;
    }
    // 0x8002A5E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002A5EC: j           L_8002A674
    // 0x8002A5F0: nop

        goto L_8002A674;
    // 0x8002A5F0: nop

L_8002A5F4:
    // 0x8002A5F4: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // 0x8002A5F8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8002A5FC: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8002A600: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002A604: j           L_8002A674
    // 0x8002A608: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
        goto L_8002A674;
    // 0x8002A608: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
L_8002A60C:
    // 0x8002A60C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A610: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A614: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002A618: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A61C: addiu       $a2, $zero, 0xF5C
    ctx->r6 = ADD32(0, 0XF5C);
    // 0x8002A620: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8002A624: beq         $v0, $zero, L_8002A634
    if (ctx->r2 == 0) {
        // 0x8002A628: addiu       $a1, $zero, 0x2A
        ctx->r5 = ADD32(0, 0X2A);
            goto L_8002A634;
    }
    // 0x8002A628: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8002A62C: addiu       $a2, $zero, 0x2E14
    ctx->r6 = ADD32(0, 0X2E14);
    // 0x8002A630: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
L_8002A634:
    // 0x8002A634: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8002A638: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8002A63C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8002A640: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8002A644: sw          $v1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r3;
    // 0x8002A648: slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002A64C: beq         $v1, $zero, L_8002A674
    if (ctx->r3 == 0) {
        // 0x8002A650: sw          $v0, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->r2;
            goto L_8002A674;
    }
    // 0x8002A650: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8002A654: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002A658: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8002A65C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A660: j           L_8002A674
    // 0x8002A664: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
        goto L_8002A674;
    // 0x8002A664: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_8002A668:
    // 0x8002A668: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002A66C: jal         0x80012DD4
    // 0x8002A670: sb          $v0, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = ctx->r2;
    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002A670: sb          $v0, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = ctx->r2;
    after_0:
L_8002A674:
    // 0x8002A674: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002A678: jr          $ra
    // 0x8002A67C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002A67C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002A680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A684: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A688: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002A68C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A690: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A694: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002A698: lw          $v0, 0x2BAC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2BAC);
    // 0x8002A69C: jalr        $v0
    // 0x8002A6A0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002A6A0: nop

    after_0:
    // 0x8002A6A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A6A8: jr          $ra
    // 0x8002A6AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002A6AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002A6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A6B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A6B4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8002A6B8: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A6BC: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A6C0: lb          $a3, 0x2B($a0)
    ctx->r7 = MEM_B(ctx->r4, 0X2B);
    // 0x8002A6C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8002A6C8: addiu       $v0, $v0, -0x32D0
    ctx->r2 = ADD32(ctx->r2, -0X32D0);
    // 0x8002A6CC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8002A6D0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x8002A6D4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002A6D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002A6DC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002A6E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A6E4: jal         0x8002A79C
    // 0x8002A6E8: nop

    func_8002A79C(rdram, ctx);
        goto after_0;
    // 0x8002A6E8: nop

    after_0:
    // 0x8002A6EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002A6F0: jr          $ra
    // 0x8002A6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002A6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002A6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A6FC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8002A700: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A704: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002A708: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002A70C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8002A710: lw          $a3, 0x28($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X28);
    // 0x8002A714: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002A718: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002A71C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002A720: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A724: jal         0x8004DAB8
    // 0x8002A728: nop

    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8002A728: nop

    after_0:
    // 0x8002A72C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A730: jr          $ra
    // 0x8002A734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002A734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002A738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A738: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002A73C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002A744: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8002A748: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8002A74C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8002A750: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A754: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002A758: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8002A75C: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002A760: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A764: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8002A768: lbu         $v0, 0x23($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X23);
    // 0x8002A76C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002A770: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x8002A774: lw          $a3, 0x28($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X28);
    // 0x8002A778: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002A77C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002A780: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002A784: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A788: jal         0x8004E008
    // 0x8002A78C: nop

    func_8004E008(rdram, ctx);
        goto after_0;
    // 0x8002A78C: nop

    after_0:
    // 0x8002A790: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8002A794: jr          $ra
    // 0x8002A798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002A798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002A79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A79C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002A7A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002A7A4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002A7A8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002A7AC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002A7B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002A7B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002A7B8: sb          $zero, 0x21($sp)
    MEM_B(0X21, ctx->r29) = 0;
    // 0x8002A7BC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002A7C0: beq         $v0, $zero, L_8002A820
    if (ctx->r2 == 0) {
        // 0x8002A7C4: addu        $s4, $a2, $zero
        ctx->r20 = ADD32(ctx->r6, 0);
            goto L_8002A820;
    }
    // 0x8002A7C4: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8002A7C8: sll         $s3, $a3, 24
    ctx->r19 = S32(ctx->r7 << 24);
    // 0x8002A7CC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002A7D0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8002A7D4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
L_8002A7D8:
    // 0x8002A7D8: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8002A7DC: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x8002A7E0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A7E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002A7E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A7EC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A7F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002A7F4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8002A7F8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8002A7FC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8002A800: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x8002A804: sra         $a3, $s3, 24
    ctx->r7 = S32(SIGNED(ctx->r19) >> 24);
    // 0x8002A808: jal         0x8004E008
    // 0x8002A80C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8004E008(rdram, ctx);
        goto after_0;
    // 0x8002A80C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002A810: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x8002A814: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002A818: bne         $v0, $zero, L_8002A7D8
    if (ctx->r2 != 0) {
        // 0x8002A81C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8002A7D8;
    }
    // 0x8002A81C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002A820:
    // 0x8002A820: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A824: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002A828: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002A82C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002A830: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A834: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002A838: jr          $ra
    // 0x8002A83C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002A83C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8002A840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002A844: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002A848: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002A84C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002A850: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002A854: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002A858: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8002A85C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002A860: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8002A864: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002A868: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002A86C: jal         0x80012D8C
    // 0x8002A870: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x8002A870: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    after_0:
    // 0x8002A874: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002A878: beq         $v1, $zero, L_8002A8D8
    if (ctx->r3 == 0) {
        // 0x8002A87C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A8D8;
    }
    // 0x8002A87C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A880: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8002A884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002A888: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8002A88C: sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17 << 24);
    // 0x8002A890: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002A894: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x8002A898: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
    // 0x8002A89C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002A8A0: mtc1        $s3, $f0
    ctx->f0.u32l = ctx->r19;
    // 0x8002A8A4: nop

    // 0x8002A8A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A8AC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002A8B0: mtc1        $s4, $f0
    ctx->f0.u32l = ctx->r20;
    // 0x8002A8B4: nop

    // 0x8002A8B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A8BC: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8002A8C0: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8002A8C4: sw          $s0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r16;
    // 0x8002A8C8: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8002A8CC: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x8002A8D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002A8D4: sb          $zero, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = 0;
L_8002A8D8:
    // 0x8002A8D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002A8DC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002A8E0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002A8E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002A8EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002A8F0: jr          $ra
    // 0x8002A8F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002A8F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002A900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A904: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002A908: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002A90C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002A910: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002A914: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002A918: lw          $v0, 0x2BC0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2BC0);
    // 0x8002A91C: jalr        $v0
    // 0x8002A920: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002A920: nop

    after_0:
    // 0x8002A924: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002A928: jr          $ra
    // 0x8002A92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002A92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002A930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A930: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002A934: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002A938: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x8002A93C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A940: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A944: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8002A948: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8002A94C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002A950: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002A954: bne         $v0, $zero, L_8002A964
    if (ctx->r2 != 0) {
        // 0x8002A958: nop
    
            goto L_8002A964;
    }
    // 0x8002A958: nop

    // 0x8002A95C: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x8002A960: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8002A964:
    // 0x8002A964: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002A968: lb          $v1, 0x5($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X5);
    // 0x8002A96C: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8002A970: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8002A974: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x8002A978: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002A97C: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    // 0x8002A980: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002A984: nop

    // 0x8002A988: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002A98C: bne         $v1, $zero, L_8002A9A0
    if (ctx->r3 != 0) {
        // 0x8002A990: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002A9A0;
    }
    // 0x8002A990: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002A994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A998: j           L_8002A9A4
    // 0x8002A99C: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
        goto L_8002A9A4;
    // 0x8002A99C: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
L_8002A9A0:
    // 0x8002A9A0: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_8002A9A4:
    // 0x8002A9A4: jr          $ra
    // 0x8002A9A8: nop

    return;
    // 0x8002A9A8: nop

;}
RECOMP_FUNC void func_8002A9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9AC: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002A9B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A9B4: jr          $ra
    // 0x8002A9B8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    return;
    // 0x8002A9B8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8002A9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002A9C0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002A9C4: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002A9C8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A9CC: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
    // 0x8002A9D0: beq         $v0, $zero, L_8002A9E8
    if (ctx->r2 == 0) {
        // 0x8002A9D4: andi        $v0, $v1, 0xC000
        ctx->r2 = ctx->r3 & 0XC000;
            goto L_8002A9E8;
    }
    // 0x8002A9D4: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x8002A9D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002A9DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A9E0: j           L_8002AA00
    // 0x8002A9E4: nop

        goto L_8002AA00;
    // 0x8002A9E4: nop

L_8002A9E8:
    // 0x8002A9E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002A9EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A9F0: beq         $v0, $zero, L_8002AA00
    if (ctx->r2 == 0) {
        // 0x8002A9F4: nop
    
            goto L_8002AA00;
    }
    // 0x8002A9F4: nop

    // 0x8002A9F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8002A9FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8002AA00:
    // 0x8002AA00: lb          $v1, 0x3($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X3);
    // 0x8002AA04: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8002AA08: beq         $v0, $zero, L_8002ABC0
    if (ctx->r2 == 0) {
        // 0x8002AA0C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8002ABC0;
    }
    // 0x8002AA0C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8002AA10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002AA14: addu        $at, $at, $v0
    gpr jr_addend_8002AA1C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002AA18: lw          $v0, -0x2990($at)
    ctx->r2 = ADD32(ctx->r1, -0X2990);
    // 0x8002AA1C: jr          $v0
    // 0x8002AA20: nop

    switch (jr_addend_8002AA1C >> 2) {
        case 0: goto L_8002AA24; break;
        case 1: goto L_8002AA58; break;
        case 2: goto L_8002AA94; break;
        case 3: goto L_8002AB38; break;
        case 4: goto L_8002AB88; break;
        case 5: goto L_8002ABC0; break;
        default: switch_error(__func__, 0x8002AA1C, 0x800AD670);
    }
    // 0x8002AA20: nop

L_8002AA24:
    // 0x8002AA24: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AA28: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AA2C: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x8002AA30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AA34: nop

    // 0x8002AA38: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002AA3C: nop

    // 0x8002AA40: nop

    // 0x8002AA44: bc1f        L_8002ABC0
    if (!c1cs) {
        // 0x8002AA48: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002ABC0;
    }
    // 0x8002AA48: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002AA4C: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002AA50: j           L_8002ABBC
    // 0x8002AA54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002ABBC;
    // 0x8002AA54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002AA58:
    // 0x8002AA58: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AA5C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8002AA60: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AA64: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x8002AA68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AA6C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8002AA70: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002AA74: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x8002AA78: nop

    // 0x8002AA7C: bc1f        L_8002ABC0
    if (!c1cs) {
        // 0x8002AA80: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002ABC0;
    }
    // 0x8002AA80: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002AA84: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002AA88: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002AA8C: j           L_8002ABB8
    // 0x8002AA90: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
        goto L_8002ABB8;
    // 0x8002AA90: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
L_8002AA94:
    // 0x8002AA94: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AA98: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002AA9C: lbu         $v1, 0x73($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X73);
    // 0x8002AAA0: sltiu       $v0, $v1, 0x15
    ctx->r2 = ctx->r3 < 0X15 ? 1 : 0;
    // 0x8002AAA4: beq         $v0, $zero, L_8002AAB0
    if (ctx->r2 == 0) {
        // 0x8002AAA8: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_8002AAB0;
    }
    // 0x8002AAA8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8002AAAC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8002AAB0:
    // 0x8002AAB0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AAB4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AAB8: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x8002AABC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AAC0: nop

    // 0x8002AAC4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002AAC8: nop

    // 0x8002AACC: nop

    // 0x8002AAD0: bc1f        L_8002AAF0
    if (!c1cs) {
        // 0x8002AAD4: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002AAF0;
    }
    // 0x8002AAD4: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002AAD8: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002AADC: beq         $v0, $zero, L_8002AAEC
    if (ctx->r2 == 0) {
        // 0x8002AAE0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8002AAEC;
    }
    // 0x8002AAE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002AAE4: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002AAE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002AAEC:
    // 0x8002AAEC: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_8002AAF0:
    // 0x8002AAF0: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002AAF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002AAF8: bne         $a1, $v0, L_8002ABC0
    if (ctx->r5 != ctx->r2) {
        // 0x8002AAFC: nop
    
            goto L_8002ABC0;
    }
    // 0x8002AAFC: nop

    // 0x8002AB00: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AB04: lui         $at, 0x42F2
    ctx->r1 = S32(0X42F2 << 16);
    // 0x8002AB08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AB0C: nop

    // 0x8002AB10: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002AB14: nop

    // 0x8002AB18: bc1f        L_8002ABC0
    if (!c1cs) {
        // 0x8002AB1C: nop
    
            goto L_8002ABC0;
    }
    // 0x8002AB1C: nop

    // 0x8002AB20: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002AB24: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8002AB28: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8002AB2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002AB30: j           L_8002ABC0
    // 0x8002AB34: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
        goto L_8002ABC0;
    // 0x8002AB34: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8002AB38:
    // 0x8002AB38: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x8002AB3C: slti        $v0, $v1, 0xB
    ctx->r2 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8002AB40: bnel        $v0, $zero, L_8002AB50
    if (ctx->r2 != 0) {
        // 0x8002AB44: sw          $zero, 0x18($a0)
        MEM_W(0X18, ctx->r4) = 0;
            goto L_8002AB50;
    }
    goto skip_0;
    // 0x8002AB44: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    skip_0:
    // 0x8002AB48: addiu       $v0, $v1, -0x8
    ctx->r2 = ADD32(ctx->r3, -0X8);
    // 0x8002AB4C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
L_8002AB50:
    // 0x8002AB50: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AB54: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AB58: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8002AB5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AB60: nop

    // 0x8002AB64: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002AB68: nop

    // 0x8002AB6C: nop

    // 0x8002AB70: bc1f        L_8002ABC0
    if (!c1cs) {
        // 0x8002AB74: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002ABC0;
    }
    // 0x8002AB74: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002AB78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002AB7C: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x8002AB80: j           L_8002ABC0
    // 0x8002AB84: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
        goto L_8002ABC0;
    // 0x8002AB84: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_8002AB88:
    // 0x8002AB88: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AB8C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AB90: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8002AB94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AB98: nop

    // 0x8002AB9C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8002ABA0: nop

    // 0x8002ABA4: nop

    // 0x8002ABA8: bc1f        L_8002ABC0
    if (!c1cs) {
        // 0x8002ABAC: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002ABC0;
    }
    // 0x8002ABAC: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002ABB0: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002ABB4: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
L_8002ABB8:
    // 0x8002ABB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002ABBC:
    // 0x8002ABBC: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_8002ABC0:
    // 0x8002ABC0: jr          $ra
    // 0x8002ABC4: nop

    return;
    // 0x8002ABC4: nop

;}
RECOMP_FUNC void func_8002ABC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ABC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002ABCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002ABD0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8002ABD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002ABD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002ABDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002ABE0: lb          $v1, 0x3($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X3);
    // 0x8002ABE4: beq         $v1, $zero, L_8002AC00
    if (ctx->r3 == 0) {
        // 0x8002ABE8: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8002AC00;
    }
    // 0x8002ABE8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8002ABEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002ABF0: beq         $v1, $v0, L_8002AC18
    if (ctx->r3 == ctx->r2) {
        // 0x8002ABF4: nop
    
            goto L_8002AC18;
    }
    // 0x8002ABF4: nop

    // 0x8002ABF8: j           L_8002AD68
    // 0x8002ABFC: nop

        goto L_8002AD68;
    // 0x8002ABFC: nop

L_8002AC00:
    // 0x8002AC00: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AC04: lbu         $v0, 0x7B93($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B93);
    // 0x8002AC08: beq         $v0, $zero, L_8002AD68
    if (ctx->r2 == 0) {
        // 0x8002AC0C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002AD68;
    }
    // 0x8002AC0C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002AC10: j           L_8002AD68
    // 0x8002AC14: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
        goto L_8002AD68;
    // 0x8002AC14: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
L_8002AC18:
    // 0x8002AC18: lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X2);
    // 0x8002AC1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002AC20: jal         0x80012D8C
    // 0x8002AC24: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x8002AC24: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    after_0:
    // 0x8002AC28: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8002AC2C: beq         $s1, $zero, L_8002ACB4
    if (ctx->r17 == 0) {
        // 0x8002AC30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002ACB4;
    }
    // 0x8002AC30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002AC34: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8002AC38: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002AC3C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8002AC40: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x8002AC44: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8002AC48: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8002AC4C: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8002AC50: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002AC54: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8002AC58: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8002AC5C: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x8002AC60: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x8002AC64: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AC68: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002AC6C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8002AC70: addiu       $s0, $s0, -0x38E0
    ctx->r16 = ADD32(ctx->r16, -0X38E0);
    // 0x8002AC74: lbu         $a2, 0x73($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X73);
    // 0x8002AC78: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002AC7C: addiu       $a1, $a1, -0x2978
    ctx->r5 = ADD32(ctx->r5, -0X2978);
    // 0x8002AC80: jal         0x80066CA0
    // 0x8002AC84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x8002AC84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8002AC88: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
    // 0x8002AC8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AC90: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002AC94: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8002AC98: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002AC9C: bne         $v0, $zero, L_8002ACA8
    if (ctx->r2 != 0) {
        // 0x8002ACA0: addiu       $v0, $zero, 0xE6
        ctx->r2 = ADD32(0, 0XE6);
            goto L_8002ACA8;
    }
    // 0x8002ACA0: addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // 0x8002ACA4: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_8002ACA8:
    // 0x8002ACA8: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8002ACAC: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x8002ACB0: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
L_8002ACB4:
    // 0x8002ACB4: jal         0x80012D8C
    // 0x8002ACB8: nop

    func_80012D8C(rdram, ctx);
        goto after_2;
    // 0x8002ACB8: nop

    after_2:
    // 0x8002ACBC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8002ACC0: beq         $s1, $zero, L_8002AD68
    if (ctx->r17 == 0) {
        // 0x8002ACC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002AD68;
    }
    // 0x8002ACC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002ACC8: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8002ACCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002ACD0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8002ACD4: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x8002ACD8: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8002ACDC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002ACE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002ACE4: nop

    // 0x8002ACE8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8002ACEC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8002ACF0: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8002ACF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002ACF8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8002ACFC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8002AD00: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x8002AD04: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x8002AD08: lb          $v0, 0x5($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X5);
    // 0x8002AD0C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8002AD10: addiu       $s0, $s0, 0x3030
    ctx->r16 = ADD32(ctx->r16, 0X3030);
    // 0x8002AD14: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002AD18: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002AD1C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8002AD20: lhu         $a2, -0x3FE2($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X3FE2);
    // 0x8002AD24: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002AD28: addiu       $a1, $a1, -0x2974
    ctx->r5 = ADD32(ctx->r5, -0X2974);
    // 0x8002AD2C: jal         0x80066CA0
    // 0x8002AD30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x8002AD30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8002AD34: jal         0x8002AF20
    // 0x8002AD38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002AF20(rdram, ctx);
        goto after_4;
    // 0x8002AD38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8002AD3C: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
    // 0x8002AD40: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AD44: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002AD48: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8002AD4C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002AD50: bne         $v0, $zero, L_8002AD5C
    if (ctx->r2 != 0) {
        // 0x8002AD54: addiu       $v0, $zero, 0xEE
        ctx->r2 = ADD32(0, 0XEE);
            goto L_8002AD5C;
    }
    // 0x8002AD54: addiu       $v0, $zero, 0xEE
    ctx->r2 = ADD32(0, 0XEE);
    // 0x8002AD58: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
L_8002AD5C:
    // 0x8002AD5C: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8002AD60: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8002AD64: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
L_8002AD68:
    // 0x8002AD68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002AD6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002AD70: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AD74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002AD78: jr          $ra
    // 0x8002AD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002AD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
