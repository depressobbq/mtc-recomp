#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005A3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A3F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A3FC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A400: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A404: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A408: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A40C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A410: bne         $v0, $zero, L_8005A420
    if (ctx->r2 != 0) {
        // 0x8005A414: nop
    
            goto L_8005A420;
    }
    // 0x8005A414: nop

    // 0x8005A418: j           L_8005A4D4
    // 0x8005A41C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A4D4;
    // 0x8005A41C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A420:
    // 0x8005A420: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A424: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A428: bne         $v1, $zero, L_8005A434
    if (ctx->r3 != 0) {
        // 0x8005A42C: nop
    
            goto L_8005A434;
    }
    // 0x8005A42C: nop

    // 0x8005A430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A434:
    // 0x8005A434: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x8005A438: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8005A43C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A440: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A444: sw          $v0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r2;
    // 0x8005A448: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A44C:
    // 0x8005A44C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A450: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A454: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A458: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A45C: bne         $v0, $zero, L_8005A46C
    if (ctx->r2 != 0) {
        // 0x8005A460: nop
    
            goto L_8005A46C;
    }
    // 0x8005A460: nop

    // 0x8005A464: j           L_8005A4CC
    // 0x8005A468: nop

        goto L_8005A4CC;
    // 0x8005A468: nop

L_8005A46C:
    // 0x8005A46C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x8005A470: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A474: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A478: bne         $v1, $v0, L_8005A4A8
    if (ctx->r3 != ctx->r2) {
        // 0x8005A47C: nop
    
            goto L_8005A4A8;
    }
    // 0x8005A47C: nop

    // 0x8005A480: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x8005A484: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A488: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8005A48C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x8005A490: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A494: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x8005A498: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A49C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A4A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A4A4: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A4A8:
    // 0x8005A4A8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A4AC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A4B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A4B4: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x8005A4B8: lw          $v1, 0xC($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XC);
    // 0x8005A4BC: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A4C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A4C4: j           L_8005A44C
    // 0x8005A4C8: sw          $v1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r3;
        goto L_8005A44C;
    // 0x8005A4C8: sw          $v1, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r3;
L_8005A4CC:
    // 0x8005A4CC: j           L_8005A4D4
    // 0x8005A4D0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A4D4;
    // 0x8005A4D0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A4D4:
    // 0x8005A4D4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A4D8: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A4DC: jr          $ra
    // 0x8005A4E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A4E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A4E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A4E8: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A4EC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A4F0: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A4F4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A4F8: bne         $v0, $zero, L_8005A508
    if (ctx->r2 != 0) {
        // 0x8005A4FC: nop
    
            goto L_8005A508;
    }
    // 0x8005A4FC: nop

    // 0x8005A500: j           L_8005A590
    // 0x8005A504: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A590;
    // 0x8005A504: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A508:
    // 0x8005A508: nop

    // 0x8005A50C: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A510: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A514: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A518: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A51C: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A520:
    // 0x8005A520: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A524: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A528: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A52C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A530: bne         $v0, $zero, L_8005A540
    if (ctx->r2 != 0) {
        // 0x8005A534: nop
    
            goto L_8005A540;
    }
    // 0x8005A534: nop

    // 0x8005A538: j           L_8005A588
    // 0x8005A53C: nop

        goto L_8005A588;
    // 0x8005A53C: nop

L_8005A540:
    // 0x8005A540: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A544: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A548: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A54C: bne         $v1, $v0, L_8005A564
    if (ctx->r3 != ctx->r2) {
        // 0x8005A550: nop
    
            goto L_8005A564;
    }
    // 0x8005A550: nop

    // 0x8005A554: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A558: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A55C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A560: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A564:
    // 0x8005A564: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A568: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A56C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A570: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005A574: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A578: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A57C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A580: j           L_8005A520
    // 0x8005A584: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A520;
    // 0x8005A584: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005A588:
    // 0x8005A588: j           L_8005A590
    // 0x8005A58C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A590;
    // 0x8005A58C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A590:
    // 0x8005A590: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A594: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A598: jr          $ra
    // 0x8005A59C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A59C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A5A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A5A4: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A5A8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A5AC: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A5B0: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A5B4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A5B8: bne         $v0, $zero, L_8005A5C8
    if (ctx->r2 != 0) {
        // 0x8005A5BC: nop
    
            goto L_8005A5C8;
    }
    // 0x8005A5BC: nop

    // 0x8005A5C0: j           L_8005A65C
    // 0x8005A5C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A65C;
    // 0x8005A5C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A5C8:
    // 0x8005A5C8: nop

    // 0x8005A5CC: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A5D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A5D4: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A5D8: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A5DC: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A5E0:
    // 0x8005A5E0: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A5E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A5E8: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A5EC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A5F0: bne         $v0, $zero, L_8005A600
    if (ctx->r2 != 0) {
        // 0x8005A5F4: nop
    
            goto L_8005A600;
    }
    // 0x8005A5F4: nop

    // 0x8005A5F8: j           L_8005A654
    // 0x8005A5FC: nop

        goto L_8005A654;
    // 0x8005A5FC: nop

L_8005A600:
    // 0x8005A600: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A604: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A608: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A60C: bne         $v1, $v0, L_8005A630
    if (ctx->r3 != ctx->r2) {
        // 0x8005A610: nop
    
            goto L_8005A630;
    }
    // 0x8005A610: nop

    // 0x8005A614: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A618: lhu         $v1, 0x1E($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X1E);
    // 0x8005A61C: sh          $v1, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r3;
    // 0x8005A620: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A624: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A628: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A62C: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A630:
    // 0x8005A630: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A634: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A638: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A63C: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005A640: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A644: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A648: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A64C: j           L_8005A5E0
    // 0x8005A650: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A5E0;
    // 0x8005A650: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005A654:
    // 0x8005A654: j           L_8005A65C
    // 0x8005A658: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A65C;
    // 0x8005A658: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A65C:
    // 0x8005A65C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A660: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A664: jr          $ra
    // 0x8005A668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A66C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A66C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A670: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A674: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A678: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A67C: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A680: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A684: bne         $v0, $zero, L_8005A694
    if (ctx->r2 != 0) {
        // 0x8005A688: nop
    
            goto L_8005A694;
    }
    // 0x8005A688: nop

    // 0x8005A68C: j           L_8005A734
    // 0x8005A690: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A734;
    // 0x8005A690: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A694:
    // 0x8005A694: nop

    // 0x8005A698: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A69C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A6A0: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A6A4: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A6A8: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A6AC:
    // 0x8005A6AC: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A6B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A6B4: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A6B8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A6BC: bne         $v0, $zero, L_8005A6CC
    if (ctx->r2 != 0) {
        // 0x8005A6C0: nop
    
            goto L_8005A6CC;
    }
    // 0x8005A6C0: nop

    // 0x8005A6C4: j           L_8005A72C
    // 0x8005A6C8: nop

        goto L_8005A72C;
    // 0x8005A6C8: nop

L_8005A6CC:
    // 0x8005A6CC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A6D0: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A6D4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A6D8: bne         $v1, $v0, L_8005A708
    if (ctx->r3 != ctx->r2) {
        // 0x8005A6DC: nop
    
            goto L_8005A708;
    }
    // 0x8005A6DC: nop

    // 0x8005A6E0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A6E4: lhu         $v1, 0x1E($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X1E);
    // 0x8005A6E8: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
    // 0x8005A6EC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A6F0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005A6F4: sb          $v1, 0xB6($v0)
    MEM_B(0XB6, ctx->r2) = ctx->r3;
    // 0x8005A6F8: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A6FC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A700: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A704: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A708:
    // 0x8005A708: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A70C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A710: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A714: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005A718: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A71C: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A720: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A724: j           L_8005A6AC
    // 0x8005A728: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A6AC;
    // 0x8005A728: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005A72C:
    // 0x8005A72C: j           L_8005A734
    // 0x8005A730: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A734;
    // 0x8005A730: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A734:
    // 0x8005A734: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A738: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A73C: jr          $ra
    // 0x8005A740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A748: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A74C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A750: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A754: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A758: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A75C: bne         $v0, $zero, L_8005A76C
    if (ctx->r2 != 0) {
        // 0x8005A760: nop
    
            goto L_8005A76C;
    }
    // 0x8005A760: nop

    // 0x8005A764: j           L_8005A80C
    // 0x8005A768: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A80C;
    // 0x8005A768: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A76C:
    // 0x8005A76C: nop

    // 0x8005A770: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A774: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A778: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A77C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A780: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A784:
    // 0x8005A784: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A78C: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A790: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A794: bne         $v0, $zero, L_8005A7A4
    if (ctx->r2 != 0) {
        // 0x8005A798: nop
    
            goto L_8005A7A4;
    }
    // 0x8005A798: nop

    // 0x8005A79C: j           L_8005A804
    // 0x8005A7A0: nop

        goto L_8005A804;
    // 0x8005A7A0: nop

L_8005A7A4:
    // 0x8005A7A4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A7A8: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A7AC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A7B0: bne         $v1, $v0, L_8005A7E0
    if (ctx->r3 != ctx->r2) {
        // 0x8005A7B4: nop
    
            goto L_8005A7E0;
    }
    // 0x8005A7B4: nop

    // 0x8005A7B8: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A7BC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A7C0: lwc1        $f0, 0x1C($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X1C);
    // 0x8005A7C4: lwc1        $f2, 0x88($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8005A7C8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005A7CC: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8005A7D0: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A7D4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A7D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A7DC: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A7E0:
    // 0x8005A7E0: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A7E4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A7E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A7EC: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005A7F0: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A7F4: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A7F8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A7FC: j           L_8005A784
    // 0x8005A800: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A784;
    // 0x8005A800: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005A804:
    // 0x8005A804: j           L_8005A80C
    // 0x8005A808: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A80C;
    // 0x8005A808: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A80C:
    // 0x8005A80C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A810: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A814: jr          $ra
    // 0x8005A818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A820: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A824: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A828: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A82C: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A830: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A834: bne         $v0, $zero, L_8005A844
    if (ctx->r2 != 0) {
        // 0x8005A838: nop
    
            goto L_8005A844;
    }
    // 0x8005A838: nop

    // 0x8005A83C: j           L_8005A928
    // 0x8005A840: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005A928;
    // 0x8005A840: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A844:
    // 0x8005A844: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A848: bgtz        $v0, L_8005A85C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8005A84C: nop
    
            goto L_8005A85C;
    }
    // 0x8005A84C: nop

    // 0x8005A850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A854: j           L_8005A874
    // 0x8005A858: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
        goto L_8005A874;
    // 0x8005A858: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_8005A85C:
    // 0x8005A85C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A860: slti        $v1, $v0, 0x101
    ctx->r3 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x8005A864: bne         $v1, $zero, L_8005A874
    if (ctx->r3 != 0) {
        // 0x8005A868: nop
    
            goto L_8005A874;
    }
    // 0x8005A868: nop

    // 0x8005A86C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8005A870: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_8005A874:
    // 0x8005A874: nop

    // 0x8005A878: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A87C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A880: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A884: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A888: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A88C:
    // 0x8005A88C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A890: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A894: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A898: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A89C: bne         $v0, $zero, L_8005A8AC
    if (ctx->r2 != 0) {
        // 0x8005A8A0: nop
    
            goto L_8005A8AC;
    }
    // 0x8005A8A0: nop

    // 0x8005A8A4: j           L_8005A920
    // 0x8005A8A8: nop

        goto L_8005A920;
    // 0x8005A8A8: nop

L_8005A8AC:
    // 0x8005A8AC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A8B0: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A8B4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A8B8: bne         $v1, $v0, L_8005A8FC
    if (ctx->r3 != ctx->r2) {
        // 0x8005A8BC: nop
    
            goto L_8005A8FC;
    }
    // 0x8005A8BC: nop

    // 0x8005A8C0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A8C4: lhu         $v1, 0x1E($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X1E);
    // 0x8005A8C8: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    // 0x8005A8CC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A8D0: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A8D4: lhu         $a0, 0xA0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA0);
    // 0x8005A8D8: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A8DC: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A8E0: mflo        $v1
    ctx->r3 = lo;
    // 0x8005A8E4: sra         $a0, $v1, 7
    ctx->r4 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8005A8E8: sh          $a0, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r4;
    // 0x8005A8EC: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A8F0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A8F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A8F8: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005A8FC:
    // 0x8005A8FC: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005A900: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A904: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A908: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005A90C: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005A910: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005A914: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A918: j           L_8005A88C
    // 0x8005A91C: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A88C;
    // 0x8005A91C: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005A920:
    // 0x8005A920: j           L_8005A928
    // 0x8005A924: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005A928;
    // 0x8005A924: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005A928:
    // 0x8005A928: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005A92C: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005A930: jr          $ra
    // 0x8005A934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005A934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005A938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A93C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005A940: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005A944: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005A948: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005A94C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A950: bne         $v0, $zero, L_8005A960
    if (ctx->r2 != 0) {
        // 0x8005A954: nop
    
            goto L_8005A960;
    }
    // 0x8005A954: nop

    // 0x8005A958: j           L_8005AA2C
    // 0x8005A95C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005AA2C;
    // 0x8005A95C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A960:
    // 0x8005A960: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A964: bgez        $v0, L_8005A974
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005A968: nop
    
            goto L_8005A974;
    }
    // 0x8005A968: nop

    // 0x8005A96C: j           L_8005A98C
    // 0x8005A970: sw          $zero, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = 0;
        goto L_8005A98C;
    // 0x8005A970: sw          $zero, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = 0;
L_8005A974:
    // 0x8005A974: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005A978: slti        $v1, $v0, 0x80
    ctx->r3 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8005A97C: bne         $v1, $zero, L_8005A98C
    if (ctx->r3 != 0) {
        // 0x8005A980: nop
    
            goto L_8005A98C;
    }
    // 0x8005A980: nop

    // 0x8005A984: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8005A988: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
L_8005A98C:
    // 0x8005A98C: nop

    // 0x8005A990: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005A994: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005A998: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005A99C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005A9A0: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005A9A4:
    // 0x8005A9A4: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005A9A8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005A9AC: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005A9B0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A9B4: bne         $v0, $zero, L_8005A9C4
    if (ctx->r2 != 0) {
        // 0x8005A9B8: nop
    
            goto L_8005A9C4;
    }
    // 0x8005A9B8: nop

    // 0x8005A9BC: j           L_8005AA24
    // 0x8005A9C0: nop

        goto L_8005AA24;
    // 0x8005A9C0: nop

L_8005A9C4:
    // 0x8005A9C4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A9C8: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005A9CC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005A9D0: bne         $v1, $v0, L_8005AA00
    if (ctx->r3 != ctx->r2) {
        // 0x8005A9D4: nop
    
            goto L_8005AA00;
    }
    // 0x8005A9D4: nop

    // 0x8005A9D8: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A9DC: lbu         $v1, 0x1F($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X1F);
    // 0x8005A9E0: sb          $v1, 0xC3($v0)
    MEM_B(0XC3, ctx->r2) = ctx->r3;
    // 0x8005A9E4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005A9E8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005A9EC: sb          $v1, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r3;
    // 0x8005A9F0: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005A9F4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005A9F8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005A9FC: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005AA00:
    // 0x8005AA00: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005AA04: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005AA08: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005AA0C: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005AA10: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005AA14: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005AA18: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005AA1C: j           L_8005A9A4
    // 0x8005AA20: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005A9A4;
    // 0x8005AA20: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005AA24:
    // 0x8005AA24: j           L_8005AA2C
    // 0x8005AA28: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
        goto L_8005AA2C;
    // 0x8005AA28: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
L_8005AA2C:
    // 0x8005AA2C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005AA30: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005AA34: jr          $ra
    // 0x8005AA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005AA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005AA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AA3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AA40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AA44: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005AA48: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005AA4C: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005AA50: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005AA54: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005AA58: jal         0x8005C774
    // 0x8005AA5C: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    func_8005C774(rdram, ctx);
        goto after_0;
    // 0x8005AA5C: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    after_0:
    // 0x8005AA60: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005AA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AA68: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005AA6C: jr          $ra
    // 0x8005AA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005AA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005AA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AA74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005AA78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005AA7C: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8005AA80: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005AA84: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x8005AA88: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x8005AA8C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005AA90: beq         $v0, $zero, L_8005AAC4
    if (ctx->r2 == 0) {
        // 0x8005AA94: nop
    
            goto L_8005AAC4;
    }
    // 0x8005AA94: nop

    // 0x8005AA98: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005AA9C: sw          $v0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r2;
    // 0x8005AAA0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AAA4: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005AAA8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8005AAAC: and         $v0, $v1, $a0
    ctx->r2 = ctx->r3 & ctx->r4;
    // 0x8005AAB0: beq         $v0, $zero, L_8005AAC4
    if (ctx->r2 == 0) {
        // 0x8005AAB4: nop
    
            goto L_8005AAC4;
    }
    // 0x8005AAB4: nop

    // 0x8005AAB8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AAC0: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
L_8005AAC4:
    // 0x8005AAC4: jal         0x80059CA4
    // 0x8005AAC8: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    func_80059CA4(rdram, ctx);
        goto after_0;
    // 0x8005AAC8: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    after_0:
    // 0x8005AACC: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x8005AAD0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005AAD4: lw          $v0, 0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5150);
    // 0x8005AAD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AADC: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
    // 0x8005AAE0: j           L_8005AAE8
    // 0x8005AAE4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
        goto L_8005AAE8;
    // 0x8005AAE4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
L_8005AAE8:
    // 0x8005AAE8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005AAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AAF0: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x8005AAF4: jr          $ra
    // 0x8005AAF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005AAF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005AAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AAFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005AB00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005AB04: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8005AB08: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005AB0C: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x8005AB10: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x8005AB14: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005AB18: beq         $v0, $zero, L_8005AB4C
    if (ctx->r2 == 0) {
        // 0x8005AB1C: nop
    
            goto L_8005AB4C;
    }
    // 0x8005AB1C: nop

    // 0x8005AB20: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005AB24: sw          $v0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r2;
    // 0x8005AB28: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AB2C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005AB30: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8005AB34: and         $v0, $v1, $a0
    ctx->r2 = ctx->r3 & ctx->r4;
    // 0x8005AB38: beq         $v0, $zero, L_8005AB4C
    if (ctx->r2 == 0) {
        // 0x8005AB3C: nop
    
            goto L_8005AB4C;
    }
    // 0x8005AB3C: nop

    // 0x8005AB40: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AB44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB48: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
L_8005AB4C:
    // 0x8005AB4C: jal         0x80059E98
    // 0x8005AB50: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    func_80059E98(rdram, ctx);
        goto after_0;
    // 0x8005AB50: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    after_0:
    // 0x8005AB54: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x8005AB58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005AB5C: lw          $v0, 0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5150);
    // 0x8005AB60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB64: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
    // 0x8005AB68: j           L_8005AB70
    // 0x8005AB6C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
        goto L_8005AB70;
    // 0x8005AB6C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
L_8005AB70:
    // 0x8005AB70: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005AB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AB78: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x8005AB7C: jr          $ra
    // 0x8005AB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005AB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005AB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AB84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005AB88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005AB8C: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x8005AB90: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005AB94: sw          $a0, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r4;
    // 0x8005AB98: sw          $a1, 0x2C($fp)
    MEM_W(0X2C, ctx->r30) = ctx->r5;
    // 0x8005AB9C: sw          $a2, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r6;
    // 0x8005ABA0: sw          $a3, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r7;
    // 0x8005ABA4: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005ABA8: beq         $v0, $zero, L_8005ABDC
    if (ctx->r2 == 0) {
        // 0x8005ABAC: nop
    
            goto L_8005ABDC;
    }
    // 0x8005ABAC: nop

    // 0x8005ABB0: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005ABB4: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
    // 0x8005ABB8: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005ABBC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005ABC0: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8005ABC4: and         $v0, $v1, $a0
    ctx->r2 = ctx->r3 & ctx->r4;
    // 0x8005ABC8: beq         $v0, $zero, L_8005ABDC
    if (ctx->r2 == 0) {
        // 0x8005ABCC: nop
    
            goto L_8005ABDC;
    }
    // 0x8005ABCC: nop

    // 0x8005ABD0: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005ABD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ABD8: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
