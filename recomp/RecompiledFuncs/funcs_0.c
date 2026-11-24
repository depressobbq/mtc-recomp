#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80000404: addiu       $t0, $t0, -0xA00
    ctx->r8 = ADD32(ctx->r8, -0XA00);
    // 0x80000408: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x8000040C: addiu       $t1, $t1, -0x7910
    ctx->r9 = ADD32(ctx->r9, -0X7910);
L_80000410:
    // 0x80000410: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000414: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80000418: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8000041C: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000420: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000424: nop
    
            goto L_80000410;
    }
    // 0x80000424: nop

    // 0x80000428: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x17F0
    ctx->r10 = ADD32(ctx->r10, 0X17F0);
    // 0x80000430: lui         $sp, 0x800D
    ctx->r29 = S32(0X800D << 16);
    // 0x80000434: jr          $t2
    // 0x80000438: addiu       $sp, $sp, 0x2720
    ctx->r29 = ADD32(ctx->r29, 0X2720);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000438: addiu       $sp, $sp, 0x2720
    ctx->r29 = ADD32(ctx->r29, 0X2720);
;}
RECOMP_FUNC void func_80000450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80000454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000458: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000045C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000460: addiu       $s2, $s0, 0x74
    ctx->r18 = ADD32(ctx->r16, 0X74);
    // 0x80000464: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80000468: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000046C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80000470: addiu       $a1, $s0, 0x8C
    ctx->r5 = ADD32(ctx->r16, 0X8C);
    // 0x80000474: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80000478: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8000047C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80000480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000484: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80000488: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000048C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000490: sw          $v0, 0x678($s0)
    MEM_W(0X678, ctx->r16) = ctx->r2;
    // 0x80000494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000498: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8000049C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800004A0: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    // 0x800004A4: sw          $zero, 0x670($s0)
    MEM_W(0X670, ctx->r16) = 0;
    // 0x800004A8: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
    // 0x800004AC: sw          $zero, 0x668($s0)
    MEM_W(0X668, ctx->r16) = 0;
    // 0x800004B0: jal         0x80061740
    // 0x800004B4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800004B4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_0:
    // 0x800004B8: addiu       $s4, $s0, 0xAC
    ctx->r20 = ADD32(ctx->r16, 0XAC);
    // 0x800004BC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800004C0: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x800004C4: jal         0x80061740
    // 0x800004C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800004C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800004CC: addiu       $s3, $s0, 0xE4
    ctx->r19 = ADD32(ctx->r16, 0XE4);
    // 0x800004D0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800004D4: addiu       $a1, $s0, 0xFC
    ctx->r5 = ADD32(ctx->r16, 0XFC);
    // 0x800004D8: jal         0x80061740
    // 0x800004DC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800004DC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800004E0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x800004E4: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x800004E8: jal         0x80061740
    // 0x800004EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800004EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800004F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x800004F4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x800004F8: jal         0x80061740
    // 0x800004FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800004FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80000500: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x80000504: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x80000508: jal         0x80061740
    // 0x8000050C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x8000050C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80000510: jal         0x80066430
    // 0x80000514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_6;
    // 0x80000514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80000518: jal         0x80067880
    // 0x8000051C: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_7;
    // 0x8000051C: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_7:
    // 0x80000520: jal         0x80066430
    // 0x80000524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x80000524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80000528: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8000052C: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x80000530: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80000534: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80000538: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8000053C: addiu       $v0, $v0, 0x6EC0
    ctx->r2 = ADD32(ctx->r2, 0X6EC0);
    // 0x80000540: jal         0x800661D0
    // 0x80000544: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    osViSetMode_recomp(rdram, ctx);
        goto after_9;
    // 0x80000544: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_9:
    // 0x80000548: jal         0x80066430
    // 0x8000054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_10;
    // 0x8000054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80000550: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80000554: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x80000558: jal         0x80066170
    // 0x8000055C: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    osViSetEvent_recomp(rdram, ctx);
        goto after_11;
    // 0x8000055C: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    after_11:
    // 0x80000560: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000564: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80000568: jal         0x80061C00
    // 0x8000056C: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x8000056C: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_12:
    // 0x80000570: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80000574: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80000578: jal         0x80061C00
    // 0x8000057C: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_13;
    // 0x8000057C: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_13:
    // 0x80000580: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80000584: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80000588: jal         0x80061C00
    // 0x8000058C: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x8000058C: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_14:
    // 0x80000590: addiu       $s1, $s0, 0x158
    ctx->r17 = ADD32(ctx->r16, 0X158);
    // 0x80000594: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80000598: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8000059C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800005A0: addiu       $a2, $a2, 0x66C
    ctx->r6 = ADD32(ctx->r6, 0X66C);
    // 0x800005A4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800005A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800005AC: addiu       $v0, $v0, 0x5030
    ctx->r2 = ADD32(ctx->r2, 0X5030);
    // 0x800005B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800005B4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800005B8: jal         0x80061770
    // 0x800005BC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_15;
    // 0x800005BC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_15:
    // 0x800005C0: jal         0x80061C60
    // 0x800005C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_16;
    // 0x800005C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_16:
    // 0x800005C8: addiu       $s1, $s0, 0x308
    ctx->r17 = ADD32(ctx->r16, 0X308);
    // 0x800005CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800005D0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800005D4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800005D8: addiu       $a2, $a2, 0x83C
    ctx->r6 = ADD32(ctx->r6, 0X83C);
    // 0x800005DC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800005E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800005E4: addiu       $v0, $v0, 0x72A0
    ctx->r2 = ADD32(ctx->r2, 0X72A0);
    // 0x800005E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800005EC: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x800005F0: jal         0x80061770
    // 0x800005F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_17;
    // 0x800005F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_17:
    // 0x800005F8: jal         0x80061C60
    // 0x800005FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_18;
    // 0x800005FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_18:
    // 0x80000600: addiu       $s1, $s0, 0x4B8
    ctx->r17 = ADD32(ctx->r16, 0X4B8);
    // 0x80000604: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80000608: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8000060C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000610: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, 0X978);
    // 0x80000614: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80000618: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000061C: addiu       $v0, $v0, -0x8F0
    ctx->r2 = ADD32(ctx->r2, -0X8F0);
    // 0x80000620: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000624: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80000628: jal         0x80061770
    // 0x8000062C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_19;
    // 0x8000062C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_19:
    // 0x80000630: jal         0x80061C60
    // 0x80000634: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_20;
    // 0x80000634: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_20:
    // 0x80000638: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8000063C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000640: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000644: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000648: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000064C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000650: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000654: jr          $ra
    // 0x80000658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80000658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000065C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000065C: jr          $ra
    // 0x80000660: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    return;
    // 0x80000660: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
;}
RECOMP_FUNC void func_80000664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000664: jr          $ra
    // 0x80000668: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
    return;
    // 0x80000668: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
;}
RECOMP_FUNC void func_8000066C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000066C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000670: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000674: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80000678: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000067C: addiu       $s2, $zero, 0x29A
    ctx->r18 = ADD32(0, 0X29A);
    // 0x80000680: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000684: addiu       $s1, $zero, 0x29D
    ctx->r17 = ADD32(0, 0X29D);
    // 0x80000688: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000068C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80000690: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
L_80000694:
    // 0x80000694: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80000698: jal         0x800619A0
    // 0x8000069C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000069C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800006A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800006A4: lw          $v0, -0x6AB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AB0);
    // 0x800006A8: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800006AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800006B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800006B4: sw          $v0, -0x6AB0($at)
    MEM_W(-0X6AB0, ctx->r1) = ctx->r2;
    // 0x800006B8: beq         $v1, $s2, L_800006D0
    if (ctx->r3 == ctx->r18) {
        // 0x800006BC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800006D0;
    }
    // 0x800006BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800006C0: beq         $v1, $s1, L_800006E0
    if (ctx->r3 == ctx->r17) {
        // 0x800006C4: nop
    
            goto L_800006E0;
    }
    // 0x800006C4: nop

    // 0x800006C8: j           L_80000694
    // 0x800006CC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
        goto L_80000694;
    // 0x800006CC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
L_800006D0:
    // 0x800006D0: jal         0x800007F0
    // 0x800006D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800007F0(rdram, ctx);
        goto after_1;
    // 0x800006D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800006D8: j           L_80000694
    // 0x800006DC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
        goto L_80000694;
    // 0x800006DC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
L_800006E0:
    // 0x800006E0: jal         0x800007F0
    // 0x800006E4: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    func_800007F0(rdram, ctx);
        goto after_2;
    // 0x800006E4: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    after_2:
    // 0x800006E8: j           L_80000694
    // 0x800006EC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
        goto L_80000694;
    // 0x800006EC: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x800006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800006F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800006F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800006FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000700: jr          $ra
    // 0x80000704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80000704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80000708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000070C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80000710: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80000714: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000718: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8000071C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000720: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80000724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000728: jal         0x80061620
    // 0x8000072C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000072C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80000730: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80000734: lw          $v1, 0x668($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X668);
    // 0x80000738: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000073C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80000740: jal         0x80061620
    // 0x80000744: sw          $s0, 0x668($s2)
    MEM_W(0X668, ctx->r18) = ctx->r16;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80000744: sw          $s0, 0x668($s2)
    MEM_W(0X668, ctx->r18) = ctx->r16;
    after_1:
    // 0x80000748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000074C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80000750: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000754: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000758: jr          $ra
    // 0x8000075C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000075C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80000760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000764: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80000768: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000076C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80000770: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80000774: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80000778: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000077C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000780: lw          $s0, 0x668($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X668);
    // 0x80000784: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80000788: jal         0x80061620
    // 0x8000078C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000078C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80000790: beq         $s0, $zero, L_800007CC
    if (ctx->r16 == 0) {
        // 0x80000794: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800007CC;
    }
    // 0x80000794: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80000798:
    // 0x80000798: bnel        $s0, $s3, L_800007C0
    if (ctx->r16 != ctx->r19) {
        // 0x8000079C: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_800007C0;
    }
    goto skip_0;
    // 0x8000079C: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800007A0: beq         $s1, $zero, L_800007B4
    if (ctx->r17 == 0) {
        // 0x800007A4: nop
    
            goto L_800007B4;
    }
    // 0x800007A4: nop

    // 0x800007A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800007AC: j           L_800007CC
    // 0x800007B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_800007CC;
    // 0x800007B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800007B4:
    // 0x800007B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800007B8: j           L_800007CC
    // 0x800007BC: sw          $v0, 0x668($s2)
    MEM_W(0X668, ctx->r18) = ctx->r2;
        goto L_800007CC;
    // 0x800007BC: sw          $v0, 0x668($s2)
    MEM_W(0X668, ctx->r18) = ctx->r2;
L_800007C0:
    // 0x800007C0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800007C4: bne         $s0, $zero, L_80000798
    if (ctx->r16 != 0) {
        // 0x800007C8: nop
    
            goto L_80000798;
    }
    // 0x800007C8: nop

L_800007CC:
    // 0x800007CC: jal         0x80061620
    // 0x800007D0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800007D0: nop

    after_1:
    // 0x800007D4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800007D8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800007DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800007E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800007E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800007E8: jr          $ra
    // 0x800007EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800007EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800007F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800007F4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800007F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800007FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000800: lw          $s0, 0x668($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X668);
    // 0x80000804: beq         $s0, $zero, L_80000828
    if (ctx->r16 == 0) {
        // 0x80000808: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80000828;
    }
    // 0x80000808: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
L_8000080C:
    // 0x8000080C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80000810: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80000814: jal         0x80061AD0
    // 0x80000818: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80000818: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8000081C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80000820: bne         $s0, $zero, L_8000080C
    if (ctx->r16 != 0) {
        // 0x80000824: nop
    
            goto L_8000080C;
    }
    // 0x80000824: nop

L_80000828:
    // 0x80000828: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000082C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000830: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000834: jr          $ra
    // 0x80000838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80000838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000083C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000083C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000840: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000844: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80000848: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000084C: addiu       $s4, $s1, 0xAC
    ctx->r20 = ADD32(ctx->r17, 0XAC);
    // 0x80000850: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000854: addiu       $s3, $sp, 0x14
    ctx->r19 = ADD32(ctx->r29, 0X14);
    // 0x80000858: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000085C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80000868: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000086C: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
L_80000870:
    // 0x80000870: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80000874: jal         0x800619A0
    // 0x80000878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80000878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000087C: jal         0x80061710
    // 0x80000880: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_80061710(rdram, ctx);
        goto after_1;
    // 0x80000880: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_1:
    // 0x80000884: lw          $s2, 0x66C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X66C);
    // 0x80000888: beq         $s2, $zero, L_800008B8
    if (ctx->r18 == 0) {
        // 0x8000088C: nop
    
            goto L_800008B8;
    }
    // 0x8000088C: nop

    // 0x80000890: jal         0x80066080
    // 0x80000894: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    osSpTaskYield_recomp(rdram, ctx);
        goto after_2;
    // 0x80000894: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    after_2:
    // 0x80000898: addiu       $a0, $s1, 0xAC
    ctx->r4 = ADD32(ctx->r17, 0XAC);
    // 0x8000089C: addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    // 0x800008A0: jal         0x800619A0
    // 0x800008A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800008A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800008A8: jal         0x800660A0
    // 0x800008AC: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_4;
    // 0x800008AC: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    after_4:
    // 0x800008B0: bnel        $v0, $zero, L_800008B8
    if (ctx->r2 != 0) {
        // 0x800008B4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800008B8;
    }
    goto skip_0;
    // 0x800008B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_0:
