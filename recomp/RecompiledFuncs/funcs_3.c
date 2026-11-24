#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8000A2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000A300: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A304: addiu       $a0, $a0, 0x7B72
    ctx->r4 = ADD32(ctx->r4, 0X7B72);
    // 0x8000A308: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000A30C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A310: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A314: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A318: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A31C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A320: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A324: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A328: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8000A32C: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8000A330: addiu       $s0, $s0, -0x2F90
    ctx->r16 = ADD32(ctx->r16, -0X2F90);
    // 0x8000A334: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A338: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000A33C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8000A340: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000A344: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8000A348: lw          $a0, -0x6444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6444);
    // 0x8000A34C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000A350: addiu       $a2, $zero, 0x690
    ctx->r6 = ADD32(0, 0X690);
    // 0x8000A354: jal         0x80006D98
    // 0x8000A358: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8000A358: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    after_0:
    // 0x8000A35C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A360: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8000A364: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A368: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000A36C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000A370: lw          $a0, -0x6444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6444);
    // 0x8000A374: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A378: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x8000A37C: jal         0x80006D98
    // 0x8000A380: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x8000A380: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_1:
    // 0x8000A384: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A388: lbu         $a0, 0x7B86($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B86);
    // 0x8000A38C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000A390: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000A394: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000A398: lbu         $v1, -0x4D30($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4D30);
    // 0x8000A39C: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000A3A0: addiu       $s1, $s1, -0x1DC0
    ctx->r17 = ADD32(ctx->r17, -0X1DC0);
    // 0x8000A3A4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000A3A8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A3AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A3B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A3B4: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x8000A3B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A3BC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000A3C0: lw          $v0, -0x6444($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6444);
    // 0x8000A3C4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000A3C8: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x8000A3CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8000A3D0: jal         0x80006D98
    // 0x8000A3D4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_2;
    // 0x8000A3D4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x8000A3D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A3DC: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8000A3E0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8000A3E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000A3E8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A3EC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000A3F0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000A3F4: lbu         $a0, -0x4D2F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X4D2F);
    // 0x8000A3F8: addiu       $s3, $zero, 0x2B
    ctx->r19 = ADD32(0, 0X2B);
    // 0x8000A3FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000A400: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000A404: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000A408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A40C: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x8000A410: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A414: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A418: lw          $v0, -0x6444($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6444);
    // 0x8000A41C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000A420: addiu       $a2, $zero, 0x5A0
    ctx->r6 = ADD32(0, 0X5A0);
    // 0x8000A424: addiu       $a1, $s1, 0x400
    ctx->r5 = ADD32(ctx->r17, 0X400);
    // 0x8000A428: jal         0x80006D98
    // 0x8000A42C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_3;
    // 0x8000A42C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8000A430: jal         0x8001F45C
    // 0x8000A434: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8001F45C(rdram, ctx);
        goto after_4;
    // 0x8000A434: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_4:
    // 0x8000A438: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000A43C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A440: sb          $v0, 0x7B95($at)
    MEM_B(0X7B95, ctx->r1) = ctx->r2;
L_8000A444:
    // 0x8000A444: jal         0x8001D520
    // 0x8000A448: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8001D520(rdram, ctx);
        goto after_5;
    // 0x8000A448: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // 0x8000A44C: beql        $v0, $zero, L_8000A464
    if (ctx->r2 == 0) {
        // 0x8000A450: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8000A464;
    }
    goto skip_0;
    // 0x8000A450: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8000A454: sb          $s4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r20;
    // 0x8000A458: sb          $s3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r19;
    // 0x8000A45C: sw          $s2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r18;
    // 0x8000A460: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000A464:
    // 0x8000A464: slti        $v0, $s2, 0xA
    ctx->r2 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8000A468: bne         $v0, $zero, L_8000A444
    if (ctx->r2 != 0) {
        // 0x8000A46C: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_8000A444;
    }
    // 0x8000A46C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8000A470: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A474: sb          $v0, 0x2089($at)
    MEM_B(0X2089, ctx->r1) = ctx->r2;
    // 0x8000A478: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A47C: lbu         $v0, 0x2089($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2089);
    // 0x8000A480: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A484: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    // 0x8000A488: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A48C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A490: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A494: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A498: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A49C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A4A0: jr          $ra
    // 0x8000A4A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000A4A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8000A4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A4A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A4AC: lbu         $v0, 0x7B87($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B87);
    // 0x8000A4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A4B4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000A4B8: beq         $v0, $zero, L_8000A4E0
    if (ctx->r2 == 0) {
        // 0x8000A4BC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000A4E0;
    }
    // 0x8000A4BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A4C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A4C4: lbu         $v0, 0x7B72($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B72);
    // 0x8000A4C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A4CC: sb          $zero, 0x7BA2($at)
    MEM_B(0X7BA2, ctx->r1) = 0;
    // 0x8000A4D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A4D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A4D8: jal         0x8001C36C
    // 0x8000A4DC: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    func_8001C36C(rdram, ctx);
        goto after_0;
    // 0x8000A4DC: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    after_0:
L_8000A4E0:
    // 0x8000A4E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A4E4: jr          $ra
    // 0x8000A4E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A4E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A4EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A4F0: lbu         $v0, 0x7B87($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B87);
    // 0x8000A4F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A4F8: bne         $v0, $zero, L_8000A634
    if (ctx->r2 != 0) {
        // 0x8000A4FC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000A634;
    }
    // 0x8000A4FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A500: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A504: lbu         $v0, 0x7B72($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B72);
    // 0x8000A508: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A50C: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x8000A510: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A514: lbu         $a0, 0x2604($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2604);
    // 0x8000A518: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000A51C: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x8000A520: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A524: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A528: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000A52C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A530: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A534: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A538: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000A53C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A540: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000A544: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A548: lbu         $a0, 0x2606($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2606);
    // 0x8000A54C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000A550: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8000A554: beq         $v0, $zero, L_8000A56C
    if (ctx->r2 == 0) {
        // 0x8000A558: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A56C;
    }
    // 0x8000A558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A55C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A560: lbu         $a1, 0x25A5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X25A5);
    // 0x8000A564: j           L_8000A584
    // 0x8000A568: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
        goto L_8000A584;
    // 0x8000A568: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
L_8000A56C:
    // 0x8000A56C: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8000A570: beq         $v0, $zero, L_8000A59C
    if (ctx->r2 == 0) {
        // 0x8000A574: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_8000A59C;
    }
    // 0x8000A574: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8000A578: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A57C: lbu         $a1, 0x25A5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X25A5);
    // 0x8000A580: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000A584:
    // 0x8000A584: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A588: sw          $v0, 0x2684($at)
    MEM_W(0X2684, ctx->r1) = ctx->r2;
    // 0x8000A58C: jal         0x8000637C
    // 0x8000A590: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8000A590: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
    // 0x8000A594: j           L_8000A5A4
    // 0x8000A598: nop

        goto L_8000A5A4;
    // 0x8000A598: nop

L_8000A59C:
    // 0x8000A59C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A5A0: sw          $zero, 0x2684($at)
    MEM_W(0X2684, ctx->r1) = 0;
L_8000A5A4:
    // 0x8000A5A4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A5A8: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x8000A5AC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000A5B0: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x8000A5B4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A5B8: lbu         $a0, 0x7A54($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A54);
    // 0x8000A5BC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A5C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A5C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A5C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000A5CC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A5D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000A5D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A5D8: lbu         $a0, 0x7A56($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A56);
    // 0x8000A5DC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000A5E0: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8000A5E4: beq         $v0, $zero, L_8000A5FC
    if (ctx->r2 == 0) {
        // 0x8000A5E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A5FC;
    }
    // 0x8000A5E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A5EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A5F0: lbu         $a1, 0x79F5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X79F5);
    // 0x8000A5F4: j           L_8000A614
    // 0x8000A5F8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
        goto L_8000A614;
    // 0x8000A5F8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
L_8000A5FC:
    // 0x8000A5FC: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8000A600: beq         $v0, $zero, L_8000A62C
    if (ctx->r2 == 0) {
        // 0x8000A604: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_8000A62C;
    }
    // 0x8000A604: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8000A608: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A60C: lbu         $a1, 0x79F5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X79F5);
    // 0x8000A610: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000A614:
    // 0x8000A614: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A618: sw          $v0, 0x7AD4($at)
    MEM_W(0X7AD4, ctx->r1) = ctx->r2;
    // 0x8000A61C: jal         0x8000637C
    // 0x8000A620: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8000A620: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
    // 0x8000A624: j           L_8000A634
    // 0x8000A628: nop

        goto L_8000A634;
    // 0x8000A628: nop

L_8000A62C:
    // 0x8000A62C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A630: sw          $zero, 0x7AD4($at)
    MEM_W(0X7AD4, ctx->r1) = 0;
L_8000A634:
    // 0x8000A634: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A638: jr          $ra
    // 0x8000A63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A640: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000A644: lw          $a2, 0x2684($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2684);
    // 0x8000A648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A64C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8000A650: addiu       $t0, $t0, 0x2606
    ctx->r8 = ADD32(ctx->r8, 0X2606);
    // 0x8000A654: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A658: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8000A65C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8000A660: addiu       $a3, $a3, 0x7A56
    ctx->r7 = ADD32(ctx->r7, 0X7A56);
    // 0x8000A664: lw          $a1, 0x7E($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7E);
    // 0x8000A668: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8000A66C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A670: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x8000A674: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000A678: addiu       $t1, $t1, -0x3998
    ctx->r9 = ADD32(ctx->r9, -0X3998);
    // 0x8000A67C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8000A680: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A684: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A688: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A68C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A690: sb          $a0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r4;
    // 0x8000A694: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x8000A698: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000A69C: lbu         $a1, 0x2604($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2604);
    // 0x8000A6A0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000A6A4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8000A6A8: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A6AC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000A6B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000A6B4: bne         $a0, $v0, L_8000A6D0
    if (ctx->r4 != ctx->r2) {
        // 0x8000A6B8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8000A6D0;
    }
    // 0x8000A6B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000A6BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A6C0: sw          $zero, 0x2684($at)
    MEM_W(0X2684, ctx->r1) = 0;
    // 0x8000A6C4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000A6C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000A6CC: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
L_8000A6D0:
    // 0x8000A6D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A6D4: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x8000A6D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A6DC: lbu         $a0, 0x7A54($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A54);
    // 0x8000A6E0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000A6E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A6E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A6EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000A6F0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8000A6F4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8000A6F8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A6FC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8000A700: bne         $v0, $v1, L_8000A71C
    if (ctx->r2 != ctx->r3) {
        // 0x8000A704: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000A71C;
    }
    // 0x8000A704: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000A708: sw          $zero, 0x7E($a3)
    MEM_W(0X7E, ctx->r7) = 0;
    // 0x8000A70C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A710: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000A714: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8000A718: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000A71C:
    // 0x8000A71C: bne         $a1, $v0, L_8000A740
    if (ctx->r5 != ctx->r2) {
        // 0x8000A720: nop
    
            goto L_8000A740;
    }
    // 0x8000A720: nop

    // 0x8000A724: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A728: lbu         $v0, 0x7B95($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B95);
    // 0x8000A72C: bne         $v0, $zero, L_8000A740
    if (ctx->r2 != 0) {
        // 0x8000A730: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000A740;
    }
    // 0x8000A730: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000A734: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A738: jal         0x8000BAC8
    // 0x8000A73C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_8000BAC8(rdram, ctx);
        goto after_0;
    // 0x8000A73C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_0:
L_8000A740:
    // 0x8000A740: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A744: jr          $ra
    // 0x8000A748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A750: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A754: jal         0x8000B80C
    // 0x8000A758: nop

    func_8000B80C(rdram, ctx);
        goto after_0;
    // 0x8000A758: nop

    after_0:
    // 0x8000A75C: bne         $v0, $zero, L_8000A76C
    if (ctx->r2 != 0) {
        // 0x8000A760: nop
    
            goto L_8000A76C;
    }
    // 0x8000A760: nop

    // 0x8000A764: jal         0x80005074
    // 0x8000A768: nop

    func_80005074(rdram, ctx);
        goto after_1;
    // 0x8000A768: nop

    after_1:
L_8000A76C:
    // 0x8000A76C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A770: jr          $ra
    // 0x8000A774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A778: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x8000A77C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8000A780: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000A784: addiu       $a2, $a2, -0x3460
    ctx->r6 = ADD32(ctx->r6, -0X3460);
    // 0x8000A788: addiu       $t0, $a2, 0xE0
    ctx->r8 = ADD32(ctx->r6, 0XE0);
    // 0x8000A78C: sw          $ra, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r31;
    // 0x8000A790: sw          $fp, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r30;
    // 0x8000A794: sw          $s7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r23;
    // 0x8000A798: sw          $s6, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r22;
    // 0x8000A79C: sw          $s5, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r21;
    // 0x8000A7A0: sw          $s4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r20;
    // 0x8000A7A4: sw          $s3, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r19;
    // 0x8000A7A8: sw          $s2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r18;
    // 0x8000A7AC: sw          $s1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r17;
    // 0x8000A7B0: sw          $s0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r16;
    // 0x8000A7B4: sdc1        $f24, 0x1A0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X1A0, ctx->r29);
    // 0x8000A7B8: sdc1        $f22, 0x198($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X198, ctx->r29);
    // 0x8000A7BC: sdc1        $f20, 0x190($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X190, ctx->r29);
L_8000A7C0:
    // 0x8000A7C0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000A7C4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8000A7C8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8000A7CC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8000A7D0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8000A7D4: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8000A7D8: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8000A7DC: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8000A7E0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8000A7E4: bne         $a2, $t0, L_8000A7C0
    if (ctx->r6 != ctx->r8) {
        // 0x8000A7E8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8000A7C0;
    }
    // 0x8000A7E8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000A7EC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000A7F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8000A7F4: addiu       $a3, $sp, 0x100
    ctx->r7 = ADD32(ctx->r29, 0X100);
    // 0x8000A7F8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000A7FC: addiu       $a2, $a2, -0x3370
    ctx->r6 = ADD32(ctx->r6, -0X3370);
    // 0x8000A800: addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8000A804:
    // 0x8000A804: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000A808: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8000A80C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8000A810: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8000A814: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8000A818: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8000A81C: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8000A820: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8000A824: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8000A828: bne         $a2, $t0, L_8000A804
    if (ctx->r6 != ctx->r8) {
        // 0x8000A82C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8000A804;
    }
    // 0x8000A82C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000A830: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000A834: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8000A838: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A83C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000A840: lbu         $v1, 0x73($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X73);
    // 0x8000A844: sltiu       $v0, $v1, 0x15
    ctx->r2 = ctx->r3 < 0X15 ? 1 : 0;
    // 0x8000A848: beq         $v0, $zero, L_8000A854
    if (ctx->r2 == 0) {
        // 0x8000A84C: addiu       $s3, $zero, 0x14
        ctx->r19 = ADD32(0, 0X14);
            goto L_8000A854;
    }
    // 0x8000A84C: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8000A850: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
L_8000A854:
    // 0x8000A854: jal         0x8000B80C
    // 0x8000A858: nop

    func_8000B80C(rdram, ctx);
        goto after_0;
    // 0x8000A858: nop

    after_0:
    // 0x8000A85C: bne         $v0, $zero, L_8000B0F0
    if (ctx->r2 != 0) {
        // 0x8000A860: nop
    
            goto L_8000B0F0;
    }
    // 0x8000A860: nop

    // 0x8000A864: jal         0x80005074
    // 0x8000A868: nop

    func_80005074(rdram, ctx);
        goto after_1;
    // 0x8000A868: nop

    after_1:
    // 0x8000A86C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A870: lbu         $v1, 0x7B72($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B72);
    // 0x8000A874: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8000A878: beq         $v0, $zero, L_8000B0F0
    if (ctx->r2 == 0) {
        // 0x8000A87C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000B0F0;
    }
    // 0x8000A87C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000A880: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000A884: addu        $at, $at, $v0
    gpr jr_addend_8000A88C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000A888: lw          $v0, -0x3308($at)
    ctx->r2 = ADD32(ctx->r1, -0X3308);
    // 0x8000A88C: jr          $v0
    // 0x8000A890: nop

    switch (jr_addend_8000A88C >> 2) {
        case 0: goto L_8000A894; break;
        case 1: goto L_8000AAB4; break;
        case 2: goto L_8000AAE4; break;
        case 3: goto L_8000AC2C; break;
        case 4: goto L_8000AC90; break;
        case 5: goto L_8000ADAC; break;
        case 6: goto L_8000AF34; break;
        case 7: goto L_8000AFE8; break;
        case 8: goto L_8000B068; break;
        case 9: goto L_8000B088; break;
        case 10: goto L_8000B0A4; break;
        default: switch_error(__func__, 0x8000A88C, 0x800ACCF8);
    }
    // 0x8000A890: nop

L_8000A894:
    // 0x8000A894: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A898: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000A89C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A8A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A8A4: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000A8A8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000A8AC: sw          $v0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->r2;
    // 0x8000A8B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A8B4: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000A8B8: lb          $v0, 0x49($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X49);
    // 0x8000A8BC: beq         $v0, $zero, L_8000A8CC
    if (ctx->r2 == 0) {
        // 0x8000A8C0: nop
    
            goto L_8000A8CC;
    }
    // 0x8000A8C0: nop

    // 0x8000A8C4: jal         0x80015490
    // 0x8000A8C8: nop

    func_80015490(rdram, ctx);
        goto after_2;
    // 0x8000A8C8: nop

    after_2:
L_8000A8CC:
    // 0x8000A8CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A8D0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000A8D4: sb          $zero, 0x49($v0)
    MEM_B(0X49, ctx->r2) = 0;
    // 0x8000A8D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A8DC: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000A8E0: lw          $a0, 0xD0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD0);
    // 0x8000A8E4: lb          $v0, 0x49($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X49);
    // 0x8000A8E8: beq         $v0, $zero, L_8000A8F8
    if (ctx->r2 == 0) {
        // 0x8000A8EC: nop
    
            goto L_8000A8F8;
    }
    // 0x8000A8EC: nop

    // 0x8000A8F0: jal         0x80015490
    // 0x8000A8F4: nop

    func_80015490(rdram, ctx);
        goto after_3;
    // 0x8000A8F4: nop

    after_3:
L_8000A8F8:
    // 0x8000A8F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A8FC: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000A900: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x8000A904: sb          $zero, 0x49($v0)
    MEM_B(0X49, ctx->r2) = 0;
    // 0x8000A908: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A90C: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x8000A910: beq         $v0, $zero, L_8000A920
    if (ctx->r2 == 0) {
        // 0x8000A914: nop
    
            goto L_8000A920;
    }
    // 0x8000A914: nop

    // 0x8000A918: jal         0x80006998
    // 0x8000A91C: nop

    func_80006998(rdram, ctx);
        goto after_4;
    // 0x8000A91C: nop

    after_4:
L_8000A920:
    // 0x8000A920: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8000A924: addiu       $a0, $a0, -0x3278
    ctx->r4 = ADD32(ctx->r4, -0X3278);
    // 0x8000A928: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000A92C: lbu         $a2, 0x7B82($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B82);
    // 0x8000A930: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000A934: addiu       $s0, $s0, -0x3520
    ctx->r16 = ADD32(ctx->r16, -0X3520);
    // 0x8000A938: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000A93C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A940: lbu         $v1, 0x7B81($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B81);
    // 0x8000A944: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x8000A948: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8000A94C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A950: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A954: jal         0x80066CA0
    // 0x8000A958: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x8000A958: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x8000A95C: lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // 0x8000A960: ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // 0x8000A964: mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A968: sra         $v1, $s2, 31
    ctx->r3 = S32(SIGNED(ctx->r18) >> 31);
    // 0x8000A96C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8000A970: addu        $v0, $t1, $s2
    ctx->r2 = ADD32(ctx->r9, ctx->r18);
    // 0x8000A974: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8000A978: subu        $s2, $v0, $v1
    ctx->r18 = SUB32(ctx->r2, ctx->r3);
    // 0x8000A97C: slti        $v0, $s2, 0xB
    ctx->r2 = SIGNED(ctx->r18) < 0XB ? 1 : 0;
    // 0x8000A980: beql        $v0, $zero, L_8000A988
    if (ctx->r2 == 0) {
        // 0x8000A984: addiu       $s2, $zero, 0xA
        ctx->r18 = ADD32(0, 0XA);
            goto L_8000A988;
    }
    goto skip_0;
    // 0x8000A984: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    skip_0:
L_8000A988:
    // 0x8000A988: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8000A98C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000A990: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8000A994: lhu         $s1, -0x3FF8($s1)
    ctx->r17 = MEM_HU(ctx->r17, -0X3FF8);
    // 0x8000A998: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A99C: addiu       $a0, $a0, 0x1218
    ctx->r4 = ADD32(ctx->r4, 0X1218);
    // 0x8000A9A0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000A9A4: addiu       $a1, $a1, -0x3514
    ctx->r5 = ADD32(ctx->r5, -0X3514);
    // 0x8000A9A8: jal         0x80066CA0
    // 0x8000A9AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_6;
    // 0x8000A9AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_6:
    // 0x8000A9B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A9B4: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000A9B8: lbu         $a2, 0x70($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X70);
    // 0x8000A9BC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A9C0: addiu       $a0, $a0, 0xB64
    ctx->r4 = ADD32(ctx->r4, 0XB64);
    // 0x8000A9C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000A9C8: sll         $v0, $a2, 5
    ctx->r2 = S32(ctx->r6 << 5);
    // 0x8000A9CC: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8000A9D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A9D4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000A9D8: jal         0x80066CA0
    // 0x8000A9DC: sll         $s2, $v0, 3
    ctx->r18 = S32(ctx->r2 << 3);
    func_80066CA0(rdram, ctx);
        goto after_7;
    // 0x8000A9DC: sll         $s2, $v0, 3
    ctx->r18 = S32(ctx->r2 << 3);
    after_7:
    // 0x8000A9E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A9E4: addiu       $a0, $a0, -0x2548
    ctx->r4 = ADD32(ctx->r4, -0X2548);
    // 0x8000A9E8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000A9EC: addiu       $a1, $a1, -0x331C
    ctx->r5 = ADD32(ctx->r5, -0X331C);
    // 0x8000A9F0: jal         0x80066CA0
    // 0x8000A9F4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80066CA0(rdram, ctx);
        goto after_8;
    // 0x8000A9F4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8000A9F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A9FC: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AA00: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    // 0x8000AA04: lbu         $a2, 0x71($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X71);
    // 0x8000AA08: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000AA0C: addiu       $a0, $a0, 0x1008
    ctx->r4 = ADD32(ctx->r4, 0X1008);
    // 0x8000AA10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000AA14: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8000AA18: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000AA1C: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x8000AA20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000AA24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AA28: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000AA2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AA30: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000AA34: sll         $s2, $v0, 5
    ctx->r18 = S32(ctx->r2 << 5);
    // 0x8000AA38: jal         0x80066CA0
    // 0x8000AA3C: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    func_80066CA0(rdram, ctx);
        goto after_9;
    // 0x8000AA3C: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    after_9:
    // 0x8000AA40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000AA44: addiu       $a0, $a0, -0x2FA0
    ctx->r4 = ADD32(ctx->r4, -0X2FA0);
    // 0x8000AA48: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000AA4C: addiu       $s0, $s0, -0x3318
    ctx->r16 = ADD32(ctx->r16, -0X3318);
    // 0x8000AA50: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000AA54: jal         0x80066CA0
    // 0x8000AA58: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80066CA0(rdram, ctx);
        goto after_10;
    // 0x8000AA58: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_10:
    // 0x8000AA5C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8000AA60: addiu       $a0, $a0, 0x2001
    ctx->r4 = ADD32(ctx->r4, 0X2001);
    // 0x8000AA64: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8000AA68: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AA6C: sw          $a2, 0x3F34($at)
    MEM_W(0X3F34, ctx->r1) = ctx->r6;
    // 0x8000AA70: jal         0x80066CA0
    // 0x8000AA74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_11;
    // 0x8000AA74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8000AA78: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000AA7C: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8000AA80: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000AA84: addiu       $s0, $s0, -0x3314
    ctx->r16 = ADD32(ctx->r16, -0X3314);
    // 0x8000AA88: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000AA8C: jal         0x80066CA0
    // 0x8000AA90: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    func_80066CA0(rdram, ctx);
        goto after_12;
    // 0x8000AA90: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_12:
    // 0x8000AA94: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000AA98: addiu       $a0, $a0, -0x2138
    ctx->r4 = ADD32(ctx->r4, -0X2138);
    // 0x8000AA9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000AAA0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8000AAA4: jal         0x80066CA0
    // 0x8000AAA8: ori         $a2, $a2, 0x86A0
    ctx->r6 = ctx->r6 | 0X86A0;
    func_80066CA0(rdram, ctx);
        goto after_13;
    // 0x8000AAA8: ori         $a2, $a2, 0x86A0
    ctx->r6 = ctx->r6 | 0X86A0;
    after_13:
    // 0x8000AAAC: j           L_8000B0F0
    // 0x8000AAB0: nop

        goto L_8000B0F0;
    // 0x8000AAB0: nop

L_8000AAB4:
    // 0x8000AAB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AAB8: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AABC: lb          $v0, 0x59($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X59);
    // 0x8000AAC0: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000AAC4: xori        $v0, $v0, 0x65
    ctx->r2 = ctx->r2 ^ 0X65;
    // 0x8000AAC8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000AACC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000AAD0: beq         $v1, $zero, L_8000B0F0
    if (ctx->r3 == 0) {
        // 0x8000AAD4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000B0F0;
    }
    // 0x8000AAD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000AAD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000AADC: j           L_8000B0F0
    // 0x8000AAE0: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
        goto L_8000B0F0;
    // 0x8000AAE0: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
L_8000AAE4:
    // 0x8000AAE4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000AAE8: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000AAEC: lw          $v0, 0xE4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE4);
    // 0x8000AAF0: beq         $v0, $zero, L_8000AAFC
    if (ctx->r2 == 0) {
        // 0x8000AAF4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000AAFC;
    }
    // 0x8000AAF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000AAF8: sw          $v0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->r2;
L_8000AAFC:
    // 0x8000AAFC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000AB00: jal         0x8000C2A4
    // 0x8000AB04: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    func_8000C2A4(rdram, ctx);
        goto after_14;
    // 0x8000AB04: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    after_14:
    // 0x8000AB08: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000AB0C: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000AB10: lw          $a0, 0xD0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XD0);
    // 0x8000AB14: jal         0x8000C2A4
    // 0x8000AB18: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    func_8000C2A4(rdram, ctx);
        goto after_15;
    // 0x8000AB18: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_15:
    // 0x8000AB1C: sltiu       $v1, $s2, 0x1
    ctx->r3 = ctx->r18 < 0X1 ? 1 : 0;
    // 0x8000AB20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000AB24: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8000AB28: beq         $v1, $zero, L_8000B0F0
    if (ctx->r3 == 0) {
        // 0x8000AB2C: addiu       $s2, $zero, 0x15
        ctx->r18 = ADD32(0, 0X15);
            goto L_8000B0F0;
    }
    // 0x8000AB2C: addiu       $s2, $zero, 0x15
    ctx->r18 = ADD32(0, 0X15);
    // 0x8000AB30: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000AB34: slti        $s7, $s3, 0xA
    ctx->r23 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8000AB38: lui         $at, 0x4314
    ctx->r1 = S32(0X4314 << 16);
    // 0x8000AB3C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8000AB40: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x8000AB44: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8000AB48: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x8000AB4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8000AB50: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x8000AB54: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8000AB58: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8000AB5C: addiu       $s5, $s5, -0x38E0
    ctx->r21 = ADD32(ctx->r21, -0X38E0);
    // 0x8000AB60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000AB64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000AB68: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000AB6C: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8000AB70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AB74: sw          $v0, 0x3F30($at)
    MEM_W(0X3F30, ctx->r1) = ctx->r2;
    // 0x8000AB78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000AB7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8000AB80: sb          $v0, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = ctx->r2;
    // 0x8000AB84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000AB88: sb          $zero, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = 0;
L_8000AB8C:
    // 0x8000AB8C: jal         0x80012D8C
    // 0x8000AB90: nop

    func_80012D8C(rdram, ctx);
        goto after_16;
    // 0x8000AB90: nop

    after_16:
    // 0x8000AB94: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8000AB98: beql        $s1, $zero, L_8000AC1C
    if (ctx->r17 == 0) {
        // 0x8000AB9C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000AC1C;
    }
    goto skip_1;
    // 0x8000AB9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x8000ABA0: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8000ABA4: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x8000ABA8: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // 0x8000ABAC: sb          $t1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r9;
    // 0x8000ABB0: bne         $s3, $v0, L_8000AC18
    if (ctx->r19 != ctx->r2) {
        // 0x8000ABB4: sb          $s2, 0x5($s1)
        MEM_B(0X5, ctx->r17) = ctx->r18;
            goto L_8000AC18;
    }
    // 0x8000ABB4: sb          $s2, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r18;
    // 0x8000ABB8: jal         0x80012D8C
    // 0x8000ABBC: nop

    func_80012D8C(rdram, ctx);
        goto after_17;
    // 0x8000ABBC: nop

    after_17:
    // 0x8000ABC0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000ABC4: beql        $s0, $zero, L_8000AC1C
    if (ctx->r16 == 0) {
        // 0x8000ABC8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000AC1C;
    }
    goto skip_2;
    // 0x8000ABC8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_2:
    // 0x8000ABCC: sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // 0x8000ABD0: sb          $s6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r22;
    // 0x8000ABD4: beq         $s7, $zero, L_8000ABE4
    if (ctx->r23 == 0) {
        // 0x8000ABD8: sb          $s4, 0x5($s0)
        MEM_B(0X5, ctx->r16) = ctx->r20;
            goto L_8000ABE4;
    }
    // 0x8000ABD8: sb          $s4, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r20;
    // 0x8000ABDC: j           L_8000ABE8
    // 0x8000ABE0: swc1        $f24, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
        goto L_8000ABE8;
    // 0x8000ABE0: swc1        $f24, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
L_8000ABE4:
    // 0x8000ABE4: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
L_8000ABE8:
    // 0x8000ABE8: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x8000ABEC: sw          $fp, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r30;
    // 0x8000ABF0: sw          $s6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r22;
    // 0x8000ABF4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000ABF8: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000ABFC: lbu         $a2, 0x73($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X73);
    // 0x8000AC00: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000AC04: addiu       $a1, $a1, -0x35B8
    ctx->r5 = ADD32(ctx->r5, -0X35B8);
    // 0x8000AC08: jal         0x80066CA0
    // 0x8000AC0C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80066CA0(rdram, ctx);
        goto after_18;
    // 0x8000AC0C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_18:
    // 0x8000AC10: sw          $s5, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r21;
    // 0x8000AC14: sw          $s1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r17;
L_8000AC18:
    // 0x8000AC18: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8000AC1C:
    // 0x8000AC1C: bltz        $s2, L_8000B0F0
    if (SIGNED(ctx->r18) < 0) {
        // 0x8000AC20: nop
    
            goto L_8000B0F0;
    }
    // 0x8000AC20: nop

    // 0x8000AC24: j           L_8000AB8C
    // 0x8000AC28: nop

        goto L_8000AB8C;
    // 0x8000AC28: nop

L_8000AC2C:
    // 0x8000AC2C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8000AC30: lb          $v0, 0x2000($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2000);
    // 0x8000AC34: beq         $v0, $zero, L_8000B0F0
    if (ctx->r2 == 0) {
        // 0x8000AC38: nop
    
            goto L_8000B0F0;
    }
    // 0x8000AC38: nop

    // 0x8000AC3C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000AC40: lw          $v1, 0x3F30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3F30);
    // 0x8000AC44: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8000AC48: bne         $a0, $zero, L_8000AC60
    if (ctx->r4 != 0) {
        // 0x8000AC4C: nop
    
            goto L_8000AC60;
    }
    // 0x8000AC4C: nop

    // 0x8000AC50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AC54: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AC58: j           L_8000AF64
    // 0x8000AC5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_8000AF64;
    // 0x8000AC5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8000AC60:
    // 0x8000AC60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AC64: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AC68: lb          $a3, 0x4($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X4);
    // 0x8000AC6C: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8000AC70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AC74: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000AC78: andi        $t0, $v0, 0xAC
    ctx->r8 = ctx->r2 & 0XAC;
    // 0x8000AC7C: andi        $v0, $a3, 0x80
    ctx->r2 = ctx->r7 & 0X80;
    // 0x8000AC80: bne         $v0, $zero, L_8000AFA0
    if (ctx->r2 != 0) {
        // 0x8000AC84: addu        $a2, $a3, $zero
        ctx->r6 = ADD32(ctx->r7, 0);
            goto L_8000AFA0;
    }
    // 0x8000AC84: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8000AC88: j           L_8000AFB8
    // 0x8000AC8C: nop

        goto L_8000AFB8;
    // 0x8000AC8C: nop

L_8000AC90:
    // 0x8000AC90: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000AC94: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000AC98: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
    // 0x8000AC9C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000ACA0: andi        $v0, $a0, 0xC000
    ctx->r2 = ctx->r4 & 0XC000;
    // 0x8000ACA4: beql        $v0, $zero, L_8000ACB8
    if (ctx->r2 == 0) {
        // 0x8000ACA8: andi        $v0, $a0, 0x30
        ctx->r2 = ctx->r4 & 0X30;
            goto L_8000ACB8;
    }
    goto skip_3;
    // 0x8000ACA8: andi        $v0, $a0, 0x30
    ctx->r2 = ctx->r4 & 0X30;
    skip_3:
    // 0x8000ACAC: lw          $v0, 0xE4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE4);
    // 0x8000ACB0: j           L_8000ACC8
    // 0x8000ACB4: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
        goto L_8000ACC8;
    // 0x8000ACB4: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
L_8000ACB8:
    // 0x8000ACB8: bne         $v0, $zero, L_8000ACC8
    if (ctx->r2 != 0) {
        // 0x8000ACBC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000ACC8;
    }
    // 0x8000ACBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000ACC0: lw          $v0, 0xE4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE4);
    // 0x8000ACC4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8000ACC8:
    // 0x8000ACC8: sw          $v0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->r2;
    // 0x8000ACCC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000ACD0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000ACD4: lw          $v0, 0xE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XE4);
    // 0x8000ACD8: bgez        $v0, L_8000B0F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000ACDC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8000B0F0;
    }
    // 0x8000ACDC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8000ACE0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000ACE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000ACE8: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000ACEC: addiu       $v0, $sp, 0x100
    ctx->r2 = ADD32(ctx->r29, 0X100);
    // 0x8000ACF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000ACF4: sb          $s2, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = ctx->r18;
    // 0x8000ACF8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000ACFC: sw          $v0, 0x3F30($at)
    MEM_W(0X3F30, ctx->r1) = ctx->r2;
    // 0x8000AD00: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8000AD04: jal         0x80012D8C
    // 0x8000AD08: sb          $s2, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = ctx->r18;
    func_80012D8C(rdram, ctx);
        goto after_19;
    // 0x8000AD08: sb          $s2, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = ctx->r18;
    after_19:
    // 0x8000AD0C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8000AD10: beq         $s1, $zero, L_8000B0F0
    if (ctx->r17 == 0) {
        // 0x8000AD14: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000B0F0;
    }
    // 0x8000AD14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000AD18: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8000AD1C: addiu       $s0, $s0, 0xB6F
    ctx->r16 = ADD32(ctx->r16, 0XB6F);
    // 0x8000AD20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000AD24: sb          $s2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r18;
    // 0x8000AD28: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8000AD2C: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x8000AD30: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000AD34: lw          $a2, 0x3F34($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3F34);
    // 0x8000AD38: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000AD3C: addiu       $a1, $a1, -0x3318
    ctx->r5 = ADD32(ctx->r5, -0X3318);
    // 0x8000AD40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000AD44: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8000AD48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000AD4C: jal         0x80066CA0
    // 0x8000AD50: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    func_80066CA0(rdram, ctx);
        goto after_20;
    // 0x8000AD50: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    after_20:
    // 0x8000AD54: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
    // 0x8000AD58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AD5C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AD60: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8000AD64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AD68: bne         $v0, $zero, L_8000AD84
    if (ctx->r2 != 0) {
        // 0x8000AD6C: addiu       $v0, $zero, 0xDE
        ctx->r2 = ADD32(0, 0XDE);
            goto L_8000AD84;
    }
    // 0x8000AD6C: addiu       $v0, $zero, 0xDE
    ctx->r2 = ADD32(0, 0XDE);
    // 0x8000AD70: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8000AD74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000AD78: nop

    // 0x8000AD7C: j           L_8000AD8C
    // 0x8000AD80: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_8000AD8C;
    // 0x8000AD80: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_8000AD84:
    // 0x8000AD84: lui         $at, 0x435E
    ctx->r1 = S32(0X435E << 16);
    // 0x8000AD88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8000AD8C:
    // 0x8000AD8C: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8000AD90: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8000AD94: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x8000AD98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000AD9C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000ADA0: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x8000ADA4: j           L_8000B0F0
    // 0x8000ADA8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_8000B0F0;
    // 0x8000ADA8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
L_8000ADAC:
    // 0x8000ADAC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000ADB0: lbu         $v1, 0x7B93($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B93);
    // 0x8000ADB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000ADB8: bne         $v1, $v0, L_8000B0F0
    if (ctx->r3 != ctx->r2) {
        // 0x8000ADBC: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8000B0F0;
    }
    // 0x8000ADBC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000ADC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8000ADC4: addiu       $a0, $a0, -0x3278
    ctx->r4 = ADD32(ctx->r4, -0X3278);
    // 0x8000ADC8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000ADCC: addiu       $a1, $a1, -0x3520
    ctx->r5 = ADD32(ctx->r5, -0X3520);
    // 0x8000ADD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000ADD4: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000ADD8: jal         0x80066CA0
    // 0x8000ADDC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80066CA0(rdram, ctx);
        goto after_21;
    // 0x8000ADDC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_21:
    // 0x8000ADE0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000ADE4: addiu       $a0, $a0, 0xB64
    ctx->r4 = ADD32(ctx->r4, 0XB64);
    // 0x8000ADE8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000ADEC: lw          $a2, 0x3F34($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3F34);
    // 0x8000ADF0: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000ADF4: addiu       $s0, $s0, -0x3318
    ctx->r16 = ADD32(ctx->r16, -0X3318);
    // 0x8000ADF8: jal         0x80066CA0
    // 0x8000ADFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_22;
    // 0x8000ADFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_22:
    // 0x8000AE00: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x8000AE04: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000AE08: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000AE0C: lhu         $a2, -0x3FE0($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X3FE0);
    // 0x8000AE10: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000AE14: addiu       $a0, $a0, 0xB80
    ctx->r4 = ADD32(ctx->r4, 0XB80);
    // 0x8000AE18: jal         0x80066CA0
    // 0x8000AE1C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_23;
    // 0x8000AE1C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_23:
    // 0x8000AE20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000AE24: lb          $v1, 0xB8A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB8A);
    // 0x8000AE28: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8000AE2C: beq         $v1, $v0, L_8000AE50
    if (ctx->r3 == ctx->r2) {
        // 0x8000AE30: addiu       $s2, $zero, 0xA
        ctx->r18 = ADD32(0, 0XA);
            goto L_8000AE50;
    }
    // 0x8000AE30: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8000AE34: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x8000AE38: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8000AE3C:
    // 0x8000AE3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AE40: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8000AE44: lb          $v0, 0xB80($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB80);
    // 0x8000AE48: bnel        $v0, $v1, L_8000AE3C
    if (ctx->r2 != ctx->r3) {
        // 0x8000AE4C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000AE3C;
    }
    goto skip_4;
    // 0x8000AE4C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_4:
L_8000AE50:
    // 0x8000AE50: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8000AE54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000AE58: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x8000AE5C: sb          $v0, 0xB80($at)
    MEM_B(0XB80, ctx->r1) = ctx->r2;
    // 0x8000AE60: slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x8000AE64: beq         $v0, $zero, L_8000AE9C
    if (ctx->r2 == 0) {
        // 0x8000AE68: nop
    
            goto L_8000AE9C;
    }
    // 0x8000AE68: nop

    // 0x8000AE6C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000AE70: addiu       $a1, $a1, -0x34F0
    ctx->r5 = ADD32(ctx->r5, -0X34F0);
    // 0x8000AE74: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8000AE78: addiu       $a0, $a0, -0x34D0
    ctx->r4 = ADD32(ctx->r4, -0X34D0);
    // 0x8000AE7C: lwl         $v0, 0x0($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r5, 0X0);
    // 0x8000AE80: lwr         $v0, 0x3($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r5, 0X3);
    // 0x8000AE84: lb          $v1, 0x4($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X4);
    // 0x8000AE88: swl         $v0, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r2);
    // 0x8000AE8C: swr         $v0, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r2);
    // 0x8000AE90: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    // 0x8000AE94: j           L_8000AED0
    // 0x8000AE98: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
        goto L_8000AED0;
    // 0x8000AE98: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_8000AE9C:
    // 0x8000AE9C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000AEA0: addiu       $a1, $a1, -0x3310
    ctx->r5 = ADD32(ctx->r5, -0X3310);
    // 0x8000AEA4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8000AEA8: addiu       $a0, $a0, -0x34D0
    ctx->r4 = ADD32(ctx->r4, -0X34D0);
    // 0x8000AEAC: lwl         $v0, 0x0($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r5, 0X0);
    // 0x8000AEB0: lwr         $v0, 0x3($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r5, 0X3);
    // 0x8000AEB4: lb          $v1, 0x4($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X4);
    // 0x8000AEB8: swl         $v0, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r2);
    // 0x8000AEBC: swr         $v0, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r2);
    // 0x8000AEC0: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    // 0x8000AEC4: lb          $v0, 0x5($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X5);
    // 0x8000AEC8: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x8000AECC: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_8000AED0:
    // 0x8000AED0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000AED4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000AED8: lhu         $v1, -0x3FE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X3FE0);
    // 0x8000AEDC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000AEE0: lw          $v0, 0x3F34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F34);
    // 0x8000AEE4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AEE8: mflo        $v0
    ctx->r2 = lo;
    // 0x8000AEEC: lui         $v1, 0x3B9A
    ctx->r3 = S32(0X3B9A << 16);
    // 0x8000AEF0: ori         $v1, $v1, 0xC9FF
    ctx->r3 = ctx->r3 | 0XC9FF;
    // 0x8000AEF4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AEF8: sw          $v0, 0x3F34($at)
    MEM_W(0X3F34, ctx->r1) = ctx->r2;
    // 0x8000AEFC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000AF00: beq         $v0, $zero, L_8000AF10
    if (ctx->r2 == 0) {
        // 0x8000AF04: nop
    
            goto L_8000AF10;
    }
    // 0x8000AF04: nop

    // 0x8000AF08: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AF0C: sw          $v1, 0x3F34($at)
    MEM_W(0X3F34, ctx->r1) = ctx->r3;
L_8000AF10:
    // 0x8000AF10: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000AF14: lw          $a2, 0x3F34($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3F34);
    // 0x8000AF18: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8000AF1C: addiu       $a0, $a0, 0x2001
    ctx->r4 = ADD32(ctx->r4, 0X2001);
    // 0x8000AF20: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000AF24: jal         0x80066CA0
    // 0x8000AF28: addiu       $a1, $a1, -0x352C
    ctx->r5 = ADD32(ctx->r5, -0X352C);
    func_80066CA0(rdram, ctx);
        goto after_24;
    // 0x8000AF28: addiu       $a1, $a1, -0x352C
    ctx->r5 = ADD32(ctx->r5, -0X352C);
    after_24:
    // 0x8000AF2C: j           L_8000B0F0
    // 0x8000AF30: nop

        goto L_8000B0F0;
    // 0x8000AF30: nop

L_8000AF34:
    // 0x8000AF34: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8000AF38: lb          $v0, 0x2000($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2000);
    // 0x8000AF3C: beq         $v0, $zero, L_8000B0F0
    if (ctx->r2 == 0) {
        // 0x8000AF40: nop
    
            goto L_8000B0F0;
    }
    // 0x8000AF40: nop

    // 0x8000AF44: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000AF48: lw          $v1, 0x3F30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3F30);
    // 0x8000AF4C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8000AF50: bne         $a0, $zero, L_8000AF78
    if (ctx->r4 != 0) {
        // 0x8000AF54: nop
    
            goto L_8000AF78;
    }
    // 0x8000AF54: nop

    // 0x8000AF58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AF5C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AF60: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_8000AF64:
    // 0x8000AF64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000AF68: sb          $v1, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r3;
    // 0x8000AF6C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8000AF70: j           L_8000AFD0
    // 0x8000AF74: sw          $v1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r3;
        goto L_8000AFD0;
    // 0x8000AF74: sw          $v1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r3;
L_8000AF78:
    // 0x8000AF78: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000AF7C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000AF80: lb          $a3, 0x4($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X4);
    // 0x8000AF84: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8000AF88: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000AF8C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000AF90: andi        $t0, $v0, 0xAC
    ctx->r8 = ctx->r2 & 0XAC;
    // 0x8000AF94: andi        $v0, $a3, 0x80
    ctx->r2 = ctx->r7 & 0X80;
    // 0x8000AF98: beq         $v0, $zero, L_8000AFB8
    if (ctx->r2 == 0) {
        // 0x8000AF9C: addu        $a2, $a3, $zero
        ctx->r6 = ADD32(ctx->r7, 0);
            goto L_8000AFB8;
    }
    // 0x8000AF9C: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
L_8000AFA0:
    // 0x8000AFA0: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x8000AFA4: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8000AFA8: jal         0x8002C0C4
    // 0x8000AFAC: andi        $a2, $a2, 0x7F
    ctx->r6 = ctx->r6 & 0X7F;
    func_8002C0C4(rdram, ctx);
        goto after_25;
    // 0x8000AFAC: andi        $a2, $a2, 0x7F
    ctx->r6 = ctx->r6 & 0X7F;
    after_25:
    // 0x8000AFB0: j           L_8000AFD0
    // 0x8000AFB4: nop

        goto L_8000AFD0;
    // 0x8000AFB4: nop

L_8000AFB8:
    // 0x8000AFB8: lhu         $a2, 0x2($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X2);
    // 0x8000AFBC: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x8000AFC0: addu        $a1, $a0, $t0
    ctx->r5 = ADD32(ctx->r4, ctx->r8);
    // 0x8000AFC4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8000AFC8: jal         0x8002A840
    // 0x8000AFCC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_8002A840(rdram, ctx);
        goto after_26;
    // 0x8000AFCC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_26:
L_8000AFD0:
    // 0x8000AFD0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000AFD4: lw          $v0, 0x3F30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F30);
    // 0x8000AFD8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8000AFDC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AFE0: j           L_8000B0F0
    // 0x8000AFE4: sw          $v0, 0x3F30($at)
    MEM_W(0X3F30, ctx->r1) = ctx->r2;
        goto L_8000B0F0;
    // 0x8000AFE4: sw          $v0, 0x3F30($at)
    MEM_W(0X3F30, ctx->r1) = ctx->r2;
L_8000AFE8:
    // 0x8000AFE8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000AFEC: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000AFF0: lw          $v0, 0xE4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE4);
    // 0x8000AFF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000AFF8: bgez        $v0, L_8000B0F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000AFFC: sw          $v0, 0xE4($v1)
        MEM_W(0XE4, ctx->r3) = ctx->r2;
            goto L_8000B0F0;
    }
    // 0x8000AFFC: sw          $v0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->r2;
    // 0x8000B000: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B004: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B008: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000B00C: lw          $v1, 0x3F34($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3F34);
    // 0x8000B010: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8000B014: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B018: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x8000B01C: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8000B020: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000B024: sw          $v0, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r2;
    // 0x8000B028: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B02C: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B030: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8000B034: lui         $v1, 0x3B9A
    ctx->r3 = S32(0X3B9A << 16);
    // 0x8000B038: ori         $v1, $v1, 0xC9FF
    ctx->r3 = ctx->r3 | 0XC9FF;
    // 0x8000B03C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B040: bnel        $v0, $zero, L_8000B048
    if (ctx->r2 != 0) {
        // 0x8000B044: sw          $v1, 0x104($a0)
        MEM_W(0X104, ctx->r4) = ctx->r3;
            goto L_8000B048;
    }
    goto skip_5;
    // 0x8000B044: sw          $v1, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r3;
    skip_5:
L_8000B048:
    // 0x8000B048: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B04C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B050: lbu         $a1, 0x5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X5);
    // 0x8000B054: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000B058: jal         0x8000637C
    // 0x8000B05C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_27;
    // 0x8000B05C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_27:
    // 0x8000B060: j           L_8000B0F0
    // 0x8000B064: nop

        goto L_8000B0F0;
    // 0x8000B064: nop

L_8000B068:
    // 0x8000B068: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B06C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B070: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8000B074: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B078: sb          $v1, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r3;
    // 0x8000B07C: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8000B080: j           L_8000B0F0
    // 0x8000B084: sw          $v1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r3;
        goto L_8000B0F0;
    // 0x8000B084: sw          $v1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r3;
L_8000B088:
    // 0x8000B088: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B08C: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000B090: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x8000B094: bltz        $v0, L_8000B0CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B098: nop
    
            goto L_8000B0CC;
    }
    // 0x8000B098: nop

    // 0x8000B09C: j           L_8000B0BC
    // 0x8000B0A0: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
        goto L_8000B0BC;
    // 0x8000B0A0: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
L_8000B0A4:
    // 0x8000B0A4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B0A8: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000B0AC: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x8000B0B0: bltz        $v0, L_8000B0CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B0B4: nop
    
            goto L_8000B0CC;
    }
    // 0x8000B0B4: nop

    // 0x8000B0B8: lw          $v0, 0xB4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB4);
L_8000B0BC:
    // 0x8000B0BC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8000B0C0: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000B0C4: bne         $v0, $zero, L_8000B0E0
    if (ctx->r2 != 0) {
        // 0x8000B0C8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8000B0E0;
    }
    // 0x8000B0C8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8000B0CC:
    // 0x8000B0CC: lw          $v0, 0xE4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE4);
    // 0x8000B0D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000B0D4: bgez        $v0, L_8000B0F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000B0D8: sw          $v0, 0xE4($v1)
        MEM_W(0XE4, ctx->r3) = ctx->r2;
            goto L_8000B0F0;
    }
    // 0x8000B0D8: sw          $v0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->r2;
    // 0x8000B0DC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8000B0E0:
    // 0x8000B0E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B0E4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000B0E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B0EC: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
L_8000B0F0:
    // 0x8000B0F0: lw          $ra, 0x18C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18C);
    // 0x8000B0F4: lw          $fp, 0x188($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X188);
    // 0x8000B0F8: lw          $s7, 0x184($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X184);
    // 0x8000B0FC: lw          $s6, 0x180($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X180);
    // 0x8000B100: lw          $s5, 0x17C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X17C);
    // 0x8000B104: lw          $s4, 0x178($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X178);
    // 0x8000B108: lw          $s3, 0x174($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X174);
    // 0x8000B10C: lw          $s2, 0x170($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X170);
    // 0x8000B110: lw          $s1, 0x16C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X16C);
    // 0x8000B114: lw          $s0, 0x168($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X168);
    // 0x8000B118: ldc1        $f24, 0x1A0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X1A0);
    // 0x8000B11C: ldc1        $f22, 0x198($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X198);
    // 0x8000B120: ldc1        $f20, 0x190($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X190);
    // 0x8000B124: jr          $ra
    // 0x8000B128: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x8000B128: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void func_8000B12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B12C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B134: jal         0x8000B80C
    // 0x8000B138: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000B80C(rdram, ctx);
        goto after_0;
    // 0x8000B138: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000B13C: bne         $v0, $zero, L_8000B678
    if (ctx->r2 != 0) {
        // 0x8000B140: nop
    
            goto L_8000B678;
    }
    // 0x8000B140: nop

    // 0x8000B144: jal         0x8002D378
    // 0x8000B148: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_1;
    // 0x8000B148: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8000B14C: jal         0x8002D0D4
    // 0x8000B150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_2;
    // 0x8000B150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8000B154: jal         0x8002CFB8
    // 0x8000B158: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_3;
    // 0x8000B158: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x8000B15C: beq         $v0, $zero, L_8000B678
    if (ctx->r2 == 0) {
        // 0x8000B160: nop
    
            goto L_8000B678;
    }
    // 0x8000B160: nop

    // 0x8000B164: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B168: addiu       $a0, $a0, 0x7B9C
    ctx->r4 = ADD32(ctx->r4, 0X7B9C);
    // 0x8000B16C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B170: beq         $v0, $zero, L_8000B23C
    if (ctx->r2 == 0) {
        // 0x8000B174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000B23C;
    }
    // 0x8000B174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B178: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B17C: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x8000B180: beq         $v1, $v0, L_8000B218
    if (ctx->r3 == ctx->r2) {
        // 0x8000B184: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8000B218;
    }
    // 0x8000B184: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8000B188: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000B18C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B190: addiu       $a1, $a1, 0x3520
    ctx->r5 = ADD32(ctx->r5, 0X3520);
    // 0x8000B194: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000B198: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B19C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B1A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B1A4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8000B1A8:
    // 0x8000B1A8: sb          $zero, 0x28($a1)
    MEM_B(0X28, ctx->r5) = 0;
    // 0x8000B1AC: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x8000B1B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B1B4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000B1B8: sb          $zero, 0x6AC8($at)
    MEM_B(0X6AC8, ctx->r1) = 0;
    // 0x8000B1BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B1C0: slti        $v0, $a0, 0x23
    ctx->r2 = SIGNED(ctx->r4) < 0X23 ? 1 : 0;
    // 0x8000B1C4: bne         $v0, $zero, L_8000B1A8
    if (ctx->r2 != 0) {
        // 0x8000B1C8: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_8000B1A8;
    }
    // 0x8000B1C8: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x8000B1CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B1D0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B1D4: sw          $zero, 0x104($v0)
    MEM_W(0X104, ctx->r2) = 0;
    // 0x8000B1D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B1DC: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000B1E0: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x8000B1E4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8000B1E8: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x8000B1EC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B1F0: jal         0x8000C520
    // 0x8000B1F4: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    func_8000C520(rdram, ctx);
        goto after_4;
    // 0x8000B1F4: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    after_4:
    // 0x8000B1F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B1FC: lbu         $v1, 0x7B9D($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9D);
    // 0x8000B200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B204: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B208: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x8000B20C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B210: j           L_8000B650
    // 0x8000B214: sb          $v1, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = ctx->r3;
        goto L_8000B650;
    // 0x8000B214: sb          $v1, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = ctx->r3;
L_8000B218:
    // 0x8000B218: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8000B21C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B220: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B224: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B228: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B22C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000B230: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B234: j           L_8000B650
    // 0x8000B238: sb          $zero, 0x5584($at)
    MEM_B(0X5584, ctx->r1) = 0;
        goto L_8000B650;
    // 0x8000B238: sb          $zero, 0x5584($at)
    MEM_B(0X5584, ctx->r1) = 0;
L_8000B23C:
    // 0x8000B23C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B240: lbu         $v0, 0x7B7F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7F);
    // 0x8000B244: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8000B248: bne         $v0, $zero, L_8000B448
    if (ctx->r2 != 0) {
        // 0x8000B24C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8000B448;
    }
    // 0x8000B24C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000B250: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B254: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B258: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000B25C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B260: sb          $v1, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r3;
    // 0x8000B264: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B268: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B26C: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x8000B270: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B274: addiu       $a1, $a1, 0x3520
    ctx->r5 = ADD32(ctx->r5, 0X3520);
    // 0x8000B278: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8000B27C: sw          $zero, 0x104($v0)
    MEM_W(0X104, ctx->r2) = 0;
L_8000B280:
    // 0x8000B280: sb          $zero, 0x28($a1)
    MEM_B(0X28, ctx->r5) = 0;
    // 0x8000B284: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x8000B288: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B28C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000B290: sb          $zero, 0x6AC8($at)
    MEM_B(0X6AC8, ctx->r1) = 0;
    // 0x8000B294: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B298: slti        $v0, $a0, 0x23
    ctx->r2 = SIGNED(ctx->r4) < 0X23 ? 1 : 0;
    // 0x8000B29C: bne         $v0, $zero, L_8000B280
    if (ctx->r2 != 0) {
        // 0x8000B2A0: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_8000B280;
    }
    // 0x8000B2A0: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x8000B2A4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8000B2A8: addiu       $s0, $s0, 0x7B85
    ctx->r16 = ADD32(ctx->r16, 0X7B85);
    // 0x8000B2AC: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000B2B0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000B2B4: beq         $v1, $v0, L_8000B2C4
    if (ctx->r3 == ctx->r2) {
        // 0x8000B2B8: nop
    
            goto L_8000B2C4;
    }
    // 0x8000B2B8: nop

    // 0x8000B2BC: jal         0x8000C554
    // 0x8000B2C0: nop

    func_8000C554(rdram, ctx);
        goto after_5;
    // 0x8000B2C0: nop

    after_5:
L_8000B2C4:
    // 0x8000B2C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B2C8: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000B2CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B2D0: beq         $v1, $v0, L_8000B32C
    if (ctx->r3 == ctx->r2) {
        // 0x8000B2D4: nop
    
            goto L_8000B32C;
    }
    // 0x8000B2D4: nop

    // 0x8000B2D8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8000B2DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000B2E0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000B2E4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8000B2E8: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8000B2EC: bne         $v0, $zero, L_8000B318
    if (ctx->r2 != 0) {
        // 0x8000B2F0: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8000B318;
    }
    // 0x8000B2F0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000B2F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B2F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B2FC: sb          $v0, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = ctx->r2;
    // 0x8000B300: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8000B304: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B308: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B30C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B310: j           L_8000B410
    // 0x8000B314: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
        goto L_8000B410;
    // 0x8000B314: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8000B318:
    // 0x8000B318: bne         $v1, $v0, L_8000B410
    if (ctx->r3 != ctx->r2) {
        // 0x8000B31C: nop
    
            goto L_8000B410;
    }
    // 0x8000B31C: nop

    // 0x8000B320: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B324: j           L_8000B410
    // 0x8000B328: sb          $zero, 0x7BB0($at)
    MEM_B(0X7BB0, ctx->r1) = 0;
        goto L_8000B410;
    // 0x8000B328: sb          $zero, 0x7BB0($at)
    MEM_B(0X7BB0, ctx->r1) = 0;
L_8000B32C:
    // 0x8000B32C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B330: lbu         $v0, 0x7B9F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9F);
    // 0x8000B334: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000B338: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B33C: sb          $v0, 0x7B9F($at)
    MEM_B(0X7B9F, ctx->r1) = ctx->r2;
    // 0x8000B340: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000B344: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8000B348: bne         $v0, $zero, L_8000B394
    if (ctx->r2 != 0) {
        // 0x8000B34C: nop
    
            goto L_8000B394;
    }
    // 0x8000B34C: nop

    // 0x8000B350: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B354: lbu         $v0, 0x7B9E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9E);
    // 0x8000B358: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000B35C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B360: sb          $v0, 0x7B9E($at)
    MEM_B(0X7B9E, ctx->r1) = ctx->r2;
    // 0x8000B364: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000B368: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8000B36C: bne         $v0, $zero, L_8000B38C
    if (ctx->r2 != 0) {
        // 0x8000B370: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8000B38C;
    }
    // 0x8000B370: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8000B374: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B378: sb          $v0, 0x7B9F($at)
    MEM_B(0X7B9F, ctx->r1) = ctx->r2;
    // 0x8000B37C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8000B380: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B384: j           L_8000B394
    // 0x8000B388: sb          $v0, 0x7B9E($at)
    MEM_B(0X7B9E, ctx->r1) = ctx->r2;
        goto L_8000B394;
    // 0x8000B388: sb          $v0, 0x7B9E($at)
    MEM_B(0X7B9E, ctx->r1) = ctx->r2;
L_8000B38C:
    // 0x8000B38C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B390: sb          $zero, 0x7B9F($at)
    MEM_B(0X7B9F, ctx->r1) = 0;
L_8000B394:
    // 0x8000B394: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B398: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B39C: lb          $v1, 0x5A($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X5A);
    // 0x8000B3A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000B3A4: beq         $v1, $v0, L_8000B3C0
    if (ctx->r3 == ctx->r2) {
        // 0x8000B3A8: nop
    
            goto L_8000B3C0;
    }
    // 0x8000B3A8: nop

    // 0x8000B3AC: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8000B3B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000B3B4: sw          $v0, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r2;
    // 0x8000B3B8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B3BC: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
L_8000B3C0:
    // 0x8000B3C0: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8000B3C4: lui         $v1, 0x3B9A
    ctx->r3 = S32(0X3B9A << 16);
    // 0x8000B3C8: ori         $v1, $v1, 0xC9FF
    ctx->r3 = ctx->r3 | 0XC9FF;
    // 0x8000B3CC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000B3D0: bnel        $v0, $zero, L_8000B3D8
    if (ctx->r2 != 0) {
        // 0x8000B3D4: sw          $v1, 0x104($a0)
        MEM_W(0X104, ctx->r4) = ctx->r3;
            goto L_8000B3D8;
    }
    goto skip_0;
    // 0x8000B3D4: sw          $v1, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r3;
    skip_0:
L_8000B3D8:
    // 0x8000B3D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B3DC: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B3E0: lw          $v1, 0xA0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA0);
    // 0x8000B3E4: sltiu       $v0, $v1, 0x3E7
    ctx->r2 = ctx->r3 < 0X3E7 ? 1 : 0;
    // 0x8000B3E8: beq         $v0, $zero, L_8000B3F4
    if (ctx->r2 == 0) {
        // 0x8000B3EC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000B3F4;
    }
    // 0x8000B3EC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000B3F0: sw          $v0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r2;
L_8000B3F4:
    // 0x8000B3F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B3F8: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000B3FC: lbu         $a0, 0x73($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X73);
    // 0x8000B400: lw          $v0, 0xA8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA8);
    // 0x8000B404: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000B408: bnel        $v0, $zero, L_8000B410
    if (ctx->r2 != 0) {
        // 0x8000B40C: sw          $a0, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r4;
            goto L_8000B410;
    }
    goto skip_1;
    // 0x8000B40C: sw          $a0, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r4;
    skip_1:
L_8000B410:
    // 0x8000B410: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B414: addiu       $v1, $v1, 0x7BB0
    ctx->r3 = ADD32(ctx->r3, 0X7BB0);
    // 0x8000B418: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000B41C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000B420: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8000B424: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8000B428: bltzl       $v0, L_8000B430
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B42C: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_8000B430;
    }
    goto skip_2;
    // 0x8000B42C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_2:
L_8000B430:
    // 0x8000B430: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B434: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8000B438: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B43C: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x8000B440: j           L_8000B650
    // 0x8000B444: sb          $v0, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r2;
        goto L_8000B650;
    // 0x8000B444: sb          $v0, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r2;
L_8000B448:
    // 0x8000B448: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B44C: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B450: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8000B454: bgez        $v0, L_8000B4E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000B458: nop
    
            goto L_8000B4E0;
    }
    // 0x8000B458: nop

    // 0x8000B45C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B460: lbu         $v0, 0x207A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207A);
    // 0x8000B464: bne         $v0, $zero, L_8000B484
    if (ctx->r2 != 0) {
        // 0x8000B468: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000B484;
    }
    // 0x8000B468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B46C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8000B470: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B474: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B478: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B47C: j           L_8000B650
    // 0x8000B480: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
        goto L_8000B650;
    // 0x8000B480: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8000B484:
    // 0x8000B484: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B488: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000B48C: bne         $v1, $v0, L_8000B4C8
    if (ctx->r3 != ctx->r2) {
        // 0x8000B490: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000B4C8;
    }
    // 0x8000B490: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000B494: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8000B498: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B49C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B4A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B4A4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B4A8: lw          $v1, 0xD0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XD0);
    // 0x8000B4AC: lbu         $a0, 0x73($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X73);
    // 0x8000B4B0: lw          $v0, 0xA8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA8);
    // 0x8000B4B4: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000B4B8: bnel        $v0, $zero, L_8000B650
    if (ctx->r2 != 0) {
        // 0x8000B4BC: sw          $a0, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r4;
            goto L_8000B650;
    }
    goto skip_3;
    // 0x8000B4BC: sw          $a0, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r4;
    skip_3:
    // 0x8000B4C0: j           L_8000B650
    // 0x8000B4C4: nop

        goto L_8000B650;
    // 0x8000B4C4: nop

L_8000B4C8:
    // 0x8000B4C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B4CC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B4D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B4D4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B4D8: j           L_8000B650
    // 0x8000B4DC: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
        goto L_8000B650;
    // 0x8000B4DC: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
L_8000B4E0:
    // 0x8000B4E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B4E4: lbu         $v0, 0x207A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207A);
    // 0x8000B4E8: beq         $v0, $zero, L_8000B524
    if (ctx->r2 == 0) {
        // 0x8000B4EC: nop
    
            goto L_8000B524;
    }
    // 0x8000B4EC: nop

    // 0x8000B4F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B4F4: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8000B4F8: beq         $v0, $zero, L_8000B524
    if (ctx->r2 == 0) {
        // 0x8000B4FC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000B524;
    }
    // 0x8000B4FC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000B500: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B504: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x8000B508: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B50C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B510: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B514: beq         $v1, $zero, L_8000B668
    if (ctx->r3 == 0) {
        // 0x8000B518: sb          $zero, 0x7B71($at)
        MEM_B(0X7B71, ctx->r1) = 0;
            goto L_8000B668;
    }
    // 0x8000B518: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B51C: j           L_8000B660
    // 0x8000B520: nop

        goto L_8000B660;
    // 0x8000B520: nop

L_8000B524:
    // 0x8000B524: jal         0x8000C1F4
    // 0x8000B528: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000C1F4(rdram, ctx);
        goto after_6;
    // 0x8000B528: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // 0x8000B52C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B530: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8000B534: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B538: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
    // 0x8000B53C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000B540: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B544: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B548: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B54C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B550: bne         $a0, $v1, L_8000B564
    if (ctx->r4 != ctx->r3) {
        // 0x8000B554: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000B564;
    }
    // 0x8000B554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B558: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B55C: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x8000B560: sb          $zero, 0x6D($a0)
    MEM_B(0X6D, ctx->r4) = 0;
L_8000B564:
    // 0x8000B564: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B568: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B56C: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x8000B570: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000B574: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B578: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000B57C: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x8000B580: sw          $zero, 0x108($v0)
    MEM_W(0X108, ctx->r2) = 0;
    // 0x8000B584: sw          $zero, 0x104($v0)
    MEM_W(0X104, ctx->r2) = 0;
    // 0x8000B588: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B58C: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x8000B590: bltz        $v0, L_8000B5EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B594: nop
    
            goto L_8000B5EC;
    }
    // 0x8000B594: nop

    // 0x8000B598: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B59C: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x8000B5A0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B5A4: lbu         $a0, 0x2605($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2605);
    // 0x8000B5A8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000B5AC: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x8000B5B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000B5B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000B5B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000B5BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000B5C0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000B5C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B5C8: sb          $a0, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = ctx->r4;
    // 0x8000B5CC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000B5D0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B5D4: lw          $v0, 0x26A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26A8);
    // 0x8000B5D8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B5DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B5E0: sw          $v0, 0x26A4($at)
    MEM_W(0X26A4, ctx->r1) = ctx->r2;
    // 0x8000B5E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B5E8: sb          $v1, 0x2606($at)
    MEM_B(0X2606, ctx->r1) = ctx->r3;
L_8000B5EC:
    // 0x8000B5EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B5F0: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x8000B5F4: bltz        $v0, L_8000B650
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B5F8: nop
    
            goto L_8000B650;
    }
    // 0x8000B5F8: nop

    // 0x8000B5FC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B600: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x8000B604: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B608: lbu         $a0, 0x7A55($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A55);
    // 0x8000B60C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000B610: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x8000B614: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000B618: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000B61C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000B620: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000B624: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000B628: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B62C: sb          $a0, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = ctx->r4;
    // 0x8000B630: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000B634: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B638: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x8000B63C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B640: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B644: sw          $v0, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = ctx->r2;
    // 0x8000B648: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B64C: sb          $v1, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r3;
L_8000B650:
    // 0x8000B650: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B654: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x8000B658: beq         $v0, $zero, L_8000B668
    if (ctx->r2 == 0) {
        // 0x8000B65C: nop
    
            goto L_8000B668;
    }
    // 0x8000B65C: nop

L_8000B660:
    // 0x8000B660: jal         0x80006998
    // 0x8000B664: nop

    func_80006998(rdram, ctx);
        goto after_7;
    // 0x8000B664: nop

    after_7:
L_8000B668:
    // 0x8000B668: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B66C: sb          $zero, 0x79F1($at)
    MEM_B(0X79F1, ctx->r1) = 0;
    // 0x8000B670: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B674: sb          $zero, 0x25A1($at)
    MEM_B(0X25A1, ctx->r1) = 0;
L_8000B678:
    // 0x8000B678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B67C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000B680: jr          $ra
    // 0x8000B684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000B684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000B688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B68C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000B690: jal         0x8002D378
    // 0x8000B694: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_0;
    // 0x8000B694: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8000B698: jal         0x8002D0D4
    // 0x8000B69C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_1;
    // 0x8000B69C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8000B6A0: jal         0x8002CFB8
    // 0x8000B6A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_2;
    // 0x8000B6A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x8000B6A8: beq         $v0, $zero, L_8000B6D0
    if (ctx->r2 == 0) {
        // 0x8000B6AC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8000B6D0;
    }
    // 0x8000B6AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8000B6B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B6B4: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000B6B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B6BC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B6C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B6C4: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x8000B6C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B6CC: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
L_8000B6D0:
    // 0x8000B6D0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000B6D4: jr          $ra
    // 0x8000B6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000B6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000B6DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B6DC: jr          $ra
    // 0x8000B6E0: nop

    return;
    // 0x8000B6E0: nop

;}
RECOMP_FUNC void func_8000B6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B6E8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000B6EC: jal         0x8002D378
    // 0x8000B6F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_0;
    // 0x8000B6F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8000B6F4: jal         0x8002D0D4
    // 0x8000B6F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_1;
    // 0x8000B6F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8000B6FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B700: addiu       $a1, $a1, 0x7B72
    ctx->r5 = ADD32(ctx->r5, 0X7B72);
    // 0x8000B704: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8000B708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B70C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8000B710: beq         $v1, $v0, L_8000B754
    if (ctx->r3 == ctx->r2) {
        // 0x8000B714: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8000B754;
    }
    // 0x8000B714: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000B718: beql        $v0, $zero, L_8000B730
    if (ctx->r2 == 0) {
        // 0x8000B71C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000B730;
    }
    goto skip_0;
    // 0x8000B71C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8000B720: beq         $v1, $zero, L_8000B740
    if (ctx->r3 == 0) {
        // 0x8000B724: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000B740;
    }
    // 0x8000B724: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000B728: j           L_8000B800
    // 0x8000B72C: nop

        goto L_8000B800;
    // 0x8000B72C: nop

L_8000B730:
    // 0x8000B730: beq         $v1, $v0, L_8000B77C
    if (ctx->r3 == ctx->r2) {
        // 0x8000B734: nop
    
            goto L_8000B77C;
    }
    // 0x8000B734: nop

    // 0x8000B738: j           L_8000B800
    // 0x8000B73C: nop

        goto L_8000B800;
    // 0x8000B73C: nop

L_8000B740:
    // 0x8000B740: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8000B744: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000B748: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B74C: j           L_8000B800
    // 0x8000B750: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
        goto L_8000B800;
    // 0x8000B750: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
L_8000B754:
    // 0x8000B754: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B758: lhu         $v0, 0x7B74($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7B74);
    // 0x8000B75C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000B760: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B764: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000B768: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000B76C: bne         $v0, $zero, L_8000B800
    if (ctx->r2 != 0) {
        // 0x8000B770: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000B800;
    }
    // 0x8000B770: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000B774: j           L_8000B800
    // 0x8000B778: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_8000B800;
    // 0x8000B778: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_8000B77C:
    // 0x8000B77C: jal         0x8002CFB8
    // 0x8000B780: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_2;
    // 0x8000B780: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x8000B784: beq         $v0, $zero, L_8000B800
    if (ctx->r2 == 0) {
        // 0x8000B788: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000B800;
    }
    // 0x8000B788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B78C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B790: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x8000B794: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B798: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000B79C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000B7A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B7A4: sb          $v0, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = ctx->r2;
    // 0x8000B7A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B7AC: sb          $v0, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = ctx->r2;
    // 0x8000B7B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000B7B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000B7B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000B7BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000B7C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B7C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000B7C8: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x8000B7CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B7D0: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x8000B7D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B7D8: sb          $v0, 0x2606($at)
    MEM_B(0X2606, ctx->r1) = ctx->r2;
    // 0x8000B7DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000B7E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000B7E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000B7E8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000B7EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B7F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000B7F4: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x8000B7F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B7FC: sb          $v0, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r2;
L_8000B800:
    // 0x8000B800: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000B804: jr          $ra
    // 0x8000B808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000B808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000B80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B80C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B810: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x8000B814: bne         $v0, $zero, L_8000B824
    if (ctx->r2 != 0) {
        // 0x8000B818: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000B824;
    }
    // 0x8000B818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B81C: j           L_8000B838
    // 0x8000B820: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8000B838;
    // 0x8000B820: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000B824:
    // 0x8000B824: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x8000B828: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B82C: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x8000B830: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B834: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
L_8000B838:
    // 0x8000B838: jr          $ra
    // 0x8000B83C: nop

    return;
    // 0x8000B83C: nop

;}
RECOMP_FUNC void func_8000B840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B840: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B844: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x8000B848: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000B84C: bltz        $v0, L_8000B85C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B850: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8000B85C;
    }
    // 0x8000B850: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8000B854: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000B858: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
L_8000B85C:
    // 0x8000B85C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B860: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x8000B864: bltz        $v0, L_8000B874
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000B868: nop
    
            goto L_8000B874;
    }
    // 0x8000B868: nop

    // 0x8000B86C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B870: lhu         $v1, -0x389A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X389A);
L_8000B874:
    // 0x8000B874: jr          $ra
    // 0x8000B878: or          $v0, $a0, $v1
    ctx->r2 = ctx->r4 | ctx->r3;
    return;
    // 0x8000B878: or          $v0, $a0, $v1
    ctx->r2 = ctx->r4 | ctx->r3;
;}
RECOMP_FUNC void func_8000B87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B880: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000B884: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B888: addiu       $a1, $a1, 0x2070
    ctx->r5 = ADD32(ctx->r5, 0X2070);
    // 0x8000B88C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8000B890:
    // 0x8000B890: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000B894: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B898: sltiu       $v0, $a0, 0x38
    ctx->r2 = ctx->r4 < 0X38 ? 1 : 0;
    // 0x8000B89C: bne         $v0, $zero, L_8000B890
    if (ctx->r2 != 0) {
        // 0x8000B8A0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000B890;
    }
    // 0x8000B8A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000B8A4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B8A8: addiu       $a1, $a1, 0x7B30
    ctx->r5 = ADD32(ctx->r5, 0X7B30);
    // 0x8000B8AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8000B8B0:
    // 0x8000B8B0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000B8B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B8B8: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
    // 0x8000B8BC: bne         $v0, $zero, L_8000B8B0
    if (ctx->r2 != 0) {
        // 0x8000B8C0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000B8B0;
    }
    // 0x8000B8C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000B8C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B8C8: addiu       $a1, $a1, 0x5580
    ctx->r5 = ADD32(ctx->r5, 0X5580);
    // 0x8000B8CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000B8D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B8D4: addiu       $v1, $v1, 0x7B30
    ctx->r3 = ADD32(ctx->r3, 0X7B30);
    // 0x8000B8D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B8DC: sb          $v0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r2;
    // 0x8000B8E0: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
L_8000B8E4:
    // 0x8000B8E4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000B8E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B8EC: sltiu       $v0, $a0, 0x14
    ctx->r2 = ctx->r4 < 0X14 ? 1 : 0;
    // 0x8000B8F0: bne         $v0, $zero, L_8000B8E4
    if (ctx->r2 != 0) {
        // 0x8000B8F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000B8E4;
    }
    // 0x8000B8F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000B8F8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B8FC: addiu       $a1, $a1, 0x7B70
    ctx->r5 = ADD32(ctx->r5, 0X7B70);
    // 0x8000B900: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8000B904:
    // 0x8000B904: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000B908: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B90C: sltiu       $v0, $a0, 0x54
    ctx->r2 = ctx->r4 < 0X54 ? 1 : 0;
    // 0x8000B910: bne         $v0, $zero, L_8000B904
    if (ctx->r2 != 0) {
        // 0x8000B914: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8000B904;
    }
    // 0x8000B914: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000B918: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000B91C: addiu       $a1, $a1, 0x25A0
    ctx->r5 = ADD32(ctx->r5, 0X25A0);
    // 0x8000B920: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B924: addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // 0x8000B928: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000B92C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B930: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
    // 0x8000B934: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B938: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x8000B93C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B940: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000B944: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B948: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
L_8000B94C:
    // 0x8000B94C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000B950: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000B954: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000B958: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000B95C: sltiu       $v0, $a0, 0x13C
    ctx->r2 = ctx->r4 < 0X13C ? 1 : 0;
    // 0x8000B960: bne         $v0, $zero, L_8000B94C
    if (ctx->r2 != 0) {
        // 0x8000B964: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000B94C;
    }
    // 0x8000B964: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000B968: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000B96C: addiu       $v1, $v1, 0x25A0
    ctx->r3 = ADD32(ctx->r3, 0X25A0);
    // 0x8000B970: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000B974: addiu       $a0, $a0, 0x79F5
    ctx->r4 = ADD32(ctx->r4, 0X79F5);
    // 0x8000B978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B97C: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x8000B980: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8000B984: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B988: addiu       $v0, $v0, -0x1D20
    ctx->r2 = ADD32(ctx->r2, -0X1D20);
    // 0x8000B98C: sw          $v0, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r2;
    // 0x8000B990: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B994: addiu       $v0, $v0, -0x2740
    ctx->r2 = ADD32(ctx->r2, -0X2740);
    // 0x8000B998: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B99C: sw          $v0, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->r2;
    // 0x8000B9A0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8000B9A4: addiu       $v0, $v0, -0x34C8
    ctx->r2 = ADD32(ctx->r2, -0X34C8);
    // 0x8000B9A8: sw          $v0, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r2;
    // 0x8000B9AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B9B0: addiu       $v0, $v0, 0xE10
    ctx->r2 = ADD32(ctx->r2, 0XE10);
    // 0x8000B9B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B9B8: sw          $v0, 0x7B00($at)
    MEM_W(0X7B00, ctx->r1) = ctx->r2;
    // 0x8000B9BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000B9C0: addiu       $v0, $v0, 0x2FB0
    ctx->r2 = ADD32(ctx->r2, 0X2FB0);
    // 0x8000B9C4: sw          $v0, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r2;
    // 0x8000B9C8: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8000B9CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B9D0: sw          $v0, 0x7AA8($at)
    MEM_W(0X7AA8, ctx->r1) = ctx->r2;
    // 0x8000B9D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000B9D8: addiu       $v0, $v0, -0x2B50
    ctx->r2 = ADD32(ctx->r2, -0X2B50);
    // 0x8000B9DC: sw          $v0, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r2;
    // 0x8000B9E0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8000B9E4: addiu       $a0, $a0, -0x5
    ctx->r4 = ADD32(ctx->r4, -0X5);
    // 0x8000B9E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000B9EC: sw          $v0, 0x7AA4($at)
    MEM_W(0X7AA4, ctx->r1) = ctx->r2;
    // 0x8000B9F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000B9F4: addiu       $v0, $v0, 0x4478
    ctx->r2 = ADD32(ctx->r2, 0X4478);
    // 0x8000B9F8: sw          $a0, 0xD0($v1)
    MEM_W(0XD0, ctx->r3) = ctx->r4;
    // 0x8000B9FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA00: sw          $v1, 0x7AC0($at)
    MEM_W(0X7AC0, ctx->r1) = ctx->r3;
    // 0x8000BA04: sw          $v0, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r2;
    // 0x8000BA08: addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    // 0x8000BA0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA10: sw          $v0, 0x7AC4($at)
    MEM_W(0X7AC4, ctx->r1) = ctx->r2;
    // 0x8000BA14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000BA18: addiu       $v0, $v0, 0x55A0
    ctx->r2 = ADD32(ctx->r2, 0X55A0);
    // 0x8000BA1C: sw          $v0, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->r2;
    // 0x8000BA20: addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // 0x8000BA24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA28: jal         0x8004D958
    // 0x8000BA2C: sw          $v0, 0x7AC8($at)
    MEM_W(0X7AC8, ctx->r1) = ctx->r2;
    func_8004D958(rdram, ctx);
        goto after_0;
    // 0x8000BA2C: sw          $v0, 0x7AC8($at)
    MEM_W(0X7AC8, ctx->r1) = ctx->r2;
    after_0:
    // 0x8000BA30: jal         0x80051C30
    // 0x8000BA34: nop

    func_80051C30(rdram, ctx);
        goto after_1;
    // 0x8000BA34: nop

    after_1:
    // 0x8000BA38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000BA3C: jr          $ra
    // 0x8000BA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000BA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000BA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BA48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000BA4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA50: sb          $zero, 0x7B83($at)
    MEM_B(0X7B83, ctx->r1) = 0;
    // 0x8000BA54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA58: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x8000BA5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000BA60: sw          $zero, -0x761C($at)
    MEM_W(-0X761C, ctx->r1) = 0;
    // 0x8000BA64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA68: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    // 0x8000BA6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA70: sb          $zero, 0x7BA1($at)
    MEM_B(0X7BA1, ctx->r1) = 0;
    // 0x8000BA74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA78: sb          $zero, 0x7BA2($at)
    MEM_B(0X7BA2, ctx->r1) = 0;
    // 0x8000BA7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BA80: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
    // 0x8000BA84: jal         0x8000C1F4
    // 0x8000BA88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000C1F4(rdram, ctx);
        goto after_0;
    // 0x8000BA88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8000BA8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000BA90: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8000BA94: bne         $v0, $zero, L_8000BAAC
    if (ctx->r2 != 0) {
        // 0x8000BA98: nop
    
            goto L_8000BAAC;
    }
    // 0x8000BA98: nop

    // 0x8000BA9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BAA0: sb          $zero, 0x7A58($at)
    MEM_B(0X7A58, ctx->r1) = 0;
    // 0x8000BAA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BAA8: sb          $zero, 0x2608($at)
    MEM_B(0X2608, ctx->r1) = 0;
L_8000BAAC:
    // 0x8000BAAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BAB0: sw          $zero, 0x7AF4($at)
    MEM_W(0X7AF4, ctx->r1) = 0;
    // 0x8000BAB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BAB8: sw          $zero, 0x26A4($at)
    MEM_W(0X26A4, ctx->r1) = 0;
    // 0x8000BABC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000BAC0: jr          $ra
    // 0x8000BAC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000BAC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000BAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BAC8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000BACC: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x8000BAD0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8000BAD4: addiu       $t1, $t1, 0x3A40
    ctx->r9 = ADD32(ctx->r9, 0X3A40);
    // 0x8000BAD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8000BADC: addiu       $a3, $zero, 0x4B00
    ctx->r7 = ADD32(0, 0X4B00);
    // 0x8000BAE0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000BAE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000BAE8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000BAEC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8000BAF0: sll         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3 << 11);
    // 0x8000BAF4: lui         $v0, 0x8037
    ctx->r2 = S32(0X8037 << 16);
    // 0x8000BAF8: addiu       $v0, $v0, -0x6000
    ctx->r2 = ADD32(ctx->r2, -0X6000);
    // 0x8000BAFC: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x8000BB00: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
L_8000BB04:
    // 0x8000BB04: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x8000BB08: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8000BB0C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8000BB10: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8000BB14: sltiu       $v0, $a3, -0x1
    ctx->r2 = ctx->r7 < -0X1 ? 1 : 0;
    // 0x8000BB18: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000BB1C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000BB20: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8000BB24: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000BB28: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8000BB2C: bgezl       $a2, L_8000BB04
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8000BB30: sll         $v1, $a3, 3
        ctx->r3 = S32(ctx->r7 << 3);
            goto L_8000BB04;
    }
    goto skip_0;
    // 0x8000BB30: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    skip_0:
    // 0x8000BB34: jr          $ra
    // 0x8000BB38: nop

    return;
    // 0x8000BB38: nop

;}
RECOMP_FUNC void func_8000BB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB3C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000BB40: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x8000BB44: addiu       $t1, $t1, 0x6AA0
    ctx->r9 = ADD32(ctx->r9, 0X6AA0);
    // 0x8000BB48: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8000BB4C: addiu       $t0, $t0, 0x3520
    ctx->r8 = ADD32(ctx->r8, 0X3520);
    // 0x8000BB50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8000BB54:
    // 0x8000BB54: addu        $a1, $a3, $t1
    ctx->r5 = ADD32(ctx->r7, ctx->r9);
    // 0x8000BB58: addu        $a0, $a3, $t0
    ctx->r4 = ADD32(ctx->r7, ctx->r8);
    // 0x8000BB5C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000BB60:
    // 0x8000BB60: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000BB64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000BB68: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000BB6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BB70: sltiu       $v0, $v1, 0x70
    ctx->r2 = ctx->r3 < 0X70 ? 1 : 0;
    // 0x8000BB74: bne         $v0, $zero, L_8000BB60
    if (ctx->r2 != 0) {
        // 0x8000BB78: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000BB60;
    }
    // 0x8000BB78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000BB7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BB80: slti        $v0, $a2, 0x23
    ctx->r2 = SIGNED(ctx->r6) < 0X23 ? 1 : 0;
    // 0x8000BB84: bne         $v0, $zero, L_8000BB54
    if (ctx->r2 != 0) {
        // 0x8000BB88: addiu       $a3, $a3, 0x70
        ctx->r7 = ADD32(ctx->r7, 0X70);
            goto L_8000BB54;
    }
    // 0x8000BB88: addiu       $a3, $a3, 0x70
    ctx->r7 = ADD32(ctx->r7, 0X70);
    // 0x8000BB8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000BB90: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    // 0x8000BB94: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000BB98:
    // 0x8000BB98: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000BB9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BBA0: sltiu       $v0, $v1, 0x70
    ctx->r2 = ctx->r3 < 0X70 ? 1 : 0;
    // 0x8000BBA4: bne         $v0, $zero, L_8000BB98
    if (ctx->r2 != 0) {
        // 0x8000BBA8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000BB98;
    }
    // 0x8000BBA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000BBAC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000BBB0: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x8000BBB4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000BBB8:
    // 0x8000BBB8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000BBBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BBC0: sltiu       $v0, $v1, 0x70
    ctx->r2 = ctx->r3 < 0X70 ? 1 : 0;
    // 0x8000BBC4: bne         $v0, $zero, L_8000BBB8
    if (ctx->r2 != 0) {
        // 0x8000BBC8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000BBB8;
    }
    // 0x8000BBC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000BBCC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000BBD0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x8000BBD4: addiu       $a3, $a3, -0x66F8
    ctx->r7 = ADD32(ctx->r7, -0X66F8);
    // 0x8000BBD8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8000BBDC:
    // 0x8000BBDC: addu        $a0, $a1, $a3
    ctx->r4 = ADD32(ctx->r5, ctx->r7);
    // 0x8000BBE0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000BBE4:
    // 0x8000BBE4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000BBE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BBEC: sltiu       $v0, $v1, 0x70
    ctx->r2 = ctx->r3 < 0X70 ? 1 : 0;
    // 0x8000BBF0: bne         $v0, $zero, L_8000BBE4
    if (ctx->r2 != 0) {
        // 0x8000BBF4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000BBE4;
    }
    // 0x8000BBF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000BBF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BBFC: slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8000BC00: bne         $v0, $zero, L_8000BBDC
    if (ctx->r2 != 0) {
        // 0x8000BC04: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_8000BBDC;
    }
    // 0x8000BC04: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x8000BC08: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000BC0C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8000BC10: addiu       $a3, $a3, 0x53C0
    ctx->r7 = ADD32(ctx->r7, 0X53C0);
    // 0x8000BC14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8000BC18:
    // 0x8000BC18: addu        $a0, $a1, $a3
    ctx->r4 = ADD32(ctx->r5, ctx->r7);
    // 0x8000BC1C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000BC20:
    // 0x8000BC20: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000BC24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BC28: sltiu       $v0, $v1, 0x70
    ctx->r2 = ctx->r3 < 0X70 ? 1 : 0;
    // 0x8000BC2C: bne         $v0, $zero, L_8000BC20
    if (ctx->r2 != 0) {
        // 0x8000BC30: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000BC20;
    }
    // 0x8000BC30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000BC34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000BC38: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8000BC3C: bne         $v0, $zero, L_8000BC18
    if (ctx->r2 != 0) {
        // 0x8000BC40: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_8000BC18;
    }
    // 0x8000BC40: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x8000BC44: jr          $ra
    // 0x8000BC48: nop

    return;
    // 0x8000BC48: nop

;}
RECOMP_FUNC void func_8000BC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BC50: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000BC54: lui         $s2, 0x1062
    ctx->r18 = S32(0X1062 << 16);
    // 0x8000BC58: ori         $s2, $s2, 0x4DD3
    ctx->r18 = ctx->r18 | 0X4DD3;
    // 0x8000BC5C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000BC60: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x8000BC64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000BC68: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000BC6C: addiu       $s0, $s0, -0xE5C
    ctx->r16 = ADD32(ctx->r16, -0XE5C);
    // 0x8000BC70: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000BC74: addiu       $s3, $s0, 0x8
    ctx->r19 = ADD32(ctx->r16, 0X8);
    // 0x8000BC78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000BC7C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8000BC80: addiu       $s1, $s1, 0x21A0
    ctx->r17 = ADD32(ctx->r17, 0X21A0);
    // 0x8000BC84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_8000BC88:
    // 0x8000BC88: jal         0x8006CEB0
    // 0x8000BC8C: nop

    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x8000BC8C: nop

    after_0:
    // 0x8000BC90: mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000BC94: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8000BC98: mfhi        $a1
    ctx->r5 = hi;
    // 0x8000BC9C: sra         $a0, $a1, 6
    ctx->r4 = S32(SIGNED(ctx->r5) >> 6);
    // 0x8000BCA0: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8000BCA4: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x8000BCA8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000BCAC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000BCB0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000BCB4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000BCB8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BCBC: addiu       $v0, $v0, 0x1F4
    ctx->r2 = ADD32(ctx->r2, 0X1F4);
    // 0x8000BCC0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8000BCC4: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8000BCC8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000BCCC: mflo        $v1
    ctx->r3 = lo;
    // 0x8000BCD0: sw          $v1, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->r3;
    // 0x8000BCD4: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8000BCD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000BCDC: subu        $v0, $s4, $v0
    ctx->r2 = SUB32(ctx->r20, ctx->r2);
    // 0x8000BCE0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000BCE4: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000BCE8: bne         $v0, $zero, L_8000BC88
    if (ctx->r2 != 0) {
        // 0x8000BCEC: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_8000BC88;
    }
    // 0x8000BCEC: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x8000BCF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000BCF4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000BCF8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BCFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000BD00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000BD04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000BD08: jr          $ra
    // 0x8000BD0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BD0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000BD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BD14: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000BD18: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x8000BD1C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000BD20: bne         $v0, $zero, L_8000BD3C
    if (ctx->r2 != 0) {
        // 0x8000BD24: sw          $v0, 0x80($a0)
        MEM_W(0X80, ctx->r4) = ctx->r2;
            goto L_8000BD3C;
    }
    // 0x8000BD24: sw          $v0, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r2;
    // 0x8000BD28: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8000BD2C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8000BD30: sw          $v1, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r3;
    // 0x8000BD34: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000BD38: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
L_8000BD3C:
    // 0x8000BD3C: lw          $a1, 0x70($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X70);
    // 0x8000BD40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8000BD44: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8000BD48: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
    // 0x8000BD4C: jal         0x80018514
    // 0x8000BD50: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_80018514(rdram, ctx);
        goto after_0;
    // 0x8000BD50: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8000BD54: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000BD58: jr          $ra
    // 0x8000BD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000BD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000BD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000BD64: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000BD68: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000BD6C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8000BD70: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8000BD74: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000BD78: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000BD7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000BD80: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000BD84: lbu         $a0, 0x60($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X60);
    // 0x8000BD88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BD8C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8000BD90: beq         $v1, $v0, L_8000BE64
    if (ctx->r3 == ctx->r2) {
        // 0x8000BD94: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8000BE64;
    }
    // 0x8000BD94: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000BD98: beql        $v0, $zero, L_8000BDB0
    if (ctx->r2 == 0) {
        // 0x8000BD9C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000BDB0;
    }
    goto skip_0;
    // 0x8000BD9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8000BDA0: beq         $v1, $zero, L_8000BDC0
    if (ctx->r3 == 0) {
        // 0x8000BDA4: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000BDC0;
    }
    // 0x8000BDA4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000BDA8: j           L_8000BF78
    // 0x8000BDAC: nop

        goto L_8000BF78;
    // 0x8000BDAC: nop

L_8000BDB0:
    // 0x8000BDB0: beq         $v1, $v0, L_8000BE84
    if (ctx->r3 == ctx->r2) {
        // 0x8000BDB4: nop
    
            goto L_8000BE84;
    }
    // 0x8000BDB4: nop

    // 0x8000BDB8: j           L_8000BF78
    // 0x8000BDBC: nop

        goto L_8000BF78;
    // 0x8000BDBC: nop

L_8000BDC0:
    // 0x8000BDC0: lui         $s3, 0x1062
    ctx->r19 = S32(0X1062 << 16);
    // 0x8000BDC4: ori         $s3, $s3, 0x4DD3
    ctx->r19 = ctx->r19 | 0X4DD3;
    // 0x8000BDC8: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8000BDCC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000BDD0: addiu       $s0, $s0, -0xE5C
    ctx->r16 = ADD32(ctx->r16, -0XE5C);
    // 0x8000BDD4: addiu       $s4, $s0, 0x8
    ctx->r20 = ADD32(ctx->r16, 0X8);
    // 0x8000BDD8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8000BDDC: addiu       $s1, $s1, 0x21A0
    ctx->r17 = ADD32(ctx->r17, 0X21A0);
    // 0x8000BDE0: sb          $v0, 0x60($s2)
    MEM_B(0X60, ctx->r18) = ctx->r2;
    // 0x8000BDE4: addiu       $v0, $zero, -0xC0
    ctx->r2 = ADD32(0, -0XC0);
    // 0x8000BDE8: sh          $v0, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r2;
    // 0x8000BDEC: sw          $zero, 0x68($s2)
    MEM_W(0X68, ctx->r18) = 0;
    // 0x8000BDF0: sw          $zero, 0x74($s2)
    MEM_W(0X74, ctx->r18) = 0;
L_8000BDF4:
    // 0x8000BDF4: jal         0x8006CEB0
    // 0x8000BDF8: nop

    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x8000BDF8: nop

    after_0:
    // 0x8000BDFC: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000BE00: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8000BE04: mfhi        $a2
    ctx->r6 = hi;
    // 0x8000BE08: sra         $a0, $a2, 6
    ctx->r4 = S32(SIGNED(ctx->r6) >> 6);
    // 0x8000BE0C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8000BE10: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x8000BE14: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000BE18: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000BE1C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000BE20: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000BE24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000BE28: addiu       $v0, $v0, 0x1F4
    ctx->r2 = ADD32(ctx->r2, 0X1F4);
    // 0x8000BE2C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8000BE30: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8000BE34: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000BE38: mflo        $v1
    ctx->r3 = lo;
    // 0x8000BE3C: sw          $v1, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->r3;
    // 0x8000BE40: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8000BE44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000BE48: subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // 0x8000BE4C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000BE50: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8000BE54: bne         $v0, $zero, L_8000BDF4
    if (ctx->r2 != 0) {
        // 0x8000BE58: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_8000BDF4;
    }
    // 0x8000BE58: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x8000BE5C: j           L_8000BF78
    // 0x8000BE60: nop

        goto L_8000BF78;
    // 0x8000BE60: nop

L_8000BE64:
    // 0x8000BE64: lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7C);
    // 0x8000BE68: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000BE6C: bne         $v0, $zero, L_8000BF78
    if (ctx->r2 != 0) {
        // 0x8000BE70: sw          $v0, 0x7C($s2)
        MEM_W(0X7C, ctx->r18) = ctx->r2;
            goto L_8000BF78;
    }
    // 0x8000BE70: sw          $v0, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r2;
    // 0x8000BE74: lbu         $v0, 0x60($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X60);
    // 0x8000BE78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000BE7C: j           L_8000BF78
    // 0x8000BE80: sb          $v0, 0x60($s2)
    MEM_B(0X60, ctx->r18) = ctx->r2;
        goto L_8000BF78;
    // 0x8000BE80: sb          $v0, 0x60($s2)
    MEM_B(0X60, ctx->r18) = ctx->r2;
L_8000BE84:
    // 0x8000BE84: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8000BE88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BE8C: ldc1        $f2, -0x32D8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X32D8);
    // 0x8000BE90: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000BE94: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8000BE98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BE9C: ldc1        $f4, -0x32D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32D0);
    // 0x8000BEA0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8000BEA4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8000BEA8: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8000BEAC: nop

    // 0x8000BEB0: nop

    // 0x8000BEB4: bc1f        L_8000BECC
    if (!c1cs) {
        // 0x8000BEB8: swc1        $f0, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
            goto L_8000BECC;
    }
    // 0x8000BEB8: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
    // 0x8000BEBC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8000BEC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000BEC4: nop

    // 0x8000BEC8: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
L_8000BECC:
    // 0x8000BECC: lhu         $v0, 0x2A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2A);
    // 0x8000BED0: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8000BED4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000BED8: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8000BEDC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000BEE0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8000BEE4: nop

    // 0x8000BEE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000BEEC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000BEF0: sh          $v1, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r3;
    // 0x8000BEF4: lw          $v1, 0x74($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X74);
    // 0x8000BEF8: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x8000BEFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000BF00: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x8000BF04: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000BF08: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000BF0C: bne         $v0, $zero, L_8000BF78
    if (ctx->r2 != 0) {
        // 0x8000BF10: nop
    
            goto L_8000BF78;
    }
    // 0x8000BF10: nop

    // 0x8000BF14: lw          $v0, 0x78($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X78);
    // 0x8000BF18: sh          $v1, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r3;
    // 0x8000BF1C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8000BF20: sw          $v0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r2;
    // 0x8000BF24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BF28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BF2C: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
    // 0x8000BF30: lwc1        $f4, 0x68($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8000BF34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BF38: ldc1        $f2, -0x32C8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X32C8);
    // 0x8000BF3C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8000BF40: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8000BF44: nop

    // 0x8000BF48: nop

    // 0x8000BF4C: bc1fl       L_8000BF60
    if (!c1cs) {
        // 0x8000BF50: neg.s       $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
            goto L_8000BF60;
    }
    goto skip_1;
    // 0x8000BF50: neg.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
    skip_1:
    // 0x8000BF54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000BF58: j           L_8000BF78
    // 0x8000BF5C: sh          $v0, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = ctx->r2;
        goto L_8000BF78;
    // 0x8000BF5C: sh          $v0, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = ctx->r2;
L_8000BF60:
    // 0x8000BF60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BF64: ldc1        $f2, -0x32C0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X32C0);
    // 0x8000BF68: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8000BF6C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8000BF70: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8000BF74: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
L_8000BF78:
    // 0x8000BF78: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
    // 0x8000BF7C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000BF80: bne         $v0, $zero, L_8000BF9C
    if (ctx->r2 != 0) {
        // 0x8000BF84: sw          $v0, 0x80($s2)
        MEM_W(0X80, ctx->r18) = ctx->r2;
            goto L_8000BF9C;
    }
    // 0x8000BF84: sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // 0x8000BF88: lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X84);
    // 0x8000BF8C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8000BF90: sw          $v1, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r3;
    // 0x8000BF94: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000BF98: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
L_8000BF9C:
    // 0x8000BF9C: lw          $a1, 0x70($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X70);
    // 0x8000BFA0: lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X84);
    // 0x8000BFA4: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    // 0x8000BFA8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8000BFAC: jal         0x80018514
    // 0x8000BFB0: sw          $a1, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r5;
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x8000BFB0: sw          $a1, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r5;
    after_1:
    // 0x8000BFB4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8000BFB8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8000BFBC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000BFC0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BFC4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000BFC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000BFCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000BFD0: jr          $ra
    // 0x8000BFD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000BFD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000BFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BFDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000BFE0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8000BFE4: addiu       $s0, $s0, 0x7B98
    ctx->r16 = ADD32(ctx->r16, 0X7B98);
    // 0x8000BFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BFEC: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000BFF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000BFF4: beq         $v1, $v0, L_8000C00C
    if (ctx->r3 == ctx->r2) {
        // 0x8000BFF8: nop
    
            goto L_8000C00C;
    }
    // 0x8000BFF8: nop

    // 0x8000BFFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C000: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8000C004: beq         $v0, $zero, L_8000C0E8
    if (ctx->r2 == 0) {
        // 0x8000C008: nop
    
            goto L_8000C0E8;
    }
    // 0x8000C008: nop

L_8000C00C:
    // 0x8000C00C: jal         0x8006CEB0
    // 0x8000C010: nop

    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x8000C010: nop

    after_0:
    // 0x8000C014: lui         $v1, 0x2AAA
    ctx->r3 = S32(0X2AAA << 16);
    // 0x8000C018: ori         $v1, $v1, 0xAAAB
    ctx->r3 = ctx->r3 | 0XAAAB;
    // 0x8000C01C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C020: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8000C024: mfhi        $a3
    ctx->r7 = hi;
    // 0x8000C028: subu        $a0, $a3, $a0
    ctx->r4 = SUB32(ctx->r7, ctx->r4);
    // 0x8000C02C: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8000C030: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000C034: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000C038: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C03C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000C040: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C044: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x8000C048: lbu         $a1, 0x14($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X14);
    // 0x8000C04C: lbu         $v1, -0x13($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X13);
    // 0x8000C050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000C054: beq         $v1, $a1, L_8000C074
    if (ctx->r3 == ctx->r5) {
        // 0x8000C058: addiu       $a0, $s0, -0x13
        ctx->r4 = ADD32(ctx->r16, -0X13);
            goto L_8000C074;
    }
    // 0x8000C058: addiu       $a0, $s0, -0x13
    ctx->r4 = ADD32(ctx->r16, -0X13);
    // 0x8000C05C: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
    // 0x8000C060: beq         $v1, $v0, L_8000C074
    if (ctx->r3 == ctx->r2) {
        // 0x8000C064: nop
    
            goto L_8000C074;
    }
    // 0x8000C064: nop

    // 0x8000C068: lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X16);
    // 0x8000C06C: bne         $v1, $v0, L_8000C0B4
    if (ctx->r3 != ctx->r2) {
        // 0x8000C070: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8000C0B4;
    }
    // 0x8000C070: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8000C074:
    // 0x8000C074: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000C078: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000C07C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8000C080: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000C084: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x8000C088: beql        $v0, $zero, L_8000C090
    if (ctx->r2 == 0) {
        // 0x8000C08C: sb          $a2, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r6;
            goto L_8000C090;
    }
    goto skip_0;
    // 0x8000C08C: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    skip_0:
L_8000C090:
    // 0x8000C090: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000C094: beq         $v1, $a1, L_8000C074
    if (ctx->r3 == ctx->r5) {
        // 0x8000C098: nop
    
            goto L_8000C074;
    }
    // 0x8000C098: nop

    // 0x8000C09C: lbu         $v0, 0x28($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X28);
    // 0x8000C0A0: beq         $v1, $v0, L_8000C074
    if (ctx->r3 == ctx->r2) {
        // 0x8000C0A4: nop
    
            goto L_8000C074;
    }
    // 0x8000C0A4: nop

    // 0x8000C0A8: lbu         $v0, 0x29($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X29);
    // 0x8000C0AC: beq         $v1, $v0, L_8000C074
    if (ctx->r3 == ctx->r2) {
        // 0x8000C0B0: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8000C074;
    }
    // 0x8000C0B0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8000C0B4:
    // 0x8000C0B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C0B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000C0BC: lbu         $v0, 0x7BAC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BAC);
    // 0x8000C0C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C0C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000C0C8: sb          $v0, 0x7BAD($at)
    MEM_B(0X7BAD, ctx->r1) = ctx->r2;
    // 0x8000C0CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000C0D0: bgez        $v1, L_8000C0B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000C0D4: nop
    
            goto L_8000C0B4;
    }
    // 0x8000C0D4: nop

    // 0x8000C0D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C0DC: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x8000C0E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C0E4: sb          $v0, 0x7BAC($at)
    MEM_B(0X7BAC, ctx->r1) = ctx->r2;
L_8000C0E8:
    // 0x8000C0E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C0EC: addiu       $v1, $v1, 0x25A0
    ctx->r3 = ADD32(ctx->r3, 0X25A0);
    // 0x8000C0F0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8000C0F4: beq         $v0, $zero, L_8000C128
    if (ctx->r2 == 0) {
        // 0x8000C0F8: nop
    
            goto L_8000C128;
    }
    // 0x8000C0F8: nop

    // 0x8000C0FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C100: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000C104: beq         $v0, $zero, L_8000C128
    if (ctx->r2 == 0) {
        // 0x8000C108: nop
    
            goto L_8000C128;
    }
    // 0x8000C108: nop

    // 0x8000C10C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C110: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8000C114: bne         $v0, $zero, L_8000C144
    if (ctx->r2 != 0) {
        // 0x8000C118: nop
    
            goto L_8000C144;
    }
    // 0x8000C118: nop

    // 0x8000C11C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C120: j           L_8000C144
    // 0x8000C124: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
        goto L_8000C144;
    // 0x8000C124: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
L_8000C128:
    // 0x8000C128: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000C12C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    // 0x8000C130: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8000C134: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C138: addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // 0x8000C13C: bnel        $v0, $zero, L_8000C144
    if (ctx->r2 != 0) {
        // 0x8000C140: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8000C144;
    }
    goto skip_1;
    // 0x8000C140: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    skip_1:
L_8000C144:
    // 0x8000C144: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x8000C148: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000C14C: bne         $v0, $zero, L_8000C164
    if (ctx->r2 != 0) {
        // 0x8000C150: nop
    
            goto L_8000C164;
    }
    // 0x8000C150: nop

    // 0x8000C154: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C158: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x8000C15C: j           L_8000C170
    // 0x8000C160: srl         $v1, $v0, 4
    ctx->r3 = S32(U32(ctx->r2) >> 4);
        goto L_8000C170;
    // 0x8000C160: srl         $v1, $v0, 4
    ctx->r3 = S32(U32(ctx->r2) >> 4);
L_8000C164:
    // 0x8000C164: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C168: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x8000C16C: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
L_8000C170:
    // 0x8000C170: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C174: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000C178: beq         $v0, $zero, L_8000C1B0
    if (ctx->r2 == 0) {
        // 0x8000C17C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000C1B0;
    }
    // 0x8000C17C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000C180: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C184: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000C188: beq         $v0, $zero, L_8000C1B0
    if (ctx->r2 == 0) {
        // 0x8000C18C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000C1B0;
    }
    // 0x8000C18C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000C190: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C194: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8000C198: bne         $v0, $zero, L_8000C1B0
    if (ctx->r2 != 0) {
        // 0x8000C19C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000C1B0;
    }
    // 0x8000C19C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000C1A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C1A4: sb          $v1, 0x7B86($at)
    MEM_B(0X7B86, ctx->r1) = ctx->r3;
    // 0x8000C1A8: j           L_8000C1DC
    // 0x8000C1AC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8000C1DC;
    // 0x8000C1AC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8000C1B0:
    // 0x8000C1B0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C1B4: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x8000C1B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C1BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C1C0: lw          $v0, 0x7E64($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E64);
    // 0x8000C1C4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000C1C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C1CC: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x8000C1D0: lbu         $a0, -0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X2);
    // 0x8000C1D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C1D8: sb          $v0, 0x7B86($at)
    MEM_B(0X7B86, ctx->r1) = ctx->r2;
L_8000C1DC:
    // 0x8000C1DC: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8000C1E0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000C1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C1E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000C1EC: jr          $ra
    // 0x8000C1F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000C1F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000C1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C1F4: bne         $a0, $zero, L_8000C238
    if (ctx->r4 != 0) {
        // 0x8000C1F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000C238;
    }
    // 0x8000C1F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000C1FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C200: lbu         $v0, 0x25F6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25F6);
    // 0x8000C204: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000C208: lbu         $a0, 0x2076($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2076);
    // 0x8000C20C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C210: lbu         $v1, 0x7A46($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A46);
    // 0x8000C214: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8000C218: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8000C21C: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
    // 0x8000C220: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000C224: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C228: sb          $v0, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = ctx->r2;
    // 0x8000C22C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C230: j           L_8000C264
    // 0x8000C234: sb          $v1, 0x7A64($at)
    MEM_B(0X7A64, ctx->r1) = ctx->r3;
        goto L_8000C264;
    // 0x8000C234: sb          $v1, 0x7A64($at)
    MEM_B(0X7A64, ctx->r1) = ctx->r3;
L_8000C238:
    // 0x8000C238: bne         $a0, $v0, L_8000C248
    if (ctx->r4 != ctx->r2) {
        // 0x8000C23C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000C248;
    }
    // 0x8000C23C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000C240: j           L_8000C254
    // 0x8000C244: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8000C254;
    // 0x8000C244: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000C248:
    // 0x8000C248: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C24C: lbu         $v1, 0x2076($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2076);
    // 0x8000C250: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8000C254:
    // 0x8000C254: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C258: sb          $v0, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = ctx->r2;
    // 0x8000C25C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C260: sb          $v0, 0x7A64($at)
    MEM_B(0X7A64, ctx->r1) = ctx->r2;
L_8000C264:
    // 0x8000C264: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C268: addiu       $v1, $v1, 0x2614
    ctx->r3 = ADD32(ctx->r3, 0X2614);
    // 0x8000C26C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C270: sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // 0x8000C274: bne         $v0, $zero, L_8000C280
    if (ctx->r2 != 0) {
        // 0x8000C278: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8000C280;
    }
    // 0x8000C278: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000C27C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000C280:
    // 0x8000C280: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C284: addiu       $v1, $v1, 0x7A64
    ctx->r3 = ADD32(ctx->r3, 0X7A64);
    // 0x8000C288: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C28C: sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // 0x8000C290: bne         $v0, $zero, L_8000C29C
    if (ctx->r2 != 0) {
        // 0x8000C294: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8000C29C;
    }
    // 0x8000C294: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000C298: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000C29C:
    // 0x8000C29C: jr          $ra
    // 0x8000C2A0: nop

    return;
    // 0x8000C2A0: nop

;}
RECOMP_FUNC void func_8000C2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C2A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C2A8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000C2AC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8000C2B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000C2B4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000C2B8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8000C2BC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000C2C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000C2C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000C2C8: addiu       $s0, $zero, -0x6
    ctx->r16 = ADD32(0, -0X6);
L_8000C2CC:
    // 0x8000C2CC: addiu       $s1, $zero, -0x6C
    ctx->r17 = ADD32(0, -0X6C);
L_8000C2D0:
    // 0x8000C2D0: lw          $v0, 0xB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C2D4: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8000C2D8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8000C2DC: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C2E0: beq         $v0, $zero, L_8000C324
    if (ctx->r2 == 0) {
        // 0x8000C2E4: nop
    
            goto L_8000C324;
    }
    // 0x8000C2E4: nop

    // 0x8000C2E8: jal         0x8006CEB0
    // 0x8000C2EC: nop

    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x8000C2EC: nop

    after_0:
    // 0x8000C2F0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000C2F4: bne         $v0, $zero, L_8000C308
    if (ctx->r2 != 0) {
        // 0x8000C2F8: nop
    
            goto L_8000C308;
    }
    // 0x8000C2F8: nop

    // 0x8000C2FC: lw          $v0, 0xE4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XE4);
    // 0x8000C300: bne         $v0, $zero, L_8000C324
    if (ctx->r2 != 0) {
        // 0x8000C304: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000C324;
    }
    // 0x8000C304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000C308:
    // 0x8000C308: lw          $v1, 0xB0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C30C: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x8000C310: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x8000C314: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8000C318: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8000C31C: sb          $v0, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r2;
    // 0x8000C320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000C324:
    // 0x8000C324: lw          $v0, 0xB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C328: addu        $v1, $s2, $v0
    ctx->r3 = ADD32(ctx->r18, ctx->r2);
    // 0x8000C32C: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8000C330: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C334: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8000C338: bne         $v0, $zero, L_8000C354
    if (ctx->r2 != 0) {
        // 0x8000C33C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8000C354;
    }
    // 0x8000C33C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8000C340: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C344: slti        $v0, $s0, 0x9
    ctx->r2 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x8000C348: bne         $v0, $zero, L_8000C2D0
    if (ctx->r2 != 0) {
        // 0x8000C34C: addiu       $s1, $s1, 0x12
        ctx->r17 = ADD32(ctx->r17, 0X12);
            goto L_8000C2D0;
    }
    // 0x8000C34C: addiu       $s1, $s1, 0x12
    ctx->r17 = ADD32(ctx->r17, 0X12);
    // 0x8000C350: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8000C354:
    // 0x8000C354: beq         $s0, $v0, L_8000C394
    if (ctx->r16 == ctx->r2) {
        // 0x8000C358: addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
            goto L_8000C394;
    }
    // 0x8000C358: addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // 0x8000C35C: beq         $s0, $v0, L_8000C378
    if (ctx->r16 == ctx->r2) {
        // 0x8000C360: sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16 << 3);
            goto L_8000C378;
    }
    // 0x8000C360: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8000C364: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000C368: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000C36C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C370: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C374: sb          $v1, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = ctx->r3;
L_8000C378:
    // 0x8000C378: lw          $v1, 0xB0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C37C: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8000C380: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000C384: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000C388: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x8000C38C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C390: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
L_8000C394:
    // 0x8000C394: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x8000C398: addiu       $s1, $zero, 0x132
    ctx->r17 = ADD32(0, 0X132);
L_8000C39C:
    // 0x8000C39C: lw          $v0, 0xB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C3A0: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8000C3A4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8000C3A8: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C3AC: beq         $v0, $zero, L_8000C3F0
    if (ctx->r2 == 0) {
        // 0x8000C3B0: nop
    
            goto L_8000C3F0;
    }
    // 0x8000C3B0: nop

    // 0x8000C3B4: jal         0x8006CEB0
    // 0x8000C3B8: nop

    func_8006CEB0(rdram, ctx);
        goto after_1;
    // 0x8000C3B8: nop

    after_1:
    // 0x8000C3BC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000C3C0: bne         $v0, $zero, L_8000C3D4
    if (ctx->r2 != 0) {
        // 0x8000C3C4: nop
    
            goto L_8000C3D4;
    }
    // 0x8000C3C4: nop

    // 0x8000C3C8: lw          $v0, 0xE4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XE4);
    // 0x8000C3CC: bne         $v0, $zero, L_8000C3F0
    if (ctx->r2 != 0) {
        // 0x8000C3D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000C3F0;
    }
    // 0x8000C3D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000C3D4:
    // 0x8000C3D4: lw          $v1, 0xB0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C3D8: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x8000C3DC: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x8000C3E0: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8000C3E4: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8000C3E8: sb          $v0, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r2;
    // 0x8000C3EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000C3F0:
    // 0x8000C3F0: lw          $v0, 0xB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C3F4: addu        $v1, $s2, $v0
    ctx->r3 = ADD32(ctx->r18, ctx->r2);
    // 0x8000C3F8: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8000C3FC: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C400: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8000C404: bne         $v0, $zero, L_8000C420
    if (ctx->r2 != 0) {
        // 0x8000C408: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8000C420;
    }
    // 0x8000C408: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8000C40C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8000C410: slti        $v0, $s0, 0x9
    ctx->r2 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x8000C414: beq         $v0, $zero, L_8000C39C
    if (ctx->r2 == 0) {
        // 0x8000C418: addiu       $s1, $s1, -0x12
        ctx->r17 = ADD32(ctx->r17, -0X12);
            goto L_8000C39C;
    }
    // 0x8000C418: addiu       $s1, $s1, -0x12
    ctx->r17 = ADD32(ctx->r17, -0X12);
    // 0x8000C41C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8000C420:
    // 0x8000C420: beql        $s0, $v0, L_8000C468
    if (ctx->r16 == ctx->r2) {
        // 0x8000C424: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8000C468;
    }
    goto skip_0;
    // 0x8000C424: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8000C428: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8000C42C: beq         $s0, $v0, L_8000C448
    if (ctx->r16 == ctx->r2) {
        // 0x8000C430: sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16 << 3);
            goto L_8000C448;
    }
    // 0x8000C430: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8000C434: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000C438: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000C43C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C440: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000C444: sb          $v1, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r3;
L_8000C448:
    // 0x8000C448: lw          $v1, 0xB0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB0);
    // 0x8000C44C: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8000C450: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000C454: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000C458: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x8000C45C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C460: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
    // 0x8000C464: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000C468:
    // 0x8000C468: slti        $v0, $s2, 0xA
    ctx->r2 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8000C46C: bne         $v0, $zero, L_8000C2CC
    if (ctx->r2 != 0) {
        // 0x8000C470: addiu       $s0, $zero, -0x6
        ctx->r16 = ADD32(0, -0X6);
            goto L_8000C2CC;
    }
    // 0x8000C470: addiu       $s0, $zero, -0x6
    ctx->r16 = ADD32(0, -0X6);
    // 0x8000C474: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8000C478: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000C47C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C480: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000C484: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8000C488: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000C48C: jr          $ra
    // 0x8000C490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000C490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000C494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C494: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C498: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000C49C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C4A0: bne         $v1, $v0, L_8000C4B4
    if (ctx->r3 != ctx->r2) {
        // 0x8000C4A4: nop
    
            goto L_8000C4B4;
    }
    // 0x8000C4A4: nop

    // 0x8000C4A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C4AC: j           L_8000C4E0
    // 0x8000C4B0: lbu         $v0, 0x7B9F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9F);
        goto L_8000C4E0;
    // 0x8000C4B0: lbu         $v0, 0x7B9F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9F);
L_8000C4B4:
    // 0x8000C4B4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C4B8: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x8000C4BC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C4C0: addiu       $a1, $a1, -0x3FB7
    ctx->r5 = ADD32(ctx->r5, -0X3FB7);
    // 0x8000C4C4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000C4C8: lb          $a0, 0x7BB0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7BB0);
    // 0x8000C4CC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000C4D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000C4D4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000C4D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000C4DC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
L_8000C4E0:
    // 0x8000C4E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C4E4: jr          $ra
    // 0x8000C4E8: sb          $v0, 0x7B9A($at)
    MEM_B(0X7B9A, ctx->r1) = ctx->r2;
    return;
    // 0x8000C4E8: sb          $v0, 0x7B9A($at)
    MEM_B(0X7B9A, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8000C4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C4EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C4F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000C4F4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8000C4F8: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x8000C4FC: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x8000C500: addiu       $a0, $a0, -0x380
    ctx->r4 = ADD32(ctx->r4, -0X380);
    // 0x8000C504: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // 0x8000C508: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8000C50C: jal         0x80006D98
    // 0x8000C510: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8000C510: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x8000C514: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000C518: jr          $ra
    // 0x8000C51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000C51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000C520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C520: lbu         $v1, 0x74($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X74);
    // 0x8000C524: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000C528: sb          $v0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r2;
    // 0x8000C52C: sb          $v0, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r2;
    // 0x8000C530: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000C534: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000C538: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C53C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C540: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C544: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C548: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x8000C54C: jr          $ra
    // 0x8000C550: sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
    return;
    // 0x8000C550: sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8000C554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C554: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8000C558: addiu       $t3, $t3, 0x7B85
    ctx->r11 = ADD32(ctx->r11, 0X7B85);
    // 0x8000C55C: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8000C560: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000C564: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8000C568: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C56C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8000C570: lbu         $v1, 0x7B53($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B53);
    // 0x8000C574: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C578: lbu         $v0, 0x7B80($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B80);
    // 0x8000C57C: lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // 0x8000C580: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8000C584: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C588: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C58C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C590: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8000C594: lbu         $v1, 0x7B52($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B52);
    // 0x8000C598: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C59C: lbu         $v0, 0x7B81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B81);
    // 0x8000C5A0: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C5A4: mfhi        $t4
    ctx->r12 = hi;
    // 0x8000C5A8: srl         $a0, $t4, 5
    ctx->r4 = S32(U32(ctx->r12) >> 5);
    // 0x8000C5AC: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8000C5B0: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C5B4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C5B8: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8000C5BC: lbu         $v1, 0x7B51($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B51);
    // 0x8000C5C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C5C4: lbu         $v0, 0x7B82($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B82);
    // 0x8000C5C8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000C5CC: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8000C5D0: lbu         $a2, 0x7B50($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B50);
    // 0x8000C5D4: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // 0x8000C5D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C5DC: lbu         $v0, 0x7BA5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA5);
    // 0x8000C5E0: mfhi        $t4
    ctx->r12 = hi;
    // 0x8000C5E4: srl         $v1, $t4, 5
    ctx->r3 = S32(U32(ctx->r12) >> 5);
    // 0x8000C5E8: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8000C5EC: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C5F0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000C5F4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8000C5F8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8000C5FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C600: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8000C604: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8000C608: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C60C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C610: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8000C614: mfhi        $t4
    ctx->r12 = hi;
    // 0x8000C618: srl         $v1, $t4, 5
    ctx->r3 = S32(U32(ctx->r12) >> 5);
    // 0x8000C61C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8000C620: sltiu       $v0, $a2, 0x64
    ctx->r2 = ctx->r6 < 0X64 ? 1 : 0;
    // 0x8000C624: beql        $v0, $zero, L_8000C62C
    if (ctx->r2 == 0) {
        // 0x8000C628: addiu       $a2, $zero, 0x63
        ctx->r6 = ADD32(0, 0X63);
            goto L_8000C62C;
    }
    goto skip_0;
    // 0x8000C628: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    skip_0:
L_8000C62C:
    // 0x8000C62C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8000C630: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000C634: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C638: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000C63C: sb          $a2, 0x7B50($at)
    MEM_B(0X7B50, ctx->r1) = ctx->r6;
    // 0x8000C640: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x8000C644: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C648: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x8000C64C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000C650: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000C654: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C658: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000C65C: sb          $a3, 0x7B51($at)
    MEM_B(0X7B51, ctx->r1) = ctx->r7;
    // 0x8000C660: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8000C664: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000C668: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C66C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C670: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C674: sb          $t0, 0x7B52($at)
    MEM_B(0X7B52, ctx->r1) = ctx->r8;
    // 0x8000C678: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8000C67C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000C680: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000C684: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C688: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C68C: jr          $ra
    // 0x8000C690: sb          $t2, 0x7B53($at)
    MEM_B(0X7B53, ctx->r1) = ctx->r10;
    return;
    // 0x8000C690: sb          $t2, 0x7B53($at)
    MEM_B(0X7B53, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_8000C6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C6A0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000C6A4: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8000C6A8: lui         $a1, 0xF650
    ctx->r5 = S32(0XF650 << 16);
    // 0x8000C6AC: ori         $a1, $a1, 0x3C0
    ctx->r5 = ctx->r5 | 0X3C0;
    // 0x8000C6B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000C6B4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000C6B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000C6BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000C6C0: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8000C6C4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000C6C8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000C6CC: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8000C6D0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000C6D4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8000C6D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000C6DC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000C6E0: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8000C6E4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000C6E8: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8000C6EC: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x8000C6F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000C6F4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000C6F8: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x8000C6FC: jr          $ra
    // 0x8000C700: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    return;
    // 0x8000C700: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8000C704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C708: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8000C70C: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x8000C710: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000C714: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C718: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000C71C: lw          $a0, -0xBF4($at)
    ctx->r4 = MEM_W(ctx->r1, -0XBF4);
    // 0x8000C720: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8000C724: sra         $v0, $v0, 19
    ctx->r2 = S32(SIGNED(ctx->r2) >> 19);
    // 0x8000C728: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8000C72C: sra         $a2, $a2, 19
    ctx->r6 = S32(SIGNED(ctx->r6) >> 19);
    // 0x8000C730: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000C734: addiu       $a1, $a1, -0x2F50
    ctx->r5 = ADD32(ctx->r5, -0X2F50);
    // 0x8000C738: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x8000C73C: addu        $a1, $a2, $a1
    ctx->r5 = ADD32(ctx->r6, ctx->r5);
    // 0x8000C740: sra         $a2, $a3, 24
    ctx->r6 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8000C744: jal         0x8005334C
    // 0x8000C748: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x8000C748: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x8000C74C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000C750: jr          $ra
    // 0x8000C754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000C754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000C758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C758: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C75C: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000C760: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000C764: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000C768: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x8000C76C: sw          $ra, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r31;
    // 0x8000C770: sw          $fp, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r30;
    // 0x8000C774: sw          $s7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r23;
    // 0x8000C778: sw          $s6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r22;
    // 0x8000C77C: sw          $s5, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r21;
    // 0x8000C780: sw          $s4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r20;
    // 0x8000C784: sw          $s3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r19;
    // 0x8000C788: sw          $s2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r18;
    // 0x8000C78C: sw          $s1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r17;
    // 0x8000C790: sw          $s0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r16;
    // 0x8000C794: sdc1        $f22, 0x178($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X178, ctx->r29);
    // 0x8000C798: sdc1        $f20, 0x170($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X170, ctx->r29);
    // 0x8000C79C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000C7A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000C7A4: sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // 0x8000C7A8: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000C7AC: sb          $zero, 0x67($sp)
        MEM_B(0X67, ctx->r29) = 0;
            goto L_8000E33C;
    }
    // 0x8000C7AC: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
    // 0x8000C7B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000C7B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000C7B8: addu        $at, $at, $v0
    gpr jr_addend_8000C7C0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000C7BC: lw          $v0, -0x3258($at)
    ctx->r2 = ADD32(ctx->r1, -0X3258);
    // 0x8000C7C0: jr          $v0
    // 0x8000C7C4: nop

    switch (jr_addend_8000C7C0 >> 2) {
        case 0: goto L_8000C7C8; break;
        case 1: goto L_8000CA4C; break;
        case 2: goto L_8000CA94; break;
        case 3: goto L_8000CC34; break;
        case 4: goto L_8000CDB4; break;
        case 5: goto L_8000CDFC; break;
        case 6: goto L_8000CFB0; break;
        case 7: goto L_8000D7E0; break;
        case 8: goto L_8000D274; break;
        case 9: goto L_8000D570; break;
        case 10: goto L_8000D7E0; break;
        case 11: goto L_8000D820; break;
        case 12: goto L_8000DFE4; break;
        case 13: goto L_8000E028; break;
        case 14: goto L_8000E0F8; break;
        case 15: goto L_8000E24C; break;
        default: switch_error(__func__, 0x8000C7C0, 0x800ACDA8);
    }
    // 0x8000C7C4: nop

L_8000C7C8:
    // 0x8000C7C8: jal         0x80031BEC
    // 0x8000C7CC: addiu       $s5, $zero, 0xC0
    ctx->r21 = ADD32(0, 0XC0);
    func_80031BEC(rdram, ctx);
        goto after_0;
    // 0x8000C7CC: addiu       $s5, $zero, 0xC0
    ctx->r21 = ADD32(0, 0XC0);
    after_0:
    // 0x8000C7D0: jal         0x80041910
    // 0x8000C7D4: addiu       $s2, $zero, 0x240
    ctx->r18 = ADD32(0, 0X240);
    func_80041910(rdram, ctx);
        goto after_1;
    // 0x8000C7D4: addiu       $s2, $zero, 0x240
    ctx->r18 = ADD32(0, 0X240);
    after_1:
    // 0x8000C7D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000C7DC: lw          $a0, -0xBF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBF4);
    // 0x8000C7E0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000C7E4: addiu       $a1, $a1, -0x2F50
    ctx->r5 = ADD32(ctx->r5, -0X2F50);
    // 0x8000C7E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000C7EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C7F0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000C7F4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8000C7F8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000C7FC: sb          $v0, 0x3F5C($at)
    MEM_B(0X3F5C, ctx->r1) = ctx->r2;
    // 0x8000C800: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000C804: sb          $v0, 0x3F5B($at)
    MEM_B(0X3F5B, ctx->r1) = ctx->r2;
    // 0x8000C808: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000C80C: sb          $v0, 0x3F5A($at)
    MEM_B(0X3F5A, ctx->r1) = ctx->r2;
    // 0x8000C810: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000C814: sb          $v0, 0x3F59($at)
    MEM_B(0X3F59, ctx->r1) = ctx->r2;
    // 0x8000C818: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000C81C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C820: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000C824: addiu       $v0, $zero, 0x4AF
    ctx->r2 = ADD32(0, 0X4AF);
    // 0x8000C828: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C82C: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
    // 0x8000C830: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C834: sb          $zero, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = 0;
    // 0x8000C838: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C83C: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
    // 0x8000C840: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C844: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x8000C848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C84C: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    // 0x8000C850: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000C854: sw          $v0, 0x3F40($at)
    MEM_W(0X3F40, ctx->r1) = ctx->r2;
    // 0x8000C858: jal         0x8005334C
    // 0x8000C85C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_8005334C(rdram, ctx);
        goto after_2;
    // 0x8000C85C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8000C860: jal         0x800067C8
    // 0x8000C864: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800067C8(rdram, ctx);
        goto after_3;
    // 0x8000C864: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8000C868: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C86C: addiu       $v0, $v0, 0x6ACA
    ctx->r2 = ADD32(ctx->r2, 0X6ACA);
    // 0x8000C870: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000C874: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000C878: jal         0x80017760
    // 0x8000C87C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_4;
    // 0x8000C87C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_4:
    // 0x8000C880: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000C884: addiu       $s1, $s1, -0x57C0
    ctx->r17 = ADD32(ctx->r17, -0X57C0);
    // 0x8000C888: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C88C: sh          $s5, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r21;
    // 0x8000C890: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C894: sh          $s5, 0x6AAE($at)
    MEM_H(0X6AAE, ctx->r1) = ctx->r21;
    // 0x8000C898: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C89C: sw          $s1, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r17;
    // 0x8000C8A0: jal         0x80066D30
    // 0x8000C8A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_5;
    // 0x8000C8A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8000C8A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C8AC: addiu       $v0, $v0, 0x354A
    ctx->r2 = ADD32(ctx->r2, 0X354A);
    // 0x8000C8B0: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000C8B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000C8B8: jal         0x80017760
    // 0x8000C8BC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_6;
    // 0x8000C8BC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_6:
    // 0x8000C8C0: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8000C8C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C8C8: sh          $s5, 0x352A($at)
    MEM_H(0X352A, ctx->r1) = ctx->r21;
    // 0x8000C8CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C8D0: sh          $s5, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r21;
    // 0x8000C8D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C8D8: sh          $v0, 0x352C($at)
    MEM_H(0X352C, ctx->r1) = ctx->r2;
    // 0x8000C8DC: jal         0x80066D30
    // 0x8000C8E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_7;
    // 0x8000C8E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8000C8E4: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8000C8E8: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8000C8EC: addiu       $a1, $s1, -0x7800
    ctx->r5 = ADD32(ctx->r17, -0X7800);
    // 0x8000C8F0: jal         0x80006D98
    // 0x8000C8F4: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_8;
    // 0x8000C8F4: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_8:
    // 0x8000C8F8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000C8FC: addiu       $v0, $v0, -0x7636
    ctx->r2 = ADD32(ctx->r2, -0X7636);
    // 0x8000C900: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000C904: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000C908: jal         0x80017760
    // 0x8000C90C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_9;
    // 0x8000C90C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_9:
    // 0x8000C910: addiu       $s1, $zero, 0x600
    ctx->r17 = ADD32(0, 0X600);
    // 0x8000C914: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8000C918: addiu       $s4, $s4, -0x75C0
    ctx->r20 = ADD32(ctx->r20, -0X75C0);
    // 0x8000C91C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8000C920: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8000C924: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8000C928: addiu       $s3, $s3, -0x2338
    ctx->r19 = ADD32(ctx->r19, -0X2338);
    // 0x8000C92C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C930: sh          $s1, -0x765E($at)
    MEM_H(-0X765E, ctx->r1) = ctx->r17;
    // 0x8000C934: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C938: sh          $zero, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = 0;
    // 0x8000C93C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C940: sh          $s5, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = ctx->r21;
    // 0x8000C944: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C948: sh          $s1, -0x765A($at)
    MEM_H(-0X765A, ctx->r1) = ctx->r17;
    // 0x8000C94C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C950: sh          $s2, -0x7652($at)
    MEM_H(-0X7652, ctx->r1) = ctx->r18;
    // 0x8000C954: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C958: sh          $s2, -0x7656($at)
    MEM_H(-0X7656, ctx->r1) = ctx->r18;
    // 0x8000C95C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C960: sw          $s4, -0x7650($at)
    MEM_W(-0X7650, ctx->r1) = ctx->r20;
    // 0x8000C964: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C968: sb          $s7, -0x764A($at)
    MEM_B(-0X764A, ctx->r1) = ctx->r23;
    // 0x8000C96C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C970: sb          $s6, -0x7649($at)
    MEM_B(-0X7649, ctx->r1) = ctx->r22;
    // 0x8000C974: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C978: sh          $zero, -0x7648($at)
    MEM_H(-0X7648, ctx->r1) = 0;
    // 0x8000C97C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C980: sw          $s3, -0x7630($at)
    MEM_W(-0X7630, ctx->r1) = ctx->r19;
    // 0x8000C984: jal         0x80066D30
    // 0x8000C988: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_10;
    // 0x8000C988: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8000C98C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000C990: addiu       $v0, $v0, 0x20D2
    ctx->r2 = ADD32(ctx->r2, 0X20D2);
    // 0x8000C994: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000C998: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000C99C: jal         0x80017760
    // 0x8000C9A0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_11;
    // 0x8000C9A0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_11:
    // 0x8000C9A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9A8: sh          $s1, 0x20AA($at)
    MEM_H(0X20AA, ctx->r1) = ctx->r17;
    // 0x8000C9AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000C9B0: sh          $s1, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r17;
    // 0x8000C9B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9B8: sh          $s5, 0x20B4($at)
    MEM_H(0X20B4, ctx->r1) = ctx->r21;
    // 0x8000C9BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9C0: sh          $s1, 0x20AE($at)
    MEM_H(0X20AE, ctx->r1) = ctx->r17;
    // 0x8000C9C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9C8: sh          $s2, 0x20B6($at)
    MEM_H(0X20B6, ctx->r1) = ctx->r18;
    // 0x8000C9CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9D0: sh          $s2, 0x20B2($at)
    MEM_H(0X20B2, ctx->r1) = ctx->r18;
    // 0x8000C9D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9D8: sw          $s4, 0x20B8($at)
    MEM_W(0X20B8, ctx->r1) = ctx->r20;
    // 0x8000C9DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9E0: sb          $s7, 0x20BE($at)
    MEM_B(0X20BE, ctx->r1) = ctx->r23;
    // 0x8000C9E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9E8: sb          $s6, 0x20BF($at)
    MEM_B(0X20BF, ctx->r1) = ctx->r22;
    // 0x8000C9EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9F0: sh          $zero, 0x20C0($at)
    MEM_H(0X20C0, ctx->r1) = 0;
    // 0x8000C9F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000C9F8: sw          $s3, 0x20D8($at)
    MEM_W(0X20D8, ctx->r1) = ctx->r19;
    // 0x8000C9FC: jal         0x80066D30
    // 0x8000CA00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_12;
    // 0x8000CA00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x8000CA04: lui         $a0, 0x11
    ctx->r4 = S32(0X11 << 16);
    // 0x8000CA08: addiu       $a0, $a0, -0x2EC0
    ctx->r4 = ADD32(ctx->r4, -0X2EC0);
    // 0x8000CA0C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8000CA10: jal         0x80006D98
    // 0x8000CA14: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    func_80006D98(rdram, ctx);
        goto after_13;
    // 0x8000CA14: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    after_13:
    // 0x8000CA18: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x8000CA1C: addiu       $a0, $a0, -0x56C0
    ctx->r4 = ADD32(ctx->r4, -0X56C0);
    // 0x8000CA20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8000CA24: jal         0x80006D98
    // 0x8000CA28: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_14;
    // 0x8000CA28: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_14:
    // 0x8000CA2C: jal         0x80053390
    // 0x8000CA30: nop

    func_80053390(rdram, ctx);
        goto after_15;
    // 0x8000CA30: nop

    after_15:
    // 0x8000CA34: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CA38: sb          $zero, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = 0;
    // 0x8000CA3C: jal         0x800064C0
    // 0x8000CA40: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_16;
    // 0x8000CA40: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_16:
    // 0x8000CA44: j           L_8000E33C
    // 0x8000CA48: nop

        goto L_8000E33C;
    // 0x8000CA48: nop

L_8000CA4C:
    // 0x8000CA4C: jal         0x80008CDC
    // 0x8000CA50: nop

    func_80008CDC(rdram, ctx);
        goto after_17;
    // 0x8000CA50: nop

    after_17:
    // 0x8000CA54: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CA58: nop
    
            goto L_8000E33C;
    }
    // 0x8000CA58: nop

    // 0x8000CA5C: jal         0x8002CFB8
    // 0x8000CA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_18;
    // 0x8000CA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x8000CA64: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CA68: nop
    
            goto L_8000E33C;
    }
    // 0x8000CA68: nop

    // 0x8000CA6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CA70: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000CA74: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000CA78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CA7C: sb          $zero, 0x7A58($at)
    MEM_B(0X7A58, ctx->r1) = 0;
    // 0x8000CA80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CA84: sb          $zero, 0x2608($at)
    MEM_B(0X2608, ctx->r1) = 0;
    // 0x8000CA88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CA8C: j           L_8000E33C
    // 0x8000CA90: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8000E33C;
    // 0x8000CA90: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000CA94:
    // 0x8000CA94: jal         0x80008CDC
    // 0x8000CA98: nop

    func_80008CDC(rdram, ctx);
        goto after_19;
    // 0x8000CA98: nop

    after_19:
    // 0x8000CA9C: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CAA0: nop
    
            goto L_8000E33C;
    }
    // 0x8000CAA0: nop

    // 0x8000CAA4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000CAA8: lw          $v0, 0x3F40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F40);
    // 0x8000CAAC: beq         $v0, $zero, L_8000CC10
    if (ctx->r2 == 0) {
        // 0x8000CAB0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000CC10;
    }
    // 0x8000CAB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000CAB4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000CAB8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000CABC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000CAC0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000CAC4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000CAC8: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8000CACC: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8000CAD0: bne         $v0, $zero, L_8000CAE0
    if (ctx->r2 != 0) {
        // 0x8000CAD4: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8000CAE0;
    }
    // 0x8000CAD4: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000CAD8: beq         $v0, $zero, L_8000CB00
    if (ctx->r2 == 0) {
        // 0x8000CADC: nop
    
            goto L_8000CB00;
    }
    // 0x8000CADC: nop

L_8000CAE0:
    // 0x8000CAE0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000CAE4: addiu       $a2, $a2, 0x7B76
    ctx->r6 = ADD32(ctx->r6, 0X7B76);
    // 0x8000CAE8: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x8000CAEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CAF4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000CAF8: jal         0x8000637C
    // 0x8000CAFC: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_20;
    // 0x8000CAFC: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    after_20:
L_8000CB00:
    // 0x8000CB00: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000CB04: sb          $zero, 0x3F50($at)
    MEM_B(0X3F50, ctx->r1) = 0;
    // 0x8000CB08: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8000CB0C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CB10: addiu       $v1, $v1, 0x2087
    ctx->r3 = ADD32(ctx->r3, 0X2087);
L_8000CB14:
    // 0x8000CB14: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000CB18: srav        $v0, $v0, $s1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r17 & 31));
    // 0x8000CB1C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000CB20: beq         $v0, $zero, L_8000CB3C
    if (ctx->r2 == 0) {
        // 0x8000CB24: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000CB3C;
    }
    // 0x8000CB24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000CB28: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000CB2C: lbu         $v0, 0x3F50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3F50);
    // 0x8000CB30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CB34: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000CB38: sb          $v0, 0x3F50($at)
    MEM_B(0X3F50, ctx->r1) = ctx->r2;
L_8000CB3C:
    // 0x8000CB3C: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8000CB40: bne         $v0, $zero, L_8000CB14
    if (ctx->r2 != 0) {
        // 0x8000CB44: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000CB14;
    }
    // 0x8000CB44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000CB48: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000CB4C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000CB50: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000CB54: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000CB58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000CB5C: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8000CB60: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8000CB64: beq         $v0, $zero, L_8000CBCC
    if (ctx->r2 == 0) {
        // 0x8000CB68: andi        $v0, $v1, 0x4000
        ctx->r2 = ctx->r3 & 0X4000;
            goto L_8000CBCC;
    }
    // 0x8000CB68: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x8000CB6C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000CB70: lb          $v0, 0x3F50($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F50);
    // 0x8000CB74: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000CB78: beq         $v0, $zero, L_8000CBA0
    if (ctx->r2 == 0) {
        // 0x8000CB7C: nop
    
            goto L_8000CBA0;
    }
    // 0x8000CB7C: nop

    // 0x8000CB80: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000CB84: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000CB88: beq         $v0, $zero, L_8000CBA0
    if (ctx->r2 == 0) {
        // 0x8000CB8C: nop
    
            goto L_8000CBA0;
    }
    // 0x8000CB8C: nop

    // 0x8000CB90: jal         0x8000637C
    // 0x8000CB94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8000637C(rdram, ctx);
        goto after_21;
    // 0x8000CB94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_21:
    // 0x8000CB98: j           L_8000E33C
    // 0x8000CB9C: nop

        goto L_8000E33C;
    // 0x8000CB9C: nop

L_8000CBA0:
    // 0x8000CBA0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CBA4: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000CBA8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000CBAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000CBB0: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    // 0x8000CBB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CBB8: jal         0x80053390
    // 0x8000CBBC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80053390(rdram, ctx);
        goto after_22;
    // 0x8000CBBC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_22:
    // 0x8000CBC0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000CBC4: j           L_8000CF8C
    // 0x8000CBC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_8000CF8C;
    // 0x8000CBC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000CBCC:
    // 0x8000CBCC: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CBD0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E33C;
    }
    // 0x8000CBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CBD4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000CBD8: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000CBDC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000CBE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000CBE4: sb          $v0, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r2;
    // 0x8000CBE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000CBEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CBF0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000CBF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000CBF8: jal         0x80053390
    // 0x8000CBFC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80053390(rdram, ctx);
        goto after_23;
    // 0x8000CBFC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_23:
    // 0x8000CC00: jal         0x800064C0
    // 0x8000CC04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_24;
    // 0x8000CC04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_24:
    // 0x8000CC08: j           L_8000E33C
    // 0x8000CC0C: nop

        goto L_8000E33C;
    // 0x8000CC0C: nop

L_8000CC10:
    // 0x8000CC10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CC14: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000CC18: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000CC1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CC20: jal         0x80053390
    // 0x8000CC24: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80053390(rdram, ctx);
        goto after_25;
    // 0x8000CC24: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_25:
    // 0x8000CC28: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000CC2C: j           L_8000CF8C
    // 0x8000CC30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_8000CF8C;
    // 0x8000CC30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000CC34:
    // 0x8000CC34: jal         0x80008CDC
    // 0x8000CC38: nop

    func_80008CDC(rdram, ctx);
        goto after_26;
    // 0x8000CC38: nop

    after_26:
    // 0x8000CC3C: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CC40: nop
    
            goto L_8000E33C;
    }
    // 0x8000CC40: nop

    // 0x8000CC44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000CC48: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000CC4C: bne         $v0, $zero, L_8000CD68
    if (ctx->r2 != 0) {
        // 0x8000CC50: nop
    
            goto L_8000CD68;
    }
    // 0x8000CC50: nop

    // 0x8000CC54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000CC58: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000CC5C: beq         $v0, $zero, L_8000CC88
    if (ctx->r2 == 0) {
        // 0x8000CC60: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000CC88;
    }
    // 0x8000CC60: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000CC64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000CC68: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000CC6C: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000CC70: bne         $v0, $zero, L_8000CCAC
    if (ctx->r2 != 0) {
        // 0x8000CC74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000CCAC;
    }
    // 0x8000CC74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CC78: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000CC7C: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000CC80: j           L_8000CCA4
    // 0x8000CC84: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
        goto L_8000CCA4;
    // 0x8000CC84: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000CC88:
    // 0x8000CC88: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000CC8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000CC90: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000CC94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000CC98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000CC9C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000CCA0: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000CCA4:
    // 0x8000CCA4: beq         $v0, $zero, L_8000CCB4
    if (ctx->r2 == 0) {
        // 0x8000CCA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000CCB4;
    }
    // 0x8000CCA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000CCAC:
    // 0x8000CCAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CCB0: sb          $v0, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = ctx->r2;
L_8000CCB4:
    // 0x8000CCB4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000CCB8: lbu         $v0, -0xBE6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE6);
    // 0x8000CCBC: bne         $v0, $zero, L_8000CCE4
    if (ctx->r2 != 0) {
        // 0x8000CCC0: nop
    
            goto L_8000CCE4;
    }
    // 0x8000CCC0: nop

    // 0x8000CCC4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CCC8: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000CCCC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000CCD0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000CCD4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000CCD8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000CCDC: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CCE0: nop
    
            goto L_8000E33C;
    }
    // 0x8000CCE0: nop

L_8000CCE4:
    // 0x8000CCE4: jal         0x80031BEC
    // 0x8000CCE8: nop

    func_80031BEC(rdram, ctx);
        goto after_27;
    // 0x8000CCE8: nop

    after_27:
    // 0x8000CCEC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CCF0: lhu         $v1, 0x7B76($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X7B76);
    // 0x8000CCF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CCF8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000CCFC: sb          $t5, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r13;
    // 0x8000CD00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CD04: sb          $t5, -0xBE7($at)
    MEM_B(-0XBE7, ctx->r1) = ctx->r13;
    // 0x8000CD08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD0C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000CD10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD14: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000CD18: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CD1C: sb          $v1, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = ctx->r3;
    // 0x8000CD20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD24: sb          $v1, 0x7BA2($at)
    MEM_B(0X7BA2, ctx->r1) = ctx->r3;
    // 0x8000CD28: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000CD2C: beq         $v1, $zero, L_8000E33C
    if (ctx->r3 == 0) {
        // 0x8000CD30: nop
    
            goto L_8000E33C;
    }
    // 0x8000CD30: nop

    // 0x8000CD34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD38: sb          $t5, 0x79F0($at)
    MEM_B(0X79F0, ctx->r1) = ctx->r13;
    // 0x8000CD3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD40: sb          $t5, 0x25A0($at)
    MEM_B(0X25A0, ctx->r1) = ctx->r13;
    // 0x8000CD44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD48: sb          $zero, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = 0;
    // 0x8000CD4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD50: sb          $t5, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r13;
    // 0x8000CD54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD58: sb          $zero, 0x7A67($at)
    MEM_B(0X7A67, ctx->r1) = 0;
    // 0x8000CD5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD60: j           L_8000E33C
    // 0x8000CD64: sb          $zero, 0x2617($at)
    MEM_B(0X2617, ctx->r1) = 0;
        goto L_8000E33C;
    // 0x8000CD64: sb          $zero, 0x2617($at)
    MEM_B(0X2617, ctx->r1) = 0;
L_8000CD68:
    // 0x8000CD68: jal         0x8002CFB8
    // 0x8000CD6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_28;
    // 0x8000CD6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_28:
    // 0x8000CD70: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CD74: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8000E33C;
    }
    // 0x8000CD74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CD78: jal         0x80031BEC
    // 0x8000CD7C: sb          $t5, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r13;
    func_80031BEC(rdram, ctx);
        goto after_29;
    // 0x8000CD7C: sb          $t5, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r13;
    after_29:
    // 0x8000CD80: jal         0x80006998
    // 0x8000CD84: nop

    func_80006998(rdram, ctx);
        goto after_30;
    // 0x8000CD84: nop

    after_30:
    // 0x8000CD88: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000CD8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD90: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000CD94: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8000CD98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CD9C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000CDA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CDA4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000CDA8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CDAC: j           L_8000E33C
    // 0x8000CDB0: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
        goto L_8000E33C;
    // 0x8000CDB0: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
L_8000CDB4:
    // 0x8000CDB4: jal         0x80008CDC
    // 0x8000CDB8: nop

    func_80008CDC(rdram, ctx);
        goto after_31;
    // 0x8000CDB8: nop

    after_31:
    // 0x8000CDBC: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CDC0: nop
    
            goto L_8000E33C;
    }
    // 0x8000CDC0: nop

    // 0x8000CDC4: jal         0x8002CFB8
    // 0x8000CDC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_32;
    // 0x8000CDC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_32:
    // 0x8000CDCC: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CDD0: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8000E33C;
    }
    // 0x8000CDD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000CDD4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000CDD8: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x8000CDDC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000CDE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CDE4: sb          $a0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r4;
    // 0x8000CDE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000CDEC: jal         0x80053390
    // 0x8000CDF0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_80053390(rdram, ctx);
        goto after_33;
    // 0x8000CDF0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_33:
    // 0x8000CDF4: j           L_8000E33C
    // 0x8000CDF8: nop

        goto L_8000E33C;
    // 0x8000CDF8: nop

L_8000CDFC:
    // 0x8000CDFC: jal         0x80008CDC
    // 0x8000CE00: nop

    func_80008CDC(rdram, ctx);
        goto after_34;
    // 0x8000CE00: nop

    after_34:
    // 0x8000CE04: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CE08: nop
    
            goto L_8000E33C;
    }
    // 0x8000CE08: nop

    // 0x8000CE0C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000CE10: lw          $v0, 0x3F40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F40);
    // 0x8000CE14: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CE18: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000E33C;
    }
    // 0x8000CE18: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000CE1C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000CE20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000CE24: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000CE28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000CE2C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000CE30: lhu         $v1, -0x33C8($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000CE34: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8000CE38: beq         $v0, $zero, L_8000CE68
    if (ctx->r2 == 0) {
        // 0x8000CE3C: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8000CE68;
    }
    // 0x8000CE3C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000CE40: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000CE44: addiu       $a0, $a0, 0x7B76
    ctx->r4 = ADD32(ctx->r4, 0X7B76);
    // 0x8000CE48: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8000CE4C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000CE50: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000CE54: bne         $v0, $zero, L_8000CE60
    if (ctx->r2 != 0) {
        // 0x8000CE58: addiu       $v0, $v1, 0x2
        ctx->r2 = ADD32(ctx->r3, 0X2);
            goto L_8000CE60;
    }
    // 0x8000CE58: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x8000CE5C: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
L_8000CE60:
    // 0x8000CE60: j           L_8000CF08
    // 0x8000CE64: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_8000CF08;
    // 0x8000CE64: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8000CE68:
    // 0x8000CE68: beq         $v0, $zero, L_8000CE94
    if (ctx->r2 == 0) {
        // 0x8000CE6C: andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
            goto L_8000CE94;
    }
    // 0x8000CE6C: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8000CE70: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000CE74: addiu       $a0, $a0, 0x7B76
    ctx->r4 = ADD32(ctx->r4, 0X7B76);
    // 0x8000CE78: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8000CE7C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000CE80: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000CE84: bne         $v0, $zero, L_8000CE60
    if (ctx->r2 != 0) {
        // 0x8000CE88: addiu       $v0, $v1, 0x2
        ctx->r2 = ADD32(ctx->r3, 0X2);
            goto L_8000CE60;
    }
    // 0x8000CE88: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x8000CE8C: j           L_8000CE60
    // 0x8000CE90: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
        goto L_8000CE60;
    // 0x8000CE90: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
L_8000CE94:
    // 0x8000CE94: beq         $v0, $zero, L_8000CED0
    if (ctx->r2 == 0) {
        // 0x8000CE98: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8000CED0;
    }
    // 0x8000CE98: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8000CE9C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000CEA0: addiu       $a1, $a1, 0x7B76
    ctx->r5 = ADD32(ctx->r5, 0X7B76);
    // 0x8000CEA4: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8000CEA8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8000CEAC: xori        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 ^ 0X1;
    // 0x8000CEB0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000CEB4: xori        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 ^ 0X3;
    // 0x8000CEB8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8000CEBC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8000CEC0: bne         $v0, $zero, L_8000CF04
    if (ctx->r2 != 0) {
        // 0x8000CEC4: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_8000CF04;
    }
    // 0x8000CEC4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8000CEC8: j           L_8000CF04
    // 0x8000CECC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8000CF04;
    // 0x8000CECC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8000CED0:
    // 0x8000CED0: beq         $v0, $zero, L_8000CF18
    if (ctx->r2 == 0) {
        // 0x8000CED4: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8000CF18;
    }
    // 0x8000CED4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8000CED8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000CEDC: addiu       $a1, $a1, 0x7B76
    ctx->r5 = ADD32(ctx->r5, 0X7B76);
    // 0x8000CEE0: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x8000CEE4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000CEE8: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000CEEC: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x8000CEF0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000CEF4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000CEF8: bne         $v1, $zero, L_8000CF04
    if (ctx->r3 != 0) {
        // 0x8000CEFC: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000CF04;
    }
    // 0x8000CEFC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000CF00: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8000CF04:
    // 0x8000CF04: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8000CF08:
    // 0x8000CF08: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000CF0C: jal         0x8000637C
    // 0x8000CF10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000637C(rdram, ctx);
        goto after_35;
    // 0x8000CF10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_35:
    // 0x8000CF14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8000CF18:
    // 0x8000CF18: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000CF1C: addiu       $a2, $a2, 0x7B76
    ctx->r6 = ADD32(ctx->r6, 0X7B76);
    // 0x8000CF20: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8000CF24: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8000CF28: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000CF2C: addiu       $v1, $v1, 0x3F59
    ctx->r3 = ADD32(ctx->r3, 0X3F59);
L_8000CF30:
    // 0x8000CF30: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8000CF34: beql        $s1, $v0, L_8000CF40
    if (ctx->r17 == ctx->r2) {
        // 0x8000CF38: sb          $a0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r4;
            goto L_8000CF40;
    }
    goto skip_0;
    // 0x8000CF38: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    skip_0:
    // 0x8000CF3C: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
L_8000CF40:
    // 0x8000CF40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000CF44: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8000CF48: bne         $v0, $zero, L_8000CF30
    if (ctx->r2 != 0) {
        // 0x8000CF4C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000CF30;
    }
    // 0x8000CF4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000CF50: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000CF54: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000CF58: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000CF5C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000CF60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000CF64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000CF68: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000CF6C: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8000CF70: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CF74: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8000E33C;
    }
    // 0x8000CF74: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000CF78: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000CF7C: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000CF80: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000CF84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CF88: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000CF8C:
    // 0x8000CF8C: jal         0x8000637C
    // 0x8000CF90: nop

    func_8000637C(rdram, ctx);
        goto after_36;
    // 0x8000CF90: nop

    after_36:
    // 0x8000CF94: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000CF98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CF9C: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000CFA0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000CFA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000CFA8: j           L_8000E33C
    // 0x8000CFAC: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
        goto L_8000E33C;
    // 0x8000CFAC: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_8000CFB0:
    // 0x8000CFB0: jal         0x80008CDC
    // 0x8000CFB4: nop

    func_80008CDC(rdram, ctx);
        goto after_37;
    // 0x8000CFB4: nop

    after_37:
    // 0x8000CFB8: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000CFBC: nop
    
            goto L_8000E33C;
    }
    // 0x8000CFBC: nop

    // 0x8000CFC0: jal         0x8002CFB8
    // 0x8000CFC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_38;
    // 0x8000CFC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_38:
    // 0x8000CFC8: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000CFCC: nop
    
            goto L_8000E33C;
    }
    // 0x8000CFCC: nop

    // 0x8000CFD0: jal         0x80053390
    // 0x8000CFD4: nop

    func_80053390(rdram, ctx);
        goto after_39;
    // 0x8000CFD4: nop

    after_39:
    // 0x8000CFD8: jal         0x80031BEC
    // 0x8000CFDC: nop

    func_80031BEC(rdram, ctx);
        goto after_40;
    // 0x8000CFDC: nop

    after_40:
    // 0x8000CFE0: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8000CFE4: addiu       $s2, $s2, 0x7B76
    ctx->r18 = ADD32(ctx->r18, 0X7B76);
    // 0x8000CFE8: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x8000CFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CFF0: beq         $v1, $v0, L_8000D060
    if (ctx->r3 == ctx->r2) {
        // 0x8000CFF4: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8000D060;
    }
    // 0x8000CFF4: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000CFF8: beql        $v0, $zero, L_8000D010
    if (ctx->r2 == 0) {
        // 0x8000CFFC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000D010;
    }
    goto skip_1;
    // 0x8000CFFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8000D000: beq         $v1, $zero, L_8000D028
    if (ctx->r3 == 0) {
        // 0x8000D004: nop
    
            goto L_8000D028;
    }
    // 0x8000D004: nop

    // 0x8000D008: j           L_8000E33C
    // 0x8000D00C: nop

        goto L_8000E33C;
    // 0x8000D00C: nop

L_8000D010:
    // 0x8000D010: beq         $v1, $v0, L_8000D0BC
    if (ctx->r3 == ctx->r2) {
        // 0x8000D014: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000D0BC;
    }
    // 0x8000D014: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D018: beq         $v1, $v0, L_8000D0F4
    if (ctx->r3 == ctx->r2) {
        // 0x8000D01C: nop
    
            goto L_8000D0F4;
    }
    // 0x8000D01C: nop

    // 0x8000D020: j           L_8000E33C
    // 0x8000D024: nop

        goto L_8000E33C;
    // 0x8000D024: nop

L_8000D028:
    // 0x8000D028: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D02C: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x8000D030: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D034: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x8000D038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D03C: jal         0x80031BEC
    // 0x8000D040: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_41;
    // 0x8000D040: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    after_41:
    // 0x8000D044: jal         0x80041668
    // 0x8000D048: nop

    func_80041668(rdram, ctx);
        goto after_42;
    // 0x8000D048: nop

    after_42:
    // 0x8000D04C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D050: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D054: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000D058: j           L_8000E33C
    // 0x8000D05C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
        goto L_8000E33C;
    // 0x8000D05C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_8000D060:
    // 0x8000D060: jal         0x80031BEC
    // 0x8000D064: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    func_80031BEC(rdram, ctx);
        goto after_43;
    // 0x8000D064: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    after_43:
    // 0x8000D068: jal         0x80041E74
    // 0x8000D06C: nop

    func_80041E74(rdram, ctx);
        goto after_44;
    // 0x8000D06C: nop

    after_44:
    // 0x8000D070: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8000D074: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000D078: addiu       $v1, $v1, 0x3F5C
    ctx->r3 = ADD32(ctx->r3, 0X3F5C);
    // 0x8000D07C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8000D080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D084: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    // 0x8000D088: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D08C: sb          $zero, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = 0;
    // 0x8000D090: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D094: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000D098: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D09C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000D0A0: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_8000D0A4:
    // 0x8000D0A4: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8000D0A8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000D0AC: bgez        $s1, L_8000D0A4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8000D0B0: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8000D0A4;
    }
    // 0x8000D0B0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000D0B4: j           L_8000E33C
    // 0x8000D0B8: nop

        goto L_8000E33C;
    // 0x8000D0B8: nop

L_8000D0BC:
    // 0x8000D0BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000D0C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D0C4: sb          $s0, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = ctx->r16;
    // 0x8000D0C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D0CC: sb          $s0, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = ctx->r16;
    // 0x8000D0D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D0D4: jal         0x80031BEC
    // 0x8000D0D8: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_45;
    // 0x8000D0D8: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    after_45:
    // 0x8000D0DC: jal         0x80041668
    // 0x8000D0E0: nop

    func_80041668(rdram, ctx);
        goto after_46;
    // 0x8000D0E0: nop

    after_46:
    // 0x8000D0E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D0E8: sb          $s0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r16;
    // 0x8000D0EC: j           L_8000E33C
    // 0x8000D0F0: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
        goto L_8000E33C;
    // 0x8000D0F0: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_8000D0F4:
    // 0x8000D0F4: jal         0x80006944
    // 0x8000D0F8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_80006944(rdram, ctx);
        goto after_47;
    // 0x8000D0F8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_47:
    // 0x8000D0FC: jal         0x80006708
    // 0x8000D100: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    func_80006708(rdram, ctx);
        goto after_48;
    // 0x8000D100: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    after_48:
    // 0x8000D104: jal         0x80031BEC
    // 0x8000D108: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    func_80031BEC(rdram, ctx);
        goto after_49;
    // 0x8000D108: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    after_49:
    // 0x8000D10C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000D110: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D114: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000D118: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D11C: sb          $zero, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = 0;
    // 0x8000D120: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D124: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000D128: jal         0x80053390
    // 0x8000D12C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    func_80053390(rdram, ctx);
        goto after_50;
    // 0x8000D12C: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    after_50:
    // 0x8000D130: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8000D134: addiu       $s6, $s6, 0x81C
    ctx->r22 = ADD32(ctx->r22, 0X81C);
    // 0x8000D138: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8000D13C: addiu       $s5, $s5, 0x5030
    ctx->r21 = ADD32(ctx->r21, 0X5030);
    // 0x8000D140: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x8000D144: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000D148: addiu       $s2, $s2, -0xB48
    ctx->r18 = ADD32(ctx->r18, -0XB48);
    // 0x8000D14C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D150: addiu       $v0, $v0, -0xB2C
    ctx->r2 = ADD32(ctx->r2, -0XB2C);
    // 0x8000D154: addiu       $s4, $v0, 0x4
    ctx->r20 = ADD32(ctx->r2, 0X4);
    // 0x8000D158: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_8000D15C:
    // 0x8000D15C: jal         0x8005357C
    // 0x8000D160: nop

    func_8005357C(rdram, ctx);
        goto after_51;
    // 0x8000D160: nop

    after_51:
    // 0x8000D164: beq         $v0, $zero, L_8000D250
    if (ctx->r2 == 0) {
        // 0x8000D168: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8000D250;
    }
    // 0x8000D168: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D16C: beq         $s1, $fp, L_8000D190
    if (ctx->r17 == ctx->r30) {
        // 0x8000D170: sb          $s7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r23;
            goto L_8000D190;
    }
    // 0x8000D170: sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    // 0x8000D174: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D178: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000D17C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D180: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D184: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000D188: j           L_8000D1BC
    // 0x8000D18C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
        goto L_8000D1BC;
    // 0x8000D18C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8000D190:
    // 0x8000D190: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000D194: lbu         $v0, 0x2076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2076);
    // 0x8000D198: lw          $v1, 0x14($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X14);
    // 0x8000D19C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D1A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D1A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D1A8: lw          $v0, -0xABC($at)
    ctx->r2 = MEM_W(ctx->r1, -0XABC);
    // 0x8000D1AC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D1B0: lw          $v1, 0x14($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X14);
    // 0x8000D1B4: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x8000D1B8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8000D1BC:
    // 0x8000D1BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1C0: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
    // 0x8000D1C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1C8: sw          $s7, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r23;
    // 0x8000D1CC: addiu       $v0, $s1, -0x5
    ctx->r2 = ADD32(ctx->r17, -0X5);
    // 0x8000D1D0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000D1D4: bne         $v0, $zero, L_8000D1F8
    if (ctx->r2 != 0) {
        // 0x8000D1D8: nop
    
            goto L_8000D1F8;
    }
    // 0x8000D1D8: nop

    // 0x8000D1DC: lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X0);
    // 0x8000D1E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D1E8: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8000D1EC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D1F0: j           L_8000D240
    // 0x8000D1F4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
        goto L_8000D240;
    // 0x8000D1F4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8000D1F8:
    // 0x8000D1F8: bne         $s1, $fp, L_8000D21C
    if (ctx->r17 != ctx->r30) {
        // 0x8000D1FC: nop
    
            goto L_8000D21C;
    }
    // 0x8000D1FC: nop

    // 0x8000D200: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D204: lh          $v0, -0xB3E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XB3E);
    // 0x8000D208: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000D20C: lbu         $v1, 0x2076($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2076);
    // 0x8000D210: lw          $a0, 0x14($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X14);
    // 0x8000D214: j           L_8000D230
    // 0x8000D218: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_8000D230;
    // 0x8000D218: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8000D21C:
    // 0x8000D21C: lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X0);
    // 0x8000D220: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000D224: lbu         $v1, 0x2085($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2085);
    // 0x8000D228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000D22C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8000D230:
    // 0x8000D230: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D234: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8000D238: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D23C: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
L_8000D240:
    // 0x8000D240: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D244: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8000D248: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8000D24C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8000D250:
    // 0x8000D250: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D254: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8000D258: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8000D25C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D260: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8000D264: bne         $v0, $zero, L_8000D15C
    if (ctx->r2 != 0) {
        // 0x8000D268: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_8000D15C;
    }
    // 0x8000D268: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8000D26C: j           L_8000E33C
    // 0x8000D270: nop

        goto L_8000E33C;
    // 0x8000D270: nop

L_8000D274:
    // 0x8000D274: jal         0x80008CDC
    // 0x8000D278: nop

    func_80008CDC(rdram, ctx);
        goto after_52;
    // 0x8000D278: nop

    after_52:
    // 0x8000D27C: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000D280: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_8000E33C;
    }
    // 0x8000D280: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000D284: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8000D288: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000D28C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000D290: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000D294: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000D298: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8000D29C: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8000D2A0: beq         $v0, $zero, L_8000D2D8
    if (ctx->r2 == 0) {
        // 0x8000D2A4: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8000D2D8;
    }
    // 0x8000D2A4: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8000D2A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D2AC: lb          $v0, -0xBE5($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE5);
    // 0x8000D2B0: blez        $v0, L_8000D2C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D2B4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000D2C0;
    }
    // 0x8000D2B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D2B8: j           L_8000D2C4
    // 0x8000D2BC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8000D2C4;
    // 0x8000D2BC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_8000D2C0:
    // 0x8000D2C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000D2C4:
    // 0x8000D2C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D2C8: sb          $v0, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = ctx->r2;
    // 0x8000D2CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000D2D0: j           L_8000D4E4
    // 0x8000D2D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_8000D4E4;
    // 0x8000D2D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000D2D8:
    // 0x8000D2D8: beq         $v0, $zero, L_8000D31C
    if (ctx->r2 == 0) {
        // 0x8000D2DC: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8000D31C;
    }
    // 0x8000D2DC: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000D2E0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D2E4: lb          $v0, -0xBE5($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE5);
    // 0x8000D2E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D2EC: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D2F0: beq         $v0, $zero, L_8000D308
    if (ctx->r2 == 0) {
        // 0x8000D2F4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000D308;
    }
    // 0x8000D2F4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000D2F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D2FC: sb          $v0, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = ctx->r2;
    // 0x8000D300: j           L_8000D314
    // 0x8000D304: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D314;
    // 0x8000D304: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D308:
    // 0x8000D308: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D30C: sb          $zero, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = 0;
    // 0x8000D310: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D314:
    // 0x8000D314: j           L_8000D4E4
    // 0x8000D318: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_8000D4E4;
    // 0x8000D318: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000D31C:
    // 0x8000D31C: beql        $v0, $zero, L_8000D3C4
    if (ctx->r2 == 0) {
        // 0x8000D320: andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
            goto L_8000D3C4;
    }
    goto skip_2;
    // 0x8000D320: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    skip_2:
    // 0x8000D324: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D328: lb          $v1, -0xBE5($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE5);
    // 0x8000D32C: bne         $v1, $zero, L_8000D468
    if (ctx->r3 != 0) {
        // 0x8000D330: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000D468;
    }
    // 0x8000D330: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000D334: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000D338: addiu       $a1, $a1, 0x2076
    ctx->r5 = ADD32(ctx->r5, 0X2076);
    // 0x8000D33C: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D340: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8000D344: beq         $v0, $zero, L_8000D4EC
    if (ctx->r2 == 0) {
        // 0x8000D348: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000D4EC;
    }
    // 0x8000D348: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000D34C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000D350: lw          $v1, 0x5044($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5044);
    // 0x8000D354: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8000D358: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D35C: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
    // 0x8000D360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D364: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8000D368: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D36C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000D370: lw          $v1, 0x5044($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5044);
    // 0x8000D374: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D378: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D37C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D380: lw          $v0, -0xABC($at)
    ctx->r2 = MEM_W(ctx->r1, -0XABC);
    // 0x8000D384: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D388: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D38C: lh          $v0, -0xB3E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XB3E);
    // 0x8000D390: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D394: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000D398: lw          $a0, 0x5044($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5044);
    // 0x8000D39C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D3A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D3A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000D3A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D3AC: lw          $v0, 0x81C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X81C);
    // 0x8000D3B0: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8000D3B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000D3B8: lw          $v0, 0x5044($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5044);
    // 0x8000D3BC: j           L_8000D4D4
    // 0x8000D3C0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
        goto L_8000D4D4;
    // 0x8000D3C0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8000D3C4:
    // 0x8000D3C4: beq         $v0, $zero, L_8000D4F0
    if (ctx->r2 == 0) {
        // 0x8000D3C8: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000D4F0;
    }
    // 0x8000D3C8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000D3CC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D3D0: lb          $v1, -0xBE5($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE5);
    // 0x8000D3D4: bne         $v1, $zero, L_8000D468
    if (ctx->r3 != 0) {
        // 0x8000D3D8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000D468;
    }
    // 0x8000D3D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000D3DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000D3E0: addiu       $a0, $a0, 0x2076
    ctx->r4 = ADD32(ctx->r4, 0X2076);
    // 0x8000D3E4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D3E8: beq         $v0, $zero, L_8000D4F0
    if (ctx->r2 == 0) {
        // 0x8000D3EC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000D4F0;
    }
    // 0x8000D3EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000D3F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000D3F4: lw          $v1, 0x5044($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5044);
    // 0x8000D3F8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8000D3FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D400: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
    // 0x8000D404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D408: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8000D40C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D410: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000D414: lw          $v1, 0x5044($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5044);
    // 0x8000D418: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D41C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D420: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D424: lw          $v0, -0xABC($at)
    ctx->r2 = MEM_W(ctx->r1, -0XABC);
    // 0x8000D428: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D42C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D430: lh          $v0, -0xB3E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XB3E);
    // 0x8000D434: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D438: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000D43C: lw          $a0, 0x5044($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5044);
    // 0x8000D440: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D444: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D448: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000D44C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D450: lw          $v0, 0x81C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X81C);
    // 0x8000D454: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8000D458: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000D45C: lw          $v0, 0x5044($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5044);
    // 0x8000D460: j           L_8000D4D4
    // 0x8000D464: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
        goto L_8000D4D4;
    // 0x8000D464: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8000D468:
    // 0x8000D468: bne         $v1, $v0, L_8000D4F0
    if (ctx->r3 != ctx->r2) {
        // 0x8000D46C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000D4F0;
    }
    // 0x8000D46C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000D470: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000D474: addiu       $v1, $v1, 0x2085
    ctx->r3 = ADD32(ctx->r3, 0X2085);
    // 0x8000D478: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000D47C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8000D480: lw          $a1, 0x5048($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5048);
    // 0x8000D484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000D488: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8000D48C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8000D490: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D494: sb          $v0, 0xB7E($at)
    MEM_B(0XB7E, ctx->r1) = ctx->r2;
    // 0x8000D498: sw          $a0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->r4;
    // 0x8000D49C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D4A0: lh          $v0, -0xB3C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XB3C);
    // 0x8000D4A4: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x8000D4A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000D4AC: lw          $a0, 0x5048($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5048);
    // 0x8000D4B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D4B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D4B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000D4BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D4C0: lw          $v0, 0x81C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X81C);
    // 0x8000D4C4: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8000D4C8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000D4CC: lw          $v0, 0x5048($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5048);
    // 0x8000D4D0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8000D4D4:
    // 0x8000D4D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000D4D8: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8000D4DC: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8000D4E0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8000D4E4:
    // 0x8000D4E4: jal         0x8000637C
    // 0x8000D4E8: nop

    func_8000637C(rdram, ctx);
        goto after_53;
    // 0x8000D4E8: nop

    after_53:
L_8000D4EC:
    // 0x8000D4EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000D4F0:
    // 0x8000D4F0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000D4F4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000D4F8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000D4FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000D500: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000D504: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000D508: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8000D50C: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000D510: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E33C;
    }
    // 0x8000D510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D514: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000D518: lb          $a0, -0xBE5($a0)
    ctx->r4 = MEM_B(ctx->r4, -0XBE5);
    // 0x8000D51C: bne         $a0, $v0, L_8000D550
    if (ctx->r4 != ctx->r2) {
        // 0x8000D520: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000D550;
    }
    // 0x8000D520: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D524: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8000D528: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D52C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000D530: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D534: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000D538: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D53C: sb          $zero, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = 0;
    // 0x8000D540: jal         0x8000637C
    // 0x8000D544: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8000637C(rdram, ctx);
        goto after_54;
    // 0x8000D544: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_54:
    // 0x8000D548: j           L_8000E33C
    // 0x8000D54C: nop

        goto L_8000E33C;
    // 0x8000D54C: nop

L_8000D550:
    // 0x8000D550: bne         $a0, $v0, L_8000E33C
    if (ctx->r4 != ctx->r2) {
        // 0x8000D554: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8000E33C;
    }
    // 0x8000D554: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8000D558: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D55C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000D560: jal         0x8000637C
    // 0x8000D564: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8000637C(rdram, ctx);
        goto after_55;
    // 0x8000D564: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_55:
    // 0x8000D568: j           L_8000E33C
    // 0x8000D56C: nop

        goto L_8000E33C;
    // 0x8000D56C: nop

L_8000D570:
    // 0x8000D570: jal         0x80008CDC
    // 0x8000D574: nop

    func_80008CDC(rdram, ctx);
        goto after_56;
    // 0x8000D574: nop

    after_56:
    // 0x8000D578: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000D57C: nop
    
            goto L_8000E33C;
    }
    // 0x8000D57C: nop

    // 0x8000D580: jal         0x8002CFB8
    // 0x8000D584: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_57;
    // 0x8000D584: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_57:
    // 0x8000D588: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000D58C: nop
    
            goto L_8000E33C;
    }
    // 0x8000D58C: nop

    // 0x8000D590: jal         0x80031BEC
    // 0x8000D594: nop

    func_80031BEC(rdram, ctx);
        goto after_58;
    // 0x8000D594: nop

    after_58:
    // 0x8000D598: jal         0x80053390
    // 0x8000D59C: nop

    func_80053390(rdram, ctx);
        goto after_59;
    // 0x8000D59C: nop

    after_59:
    // 0x8000D5A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D5A4: lb          $v1, -0xBE5($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE5);
    // 0x8000D5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D5AC: bne         $v1, $v0, L_8000D77C
    if (ctx->r3 != ctx->r2) {
        // 0x8000D5B0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000D77C;
    }
    // 0x8000D5B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D5B4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8000D5B8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000D5BC: addiu       $a1, $a1, -0x3260
    ctx->r5 = ADD32(ctx->r5, -0X3260);
    // 0x8000D5C0: lhu         $a3, 0x0($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X0);
    // 0x8000D5C4: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8000D5C8: addiu       $a2, $a2, 0x3F44
    ctx->r6 = ADD32(ctx->r6, 0X3F44);
    // 0x8000D5CC: addiu       $t4, $a2, 0x2
    ctx->r12 = ADD32(ctx->r6, 0X2);
    // 0x8000D5D0: addiu       $t3, $a2, 0x4
    ctx->r11 = ADD32(ctx->r6, 0X4);
    // 0x8000D5D4: addiu       $t2, $a2, 0x6
    ctx->r10 = ADD32(ctx->r6, 0X6);
    // 0x8000D5D8: addiu       $t1, $a2, 0x8
    ctx->r9 = ADD32(ctx->r6, 0X8);
    // 0x8000D5DC: addiu       $t0, $a2, 0xA
    ctx->r8 = ADD32(ctx->r6, 0XA);
    // 0x8000D5E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000D5E4: addiu       $a0, $a0, -0xBE0
    ctx->r4 = ADD32(ctx->r4, -0XBE0);
    // 0x8000D5E8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000D5EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D5F0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000D5F4:
    // 0x8000D5F4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D5F8: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8000D5FC: bnel        $v0, $zero, L_8000D604
    if (ctx->r2 != 0) {
        // 0x8000D600: sh          $s1, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r17;
            goto L_8000D604;
    }
    goto skip_3;
    // 0x8000D600: sh          $s1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r17;
    skip_3:
L_8000D604:
    // 0x8000D604: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x8000D608: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D60C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D610: bnel        $v0, $zero, L_8000D618
    if (ctx->r2 != 0) {
        // 0x8000D614: sh          $s1, 0x0($t4)
        MEM_H(0X0, ctx->r12) = ctx->r17;
            goto L_8000D618;
    }
    goto skip_4;
    // 0x8000D614: sh          $s1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r17;
    skip_4:
L_8000D618:
    // 0x8000D618: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x8000D61C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D620: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D624: bnel        $v0, $zero, L_8000D62C
    if (ctx->r2 != 0) {
        // 0x8000D628: sh          $s1, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r17;
            goto L_8000D62C;
    }
    goto skip_5;
    // 0x8000D628: sh          $s1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r17;
    skip_5:
L_8000D62C:
    // 0x8000D62C: lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X6);
    // 0x8000D630: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D634: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D638: bnel        $v0, $zero, L_8000D640
    if (ctx->r2 != 0) {
        // 0x8000D63C: sh          $s1, 0x0($t2)
        MEM_H(0X0, ctx->r10) = ctx->r17;
            goto L_8000D640;
    }
    goto skip_6;
    // 0x8000D63C: sh          $s1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r17;
    skip_6:
L_8000D640:
    // 0x8000D640: lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XA);
    // 0x8000D644: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D648: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D64C: bnel        $v0, $zero, L_8000D654
    if (ctx->r2 != 0) {
        // 0x8000D650: sh          $s1, 0x0($t1)
        MEM_H(0X0, ctx->r9) = ctx->r17;
            goto L_8000D654;
    }
    goto skip_7;
    // 0x8000D650: sh          $s1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r17;
    skip_7:
L_8000D654:
    // 0x8000D654: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x8000D658: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000D65C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000D660: bnel        $v0, $zero, L_8000D668
    if (ctx->r2 != 0) {
        // 0x8000D664: sh          $s1, 0x0($t0)
        MEM_H(0X0, ctx->r8) = ctx->r17;
            goto L_8000D668;
    }
    goto skip_8;
    // 0x8000D664: sh          $s1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r17;
    skip_8:
L_8000D668:
    // 0x8000D668: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D66C: slti        $v0, $s1, 0x5
    ctx->r2 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x8000D670: bne         $v0, $zero, L_8000D5F4
    if (ctx->r2 != 0) {
        // 0x8000D674: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8000D5F4;
    }
    // 0x8000D674: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000D678: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D67C: sb          $zero, 0x3F50($at)
    MEM_B(0X3F50, ctx->r1) = 0;
    // 0x8000D680: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8000D684: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000D688: addiu       $v1, $v1, 0x2087
    ctx->r3 = ADD32(ctx->r3, 0X2087);
L_8000D68C:
    // 0x8000D68C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000D690: srav        $v0, $v0, $s1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r17 & 31));
    // 0x8000D694: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000D698: beq         $v0, $zero, L_8000D6B4
    if (ctx->r2 == 0) {
        // 0x8000D69C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000D6B4;
    }
    // 0x8000D69C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D6A0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000D6A4: lbu         $v0, 0x3F50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3F50);
    // 0x8000D6A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D6AC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D6B0: sb          $v0, 0x3F50($at)
    MEM_B(0X3F50, ctx->r1) = ctx->r2;
L_8000D6B4:
    // 0x8000D6B4: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8000D6B8: bne         $v0, $zero, L_8000D68C
    if (ctx->r2 != 0) {
        // 0x8000D6BC: nop
    
            goto L_8000D68C;
    }
    // 0x8000D6BC: nop

    // 0x8000D6C0: jal         0x80053390
    // 0x8000D6C4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_80053390(rdram, ctx);
        goto after_60;
    // 0x8000D6C4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_60:
    // 0x8000D6C8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8000D6CC: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8000D6D0: addiu       $s6, $s6, 0x81C
    ctx->r22 = ADD32(ctx->r22, 0X81C);
    // 0x8000D6D4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8000D6D8: addiu       $s0, $s0, 0x5030
    ctx->r16 = ADD32(ctx->r16, 0X5030);
    // 0x8000D6DC: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8000D6E0: addiu       $s4, $s4, -0xB38
    ctx->r20 = ADD32(ctx->r20, -0XB38);
    // 0x8000D6E4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D6E8: addiu       $v0, $v0, -0xAEC
    ctx->r2 = ADD32(ctx->r2, -0XAEC);
    // 0x8000D6EC: addiu       $s3, $v0, 0x4
    ctx->r19 = ADD32(ctx->r2, 0X4);
    // 0x8000D6F0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_8000D6F4:
    // 0x8000D6F4: jal         0x8005357C
    // 0x8000D6F8: nop

    func_8005357C(rdram, ctx);
        goto after_61;
    // 0x8000D6F8: nop

    after_61:
    // 0x8000D6FC: beq         $v0, $zero, L_8000D758
    if (ctx->r2 == 0) {
        // 0x8000D700: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8000D758;
    }
    // 0x8000D700: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D704: sb          $s5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r21;
    // 0x8000D708: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D70C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8000D710: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000D714: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D718: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000D71C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8000D720: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D724: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
    // 0x8000D728: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D72C: sw          $s5, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r21;
    // 0x8000D730: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8000D734: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D738: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000D73C: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8000D740: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D744: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8000D748: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D74C: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8000D750: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8000D754: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8000D758:
    // 0x8000D758: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D75C: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8000D760: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8000D764: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D768: slti        $v0, $s1, 0x6
    ctx->r2 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x8000D76C: bne         $v0, $zero, L_8000D6F4
    if (ctx->r2 != 0) {
        // 0x8000D770: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8000D6F4;
    }
    // 0x8000D770: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8000D774: j           L_8000E33C
    // 0x8000D778: nop

        goto L_8000E33C;
    // 0x8000D778: nop

L_8000D77C:
    // 0x8000D77C: bne         $v1, $v0, L_8000E33C
    if (ctx->r3 != ctx->r2) {
        // 0x8000D780: nop
    
            goto L_8000E33C;
    }
    // 0x8000D780: nop

    // 0x8000D784: jal         0x80053390
    // 0x8000D788: nop

    func_80053390(rdram, ctx);
        goto after_62;
    // 0x8000D788: nop

    after_62:
    // 0x8000D78C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000D790: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D794: jal         0x80031BEC
    // 0x8000D798: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_80031BEC(rdram, ctx);
        goto after_63;
    // 0x8000D798: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_63:
    // 0x8000D79C: jal         0x80041910
    // 0x8000D7A0: nop

    func_80041910(rdram, ctx);
        goto after_64;
    // 0x8000D7A0: nop

    after_64:
    // 0x8000D7A4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8000D7A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D7AC: sb          $v0, 0x3F5C($at)
    MEM_B(0X3F5C, ctx->r1) = ctx->r2;
    // 0x8000D7B0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D7B4: sb          $v0, 0x3F5B($at)
    MEM_B(0X3F5B, ctx->r1) = ctx->r2;
    // 0x8000D7B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D7BC: sb          $v0, 0x3F5A($at)
    MEM_B(0X3F5A, ctx->r1) = ctx->r2;
    // 0x8000D7C0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000D7C4: sb          $v0, 0x3F59($at)
    MEM_B(0X3F59, ctx->r1) = ctx->r2;
    // 0x8000D7C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D7CC: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
    // 0x8000D7D0: jal         0x800067C8
    // 0x8000D7D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800067C8(rdram, ctx);
        goto after_65;
    // 0x8000D7D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_65:
    // 0x8000D7D8: j           L_8000E33C
    // 0x8000D7DC: nop

        goto L_8000E33C;
    // 0x8000D7DC: nop

L_8000D7E0:
    // 0x8000D7E0: jal         0x80008CDC
    // 0x8000D7E4: nop

    func_80008CDC(rdram, ctx);
        goto after_66;
    // 0x8000D7E4: nop

    after_66:
    // 0x8000D7E8: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000D7EC: nop
    
            goto L_8000E33C;
    }
    // 0x8000D7EC: nop

    // 0x8000D7F0: jal         0x8002CFB8
    // 0x8000D7F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_67;
    // 0x8000D7F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_67:
    // 0x8000D7F8: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000D7FC: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_8000E33C;
    }
    // 0x8000D7FC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000D800: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000D804: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000D808: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D80C: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8000D810: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D814: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000D818: j           L_8000E33C
    // 0x8000D81C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_8000E33C;
    // 0x8000D81C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000D820:
    // 0x8000D820: jal         0x80008CDC
    // 0x8000D824: nop

    func_80008CDC(rdram, ctx);
        goto after_68;
    // 0x8000D824: nop

    after_68:
    // 0x8000D828: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000D82C: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_8000E33C;
    }
    // 0x8000D82C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8000D830: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000D834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D838: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000D83C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000D840: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000D844: lhu         $a0, -0x33C8($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X33C8);
    // 0x8000D848: andi        $v0, $a0, 0x800
    ctx->r2 = ctx->r4 & 0X800;
    // 0x8000D84C: beql        $v0, $zero, L_8000D8B4
    if (ctx->r2 == 0) {
        // 0x8000D850: andi        $v0, $a0, 0x400
        ctx->r2 = ctx->r4 & 0X400;
            goto L_8000D8B4;
    }
    goto skip_9;
    // 0x8000D850: andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    skip_9:
    // 0x8000D854: bne         $v1, $zero, L_8000D894
    if (ctx->r3 != 0) {
        // 0x8000D858: nop
    
            goto L_8000D894;
    }
    // 0x8000D858: nop

    // 0x8000D85C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D860: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000D864: blez        $v0, L_8000D880
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D868: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000D880;
    }
    // 0x8000D868: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D86C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000D870: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D874: sb          $v0, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = ctx->r2;
    // 0x8000D878: j           L_8000D930
    // 0x8000D87C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D930;
    // 0x8000D87C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D880:
    // 0x8000D880: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D884: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D888: sb          $v0, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = ctx->r2;
    // 0x8000D88C: j           L_8000D930
    // 0x8000D890: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D930;
    // 0x8000D890: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D894:
    // 0x8000D894: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D898: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000D89C: blez        $v0, L_8000D8AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D8A0: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000D8AC;
    }
    // 0x8000D8A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D8A4: j           L_8000D914
    // 0x8000D8A8: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8000D914;
    // 0x8000D8A8: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_8000D8AC:
    // 0x8000D8AC: j           L_8000D914
    // 0x8000D8B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8000D914;
    // 0x8000D8B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000D8B4:
    // 0x8000D8B4: beq         $v0, $zero, L_8000D938
    if (ctx->r2 == 0) {
        // 0x8000D8B8: nop
    
            goto L_8000D938;
    }
    // 0x8000D8B8: nop

    // 0x8000D8BC: bne         $v1, $zero, L_8000D8FC
    if (ctx->r3 != 0) {
        // 0x8000D8C0: nop
    
            goto L_8000D8FC;
    }
    // 0x8000D8C0: nop

    // 0x8000D8C4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D8C8: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000D8CC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D8D0: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D8D4: beq         $v0, $zero, L_8000D8EC
    if (ctx->r2 == 0) {
        // 0x8000D8D8: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000D8EC;
    }
    // 0x8000D8D8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000D8DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D8E0: sb          $v0, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = ctx->r2;
    // 0x8000D8E4: j           L_8000D930
    // 0x8000D8E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D930;
    // 0x8000D8E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D8EC:
    // 0x8000D8EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D8F0: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000D8F4: j           L_8000D930
    // 0x8000D8F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D930;
    // 0x8000D8F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D8FC:
    // 0x8000D8FC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D900: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000D904: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D908: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D90C: beq         $v0, $zero, L_8000D924
    if (ctx->r2 == 0) {
        // 0x8000D910: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000D924;
    }
    // 0x8000D910: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8000D914:
    // 0x8000D914: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D918: sb          $v0, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = ctx->r2;
    // 0x8000D91C: j           L_8000D930
    // 0x8000D920: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000D930;
    // 0x8000D920: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D924:
    // 0x8000D924: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D928: sb          $zero, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = 0;
    // 0x8000D92C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D930:
    // 0x8000D930: jal         0x8000637C
    // 0x8000D934: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000637C(rdram, ctx);
        goto after_69;
    // 0x8000D934: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_69:
L_8000D938:
    // 0x8000D938: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000D93C: lb          $v0, 0x3F50($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F50);
    // 0x8000D940: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000D944: bne         $v0, $zero, L_8000DA60
    if (ctx->r2 != 0) {
        // 0x8000D948: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000DA60;
    }
    // 0x8000D948: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000D94C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000D950: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8000D954: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000D958: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000D95C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000D960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000D964: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000D968: lhu         $v1, -0x33C8($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000D96C: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8000D970: beql        $v0, $zero, L_8000D9D8
    if (ctx->r2 == 0) {
        // 0x8000D974: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8000D9D8;
    }
    goto skip_10;
    // 0x8000D974: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    skip_10:
    // 0x8000D978: bne         $a0, $zero, L_8000D9B8
    if (ctx->r4 != 0) {
        // 0x8000D97C: nop
    
            goto L_8000D9B8;
    }
    // 0x8000D97C: nop

    // 0x8000D980: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D984: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000D988: blez        $v0, L_8000D9A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D98C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000D9A4;
    }
    // 0x8000D98C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D990: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000D994: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D998: sb          $v0, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = ctx->r2;
    // 0x8000D99C: j           L_8000DA54
    // 0x8000D9A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000DA54;
    // 0x8000D9A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D9A4:
    // 0x8000D9A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000D9A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D9AC: sb          $v0, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = ctx->r2;
    // 0x8000D9B0: j           L_8000DA54
    // 0x8000D9B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000DA54;
    // 0x8000D9B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000D9B8:
    // 0x8000D9B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D9BC: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000D9C0: blez        $v0, L_8000D9D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D9C4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000D9D0;
    }
    // 0x8000D9C4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D9C8: j           L_8000DA38
    // 0x8000D9CC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8000DA38;
    // 0x8000D9CC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_8000D9D0:
    // 0x8000D9D0: j           L_8000DA38
    // 0x8000D9D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8000DA38;
    // 0x8000D9D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000D9D8:
    // 0x8000D9D8: beq         $v0, $zero, L_8000DA60
    if (ctx->r2 == 0) {
        // 0x8000D9DC: nop
    
            goto L_8000DA60;
    }
    // 0x8000D9DC: nop

    // 0x8000D9E0: bne         $a0, $zero, L_8000DA20
    if (ctx->r4 != 0) {
        // 0x8000D9E4: nop
    
            goto L_8000DA20;
    }
    // 0x8000D9E4: nop

    // 0x8000D9E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D9EC: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000D9F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000D9F4: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D9F8: beq         $v0, $zero, L_8000DA10
    if (ctx->r2 == 0) {
        // 0x8000D9FC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000DA10;
    }
    // 0x8000D9FC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000DA00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DA04: sb          $v0, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = ctx->r2;
    // 0x8000DA08: j           L_8000DA54
    // 0x8000DA0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000DA54;
    // 0x8000DA0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000DA10:
    // 0x8000DA10: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DA14: sb          $zero, -0xBE3($at)
    MEM_B(-0XBE3, ctx->r1) = 0;
    // 0x8000DA18: j           L_8000DA54
    // 0x8000DA1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000DA54;
    // 0x8000DA1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000DA20:
    // 0x8000DA20: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DA24: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000DA28: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000DA2C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000DA30: beq         $v0, $zero, L_8000DA48
    if (ctx->r2 == 0) {
        // 0x8000DA34: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000DA48;
    }
    // 0x8000DA34: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8000DA38:
    // 0x8000DA38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DA3C: sb          $v0, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = ctx->r2;
    // 0x8000DA40: j           L_8000DA54
    // 0x8000DA44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_8000DA54;
    // 0x8000DA44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000DA48:
    // 0x8000DA48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DA4C: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000DA50: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000DA54:
    // 0x8000DA54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DA58: jal         0x8000637C
    // 0x8000DA5C: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    func_8000637C(rdram, ctx);
        goto after_70;
    // 0x8000DA5C: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    after_70:
L_8000DA60:
    // 0x8000DA60: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000DA64: addiu       $a0, $a0, -0x33C8
    ctx->r4 = ADD32(ctx->r4, -0X33C8);
    // 0x8000DA68: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000DA6C: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x8000DA70: beq         $v0, $zero, L_8000DA94
    if (ctx->r2 == 0) {
        // 0x8000DA74: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000DA94;
    }
    // 0x8000DA74: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000DA78: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DA7C: sh          $v0, 0x3F46($at)
    MEM_H(0X3F46, ctx->r1) = ctx->r2;
    // 0x8000DA80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DA84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DA88: sh          $zero, 0x3F44($at)
    MEM_H(0X3F44, ctx->r1) = 0;
    // 0x8000DA8C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DA90: sh          $v0, 0x3F48($at)
    MEM_H(0X3F48, ctx->r1) = ctx->r2;
L_8000DA94:
    // 0x8000DA94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000DA98: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000DA9C: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x8000DAA0: beq         $v0, $zero, L_8000DAC4
    if (ctx->r2 == 0) {
        // 0x8000DAA4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000DAC4;
    }
    // 0x8000DAA4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000DAA8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DAAC: sh          $v0, 0x3F4C($at)
    MEM_H(0X3F4C, ctx->r1) = ctx->r2;
    // 0x8000DAB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DAB4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DAB8: sh          $zero, 0x3F4A($at)
    MEM_H(0X3F4A, ctx->r1) = 0;
    // 0x8000DABC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000DAC0: sh          $v0, 0x3F4E($at)
    MEM_H(0X3F4E, ctx->r1) = ctx->r2;
L_8000DAC4:
    // 0x8000DAC4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DAC8: lb          $v1, -0xBE4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE4);
    // 0x8000DACC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DAD0: beq         $v1, $v0, L_8000DB50
    if (ctx->r3 == ctx->r2) {
        // 0x8000DAD4: nop
    
            goto L_8000DB50;
    }
    // 0x8000DAD4: nop

    // 0x8000DAD8: lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X0);
    // 0x8000DADC: andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // 0x8000DAE0: beq         $v0, $zero, L_8000DB14
    if (ctx->r2 == 0) {
        // 0x8000DAE4: andi        $v0, $a0, 0x200
        ctx->r2 = ctx->r4 & 0X200;
            goto L_8000DB14;
    }
    // 0x8000DAE4: andi        $v0, $a0, 0x200
    ctx->r2 = ctx->r4 & 0X200;
    // 0x8000DAE8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DAEC: addiu       $v0, $v0, 0x3F44
    ctx->r2 = ADD32(ctx->r2, 0X3F44);
    // 0x8000DAF0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DAF4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DAF8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DAFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DB00: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8000DB04: bne         $v0, $zero, L_8000DB40
    if (ctx->r2 != 0) {
        // 0x8000DB08: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DB40;
    }
    // 0x8000DB08: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DB0C: j           L_8000DB44
    // 0x8000DB10: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
        goto L_8000DB44;
    // 0x8000DB10: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8000DB14:
    // 0x8000DB14: beq         $v0, $zero, L_8000DB50
    if (ctx->r2 == 0) {
        // 0x8000DB18: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8000DB50;
    }
    // 0x8000DB18: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DB1C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DB20: addiu       $v0, $v0, 0x3F44
    ctx->r2 = ADD32(ctx->r2, 0X3F44);
    // 0x8000DB24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DB28: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DB2C: blez        $v0, L_8000DB3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000DB30: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DB3C;
    }
    // 0x8000DB30: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DB34: j           L_8000DB40
    // 0x8000DB38: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_8000DB40;
    // 0x8000DB38: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8000DB3C:
    // 0x8000DB3C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000DB40:
    // 0x8000DB40: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8000DB44:
    // 0x8000DB44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000DB48: jal         0x8000637C
    // 0x8000DB4C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8000637C(rdram, ctx);
        goto after_71;
    // 0x8000DB4C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_71:
L_8000DB50:
    // 0x8000DB50: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DB54: lb          $v1, -0xBE3($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE3);
    // 0x8000DB58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DB5C: beq         $v1, $v0, L_8000DBE0
    if (ctx->r3 == ctx->r2) {
        // 0x8000DB60: nop
    
            goto L_8000DBE0;
    }
    // 0x8000DB60: nop

    // 0x8000DB64: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000DB68: lhu         $a0, -0x33C2($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X33C2);
    // 0x8000DB6C: andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // 0x8000DB70: beq         $v0, $zero, L_8000DBA4
    if (ctx->r2 == 0) {
        // 0x8000DB74: andi        $v0, $a0, 0x200
        ctx->r2 = ctx->r4 & 0X200;
            goto L_8000DBA4;
    }
    // 0x8000DB74: andi        $v0, $a0, 0x200
    ctx->r2 = ctx->r4 & 0X200;
    // 0x8000DB78: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DB7C: addiu       $v0, $v0, 0x3F4A
    ctx->r2 = ADD32(ctx->r2, 0X3F4A);
    // 0x8000DB80: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DB84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DB88: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DB8C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DB90: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8000DB94: bne         $v0, $zero, L_8000DBD0
    if (ctx->r2 != 0) {
        // 0x8000DB98: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DBD0;
    }
    // 0x8000DB98: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DB9C: j           L_8000DBD4
    // 0x8000DBA0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
        goto L_8000DBD4;
    // 0x8000DBA0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8000DBA4:
    // 0x8000DBA4: beq         $v0, $zero, L_8000DBE0
    if (ctx->r2 == 0) {
        // 0x8000DBA8: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8000DBE0;
    }
    // 0x8000DBA8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DBAC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DBB0: addiu       $v0, $v0, 0x3F4A
    ctx->r2 = ADD32(ctx->r2, 0X3F4A);
    // 0x8000DBB4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DBB8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DBBC: blez        $v0, L_8000DBCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000DBC0: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DBCC;
    }
    // 0x8000DBC0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DBC4: j           L_8000DBD0
    // 0x8000DBC8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_8000DBD0;
    // 0x8000DBC8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8000DBCC:
    // 0x8000DBCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000DBD0:
    // 0x8000DBD0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8000DBD4:
    // 0x8000DBD4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000DBD8: jal         0x8000637C
    // 0x8000DBDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000637C(rdram, ctx);
        goto after_72;
    // 0x8000DBDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_72:
L_8000DBE0:
    // 0x8000DBE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DBE4: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000DBE8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000DBEC: beql        $v0, $v1, L_8000DC08
    if (ctx->r2 == ctx->r3) {
        // 0x8000DBF0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000DC08;
    }
    goto skip_11;
    // 0x8000DBF0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_11:
    // 0x8000DBF4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DBF8: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000DBFC: bne         $v0, $v1, L_8000DC88
    if (ctx->r2 != ctx->r3) {
        // 0x8000DC00: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000DC88;
    }
    // 0x8000DC00: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000DC04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000DC08:
    // 0x8000DC08: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000DC0C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000DC10: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DC14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000DC18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000DC1C: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000DC20: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8000DC24: bne         $v0, $zero, L_8000DC68
    if (ctx->r2 != 0) {
        // 0x8000DC28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000DC68;
    }
    // 0x8000DC28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000DC2C: subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    // 0x8000DC30: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000DC34: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000DC38: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DC3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000DC40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000DC44: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000DC48: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8000DC4C: beq         $v0, $zero, L_8000DC88
    if (ctx->r2 == 0) {
        // 0x8000DC50: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000DC88;
    }
    // 0x8000DC50: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000DC54: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DC58: lb          $v0, 0x3F50($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F50);
    // 0x8000DC5C: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000DC60: bne         $v0, $zero, L_8000DC88
    if (ctx->r2 != 0) {
        // 0x8000DC64: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000DC88;
    }
    // 0x8000DC64: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8000DC68:
    // 0x8000DC68: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000DC6C: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000DC70: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000DC74: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000DC78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000DC7C: jal         0x8000637C
    // 0x8000DC80: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_73;
    // 0x8000DC80: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_73:
    // 0x8000DC84: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8000DC88:
    // 0x8000DC88: bne         $v0, $zero, L_8000DCA0
    if (ctx->r2 != 0) {
        // 0x8000DC8C: nop
    
            goto L_8000DCA0;
    }
    // 0x8000DC8C: nop

    // 0x8000DC90: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DC94: lbu         $v0, -0xBE4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE4);
    // 0x8000DC98: j           L_8000DCAC
    // 0x8000DC9C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
        goto L_8000DCAC;
    // 0x8000DC9C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
L_8000DCA0:
    // 0x8000DCA0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DCA4: lbu         $v0, -0xBE3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE3);
    // 0x8000DCA8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
L_8000DCAC:
    // 0x8000DCAC: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000DCB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DCB4: beq         $a0, $v0, L_8000DCCC
    if (ctx->r4 == ctx->r2) {
        // 0x8000DCB8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_8000DCCC;
    }
    // 0x8000DCB8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8000DCBC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000DCC0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000DCC4: bne         $v1, $v0, L_8000DD58
    if (ctx->r3 != ctx->r2) {
        // 0x8000DCC8: addiu       $t1, $a0, 0x1
        ctx->r9 = ADD32(ctx->r4, 0X1);
            goto L_8000DD58;
    }
    // 0x8000DCC8: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
L_8000DCCC:
    // 0x8000DCCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000DCD0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8000DCD4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000DCD8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000DCDC: addiu       $a0, $a0, 0x3F44
    ctx->r4 = ADD32(ctx->r4, 0X3F44);
    // 0x8000DCE0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000DCE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DCE8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DCEC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000DCF0: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x8000DCF4: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
L_8000DCF8:
    // 0x8000DCF8: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8000DCFC: beq         $v0, $zero, L_8000DD0C
    if (ctx->r2 == 0) {
        // 0x8000DD00: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8000DD0C;
    }
    // 0x8000DD00: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000DD04: j           L_8000DD14
    // 0x8000DD08: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8000DD14;
    // 0x8000DD08: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8000DD0C:
    // 0x8000DD0C: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x8000DD10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8000DD14:
    // 0x8000DD14: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8000DD18: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8000DD1C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8000DD20: bne         $a1, $v0, L_8000DD40
    if (ctx->r5 != ctx->r2) {
        // 0x8000DD24: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DD40;
    }
    // 0x8000DD24: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DD28: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8000DD2C: beq         $v0, $zero, L_8000DD3C
    if (ctx->r2 == 0) {
        // 0x8000DD30: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DD3C;
    }
    // 0x8000DD30: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DD34: j           L_8000DD40
    // 0x8000DD38: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
        goto L_8000DD40;
    // 0x8000DD38: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
L_8000DD3C:
    // 0x8000DD3C: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_8000DD40:
    // 0x8000DD40: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000DD44: slti        $v0, $t1, 0x3
    ctx->r2 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8000DD48: bne         $v0, $zero, L_8000DCF8
    if (ctx->r2 != 0) {
        // 0x8000DD4C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8000DCF8;
    }
    // 0x8000DD4C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000DD50: j           L_8000DDC8
    // 0x8000DD54: nop

        goto L_8000DDC8;
    // 0x8000DD54: nop

L_8000DD58:
    // 0x8000DD58: slti        $v0, $t1, 0x3
    ctx->r2 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8000DD5C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000DD60: and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
    // 0x8000DD64: addiu       $a3, $t1, 0x1
    ctx->r7 = ADD32(ctx->r9, 0X1);
    // 0x8000DD68: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x8000DD6C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000DD70: and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // 0x8000DD74: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8000DD78: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000DD7C: addiu       $a0, $a0, 0x3F44
    ctx->r4 = ADD32(ctx->r4, 0X3F44);
    // 0x8000DD80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000DD84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000DD88: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DD8C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000DD90: sll         $a0, $t1, 1
    ctx->r4 = S32(ctx->r9 << 1);
    // 0x8000DD94: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000DD98: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x8000DD9C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DDA0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DDA4: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8000DDA8: bne         $a1, $v0, L_8000DDC8
    if (ctx->r5 != ctx->r2) {
        // 0x8000DDAC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DDC8;
    }
    // 0x8000DDAC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DDB0: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8000DDB4: beq         $v0, $zero, L_8000DDC4
    if (ctx->r2 == 0) {
        // 0x8000DDB8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DDC4;
    }
    // 0x8000DDB8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DDBC: j           L_8000DDC8
    // 0x8000DDC0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_8000DDC8;
    // 0x8000DDC0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8000DDC4:
    // 0x8000DDC4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8000DDC8:
    // 0x8000DDC8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DDCC: lb          $v0, 0x3F50($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F50);
    // 0x8000DDD0: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000DDD4: bne         $v0, $zero, L_8000DF20
    if (ctx->r2 != 0) {
        // 0x8000DDD8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000DF20;
    }
    // 0x8000DDD8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000DDDC: bne         $v0, $zero, L_8000DDF4
    if (ctx->r2 != 0) {
        // 0x8000DDE0: nop
    
            goto L_8000DDF4;
    }
    // 0x8000DDE0: nop

    // 0x8000DDE4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DDE8: lbu         $v0, -0xBE3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE3);
    // 0x8000DDEC: j           L_8000DE00
    // 0x8000DDF0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
        goto L_8000DE00;
    // 0x8000DDF0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
L_8000DDF4:
    // 0x8000DDF4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DDF8: lbu         $v0, -0xBE4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE4);
    // 0x8000DDFC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
L_8000DE00:
    // 0x8000DE00: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000DE04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DE08: beq         $a0, $v0, L_8000DE20
    if (ctx->r4 == ctx->r2) {
        // 0x8000DE0C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_8000DE20;
    }
    // 0x8000DE0C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8000DE10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000DE14: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000DE18: bne         $v1, $v0, L_8000DEAC
    if (ctx->r3 != ctx->r2) {
        // 0x8000DE1C: addiu       $t1, $a0, 0x1
        ctx->r9 = ADD32(ctx->r4, 0X1);
            goto L_8000DEAC;
    }
    // 0x8000DE1C: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
L_8000DE20:
    // 0x8000DE20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000DE24: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8000DE28: subu        $v0, $a3, $s0
    ctx->r2 = SUB32(ctx->r7, ctx->r16);
    // 0x8000DE2C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000DE30: addiu       $a0, $a0, 0x3F44
    ctx->r4 = ADD32(ctx->r4, 0X3F44);
    // 0x8000DE34: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000DE38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DE3C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000DE40: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000DE44: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x8000DE48: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
L_8000DE4C:
    // 0x8000DE4C: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8000DE50: beq         $v0, $zero, L_8000DE60
    if (ctx->r2 == 0) {
        // 0x8000DE54: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8000DE60;
    }
    // 0x8000DE54: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000DE58: j           L_8000DE68
    // 0x8000DE5C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8000DE68;
    // 0x8000DE5C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8000DE60:
    // 0x8000DE60: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // 0x8000DE64: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8000DE68:
    // 0x8000DE68: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8000DE6C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8000DE70: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8000DE74: bne         $a1, $v0, L_8000DE94
    if (ctx->r5 != ctx->r2) {
        // 0x8000DE78: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DE94;
    }
    // 0x8000DE78: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DE7C: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8000DE80: beq         $v0, $zero, L_8000DE90
    if (ctx->r2 == 0) {
        // 0x8000DE84: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DE90;
    }
    // 0x8000DE84: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DE88: j           L_8000DE94
    // 0x8000DE8C: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
        goto L_8000DE94;
    // 0x8000DE8C: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
L_8000DE90:
    // 0x8000DE90: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_8000DE94:
    // 0x8000DE94: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000DE98: slti        $v0, $t1, 0x3
    ctx->r2 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8000DE9C: bne         $v0, $zero, L_8000DE4C
    if (ctx->r2 != 0) {
        // 0x8000DEA0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8000DE4C;
    }
    // 0x8000DEA0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000DEA4: j           L_8000DF20
    // 0x8000DEA8: nop

        goto L_8000DF20;
    // 0x8000DEA8: nop

L_8000DEAC:
    // 0x8000DEAC: slti        $v0, $t1, 0x3
    ctx->r2 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8000DEB0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000DEB4: and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
    // 0x8000DEB8: addiu       $a3, $t1, 0x1
    ctx->r7 = ADD32(ctx->r9, 0X1);
    // 0x8000DEBC: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x8000DEC0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8000DEC4: and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // 0x8000DEC8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000DECC: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x8000DED0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000DED4: addiu       $a0, $a0, 0x3F44
    ctx->r4 = ADD32(ctx->r4, 0X3F44);
    // 0x8000DED8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000DEDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000DEE0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DEE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000DEE8: sll         $a0, $t1, 1
    ctx->r4 = S32(ctx->r9 << 1);
    // 0x8000DEEC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000DEF0: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x8000DEF4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DEF8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000DEFC: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8000DF00: bne         $a1, $v0, L_8000DF20
    if (ctx->r5 != ctx->r2) {
        // 0x8000DF04: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8000DF20;
    }
    // 0x8000DF04: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000DF08: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8000DF0C: beq         $v0, $zero, L_8000DF1C
    if (ctx->r2 == 0) {
        // 0x8000DF10: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000DF1C;
    }
    // 0x8000DF10: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000DF14: j           L_8000DF20
    // 0x8000DF18: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_8000DF20;
    // 0x8000DF18: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8000DF1C:
    // 0x8000DF1C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8000DF20:
    // 0x8000DF20: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DF24: lh          $v0, 0x3F44($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F44);
    // 0x8000DF28: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DF2C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DF30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DF34: lhu         $v1, -0xBE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XBE0);
    // 0x8000DF38: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DF3C: lh          $v0, 0x3F46($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F46);
    // 0x8000DF40: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DF44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DF48: sh          $v1, -0x3260($at)
    MEM_H(-0X3260, ctx->r1) = ctx->r3;
    // 0x8000DF4C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DF50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DF54: lhu         $v1, -0xBE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XBE0);
    // 0x8000DF58: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DF5C: lh          $v0, 0x3F48($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F48);
    // 0x8000DF60: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DF64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DF68: sh          $v1, -0x325C($at)
    MEM_H(-0X325C, ctx->r1) = ctx->r3;
    // 0x8000DF6C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DF70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DF74: lhu         $v1, -0xBE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XBE0);
    // 0x8000DF78: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DF7C: lh          $v0, 0x3F4A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F4A);
    // 0x8000DF80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DF84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DF88: sh          $v1, -0x325E($at)
    MEM_H(-0X325E, ctx->r1) = ctx->r3;
    // 0x8000DF8C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DF90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DF94: lhu         $v1, -0xBE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XBE0);
    // 0x8000DF98: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DF9C: lh          $v0, 0x3F4C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F4C);
    // 0x8000DFA0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DFA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DFA8: sh          $v1, -0x325A($at)
    MEM_H(-0X325A, ctx->r1) = ctx->r3;
    // 0x8000DFAC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DFB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000DFB4: lhu         $v1, -0xBE0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XBE0);
    // 0x8000DFB8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000DFBC: lh          $v0, 0x3F4E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X3F4E);
    // 0x8000DFC0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000DFC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DFC8: sh          $v1, -0x3256($at)
    MEM_H(-0X3256, ctx->r1) = ctx->r3;
    // 0x8000DFCC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DFD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000DFD4: lhu         $v0, -0xBE0($at)
    ctx->r2 = MEM_HU(ctx->r1, -0XBE0);
    // 0x8000DFD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000DFDC: j           L_8000E33C
    // 0x8000DFE0: sh          $v0, -0x3258($at)
    MEM_H(-0X3258, ctx->r1) = ctx->r2;
        goto L_8000E33C;
    // 0x8000DFE0: sh          $v0, -0x3258($at)
    MEM_H(-0X3258, ctx->r1) = ctx->r2;
L_8000DFE4:
    // 0x8000DFE4: jal         0x80008CDC
    // 0x8000DFE8: nop

    func_80008CDC(rdram, ctx);
        goto after_74;
    // 0x8000DFE8: nop

    after_74:
    // 0x8000DFEC: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000DFF0: nop
    
            goto L_8000E33C;
    }
    // 0x8000DFF0: nop

    // 0x8000DFF4: jal         0x8002CFB8
    // 0x8000DFF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_75;
    // 0x8000DFF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_75:
    // 0x8000DFFC: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000E000: nop
    
            goto L_8000E33C;
    }
    // 0x8000E000: nop

    // 0x8000E004: jal         0x80031BEC
    // 0x8000E008: nop

    func_80031BEC(rdram, ctx);
        goto after_76;
    // 0x8000E008: nop

    after_76:
    // 0x8000E00C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000E010: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E014: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000E018: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000E01C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E020: j           L_8000E33C
    // 0x8000E024: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
        goto L_8000E33C;
    // 0x8000E024: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
L_8000E028:
    // 0x8000E028: jal         0x80008CDC
    // 0x8000E02C: nop

    func_80008CDC(rdram, ctx);
        goto after_77;
    // 0x8000E02C: nop

    after_77:
    // 0x8000E030: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000E034: nop
    
            goto L_8000E33C;
    }
    // 0x8000E034: nop

    // 0x8000E038: jal         0x8002CFB8
    // 0x8000E03C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_78;
    // 0x8000E03C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_78:
    // 0x8000E040: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000E044: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000E33C;
    }
    // 0x8000E044: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000E048: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E04C: lb          $v1, -0xBE5($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE5);
    // 0x8000E050: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E054: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000E058: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8000E05C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000E060: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000E064: sb          $v0, 0x3F59($at)
    MEM_B(0X3F59, ctx->r1) = ctx->r2;
    // 0x8000E068: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E06C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000E070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000E074: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E078: jal         0x80053390
    // 0x8000E07C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_80053390(rdram, ctx);
        goto after_79;
    // 0x8000E07C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_79:
    // 0x8000E080: jal         0x8005357C
    // 0x8000E084: nop

    func_8005357C(rdram, ctx);
        goto after_80;
    // 0x8000E084: nop

    after_80:
    // 0x8000E088: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000E08C: sw          $v0, 0x5030($at)
    MEM_W(0X5030, ctx->r1) = ctx->r2;
    // 0x8000E090: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000E094: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E33C;
    }
    // 0x8000E094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E098: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E09C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E0A0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8000E0A4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E0A8: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E0AC: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // 0x8000E0B0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000E0B4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E0B8: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E0BC: addiu       $v0, $zero, 0xB8
    ctx->r2 = ADD32(0, 0XB8);
    // 0x8000E0C0: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8000E0C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000E0C8: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8000E0CC: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
    // 0x8000E0D0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E0D4: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E0D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E0DC: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8000E0E0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E0E4: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E0E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8000E0EC: lw          $v0, 0x70C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70C);
    // 0x8000E0F0: j           L_8000E1C8
    // 0x8000E0F4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
        goto L_8000E1C8;
    // 0x8000E0F4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8000E0F8:
    // 0x8000E0F8: jal         0x80008CDC
    // 0x8000E0FC: nop

    func_80008CDC(rdram, ctx);
        goto after_81;
    // 0x8000E0FC: nop

    after_81:
    // 0x8000E100: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000E104: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_8000E33C;
    }
    // 0x8000E104: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000E108: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8000E10C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000E110: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000E114: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E118: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000E11C: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8000E120: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000E124: bne         $v0, $zero, L_8000E134
    if (ctx->r2 != 0) {
        // 0x8000E128: andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
            goto L_8000E134;
    }
    // 0x8000E128: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8000E12C: beq         $v0, $zero, L_8000E1E0
    if (ctx->r2 == 0) {
        // 0x8000E130: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8000E1E0;
    }
    // 0x8000E130: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
L_8000E134:
    // 0x8000E134: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E138: lbu         $v0, -0xBE5($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE5);
    // 0x8000E13C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000E140: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000E144: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x8000E148: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8000E14C: sra         $a1, $v1, 24
    ctx->r5 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8000E150: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8000E154: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E158: sb          $v0, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = ctx->r2;
    // 0x8000E15C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8000E160: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E164: sh          $a1, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r5;
    // 0x8000E168: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000E16C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000E170: sb          $v0, 0x3F59($at)
    MEM_B(0X3F59, ctx->r1) = ctx->r2;
    // 0x8000E174: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E178: lb          $v1, -0xBE5($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XBE5);
    // 0x8000E17C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8000E180: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000E184: addiu       $v0, $v0, 0x3F5A
    ctx->r2 = ADD32(ctx->r2, 0X3F5A);
    // 0x8000E188: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000E18C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x8000E190: jal         0x8000637C
    // 0x8000E194: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_8000637C(rdram, ctx);
        goto after_82;
    // 0x8000E194: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_82:
    // 0x8000E198: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E19C: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E1A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E1A4: lb          $v0, -0xBE5($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE5);
    // 0x8000E1A8: sw          $s0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r16;
    // 0x8000E1AC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E1B0: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8000E1B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E1B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000E1BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000E1C0: lw          $v0, 0x70C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X70C);
    // 0x8000E1C4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8000E1C8:
    // 0x8000E1C8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000E1CC: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8000E1D0: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8000E1D4: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8000E1D8: j           L_8000E33C
    // 0x8000E1DC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
        goto L_8000E33C;
    // 0x8000E1DC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8000E1E0:
    // 0x8000E1E0: beq         $v0, $zero, L_8000E214
    if (ctx->r2 == 0) {
        // 0x8000E1E4: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8000E214;
    }
    // 0x8000E1E4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000E1E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000E1EC: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000E1F0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E1F4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8000E1F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E1FC: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000E200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000E204: jal         0x8000637C
    // 0x8000E208: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_83;
    // 0x8000E208: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_83:
    // 0x8000E20C: j           L_8000E33C
    // 0x8000E210: nop

        goto L_8000E33C;
    // 0x8000E210: nop

L_8000E214:
    // 0x8000E214: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x8000E218: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000E21C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8000E33C;
    }
    // 0x8000E21C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000E220: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000E224: addiu       $a1, $a1, 0x7B71
    ctx->r5 = ADD32(ctx->r5, 0X7B71);
    // 0x8000E228: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E22C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E230: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E234: sb          $v0, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = ctx->r2;
    // 0x8000E238: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E23C: jal         0x800064C0
    // 0x8000E240: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    func_800064C0(rdram, ctx);
        goto after_84;
    // 0x8000E240: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    after_84:
    // 0x8000E244: j           L_8000E33C
    // 0x8000E248: nop

        goto L_8000E33C;
    // 0x8000E248: nop

L_8000E24C:
    // 0x8000E24C: jal         0x80008CDC
    // 0x8000E250: nop

    func_80008CDC(rdram, ctx);
        goto after_85;
    // 0x8000E250: nop

    after_85:
    // 0x8000E254: bne         $v0, $zero, L_8000E33C
    if (ctx->r2 != 0) {
        // 0x8000E258: nop
    
            goto L_8000E33C;
    }
    // 0x8000E258: nop

    // 0x8000E25C: jal         0x8002CFB8
    // 0x8000E260: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_86;
    // 0x8000E260: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_86:
    // 0x8000E264: beq         $v0, $zero, L_8000E33C
    if (ctx->r2 == 0) {
        // 0x8000E268: nop
    
            goto L_8000E33C;
    }
    // 0x8000E268: nop

    // 0x8000E26C: jal         0x80053390
    // 0x8000E270: nop

    func_80053390(rdram, ctx);
        goto after_87;
    // 0x8000E270: nop

    after_87:
    // 0x8000E274: jal         0x80031BEC
    // 0x8000E278: nop

    func_80031BEC(rdram, ctx);
        goto after_88;
    // 0x8000E278: nop

    after_88:
    // 0x8000E27C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E280: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000E284: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000E288: bne         $v0, $zero, L_8000E320
    if (ctx->r2 != 0) {
        // 0x8000E28C: sb          $t5, 0x67($sp)
        MEM_B(0X67, ctx->r29) = ctx->r13;
            goto L_8000E320;
    }
    // 0x8000E28C: sb          $t5, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r13;
    // 0x8000E290: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E294: lb          $v0, -0xBE5($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE5);
    // 0x8000E298: beq         $v0, $zero, L_8000E2D8
    if (ctx->r2 == 0) {
        // 0x8000E29C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8000E2D8;
    }
    // 0x8000E29C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000E2A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E2A4: sb          $t5, -0xBE7($at)
    MEM_B(-0XBE7, ctx->r1) = ctx->r13;
    // 0x8000E2A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2AC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000E2B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2B4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000E2B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E2BC: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
    // 0x8000E2C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2C4: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x8000E2C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2CC: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x8000E2D0: j           L_8000E314
    // 0x8000E2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E314;
    // 0x8000E2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E2D8:
    // 0x8000E2D8: lbu         $t5, 0x67($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X67);
    // 0x8000E2DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2E0: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000E2E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000E2E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2EC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000E2F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E2F4: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
    // 0x8000E2F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E2FC: sb          $v0, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = ctx->r2;
    // 0x8000E300: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E304: sb          $v0, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = ctx->r2;
    // 0x8000E308: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E30C: sb          $t5, -0xBE7($at)
    MEM_B(-0XBE7, ctx->r1) = ctx->r13;
    // 0x8000E310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E314:
    // 0x8000E314: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E318: j           L_8000E33C
    // 0x8000E31C: sb          $v0, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = ctx->r2;
        goto L_8000E33C;
    // 0x8000E31C: sb          $v0, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = ctx->r2;
L_8000E320:
    // 0x8000E320: jal         0x80041910
    // 0x8000E324: nop

    func_80041910(rdram, ctx);
        goto after_89;
    // 0x8000E324: nop

    after_89:
    // 0x8000E328: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000E32C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E330: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000E334: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E338: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
L_8000E33C:
    // 0x8000E33C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000E340: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x8000E344: jal         0x80017D38
    // 0x8000E348: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    func_80017D38(rdram, ctx);
        goto after_90;
    // 0x8000E348: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    after_90:
    // 0x8000E34C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000E350: lhu         $v0, -0x765C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X765C);
    // 0x8000E354: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000E358: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E35C: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
    // 0x8000E360: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000E364: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000E368: bne         $v0, $s0, L_8000E378
    if (ctx->r2 != ctx->r16) {
        // 0x8000E36C: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8000E378;
    }
    // 0x8000E36C: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8000E370: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E374: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
L_8000E378:
    // 0x8000E378: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000E37C: jal         0x80017D38
    // 0x8000E380: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    func_80017D38(rdram, ctx);
        goto after_91;
    // 0x8000E380: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    after_91:
    // 0x8000E384: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E388: lhu         $v0, 0x20AC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20AC);
    // 0x8000E38C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000E390: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E394: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
    // 0x8000E398: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000E39C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000E3A0: bne         $v0, $s0, L_8000E3B0
    if (ctx->r2 != ctx->r16) {
        // 0x8000E3A4: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8000E3B0;
    }
    // 0x8000E3A4: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8000E3A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E3AC: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
L_8000E3B0:
    // 0x8000E3B0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000E3B4: jal         0x80017D38
    // 0x8000E3B8: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    func_80017D38(rdram, ctx);
        goto after_92;
    // 0x8000E3B8: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    after_92:
    // 0x8000E3BC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000E3C0: jal         0x80017D38
    // 0x8000E3C4: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    func_80017D38(rdram, ctx);
        goto after_93;
    // 0x8000E3C4: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    after_93:
    // 0x8000E3C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000E3CC: lbu         $a1, 0x7B71($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B71);
    // 0x8000E3D0: lbu         $t5, 0x67($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X67);
    // 0x8000E3D4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8000E3D8: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8000E3DC: xori        $v1, $t5, 0x1
    ctx->r3 = ctx->r13 ^ 0X1;
    // 0x8000E3E0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000E3E4: beq         $v0, $zero, L_8000E3FC
    if (ctx->r2 == 0) {
        // 0x8000E3E8: sltiu       $v0, $a0, 0x7
        ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
            goto L_8000E3FC;
    }
    // 0x8000E3E8: sltiu       $v0, $a0, 0x7
    ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x8000E3EC: jal         0x80041778
    // 0x8000E3F0: nop

    func_80041778(rdram, ctx);
        goto after_94;
    // 0x8000E3F0: nop

    after_94:
    // 0x8000E3F4: j           L_8000E430
    // 0x8000E3F8: nop

        goto L_8000E430;
    // 0x8000E3F8: nop

L_8000E3FC:
    // 0x8000E3FC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000E400: beq         $v0, $zero, L_8000E418
    if (ctx->r2 == 0) {
        // 0x8000E404: addiu       $v0, $a1, -0xD
        ctx->r2 = ADD32(ctx->r5, -0XD);
            goto L_8000E418;
    }
    // 0x8000E404: addiu       $v0, $a1, -0xD
    ctx->r2 = ADD32(ctx->r5, -0XD);
    // 0x8000E408: jal         0x80041BE8
    // 0x8000E40C: nop

    func_80041BE8(rdram, ctx);
        goto after_95;
    // 0x8000E40C: nop

    after_95:
    // 0x8000E410: j           L_8000E430
    // 0x8000E414: nop

        goto L_8000E430;
    // 0x8000E414: nop

L_8000E418:
    // 0x8000E418: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8000E41C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000E420: beq         $v0, $zero, L_8000E430
    if (ctx->r2 == 0) {
        // 0x8000E424: nop
    
            goto L_8000E430;
    }
    // 0x8000E424: nop

    // 0x8000E428: jal         0x80042040
    // 0x8000E42C: nop

    func_80042040(rdram, ctx);
        goto after_96;
    // 0x8000E42C: nop

    after_96:
L_8000E430:
    // 0x8000E430: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8000E434: addiu       $s2, $s2, 0x7B71
    ctx->r18 = ADD32(ctx->r18, 0X7B71);
    // 0x8000E438: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8000E43C: addiu       $v0, $v0, -0x7
    ctx->r2 = ADD32(ctx->r2, -0X7);
    // 0x8000E440: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8000E444: beq         $v0, $zero, L_8000E4A8
    if (ctx->r2 == 0) {
        // 0x8000E448: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8000E4A8;
    }
    // 0x8000E448: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8000E44C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000E450: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8000E454: ori         $a0, $a0, 0x3C0
    ctx->r4 = ctx->r4 | 0X3C0;
    // 0x8000E458: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8000E45C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000E460: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000E464: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8000E468: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E46C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E470: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8000E474: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000E478: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8000E47C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000E480: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000E484: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8000E488: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8000E48C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8000E490: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8000E494: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8000E498: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000E49C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8000E4A0: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8000E4A4: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
L_8000E4A8:
    // 0x8000E4A8: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8000E4AC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000E4B0: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8000E4B4: beq         $v0, $zero, L_8000E598
    if (ctx->r2 == 0) {
        // 0x8000E4B8: addiu       $a1, $zero, 0x22
        ctx->r5 = ADD32(0, 0X22);
            goto L_8000E598;
    }
    // 0x8000E4B8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8000E4BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E4C0: addiu       $a0, $a0, -0x32B0
    ctx->r4 = ADD32(ctx->r4, -0X32B0);
    // 0x8000E4C4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8000E4C8: addiu       $s0, $s0, 0x3F59
    ctx->r16 = ADD32(ctx->r16, 0X3F59);
    // 0x8000E4CC: lb          $a3, 0x0($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X0);
    // 0x8000E4D0: jal         0x8004EC44
    // 0x8000E4D4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    func_8004EC44(rdram, ctx);
        goto after_97;
    // 0x8000E4D4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    after_97:
    // 0x8000E4D8: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8000E4DC: addiu       $s1, $s1, -0x32A8
    ctx->r17 = ADD32(ctx->r17, -0X32A8);
    // 0x8000E4E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000E4E4: lb          $a3, 0x0($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X0);
    // 0x8000E4E8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8000E4EC: jal         0x8004EC44
    // 0x8000E4F0: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    func_8004EC44(rdram, ctx);
        goto after_98;
    // 0x8000E4F0: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_98:
    // 0x8000E4F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E4F8: addiu       $a0, $a0, -0x32A0
    ctx->r4 = ADD32(ctx->r4, -0X32A0);
    // 0x8000E4FC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E500: lb          $a3, 0x3F5A($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5A);
    // 0x8000E504: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8000E508: jal         0x8004EC44
    // 0x8000E50C: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    func_8004EC44(rdram, ctx);
        goto after_99;
    // 0x8000E50C: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    after_99:
    // 0x8000E510: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E514: addiu       $a0, $a0, -0x3298
    ctx->r4 = ADD32(ctx->r4, -0X3298);
    // 0x8000E518: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E51C: lb          $a3, 0x3F5A($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5A);
    // 0x8000E520: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x8000E524: jal         0x8004EC44
    // 0x8000E528: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    func_8004EC44(rdram, ctx);
        goto after_100;
    // 0x8000E528: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_100:
    // 0x8000E52C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E530: addiu       $a0, $a0, -0x3290
    ctx->r4 = ADD32(ctx->r4, -0X3290);
    // 0x8000E534: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E538: lb          $a3, 0x3F5B($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5B);
    // 0x8000E53C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8000E540: jal         0x8004EC44
    // 0x8000E544: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    func_8004EC44(rdram, ctx);
        goto after_101;
    // 0x8000E544: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    after_101:
    // 0x8000E548: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000E54C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E550: lb          $a3, 0x3F5B($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5B);
    // 0x8000E554: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8000E558: jal         0x8004EC44
    // 0x8000E55C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    func_8004EC44(rdram, ctx);
        goto after_102;
    // 0x8000E55C: addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    after_102:
    // 0x8000E560: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E564: addiu       $a0, $a0, -0x3288
    ctx->r4 = ADD32(ctx->r4, -0X3288);
    // 0x8000E568: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E56C: lb          $a3, 0x3F5C($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5C);
    // 0x8000E570: addiu       $a1, $zero, 0xC6
    ctx->r5 = ADD32(0, 0XC6);
    // 0x8000E574: jal         0x8004EC44
    // 0x8000E578: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    func_8004EC44(rdram, ctx);
        goto after_103;
    // 0x8000E578: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    after_103:
    // 0x8000E57C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E580: addiu       $a0, $a0, -0x3280
    ctx->r4 = ADD32(ctx->r4, -0X3280);
    // 0x8000E584: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8000E588: lb          $a3, 0x3F5C($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X3F5C);
    // 0x8000E58C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8000E590: jal         0x8004EC44
    // 0x8000E594: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    func_8004EC44(rdram, ctx);
        goto after_104;
    // 0x8000E594: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_104:
L_8000E598:
    // 0x8000E598: jal         0x80051D6C
    // 0x8000E59C: nop

    func_80051D6C(rdram, ctx);
        goto after_105;
    // 0x8000E59C: nop

    after_105:
    // 0x8000E5A0: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8000E5A4: addiu       $v0, $v1, -0x7
    ctx->r2 = ADD32(ctx->r3, -0X7);
    // 0x8000E5A8: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8000E5AC: beq         $v0, $zero, L_8000E5DC
    if (ctx->r2 == 0) {
        // 0x8000E5B0: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_8000E5DC;
    }
    // 0x8000E5B0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000E5B4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E5B8: lb          $v0, -0xBE5($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE5);
    // 0x8000E5BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E5C0: addiu       $a0, $a0, -0x3278
    ctx->r4 = ADD32(ctx->r4, -0X3278);
    // 0x8000E5C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E5C8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000E5CC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000E5D0: lw          $a2, -0xB70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB70);
    // 0x8000E5D4: j           L_8000E7A4
    // 0x8000E5D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8000E7A4;
    // 0x8000E5D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8000E5DC:
    // 0x8000E5DC: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x8000E5E0: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8000E5E4: beq         $v0, $zero, L_8000E76C
    if (ctx->r2 == 0) {
        // 0x8000E5E8: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_8000E76C;
    }
    // 0x8000E5E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8000E5EC: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000E5F0: addiu       $s0, $s0, -0x3278
    ctx->r16 = ADD32(ctx->r16, -0X3278);
    // 0x8000E5F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000E5F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E5FC: lb          $v0, -0xBE4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE4);
    // 0x8000E600: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000E604: addiu       $s3, $s3, -0xBD4
    ctx->r19 = ADD32(ctx->r19, -0XBD4);
    // 0x8000E608: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E60C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000E610: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000E614: lw          $a2, -0xB60($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB60);
    // 0x8000E618: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8000E61C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8000E620: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8000E624: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8000E628: nop

    // 0x8000E62C: jal         0x8004EC44
    // 0x8000E630: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_106;
    // 0x8000E630: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_106:
    // 0x8000E634: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E638: lb          $v0, -0xBE3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XBE3);
    // 0x8000E63C: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x8000E640: addiu       $s4, $s4, 0x3F44
    ctx->r20 = ADD32(ctx->r20, 0X3F44);
    // 0x8000E644: addiu       $s5, $s4, 0x6
    ctx->r21 = ADD32(ctx->r20, 0X6);
    // 0x8000E648: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000E64C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000E650: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000E654: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000E658: lw          $a2, -0xB60($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB60);
    // 0x8000E65C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8000E660: jal         0x8004EC44
    // 0x8000E664: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004EC44(rdram, ctx);
        goto after_107;
    // 0x8000E664: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_107:
    // 0x8000E668: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E66C: addiu       $a0, $a0, -0x3274
    ctx->r4 = ADD32(ctx->r4, -0X3274);
    // 0x8000E670: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x8000E674: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8000E678: jal         0x8004EC44
    // 0x8000E67C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004EC44(rdram, ctx);
        goto after_108;
    // 0x8000E67C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_108:
    // 0x8000E680: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E684: addiu       $a0, $a0, -0x3270
    ctx->r4 = ADD32(ctx->r4, -0X3270);
    // 0x8000E688: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8000E68C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8000E690: jal         0x8004EC44
    // 0x8000E694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004EC44(rdram, ctx);
        goto after_109;
    // 0x8000E694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_109:
    // 0x8000E698: sll         $s2, $s1, 1
    ctx->r18 = S32(ctx->r17 << 1);
L_8000E69C:
    // 0x8000E69C: addu        $v0, $s2, $s4
    ctx->r2 = ADD32(ctx->r18, ctx->r20);
    // 0x8000E6A0: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8000E6A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8000E6A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E6AC: nop

    // 0x8000E6B0: beql        $v0, $zero, L_8000E6C8
    if (ctx->r2 == 0) {
        // 0x8000E6B4: mul.s       $f0, $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
            goto L_8000E6C8;
    }
    goto skip_12;
    // 0x8000E6B4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    skip_12:
    // 0x8000E6B8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8000E6BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E6C0: nop

    // 0x8000E6C4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_8000E6C8:
    // 0x8000E6C8: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8000E6CC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000E6D0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000E6D4: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x8000E6D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000E6DC: sll         $v0, $s1, 5
    ctx->r2 = S32(ctx->r17 << 5);
    // 0x8000E6E0: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8000E6E4: addiu       $s0, $v0, 0x2D
    ctx->r16 = ADD32(ctx->r2, 0X2D);
    // 0x8000E6E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000E6EC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000E6F0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8000E6F4: nop

    // 0x8000E6F8: jal         0x8004EC44
    // 0x8000E6FC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004EC44(rdram, ctx);
        goto after_110;
    // 0x8000E6FC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_110:
    // 0x8000E700: addu        $v0, $s2, $s5
    ctx->r2 = ADD32(ctx->r18, ctx->r21);
    // 0x8000E704: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8000E708: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000E70C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E710: nop

    // 0x8000E714: beql        $v0, $zero, L_8000E72C
    if (ctx->r2 == 0) {
        // 0x8000E718: mul.s       $f0, $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
            goto L_8000E72C;
    }
    goto skip_13;
    // 0x8000E718: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    skip_13:
    // 0x8000E71C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8000E720: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E724: nop

    // 0x8000E728: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_8000E72C:
    // 0x8000E72C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8000E730: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8000E734: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000E738: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8000E73C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x8000E740: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8000E744: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000E748: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8000E74C: nop

    // 0x8000E750: jal         0x8004EC44
    // 0x8000E754: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004EC44(rdram, ctx);
        goto after_111;
    // 0x8000E754: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_111:
    // 0x8000E758: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8000E75C: bne         $v0, $zero, L_8000E69C
    if (ctx->r2 != 0) {
        // 0x8000E760: sll         $s2, $s1, 1
        ctx->r18 = S32(ctx->r17 << 1);
            goto L_8000E69C;
    }
    // 0x8000E760: sll         $s2, $s1, 1
    ctx->r18 = S32(ctx->r17 << 1);
    // 0x8000E764: j           L_8000E7AC
    // 0x8000E768: nop

        goto L_8000E7AC;
    // 0x8000E768: nop

L_8000E76C:
    // 0x8000E76C: addiu       $v0, $v1, -0xD
    ctx->r2 = ADD32(ctx->r3, -0XD);
    // 0x8000E770: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8000E774: beq         $v0, $zero, L_8000E7AC
    if (ctx->r2 == 0) {
        // 0x8000E778: addiu       $a1, $zero, 0x58
        ctx->r5 = ADD32(0, 0X58);
            goto L_8000E7AC;
    }
    // 0x8000E778: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x8000E77C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E780: addiu       $a0, $a0, -0x326C
    ctx->r4 = ADD32(ctx->r4, -0X326C);
    // 0x8000E784: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8000E788: jal         0x8004EC44
    // 0x8000E78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8004EC44(rdram, ctx);
        goto after_112;
    // 0x8000E78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_112:
    // 0x8000E790: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000E794: addiu       $a0, $a0, -0x3260
    ctx->r4 = ADD32(ctx->r4, -0X3260);
    // 0x8000E798: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8000E79C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x8000E7A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8000E7A4:
    // 0x8000E7A4: jal         0x8004EC44
    // 0x8000E7A8: nop

    func_8004EC44(rdram, ctx);
        goto after_113;
    // 0x8000E7A8: nop

    after_113:
L_8000E7AC:
    // 0x8000E7AC: jal         0x800533F0
    // 0x8000E7B0: nop

    func_800533F0(rdram, ctx);
        goto after_114;
    // 0x8000E7B0: nop

    after_114:
    // 0x8000E7B4: lw          $ra, 0x16C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X16C);
    // 0x8000E7B8: lw          $fp, 0x168($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X168);
    // 0x8000E7BC: lw          $s7, 0x164($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X164);
    // 0x8000E7C0: lw          $s6, 0x160($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X160);
    // 0x8000E7C4: lw          $s5, 0x15C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X15C);
    // 0x8000E7C8: lw          $s4, 0x158($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X158);
    // 0x8000E7CC: lw          $s3, 0x154($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X154);
    // 0x8000E7D0: lw          $s2, 0x150($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X150);
    // 0x8000E7D4: lw          $s1, 0x14C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14C);
    // 0x8000E7D8: lw          $s0, 0x148($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X148);
    // 0x8000E7DC: ldc1        $f22, 0x178($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X178);
    // 0x8000E7E0: ldc1        $f20, 0x170($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X170);
    // 0x8000E7E4: jr          $ra
    // 0x8000E7E8: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x8000E7E8: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void func_8000E7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E7EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E7F0: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000E7F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000E7F8: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000E7FC: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8000E800: sw          $fp, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r30;
    // 0x8000E804: sw          $ra, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r31;
    // 0x8000E808: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x8000E80C: sw          $s6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r22;
    // 0x8000E810: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x8000E814: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x8000E818: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x8000E81C: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x8000E820: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x8000E824: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x8000E828: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8000E82C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000E830: sltiu       $v0, $v1, 0xE
    ctx->r2 = ctx->r3 < 0XE ? 1 : 0;
    // 0x8000E834: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000E838: addu        $fp, $zero, $zero
        ctx->r30 = ADD32(0, 0);
            goto L_8000FDA0;
    }
    // 0x8000E838: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8000E83C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000E840: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000E844: addu        $at, $at, $v0
    gpr jr_addend_8000E84C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000E848: lw          $v0, -0x3208($at)
    ctx->r2 = ADD32(ctx->r1, -0X3208);
    // 0x8000E84C: jr          $v0
    // 0x8000E850: nop

    switch (jr_addend_8000E84C >> 2) {
        case 0: goto L_8000E854; break;
        case 1: goto L_8000EC28; break;
        case 2: goto L_8000ECD8; break;
        case 3: goto L_8000EDB8; break;
        case 4: goto L_8000EFC8; break;
        case 5: goto L_8000F1B4; break;
        case 6: goto L_8000F2EC; break;
        case 7: goto L_8000F3A0; break;
        case 8: goto L_8000F820; break;
        case 9: goto L_8000F8C8; break;
        case 10: goto L_8000F9D4; break;
        case 11: goto L_8000FA78; break;
        case 12: goto L_8000FC8C; break;
        case 13: goto L_8000FD54; break;
        default: switch_error(__func__, 0x8000E84C, 0x800ACDF8);
    }
    // 0x8000E850: nop

L_8000E854:
    // 0x8000E854: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000E858: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000E85C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000E860: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000E864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E868: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000E86C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E870: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
    // 0x8000E874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E878: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    // 0x8000E87C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E880: jal         0x80053390
    // 0x8000E884: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80053390(rdram, ctx);
        goto after_0;
    // 0x8000E884: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_0:
    // 0x8000E888: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E88C: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000E890: beq         $v0, $zero, L_8000E8A4
    if (ctx->r2 == 0) {
        // 0x8000E894: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000E8A4;
    }
    // 0x8000E894: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000E898: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E89C: j           L_8000E8AC
    // 0x8000E8A0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
        goto L_8000E8AC;
    // 0x8000E8A0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_8000E8A4:
    // 0x8000E8A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E8A8: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8000E8AC:
    // 0x8000E8AC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E8B0: lbu         $v0, -0xBE7($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE7);
    // 0x8000E8B4: bne         $v0, $zero, L_8000EA98
    if (ctx->r2 != 0) {
        // 0x8000E8B8: nop
    
            goto L_8000EA98;
    }
    // 0x8000E8B8: nop

    // 0x8000E8BC: jal         0x800067C8
    // 0x8000E8C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x8000E8C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8000E8C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E8C8: addiu       $v0, $v0, 0x6ACA
    ctx->r2 = ADD32(ctx->r2, 0X6ACA);
    // 0x8000E8CC: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000E8D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000E8D4: jal         0x80017760
    // 0x8000E8D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_2;
    // 0x8000E8D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_2:
    // 0x8000E8DC: addiu       $s5, $zero, 0xC0
    ctx->r21 = ADD32(0, 0XC0);
    // 0x8000E8E0: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000E8E4: addiu       $s1, $s1, -0x57C0
    ctx->r17 = ADD32(ctx->r17, -0X57C0);
    // 0x8000E8E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E8EC: sh          $s5, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r21;
    // 0x8000E8F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E8F4: sh          $s5, 0x6AAE($at)
    MEM_H(0X6AAE, ctx->r1) = ctx->r21;
    // 0x8000E8F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E8FC: sw          $s1, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r17;
    // 0x8000E900: jal         0x80066D30
    // 0x8000E904: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_3;
    // 0x8000E904: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8000E908: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E90C: addiu       $v0, $v0, 0x354A
    ctx->r2 = ADD32(ctx->r2, 0X354A);
    // 0x8000E910: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000E914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000E918: jal         0x80017760
    // 0x8000E91C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_4;
    // 0x8000E91C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_4:
    // 0x8000E920: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8000E924: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E928: sh          $s5, 0x352A($at)
    MEM_H(0X352A, ctx->r1) = ctx->r21;
    // 0x8000E92C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E930: sh          $s5, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r21;
    // 0x8000E934: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000E938: sh          $v0, 0x352C($at)
    MEM_H(0X352C, ctx->r1) = ctx->r2;
    // 0x8000E93C: jal         0x80066D30
    // 0x8000E940: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_5;
    // 0x8000E940: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8000E944: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8000E948: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8000E94C: addiu       $a1, $s1, -0x7800
    ctx->r5 = ADD32(ctx->r17, -0X7800);
    // 0x8000E950: jal         0x80006D98
    // 0x8000E954: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_6;
    // 0x8000E954: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_6:
    // 0x8000E958: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000E95C: addiu       $v0, $v0, -0x7636
    ctx->r2 = ADD32(ctx->r2, -0X7636);
    // 0x8000E960: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000E964: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000E968: jal         0x80017760
    // 0x8000E96C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_7;
    // 0x8000E96C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_7:
    // 0x8000E970: addiu       $s1, $zero, 0x600
    ctx->r17 = ADD32(0, 0X600);
    // 0x8000E974: addiu       $s2, $zero, 0x240
    ctx->r18 = ADD32(0, 0X240);
    // 0x8000E978: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8000E97C: addiu       $s4, $s4, -0x75C0
    ctx->r20 = ADD32(ctx->r20, -0X75C0);
    // 0x8000E980: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8000E984: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8000E988: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8000E98C: addiu       $s3, $s3, -0x2338
    ctx->r19 = ADD32(ctx->r19, -0X2338);
    // 0x8000E990: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E994: sh          $s1, -0x765E($at)
    MEM_H(-0X765E, ctx->r1) = ctx->r17;
    // 0x8000E998: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E99C: sh          $zero, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = 0;
    // 0x8000E9A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9A4: sh          $s5, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = ctx->r21;
    // 0x8000E9A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9AC: sh          $s1, -0x765A($at)
    MEM_H(-0X765A, ctx->r1) = ctx->r17;
    // 0x8000E9B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9B4: sh          $s2, -0x7652($at)
    MEM_H(-0X7652, ctx->r1) = ctx->r18;
    // 0x8000E9B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9BC: sh          $s2, -0x7656($at)
    MEM_H(-0X7656, ctx->r1) = ctx->r18;
    // 0x8000E9C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9C4: sw          $s4, -0x7650($at)
    MEM_W(-0X7650, ctx->r1) = ctx->r20;
    // 0x8000E9C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9CC: sb          $s7, -0x764A($at)
    MEM_B(-0X764A, ctx->r1) = ctx->r23;
    // 0x8000E9D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9D4: sb          $s6, -0x7649($at)
    MEM_B(-0X7649, ctx->r1) = ctx->r22;
    // 0x8000E9D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9DC: sh          $zero, -0x7648($at)
    MEM_H(-0X7648, ctx->r1) = 0;
    // 0x8000E9E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000E9E4: sw          $s3, -0x7630($at)
    MEM_W(-0X7630, ctx->r1) = ctx->r19;
    // 0x8000E9E8: jal         0x80066D30
    // 0x8000E9EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_8;
    // 0x8000E9EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8000E9F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000E9F4: addiu       $v0, $v0, 0x20D2
    ctx->r2 = ADD32(ctx->r2, 0X20D2);
    // 0x8000E9F8: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8000E9FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000EA00: jal         0x80017760
    // 0x8000EA04: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_9;
    // 0x8000EA04: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_9:
    // 0x8000EA08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA0C: sh          $s1, 0x20AA($at)
    MEM_H(0X20AA, ctx->r1) = ctx->r17;
    // 0x8000EA10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000EA14: sh          $s1, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r17;
    // 0x8000EA18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA1C: sh          $s5, 0x20B4($at)
    MEM_H(0X20B4, ctx->r1) = ctx->r21;
    // 0x8000EA20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA24: sh          $s1, 0x20AE($at)
    MEM_H(0X20AE, ctx->r1) = ctx->r17;
    // 0x8000EA28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA2C: sh          $s2, 0x20B6($at)
    MEM_H(0X20B6, ctx->r1) = ctx->r18;
    // 0x8000EA30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA34: sh          $s2, 0x20B2($at)
    MEM_H(0X20B2, ctx->r1) = ctx->r18;
    // 0x8000EA38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA3C: sw          $s4, 0x20B8($at)
    MEM_W(0X20B8, ctx->r1) = ctx->r20;
    // 0x8000EA40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA44: sb          $s7, 0x20BE($at)
    MEM_B(0X20BE, ctx->r1) = ctx->r23;
    // 0x8000EA48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA4C: sb          $s6, 0x20BF($at)
    MEM_B(0X20BF, ctx->r1) = ctx->r22;
    // 0x8000EA50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA54: sh          $zero, 0x20C0($at)
    MEM_H(0X20C0, ctx->r1) = 0;
    // 0x8000EA58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EA5C: sw          $s3, 0x20D8($at)
    MEM_W(0X20D8, ctx->r1) = ctx->r19;
    // 0x8000EA60: jal         0x80066D30
    // 0x8000EA64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_10;
    // 0x8000EA64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8000EA68: lui         $a0, 0x11
    ctx->r4 = S32(0X11 << 16);
    // 0x8000EA6C: addiu       $a0, $a0, -0x2EC0
    ctx->r4 = ADD32(ctx->r4, -0X2EC0);
    // 0x8000EA70: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8000EA74: jal         0x80006D98
    // 0x8000EA78: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    func_80006D98(rdram, ctx);
        goto after_11;
    // 0x8000EA78: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    after_11:
    // 0x8000EA7C: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x8000EA80: addiu       $a0, $a0, -0x56C0
    ctx->r4 = ADD32(ctx->r4, -0X56C0);
    // 0x8000EA84: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8000EA88: jal         0x80006D98
    // 0x8000EA8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_12;
    // 0x8000EA8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_12:
    // 0x8000EA90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EA94: sb          $zero, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = 0;
L_8000EA98:
    // 0x8000EA98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EA9C: sb          $zero, -0xBE7($at)
    MEM_B(-0XBE7, ctx->r1) = 0;
    // 0x8000EAA0: jal         0x800440C4
    // 0x8000EAA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800440C4(rdram, ctx);
        goto after_13;
    // 0x8000EAA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // 0x8000EAA8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000EAAC: lw          $a0, -0xBF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBF4);
    // 0x8000EAB0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000EAB4: addiu       $a1, $a1, -0x2F50
    ctx->r5 = ADD32(ctx->r5, -0X2F50);
    // 0x8000EAB8: jal         0x8005334C
    // 0x8000EABC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_8005334C(rdram, ctx);
        goto after_14;
    // 0x8000EABC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_14:
    // 0x8000EAC0: jal         0x80031BEC
    // 0x8000EAC4: nop

    func_80031BEC(rdram, ctx);
        goto after_15;
    // 0x8000EAC4: nop

    after_15:
    // 0x8000EAC8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EACC: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000EAD0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000EAD4: beq         $v0, $zero, L_8000EB04
    if (ctx->r2 == 0) {
        // 0x8000EAD8: sb          $zero, 0x3F58($at)
        MEM_B(0X3F58, ctx->r1) = 0;
            goto L_8000EB04;
    }
    // 0x8000EAD8: sb          $zero, 0x3F58($at)
    MEM_B(0X3F58, ctx->r1) = 0;
    // 0x8000EADC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EAE0: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000EAE4: beq         $v0, $zero, L_8000EB04
    if (ctx->r2 == 0) {
        // 0x8000EAE8: nop
    
            goto L_8000EB04;
    }
    // 0x8000EAE8: nop

    // 0x8000EAEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EAF0: lbu         $v0, 0x7BA4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA4);
    // 0x8000EAF4: bne         $v0, $zero, L_8000EBD8
    if (ctx->r2 != 0) {
        // 0x8000EAF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD8;
    }
    // 0x8000EAF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EAFC: j           L_8000EBD0
    // 0x8000EB00: nop

        goto L_8000EBD0;
    // 0x8000EB00: nop

L_8000EB04:
    // 0x8000EB04: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000EB08: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
    // 0x8000EB0C: beq         $v1, $zero, L_8000EB6C
    if (ctx->r3 == 0) {
        // 0x8000EB10: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB10: nop

    // 0x8000EB14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB18: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8000EB1C: beq         $v0, $zero, L_8000EB6C
    if (ctx->r2 == 0) {
        // 0x8000EB20: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB20: nop

    // 0x8000EB24: bne         $v1, $v0, L_8000EB6C
    if (ctx->r3 != ctx->r2) {
        // 0x8000EB28: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB28: nop

    // 0x8000EB2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB30: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000EB34: beq         $v0, $zero, L_8000EB54
    if (ctx->r2 == 0) {
        // 0x8000EB38: nop
    
            goto L_8000EB54;
    }
    // 0x8000EB38: nop

    // 0x8000EB3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB40: lb          $v0, 0x25F3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25F3);
    // 0x8000EB44: beq         $v0, $zero, L_8000EBD0
    if (ctx->r2 == 0) {
        // 0x8000EB48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD0;
    }
    // 0x8000EB48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EB4C: j           L_8000EBC4
    // 0x8000EB50: nop

        goto L_8000EBC4;
    // 0x8000EB50: nop

L_8000EB54:
    // 0x8000EB54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB58: lb          $v0, 0x7A43($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A43);
    // 0x8000EB5C: beq         $v0, $zero, L_8000EBD0
    if (ctx->r2 == 0) {
        // 0x8000EB60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD0;
    }
    // 0x8000EB60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EB64: j           L_8000EBC4
    // 0x8000EB68: nop

        goto L_8000EBC4;
    // 0x8000EB68: nop

L_8000EB6C:
    // 0x8000EB6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB70: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000EB74: beq         $v0, $zero, L_8000EBA4
    if (ctx->r2 == 0) {
        // 0x8000EB78: nop
    
            goto L_8000EBA4;
    }
    // 0x8000EB78: nop

    // 0x8000EB7C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB80: lb          $v0, 0x25F3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25F3);
    // 0x8000EB84: beq         $v0, $zero, L_8000EBD0
    if (ctx->r2 == 0) {
        // 0x8000EB88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD0;
    }
    // 0x8000EB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EB8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EB90: lb          $v0, 0x25E8($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25E8);
    // 0x8000EB94: beq         $v0, $zero, L_8000EBC4
    if (ctx->r2 == 0) {
        // 0x8000EB98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBC4;
    }
    // 0x8000EB98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EB9C: j           L_8000EBD0
    // 0x8000EBA0: nop

        goto L_8000EBD0;
    // 0x8000EBA0: nop

L_8000EBA4:
    // 0x8000EBA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EBA8: lb          $v0, 0x7A43($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A43);
    // 0x8000EBAC: beq         $v0, $zero, L_8000EBD0
    if (ctx->r2 == 0) {
        // 0x8000EBB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD0;
    }
    // 0x8000EBB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EBB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EBB8: lb          $v0, 0x7A38($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A38);
    // 0x8000EBBC: bne         $v0, $zero, L_8000EBD0
    if (ctx->r2 != 0) {
        // 0x8000EBC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000EBD0;
    }
    // 0x8000EBC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000EBC4:
    // 0x8000EBC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000EBC8: j           L_8000EBD8
    // 0x8000EBCC: sb          $zero, 0x3F58($at)
    MEM_B(0X3F58, ctx->r1) = 0;
        goto L_8000EBD8;
    // 0x8000EBCC: sb          $zero, 0x3F58($at)
    MEM_B(0X3F58, ctx->r1) = 0;
L_8000EBD0:
    // 0x8000EBD0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000EBD4: sb          $v0, 0x3F58($at)
    MEM_B(0X3F58, ctx->r1) = ctx->r2;
L_8000EBD8:
    // 0x8000EBD8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000EBDC: lb          $v0, 0x3F58($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F58);
    // 0x8000EBE0: beq         $v0, $zero, L_8000EBF0
    if (ctx->r2 == 0) {
        // 0x8000EBE4: nop
    
            goto L_8000EBF0;
    }
    // 0x8000EBE4: nop

    // 0x8000EBE8: jal         0x8003389C
    // 0x8000EBEC: nop

    func_8003389C(rdram, ctx);
        goto after_16;
    // 0x8000EBEC: nop

    after_16:
L_8000EBF0:
    // 0x8000EBF0: jal         0x8002CFB8
    // 0x8000EBF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_17;
    // 0x8000EBF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8000EBF8: beq         $v0, $zero, L_8000FCEC
    if (ctx->r2 == 0) {
        // 0x8000EBFC: nop
    
            goto L_8000FCEC;
    }
    // 0x8000EBFC: nop

    // 0x8000EC00: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EC04: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000EC08: beq         $v0, $zero, L_8000EC1C
    if (ctx->r2 == 0) {
        // 0x8000EC0C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000EC1C;
    }
    // 0x8000EC0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000EC10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EC14: j           L_8000FDA0
    // 0x8000EC18: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
        goto L_8000FDA0;
    // 0x8000EC18: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_8000EC1C:
    // 0x8000EC1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EC20: j           L_8000FDA0
    // 0x8000EC24: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
        goto L_8000FDA0;
    // 0x8000EC24: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8000EC28:
    // 0x8000EC28: jal         0x80008CDC
    // 0x8000EC2C: nop

    func_80008CDC(rdram, ctx);
        goto after_18;
    // 0x8000EC2C: nop

    after_18:
    // 0x8000EC30: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EC34: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EC34: nop

    // 0x8000EC38: jal         0x8002CFB8
    // 0x8000EC3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_19;
    // 0x8000EC3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8000EC40: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000EC44: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EC44: nop

    // 0x8000EC48: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EC4C: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000EC50: beq         $v0, $zero, L_8000EC64
    if (ctx->r2 == 0) {
        // 0x8000EC54: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000EC64;
    }
    // 0x8000EC54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000EC58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EC5C: j           L_8000EC6C
    // 0x8000EC60: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
        goto L_8000EC6C;
    // 0x8000EC60: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_8000EC64:
    // 0x8000EC64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EC68: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8000EC6C:
    // 0x8000EC6C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000EC70: lb          $v0, 0x3F58($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3F58);
    // 0x8000EC74: bne         $v0, $zero, L_8000ECC0
    if (ctx->r2 != 0) {
        // 0x8000EC78: nop
    
            goto L_8000ECC0;
    }
    // 0x8000EC78: nop

    // 0x8000EC7C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EC80: lbu         $v0, 0x7BA4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA4);
    // 0x8000EC84: bne         $v0, $zero, L_8000EC9C
    if (ctx->r2 != 0) {
        // 0x8000EC88: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8000EC9C;
    }
    // 0x8000EC88: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000EC8C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000EC90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EC94: j           L_8000F2C4
    // 0x8000EC98: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_8000F2C4;
    // 0x8000EC98: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000EC9C:
    // 0x8000EC9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000ECA0: jal         0x80031BEC
    // 0x8000ECA4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_80031BEC(rdram, ctx);
        goto after_20;
    // 0x8000ECA4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_20:
    // 0x8000ECA8: jal         0x800437FC
    // 0x8000ECAC: nop

    func_800437FC(rdram, ctx);
        goto after_21;
    // 0x8000ECAC: nop

    after_21:
    // 0x8000ECB0: jal         0x80054350
    // 0x8000ECB4: nop

    func_80054350(rdram, ctx);
        goto after_22;
    // 0x8000ECB4: nop

    after_22:
    // 0x8000ECB8: j           L_8000FDA0
    // 0x8000ECBC: nop

        goto L_8000FDA0;
    // 0x8000ECBC: nop

L_8000ECC0:
    // 0x8000ECC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000ECC4: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000ECC8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000ECCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000ECD0: j           L_8000FDA0
    // 0x8000ECD4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8000FDA0;
    // 0x8000ECD4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000ECD8:
    // 0x8000ECD8: jal         0x80008CDC
    // 0x8000ECDC: nop

    func_80008CDC(rdram, ctx);
        goto after_23;
    // 0x8000ECDC: nop

    after_23:
    // 0x8000ECE0: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000ECE4: nop
    
            goto L_8000FDA0;
    }
    // 0x8000ECE4: nop

    // 0x8000ECE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000ECEC: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000ECF0: beq         $v0, $zero, L_8000ED2C
    if (ctx->r2 == 0) {
        // 0x8000ECF4: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000ED2C;
    }
    // 0x8000ECF4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000ECF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000ECFC: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000ED00: beq         $v0, $zero, L_8000ED2C
    if (ctx->r2 == 0) {
        // 0x8000ED04: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000ED2C;
    }
    // 0x8000ED04: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000ED08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000ED0C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000ED10: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000ED14: bne         $v0, $zero, L_8000ED50
    if (ctx->r2 != 0) {
        // 0x8000ED18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000ED50;
    }
    // 0x8000ED18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000ED1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000ED20: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000ED24: j           L_8000ED48
    // 0x8000ED28: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
        goto L_8000ED48;
    // 0x8000ED28: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000ED2C:
    // 0x8000ED2C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000ED30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000ED34: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000ED38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000ED3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000ED40: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000ED44: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000ED48:
    // 0x8000ED48: beq         $v0, $zero, L_8000ED58
    if (ctx->r2 == 0) {
        // 0x8000ED4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000ED58;
    }
    // 0x8000ED4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000ED50:
    // 0x8000ED50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000ED54: sb          $v0, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = ctx->r2;
L_8000ED58:
    // 0x8000ED58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000ED5C: lbu         $v0, -0xBE6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE6);
    // 0x8000ED60: bne         $v0, $zero, L_8000ED88
    if (ctx->r2 != 0) {
        // 0x8000ED64: nop
    
            goto L_8000ED88;
    }
    // 0x8000ED64: nop

    // 0x8000ED68: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000ED6C: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000ED70: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000ED74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000ED78: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000ED7C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000ED80: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000ED84: nop
    
            goto L_8000FDA0;
    }
    // 0x8000ED84: nop

L_8000ED88:
    // 0x8000ED88: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000ED8C: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000ED90: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000ED94: addiu       $v0, $zero, 0x257
    ctx->r2 = ADD32(0, 0X257);
    // 0x8000ED98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000ED9C: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x8000EDA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EDA4: sb          $zero, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = 0;
    // 0x8000EDA8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000EDAC: sw          $v0, 0x3F54($at)
    MEM_W(0X3F54, ctx->r1) = ctx->r2;
    // 0x8000EDB0: j           L_8000FA70
    // 0x8000EDB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8000FA70;
    // 0x8000EDB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000EDB8:
    // 0x8000EDB8: jal         0x80008CDC
    // 0x8000EDBC: nop

    func_80008CDC(rdram, ctx);
        goto after_24;
    // 0x8000EDBC: nop

    after_24:
    // 0x8000EDC0: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EDC4: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EDC4: nop

    // 0x8000EDC8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000EDCC: lw          $v0, 0x3F54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F54);
    // 0x8000EDD0: beq         $v0, $zero, L_8000EFA0
    if (ctx->r2 == 0) {
        // 0x8000EDD4: addiu       $v0, $zero, 0x78
        ctx->r2 = ADD32(0, 0X78);
            goto L_8000EFA0;
    }
    // 0x8000EDD4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000EDD8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EDDC: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000EDE0: beq         $v0, $zero, L_8000EEEC
    if (ctx->r2 == 0) {
        // 0x8000EDE4: nop
    
            goto L_8000EEEC;
    }
    // 0x8000EDE4: nop

    // 0x8000EDE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EDEC: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000EDF0: beq         $v0, $zero, L_8000EEEC
    if (ctx->r2 == 0) {
        // 0x8000EDF4: nop
    
            goto L_8000EEEC;
    }
    // 0x8000EDF4: nop

    // 0x8000EDF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EDFC: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000EE00: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000EE04: bne         $v0, $zero, L_8000EE34
    if (ctx->r2 != 0) {
        // 0x8000EE08: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_8000EE34;
    }
    // 0x8000EE08: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8000EE0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EE10: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000EE14: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EE18: sh          $v1, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r3;
    // 0x8000EE1C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000EE20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EE24: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8000EE28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EE2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EE30: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000EE34:
    // 0x8000EE34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000EE38: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000EE3C: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EE40: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EE40: nop

    // 0x8000EE44: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000EE48: lbu         $v0, -0x7A6F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6F);
    // 0x8000EE4C: bne         $v0, $zero, L_8000EEA0
    if (ctx->r2 != 0) {
        // 0x8000EE50: nop
    
            goto L_8000EEA0;
    }
    // 0x8000EE50: nop

    // 0x8000EE54: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EE58: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000EE5C: beq         $v0, $zero, L_8000EEA0
    if (ctx->r2 == 0) {
        // 0x8000EE60: nop
    
            goto L_8000EEA0;
    }
    // 0x8000EE60: nop

    // 0x8000EE64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000EE68: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000EE6C: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8000EE70: beq         $v0, $zero, L_8000EEA0
    if (ctx->r2 == 0) {
        // 0x8000EE74: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8000EEA0;
    }
    // 0x8000EE74: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000EE78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EE7C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000EE80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000EE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000EE88: sb          $v0, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r2;
    // 0x8000EE8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000EE90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EE94: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000EE98: jal         0x800064C0
    // 0x8000EE9C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_25;
    // 0x8000EE9C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
L_8000EEA0:
    // 0x8000EEA0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000EEA4: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000EEA8: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EEAC: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EEAC: nop

    // 0x8000EEB0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000EEB4: lbu         $v0, -0x7A07($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A07);
    // 0x8000EEB8: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EEBC: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EEBC: nop

    // 0x8000EEC0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EEC4: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000EEC8: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000EECC: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EECC: nop

    // 0x8000EED0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000EED4: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000EED8: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8000EEDC: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000EEE0: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8000FDA0;
    }
    // 0x8000EEE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000EEE4: j           L_8000FC14
    // 0x8000EEE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8000FC14;
    // 0x8000EEE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000EEEC:
    // 0x8000EEEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EEF0: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000EEF4: beq         $v0, $zero, L_8000EF24
    if (ctx->r2 == 0) {
        // 0x8000EEF8: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_8000EF24;
    }
    // 0x8000EEF8: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8000EEFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EF00: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000EF04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EF08: sh          $v1, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r3;
    // 0x8000EF0C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000EF10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EF14: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8000EF18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EF1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EF20: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000EF24:
    // 0x8000EF24: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8000EF28: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8000EF2C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8000EF30: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8000EF34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000EF38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000EF3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000EF40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000EF44: lbu         $v0, -0x7A6F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7A6F);
    // 0x8000EF48: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EF4C: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_8000FDA0;
    }
    // 0x8000EF4C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000EF50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000EF54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000EF58: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000EF5C: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8000EF60: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000EF64: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000FDA0;
    }
    // 0x8000EF64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000EF68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000EF6C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000EF70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000EF74: sb          $v1, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r3;
    // 0x8000EF78: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000EF7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EF80: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8000EF84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EF88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EF8C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000EF90: jal         0x800064C0
    // 0x8000EF94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_26;
    // 0x8000EF94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_26:
    // 0x8000EF98: j           L_8000FDA0
    // 0x8000EF9C: nop

        goto L_8000FDA0;
    // 0x8000EF9C: nop

L_8000EFA0:
    // 0x8000EFA0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000EFA4: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000EFA8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000EFAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EFB0: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000EFB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000EFB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000EFBC: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000EFC0: j           L_8000FA70
    // 0x8000EFC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8000FA70;
    // 0x8000EFC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000EFC8:
    // 0x8000EFC8: jal         0x80008CDC
    // 0x8000EFCC: nop

    func_80008CDC(rdram, ctx);
        goto after_27;
    // 0x8000EFCC: nop

    after_27:
    // 0x8000EFD0: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000EFD4: nop
    
            goto L_8000FDA0;
    }
    // 0x8000EFD4: nop

    // 0x8000EFD8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000EFDC: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000EFE0: bne         $v0, $zero, L_8000F058
    if (ctx->r2 != 0) {
        // 0x8000EFE4: nop
    
            goto L_8000F058;
    }
    // 0x8000EFE4: nop

    // 0x8000EFE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000EFEC: addiu       $a1, $a1, 0x7B74
    ctx->r5 = ADD32(ctx->r5, 0X7B74);
    // 0x8000EFF0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8000EFF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000EFF8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000EFFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000F000: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F004: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_8000FDA0;
    }
    // 0x8000F004: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8000F008: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F00C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000F010: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F014: lb          $a0, 0x25A0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X25A0);
    // 0x8000F018: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x8000F01C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F020: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F024: beq         $a0, $zero, L_8000FDA0
    if (ctx->r4 == 0) {
        // 0x8000F028: sb          $v0, 0x7B71($at)
        MEM_B(0X7B71, ctx->r1) = ctx->r2;
            goto L_8000FDA0;
    }
    // 0x8000F028: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000F02C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F030: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000F034: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000F038: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F038: nop

    // 0x8000F03C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000F040: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000F044: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F048: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_8000FDA0;
    }
    // 0x8000F048: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8000F04C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F050: j           L_8000FCEC
    // 0x8000F054: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_8000FCEC;
    // 0x8000F054: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000F058:
    // 0x8000F058: jal         0x8002CFB8
    // 0x8000F05C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_28;
    // 0x8000F05C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_28:
    // 0x8000F060: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000F064: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F064: nop

    // 0x8000F068: jal         0x80031BEC
    // 0x8000F06C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    func_80031BEC(rdram, ctx);
        goto after_29;
    // 0x8000F06C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_29:
    // 0x8000F070: jal         0x80053390
    // 0x8000F074: nop

    func_80053390(rdram, ctx);
        goto after_30;
    // 0x8000F074: nop

    after_30:
    // 0x8000F078: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F07C: lw          $v1, 0x7BBC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BBC);
    // 0x8000F080: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F088: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F08C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8000F090: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F094: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000F098: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F09C: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
    // 0x8000F0A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0A4: sb          $zero, 0x7BA2($at)
    MEM_B(0X7BA2, ctx->r1) = 0;
    // 0x8000F0A8: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x8000F0AC: bne         $v0, $zero, L_8000F0CC
    if (ctx->r2 != 0) {
        // 0x8000F0B0: addiu       $v0, $zero, -0x80
        ctx->r2 = ADD32(0, -0X80);
            goto L_8000F0CC;
    }
    // 0x8000F0B0: addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // 0x8000F0B4: addiu       $v0, $zero, -0x7F
    ctx->r2 = ADD32(0, -0X7F);
    // 0x8000F0B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0BC: sb          $zero, 0x79F0($at)
    MEM_B(0X79F0, ctx->r1) = 0;
    // 0x8000F0C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0C4: j           L_8000F0DC
    // 0x8000F0C8: sb          $v0, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r2;
        goto L_8000F0DC;
    // 0x8000F0C8: sb          $v0, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r2;
L_8000F0CC:
    // 0x8000F0CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0D0: sb          $zero, 0x25A0($at)
    MEM_B(0X25A0, ctx->r1) = 0;
    // 0x8000F0D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0D8: sb          $v0, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = ctx->r2;
L_8000F0DC:
    // 0x8000F0DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F0E0: addiu       $a0, $a0, 0x7B98
    ctx->r4 = ADD32(ctx->r4, 0X7B98);
    // 0x8000F0E4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000F0E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F0EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0F0: sb          $zero, 0x25F3($at)
    MEM_B(0X25F3, ctx->r1) = 0;
    // 0x8000F0F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F0F8: sb          $zero, 0x7A43($at)
    MEM_B(0X7A43, ctx->r1) = 0;
    // 0x8000F0FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F100: sb          $zero, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = 0;
    // 0x8000F104: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000F108: bne         $v1, $v0, L_8000F164
    if (ctx->r3 != ctx->r2) {
        // 0x8000F10C: sb          $zero, -0x4FB0($at)
        MEM_B(-0X4FB0, ctx->r1) = 0;
            goto L_8000F164;
    }
    // 0x8000F10C: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    // 0x8000F110: jal         0x80031BEC
    // 0x8000F114: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    func_80031BEC(rdram, ctx);
        goto after_31;
    // 0x8000F114: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    after_31:
    // 0x8000F118: jal         0x80041E74
    // 0x8000F11C: nop

    func_80041E74(rdram, ctx);
        goto after_32;
    // 0x8000F11C: nop

    after_32:
    // 0x8000F120: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8000F124: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000F128: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000F12C: addiu       $a0, $a0, 0x3F5C
    ctx->r4 = ADD32(ctx->r4, 0X3F5C);
    // 0x8000F130: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8000F134: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F138: sb          $zero, -0xBE5($at)
    MEM_B(-0XBE5, ctx->r1) = 0;
    // 0x8000F13C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F140: sb          $zero, -0xBE4($at)
    MEM_B(-0XBE4, ctx->r1) = 0;
    // 0x8000F144: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F148: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000F14C:
    // 0x8000F14C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8000F150: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000F154: bgez        $v1, L_8000F14C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000F158: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8000F14C;
    }
    // 0x8000F158: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000F15C: j           L_8000F1A0
    // 0x8000F160: nop

        goto L_8000F1A0;
    // 0x8000F160: nop

L_8000F164:
    // 0x8000F164: jal         0x80031BEC
    // 0x8000F168: nop

    func_80031BEC(rdram, ctx);
        goto after_33;
    // 0x8000F168: nop

    after_33:
    // 0x8000F16C: jal         0x80041668
    // 0x8000F170: nop

    func_80041668(rdram, ctx);
        goto after_34;
    // 0x8000F170: nop

    after_34:
    // 0x8000F174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F178: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F17C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000F180: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8000F184: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000F188: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000F18C: addiu       $v0, $v0, 0x3F5C
    ctx->r2 = ADD32(ctx->r2, 0X3F5C);
L_8000F190:
    // 0x8000F190: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8000F194: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000F198: bgez        $v1, L_8000F190
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000F19C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000F190;
    }
    // 0x8000F19C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8000F1A0:
    // 0x8000F1A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F1A4: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x8000F1A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F1AC: j           L_8000FDA0
    // 0x8000F1B0: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
        goto L_8000FDA0;
    // 0x8000F1B0: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
L_8000F1B4:
    // 0x8000F1B4: jal         0x80008CDC
    // 0x8000F1B8: nop

    func_80008CDC(rdram, ctx);
        goto after_35;
    // 0x8000F1B8: nop

    after_35:
    // 0x8000F1BC: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F1C0: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F1C0: nop

    // 0x8000F1C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F1C8: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F1CC: beq         $v0, $zero, L_8000F208
    if (ctx->r2 == 0) {
        // 0x8000F1D0: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000F208;
    }
    // 0x8000F1D0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000F1D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F1D8: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000F1DC: beq         $v0, $zero, L_8000F208
    if (ctx->r2 == 0) {
        // 0x8000F1E0: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000F208;
    }
    // 0x8000F1E0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000F1E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F1E8: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000F1EC: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000F1F0: bne         $v0, $zero, L_8000F22C
    if (ctx->r2 != 0) {
        // 0x8000F1F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000F22C;
    }
    // 0x8000F1F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F1F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F1FC: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000F200: j           L_8000F224
    // 0x8000F204: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
        goto L_8000F224;
    // 0x8000F204: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000F208:
    // 0x8000F208: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000F20C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F210: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000F214: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F218: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F21C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000F220: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
L_8000F224:
    // 0x8000F224: beq         $v0, $zero, L_8000F234
    if (ctx->r2 == 0) {
        // 0x8000F228: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000F234;
    }
    // 0x8000F228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F22C:
    // 0x8000F22C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F230: sb          $v0, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = ctx->r2;
L_8000F234:
    // 0x8000F234: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000F238: lbu         $v0, -0xBE6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE6);
    // 0x8000F23C: bne         $v0, $zero, L_8000F264
    if (ctx->r2 != 0) {
        // 0x8000F240: nop
    
            goto L_8000F264;
    }
    // 0x8000F240: nop

    // 0x8000F244: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F248: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000F24C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F250: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000F254: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000F258: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000F25C: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F260: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F260: nop

L_8000F264:
    // 0x8000F264: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F268: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F26C: beq         $v0, $zero, L_8000F2B4
    if (ctx->r2 == 0) {
        // 0x8000F270: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8000F2B4;
    }
    // 0x8000F270: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000F274: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F278: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000F27C: beq         $v0, $zero, L_8000F2B0
    if (ctx->r2 == 0) {
        // 0x8000F280: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8000F2B0;
    }
    // 0x8000F280: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000F284: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F288: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000F28C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000F290: jal         0x80031BEC
    // 0x8000F294: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_36;
    // 0x8000F294: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
    after_36:
    // 0x8000F298: jal         0x800437FC
    // 0x8000F29C: nop

    func_800437FC(rdram, ctx);
        goto after_37;
    // 0x8000F29C: nop

    after_37:
    // 0x8000F2A0: jal         0x80054350
    // 0x8000F2A4: nop

    func_80054350(rdram, ctx);
        goto after_38;
    // 0x8000F2A4: nop

    after_38:
    // 0x8000F2A8: j           L_8000F2D8
    // 0x8000F2AC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_8000F2D8;
    // 0x8000F2AC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8000F2B0:
    // 0x8000F2B0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8000F2B4:
    // 0x8000F2B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F2B8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000F2BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000F2C0: sb          $zero, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = 0;
L_8000F2C4:
    // 0x8000F2C4: jal         0x80031BEC
    // 0x8000F2C8: nop

    func_80031BEC(rdram, ctx);
        goto after_39;
    // 0x8000F2C8: nop

    after_39:
    // 0x8000F2CC: jal         0x80042954
    // 0x8000F2D0: nop

    func_80042954(rdram, ctx);
        goto after_40;
    // 0x8000F2D0: nop

    after_40:
    // 0x8000F2D4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8000F2D8:
    // 0x8000F2D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F2DC: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000F2E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F2E4: j           L_8000FDA0
    // 0x8000F2E8: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
        goto L_8000FDA0;
    // 0x8000F2E8: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
L_8000F2EC:
    // 0x8000F2EC: jal         0x80008CDC
    // 0x8000F2F0: nop

    func_80008CDC(rdram, ctx);
        goto after_41;
    // 0x8000F2F0: nop

    after_41:
    // 0x8000F2F4: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F2F8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000FDA0;
    }
    // 0x8000F2F8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000F2FC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000F300: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F304: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000F308: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F30C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F310: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000F314: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000F318: beq         $v0, $zero, L_8000F328
    if (ctx->r2 == 0) {
        // 0x8000F31C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000F328;
    }
    // 0x8000F31C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F320: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F324: sb          $v0, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = ctx->r2;
L_8000F328:
    // 0x8000F328: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000F32C: lbu         $v0, -0xBE6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE6);
    // 0x8000F330: bne         $v0, $zero, L_8000F358
    if (ctx->r2 != 0) {
        // 0x8000F334: nop
    
            goto L_8000F358;
    }
    // 0x8000F334: nop

    // 0x8000F338: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F33C: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000F340: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000F344: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000F348: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000F34C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000F350: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F354: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F354: nop

L_8000F358:
    // 0x8000F358: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F35C: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000F360: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000F364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F368: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F36C: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
    // 0x8000F370: addiu       $v0, $zero, 0x257
    ctx->r2 = ADD32(0, 0X257);
    // 0x8000F374: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F378: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x8000F37C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000F380: sw          $v0, 0x3F54($at)
    MEM_W(0X3F54, ctx->r1) = ctx->r2;
    // 0x8000F384: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F388: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
    // 0x8000F38C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F390: jal         0x80053390
    // 0x8000F394: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80053390(rdram, ctx);
        goto after_42;
    // 0x8000F394: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_42:
    // 0x8000F398: j           L_8000FDA0
    // 0x8000F39C: nop

        goto L_8000FDA0;
    // 0x8000F39C: nop

L_8000F3A0:
    // 0x8000F3A0: jal         0x80008CDC
    // 0x8000F3A4: nop

    func_80008CDC(rdram, ctx);
        goto after_43;
    // 0x8000F3A4: nop

    after_43:
    // 0x8000F3A8: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F3AC: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F3AC: nop

    // 0x8000F3B0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000F3B4: lw          $v0, 0x3F54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F54);
    // 0x8000F3B8: beq         $v0, $zero, L_8000F614
    if (ctx->r2 == 0) {
        // 0x8000F3BC: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8000F614;
    }
    // 0x8000F3BC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8000F3C0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8000F3C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F3C8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8000F3CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000F3D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8000F3D4: lhu         $v1, -0x33C8($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8000F3D8: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8000F3DC: beq         $v0, $zero, L_8000F408
    if (ctx->r2 == 0) {
        // 0x8000F3E0: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8000F408;
    }
    // 0x8000F3E0: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000F3E4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F3E8: addiu       $a0, $a0, 0x7B76
    ctx->r4 = ADD32(ctx->r4, 0X7B76);
    // 0x8000F3EC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8000F3F0: blez        $v0, L_8000F400
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F3F4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8000F400;
    }
    // 0x8000F3F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000F3F8: j           L_8000F42C
    // 0x8000F3FC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8000F42C;
    // 0x8000F3FC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_8000F400:
    // 0x8000F400: j           L_8000F42C
    // 0x8000F404: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000F42C;
    // 0x8000F404: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000F408:
    // 0x8000F408: beq         $v0, $zero, L_8000F448
    if (ctx->r2 == 0) {
        // 0x8000F40C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8000F448;
    }
    // 0x8000F40C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000F410: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F414: addiu       $a0, $a0, 0x7B76
    ctx->r4 = ADD32(ctx->r4, 0X7B76);
    // 0x8000F418: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8000F41C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8000F420: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000F424: beq         $v0, $zero, L_8000F434
    if (ctx->r2 == 0) {
        // 0x8000F428: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000F434;
    }
    // 0x8000F428: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8000F42C:
    // 0x8000F42C: j           L_8000F438
    // 0x8000F430: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_8000F438;
    // 0x8000F430: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8000F434:
    // 0x8000F434: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8000F438:
    // 0x8000F438: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8000F43C: jal         0x8000637C
    // 0x8000F440: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8000637C(rdram, ctx);
        goto after_44;
    // 0x8000F440: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_44:
    // 0x8000F444: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8000F448:
    // 0x8000F448: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8000F44C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F450: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000F454: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000F458: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000F45C: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8000F460: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8000F464: beq         $v0, $zero, L_8000F5D0
    if (ctx->r2 == 0) {
        // 0x8000F468: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8000F5D0;
    }
    // 0x8000F468: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000F46C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F470: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000F474: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F478: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F47C: jal         0x8000637C
    // 0x8000F480: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_45;
    // 0x8000F480: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_45:
    // 0x8000F484: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F488: lb          $v1, 0xB60($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB60);
    // 0x8000F48C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F490: lbu         $a0, 0x25FA($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X25FA);
    // 0x8000F494: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000F498: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F49C: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000F4A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F4A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F4A8: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F4AC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000F4B0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000F4B4: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8000F4B8: lw          $a1, -0xE28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XE28);
    // 0x8000F4BC: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8000F4C0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000F4C4: bne         $v0, $zero, L_8000F4E4
    if (ctx->r2 != 0) {
        // 0x8000F4C8: nop
    
            goto L_8000F4E4;
    }
    // 0x8000F4C8: nop

    // 0x8000F4CC: bne         $a0, $zero, L_8000F544
    if (ctx->r4 != 0) {
        // 0x8000F4D0: nop
    
            goto L_8000F544;
    }
    // 0x8000F4D0: nop

    // 0x8000F4D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F4D8: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000F4DC: beq         $v0, $zero, L_8000F544
    if (ctx->r2 == 0) {
        // 0x8000F4E0: nop
    
            goto L_8000F544;
    }
    // 0x8000F4E0: nop

L_8000F4E4:
    // 0x8000F4E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F4E8: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F4EC: beq         $v0, $zero, L_8000F51C
    if (ctx->r2 == 0) {
        // 0x8000F4F0: nop
    
            goto L_8000F51C;
    }
    // 0x8000F4F0: nop

    // 0x8000F4F4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F4F8: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F4FC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F500: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F504: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F508: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F50C: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
    // 0x8000F510: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F514: j           L_8000F7B8
    // 0x8000F518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7B8;
    // 0x8000F518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F51C:
    // 0x8000F51C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F520: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F524: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F528: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F52C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F530: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F534: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
    // 0x8000F538: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F53C: j           L_8000F7F8
    // 0x8000F540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7F8;
    // 0x8000F540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F544:
    // 0x8000F544: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F548: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000F54C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F550: beq         $v1, $v0, L_8000F570
    if (ctx->r3 == ctx->r2) {
        // 0x8000F554: nop
    
            goto L_8000F570;
    }
    // 0x8000F554: nop

    // 0x8000F558: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F55C: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F560: beq         $v0, $zero, L_8000F748
    if (ctx->r2 == 0) {
        // 0x8000F564: nop
    
            goto L_8000F748;
    }
    // 0x8000F564: nop

    // 0x8000F568: j           L_8000F718
    // 0x8000F56C: nop

        goto L_8000F718;
    // 0x8000F56C: nop

L_8000F570:
    // 0x8000F570: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F574: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F578: beq         $v0, $zero, L_8000F5A8
    if (ctx->r2 == 0) {
        // 0x8000F57C: nop
    
            goto L_8000F5A8;
    }
    // 0x8000F57C: nop

    // 0x8000F580: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F584: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F588: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F58C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F590: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F594: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F598: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
    // 0x8000F59C: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F5A0: j           L_8000F7B8
    // 0x8000F5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7B8;
    // 0x8000F5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F5A8:
    // 0x8000F5A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F5AC: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F5B0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F5B4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F5B8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F5BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F5C0: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
    // 0x8000F5C4: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F5C8: j           L_8000F7F8
    // 0x8000F5CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7F8;
    // 0x8000F5CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F5D0:
    // 0x8000F5D0: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x8000F5D4: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000F5D8: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8000FDA0;
    }
    // 0x8000F5D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000F5DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000F5E0: addiu       $a1, $a1, 0x7B71
    ctx->r5 = ADD32(ctx->r5, 0X7B71);
    // 0x8000F5E4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000F5E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F5EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000F5F0: sb          $v0, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r2;
    // 0x8000F5F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F5F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F5FC: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F600: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F604: jal         0x800064C0
    // 0x8000F608: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    func_800064C0(rdram, ctx);
        goto after_46;
    // 0x8000F608: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    after_46:
    // 0x8000F60C: j           L_8000FDA0
    // 0x8000F610: nop

        goto L_8000FDA0;
    // 0x8000F610: nop

L_8000F614:
    // 0x8000F614: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F618: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000F61C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F620: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8000F624: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000F628: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000F62C: jal         0x8000637C
    // 0x8000F630: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_47;
    // 0x8000F630: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_47:
    // 0x8000F634: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F638: lb          $v1, 0xB60($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB60);
    // 0x8000F63C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F640: lbu         $a0, 0x25FA($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X25FA);
    // 0x8000F644: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000F648: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F64C: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000F650: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F654: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F658: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F65C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000F660: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000F664: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8000F668: lw          $a1, -0xE28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XE28);
    // 0x8000F66C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8000F670: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000F674: bne         $v0, $zero, L_8000F694
    if (ctx->r2 != 0) {
        // 0x8000F678: nop
    
            goto L_8000F694;
    }
    // 0x8000F678: nop

    // 0x8000F67C: bne         $a0, $zero, L_8000F6F4
    if (ctx->r4 != 0) {
        // 0x8000F680: nop
    
            goto L_8000F6F4;
    }
    // 0x8000F680: nop

    // 0x8000F684: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F688: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000F68C: beq         $v0, $zero, L_8000F6F4
    if (ctx->r2 == 0) {
        // 0x8000F690: nop
    
            goto L_8000F6F4;
    }
    // 0x8000F690: nop

L_8000F694:
    // 0x8000F694: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F698: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F69C: beq         $v0, $zero, L_8000F6CC
    if (ctx->r2 == 0) {
        // 0x8000F6A0: nop
    
            goto L_8000F6CC;
    }
    // 0x8000F6A0: nop

    // 0x8000F6A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F6A8: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F6AC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F6B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F6B4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F6B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F6BC: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
    // 0x8000F6C0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F6C4: j           L_8000F7B8
    // 0x8000F6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7B8;
    // 0x8000F6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F6CC:
    // 0x8000F6CC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F6D0: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F6D4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F6D8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F6DC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F6E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F6E4: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
    // 0x8000F6E8: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F6EC: j           L_8000F7F8
    // 0x8000F6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F7F8;
    // 0x8000F6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F6F4:
    // 0x8000F6F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F6F8: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000F6FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F700: beq         $v1, $v0, L_8000F784
    if (ctx->r3 == ctx->r2) {
        // 0x8000F704: nop
    
            goto L_8000F784;
    }
    // 0x8000F704: nop

    // 0x8000F708: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F70C: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F710: beq         $v0, $zero, L_8000F748
    if (ctx->r2 == 0) {
        // 0x8000F714: nop
    
            goto L_8000F748;
    }
    // 0x8000F714: nop

L_8000F718:
    // 0x8000F718: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8000F71C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F720: sb          $v0, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r2;
    // 0x8000F724: lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3);
    // 0x8000F728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F72C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F730: sb          $v0, 0x2615($at)
    MEM_B(0X2615, ctx->r1) = ctx->r2;
    // 0x8000F734: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F738: sb          $v0, 0x25E8($at)
    MEM_B(0X25E8, ctx->r1) = ctx->r2;
    // 0x8000F73C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F740: j           L_8000F774
    // 0x8000F744: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
        goto L_8000F774;
    // 0x8000F744: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
L_8000F748:
    // 0x8000F748: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8000F74C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F750: sb          $v0, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r2;
    // 0x8000F754: lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3);
    // 0x8000F758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F75C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F760: sb          $v0, 0x7A65($at)
    MEM_B(0X7A65, ctx->r1) = ctx->r2;
    // 0x8000F764: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F768: sb          $v0, 0x7A38($at)
    MEM_B(0X7A38, ctx->r1) = ctx->r2;
    // 0x8000F76C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F770: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
L_8000F774:
    // 0x8000F774: jal         0x8000C1F4
    // 0x8000F778: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8000C1F4(rdram, ctx);
        goto after_48;
    // 0x8000F778: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_48:
    // 0x8000F77C: j           L_8000FDA0
    // 0x8000F780: nop

        goto L_8000FDA0;
    // 0x8000F780: nop

L_8000F784:
    // 0x8000F784: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F788: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F78C: beq         $v0, $zero, L_8000F7D4
    if (ctx->r2 == 0) {
        // 0x8000F790: nop
    
            goto L_8000F7D4;
    }
    // 0x8000F790: nop

    // 0x8000F794: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F798: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F79C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F7A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F7A4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F7A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7AC: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
    // 0x8000F7B0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F7B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F7B8:
    // 0x8000F7B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7BC: sb          $a0, 0x2615($at)
    MEM_B(0X2615, ctx->r1) = ctx->r4;
    // 0x8000F7C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7C4: sb          $v0, 0x25E8($at)
    MEM_B(0X25E8, ctx->r1) = ctx->r2;
    // 0x8000F7C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7CC: j           L_8000F810
    // 0x8000F7D0: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
        goto L_8000F810;
    // 0x8000F7D0: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
L_8000F7D4:
    // 0x8000F7D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000F7D8: lh          $a0, 0x7B76($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7B76);
    // 0x8000F7DC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8000F7E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000F7E4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F7E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7EC: sb          $v1, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = ctx->r3;
    // 0x8000F7F0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F7F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F7F8:
    // 0x8000F7F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F7FC: sb          $a0, 0x7A65($at)
    MEM_B(0X7A65, ctx->r1) = ctx->r4;
    // 0x8000F800: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F804: sb          $v0, 0x7A38($at)
    MEM_B(0X7A38, ctx->r1) = ctx->r2;
    // 0x8000F808: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F80C: sb          $v1, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = ctx->r3;
L_8000F810:
    // 0x8000F810: jal         0x8000C1F4
    // 0x8000F814: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000C1F4(rdram, ctx);
        goto after_49;
    // 0x8000F814: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_49:
    // 0x8000F818: j           L_8000FDA0
    // 0x8000F81C: nop

        goto L_8000FDA0;
    // 0x8000F81C: nop

L_8000F820:
    // 0x8000F820: jal         0x80008CDC
    // 0x8000F824: nop

    func_80008CDC(rdram, ctx);
        goto after_50;
    // 0x8000F824: nop

    after_50:
    // 0x8000F828: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F82C: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F82C: nop

    // 0x8000F830: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000F834: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000F838: bne         $v0, $zero, L_8000F888
    if (ctx->r2 != 0) {
        // 0x8000F83C: nop
    
            goto L_8000F888;
    }
    // 0x8000F83C: nop

    // 0x8000F840: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000F844: addiu       $a1, $a1, 0x7B74
    ctx->r5 = ADD32(ctx->r5, 0X7B74);
    // 0x8000F848: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8000F84C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000F850: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000F854: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000F858: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F85C: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_8000FDA0;
    }
    // 0x8000F85C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000F860: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F864: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000F868: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000F86C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F870: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F874: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x8000F878: jal         0x800064C0
    // 0x8000F87C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_51;
    // 0x8000F87C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_51:
    // 0x8000F880: j           L_8000FDA0
    // 0x8000F884: nop

        goto L_8000FDA0;
    // 0x8000F884: nop

L_8000F888:
    // 0x8000F888: jal         0x8002CFB8
    // 0x8000F88C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_52;
    // 0x8000F88C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_52:
    // 0x8000F890: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000F894: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F894: nop

    // 0x8000F898: jal         0x80031BEC
    // 0x8000F89C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    func_80031BEC(rdram, ctx);
        goto after_53;
    // 0x8000F89C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_53:
    // 0x8000F8A0: jal         0x80053390
    // 0x8000F8A4: nop

    func_80053390(rdram, ctx);
        goto after_54;
    // 0x8000F8A4: nop

    after_54:
    // 0x8000F8A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F8AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F8B0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F8B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F8B8: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000F8BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000F8C0: j           L_8000FD30
    // 0x8000F8C4: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
        goto L_8000FD30;
    // 0x8000F8C4: sb          $zero, -0xBE8($at)
    MEM_B(-0XBE8, ctx->r1) = 0;
L_8000F8C8:
    // 0x8000F8C8: jal         0x80008CDC
    // 0x8000F8CC: nop

    func_80008CDC(rdram, ctx);
        goto after_55;
    // 0x8000F8CC: nop

    after_55:
    // 0x8000F8D0: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F8D4: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F8D4: nop

    // 0x8000F8D8: jal         0x8002CFB8
    // 0x8000F8DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_56;
    // 0x8000F8DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_56:
    // 0x8000F8E0: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000F8E4: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F8E4: nop

    // 0x8000F8E8: jal         0x80031BEC
    // 0x8000F8EC: nop

    func_80031BEC(rdram, ctx);
        goto after_57;
    // 0x8000F8EC: nop

    after_57:
    // 0x8000F8F0: jal         0x80053390
    // 0x8000F8F4: nop

    func_80053390(rdram, ctx);
        goto after_58;
    // 0x8000F8F4: nop

    after_58:
    // 0x8000F8F8: jal         0x80006998
    // 0x8000F8FC: nop

    func_80006998(rdram, ctx);
        goto after_59;
    // 0x8000F8FC: nop

    after_59:
    // 0x8000F900: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F904: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000F908: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F90C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F910: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F914: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000F918: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F91C: sb          $zero, 0x7B9C($at)
    MEM_B(0X7B9C, ctx->r1) = 0;
    // 0x8000F920: beq         $v1, $a0, L_8000FD90
    if (ctx->r3 == ctx->r4) {
        // 0x8000F924: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000FD90;
    }
    // 0x8000F924: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000F928: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F92C: lb          $v0, 0x25FA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25FA);
    // 0x8000F930: beq         $v0, $a0, L_8000F950
    if (ctx->r2 == ctx->r4) {
        // 0x8000F934: nop
    
            goto L_8000F950;
    }
    // 0x8000F934: nop

    // 0x8000F938: bne         $v0, $zero, L_8000F990
    if (ctx->r2 != 0) {
        // 0x8000F93C: nop
    
            goto L_8000F990;
    }
    // 0x8000F93C: nop

    // 0x8000F940: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F944: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000F948: beq         $v0, $zero, L_8000F990
    if (ctx->r2 == 0) {
        // 0x8000F94C: nop
    
            goto L_8000F990;
    }
    // 0x8000F94C: nop

L_8000F950:
    // 0x8000F950: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F954: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000F958: beq         $v0, $zero, L_8000F978
    if (ctx->r2 == 0) {
        // 0x8000F95C: nop
    
            goto L_8000F978;
    }
    // 0x8000F95C: nop

    // 0x8000F960: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F964: lbu         $v0, 0x260D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X260D);
    // 0x8000F968: beq         $v0, $zero, L_8000F988
    if (ctx->r2 == 0) {
        // 0x8000F96C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000F988;
    }
    // 0x8000F96C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F970: j           L_8000FD90
    // 0x8000F974: nop

        goto L_8000FD90;
    // 0x8000F974: nop

L_8000F978:
    // 0x8000F978: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000F97C: lbu         $v0, 0x7A5D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A5D);
    // 0x8000F980: bne         $v0, $zero, L_8000FD90
    if (ctx->r2 != 0) {
        // 0x8000F984: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000FD90;
    }
    // 0x8000F984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F988:
    // 0x8000F988: j           L_8000FD90
    // 0x8000F98C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_8000FD90;
    // 0x8000F98C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8000F990:
    // 0x8000F990: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000F994: lb          $v1, 0x25A0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25A0);
    // 0x8000F998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F99C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F9A0: sb          $v0, 0x7B9C($at)
    MEM_B(0X7B9C, ctx->r1) = ctx->r2;
    // 0x8000F9A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F9A8: sb          $zero, 0x7A58($at)
    MEM_B(0X7A58, ctx->r1) = 0;
    // 0x8000F9AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F9B0: sb          $zero, 0x2608($at)
    MEM_B(0X2608, ctx->r1) = 0;
    // 0x8000F9B4: bne         $v1, $zero, L_8000F9C0
    if (ctx->r3 != 0) {
        // 0x8000F9B8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000F9C0;
    }
    // 0x8000F9B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000F9BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000F9C0:
    // 0x8000F9C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000F9C4: jal         0x8002CAB4
    // 0x8000F9C8: sb          $v0, 0x5584($at)
    MEM_B(0X5584, ctx->r1) = ctx->r2;
    func_8002CAB4(rdram, ctx);
        goto after_60;
    // 0x8000F9C8: sb          $v0, 0x5584($at)
    MEM_B(0X5584, ctx->r1) = ctx->r2;
    after_60:
    // 0x8000F9CC: j           L_8000FDA0
    // 0x8000F9D0: nop

        goto L_8000FDA0;
    // 0x8000F9D0: nop

L_8000F9D4:
    // 0x8000F9D4: jal         0x80008CDC
    // 0x8000F9D8: nop

    func_80008CDC(rdram, ctx);
        goto after_61;
    // 0x8000F9D8: nop

    after_61:
    // 0x8000F9DC: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000F9E0: nop
    
            goto L_8000FDA0;
    }
    // 0x8000F9E0: nop

    // 0x8000F9E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F9E8: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000F9EC: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000F9F0: bne         $v0, $zero, L_8000FA0C
    if (ctx->r2 != 0) {
        // 0x8000F9F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000FA0C;
    }
    // 0x8000F9F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F9F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000F9FC: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000FA00: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000FA04: beq         $v0, $zero, L_8000FA14
    if (ctx->r2 == 0) {
        // 0x8000FA08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000FA14;
    }
    // 0x8000FA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000FA0C:
    // 0x8000FA0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000FA10: sb          $v0, -0xBE6($at)
    MEM_B(-0XBE6, ctx->r1) = ctx->r2;
L_8000FA14:
    // 0x8000FA14: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000FA18: lbu         $v0, -0xBE6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE6);
    // 0x8000FA1C: bne         $v0, $zero, L_8000FA44
    if (ctx->r2 != 0) {
        // 0x8000FA20: nop
    
            goto L_8000FA44;
    }
    // 0x8000FA20: nop

    // 0x8000FA24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FA28: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000FA2C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000FA30: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000FA34: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8000FA38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000FA3C: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FA40: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FA40: nop

L_8000FA44:
    // 0x8000FA44: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FA48: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000FA4C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000FA50: addiu       $v0, $zero, 0x257
    ctx->r2 = ADD32(0, 0X257);
    // 0x8000FA54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FA58: sh          $zero, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = 0;
    // 0x8000FA5C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000FA60: sw          $v0, 0x3F54($at)
    MEM_W(0X3F54, ctx->r1) = ctx->r2;
    // 0x8000FA64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FA68: sh          $zero, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = 0;
    // 0x8000FA6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000FA70:
    // 0x8000FA70: j           L_8000FDA0
    // 0x8000FA74: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
        goto L_8000FDA0;
    // 0x8000FA74: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8000FA78:
    // 0x8000FA78: jal         0x80008CDC
    // 0x8000FA7C: nop

    func_80008CDC(rdram, ctx);
        goto after_62;
    // 0x8000FA7C: nop

    after_62:
    // 0x8000FA80: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FA84: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FA84: nop

    // 0x8000FA88: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000FA8C: lw          $v0, 0x3F54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F54);
    // 0x8000FA90: beq         $v0, $zero, L_8000FC40
    if (ctx->r2 == 0) {
        // 0x8000FA94: addiu       $v0, $zero, 0x78
        ctx->r2 = ADD32(0, 0X78);
            goto L_8000FC40;
    }
    // 0x8000FA94: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000FA98: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FA9C: lh          $v0, 0x7B76($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B76);
    // 0x8000FAA0: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000FAA4: bne         $v0, $zero, L_8000FAFC
    if (ctx->r2 != 0) {
        // 0x8000FAA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000FAFC;
    }
    // 0x8000FAA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FAAC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FAB0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000FAB4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000FAB8: lbu         $a0, -0xBE8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0XBE8);
    // 0x8000FABC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000FAC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FAC4: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000FAC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FACC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FAD0: sb          $v0, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r2;
    // 0x8000FAD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FAD8: sb          $v0, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r2;
    // 0x8000FADC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FAE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FAE4: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x8000FAE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FAEC: jal         0x80008A1C
    // 0x8000FAF0: sb          $a0, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = ctx->r4;
    func_80008A1C(rdram, ctx);
        goto after_63;
    // 0x8000FAF0: sb          $a0, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = ctx->r4;
    after_63:
    // 0x8000FAF4: j           L_8000FDA0
    // 0x8000FAF8: nop

        goto L_8000FDA0;
    // 0x8000FAF8: nop

L_8000FAFC:
    // 0x8000FAFC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FB00: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000FB04: beq         $v1, $v0, L_8000FB80
    if (ctx->r3 == ctx->r2) {
        // 0x8000FB08: nop
    
            goto L_8000FB80;
    }
    // 0x8000FB08: nop

    // 0x8000FB0C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8000FB10: lhu         $a0, -0x33C8($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X33C8);
    // 0x8000FB14: andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // 0x8000FB18: bne         $v0, $zero, L_8000FB34
    if (ctx->r2 != 0) {
        // 0x8000FB1C: nop
    
            goto L_8000FB34;
    }
    // 0x8000FB1C: nop

    // 0x8000FB20: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000FB24: lhu         $v1, -0x33C2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C2);
    // 0x8000FB28: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8000FB2C: beq         $v0, $zero, L_8000FB54
    if (ctx->r2 == 0) {
        // 0x8000FB30: andi        $v0, $a0, 0x200
        ctx->r2 = ctx->r4 & 0X200;
            goto L_8000FB54;
    }
    // 0x8000FB30: andi        $v0, $a0, 0x200
    ctx->r2 = ctx->r4 & 0X200;
L_8000FB34:
    // 0x8000FB34: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FB38: addiu       $a0, $a0, 0x2077
    ctx->r4 = ADD32(ctx->r4, 0X2077);
    // 0x8000FB3C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000FB40: sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x8000FB44: beq         $v0, $zero, L_8000FB80
    if (ctx->r2 == 0) {
        // 0x8000FB48: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8000FB80;
    }
    // 0x8000FB48: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8000FB4C: j           L_8000FB80
    // 0x8000FB50: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8000FB80;
    // 0x8000FB50: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8000FB54:
    // 0x8000FB54: bne         $v0, $zero, L_8000FB64
    if (ctx->r2 != 0) {
        // 0x8000FB58: andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
            goto L_8000FB64;
    }
    // 0x8000FB58: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8000FB5C: beq         $v0, $zero, L_8000FB80
    if (ctx->r2 == 0) {
        // 0x8000FB60: nop
    
            goto L_8000FB80;
    }
    // 0x8000FB60: nop

L_8000FB64:
    // 0x8000FB64: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FB68: addiu       $a0, $a0, 0x2077
    ctx->r4 = ADD32(ctx->r4, 0X2077);
    // 0x8000FB6C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000FB70: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8000FB74: bne         $v0, $zero, L_8000FB80
    if (ctx->r2 != 0) {
        // 0x8000FB78: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_8000FB80;
    }
    // 0x8000FB78: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8000FB7C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8000FB80:
    // 0x8000FB80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000FB84: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x8000FB88: bne         $v0, $zero, L_8000FBDC
    if (ctx->r2 != 0) {
        // 0x8000FB8C: nop
    
            goto L_8000FBDC;
    }
    // 0x8000FB8C: nop

    // 0x8000FB90: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FB94: lbu         $v0, 0x7BA4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA4);
    // 0x8000FB98: bne         $v0, $zero, L_8000FBDC
    if (ctx->r2 != 0) {
        // 0x8000FB9C: nop
    
            goto L_8000FBDC;
    }
    // 0x8000FB9C: nop

    // 0x8000FBA0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000FBA4: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8000FBA8: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8000FBAC: beq         $v0, $zero, L_8000FBDC
    if (ctx->r2 == 0) {
        // 0x8000FBB0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_8000FBDC;
    }
    // 0x8000FBB0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8000FBB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FBB8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000FBBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FBC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000FBC4: sb          $v0, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r2;
    // 0x8000FBC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FBCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FBD0: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000FBD4: jal         0x800064C0
    // 0x8000FBD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_64;
    // 0x8000FBD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_64:
L_8000FBDC:
    // 0x8000FBDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000FBE0: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x8000FBE4: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FBE8: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FBE8: nop

    // 0x8000FBEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FBF0: lbu         $v0, 0x7BA4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA4);
    // 0x8000FBF4: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FBF8: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FBF8: nop

    // 0x8000FBFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000FC00: lhu         $v0, -0x33C2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C2);
    // 0x8000FC04: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8000FC08: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000FC0C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8000FDA0;
    }
    // 0x8000FC0C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000FC10: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8000FC14:
    // 0x8000FC14: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC18: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000FC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FC20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000FC24: sb          $v0, -0x4FB0($at)
    MEM_B(-0X4FB0, ctx->r1) = ctx->r2;
    // 0x8000FC28: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FC2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC30: jal         0x800064C0
    // 0x8000FC34: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    func_800064C0(rdram, ctx);
        goto after_65;
    // 0x8000FC34: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    after_65:
    // 0x8000FC38: j           L_8000FDA0
    // 0x8000FC3C: nop

        goto L_8000FDA0;
    // 0x8000FC3C: nop

L_8000FC40:
    // 0x8000FC40: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FC44: addiu       $a0, $a0, 0x7B71
    ctx->r4 = ADD32(ctx->r4, 0X7B71);
    // 0x8000FC48: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000FC4C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000FC50: lbu         $a1, -0xBE8($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XBE8);
    // 0x8000FC54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC58: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8000FC5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FC60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC64: sb          $v0, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r2;
    // 0x8000FC68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC6C: sb          $v0, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r2;
    // 0x8000FC70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FC74: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8000FC78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FC7C: jal         0x80008A1C
    // 0x8000FC80: sb          $a1, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = ctx->r5;
    func_80008A1C(rdram, ctx);
        goto after_66;
    // 0x8000FC80: sb          $a1, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = ctx->r5;
    after_66:
    // 0x8000FC84: j           L_8000FDA0
    // 0x8000FC88: nop

        goto L_8000FDA0;
    // 0x8000FC88: nop

L_8000FC8C:
    // 0x8000FC8C: jal         0x80008CDC
    // 0x8000FC90: nop

    func_80008CDC(rdram, ctx);
        goto after_67;
    // 0x8000FC90: nop

    after_67:
    // 0x8000FC94: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FC98: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FC98: nop

    // 0x8000FC9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000FCA0: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x8000FCA4: bne         $v0, $zero, L_8000FCFC
    if (ctx->r2 != 0) {
        // 0x8000FCA8: nop
    
            goto L_8000FCFC;
    }
    // 0x8000FCA8: nop

    // 0x8000FCAC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000FCB0: addiu       $a1, $a1, 0x7B74
    ctx->r5 = ADD32(ctx->r5, 0X7B74);
    // 0x8000FCB4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8000FCB8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000FCBC: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000FCC0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000FCC4: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FCC8: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_8000FDA0;
    }
    // 0x8000FCC8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8000FCCC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FCD0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000FCD4: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8000FCD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FCDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FCE0: sb          $v1, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r3;
    // 0x8000FCE4: jal         0x8000C1F4
    // 0x8000FCE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8000C1F4(rdram, ctx);
        goto after_68;
    // 0x8000FCE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_68:
L_8000FCEC:
    // 0x8000FCEC: jal         0x800064C0
    // 0x8000FCF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800064C0(rdram, ctx);
        goto after_69;
    // 0x8000FCF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_69:
    // 0x8000FCF4: j           L_8000FDA0
    // 0x8000FCF8: nop

        goto L_8000FDA0;
    // 0x8000FCF8: nop

L_8000FCFC:
    // 0x8000FCFC: jal         0x8002CFB8
    // 0x8000FD00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_70;
    // 0x8000FD00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_70:
    // 0x8000FD04: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000FD08: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FD08: nop

    // 0x8000FD0C: jal         0x80031BEC
    // 0x8000FD10: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    func_80031BEC(rdram, ctx);
        goto after_71;
    // 0x8000FD10: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_71:
    // 0x8000FD14: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FD18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD1C: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8000FD20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD24: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8000FD28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD2C: sb          $zero, 0x7BA4($at)
    MEM_B(0X7BA4, ctx->r1) = 0;
L_8000FD30:
    // 0x8000FD30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD34: sb          $zero, 0x25F3($at)
    MEM_B(0X25F3, ctx->r1) = 0;
    // 0x8000FD38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD3C: sb          $zero, 0x7A43($at)
    MEM_B(0X7A43, ctx->r1) = 0;
    // 0x8000FD40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD44: sb          $zero, 0x25E8($at)
    MEM_B(0X25E8, ctx->r1) = 0;
    // 0x8000FD48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD4C: j           L_8000FDA0
    // 0x8000FD50: sb          $zero, 0x7A38($at)
    MEM_B(0X7A38, ctx->r1) = 0;
        goto L_8000FDA0;
    // 0x8000FD50: sb          $zero, 0x7A38($at)
    MEM_B(0X7A38, ctx->r1) = 0;
L_8000FD54:
    // 0x8000FD54: jal         0x80008CDC
    // 0x8000FD58: nop

    func_80008CDC(rdram, ctx);
        goto after_72;
    // 0x8000FD58: nop

    after_72:
    // 0x8000FD5C: bne         $v0, $zero, L_8000FDA0
    if (ctx->r2 != 0) {
        // 0x8000FD60: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FD60: nop

    // 0x8000FD64: jal         0x8002CFB8
    // 0x8000FD68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_73;
    // 0x8000FD68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_73:
    // 0x8000FD6C: beq         $v0, $zero, L_8000FDA0
    if (ctx->r2 == 0) {
        // 0x8000FD70: nop
    
            goto L_8000FDA0;
    }
    // 0x8000FD70: nop

    // 0x8000FD74: jal         0x80031BEC
    // 0x8000FD78: nop

    func_80031BEC(rdram, ctx);
        goto after_74;
    // 0x8000FD78: nop

    after_74:
    // 0x8000FD7C: jal         0x80006998
    // 0x8000FD80: nop

    func_80006998(rdram, ctx);
        goto after_75;
    // 0x8000FD80: nop

    after_75:
    // 0x8000FD84: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000FD88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD8C: sb          $zero, 0x7BA4($at)
    MEM_B(0X7BA4, ctx->r1) = 0;
L_8000FD90:
    // 0x8000FD90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD94: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8000FD98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FD9C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8000FDA0:
    // 0x8000FDA0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000FDA4: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x8000FDA8: jal         0x80017D38
    // 0x8000FDAC: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    func_80017D38(rdram, ctx);
        goto after_76;
    // 0x8000FDAC: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    after_76:
    // 0x8000FDB0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8000FDB4: lhu         $v0, -0x765C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X765C);
    // 0x8000FDB8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000FDBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000FDC0: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
    // 0x8000FDC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000FDC8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000FDCC: bne         $v0, $s0, L_8000FDDC
    if (ctx->r2 != ctx->r16) {
        // 0x8000FDD0: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8000FDDC;
    }
    // 0x8000FDD0: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8000FDD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000FDD8: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
L_8000FDDC:
    // 0x8000FDDC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FDE0: jal         0x80017D38
    // 0x8000FDE4: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    func_80017D38(rdram, ctx);
        goto after_77;
    // 0x8000FDE4: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    after_77:
    // 0x8000FDE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FDEC: lhu         $v0, 0x20AC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20AC);
    // 0x8000FDF0: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000FDF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FDF8: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
    // 0x8000FDFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000FE00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000FE04: bne         $v0, $s0, L_8000FE14
    if (ctx->r2 != ctx->r16) {
        // 0x8000FE08: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8000FE14;
    }
    // 0x8000FE08: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8000FE0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000FE10: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
L_8000FE14:
    // 0x8000FE14: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FE18: jal         0x80017D38
    // 0x8000FE1C: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    func_80017D38(rdram, ctx);
        goto after_78;
    // 0x8000FE1C: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    after_78:
    // 0x8000FE20: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FE24: jal         0x80017D38
    // 0x8000FE28: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    func_80017D38(rdram, ctx);
        goto after_79;
    // 0x8000FE28: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    after_79:
    // 0x8000FE2C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FE30: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x8000FE34: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8000FE38: sltiu       $v1, $a1, 0x1
    ctx->r3 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8000FE3C: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x8000FE40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000FE44: bne         $v0, $zero, L_8000FE98
    if (ctx->r2 != 0) {
        // 0x8000FE48: sltiu       $v0, $a0, 0xA
        ctx->r2 = ctx->r4 < 0XA ? 1 : 0;
            goto L_8000FE98;
    }
    // 0x8000FE48: sltiu       $v0, $a0, 0xA
    ctx->r2 = ctx->r4 < 0XA ? 1 : 0;
    // 0x8000FE4C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000FE50: beq         $v0, $zero, L_8000FE68
    if (ctx->r2 == 0) {
        // 0x8000FE54: nop
    
            goto L_8000FE68;
    }
    // 0x8000FE54: nop

    // 0x8000FE58: jal         0x80042BA8
    // 0x8000FE5C: nop

    func_80042BA8(rdram, ctx);
        goto after_80;
    // 0x8000FE5C: nop

    after_80:
    // 0x8000FE60: j           L_8000FEA0
    // 0x8000FE64: nop

        goto L_8000FEA0;
    // 0x8000FE64: nop

L_8000FE68:
    // 0x8000FE68: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000FE6C: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x8000FE70: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8000FE74: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000FE78: beq         $v0, $zero, L_8000FE90
    if (ctx->r2 == 0) {
        // 0x8000FE7C: nop
    
            goto L_8000FE90;
    }
    // 0x8000FE7C: nop

    // 0x8000FE80: jal         0x80043CF4
    // 0x8000FE84: nop

    func_80043CF4(rdram, ctx);
        goto after_81;
    // 0x8000FE84: nop

    after_81:
    // 0x8000FE88: j           L_8000FEA0
    // 0x8000FE8C: nop

        goto L_8000FEA0;
    // 0x8000FE8C: nop

L_8000FE90:
    // 0x8000FE90: bne         $a1, $zero, L_8000FEA0
    if (ctx->r5 != 0) {
        // 0x8000FE94: nop
    
            goto L_8000FEA0;
    }
    // 0x8000FE94: nop

L_8000FE98:
    // 0x8000FE98: jal         0x800354C0
    // 0x8000FE9C: nop

    func_800354C0(rdram, ctx);
        goto after_82;
    // 0x8000FE9C: nop

    after_82:
L_8000FEA0:
    // 0x8000FEA0: jal         0x80051D6C
    // 0x8000FEA4: nop

    func_80051D6C(rdram, ctx);
        goto after_83;
    // 0x8000FEA4: nop

    after_83:
    // 0x8000FEA8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FEAC: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000FEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FEB4: beq         $v1, $v0, L_8000FF10
    if (ctx->r3 == ctx->r2) {
        // 0x8000FEB8: nop
    
            goto L_8000FF10;
    }
    // 0x8000FEB8: nop

    // 0x8000FEBC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FEC0: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000FEC4: addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // 0x8000FEC8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000FECC: beq         $v0, $zero, L_8000FF10
    if (ctx->r2 == 0) {
        // 0x8000FED0: addiu       $a1, $zero, 0x50
        ctx->r5 = ADD32(0, 0X50);
            goto L_8000FF10;
    }
    // 0x8000FED0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8000FED4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000FED8: addiu       $a0, $a0, -0x3218
    ctx->r4 = ADD32(ctx->r4, -0X3218);
    // 0x8000FEDC: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x8000FEE0: jal         0x8004EC44
    // 0x8000FEE4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004EC44(rdram, ctx);
        goto after_84;
    // 0x8000FEE4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_84:
    // 0x8000FEE8: jal         0x800346F4
    // 0x8000FEEC: nop

    func_800346F4(rdram, ctx);
        goto after_85;
    // 0x8000FEEC: nop

    after_85:
    // 0x8000FEF0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000FEF4: lbu         $v1, 0x2077($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2077);
    // 0x8000FEF8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000FEFC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8000FF00: lbu         $a0, -0xAA9($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0XAA9);
    // 0x8000FF04: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8000FF08: jal         0x80055A1C
    // 0x8000FF0C: addiu       $a2, $v0, 0xC0
    ctx->r6 = ADD32(ctx->r2, 0XC0);
    func_80055A1C(rdram, ctx);
        goto after_86;
    // 0x8000FF0C: addiu       $a2, $v0, 0xC0
    ctx->r6 = ADD32(ctx->r2, 0XC0);
    after_86:
L_8000FF10:
    // 0x8000FF10: lw          $ra, 0xD4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD4);
    // 0x8000FF14: lw          $fp, 0xD0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD0);
    // 0x8000FF18: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x8000FF1C: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x8000FF20: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x8000FF24: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x8000FF28: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x8000FF2C: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x8000FF30: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x8000FF34: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x8000FF38: jr          $ra
    // 0x8000FF3C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8000FF3C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8000FF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FF44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000FF48: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000FF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FF50: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8000FF54: lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // 0x8000FF58: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x8000FF5C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000FF60: lbu         $a0, 0x7BA8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7BA8);
    // 0x8000FF64: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8000FF68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000FF6C: lbu         $v0, 0x7BA7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA7);
    // 0x8000FF70: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8000FF74: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000FF78: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000FF7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000FF80: mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000FF84: mfhi        $a2
    ctx->r6 = hi;
    // 0x8000FF88: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8000FF8C: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8000FF90: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8000FF94: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000FF98: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x8000FF9C: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8000FFA0: bne         $v0, $zero, L_8000FFAC
    if (ctx->r2 != 0) {
        // 0x8000FFA4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000FFAC;
    }
    // 0x8000FFA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000FFA8: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
L_8000FFAC:
    // 0x8000FFAC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8000FFB0: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8000FFB4: beq         $a0, $v0, L_8000FFE0
    if (ctx->r4 == ctx->r2) {
        // 0x8000FFB8: nop
    
            goto L_8000FFE0;
    }
    // 0x8000FFB8: nop

    // 0x8000FFBC: jal         0x8001F45C
    // 0x8000FFC0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    func_8001F45C(rdram, ctx);
        goto after_0;
    // 0x8000FFC0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_0:
    // 0x8000FFC4: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8000FFC8: beq         $v0, $zero, L_8000FFE0
    if (ctx->r2 == 0) {
        // 0x8000FFCC: nop
    
            goto L_8000FFE0;
    }
    // 0x8000FFCC: nop

    // 0x8000FFD0: jal         0x800064C0
    // 0x8000FFD4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800064C0(rdram, ctx);
        goto after_1;
    // 0x8000FFD4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_1:
    // 0x8000FFD8: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8000FFDC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_8000FFE0:
    // 0x8000FFE0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8000FFE4: beq         $v0, $zero, L_8000FFF0
    if (ctx->r2 == 0) {
        // 0x8000FFE8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000FFF0;
    }
    // 0x8000FFE8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000FFEC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_8000FFF0:
    // 0x8000FFF0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8000FFF4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8000FFF8: addiu       $v0, $v0, 0x88
    ctx->r2 = ADD32(ctx->r2, 0X88);
    // 0x8000FFFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010000: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80010004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010008: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001000C: jr          $ra
    // 0x80010010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80010010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80010014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010014: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010018: lb          $v0, 0x25FA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25FA);
    // 0x8001001C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80010020: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80010024: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80010028: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8001002C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80010030: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80010034: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80010038: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8001003C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80010040: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80010044: beq         $v0, $zero, L_8001005C
    if (ctx->r2 == 0) {
        // 0x80010048: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8001005C;
    }
    // 0x80010048: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001004C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010050: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80010054: bne         $v0, $zero, L_8001037C
    if (ctx->r2 != 0) {
        // 0x80010058: nop
    
            goto L_8001037C;
    }
    // 0x80010058: nop

L_8001005C:
    // 0x8001005C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80010060: jal         0x80017D38
    // 0x80010064: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x80010064: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    after_0:
    // 0x80010068: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001006C: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x80010070: slti        $v0, $a1, 0x4C
    ctx->r2 = SIGNED(ctx->r5) < 0X4C ? 1 : 0;
    // 0x80010074: beq         $v0, $zero, L_8001037C
    if (ctx->r2 == 0) {
        // 0x80010078: lui         $t0, 0xBA00
        ctx->r8 = S32(0XBA00 << 16);
            goto L_8001037C;
    }
    // 0x80010078: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8001007C: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x80010080: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80010084: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x80010088: lui         $t1, 0xC08
    ctx->r9 = S32(0XC08 << 16);
    // 0x8001008C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80010090: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80010094: ori         $t1, $t1, 0x7008
    ctx->r9 = ctx->r9 | 0X7008;
    // 0x80010098: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001009C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800100A0: addiu       $s0, $s0, 0x4580
    ctx->r16 = ADD32(ctx->r16, 0X4580);
    // 0x800100A4: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800100A8: addiu       $s1, $s1, 0x1230
    ctx->r17 = ADD32(ctx->r17, 0X1230);
    // 0x800100AC: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x800100B0: addiu       $s2, $s2, -0x7540
    ctx->r18 = ADD32(ctx->r18, -0X7540);
    // 0x800100B4: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x800100B8: addiu       $s4, $s4, 0x26E0
    ctx->r20 = ADD32(ctx->r20, 0X26E0);
    // 0x800100BC: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800100C0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800100C4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800100C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800100CC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800100D0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800100D4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800100D8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800100DC: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x800100E0: addu        $fp, $v1, $a1
    ctx->r30 = ADD32(ctx->r3, ctx->r5);
    // 0x800100E4: addu        $a1, $v0, $s1
    ctx->r5 = ADD32(ctx->r2, ctx->r17);
    // 0x800100E8: addu        $s5, $v1, $a1
    ctx->r21 = ADD32(ctx->r3, ctx->r5);
    // 0x800100EC: addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
    // 0x800100F0: addu        $s6, $v1, $a1
    ctx->r22 = ADD32(ctx->r3, ctx->r5);
    // 0x800100F4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800100F8: addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    // 0x800100FC: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x80010100: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80010104: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80010108: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8001010C: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // 0x80010110: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010114: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010118: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001011C: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80010120: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80010124: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010128: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8001012C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80010130: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80010134: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010138: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001013C: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80010140: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80010144: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80010148: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001014C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010150: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x80010154: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80010158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001015C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80010160: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80010164: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80010168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001016C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010170: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x80010174: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x80010178: jal         0x800178E0
    // 0x8001017C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_800178E0(rdram, ctx);
        goto after_1;
    // 0x8001017C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_1:
    // 0x80010180: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80010184: addiu       $v0, $v0, 0x1BC0
    ctx->r2 = ADD32(ctx->r2, 0X1BC0);
    // 0x80010188: sw          $v0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r2;
    // 0x8001018C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010190: lbu         $v0, 0x7BA8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA8);
    // 0x80010194: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80010198: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x8001019C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800101A0: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x800101A4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800101A8: jal         0x80018514
    // 0x800101AC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    func_80018514(rdram, ctx);
        goto after_2;
    // 0x800101AC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_2:
    // 0x800101B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800101B4: lw          $v0, 0x555C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X555C);
    // 0x800101B8: lui         $s3, 0xC100
    ctx->r19 = S32(0XC100 << 16);
    // 0x800101BC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800101C0: lw          $t0, 0x2FE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2FE4);
    // 0x800101C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800101C8: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x800101CC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800101D0: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x800101D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800101D8: sh          $v0, 0x10($s5)
    MEM_H(0X10, ctx->r21) = ctx->r2;
    // 0x800101DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800101E0: lw          $v1, 0x555C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X555C);
    // 0x800101E4: ori         $s3, $s3, 0x17
    ctx->r19 = ctx->r19 | 0X17;
    // 0x800101E8: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x800101EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800101F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800101F4: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x800101F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800101FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010200: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x80010204: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010208: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001020C: addiu       $v0, $t0, 0x20
    ctx->r2 = ADD32(ctx->r8, 0X20);
    // 0x80010210: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010214: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010218: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001021C: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80010220: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80010224: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010228: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001022C: sw          $a1, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r5;
    // 0x80010230: andi        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 & 0X2;
    // 0x80010234: addiu       $v1, $v1, 0x27
    ctx->r3 = ADD32(ctx->r3, 0X27);
    // 0x80010238: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001023C: sh          $v1, 0x12($s5)
    MEM_H(0X12, ctx->r21) = ctx->r3;
    // 0x80010240: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80010244: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80010248: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001024C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80010250: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80010254: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80010258: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001025C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80010260: addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // 0x80010264: sw          $fp, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r30;
    // 0x80010268: addu        $fp, $v1, $s0
    ctx->r30 = ADD32(ctx->r3, ctx->r16);
    // 0x8001026C: addu        $s1, $v0, $s1
    ctx->r17 = ADD32(ctx->r2, ctx->r17);
    // 0x80010270: sw          $s5, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r21;
    // 0x80010274: addu        $s5, $v1, $s1
    ctx->r21 = ADD32(ctx->r3, ctx->r17);
    // 0x80010278: addu        $s2, $v0, $s2
    ctx->r18 = ADD32(ctx->r2, ctx->r18);
    // 0x8001027C: sw          $s6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r22;
    // 0x80010280: addu        $s6, $v1, $s2
    ctx->r22 = ADD32(ctx->r3, ctx->r18);
    // 0x80010284: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80010288: sw          $s7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r23;
    // 0x8001028C: addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    // 0x80010290: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x80010294: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80010298: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // 0x8001029C: lui         $s0, 0x517
    ctx->r16 = S32(0X517 << 16);
    // 0x800102A0: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x800102A4: sw          $s3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r19;
    // 0x800102A8: sw          $s3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r19;
    // 0x800102AC: sw          $s0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r16;
    // 0x800102B0: sw          $s1, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r17;
    // 0x800102B4: jal         0x800178E0
    // 0x800102B8: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_800178E0(rdram, ctx);
        goto after_3;
    // 0x800102B8: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_3:
    // 0x800102BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800102C0: lbu         $v0, 0x7BA7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA7);
    // 0x800102C4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800102C8: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x800102CC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800102D0: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x800102D4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800102D8: jal         0x80018514
    // 0x800102DC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    func_80018514(rdram, ctx);
        goto after_4;
    // 0x800102DC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_4:
    // 0x800102E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800102E4: lw          $v0, 0x555C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X555C);
    // 0x800102E8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800102EC: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x800102F0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800102F4: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x800102F8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800102FC: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x80010300: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010304: sh          $v0, 0x10($s5)
    MEM_H(0X10, ctx->r21) = ctx->r2;
    // 0x80010308: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001030C: lw          $a0, 0x555C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X555C);
    // 0x80010310: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010314: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010318: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001031C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80010320: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010324: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010328: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8001032C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010330: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010334: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80010338: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001033C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010340: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010344: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80010348: sw          $a1, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r5;
    // 0x8001034C: andi        $a0, $a0, 0x2
    ctx->r4 = ctx->r4 & 0X2;
    // 0x80010350: addiu       $a0, $a0, 0x27
    ctx->r4 = ADD32(ctx->r4, 0X27);
    // 0x80010354: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80010358: sh          $a0, 0x12($s5)
    MEM_H(0X12, ctx->r21) = ctx->r4;
    // 0x8001035C: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x80010360: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x80010364: sw          $s3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r19;
    // 0x80010368: sw          $s6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r22;
    // 0x8001036C: sw          $s0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r16;
    // 0x80010370: sw          $s5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r21;
    // 0x80010374: sw          $s1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r17;
    // 0x80010378: sw          $fp, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r30;
L_8001037C:
    // 0x8001037C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80010380: jal         0x80017D38
    // 0x80010384: addiu       $a0, $a0, 0x53C0
    ctx->r4 = ADD32(ctx->r4, 0X53C0);
    func_80017D38(rdram, ctx);
        goto after_5;
    // 0x80010384: addiu       $a0, $a0, 0x53C0
    ctx->r4 = ADD32(ctx->r4, 0X53C0);
    after_5:
    // 0x80010388: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001038C: lb          $v0, 0x25EA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25EA);
    // 0x80010390: bne         $v0, $zero, L_800103A8
    if (ctx->r2 != 0) {
        // 0x80010394: nop
    
            goto L_800103A8;
    }
    // 0x80010394: nop

    // 0x80010398: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001039C: lb          $v0, 0x7A3A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A3A);
    // 0x800103A0: beq         $v0, $zero, L_80010714
    if (ctx->r2 == 0) {
        // 0x800103A4: nop
    
            goto L_80010714;
    }
    // 0x800103A4: nop

L_800103A8:
    // 0x800103A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800103AC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800103B0: bne         $v0, $zero, L_80010714
    if (ctx->r2 != 0) {
        // 0x800103B4: nop
    
            goto L_80010714;
    }
    // 0x800103B4: nop

    // 0x800103B8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800103BC: lbu         $v1, 0x7B7C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B7C);
    // 0x800103C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800103C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800103C8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800103CC: lw          $v0, -0x33F4($at)
    ctx->r2 = MEM_W(ctx->r1, -0X33F4);
    // 0x800103D0: beq         $v1, $zero, L_800103E4
    if (ctx->r3 == 0) {
        // 0x800103D4: lui         $a0, 0xBA00
        ctx->r4 = S32(0XBA00 << 16);
            goto L_800103E4;
    }
    // 0x800103D4: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x800103D8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800103DC: j           L_800103E8
    // 0x800103E0: nop

        goto L_800103E8;
    // 0x800103E0: nop

L_800103E4:
    // 0x800103E4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
L_800103E8:
    // 0x800103E8: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x800103EC: lui         $a3, 0x71F
    ctx->r7 = S32(0X71F << 16);
    // 0x800103F0: ori         $a3, $a3, 0xF200
    ctx->r7 = ctx->r7 | 0XF200;
    // 0x800103F4: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x800103F8: ori         $t0, $t0, 0x800
    ctx->r8 = ctx->r8 | 0X800;
    // 0x800103FC: lui         $t1, 0x7
    ctx->r9 = S32(0X7 << 16);
    // 0x80010400: ori         $t1, $t1, 0xC07C
    ctx->r9 = ctx->r9 | 0XC07C;
    // 0x80010404: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x80010408: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x8001040C: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x80010410: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x80010414: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80010418: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8001041C: addiu       $s2, $s2, 0x7B7C
    ctx->r18 = ADD32(ctx->r18, 0X7B7C);
    // 0x80010420: lui         $s5, 0xE400
    ctx->r21 = S32(0XE400 << 16);
    // 0x80010424: lui         $s4, 0xB400
    ctx->r20 = S32(0XB400 << 16);
    // 0x80010428: lui         $s3, 0xB300
    ctx->r19 = S32(0XB300 << 16);
    // 0x8001042C: lui         $s1, 0x666
    ctx->r17 = S32(0X666 << 16);
    // 0x80010430: ori         $s1, $s1, 0x666
    ctx->r17 = ctx->r17 | 0X666;
    // 0x80010434: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80010438: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001043C: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80010440: addu        $t6, $v1, $zero
    ctx->r14 = ADD32(ctx->r3, 0);
    // 0x80010444: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x80010448: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8001044C: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x80010450: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80010454: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010458: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001045C: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80010460: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80010464: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010468: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x8001046C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80010470: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80010474: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010478: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001047C: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x80010480: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80010484: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80010488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001048C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010490: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x80010494: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80010498: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001049C: addiu       $v1, $v1, -0xA98
    ctx->r3 = ADD32(ctx->r3, -0XA98);
    // 0x800104A0: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800104A4: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x800104A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800104AC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800104B0: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x800104B4: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800104B8: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800104BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800104C0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800104C4: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x800104C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800104CC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800104D0: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x800104D4: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x800104D8: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x800104DC: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800104E0: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x800104E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800104E8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800104EC: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x800104F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800104F4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800104F8: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x800104FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010500: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010504: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80010508: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8001050C: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80010510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010514: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010518: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8001051C: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80010520: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010524: addiu       $v1, $v1, -0x690
    ctx->r3 = ADD32(ctx->r3, -0X690);
    // 0x80010528: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x8001052C: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x80010530: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010534: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010538: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x8001053C: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
    // 0x80010540: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x80010544: sw          $a2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r6;
    // 0x80010548: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x8001054C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80010550: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x80010554: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x80010558: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x8001055C: sw          $t0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r8;
    // 0x80010560: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80010564: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80010568: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x8001056C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010570: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010574: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x80010578: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001057C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010580: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x80010584: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010588: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001058C: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80010590: sw          $v1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r3;
    // 0x80010594: addiu       $v1, $v0, 0x78
    ctx->r3 = ADD32(ctx->r2, 0X78);
    // 0x80010598: sw          $t2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r10;
    // 0x8001059C: sw          $a2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r6;
    // 0x800105A0: sw          $a1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r5;
    // 0x800105A4: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x800105A8: sw          $t3, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r11;
    // 0x800105AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800105B0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800105B4: sw          $a0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r4;
    // 0x800105B8: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
L_800105BC:
    // 0x800105BC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800105C0: addu        $t4, $t5, $zero
    ctx->r12 = ADD32(ctx->r13, 0);
    // 0x800105C4: addu        $t3, $t7, $zero
    ctx->r11 = ADD32(ctx->r15, 0);
    // 0x800105C8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800105CC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800105D0: addu        $a3, $t6, $zero
    ctx->r7 = ADD32(ctx->r14, 0);
L_800105D4:
    // 0x800105D4: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x800105D8: beq         $a2, $zero, L_800106E4
    if (ctx->r6 == 0) {
        // 0x800105DC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800106E4;
    }
    // 0x800105DC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800105E0: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800105E4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800105E8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800105EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800105F0: lw          $v1, 0x1360($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1360);
    // 0x800105F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800105F8: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x800105FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010600: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80010604: lw          $v0, 0x1364($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1364);
    // 0x80010608: addiu       $v1, $v1, 0x94
    ctx->r3 = ADD32(ctx->r3, 0X94);
    // 0x8001060C: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80010610: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80010614: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80010618: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8001061C: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80010620: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x80010624: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010628: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001062C: or          $v0, $v0, $s5
    ctx->r2 = ctx->r2 | ctx->r21;
    // 0x80010630: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80010634: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80010638: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001063C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80010640: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010644: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80010648: lw          $v1, 0x1360($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1360);
    // 0x8001064C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010650: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80010654: lw          $a0, 0x1364($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1364);
    // 0x80010658: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8001065C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010660: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010664: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80010668: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001066C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010670: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80010674: sw          $s4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r20;
    // 0x80010678: addiu       $v1, $v1, 0x94
    ctx->r3 = ADD32(ctx->r3, 0X94);
    // 0x8001067C: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x80010680: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80010684: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80010688: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8001068C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80010690: addu        $a0, $t4, $a0
    ctx->r4 = ADD32(ctx->r12, ctx->r4);
    // 0x80010694: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80010698: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8001069C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800106A0: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x800106A4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800106A8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800106AC: lb          $a0, -0x3DF4($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X3DF4);
    // 0x800106B0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800106B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800106B8: lb          $v1, -0x3DF3($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DF3);
    // 0x800106BC: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x800106C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800106C4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800106C8: sw          $s3, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r19;
    // 0x800106CC: sw          $s1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r17;
    // 0x800106D0: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x800106D4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800106D8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800106DC: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800106E0: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_800106E4:
    // 0x800106E4: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x800106E8: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x800106EC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800106F0: slti        $v0, $t2, 0x5
    ctx->r2 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x800106F4: bne         $v0, $zero, L_800105D4
    if (ctx->r2 != 0) {
        // 0x800106F8: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800105D4;
    }
    // 0x800106F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800106FC: addiu       $t7, $t7, 0x5
    ctx->r15 = ADD32(ctx->r15, 0X5);
    // 0x80010700: addiu       $t6, $t6, 0x5
    ctx->r14 = ADD32(ctx->r14, 0X5);
    // 0x80010704: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80010708: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8001070C: bne         $v0, $zero, L_800105BC
    if (ctx->r2 != 0) {
        // 0x80010710: addiu       $t5, $t5, 0x5
        ctx->r13 = ADD32(ctx->r13, 0X5);
            goto L_800105BC;
    }
    // 0x80010710: addiu       $t5, $t5, 0x5
    ctx->r13 = ADD32(ctx->r13, 0X5);
L_80010714:
    // 0x80010714: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80010718: addiu       $t5, $t5, 0x25A0
    ctx->r13 = ADD32(ctx->r13, 0X25A0);
    // 0x8001071C: lb          $v0, 0x0($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X0);
    // 0x80010720: beq         $v0, $zero, L_80010CE0
    if (ctx->r2 == 0) {
        // 0x80010724: nop
    
            goto L_80010CE0;
    }
    // 0x80010724: nop

    // 0x80010728: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001072C: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80010730: beq         $v0, $zero, L_80010CE0
    if (ctx->r2 == 0) {
        // 0x80010734: lui         $a0, 0xBA00
        ctx->r4 = S32(0XBA00 << 16);
            goto L_80010CE0;
    }
    // 0x80010734: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80010738: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x8001073C: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x80010740: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x80010744: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x80010748: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x8001074C: lui         $t1, 0x703
    ctx->r9 = S32(0X703 << 16);
    // 0x80010750: ori         $t1, $t1, 0xF800
    ctx->r9 = ctx->r9 | 0XF800;
    // 0x80010754: lui         $t2, 0xF540
    ctx->r10 = S32(0XF540 << 16);
    // 0x80010758: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8001075C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80010760: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80010764: lui         $t3, 0x3
    ctx->r11 = S32(0X3 << 16);
    // 0x80010768: ori         $t3, $t3, 0xC03C
    ctx->r11 = ctx->r11 | 0XC03C;
    // 0x8001076C: lui         $a3, 0x700
    ctx->r7 = S32(0X700 << 16);
    // 0x80010770: lui         $a2, 0xE600
    ctx->r6 = S32(0XE600 << 16);
    // 0x80010774: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80010778: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001077C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010780: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80010784: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80010788: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001078C: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x80010790: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80010794: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80010798: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001079C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800107A0: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x800107A4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800107A8: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x800107AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800107B0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800107B4: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x800107B8: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800107BC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800107C0: addiu       $a0, $a0, 0x49C0
    ctx->r4 = ADD32(ctx->r4, 0X49C0);
    // 0x800107C4: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800107C8: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x800107CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800107D0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800107D4: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x800107D8: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800107DC: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800107E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800107E4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800107E8: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x800107EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800107F0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800107F4: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x800107F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800107FC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010800: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80010804: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80010808: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x8001080C: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x80010810: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x80010814: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010818: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001081C: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x80010820: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010824: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010828: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x8001082C: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x80010830: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x80010834: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x80010838: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x8001083C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010840: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010844: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x80010848: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x8001084C: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x80010850: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80010854: sw          $a3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r7;
    // 0x80010858: sw          $a2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r6;
    // 0x8001085C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80010860: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x80010864: sw          $a1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r5;
    // 0x80010868: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8001086C: sw          $a0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r4;
    // 0x80010870: sw          $a3, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r7;
    // 0x80010874: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010878: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001087C: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x80010880: sw          $a2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r6;
    // 0x80010884: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80010888: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x8001088C: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80010890: sw          $t1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r9;
    // 0x80010894: sw          $a1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r5;
    // 0x80010898: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8001089C: sw          $t2, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r10;
    // 0x800108A0: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x800108A4: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x800108A8: sw          $t3, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r11;
    // 0x800108AC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800108B0: lbu         $a0, 0x2618($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2618);
    // 0x800108B4: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x800108B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800108BC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800108C0: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x800108C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800108C8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800108CC: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x800108D0: addiu       $v0, $v0, 0x78
    ctx->r2 = ADD32(ctx->r2, 0X78);
    // 0x800108D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800108D8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800108DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800108E0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800108E4: blez        $a0, L_8001098C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800108E8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8001098C;
    }
    // 0x800108E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800108EC: lui         $t1, 0xE424
    ctx->r9 = S32(0XE424 << 16);
    // 0x800108F0: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x800108F4: lui         $t0, 0x20
    ctx->r8 = S32(0X20 << 16);
    // 0x800108F8: ori         $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 | 0X8000;
    // 0x800108FC: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x80010900: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x80010904: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x80010908: ori         $a3, $a3, 0x400
    ctx->r7 = ctx->r7 | 0X400;
    // 0x8001090C: addiu       $t2, $t5, 0x78
    ctx->r10 = ADD32(ctx->r13, 0X78);
L_80010910:
    // 0x80010910: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80010914: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80010918: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x8001091C: sll         $v0, $a1, 6
    ctx->r2 = S32(ctx->r5 << 6);
    // 0x80010920: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010924: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80010928: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x8001092C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80010930: sll         $v0, $a2, 6
    ctx->r2 = S32(ctx->r6 << 6);
    // 0x80010934: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010938: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001093C: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x80010940: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80010944: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80010948: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8001094C: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80010950: sw          $a3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r7;
    // 0x80010954: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80010958: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8001095C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010964: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010968: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001096C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80010970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010974: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001097C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010980: slt         $a0, $a2, $a0
    ctx->r4 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010984: bne         $a0, $zero, L_80010910
    if (ctx->r4 != 0) {
        // 0x80010988: nop
    
            goto L_80010910;
    }
    // 0x80010988: nop

L_8001098C:
    // 0x8001098C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x80010990: addiu       $t0, $t0, 0x7A68
    ctx->r8 = ADD32(ctx->r8, 0X7A68);
    // 0x80010994: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80010998: blez        $v0, L_80010A3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001099C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80010A3C;
    }
    // 0x8001099C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800109A0: lui         $t2, 0xE42F
    ctx->r10 = S32(0XE42F << 16);
    // 0x800109A4: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x800109A8: lui         $t1, 0x2B
    ctx->r9 = S32(0X2B << 16);
    // 0x800109AC: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x800109B0: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x800109B4: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x800109B8: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x800109BC: ori         $a3, $a3, 0x400
    ctx->r7 = ctx->r7 | 0X400;
L_800109C0:
    // 0x800109C0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800109C4: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x800109C8: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x800109CC: sll         $v0, $a1, 6
    ctx->r2 = S32(ctx->r5 << 6);
    // 0x800109D0: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x800109D4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800109D8: or          $v0, $v0, $t2
    ctx->r2 = ctx->r2 | ctx->r10;
    // 0x800109DC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800109E0: sll         $v0, $a2, 6
    ctx->r2 = S32(ctx->r6 << 6);
    // 0x800109E4: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x800109E8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800109EC: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x800109F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800109F4: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x800109F8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800109FC: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80010A00: sw          $a3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r7;
    // 0x80010A04: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80010A08: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80010A0C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010A10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010A14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010A18: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80010A1C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80010A20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010A24: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010A28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010A2C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010A30: slt         $a0, $a2, $a0
    ctx->r4 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010A34: bne         $a0, $zero, L_800109C0
    if (ctx->r4 != 0) {
        // 0x80010A38: nop
    
            goto L_800109C0;
    }
    // 0x80010A38: nop

L_80010A3C:
    // 0x80010A3C: lui         $a0, 0x703
    ctx->r4 = S32(0X703 << 16);
    // 0x80010A40: ori         $a0, $a0, 0xF800
    ctx->r4 = ctx->r4 | 0XF800;
    // 0x80010A44: lui         $a3, 0xF540
    ctx->r7 = S32(0XF540 << 16);
    // 0x80010A48: ori         $a3, $a3, 0x200
    ctx->r7 = ctx->r7 | 0X200;
    // 0x80010A4C: lui         $t2, 0x3
    ctx->r10 = S32(0X3 << 16);
    // 0x80010A50: ori         $t2, $t2, 0xC03C
    ctx->r10 = ctx->r10 | 0XC03C;
    // 0x80010A54: lui         $t1, 0xFC11
    ctx->r9 = S32(0XFC11 << 16);
    // 0x80010A58: ori         $t1, $t1, 0x9623
    ctx->r9 = ctx->r9 | 0X9623;
    // 0x80010A5C: lui         $t0, 0xFF2F
    ctx->r8 = S32(0XFF2F << 16);
    // 0x80010A60: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80010A64: lui         $a2, 0xB900
    ctx->r6 = S32(0XB900 << 16);
    // 0x80010A68: ori         $a2, $a2, 0x31D
    ctx->r6 = ctx->r6 | 0X31D;
    // 0x80010A6C: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x80010A70: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80010A74: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80010A78: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x80010A7C: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x80010A80: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80010A84: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010A88: addiu       $v1, $v1, 0x4940
    ctx->r3 = ADD32(ctx->r3, 0X4940);
    // 0x80010A8C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80010A90: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x80010A94: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80010A98: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x80010A9C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80010AA0: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x80010AA4: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80010AA8: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x80010AAC: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80010AB0: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x80010AB4: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80010AB8: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80010ABC: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80010AC0: lui         $v1, 0xFA00
    ctx->r3 = S32(0XFA00 << 16);
    // 0x80010AC4: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80010AC8: addiu       $v1, $zero, -0x60
    ctx->r3 = ADD32(0, -0X60);
    // 0x80010ACC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80010AD0: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x80010AD4: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80010AD8: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
    // 0x80010ADC: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80010AE0: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x80010AE4: sw          $t1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r9;
    // 0x80010AE8: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    // 0x80010AEC: sw          $a2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r6;
    // 0x80010AF0: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    // 0x80010AF4: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x80010AF8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80010AFC: lbu         $a2, 0x2618($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X2618);
    // 0x80010B00: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x80010B04: addiu       $t2, $t2, 0x2077
    ctx->r10 = ADD32(ctx->r10, 0X2077);
    // 0x80010B08: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80010B0C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80010B10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B14: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B18: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80010B1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B20: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B24: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80010B28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B2C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B30: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80010B34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B38: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B3C: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80010B40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B44: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B48: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x80010B4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B50: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B54: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x80010B58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B5C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B60: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x80010B64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B68: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B6C: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x80010B70: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80010B74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B78: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010B7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010B80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010B84: slt         $a0, $a2, $a0
    ctx->r4 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010B88: beq         $a0, $zero, L_80010C28
    if (ctx->r4 == 0) {
        // 0x80010B8C: lui         $t0, 0x20
        ctx->r8 = S32(0X20 << 16);
            goto L_80010C28;
    }
    // 0x80010B8C: lui         $t0, 0x20
    ctx->r8 = S32(0X20 << 16);
    // 0x80010B90: lui         $t1, 0xE424
    ctx->r9 = S32(0XE424 << 16);
    // 0x80010B94: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80010B98: ori         $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 | 0X8000;
    // 0x80010B9C: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x80010BA0: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x80010BA4: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x80010BA8: ori         $a3, $a3, 0x400
    ctx->r7 = ctx->r7 | 0X400;
L_80010BAC:
    // 0x80010BAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80010BB0: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80010BB4: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x80010BB8: sll         $v0, $a1, 6
    ctx->r2 = S32(ctx->r5 << 6);
    // 0x80010BBC: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010BC0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80010BC4: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x80010BC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80010BCC: sll         $v0, $a2, 6
    ctx->r2 = S32(ctx->r6 << 6);
    // 0x80010BD0: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010BD4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80010BD8: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x80010BDC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80010BE0: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80010BE4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80010BE8: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80010BEC: sw          $a3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r7;
    // 0x80010BF0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80010BF4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80010BF8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010BFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010C00: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010C04: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80010C08: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80010C0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010C10: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010C14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010C18: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010C1C: slt         $a0, $a2, $a0
    ctx->r4 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010C20: bne         $a0, $zero, L_80010BAC
    if (ctx->r4 != 0) {
        // 0x80010C24: nop
    
            goto L_80010BAC;
    }
    // 0x80010C24: nop

L_80010C28:
    // 0x80010C28: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80010C2C: lbu         $a2, 0x7A68($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7A68);
    // 0x80010C30: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x80010C34: addiu       $t0, $t0, 0x2077
    ctx->r8 = ADD32(ctx->r8, 0X2077);
    // 0x80010C38: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80010C3C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010C40: beq         $v0, $zero, L_80010CE0
    if (ctx->r2 == 0) {
        // 0x80010C44: lui         $t2, 0xE42F
        ctx->r10 = S32(0XE42F << 16);
            goto L_80010CE0;
    }
    // 0x80010C44: lui         $t2, 0xE42F
    ctx->r10 = S32(0XE42F << 16);
    // 0x80010C48: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x80010C4C: lui         $t1, 0x2B
    ctx->r9 = S32(0X2B << 16);
    // 0x80010C50: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80010C54: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x80010C58: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x80010C5C: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x80010C60: ori         $a3, $a3, 0x400
    ctx->r7 = ctx->r7 | 0X400;
L_80010C64:
    // 0x80010C64: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80010C68: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80010C6C: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x80010C70: sll         $v0, $a1, 6
    ctx->r2 = S32(ctx->r5 << 6);
    // 0x80010C74: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010C78: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80010C7C: or          $v0, $v0, $t2
    ctx->r2 = ctx->r2 | ctx->r10;
    // 0x80010C80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80010C84: sll         $v0, $a2, 6
    ctx->r2 = S32(ctx->r6 << 6);
    // 0x80010C88: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
    // 0x80010C8C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80010C90: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x80010C94: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80010C98: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80010C9C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80010CA0: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80010CA4: sw          $a3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r7;
    // 0x80010CA8: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80010CAC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80010CB0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80010CB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010CB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010CBC: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80010CC0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80010CC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010CC8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80010CCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80010CD0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80010CD4: slt         $a0, $a2, $a0
    ctx->r4 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010CD8: bne         $a0, $zero, L_80010C64
    if (ctx->r4 != 0) {
        // 0x80010CDC: nop
    
            goto L_80010C64;
    }
    // 0x80010CDC: nop

L_80010CE0:
    // 0x80010CE0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80010CE4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80010CE8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80010CEC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80010CF0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80010CF4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80010CF8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80010CFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80010D00: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80010D04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80010D08: jr          $ra
    // 0x80010D0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80010D0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80010D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010D10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010D14: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80010D18: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80010D1C: addiu       $s1, $s1, 0x25A0
    ctx->r17 = ADD32(ctx->r17, 0X25A0);
    // 0x80010D20: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80010D24: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80010D28: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x80010D2C: beq         $v0, $zero, L_80010D44
    if (ctx->r2 == 0) {
        // 0x80010D30: nop
    
            goto L_80010D44;
    }
    // 0x80010D30: nop

    // 0x80010D34: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010D38: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80010D3C: bne         $v0, $zero, L_80010E14
    if (ctx->r2 != 0) {
        // 0x80010D40: nop
    
            goto L_80010E14;
    }
    // 0x80010D40: nop

L_80010D44:
    // 0x80010D44: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80010D48: addiu       $s0, $s0, 0x5430
    ctx->r16 = ADD32(ctx->r16, 0X5430);
    // 0x80010D4C: jal         0x80017D38
    // 0x80010D50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x80010D50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80010D54: jal         0x80017D38
    // 0x80010D58: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_1;
    // 0x80010D58: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_1:
    // 0x80010D5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010D60: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80010D64: beq         $v0, $zero, L_80010D78
    if (ctx->r2 == 0) {
        // 0x80010D68: nop
    
            goto L_80010D78;
    }
    // 0x80010D68: nop

    // 0x80010D6C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80010D70: j           L_80010D8C
    // 0x80010D74: lw          $s1, 0x7BBC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X7BBC);
        goto L_80010D8C;
    // 0x80010D74: lw          $s1, 0x7BBC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X7BBC);
L_80010D78:
    // 0x80010D78: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80010D7C: addiu       $v1, $v1, 0x79F5
    ctx->r3 = ADD32(ctx->r3, 0X79F5);
    // 0x80010D80: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80010D84: bgezl       $v0, L_80010D8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80010D88: addiu       $s1, $v1, -0x5
        ctx->r17 = ADD32(ctx->r3, -0X5);
            goto L_80010D8C;
    }
    goto skip_0;
    // 0x80010D88: addiu       $s1, $v1, -0x5
    ctx->r17 = ADD32(ctx->r3, -0X5);
    skip_0:
L_80010D8C:
    // 0x80010D8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010D90: lbu         $v0, 0x7B96($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B96);
    // 0x80010D94: beq         $v0, $zero, L_80010DEC
    if (ctx->r2 == 0) {
        // 0x80010D98: nop
    
            goto L_80010DEC;
    }
    // 0x80010D98: nop

    // 0x80010D9C: lbu         $a2, 0x73($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X73);
    // 0x80010DA0: sltiu       $v0, $a2, 0xA
    ctx->r2 = ctx->r6 < 0XA ? 1 : 0;
    // 0x80010DA4: beq         $v0, $zero, L_80010DC8
    if (ctx->r2 == 0) {
        // 0x80010DA8: addiu       $s0, $sp, 0x20
        ctx->r16 = ADD32(ctx->r29, 0X20);
            goto L_80010DC8;
    }
    // 0x80010DA8: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x80010DAC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010DB0: addiu       $a1, $a1, -0x31D0
    ctx->r5 = ADD32(ctx->r5, -0X31D0);
    // 0x80010DB4: jal         0x80066CA0
    // 0x80010DB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_2;
    // 0x80010DB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80010DBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010DC0: j           L_80010DE0
    // 0x80010DC4: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
        goto L_80010DE0;
    // 0x80010DC4: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
L_80010DC8:
    // 0x80010DC8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010DCC: addiu       $a1, $a1, -0x31CC
    ctx->r5 = ADD32(ctx->r5, -0X31CC);
    // 0x80010DD0: jal         0x80066CA0
    // 0x80010DD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x80010DD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80010DD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80010DDC: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
L_80010DE0:
    // 0x80010DE0: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    // 0x80010DE4: jal         0x8004DAB8
    // 0x80010DE8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x80010DE8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_4:
L_80010DEC:
    // 0x80010DEC: lw          $a2, 0x104($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X104);
    // 0x80010DF0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010DF4: addiu       $a1, $a1, -0x31C8
    ctx->r5 = ADD32(ctx->r5, -0X31C8);
    // 0x80010DF8: jal         0x80066CA0
    // 0x80010DFC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x80010DFC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x80010E00: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010E04: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x80010E08: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    // 0x80010E0C: jal         0x8004DAB8
    // 0x80010E10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_6;
    // 0x80010E10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
L_80010E14:
    // 0x80010E14: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80010E18: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80010E1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80010E20: jr          $ra
    // 0x80010E24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80010E24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80010E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010E28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80010E2C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80010E30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80010E34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80010E38: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80010E3C: bltz        $v0, L_80010FD4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80010E40: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80010FD4;
    }
    // 0x80010E40: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80010E44: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80010E48: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x80010E4C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80010E50: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80010E54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80010E58: addiu       $v0, $v0, 0x53C0
    ctx->r2 = ADD32(ctx->r2, 0X53C0);
    // 0x80010E5C: jal         0x80017D38
    // 0x80010E60: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x80010E60: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x80010E64: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80010E68: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80010E6C: bne         $v0, $zero, L_80010F20
    if (ctx->r2 != 0) {
        // 0x80010E70: nop
    
            goto L_80010F20;
    }
    // 0x80010E70: nop

    // 0x80010E74: lw          $a2, 0x104($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X104);
    // 0x80010E78: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010E7C: addiu       $a1, $a1, -0x31C8
    ctx->r5 = ADD32(ctx->r5, -0X31C8);
    // 0x80010E80: jal         0x80066CA0
    // 0x80010E84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x80010E84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80010E88: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010E8C: addiu       $a1, $zero, 0x7A
    ctx->r5 = ADD32(0, 0X7A);
    // 0x80010E90: addiu       $a2, $zero, 0x59
    ctx->r6 = ADD32(0, 0X59);
    // 0x80010E94: jal         0x8004DAB8
    // 0x80010E98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x80010E98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x80010E9C: lhu         $a2, 0x7E($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X7E);
    // 0x80010EA0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010EA4: addiu       $a1, $a1, -0x31C4
    ctx->r5 = ADD32(ctx->r5, -0X31C4);
    // 0x80010EA8: jal         0x80066CA0
    // 0x80010EAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x80010EAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80010EB0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010EB4: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    // 0x80010EB8: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80010EBC: jal         0x8004DAB8
    // 0x80010EC0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x80010EC0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x80010EC4: lhu         $v1, 0x7E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7E);
    // 0x80010EC8: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x80010ECC: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x80010ED0: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010ED4: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80010ED8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80010EDC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80010EE0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80010EE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80010EE8: mfhi        $t0
    ctx->r8 = hi;
    // 0x80010EEC: srl         $a0, $t0, 3
    ctx->r4 = S32(U32(ctx->r8) >> 3);
    // 0x80010EF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80010EF4: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x80010EF8: slti        $v0, $a2, 0x64
    ctx->r2 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    // 0x80010EFC: beql        $v0, $zero, L_80010F04
    if (ctx->r2 == 0) {
        // 0x80010F00: addiu       $a2, $zero, 0x63
        ctx->r6 = ADD32(0, 0X63);
            goto L_80010F04;
    }
    goto skip_0;
    // 0x80010F00: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    skip_0:
L_80010F04:
    // 0x80010F04: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010F08: addiu       $a1, $a1, -0x31CC
    ctx->r5 = ADD32(ctx->r5, -0X31CC);
    // 0x80010F0C: jal         0x80066CA0
    // 0x80010F10: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x80010F10: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x80010F14: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010F18: j           L_80010FC8
    // 0x80010F1C: addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
        goto L_80010FC8;
    // 0x80010F1C: addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
L_80010F20:
    // 0x80010F20: lw          $a2, 0x104($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X104);
    // 0x80010F24: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010F28: addiu       $a1, $a1, -0x31C8
    ctx->r5 = ADD32(ctx->r5, -0X31C8);
    // 0x80010F2C: jal         0x80066CA0
    // 0x80010F30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_6;
    // 0x80010F30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x80010F34: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010F38: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80010F3C: addiu       $a2, $zero, 0x59
    ctx->r6 = ADD32(0, 0X59);
    // 0x80010F40: jal         0x8004DAB8
    // 0x80010F44: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_7;
    // 0x80010F44: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x80010F48: lhu         $a2, 0x7E($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X7E);
    // 0x80010F4C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010F50: addiu       $a1, $a1, -0x31C4
    ctx->r5 = ADD32(ctx->r5, -0X31C4);
    // 0x80010F54: jal         0x80066CA0
    // 0x80010F58: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_8;
    // 0x80010F58: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_8:
    // 0x80010F5C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010F60: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    // 0x80010F64: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80010F68: jal         0x8004DAB8
    // 0x80010F6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_9;
    // 0x80010F6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // 0x80010F70: lhu         $v1, 0x7E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7E);
    // 0x80010F74: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x80010F78: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x80010F7C: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010F80: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80010F84: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80010F88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80010F8C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80010F90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80010F94: mfhi        $t0
    ctx->r8 = hi;
    // 0x80010F98: srl         $a0, $t0, 3
    ctx->r4 = S32(U32(ctx->r8) >> 3);
    // 0x80010F9C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80010FA0: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x80010FA4: slti        $v0, $a2, 0x64
    ctx->r2 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    // 0x80010FA8: beql        $v0, $zero, L_80010FB0
    if (ctx->r2 == 0) {
        // 0x80010FAC: addiu       $a2, $zero, 0x63
        ctx->r6 = ADD32(0, 0X63);
            goto L_80010FB0;
    }
    goto skip_1;
    // 0x80010FAC: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    skip_1:
L_80010FB0:
    // 0x80010FB0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80010FB4: addiu       $a1, $a1, -0x31CC
    ctx->r5 = ADD32(ctx->r5, -0X31CC);
    // 0x80010FB8: jal         0x80066CA0
    // 0x80010FBC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_10;
    // 0x80010FBC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_10:
    // 0x80010FC0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80010FC4: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
L_80010FC8:
    // 0x80010FC8: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    // 0x80010FCC: jal         0x8004DAB8
    // 0x80010FD0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_11;
    // 0x80010FD0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
L_80010FD4:
    // 0x80010FD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80010FD8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80010FDC: jr          $ra
    // 0x80010FE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80010FE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80010FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010FE8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80010FEC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80010FF0: jal         0x80010E28
    // 0x80010FF4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80010E28(rdram, ctx);
        goto after_0;
    // 0x80010FF4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_0:
    // 0x80010FF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80010FFC: jal         0x80010E28
    // 0x80011000: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80010E28(rdram, ctx);
        goto after_1;
    // 0x80011000: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_1:
    // 0x80011004: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80011008: jr          $ra
    // 0x8001100C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001100C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80011010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011010: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80011014: lb          $v0, 0x5($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X5);
    // 0x80011018: bltz        $v0, L_80011280
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001101C: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_80011280;
    }
    // 0x8001101C: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x80011020: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80011024: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80011028: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x8001102C: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80011030: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011034: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011038: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8001103C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80011040: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80011044: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x80011048: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8001104C: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80011050: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011054: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011058: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x8001105C: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80011060: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80011064: lbu         $v0, 0x5($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X5);
    // 0x80011068: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001106C: bne         $v0, $zero, L_80011078
    if (ctx->r2 != 0) {
        // 0x80011070: addiu       $a3, $zero, 0x22
        ctx->r7 = ADD32(0, 0X22);
            goto L_80011078;
    }
    // 0x80011070: addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    // 0x80011074: addiu       $a3, $zero, 0xCE
    ctx->r7 = ADD32(0, 0XCE);
L_80011078:
    // 0x80011078: lhu         $v0, 0x96($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X96);
    // 0x8001107C: beq         $v0, $zero, L_800110F4
    if (ctx->r2 == 0) {
        // 0x80011080: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_800110F4;
    }
    // 0x80011080: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80011084: sltiu       $v0, $a2, 0x91
    ctx->r2 = ctx->r6 < 0X91 ? 1 : 0;
    // 0x80011088: beql        $v0, $zero, L_80011090
    if (ctx->r2 == 0) {
        // 0x8001108C: addiu       $a2, $zero, 0x90
        ctx->r6 = ADD32(0, 0X90);
            goto L_80011090;
    }
    goto skip_0;
    // 0x8001108C: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    skip_0:
L_80011090:
    // 0x80011090: lui         $v1, 0x7C1
    ctx->r3 = S32(0X7C1 << 16);
    // 0x80011094: ori         $v1, $v1, 0x7C1
    ctx->r3 = ctx->r3 | 0X7C1;
    // 0x80011098: lui         $a0, 0xF600
    ctx->r4 = S32(0XF600 << 16);
    // 0x8001109C: ori         $a0, $a0, 0x35C
    ctx->r4 = ctx->r4 | 0X35C;
    // 0x800110A0: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x800110A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800110A8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800110AC: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x800110B0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x800110B4: addiu       $v0, $a1, 0x20
    ctx->r2 = ADD32(ctx->r5, 0X20);
    // 0x800110B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800110BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800110C0: addiu       $v0, $a3, 0x1F
    ctx->r2 = ADD32(ctx->r7, 0X1F);
    // 0x800110C4: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x800110C8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800110CC: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
    // 0x800110D0: addiu       $v1, $a3, 0x18
    ctx->r3 = ADD32(ctx->r7, 0X18);
    // 0x800110D4: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800110D8: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x800110DC: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x800110E0: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800110E4: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800110E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800110EC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800110F0: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
L_800110F4:
    // 0x800110F4: lhu         $v0, 0x98($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X98);
    // 0x800110F8: beq         $v0, $zero, L_80011178
    if (ctx->r2 == 0) {
        // 0x800110FC: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_80011178;
    }
    // 0x800110FC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80011100: sltiu       $v0, $a2, 0x91
    ctx->r2 = ctx->r6 < 0X91 ? 1 : 0;
    // 0x80011104: beql        $v0, $zero, L_8001110C
    if (ctx->r2 == 0) {
        // 0x80011108: addiu       $a2, $zero, 0x90
        ctx->r6 = ADD32(0, 0X90);
            goto L_8001110C;
    }
    goto skip_1;
    // 0x80011108: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    skip_1:
L_8001110C:
    // 0x8001110C: lui         $v1, 0xFFC1
    ctx->r3 = S32(0XFFC1 << 16);
    // 0x80011110: ori         $v1, $v1, 0xFFC1
    ctx->r3 = ctx->r3 | 0XFFC1;
    // 0x80011114: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80011118: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8001111C: lui         $a1, 0xF600
    ctx->r5 = S32(0XF600 << 16);
    // 0x80011120: ori         $a1, $a1, 0x35C
    ctx->r5 = ctx->r5 | 0X35C;
    // 0x80011124: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80011128: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001112C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011130: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80011134: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80011138: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8001113C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011140: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011144: addiu       $v0, $a3, 0x27
    ctx->r2 = ADD32(ctx->r7, 0X27);
    // 0x80011148: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x8001114C: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80011150: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80011154: addiu       $v1, $a3, 0x20
    ctx->r3 = ADD32(ctx->r7, 0X20);
    // 0x80011158: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8001115C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80011160: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x80011164: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80011168: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8001116C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011170: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80011174: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_80011178:
    // 0x80011178: lhu         $v0, 0x9A($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X9A);
    // 0x8001117C: beq         $v0, $zero, L_800111FC
    if (ctx->r2 == 0) {
        // 0x80011180: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_800111FC;
    }
    // 0x80011180: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80011184: sltiu       $v0, $a2, 0x91
    ctx->r2 = ctx->r6 < 0X91 ? 1 : 0;
    // 0x80011188: beql        $v0, $zero, L_80011190
    if (ctx->r2 == 0) {
        // 0x8001118C: addiu       $a2, $zero, 0x90
        ctx->r6 = ADD32(0, 0X90);
            goto L_80011190;
    }
    goto skip_2;
    // 0x8001118C: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    skip_2:
L_80011190:
    // 0x80011190: lui         $v1, 0x7FF
    ctx->r3 = S32(0X7FF << 16);
    // 0x80011194: ori         $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 | 0X7FF;
    // 0x80011198: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8001119C: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x800111A0: lui         $a1, 0xF600
    ctx->r5 = S32(0XF600 << 16);
    // 0x800111A4: ori         $a1, $a1, 0x35C
    ctx->r5 = ctx->r5 | 0X35C;
    // 0x800111A8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800111AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800111B0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800111B4: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x800111B8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800111BC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x800111C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800111C4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800111C8: addiu       $v0, $a3, 0x2F
    ctx->r2 = ADD32(ctx->r7, 0X2F);
    // 0x800111CC: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x800111D0: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x800111D4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800111D8: addiu       $v1, $a3, 0x28
    ctx->r3 = ADD32(ctx->r7, 0X28);
    // 0x800111DC: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800111E0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800111E4: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x800111E8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800111EC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800111F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800111F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800111F8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_800111FC:
    // 0x800111FC: lhu         $v0, 0x9C($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X9C);
    // 0x80011200: beq         $v0, $zero, L_80011280
    if (ctx->r2 == 0) {
        // 0x80011204: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_80011280;
    }
    // 0x80011204: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80011208: sltiu       $v0, $a2, 0x91
    ctx->r2 = ctx->r6 < 0X91 ? 1 : 0;
    // 0x8001120C: beql        $v0, $zero, L_80011214
    if (ctx->r2 == 0) {
        // 0x80011210: addiu       $a2, $zero, 0x90
        ctx->r6 = ADD32(0, 0X90);
            goto L_80011214;
    }
    goto skip_3;
    // 0x80011210: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    skip_3:
L_80011214:
    // 0x80011214: lui         $v1, 0xF801
    ctx->r3 = S32(0XF801 << 16);
    // 0x80011218: ori         $v1, $v1, 0xF801
    ctx->r3 = ctx->r3 | 0XF801;
    // 0x8001121C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80011220: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80011224: lui         $a1, 0xF600
    ctx->r5 = S32(0XF600 << 16);
    // 0x80011228: ori         $a1, $a1, 0x35C
    ctx->r5 = ctx->r5 | 0X35C;
    // 0x8001122C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80011230: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011234: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011238: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x8001123C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80011240: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80011244: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011248: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001124C: addiu       $v0, $a3, 0x37
    ctx->r2 = ADD32(ctx->r7, 0X37);
    // 0x80011250: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80011254: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80011258: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8001125C: addiu       $v1, $a3, 0x30
    ctx->r3 = ADD32(ctx->r7, 0X30);
    // 0x80011260: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x80011264: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80011268: addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // 0x8001126C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80011270: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80011274: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011278: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001127C: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_80011280:
    // 0x80011280: jr          $ra
    // 0x80011284: nop

    return;
    // 0x80011284: nop

;}
RECOMP_FUNC void func_80011288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011288: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001128C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80011290: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80011294: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80011298: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8001129C:
    // 0x8001129C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800112A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800112A4: lbu         $v0, 0x7B50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B50);
    // 0x800112A8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800112AC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800112B0: lbu         $v1, 0x7B51($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B51);
    // 0x800112B4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800112B8: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800112BC: lbu         $a0, 0x7B52($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B52);
    // 0x800112C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800112C4: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800112C8: lbu         $a1, 0x7B53($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B53);
    // 0x800112CC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800112D0: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800112D4: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x800112D8: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800112DC: sltiu       $v0, $a2, 0x18
    ctx->r2 = ctx->r6 < 0X18 ? 1 : 0;
    // 0x800112E0: bne         $v0, $zero, L_8001129C
    if (ctx->r2 != 0) {
        // 0x800112E4: addu        $t2, $t2, $a1
        ctx->r10 = ADD32(ctx->r10, ctx->r5);
            goto L_8001129C;
    }
    // 0x800112E4: addu        $t2, $t2, $a1
    ctx->r10 = ADD32(ctx->r10, ctx->r5);
    // 0x800112E8: lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // 0x800112EC: ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // 0x800112F0: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800112F4: mfhi        $t3
    ctx->r11 = hi;
    // 0x800112F8: srl         $v1, $t3, 5
    ctx->r3 = S32(U32(ctx->r11) >> 5);
    // 0x800112FC: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80011300: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011304: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80011308: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001130C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011310: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80011314: mfhi        $t3
    ctx->r11 = hi;
    // 0x80011318: srl         $v1, $t3, 5
    ctx->r3 = S32(U32(ctx->r11) >> 5);
    // 0x8001131C: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80011320: sltiu       $v0, $t0, 0x64
    ctx->r2 = ctx->r8 < 0X64 ? 1 : 0;
    // 0x80011324: beql        $v0, $zero, L_8001132C
    if (ctx->r2 == 0) {
        // 0x80011328: addiu       $t0, $zero, 0x63
        ctx->r8 = ADD32(0, 0X63);
            goto L_8001132C;
    }
    goto skip_0;
    // 0x80011328: addiu       $t0, $zero, 0x63
    ctx->r8 = ADD32(0, 0X63);
    skip_0:
L_8001132C:
    // 0x8001132C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80011330: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80011334: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011338: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x8001133C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80011340: sb          $t0, 0x7B68($at)
    MEM_B(0X7B68, ctx->r1) = ctx->r8;
    // 0x80011344: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80011348: sb          $a3, 0x7B69($at)
    MEM_B(0X7B69, ctx->r1) = ctx->r7;
    // 0x8001134C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80011350: sb          $t1, 0x7B6A($at)
    MEM_B(0X7B6A, ctx->r1) = ctx->r9;
    // 0x80011354: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80011358: jr          $ra
    // 0x8001135C: sb          $t2, 0x7B6B($at)
    MEM_B(0X7B6B, ctx->r1) = ctx->r10;
    return;
    // 0x8001135C: sb          $t2, 0x7B6B($at)
    MEM_B(0X7B6B, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_80011360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011360: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80011364: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80011368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001136C: beq         $v0, $zero, L_800114E4
    if (ctx->r2 == 0) {
        // 0x80011370: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800114E4;
    }
    // 0x80011370: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80011374: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80011378: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x8001137C: bne         $v0, $zero, L_800114E4
    if (ctx->r2 != 0) {
        // 0x80011380: nop
    
            goto L_800114E4;
    }
    // 0x80011380: nop

    // 0x80011384: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80011388: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x8001138C: bne         $v0, $zero, L_800114E4
    if (ctx->r2 != 0) {
        // 0x80011390: nop
    
            goto L_800114E4;
    }
    // 0x80011390: nop

    // 0x80011394: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80011398: addiu       $a0, $a0, -0x75C1
    ctx->r4 = ADD32(ctx->r4, -0X75C1);
    // 0x8001139C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800113A0: sltiu       $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 < 0XF0 ? 1 : 0;
    // 0x800113A4: bne         $v0, $zero, L_800113B0
    if (ctx->r2 != 0) {
        // 0x800113A8: addiu       $v0, $v1, 0xA
        ctx->r2 = ADD32(ctx->r3, 0XA);
            goto L_800113B0;
    }
    // 0x800113A8: addiu       $v0, $v1, 0xA
    ctx->r2 = ADD32(ctx->r3, 0XA);
    // 0x800113AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800113B0:
    // 0x800113B0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800113B4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x800113B8: addiu       $v0, $v0, -0x75BC
    ctx->r2 = ADD32(ctx->r2, -0X75BC);
    // 0x800113BC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800113C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800113C4: ldc1        $f0, -0x31C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X31C0);
    // 0x800113C8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800113CC: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x800113D0: nop

    // 0x800113D4: bc1f        L_800113F0
    if (!c1cs) {
        // 0x800113D8: nop
    
            goto L_800113F0;
    }
    // 0x800113D8: nop

    // 0x800113DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800113E0: ldc1        $f0, -0x31B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X31B8);
    // 0x800113E4: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x800113E8: j           L_800113FC
    // 0x800113EC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
        goto L_800113FC;
    // 0x800113EC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
L_800113F0:
    // 0x800113F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800113F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800113F8: nop

L_800113FC:
    // 0x800113FC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80011400: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80011404: lwc1        $f4, -0x75BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75BC);
    // 0x80011408: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001140C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011410: nop

    // 0x80011414: div.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80011418: lui         $at, 0x4330
    ctx->r1 = S32(0X4330 << 16);
    // 0x8001141C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80011420: nop

    // 0x80011424: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80011428: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001142C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80011430: nop

    // 0x80011434: div.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80011438: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x8001143C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80011440: nop

    // 0x80011444: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80011448: div.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001144C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80011450: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80011454: nop

    // 0x80011458: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001145C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80011460: sh          $v0, -0x75EA($at)
    MEM_H(-0X75EA, ctx->r1) = ctx->r2;
    // 0x80011464: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80011468: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001146C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80011470: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80011474: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80011478: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001147C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80011480: addiu       $a0, $a0, -0x75EC
    ctx->r4 = ADD32(ctx->r4, -0X75EC);
    // 0x80011484: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011488: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001148C: sh          $v0, -0x75E2($at)
    MEM_H(-0X75E2, ctx->r1) = ctx->r2;
    // 0x80011490: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80011494: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80011498: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001149C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800114A0: sh          $v0, -0x75D4($at)
    MEM_H(-0X75D4, ctx->r1) = ctx->r2;
    // 0x800114A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800114A8: sh          $v0, -0x75D2($at)
    MEM_H(-0X75D2, ctx->r1) = ctx->r2;
    // 0x800114AC: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800114B0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800114B4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800114B8: nop

    // 0x800114BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800114C0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800114C4: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800114C8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800114CC: nop

    // 0x800114D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800114D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800114D8: sh          $v0, -0x75E4($at)
    MEM_H(-0X75E4, ctx->r1) = ctx->r2;
    // 0x800114DC: jal         0x80017D38
    // 0x800114E0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x800114E0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    after_0:
L_800114E4:
    // 0x800114E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800114E8: jr          $ra
    // 0x800114EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800114EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800114F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800114F0: jr          $ra
    // 0x800114F4: nop

    return;
    // 0x800114F4: nop

;}
RECOMP_FUNC void func_800114F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800114F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800114FC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80011500: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80011504: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80011508: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8001150C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80011510: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80011514: addiu       $s4, $s4, 0x1398
    ctx->r20 = ADD32(ctx->r20, 0X1398);
    // 0x80011518: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001151C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80011520: addiu       $s1, $s1, 0x55A0
    ctx->r17 = ADD32(ctx->r17, 0X55A0);
    // 0x80011524: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80011528: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x8001152C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80011530: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80011534: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
L_80011538:
    // 0x80011538: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001153C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80011540: lb          $v0, 0x55A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X55A0);
    // 0x80011544: beql        $v0, $zero, L_80011584
    if (ctx->r2 == 0) {
        // 0x80011548: addiu       $s1, $s1, 0x38
        ctx->r17 = ADD32(ctx->r17, 0X38);
            goto L_80011584;
    }
    goto skip_0;
    // 0x80011548: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    skip_0:
    // 0x8001154C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80011550: lbu         $v0, 0x7B7D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7D);
    // 0x80011554: beq         $v0, $zero, L_80011568
    if (ctx->r2 == 0) {
        // 0x80011558: nop
    
            goto L_80011568;
    }
    // 0x80011558: nop

    // 0x8001155C: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80011560: bnel        $v0, $s5, L_80011584
    if (ctx->r2 != ctx->r21) {
        // 0x80011564: addiu       $s1, $s1, 0x38
        ctx->r17 = ADD32(ctx->r17, 0X38);
            goto L_80011584;
    }
    goto skip_1;
    // 0x80011564: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    skip_1:
L_80011568:
    // 0x80011568: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8001156C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011570: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80011574: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80011578: jalr        $v0
    // 0x8001157C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001157C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80011580: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
L_80011584:
    // 0x80011584: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80011588: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001158C: slti        $v0, $s3, 0x60
    ctx->r2 = SIGNED(ctx->r19) < 0X60 ? 1 : 0;
    // 0x80011590: bne         $v0, $zero, L_80011538
    if (ctx->r2 != 0) {
        // 0x80011594: addiu       $s2, $s2, 0x38
        ctx->r18 = ADD32(ctx->r18, 0X38);
            goto L_80011538;
    }
    // 0x80011594: addiu       $s2, $s2, 0x38
    ctx->r18 = ADD32(ctx->r18, 0X38);
    // 0x80011598: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8001159C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800115A0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800115A4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800115A8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800115AC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800115B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800115B4: jr          $ra
    // 0x800115B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800115B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800115BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800115BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800115C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800115C4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800115C8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800115CC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x800115D0: addiu       $s3, $s3, 0x13B4
    ctx->r19 = ADD32(ctx->r19, 0X13B4);
    // 0x800115D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800115D8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800115DC: addiu       $s0, $s0, 0x55A0
    ctx->r16 = ADD32(ctx->r16, 0X55A0);
    // 0x800115E0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800115E4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800115E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800115EC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
L_800115F0:
    // 0x800115F0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800115F4: beql        $v0, $zero, L_8001162C
    if (ctx->r2 == 0) {
        // 0x800115F8: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_8001162C;
    }
    goto skip_0;
    // 0x800115F8: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    skip_0:
    // 0x800115FC: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80011600: bnel        $v0, $zero, L_8001162C
    if (ctx->r2 != 0) {
        // 0x80011604: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_8001162C;
    }
    goto skip_1;
    // 0x80011604: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    skip_1:
    // 0x80011608: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001160C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80011610: lb          $v0, 0x55A1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X55A1);
    // 0x80011614: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011618: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8001161C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80011620: jalr        $v0
    // 0x80011624: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80011624: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80011628: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
L_8001162C:
    // 0x8001162C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011630: slti        $v0, $s1, 0x60
    ctx->r2 = SIGNED(ctx->r17) < 0X60 ? 1 : 0;
    // 0x80011634: bne         $v0, $zero, L_800115F0
    if (ctx->r2 != 0) {
        // 0x80011638: addiu       $s2, $s2, 0x38
        ctx->r18 = ADD32(ctx->r18, 0X38);
            goto L_800115F0;
    }
    // 0x80011638: addiu       $s2, $s2, 0x38
    ctx->r18 = ADD32(ctx->r18, 0X38);
    // 0x8001163C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80011640: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80011644: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80011648: addiu       $s3, $s3, 0x13B4
    ctx->r19 = ADD32(ctx->r19, 0X13B4);
    // 0x8001164C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80011650: addiu       $s0, $s0, 0x55A0
    ctx->r16 = ADD32(ctx->r16, 0X55A0);
    // 0x80011654: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80011658:
    // 0x80011658: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8001165C: beql        $v0, $zero, L_80011694
    if (ctx->r2 == 0) {
        // 0x80011660: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_80011694;
    }
    goto skip_2;
    // 0x80011660: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    skip_2:
    // 0x80011664: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80011668: bnel        $v0, $s4, L_80011694
    if (ctx->r2 != ctx->r20) {
        // 0x8001166C: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_80011694;
    }
    goto skip_3;
    // 0x8001166C: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    skip_3:
    // 0x80011670: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80011674: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80011678: lb          $v0, 0x55A1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X55A1);
    // 0x8001167C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011680: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80011684: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80011688: jalr        $v0
    // 0x8001168C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8001168C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80011690: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
L_80011694:
    // 0x80011694: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011698: slti        $v0, $s1, 0x60
    ctx->r2 = SIGNED(ctx->r17) < 0X60 ? 1 : 0;
    // 0x8001169C: bne         $v0, $zero, L_80011658
    if (ctx->r2 != 0) {
        // 0x800116A0: addiu       $s2, $s2, 0x38
        ctx->r18 = ADD32(ctx->r18, 0X38);
            goto L_80011658;
    }
    // 0x800116A0: addiu       $s2, $s2, 0x38
    ctx->r18 = ADD32(ctx->r18, 0X38);
    // 0x800116A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800116A8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800116AC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800116B0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800116B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800116B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800116BC: jr          $ra
    // 0x800116C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800116C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800116C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800116C4: jr          $ra
    // 0x800116C8: nop

    return;
    // 0x800116C8: nop

;}
RECOMP_FUNC void func_800116CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800116CC: addu        $t7, $a0, $zero
    ctx->r15 = ADD32(ctx->r4, 0);
    // 0x800116D0: lbu         $v0, 0x5($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X5);
    // 0x800116D4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800116D8: bne         $v0, $zero, L_800116E4
    if (ctx->r2 != 0) {
        // 0x800116DC: addiu       $t8, $zero, 0xCE
        ctx->r24 = ADD32(0, 0XCE);
            goto L_800116E4;
    }
    // 0x800116DC: addiu       $t8, $zero, 0xCE
    ctx->r24 = ADD32(0, 0XCE);
    // 0x800116E0: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
L_800116E4:
    // 0x800116E4: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x800116E8: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x800116EC: lui         $a1, 0xFC11
    ctx->r5 = S32(0XFC11 << 16);
    // 0x800116F0: ori         $a1, $a1, 0xFE23
    ctx->r5 = ctx->r5 | 0XFE23;
    // 0x800116F4: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x800116F8: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x800116FC: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80011700: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80011704: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80011708: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8001170C: lui         $t2, 0x701
    ctx->r10 = S32(0X701 << 16);
    // 0x80011710: ori         $t2, $t2, 0x4050
    ctx->r10 = ctx->r10 | 0X4050;
    // 0x80011714: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x80011718: ori         $t3, $t3, 0xF100
    ctx->r11 = ctx->r11 | 0XF100;
    // 0x8001171C: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x80011720: ori         $t5, $t5, 0x1000
    ctx->r13 = ctx->r13 | 0X1000;
    // 0x80011724: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80011728: ori         $t4, $t4, 0x4050
    ctx->r12 = ctx->r12 | 0X4050;
    // 0x8001172C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80011730: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80011734: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80011738: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x8001173C: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80011740: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80011744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011748: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001174C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80011750: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011754: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011758: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8001175C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011760: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011764: addiu       $v0, $zero, -0x805
    ctx->r2 = ADD32(0, -0X805);
    // 0x80011768: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8001176C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80011770: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011774: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011778: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8001177C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011780: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011784: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80011788: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001178C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011790: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80011794: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80011798: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001179C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x800117A0: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800117A4: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x800117A8: sw          $a2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r6;
    // 0x800117AC: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x800117B0: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x800117B4: sw          $a3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r7;
    // 0x800117B8: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x800117BC: lbu         $a1, 0x6C($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X6C);
    // 0x800117C0: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x800117C4: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x800117C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800117CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800117D0: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x800117D4: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x800117D8: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800117DC: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x800117E0: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x800117E4: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x800117E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800117EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800117F0: lui         $v0, 0xF510
    ctx->r2 = S32(0XF510 << 16);
    // 0x800117F4: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    // 0x800117F8: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x800117FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011800: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011804: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80011808: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x8001180C: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x80011810: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011814: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011818: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8001181C: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x80011820: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x80011824: sw          $t2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r10;
    // 0x80011828: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8001182C: sw          $t3, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r11;
    // 0x80011830: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011834: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011838: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8001183C: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80011840: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80011844: sll         $a0, $a1, 8
    ctx->r4 = S32(ctx->r5 << 8);
    // 0x80011848: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001184C: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80011850: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // 0x80011854: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x80011858: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x8001185C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011860: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011864: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x80011868: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001186C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011870: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80011874: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
    // 0x80011878: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x8001187C: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x80011880: sw          $t5, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r13;
    // 0x80011884: sw          $t4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r12;
    // 0x80011888: sw          $t6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r14;
    // 0x8001188C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011890: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011894: lb          $v0, 0x58($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X58);
    // 0x80011898: addiu       $a1, $t8, 0x50
    ctx->r5 = ADD32(ctx->r24, 0X50);
    // 0x8001189C: sll         $a1, $a1, 14
    ctx->r5 = S32(ctx->r5 << 14);
    // 0x800118A0: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x800118A4: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    // 0x800118A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800118AC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800118B0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800118B4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800118B8: sw          $a1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r5;
    // 0x800118BC: lb          $a0, 0x58($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X58);
    // 0x800118C0: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x800118C4: addiu       $v0, $v1, 0x78
    ctx->r2 = ADD32(ctx->r3, 0X78);
    // 0x800118C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800118CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800118D0: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x800118D4: sw          $v0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r2;
    // 0x800118D8: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x800118DC: sw          $v0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r2;
    // 0x800118E0: addiu       $v0, $v1, 0x80
    ctx->r2 = ADD32(ctx->r3, 0X80);
    // 0x800118E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800118E8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800118EC: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x800118F0: sw          $v0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r2;
    // 0x800118F4: sll         $v0, $t8, 14
    ctx->r2 = S32(ctx->r24 << 14);
    // 0x800118F8: sw          $a2, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->r6;
    // 0x800118FC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80011900: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80011904: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80011908: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001190C: jr          $ra
    // 0x80011910: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    return;
    // 0x80011910: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80011914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011914: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80011918: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8001191C: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80011920: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80011924: lui         $a2, 0x72F
    ctx->r6 = S32(0X72F << 16);
    // 0x80011928: ori         $a2, $a2, 0xF200
    ctx->r6 = ctx->r6 | 0XF200;
    // 0x8001192C: lui         $a3, 0xF548
    ctx->r7 = S32(0XF548 << 16);
    // 0x80011930: ori         $a3, $a3, 0x800
    ctx->r7 = ctx->r7 | 0X800;
    // 0x80011934: lui         $t0, 0x7
    ctx->r8 = S32(0X7 << 16);
    // 0x80011938: ori         $t0, $t0, 0xC0BC
    ctx->r8 = ctx->r8 | 0XC0BC;
    // 0x8001193C: lui         $t1, 0xF500
    ctx->r9 = S32(0XF500 << 16);
    // 0x80011940: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80011944: lb          $v0, 0x54($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X54);
    // 0x80011948: lw          $v1, 0xDC($t3)
    ctx->r3 = MEM_W(ctx->r11, 0XDC);
    // 0x8001194C: ori         $t1, $t1, 0x100
    ctx->r9 = ctx->r9 | 0X100;
    // 0x80011950: lui         $t2, 0x73F
    ctx->r10 = S32(0X73F << 16);
    // 0x80011954: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011958: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001195C: lb          $v1, 0x4C($t3)
    ctx->r3 = MEM_B(ctx->r11, 0X4C);
    // 0x80011960: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80011964: ori         $t2, $t2, 0xC000
    ctx->r10 = ctx->r10 | 0XC000;
    // 0x80011968: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001196C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80011970: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80011974: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80011978: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8001197C: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x80011980: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80011984: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011988: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001198C: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80011990: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011994: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011998: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8001199C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119A0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119A4: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x800119A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119AC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119B0: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800119B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119B8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119BC: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x800119C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119C4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119C8: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x800119CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119D0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119D4: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x800119D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119DC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119E0: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x800119E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800119E8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800119EC: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x800119F0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800119F4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800119F8: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x800119FC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80011A00: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x80011A04: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80011A08: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x80011A0C: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80011A10: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011A14: addiu       $v1, $v1, -0x5B8
    ctx->r3 = ADD32(ctx->r3, -0X5B8);
    // 0x80011A18: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80011A1C: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x80011A20: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80011A24: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x80011A28: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80011A2C: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x80011A30: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x80011A34: lui         $a2, 0xE700
    ctx->r6 = S32(0XE700 << 16);
    // 0x80011A38: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80011A3C: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80011A40: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x80011A44: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80011A48: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x80011A4C: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x80011A50: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80011A54: sw          $a2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r6;
    // 0x80011A58: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80011A5C: sw          $a3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r7;
    // 0x80011A60: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80011A64: sw          $t0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r8;
    // 0x80011A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011A6C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011A70: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x80011A74: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x80011A78: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011A7C: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x80011A80: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x80011A84: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x80011A88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011A8C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011A90: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x80011A94: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
    // 0x80011A98: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x80011A9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011AA0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011AA4: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x80011AA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011AAC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011AB0: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x80011AB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011AB8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011ABC: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80011AC0: sw          $v1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r3;
    // 0x80011AC4: addiu       $v1, $v0, 0x78
    ctx->r3 = ADD32(ctx->r2, 0X78);
    // 0x80011AC8: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80011ACC: sw          $t1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r9;
    // 0x80011AD0: sw          $a0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r4;
    // 0x80011AD4: sw          $a1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r5;
    // 0x80011AD8: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x80011ADC: sw          $t2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r10;
    // 0x80011AE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011AE4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011AE8: sw          $a2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r6;
    // 0x80011AEC: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x80011AF0: lbu         $v0, 0x5($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X5);
    // 0x80011AF4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80011AF8: bne         $v0, $zero, L_80011B04
    if (ctx->r2 != 0) {
        // 0x80011AFC: addiu       $t5, $zero, 0xCE
        ctx->r13 = ADD32(0, 0XCE);
            goto L_80011B04;
    }
    // 0x80011AFC: addiu       $t5, $zero, 0xCE
    ctx->r13 = ADD32(0, 0XCE);
    // 0x80011B00: addiu       $t5, $zero, 0x22
    ctx->r13 = ADD32(0, 0X22);
L_80011B04:
    // 0x80011B04: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80011B08: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80011B0C: addiu       $s0, $s0, 0x7BC0
    ctx->r16 = ADD32(ctx->r16, 0X7BC0);
    // 0x80011B10: lui         $t9, 0xE400
    ctx->r25 = S32(0XE400 << 16);
    // 0x80011B14: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80011B18: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80011B1C: addu        $t6, $t4, $zero
    ctx->r14 = ADD32(ctx->r12, 0);
L_80011B20:
    // 0x80011B20: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80011B24: addu        $t4, $t6, $zero
    ctx->r12 = ADD32(ctx->r14, 0);
L_80011B28:
    // 0x80011B28: lb          $a3, 0x0($t4)
    ctx->r7 = MEM_B(ctx->r12, 0X0);
    // 0x80011B2C: beql        $a3, $zero, L_80011C8C
    if (ctx->r7 == 0) {
        // 0x80011B30: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80011C8C;
    }
    goto skip_0;
    // 0x80011B30: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x80011B34: lbu         $v0, 0x54($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X54);
    // 0x80011B38: addiu       $v0, $v0, -0x1E
    ctx->r2 = ADD32(ctx->r2, -0X1E);
    // 0x80011B3C: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80011B40: beq         $v0, $zero, L_80011B78
    if (ctx->r2 == 0) {
        // 0x80011B44: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80011B78;
    }
    // 0x80011B44: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80011B48: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80011B4C: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x80011B50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011B54: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80011B58: lb          $v1, -0x3DF3($at)
    ctx->r3 = MEM_B(ctx->r1, -0X3DF3);
    // 0x80011B5C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80011B60: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x80011B64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011B68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80011B6C: lb          $v0, 0x13D0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X13D0);
    // 0x80011B70: j           L_80011B88
    // 0x80011B74: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
        goto L_80011B88;
    // 0x80011B74: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
L_80011B78:
    // 0x80011B78: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80011B7C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80011B80: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80011B84: lb          $t2, -0x3DF3($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X3DF3);
L_80011B88:
    // 0x80011B88: lw          $v0, 0x1C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1C);
    // 0x80011B8C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80011B90: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80011B94: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80011B98: slti        $v0, $v0, 0x39
    ctx->r2 = SIGNED(ctx->r2) < 0X39 ? 1 : 0;
    // 0x80011B9C: bnel        $v0, $zero, L_80011C8C
    if (ctx->r2 != 0) {
        // 0x80011BA0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80011C8C;
    }
    goto skip_1;
    // 0x80011BA0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_1:
    // 0x80011BA4: lw          $v1, 0x18($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X18);
    // 0x80011BA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80011BAC: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80011BB0: lw          $v0, 0x1C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1C);
    // 0x80011BB4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80011BB8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80011BBC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80011BC0: addu        $v1, $t5, $v1
    ctx->r3 = ADD32(ctx->r13, ctx->r3);
    // 0x80011BC4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80011BC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80011BCC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80011BD0: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80011BD4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80011BD8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80011BDC: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x80011BE0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80011BE4: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
    // 0x80011BE8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80011BEC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80011BF0: lw          $v0, 0x18($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X18);
    // 0x80011BF4: lw          $a0, 0x1C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1C);
    // 0x80011BF8: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x80011BFC: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80011C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011C04: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011C08: addiu       $v1, $a1, 0x10
    ctx->r3 = ADD32(ctx->r5, 0X10);
    // 0x80011C0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011C10: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011C14: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80011C18: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80011C1C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80011C20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80011C24: addu        $v0, $t5, $v0
    ctx->r2 = ADD32(ctx->r13, ctx->r2);
    // 0x80011C28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011C2C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80011C30: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80011C34: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80011C38: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80011C3C: addiu       $a0, $a0, 0xE0
    ctx->r4 = ADD32(ctx->r4, 0XE0);
    // 0x80011C40: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80011C44: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80011C48: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80011C4C: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80011C50: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011C54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80011C58: lb          $v1, -0x3DF4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DF4);
    // 0x80011C5C: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80011C60: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80011C64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011C68: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80011C6C: sll         $v0, $t2, 5
    ctx->r2 = S32(ctx->r10 << 5);
    // 0x80011C70: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011C74: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x80011C78: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    // 0x80011C7C: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x80011C80: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80011C84: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80011C88: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80011C8C:
    // 0x80011C8C: slti        $v0, $t0, 0x5
    ctx->r2 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80011C90: bne         $v0, $zero, L_80011B28
    if (ctx->r2 != 0) {
        // 0x80011C94: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_80011B28;
    }
    // 0x80011C94: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80011C98: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80011C9C: slti        $v0, $t1, 0x5
    ctx->r2 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80011CA0: bne         $v0, $zero, L_80011B20
    if (ctx->r2 != 0) {
        // 0x80011CA4: addiu       $t6, $t6, 0x5
        ctx->r14 = ADD32(ctx->r14, 0X5);
            goto L_80011B20;
    }
    // 0x80011CA4: addiu       $t6, $t6, 0x5
    ctx->r14 = ADD32(ctx->r14, 0X5);
    // 0x80011CA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80011CAC: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80011CB0: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80011CB4: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80011CB8: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80011CBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011CC0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011CC4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80011CC8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80011CCC: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80011CD0: jr          $ra
    // 0x80011CD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80011CD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80011CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011CDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80011CE0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80011CE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011CE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011CEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011CF0: lb          $v0, 0x54($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X54);
    // 0x80011CF4: lw          $v1, 0xDC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XDC);
    // 0x80011CF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011CFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80011D00: lb          $v1, 0x4C($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X4C);
    // 0x80011D04: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80011D08: lw          $s0, 0x1C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1C);
    // 0x80011D0C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80011D10: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80011D14: lw          $s2, 0x0($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X0);
L_80011D18:
    // 0x80011D18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80011D1C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80011D20: jal         0x800151FC
    // 0x80011D24: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_800151FC(rdram, ctx);
        goto after_0;
    // 0x80011D24: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_0:
    // 0x80011D28: bne         $v0, $zero, L_80011D40
    if (ctx->r2 != 0) {
        // 0x80011D2C: lui         $a0, 0xBA00
        ctx->r4 = S32(0XBA00 << 16);
            goto L_80011D40;
    }
    // 0x80011D2C: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80011D30: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80011D34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80011D38: j           L_80011D18
    // 0x80011D3C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_80011D18;
    // 0x80011D3C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_80011D40:
    // 0x80011D40: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80011D44: lui         $a3, 0xFC11
    ctx->r7 = S32(0XFC11 << 16);
    // 0x80011D48: ori         $a3, $a3, 0x9623
    ctx->r7 = ctx->r7 | 0X9623;
    // 0x80011D4C: lui         $a1, 0xFF2F
    ctx->r5 = S32(0XFF2F << 16);
    // 0x80011D50: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80011D54: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80011D58: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80011D5C: lui         $a2, 0x40
    ctx->r6 = S32(0X40 << 16);
    // 0x80011D60: ori         $a2, $a2, 0x4240
    ctx->r6 = ctx->r6 | 0X4240;
    // 0x80011D64: lui         $t1, 0x72F
    ctx->r9 = S32(0X72F << 16);
    // 0x80011D68: ori         $t1, $t1, 0xF200
    ctx->r9 = ctx->r9 | 0XF200;
    // 0x80011D6C: lui         $t2, 0xF548
    ctx->r10 = S32(0XF548 << 16);
    // 0x80011D70: ori         $t2, $t2, 0x800
    ctx->r10 = ctx->r10 | 0X800;
    // 0x80011D74: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x80011D78: ori         $t3, $t3, 0xC0BC
    ctx->r11 = ctx->r11 | 0XC0BC;
    // 0x80011D7C: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x80011D80: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x80011D84: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
    // 0x80011D88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80011D8C: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80011D90: lui         $t5, 0x73F
    ctx->r13 = S32(0X73F << 16);
    // 0x80011D94: ori         $t5, $t5, 0xC000
    ctx->r13 = ctx->r13 | 0XC000;
    // 0x80011D98: sw          $s0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r16;
    // 0x80011D9C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80011DA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011DA4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011DA8: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80011DAC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80011DB0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011DB4: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x80011DB8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80011DBC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80011DC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011DC4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011DC8: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x80011DCC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80011DD0: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80011DD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011DD8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011DDC: lui         $v1, 0xFA00
    ctx->r3 = S32(0XFA00 << 16);
    // 0x80011DE0: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80011DE4: addiu       $v1, $zero, -0xC0
    ctx->r3 = ADD32(0, -0XC0);
    // 0x80011DE8: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80011DEC: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80011DF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011DF4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011DF8: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80011DFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E00: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E04: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x80011E08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E0C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E10: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x80011E14: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80011E18: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011E1C: addiu       $v1, $v1, -0x5B8
    ctx->r3 = ADD32(ctx->r3, -0X5B8);
    // 0x80011E20: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x80011E24: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x80011E28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E2C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E30: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x80011E34: sw          $a2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r6;
    // 0x80011E38: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80011E3C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80011E40: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x80011E44: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x80011E48: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x80011E4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E50: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E54: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x80011E58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E5C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E60: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x80011E64: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x80011E68: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80011E6C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80011E70: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x80011E74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011E78: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011E7C: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x80011E80: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x80011E84: sw          $t0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r8;
    // 0x80011E88: sw          $a2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r6;
    // 0x80011E8C: sw          $a1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r5;
    // 0x80011E90: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80011E94: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80011E98: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
    // 0x80011E9C: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    // 0x80011EA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011EA4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011EA8: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x80011EAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011EB0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011EB4: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80011EB8: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x80011EBC: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x80011EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011EC4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011EC8: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x80011ECC: sw          $v1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r3;
    // 0x80011ED0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011ED4: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x80011ED8: sw          $v1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r3;
    // 0x80011EDC: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x80011EE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011EE4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011EE8: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x80011EEC: sw          $v1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r3;
    // 0x80011EF0: addiu       $v1, $v0, 0x78
    ctx->r3 = ADD32(ctx->r2, 0X78);
    // 0x80011EF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011EF8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011EFC: addiu       $v1, $v0, 0x80
    ctx->r3 = ADD32(ctx->r2, 0X80);
    // 0x80011F00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011F04: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011F08: addiu       $v1, $v0, 0x88
    ctx->r3 = ADD32(ctx->r2, 0X88);
    // 0x80011F0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011F10: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011F14: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80011F18: sw          $v1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r3;
    // 0x80011F1C: addiu       $v1, $v0, 0x90
    ctx->r3 = ADD32(ctx->r2, 0X90);
    // 0x80011F20: sw          $t2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r10;
    // 0x80011F24: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80011F28: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x80011F2C: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80011F30: sw          $t4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r12;
    // 0x80011F34: sw          $a2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r6;
    // 0x80011F38: sw          $a1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r5;
    // 0x80011F3C: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x80011F40: sw          $t5, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r13;
    // 0x80011F44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011F48: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80011F4C: sw          $a0, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r4;
    // 0x80011F50: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x80011F54: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80011F58: addiu       $t2, $zero, 0xCE
    ctx->r10 = ADD32(0, 0XCE);
    // 0x80011F5C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80011F60: bne         $v0, $zero, L_80011F6C
    if (ctx->r2 != 0) {
        // 0x80011F64: addiu       $t6, $t6, -0x1
        ctx->r14 = ADD32(ctx->r14, -0X1);
            goto L_80011F6C;
    }
    // 0x80011F64: addiu       $t6, $t6, -0x1
    ctx->r14 = ADD32(ctx->r14, -0X1);
    // 0x80011F68: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
L_80011F6C:
    // 0x80011F6C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80011F70: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80011F74: addiu       $t7, $t7, 0x7BC0
    ctx->r15 = ADD32(ctx->r15, 0X7BC0);
    // 0x80011F78: lui         $t8, 0xE400
    ctx->r24 = S32(0XE400 << 16);
    // 0x80011F7C: addu        $t3, $s2, $zero
    ctx->r11 = ADD32(ctx->r18, 0);
L_80011F80:
    // 0x80011F80: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80011F84: addu        $v1, $t6, $t1
    ctx->r3 = ADD32(ctx->r14, ctx->r9);
    // 0x80011F88: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80011F8C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80011F90: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x80011F94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80011F98: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80011F9C: or          $t5, $v0, $t8
    ctx->r13 = ctx->r2 | ctx->r24;
    // 0x80011FA0: addiu       $v1, $v1, 0x48
    ctx->r3 = ADD32(ctx->r3, 0X48);
    // 0x80011FA4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80011FA8: andi        $t4, $v1, 0xFFF
    ctx->r12 = ctx->r3 & 0XFFF;
    // 0x80011FAC: addu        $t0, $t3, $zero
    ctx->r8 = ADD32(ctx->r11, 0);
L_80011FB0:
    // 0x80011FB0: lb          $a2, 0x0($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X0);
    // 0x80011FB4: beql        $a2, $zero, L_800120D4
    if (ctx->r6 == 0) {
        // 0x80011FB8: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800120D4;
    }
    goto skip_0;
    // 0x80011FB8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x80011FBC: lbu         $v0, 0x54($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X54);
    // 0x80011FC0: addiu       $v0, $v0, -0x1E
    ctx->r2 = ADD32(ctx->r2, -0X1E);
    // 0x80011FC4: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80011FC8: beq         $v0, $zero, L_80012000
    if (ctx->r2 == 0) {
        // 0x80011FCC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80012000;
    }
    // 0x80011FCC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80011FD0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x80011FD4: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80011FD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011FDC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80011FE0: lb          $v1, -0x3DF3($at)
    ctx->r3 = MEM_B(ctx->r1, -0X3DF3);
    // 0x80011FE4: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80011FE8: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x80011FEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011FF0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80011FF4: lb          $v0, 0x13D8($at)
    ctx->r2 = MEM_B(ctx->r1, 0X13D8);
    // 0x80011FF8: j           L_80012010
    // 0x80011FFC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
        goto L_80012010;
    // 0x80011FFC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_80012000:
    // 0x80012000: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80012004: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80012008: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8001200C: lb          $s0, -0x3DF3($s0)
    ctx->r16 = MEM_B(ctx->r16, -0X3DF3);
L_80012010:
    // 0x80012010: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80012014: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80012018: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8001201C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80012020: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80012024: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80012028: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x8001202C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80012030: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012034: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80012038: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8001203C: or          $v0, $v0, $t5
    ctx->r2 = ctx->r2 | ctx->r13;
    // 0x80012040: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80012044: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80012048: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x8001204C: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x80012050: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012054: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012058: addiu       $v1, $a0, 0x10
    ctx->r3 = ADD32(ctx->r4, 0X10);
    // 0x8001205C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012060: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012064: lui         $v1, 0xB400
    ctx->r3 = S32(0XB400 << 16);
    // 0x80012068: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x8001206C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80012070: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80012074: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80012078: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x8001207C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012080: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80012084: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80012088: or          $v0, $v0, $t4
    ctx->r2 = ctx->r2 | ctx->r12;
    // 0x8001208C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80012090: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80012094: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012098: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001209C: lb          $v1, -0x3DF4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DF4);
    // 0x800120A0: ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    // 0x800120A4: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x800120A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800120AC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800120B0: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x800120B4: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800120B8: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x800120BC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800120C0: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x800120C4: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x800120C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800120CC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800120D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800120D4:
    // 0x800120D4: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x800120D8: bne         $v0, $zero, L_80011FB0
    if (ctx->r2 != 0) {
        // 0x800120DC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80011FB0;
    }
    // 0x800120DC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800120E0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800120E4: slti        $v0, $t1, 0x5
    ctx->r2 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x800120E8: bne         $v0, $zero, L_80011F80
    if (ctx->r2 != 0) {
        // 0x800120EC: addiu       $t3, $t3, 0x5
        ctx->r11 = ADD32(ctx->r11, 0X5);
            goto L_80011F80;
    }
    // 0x800120EC: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x800120F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800120F4: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x800120F8: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x800120FC: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80012100: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80012104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012108: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001210C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80012110: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80012114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80012118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001211C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012124: jr          $ra
    // 0x80012128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80012128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001212C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001212C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80012130: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80012134: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80012138: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8001213C: lui         $a1, 0xBA00
    ctx->r5 = S32(0XBA00 << 16);
    // 0x80012140: ori         $a1, $a1, 0x1301
    ctx->r5 = ctx->r5 | 0X1301;
    // 0x80012144: lui         $a3, 0xB900
    ctx->r7 = S32(0XB900 << 16);
    // 0x80012148: ori         $a3, $a3, 0x31D
    ctx->r7 = ctx->r7 | 0X31D;
    // 0x8001214C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80012150: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80012154: lui         $a2, 0xF0A
    ctx->r6 = S32(0XF0A << 16);
    // 0x80012158: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x8001215C: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80012160: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80012164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012168: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001216C: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x80012170: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80012174: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80012178: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001217C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012180: lui         $v1, 0x30
    ctx->r3 = S32(0X30 << 16);
    // 0x80012184: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80012188: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8001218C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012190: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012194: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80012198: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001219C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800121A0: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800121A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800121A8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800121AC: lui         $v1, 0xF700
    ctx->r3 = S32(0XF700 << 16);
    // 0x800121B0: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800121B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800121B8: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800121BC: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x800121C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800121C4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800121C8: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x800121CC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800121D0: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x800121D4: sw          $a2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r6;
    // 0x800121D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800121DC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800121E0: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
    // 0x800121E4: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x800121E8: lbu         $v0, 0x5($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X5);
    // 0x800121EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800121F0: bne         $v0, $zero, L_800121FC
    if (ctx->r2 != 0) {
        // 0x800121F4: addiu       $t3, $zero, 0xCE
        ctx->r11 = ADD32(0, 0XCE);
            goto L_800121FC;
    }
    // 0x800121F4: addiu       $t3, $zero, 0xCE
    ctx->r11 = ADD32(0, 0XCE);
    // 0x800121F8: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
L_800121FC:
    // 0x800121FC: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x80012200: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x80012204: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80012208: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001220C: lui         $t8, 0xF600
    ctx->r24 = S32(0XF600 << 16);
    // 0x80012210: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80012214: addiu       $t7, $zero, 0x132
    ctx->r15 = ADD32(0, 0X132);
L_80012218:
    // 0x80012218: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001221C: subu        $v0, $s0, $t4
    ctx->r2 = SUB32(ctx->r16, ctx->r12);
    // 0x80012220: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80012224: subu        $v0, $t9, $t4
    ctx->r2 = SUB32(ctx->r25, ctx->r12);
    // 0x80012228: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x8001222C: addu        $t2, $t3, $zero
    ctx->r10 = ADD32(ctx->r11, 0);
    // 0x80012230: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80012234: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_80012238:
    // 0x80012238: lw          $v0, 0xB0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XB0);
    // 0x8001223C: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80012240: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80012244: lbu         $a0, 0x70($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X70);
    // 0x80012248: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001224C: beq         $v0, $zero, L_800123CC
    if (ctx->r2 == 0) {
        // 0x80012250: srl         $v1, $v0, 6
        ctx->r3 = S32(U32(ctx->r2) >> 6);
            goto L_800123CC;
    }
    // 0x80012250: srl         $v1, $v0, 6
    ctx->r3 = S32(U32(ctx->r2) >> 6);
    // 0x80012254: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80012258: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8001225C: xori        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 ^ 0X80;
    // 0x80012260: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80012264: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80012268: beq         $v1, $zero, L_800123CC
    if (ctx->r3 == 0) {
        // 0x8001226C: andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
            goto L_800123CC;
    }
    // 0x8001226C: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x80012270: beq         $v0, $zero, L_8001233C
    if (ctx->r2 == 0) {
        // 0x80012274: addu        $v1, $t3, $a2
        ctx->r3 = ADD32(ctx->r11, ctx->r6);
            goto L_8001233C;
    }
    // 0x80012274: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x80012278: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8001227C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80012280: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80012284: nop

    // 0x80012288: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x8001228C: slti        $v0, $v0, 0x50
    ctx->r2 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x80012290: beq         $v0, $zero, L_800123CC
    if (ctx->r2 == 0) {
        // 0x80012294: addu        $v0, $a2, $v1
        ctx->r2 = ADD32(ctx->r6, ctx->r3);
            goto L_800123CC;
    }
    // 0x80012294: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80012298: blez        $v0, L_800123CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001229C: addu        $v1, $t3, $a2
        ctx->r3 = ADD32(ctx->r11, ctx->r6);
            goto L_800123CC;
    }
    // 0x8001229C: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x800122A0: lwc1        $f2, 0x10($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800122A4: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x800122A8: nop

    // 0x800122AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800122B0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800122B4: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800122B8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800122BC: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x800122C0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800122C4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800122C8: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800122CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800122D0: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x800122D4: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800122D8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800122DC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800122E0: nop

    // 0x800122E4: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800122E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800122EC: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x800122F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800122F4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800122F8: lwc1        $f2, 0x10($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800122FC: mtc1        $t5, $f0
    ctx->f0.u32l = ctx->r13;
    // 0x80012300: nop

    // 0x80012304: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80012308: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001230C: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80012310: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80012314: addu        $v1, $t3, $a3
    ctx->r3 = ADD32(ctx->r11, ctx->r7);
    // 0x80012318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001231C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012320: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80012324: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80012328: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8001232C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80012330: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x80012334: j           L_800123B0
    // 0x80012338: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
        goto L_800123B0;
    // 0x80012338: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
L_8001233C:
    // 0x8001233C: lwc1        $f2, 0x10($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80012340: mtc1        $t6, $f0
    ctx->f0.u32l = ctx->r14;
    // 0x80012344: nop

    // 0x80012348: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001234C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80012350: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80012354: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80012358: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8001235C: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x80012360: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x80012364: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80012368: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001236C: nop

    // 0x80012370: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80012374: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012378: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x8001237C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80012380: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80012384: lwc1        $f2, 0x10($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80012388: mtc1        $t5, $f0
    ctx->f0.u32l = ctx->r13;
    // 0x8001238C: nop

    // 0x80012390: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80012394: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80012398: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8001239C: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800123A0: andi        $v1, $t2, 0x3FF
    ctx->r3 = ctx->r10 & 0X3FF;
    // 0x800123A4: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x800123A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800123AC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
L_800123B0:
    // 0x800123B0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800123B4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800123B8: nop

    // 0x800123BC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800123C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800123C4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800123C8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_800123CC:
    // 0x800123CC: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800123D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800123D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800123D8: slti        $v0, $t1, 0xA
    ctx->r2 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x800123DC: bne         $v0, $zero, L_80012238
    if (ctx->r2 != 0) {
        // 0x800123E0: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80012238;
    }
    // 0x800123E0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800123E4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800123E8: bgez        $t4, L_80012218
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800123EC: addiu       $t7, $t7, -0x12
        ctx->r15 = ADD32(ctx->r15, -0X12);
            goto L_80012218;
    }
    // 0x800123EC: addiu       $t7, $t7, -0x12
    ctx->r15 = ADD32(ctx->r15, -0X12);
    // 0x800123F0: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800123F4: jr          $ra
    // 0x800123F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800123F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800123FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80012400: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80012404: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80012408: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001240C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80012410: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80012414: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80012418: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001241C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012420: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012424: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012428: lbu         $v0, 0x5($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X5);
    // 0x8001242C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80012430: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80012434: bne         $v0, $zero, L_80012440
    if (ctx->r2 != 0) {
        // 0x80012438: addiu       $t9, $zero, 0xCE
        ctx->r25 = ADD32(0, 0XCE);
            goto L_80012440;
    }
    // 0x80012438: addiu       $t9, $zero, 0xCE
    ctx->r25 = ADD32(0, 0XCE);
    // 0x8001243C: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
L_80012440:
    // 0x80012440: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80012444: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80012448: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8001244C: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80012450: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80012454: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012458: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001245C: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80012460: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80012464: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012468: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x8001246C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80012470: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80012474: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012478: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001247C: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80012480: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x80012484: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80012488: lbu         $v0, 0x6B($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X6B);
    // 0x8001248C: srl         $v1, $v0, 2
    ctx->r3 = S32(U32(ctx->r2) >> 2);
    // 0x80012490: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80012494: beql        $v0, $zero, L_8001249C
    if (ctx->r2 == 0) {
        // 0x80012498: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8001249C;
    }
    goto skip_0;
    // 0x80012498: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_0:
L_8001249C:
    // 0x8001249C: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x800124A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800124A4: addiu       $v0, $v0, 0x13E0
    ctx->r2 = ADD32(ctx->r2, 0X13E0);
    // 0x800124A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800124AC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800124B0: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
    // 0x800124B4: lui         $s2, 0xE600
    ctx->r18 = S32(0XE600 << 16);
    // 0x800124B8: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x800124BC: lui         $s4, 0xF548
    ctx->r20 = S32(0XF548 << 16);
    // 0x800124C0: ori         $s4, $s4, 0x800
    ctx->r20 = ctx->r20 | 0X800;
    // 0x800124C4: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x800124C8: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x800124CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800124D0: addiu       $v0, $v0, 0x13EC
    ctx->r2 = ADD32(ctx->r2, 0X13EC);
    // 0x800124D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800124D8: lui         $s7, 0xE400
    ctx->r23 = S32(0XE400 << 16);
    // 0x800124DC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800124E0: sw          $v1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r3;
    // 0x800124E4: lw          $v0, 0xB0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XB0);
    // 0x800124E8: lui         $s6, 0xB400
    ctx->r22 = S32(0XB400 << 16);
    // 0x800124EC: lui         $s5, 0xB300
    ctx->r21 = S32(0XB300 << 16);
    // 0x800124F0: addiu       $t8, $v0, 0x1A2
    ctx->r24 = ADD32(ctx->r2, 0X1A2);
L_800124F4:
    // 0x800124F4: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x800124F8: andi        $v0, $a2, 0x80
    ctx->r2 = ctx->r6 & 0X80;
    // 0x800124FC: beq         $v0, $zero, L_80012668
    if (ctx->r2 == 0) {
        // 0x80012500: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80012668;
    }
    // 0x80012500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80012504: beq         $s0, $v0, L_800127CC
    if (ctx->r16 == ctx->r2) {
        // 0x80012508: lui         $s4, 0xFD50
        ctx->r20 = S32(0XFD50 << 16);
            goto L_800127CC;
    }
    // 0x80012508: lui         $s4, 0xFD50
    ctx->r20 = S32(0XFD50 << 16);
    // 0x8001250C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80012510: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80012514: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80012518: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8001251C: lw          $s4, 0x4($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4);
    // 0x80012520: lui         $v0, 0x71F
    ctx->r2 = S32(0X71F << 16);
    // 0x80012524: ori         $v0, $v0, 0xF200
    ctx->r2 = ctx->r2 | 0XF200;
    // 0x80012528: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8001252C: lui         $a1, 0x7
    ctx->r5 = S32(0X7 << 16);
    // 0x80012530: lui         $s4, 0xF550
    ctx->r20 = S32(0XF550 << 16);
    // 0x80012534: sw          $s4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r20;
    // 0x80012538: lui         $s4, 0xF300
    ctx->r20 = S32(0XF300 << 16);
    // 0x8001253C: sw          $s3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r19;
    // 0x80012540: sw          $s2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r18;
    // 0x80012544: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80012548: sw          $s4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r20;
    // 0x8001254C: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x80012550: sw          $s1, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r17;
    // 0x80012554: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80012558: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x8001255C: ori         $a1, $a1, 0xC07C
    ctx->r5 = ctx->r5 | 0XC07C;
    // 0x80012560: lui         $a2, 0xF500
    ctx->r6 = S32(0XF500 << 16);
    // 0x80012564: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80012568: sw          $fp, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r30;
    // 0x8001256C: sw          $a1, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r5;
    // 0x80012570: sw          $s4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r20;
    // 0x80012574: lui         $s4, 0xFD10
    ctx->r20 = S32(0XFD10 << 16);
    // 0x80012578: sw          $s4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r20;
    // 0x8001257C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80012580: lw          $s4, 0xC($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC);
    // 0x80012584: ori         $a2, $a2, 0x100
    ctx->r6 = ctx->r6 | 0X100;
    // 0x80012588: lui         $a3, 0x73F
    ctx->r7 = S32(0X73F << 16);
    // 0x8001258C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80012590: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x80012594: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80012598: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001259C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125A0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800125A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125A8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125AC: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x800125B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125B4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125B8: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x800125BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125C0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125C4: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x800125C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125D0: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x800125D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125D8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125DC: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x800125E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125E4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125E8: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x800125EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800125F4: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x800125F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800125FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012600: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x80012604: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012608: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001260C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80012610: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x80012614: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x80012618: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8001261C: sw          $a2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r6;
    // 0x80012620: sw          $s3, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r19;
    // 0x80012624: sw          $a0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r4;
    // 0x80012628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001262C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012630: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x80012634: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012638: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001263C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80012640: sw          $v0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r2;
    // 0x80012644: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x80012648: sw          $s2, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r18;
    // 0x8001264C: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x80012650: sw          $a3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r7;
    // 0x80012654: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012658: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001265C: sw          $s1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r17;
    // 0x80012660: j           L_800127CC
    // 0x80012664: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
        goto L_800127CC;
    // 0x80012664: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
L_80012668:
    // 0x80012668: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001266C: beq         $s0, $v0, L_800127CC
    if (ctx->r16 == ctx->r2) {
        // 0x80012670: lui         $a0, 0x73F
        ctx->r4 = S32(0X73F << 16);
            goto L_800127CC;
    }
    // 0x80012670: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x80012674: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80012678: ori         $a0, $a0, 0xF200
    ctx->r4 = ctx->r4 | 0XF200;
    // 0x8001267C: lui         $a1, 0x7
    ctx->r5 = S32(0X7 << 16);
    // 0x80012680: ori         $a1, $a1, 0xC0FC
    ctx->r5 = ctx->r5 | 0XC0FC;
    // 0x80012684: lui         $a2, 0xF500
    ctx->r6 = S32(0XF500 << 16);
    // 0x80012688: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001268C: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80012690: ori         $a2, $a2, 0x100
    ctx->r6 = ctx->r6 | 0X100;
    // 0x80012694: lui         $a3, 0x73F
    ctx->r7 = S32(0X73F << 16);
    // 0x80012698: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8001269C: lui         $s4, 0xFD50
    ctx->r20 = S32(0XFD50 << 16);
    // 0x800126A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800126A4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800126A8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800126AC: addiu       $v1, $v1, -0xA98
    ctx->r3 = ADD32(ctx->r3, -0XA98);
    // 0x800126B0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800126B4: lui         $s4, 0xF550
    ctx->r20 = S32(0XF550 << 16);
    // 0x800126B8: sw          $s4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r20;
    // 0x800126BC: lui         $s4, 0xF300
    ctx->r20 = S32(0XF300 << 16);
    // 0x800126C0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800126C4: sw          $s3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r19;
    // 0x800126C8: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800126CC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800126D0: sw          $s4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r20;
    // 0x800126D4: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x800126D8: sw          $s1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r17;
    // 0x800126DC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x800126E0: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x800126E4: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x800126E8: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800126EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800126F0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800126F4: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x800126F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800126FC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012700: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80012704: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012708: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001270C: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80012710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012714: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012718: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8001271C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012720: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012724: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x80012728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001272C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012730: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x80012734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012738: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001273C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012740: addiu       $v1, $v1, -0x690
    ctx->r3 = ADD32(ctx->r3, -0X690);
    // 0x80012744: sw          $v1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r3;
    // 0x80012748: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8001274C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012750: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012754: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x80012758: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8001275C: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80012760: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012764: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012768: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x8001276C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012770: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012774: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x80012778: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8001277C: sw          $fp, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r30;
    // 0x80012780: sw          $a1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r5;
    // 0x80012784: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x80012788: sw          $a2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r6;
    // 0x8001278C: sw          $s3, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r19;
    // 0x80012790: sw          $s4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r20;
    // 0x80012794: lui         $s4, 0xFD10
    ctx->r20 = S32(0XFD10 << 16);
    // 0x80012798: sw          $s4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r20;
    // 0x8001279C: sw          $s2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r18;
    // 0x800127A0: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x800127A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800127A8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800127AC: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x800127B0: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x800127B4: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x800127B8: sw          $a3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r7;
    // 0x800127BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800127C0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800127C4: sw          $s1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r17;
    // 0x800127C8: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
L_800127CC:
    // 0x800127CC: addu        $t3, $t8, $zero
    ctx->r11 = ADD32(ctx->r24, 0);
    // 0x800127D0: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800127D4: addiu       $s4, $zero, 0x11
    ctx->r20 = ADD32(0, 0X11);
    // 0x800127D8: subu        $v0, $s4, $t7
    ctx->r2 = SUB32(ctx->r20, ctx->r15);
    // 0x800127DC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800127E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x800127E4: subu        $v0, $s4, $t7
    ctx->r2 = SUB32(ctx->r20, ctx->r15);
    // 0x800127E8: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800127EC: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x800127F0: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x800127F4: addu        $t1, $t9, $zero
    ctx->r9 = ADD32(ctx->r25, 0);
    // 0x800127F8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_800127FC:
    // 0x800127FC: lbu         $a2, 0x0($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X0);
    // 0x80012800: beq         $a2, $zero, L_800129D0
    if (ctx->r6 == 0) {
        // 0x80012804: andi        $v0, $a2, 0x40
        ctx->r2 = ctx->r6 & 0X40;
            goto L_800129D0;
    }
    // 0x80012804: andi        $v0, $a2, 0x40
    ctx->r2 = ctx->r6 & 0X40;
    // 0x80012808: bnel        $v0, $zero, L_800129D4
    if (ctx->r2 != 0) {
        // 0x8001280C: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800129D4;
    }
    goto skip_1;
    // 0x8001280C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_1:
    // 0x80012810: andi        $v0, $a2, 0x80
    ctx->r2 = ctx->r6 & 0X80;
    // 0x80012814: beq         $v0, $zero, L_800128B0
    if (ctx->r2 == 0) {
        // 0x80012818: addu        $v1, $t9, $a3
        ctx->r3 = ADD32(ctx->r25, ctx->r7);
            goto L_800128B0;
    }
    // 0x80012818: addu        $v1, $t9, $a3
    ctx->r3 = ADD32(ctx->r25, ctx->r7);
    // 0x8001281C: andi        $a2, $a2, 0x1F
    ctx->r6 = ctx->r6 & 0X1F;
    // 0x80012820: beq         $a2, $zero, L_800129D4
    if (ctx->r6 == 0) {
        // 0x80012824: sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3 << 2);
            goto L_800129D4;
    }
    // 0x80012824: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80012828: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8001282C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80012830: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80012834: mtc1        $t6, $f2
    ctx->f2.u32l = ctx->r14;
    // 0x80012838: nop

    // 0x8001283C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80012840: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80012844: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80012848: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001284C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012850: lb          $v0, 0x58($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X58);
    // 0x80012854: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    // 0x80012858: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001285C: nop

    // 0x80012860: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80012864: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80012868: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001286C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80012870: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80012874: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80012878: nop

    // 0x8001287C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012880: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80012884: or          $v0, $v0, $s7
    ctx->r2 = ctx->r2 | ctx->r23;
    // 0x80012888: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001288C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80012890: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80012894: lb          $v1, 0x58($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X58);
    // 0x80012898: mtc1        $t5, $f2
    ctx->f2.u32l = ctx->r13;
    // 0x8001289C: nop

    // 0x800128A0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800128A4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800128A8: j           L_8001293C
    // 0x800128AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_8001293C;
    // 0x800128AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800128B0:
    // 0x800128B0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800128B4: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x800128B8: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800128BC: mtc1        $t6, $f2
    ctx->f2.u32l = ctx->r14;
    // 0x800128C0: nop

    // 0x800128C4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800128C8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800128CC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800128D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800128D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800128D8: lb          $v0, 0x58($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X58);
    // 0x800128DC: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    // 0x800128E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800128E4: nop

    // 0x800128E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800128EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800128F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800128F4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800128F8: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800128FC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80012900: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80012904: nop

    // 0x80012908: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001290C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80012910: or          $v0, $v0, $s7
    ctx->r2 = ctx->r2 | ctx->r23;
    // 0x80012914: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80012918: andi        $v0, $a2, 0x1F
    ctx->r2 = ctx->r6 & 0X1F;
    // 0x8001291C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80012920: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80012924: lb          $v1, 0x58($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X58);
    // 0x80012928: mtc1        $t5, $f2
    ctx->f2.u32l = ctx->r13;
    // 0x8001292C: nop

    // 0x80012930: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80012934: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80012938: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_8001293C:
    // 0x8001293C: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80012940: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012944: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012948: sw          $s6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r22;
    // 0x8001294C: addiu       $v1, $v1, 0xD8
    ctx->r3 = ADD32(ctx->r3, 0XD8);
    // 0x80012950: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80012954: nop

    // 0x80012958: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001295C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80012960: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80012964: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80012968: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8001296C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80012970: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80012974: nop

    // 0x80012978: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001297C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80012980: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80012984: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80012988: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001298C: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80012990: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012994: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80012998: lb          $a0, -0x3DF4($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X3DF4);
    // 0x8001299C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800129A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800129A4: lb          $v1, -0x3DF3($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DF3);
    // 0x800129A8: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x800129AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800129B0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800129B4: sw          $s5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r21;
    // 0x800129B8: sw          $t4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r12;
    // 0x800129BC: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x800129C0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800129C4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800129C8: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800129CC: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_800129D0:
    // 0x800129D0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_800129D4:
    // 0x800129D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800129D8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800129DC: slti        $v0, $t2, 0xA
    ctx->r2 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800129E0: bne         $v0, $zero, L_800127FC
    if (ctx->r2 != 0) {
        // 0x800129E4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800127FC;
    }
    // 0x800129E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800129E8: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    // 0x800129EC: bgez        $t7, L_800124F4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800129F0: addiu       $t8, $t8, -0x12
        ctx->r24 = ADD32(ctx->r24, -0X12);
            goto L_800124F4;
    }
    // 0x800129F0: addiu       $t8, $t8, -0x12
    ctx->r24 = ADD32(ctx->r24, -0X12);
    // 0x800129F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800129F8: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x800129FC: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80012A00: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80012A04: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80012A08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012A0C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012A10: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80012A14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80012A18: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80012A1C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80012A20: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80012A24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80012A28: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80012A2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012A30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012A34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012A3C: jr          $ra
    // 0x80012A40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80012A40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80012A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012A44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012A48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80012A4C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80012A50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80012A54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80012A58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012A5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012A60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012A64: lhu         $v0, 0x7A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7A);
    // 0x80012A68: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
    // 0x80012A6C: lbu         $v1, 0x5($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X5);
    // 0x80012A70: addiu       $v0, $v0, 0x38E
    ctx->r2 = ADD32(ctx->r2, 0X38E);
    // 0x80012A74: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80012A78: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80012A7C: bne         $v1, $zero, L_80012A88
    if (ctx->r3 != 0) {
        // 0x80012A80: sh          $s2, 0x7A($s3)
        MEM_H(0X7A, ctx->r19) = ctx->r18;
            goto L_80012A88;
    }
    // 0x80012A80: sh          $s2, 0x7A($s3)
    MEM_H(0X7A, ctx->r19) = ctx->r18;
    // 0x80012A84: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
L_80012A88:
    // 0x80012A88: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012A8C: lw          $a0, 0x13F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F8);
    // 0x80012A90: sb          $zero, 0x11($sp)
    MEM_B(0X11, ctx->r29) = 0;
    // 0x80012A94: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80012A98: beq         $v0, $zero, L_80012B08
    if (ctx->r2 == 0) {
        // 0x80012A9C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80012B08;
    }
    // 0x80012A9C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80012AA0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
L_80012AA4:
    // 0x80012AA4: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x80012AA8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80012AAC: addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
    // 0x80012AB0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80012AB4: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80012AB8: jal         0x80061430
    // 0x80012ABC: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    func_80061430(rdram, ctx);
        goto after_0;
    // 0x80012ABC: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80012AC0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80012AC4: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x80012AC8: addu        $a1, $s4, $s0
    ctx->r5 = ADD32(ctx->r20, ctx->r16);
    // 0x80012ACC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80012AD0: sra         $v0, $v0, 28
    ctx->r2 = S32(SIGNED(ctx->r2) >> 28);
    // 0x80012AD4: addiu       $a2, $v0, 0x88
    ctx->r6 = ADD32(ctx->r2, 0X88);
    // 0x80012AD8: jal         0x8004EC44
    // 0x80012ADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_1;
    // 0x80012ADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x80012AE0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012AE4: lw          $a0, 0x13F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F8);
    // 0x80012AE8: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
    // 0x80012AEC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80012AF0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012AF4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80012AF8: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80012AFC: addiu       $s2, $s2, 0x1999
    ctx->r18 = ADD32(ctx->r18, 0X1999);
    // 0x80012B00: bne         $v0, $zero, L_80012AA4
    if (ctx->r2 != 0) {
        // 0x80012B04: addu        $s1, $v1, $zero
        ctx->r17 = ADD32(ctx->r3, 0);
            goto L_80012AA4;
    }
    // 0x80012B04: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80012B08:
    // 0x80012B08: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
    // 0x80012B0C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80012B10: bne         $v0, $zero, L_80012B1C
    if (ctx->r2 != 0) {
        // 0x80012B14: addiu       $a1, $zero, 0xE6
        ctx->r5 = ADD32(0, 0XE6);
            goto L_80012B1C;
    }
    // 0x80012B14: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80012B18: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
L_80012B1C:
    // 0x80012B1C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80012B20: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80012B24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80012B28: bne         $v1, $v0, L_80012B6C
    if (ctx->r3 != ctx->r2) {
        // 0x80012B2C: nop
    
            goto L_80012B6C;
    }
    // 0x80012B2C: nop

    // 0x80012B30: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012B34: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80012B38: bne         $v0, $v1, L_80012B6C
    if (ctx->r2 != ctx->r3) {
        // 0x80012B3C: nop
    
            goto L_80012B6C;
    }
    // 0x80012B3C: nop

    // 0x80012B40: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012B44: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x80012B48: bltz        $v0, L_80012B6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80012B4C: nop
    
            goto L_80012B6C;
    }
    // 0x80012B4C: nop

    // 0x80012B50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012B54: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x80012B58: bltz        $v0, L_80012B6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80012B5C: nop
    
            goto L_80012B6C;
    }
    // 0x80012B5C: nop

    // 0x80012B60: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012B64: j           L_80012B94
    // 0x80012B68: lw          $v0, 0x1404($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1404);
        goto L_80012B94;
    // 0x80012B68: lw          $v0, 0x1404($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1404);
L_80012B6C:
    // 0x80012B6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012B70: lbu         $v0, 0x7B99($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B99);
    // 0x80012B74: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80012B78: beq         $v0, $zero, L_80012B8C
    if (ctx->r2 == 0) {
        // 0x80012B7C: nop
    
            goto L_80012B8C;
    }
    // 0x80012B7C: nop

    // 0x80012B80: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012B84: j           L_80012B94
    // 0x80012B88: lw          $v0, 0x13FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13FC);
        goto L_80012B94;
    // 0x80012B88: lw          $v0, 0x13FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13FC);
L_80012B8C:
    // 0x80012B8C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012B90: lw          $v0, 0x1400($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1400);
L_80012B94:
    // 0x80012B94: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80012B98: sw          $v0, 0x3F60($at)
    MEM_W(0X3F60, ctx->r1) = ctx->r2;
    // 0x80012B9C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80012BA0: lw          $a0, 0x3F60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3F60);
    // 0x80012BA4: sb          $zero, 0x11($sp)
    MEM_B(0X11, ctx->r29) = 0;
    // 0x80012BA8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80012BAC: beq         $v0, $zero, L_80012C1C
    if (ctx->r2 == 0) {
        // 0x80012BB0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80012C1C;
    }
    // 0x80012BB0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80012BB4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
L_80012BB8:
    // 0x80012BB8: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x80012BBC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80012BC0: addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
    // 0x80012BC4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80012BC8: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80012BCC: jal         0x80061430
    // 0x80012BD0: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    func_80061430(rdram, ctx);
        goto after_2;
    // 0x80012BD0: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80012BD4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80012BD8: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x80012BDC: addu        $a1, $s3, $s0
    ctx->r5 = ADD32(ctx->r19, ctx->r16);
    // 0x80012BE0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80012BE4: sra         $v0, $v0, 28
    ctx->r2 = S32(SIGNED(ctx->r2) >> 28);
    // 0x80012BE8: addiu       $a2, $v0, 0x68
    ctx->r6 = ADD32(ctx->r2, 0X68);
    // 0x80012BEC: jal         0x8004EC44
    // 0x80012BF0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_3;
    // 0x80012BF0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x80012BF4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80012BF8: lw          $a0, 0x3F60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3F60);
    // 0x80012BFC: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
    // 0x80012C00: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80012C04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012C08: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80012C0C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80012C10: addiu       $s2, $s2, 0x1999
    ctx->r18 = ADD32(ctx->r18, 0X1999);
    // 0x80012C14: bne         $v0, $zero, L_80012BB8
    if (ctx->r2 != 0) {
        // 0x80012C18: addu        $s1, $v1, $zero
        ctx->r17 = ADD32(ctx->r3, 0);
            goto L_80012BB8;
    }
    // 0x80012C18: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80012C1C:
    // 0x80012C1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012C20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80012C24: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012C28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012C2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012C34: jr          $ra
    // 0x80012C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80012C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80012C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C3C: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80012C40: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x80012C44: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80012C48: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x80012C4C: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x80012C50: lui         $t6, 0xF600
    ctx->r14 = S32(0XF600 << 16);
    // 0x80012C54: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80012C58: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80012C5C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80012C60: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80012C64: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80012C68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012C6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012C70: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80012C74: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80012C78: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80012C7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012C80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012C84: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80012C88: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80012C8C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80012C90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012C94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80012C98: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80012C9C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012CA0: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x80012CA4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80012CA8: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
L_80012CAC:
    // 0x80012CAC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80012CB0: andi        $v0, $t3, 0x3FF
    ctx->r2 = ctx->r11 & 0X3FF;
    // 0x80012CB4: sll         $t2, $v0, 14
    ctx->r10 = S32(ctx->r2 << 14);
    // 0x80012CB8: andi        $v0, $t4, 0x3FF
    ctx->r2 = ctx->r12 & 0X3FF;
    // 0x80012CBC: sll         $t1, $v0, 14
    ctx->r9 = S32(ctx->r2 << 14);
    // 0x80012CC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80012CC4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_80012CC8:
    // 0x80012CC8: andi        $a0, $a3, 0x3FF
    ctx->r4 = ctx->r7 & 0X3FF;
    // 0x80012CCC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80012CD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80012CD4: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80012CD8: andi        $v0, $a2, 0x3FF
    ctx->r2 = ctx->r6 & 0X3FF;
    // 0x80012CDC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012CE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80012CE4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012CE8: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // 0x80012CEC: or          $v0, $t2, $v0
    ctx->r2 = ctx->r10 | ctx->r2;
    // 0x80012CF0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80012CF4: or          $a0, $t1, $a0
    ctx->r4 = ctx->r9 | ctx->r4;
    // 0x80012CF8: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80012CFC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80012D00: slti        $v0, $t0, 0x1E
    ctx->r2 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
    // 0x80012D04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80012D08: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80012D0C: bne         $v0, $zero, L_80012CC8
    if (ctx->r2 != 0) {
        // 0x80012D10: sw          $a0, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r4;
            goto L_80012CC8;
    }
    // 0x80012D10: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x80012D14: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x80012D18: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80012D1C: slti        $v0, $t5, 0x28
    ctx->r2 = SIGNED(ctx->r13) < 0X28 ? 1 : 0;
    // 0x80012D20: bne         $v0, $zero, L_80012CAC
    if (ctx->r2 != 0) {
        // 0x80012D24: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_80012CAC;
    }
    // 0x80012D24: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80012D28: jr          $ra
    // 0x80012D2C: nop

    return;
    // 0x80012D2C: nop

;}
RECOMP_FUNC void func_80012D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012D34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80012D38: addiu       $a1, $a1, 0x7BD0
    ctx->r5 = ADD32(ctx->r5, 0X7BD0);
    // 0x80012D3C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80012D40:
    // 0x80012D40: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012D44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80012D48: lb          $v0, 0x7BD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7BD0);
    // 0x80012D4C: bnel        $v0, $zero, L_80012D5C
    if (ctx->r2 != 0) {
        // 0x80012D50: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_80012D5C;
    }
    goto skip_0;
    // 0x80012D50: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    skip_0:
    // 0x80012D54: j           L_80012D70
    // 0x80012D58: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80012D70;
    // 0x80012D58: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80012D5C:
    // 0x80012D5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80012D60: slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // 0x80012D64: bne         $v0, $zero, L_80012D40
    if (ctx->r2 != 0) {
        // 0x80012D68: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_80012D40;
    }
    // 0x80012D68: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80012D6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80012D70:
    // 0x80012D70: jr          $ra
    // 0x80012D74: nop

    return;
    // 0x80012D74: nop

;}