L_8005ABDC:
    // 0x8005ABDC: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005ABE0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005ABE4: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    // 0x8005ABE8: lw          $a1, 0x30($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X30);
    // 0x8005ABEC: lw          $a2, 0x34($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X34);
    // 0x8005ABF0: jal         0x80059FF8
    // 0x8005ABF4: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    func_80059FF8(rdram, ctx);
        goto after_0;
    // 0x8005ABF4: lw          $a3, 0x38($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X38);
    after_0:
    // 0x8005ABF8: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
    // 0x8005ABFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005AC00: lw          $v0, 0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5150);
    // 0x8005AC04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AC08: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
    // 0x8005AC0C: j           L_8005AC14
    // 0x8005AC10: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
        goto L_8005AC14;
    // 0x8005AC10: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
L_8005AC14:
    // 0x8005AC14: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005AC18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005AC1C: lw          $fp, 0x20($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X20);
    // 0x8005AC20: jr          $ra
    // 0x8005AC24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005AC24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005AC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AC2C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005AC30: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005AC34: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005AC38: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005AC3C: bne         $v0, $zero, L_8005AC4C
    if (ctx->r2 != 0) {
        // 0x8005AC40: nop
    
            goto L_8005AC4C;
    }
    // 0x8005AC40: nop

    // 0x8005AC44: j           L_8005ACD0
    // 0x8005AC48: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005ACD0;
    // 0x8005AC48: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005AC4C:
    // 0x8005AC4C: nop

    // 0x8005AC50: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005AC54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005AC58: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005AC5C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005AC60: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005AC64:
    // 0x8005AC64: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005AC68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005AC6C: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005AC70: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005AC74: bne         $v0, $zero, L_8005AC84
    if (ctx->r2 != 0) {
        // 0x8005AC78: nop
    
            goto L_8005AC84;
    }
    // 0x8005AC78: nop

    // 0x8005AC7C: j           L_8005ACC8
    // 0x8005AC80: nop

        goto L_8005ACC8;
    // 0x8005AC80: nop

L_8005AC84:
    // 0x8005AC84: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005AC88: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8005AC8C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005AC90: bne         $v1, $v0, L_8005ACA4
    if (ctx->r3 != ctx->r2) {
        // 0x8005AC94: nop
    
            goto L_8005ACA4;
    }
    // 0x8005AC94: nop

    // 0x8005AC98: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005AC9C: j           L_8005ACD0
    // 0x8005ACA0: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
        goto L_8005ACD0;
    // 0x8005ACA0: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
L_8005ACA4:
    // 0x8005ACA4: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005ACA8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005ACAC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005ACB0: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005ACB4: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005ACB8: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005ACBC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005ACC0: j           L_8005AC64
    // 0x8005ACC4: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005AC64;
    // 0x8005ACC4: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005ACC8:
    // 0x8005ACC8: j           L_8005ACD0
    // 0x8005ACCC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005ACD0;
    // 0x8005ACCC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005ACD0:
    // 0x8005ACD0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005ACD4: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005ACD8: jr          $ra
    // 0x8005ACDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005ACDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005ACE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005ACE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005ACE8: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x8005ACEC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005ACF0: sw          $a0, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r4;
    // 0x8005ACF4: sw          $zero, 0x10($fp)
    MEM_W(0X10, ctx->r30) = 0;
    // 0x8005ACF8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005ACFC: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005AD00: sw          $v0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r2;
L_8005AD04:
    // 0x8005AD04: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005AD08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005AD0C: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005AD10: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005AD14: bne         $v0, $zero, L_8005AD24
    if (ctx->r2 != 0) {
        // 0x8005AD18: nop
    
            goto L_8005AD24;
    }
    // 0x8005AD18: nop

    // 0x8005AD1C: j           L_8005B010
    // 0x8005AD20: nop

        goto L_8005B010;
    // 0x8005AD20: nop

L_8005AD24:
    // 0x8005AD24: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD28: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005AD2C: bne         $v1, $zero, L_8005AD3C
    if (ctx->r3 != 0) {
        // 0x8005AD30: nop
    
            goto L_8005AD3C;
    }
    // 0x8005AD30: nop

    // 0x8005AD34: j           L_8005AFEC
    // 0x8005AD38: nop

        goto L_8005AFEC;
    // 0x8005AD38: nop

L_8005AD3C:
    // 0x8005AD3C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD40: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8005AD44: beq         $v1, $zero, L_8005AD58
    if (ctx->r3 == 0) {
        // 0x8005AD48: nop
    
            goto L_8005AD58;
    }
    // 0x8005AD48: nop

    // 0x8005AD4C: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD50: jal         0x8005B624
    // 0x8005AD54: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    func_8005B624(rdram, ctx);
        goto after_0;
    // 0x8005AD54: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    after_0:
L_8005AD58:
    // 0x8005AD58: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD5C: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD60: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD64: lhu         $a1, 0x94($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X94);
    // 0x8005AD68: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AD6C: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x8005AD70: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8005AD74: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD78: lhu         $v1, 0x92($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X92);
    // 0x8005AD7C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8005AD80: beq         $v1, $v0, L_8005ADF0
    if (ctx->r3 == ctx->r2) {
        // 0x8005AD84: nop
    
            goto L_8005ADF0;
    }
    // 0x8005AD84: nop

L_8005AD88:
    // 0x8005AD88: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD8C: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AD90: lw          $v0, 0x38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38);
    // 0x8005AD94: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AD98: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005AD9C: beq         $v0, $zero, L_8005ADBC
    if (ctx->r2 == 0) {
        // 0x8005ADA0: nop
    
            goto L_8005ADBC;
    }
    // 0x8005ADA0: nop

    // 0x8005ADA4: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005ADA8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005ADAC: bne         $v1, $zero, L_8005ADC4
    if (ctx->r3 != 0) {
        // 0x8005ADB0: nop
    
            goto L_8005ADC4;
    }
    // 0x8005ADB0: nop

    // 0x8005ADB4: j           L_8005ADBC
    // 0x8005ADB8: nop

        goto L_8005ADBC;
    // 0x8005ADB8: nop

L_8005ADBC:
    // 0x8005ADBC: j           L_8005ADD8
    // 0x8005ADC0: nop

        goto L_8005ADD8;
    // 0x8005ADC0: nop

L_8005ADC4:
    // 0x8005ADC4: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005ADC8: jal         0x8005B030
    // 0x8005ADCC: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    func_8005B030(rdram, ctx);
        goto after_1;
    // 0x8005ADCC: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    after_1:
    // 0x8005ADD0: j           L_8005AD88
    // 0x8005ADD4: nop

        goto L_8005AD88;
    // 0x8005ADD4: nop

L_8005ADD8:
    // 0x8005ADD8: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005ADDC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005ADE0: bne         $v1, $zero, L_8005ADF0
    if (ctx->r3 != 0) {
        // 0x8005ADE4: nop
    
            goto L_8005ADF0;
    }
    // 0x8005ADE4: nop

    // 0x8005ADE8: j           L_8005AFEC
    // 0x8005ADEC: nop

        goto L_8005AFEC;
    // 0x8005ADEC: nop

L_8005ADF0:
    // 0x8005ADF0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005ADF4: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x8005ADF8: beq         $v1, $zero, L_8005AE24
    if (ctx->r3 == 0) {
        // 0x8005ADFC: nop
    
            goto L_8005AE24;
    }
    // 0x8005ADFC: nop

    // 0x8005AE00: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE04: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE08: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8005AE0C: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AE10: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005AE14: beq         $v0, $zero, L_8005AE24
    if (ctx->r2 == 0) {
        // 0x8005AE18: nop
    
            goto L_8005AE24;
    }
    // 0x8005AE18: nop

    // 0x8005AE1C: jal         0x8005C1D8
    // 0x8005AE20: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005C1D8(rdram, ctx);
        goto after_2;
    // 0x8005AE20: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_2:
L_8005AE24:
    // 0x8005AE24: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE28: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8005AE2C: beq         $v1, $zero, L_8005AE58
    if (ctx->r3 == 0) {
        // 0x8005AE30: nop
    
            goto L_8005AE58;
    }
    // 0x8005AE30: nop

    // 0x8005AE34: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE38: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE3C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8005AE40: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AE44: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005AE48: beq         $v0, $zero, L_8005AE58
    if (ctx->r2 == 0) {
        // 0x8005AE4C: nop
    
            goto L_8005AE58;
    }
    // 0x8005AE4C: nop

    // 0x8005AE50: jal         0x8005C340
    // 0x8005AE54: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005C340(rdram, ctx);
        goto after_3;
    // 0x8005AE54: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_3:
L_8005AE58:
    // 0x8005AE58: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE5C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005AE60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005AE64: beq         $v1, $v0, L_8005AEF0
    if (ctx->r3 == ctx->r2) {
        // 0x8005AE68: nop
    
            goto L_8005AEF0;
    }
    // 0x8005AE68: nop

    // 0x8005AE6C: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE70: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE74: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE78: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8005AE7C: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8005AE80: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005AE84: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8005AE88: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AE8C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005AE90: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005AE94: bne         $v1, $v0, L_8005AEF0
    if (ctx->r3 != ctx->r2) {
        // 0x8005AE98: nop
    
            goto L_8005AEF0;
    }
    // 0x8005AE98: nop

    // 0x8005AE9C: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AEA0: jal         0x80058300
    // 0x8005AEA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80058300(rdram, ctx);
        goto after_4;
    // 0x8005AEA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x8005AEA8: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AEAC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005AEB0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AEB4: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005AEB8: beq         $v1, $zero, L_8005AEF0
    if (ctx->r3 == 0) {
        // 0x8005AEBC: nop
    
            goto L_8005AEF0;
    }
    // 0x8005AEBC: nop

    // 0x8005AEC0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AEC4: sb          $zero, 0xC1($v0)
    MEM_B(0XC1, ctx->r2) = 0;
    // 0x8005AEC8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005AECC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005AED0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005AED4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005AED8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005AEDC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005AEE0: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005AEE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005AEE8: jal         0x8005D950
    // 0x8005AEEC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005D950(rdram, ctx);
        goto after_5;
    // 0x8005AEEC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_5:
L_8005AEF0:
    // 0x8005AEF0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AEF4: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005AEF8: beq         $v1, $zero, L_8005AFCC
    if (ctx->r3 == 0) {
        // 0x8005AEFC: nop
    
            goto L_8005AFCC;
    }
    // 0x8005AEFC: nop

    // 0x8005AF00: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF04: lbu         $v1, 0xBB($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBB);
    // 0x8005AF08: beq         $v1, $zero, L_8005AF18
    if (ctx->r3 == 0) {
        // 0x8005AF0C: nop
    
            goto L_8005AF18;
    }
    // 0x8005AF0C: nop

    // 0x8005AF10: jal         0x8005BB70
    // 0x8005AF14: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005BB70(rdram, ctx);
        goto after_6;
    // 0x8005AF14: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_6:
L_8005AF18:
    // 0x8005AF18: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF1C: lbu         $v1, 0xCC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCC);
    // 0x8005AF20: beq         $v1, $zero, L_8005AF4C
    if (ctx->r3 == 0) {
        // 0x8005AF24: nop
    
            goto L_8005AF4C;
    }
    // 0x8005AF24: nop

    // 0x8005AF28: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF2C: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF30: lw          $v0, 0x8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8C);
    // 0x8005AF34: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AF38: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005AF3C: beq         $v0, $zero, L_8005AF4C
    if (ctx->r2 == 0) {
        // 0x8005AF40: nop
    
            goto L_8005AF4C;
    }
    // 0x8005AF40: nop

    // 0x8005AF44: jal         0x8005BF04
    // 0x8005AF48: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005BF04(rdram, ctx);
        goto after_7;
    // 0x8005AF48: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_7:
L_8005AF4C:
    // 0x8005AF4C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF50: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8005AF54: swc1        $f0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->f0.u32l;
    // 0x8005AF58: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF5C: lbu         $v1, 0xCD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCD);
    // 0x8005AF60: beq         $v1, $zero, L_8005AF7C
    if (ctx->r3 == 0) {
        // 0x8005AF64: nop
    
            goto L_8005AF7C;
    }
    // 0x8005AF64: nop

    // 0x8005AF68: jal         0x8005C11C
    // 0x8005AF6C: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005C11C(rdram, ctx);
        goto after_8;
    // 0x8005AF6C: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_8:
    // 0x8005AF70: lwc1        $f2, 0x1C($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X1C);
    // 0x8005AF74: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005AF78: swc1        $f0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->f0.u32l;
L_8005AF7C:
    // 0x8005AF7C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AF80: lbu         $v1, 0xC6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC6);
    // 0x8005AF84: beq         $v1, $zero, L_8005AFA0
    if (ctx->r3 == 0) {
        // 0x8005AF88: nop
    
            goto L_8005AFA0;
    }
    // 0x8005AF88: nop

    // 0x8005AF8C: jal         0x8005C068
    // 0x8005AF90: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    func_8005C068(rdram, ctx);
        goto after_9;
    // 0x8005AF90: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    after_9:
    // 0x8005AF94: lwc1        $f2, 0x1C($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X1C);
    // 0x8005AF98: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005AF9C: swc1        $f0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->f0.u32l;
L_8005AFA0:
    // 0x8005AFA0: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFA4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8005AFA8: bne         $v1, $zero, L_8005AFCC
    if (ctx->r3 != 0) {
        // 0x8005AFAC: nop
    
            goto L_8005AFCC;
    }
    // 0x8005AFAC: nop

    // 0x8005AFB0: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFB4: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    // 0x8005AFB8: jal         0x8005B8C0
    // 0x8005AFBC: lw          $a2, 0x1C($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X1C);
    func_8005B8C0(rdram, ctx);
        goto after_10;
    // 0x8005AFBC: lw          $a2, 0x1C($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X1C);
    after_10:
    // 0x8005AFC0: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFC4: jal         0x8005B6CC
    // 0x8005AFC8: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    func_8005B6CC(rdram, ctx);
        goto after_11;
    // 0x8005AFC8: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    after_11:
L_8005AFCC:
    // 0x8005AFCC: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFD0: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFD4: lw          $a0, 0x14($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X14);
    // 0x8005AFD8: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005AFDC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x8005AFE0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8005AFE4: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8005AFE8: sh          $a0, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r4;
L_8005AFEC:
    // 0x8005AFEC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005AFF0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005AFF4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005AFF8: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
    // 0x8005AFFC: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x8005B000: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005B004: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005B008: j           L_8005AD04
    // 0x8005B00C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
        goto L_8005AD04;
    // 0x8005B00C: sw          $v1, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r3;
L_8005B010:
    // 0x8005B010: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B014: j           L_8005B01C
    // 0x8005B018: lw          $v0, -0x4430($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4430);
        goto L_8005B01C;
    // 0x8005B018: lw          $v0, -0x4430($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4430);
L_8005B01C:
    // 0x8005B01C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005B020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B024: lw          $fp, 0x20($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X20);
    // 0x8005B028: jr          $ra
    // 0x8005B02C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005B02C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005B030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B030: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005B034: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005B038: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8005B03C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005B040: sw          $a0, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r4;
    // 0x8005B044: sw          $a1, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r5;
    // 0x8005B048: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B04C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005B050: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
L_8005B054:
    // 0x8005B054: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B058: beq         $v0, $zero, L_8005B084
    if (ctx->r2 == 0) {
        // 0x8005B05C: nop
    
            goto L_8005B084;
    }
    // 0x8005B05C: nop

    // 0x8005B060: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B064: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005B068: sb          $v1, 0x14($fp)
    MEM_B(0X14, ctx->r30) = ctx->r3;
    // 0x8005B06C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8005B070: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005B074: beq         $v1, $zero, L_8005B08C
    if (ctx->r3 == 0) {
        // 0x8005B078: nop
    
            goto L_8005B08C;
    }
    // 0x8005B078: nop

    // 0x8005B07C: j           L_8005B084
    // 0x8005B080: nop

        goto L_8005B084;
    // 0x8005B080: nop

L_8005B084:
    // 0x8005B084: j           L_8005B0C8
    // 0x8005B088: nop

        goto L_8005B0C8;
    // 0x8005B088: nop

L_8005B08C:
    // 0x8005B08C: lbu         $v0, 0x14($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B090: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x8005B094: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8005B098: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005B09C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B0A0: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005B0A4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8005B0A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005B0AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005B0B0: lw          $v0, 0x6000($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6000);
    // 0x8005B0B4: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B0B8: jalr        $v0
    // 0x8005B0BC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005B0BC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_0:
    // 0x8005B0C0: j           L_8005B054
    // 0x8005B0C4: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
        goto L_8005B054;
    // 0x8005B0C4: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_8005B0C8:
    // 0x8005B0C8: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B0CC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005B0D0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005B0D4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B0D8: beq         $v0, $zero, L_8005B59C
    if (ctx->r2 == 0) {
        // 0x8005B0DC: nop
    
            goto L_8005B59C;
    }
    // 0x8005B0DC: nop

    // 0x8005B0E0: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B0E4: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B0E8: lwc1        $f0, 0x4C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8005B0EC: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8005B0F0: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B0F4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005B0F8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005B0FC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005B100: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005B104: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
    // 0x8005B108: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B10C: lbu         $v1, 0xCA($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCA);
    // 0x8005B110: beq         $v1, $zero, L_8005B138
    if (ctx->r3 == 0) {
        // 0x8005B114: nop
    
            goto L_8005B138;
    }
    // 0x8005B114: nop

    // 0x8005B118: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B11C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B120: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8005B124: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x8005B128: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8005B12C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8005B130: j           L_8005B148
    // 0x8005B134: sb          $v1, 0xB3($v0)
    MEM_B(0XB3, ctx->r2) = ctx->r3;
        goto L_8005B148;
    // 0x8005B134: sb          $v1, 0xB3($v0)
    MEM_B(0XB3, ctx->r2) = ctx->r3;
L_8005B138:
    // 0x8005B138: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B13C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B140: lbu         $a0, 0xCB($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XCB);
    // 0x8005B144: sb          $a0, 0xB3($v0)
    MEM_B(0XB3, ctx->r2) = ctx->r4;
L_8005B148:
    // 0x8005B148: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B14C: lhu         $v1, 0xA4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA4);
    // 0x8005B150: beq         $v1, $zero, L_8005B1F4
    if (ctx->r3 == 0) {
        // 0x8005B154: nop
    
            goto L_8005B1F4;
    }
    // 0x8005B154: nop

    // 0x8005B158: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B15C: lbu         $v1, 0xAF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XAF);
    // 0x8005B160: bne         $v1, $zero, L_8005B17C
    if (ctx->r3 != 0) {
        // 0x8005B164: nop
    
            goto L_8005B17C;
    }
    // 0x8005B164: nop

    // 0x8005B168: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B16C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B170: lhu         $a0, 0xA4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA4);
    // 0x8005B174: j           L_8005B1EC
    // 0x8005B178: sh          $a0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r4;
        goto L_8005B1EC;
    // 0x8005B178: sh          $a0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r4;
L_8005B17C:
    // 0x8005B17C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B180: sb          $zero, 0xAF($v0)
    MEM_B(0XAF, ctx->r2) = 0;
    // 0x8005B184: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B188: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005B18C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005B190: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005B194: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005B198: sb          $v0, 0x14($fp)
    MEM_B(0X14, ctx->r30) = ctx->r2;
    // 0x8005B19C: lbu         $v0, 0x14($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B1A0: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005B1A4: beq         $v1, $zero, L_8005B1BC
    if (ctx->r3 == 0) {
        // 0x8005B1A8: nop
    
            goto L_8005B1BC;
    }
    // 0x8005B1A8: nop

    // 0x8005B1AC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B1B0: lbu         $v1, 0x14($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B1B4: j           L_8005B1EC
    // 0x8005B1B8: sh          $v1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r3;
        goto L_8005B1EC;
    // 0x8005B1B8: sh          $v1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r3;