L_800008B8:
    // 0x800008B8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800008BC: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800008C0: jal         0x80065E40
    // 0x800008C4: sw          $v0, 0x670($s1)
    MEM_W(0X670, ctx->r17) = ctx->r2;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_5;
    // 0x800008C4: sw          $v0, 0x670($s1)
    MEM_W(0X670, ctx->r17) = ctx->r2;
    after_5:
    // 0x800008C8: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800008CC: jal         0x8006604C
    // 0x800008D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_6;
    // 0x800008D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x800008D4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800008D8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800008DC: jal         0x800619A0
    // 0x800008E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800008E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800008E4: lw          $v0, 0x674($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X674);
    // 0x800008E8: beq         $v0, $zero, L_80000900
    if (ctx->r2 == 0) {
        // 0x800008EC: sw          $zero, 0x670($s1)
        MEM_W(0X670, ctx->r17) = 0;
            goto L_80000900;
    }
    // 0x800008EC: sw          $zero, 0x670($s1)
    MEM_W(0X670, ctx->r17) = 0;
    // 0x800008F0: addiu       $a0, $s1, 0x11C
    ctx->r4 = ADD32(ctx->r17, 0X11C);
    // 0x800008F4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800008F8: jal         0x80061AD0
    // 0x800008FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800008FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_80000900:
    // 0x80000900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000904: bne         $s0, $v0, L_80000928
    if (ctx->r16 != ctx->r2) {
        // 0x80000908: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80000928;
    }
    // 0x80000908: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000090C: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x80000910: jal         0x80065E40
    // 0x80000914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_9;
    // 0x80000914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80000918: jal         0x8006604C
    // 0x8000091C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_10;
    // 0x8000091C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x80000920: j           L_8000093C
    // 0x80000924: nop

        goto L_8000093C;
    // 0x80000924: nop

L_80000928:
    // 0x80000928: bne         $s0, $v0, L_8000093C
    if (ctx->r16 != ctx->r2) {
        // 0x8000092C: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8000093C;
    }
    // 0x8000092C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80000930: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80000934: jal         0x80061AD0
    // 0x80000938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80000938: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_8000093C:
    // 0x8000093C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80000940: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80000944: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    // 0x80000948: jal         0x80061AD0
    // 0x8000094C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x8000094C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80000950: j           L_80000870
    // 0x80000954: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
        goto L_80000870;
    // 0x80000954: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x80000958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000095C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000960: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000964: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000968: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000096C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000970: jr          $ra
    // 0x80000974: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80000974: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80000978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000978: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000097C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000980: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80000984: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000988: addiu       $s1, $sp, 0x14
    ctx->r17 = ADD32(ctx->r29, 0X14);
    // 0x8000098C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80000990: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80000994: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
L_80000998:
    // 0x80000998: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8000099C: jal         0x800619A0
    // 0x800009A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800009A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800009A4: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800009A8: jal         0x80000A78
    // 0x800009AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80000A78(rdram, ctx);
        goto after_1;
    // 0x800009AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800009B0: lw          $v0, 0x670($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X670);
    // 0x800009B4: beq         $v0, $zero, L_800009D4
    if (ctx->r2 == 0) {
        // 0x800009B8: addiu       $a1, $sp, 0x14
        ctx->r5 = ADD32(ctx->r29, 0X14);
            goto L_800009D4;
    }
    // 0x800009B8: addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    // 0x800009BC: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x800009C0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800009C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800009C8: jal         0x800619A0
    // 0x800009CC: sw          $v0, 0x674($s0)
    MEM_W(0X674, ctx->r16) = ctx->r2;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800009CC: sw          $v0, 0x674($s0)
    MEM_W(0X674, ctx->r16) = ctx->r2;
    after_2:
    // 0x800009D0: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
L_800009D4:
    // 0x800009D4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800009D8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800009DC: jal         0x80065E40
    // 0x800009E0: sw          $v0, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = ctx->r2;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_3;
    // 0x800009E0: sw          $v0, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = ctx->r2;
    after_3:
    // 0x800009E4: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800009E8: jal         0x8006604C
    // 0x800009EC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_4;
    // 0x800009EC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x800009F0: addiu       $a0, $s0, 0xAC
    ctx->r4 = ADD32(ctx->r16, 0XAC);
    // 0x800009F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800009F8: jal         0x800619A0
    // 0x800009FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800009FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80000A00: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80000A04: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80000A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80000A0C: jal         0x800619A0
    // 0x80000A10: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80000A10: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    after_6:
    // 0x80000A14: lw          $v0, 0x678($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X678);
    // 0x80000A18: beq         $v0, $zero, L_80000A2C
    if (ctx->r2 == 0) {
        // 0x80000A1C: nop
    
            goto L_80000A2C;
    }
    // 0x80000A1C: nop

    // 0x80000A20: jal         0x80066430
    // 0x80000A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    osViBlack_recomp(rdram, ctx);
        goto after_7;
    // 0x80000A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x80000A28: sw          $zero, 0x678($s0)
    MEM_W(0X678, ctx->r16) = 0;
L_80000A2C:
    // 0x80000A2C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80000A30: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80000A34: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80000A38: beq         $v0, $zero, L_80000A48
    if (ctx->r2 == 0) {
        // 0x80000A3C: nop
    
            goto L_80000A48;
    }
    // 0x80000A3C: nop

    // 0x80000A40: jal         0x800663E0
    // 0x80000A44: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_8;
    // 0x80000A44: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    after_8:
L_80000A48:
    // 0x80000A48: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80000A4C: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80000A50: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    // 0x80000A54: jal         0x80061AD0
    // 0x80000A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80000A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80000A5C: j           L_80000998
    // 0x80000A60: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
        goto L_80000998;
    // 0x80000A60: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80000A64: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80000A68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000A6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000A70: jr          $ra
    // 0x80000A74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80000A74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80000A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A78: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80000A7C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80000A80: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80000A84: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80000A88: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80000A8C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80000A90: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80000A94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80000A98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80000A9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000AA0: lw          $s6, 0xC($a1)
    ctx->r22 = MEM_W(ctx->r5, 0XC);
    // 0x80000AA4: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x80000AA8: addiu       $s4, $s3, 0x11C
    ctx->r20 = ADD32(ctx->r19, 0X11C);
    // 0x80000AAC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80000AB0:
    // 0x80000AB0: jal         0x800660F0
    // 0x80000AB4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80000AB4: nop

    after_0:
    // 0x80000AB8: beq         $v0, $s6, L_80000AD0
    if (ctx->r2 == ctx->r22) {
        // 0x80000ABC: nop
    
            goto L_80000AD0;
    }
    // 0x80000ABC: nop

    // 0x80000AC0: jal         0x80066130
    // 0x80000AC4: nop

    func_80066130(rdram, ctx);
        goto after_1;
    // 0x80000AC4: nop

    after_1:
    // 0x80000AC8: bne         $v0, $s6, L_80000B60
    if (ctx->r2 != ctx->r22) {
        // 0x80000ACC: nop
    
            goto L_80000B60;
    }
    // 0x80000ACC: nop

L_80000AD0:
    // 0x80000AD0: jal         0x80061620
    // 0x80000AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80000AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80000AD8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80000ADC: lw          $v1, 0x668($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X668);
    // 0x80000AE0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80000AE4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80000AE8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80000AEC: jal         0x80061620
    // 0x80000AF0: sw          $s5, 0x668($s3)
    MEM_W(0X668, ctx->r19) = ctx->r21;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80000AF0: sw          $s5, 0x668($s3)
    MEM_W(0X668, ctx->r19) = ctx->r21;
    after_3:
    // 0x80000AF4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80000AF8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80000AFC: jal         0x800619A0
    // 0x80000B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80000B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80000B04: lw          $s0, 0x668($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X668);
    // 0x80000B08: jal         0x80061620
    // 0x80000B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_5;
    // 0x80000B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80000B10: addu        $s2, $s5, $zero
    ctx->r18 = ADD32(ctx->r21, 0);
    // 0x80000B14: beq         $s0, $zero, L_80000B44
    if (ctx->r16 == 0) {
        // 0x80000B18: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80000B44;
    }
    // 0x80000B18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80000B1C:
    // 0x80000B1C: bnel        $s0, $s2, L_80000B38
    if (ctx->r16 != ctx->r18) {
        // 0x80000B20: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_80000B38;
    }
    goto skip_0;
    // 0x80000B20: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80000B24: bne         $s1, $zero, L_80000B54
    if (ctx->r17 != 0) {
        // 0x80000B28: nop
    
            goto L_80000B54;
    }
    // 0x80000B28: nop

    // 0x80000B2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80000B30: j           L_80000B44
    // 0x80000B34: sw          $v0, 0x668($s3)
    MEM_W(0X668, ctx->r19) = ctx->r2;
        goto L_80000B44;
    // 0x80000B34: sw          $v0, 0x668($s3)
    MEM_W(0X668, ctx->r19) = ctx->r2;
L_80000B38:
    // 0x80000B38: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80000B3C: bne         $s0, $zero, L_80000B1C
    if (ctx->r16 != 0) {
        // 0x80000B40: nop
    
            goto L_80000B1C;
    }
    // 0x80000B40: nop

L_80000B44:
    // 0x80000B44: jal         0x80061620
    // 0x80000B48: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x80000B48: nop

    after_6:
    // 0x80000B4C: j           L_80000AB0
    // 0x80000B50: nop

        goto L_80000AB0;
    // 0x80000B50: nop

L_80000B54:
    // 0x80000B54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80000B58: j           L_80000B44
    // 0x80000B5C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80000B44;
    // 0x80000B5C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80000B60:
    // 0x80000B60: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80000B64: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80000B68: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80000B6C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80000B70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80000B74: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80000B78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80000B7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80000B80: jr          $ra
    // 0x80000B84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80000B84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80000B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000B94: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80000B98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000B9C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80000BA0: addiu       $s0, $s0, -0xA00
    ctx->r16 = ADD32(ctx->r16, -0XA00);
    // 0x80000BA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000BA8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80000BAC: addiu       $v0, $v0, 0x17B0
    ctx->r2 = ADD32(ctx->r2, 0X17B0);
    // 0x80000BB0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000BB4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80000BB8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80000BBC: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000BC0: addiu       $a2, $a2, 0xBE8
    ctx->r6 = ADD32(ctx->r6, 0XBE8);
    // 0x80000BC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000BC8: jal         0x80061770
    // 0x80000BCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80000BCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80000BD0: jal         0x80061C60
    // 0x80000BD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80000BD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80000BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80000BDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000BE0: jr          $ra
    // 0x80000BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80000BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80000BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BE8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80000BEC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80000BF0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80000BF4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80000BF8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80000BFC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80000C00: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80000C04: jal         0x80061740
    // 0x80000C08: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80000C08: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    after_0:
    // 0x80000C0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000C10: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80000C14: jal         0x80000708
    // 0x80000C18: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80000708(rdram, ctx);
        goto after_1;
    // 0x80000C18: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80000C1C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80000C20:
    // 0x80000C20: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80000C24: jal         0x800619A0
    // 0x80000C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80000C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000C2C: j           L_80000C20
    // 0x80000C30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80000C20;
    // 0x80000C30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80000C34: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80000C38: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80000C3C: jr          $ra
    // 0x80000C40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80000C40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80000C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000C54: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80000C58: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x80000C5C: addiu       $s3, $s3, 0x2087
    ctx->r19 = ADD32(ctx->r19, 0X2087);
    // 0x80000C60: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80000C64: addiu       $v0, $v0, -0x3390
    ctx->r2 = ADD32(ctx->r2, -0X3390);
    // 0x80000C68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000C6C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80000C70: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80000C74: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80000C78: addiu       $s2, $s2, -0x6AA0
    ctx->r18 = ADD32(ctx->r18, -0X6AA0);
    // 0x80000C7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000C80: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80000C84: addiu       $s1, $s1, -0x6A9C
    ctx->r17 = ADD32(ctx->r17, -0X6A9C);
    // 0x80000C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000C8C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80000C90: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80000C94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000C98: sb          $zero, -0x338F($at)
    MEM_B(-0X338F, ctx->r1) = 0;
    // 0x80000C9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000CA0: sb          $zero, -0x338E($at)
    MEM_B(-0X338E, ctx->r1) = 0;
    // 0x80000CA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80000CA8: sb          $zero, -0x338D($at)
    MEM_B(-0X338D, ctx->r1) = 0;
    // 0x80000CAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80000CB0: sb          $v0, 0x7BA3($at)
    MEM_B(0X7BA3, ctx->r1) = ctx->r2;
L_80000CB4:
    // 0x80000CB4: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x80000CB8: beq         $v0, $zero, L_80000CD0
    if (ctx->r2 == 0) {
        // 0x80000CBC: nop
    
            goto L_80000CD0;
    }
    // 0x80000CBC: nop

    // 0x80000CC0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80000CC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80000CC8: j           L_80000CDC
    // 0x80000CCC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
        goto L_80000CDC;
    // 0x80000CCC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
L_80000CD0:
    // 0x80000CD0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80000CD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80000CD8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
L_80000CDC:
    // 0x80000CDC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80000CE0: jalr        $v0
    // 0x80000CE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80000CE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80000CE8: jal         0x80004644
    // 0x80000CEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_1;
    // 0x80000CEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80000CF0: j           L_80000CB4
    // 0x80000CF4: nop

        goto L_80000CB4;
    // 0x80000CF4: nop

    // 0x80000CF8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80000CFC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80000D00: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80000D04: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000D08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000D0C: jr          $ra
    // 0x80000D10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80000D10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80000D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000D18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000D1C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80000D20: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80000D24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000D28: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80000D2C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80000D30: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80000D34: beq         $v1, $s1, L_80000D7C
    if (ctx->r3 == ctx->r17) {
        // 0x80000D38: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80000D7C;
    }
    // 0x80000D38: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80000D3C: beql        $v0, $zero, L_80000D54
    if (ctx->r2 == 0) {
        // 0x80000D40: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80000D54;
    }
    goto skip_0;
    // 0x80000D40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80000D44: beq         $v1, $zero, L_80000D6C
    if (ctx->r3 == 0) {
        // 0x80000D48: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80000D6C;
    }
    // 0x80000D48: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80000D4C: j           L_80000E38
    // 0x80000D50: nop

        goto L_80000E38;
    // 0x80000D50: nop