L_8005B1BC:
    // 0x8005B1BC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B1C0: lbu         $v1, 0x14($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B1C4: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005B1C8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8005B1CC: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x8005B1D0: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B1D4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005B1D8: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8005B1DC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8005B1E0: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8005B1E4: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8005B1E8: sh          $a0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r4;
L_8005B1EC:
    // 0x8005B1EC: j           L_8005B25C
    // 0x8005B1F0: nop

        goto L_8005B25C;
    // 0x8005B1F0: nop

L_8005B1F4:
    // 0x8005B1F4: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B1F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005B1FC: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005B200: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005B204: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005B208: sb          $v0, 0x14($fp)
    MEM_B(0X14, ctx->r30) = ctx->r2;
    // 0x8005B20C: lbu         $v0, 0x14($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B210: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005B214: beq         $v1, $zero, L_8005B22C
    if (ctx->r3 == 0) {
        // 0x8005B218: nop
    
            goto L_8005B22C;
    }
    // 0x8005B218: nop

    // 0x8005B21C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B220: lbu         $v1, 0x14($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B224: j           L_8005B25C
    // 0x8005B228: sh          $v1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r3;
        goto L_8005B25C;
    // 0x8005B228: sh          $v1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r3;
L_8005B22C:
    // 0x8005B22C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B230: lbu         $v1, 0x14($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X14);
    // 0x8005B234: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005B238: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8005B23C: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x8005B240: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B244: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005B248: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8005B24C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8005B250: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8005B254: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8005B258: sh          $a0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r4;
L_8005B25C:
    // 0x8005B25C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B260: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B264: lw          $a0, 0x38($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X38);
    // 0x8005B268: sw          $a0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r4;
    // 0x8005B26C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B270: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B274: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B278: lhu         $a1, 0x92($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X92);
    // 0x8005B27C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8005B280: sll         $a1, $a0, 8
    ctx->r5 = S32(ctx->r4 << 8);
    // 0x8005B284: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x8005B288: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x8005B28C: sw          $a0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r4;
    // 0x8005B290: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B294: sh          $zero, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = 0;
    // 0x8005B298: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B29C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2A0: lbu         $a0, 0xC7($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC7);
    // 0x8005B2A4: sb          $a0, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r4;
    // 0x8005B2A8: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2AC: sb          $zero, 0xC9($v0)
    MEM_B(0XC9, ctx->r2) = 0;
    // 0x8005B2B0: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005B2B4: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x8005B2B8: beq         $v0, $v1, L_8005B548
    if (ctx->r2 == ctx->r3) {
        // 0x8005B2BC: nop
    
            goto L_8005B548;
    }
    // 0x8005B2BC: nop

    // 0x8005B2C0: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2C4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8005B2C8: sw          $v1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r3;
    // 0x8005B2CC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2D0: lw          $v1, 0x7C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7C);
    // 0x8005B2D4: beq         $v1, $zero, L_8005B398
    if (ctx->r3 == 0) {
        // 0x8005B2D8: nop
    
            goto L_8005B398;
    }
    // 0x8005B2D8: nop

    // 0x8005B2DC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2E0: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B2E4: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005B2E8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005B2EC: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005B2F0: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x8005B2F4: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005B2F8: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8005B2FC: sh          $a0, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r4;
    // 0x8005B300: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B304: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B308: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005B30C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005B310: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005B314: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x8005B318: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005B31C: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x8005B320: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8005B324: srl         $v1, $a1, 1
    ctx->r3 = S32(U32(ctx->r5) >> 1);
    // 0x8005B328: sb          $v1, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r3;
    // 0x8005B32C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B330: lw          $v0, 0x70($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X70);
    // 0x8005B334: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B338: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8005B33C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005B340: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005B344: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x8005B348: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005B34C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005B350: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8005B354: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8005B358: sll         $a0, $a1, 3
    ctx->r4 = S32(ctx->r5 << 3);
    // 0x8005B35C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8005B360: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005B364: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8005B368: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B36C: jal         0x80058480
    // 0x8005B370: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80058480(rdram, ctx);
        goto after_1;
    // 0x8005B370: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8005B374: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B378: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005B37C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005B380: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005B384: lw          $a0, 0x7C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7C);
    // 0x8005B388: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005B38C: addiu       $v1, $v0, 0x3
    ctx->r3 = ADD32(ctx->r2, 0X3);
    // 0x8005B390: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005B394: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
L_8005B398:
    // 0x8005B398: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B39C: lbu         $v1, 0xCE($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCE);
    // 0x8005B3A0: bne         $v1, $zero, L_8005B3B0
    if (ctx->r3 != 0) {
        // 0x8005B3A4: nop
    
            goto L_8005B3B0;
    }
    // 0x8005B3A4: nop

    // 0x8005B3A8: jal         0x8005BAA4
    // 0x8005B3AC: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    func_8005BAA4(rdram, ctx);
        goto after_2;
    // 0x8005B3AC: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    after_2:
L_8005B3B0:
    // 0x8005B3B0: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B3B4: lbu         $v1, 0xCC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCC);
    // 0x8005B3B8: beq         $v1, $zero, L_8005B3C8
    if (ctx->r3 == 0) {
        // 0x8005B3BC: nop
    
            goto L_8005B3C8;
    }
    // 0x8005B3BC: nop

    // 0x8005B3C0: jal         0x8005BEB8
    // 0x8005B3C4: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    func_8005BEB8(rdram, ctx);
        goto after_3;
    // 0x8005B3C4: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    after_3:
L_8005B3C8:
    // 0x8005B3C8: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B3CC: lhu         $v1, 0xA6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA6);
    // 0x8005B3D0: sw          $v1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r3;
    // 0x8005B3D4: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B3D8: lbu         $v1, 0xCF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCF);
    // 0x8005B3DC: bne         $v1, $zero, L_8005B480
    if (ctx->r3 != 0) {
        // 0x8005B3E0: nop
    
            goto L_8005B480;
    }
    // 0x8005B3E0: nop

    // 0x8005B3E4: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B3E8: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005B3EC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005B3F0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005B3F4: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005B3F8: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005B3FC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005B400: sw          $v1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r3;
    // 0x8005B404: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B408: lw          $v1, 0x24($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X24);
    // 0x8005B40C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8005B410: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B414: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005B418: beq         $v1, $zero, L_8005B474
    if (ctx->r3 == 0) {
        // 0x8005B41C: nop
    
            goto L_8005B474;
    }
    // 0x8005B41C: nop

    // 0x8005B420: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B424: lhu         $v1, 0x98($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X98);
    // 0x8005B428: beq         $v1, $zero, L_8005B474
    if (ctx->r3 == 0) {
        // 0x8005B42C: nop
    
            goto L_8005B474;
    }
    // 0x8005B42C: nop

    // 0x8005B430: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B434: sh          $zero, 0x98($v0)
    MEM_H(0X98, ctx->r2) = 0;
    // 0x8005B438: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005B43C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B440: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B444: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B448: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B44C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B450: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B454: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B458: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B45C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005B460: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B464: jal         0x8005D7D0
    // 0x8005B468: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    func_8005D7D0(rdram, ctx);
        goto after_4;
    // 0x8005B468: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    after_4:
    // 0x8005B46C: j           L_8005B480
    // 0x8005B470: nop

        goto L_8005B480;
    // 0x8005B470: nop

L_8005B474:
    // 0x8005B474: lw          $a0, 0x38($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X38);
    // 0x8005B478: jal         0x8005B624
    // 0x8005B47C: lw          $a1, 0x3C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X3C);
    func_8005B624(rdram, ctx);
        goto after_5;
    // 0x8005B47C: lw          $a1, 0x3C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X3C);
    after_5:
L_8005B480:
    // 0x8005B480: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B484: lwc1        $f0, 0x18($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X18);
    // 0x8005B488: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005B48C: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B490: lw          $a0, 0x1C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X1C);
    // 0x8005B494: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005B498: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005B49C: lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X28);
    // 0x8005B4A0: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005B4A4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005B4A8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B4AC: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8005B4B0: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B4B4: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B4B8: lbu         $v0, 0xC2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC2);
    // 0x8005B4BC: lbu         $v1, 0xC4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XC4);
    // 0x8005B4C0: beq         $v0, $v1, L_8005B540
    if (ctx->r2 == ctx->r3) {
        // 0x8005B4C4: nop
    
            goto L_8005B540;
    }
    // 0x8005B4C4: nop

    // 0x8005B4C8: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B4CC: lbu         $v1, 0xC3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC3);
    // 0x8005B4D0: sb          $v1, 0x28($fp)
    MEM_B(0X28, ctx->r30) = ctx->r3;
    // 0x8005B4D4: lbu         $v0, 0x28($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X28);
    // 0x8005B4D8: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8005B4DC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B4E0: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B4E4: lbu         $a0, 0xC2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC2);
    // 0x8005B4E8: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B4EC: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B4F0: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005B4F4: lbu         $v0, 0x28($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X28);
    // 0x8005B4F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B4FC: sb          $v0, 0x28($fp)
    MEM_B(0X28, ctx->r30) = ctx->r2;
    // 0x8005B500: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B504: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B508: lbu         $a0, 0xC2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC2);
    // 0x8005B50C: sb          $a0, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r4;
    // 0x8005B510: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005B514: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B518: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B51C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B520: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B524: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B528: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B52C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B530: lbu         $v1, 0x28($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X28);
    // 0x8005B534: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B538: jal         0x8005D5F0
    // 0x8005B53C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    func_8005D5F0(rdram, ctx);
        goto after_6;
    // 0x8005B53C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_6:
L_8005B540:
    // 0x8005B540: j           L_8005B594
    // 0x8005B544: nop

        goto L_8005B594;
    // 0x8005B544: nop

L_8005B548:
    // 0x8005B548: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B54C: lbu         $v1, 0xBB($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBB);
    // 0x8005B550: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8005B554: beq         $v0, $zero, L_8005B594
    if (ctx->r2 == 0) {
        // 0x8005B558: nop
    
            goto L_8005B594;
    }
    // 0x8005B558: nop

    // 0x8005B55C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B560: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8005B564: sb          $v1, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r3;
    // 0x8005B568: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B56C: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B570: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x8005B574: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
    // 0x8005B578: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B57C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005B580: sb          $v1, 0xBD($v0)
    MEM_B(0XBD, ctx->r2) = ctx->r3;
    // 0x8005B584: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B588: lw          $v1, 0x38($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X38);
    // 0x8005B58C: lbu         $a0, 0xBC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBC);
    // 0x8005B590: sb          $a0, 0xC5($v0)
    MEM_B(0XC5, ctx->r2) = ctx->r4;
L_8005B594:
    // 0x8005B594: j           L_8005B610
    // 0x8005B598: nop

        goto L_8005B610;
    // 0x8005B598: nop

L_8005B59C:
    // 0x8005B59C: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B5A0: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005B5A4: beq         $v1, $zero, L_8005B610
    if (ctx->r3 == 0) {
        // 0x8005B5A8: nop
    
            goto L_8005B610;
    }
    // 0x8005B5A8: nop

    // 0x8005B5AC: lw          $v0, 0x38($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X38);
    // 0x8005B5B0: sb          $zero, 0xC1($v0)
    MEM_B(0XC1, ctx->r2) = 0;
    // 0x8005B5B4: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005B5B8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B5BC: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B5C0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B5C4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B5C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B5CC: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B5D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B5D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B5D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005B5DC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B5E0: jal         0x8005D7D0
    // 0x8005B5E4: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    func_8005D7D0(rdram, ctx);
        goto after_7;
    // 0x8005B5E4: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    after_7:
    // 0x8005B5E8: lw          $v0, 0x3C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X3C);
    // 0x8005B5EC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B5F0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B5F4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B5F8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B5FC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B600: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B604: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B608: jal         0x8005D950
    // 0x8005B60C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005D950(rdram, ctx);
        goto after_8;
    // 0x8005B60C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_8:
L_8005B610:
    // 0x8005B610: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005B614: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005B618: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8005B61C: jr          $ra
    // 0x8005B620: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005B620: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005B624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B62C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005B630: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005B634: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005B638: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005B63C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005B640: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005B644: beq         $v1, $zero, L_8005B674
    if (ctx->r3 == 0) {
        // 0x8005B648: nop
    
            goto L_8005B674;
    }
    // 0x8005B648: nop

    // 0x8005B64C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005B650: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B654: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B658: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B65C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B660: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B664: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B668: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B66C: jal         0x8005D950
    // 0x8005B670: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005D950(rdram, ctx);
        goto after_0;
    // 0x8005B670: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
L_8005B674:
    // 0x8005B674: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005B678: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005B67C: sb          $v1, 0xC1($v0)
    MEM_B(0XC1, ctx->r2) = ctx->r3;
    // 0x8005B680: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005B684: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B688: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B68C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B690: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B694: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B698: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B69C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B6A0: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005B6A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B6A8: jal         0x8005D8A0
    // 0x8005B6AC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    func_8005D8A0(rdram, ctx);
        goto after_1;
    // 0x8005B6AC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x8005B6B0: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005B6B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005B6B8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005B6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B6C0: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005B6C4: jr          $ra
    // 0x8005B6C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005B6C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005B6CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B6CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B6D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B6D4: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8005B6D8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005B6DC: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x8005B6E0: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x8005B6E4: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B6E8: lbu         $v0, 0xB4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB4);
    // 0x8005B6EC: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B6F0: lbu         $a0, 0xBC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBC);
    // 0x8005B6F4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B6F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B6FC: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B700: lbu         $a0, 0xB3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB3);
    // 0x8005B704: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B708: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B70C: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B710: lh          $a0, 0x96($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X96);
    // 0x8005B714: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B718: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B71C: srl         $v1, $v0, 13
    ctx->r3 = S32(U32(ctx->r2) >> 13);
    // 0x8005B720: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
    // 0x8005B724: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B728: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
    // 0x8005B72C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8005B730: beq         $v0, $zero, L_8005B740
    if (ctx->r2 == 0) {
        // 0x8005B734: nop
    
            goto L_8005B740;
    }
    // 0x8005B734: nop

    // 0x8005B738: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8005B73C: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_8005B740:
    // 0x8005B740: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B744: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005B748: bne         $v1, $zero, L_8005B76C
    if (ctx->r3 != 0) {
        // 0x8005B74C: nop
    
            goto L_8005B76C;
    }
    // 0x8005B74C: nop

    // 0x8005B750: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B754: lhu         $v0, 0x74A8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X74A8);
    // 0x8005B758: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005B75C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B760: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B764: j           L_8005B784
    // 0x8005B768: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
        goto L_8005B784;
    // 0x8005B768: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_8005B76C:
    // 0x8005B76C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B770: lhu         $v0, -0x381C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X381C);
    // 0x8005B774: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005B778: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B77C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B780: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_8005B784:
    // 0x8005B784: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B788: srl         $v1, $v0, 15
    ctx->r3 = S32(U32(ctx->r2) >> 15);
    // 0x8005B78C: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
    // 0x8005B790: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B794: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8005B798: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005B79C: beq         $v1, $v0, L_8005B7D8
    if (ctx->r3 == ctx->r2) {
        // 0x8005B7A0: nop
    
            goto L_8005B7D8;
    }
    // 0x8005B7A0: nop

    // 0x8005B7A4: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B7A8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005B7AC: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005B7B0: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B7B4: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B7B8: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B7BC: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x8005B7C0: divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // 0x8005B7C4: bne         $a0, $zero, L_8005B7D0
    if (ctx->r4 != 0) {
        // 0x8005B7C8: nop
    
            goto L_8005B7D0;
    }
    // 0x8005B7C8: nop

    // 0x8005B7CC: break       7
    do_break(2147858380);
L_8005B7D0:
    // 0x8005B7D0: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B7D4: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
L_8005B7D8:
    // 0x8005B7D8: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B7DC: lhu         $v1, 0x98($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X98);
    // 0x8005B7E0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005B7E4: beq         $v0, $v1, L_8005B830
    if (ctx->r2 == ctx->r3) {
        // 0x8005B7E8: nop
    
            goto L_8005B830;
    }
    // 0x8005B7E8: nop

    // 0x8005B7EC: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B7F0: lhu         $v1, 0x12($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X12);
    // 0x8005B7F4: sh          $v1, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r3;
    // 0x8005B7F8: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x8005B7FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B800: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B804: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B808: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B80C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B810: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B814: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B818: lh          $v1, 0x12($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X12);
    // 0x8005B81C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B820: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8005B824: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B828: jal         0x8005D7D0
    // 0x8005B82C: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    func_8005D7D0(rdram, ctx);
        goto after_0;
    // 0x8005B82C: lw          $a2, -0x4430($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4430);
    after_0:
L_8005B830:
    // 0x8005B830: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B834: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B838: lbu         $v0, 0xB5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB5);
    // 0x8005B83C: lbu         $v1, 0xB6($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB6);
    // 0x8005B840: beq         $v0, $v1, L_8005B8AC
    if (ctx->r2 == ctx->r3) {
        // 0x8005B844: nop
    
            goto L_8005B8AC;
    }
    // 0x8005B844: nop

    // 0x8005B848: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B84C: lbu         $v0, 0xB5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB5);
    // 0x8005B850: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B854: lh          $a0, 0xA8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA8);
    // 0x8005B858: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B85C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B860: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005B864: andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // 0x8005B868: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x8005B86C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005B870: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005B874: lbu         $a0, 0xB5($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB5);
    // 0x8005B878: sb          $a0, 0xB6($v0)
    MEM_B(0XB6, ctx->r2) = ctx->r4;
    // 0x8005B87C: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x8005B880: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B884: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005B888: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B88C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005B890: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005B894: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005B898: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B89C: lbu         $v1, 0x13($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X13);
    // 0x8005B8A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005B8A4: jal         0x8005D690
    // 0x8005B8A8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    func_8005D690(rdram, ctx);
        goto after_1;
    // 0x8005B8A8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_1:
L_8005B8AC:
    // 0x8005B8AC: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005B8B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B8B4: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x8005B8B8: jr          $ra
    // 0x8005B8BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005B8BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005B8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B8C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005B8C8: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x8005B8CC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005B8D0: sw          $a0, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r4;
    // 0x8005B8D4: sw          $a1, 0x2C($fp)
    MEM_W(0X2C, ctx->r30) = ctx->r5;
    // 0x8005B8D8: sw          $a2, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r6;
    // 0x8005B8DC: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B8E0: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8005B8E4: swc1        $f0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f0.u32l;
    // 0x8005B8E8: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B8EC: lbu         $v1, 0xB0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB0);
    // 0x8005B8F0: beq         $v1, $zero, L_8005B984
    if (ctx->r3 == 0) {
        // 0x8005B8F4: nop
    
            goto L_8005B984;
    }
    // 0x8005B8F4: nop

    // 0x8005B8F8: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B8FC: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005B900: lbu         $a0, 0xB0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB0);
    // 0x8005B904: lhu         $v0, 0xA2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA2);
    // 0x8005B908: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005B90C: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8005B910: bne         $v0, $zero, L_8005B978
    if (ctx->r2 != 0) {
        // 0x8005B914: nop
    
            goto L_8005B978;
    }
    // 0x8005B914: nop

    // 0x8005B918: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B91C: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005B920: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005B924: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005B928: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B92C: lbu         $v1, 0xB0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB0);
    // 0x8005B930: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8005B934: nop

    // 0x8005B938: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005B93C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005B940: swc1        $f0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->f0.u32l;
    // 0x8005B944: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B948: lhu         $v1, 0xA2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA2);
    // 0x8005B94C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005B950: nop

    // 0x8005B954: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005B958: lwc1        $f2, 0x14($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X14);
    // 0x8005B95C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005B960: swc1        $f0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->f0.u32l;
    // 0x8005B964: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B968: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005B96C: lwc1        $f2, 0x14($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X14);
    // 0x8005B970: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B974: swc1        $f0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f0.u32l;
L_8005B978:
    // 0x8005B978: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B97C: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005B980: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
L_8005B984:
    // 0x8005B984: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005B988: lb          $v0, 0xB1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0XB1);
    // 0x8005B98C: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005B990: lbu         $a0, 0xB2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB2);
    // 0x8005B994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005B998: subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
    // 0x8005B99C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B9A0: mflo        $v0
    ctx->r2 = lo;
    // 0x8005B9A4: sw          $v0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r2;
    // 0x8005B9A8: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B9AC: sb          $zero, 0xB2($v0)
    MEM_B(0XB2, ctx->r2) = 0;
    // 0x8005B9B0: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B9B4: lwc1        $f0, 0x30($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X30);
    // 0x8005B9B8: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8005B9BC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B9C0: lwc1        $f2, 0x18($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X18);
    // 0x8005B9C4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005B9C8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B9CC: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005B9D0: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005B9D4: swc1        $f0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f0.u32l;
    // 0x8005B9D8: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005B9DC: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005B9E0: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8005B9E4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8005B9E8: nop

    // 0x8005B9EC: bc1f        L_8005B9FC
    if (!c1cs) {
        // 0x8005B9F0: nop
    
            goto L_8005B9FC;
    }
    // 0x8005B9F0: nop

    // 0x8005B9F4: j           L_8005BA90
    // 0x8005B9F8: nop

        goto L_8005BA90;
    // 0x8005B9F8: nop

L_8005B9FC:
    // 0x8005B9FC: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005BA00: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005BA04: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8005BA08: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005BA0C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005BA10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005BA14: ldc1        $f2, -0x1298($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1298);
    // 0x8005BA18: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005BA1C: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005BA20: jal         0x8005C524
    // 0x8005BA24: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    func_8005C524(rdram, ctx);
        goto after_0;
    // 0x8005BA24: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    after_0:
    // 0x8005BA28: swc1        $f0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f0.u32l;
    // 0x8005BA2C: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005BA30: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005BA34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005BA38: ldc1        $f2, -0x1290($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1290);
    // 0x8005BA3C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8005BA40: nop

    // 0x8005BA44: bc1f        L_8005BA64
    if (!c1cs) {
        // 0x8005BA48: nop
    
            goto L_8005BA64;
    }
    // 0x8005BA48: nop

    // 0x8005BA4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005BA54: nop

    // 0x8005BA58: swc1        $f0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f0.u32l;
    // 0x8005BA5C: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005BA60: sb          $zero, 0xB3($v0)
    MEM_B(0XB3, ctx->r2) = 0;
L_8005BA64:
    // 0x8005BA64: lw          $v0, 0x2C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X2C);
    // 0x8005BA68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005BA6C: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x8005BA70: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005BA74: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005BA78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005BA7C: lw          $v1, 0x7660($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7660);
    // 0x8005BA80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005BA84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005BA88: jal         0x8005D730
    // 0x8005BA8C: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    func_8005D730(rdram, ctx);
        goto after_1;
    // 0x8005BA8C: lw          $a1, 0x10($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X10);
    after_1:
L_8005BA90:
    // 0x8005BA90: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005BA94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005BA98: lw          $fp, 0x20($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X20);
    // 0x8005BA9C: jr          $ra
    // 0x8005BAA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005BAA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005BAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BAA4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005BAA8: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x8005BAAC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005BAB0: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x8005BAB4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BAB8: lhu         $v1, 0x92($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X92);
    // 0x8005BABC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8005BAC0: beq         $v1, $v0, L_8005BB24
    if (ctx->r3 == ctx->r2) {
        // 0x8005BAC4: nop
    
            goto L_8005BB24;
    }
    // 0x8005BAC4: nop

    // 0x8005BAC8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BACC: lhu         $v1, 0xAA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XAA);
    // 0x8005BAD0: beq         $v1, $zero, L_8005BAFC
    if (ctx->r3 == 0) {
        // 0x8005BAD4: nop
    
            goto L_8005BAFC;
    }
    // 0x8005BAD4: nop

    // 0x8005BAD8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BADC: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BAE0: lw          $a0, 0x8($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X8);
    // 0x8005BAE4: lhu         $a1, 0xAA($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0XAA);
    // 0x8005BAE8: sll         $a0, $a1, 8
    ctx->r4 = S32(ctx->r5 << 8);
    // 0x8005BAEC: lw          $v1, 0x3C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3C);
    // 0x8005BAF0: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8005BAF4: j           L_8005BB1C
    // 0x8005BAF8: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
        goto L_8005BB1C;
    // 0x8005BAF8: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
L_8005BAFC:
    // 0x8005BAFC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB00: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB04: lw          $a0, 0x8($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB08: lhu         $a1, 0xAC($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0XAC);
    // 0x8005BB0C: sll         $a0, $a1, 8
    ctx->r4 = S32(ctx->r5 << 8);
    // 0x8005BB10: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x8005BB14: subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // 0x8005BB18: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
L_8005BB1C:
    // 0x8005BB1C: j           L_8005BB34
    // 0x8005BB20: nop

        goto L_8005BB34;
    // 0x8005BB20: nop

L_8005BB24:
    // 0x8005BB24: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB28: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x8005BB2C: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005BB30: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
L_8005BB34:
    // 0x8005BB34: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB38: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB3C: lbu         $a0, 0xB8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB8);
    // 0x8005BB40: sb          $a0, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r4;
    // 0x8005BB44: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB48: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB4C: lbu         $a0, 0xB7($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB7);
    // 0x8005BB50: sb          $a0, 0xBD($v0)
    MEM_B(0XBD, ctx->r2) = ctx->r4;
    // 0x8005BB54: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BB58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005BB5C: sb          $v1, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r3;
    // 0x8005BB60: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005BB64: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005BB68: jr          $ra
    // 0x8005BB6C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005BB6C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005BB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BB70: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005BB74: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005BB78: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005BB7C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x8005BB80: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BB84: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BB88: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005BB8C: lw          $v1, 0x50($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50);
    // 0x8005BB90: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005BB94: bne         $v0, $zero, L_8005BBD8
    if (ctx->r2 != 0) {
        // 0x8005BB98: nop
    
            goto L_8005BBD8;
    }
    // 0x8005BB98: nop

    // 0x8005BB9C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBA0: lbu         $v1, 0xBB($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBB);
    // 0x8005BBA4: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8005BBA8: beq         $v0, $zero, L_8005BBD8
    if (ctx->r2 == 0) {
        // 0x8005BBAC: nop
    
            goto L_8005BBD8;
    }
    // 0x8005BBAC: nop

    // 0x8005BBB0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBB4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8005BBB8: sb          $v1, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r3;
    // 0x8005BBBC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005BBC4: sb          $v1, 0xBD($v0)
    MEM_B(0XBD, ctx->r2) = ctx->r3;
    // 0x8005BBC8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBCC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBD0: lbu         $a0, 0xBC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBC);
    // 0x8005BBD4: sb          $a0, 0xC5($v0)
    MEM_B(0XC5, ctx->r2) = ctx->r4;
L_8005BBD8:
    // 0x8005BBD8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBDC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBE0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBE4: lbu         $a0, 0xBD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBD);
    // 0x8005BBE8: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8005BBEC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005BBF0: sb          $a0, 0xBD($v0)
    MEM_B(0XBD, ctx->r2) = ctx->r4;
    // 0x8005BBF4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BBF8: lbu         $v1, 0xBD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBD);
    // 0x8005BBFC: bne         $v1, $zero, L_8005BEA8
    if (ctx->r3 != 0) {
        // 0x8005BC00: nop
    
            goto L_8005BEA8;
    }
    // 0x8005BC00: nop

    // 0x8005BC04: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC08: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC0C: lbu         $a0, 0xB7($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB7);
    // 0x8005BC10: sb          $a0, 0xBD($v0)
    MEM_B(0XBD, ctx->r2) = ctx->r4;
    // 0x8005BC14: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC18: lbu         $v0, 0xBB($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XBB);
    // 0x8005BC1C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8005BC20: beq         $v0, $v1, L_8005BD1C
    if (ctx->r2 == ctx->r3) {
        // 0x8005BC24: nop
    
            goto L_8005BD1C;
    }
    // 0x8005BC24: nop

    // 0x8005BC28: slti        $v1, $v0, 0x3
    ctx->r3 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8005BC2C: beq         $v1, $zero, L_8005BC48
    if (ctx->r3 == 0) {
        // 0x8005BC30: nop
    
            goto L_8005BC48;
    }
    // 0x8005BC30: nop

    // 0x8005BC34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005BC38: beq         $v0, $v1, L_8005BC68
    if (ctx->r2 == ctx->r3) {
        // 0x8005BC3C: nop
    
            goto L_8005BC68;
    }
    // 0x8005BC3C: nop

    // 0x8005BC40: j           L_8005BEA8
    // 0x8005BC44: nop

        goto L_8005BEA8;
    // 0x8005BC44: nop

L_8005BC48:
    // 0x8005BC48: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8005BC4C: beq         $v0, $v1, L_8005BDDC
    if (ctx->r2 == ctx->r3) {
        // 0x8005BC50: nop
    
            goto L_8005BDDC;
    }
    // 0x8005BC50: nop

    // 0x8005BC54: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8005BC58: beq         $v0, $v1, L_8005BDE4
    if (ctx->r2 == ctx->r3) {
        // 0x8005BC5C: nop
    
            goto L_8005BDE4;
    }
    // 0x8005BC5C: nop

    // 0x8005BC60: j           L_8005BEA8
    // 0x8005BC64: nop

        goto L_8005BEA8;
    // 0x8005BC64: nop

L_8005BC68:
    // 0x8005BC68: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC6C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC70: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005BC74: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x8005BC78: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8005BC7C: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x8005BC80: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC84: lw          $a0, 0x60($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X60);
    // 0x8005BC88: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BC8C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BC90: srl         $v1, $v0, 10
    ctx->r3 = S32(U32(ctx->r2) >> 10);
    // 0x8005BC94: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005BC98: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BC9C: lbu         $v1, 0xBE($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBE);
    // 0x8005BCA0: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005BCA4: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BCA8: beq         $v1, $zero, L_8005BCEC
    if (ctx->r3 == 0) {
        // 0x8005BCAC: nop
    
            goto L_8005BCEC;
    }
    // 0x8005BCAC: nop

    // 0x8005BCB0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCB4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCB8: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCBC: lwc1        $f0, 0x4($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X4);
    // 0x8005BCC0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005BCC4: lwc1        $f2, 0x54($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8005BCC8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005BCCC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005BCD0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8005BCD4: lbu         $v1, 0xB8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB8);
    // 0x8005BCD8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005BCDC: j           L_8005BEA8
    // 0x8005BCE0: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
        goto L_8005BEA8;
    // 0x8005BCE0: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
    // 0x8005BCE4: j           L_8005BD1C
    // 0x8005BCE8: nop

        goto L_8005BD1C;
    // 0x8005BCE8: nop

L_8005BCEC:
    // 0x8005BCEC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCF0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCF4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BCF8: lbu         $a0, 0xBB($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBB);
    // 0x8005BCFC: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8005BD00: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005BD04: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x8005BD08: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD0C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD10: lbu         $a0, 0xB9($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB9);
    // 0x8005BD14: j           L_8005BEA8
    // 0x8005BD18: sb          $a0, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r4;
        goto L_8005BEA8;
    // 0x8005BD18: sb          $a0, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r4;
L_8005BD1C:
    // 0x8005BD1C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD20: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD24: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005BD28: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x8005BD2C: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8005BD30: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x8005BD34: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD38: lbu         $a0, 0xBE($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBE);
    // 0x8005BD3C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8005BD40: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD44: lw          $a0, 0x60($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X60);
    // 0x8005BD48: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BD4C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BD50: srl         $v1, $v0, 10
    ctx->r3 = S32(U32(ctx->r2) >> 10);
    // 0x8005BD54: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005BD58: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD5C: lbu         $v1, 0xBF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XBF);
    // 0x8005BD60: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005BD64: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BD68: beq         $v1, $zero, L_8005BDAC
    if (ctx->r3 == 0) {
        // 0x8005BD6C: nop
    
            goto L_8005BDAC;
    }
    // 0x8005BD6C: nop

    // 0x8005BD70: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD74: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD78: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005BD7C: lwc1        $f0, 0x4($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X4);
    // 0x8005BD80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005BD84: lwc1        $f2, 0x58($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8005BD88: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005BD8C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005BD90: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8005BD94: lbu         $v1, 0xB9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB9);
    // 0x8005BD98: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005BD9C: j           L_8005BEA8
    // 0x8005BDA0: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
        goto L_8005BEA8;
    // 0x8005BDA0: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
    // 0x8005BDA4: j           L_8005BDDC
    // 0x8005BDA8: nop

        goto L_8005BDDC;
    // 0x8005BDA8: nop

L_8005BDAC:
    // 0x8005BDAC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDB0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDB4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDB8: lbu         $a0, 0xBB($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBB);
    // 0x8005BDBC: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8005BDC0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005BDC4: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x8005BDC8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDCC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDD0: lbu         $a0, 0xBA($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBA);
    // 0x8005BDD4: j           L_8005BEA8
    // 0x8005BDD8: sb          $a0, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r4;
        goto L_8005BEA8;
    // 0x8005BDD8: sb          $a0, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r4;
L_8005BDDC:
    // 0x8005BDDC: j           L_8005BEA8
    // 0x8005BDE0: nop

        goto L_8005BEA8;
    // 0x8005BDE0: nop

L_8005BDE4:
    // 0x8005BDE4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDE8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BDEC: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005BDF0: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x8005BDF4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8005BDF8: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x8005BDFC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE00: lw          $a0, 0x60($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X60);
    // 0x8005BE04: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BE08: mflo        $v0
    ctx->r2 = lo;
    // 0x8005BE0C: srl         $v1, $v0, 10
    ctx->r3 = S32(U32(ctx->r2) >> 10);
    // 0x8005BE10: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005BE14: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE18: lbu         $v1, 0xC0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC0);
    // 0x8005BE1C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005BE20: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BE24: beq         $v1, $zero, L_8005BE80
    if (ctx->r3 == 0) {
        // 0x8005BE28: nop
    
            goto L_8005BE80;
    }
    // 0x8005BE28: nop

    // 0x8005BE2C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE30: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE34: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE38: lwc1        $f0, 0x4($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X4);
    // 0x8005BE3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005BE40: lwc1        $f2, 0x5C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8005BE44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005BE48: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE4C: lbu         $a1, 0xC5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0XC5);
    // 0x8005BE50: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x8005BE54: nop

    // 0x8005BE58: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005BE5C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005BE60: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005BE64: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8005BE68: lbu         $v1, 0xC5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XC5);
    // 0x8005BE6C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8005BE70: j           L_8005BEA8
    // 0x8005BE74: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
        goto L_8005BEA8;
    // 0x8005BE74: sb          $v1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r3;
    // 0x8005BE78: j           L_8005BEA8
    // 0x8005BE7C: nop

        goto L_8005BEA8;
    // 0x8005BE7C: nop

L_8005BE80:
    // 0x8005BE80: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE84: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE88: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BE8C: lbu         $a0, 0xBB($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBB);
    // 0x8005BE90: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8005BE94: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005BE98: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x8005BE9C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BEA0: j           L_8005BEA8
    // 0x8005BEA4: sb          $zero, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = 0;
        goto L_8005BEA8;
    // 0x8005BEA4: sb          $zero, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = 0;
L_8005BEA8:
    // 0x8005BEA8: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005BEAC: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005BEB0: jr          $ra
    // 0x8005BEB4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005BEB4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005BEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BEB8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005BEBC: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x8005BEC0: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005BEC4: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x8005BEC8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BECC: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BED0: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x8005BED4: sw          $a0, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r4;
    // 0x8005BED8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BEDC: sb          $zero, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = 0;
    // 0x8005BEE0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005BEE4: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005BEE8: lbu         $a0, 0xB5($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB5);
    // 0x8005BEEC: andi        $v1, $a0, 0x40
    ctx->r3 = ctx->r4 & 0X40;
    // 0x8005BEF0: sb          $v1, 0xD2($v0)
    MEM_B(0XD2, ctx->r2) = ctx->r3;
    // 0x8005BEF4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005BEF8: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005BEFC: jr          $ra
    // 0x8005BF00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005BF00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005BF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BF04: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005BF08: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005BF0C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005BF10: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
L_8005BF14:
    // 0x8005BF14: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF18: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF1C: lw          $a0, 0x8C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8C);
    // 0x8005BF20: addiu       $v1, $a0, 0x100
    ctx->r3 = ADD32(ctx->r4, 0X100);
    // 0x8005BF24: sw          $v1, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r3;
    // 0x8005BF28: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF2C: lbu         $v0, 0xD1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD1);
    // 0x8005BF30: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF34: lbu         $a0, 0xCC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XCC);
    // 0x8005BF38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005BF3C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005BF40: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005BF44: sltiu       $v1, $v0, 0x40
    ctx->r3 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x8005BF48: beq         $v1, $zero, L_8005BF60
    if (ctx->r3 == 0) {
        // 0x8005BF4C: nop
    
            goto L_8005BF60;
    }
    // 0x8005BF4C: nop

    // 0x8005BF50: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF54: lbu         $v1, 0x3($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X3);
    // 0x8005BF58: j           L_8005C02C
    // 0x8005BF5C: sb          $v1, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = ctx->r3;
        goto L_8005C02C;
    // 0x8005BF5C: sb          $v1, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = ctx->r3;
L_8005BF60:
    // 0x8005BF60: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF64: lbu         $v1, 0x3($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X3);
    // 0x8005BF68: andi        $a0, $v1, 0x3F
    ctx->r4 = ctx->r3 & 0X3F;
    // 0x8005BF6C: sb          $a0, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = ctx->r4;
    // 0x8005BF70: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005BF74: srl         $v1, $v0, 6
    ctx->r3 = S32(U32(ctx->r2) >> 6);
    // 0x8005BF78: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
    // 0x8005BF7C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF80: lbu         $v1, 0xD2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD2);
    // 0x8005BF84: bne         $v1, $zero, L_8005BFD8
    if (ctx->r3 != 0) {
        // 0x8005BF88: nop
    
            goto L_8005BFD8;
    }
    // 0x8005BF88: nop

    // 0x8005BF8C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF90: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BF94: lbu         $a0, 0xB5($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB5);
    // 0x8005BF98: lbu         $v1, 0x3($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X3);
    // 0x8005BF9C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005BFA0: sb          $a0, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r4;
    // 0x8005BFA4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFA8: lbu         $v1, 0xB5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB5);
    // 0x8005BFAC: sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x8005BFB0: bne         $v0, $zero, L_8005BFD0
    if (ctx->r2 != 0) {
        // 0x8005BFB4: nop
    
            goto L_8005BFD0;
    }
    // 0x8005BFB4: nop

    // 0x8005BFB8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFBC: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8005BFC0: sb          $v1, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r3;
    // 0x8005BFC4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFC8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005BFCC: sb          $v1, 0xD2($v0)
    MEM_B(0XD2, ctx->r2) = ctx->r3;
L_8005BFD0:
    // 0x8005BFD0: j           L_8005C02C
    // 0x8005BFD4: nop

        goto L_8005C02C;
    // 0x8005BFD4: nop