L_80000D54:
    // 0x80000D54: beq         $v1, $v0, L_80000DB4
    if (ctx->r3 == ctx->r2) {
        // 0x80000D58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80000DB4;
    }
    // 0x80000D58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80000D5C: beq         $v1, $v0, L_80000DF4
    if (ctx->r3 == ctx->r2) {
        // 0x80000D60: nop
    
            goto L_80000DF4;
    }
    // 0x80000D60: nop

    // 0x80000D64: j           L_80000E38
    // 0x80000D68: nop

        goto L_80000E38;
    // 0x80000D68: nop

L_80000D6C:
    // 0x80000D6C: jal         0x80056E94
    // 0x80000D70: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    func_80056E94(rdram, ctx);
        goto after_0;
    // 0x80000D70: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    after_0:
    // 0x80000D74: jal         0x80056EB0
    // 0x80000D78: nop

    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x80000D78: nop

    after_1:
L_80000D7C:
    // 0x80000D7C: jal         0x80000E94
    // 0x80000D80: nop

    func_80000E94(rdram, ctx);
        goto after_2;
    // 0x80000D80: nop

    after_2:
    // 0x80000D84: jal         0x80056F7C
    // 0x80000D88: nop

    func_80056F7C(rdram, ctx);
        goto after_3;
    // 0x80000D88: nop

    after_3:
    // 0x80000D8C: jal         0x80056EFC
    // 0x80000D90: nop

    func_80056EFC(rdram, ctx);
        goto after_4;
    // 0x80000D90: nop

    after_4:
    // 0x80000D94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80000D98: bne         $v0, $v1, L_80000E38
    if (ctx->r2 != ctx->r3) {
        // 0x80000D9C: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_80000E38;
    }
    // 0x80000D9C: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x80000DA0: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80000DA4: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x80000DA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000DAC: j           L_80000E38
    // 0x80000DB0: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
        goto L_80000E38;
    // 0x80000DB0: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_80000DB4:
    // 0x80000DB4: jal         0x80000E94
    // 0x80000DB8: nop

    func_80000E94(rdram, ctx);
        goto after_5;
    // 0x80000DB8: nop

    after_5:
    // 0x80000DBC: jal         0x80056F7C
    // 0x80000DC0: nop

    func_80056F7C(rdram, ctx);
        goto after_6;
    // 0x80000DC0: nop

    after_6:
    // 0x80000DC4: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80000DC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80000DCC: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80000DD0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80000DD4: bne         $v0, $zero, L_80000E38
    if (ctx->r2 != 0) {
        // 0x80000DD8: nop
    
            goto L_80000E38;
    }
    // 0x80000DD8: nop

    // 0x80000DDC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80000DE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000DE4: jal         0x80056ED8
    // 0x80000DE8: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    func_80056ED8(rdram, ctx);
        goto after_7;
    // 0x80000DE8: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    after_7:
    // 0x80000DEC: j           L_80000E38
    // 0x80000DF0: nop

        goto L_80000E38;
    // 0x80000DF0: nop

L_80000DF4:
    // 0x80000DF4: jal         0x80000E94
    // 0x80000DF8: nop

    func_80000E94(rdram, ctx);
        goto after_8;
    // 0x80000DF8: nop

    after_8:
    // 0x80000DFC: jal         0x80056F7C
    // 0x80000E00: nop

    func_80056F7C(rdram, ctx);
        goto after_9;
    // 0x80000E00: nop

    after_9:
    // 0x80000E04: jal         0x80056EFC
    // 0x80000E08: nop

    func_80056EFC(rdram, ctx);
        goto after_10;
    // 0x80000E08: nop

    after_10:
    // 0x80000E0C: bne         $v0, $s1, L_80000E38
    if (ctx->r2 != ctx->r17) {
        // 0x80000E10: nop
    
            goto L_80000E38;
    }
    // 0x80000E10: nop

    // 0x80000E14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000E18: sw          $v0, 0x5158($at)
    MEM_W(0X5158, ctx->r1) = ctx->r2;
    // 0x80000E1C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80000E20: addiu       $a1, $a1, 0x35E0
    ctx->r5 = ADD32(ctx->r5, 0X35E0);
    // 0x80000E24: jal         0x800045A0
    // 0x80000E28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800045A0(rdram, ctx);
        goto after_11;
    // 0x80000E28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x80000E2C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80000E30: jal         0x80004780
    // 0x80000E34: addiu       $a0, $a0, 0x6FB0
    ctx->r4 = ADD32(ctx->r4, 0X6FB0);
    func_80004780(rdram, ctx);
        goto after_12;
    // 0x80000E34: addiu       $a0, $a0, 0x6FB0
    ctx->r4 = ADD32(ctx->r4, 0X6FB0);
    after_12:
L_80000E38:
    // 0x80000E38: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80000E3C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000E40: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000E44: jr          $ra
    // 0x80000E48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80000E48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80000E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E4C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80000E50: addiu       $a0, $a0, -0x3390
    ctx->r4 = ADD32(ctx->r4, -0X3390);
    // 0x80000E54: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80000E58: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80000E5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80000E60: sb          $v0, 0x5580($at)
    MEM_B(0X5580, ctx->r1) = ctx->r2;
    // 0x80000E64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80000E68: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80000E6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80000E70: jr          $ra
    // 0x80000E74: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x80000E74: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80000E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000E7C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80000E80: jal         0x8002F8AC
    // 0x80000E84: nop

    func_8002F8AC(rdram, ctx);
        goto after_0;
    // 0x80000E84: nop

    after_0:
    // 0x80000E88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80000E8C: jr          $ra
    // 0x80000E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80000E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80000E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000E98: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80000E9C: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x80000EA0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80000EA4: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x80000EA8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80000EAC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80000EB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80000EB4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80000EB8: addiu       $s0, $s0, -0x6A94
    ctx->r16 = ADD32(ctx->r16, -0X6A94);
    // 0x80000EBC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80000EC0:
    // 0x80000EC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000EC4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80000EC8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80000ECC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80000ED0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80000ED4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80000ED8: jal         0x8004E614
    // 0x80000EDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_8004E614(rdram, ctx);
        goto after_0;
    // 0x80000EDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80000EE0: slti        $v0, $s1, 0x18
    ctx->r2 = SIGNED(ctx->r17) < 0X18 ? 1 : 0;
    // 0x80000EE4: bne         $v0, $zero, L_80000EC0
    if (ctx->r2 != 0) {
        // 0x80000EE8: addiu       $a1, $zero, 0x50
        ctx->r5 = ADD32(0, 0X50);
            goto L_80000EC0;
    }
    // 0x80000EE8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80000EEC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80000EF0: addiu       $s0, $s0, -0x6A34
    ctx->r16 = ADD32(ctx->r16, -0X6A34);
    // 0x80000EF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000EF8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80000EFC: jal         0x8004E614
    // 0x80000F00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_1;
    // 0x80000F00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x80000F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F08: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80000F0C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80000F10: jal         0x8004E614
    // 0x80000F14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_2;
    // 0x80000F14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x80000F18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F1C: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80000F20: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80000F24: jal         0x8004E614
    // 0x80000F28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_3;
    // 0x80000F28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x80000F2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F30: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80000F34: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80000F38: jal         0x8004E614
    // 0x80000F3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_4;
    // 0x80000F3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x80000F40: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80000F44: addiu       $s0, $s0, -0x6A2C
    ctx->r16 = ADD32(ctx->r16, -0X6A2C);
    // 0x80000F48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F4C: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x80000F50: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80000F54: jal         0x8004E614
    // 0x80000F58: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_5;
    // 0x80000F58: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x80000F5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F60: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x80000F64: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80000F68: jal         0x8004E614
    // 0x80000F6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_6;
    // 0x80000F6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x80000F70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F74: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80000F78: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x80000F7C: jal         0x8004E614
    // 0x80000F80: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_7;
    // 0x80000F80: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x80000F84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000F88: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    // 0x80000F8C: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80000F90: jal         0x8004E614
    // 0x80000F94: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004E614(rdram, ctx);
        goto after_8;
    // 0x80000F94: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // 0x80000F98: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80000F9C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80000FA0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80000FA4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80000FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80000FAC: jr          $ra
    // 0x80000FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80000FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80000FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FC0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80000FC4: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x80000FC8: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x80000FCC: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x80000FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000FD4: sw          $zero, -0x4C38($at)
    MEM_W(-0X4C38, ctx->r1) = 0;
    // 0x80000FD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000FDC: sw          $zero, 0x7454($at)
    MEM_W(0X7454, ctx->r1) = 0;
    // 0x80000FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000FE4: sw          $zero, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = 0;
    // 0x80000FE8: jal         0x80004450
    // 0x80000FEC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80004450(rdram, ctx);
        goto after_0;
    // 0x80000FEC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80000FF0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80000FF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80000FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000FFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001000: sw          $zero, -0x34C0($at)
    MEM_W(-0X34C0, ctx->r1) = 0;
    // 0x80001004: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001008: sw          $v0, 0x775C($at)
    MEM_W(0X775C, ctx->r1) = ctx->r2;
    // 0x8000100C: jal         0x80061740
    // 0x80001010: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80001010: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80001014: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80001018: addiu       $s1, $s1, 0x5280
    ctx->r17 = ADD32(ctx->r17, 0X5280);
    // 0x8000101C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80001020: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001024: addiu       $a1, $a1, 0x7CC0
    ctx->r5 = ADD32(ctx->r5, 0X7CC0);
    // 0x80001028: jal         0x80061740
    // 0x8000102C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8000102C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80001030: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80001034: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001038: jal         0x80061AD0
    // 0x8000103C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8000103C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80001040: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001044: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80001048: jal         0x80000708
    // 0x8000104C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80000708(rdram, ctx);
        goto after_4;
    // 0x8000104C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x80001050: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80001054: addiu       $a1, $a1, 0xC50
    ctx->r5 = ADD32(ctx->r5, 0XC50);
    // 0x80001058: jal         0x800045A0
    // 0x8000105C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800045A0(rdram, ctx);
        goto after_5;
    // 0x8000105C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80001060: jal         0x80051C30
    // 0x80001064: nop

    func_80051C30(rdram, ctx);
        goto after_6;
    // 0x80001064: nop

    after_6:
    // 0x80001068: jal         0x80053390
    // 0x8000106C: nop

    func_80053390(rdram, ctx);
        goto after_7;
    // 0x8000106C: nop

    after_7:
    // 0x80001070: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80001074: jal         0x800663E0
    // 0x80001078: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_8;
    // 0x80001078: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    after_8:
    // 0x8000107C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80001080: addiu       $s0, $s0, -0x3260
    ctx->r16 = ADD32(ctx->r16, -0X3260);
    // 0x80001084: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80001088:
    // 0x80001088: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000108C: jal         0x800619A0
    // 0x80001090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80001090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80001094: jal         0x80005F7C
    // 0x80001098: nop

    func_80005F7C(rdram, ctx);
        goto after_10;
    // 0x80001098: nop

    after_10:
    // 0x8000109C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800010A0: lw          $v0, 0x7CA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CA4);
    // 0x800010A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800010A8: sw          $zero, -0x4C38($at)
    MEM_W(-0X4C38, ctx->r1) = 0;
    // 0x800010AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800010B0: sw          $zero, 0x7454($at)
    MEM_W(0X7454, ctx->r1) = 0;
    // 0x800010B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800010B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800010BC: sw          $v0, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = ctx->r2;
    // 0x800010C0: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800010C4: bne         $v0, $zero, L_800010D4
    if (ctx->r2 != 0) {
        // 0x800010C8: nop
    
            goto L_800010D4;
    }
    // 0x800010C8: nop

    // 0x800010CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800010D0: sw          $zero, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = 0;