L_8005BFD8:
    // 0x8005BFD8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFDC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFE0: lbu         $a0, 0xB5($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB5);
    // 0x8005BFE4: lbu         $v1, 0x3($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X3);
    // 0x8005BFE8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8005BFEC: sb          $a0, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r4;
    // 0x8005BFF0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005BFF4: lbu         $v1, 0xB5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB5);
    // 0x8005BFF8: sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // 0x8005BFFC: beq         $v0, $zero, L_8005C01C
    if (ctx->r2 == 0) {
        // 0x8005C000: nop
    
            goto L_8005C01C;
    }
    // 0x8005C000: nop

    // 0x8005C004: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C008: lbu         $v1, 0xB5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB5);
    // 0x8005C00C: bne         $v1, $zero, L_8005C02C
    if (ctx->r3 != 0) {
        // 0x8005C010: nop
    
            goto L_8005C02C;
    }
    // 0x8005C010: nop

    // 0x8005C014: j           L_8005C01C
    // 0x8005C018: nop

        goto L_8005C01C;
    // 0x8005C018: nop

L_8005C01C:
    // 0x8005C01C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C020: sb          $zero, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = 0;
    // 0x8005C024: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C028: sb          $zero, 0xD2($v0)
    MEM_B(0XD2, ctx->r2) = 0;
L_8005C02C:
    // 0x8005C02C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C030: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C034: lw          $v0, 0x8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8C);
    // 0x8005C038: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005C03C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005C040: bne         $v0, $zero, L_8005C050
    if (ctx->r2 != 0) {
        // 0x8005C044: nop
    
            goto L_8005C050;
    }
    // 0x8005C044: nop

    // 0x8005C048: j           L_8005C058
    // 0x8005C04C: nop

        goto L_8005C058;
    // 0x8005C04C: nop

L_8005C050:
    // 0x8005C050: j           L_8005BF14
    // 0x8005C054: nop

        goto L_8005BF14;
    // 0x8005C054: nop

L_8005C058:
    // 0x8005C058: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C05C: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005C060: jr          $ra
    // 0x8005C064: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005C064: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005C068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C068: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005C06C: sw          $fp, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r30;
    // 0x8005C070: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C074: sw          $a0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r4;
    // 0x8005C078: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005C07C: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C080: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005C084: lbu         $a0, 0xC8($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC8);
    // 0x8005C088: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8005C08C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C090: sb          $a0, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r4;
    // 0x8005C094: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C098: lbu         $v1, 0xC8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC8);
    // 0x8005C09C: bne         $v1, $zero, L_8005C0F0
    if (ctx->r3 != 0) {
        // 0x8005C0A0: nop
    
            goto L_8005C0F0;
    }
    // 0x8005C0A0: nop

    // 0x8005C0A4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0A8: lb          $v1, 0xC9($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XC9);
    // 0x8005C0AC: bne         $v1, $zero, L_8005C0D8
    if (ctx->r3 != 0) {
        // 0x8005C0B0: nop
    
            goto L_8005C0D8;
    }
    // 0x8005C0B0: nop

    // 0x8005C0B4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0B8: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0BC: lbu         $a0, 0xD0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD0);
    // 0x8005C0C0: sb          $a0, 0xC9($v0)
    MEM_B(0XC9, ctx->r2) = ctx->r4;
    // 0x8005C0C4: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0C8: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0CC: lbu         $a0, 0xC6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC6);
    // 0x8005C0D0: j           L_8005C0F0
    // 0x8005C0D4: sb          $a0, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r4;
        goto L_8005C0F0;
    // 0x8005C0D4: sb          $a0, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r4;
L_8005C0D8:
    // 0x8005C0D8: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0DC: sb          $zero, 0xC9($v0)
    MEM_B(0XC9, ctx->r2) = 0;
    // 0x8005C0E0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0E4: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0E8: lbu         $a0, 0xC7($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC7);
    // 0x8005C0EC: sb          $a0, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r4;
L_8005C0F0:
    // 0x8005C0F0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005C0F4: lb          $v1, 0xC9($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XC9);
    // 0x8005C0F8: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8005C0FC: nop

    // 0x8005C100: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005C104: j           L_8005C10C
    // 0x8005C108: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8005C10C;
    // 0x8005C108: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8005C10C:
    // 0x8005C10C: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C110: lw          $fp, 0x0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X0);
    // 0x8005C114: jr          $ra
    // 0x8005C118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005C118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005C11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C11C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005C120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C124: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8005C128: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005C12C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C130: sw          $a0, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r4;
    // 0x8005C134: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005C138: lhu         $v0, 0xA2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA2);
    // 0x8005C13C: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005C140: lbu         $a0, 0xAE($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XAE);
    // 0x8005C144: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8005C148: sw          $v0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r2;
    // 0x8005C14C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C150: blez        $v0, L_8005C1B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005C154: nop
    
            goto L_8005C1B4;
    }
    // 0x8005C154: nop

    // 0x8005C158: lwc1        $f20, 0x10($fp)
    ctx->f20.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C15C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8005C160: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C164: lbu         $v1, 0xCD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XCD);
    // 0x8005C168: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005C16C: nop

    // 0x8005C170: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005C174: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8005C178: add.s       $f0, $f20, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x8005C17C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005C180: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C184: ldc1        $f4, -0x1288($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1288);
    // 0x8005C188: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8005C18C: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C190: jal         0x80061290
    // 0x8005C194: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8005C194: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    after_0:
    // 0x8005C198: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C19C: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005C1A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C1A4: swc1        $f0, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->f0.u32l;
    // 0x8005C1A8: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C1AC: lwc1        $f0, 0x14($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X14);
    // 0x8005C1B0: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_8005C1B4:
    // 0x8005C1B4: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C1B8: j           L_8005C1C0
    // 0x8005C1BC: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
        goto L_8005C1C0;
    // 0x8005C1BC: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
L_8005C1C0:
    // 0x8005C1C0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C1C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C1C8: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x8005C1CC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005C1D0: jr          $ra
    // 0x8005C1D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005C1D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005C1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C1D8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005C1DC: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005C1E0: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C1E4: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
L_8005C1E8:
    // 0x8005C1E8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C1EC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C1F0: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8005C1F4: addiu       $v1, $a0, 0x100
    ctx->r3 = ADD32(ctx->r4, 0X100);
    // 0x8005C1F8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8005C1FC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C200: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C204: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C208: lhu         $a0, 0x9A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9A);
    // 0x8005C20C: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8005C210: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C214: sh          $a0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r4;
    // 0x8005C218: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C21C: lhu         $v1, 0x9A($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9A);
    // 0x8005C220: bne         $v1, $zero, L_8005C304
    if (ctx->r3 != 0) {
        // 0x8005C224: nop
    
            goto L_8005C304;
    }
    // 0x8005C224: nop

    // 0x8005C228: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C22C: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x8005C230: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005C234: sw          $a0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r4;
    // 0x8005C238: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005C23C: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x8005C240: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C244: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005C248: bne         $v1, $zero, L_8005C2EC
    if (ctx->r3 != 0) {
        // 0x8005C24C: nop
    
            goto L_8005C2EC;
    }
    // 0x8005C24C: nop

    // 0x8005C250: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C254: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C258: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005C25C: sb          $a0, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r4;
    // 0x8005C260: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C264: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x8005C268: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005C26C: sw          $a0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r4;
    // 0x8005C270: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005C274: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x8005C278: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C27C: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005C280: bne         $v1, $zero, L_8005C2D4
    if (ctx->r3 != 0) {
        // 0x8005C284: nop
    
            goto L_8005C2D4;
    }
    // 0x8005C284: nop

    // 0x8005C288: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C28C: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C290: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005C294: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8005C298: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C29C: sll         $v1, $a0, 8
    ctx->r3 = S32(ctx->r4 << 8);
    // 0x8005C2A0: sh          $v1, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r3;
    // 0x8005C2A4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2A8: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2AC: lhu         $a0, 0x9A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9A);
    // 0x8005C2B0: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x8005C2B4: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2B8: lw          $a1, 0x34($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X34);
    // 0x8005C2BC: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8005C2C0: sw          $a2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r6;
    // 0x8005C2C4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8005C2C8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C2CC: j           L_8005C2E4
    // 0x8005C2D0: sh          $a0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r4;
        goto L_8005C2E4;
    // 0x8005C2D0: sh          $a0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r4;
L_8005C2D4:
    // 0x8005C2D4: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2D8: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C2DC: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x8005C2E0: sh          $a0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r4;
L_8005C2E4:
    // 0x8005C2E4: j           L_8005C304
    // 0x8005C2E8: nop

        goto L_8005C304;
    // 0x8005C2E8: nop

L_8005C2EC:
    // 0x8005C2EC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2F0: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C2F4: sb          $v1, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r3;
    // 0x8005C2F8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C2FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005C300: sh          $v1, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r3;
L_8005C304:
    // 0x8005C304: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C308: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C30C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005C310: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005C314: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005C318: bne         $v0, $zero, L_8005C328
    if (ctx->r2 != 0) {
        // 0x8005C31C: nop
    
            goto L_8005C328;
    }
    // 0x8005C31C: nop

    // 0x8005C320: j           L_8005C330
    // 0x8005C324: nop

        goto L_8005C330;
    // 0x8005C324: nop

L_8005C328:
    // 0x8005C328: j           L_8005C1E8
    // 0x8005C32C: nop

        goto L_8005C1E8;
    // 0x8005C32C: nop

L_8005C330:
    // 0x8005C330: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C334: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005C338: jr          $ra
    // 0x8005C33C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005C33C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005C340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C340: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005C344: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005C348: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C34C: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
L_8005C350:
    // 0x8005C350: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C354: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C358: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x8005C35C: addiu       $v1, $a0, 0x100
    ctx->r3 = ADD32(ctx->r4, 0X100);
    // 0x8005C360: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x8005C364: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C368: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C36C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C370: lhu         $a0, 0x9C($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9C);
    // 0x8005C374: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8005C378: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C37C: sh          $a0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r4;
    // 0x8005C380: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C384: lhu         $v1, 0x9C($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9C);
    // 0x8005C388: bne         $v1, $zero, L_8005C4E8
    if (ctx->r3 != 0) {
        // 0x8005C38C: nop
    
            goto L_8005C4E8;
    }
    // 0x8005C38C: nop

    // 0x8005C390: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C394: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8005C398: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005C39C: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x8005C3A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005C3A4: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x8005C3A8: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C3AC: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005C3B0: bne         $v1, $zero, L_8005C494
    if (ctx->r3 != 0) {
        // 0x8005C3B4: nop
    
            goto L_8005C494;
    }
    // 0x8005C3B4: nop

    // 0x8005C3B8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C3BC: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C3C0: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005C3C4: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8005C3C8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005C3CC: nop

    // 0x8005C3D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005C3D4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005C3D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C3DC: ldc1        $f4, -0x1280($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1280);
    // 0x8005C3E0: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
    // 0x8005C3E4: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C3E8: swc1        $f2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
    // 0x8005C3EC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C3F0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C3F4: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005C3F8: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8005C3FC: lwc1        $f2, 0x68($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8005C400: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C404: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8005C408: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C40C: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8005C410: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005C414: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x8005C418: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005C41C: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x8005C420: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C424: sltiu       $v1, $v0, 0x80
    ctx->r3 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x8005C428: bne         $v1, $zero, L_8005C47C
    if (ctx->r3 != 0) {
        // 0x8005C42C: nop
    
            goto L_8005C47C;
    }
    // 0x8005C42C: nop

    // 0x8005C430: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C434: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C438: andi        $a0, $v1, 0x7F
    ctx->r4 = ctx->r3 & 0X7F;
    // 0x8005C43C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8005C440: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C444: sll         $v1, $a0, 8
    ctx->r3 = S32(ctx->r4 << 8);
    // 0x8005C448: sh          $v1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r3;
    // 0x8005C44C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C450: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C454: lhu         $a0, 0x9C($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9C);
    // 0x8005C458: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x8005C45C: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005C460: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    // 0x8005C464: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8005C468: sw          $a2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r6;
    // 0x8005C46C: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8005C470: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C474: j           L_8005C48C
    // 0x8005C478: sh          $a0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r4;
        goto L_8005C48C;
    // 0x8005C478: sh          $a0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r4;
L_8005C47C:
    // 0x8005C47C: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C480: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C484: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x8005C488: sh          $a0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r4;
L_8005C48C:
    // 0x8005C48C: j           L_8005C4E8
    // 0x8005C490: nop

        goto L_8005C4E8;
    // 0x8005C490: nop

L_8005C494:
    // 0x8005C494: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C498: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005C49C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005C4A0: nop

    // 0x8005C4A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005C4A8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005C4AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C4B0: ldc1        $f4, -0x1278($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1278);
    // 0x8005C4B4: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
    // 0x8005C4B8: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C4BC: swc1        $f2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
    // 0x8005C4C0: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4C4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4C8: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4CC: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8005C4D0: lwc1        $f2, 0x68($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8005C4D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C4D8: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8005C4DC: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005C4E4: sh          $v1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r3;
L_8005C4E8:
    // 0x8005C4E8: lw          $v0, 0x10($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4EC: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C4F0: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8005C4F4: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8005C4F8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005C4FC: bne         $v0, $zero, L_8005C50C
    if (ctx->r2 != 0) {
        // 0x8005C500: nop
    
            goto L_8005C50C;
    }
    // 0x8005C500: nop

    // 0x8005C504: j           L_8005C514
    // 0x8005C508: nop

        goto L_8005C514;
    // 0x8005C508: nop

L_8005C50C:
    // 0x8005C50C: j           L_8005C350
    // 0x8005C510: nop

        goto L_8005C350;
    // 0x8005C510: nop

L_8005C514:
    // 0x8005C514: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C518: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005C51C: jr          $ra
    // 0x8005C520: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005C520: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005C524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C524: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005C528: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005C52C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C530: swc1        $f12, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f12.u32l;
    // 0x8005C534: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C538: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005C53C: nop

    // 0x8005C540: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8005C544: nop

    // 0x8005C548: bc1f        L_8005C560
    if (!c1cs) {
        // 0x8005C54C: nop
    
            goto L_8005C560;
    }
    // 0x8005C54C: nop

    // 0x8005C550: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C554: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005C558: j           L_8005C764
    // 0x8005C55C: nop

        goto L_8005C764;
    // 0x8005C55C: nop

L_8005C560:
    // 0x8005C560: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C564: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005C568: nop

    // 0x8005C56C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005C570: nop

    // 0x8005C574: bc1f        L_8005C668
    if (!c1cs) {
        // 0x8005C578: nop
    
            goto L_8005C668;
    }
    // 0x8005C578: nop

    // 0x8005C57C: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C580: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C584: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C588: swc1        $f0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f0.u32l;
    // 0x8005C58C: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C590: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C594: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C598: ldc1        $f2, -0x1270($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1270);
    // 0x8005C59C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005C5A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C5A4: ldc1        $f2, -0x1268($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1268);
    // 0x8005C5A8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C5AC: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C5B0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C5B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C5B8: ldc1        $f4, -0x1260($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1260);
    // 0x8005C5BC: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8005C5C0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C5C4: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C5C8: lwc1        $f4, 0x10($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C5CC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C5D0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C5D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C5D8: ldc1        $f6, -0x1258($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1258);
    // 0x8005C5DC: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C5E0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C5E4: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C5E8: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C5EC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C5F0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C5F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C5F8: ldc1        $f6, -0x1250($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1250);
    // 0x8005C5FC: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C600: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C604: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C608: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C60C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C610: lwc1        $f4, 0x10($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C614: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C618: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C61C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C620: ldc1        $f6, -0x1248($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1248);
    // 0x8005C624: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C628: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C62C: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C630: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C634: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C638: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C63C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C640: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C644: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C648: ldc1        $f6, -0x1240($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1240);
    // 0x8005C64C: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C650: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C654: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C658: j           L_8005C764
    // 0x8005C65C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8005C764;
    // 0x8005C65C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8005C660: j           L_8005C764
    // 0x8005C664: nop

        goto L_8005C764;
    // 0x8005C664: nop

L_8005C668:
    // 0x8005C668: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C66C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005C670: swc1        $f2, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->f2.u32l;
    // 0x8005C674: lwc1        $f0, 0x10($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C678: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C67C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C680: swc1        $f0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f0.u32l;
    // 0x8005C684: lwc1        $f2, 0x10($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C688: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C68C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C690: ldc1        $f2, -0x1238($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1238);
    // 0x8005C694: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005C698: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C69C: ldc1        $f2, -0x1230($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1230);
    // 0x8005C6A0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C6A4: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C6A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C6AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C6B0: ldc1        $f4, -0x1228($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1228);
    // 0x8005C6B4: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8005C6B8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C6BC: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C6C0: lwc1        $f4, 0x10($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C6C4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C6C8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C6CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C6D0: ldc1        $f6, -0x1220($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1220);
    // 0x8005C6D4: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C6D8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C6DC: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C6E0: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C6E4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C6E8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C6EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C6F0: ldc1        $f6, -0x1218($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1218);
    // 0x8005C6F4: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C6F8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C6FC: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C700: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C704: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C708: lwc1        $f4, 0x10($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X10);
    // 0x8005C70C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C710: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C714: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C718: ldc1        $f6, -0x1210($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1210);
    // 0x8005C71C: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C720: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C724: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C728: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C72C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C730: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8005C734: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005C738: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C73C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C740: ldc1        $f6, -0x1208($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1208);
    // 0x8005C744: mul.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005C748: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005C74C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C750: ldc1        $f2, -0x1200($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1200);
    // 0x8005C754: div.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f2.d, ctx->f0.d);
    // 0x8005C758: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C75C: j           L_8005C764
    // 0x8005C760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8005C764;
    // 0x8005C760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8005C764:
    // 0x8005C764: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005C768: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005C76C: jr          $ra
    // 0x8005C770: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005C770: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005C774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C774: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005C778: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005C77C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005C780: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005C784: sw          $a0, 0x40($fp)
    MEM_W(0X40, ctx->r30) = ctx->r4;
    // 0x8005C788: sw          $a1, 0x44($fp)
    MEM_W(0X44, ctx->r30) = ctx->r5;
    // 0x8005C78C: lw          $v0, 0x40($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X40);
    // 0x8005C790: sw          $v0, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r2;
    // 0x8005C794: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C798: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005C79C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8005C7A0: and         $v0, $v1, $a0
    ctx->r2 = ctx->r3 & ctx->r4;
    // 0x8005C7A4: beq         $v0, $zero, L_8005C7B4
    if (ctx->r2 == 0) {
        // 0x8005C7A8: nop
    
            goto L_8005C7B4;
    }
    // 0x8005C7A8: nop

    // 0x8005C7AC: j           L_8005CADC
    // 0x8005C7B0: nop

        goto L_8005CADC;
    // 0x8005C7B0: nop

L_8005C7B4:
    // 0x8005C7B4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C7B8: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C7BC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8005C7C0: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x8005C7C4: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8005C7C8: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x8005C7CC: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C7D0: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    // 0x8005C7D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005C7D8: lw          $a1, 0x40($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X40);
    // 0x8005C7DC: jal         0x8005D164
    // 0x8005C7E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8005D164(rdram, ctx);
        goto after_0;
    // 0x8005C7E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8005C7E4: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C7E8: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C7EC: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x8005C7F0: lw          $a1, 0x40($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X40);
    // 0x8005C7F4: jal         0x8005D164
    // 0x8005C7F8: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    func_8005D164(rdram, ctx);
        goto after_1;
    // 0x8005C7F8: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x8005C7FC: sw          $zero, 0x10($fp)
    MEM_W(0X10, ctx->r30) = 0;
L_8005C800:
    // 0x8005C800: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C804: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C808: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x8005C80C: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005C810: bne         $v1, $zero, L_8005C820
    if (ctx->r3 != 0) {
        // 0x8005C814: nop
    
            goto L_8005C820;
    }
    // 0x8005C814: nop

    // 0x8005C818: j           L_8005CAD4
    // 0x8005C81C: nop

        goto L_8005CAD4;
    // 0x8005C81C: nop

L_8005C820:
    // 0x8005C820: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C824: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C828: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C82C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C830: lw          $v0, 0x28($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X28);
    // 0x8005C834: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C838: sw          $v1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r3;
    // 0x8005C83C: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C840: sw          $v0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r2;
    // 0x8005C844: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005C848: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005C84C: sb          $v1, 0x24($fp)
    MEM_B(0X24, ctx->r30) = ctx->r3;
    // 0x8005C850: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C854: andi        $v1, $v0, 0x80
    ctx->r3 = ctx->r2 & 0X80;
    // 0x8005C858: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8005C85C: beq         $v0, $zero, L_8005C87C
    if (ctx->r2 == 0) {
        // 0x8005C860: nop
    
            goto L_8005C87C;
    }
    // 0x8005C860: nop

    // 0x8005C864: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C868: addiu       $v1, $v0, -0x100
    ctx->r3 = ADD32(ctx->r2, -0X100);
    // 0x8005C86C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005C870: nop

    // 0x8005C874: j           L_8005C88C
    // 0x8005C878: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
        goto L_8005C88C;
    // 0x8005C878: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_8005C87C:
    // 0x8005C87C: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C880: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005C884: nop

    // 0x8005C888: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_8005C88C:
    // 0x8005C88C: swc1        $f0, 0x2C($fp)
    MEM_W(0X2C, ctx->r30) = ctx->f0.u32l;
    // 0x8005C890: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C894: lwc1        $f2, 0x2C($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X2C);
    // 0x8005C898: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C89C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C8A0: ldc1        $f2, -0x11F8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11F8);
    // 0x8005C8A4: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005C8A8: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
    // 0x8005C8AC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8005C8B0: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C8B4: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x8005C8B8: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005C8BC: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C8C0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005C8C4: addiu       $v0, $v1, -0x30
    ctx->r2 = ADD32(ctx->r3, -0X30);
    // 0x8005C8C8: sb          $v0, 0x24($fp)
    MEM_B(0X24, ctx->r30) = ctx->r2;
    // 0x8005C8CC: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C8D0: andi        $v1, $v0, 0x80
    ctx->r3 = ctx->r2 & 0X80;
    // 0x8005C8D4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8005C8D8: beq         $v0, $zero, L_8005C8F8
    if (ctx->r2 == 0) {
        // 0x8005C8DC: nop
    
            goto L_8005C8F8;
    }
    // 0x8005C8DC: nop

    // 0x8005C8E0: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C8E4: addiu       $v1, $v0, -0x100
    ctx->r3 = ADD32(ctx->r2, -0X100);
    // 0x8005C8E8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8005C8EC: nop

    // 0x8005C8F0: j           L_8005C908
    // 0x8005C8F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
        goto L_8005C908;
    // 0x8005C8F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_8005C8F8:
    // 0x8005C8F8: lbu         $v0, 0x24($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X24);
    // 0x8005C8FC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005C900: nop

    // 0x8005C904: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_8005C908:
    // 0x8005C908: swc1        $f0, 0x2C($fp)
    MEM_W(0X2C, ctx->r30) = ctx->f0.u32l;
    // 0x8005C90C: lw          $v0, 0x28($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X28);
    // 0x8005C910: lw          $v1, 0x28($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X28);
    // 0x8005C914: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005C918: lwc1        $f2, 0x2C($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X2C);
    // 0x8005C91C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005C920: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8005C924: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C928: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C92C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C930: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C934: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005C938: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C93C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005C940: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x8005C944: bne         $v0, $zero, L_8005CAC0
    if (ctx->r2 != 0) {
        // 0x8005C948: nop
    
            goto L_8005CAC0;
    }
    // 0x8005C948: nop

    // 0x8005C94C: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C950: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C954: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C958: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C95C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005C960: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C964: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005C968: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005C96C: sw          $v0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r2;
    // 0x8005C970: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005C974: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x8005C978: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005C97C: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x8005C980: beq         $v0, $v1, L_8005C9BC
    if (ctx->r2 == ctx->r3) {
        // 0x8005C984: nop
    
            goto L_8005C9BC;
    }
    // 0x8005C984: nop

    // 0x8005C988: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005C98C: lw          $v1, 0x44($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X44);
    // 0x8005C990: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C994: sw          $v0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r2;
    // 0x8005C998: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C99C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C9A0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C9A4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C9A8: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005C9AC: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C9B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005C9B4: lw          $v0, 0x30($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X30);
    // 0x8005C9B8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8005C9BC:
    // 0x8005C9BC: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C9C0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C9C4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C9C8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C9CC: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005C9D0: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C9D4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005C9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C9DC: sb          $v0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r2;
    // 0x8005C9E0: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005C9E4: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005C9E8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005C9EC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005C9F0: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005C9F4: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005C9F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005C9FC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005CA00: beq         $v0, $zero, L_8005CA50
    if (ctx->r2 == 0) {
        // 0x8005CA04: nop
    
            goto L_8005CA50;
    }
    // 0x8005CA04: nop

    // 0x8005CA08: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005CA0C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005CA10: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005CA14: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005CA18: lw          $v0, 0x2C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C);
    // 0x8005CA1C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005CA20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005CA24: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005CA28: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005CA2C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005CA30: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005CA34: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8005CA38: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005CA3C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8005CA40: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8005CA44: lw          $a0, 0x40($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X40);
    // 0x8005CA48: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005CA4C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_8005CA50:
    // 0x8005CA50: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005CA54: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005CA58: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005CA5C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005CA60: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x8005CA64: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005CA68: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005CA6C: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x8005CA70: bne         $v0, $zero, L_8005CAC0
    if (ctx->r2 != 0) {
        // 0x8005CA74: nop
    
            goto L_8005CAC0;
    }
    // 0x8005CA74: nop

    // 0x8005CA78: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005CA7C: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005CA80: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005CA84: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005CA88: lw          $v0, 0x2C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C);
    // 0x8005CA8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005CA90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005CA94: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005CA98: lw          $a0, 0x10($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X10);
    // 0x8005CA9C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005CAA0: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005CAA4: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8005CAA8: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8005CAAC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8005CAB0: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x8005CAB4: lw          $a0, 0x40($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X40);
    // 0x8005CAB8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005CABC: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
L_8005CAC0:
    // 0x8005CAC0: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005CAC4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CAC8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CACC: j           L_8005C800
    // 0x8005CAD0: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
        goto L_8005C800;
    // 0x8005CAD0: sw          $v1, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r3;
L_8005CAD4:
    // 0x8005CAD4: jal         0x80061710
    // 0x8005CAD8: nop

    func_80061710(rdram, ctx);
        goto after_2;
    // 0x8005CAD8: nop

    after_2:
L_8005CADC:
    // 0x8005CADC: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005CAE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005CAE4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8005CAE8: jr          $ra
    // 0x8005CAEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005CAEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005CAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CAF4: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005CAF8: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005CAFC: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005CB00: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
L_8005CB04:
    // 0x8005CB04: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CB08: slti        $v1, $v0, 0x8
    ctx->r3 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8005CB0C: bne         $v1, $zero, L_8005CB1C
    if (ctx->r3 != 0) {
        // 0x8005CB10: nop
    
            goto L_8005CB1C;
    }
    // 0x8005CB10: nop

    // 0x8005CB14: j           L_8005CB94
    // 0x8005CB18: nop

        goto L_8005CB94;
    // 0x8005CB18: nop

L_8005CB1C:
    // 0x8005CB1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CB20: lw          $v0, -0x42C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C8);
    // 0x8005CB24: lui         $v1, 0x4800
    ctx->r3 = S32(0X4800 << 16);
    // 0x8005CB28: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005CB2C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005CB30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CB34: lw          $v0, -0x42C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C8);
    // 0x8005CB38: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8005CB3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005CB40: sw          $v1, -0x42C8($at)
    MEM_W(-0X42C8, ctx->r1) = ctx->r3;
    // 0x8005CB44: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CB48: lui         $v1, 0x4800
    ctx->r3 = S32(0X4800 << 16);
    // 0x8005CB4C: beq         $v0, $v1, L_8005CB6C
    if (ctx->r2 == ctx->r3) {
        // 0x8005CB50: nop
    
            goto L_8005CB6C;
    }
    // 0x8005CB50: nop

    // 0x8005CB54: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CB58: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8005CB5C: beq         $v0, $v1, L_8005CB6C
    if (ctx->r2 == ctx->r3) {
        // 0x8005CB60: nop
    
            goto L_8005CB6C;
    }
    // 0x8005CB60: nop

    // 0x8005CB64: j           L_8005CB80
    // 0x8005CB68: nop

        goto L_8005CB80;
    // 0x8005CB68: nop

L_8005CB6C:
    // 0x8005CB6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CB70: lw          $v0, -0x42C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C8);
    // 0x8005CB74: ori         $v1, $v0, 0x1
    ctx->r3 = ctx->r2 | 0X1;
    // 0x8005CB78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005CB7C: sw          $v1, -0x42C8($at)
    MEM_W(-0X42C8, ctx->r1) = ctx->r3;
L_8005CB80:
    // 0x8005CB80: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005CB84: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CB88: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CB8C: j           L_8005CB04
    // 0x8005CB90: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
        goto L_8005CB04;
    // 0x8005CB90: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
L_8005CB94:
    // 0x8005CB94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005CB98: lwc1        $f0, -0x42C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X42C8);
    // 0x8005CB9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005CBA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8005CBA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005CBA8: nop

    // 0x8005CBAC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CBB0: swc1        $f0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->f0.u32l;
    // 0x8005CBB4: lwc1        $f0, 0x8($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X8);
    // 0x8005CBB8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8005CBBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005CBC0: nop

    // 0x8005CBC4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CBC8: swc1        $f0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->f0.u32l;
    // 0x8005CBCC: lwc1        $f0, 0x18($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X18);
    // 0x8005CBD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005CBD4: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x8005CBD8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CBDC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005CBE0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8005CBE4: nop

    // 0x8005CBE8: j           L_8005CBF0
    // 0x8005CBEC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005CBF0;
    // 0x8005CBEC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005CBF0:
    // 0x8005CBF0: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005CBF4: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005CBF8: jr          $ra
    // 0x8005CBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005CBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005CC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CC04: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005CC08: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005CC0C: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005CC10: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC14: sh          $zero, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = 0;
    // 0x8005CC18: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC1C: sb          $zero, 0xAF($v0)
    MEM_B(0XAF, ctx->r2) = 0;
    // 0x8005CC20: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC24: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8005CC28: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC2C: lbu         $v1, 0xC1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC1);
    // 0x8005CC30: sb          $v1, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r3;
    // 0x8005CC34: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC38: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x8005CC3C: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005CC40:
    // 0x8005CC40: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005CC44: sltiu       $v1, $v0, 0x120
    ctx->r3 = ctx->r2 < 0X120 ? 1 : 0;
    // 0x8005CC48: bne         $v1, $zero, L_8005CC58
    if (ctx->r3 != 0) {
        // 0x8005CC4C: nop
    
            goto L_8005CC58;
    }
    // 0x8005CC4C: nop

    // 0x8005CC50: j           L_8005CC7C
    // 0x8005CC54: nop

        goto L_8005CC7C;
    // 0x8005CC54: nop

L_8005CC58:
    // 0x8005CC58: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CC5C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8005CC60: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005CC64: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8005CC68: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005CC6C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CC70: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CC74: j           L_8005CC40
    // 0x8005CC78: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
        goto L_8005CC40;
    // 0x8005CC78: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005CC7C:
    // 0x8005CC7C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC80: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8005CC84: sh          $v1, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r3;
    // 0x8005CC88: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC8C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005CC90: sb          $v1, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r3;
    // 0x8005CC94: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CC98: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005CC9C: sb          $v1, 0xB6($v0)
    MEM_B(0XB6, ctx->r2) = ctx->r3;
    // 0x8005CCA0: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CCA4: lui         $at, 0x42C7
    ctx->r1 = S32(0X42C7 << 16);
    // 0x8005CCA8: ori         $at, $at, 0xCCCD
    ctx->r1 = ctx->r1 | 0XCCCD;
    // 0x8005CCAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CCB0: nop

    // 0x8005CCB4: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8005CCB8: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CCBC: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005CCC0: addiu       $a0, $zero, 0x6000
    ctx->r4 = ADD32(0, 0X6000);
    // 0x8005CCC4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005CCC8: lw          $a1, -0x42C4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X42C4);
    // 0x8005CCCC: div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // 0x8005CCD0: bne         $a1, $zero, L_8005CCDC
    if (ctx->r5 != 0) {
        // 0x8005CCD4: nop
    
            goto L_8005CCDC;
    }
    // 0x8005CCD4: nop

    // 0x8005CCD8: break       7
    do_break(2147863768);
L_8005CCDC:
    // 0x8005CCDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CCE0: bne         $a1, $at, L_8005CCF4
    if (ctx->r5 != ctx->r1) {
        // 0x8005CCE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005CCF4;
    }
    // 0x8005CCE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005CCE8: bne         $a0, $at, L_8005CCF4
    if (ctx->r4 != ctx->r1) {
        // 0x8005CCEC: nop
    
            goto L_8005CCF4;
    }
    // 0x8005CCEC: nop

    // 0x8005CCF0: break       6
    do_break(2147863792);
L_8005CCF4:
    // 0x8005CCF4: mflo        $a0
    ctx->r4 = lo;
    // 0x8005CCF8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005CCFC: sh          $a1, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r5;
    // 0x8005CD00: sh          $a1, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r5;
    // 0x8005CD04: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CD0C: sh          $v1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r3;
    // 0x8005CD10: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD14: sb          $zero, 0xCA($v0)
    MEM_B(0XCA, ctx->r2) = 0;
    // 0x8005CD18: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD1C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8005CD20: sb          $v1, 0xCB($v0)
    MEM_B(0XCB, ctx->r2) = ctx->r3;
    // 0x8005CD24: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD28: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8005CD2C: sb          $v1, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r3;
    // 0x8005CD30: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD34: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x8005CD38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CD3C: nop

    // 0x8005CD40: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x8005CD44: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD48: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x8005CD4C: sb          $v1, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = ctx->r3;
    // 0x8005CD50: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CD58: sh          $v1, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r3;
    // 0x8005CD5C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD60: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CD64: sh          $v1, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r3;
    // 0x8005CD68: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD6C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005CD70: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8005CD74: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD78: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8005CD7C: sh          $v1, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r3;
    // 0x8005CD80: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD84: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8005CD88: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
    // 0x8005CD8C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD90: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8005CD94: sh          $v1, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r3;
    // 0x8005CD98: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CD9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CDA0: sb          $v1, 0xB7($v0)
    MEM_B(0XB7, ctx->r2) = ctx->r3;
    // 0x8005CDA4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CDAC: sb          $v1, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r3;
    // 0x8005CDB0: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CDB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CDBC: nop

    // 0x8005CDC0: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x8005CDC4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDC8: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8005CDCC: sb          $v1, 0xB9($v0)
    MEM_B(0XB9, ctx->r2) = ctx->r3;
    // 0x8005CDD0: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDD4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8005CDD8: sb          $v1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r3;
    // 0x8005CDDC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDE0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8005CDE4: ori         $at, $at, 0x8081
    ctx->r1 = ctx->r1 | 0X8081;
    // 0x8005CDE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CDEC: nop

    // 0x8005CDF0: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8005CDF4: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CDF8: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8005CDFC: sb          $v1, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = ctx->r3;
    // 0x8005CE00: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CE04: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x8005CE08: sb          $v1, 0xC0($v0)
    MEM_B(0XC0, ctx->r2) = ctx->r3;
    // 0x8005CE0C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CE10: lui         $at, 0x3D88
    ctx->r1 = S32(0X3D88 << 16);
    // 0x8005CE14: ori         $at, $at, 0x8889
    ctx->r1 = ctx->r1 | 0X8889;
    // 0x8005CE18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CE1C: nop

    // 0x8005CE20: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8005CE24: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CE28: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005CE2C: lw          $v1, -0x3828($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3828);
    // 0x8005CE30: sw          $v1, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r3;
    // 0x8005CE34: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CE38: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x8005CE3C: sb          $v1, 0xC1($v0)
    MEM_B(0XC1, ctx->r2) = ctx->r3;
    // 0x8005CE40: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005CE44: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005CE48: jr          $ra
    // 0x8005CE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005CE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005CE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CE54: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005CE58: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005CE5C: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005CE60: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005CE64: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005CE68: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CE6C: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005CE70: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_8005CE74:
    // 0x8005CE74: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CE78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005CE7C: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005CE80: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CE84: bne         $v0, $zero, L_8005CE94
    if (ctx->r2 != 0) {
        // 0x8005CE88: nop
    
            goto L_8005CE94;
    }
    // 0x8005CE88: nop

    // 0x8005CE8C: j           L_8005CED0
    // 0x8005CE90: nop

        goto L_8005CED0;
    // 0x8005CE90: nop

L_8005CE94:
    // 0x8005CE94: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CE98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005CE9C: bne         $v1, $zero, L_8005CEAC
    if (ctx->r3 != 0) {
        // 0x8005CEA0: nop
    
            goto L_8005CEAC;
    }
    // 0x8005CEA0: nop

    // 0x8005CEA4: j           L_8005D0E4
    // 0x8005CEA8: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
        goto L_8005D0E4;
    // 0x8005CEA8: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
L_8005CEAC:
    // 0x8005CEAC: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005CEB0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CEB4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CEB8: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005CEBC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005CEC0: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005CEC4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CEC8: j           L_8005CE74
    // 0x8005CECC: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005CE74;
    // 0x8005CECC: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005CED0:
    // 0x8005CED0: nop

    // 0x8005CED4: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005CED8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CEDC: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005CEE0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005CEE4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x8005CEE8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8005CEEC: sw          $v0, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r2;
    // 0x8005CEF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CEF4: sw          $v0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r2;
L_8005CEF8:
    // 0x8005CEF8: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CEFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005CF00: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005CF04: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CF08: bne         $v0, $zero, L_8005CF18
    if (ctx->r2 != 0) {
        // 0x8005CF0C: nop
    
            goto L_8005CF18;
    }
    // 0x8005CF0C: nop

    // 0x8005CF10: j           L_8005CF78
    // 0x8005CF14: nop

        goto L_8005CF78;
    // 0x8005CF14: nop

L_8005CF18:
    // 0x8005CF18: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CF1C: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005CF20: beq         $v1, $zero, L_8005CF54
    if (ctx->r3 == 0) {
        // 0x8005CF24: nop
    
            goto L_8005CF54;
    }
    // 0x8005CF24: nop

    // 0x8005CF28: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CF2C: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8005CF30: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005CF34: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CF38: bne         $v1, $zero, L_8005CF54
    if (ctx->r3 != 0) {
        // 0x8005CF3C: nop
    
            goto L_8005CF54;
    }
    // 0x8005CF3C: nop

    // 0x8005CF40: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CF44: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8005CF48: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
    // 0x8005CF4C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CF50: sw          $v0, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r2;
L_8005CF54:
    // 0x8005CF54: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005CF58: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CF5C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CF60: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005CF64: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005CF68: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005CF6C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CF70: j           L_8005CEF8
    // 0x8005CF74: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005CEF8;
    // 0x8005CF74: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005CF78:
    // 0x8005CF78: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x8005CF7C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005CF80: beq         $v0, $v1, L_8005CF90
    if (ctx->r2 == ctx->r3) {
        // 0x8005CF84: nop
    
            goto L_8005CF90;
    }
    // 0x8005CF84: nop

    // 0x8005CF88: j           L_8005D0E4
    // 0x8005CF8C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
        goto L_8005D0E4;
    // 0x8005CF8C: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