L_800010D4:
    // 0x800010D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800010D8: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x800010DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800010E0: sw          $zero, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = 0;
    // 0x800010E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800010E8: sw          $zero, -0x6700($at)
    MEM_W(-0X6700, ctx->r1) = 0;
    // 0x800010EC: sll         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2 << 15);
    // 0x800010F0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800010F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800010F8: jal         0x80001188
    // 0x800010FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    func_80001188(rdram, ctx);
        goto after_11;
    // 0x800010FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    after_11:
    // 0x80001100: jal         0x800011D0
    // 0x80001104: nop

    func_800011D0(rdram, ctx);
        goto after_12;
    // 0x80001104: nop

    after_12:
    // 0x80001108: jal         0x8004DA90
    // 0x8000110C: nop

    func_8004DA90(rdram, ctx);
        goto after_13;
    // 0x8000110C: nop

    after_13:
    // 0x80001110: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001114: jal         0x800044EC
    // 0x80001118: sw          $zero, 0x2090($at)
    MEM_W(0X2090, ctx->r1) = 0;
    func_800044EC(rdram, ctx);
        goto after_14;
    // 0x80001118: sw          $zero, 0x2090($at)
    MEM_W(0X2090, ctx->r1) = 0;
    after_14:
    // 0x8000111C: jal         0x80001298
    // 0x80001120: nop

    func_80001298(rdram, ctx);
        goto after_15;
    // 0x80001120: nop

    after_15:
    // 0x80001124: jal         0x800012A0
    // 0x80001128: nop

    func_800012A0(rdram, ctx);
        goto after_16;
    // 0x80001128: nop

    after_16:
    // 0x8000112C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001130: addiu       $a0, $a0, 0x5280
    ctx->r4 = ADD32(ctx->r4, 0X5280);
    // 0x80001134: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001138: jal         0x800619A0
    // 0x8000113C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_17;
    // 0x8000113C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80001140: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80001144: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80001148: jal         0x800619A0
    // 0x8000114C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_18;
    // 0x8000114C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_18:
    // 0x80001150: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001154: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80001158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000115C: sw          $v0, 0x775C($at)
    MEM_W(0X775C, ctx->r1) = ctx->r2;
    // 0x80001160: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80001164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001168: sw          $v0, -0x34C0($at)
    MEM_W(-0X34C0, ctx->r1) = ctx->r2;
    // 0x8000116C: j           L_80001088
    // 0x80001170: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80001088;
    // 0x80001170: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80001174: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x80001178: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x8000117C: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80001180: jr          $ra
    // 0x80001184: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80001184: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80001188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001188: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000118C: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80001190: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x80001194: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80001198: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000119C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800011A0: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800011A4: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x800011A8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800011AC: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800011B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800011B4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800011B8: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800011BC: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x800011C0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800011C4: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x800011C8: jr          $ra
    // 0x800011CC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    return;
    // 0x800011CC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800011D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800011D8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800011DC: lw          $s0, 0x2FE4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2FE4);
    // 0x800011E0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800011E4: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x800011E8: lui         $a0, 0xFF10
    ctx->r4 = S32(0XFF10 << 16);
    // 0x800011EC: ori         $a0, $a0, 0x13F
    ctx->r4 = ctx->r4 | 0X13F;
    // 0x800011F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011F4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800011F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800011FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001200: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80001204: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001208: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x8000120C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80001210: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80001214: sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4 << 11);
    // 0x80001218: lui         $v0, 0x8037
    ctx->r2 = S32(0X8037 << 16);
    // 0x8000121C: addiu       $v0, $v0, -0x6000
    ctx->r2 = ADD32(ctx->r2, -0X6000);
    // 0x80001220: jal         0x80062180
    // 0x80001224: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80001224: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x80001228: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000122C: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // 0x80001230: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80001234: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80001238: lui         $a1, 0xF64F
    ctx->r5 = S32(0XF64F << 16);
    // 0x8000123C: ori         $a1, $a1, 0xC3BC
    ctx->r5 = ctx->r5 | 0XC3BC;
    // 0x80001240: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80001244: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80001248: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000124C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001250: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80001254: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80001258: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8000125C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001260: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001264: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80001268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000126C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001270: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80001274: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80001278: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8000127C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80001280: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80001284: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80001288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000128C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001290: jr          $ra
    // 0x80001294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80001298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001298: jr          $ra
    // 0x8000129C: nop

    return;
    // 0x8000129C: nop

;}
RECOMP_FUNC void func_800012A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012A0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800012A4: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x800012A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800012AC: lw          $a0, -0x34C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34C0);
    // 0x800012B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800012B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800012BC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800012C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800012C4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800012C8: lui         $v0, 0xE900
    ctx->r2 = S32(0XE900 << 16);
    // 0x800012CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800012D0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800012D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800012D8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800012DC: lui         $v0, 0xB800
    ctx->r2 = S32(0XB800 << 16);
    // 0x800012E0: sll         $s0, $a0, 1
    ctx->r16 = S32(ctx->r4 << 1);
    // 0x800012E4: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x800012E8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800012EC: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x800012F0: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x800012F4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800012F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800012FC: addiu       $v0, $v0, 0x75B0
    ctx->r2 = ADD32(ctx->r2, 0X75B0);
    // 0x80001300: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80001304: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80001308: jal         0x80061710
    // 0x8000130C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    func_80061710(rdram, ctx);
        goto after_0;
    // 0x8000130C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    after_0:
    // 0x80001310: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80001314: lw          $a1, -0x34C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X34C0);
    // 0x80001318: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000131C: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80001320: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80001324: addiu       $a2, $a2, -0x3260
    ctx->r6 = ADD32(ctx->r6, -0X3260);
    // 0x80001328: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8000132C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80001330: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80001334: sll         $a1, $a1, 15
    ctx->r5 = S32(ctx->r5 << 15);
    // 0x80001338: addu        $v1, $a1, $a2
    ctx->r3 = ADD32(ctx->r5, ctx->r6);
    // 0x8000133C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80001340: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80001344: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80001348: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000134C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001350: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80001354: sw          $v0, -0x34AC($at)
    MEM_W(-0X34AC, ctx->r1) = ctx->r2;
    // 0x80001358: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000135C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001360: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80001364: sw          $v0, -0x34A8($at)
    MEM_W(-0X34A8, ctx->r1) = ctx->r2;
    // 0x80001368: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8000136C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001370: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80001374: sw          $v0, -0x34A4($at)
    MEM_W(-0X34A4, ctx->r1) = ctx->r2;
    // 0x80001378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000137C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001380: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80001384: sw          $s0, -0x34B4($at)
    MEM_W(-0X34B4, ctx->r1) = ctx->r16;
    // 0x80001388: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000138C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80001390: sw          $v1, -0x34B0($at)
    MEM_W(-0X34B0, ctx->r1) = ctx->r3;
    // 0x80001394: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001398: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000139C: sw          $v0, -0x34B8($at)
    MEM_W(-0X34B8, ctx->r1) = ctx->r2;
    // 0x800013A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800013A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800013A8: jr          $ra
    // 0x800013AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800013AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800013B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800013B0: jr          $ra
    // 0x800013B4: nop

    return;
    // 0x800013B4: nop