L_8005CF90:
    // 0x8005CF90: nop

    // 0x8005CF94: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005CF98: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005CF9C: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005CFA0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_8005CFA4:
    // 0x8005CFA4: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005CFA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005CFAC: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005CFB0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CFB4: bne         $v0, $zero, L_8005CFC4
    if (ctx->r2 != 0) {
        // 0x8005CFB8: nop
    
            goto L_8005CFC4;
    }
    // 0x8005CFB8: nop

    // 0x8005CFBC: j           L_8005D004
    // 0x8005CFC0: nop

        goto L_8005D004;
    // 0x8005CFC0: nop

L_8005CFC4:
    // 0x8005CFC4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CFC8: lhu         $v1, 0x9E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X9E);
    // 0x8005CFCC: bne         $v1, $zero, L_8005CFF0
    if (ctx->r3 != 0) {
        // 0x8005CFD0: nop
    
            goto L_8005CFF0;
    }
    // 0x8005CFD0: nop

    // 0x8005CFD4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005CFD8: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x8005CFDC: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005CFE0: beq         $v1, $v0, L_8005CFF0
    if (ctx->r3 == ctx->r2) {
        // 0x8005CFE4: nop
    
            goto L_8005CFF0;
    }
    // 0x8005CFE4: nop

    // 0x8005CFE8: j           L_8005D0E4
    // 0x8005CFEC: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
        goto L_8005D0E4;
    // 0x8005CFEC: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
L_8005CFF0:
    // 0x8005CFF0: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005CFF4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CFF8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005CFFC: j           L_8005CFA4
    // 0x8005D000: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
        goto L_8005CFA4;
    // 0x8005D000: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
L_8005D004:
    // 0x8005D004: nop

    // 0x8005D008: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
    // 0x8005D00C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005D010: lw          $v0, -0x42C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X42C0);
    // 0x8005D014: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_8005D018:
    // 0x8005D018: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8005D01C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8005D020: lw          $v1, 0x7664($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7664);
    // 0x8005D024: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005D028: bne         $v0, $zero, L_8005D038
    if (ctx->r2 != 0) {
        // 0x8005D02C: nop
    
            goto L_8005D038;
    }
    // 0x8005D02C: nop

    // 0x8005D030: j           L_8005D0A4
    // 0x8005D034: nop

        goto L_8005D0A4;
    // 0x8005D034: nop

L_8005D038:
    // 0x8005D038: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8005D03C: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x8005D040: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005D044: bne         $v1, $v0, L_8005D080
    if (ctx->r3 != ctx->r2) {
        // 0x8005D048: nop
    
            goto L_8005D080;
    }
    // 0x8005D048: nop

    // 0x8005D04C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005D050: lw          $v1, 0x1C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X1C);
    // 0x8005D054: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005D058: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005D05C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8005D060: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8005D064: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005D068: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005D06C: lw          $v1, 0x78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78);
    // 0x8005D070: bne         $v0, $v1, L_8005D080
    if (ctx->r2 != ctx->r3) {
        // 0x8005D074: nop
    
            goto L_8005D080;
    }
    // 0x8005D074: nop

    // 0x8005D078: j           L_8005D0E4
    // 0x8005D07C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
        goto L_8005D0E4;
    // 0x8005D07C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
L_8005D080:
    // 0x8005D080: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005D084: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005D088: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D08C: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
    // 0x8005D090: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005D094: addiu       $v0, $v1, 0x120
    ctx->r2 = ADD32(ctx->r3, 0X120);
    // 0x8005D098: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D09C: j           L_8005D018
    // 0x8005D0A0: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
        goto L_8005D018;
    // 0x8005D0A0: sw          $v1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r3;
L_8005D0A4:
    // 0x8005D0A4: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005D0A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D0AC: lw          $a0, 0x7664($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7664);
    // 0x8005D0B0: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8005D0B4: bne         $a0, $zero, L_8005D0C0
    if (ctx->r4 != 0) {
        // 0x8005D0B8: nop
    
            goto L_8005D0C0;
    }
    // 0x8005D0B8: nop

    // 0x8005D0BC: break       7
    do_break(2147864764);
L_8005D0C0:
    // 0x8005D0C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005D0C4: bne         $a0, $at, L_8005D0D8
    if (ctx->r4 != ctx->r1) {
        // 0x8005D0C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005D0D8;
    }
    // 0x8005D0C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005D0CC: bne         $v0, $at, L_8005D0D8
    if (ctx->r2 != ctx->r1) {
        // 0x8005D0D0: nop
    
            goto L_8005D0D8;
    }
    // 0x8005D0D0: nop

    // 0x8005D0D4: break       6
    do_break(2147864788);
L_8005D0D8:
    // 0x8005D0D8: mfhi        $v1
    ctx->r3 = hi;
    // 0x8005D0DC: j           L_8005D0E4
    // 0x8005D0E0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005D0E4;
    // 0x8005D0E0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8005D0E4:
    // 0x8005D0E4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005D0E8: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005D0EC: jr          $ra
    // 0x8005D0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D0F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005D0F8: sw          $fp, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r30;
    // 0x8005D0FC: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005D100: sw          $a0, 0x10($fp)
    MEM_W(0X10, ctx->r30) = ctx->r4;
    // 0x8005D104: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8005D108: sw          $a2, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r6;
    // 0x8005D10C: sb          $v0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r2;
    // 0x8005D110: lw          $v1, 0x10($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X10);
    // 0x8005D114: sw          $v1, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r3;
L_8005D118:
    // 0x8005D118: lw          $v1, 0x18($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X18);
    // 0x8005D11C: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x8005D120: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8005D124: sw          $v1, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r3;
    // 0x8005D128: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D12C: bne         $v1, $a0, L_8005D13C
    if (ctx->r3 != ctx->r4) {
        // 0x8005D130: nop
    
            goto L_8005D13C;
    }
    // 0x8005D130: nop

    // 0x8005D134: j           L_8005D154
    // 0x8005D138: nop

        goto L_8005D154;
    // 0x8005D138: nop

L_8005D13C:
    // 0x8005D13C: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005D140: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005D144: sw          $a0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r4;
    // 0x8005D148: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8005D14C: j           L_8005D118
    // 0x8005D150: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
        goto L_8005D118;
    // 0x8005D150: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_8005D154:
    // 0x8005D154: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005D158: lw          $fp, 0x8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X8);
    // 0x8005D15C: jr          $ra
    // 0x8005D160: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8005D160: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8005D164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D168: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8005D16C: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005D170: sw          $a0, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r4;
    // 0x8005D174: sw          $a1, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r5;
    // 0x8005D178: sw          $a2, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r6;
    // 0x8005D17C: lw          $v0, 0x18($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18);
    // 0x8005D180: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8005D184: lw          $v0, 0x1C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1C);
    // 0x8005D188: sw          $v0, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r2;
    // 0x8005D18C: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
L_8005D190:
    // 0x8005D190: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005D194: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005D198: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005D19C: bne         $v0, $zero, L_8005D1AC
    if (ctx->r2 != 0) {
        // 0x8005D1A0: nop
    
            goto L_8005D1AC;
    }
    // 0x8005D1A0: nop

    // 0x8005D1A4: j           L_8005D218
    // 0x8005D1A8: nop

        goto L_8005D218;
    // 0x8005D1A8: nop

L_8005D1AC:
    // 0x8005D1AC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005D1B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D1B4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D1B8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005D1BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005D1C0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005D1C4: beq         $v1, $zero, L_8005D204
    if (ctx->r3 == 0) {
        // 0x8005D1C8: nop
    
            goto L_8005D204;
    }
    // 0x8005D1C8: nop

    // 0x8005D1CC: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8005D1D0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D1D4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005D1D8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x8005D1DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005D1E0: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005D1E4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005D1E8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8005D1EC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x8005D1F0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005D1F4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8005D1F8: lw          $v1, 0x4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X4);
    // 0x8005D1FC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005D200: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8005D204:
    // 0x8005D204: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8005D208: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005D20C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D210: j           L_8005D190
    // 0x8005D214: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
        goto L_8005D190;
    // 0x8005D214: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
L_8005D218:
    // 0x8005D218: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005D21C: lw          $fp, 0x10($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X10);
    // 0x8005D220: jr          $ra
    // 0x8005D224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D228: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D22C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D230: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8005D234: addu        $fp, $sp, $zero
    ctx->r30 = ADD32(ctx->r29, 0);
    // 0x8005D238: sw          $a0, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r4;
    // 0x8005D23C: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    // 0x8005D240: sw          $a2, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r6;
    // 0x8005D244: sw          $a3, 0x2C($fp)
    MEM_W(0X2C, ctx->r30) = ctx->r7;
    // 0x8005D248: jal         0x8005CC00
    // 0x8005D24C: lw          $a0, 0x20($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X20);
    func_8005CC00(rdram, ctx);
        goto after_0;
    // 0x8005D24C: lw          $a0, 0x20($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X20);
    after_0:
    // 0x8005D250: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D254: lhu         $v1, 0x26($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X26);
    // 0x8005D258: sh          $v1, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r3;
    // 0x8005D25C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D260: lhu         $v1, 0x2A($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X2A);
    // 0x8005D264: sh          $v1, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r3;
    // 0x8005D268: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D26C: lhu         $v1, 0x2E($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X2E);
    // 0x8005D270: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
    // 0x8005D274: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D278: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005D27C: lw          $v1, -0x2AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AF0);
    // 0x8005D280: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8005D284: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D288: sw          $a0, -0x2AF0($at)
    MEM_W(-0X2AF0, ctx->r1) = ctx->r4;
    // 0x8005D28C: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8005D290: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D294: lw          $v1, 0x30($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X30);
    // 0x8005D298: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8005D29C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x8005D2A0: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005D2A4: lw          $a0, 0x24($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X24);
    // 0x8005D2A8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005D2AC: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005D2B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005D2B4: lw          $a1, -0x43AC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43AC);
    // 0x8005D2B8: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8005D2BC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005D2C0: sw          $a1, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r5;
    // 0x8005D2C4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8005D2C8: lw          $v1, 0x20($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X20);
    // 0x8005D2CC: j           L_8005D2D4
    // 0x8005D2D0: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
        goto L_8005D2D4;
    // 0x8005D2D0: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
L_8005D2D4:
    // 0x8005D2D4: addu        $sp, $fp, $zero
    ctx->r29 = ADD32(ctx->r30, 0);
    // 0x8005D2D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2DC: lw          $fp, 0x18($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X18);
    // 0x8005D2E0: jr          $ra
    // 0x8005D2E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D2E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D2F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005D2F4: lw          $v0, 0x60B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B0);
    // 0x8005D2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D2FC: bne         $v0, $zero, L_8005D328
    if (ctx->r2 != 0) {
        // 0x8005D300: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005D328;
    }
    // 0x8005D300: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D304: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005D308: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005D30C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D310: bne         $v0, $zero, L_8005D328
    if (ctx->r2 != 0) {
        // 0x8005D314: sw          $a0, 0x60B0($at)
        MEM_W(0X60B0, ctx->r1) = ctx->r4;
            goto L_8005D328;
    }
    // 0x8005D314: sw          $a0, 0x60B0($at)
    MEM_W(0X60B0, ctx->r1) = ctx->r4;
    // 0x8005D318: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D31C: sw          $a0, 0x60B4($at)
    MEM_W(0X60B4, ctx->r1) = ctx->r4;
    // 0x8005D320: jal         0x8005D9E0
    // 0x8005D324: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8005D9E0(rdram, ctx);
        goto after_0;
    // 0x8005D324: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_8005D328:
    // 0x8005D328: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D32C: jr          $ra
    // 0x8005D330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D334: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005D338: lw          $v0, 0x60B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B0);
    // 0x8005D33C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D340: beq         $v0, $zero, L_8005D360
    if (ctx->r2 == 0) {
        // 0x8005D344: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005D360;
    }
    // 0x8005D344: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005D348: jal         0x8005D5E0
    // 0x8005D34C: nop

    func_8005D5E0(rdram, ctx);
        goto after_0;
    // 0x8005D34C: nop

    after_0:
    // 0x8005D350: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D354: sw          $zero, 0x60B0($at)
    MEM_W(0X60B0, ctx->r1) = 0;
    // 0x8005D358: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D35C: sw          $zero, 0x60B4($at)
    MEM_W(0X60B4, ctx->r1) = 0;
L_8005D360:
    // 0x8005D360: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005D364: jr          $ra
    // 0x8005D368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D374: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D378: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D380: jal         0x80061620
    // 0x8005D384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8005D384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8005D388: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005D38C: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005D390: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x8005D394: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8005D398: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x8005D39C: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
    // 0x8005D3A0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8005D3A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005D3A8: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x8005D3AC: jal         0x80061620
    // 0x8005D3B0: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8005D3B0: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    after_1:
    // 0x8005D3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D3B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D3BC: jr          $ra
    // 0x8005D3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D3D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D3D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D3D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D3DC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005D3E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D3E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005D3E8: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x8005D3EC: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x8005D3F0: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8005D3F4: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x8005D3F8: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8005D3FC: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x8005D400: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8005D404: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x8005D408: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x8005D40C: jal         0x8005D518
    // 0x8005D410: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8005D518(rdram, ctx);
        goto after_0;
    // 0x8005D410: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8005D414: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8005D418: beq         $a0, $zero, L_8005D500
    if (ctx->r4 == 0) {
        // 0x8005D41C: nop
    
            goto L_8005D500;
    }
    // 0x8005D41C: nop

    // 0x8005D420: beq         $v0, $zero, L_8005D4F4
    if (ctx->r2 == 0) {
        // 0x8005D424: addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
            goto L_8005D4F4;
    }
    // 0x8005D424: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8005D428: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8005D42C: sw          $v0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r2;
    // 0x8005D430: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8005D434: sw          $s0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r16;
    // 0x8005D438: jal         0x8005DE40
    // 0x8005D43C: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    func_8005DE40(rdram, ctx);
        goto after_1;
    // 0x8005D43C: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_1:
    // 0x8005D440: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005D444: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005D448: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    // 0x8005D44C: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    // 0x8005D450: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8005D454: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D458: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005D45C: sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // 0x8005D460: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x8005D464: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8005D468: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8005D46C: lw          $v0, 0x88($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X88);
    // 0x8005D470: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x8005D474: sw          $v0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r2;
    // 0x8005D478: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D47C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x8005D480: jal         0x8005EBA0
    // 0x8005D484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8005EBA0(rdram, ctx);
        goto after_2;
    // 0x8005D484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8005D488: jal         0x8005DE40
    // 0x8005D48C: nop

    func_8005DE40(rdram, ctx);
        goto after_3;
    // 0x8005D48C: nop

    after_3:
    // 0x8005D490: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D494: beq         $t0, $zero, L_8005D500
    if (ctx->r8 == 0) {
        // 0x8005D498: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D500;
    }
    // 0x8005D498: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D49C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8005D4A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D4A4: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D4A8: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D4AC: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D4B0: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D4B4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8005D4B8: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D4BC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D4C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D4C4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D4C8: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D4CC: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D4D0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D4D4: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D4D8: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D4DC: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D4E0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D4E4: jal         0x8005EBA0
    // 0x8005D4E8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_4;
    // 0x8005D4E8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_4:
    // 0x8005D4EC: j           L_8005D500
    // 0x8005D4F0: nop

        goto L_8005D500;
    // 0x8005D4F0: nop

L_8005D4F4:
    // 0x8005D4F4: sw          $zero, 0x88($a0)
    MEM_W(0X88, ctx->r4) = 0;
    // 0x8005D4F8: sw          $s0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r16;
    // 0x8005D4FC: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
L_8005D500:
    // 0x8005D500: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8005D504: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005D508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D50C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D510: jr          $ra
    // 0x8005D514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D518: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005D51C: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005D520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D524: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005D528: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005D52C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D530: lw          $s0, 0x14($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X14);
    // 0x8005D534: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005D538: bne         $s0, $zero, L_8005D54C
    if (ctx->r16 != 0) {
        // 0x8005D53C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005D54C;
    }
    // 0x8005D53C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005D540: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    // 0x8005D544: beq         $s0, $zero, L_8005D574
    if (ctx->r16 == 0) {
        // 0x8005D548: nop
    
            goto L_8005D574;
    }
    // 0x8005D548: nop

L_8005D54C:
    // 0x8005D54C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005D550: jal         0x8006553C
    // 0x8005D554: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x8005D554: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    after_0:
    // 0x8005D558: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8005D55C: lw          $a1, 0x60B4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60B4);
    // 0x8005D560: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005D564: jal         0x8006551C
    // 0x8005D568: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x8005D568: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x8005D56C: j           L_8005D5C4
    // 0x8005D570: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
        goto L_8005D5C4;
    // 0x8005D570: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8005D574:
    // 0x8005D574: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x8005D578: beq         $s0, $zero, L_8005D5C4
    if (ctx->r16 == 0) {
        // 0x8005D57C: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_8005D5C4;
    }
    // 0x8005D57C: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8005D580:
    // 0x8005D580: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D584: lh          $v1, 0x16($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X16);
    // 0x8005D588: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8005D58C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005D590: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005D594: bne         $v0, $zero, L_8005D5B8
    if (ctx->r2 != 0) {
        // 0x8005D598: nop
    
            goto L_8005D5B8;
    }
    // 0x8005D598: nop

    // 0x8005D59C: lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X88);
    // 0x8005D5A0: bne         $v0, $zero, L_8005D5B8
    if (ctx->r2 != 0) {
        // 0x8005D5A4: nop
    
            goto L_8005D5B8;
    }
    // 0x8005D5A4: nop

    // 0x8005D5A8: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8005D5AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D5B0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005D5B4: lhu         $a1, 0x16($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X16);
L_8005D5B8:
    // 0x8005D5B8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8005D5BC: bne         $s0, $zero, L_8005D580
    if (ctx->r16 != 0) {
        // 0x8005D5C0: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_8005D580;
    }
    // 0x8005D5C0: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8005D5C4:
    // 0x8005D5C4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005D5C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005D5CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D5D0: jr          $ra
    // 0x8005D5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D5E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005D5E4: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005D5E8: jr          $ra
    // 0x8005D5EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x8005D5EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8005D5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D5F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D5F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D5F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D5FC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005D600: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005D604: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D608: beq         $v0, $zero, L_8005D67C
    if (ctx->r2 == 0) {
        // 0x8005D60C: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_8005D67C;
    }
    // 0x8005D60C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005D610: jal         0x8005DE40
    // 0x8005D614: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D614: nop

    after_0:
    // 0x8005D618: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D61C: beq         $t0, $zero, L_8005D67C
    if (ctx->r8 == 0) {
        // 0x8005D620: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D67C;
    }
    // 0x8005D620: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D624: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D628: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D62C: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D630: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D634: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D638: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D63C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8005D640: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D644: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8005D648: sw          $a0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r4;
    // 0x8005D64C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D650: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D654: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D658: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D65C: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D660: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D664: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D668: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D66C: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D670: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D674: jal         0x8005EBA0
    // 0x8005D678: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_1;
    // 0x8005D678: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_1:
L_8005D67C:
    // 0x8005D67C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005D680: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005D684: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D688: jr          $ra
    // 0x8005D68C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D68C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D694: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D698: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D69C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005D6A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005D6A4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D6A8: beq         $v0, $zero, L_8005D71C
    if (ctx->r2 == 0) {
        // 0x8005D6AC: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_8005D71C;
    }
    // 0x8005D6AC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005D6B0: jal         0x8005DE40
    // 0x8005D6B4: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D6B4: nop

    after_0:
    // 0x8005D6B8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D6BC: beq         $t0, $zero, L_8005D71C
    if (ctx->r8 == 0) {
        // 0x8005D6C0: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D71C;
    }
    // 0x8005D6C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D6C4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D6C8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D6CC: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D6D0: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D6D4: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D6D8: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D6DC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8005D6E0: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D6E4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8005D6E8: sw          $a0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r4;
    // 0x8005D6EC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D6F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D6F4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D6F8: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D6FC: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D700: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D704: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D708: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D70C: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D710: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D714: jal         0x8005EBA0
    // 0x8005D718: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_1;
    // 0x8005D718: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_1:
L_8005D71C:
    // 0x8005D71C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005D720: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005D724: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D728: jr          $ra
    // 0x8005D72C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D72C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D734: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D738: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D740: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8005D744: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D748: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8005D74C: beq         $v0, $zero, L_8005D7BC
    if (ctx->r2 == 0) {
        // 0x8005D750: nop
    
            goto L_8005D7BC;
    }
    // 0x8005D750: nop

    // 0x8005D754: jal         0x8005DE40
    // 0x8005D758: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D758: nop

    after_0:
    // 0x8005D75C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D760: beq         $t0, $zero, L_8005D7BC
    if (ctx->r8 == 0) {
        // 0x8005D764: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D7BC;
    }
    // 0x8005D764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D768: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D76C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D770: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D774: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D778: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D77C: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D780: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8005D784: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D788: swc1        $f20, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f20.u32l;
    // 0x8005D78C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D790: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D794: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D798: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D79C: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D7A0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D7A4: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D7A8: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D7AC: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D7B0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D7B4: jal         0x8005EBA0
    // 0x8005D7B8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_1;
    // 0x8005D7B8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_1:
L_8005D7BC:
    // 0x8005D7BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D7C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D7C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8005D7C8: jr          $ra
    // 0x8005D7CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D7CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D7D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D7D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005D7D8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005D7DC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8005D7E0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005D7E4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005D7E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D7EC: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8005D7F0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8005D7F4: beq         $v0, $zero, L_8005D87C
    if (ctx->r2 == 0) {
        // 0x8005D7F8: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8005D87C;
    }
    // 0x8005D7F8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005D7FC: jal         0x8005DE40
    // 0x8005D800: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D800: nop

    after_0:
    // 0x8005D804: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D808: beq         $s0, $zero, L_8005D87C
    if (ctx->r16 == 0) {
        // 0x8005D80C: nop
    
            goto L_8005D87C;
    }
    // 0x8005D80C: nop

    // 0x8005D810: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8005D814: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005D818: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005D81C: lw          $a1, 0x88($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X88);
    // 0x8005D820: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    // 0x8005D824: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x8005D828: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005D82C: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x8005D830: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x8005D834: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005D838: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8005D83C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005D840: sra         $a2, $a1, 31
    ctx->r6 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8005D844: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x8005D848: sltu        $v0, $t1, $a3
    ctx->r2 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8005D84C: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8005D850: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8005D854: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x8005D858: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x8005D85C: jal         0x8005DF6C
    // 0x8005D860: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8005DF6C(rdram, ctx);
        goto after_1;
    // 0x8005D860: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8005D864: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8005D868: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8005D86C: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8005D870: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D874: jal         0x8005EBA0
    // 0x8005D878: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8005EBA0(rdram, ctx);
        goto after_2;
    // 0x8005D878: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
L_8005D87C:
    // 0x8005D87C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8005D880: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D884: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005D888: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005D88C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D890: jr          $ra
    // 0x8005D894: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D894: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005D8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D8A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D8A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D8A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D8AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005D8B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005D8B4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D8B8: beq         $v0, $zero, L_8005D930
    if (ctx->r2 == 0) {
        // 0x8005D8BC: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_8005D930;
    }
    // 0x8005D8BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005D8C0: jal         0x8005DE40
    // 0x8005D8C4: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D8C4: nop

    after_0:
    // 0x8005D8C8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D8CC: beq         $t0, $zero, L_8005D930
    if (ctx->r8 == 0) {
        // 0x8005D8D0: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D930;
    }
    // 0x8005D8D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D8D4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D8D8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D8DC: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D8E0: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D8E4: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D8E8: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D8EC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8005D8F0: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D8F4: sw          $s1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r17;
    // 0x8005D8F8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D8FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D900: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D904: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D908: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D90C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D910: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D914: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D918: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D91C: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x8005D920: sh          $v0, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r2;
    // 0x8005D924: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D928: jal         0x8005EBA0
    // 0x8005D92C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_1;
    // 0x8005D92C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_1:
L_8005D930:
    // 0x8005D930: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005D934: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005D938: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D93C: jr          $ra
    // 0x8005D940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005D950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D954: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005D958: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005D95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D960: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D964: beq         $v0, $zero, L_8005D9D0
    if (ctx->r2 == 0) {
        // 0x8005D968: nop
    
            goto L_8005D9D0;
    }
    // 0x8005D968: nop

    // 0x8005D96C: jal         0x8005DE40
    // 0x8005D970: nop

    func_8005DE40(rdram, ctx);
        goto after_0;
    // 0x8005D970: nop

    after_0:
    // 0x8005D974: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005D978: beq         $t0, $zero, L_8005D9D0
    if (ctx->r8 == 0) {
        // 0x8005D97C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8005D9D0;
    }
    // 0x8005D97C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005D980: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005D984: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D988: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005D98C: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8005D990: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8005D994: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8005D998: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8005D99C: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8005D9A0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D9A4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D9A8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005D9AC: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8005D9B0: sltu        $a0, $a3, $v1
    ctx->r4 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x8005D9B4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005D9B8: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005D9BC: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
    // 0x8005D9C0: sw          $a3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r7;
    // 0x8005D9C4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005D9C8: jal         0x8005EBA0
    // 0x8005D9CC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_8005EBA0(rdram, ctx);
        goto after_1;
    // 0x8005D9CC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_1:
L_8005D9D0:
    // 0x8005D9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D9D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005D9D8: jr          $ra
    // 0x8005D9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005D9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D9E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D9E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005D9E4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005D9E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005D9EC: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8005D9F0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005D9F4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005D9F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005D9FC: lw          $s3, 0x14($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X14);
    // 0x8005DA00: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DA04: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DA08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DA0C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005DA10: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8005DA14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DA18: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8005DA1C: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8005DA20: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8005DA24: sw          $t3, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r11;
    // 0x8005DA28: sw          $t2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r10;
    // 0x8005DA2C: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x8005DA30: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8005DA34: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8005DA38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005DA3C: addiu       $v0, $zero, 0xB8
    ctx->r2 = ADD32(0, 0XB8);
    // 0x8005DA40: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8005DA44: sw          $a2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r6;
    // 0x8005DA48: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x8005DA4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005DA50: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005DA54: sw          $v0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r2;
    // 0x8005DA58: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
    // 0x8005DA5C: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x8005DA60: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x8005DA64: jal         0x800655B0
    // 0x8005DA68: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x8005DA68: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005DA6C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DA70: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DA74: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x8005DA78: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8005DA7C: lw          $v1, 0x40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40);
    // 0x8005DA80: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8005DA84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DA88: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8005DA8C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005DA90: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005DA94: lw          $a3, 0x4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4);
    // 0x8005DA98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DA9C: jal         0x800655B0
    // 0x8005DAA0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x8005DAA0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_1:
    // 0x8005DAA4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DAA8: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DAAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DAB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DAB4: lw          $v1, 0x40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40);
    // 0x8005DAB8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005DABC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005DAC0: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8005DAC4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8005DAC8: jal         0x800655B0
    // 0x8005DACC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x8005DACC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005DAD0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DAD4: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DAD8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005DADC: sw          $a0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r4;
    // 0x8005DAE0: lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1C);
    // 0x8005DAE4: beq         $v0, $zero, L_8005DB1C
    if (ctx->r2 == 0) {
        // 0x8005DAE8: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8005DB1C;
    }
    // 0x8005DAE8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005DAEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DAF0: jal         0x80060330
    // 0x8005DAF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80060330(rdram, ctx);
        goto after_3;
    // 0x8005DAF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8005DAF8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005DAFC: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005DB00: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x8005DB04: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8005DB08: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x8005DB0C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8005DB10: addiu       $v0, $v0, -0x710
    ctx->r2 = ADD32(ctx->r2, -0X710);
    // 0x8005DB14: j           L_8005DB28
    // 0x8005DB18: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_8005DB28;
    // 0x8005DB18: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005DB1C:
    // 0x8005DB1C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8005DB20: addiu       $v0, $v0, -0x2040
    ctx->r2 = ADD32(ctx->r2, -0X2040);
    // 0x8005DB24: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8005DB28:
    // 0x8005DB28: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DB2C: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DB30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DB34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005DB38: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8005DB3C: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8005DB40: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8005DB44: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8005DB48: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8005DB4C: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x8005DB50: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005DB54: lw          $a3, 0x4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4);
    // 0x8005DB58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DB5C: jal         0x800655B0
    // 0x8005DB60: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800655B0(rdram, ctx);
        goto after_4;
    // 0x8005DB60: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_4:
    // 0x8005DB64: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x8005DB68: blez        $v1, L_8005DBE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005DB6C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8005DBE0;
    }
    // 0x8005DB6C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005DB70: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8005DB74:
    // 0x8005DB74: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8005DB78: lw          $a1, 0x60B4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60B4);
    // 0x8005DB7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005DB80: jal         0x8006551C
    // 0x8005DB84: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8006551C(rdram, ctx);
        goto after_5;
    // 0x8005DB84: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x8005DB88: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DB8C: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DB90: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8005DB94: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x8005DB98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005DB9C: jal         0x8005E45C
    // 0x8005DBA0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_8005E45C(rdram, ctx);
        goto after_6;
    // 0x8005DBA0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_6:
    // 0x8005DBA4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DBA8: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DBAC: lw          $a0, 0x40($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X40);
    // 0x8005DBB0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x8005DBB4: lw          $a1, 0x1C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1C);
    // 0x8005DBB8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005DBBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005DBC0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005DBC4: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8005DBC8: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x8005DBCC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8005DBD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005DBD4: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005DBD8: bne         $v0, $zero, L_8005DB74
    if (ctx->r2 != 0) {
        // 0x8005DBDC: addiu       $s1, $s1, 0x8C
        ctx->r17 = ADD32(ctx->r17, 0X8C);
            goto L_8005DB74;
    }
    // 0x8005DBDC: addiu       $s1, $s1, 0x8C
    ctx->r17 = ADD32(ctx->r17, 0X8C);
L_8005DBE0:
    // 0x8005DBE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DBE4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8005DBE8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005DBEC: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    // 0x8005DBF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DBF4: jal         0x800655B0
    // 0x8005DBF8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800655B0(rdram, ctx);
        goto after_7;
    // 0x8005DBF8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_7:
    // 0x8005DBFC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005DC00: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005DC04: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8005DC08: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8005DC0C: blez        $v1, L_8005DC38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005DC10: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8005DC38;
    }
    // 0x8005DC10: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005DC14: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8005DC18:
    // 0x8005DC18: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8005DC1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005DC20: sw          $v1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r3;
    // 0x8005DC24: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x8005DC28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005DC2C: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005DC30: bne         $v0, $zero, L_8005DC18
    if (ctx->r2 != 0) {
        // 0x8005DC34: addiu       $v1, $v1, 0x28
        ctx->r3 = ADD32(ctx->r3, 0X28);
            goto L_8005DC18;
    }
    // 0x8005DC34: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
L_8005DC38:
    // 0x8005DC38: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DC3C: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DC40: sw          $s3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r19;
    // 0x8005DC44: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8005DC48: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005DC4C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005DC50: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DC54: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005DC58: jr          $ra
    // 0x8005DC5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005DC5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005DC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DC60: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DC64: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DC68: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005DC6C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8005DC70: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005DC74: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8005DC78: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x8005DC7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005DC80: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8005DC84: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005DC88: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8005DC8C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8005DC90: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005DC94: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005DC98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DC9C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005DCA0: addu        $s2, $s6, $zero
    ctx->r18 = ADD32(ctx->r22, 0);
    // 0x8005DCA4: bne         $a0, $zero, L_8005DCB4
    if (ctx->r4 != 0) {
        // 0x8005DCA8: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_8005DCB4;
    }
    // 0x8005DCA8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8005DCAC: j           L_8005DE10
    // 0x8005DCB0: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
        goto L_8005DE10;
    // 0x8005DCB0: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
L_8005DCB4:
    // 0x8005DCB4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8005DCB8: addiu       $s5, $zero, -0x10
    ctx->r21 = ADD32(0, -0X10);
    // 0x8005DCBC: j           L_8005DD20
    // 0x8005DCC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_8005DD20;
    // 0x8005DCC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_8005DCC4:
    // 0x8005DCC4: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8005DCC8: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8005DCCC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005DCD0: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005DCD4: and         $v0, $v0, $s4
    ctx->r2 = ctx->r2 & ctx->r20;
    // 0x8005DCD8: and         $v1, $v1, $s5
    ctx->r3 = ctx->r3 & ctx->r21;
    // 0x8005DCDC: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x8005DCE0: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x8005DCE4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005DCE8: jalr        $v0
    // 0x8005DCEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005DCEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005DCF0: jal         0x8005DF1C
    // 0x8005DCF4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8005DF1C(rdram, ctx);
        goto after_1;
    // 0x8005DCF4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8005DCF8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8005DCFC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8005DD00: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8005DD04: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005DD08: addu        $a3, $a3, $a1
    ctx->r7 = ADD32(ctx->r7, ctx->r5);
    // 0x8005DD0C: sltu        $v0, $a3, $a1
    ctx->r2 = ctx->r7 < ctx->r5 ? 1 : 0;
    // 0x8005DD10: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x8005DD14: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005DD18: sw          $a2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r6;
    // 0x8005DD1C: sw          $a3, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r7;
L_8005DD20:
    // 0x8005DD20: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8005DD24: lw          $a3, 0x60B4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X60B4);
    // 0x8005DD28: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x8005DD2C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8005DD30: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8005DD34: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8005DD38: sra         $t0, $s1, 31
    ctx->r8 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8005DD3C: sltu        $a2, $a1, $v1
    ctx->r6 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8005DD40: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8005DD44: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8005DD48: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x8005DD4C: slt         $v0, $a0, $t0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005DD50: bne         $v0, $zero, L_8005DCC4
    if (ctx->r2 != 0) {
        // 0x8005DD54: addu        $t1, $s1, $zero
        ctx->r9 = ADD32(ctx->r17, 0);
            goto L_8005DCC4;
    }
    // 0x8005DD54: addu        $t1, $s1, $zero
    ctx->r9 = ADD32(ctx->r17, 0);
    // 0x8005DD58: bne         $t0, $a0, L_8005DD68
    if (ctx->r8 != ctx->r4) {
        // 0x8005DD5C: sltu        $v0, $a1, $t1
        ctx->r2 = ctx->r5 < ctx->r9 ? 1 : 0;
            goto L_8005DD68;
    }
    // 0x8005DD5C: sltu        $v0, $a1, $t1
    ctx->r2 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x8005DD60: bne         $v0, $zero, L_8005DCC4
    if (ctx->r2 != 0) {
        // 0x8005DD64: nop
    
            goto L_8005DCC4;
    }
    // 0x8005DD64: nop

L_8005DD68:
    // 0x8005DD68: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8005DD6C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x8005DD70: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005DD74: addiu       $a1, $zero, -0x10
    ctx->r5 = ADD32(0, -0X10);
    // 0x8005DD78: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x8005DD7C: and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // 0x8005DD80: sw          $v0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r2;
    // 0x8005DD84: sw          $v1, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r3;
    // 0x8005DD88: blez        $s1, L_8005DE04
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8005DD8C: subu        $v0, $s2, $s6
        ctx->r2 = SUB32(ctx->r18, ctx->r22);
            goto L_8005DE04;
    }
    // 0x8005DD8C: subu        $v0, $s2, $s6
    ctx->r2 = SUB32(ctx->r18, ctx->r22);
L_8005DD90:
    // 0x8005DD90: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DD94: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DD98: lw          $s0, 0x50($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X50);
    // 0x8005DD9C: slt         $v0, $s1, $s0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8005DDA0: bnel        $v0, $zero, L_8005DDA8
    if (ctx->r2 != 0) {
        // 0x8005DDA4: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_8005DDA8;
    }
    goto skip_0;
    // 0x8005DDA4: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    skip_0:
L_8005DDA8:
    // 0x8005DDA8: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x8005DDAC: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8005DDB0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8005DDB4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005DDB8: jal         0x800602E0
    // 0x8005DDBC: sw          $s3, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r19;
    func_800602E0(rdram, ctx);
        goto after_2;
    // 0x8005DDBC: sw          $s3, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r19;
    after_2:
    // 0x8005DDC0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005DDC4: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005DDC8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8005DDCC: lw          $a3, 0x60B4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X60B4);
    // 0x8005DDD0: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x8005DDD4: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x8005DDD8: lw          $a1, 0x2C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X2C);
    // 0x8005DDDC: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8005DDE0: sra         $v0, $s0, 31
    ctx->r2 = S32(SIGNED(ctx->r16) >> 31);
    // 0x8005DDE4: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8005DDE8: sltu        $a2, $a1, $v1
    ctx->r6 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8005DDEC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005DDF0: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8005DDF4: sw          $a0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r4;
    // 0x8005DDF8: sw          $a1, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r5;
    // 0x8005DDFC: bgtz        $s1, L_8005DD90
    if (SIGNED(ctx->r17) > 0) {
        // 0x8005DE00: subu        $v0, $s2, $s6
        ctx->r2 = SUB32(ctx->r18, ctx->r22);
            goto L_8005DD90;
    }
    // 0x8005DE00: subu        $v0, $s2, $s6
    ctx->r2 = SUB32(ctx->r18, ctx->r22);
L_8005DE04:
    // 0x8005DE04: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8005DE08: jal         0x8005DE84
    // 0x8005DE0C: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    func_8005DE84(rdram, ctx);
        goto after_3;
    // 0x8005DE0C: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    after_3:
L_8005DE10:
    // 0x8005DE10: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8005DE14: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005DE18: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8005DE1C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8005DE20: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8005DE24: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005DE28: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DE2C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005DE30: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005DE34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DE38: jr          $ra
    // 0x8005DE3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005DE3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005DE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DE40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005DE44: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x8005DE48: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8005DE4C: beq         $v0, $zero, L_8005DE64
    if (ctx->r2 == 0) {
        // 0x8005DE50: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8005DE64;
    }
    // 0x8005DE50: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8005DE54: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005DE58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005DE5C: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
    // 0x8005DE60: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8005DE64:
    // 0x8005DE64: jr          $ra
    // 0x8005DE68: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8005DE68: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8005DE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DE6C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005DE70: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8005DE74: lw          $v0, 0x38($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38);
    // 0x8005DE78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005DE7C: jr          $ra
    // 0x8005DE80: sw          $a0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r4;
    return;
    // 0x8005DE80: sw          $a0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_8005DE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DE84: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DE88: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DE8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DE90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DE94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DE98: lw          $s0, 0x14($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X14);
    // 0x8005DE9C: beq         $s0, $zero, L_8005DED4
    if (ctx->r16 == 0) {
        // 0x8005DEA0: nop
    
            goto L_8005DED4;
    }
    // 0x8005DEA0: nop

L_8005DEA4:
    // 0x8005DEA4: jal         0x8006553C
    // 0x8005DEA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x8005DEA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005DEAC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8005DEB0: lw          $a1, 0x60B4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60B4);
    // 0x8005DEB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005DEB8: jal         0x8006551C
    // 0x8005DEBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x8005DEBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x8005DEC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DEC4: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DEC8: lw          $s0, 0x14($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X14);
    // 0x8005DECC: bne         $s0, $zero, L_8005DEA4
    if (ctx->r16 != 0) {
        // 0x8005DED0: nop
    
            goto L_8005DEA4;
    }
    // 0x8005DED0: nop

L_8005DED4:
    // 0x8005DED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DED8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DEDC: jr          $ra
    // 0x8005DEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005DEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