;}
RECOMP_FUNC void func_800013C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800013C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800013C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800013C8: sh          $v0, -0x28F8($at)
    MEM_H(-0X28F8, ctx->r1) = ctx->r2;
    // 0x800013CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800013D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800013D4: sh          $v0, -0x33D8($at)
    MEM_H(-0X33D8, ctx->r1) = ctx->r2;
    // 0x800013D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800013DC: jr          $ra
    // 0x800013E0: sw          $zero, 0x7450($at)
    MEM_W(0X7450, ctx->r1) = 0;
    return;
    // 0x800013E0: sw          $zero, 0x7450($at)
    MEM_W(0X7450, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800013E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800013E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800013E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800013EC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800013F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800013F4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800013F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800013FC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80001400: addiu       $s0, $s0, -0x38B8
    ctx->r16 = ADD32(ctx->r16, -0X38B8);
    // 0x80001404: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001408: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8000140C: addiu       $a1, $a1, -0x2938
    ctx->r5 = ADD32(ctx->r5, -0X2938);
    // 0x80001410: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80001414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80001418: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000141C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80001420: jal         0x80061740
    // 0x80001424: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80001424: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80001428: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000142C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001430: addiu       $a1, $a1, 0x47F0
    ctx->r5 = ADD32(ctx->r5, 0X47F0);
    // 0x80001434: jal         0x80000708
    // 0x80001438: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80000708(rdram, ctx);
        goto after_1;
    // 0x80001438: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8000143C: jal         0x80000664
    // 0x80001440: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80000664(rdram, ctx);
        goto after_2;
    // 0x80001440: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80001444: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80001448: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000144C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80001450: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80001454: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001458: sw          $v0, 0x7C98($at)
    MEM_W(0X7C98, ctx->r1) = ctx->r2;
    // 0x8000145C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80001460:
    // 0x80001460: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80001464: sw          $v0, 0x17B0($at)
    MEM_W(0X17B0, ctx->r1) = ctx->r2;
L_80001468:
    // 0x80001468: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000146C: addiu       $a0, $a0, -0x38B8
    ctx->r4 = ADD32(ctx->r4, -0X38B8);
    // 0x80001470: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80001474: jal         0x800619A0
    // 0x80001478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80001478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8000147C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80001480: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80001484: beq         $v1, $s0, L_80001514
    if (ctx->r3 == ctx->r16) {
        // 0x80001488: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80001514;
    }
    // 0x80001488: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8000148C: beq         $v0, $zero, L_800014A4
    if (ctx->r2 == 0) {
        // 0x80001490: nop
    
            goto L_800014A4;
    }
    // 0x80001490: nop

    // 0x80001494: beq         $v1, $s4, L_800014B4
    if (ctx->r3 == ctx->r20) {
        // 0x80001498: nop
    
            goto L_800014B4;
    }
    // 0x80001498: nop

    // 0x8000149C: j           L_80001468
    // 0x800014A0: nop

        goto L_80001468;
    // 0x800014A0: nop

L_800014A4:
    // 0x800014A4: beql        $v1, $s3, L_80001468
    if (ctx->r3 == ctx->r19) {
        // 0x800014A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80001468;
    }
    goto skip_0;
    // 0x800014A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800014AC: j           L_80001468
    // 0x800014B0: nop

        goto L_80001468;
    // 0x800014B0: nop

L_800014B4:
    // 0x800014B4: beql        $s2, $v1, L_80001504
    if (ctx->r18 == ctx->r3) {
        // 0x800014B8: addiu       $s2, $zero, 0x2
        ctx->r18 = ADD32(0, 0X2);
            goto L_80001504;
    }
    goto skip_1;
    // 0x800014B8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    skip_1:
    // 0x800014BC: bne         $s2, $s0, L_80001504
    if (ctx->r18 != ctx->r16) {
        // 0x800014C0: nop
    
            goto L_80001504;
    }
    // 0x800014C0: nop

    // 0x800014C4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800014C8: lw          $v0, 0x17B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X17B0);
    // 0x800014CC: bne         $v0, $s1, L_800014E4
    if (ctx->r2 != ctx->r17) {
        // 0x800014D0: nop
    
            goto L_800014E4;
    }
    // 0x800014D0: nop

    // 0x800014D4: jal         0x80067ED0
    // 0x800014D8: nop

    func_80067ED0(rdram, ctx);
        goto after_4;
    // 0x800014D8: nop

    after_4:
    // 0x800014DC: j           L_80001460
    // 0x800014E0: nop

        goto L_80001460;
    // 0x800014E0: nop

L_800014E4:
    // 0x800014E4: jal         0x80001C20
    // 0x800014E8: nop

    func_80001C20(rdram, ctx);
        goto after_5;
    // 0x800014E8: nop

    after_5:
    // 0x800014EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800014F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800014F4: jal         0x80066390
    // 0x800014F8: nop

    osViSetYScale_recomp(rdram, ctx);
        goto after_6;
    // 0x800014F8: nop

    after_6:
    // 0x800014FC: j           L_80001468
    // 0x80001500: nop

        goto L_80001468;
    // 0x80001500: nop

L_80001504:
    // 0x80001504: jal         0x8000156C
    // 0x80001508: nop

    func_8000156C(rdram, ctx);
        goto after_7;
    // 0x80001508: nop

    after_7:
    // 0x8000150C: j           L_80001468
    // 0x80001510: nop

        goto L_80001468;
    // 0x80001510: nop

L_80001514:
    // 0x80001514: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001518: addiu       $a0, $a0, 0x5280
    ctx->r4 = ADD32(ctx->r4, 0X5280);
    // 0x8000151C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001520: jal         0x80061AD0
    // 0x80001524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80001524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80001528: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000152C: lw          $v1, -0x69CC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69CC);
    // 0x80001530: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80001534: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001538: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000153C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001540: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80001544: j           L_80001468
    // 0x80001548: sw          $zero, -0x34B8($at)
    MEM_W(-0X34B8, ctx->r1) = 0;
        goto L_80001468;
    // 0x80001548: sw          $zero, -0x34B8($at)
    MEM_W(-0X34B8, ctx->r1) = 0;
    // 0x8000154C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80001550: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80001554: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80001558: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000155C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001564: jr          $ra
    // 0x80001568: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80001568: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000156C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000156C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001570: lw          $a0, 0x775C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X775C);
    // 0x80001574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001578: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000157C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80001580: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80001584: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80001588: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000158C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80001590: lw          $v1, -0x34B8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34B8);
    // 0x80001594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001598: bne         $v1, $v0, L_80001610
    if (ctx->r3 != ctx->r2) {
        // 0x8000159C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80001610;
    }
    // 0x8000159C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800015A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800015A4: sw          $a0, -0x69CC($at)
    MEM_W(-0X69CC, ctx->r1) = ctx->r4;
    // 0x800015A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800015AC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800015B0: jal         0x80061710
    // 0x800015B4: sw          $v0, -0x34B8($at)
    MEM_W(-0X34B8, ctx->r1) = ctx->r2;
    func_80061710(rdram, ctx);
        goto after_0;
    // 0x800015B4: sw          $v0, -0x34B8($at)
    MEM_W(-0X34B8, ctx->r1) = ctx->r2;
    after_0:
    // 0x800015B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800015BC: lw          $v1, 0x775C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X775C);
    // 0x800015C0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800015C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800015C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800015CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800015D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800015D4: lw          $v1, -0x34A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34A4);
    // 0x800015D8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800015DC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800015E0: lw          $a0, -0x34B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34B4);
    // 0x800015E4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800015E8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800015EC: lw          $a1, -0x34B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X34B0);
    // 0x800015F0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800015F4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800015F8: lw          $a2, -0x34AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X34AC);
    // 0x800015FC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80001600: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80001604: lw          $a3, -0x34A8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X34A8);
    // 0x80001608: jal         0x800016A8
    // 0x8000160C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800016A8(rdram, ctx);
        goto after_1;
    // 0x8000160C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
L_80001610:
    // 0x80001610: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80001614: jr          $ra
    // 0x80001618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80001618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000161C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000161C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001620: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80001624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001628: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8000162C: addiu       $s0, $s0, -0x2AE8
    ctx->r16 = ADD32(ctx->r16, -0X2AE8);
    // 0x80001630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001634: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001638: addiu       $v0, $v0, -0x4430
    ctx->r2 = ADD32(ctx->r2, -0X4430);
    // 0x8000163C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001640: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80001644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80001648: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8000164C: addiu       $a2, $a2, 0x13E4
    ctx->r6 = ADD32(ctx->r6, 0X13E4);
    // 0x80001650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80001654: jal         0x80061770
    // 0x80001658: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80001658: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x8000165C: jal         0x80061C60
    // 0x80001660: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80001660: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80001664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000166C: jr          $ra
    // 0x80001670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80001670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80001674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001674: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001678: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000167C: addiu       $a0, $a0, -0x38B8
    ctx->r4 = ADD32(ctx->r4, -0X38B8);
    // 0x80001680: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80001684: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80001688: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000168C: jal         0x800619A0
    // 0x80001690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80001690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80001694: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80001698: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8000169C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800016A0: jr          $ra
    // 0x800016A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800016A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800016A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800016AC: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800016B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800016B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800016B8: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x800016BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800016C0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800016C4: addiu       $v1, $v1, -0x2B60
    ctx->r3 = ADD32(ctx->r3, -0X2B60);
    // 0x800016C8: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800016CC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800016D0: addiu       $v0, $v0, -0x2A90
    ctx->r2 = ADD32(ctx->r2, -0X2A90);
    // 0x800016D4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800016D8: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x800016DC: sw          $a1, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r5;
    // 0x800016E0: sw          $a2, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r6;
    // 0x800016E4: sw          $v1, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r3;
    // 0x800016E8: sw          $v0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r2;
    // 0x800016EC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800016F0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800016F4: lw          $v0, -0x6A10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6A10);
    // 0x800016F8: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x800016FC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80001700: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001704: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x80001708: lw          $a0, -0x6A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6A0C);
    // 0x8000170C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80001710: sw          $v0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r2;
    // 0x80001714: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x80001718: addiu       $v0, $v0, 0x7000
    ctx->r2 = ADD32(ctx->r2, 0X7000);
    // 0x8000171C: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x80001720: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80001724: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x80001728: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8000172C: addiu       $v0, $v0, 0x5000
    ctx->r2 = ADD32(ctx->r2, 0X5000);
    // 0x80001730: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    // 0x80001734: addiu       $v0, $v0, 0x2000
    ctx->r2 = ADD32(ctx->r2, 0X2000);
    // 0x80001738: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // 0x8000173C: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x80001740: addiu       $v0, $v0, 0x7400
    ctx->r2 = ADD32(ctx->r2, 0X7400);
    // 0x80001744: sw          $v0, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r2;
    // 0x80001748: addiu       $v0, $zero, 0xC00
    ctx->r2 = ADD32(0, 0XC00);
    // 0x8000174C: sw          $v0, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->r2;
    // 0x80001750: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001754: addiu       $v0, $v0, -0x38B8
    ctx->r2 = ADD32(ctx->r2, -0X38B8);
    // 0x80001758: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8000175C: sw          $v0, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r2;
    // 0x80001760: sw          $v1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r3;
    // 0x80001764: andi        $v1, $v1, 0x40
    ctx->r3 = ctx->r3 & 0X40;
    // 0x80001768: beq         $v1, $zero, L_80001780
    if (ctx->r3 == 0) {
        // 0x8000176C: sw          $a0, 0x28($t0)
        MEM_W(0X28, ctx->r8) = ctx->r4;
            goto L_80001780;
    }
    // 0x8000176C: sw          $a0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r4;
    // 0x80001770: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001774: addiu       $v0, $v0, -0x28F8
    ctx->r2 = ADD32(ctx->r2, -0X28F8);
    // 0x80001778: j           L_8000178C
    // 0x8000177C: sw          $v0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r2;
        goto L_8000178C;
    // 0x8000177C: sw          $v0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r2;
L_80001780:
    // 0x80001780: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001784: addiu       $v0, $v0, -0x33D8
    ctx->r2 = ADD32(ctx->r2, -0X33D8);
    // 0x80001788: sw          $v0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r2;
L_8000178C:
    // 0x8000178C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001790: lw          $v0, 0x775C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X775C);
    // 0x80001794: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001798: lw          $a0, 0x7C98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C98);
    // 0x8000179C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x800017A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800017A4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800017A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800017AC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800017B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800017B4: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x800017B8: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x800017BC: addiu       $v1, $v1, -0x6000
    ctx->r3 = ADD32(ctx->r3, -0X6000);
    // 0x800017C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800017C4: jal         0x80061AD0
    // 0x800017C8: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800017C8: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    after_0:
    // 0x800017CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800017D0: lw          $v0, 0x7450($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7450);
    // 0x800017D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800017D8: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x800017DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800017E0: sw          $v0, 0x7450($at)
    MEM_W(0X7450, ctx->r1) = ctx->r2;
    // 0x800017E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800017E8: jr          $ra
    // 0x800017EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800017EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mtc_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800017F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800017F8: jal         0x80068860
    // 0x800017FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x800017FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80001800: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80001804: addiu       $s0, $s0, 0x77B0
    ctx->r16 = ADD32(ctx->r16, 0X77B0);
    // 0x80001808: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000180C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001810: addiu       $v0, $v0, 0x5260
    ctx->r2 = ADD32(ctx->r2, 0X5260);
    // 0x80001814: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000181C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001820: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80001824: addiu       $a2, $a2, 0x184C
    ctx->r6 = ADD32(ctx->r6, 0X184C);
    // 0x80001828: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000182C: jal         0x80061770
    // 0x80001830: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80001830: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x80001834: jal         0x80061C60
    // 0x80001838: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80001838: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8000183C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001844: jr          $ra
    // 0x80001848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80001848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000184C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000184C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001850: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001854: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80001858: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8000185C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001860: addiu       $a1, $a1, 0x7CA8
    ctx->r5 = ADD32(ctx->r5, 0X7CA8);
    // 0x80001864: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80001868: addiu       $a2, $a2, 0x2980
    ctx->r6 = ADD32(ctx->r6, 0X2980);
    // 0x8000186C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80001870: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80001874: jal         0x80067570
    // 0x80001878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osCreatePiManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80001878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000187C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80001880: addiu       $s0, $s0, 0x72A0
    ctx->r16 = ADD32(ctx->r16, 0X72A0);
    // 0x80001884: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001888: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8000188C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80001890: addiu       $a2, $a2, 0x18E0
    ctx->r6 = ADD32(ctx->r6, 0X18E0);
    // 0x80001894: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80001898: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000189C: addiu       $v0, $v0, 0x5150
    ctx->r2 = ADD32(ctx->r2, 0X5150);
    // 0x800018A0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800018A4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800018A8: jal         0x80061770
    // 0x800018AC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800018AC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800018B0: jal         0x80061C60
    // 0x800018B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800018B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_800018B8:
    // 0x800018B8: j           L_800018B8
    pause_self(rdram);
    // 0x800018BC: nop

    // 0x800018C0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800018C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800018C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800018CC: jr          $ra
    // 0x800018D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800018D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800018E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800018E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800018E8: jal         0x800616C0
    // 0x800018EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800616C0(rdram, ctx);
        goto after_0;
    // 0x800018EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800018F0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800018F4: addiu       $a0, $a0, 0x2070
    ctx->r4 = ADD32(ctx->r4, 0X2070);
    // 0x800018F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800018FC:
    // 0x800018FC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80001900: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001904: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80001908: sltiu       $v0, $v0, 0x38
    ctx->r2 = ctx->r2 < 0X38 ? 1 : 0;
    // 0x8000190C: bne         $v0, $zero, L_800018FC
    if (ctx->r2 != 0) {
        // 0x80001910: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800018FC;
    }
    // 0x80001910: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001914: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80001918: addiu       $a0, $a0, 0x7B30
    ctx->r4 = ADD32(ctx->r4, 0X7B30);
    // 0x8000191C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80001920:
    // 0x80001920: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80001924: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001928: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8000192C: sltiu       $v0, $v0, 0x20
    ctx->r2 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x80001930: bne         $v0, $zero, L_80001920
    if (ctx->r2 != 0) {
        // 0x80001934: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80001920;
    }
    // 0x80001934: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001938: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000193C: addiu       $a0, $a0, 0x5580
    ctx->r4 = ADD32(ctx->r4, 0X5580);
    // 0x80001940: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80001944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001948: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000194C: sb          $v0, 0x7B41($at)
    MEM_B(0X7B41, ctx->r1) = ctx->r2;
    // 0x80001950: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001954: sb          $v0, 0x7B40($at)
    MEM_B(0X7B40, ctx->r1) = ctx->r2;
L_80001958:
    // 0x80001958: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000195C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001960: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80001964: sltiu       $v0, $v0, 0x14
    ctx->r2 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x80001968: bne         $v0, $zero, L_80001958
    if (ctx->r2 != 0) {
        // 0x8000196C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80001958;
    }
    // 0x8000196C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001970: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80001974: addiu       $a0, $a0, 0x7B70
    ctx->r4 = ADD32(ctx->r4, 0X7B70);
    // 0x80001978: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8000197C:
    // 0x8000197C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80001980: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001984: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80001988: sltiu       $v0, $v0, 0x54
    ctx->r2 = ctx->r2 < 0X54 ? 1 : 0;
    // 0x8000198C: bne         $v0, $zero, L_8000197C
    if (ctx->r2 != 0) {
        // 0x80001990: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000197C;
    }
    // 0x80001990: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001994: jal         0x8000B87C
    // 0x80001998: nop

    func_8000B87C(rdram, ctx);
        goto after_1;
    // 0x80001998: nop

    after_1:
    // 0x8000199C: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800019A0: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x800019A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800019A8: beq         $v1, $v0, L_800019C4
    if (ctx->r3 == ctx->r2) {
        // 0x800019AC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800019C4;
    }
    // 0x800019AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800019B0: bne         $v1, $v0, L_800019C4
    if (ctx->r3 != ctx->r2) {
        // 0x800019B4: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_800019C4;
    }
    // 0x800019B4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800019B8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800019BC: j           L_800019D0
    // 0x800019C0: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
        goto L_800019D0;
    // 0x800019C0: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
L_800019C4:
    // 0x800019C4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800019C8: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    // 0x800019CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800019D0:
    // 0x800019D0: jal         0x80000450
    // 0x800019D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80000450(rdram, ctx);
        goto after_2;
    // 0x800019D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800019D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800019DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800019E0: jal         0x80066390
    // 0x800019E4: nop

    osViSetYScale_recomp(rdram, ctx);
        goto after_3;
    // 0x800019E4: nop

    after_3:
    // 0x800019E8: jal         0x80001C20
    // 0x800019EC: nop

    func_80001C20(rdram, ctx);
        goto after_4;
    // 0x800019EC: nop

    after_4:
    // 0x800019F0: jal         0x80066220
    // 0x800019F4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_5;
    // 0x800019F4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_5:
    // 0x800019F8: jal         0x800013C0
    // 0x800019FC: nop

    func_800013C0(rdram, ctx);
        goto after_6;
    // 0x800019FC: nop

    after_6:
    // 0x80001A00: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80001A04: addiu       $s0, $s0, -0x31D0
    ctx->r16 = ADD32(ctx->r16, -0X31D0);
    // 0x80001A08: jal         0x8000161C
    // 0x80001A0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000161C(rdram, ctx);
        goto after_7;
    // 0x80001A0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80001A10: jal         0x80004870
    // 0x80001A14: nop

    func_80004870(rdram, ctx);
        goto after_8;
    // 0x80001A14: nop

    after_8:
    // 0x80001A18: jal         0x80005110
    // 0x80001A1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80005110(rdram, ctx);
        goto after_9;
    // 0x80001A1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80001A20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001A24: addiu       $a0, $a0, 0x4800
    ctx->r4 = ADD32(ctx->r4, 0X4800);
    // 0x80001A28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001A2C: addiu       $a1, $a1, 0x7758
    ctx->r5 = ADD32(ctx->r5, 0X7758);
    // 0x80001A30: jal         0x80061740
    // 0x80001A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_10;
    // 0x80001A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80001A38: jal         0x80005E54
    // 0x80001A3C: nop

    func_80005E54(rdram, ctx);
        goto after_11;
    // 0x80001A3C: nop

    after_11:
    // 0x80001A40: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80001A44: lw          $v0, 0x30C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30C);
    // 0x80001A48: bne         $v0, $zero, L_80001AAC
    if (ctx->r2 != 0) {
        // 0x80001A4C: nop
    
            goto L_80001AAC;
    }
    // 0x80001A4C: nop

    // 0x80001A50: jal         0x80051A08
    // 0x80001A54: nop

    func_80051A08(rdram, ctx);
        goto after_12;
    // 0x80001A54: nop

    after_12:
    // 0x80001A58: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x80001A5C: addiu       $a0, $a0, 0x3230
    ctx->r4 = ADD32(ctx->r4, 0X3230);
    // 0x80001A60: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80001A64: addiu       $a1, $a1, 0xB90
    ctx->r5 = ADD32(ctx->r5, 0XB90);
    // 0x80001A68: jal         0x80006D98
    // 0x80001A6C: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    func_80006D98(rdram, ctx);
        goto after_13;
    // 0x80001A6C: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    after_13:
    // 0x80001A70: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80001A74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001A78: sh          $v0, -0x325A($at)
    MEM_H(-0X325A, ctx->r1) = ctx->r2;
    // 0x80001A7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001A80: sh          $v0, -0x3260($at)
    MEM_H(-0X3260, ctx->r1) = ctx->r2;
    // 0x80001A84: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80001A88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001A8C: sh          $v0, -0x3258($at)
    MEM_H(-0X3258, ctx->r1) = ctx->r2;
    // 0x80001A90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001A94: sh          $v0, -0x325E($at)
    MEM_H(-0X325E, ctx->r1) = ctx->r2;
    // 0x80001A98: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80001A9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001AA0: sh          $v0, -0x3256($at)
    MEM_H(-0X3256, ctx->r1) = ctx->r2;
    // 0x80001AA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001AA8: sh          $v0, -0x325C($at)
    MEM_H(-0X325C, ctx->r1) = ctx->r2;
L_80001AAC:
    // 0x80001AAC: jal         0x80061910
    // 0x80001AB0: nop

    osGetTime_recomp(rdram, ctx);
        goto after_14;
    // 0x80001AB0: nop

    after_14:
    // 0x80001AB4: jal         0x8006CEE4
    // 0x80001AB8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8006CEE4(rdram, ctx);
        goto after_15;
    // 0x80001AB8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_15:
    // 0x80001ABC: jal         0x8004D958
    // 0x80001AC0: nop

    func_8004D958(rdram, ctx);
        goto after_16;
    // 0x80001AC0: nop

    after_16:
    // 0x80001AC4: jal         0x80000B90
    // 0x80001AC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80000B90(rdram, ctx);
        goto after_17;
    // 0x80001AC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
L_80001ACC:
    // 0x80001ACC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80001AD0: jal         0x80000FC0
    // 0x80001AD4: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    func_80000FC0(rdram, ctx);
        goto after_18;
    // 0x80001AD4: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    after_18:
    // 0x80001AD8: j           L_80001ACC
    // 0x80001ADC: nop

        goto L_80001ACC;
    // 0x80001ADC: nop

    // 0x80001AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AE4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001AE8: jr          $ra
    // 0x80001AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80001AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001AF4: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80001AF8: lui         $a2, 0x4204
    ctx->r6 = S32(0X4204 << 16);
    // 0x80001AFC: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80001B00: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80001B04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80001B08: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80001B0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80001B10: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80001B14: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80001B18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80001B1C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80001B20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80001B24: addiu       $a0, $a0, -0x3458
    ctx->r4 = ADD32(ctx->r4, -0X3458);
    // 0x80001B28: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80001B2C: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x80001B30: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80001B34: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80001B38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80001B3C: jal         0x800610C0
    // 0x80001B40: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x80001B40: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80001B44: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x80001B48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80001B4C: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80001B50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80001B54: nop

    // 0x80001B58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80001B5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001B60: addiu       $a0, $a0, -0x43A8
    ctx->r4 = ADD32(ctx->r4, -0X43A8);
    // 0x80001B64: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80001B68: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80001B6C: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x80001B70: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80001B74: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80001B78: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x80001B7C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80001B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001B84: jal         0x80060900
    // 0x80001B88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    guLookAt(rdram, ctx);
        goto after_1;
    // 0x80001B88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80001B8C: lui         $a1, 0x103
    ctx->r5 = S32(0X103 << 16);
    // 0x80001B90: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
    // 0x80001B94: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80001B98: ori         $a2, $a2, 0x40
    ctx->r6 = ctx->r6 | 0X40;
    // 0x80001B9C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80001BA0: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80001BA4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80001BA8: lw          $a0, -0x34C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34C0);
    // 0x80001BAC: lui         $a3, 0xBC00
    ctx->r7 = S32(0XBC00 << 16);
    // 0x80001BB0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80001BB4: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x80001BB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001BBC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001BC0: lui         $v0, 0xD
    ctx->r2 = S32(0XD << 16);
    // 0x80001BC4: addiu       $v0, $v0, -0x3458
    ctx->r2 = ADD32(ctx->r2, -0X3458);
    // 0x80001BC8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80001BCC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80001BD0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80001BD4: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x80001BD8: lhu         $a1, 0x28($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X28);
    // 0x80001BDC: ori         $a3, $a3, 0xE
    ctx->r7 = ctx->r7 | 0XE;
    // 0x80001BE0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80001BE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001BE8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001BEC: lui         $v0, 0xE
    ctx->r2 = S32(0XE << 16);
    // 0x80001BF0: addiu       $v0, $v0, -0x43A8
    ctx->r2 = ADD32(ctx->r2, -0X43A8);
    // 0x80001BF4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80001BF8: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80001BFC: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x80001C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80001C04: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80001C08: sw          $a3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r7;
    // 0x80001C0C: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    // 0x80001C10: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80001C14: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80001C18: jr          $ra
    // 0x80001C1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80001C1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80001C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C20: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80001C24: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80001C28: ori         $a3, $a3, 0x2BFF
    ctx->r7 = ctx->r7 | 0X2BFF;
    // 0x80001C2C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80001C30: addiu       $a1, $a1, -0x6000
    ctx->r5 = ADD32(ctx->r5, -0X6000);
    // 0x80001C34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80001C38:
    // 0x80001C38: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80001C3C:
    // 0x80001C3C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80001C40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001C44: slt         $v0, $a3, $a0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80001C48: beq         $v0, $zero, L_80001C3C
    if (ctx->r2 == 0) {
        // 0x80001C4C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80001C3C;
    }
    // 0x80001C4C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80001C50: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x80001C54: ori         $v0, $v0, 0x5800
    ctx->r2 = ctx->r2 | 0X5800;
    // 0x80001C58: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80001C5C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80001C60: slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80001C64: bnel        $v0, $zero, L_80001C38
    if (ctx->r2 != 0) {
        // 0x80001C68: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80001C38;
    }
    goto skip_0;
    // 0x80001C68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x80001C6C: jr          $ra
    // 0x80001C70: nop

    return;
    // 0x80001C70: nop

;}
RECOMP_FUNC void func_80001C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001C84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80001C88: jal         0x80001E9C
    // 0x80001C8C: nop

    func_80001E9C(rdram, ctx);
        goto after_0;
    // 0x80001C8C: nop

    after_0:
    // 0x80001C90: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001C94: lbu         $v0, 0x7B4C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4C);
    // 0x80001C98: bne         $v0, $zero, L_80001CEC
    if (ctx->r2 != 0) {
        // 0x80001C9C: nop
    
            goto L_80001CEC;
    }
    // 0x80001C9C: nop

    // 0x80001CA0: jal         0x80001E8C
    // 0x80001CA4: nop

    func_80001E8C(rdram, ctx);
        goto after_1;
    // 0x80001CA4: nop

    after_1:
    // 0x80001CA8: jal         0x80001E94
    // 0x80001CAC: nop

    func_80001E94(rdram, ctx);
        goto after_2;
    // 0x80001CAC: nop

    after_2:
    // 0x80001CB0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80001CB4: lbu         $a1, 0x7B44($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B44);
    // 0x80001CB8: jal         0x80001D54
    // 0x80001CBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80001D54(rdram, ctx);
        goto after_3;
    // 0x80001CBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x80001CC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001CC4: lbu         $v1, 0x7B4A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4A);
    // 0x80001CC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80001CCC: beq         $v1, $v0, L_80001CE4
    if (ctx->r3 == ctx->r2) {
        // 0x80001CD0: nop
    
            goto L_80001CE4;
    }
    // 0x80001CD0: nop

    // 0x80001CD4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80001CD8: lbu         $a1, 0x7B45($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B45);
    // 0x80001CDC: jal         0x80001D54
    // 0x80001CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80001D54(rdram, ctx);
        goto after_4;
    // 0x80001CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
L_80001CE4:
    // 0x80001CE4: jal         0x80001D4C
    // 0x80001CE8: nop

    func_80001D4C(rdram, ctx);
        goto after_5;
    // 0x80001CE8: nop

    after_5:
L_80001CEC:
    // 0x80001CEC: jal         0x80001F20
    // 0x80001CF0: nop

    func_80001F20(rdram, ctx);
        goto after_6;
    // 0x80001CF0: nop

    after_6:
    // 0x80001CF4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001CF8: lbu         $v1, 0x7B38($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B38);
    // 0x80001CFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001D00: lbu         $v0, 0x7B3A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B3A);
    // 0x80001D04: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80001D08: lbu         $a0, 0x7B4A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B4A);
    // 0x80001D0C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80001D10: addiu       $a2, $a2, 0x2080
    ctx->r6 = ADD32(ctx->r6, 0X2080);
    // 0x80001D14: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x80001D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001D1C: bne         $a0, $v0, L_80001D40
    if (ctx->r4 != ctx->r2) {
        // 0x80001D20: sb          $a1, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r5;
            goto L_80001D40;
    }
    // 0x80001D20: sb          $a1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r5;
    // 0x80001D24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001D28: lbu         $v0, 0x7B3C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B3C);
    // 0x80001D2C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001D30: lbu         $v1, 0x7B3E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B3E);
    // 0x80001D34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001D38: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80001D3C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80001D40:
    // 0x80001D40: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80001D44: jr          $ra
    // 0x80001D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80001D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001D4C: jr          $ra
    // 0x80001D50: nop

    return;
    // 0x80001D50: nop

;}
RECOMP_FUNC void func_80001D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001D58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80001D5C: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x80001D60: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80001D64: addiu       $a0, $a0, 0x7B30
    ctx->r4 = ADD32(ctx->r4, 0X7B30);
    // 0x80001D68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001D6C: addu        $s0, $a3, $a0
    ctx->r16 = ADD32(ctx->r7, ctx->r4);
    // 0x80001D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001D74: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80001D78: beq         $a2, $zero, L_80001D90
    if (ctx->r6 == 0) {
        // 0x80001D7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001D90;
    }
    // 0x80001D7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001D80: beq         $a2, $v0, L_80001DB0
    if (ctx->r6 == ctx->r2) {
        // 0x80001D84: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_80001DB0;
    }
    // 0x80001D84: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80001D88: j           L_80001E04
    // 0x80001D8C: nop

        goto L_80001E04;
    // 0x80001D8C: nop

L_80001D90:
    // 0x80001D90: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80001D94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80001D98: bne         $v1, $v0, L_80001E04
    if (ctx->r3 != ctx->r2) {
        // 0x80001D9C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001E04;
    }
    // 0x80001D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001DA0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80001DA4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x80001DA8: j           L_80001E04
    // 0x80001DAC: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
        goto L_80001E04;
    // 0x80001DAC: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_80001DB0:
    // 0x80001DB0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80001DB4: beq         $v1, $v0, L_80001DDC
    if (ctx->r3 == ctx->r2) {
        // 0x80001DB8: nop
    
            goto L_80001DDC;
    }
    // 0x80001DB8: nop

    // 0x80001DBC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80001DC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80001DC4: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80001DC8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80001DCC: beql        $v0, $zero, L_80001E04
    if (ctx->r2 == 0) {
        // 0x80001DD0: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80001E04;
    }
    goto skip_0;
    // 0x80001DD0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_0:
    // 0x80001DD4: j           L_80001E04
    // 0x80001DD8: nop

        goto L_80001E04;
    // 0x80001DD8: nop

L_80001DDC:
    // 0x80001DDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001DE0: lbu         $v0, 0x7B4A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4A);
    // 0x80001DE4: bne         $v0, $a2, L_80001DF0
    if (ctx->r2 != ctx->r6) {
        // 0x80001DE8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80001DF0;
    }
    // 0x80001DE8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80001DEC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
L_80001DF0:
    // 0x80001DF0: jal         0x80001E14
    // 0x80001DF4: nop

    func_80001E14(rdram, ctx);
        goto after_0;
    // 0x80001DF4: nop

    after_0:
    // 0x80001DF8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80001DFC: jal         0x80006538
    // 0x80001E00: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80006538(rdram, ctx);
        goto after_1;
    // 0x80001E00: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_1:
L_80001E04:
    // 0x80001E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001E08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001E0C: jr          $ra
    // 0x80001E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80001E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E14: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001E18: addiu       $v1, $v1, 0x7B47
    ctx->r3 = ADD32(ctx->r3, 0X7B47);
    // 0x80001E1C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80001E20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001E24: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80001E28: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80001E2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001E30: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x80001E34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001E38: lbu         $v1, 0x7B40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B40);
    // 0x80001E3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80001E40: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80001E44: bne         $v0, $zero, L_80001E74
    if (ctx->r2 != 0) {
        // 0x80001E48: nop
    
            goto L_80001E74;
    }
    // 0x80001E48: nop

    // 0x80001E4C: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x80001E50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001E54: lbu         $v1, 0x7B41($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B41);
    // 0x80001E58: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x80001E5C: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80001E60: bne         $v0, $zero, L_80001E6C
    if (ctx->r2 != 0) {
        // 0x80001E64: addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
            goto L_80001E6C;
    }
    // 0x80001E64: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x80001E68: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80001E6C:
    // 0x80001E6C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80001E70: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_80001E74:
    // 0x80001E74: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80001E78: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80001E7C: beql        $v0, $zero, L_80001E84
    if (ctx->r2 == 0) {
        // 0x80001E80: sb          $zero, 0x2($a0)
        MEM_B(0X2, ctx->r4) = 0;
            goto L_80001E84;
    }
    goto skip_0;
    // 0x80001E80: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    skip_0:
L_80001E84:
    // 0x80001E84: jr          $ra
    // 0x80001E88: nop

    return;
    // 0x80001E88: nop

;}
RECOMP_FUNC void func_80001E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E8C: jr          $ra
    // 0x80001E90: nop

    return;
    // 0x80001E90: nop

;}
RECOMP_FUNC void func_80001E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E94: jr          $ra
    // 0x80001E98: nop

    return;
    // 0x80001E98: nop

;}
RECOMP_FUNC void func_80001E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E9C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80001EA0: addiu       $a1, $a1, 0x7B44
    ctx->r5 = ADD32(ctx->r5, 0X7B44);
    // 0x80001EA4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80001EA8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001EAC: lbu         $v1, 0x7B45($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B45);
    // 0x80001EB0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80001EB4: andi        $a0, $v0, 0xF
    ctx->r4 = ctx->r2 & 0XF;
    // 0x80001EB8: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x80001EBC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001EC0: lbu         $v0, 0x7B46($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B46);
    // 0x80001EC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80001EC8: andi        $a2, $v1, 0xF
    ctx->r6 = ctx->r3 & 0XF;
    // 0x80001ECC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80001ED0: lhu         $v1, -0x38A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X38A0);
    // 0x80001ED4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001ED8: sb          $a2, 0x7B45($at)
    MEM_B(0X7B45, ctx->r1) = ctx->r6;
    // 0x80001EDC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80001EE0: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80001EE4: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80001EE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001EEC: sb          $v0, 0x7B46($at)
    MEM_B(0X7B46, ctx->r1) = ctx->r2;
    // 0x80001EF0: beq         $v1, $zero, L_80001EFC
    if (ctx->r3 == 0) {
        // 0x80001EF4: ori         $v0, $a0, 0x1
        ctx->r2 = ctx->r4 | 0X1;
            goto L_80001EFC;
    }
    // 0x80001EF4: ori         $v0, $a0, 0x1
    ctx->r2 = ctx->r4 | 0X1;
    // 0x80001EF8: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80001EFC:
    // 0x80001EFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001F00: lhu         $v0, -0x389A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X389A);
    // 0x80001F04: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80001F08: beq         $v0, $zero, L_80001F18
    if (ctx->r2 == 0) {
        // 0x80001F0C: ori         $v0, $a2, 0x1
        ctx->r2 = ctx->r6 | 0X1;
            goto L_80001F18;
    }
    // 0x80001F0C: ori         $v0, $a2, 0x1
    ctx->r2 = ctx->r6 | 0X1;
    // 0x80001F10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80001F14: sb          $v0, 0x7B45($at)
    MEM_B(0X7B45, ctx->r1) = ctx->r2;
L_80001F18:
    // 0x80001F18: jr          $ra
    // 0x80001F1C: nop

    return;
    // 0x80001F1C: nop

;}
RECOMP_FUNC void func_80001F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F20: jr          $ra
    // 0x80001F24: nop

    return;
    // 0x80001F24: nop

;}
RECOMP_FUNC void func_80001F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001F34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001F38: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80001F3C: addiu       $s0, $s0, -0x7580
    ctx->r16 = ADD32(ctx->r16, -0X7580);
    // 0x80001F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80001F44:
    // 0x80001F44: jal         0x80004644
    // 0x80001F48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_0;
    // 0x80001F48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80001F4C: jal         0x80002020
    // 0x80001F50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80002020(rdram, ctx);
        goto after_1;
    // 0x80001F50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80001F54: jal         0x80002020
    // 0x80001F58: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    func_80002020(rdram, ctx);
        goto after_2;
    // 0x80001F58: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_2:
    // 0x80001F5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001F60: lbu         $v0, 0x2072($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2072);
    // 0x80001F64: bne         $v0, $zero, L_80001F44
    if (ctx->r2 != 0) {
        // 0x80001F68: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80001F44;
    }
    // 0x80001F68: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80001F6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001F70: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x80001F74: sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // 0x80001F78: beq         $v1, $zero, L_80001F98
    if (ctx->r3 == 0) {
        // 0x80001F7C: sb          $v0, 0x5($s0)
        MEM_B(0X5, ctx->r16) = ctx->r2;
            goto L_80001F98;
    }
    // 0x80001F7C: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
L_80001F80:
    // 0x80001F80: jal         0x80004644
    // 0x80001F84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_3;
    // 0x80001F84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80001F88: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80001F8C: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80001F90: bne         $v0, $zero, L_80001F80
    if (ctx->r2 != 0) {
        // 0x80001F94: nop
    
            goto L_80001F80;
    }
    // 0x80001F94: nop

L_80001F98:
    // 0x80001F98: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80001F9C: jal         0x80004780
    // 0x80001FA0: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    func_80004780(rdram, ctx);
        goto after_4;
    // 0x80001FA0: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    after_4:
    // 0x80001FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001FAC: jr          $ra
    // 0x80001FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80001FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FB4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x80001FB8: addiu       $v1, $v1, -0x7580
    ctx->r3 = ADD32(ctx->r3, -0X7580);
    // 0x80001FBC: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    // 0x80001FC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80001FC4:
    // 0x80001FC4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80001FC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80001FCC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80001FD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80001FD4: sltiu       $v0, $a0, 0x1C
    ctx->r2 = ctx->r4 < 0X1C ? 1 : 0;
    // 0x80001FD8: bne         $v0, $zero, L_80001FC4
    if (ctx->r2 != 0) {
        // 0x80001FDC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80001FC4;
    }
    // 0x80001FDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80001FE0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80001FE4: lbu         $v1, 0x2070($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2070);
    // 0x80001FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001FEC: bne         $v1, $v0, L_80002008
    if (ctx->r3 != ctx->r2) {
        // 0x80001FF0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80002008;
    }
    // 0x80001FF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80001FF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80001FF8: sb          $v0, -0x755F($at)
    MEM_B(-0X755F, ctx->r1) = ctx->r2;
    // 0x80001FFC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80002000: j           L_80002018
    // 0x80002004: sb          $v0, -0x757B($at)
    MEM_B(-0X757B, ctx->r1) = ctx->r2;
        goto L_80002018;
    // 0x80002004: sb          $v0, -0x757B($at)
    MEM_B(-0X757B, ctx->r1) = ctx->r2;
L_80002008:
    // 0x80002008: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000200C: sb          $zero, -0x755F($at)
    MEM_B(-0X755F, ctx->r1) = 0;
    // 0x80002010: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80002014: sb          $zero, -0x757B($at)
    MEM_B(-0X757B, ctx->r1) = 0;
L_80002018:
    // 0x80002018: jr          $ra
    // 0x8000201C: nop

    return;
    // 0x8000201C: nop

;}
RECOMP_FUNC void func_80002020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002024: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002028: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8000202C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80002030: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002034: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002038: lw          $v0, -0x217C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X217C);
    // 0x8000203C: jalr        $v0
    // 0x80002040: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80002040: nop

    after_0:
    // 0x80002044: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002048: jr          $ra
    // 0x8000204C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000204C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80002050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002054: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80002058: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8000205C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80002060: lbu         $a1, 0x2071($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2071);
    // 0x80002064: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80002068: and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // 0x8000206C: beq         $v0, $zero, L_80002118
    if (ctx->r2 == 0) {
        // 0x80002070: xori        $v0, $v1, 0x3
        ctx->r2 = ctx->r3 ^ 0X3;
            goto L_80002118;
    }
    // 0x80002070: xori        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 ^ 0X3;
    // 0x80002074: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x80002078: beq         $v0, $zero, L_800020F0
    if (ctx->r2 == 0) {
        // 0x8000207C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800020F0;
    }
    // 0x8000207C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80002080: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80002084: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80002088: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000208C: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80002090: bne         $v0, $zero, L_80002124
    if (ctx->r2 != 0) {
        // 0x80002094: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80002124;
    }
    // 0x80002094: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80002098: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000209C: sb          $v1, 0x2077($at)
    MEM_B(0X2077, ctx->r1) = ctx->r3;
    // 0x800020A0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800020A4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800020A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800020AC: sb          $v1, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r3;
    // 0x800020B0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800020B4: sb          $zero, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = 0;
    // 0x800020B8: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800020BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800020C0: sb          $v1, 0x7B83($at)
    MEM_B(0X7B83, ctx->r1) = ctx->r3;
    // 0x800020C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800020C8: sb          $zero, -0x75C1($at)
    MEM_B(-0X75C1, ctx->r1) = 0;
    // 0x800020CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800020D0: swc1        $f0, -0x75BC($at)
    MEM_W(-0X75BC, ctx->r1) = ctx->f0.u32l;
    // 0x800020D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800020D8: sw          $v0, 0x7BB8($at)
    MEM_W(0X7BB8, ctx->r1) = ctx->r2;
    // 0x800020DC: lbu         $a1, 0x4($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X4);
    // 0x800020E0: jal         0x8000637C
    // 0x800020E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x800020E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800020E8: j           L_80002124
    // 0x800020EC: nop

        goto L_80002124;
    // 0x800020EC: nop

L_800020F0:
    // 0x800020F0: lbu         $v0, 0x16($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X16);
    // 0x800020F4: bne         $v0, $zero, L_8000211C
    if (ctx->r2 != 0) {
        // 0x800020F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000211C;
    }
    // 0x800020F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800020FC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80002100: jal         0x800039B0
    // 0x80002104: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    func_800039B0(rdram, ctx);
        goto after_1;
    // 0x80002104: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    after_1:
    // 0x80002108: jal         0x80003A14
    // 0x8000210C: nop

    func_80003A14(rdram, ctx);
        goto after_2;
    // 0x8000210C: nop

    after_2:
    // 0x80002110: j           L_80002124
    // 0x80002114: nop

        goto L_80002124;
    // 0x80002114: nop

L_80002118:
    // 0x80002118: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000211C:
    // 0x8000211C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80002120: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80002124:
    // 0x80002124: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80002128: jr          $ra
    // 0x8000212C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000212C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80002130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002130: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80002134: sb          $a2, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r6;
    // 0x80002138: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000213C: lbu         $v0, 0x7B7E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7E);
    // 0x80002140: bne         $v0, $zero, L_800021F4
    if (ctx->r2 != 0) {
        // 0x80002144: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800021F4;
    }
    // 0x80002144: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002148: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8000214C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80002150: lbu         $a1, 0x2071($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2071);
    // 0x80002154: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80002158: and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // 0x8000215C: bne         $v0, $zero, L_800021E8
    if (ctx->r2 != 0) {
        // 0x80002160: xori        $v0, $v1, 0x3
        ctx->r2 = ctx->r3 ^ 0X3;
            goto L_800021E8;
    }
    // 0x80002160: xori        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 ^ 0X3;
    // 0x80002164: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002168: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000216C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002170: beq         $v1, $v0, L_800021F4
    if (ctx->r3 == ctx->r2) {
        // 0x80002174: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800021F4;
    }
    // 0x80002174: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002178: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000217C: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80002180: bne         $v0, $zero, L_800021F4
    if (ctx->r2 != 0) {
        // 0x80002184: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800021F4;
    }
    // 0x80002184: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002188: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000218C: lbu         $v0, 0x207A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207A);
    // 0x80002190: bne         $v0, $zero, L_800021A0
    if (ctx->r2 != 0) {
        // 0x80002194: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_800021A0;
    }
    // 0x80002194: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80002198: j           L_800021F4
    // 0x8000219C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800021F4;
    // 0x8000219C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800021A0:
    // 0x800021A0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800021A4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800021A8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x800021AC: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x800021B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800021B4: sb          $zero, 0x2084($at)
    MEM_B(0X2084, ctx->r1) = 0;
    // 0x800021B8: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x800021BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800021C0: sb          $a2, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r6;
    // 0x800021C4: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x800021C8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800021CC: lbu         $v1, 0x7B8E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8E);
    // 0x800021D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800021D4: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800021D8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800021DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800021E0: j           L_800021FC
    // 0x800021E4: sb          $v1, 0x7B8E($at)
    MEM_B(0X7B8E, ctx->r1) = ctx->r3;
        goto L_800021FC;
    // 0x800021E4: sb          $v1, 0x7B8E($at)
    MEM_B(0X7B8E, ctx->r1) = ctx->r3;
L_800021E8:
    // 0x800021E8: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x800021EC: beq         $v0, $zero, L_800021FC
    if (ctx->r2 == 0) {
        // 0x800021F0: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800021FC;
    }
    // 0x800021F0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800021F4:
    // 0x800021F4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800021F8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800021FC:
    // 0x800021FC: jr          $ra
    // 0x80002200: nop

    return;
    // 0x80002200: nop

;}
RECOMP_FUNC void func_80002204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002204: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80002208: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8000220C: sb          $a2, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r6;
    // 0x80002210: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80002214: lbu         $a1, 0x2071($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2071);
    // 0x80002218: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8000221C: and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // 0x80002220: bne         $v0, $zero, L_80002284
    if (ctx->r2 != 0) {
        // 0x80002224: xori        $v0, $v1, 0x3
        ctx->r2 = ctx->r3 ^ 0X3;
            goto L_80002284;
    }
    // 0x80002224: xori        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 ^ 0X3;
    // 0x80002228: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000222C: lbu         $v0, 0x207A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207A);
    // 0x80002230: beq         $v0, $zero, L_8000227C
    if (ctx->r2 == 0) {
        // 0x80002234: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000227C;
    }
    // 0x80002234: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002238: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8000223C: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80002240: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002244: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80002248: beq         $v0, $zero, L_80002258
    if (ctx->r2 == 0) {
        // 0x8000224C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002258;
    }
    // 0x8000224C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002250: j           L_8000225C
    // 0x80002254: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
        goto L_8000225C;
    // 0x80002254: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
L_80002258:
    // 0x80002258: sb          $v0, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r2;
L_8000225C:
    // 0x8000225C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80002260: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002264: sb          $zero, 0x2084($at)
    MEM_B(0X2084, ctx->r1) = 0;
    // 0x80002268: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x8000226C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80002270: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002274: j           L_800022F4
    // 0x80002278: sb          $v0, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r2;
        goto L_800022F4;
    // 0x80002278: sb          $v0, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r2;
L_8000227C:
    // 0x8000227C: j           L_800022EC
    // 0x80002280: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800022EC;
    // 0x80002280: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80002284:
    // 0x80002284: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x80002288: bne         $v0, $zero, L_800022F4
    if (ctx->r2 != 0) {
        // 0x8000228C: nop
    
            goto L_800022F4;
    }
    // 0x8000228C: nop

    // 0x80002290: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002294: lbu         $v0, 0x207A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207A);
    // 0x80002298: beq         $v0, $zero, L_800022D8
    if (ctx->r2 == 0) {
        // 0x8000229C: nop
    
            goto L_800022D8;
    }
    // 0x8000229C: nop

    // 0x800022A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800022A4: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x800022A8: beq         $v0, $zero, L_800022D8
    if (ctx->r2 == 0) {
        // 0x800022AC: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_800022D8;
    }
    // 0x800022AC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800022B0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800022B4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800022B8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x800022BC: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x800022C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800022C4: sb          $zero, 0x2084($at)
    MEM_B(0X2084, ctx->r1) = 0;
    // 0x800022C8: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x800022CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800022D0: j           L_800022F4
    // 0x800022D4: sb          $a2, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r6;
        goto L_800022F4;
    // 0x800022D4: sb          $a2, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r6;
L_800022D8:
    // 0x800022D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800022DC: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x800022E0: bne         $v0, $zero, L_800022EC
    if (ctx->r2 != 0) {
        // 0x800022E4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800022EC;
    }
    // 0x800022E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800022E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800022EC:
    // 0x800022EC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800022F0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800022F4:
    // 0x800022F4: jr          $ra
    // 0x800022F8: nop

    return;
    // 0x800022F8: nop

;}
RECOMP_FUNC void func_800022FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800022FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002300: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002304: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80002308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000230C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002310: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002314: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80002318: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000231C: lbu         $v1, 0x7B7E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B7E);
    // 0x80002320: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002324: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002328: beq         $v1, $zero, L_80002340
    if (ctx->r3 == 0) {
        // 0x8000232C: sb          $v0, 0x2073($at)
        MEM_B(0X2073, ctx->r1) = ctx->r2;
            goto L_80002340;
    }
    // 0x8000232C: sb          $v0, 0x2073($at)
    MEM_B(0X2073, ctx->r1) = ctx->r2;
    // 0x80002330: jal         0x800033BC
    // 0x80002334: nop

    func_800033BC(rdram, ctx);
        goto after_0;
    // 0x80002334: nop

    after_0:
    // 0x80002338: j           L_8000275C
    // 0x8000233C: nop

        goto L_8000275C;
    // 0x8000233C: nop

L_80002340:
    // 0x80002340: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002344: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80002348: bne         $v0, $zero, L_8000238C
    if (ctx->r2 != 0) {
        // 0x8000234C: nop
    
            goto L_8000238C;
    }
    // 0x8000234C: nop

    // 0x80002350: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002354: lbu         $v0, 0x207E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207E);
    // 0x80002358: bne         $v0, $zero, L_8000238C
    if (ctx->r2 != 0) {
        // 0x8000235C: nop
    
            goto L_8000238C;
    }
    // 0x8000235C: nop

    // 0x80002360: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80002364: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002368: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x8000236C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002370: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80002374: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80002378: beq         $v1, $zero, L_8000238C
    if (ctx->r3 == 0) {
        // 0x8000237C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8000238C;
    }
    // 0x8000237C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80002380: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80002384: j           L_8000275C
    // 0x80002388: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_8000275C;
    // 0x80002388: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_8000238C:
    // 0x8000238C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002390: lbu         $v0, 0x7B8D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8D);
    // 0x80002394: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80002398: lbu         $a3, 0x7B8E($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7B8E);
    // 0x8000239C: lbu         $a1, 0x4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4);
    // 0x800023A0: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x800023A4: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800023A8: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800023AC: beq         $v0, $zero, L_800023CC
    if (ctx->r2 == 0) {
        // 0x800023B0: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800023CC;
    }
    // 0x800023B0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800023B4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800023B8: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800023BC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800023C0: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x800023C4: j           L_8000275C
    // 0x800023C8: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
        goto L_8000275C;
    // 0x800023C8: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
L_800023CC:
    // 0x800023CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800023D0: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x800023D4: beq         $v0, $zero, L_80002420
    if (ctx->r2 == 0) {
        // 0x800023D8: xori        $v0, $a0, 0x3
        ctx->r2 = ctx->r4 ^ 0X3;
            goto L_80002420;
    }
    // 0x800023D8: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x800023DC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800023E0: addiu       $a2, $a2, 0x2071
    ctx->r6 = ADD32(ctx->r6, 0X2071);
    // 0x800023E4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800023E8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800023EC: beq         $v0, $zero, L_80002420
    if (ctx->r2 == 0) {
        // 0x800023F0: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80002420;
    }
    // 0x800023F0: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800023F4: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // 0x800023F8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x800023FC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80002400: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002404: and         $v0, $a3, $v0
    ctx->r2 = ctx->r7 & ctx->r2;
    // 0x80002408: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000240C: sb          $v0, 0x7B8E($at)
    MEM_B(0X7B8E, ctx->r1) = ctx->r2;
    // 0x80002410: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80002414: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80002418: j           L_80002518
    // 0x8000241C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80002518;
    // 0x8000241C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80002420:
    // 0x80002420: jal         0x80003558
    // 0x80002424: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80003558(rdram, ctx);
        goto after_1;
    // 0x80002424: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80002428: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000242C: lbu         $v1, 0x2070($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2070);
    // 0x80002430: bne         $v1, $zero, L_80002450
    if (ctx->r3 != 0) {
        // 0x80002434: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_80002450;
    }
    // 0x80002434: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80002438: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x8000243C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002440: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002444: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x80002448: beq         $v0, $zero, L_80002524
    if (ctx->r2 == 0) {
        // 0x8000244C: nop
    
            goto L_80002524;
    }
    // 0x8000244C: nop

L_80002450:
    // 0x80002450: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002454: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80002458: beq         $v0, $zero, L_80002478
    if (ctx->r2 == 0) {
        // 0x8000245C: nop
    
            goto L_80002478;
    }
    // 0x8000245C: nop

    // 0x80002460: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80002464: bne         $v0, $zero, L_80002478
    if (ctx->r2 != 0) {
        // 0x80002468: nop
    
            goto L_80002478;
    }
    // 0x80002468: nop

    // 0x8000246C: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x80002470: beq         $v0, $zero, L_80002524
    if (ctx->r2 == 0) {
        // 0x80002474: nop
    
            goto L_80002524;
    }
    // 0x80002474: nop

L_80002478:
    // 0x80002478: jal         0x80003A7C
    // 0x8000247C: nop

    func_80003A7C(rdram, ctx);
        goto after_2;
    // 0x8000247C: nop

    after_2:
    // 0x80002480: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80002484: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80002488: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000248C: and         $v1, $s1, $v1
    ctx->r3 = ctx->r17 & ctx->r3;
    // 0x80002490: beq         $v1, $zero, L_80002524
    if (ctx->r3 == 0) {
        // 0x80002494: nop
    
            goto L_80002524;
    }
    // 0x80002494: nop

    // 0x80002498: jal         0x80006708
    // 0x8000249C: nop

    func_80006708(rdram, ctx);
        goto after_3;
    // 0x8000249C: nop

    after_3:
    // 0x800024A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x800024A4: jal         0x8000637C
    // 0x800024A8: sra         $a1, $s1, 1
    ctx->r5 = S32(SIGNED(ctx->r17) >> 1);
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x800024A8: sra         $a1, $s1, 1
    ctx->r5 = S32(SIGNED(ctx->r17) >> 1);
    after_4:
    // 0x800024AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800024B0: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x800024B4: bne         $v0, $zero, L_800024D8
    if (ctx->r2 != 0) {
        // 0x800024B8: sll         $v1, $s2, 2
        ctx->r3 = S32(ctx->r18 << 2);
            goto L_800024D8;
    }
    // 0x800024B8: sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18 << 2);
    // 0x800024BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800024C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800024C4: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x800024C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800024CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800024D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800024D4: sb          $v0, 0x7B38($at)
    MEM_B(0X7B38, ctx->r1) = ctx->r2;
L_800024D8:
    // 0x800024D8: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800024DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800024E0: lbu         $v1, 0x2071($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2071);
    // 0x800024E4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800024E8: addiu       $a0, $a0, 0x7B8E
    ctx->r4 = ADD32(ctx->r4, 0X7B8E);
    // 0x800024EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800024F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800024F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800024F8: sb          $v1, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r3;
    // 0x800024FC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80002500: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002504: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002508: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8000250C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002510: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80002514: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80002518:
    // 0x80002518: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8000251C: j           L_8000275C
    // 0x80002520: sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
        goto L_8000275C;
    // 0x80002520: sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
L_80002524:
    // 0x80002524: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x80002528: beq         $v1, $zero, L_80002540
    if (ctx->r3 == 0) {
        // 0x8000252C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002540;
    }
    // 0x8000252C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002530: beq         $v1, $v0, L_80002574
    if (ctx->r3 == ctx->r2) {
        // 0x80002534: sll         $a0, $s2, 2
        ctx->r4 = S32(ctx->r18 << 2);
            goto L_80002574;
    }
    // 0x80002534: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x80002538: j           L_8000275C
    // 0x8000253C: nop

        goto L_8000275C;
    // 0x8000253C: nop

L_80002540:
    // 0x80002540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002544: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80002548: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8000254C: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80002550: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80002554: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002558: sb          $v0, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r2;
    // 0x8000255C: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x80002560: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80002564: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002568: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x8000256C: j           L_8000275C
    // 0x80002570: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
        goto L_8000275C;
    // 0x80002570: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
L_80002574:
    // 0x80002574: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002578: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000257C: lbu         $v1, 0x7B38($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B38);
    // 0x80002580: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002584: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80002588: lbu         $a0, 0x7B3A($at)
    ctx->r4 = MEM_BU(ctx->r1, 0X7B3A);
    // 0x8000258C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80002590: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002594: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x80002598: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000259C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800025A0: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800025A4: beq         $v1, $zero, L_800025FC
    if (ctx->r3 == 0) {
        // 0x800025A8: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800025FC;
    }
    // 0x800025A8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800025AC: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x800025B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800025B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800025B8: sb          $v0, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r2;
    // 0x800025BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800025C0: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800025C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800025C8: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x800025CC: beq         $v0, $zero, L_80002600
    if (ctx->r2 == 0) {
        // 0x800025D0: sll         $a0, $s2, 2
        ctx->r4 = S32(ctx->r18 << 2);
            goto L_80002600;
    }
    // 0x800025D0: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x800025D4: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800025D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800025DC: sh          $v0, -0x755E($at)
    MEM_H(-0X755E, ctx->r1) = ctx->r2;
    // 0x800025E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800025E4: sh          $v0, -0x757A($at)
    MEM_H(-0X757A, ctx->r1) = ctx->r2;
    // 0x800025E8: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x800025EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800025F0: sh          $v0, -0x755C($at)
    MEM_H(-0X755C, ctx->r1) = ctx->r2;
    // 0x800025F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800025F8: sh          $v0, -0x7578($at)
    MEM_H(-0X7578, ctx->r1) = ctx->r2;
L_800025FC:
    // 0x800025FC: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
L_80002600:
    // 0x80002600: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002604: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80002608: lbu         $v1, 0x7B38($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B38);
    // 0x8000260C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80002610: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002614: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002618: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000261C: lbu         $v1, 0x7B3A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B3A);
    // 0x80002620: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    // 0x80002624: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80002628: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000262C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80002630: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80002634: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x80002638: sb          $v1, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r3;
    // 0x8000263C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80002640: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80002644: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x80002648: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8000264C: beq         $v0, $zero, L_80002658
    if (ctx->r2 == 0) {
        // 0x80002650: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80002658;
    }
    // 0x80002650: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80002654: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002658:
    // 0x80002658: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000265C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80002660: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80002664: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80002668: beq         $v0, $zero, L_80002674
    if (ctx->r2 == 0) {
        // 0x8000266C: nop
    
            goto L_80002674;
    }
    // 0x8000266C: nop

    // 0x80002670: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
L_80002674:
    // 0x80002674: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80002678: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8000267C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80002680: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002684: bgtz        $v0, L_8000275C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80002688: nop
    
            goto L_8000275C;
    }
    // 0x80002688: nop

    // 0x8000268C: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80002690: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002694: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80002698: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000269C: bltz        $v0, L_800026CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800026A0: sh          $v1, 0x6($s0)
        MEM_H(0X6, ctx->r16) = ctx->r3;
            goto L_800026CC;
    }
    // 0x800026A0: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x800026A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800026A8: sb          $v1, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r3;
    // 0x800026AC: lbu         $a1, 0x4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4);
    // 0x800026B0: jal         0x8000637C
    // 0x800026B4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_8000637C(rdram, ctx);
        goto after_5;
    // 0x800026B4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_5:
    // 0x800026B8: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x800026BC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800026C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800026C4: j           L_8000272C
    // 0x800026C8: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
        goto L_8000272C;
    // 0x800026C8: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
L_800026CC:
    // 0x800026CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800026D0: addiu       $v1, $v1, 0x7B89
    ctx->r3 = ADD32(ctx->r3, 0X7B89);
    // 0x800026D4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800026D8: beq         $v0, $zero, L_80002704
    if (ctx->r2 == 0) {
        // 0x800026DC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002704;
    }
    // 0x800026DC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800026E0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800026E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800026E8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800026EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800026F0: sb          $v0, 0x2084($at)
    MEM_B(0X2084, ctx->r1) = ctx->r2;
    // 0x800026F4: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800026F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800026FC: j           L_80002734
    // 0x80002700: sb          $zero, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = 0;
        goto L_80002734;
    // 0x80002700: sb          $zero, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = 0;
L_80002704:
    // 0x80002704: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002708: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8000270C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002710: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80002714: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002718: sb          $v0, 0x2084($at)
    MEM_B(0X2084, ctx->r1) = ctx->r2;
    // 0x8000271C: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80002720: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80002724: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002728: sb          $zero, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = 0;
L_8000272C:
    // 0x8000272C: beq         $v0, $zero, L_8000275C
    if (ctx->r2 == 0) {
        // 0x80002730: nop
    
            goto L_8000275C;
    }
    // 0x80002730: nop

L_80002734:
    // 0x80002734: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80002738: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000273C: sh          $v0, -0x755E($at)
    MEM_H(-0X755E, ctx->r1) = ctx->r2;
    // 0x80002740: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80002744: sh          $v0, -0x757A($at)
    MEM_H(-0X757A, ctx->r1) = ctx->r2;
    // 0x80002748: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8000274C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80002750: sh          $v0, -0x755C($at)
    MEM_H(-0X755C, ctx->r1) = ctx->r2;
    // 0x80002754: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80002758: sh          $v0, -0x7578($at)
    MEM_H(-0X7578, ctx->r1) = ctx->r2;
L_8000275C:
    // 0x8000275C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002760: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002764: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002768: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000276C: jr          $ra
    // 0x80002770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
