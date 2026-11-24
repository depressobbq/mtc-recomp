#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80002774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002774: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80002778: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000277C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80002780: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80002784: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80002788: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8000278C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80002790: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80002794: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80002798: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000279C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800027A0: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x800027A4: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x800027A8: addiu       $s4, $s4, 0x79F0
    ctx->r20 = ADD32(ctx->r20, 0X79F0);
    // 0x800027AC: bne         $v0, $zero, L_800027BC
    if (ctx->r2 != 0) {
        // 0x800027B0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800027BC;
    }
    // 0x800027B0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800027B4: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x800027B8: addiu       $s4, $s4, 0x25A0
    ctx->r20 = ADD32(ctx->r20, 0X25A0);
L_800027BC:
    // 0x800027BC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800027C0: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x800027C4: bne         $v1, $zero, L_800027E8
    if (ctx->r3 != 0) {
        // 0x800027C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800027E8;
    }
    // 0x800027C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800027CC: lb          $v1, 0x5A($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X5A);
    // 0x800027D0: beq         $v1, $zero, L_8000280C
    if (ctx->r3 == 0) {
        // 0x800027D4: nop
    
            goto L_8000280C;
    }
    // 0x800027D4: nop

    // 0x800027D8: beql        $v1, $v0, L_8000280C
    if (ctx->r3 == ctx->r2) {
        // 0x800027DC: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_8000280C;
    }
    goto skip_0;
    // 0x800027DC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    skip_0:
    // 0x800027E0: j           L_8000280C
    // 0x800027E4: nop

        goto L_8000280C;
    // 0x800027E4: nop

L_800027E8:
    // 0x800027E8: bne         $v1, $v0, L_8000280C
    if (ctx->r3 != ctx->r2) {
        // 0x800027EC: nop
    
            goto L_8000280C;
    }
    // 0x800027EC: nop

    // 0x800027F0: lb          $v1, 0x5A($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X5A);
    // 0x800027F4: bne         $v1, $zero, L_80002804
    if (ctx->r3 != 0) {
        // 0x800027F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80002804;
    }
    // 0x800027F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800027FC: j           L_8000280C
    // 0x80002800: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
        goto L_8000280C;
    // 0x80002800: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80002804:
    // 0x80002804: beql        $v1, $v0, L_8000280C
    if (ctx->r3 == ctx->r2) {
        // 0x80002808: addiu       $s2, $zero, 0x2
        ctx->r18 = ADD32(0, 0X2);
            goto L_8000280C;
    }
    goto skip_1;
    // 0x80002808: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    skip_1:
L_8000280C:
    // 0x8000280C: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80002810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002814: beq         $v1, $v0, L_80002AC8
    if (ctx->r3 == ctx->r2) {
        // 0x80002818: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80002AC8;
    }
    // 0x80002818: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000281C: beql        $v0, $zero, L_80002834
    if (ctx->r2 == 0) {
        // 0x80002820: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80002834;
    }
    goto skip_2;
    // 0x80002820: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_2:
    // 0x80002824: beq         $v1, $zero, L_80002844
    if (ctx->r3 == 0) {
        // 0x80002828: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_80002844;
    }
    // 0x80002828: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8000282C: j           L_80002F10
    // 0x80002830: nop

        goto L_80002F10;
    // 0x80002830: nop

L_80002834:
    // 0x80002834: beq         $v1, $v0, L_80002E50
    if (ctx->r3 == ctx->r2) {
        // 0x80002838: nop
    
            goto L_80002E50;
    }
    // 0x80002838: nop

    // 0x8000283C: j           L_80002F10
    // 0x80002840: nop

        goto L_80002F10;
    // 0x80002840: nop

L_80002844:
    // 0x80002844: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80002848: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8000284C: sll         $s3, $v0, 5
    ctx->r19 = S32(ctx->r2 << 5);
    // 0x80002850: lui         $s7, 0x801D
    ctx->r23 = S32(0X801D << 16);
    // 0x80002854: addiu       $s7, $s7, 0xB90
    ctx->r23 = ADD32(ctx->r23, 0XB90);
    // 0x80002858: addiu       $v0, $s7, -0x10
    ctx->r2 = ADD32(ctx->r23, -0X10);
    // 0x8000285C: addu        $s6, $s3, $v0
    ctx->r22 = ADD32(ctx->r19, ctx->r2);
    // 0x80002860: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_80002864:
    // 0x80002864: lw          $v1, 0x104($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X104);
    // 0x80002868: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000286C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80002870: lw          $v0, 0xB98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB98);
    // 0x80002874: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80002878: beq         $v0, $zero, L_80002A40
    if (ctx->r2 == 0) {
        // 0x8000287C: slti        $v0, $s5, 0x9
        ctx->r2 = SIGNED(ctx->r21) < 0X9 ? 1 : 0;
            goto L_80002A40;
    }
    // 0x8000287C: slti        $v0, $s5, 0x9
    ctx->r2 = SIGNED(ctx->r21) < 0X9 ? 1 : 0;
    // 0x80002880: beq         $v0, $zero, L_80002954
    if (ctx->r2 == 0) {
        // 0x80002884: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80002954;
    }
    // 0x80002884: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80002888: addiu       $s0, $a0, -0x1
    ctx->r16 = ADD32(ctx->r4, -0X1);
L_8000288C:
    // 0x8000288C: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x80002890: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80002894: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002898: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000289C: lbu         $v0, 0xB90($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB90);
    // 0x800028A0: sll         $a1, $a0, 4
    ctx->r5 = S32(ctx->r4 << 4);
    // 0x800028A4: addu        $a2, $a1, $s3
    ctx->r6 = ADD32(ctx->r5, ctx->r19);
    // 0x800028A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800028AC: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800028B0: sb          $v0, 0xB90($at)
    MEM_B(0XB90, ctx->r1) = ctx->r2;
    // 0x800028B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800028B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800028BC: lbu         $v0, 0xB91($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB91);
    // 0x800028C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800028C4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800028C8: sb          $v0, 0xB91($at)
    MEM_B(0XB91, ctx->r1) = ctx->r2;
    // 0x800028CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800028D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800028D4: lbu         $v0, 0xB92($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB92);
    // 0x800028D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800028DC: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800028E0: sb          $v0, 0xB92($at)
    MEM_B(0XB92, ctx->r1) = ctx->r2;
    // 0x800028E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800028E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800028EC: lbu         $v0, 0xB93($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB93);
    // 0x800028F0: addu        $a0, $a1, $s7
    ctx->r4 = ADD32(ctx->r5, ctx->r23);
    // 0x800028F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800028F8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800028FC: sb          $v0, 0xB93($at)
    MEM_B(0XB93, ctx->r1) = ctx->r2;
    // 0x80002900: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002904: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002908: lbu         $v0, 0xB94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB94);
    // 0x8000290C: addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // 0x80002910: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80002914: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002918: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8000291C: sb          $v0, 0xB94($at)
    MEM_B(0XB94, ctx->r1) = ctx->r2;
    // 0x80002920: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002924: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002928: lw          $v0, 0xB98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB98);
    // 0x8000292C: addu        $a1, $s6, $a1
    ctx->r5 = ADD32(ctx->r22, ctx->r5);
    // 0x80002930: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002934: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80002938: sw          $v0, 0xB98($at)
    MEM_W(0XB98, ctx->r1) = ctx->r2;
    // 0x8000293C: jal         0x8006D000
    // 0x80002940: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8006D000(rdram, ctx);
        goto after_0;
    // 0x80002940: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80002944: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002948: slt         $v0, $s5, $a0
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000294C: bne         $v0, $zero, L_8000288C
    if (ctx->r2 != 0) {
        // 0x80002950: addiu       $s0, $a0, -0x1
        ctx->r16 = ADD32(ctx->r4, -0X1);
            goto L_8000288C;
    }
    // 0x80002950: addiu       $s0, $a0, -0x1
    ctx->r16 = ADD32(ctx->r4, -0X1);
L_80002954:
    // 0x80002954: jal         0x80011288
    // 0x80002958: nop

    func_80011288(rdram, ctx);
        goto after_1;
    // 0x80002958: nop

    after_1:
    // 0x8000295C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002960: lbu         $v0, 0x7B68($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B68);
    // 0x80002964: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002968: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x8000296C: sb          $v0, 0xB90($at)
    MEM_B(0XB90, ctx->r1) = ctx->r2;
    // 0x80002970: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002974: lbu         $v0, 0x7B69($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B69);
    // 0x80002978: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000297C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80002980: sb          $v0, 0xB91($at)
    MEM_B(0XB91, ctx->r1) = ctx->r2;
    // 0x80002984: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002988: lbu         $v0, 0x7B6A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B6A);
    // 0x8000298C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002990: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80002994: sb          $v0, 0xB92($at)
    MEM_B(0XB92, ctx->r1) = ctx->r2;
    // 0x80002998: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000299C: lbu         $v0, 0x7B6B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B6B);
    // 0x800029A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800029A4: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800029A8: sb          $v0, 0xB93($at)
    MEM_B(0XB93, ctx->r1) = ctx->r2;
    // 0x800029AC: lbu         $v0, 0x75($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X75);
    // 0x800029B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800029B4: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800029B8: sb          $v0, 0xB94($at)
    MEM_B(0XB94, ctx->r1) = ctx->r2;
    // 0x800029BC: lw          $v0, 0x104($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X104);
    // 0x800029C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800029C4: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800029C8: sw          $v0, 0xB98($at)
    MEM_W(0XB98, ctx->r1) = ctx->r2;
    // 0x800029CC: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x800029D0: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x800029D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800029D8: sb          $v0, 0x7BA0($at)
    MEM_B(0X7BA0, ctx->r1) = ctx->r2;
    // 0x800029DC: lb          $v1, 0x5A($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X5A);
    // 0x800029E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800029E4: bne         $v1, $v0, L_80002A54
    if (ctx->r3 != ctx->r2) {
        // 0x800029E8: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80002A54;
    }
    // 0x800029E8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800029EC: lhu         $v1, 0x7E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X7E);
    // 0x800029F0: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x800029F4: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x800029F8: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800029FC: lbu         $v0, 0x74($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X74);
    // 0x80002A00: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80002A04: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80002A08: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80002A0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002A10: mfhi        $a3
    ctx->r7 = hi;
    // 0x80002A14: srl         $a0, $a3, 3
    ctx->r4 = S32(U32(ctx->r7) >> 3);
    // 0x80002A18: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80002A1C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80002A20: slti        $v0, $a0, 0x64
    ctx->r2 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x80002A24: beql        $v0, $zero, L_80002A2C
    if (ctx->r2 == 0) {
        // 0x80002A28: addiu       $a0, $zero, 0x63
        ctx->r4 = ADD32(0, 0X63);
            goto L_80002A2C;
    }
    goto skip_3;
    // 0x80002A28: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    skip_3:
L_80002A2C:
    // 0x80002A2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002A30: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80002A34: sb          $a0, 0xB91($at)
    MEM_B(0XB91, ctx->r1) = ctx->r4;
    // 0x80002A38: j           L_80002A54
    // 0x80002A3C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80002A54;
    // 0x80002A3C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80002A40:
    // 0x80002A40: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80002A44: slti        $v0, $s5, 0xA
    ctx->r2 = SIGNED(ctx->r21) < 0XA ? 1 : 0;
    // 0x80002A48: bne         $v0, $zero, L_80002864
    if (ctx->r2 != 0) {
        // 0x80002A4C: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80002864;
    }
    // 0x80002A4C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80002A50: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80002A54:
    // 0x80002A54: beq         $s5, $v0, L_80002AA4
    if (ctx->r21 == ctx->r2) {
        // 0x80002A58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002AA4;
    }
    // 0x80002A58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002A5C: addiu       $v1, $zero, 0xE10
    ctx->r3 = ADD32(0, 0XE10);
    // 0x80002A60: sh          $v1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r3;
    // 0x80002A64: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80002A68: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80002A6C: sb          $zero, 0x15($s1)
    MEM_B(0X15, ctx->r17) = 0;
    // 0x80002A70: sb          $zero, 0xC($s1)
    MEM_B(0XC, ctx->r17) = 0;
    // 0x80002A74: sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
    // 0x80002A78: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
    // 0x80002A7C: sb          $zero, 0x11($s1)
    MEM_B(0X11, ctx->r17) = 0;
    // 0x80002A80: sb          $zero, 0x10($s1)
    MEM_B(0X10, ctx->r17) = 0;
    // 0x80002A84: sb          $v1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r3;
    // 0x80002A88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80002A8C: sw          $zero, 0x17C4($at)
    MEM_W(0X17C4, ctx->r1) = 0;
    // 0x80002A90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80002A94: sw          $zero, 0x17C0($at)
    MEM_W(0X17C0, ctx->r1) = 0;
    // 0x80002A98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002A9C: j           L_80002F10
    // 0x80002AA0: sb          $v0, 0x7B94($at)
    MEM_B(0X7B94, ctx->r1) = ctx->r2;
        goto L_80002F10;
    // 0x80002AA0: sb          $v0, 0x7B94($at)
    MEM_B(0X7B94, ctx->r1) = ctx->r2;
L_80002AA4:
    // 0x80002AA4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002AA8: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80002AAC: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002AB0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80002AB4: addiu       $a0, $a0, 0x7B8E
    ctx->r4 = ADD32(ctx->r4, 0X7B8E);
    // 0x80002AB8: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x80002ABC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002AC0: j           L_80002F08
    // 0x80002AC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80002F08;
    // 0x80002AC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80002AC8:
    // 0x80002AC8: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002ACC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002AD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002AD4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002AD8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80002ADC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002AE0: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x80002AE4: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x80002AE8: beq         $v0, $zero, L_80002B08
    if (ctx->r2 == 0) {
        // 0x80002AEC: nop
    
            goto L_80002B08;
    }
    // 0x80002AEC: nop

    // 0x80002AF0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80002AF4: lw          $v0, 0x17C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X17C0);
    // 0x80002AF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002AFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80002B00: j           L_80002B10
    // 0x80002B04: sw          $v0, 0x17C0($at)
    MEM_W(0X17C0, ctx->r1) = ctx->r2;
        goto L_80002B10;
    // 0x80002B04: sw          $v0, 0x17C0($at)
    MEM_W(0X17C0, ctx->r1) = ctx->r2;
L_80002B08:
    // 0x80002B08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80002B0C: sw          $zero, 0x17C0($at)
    MEM_W(0X17C0, ctx->r1) = 0;
L_80002B10:
    // 0x80002B10: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80002B14: lw          $v1, 0x17C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X17C0);
    // 0x80002B18: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80002B1C: bne         $v0, $zero, L_80002B4C
    if (ctx->r2 != 0) {
        // 0x80002B20: andi        $v0, $v1, 0x7
        ctx->r2 = ctx->r3 & 0X7;
            goto L_80002B4C;
    }
    // 0x80002B20: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x80002B24: bne         $v0, $zero, L_80002B4C
    if (ctx->r2 != 0) {
        // 0x80002B28: nop
    
            goto L_80002B4C;
    }
    // 0x80002B28: nop

    // 0x80002B2C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002B30: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002B34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002B38: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002B3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80002B40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002B44: j           L_80002B68
    // 0x80002B48: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
        goto L_80002B68;
    // 0x80002B48: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
L_80002B4C:
    // 0x80002B4C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002B50: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002B54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002B58: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002B5C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002B60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002B64: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
L_80002B68:
    // 0x80002B68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80002B6C: sh          $v0, 0x17C8($at)
    MEM_H(0X17C8, ctx->r1) = ctx->r2;
    // 0x80002B70: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80002B74: lhu         $v0, 0x17C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X17C8);
    // 0x80002B78: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x80002B7C: beq         $v0, $zero, L_80002BA8
    if (ctx->r2 == 0) {
        // 0x80002B80: nop
    
            goto L_80002BA8;
    }
    // 0x80002B80: nop

    // 0x80002B84: lbu         $v1, 0xC($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XC);
    // 0x80002B88: sltiu       $v0, $v1, 0x30
    ctx->r2 = ctx->r3 < 0X30 ? 1 : 0;
    // 0x80002B8C: bne         $v0, $zero, L_80002B98
    if (ctx->r2 != 0) {
        // 0x80002B90: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80002B98;
    }
    // 0x80002B90: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80002B94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002B98:
    // 0x80002B98: lbu         $a1, 0x4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X4);
    // 0x80002B9C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80002BA0: jal         0x8000637C
    // 0x80002BA4: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80002BA4: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    after_2:
L_80002BA8:
    // 0x80002BA8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80002BAC: lhu         $v0, 0x17C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X17C8);
    // 0x80002BB0: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x80002BB4: beq         $v0, $zero, L_80002BDC
    if (ctx->r2 == 0) {
        // 0x80002BB8: nop
    
            goto L_80002BDC;
    }
    // 0x80002BB8: nop

    // 0x80002BBC: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x80002BC0: bne         $v0, $zero, L_80002BCC
    if (ctx->r2 != 0) {
        // 0x80002BC4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80002BCC;
    }
    // 0x80002BC4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002BC8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80002BCC:
    // 0x80002BCC: lbu         $a1, 0x4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X4);
    // 0x80002BD0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80002BD4: jal         0x8000637C
    // 0x80002BD8: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80002BD8: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    after_3:
L_80002BDC:
    // 0x80002BDC: lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X15);
    // 0x80002BE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002BE4: bne         $v1, $v0, L_80002C14
    if (ctx->r3 != ctx->r2) {
        // 0x80002BE8: nop
    
            goto L_80002C14;
    }
    // 0x80002BE8: nop

    // 0x80002BEC: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x80002BF0: bne         $v0, $zero, L_80002BFC
    if (ctx->r2 != 0) {
        // 0x80002BF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002BFC;
    }
    // 0x80002BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002BF8: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
L_80002BFC:
    // 0x80002BFC: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x80002C00: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80002C04: beq         $v0, $zero, L_80002C10
    if (ctx->r2 == 0) {
        // 0x80002C08: addiu       $v1, $zero, 0x30
        ctx->r3 = ADD32(0, 0X30);
            goto L_80002C10;
    }
    // 0x80002C08: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x80002C0C: addiu       $v1, $zero, 0x2F
    ctx->r3 = ADD32(0, 0X2F);
L_80002C10:
    // 0x80002C10: sb          $v1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r3;
L_80002C14:
    // 0x80002C14: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002C18: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002C1C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002C20: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002C24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002C28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002C2C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80002C30: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x80002C34: beq         $v0, $zero, L_80002C68
    if (ctx->r2 == 0) {
        // 0x80002C38: nop
    
            goto L_80002C68;
    }
    // 0x80002C38: nop

    // 0x80002C3C: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002C40: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80002C44: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80002C48: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002C4C: bne         $v0, $zero, L_80002C58
    if (ctx->r2 != 0) {
        // 0x80002C50: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80002C58;
    }
    // 0x80002C50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002C54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002C58:
    // 0x80002C58: lbu         $a1, 0x4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X4);
    // 0x80002C5C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80002C60: jal         0x8000637C
    // 0x80002C64: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80002C64: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
    after_4:
L_80002C68:
    // 0x80002C68: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002C6C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002C70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002C74: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002C78: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002C7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002C80: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80002C84: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80002C88: beq         $v0, $zero, L_80002D2C
    if (ctx->r2 == 0) {
        // 0x80002C8C: addiu       $v0, $zero, 0x2F
        ctx->r2 = ADD32(0, 0X2F);
            goto L_80002D2C;
    }
    // 0x80002C8C: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x80002C90: lbu         $v1, 0xC($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XC);
    // 0x80002C94: bne         $v1, $v0, L_80002CBC
    if (ctx->r3 != ctx->r2) {
        // 0x80002C98: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_80002CBC;
    }
    // 0x80002C98: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80002C9C: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002CA0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80002CA4: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80002CA8: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002CAC: bne         $v0, $zero, L_80002D10
    if (ctx->r2 != 0) {
        // 0x80002CB0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80002D10;
    }
    // 0x80002CB0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002CB4: j           L_80002D10
    // 0x80002CB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80002D10;
    // 0x80002CB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002CBC:
    // 0x80002CBC: bne         $v1, $v0, L_80002CE0
    if (ctx->r3 != ctx->r2) {
        // 0x80002CC0: nop
    
            goto L_80002CE0;
    }
    // 0x80002CC0: nop

    // 0x80002CC4: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002CC8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80002CCC: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80002CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002CD4: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80002CD8: j           L_80002D10
    // 0x80002CDC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80002D10;
    // 0x80002CDC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80002CE0:
    // 0x80002CE0: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002CE4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002CE8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80002CEC: lbu         $v1, -0x21B0($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X21B0);
    // 0x80002CF0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80002CF4: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80002CF8: lbu         $a0, 0x15($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X15);
    // 0x80002CFC: lbu         $a1, 0x4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X4);
    // 0x80002D00: jal         0x8000637C
    // 0x80002D04: addiu       $a0, $a0, 0x2F
    ctx->r4 = ADD32(ctx->r4, 0X2F);
    func_8000637C(rdram, ctx);
        goto after_5;
    // 0x80002D04: addiu       $a0, $a0, 0x2F
    ctx->r4 = ADD32(ctx->r4, 0X2F);
    after_5:
    // 0x80002D08: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002D0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80002D10:
    // 0x80002D10: sb          $v0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r2;
    // 0x80002D14: lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X15);
    // 0x80002D18: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80002D1C: bne         $v1, $v0, L_80002D6C
    if (ctx->r3 != ctx->r2) {
        // 0x80002D20: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_80002D6C;
    }
    // 0x80002D20: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80002D24: j           L_80002D6C
    // 0x80002D28: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
        goto L_80002D6C;
    // 0x80002D28: sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
L_80002D2C:
    // 0x80002D2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002D30: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80002D34: andi        $v0, $v0, 0xC
    ctx->r2 = ctx->r2 & 0XC;
    // 0x80002D38: beq         $v0, $zero, L_80002D60
    if (ctx->r2 == 0) {
        // 0x80002D3C: addiu       $v1, $zero, 0x20
        ctx->r3 = ADD32(0, 0X20);
            goto L_80002D60;
    }
    // 0x80002D3C: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80002D40: lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC);
    // 0x80002D44: lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X15);
    // 0x80002D48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002D4C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002D50: lbu         $v0, -0x21B0($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X21B0);
    // 0x80002D54: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x80002D58: j           L_80002D6C
    // 0x80002D5C: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
        goto L_80002D6C;
    // 0x80002D5C: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
L_80002D60:
    // 0x80002D60: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002D64: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80002D68: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
L_80002D6C:
    // 0x80002D6C: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80002D70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002D74: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80002D78: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002D7C: beq         $v0, $zero, L_80002D94
    if (ctx->r2 == 0) {
        // 0x80002D80: nop
    
            goto L_80002D94;
    }
    // 0x80002D80: nop

    // 0x80002D84: lbu         $v0, 0x15($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X15);
    // 0x80002D88: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80002D8C: bne         $v0, $zero, L_80002F10
    if (ctx->r2 != 0) {
        // 0x80002D90: nop
    
            goto L_80002F10;
    }
    // 0x80002D90: nop

L_80002D94:
    // 0x80002D94: lbu         $a1, 0x4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X4);
    // 0x80002D98: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80002D9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002DA0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80002DA4: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x80002DA8: jal         0x8000637C
    // 0x80002DAC: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_6;
    // 0x80002DAC: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_6:
    // 0x80002DB0: lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X15);
    // 0x80002DB4: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80002DB8: bne         $v0, $zero, L_80002DC8
    if (ctx->r2 != 0) {
        // 0x80002DBC: addu        $v0, $s1, $v1
        ctx->r2 = ADD32(ctx->r17, ctx->r3);
            goto L_80002DC8;
    }
    // 0x80002DBC: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x80002DC0: j           L_80002DCC
    // 0x80002DC4: sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
        goto L_80002DCC;
    // 0x80002DC4: sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
L_80002DC8:
    // 0x80002DC8: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
L_80002DCC:
    // 0x80002DCC: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // 0x80002DD0: jal         0x80003578
    // 0x80002DD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80003578(rdram, ctx);
        goto after_7;
    // 0x80002DD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x80002DD8: beq         $v0, $zero, L_80002E18
    if (ctx->r2 == 0) {
        // 0x80002DDC: sll         $v0, $s2, 2
        ctx->r2 = S32(ctx->r18 << 2);
            goto L_80002E18;
    }
    // 0x80002DDC: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80002DE0: lbu         $v1, 0xD($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XD);
    // 0x80002DE4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80002DE8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80002DEC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80002DF0: addiu       $a1, $a1, -0x3880
    ctx->r5 = ADD32(ctx->r5, -0X3880);
    // 0x80002DF4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80002DF8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80002DFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002E00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002E04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002E08: sw          $a0, 0xB9C($at)
    MEM_W(0XB9C, ctx->r1) = ctx->r4;
    // 0x80002E0C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80002E10: j           L_80002F10
    // 0x80002E14: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
        goto L_80002F10;
    // 0x80002E14: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_80002E18:
    // 0x80002E18: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80002E1C: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x80002E20: lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD);
    // 0x80002E24: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80002E28: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80002E2C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002E30: addiu       $v1, $v1, 0xB90
    ctx->r3 = ADD32(ctx->r3, 0XB90);
    // 0x80002E34: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80002E38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002E3C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80002E40: jal         0x8006D000
    // 0x80002E44: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_8006D000(rdram, ctx);
        goto after_8;
    // 0x80002E44: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_8:
    // 0x80002E48: j           L_80002F10
    // 0x80002E4C: nop

        goto L_80002F10;
    // 0x80002E4C: nop

L_80002E50:
    // 0x80002E50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002E54: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80002E58: andi        $v0, $v0, 0xC
    ctx->r2 = ctx->r2 & 0XC;
    // 0x80002E5C: beq         $v0, $zero, L_80002E98
    if (ctx->r2 == 0) {
        // 0x80002E60: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_80002E98;
    }
    // 0x80002E60: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x80002E64: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x80002E68: lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD);
    // 0x80002E6C: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x80002E70: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80002E74: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002E78: addiu       $v1, $v1, 0xB90
    ctx->r3 = ADD32(ctx->r3, 0XB90);
    // 0x80002E7C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80002E80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002E84: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80002E88: jal         0x8006D000
    // 0x80002E8C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8006D000(rdram, ctx);
        goto after_9;
    // 0x80002E8C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_9:
    // 0x80002E90: j           L_80002EA4
    // 0x80002E94: nop

        goto L_80002EA4;
    // 0x80002E94: nop

L_80002E98:
    // 0x80002E98: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80002E9C: lw          $v0, -0x387C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X387C);
    // 0x80002EA0: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_80002EA4:
    // 0x80002EA4: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80002EA8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002EAC: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80002EB0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002EB4: beq         $v0, $zero, L_80002EE4
    if (ctx->r2 == 0) {
        // 0x80002EB8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002EE4;
    }
    // 0x80002EB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002EBC: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002EC0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80002EC4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002EC8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002ECC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80002ED0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002ED4: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80002ED8: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80002EDC: beq         $v0, $zero, L_80002F10
    if (ctx->r2 == 0) {
        // 0x80002EE0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002F10;
    }
    // 0x80002EE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80002EE4:
    // 0x80002EE4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80002EE8: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80002EEC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80002EF0: addiu       $a0, $a0, 0x7B8E
    ctx->r4 = ADD32(ctx->r4, 0X7B8E);
    // 0x80002EF4: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x80002EF8: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002EFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002F00: sb          $zero, 0x7B94($at)
    MEM_B(0X7B94, ctx->r1) = 0;
    // 0x80002F04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80002F08:
    // 0x80002F08: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80002F0C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_80002F10:
    // 0x80002F10: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80002F14: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80002F18: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80002F1C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80002F20: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80002F24: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80002F28: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002F2C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002F30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002F34: jr          $ra
    // 0x80002F38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80002F38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80002F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F3C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80002F40: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x80002F44: beq         $v1, $zero, L_80002F5C
    if (ctx->r3 == 0) {
        // 0x80002F48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002F5C;
    }
    // 0x80002F48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002F4C: beq         $v1, $v0, L_80002FB8
    if (ctx->r3 == ctx->r2) {
        // 0x80002F50: nop
    
            goto L_80002FB8;
    }
    // 0x80002F50: nop

    // 0x80002F54: j           L_80003018
    // 0x80002F58: nop

        goto L_80003018;
    // 0x80002F58: nop

L_80002F5C:
    // 0x80002F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002F60: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x80002F64: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x80002F68: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x80002F6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002F70: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x80002F74: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x80002F78: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80002F7C: addiu       $a0, $a0, 0x2071
    ctx->r4 = ADD32(ctx->r4, 0X2071);
    // 0x80002F80: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002F88: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80002F8C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80002F90: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80002F94: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x80002F98: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80002F9C: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x80002FA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002FA4: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80002FA8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80002FAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80002FB0: j           L_80003018
    // 0x80002FB4: sb          $v1, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r3;
        goto L_80003018;
    // 0x80002FB4: sb          $v1, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r3;
L_80002FB8:
    // 0x80002FB8: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80002FBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80002FC0: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x80002FC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80002FC8: bne         $v0, $zero, L_80003018
    if (ctx->r2 != 0) {
        // 0x80002FCC: nop
    
            goto L_80003018;
    }
    // 0x80002FCC: nop

    // 0x80002FD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80002FD4: lbu         $v0, 0x7B8D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8D);
    // 0x80002FD8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80002FDC: lbu         $a0, 0x7B8E($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8E);
    // 0x80002FE0: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x80002FE4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80002FE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80002FEC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80002FF0: beq         $v0, $zero, L_8000300C
    if (ctx->r2 == 0) {
        // 0x80002FF4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8000300C;
    }
    // 0x80002FF4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80002FF8: sb          $v0, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r2;
    // 0x80002FFC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80003000: sb          $zero, 0xE($a1)
    MEM_B(0XE, ctx->r5) = 0;
    // 0x80003004: j           L_80003018
    // 0x80003008: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80003018;
    // 0x80003008: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_8000300C:
    // 0x8000300C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80003010: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80003014: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
L_80003018:
    // 0x80003018: jr          $ra
    // 0x8000301C: nop

    return;
    // 0x8000301C: nop

;}
RECOMP_FUNC void func_80003020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003020: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003024: lbu         $v0, 0x7B7E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7E);
    // 0x80003028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000302C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003030: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80003034: beq         $v0, $zero, L_8000304C
    if (ctx->r2 == 0) {
        // 0x80003038: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000304C;
    }
    // 0x80003038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000303C: jal         0x800033BC
    // 0x80003040: nop

    func_800033BC(rdram, ctx);
        goto after_0;
    // 0x80003040: nop

    after_0:
    // 0x80003044: j           L_80003154
    // 0x80003048: nop

        goto L_80003154;
    // 0x80003048: nop

L_8000304C:
    // 0x8000304C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003050: lbu         $v0, 0x207E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207E);
    // 0x80003054: bne         $v0, $zero, L_8000307C
    if (ctx->r2 != 0) {
        // 0x80003058: nop
    
            goto L_8000307C;
    }
    // 0x80003058: nop

    // 0x8000305C: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80003060: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003064: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x80003068: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000306C: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80003070: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80003074: bne         $v1, $zero, L_8000314C
    if (ctx->r3 != 0) {
        // 0x80003078: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8000314C;
    }
    // 0x80003078: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8000307C:
    // 0x8000307C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003080: lbu         $v0, 0x7B8D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8D);
    // 0x80003084: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80003088: lbu         $a0, 0x7B8E($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8E);
    // 0x8000308C: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80003090: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80003094: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80003098: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8000309C: beq         $v0, $zero, L_800030B4
    if (ctx->r2 == 0) {
        // 0x800030A0: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800030B4;
    }
    // 0x800030A0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800030A4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800030A8: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800030AC: j           L_800030E4
    // 0x800030B0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
        goto L_800030E4;
    // 0x800030B0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
L_800030B4:
    // 0x800030B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800030B8: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x800030BC: bne         $v0, $zero, L_8000314C
    if (ctx->r2 != 0) {
        // 0x800030C0: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000314C;
    }
    // 0x800030C0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800030C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800030C8: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x800030CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800030D0: bne         $v1, $v0, L_800030F0
    if (ctx->r3 != ctx->r2) {
        // 0x800030D4: addiu       $v1, $zero, 0xC
        ctx->r3 = ADD32(0, 0XC);
            goto L_800030F0;
    }
    // 0x800030D4: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x800030D8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800030DC: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800030E0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
L_800030E4:
    // 0x800030E4: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x800030E8: j           L_80003154
    // 0x800030EC: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
        goto L_80003154;
    // 0x800030EC: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
L_800030F0:
    // 0x800030F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800030F4: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x800030F8: bne         $v0, $zero, L_80003144
    if (ctx->r2 != 0) {
        // 0x800030FC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80003144;
    }
    // 0x800030FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80003100: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80003104: jal         0x80003558
    // 0x80003108: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    func_80003558(rdram, ctx);
        goto after_1;
    // 0x80003108: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    after_1:
    // 0x8000310C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003110: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003114: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80003118: lbu         $v1, 0x7B38($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B38);
    // 0x8000311C: beq         $v1, $zero, L_80003154
    if (ctx->r3 == 0) {
        // 0x80003120: nop
    
            goto L_80003154;
    }
    // 0x80003120: nop

    // 0x80003124: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003128: lbu         $v0, 0x207B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207B);
    // 0x8000312C: beq         $v0, $zero, L_80003148
    if (ctx->r2 == 0) {
        // 0x80003130: sltiu       $v0, $v1, 0x2
        ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
            goto L_80003148;
    }
    // 0x80003130: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80003134: bne         $v0, $zero, L_80003154
    if (ctx->r2 != 0) {
        // 0x80003138: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80003154;
    }
    // 0x80003138: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000313C: j           L_8000314C
    // 0x80003140: nop

        goto L_8000314C;
    // 0x80003140: nop

L_80003144:
    // 0x80003144: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
L_80003148:
    // 0x80003148: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8000314C:
    // 0x8000314C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80003150: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80003154:
    // 0x80003154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003158: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000315C: jr          $ra
    // 0x80003160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003164: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003168: lbu         $v0, 0x7B7E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7E);
    // 0x8000316C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80003170: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003174: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80003178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000317C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80003180: beq         $v0, $zero, L_80003198
    if (ctx->r2 == 0) {
        // 0x80003184: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80003198;
    }
    // 0x80003184: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80003188: jal         0x800033BC
    // 0x8000318C: nop

    func_800033BC(rdram, ctx);
        goto after_0;
    // 0x8000318C: nop

    after_0:
    // 0x80003190: j           L_8000337C
    // 0x80003194: nop

        goto L_8000337C;
    // 0x80003194: nop

L_80003198:
    // 0x80003198: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000319C: lbu         $v0, 0x207E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207E);
    // 0x800031A0: bne         $v0, $zero, L_800031C8
    if (ctx->r2 != 0) {
        // 0x800031A4: nop
    
            goto L_800031C8;
    }
    // 0x800031A4: nop

    // 0x800031A8: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800031AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800031B0: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x800031B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800031B8: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800031BC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800031C0: bne         $v1, $zero, L_800032A0
    if (ctx->r3 != 0) {
        // 0x800031C4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_800032A0;
    }
    // 0x800031C4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800031C8:
    // 0x800031C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800031CC: lbu         $v0, 0x7B8D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8D);
    // 0x800031D0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800031D4: lbu         $a0, 0x7B8E($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8E);
    // 0x800031D8: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800031DC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800031E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800031E4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800031E8: beq         $v0, $zero, L_80003200
    if (ctx->r2 == 0) {
        // 0x800031EC: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_80003200;
    }
    // 0x800031EC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800031F0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800031F4: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800031F8: j           L_80003230
    // 0x800031FC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
        goto L_80003230;
    // 0x800031FC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
L_80003200:
    // 0x80003200: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003204: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80003208: bne         $v0, $zero, L_800032A0
    if (ctx->r2 != 0) {
        // 0x8000320C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800032A0;
    }
    // 0x8000320C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80003210: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003214: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x80003218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000321C: bne         $v1, $v0, L_8000323C
    if (ctx->r3 != ctx->r2) {
        // 0x80003220: addiu       $v1, $zero, 0xC
        ctx->r3 = ADD32(0, 0XC);
            goto L_8000323C;
    }
    // 0x80003220: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80003224: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80003228: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x8000322C: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
L_80003230:
    // 0x80003230: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x80003234: j           L_8000337C
    // 0x80003238: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
        goto L_8000337C;
    // 0x80003238: sb          $a0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r4;
L_8000323C:
    // 0x8000323C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003240: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x80003244: bne         $v0, $zero, L_800032AC
    if (ctx->r2 != 0) {
        // 0x80003248: nop
    
            goto L_800032AC;
    }
    // 0x80003248: nop

    // 0x8000324C: jal         0x80003558
    // 0x80003250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80003558(rdram, ctx);
        goto after_1;
    // 0x80003250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80003254: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003258: lbu         $v1, 0x207B($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X207B);
    // 0x8000325C: beq         $v1, $zero, L_80003288
    if (ctx->r3 == 0) {
        // 0x80003260: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_80003288;
    }
    // 0x80003260: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80003264: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80003268: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000326C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003270: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x80003274: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80003278: bne         $v0, $zero, L_800032A0
    if (ctx->r2 != 0) {
        // 0x8000327C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800032A0;
    }
    // 0x8000327C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80003280: j           L_800032AC
    // 0x80003284: nop

        goto L_800032AC;
    // 0x80003284: nop

L_80003288:
    // 0x80003288: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8000328C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003290: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003294: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x80003298: bne         $v0, $zero, L_800032AC
    if (ctx->r2 != 0) {
        // 0x8000329C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800032AC;
    }
    // 0x8000329C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800032A0:
    // 0x800032A0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800032A4: j           L_8000337C
    // 0x800032A8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_8000337C;
    // 0x800032A8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800032AC:
    // 0x800032AC: jal         0x80003558
    // 0x800032B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80003558(rdram, ctx);
        goto after_2;
    // 0x800032B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800032B4: jal         0x80003A7C
    // 0x800032B8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_80003A7C(rdram, ctx);
        goto after_3;
    // 0x800032B8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_3:
    // 0x800032BC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800032C0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800032C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800032C8: and         $v1, $s2, $v1
    ctx->r3 = ctx->r18 & ctx->r3;
    // 0x800032CC: beq         $v1, $zero, L_8000337C
    if (ctx->r3 == 0) {
        // 0x800032D0: nop
    
            goto L_8000337C;
    }
    // 0x800032D0: nop

    // 0x800032D4: jal         0x80006708
    // 0x800032D8: nop

    func_80006708(rdram, ctx);
        goto after_4;
    // 0x800032D8: nop

    after_4:
    // 0x800032DC: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x800032E0: jal         0x8000637C
    // 0x800032E4: sra         $a1, $s2, 1
    ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
    func_8000637C(rdram, ctx);
        goto after_5;
    // 0x800032E4: sra         $a1, $s2, 1
    ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
    after_5:
    // 0x800032E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800032EC: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x800032F0: bne         $v0, $zero, L_8000333C
    if (ctx->r2 != 0) {
        // 0x800032F4: sll         $a0, $s1, 2
        ctx->r4 = S32(ctx->r17 << 2);
            goto L_8000333C;
    }
    // 0x800032F4: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x800032F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800032FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80003300: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x80003304: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003308: addiu       $v1, $v1, 0x7B30
    ctx->r3 = ADD32(ctx->r3, 0X7B30);
    // 0x8000330C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80003310: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003314: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x80003318: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000331C: lbu         $v0, 0x207B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207B);
    // 0x80003320: beq         $v0, $zero, L_8000333C
    if (ctx->r2 == 0) {
        // 0x80003324: nop
    
            goto L_8000333C;
    }
    // 0x80003324: nop

    // 0x80003328: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000332C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80003330: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x80003334: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003338: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8000333C:
    // 0x8000333C: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80003340: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80003344: addiu       $a0, $a0, 0x2071
    ctx->r4 = ADD32(ctx->r4, 0X2071);
    // 0x80003348: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000334C: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80003350: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80003354: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003358: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8000335C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80003360: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80003364: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003368: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x8000336C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003370: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80003374: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003378: sb          $v1, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r3;
L_8000337C:
    // 0x8000337C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003380: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80003384: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80003388: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000338C: jr          $ra
    // 0x80003390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80003390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80003394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003394: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80003398: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x8000339C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800033A0: lbu         $v0, 0x7B7E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7E);
    // 0x800033A4: bne         $v0, $zero, L_800033B4
    if (ctx->r2 != 0) {
        // 0x800033A8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800033B4;
    }
    // 0x800033A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800033AC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800033B0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800033B4:
    // 0x800033B4: jr          $ra
    // 0x800033B8: nop

    return;
    // 0x800033B8: nop

;}
RECOMP_FUNC void func_800033BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800033C0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800033C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800033C8: jr          $ra
    // 0x800033CC: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    return;
    // 0x800033CC: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800033D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033D0: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x800033D4: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800033D8: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
    // 0x800033DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800033E0: lbu         $v1, 0x2072($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2072);
    // 0x800033E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800033E8: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800033EC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800033F0: bne         $v1, $zero, L_80003400
    if (ctx->r3 != 0) {
        // 0x800033F4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80003400;
    }
    // 0x800033F4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800033F8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800033FC: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80003400:
    // 0x80003400: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003404: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80003408: beq         $v0, $zero, L_80003418
    if (ctx->r2 == 0) {
        // 0x8000340C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80003418;
    }
    // 0x8000340C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80003410: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80003414: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80003418:
    // 0x80003418: jr          $ra
    // 0x8000341C: nop

    return;
    // 0x8000341C: nop

;}
RECOMP_FUNC void func_80003420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003420: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80003424: lbu         $v0, 0xE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XE);
    // 0x80003428: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8000342C: sb          $v1, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r3;
    // 0x80003430: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80003434: bne         $v0, $v1, L_80003494
    if (ctx->r2 != ctx->r3) {
        // 0x80003438: nop
    
            goto L_80003494;
    }
    // 0x80003438: nop

    // 0x8000343C: lbu         $v0, 0x17($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X17);
    // 0x80003440: beq         $v0, $zero, L_80003458
    if (ctx->r2 == 0) {
        // 0x80003444: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80003458;
    }
    // 0x80003444: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80003448: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000344C: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80003450: beq         $v1, $v0, L_800034B0
    if (ctx->r3 == ctx->r2) {
        // 0x80003454: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800034B0;
    }
    // 0x80003454: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80003458:
    // 0x80003458: lbu         $v1, 0xE($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XE);
    // 0x8000345C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80003460: bne         $v1, $v0, L_80003494
    if (ctx->r3 != ctx->r2) {
        // 0x80003464: nop
    
            goto L_80003494;
    }
    // 0x80003464: nop

    // 0x80003468: lbu         $v0, 0x17($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X17);
    // 0x8000346C: beq         $v0, $zero, L_80003494
    if (ctx->r2 == 0) {
        // 0x80003470: nop
    
            goto L_80003494;
    }
    // 0x80003470: nop

    // 0x80003474: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x80003478: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000347C: lbu         $v1, 0x2071($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2071);
    // 0x80003480: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003484: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80003488: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8000348C: beq         $v1, $zero, L_800034B0
    if (ctx->r3 == 0) {
        // 0x80003490: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800034B0;
    }
    // 0x80003490: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80003494:
    // 0x80003494: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003498: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8000349C: beq         $v0, $zero, L_800034BC
    if (ctx->r2 == 0) {
        // 0x800034A0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800034BC;
    }
    // 0x800034A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800034A4: lbu         $v1, 0xE($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XE);
    // 0x800034A8: bne         $v1, $v0, L_800034BC
    if (ctx->r3 != ctx->r2) {
        // 0x800034AC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800034BC;
    }
    // 0x800034AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800034B0:
    // 0x800034B0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800034B4: j           L_800034F4
    // 0x800034B8: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
        goto L_800034F4;
    // 0x800034B8: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
L_800034BC:
    // 0x800034BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800034C0: lbu         $v0, 0x7B8D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8D);
    // 0x800034C4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800034C8: lbu         $a0, 0x7B8E($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8E);
    // 0x800034CC: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x800034D0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800034D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800034D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800034DC: bne         $v0, $zero, L_800034F4
    if (ctx->r2 != 0) {
        // 0x800034E0: nop
    
            goto L_800034F4;
    }
    // 0x800034E0: nop

    // 0x800034E4: lbu         $v0, 0xE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XE);
    // 0x800034E8: lbu         $v1, 0xF($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XF);
    // 0x800034EC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800034F0: sb          $v1, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r3;
L_800034F4:
    // 0x800034F4: jr          $ra
    // 0x800034F8: nop

    return;
    // 0x800034F8: nop

;}
RECOMP_FUNC void func_800034FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80003500: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80003504: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003508: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000350C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003510: beq         $v1, $v0, L_80003528
    if (ctx->r3 == ctx->r2) {
        // 0x80003514: nop
    
            goto L_80003528;
    }
    // 0x80003514: nop

    // 0x80003518: lbu         $v0, 0xE($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XE);
    // 0x8000351C: lbu         $v1, 0xF($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XF);
    // 0x80003520: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80003524: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
L_80003528:
    // 0x80003528: jr          $ra
    // 0x8000352C: nop

    return;
    // 0x8000352C: nop

;}
RECOMP_FUNC void func_80003530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003530: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80003534: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80003538: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000353C: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80003540: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80003544: bne         $v1, $v0, L_80003550
    if (ctx->r3 != ctx->r2) {
        // 0x80003548: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80003550;
    }
    // 0x80003548: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000354C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80003550:
    // 0x80003550: jr          $ra
    // 0x80003554: nop

    return;
    // 0x80003554: nop

;}
RECOMP_FUNC void func_80003558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003558: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000355C: lbu         $v1, 0x7B4A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4A);
    // 0x80003560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003564: bne         $v1, $v0, L_80003570
    if (ctx->r3 != ctx->r2) {
        // 0x80003568: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80003570;
    }
    // 0x80003568: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8000356C: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
L_80003570:
    // 0x80003570: jr          $ra
    // 0x80003574: nop

    return;
    // 0x80003574: nop

;}
RECOMP_FUNC void func_80003578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000357C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80003580: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80003584: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003588: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000358C: addiu       $s0, $s0, -0x3774
    ctx->r16 = ADD32(ctx->r16, -0X3774);
    // 0x80003590: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80003594:
    // 0x80003594: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80003598: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000359C: jal         0x8006CEF0
    // 0x800035A0: addiu       $a1, $a1, -0x3878
    ctx->r5 = ADD32(ctx->r5, -0X3878);
    func_8006CEF0(rdram, ctx);
        goto after_0;
    // 0x800035A0: addiu       $a1, $a1, -0x3878
    ctx->r5 = ADD32(ctx->r5, -0X3878);
    after_0:
    // 0x800035A4: beq         $v0, $zero, L_800035C4
    if (ctx->r2 == 0) {
        // 0x800035A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800035C4;
    }
    // 0x800035A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800035AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800035B0: jal         0x8006CEF0
    // 0x800035B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8006CEF0(rdram, ctx);
        goto after_1;
    // 0x800035B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800035B8: bne         $v0, $zero, L_80003594
    if (ctx->r2 != 0) {
        // 0x800035BC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80003594;
    }
    // 0x800035BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800035C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800035C4:
    // 0x800035C4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800035C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800035CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800035D0: jr          $ra
    // 0x800035D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800035D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800035E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800035E4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800035E8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800035EC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800035F0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800035F4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800035F8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800035FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80003600: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80003604: jal         0x80001FB4
    // 0x80003608: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80001FB4(rdram, ctx);
        goto after_0;
    // 0x80003608: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000360C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003610: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80003614: sb          $v0, -0x7560($at)
    MEM_B(-0X7560, ctx->r1) = ctx->r2;
    // 0x80003618: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000361C: addiu       $v0, $v0, 0x25A0
    ctx->r2 = ADD32(ctx->r2, 0X25A0);
    // 0x80003620: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80003624: sw          $v0, -0x7568($at)
    MEM_W(-0X7568, ctx->r1) = ctx->r2;
    // 0x80003628: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000362C: addiu       $v0, $v0, 0x79F0
    ctx->r2 = ADD32(ctx->r2, 0X79F0);
    // 0x80003630: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80003634: sb          $zero, -0x757C($at)
    MEM_B(-0X757C, ctx->r1) = 0;
    // 0x80003638: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8000363C: sw          $v0, -0x754C($at)
    MEM_W(-0X754C, ctx->r1) = ctx->r2;
    // 0x80003640: jal         0x80004644
    // 0x80003644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_1;
    // 0x80003644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80003648:
    // 0x80003648: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000364C: addiu       $v0, $v0, 0x7B4D
    ctx->r2 = ADD32(ctx->r2, 0X7B4D);
    // 0x80003650: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80003654: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80003658: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8000365C: addiu       $s3, $s3, 0x2080
    ctx->r19 = ADD32(ctx->r19, 0X2080);
    // 0x80003660: addiu       $s1, $v0, -0x15
    ctx->r17 = ADD32(ctx->r2, -0X15);
    // 0x80003664: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80003668: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x8000366C: addiu       $s2, $s2, -0x757B
    ctx->r18 = ADD32(ctx->r18, -0X757B);
L_80003670:
    // 0x80003670: jal         0x80004644
    // 0x80003674: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_2;
    // 0x80003674: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80003678: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000367C: lb          $v0, 0x5581($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5581);
    // 0x80003680: beq         $v0, $s4, L_8000369C
    if (ctx->r2 == ctx->r20) {
        // 0x80003684: nop
    
            goto L_8000369C;
    }
    // 0x80003684: nop

    // 0x80003688: jal         0x80003A7C
    // 0x8000368C: nop

    func_80003A7C(rdram, ctx);
        goto after_3;
    // 0x8000368C: nop

    after_3:
    // 0x80003690: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80003694: beq         $s0, $zero, L_800036BC
    if (ctx->r16 == 0) {
        // 0x80003698: nop
    
            goto L_800036BC;
    }
    // 0x80003698: nop

L_8000369C:
    // 0x8000369C: jal         0x80006708
    // 0x800036A0: nop

    func_80006708(rdram, ctx);
        goto after_4;
    // 0x800036A0: nop

    after_4:
    // 0x800036A4: beq         $s0, $zero, L_8000371C
    if (ctx->r16 == 0) {
        // 0x800036A8: addiu       $a0, $zero, 0x3B
        ctx->r4 = ADD32(0, 0X3B);
            goto L_8000371C;
    }
    // 0x800036A8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x800036AC: jal         0x8000637C
    // 0x800036B0: sra         $a1, $s0, 1
    ctx->r5 = S32(SIGNED(ctx->r16) >> 1);
    func_8000637C(rdram, ctx);
        goto after_5;
    // 0x800036B0: sra         $a1, $s0, 1
    ctx->r5 = S32(SIGNED(ctx->r16) >> 1);
    after_5:
    // 0x800036B4: j           L_8000371C
    // 0x800036B8: nop

        goto L_8000371C;
    // 0x800036B8: nop

L_800036BC:
    // 0x800036BC: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800036C0: lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2);
    // 0x800036C4: lbu         $a0, 0x12($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X12);
    // 0x800036C8: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x800036CC: bne         $a0, $s5, L_800036E8
    if (ctx->r4 != ctx->r21) {
        // 0x800036D0: sb          $a1, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r5;
            goto L_800036E8;
    }
    // 0x800036D0: sb          $a1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r5;
    // 0x800036D4: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x800036D8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800036DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800036E0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800036E4: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800036E8:
    // 0x800036E8: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x800036EC: bne         $v0, $zero, L_80003948
    if (ctx->r2 != 0) {
        // 0x800036F0: nop
    
            goto L_80003948;
    }
    // 0x800036F0: nop

    // 0x800036F4: lbu         $v0, -0x10($s3)
    ctx->r2 = MEM_BU(ctx->r19, -0X10);
    // 0x800036F8: bnel        $v0, $s5, L_80003710
    if (ctx->r2 != ctx->r21) {
        // 0x800036FC: sb          $zero, 0x1C($s2)
        MEM_B(0X1C, ctx->r18) = 0;
            goto L_80003710;
    }
    goto skip_0;
    // 0x800036FC: sb          $zero, 0x1C($s2)
    MEM_B(0X1C, ctx->r18) = 0;
    skip_0:
    // 0x80003700: sb          $s4, 0x1C($s2)
    MEM_B(0X1C, ctx->r18) = ctx->r20;
    // 0x80003704: sb          $s4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r20;
    // 0x80003708: j           L_80003670
    // 0x8000370C: sb          $s4, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r20;
        goto L_80003670;
    // 0x8000370C: sb          $s4, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r20;
L_80003710:
    // 0x80003710: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80003714: j           L_80003670
    // 0x80003718: sb          $zero, 0x11($s1)
    MEM_B(0X11, ctx->r17) = 0;
        goto L_80003670;
    // 0x80003718: sb          $zero, 0x11($s1)
    MEM_B(0X11, ctx->r17) = 0;
L_8000371C:
    // 0x8000371C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003720: addiu       $v1, $v1, 0x5580
    ctx->r3 = ADD32(ctx->r3, 0X5580);
    // 0x80003724: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80003728: bne         $v0, $zero, L_80003748
    if (ctx->r2 != 0) {
        // 0x8000372C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80003748;
    }
    // 0x8000372C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80003730: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003734: lbu         $v0, 0x5581($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5581);
    // 0x80003738: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000373C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80003740: bne         $v0, $zero, L_80003764
    if (ctx->r2 != 0) {
        // 0x80003744: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80003764;
    }
    // 0x80003744: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80003748:
    // 0x80003748: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000374C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003750: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x80003754: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003758: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8000375C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003760: sb          $zero, 0x7BA3($at)
    MEM_B(0X7BA3, ctx->r1) = 0;
L_80003764:
    // 0x80003764: jal         0x80004644
    // 0x80003768: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80004644(rdram, ctx);
        goto after_6;
    // 0x80003768: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8000376C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80003770: lui         $s6, 0x801E
    ctx->r22 = S32(0X801E << 16);
    // 0x80003774: addiu       $s6, $s6, -0x757B
    ctx->r22 = ADD32(ctx->r22, -0X757B);
    // 0x80003778: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8000377C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80003780: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x80003784: addiu       $s2, $s2, 0x7B4D
    ctx->r18 = ADD32(ctx->r18, 0X7B4D);
    // 0x80003788: addiu       $s7, $s2, -0x3
    ctx->r23 = ADD32(ctx->r18, -0X3);
L_8000378C:
    // 0x8000378C: jal         0x80004644
    // 0x80003790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_7;
    // 0x80003790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80003794: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80003798: bne         $v0, $zero, L_80003648
    if (ctx->r2 != 0) {
        // 0x8000379C: nop
    
            goto L_80003648;
    }
    // 0x8000379C: nop

    // 0x800037A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800037A4: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x800037A8: bne         $v0, $s4, L_800037C0
    if (ctx->r2 != ctx->r20) {
        // 0x800037AC: nop
    
            goto L_800037C0;
    }
    // 0x800037AC: nop

    // 0x800037B0: sb          $s3, 0x1C($s6)
    MEM_B(0X1C, ctx->r22) = ctx->r19;
    // 0x800037B4: sb          $s3, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r19;
    // 0x800037B8: j           L_800037F4
    // 0x800037BC: sb          $s3, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = ctx->r19;
        goto L_800037F4;
    // 0x800037BC: sb          $s3, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = ctx->r19;
L_800037C0:
    // 0x800037C0: lbu         $v0, -0x2($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2);
    // 0x800037C4: beq         $v0, $zero, L_800037E4
    if (ctx->r2 == 0) {
        // 0x800037C8: nop
    
            goto L_800037E4;
    }
    // 0x800037C8: nop

    // 0x800037CC: lbu         $v0, -0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X15);
    // 0x800037D0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800037D4: beql        $v0, $zero, L_800037F4
    if (ctx->r2 == 0) {
        // 0x800037D8: sb          $s4, -0x4($s2)
        MEM_B(-0X4, ctx->r18) = ctx->r20;
            goto L_800037F4;
    }
    goto skip_1;
    // 0x800037D8: sb          $s4, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = ctx->r20;
    skip_1:
    // 0x800037DC: j           L_800037F4
    // 0x800037E0: sb          $zero, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = 0;
        goto L_800037F4;
    // 0x800037E0: sb          $zero, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = 0;
L_800037E4:
    // 0x800037E4: lbu         $v0, -0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X15);
    // 0x800037E8: beql        $v0, $zero, L_800037F4
    if (ctx->r2 == 0) {
        // 0x800037EC: sb          $zero, -0x4($s2)
        MEM_B(-0X4, ctx->r18) = 0;
            goto L_800037F4;
    }
    goto skip_2;
    // 0x800037EC: sb          $zero, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = 0;
    skip_2:
    // 0x800037F0: sb          $s4, -0x4($s2)
    MEM_B(-0X4, ctx->r18) = ctx->r20;
L_800037F4:
    // 0x800037F4: jal         0x80003A7C
    // 0x800037F8: nop

    func_80003A7C(rdram, ctx);
        goto after_8;
    // 0x800037F8: nop

    after_8:
    // 0x800037FC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80003800: beq         $s0, $zero, L_8000378C
    if (ctx->r16 == 0) {
        // 0x80003804: nop
    
            goto L_8000378C;
    }
    // 0x80003804: nop

    // 0x80003808: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000380C: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x80003810: bne         $v0, $zero, L_8000382C
    if (ctx->r2 != 0) {
        // 0x80003814: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_8000382C;
    }
    // 0x80003814: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x80003818: bne         $s1, $s5, L_80003838
    if (ctx->r17 != ctx->r21) {
        // 0x8000381C: nop
    
            goto L_80003838;
    }
    // 0x8000381C: nop

    // 0x80003820: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80003824: j           L_80003838
    // 0x80003828: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80003838;
    // 0x80003828: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8000382C:
    // 0x8000382C: beql        $s0, $s5, L_80003834
    if (ctx->r16 == ctx->r21) {
        // 0x80003830: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80003834;
    }
    goto skip_3;
    // 0x80003830: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_3:
L_80003834:
    // 0x80003834: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80003838:
    // 0x80003838: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000383C: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x80003840: beq         $v0, $zero, L_8000385C
    if (ctx->r2 == 0) {
        // 0x80003844: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000385C;
    }
    // 0x80003844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80003848: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8000384C:
    // 0x8000384C: bgez        $a0, L_8000384C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003850: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8000384C;
    }
    // 0x80003850: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80003854: j           L_800038E0
    // 0x80003858: nop

        goto L_800038E0;
    // 0x80003858: nop

L_8000385C:
    // 0x8000385C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003860: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x80003864: bne         $v0, $zero, L_80003870
    if (ctx->r2 != 0) {
        // 0x80003868: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80003870;
    }
    // 0x80003868: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000386C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80003870:
    // 0x80003870: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80003874: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80003878: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8000387C:
    // 0x8000387C: and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // 0x80003880: beql        $v0, $zero, L_800038CC
    if (ctx->r2 == 0) {
        // 0x80003884: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800038CC;
    }
    goto skip_4;
    // 0x80003884: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x80003888: lbu         $v0, 0x0($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X0);
    // 0x8000388C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80003890: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80003894: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80003898: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8000389C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800038A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800038A4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800038A8: lbu         $v1, 0x7B38($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B38);
    // 0x800038AC: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800038B0: bne         $v0, $zero, L_800038CC
    if (ctx->r2 != 0) {
        // 0x800038B4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800038CC;
    }
    // 0x800038B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800038B8: subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // 0x800038BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800038C0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800038C4: sb          $v0, 0x7B38($at)
    MEM_B(0X7B38, ctx->r1) = ctx->r2;
    // 0x800038C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800038CC:
    // 0x800038CC: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x800038D0: bnel        $v0, $zero, L_8000387C
    if (ctx->r2 != 0) {
        // 0x800038D4: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8000387C;
    }
    goto skip_5;
    // 0x800038D4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x800038D8: beq         $a3, $zero, L_8000378C
    if (ctx->r7 == 0) {
        // 0x800038DC: nop
    
            goto L_8000378C;
    }
    // 0x800038DC: nop

L_800038E0:
    // 0x800038E0: jal         0x80006708
    // 0x800038E4: nop

    func_80006708(rdram, ctx);
        goto after_9;
    // 0x800038E4: nop

    after_9:
    // 0x800038E8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x800038EC: jal         0x8000637C
    // 0x800038F0: sra         $a1, $s0, 1
    ctx->r5 = S32(SIGNED(ctx->r16) >> 1);
    func_8000637C(rdram, ctx);
        goto after_10;
    // 0x800038F0: sra         $a1, $s0, 1
    ctx->r5 = S32(SIGNED(ctx->r16) >> 1);
    after_10:
    // 0x800038F4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800038F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800038FC: sb          $v0, 0x7B49($at)
    MEM_B(0X7B49, ctx->r1) = ctx->r2;
    // 0x80003900: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80003904: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80003908: sb          $v0, -0x755F($at)
    MEM_B(-0X755F, ctx->r1) = ctx->r2;
    // 0x8000390C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80003910: sb          $v0, -0x757B($at)
    MEM_B(-0X757B, ctx->r1) = ctx->r2;
    // 0x80003914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003918: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000391C: sb          $v0, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = ctx->r2;
    // 0x80003920: andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // 0x80003924: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003928: sb          $s1, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r17;
    // 0x8000392C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003930: sb          $s1, 0x2072($at)
    MEM_B(0X2072, ctx->r1) = ctx->r17;
    // 0x80003934: beq         $v0, $zero, L_80003958
    if (ctx->r2 == 0) {
        // 0x80003938: andi        $v0, $s1, 0x2
        ctx->r2 = ctx->r17 & 0X2;
            goto L_80003958;
    }
    // 0x80003938: andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
    // 0x8000393C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003940: j           L_80003968
    // 0x80003944: addiu       $v0, $v0, 0x25A0
    ctx->r2 = ADD32(ctx->r2, 0X25A0);
        goto L_80003968;
    // 0x80003944: addiu       $v0, $v0, 0x25A0
    ctx->r2 = ADD32(ctx->r2, 0X25A0);
L_80003948:
    // 0x80003948: jal         0x80006708
    // 0x8000394C: nop

    func_80006708(rdram, ctx);
        goto after_11;
    // 0x8000394C: nop

    after_11:
    // 0x80003950: j           L_8000371C
    // 0x80003954: nop

        goto L_8000371C;
    // 0x80003954: nop

L_80003958:
    // 0x80003958: beq         $v0, $zero, L_80003970
    if (ctx->r2 == 0) {
        // 0x8000395C: nop
    
            goto L_80003970;
    }
    // 0x8000395C: nop

    // 0x80003960: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003964: addiu       $v0, $v0, 0x79F0
    ctx->r2 = ADD32(ctx->r2, 0X79F0);
L_80003968:
    // 0x80003968: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000396C: sw          $v0, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->r2;
L_80003970:
    // 0x80003970: jal         0x800039B0
    // 0x80003974: nop

    func_800039B0(rdram, ctx);
        goto after_12;
    // 0x80003974: nop

    after_12:
    // 0x80003978: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8000397C: jal         0x80004780
    // 0x80003980: addiu       $a0, $a0, 0x1F30
    ctx->r4 = ADD32(ctx->r4, 0X1F30);
    func_80004780(rdram, ctx);
        goto after_13;
    // 0x80003980: addiu       $a0, $a0, 0x1F30
    ctx->r4 = ADD32(ctx->r4, 0X1F30);
    after_13:
    // 0x80003984: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80003988: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8000398C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80003990: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80003994: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80003998: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000399C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800039A0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800039A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800039A8: jr          $ra
    // 0x800039AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800039AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800039B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800039B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800039B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800039B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800039BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039C0: sb          $v0, 0x5580($at)
    MEM_B(0X5580, ctx->r1) = ctx->r2;
    // 0x800039C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039C8: sb          $zero, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = 0;
    // 0x800039CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039D0: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
    // 0x800039D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039D8: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x800039DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039E0: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
    // 0x800039E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039E8: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x800039EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039F0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800039F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800039F8: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x800039FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003A00: jal         0x80003A14
    // 0x80003A04: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
    func_80003A14(rdram, ctx);
        goto after_0;
    // 0x80003A04: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
    after_0:
    // 0x80003A08: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003A0C: jr          $ra
    // 0x80003A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003A14: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80003A18: lbu         $a0, 0x2071($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2071);
    // 0x80003A1C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003A20: addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // 0x80003A24: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80003A28: addiu       $a1, $a1, 0x25A0
    ctx->r5 = ADD32(ctx->r5, 0X25A0);
    // 0x80003A2C: addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // 0x80003A30: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80003A34: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80003A38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003A3C: sb          $v0, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = ctx->r2;
    // 0x80003A40: addiu       $v0, $zero, -0x7F
    ctx->r2 = ADD32(0, -0X7F);
    // 0x80003A44: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x80003A48: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80003A4C: beq         $v0, $zero, L_80003A60
    if (ctx->r2 == 0) {
        // 0x80003A50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003A60;
    }
    // 0x80003A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003A54: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80003A58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003A5C: sb          $zero, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = 0;
L_80003A60:
    // 0x80003A60: andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // 0x80003A64: beq         $v0, $zero, L_80003A74
    if (ctx->r2 == 0) {
        // 0x80003A68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003A74;
    }
    // 0x80003A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003A6C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80003A70: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
L_80003A74:
    // 0x80003A74: jr          $ra
    // 0x80003A78: nop

    return;
    // 0x80003A78: nop

;}
RECOMP_FUNC void func_80003A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003A7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80003A80: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80003A84: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80003A88: lhu         $v1, -0x33C2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C2);
    // 0x80003A8C: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80003A90: andi        $v1, $v1, 0x1000
    ctx->r3 = ctx->r3 & 0X1000;
    // 0x80003A94: beq         $v1, $zero, L_80003AA0
    if (ctx->r3 == 0) {
        // 0x80003A98: sltu        $v0, $zero, $v0
        ctx->r2 = 0 < ctx->r2 ? 1 : 0;
            goto L_80003AA0;
    }
    // 0x80003A98: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80003A9C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80003AA0:
    // 0x80003AA0: jr          $ra
    // 0x80003AA4: nop

    return;
    // 0x80003AA4: nop

;}
RECOMP_FUNC void func_80003AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003AA8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003AAC: lbu         $v0, 0x7BA3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA3);
    // 0x80003AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003AB8: bne         $v0, $zero, L_80003B10
    if (ctx->r2 != 0) {
        // 0x80003ABC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80003B10;
    }
    // 0x80003ABC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003AC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003AC4: lbu         $v1, 0x7B4A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4A);
    // 0x80003AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003ACC: bne         $v1, $v0, L_80003B00
    if (ctx->r3 != ctx->r2) {
        // 0x80003AD0: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80003B00;
    }
    // 0x80003AD0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80003AD4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80003AD8: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80003ADC: addiu       $s0, $s0, -0x7580
    ctx->r16 = ADD32(ctx->r16, -0X7580);
    // 0x80003AE0: jal         0x80003D84
    // 0x80003AE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80003D84(rdram, ctx);
        goto after_0;
    // 0x80003AE4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80003AE8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80003AEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80003AF0: jal         0x80003D84
    // 0x80003AF4: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    func_80003D84(rdram, ctx);
        goto after_1;
    // 0x80003AF4: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_1:
    // 0x80003AF8: j           L_80003B08
    // 0x80003AFC: nop

        goto L_80003B08;
    // 0x80003AFC: nop

L_80003B00:
    // 0x80003B00: jal         0x80003B20
    // 0x80003B04: nop

    func_80003B20(rdram, ctx);
        goto after_2;
    // 0x80003B04: nop

    after_2:
L_80003B08:
    // 0x80003B08: jal         0x8002C358
    // 0x80003B0C: nop

    func_8002C358(rdram, ctx);
        goto after_3;
    // 0x80003B0C: nop

    after_3:
L_80003B10:
    // 0x80003B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003B14: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80003B18: jr          $ra
    // 0x80003B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003B20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003B24: lbu         $v1, 0x7B49($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B49);
    // 0x80003B28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80003B2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80003B30: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80003B34: beq         $v0, $zero, L_80003D74
    if (ctx->r2 == 0) {
        // 0x80003B38: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80003D74;
    }
    // 0x80003B38: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80003B3C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003B40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80003B44: addu        $at, $at, $v0
    gpr jr_addend_80003B4C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003B48: lw          $v0, -0x3798($at)
    ctx->r2 = ADD32(ctx->r1, -0X3798);
    // 0x80003B4C: jr          $v0
    // 0x80003B50: nop

    switch (jr_addend_80003B4C >> 2) {
        case 0: goto L_80003B54; break;
        case 1: goto L_80003C0C; break;
        case 2: goto L_80003D1C; break;
        case 3: goto L_80003D74; break;
        case 4: goto L_80003D74; break;
        case 5: goto L_80003D74; break;
        case 6: goto L_80003D74; break;
        case 7: goto L_80003D74; break;
        case 8: goto L_80003D4C; break;
        case 9: goto L_80003D74; break;
        default: switch_error(__func__, 0x80003B4C, 0x800AC868);
    }
    // 0x80003B50: nop

L_80003B54:
    // 0x80003B54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003B58: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003B5C: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80003B60: beq         $v0, $zero, L_80003D74
    if (ctx->r2 == 0) {
        // 0x80003B64: nop
    
            goto L_80003D74;
    }
    // 0x80003B64: nop

    // 0x80003B68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003B6C: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x80003B70: beq         $v0, $zero, L_80003BC0
    if (ctx->r2 == 0) {
        // 0x80003B74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003BC0;
    }
    // 0x80003B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003B78: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003B7C: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x80003B80: bne         $v0, $zero, L_80003B98
    if (ctx->r2 != 0) {
        // 0x80003B84: addiu       $a1, $zero, 0x58
        ctx->r5 = ADD32(0, 0X58);
            goto L_80003B98;
    }
    // 0x80003B84: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80003B88: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003B8C: addiu       $a0, $a0, -0x3870
    ctx->r4 = ADD32(ctx->r4, -0X3870);
    // 0x80003B90: j           L_80003BA0
    // 0x80003B94: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
        goto L_80003BA0;
    // 0x80003B94: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
L_80003B98:
    // 0x80003B98: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003B9C: addiu       $a0, $a0, -0x3860
    ctx->r4 = ADD32(ctx->r4, -0X3860);
L_80003BA0:
    // 0x80003BA0: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80003BA4: jal         0x8004DAB8
    // 0x80003BA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x80003BA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80003BAC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003BB0: addiu       $a0, $a0, -0x384C
    ctx->r4 = ADD32(ctx->r4, -0X384C);
    // 0x80003BB4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80003BB8: j           L_80003D3C
    // 0x80003BBC: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
        goto L_80003D3C;
    // 0x80003BBC: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
L_80003BC0:
    // 0x80003BC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003BC4: lbu         $v1, 0x7B40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B40);
    // 0x80003BC8: bne         $v1, $v0, L_80003BE0
    if (ctx->r3 != ctx->r2) {
        // 0x80003BCC: nop
    
            goto L_80003BE0;
    }
    // 0x80003BCC: nop

    // 0x80003BD0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003BD4: addiu       $a0, $a0, -0x3830
    ctx->r4 = ADD32(ctx->r4, -0X3830);
    // 0x80003BD8: j           L_80003D38
    // 0x80003BDC: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
        goto L_80003D38;
    // 0x80003BDC: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
L_80003BE0:
    // 0x80003BE0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80003BE4: lbu         $a0, 0x7B3A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B3A);
    // 0x80003BE8: jal         0x80004128
    // 0x80003BEC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_80004128(rdram, ctx);
        goto after_1;
    // 0x80003BEC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80003BF0: jal         0x80066C48
    // 0x80003BF4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    strlen_recomp(rdram, ctx);
        goto after_2;
    // 0x80003BF4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80003BF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003BFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003C00: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80003C04: j           L_80003D38
    // 0x80003C08: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
        goto L_80003D38;
    // 0x80003C08: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
L_80003C0C:
    // 0x80003C0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003C10: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003C14: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80003C18: beq         $v0, $zero, L_80003D74
    if (ctx->r2 == 0) {
        // 0x80003C1C: nop
    
            goto L_80003D74;
    }
    // 0x80003C1C: nop

    // 0x80003C20: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003C24: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x80003C28: beq         $v0, $zero, L_80003C54
    if (ctx->r2 == 0) {
        // 0x80003C2C: addiu       $a1, $zero, 0x38
        ctx->r5 = ADD32(0, 0X38);
            goto L_80003C54;
    }
    // 0x80003C2C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80003C30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003C34: addiu       $a0, $a0, -0x384C
    ctx->r4 = ADD32(ctx->r4, -0X384C);
    // 0x80003C38: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80003C3C: jal         0x8004DAB8
    // 0x80003C40: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_3;
    // 0x80003C40: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80003C44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003C48: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x80003C4C: j           L_80003C60
    // 0x80003C50: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
        goto L_80003C60;
    // 0x80003C50: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
L_80003C54:
    // 0x80003C54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003C58: lbu         $v0, 0x7B38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B38);
    // 0x80003C5C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
L_80003C60:
    // 0x80003C60: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80003C64: beq         $v0, $zero, L_80003C7C
    if (ctx->r2 == 0) {
        // 0x80003C68: addiu       $a1, $zero, 0x34
        ctx->r5 = ADD32(0, 0X34);
            goto L_80003C7C;
    }
    // 0x80003C68: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x80003C6C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003C70: addiu       $a0, $a0, -0x3824
    ctx->r4 = ADD32(ctx->r4, -0X3824);
    // 0x80003C74: j           L_80003C8C
    // 0x80003C78: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
        goto L_80003C8C;
    // 0x80003C78: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
L_80003C7C:
    // 0x80003C7C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003C80: addiu       $a0, $a0, -0x3808
    ctx->r4 = ADD32(ctx->r4, -0X3808);
    // 0x80003C84: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80003C88: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
L_80003C8C:
    // 0x80003C8C: jal         0x8004DAB8
    // 0x80003C90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x80003C90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x80003C94: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003C98: lbu         $v1, 0x7B40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B40);
    // 0x80003C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80003CA0: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80003CA4: beq         $a0, $a1, L_80003D74
    if (ctx->r4 == ctx->r5) {
        // 0x80003CA8: nop
    
            goto L_80003D74;
    }
    // 0x80003CA8: nop

    // 0x80003CAC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003CB0: lbu         $v0, 0x7B3A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B3A);
    // 0x80003CB4: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80003CB8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80003CBC: sra         $a2, $v0, 24
    ctx->r6 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80003CC0: bne         $a2, $a1, L_80003CDC
    if (ctx->r6 != ctx->r5) {
        // 0x80003CC4: slti        $v0, $a2, 0x2
        ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_80003CDC;
    }
    // 0x80003CC4: slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80003CC8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003CCC: addiu       $a0, $a0, -0x37EC
    ctx->r4 = ADD32(ctx->r4, -0X37EC);
    // 0x80003CD0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80003CD4: j           L_80003D3C
    // 0x80003CD8: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
        goto L_80003D3C;
    // 0x80003CD8: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
L_80003CDC:
    // 0x80003CDC: bne         $v0, $zero, L_80003D74
    if (ctx->r2 != 0) {
        // 0x80003CE0: slt         $v0, $a2, $a0
        ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80003D74;
    }
    // 0x80003CE0: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80003CE4: beq         $v0, $zero, L_80003D74
    if (ctx->r2 == 0) {
        // 0x80003CE8: nop
    
            goto L_80003D74;
    }
    // 0x80003CE8: nop

    // 0x80003CEC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003CF0: addiu       $a1, $a1, -0x37CC
    ctx->r5 = ADD32(ctx->r5, -0X37CC);
    // 0x80003CF4: jal         0x80066CA0
    // 0x80003CF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x80003CF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x80003CFC: jal         0x80066C48
    // 0x80003D00: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    strlen_recomp(rdram, ctx);
        goto after_6;
    // 0x80003D00: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x80003D04: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003D08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003D0C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80003D10: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x80003D14: j           L_80003D3C
    // 0x80003D18: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
        goto L_80003D3C;
    // 0x80003D18: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
L_80003D1C:
    // 0x80003D1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003D20: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003D24: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80003D28: beq         $v0, $zero, L_80003D74
    if (ctx->r2 == 0) {
        // 0x80003D2C: addiu       $a1, $zero, 0x74
        ctx->r5 = ADD32(0, 0X74);
            goto L_80003D74;
    }
    // 0x80003D2C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x80003D30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003D34: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
L_80003D38:
    // 0x80003D38: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
L_80003D3C:
    // 0x80003D3C: jal         0x8004DAB8
    // 0x80003D40: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_7;
    // 0x80003D40: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_7:
    // 0x80003D44: j           L_80003D74
    // 0x80003D48: nop

        goto L_80003D74;
    // 0x80003D48: nop

L_80003D4C:
    // 0x80003D4C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80003D50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80003D54: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x80003D58: addiu       $s0, $s0, -0x7580
    ctx->r16 = ADD32(ctx->r16, -0X7580);
    // 0x80003D5C: jal         0x80003D84
    // 0x80003D60: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80003D84(rdram, ctx);
        goto after_8;
    // 0x80003D60: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_8:
    // 0x80003D64: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80003D68: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80003D6C: jal         0x80003D84
    // 0x80003D70: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    func_80003D84(rdram, ctx);
        goto after_9;
    // 0x80003D70: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_9:
L_80003D74:
    // 0x80003D74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80003D78: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80003D7C: jr          $ra
    // 0x80003D80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80003D80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80003D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003D84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80003D88: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80003D8C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80003D90: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80003D94: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80003D98: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80003D9C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80003DA0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80003DA4: lbu         $v0, 0x4($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X4);
    // 0x80003DA8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80003DAC: addiu       $a2, $a2, 0x79F0
    ctx->r6 = ADD32(ctx->r6, 0X79F0);
    // 0x80003DB0: bne         $v0, $zero, L_80003DC0
    if (ctx->r2 != 0) {
        // 0x80003DB4: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_80003DC0;
    }
    // 0x80003DB4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80003DB8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80003DBC: addiu       $a2, $a2, 0x25A0
    ctx->r6 = ADD32(ctx->r6, 0X25A0);
L_80003DC0:
    // 0x80003DC0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003DC4: lbu         $v0, 0x7BA2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA2);
    // 0x80003DC8: bne         $v0, $zero, L_80003DD4
    if (ctx->r2 != 0) {
        // 0x80003DCC: addiu       $s0, $zero, 0x9
        ctx->r16 = ADD32(0, 0X9);
            goto L_80003DD4;
    }
    // 0x80003DCC: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x80003DD0: lbu         $s0, 0x5($s3)
    ctx->r16 = MEM_BU(ctx->r19, 0X5);
L_80003DD4:
    // 0x80003DD4: sltiu       $v0, $s0, 0xB
    ctx->r2 = ctx->r16 < 0XB ? 1 : 0;
    // 0x80003DD8: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x80003DDC: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_8000410C;
    }
    // 0x80003DDC: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80003DE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80003DE4: addu        $at, $at, $v0
    gpr jr_addend_80003DEC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003DE8: lw          $v0, -0x36E8($at)
    ctx->r2 = ADD32(ctx->r1, -0X36E8);
    // 0x80003DEC: jr          $v0
    // 0x80003DF0: nop

    switch (jr_addend_80003DEC >> 2) {
        case 0: goto L_80003DF4; break;
        case 1: goto L_80003E68; break;
        case 2: goto L_80003EC4; break;
        case 3: goto L_80003F20; break;
        case 4: goto L_80003F3C; break;
        case 5: goto L_80003FB8; break;
        case 6: goto L_80003FC8; break;
        case 7: goto L_80004080; break;
        case 8: goto L_8000410C; break;
        case 9: goto L_800040A0; break;
        case 10: goto L_800040E0; break;
        default: switch_error(__func__, 0x80003DEC, 0x800AC918);
    }
    // 0x80003DF0: nop

L_80003DF4:
    // 0x80003DF4: lbu         $a2, 0x4($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X4);
    // 0x80003DF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80003DFC: jal         0x80004194
    // 0x80003E00: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80004194(rdram, ctx);
        goto after_0;
    // 0x80003E00: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80003E04: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003E08: lbu         $v1, 0x7B4A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4A);
    // 0x80003E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E10: bne         $v1, $v0, L_80003E1C
    if (ctx->r3 != ctx->r2) {
        // 0x80003E14: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80003E1C;
    }
    // 0x80003E14: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80003E18: lbu         $s0, 0x4($s3)
    ctx->r16 = MEM_BU(ctx->r19, 0X4);
L_80003E1C:
    // 0x80003E1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003E20: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x80003E24: beq         $v0, $zero, L_80003E4C
    if (ctx->r2 == 0) {
        // 0x80003E28: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_80003E4C;
    }
    // 0x80003E28: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80003E2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003E30: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003E34: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x80003E38: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80003E3C: bne         $v0, $zero, L_8000410C
    if (ctx->r2 != 0) {
        // 0x80003E40: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000410C;
    }
    // 0x80003E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E44: j           L_80003E60
    // 0x80003E48: nop

        goto L_80003E60;
    // 0x80003E48: nop

L_80003E4C:
    // 0x80003E4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80003E50: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80003E54: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x80003E58: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x80003E5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000410C;
    }
    // 0x80003E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003E60:
    // 0x80003E60: j           L_8000410C
    // 0x80003E64: sb          $v0, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r2;
        goto L_8000410C;
    // 0x80003E64: sb          $v0, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r2;
L_80003E68:
    // 0x80003E68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003E6C: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003E70: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80003E74: beq         $v0, $zero, L_80003E88
    if (ctx->r2 == 0) {
        // 0x80003E78: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_80003E88;
    }
    // 0x80003E78: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80003E7C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003E80: j           L_80004100
    // 0x80003E84: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
        goto L_80004100;
    // 0x80003E84: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
L_80003E88:
    // 0x80003E88: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003E8C: lbu         $v0, 0x2072($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2072);
    // 0x80003E90: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x80003E94: nop
    
            goto L_8000410C;
    }
    // 0x80003E94: nop

    // 0x80003E98: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x80003E9C: bne         $v0, $zero, L_80003EB4
    if (ctx->r2 != 0) {
        // 0x80003EA0: addiu       $a1, $s1, -0x8
        ctx->r5 = ADD32(ctx->r17, -0X8);
            goto L_80003EB4;
    }
    // 0x80003EA0: addiu       $a1, $s1, -0x8
    ctx->r5 = ADD32(ctx->r17, -0X8);
    // 0x80003EA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003EA8: addiu       $a0, $a0, -0x3770
    ctx->r4 = ADD32(ctx->r4, -0X3770);
    // 0x80003EAC: j           L_80004104
    // 0x80003EB0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
        goto L_80004104;
    // 0x80003EB0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_80003EB4:
    // 0x80003EB4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003EB8: addiu       $a0, $a0, -0x3760
    ctx->r4 = ADD32(ctx->r4, -0X3760);
    // 0x80003EBC: j           L_80004100
    // 0x80003EC0: addiu       $a1, $s1, -0x4
    ctx->r5 = ADD32(ctx->r17, -0X4);
        goto L_80004100;
    // 0x80003EC0: addiu       $a1, $s1, -0x4
    ctx->r5 = ADD32(ctx->r17, -0X4);
L_80003EC4:
    // 0x80003EC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003EC8: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003ECC: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80003ED0: beq         $v0, $zero, L_80003EE4
    if (ctx->r2 == 0) {
        // 0x80003ED4: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_80003EE4;
    }
    // 0x80003ED4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80003ED8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003EDC: j           L_80004100
    // 0x80003EE0: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
        goto L_80004100;
    // 0x80003EE0: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
L_80003EE4:
    // 0x80003EE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003EE8: lbu         $v0, 0x2072($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2072);
    // 0x80003EEC: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x80003EF0: nop
    
            goto L_8000410C;
    }
    // 0x80003EF0: nop

    // 0x80003EF4: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x80003EF8: bne         $v0, $zero, L_80003F10
    if (ctx->r2 != 0) {
        // 0x80003EFC: addiu       $a1, $s1, -0x8
        ctx->r5 = ADD32(ctx->r17, -0X8);
            goto L_80003F10;
    }
    // 0x80003EFC: addiu       $a1, $s1, -0x8
    ctx->r5 = ADD32(ctx->r17, -0X8);
    // 0x80003F00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003F04: addiu       $a0, $a0, -0x3770
    ctx->r4 = ADD32(ctx->r4, -0X3770);
    // 0x80003F08: j           L_80004104
    // 0x80003F0C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
        goto L_80004104;
    // 0x80003F0C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_80003F10:
    // 0x80003F10: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003F14: addiu       $a0, $a0, -0x3760
    ctx->r4 = ADD32(ctx->r4, -0X3760);
    // 0x80003F18: j           L_80004100
    // 0x80003F1C: addiu       $a1, $s1, -0x4
    ctx->r5 = ADD32(ctx->r17, -0X4);
        goto L_80004100;
    // 0x80003F1C: addiu       $a1, $s1, -0x4
    ctx->r5 = ADD32(ctx->r17, -0X4);
L_80003F20:
    // 0x80003F20: lh          $a2, 0x6($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X6);
    // 0x80003F24: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003F28: addiu       $a1, $a1, -0x3750
    ctx->r5 = ADD32(ctx->r5, -0X3750);
    // 0x80003F2C: jal         0x80066CA0
    // 0x80003F30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x80003F30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80003F34: j           L_800040FC
    // 0x80003F38: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800040FC;
    // 0x80003F38: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80003F3C:
    // 0x80003F3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003F40: lbu         $v0, 0x7BA1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA1);
    // 0x80003F44: beq         $v0, $zero, L_80003F5C
    if (ctx->r2 == 0) {
        // 0x80003F48: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_80003F5C;
    }
    // 0x80003F48: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80003F4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003F50: addiu       $a0, $a0, -0x3740
    ctx->r4 = ADD32(ctx->r4, -0X3740);
    // 0x80003F54: j           L_80004100
    // 0x80003F58: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
        goto L_80004100;
    // 0x80003F58: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
L_80003F5C:
    // 0x80003F5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80003F60: lbu         $v1, 0x7B70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B70);
    // 0x80003F64: bne         $v1, $v0, L_80003FA8
    if (ctx->r3 != ctx->r2) {
        // 0x80003F68: nop
    
            goto L_80003FA8;
    }
    // 0x80003F68: nop

    // 0x80003F6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003F70: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003F74: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80003F78: beq         $v0, $zero, L_80003FA8
    if (ctx->r2 == 0) {
        // 0x80003F7C: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_80003FA8;
    }
    // 0x80003F7C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80003F80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003F84: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
    // 0x80003F88: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80003F8C: jal         0x8004DAB8
    // 0x80003F90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x80003F90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80003F94: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003F98: addiu       $a0, $a0, -0x3734
    ctx->r4 = ADD32(ctx->r4, -0X3734);
    // 0x80003F9C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // 0x80003FA0: j           L_80004104
    // 0x80003FA4: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
        goto L_80004104;
    // 0x80003FA4: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
L_80003FA8:
    // 0x80003FA8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003FAC: addiu       $a0, $a0, -0x372C
    ctx->r4 = ADD32(ctx->r4, -0X372C);
    // 0x80003FB0: j           L_80004100
    // 0x80003FB4: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
        goto L_80004100;
    // 0x80003FB4: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
L_80003FB8:
    // 0x80003FB8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003FBC: addiu       $a0, $a0, -0x3740
    ctx->r4 = ADD32(ctx->r4, -0X3740);
    // 0x80003FC0: j           L_80004100
    // 0x80003FC4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
        goto L_80004100;
    // 0x80003FC4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
L_80003FC8:
    // 0x80003FC8: lbu         $v0, 0x4($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X4);
    // 0x80003FCC: bne         $v0, $zero, L_80003FD8
    if (ctx->r2 != 0) {
        // 0x80003FD0: addiu       $s0, $zero, 0xC8
        ctx->r16 = ADD32(0, 0XC8);
            goto L_80003FD8;
    }
    // 0x80003FD0: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x80003FD4: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
L_80003FD8:
    // 0x80003FD8: lbu         $a2, 0xD($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0XD);
    // 0x80003FDC: sltiu       $v0, $a2, 0x3
    ctx->r2 = ctx->r6 < 0X3 ? 1 : 0;
    // 0x80003FE0: beq         $v0, $zero, L_80003FEC
    if (ctx->r2 == 0) {
        // 0x80003FE4: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80003FEC;
    }
    // 0x80003FE4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80003FE8: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80003FEC:
    // 0x80003FEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80003FF0: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80003FF4: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80003FF8: beq         $v0, $zero, L_80004028
    if (ctx->r2 == 0) {
        // 0x80003FFC: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80004028;
    }
    // 0x80003FFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004000: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004004: addiu       $a0, $a0, -0x3720
    ctx->r4 = ADD32(ctx->r4, -0X3720);
    // 0x80004008: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8000400C: jal         0x8004DAB8
    // 0x80004010: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_3;
    // 0x80004010: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x80004014: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004018: addiu       $a0, $a0, -0x3718
    ctx->r4 = ADD32(ctx->r4, -0X3718);
    // 0x8000401C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004020: j           L_8000405C
    // 0x80004024: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
        goto L_8000405C;
    // 0x80004024: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_80004028:
    // 0x80004028: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8000402C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004030: addiu       $a1, $a1, -0x3710
    ctx->r5 = ADD32(ctx->r5, -0X3710);
    // 0x80004034: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80004038: sll         $a3, $v1, 1
    ctx->r7 = S32(ctx->r3 << 1);
    // 0x8000403C: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80004040: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004044: addiu       $v0, $v0, -0x3DC4
    ctx->r2 = ADD32(ctx->r2, -0X3DC4);
    // 0x80004048: jal         0x80066CA0
    // 0x8000404C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    func_80066CA0(rdram, ctx);
        goto after_4;
    // 0x8000404C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    after_4:
    // 0x80004050: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80004054: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004058: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_8000405C:
    // 0x8000405C: jal         0x8004DAB8
    // 0x80004060: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x80004060: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x80004064: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    // 0x80004068: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x8000406C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80004070: jal         0x8004EC44
    // 0x80004074: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_6;
    // 0x80004074: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x80004078: j           L_8000410C
    // 0x8000407C: nop

        goto L_8000410C;
    // 0x8000407C: nop

L_80004080:
    // 0x80004080: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004084: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80004088: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8000408C: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x80004090: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_8000410C;
    }
    // 0x80004090: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80004094: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004098: j           L_80004100
    // 0x8000409C: addiu       $a0, $a0, -0x3740
    ctx->r4 = ADD32(ctx->r4, -0X3740);
        goto L_80004100;
    // 0x8000409C: addiu       $a0, $a0, -0x3740
    ctx->r4 = ADD32(ctx->r4, -0X3740);
L_800040A0:
    // 0x800040A0: lbu         $a2, 0x68($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X68);
    // 0x800040A4: beq         $a2, $zero, L_8000410C
    if (ctx->r6 == 0) {
        // 0x800040A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000410C;
    }
    // 0x800040A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800040AC: bne         $a2, $v0, L_800040C4
    if (ctx->r6 != ctx->r2) {
        // 0x800040B0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800040C4;
    }
    // 0x800040B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800040B4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800040B8: addiu       $a1, $a1, -0x3708
    ctx->r5 = ADD32(ctx->r5, -0X3708);
    // 0x800040BC: j           L_800040CC
    // 0x800040C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800040CC;
    // 0x800040C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800040C4:
    // 0x800040C4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800040C8: addiu       $a1, $a1, -0x3700
    ctx->r5 = ADD32(ctx->r5, -0X3700);
L_800040CC:
    // 0x800040CC: jal         0x80066CA0
    // 0x800040D0: nop

    func_80066CA0(rdram, ctx);
        goto after_7;
    // 0x800040D0: nop

    after_7:
    // 0x800040D4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800040D8: j           L_80004100
    // 0x800040DC: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
        goto L_80004100;
    // 0x800040DC: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
L_800040E0:
    // 0x800040E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800040E4: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x800040E8: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x800040EC: beq         $v0, $zero, L_8000410C
    if (ctx->r2 == 0) {
        // 0x800040F0: nop
    
            goto L_8000410C;
    }
    // 0x800040F0: nop

    // 0x800040F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800040F8: addiu       $a0, $a0, -0x36F4
    ctx->r4 = ADD32(ctx->r4, -0X36F4);
L_800040FC:
    // 0x800040FC: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
L_80004100:
    // 0x80004100: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_80004104:
    // 0x80004104: jal         0x8004DAB8
    // 0x80004108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_8;
    // 0x80004108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_8:
L_8000410C:
    // 0x8000410C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80004110: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80004114: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80004118: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000411C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80004120: jr          $ra
    // 0x80004124: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004124: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80004128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000412C: bne         $a0, $zero, L_8000414C
    if (ctx->r4 != 0) {
        // 0x80004130: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8000414C;
    }
    // 0x80004130: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004134: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80004138: lbu         $a2, 0x7B40($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B40);
    // 0x8000413C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80004140: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004144: j           L_80004180
    // 0x80004148: addiu       $a1, $a1, -0x36BC
    ctx->r5 = ADD32(ctx->r5, -0X36BC);
        goto L_80004180;
    // 0x80004148: addiu       $a1, $a1, -0x36BC
    ctx->r5 = ADD32(ctx->r5, -0X36BC);
L_8000414C:
    // 0x8000414C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004150: lbu         $v0, 0x7B40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B40);
    // 0x80004154: subu        $a2, $v0, $a0
    ctx->r6 = SUB32(ctx->r2, ctx->r4);
    // 0x80004158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000415C: bne         $a2, $v0, L_80004178
    if (ctx->r6 != ctx->r2) {
        // 0x80004160: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_80004178;
    }
    // 0x80004160: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80004164: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004168: jal         0x80066CA0
    // 0x8000416C: addiu       $a1, $a1, -0x3860
    ctx->r5 = ADD32(ctx->r5, -0X3860);
    func_80066CA0(rdram, ctx);
        goto after_0;
    // 0x8000416C: addiu       $a1, $a1, -0x3860
    ctx->r5 = ADD32(ctx->r5, -0X3860);
    after_0:
    // 0x80004170: j           L_80004188
    // 0x80004174: nop

        goto L_80004188;
    // 0x80004174: nop

L_80004178:
    // 0x80004178: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000417C: addiu       $a1, $a1, -0x36AC
    ctx->r5 = ADD32(ctx->r5, -0X36AC);
L_80004180:
    // 0x80004180: jal         0x80066CA0
    // 0x80004184: nop

    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x80004184: nop

    after_1:
L_80004188:
    // 0x80004188: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000418C: jr          $ra
    // 0x80004190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004194: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004198: lbu         $v0, 0x7B4A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4A);
    // 0x8000419C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800041A0: lhu         $v1, 0x7BC0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X7BC0);
    // 0x800041A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800041A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800041AC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800041B0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800041B4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800041B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800041BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800041C0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800041C4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800041C8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800041CC: and         $a0, $v0, $a2
    ctx->r4 = ctx->r2 & ctx->r6;
    // 0x800041D0: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x800041D4: beq         $v0, $zero, L_800043D4
    if (ctx->r2 == 0) {
        // 0x800041D8: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_800043D4;
    }
    // 0x800041D8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800041DC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800041E0: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x800041E4: beq         $v0, $zero, L_80004294
    if (ctx->r2 == 0) {
        // 0x800041E8: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_80004294;
    }
    // 0x800041E8: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x800041EC: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800041F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800041F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800041F8: lbu         $v0, 0x7B38($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X7B38);
    // 0x800041FC: bne         $v0, $zero, L_8000424C
    if (ctx->r2 != 0) {
        // 0x80004200: nop
    
            goto L_8000424C;
    }
    // 0x80004200: nop

    // 0x80004204: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004208: addiu       $a1, $a1, -0x3694
    ctx->r5 = ADD32(ctx->r5, -0X3694);
    // 0x8000420C: jal         0x80066CA0
    // 0x80004210: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_0;
    // 0x80004210: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80004214: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004218: addiu       $a1, $a1, -0x368C
    ctx->r5 = ADD32(ctx->r5, -0X368C);
    // 0x8000421C: jal         0x80066CA0
    // 0x80004220: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x80004220: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80004224: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80004228: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x8000422C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004230: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80004234: jal         0x8004DAB8
    // 0x80004238: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x80004238: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8000423C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80004240: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004244: j           L_80004424
    // 0x80004248: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
        goto L_80004424;
    // 0x80004248: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
L_8000424C:
    // 0x8000424C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004250: addiu       $a1, $a1, -0x3684
    ctx->r5 = ADD32(ctx->r5, -0X3684);
    // 0x80004254: jal         0x80066CA0
    // 0x80004258: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x80004258: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8000425C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004260: addiu       $a1, $a1, -0x367C
    ctx->r5 = ADD32(ctx->r5, -0X367C);
    // 0x80004264: jal         0x80066CA0
    // 0x80004268: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80066CA0(rdram, ctx);
        goto after_4;
    // 0x80004268: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x8000426C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80004270: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x80004274: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004278: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8000427C: jal         0x8004DAB8
    // 0x80004280: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x80004280: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80004284: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80004288: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8000428C: j           L_80004424
    // 0x80004290: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
        goto L_80004424;
    // 0x80004290: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
L_80004294:
    // 0x80004294: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80004298: lbu         $a1, 0x7B40($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B40);
    // 0x8000429C: bne         $a1, $a3, L_800042DC
    if (ctx->r5 != ctx->r7) {
        // 0x800042A0: sra         $v0, $v0, 22
        ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
            goto L_800042DC;
    }
    // 0x800042A0: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800042A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800042A8: lbu         $v0, 0x207E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207E);
    // 0x800042AC: beq         $v0, $zero, L_800042BC
    if (ctx->r2 == 0) {
        // 0x800042B0: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_800042BC;
    }
    // 0x800042B0: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800042B4: beq         $v0, $zero, L_800042CC
    if (ctx->r2 == 0) {
        // 0x800042B8: nop
    
            goto L_800042CC;
    }
    // 0x800042B8: nop

L_800042BC:
    // 0x800042BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800042C0: addiu       $a0, $a0, -0x3830
    ctx->r4 = ADD32(ctx->r4, -0X3830);
    // 0x800042C4: j           L_80004420
    // 0x800042C8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
        goto L_80004420;
    // 0x800042C8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_800042CC:
    // 0x800042CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800042D0: addiu       $a0, $a0, -0x3658
    ctx->r4 = ADD32(ctx->r4, -0X3658);
    // 0x800042D4: j           L_80004420
    // 0x800042D8: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
        goto L_80004420;
    // 0x800042D8: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
L_800042DC:
    // 0x800042DC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800042E0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800042E4: lbu         $a2, 0x7B3A($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B3A);
    // 0x800042E8: bnel        $a2, $zero, L_8000436C
    if (ctx->r6 != 0) {
        // 0x800042EC: subu        $a2, $a1, $a2
        ctx->r6 = SUB32(ctx->r5, ctx->r6);
            goto L_8000436C;
    }
    goto skip_0;
    // 0x800042EC: subu        $a2, $a1, $a2
    ctx->r6 = SUB32(ctx->r5, ctx->r6);
    skip_0:
    // 0x800042F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800042F4: lbu         $v0, 0x207E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X207E);
    // 0x800042F8: beq         $v0, $zero, L_80004308
    if (ctx->r2 == 0) {
        // 0x800042FC: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_80004308;
    }
    // 0x800042FC: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80004300: beq         $v0, $zero, L_8000435C
    if (ctx->r2 == 0) {
        // 0x80004304: nop
    
            goto L_8000435C;
    }
    // 0x80004304: nop

L_80004308:
    // 0x80004308: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x8000430C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004310: addiu       $a1, $a1, -0x3694
    ctx->r5 = ADD32(ctx->r5, -0X3694);
    // 0x80004314: jal         0x80066CA0
    // 0x80004318: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_6;
    // 0x80004318: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8000431C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80004320: lbu         $a2, 0x7B40($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B40);
    // 0x80004324: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004328: addiu       $a1, $a1, -0x3674
    ctx->r5 = ADD32(ctx->r5, -0X3674);
    // 0x8000432C: jal         0x80066CA0
    // 0x80004330: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80066CA0(rdram, ctx);
        goto after_7;
    // 0x80004330: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x80004334: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004338: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x8000433C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004340: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80004344: jal         0x8004DAB8
    // 0x80004348: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_8;
    // 0x80004348: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_8:
    // 0x8000434C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80004350: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80004354: j           L_80004424
    // 0x80004358: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
        goto L_80004424;
    // 0x80004358: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
L_8000435C:
    // 0x8000435C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004360: addiu       $a0, $a0, -0x3658
    ctx->r4 = ADD32(ctx->r4, -0X3658);
    // 0x80004364: j           L_80004420
    // 0x80004368: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
        goto L_80004420;
    // 0x80004368: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
L_8000436C:
    // 0x8000436C: bne         $a2, $a3, L_80004390
    if (ctx->r6 != ctx->r7) {
        // 0x80004370: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80004390;
    }
    // 0x80004370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80004374: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004378: jal         0x80066CA0
    // 0x8000437C: addiu       $a1, $a1, -0x3684
    ctx->r5 = ADD32(ctx->r5, -0X3684);
    func_80066CA0(rdram, ctx);
        goto after_9;
    // 0x8000437C: addiu       $a1, $a1, -0x3684
    ctx->r5 = ADD32(ctx->r5, -0X3684);
    after_9:
    // 0x80004380: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004384: addiu       $a1, $a1, -0x367C
    ctx->r5 = ADD32(ctx->r5, -0X367C);
    // 0x80004388: j           L_800043A8
    // 0x8000438C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_800043A8;
    // 0x8000438C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_80004390:
    // 0x80004390: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004394: jal         0x80066CA0
    // 0x80004398: addiu       $a1, $a1, -0x3668
    ctx->r5 = ADD32(ctx->r5, -0X3668);
    func_80066CA0(rdram, ctx);
        goto after_10;
    // 0x80004398: addiu       $a1, $a1, -0x3668
    ctx->r5 = ADD32(ctx->r5, -0X3668);
    after_10:
    // 0x8000439C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800043A0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800043A4: addiu       $a1, $a1, -0x3660
    ctx->r5 = ADD32(ctx->r5, -0X3660);
L_800043A8:
    // 0x800043A8: jal         0x80066CA0
    // 0x800043AC: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_11;
    // 0x800043AC: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    after_11:
    // 0x800043B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800043B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800043B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800043BC: jal         0x8004DAB8
    // 0x800043C0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_12;
    // 0x800043C0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
    // 0x800043C4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800043C8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800043CC: j           L_80004424
    // 0x800043D0: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
        goto L_80004424;
    // 0x800043D0: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
L_800043D4:
    // 0x800043D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800043D8: lbu         $v0, 0x2072($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2072);
    // 0x800043DC: beq         $v0, $zero, L_8000442C
    if (ctx->r2 == 0) {
        // 0x800043E0: nop
    
            goto L_8000442C;
    }
    // 0x800043E0: nop

    // 0x800043E4: bne         $a2, $zero, L_800043F8
    if (ctx->r6 != 0) {
        // 0x800043E8: nop
    
            goto L_800043F8;
    }
    // 0x800043E8: nop

    // 0x800043EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800043F0: j           L_80004400
    // 0x800043F4: lbu         $v0, 0x25FA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25FA);
        goto L_80004400;
    // 0x800043F4: lbu         $v0, 0x25FA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25FA);
L_800043F8:
    // 0x800043F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800043FC: lbu         $v0, 0x7A4A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A4A);
L_80004400:
    // 0x80004400: bne         $v0, $zero, L_80004418
    if (ctx->r2 != 0) {
        // 0x80004404: addiu       $a1, $s2, -0x4
        ctx->r5 = ADD32(ctx->r18, -0X4);
            goto L_80004418;
    }
    // 0x80004404: addiu       $a1, $s2, -0x4
    ctx->r5 = ADD32(ctx->r18, -0X4);
    // 0x80004408: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000440C: addiu       $a0, $a0, -0x3770
    ctx->r4 = ADD32(ctx->r4, -0X3770);
    // 0x80004410: j           L_80004420
    // 0x80004414: addiu       $a1, $s2, -0x8
    ctx->r5 = ADD32(ctx->r18, -0X8);
        goto L_80004420;
    // 0x80004414: addiu       $a1, $s2, -0x8
    ctx->r5 = ADD32(ctx->r18, -0X8);
L_80004418:
    // 0x80004418: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000441C: addiu       $a0, $a0, -0x3760
    ctx->r4 = ADD32(ctx->r4, -0X3760);
L_80004420:
    // 0x80004420: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
L_80004424:
    // 0x80004424: jal         0x8004DAB8
    // 0x80004428: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_13;
    // 0x80004428: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_13:
L_8000442C:
    // 0x8000442C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80004430: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80004434: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80004438: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000443C: jr          $ra
    // 0x80004440: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80004440: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80004450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004454: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004458: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000445C: addiu       $a2, $a2, 0x4818
    ctx->r6 = ADD32(ctx->r6, 0X4818);
    // 0x80004460: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80004464: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80004468: addiu       $t1, $t1, 0x2A90
    ctx->r9 = ADD32(ctx->r9, 0X2A90);
    // 0x8000446C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80004470: addiu       $t0, $t0, 0x7050
    ctx->r8 = ADD32(ctx->r8, 0X7050);
    // 0x80004474: addiu       $a1, $a2, 0x2C
    ctx->r5 = ADD32(ctx->r6, 0X2C);
L_80004478:
    // 0x80004478: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000447C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80004480: addiu       $v0, $a3, 0x3E8
    ctx->r2 = ADD32(ctx->r7, 0X3E8);
    // 0x80004484: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80004488: sw          $t0, -0x28($a1)
    MEM_W(-0X28, ctx->r5) = ctx->r8;
    // 0x8000448C: sw          $t1, -0x24($a1)
    MEM_W(-0X24, ctx->r5) = ctx->r9;
    // 0x80004490: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80004494:
    // 0x80004494: sh          $zero, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = 0;
    // 0x80004498: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x8000449C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800044A0: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800044A4: bne         $v0, $zero, L_80004494
    if (ctx->r2 != 0) {
        // 0x800044A8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80004494;
    }
    // 0x800044A8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800044AC: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    // 0x800044B0: addiu       $a2, $a2, 0x54
    ctx->r6 = ADD32(ctx->r6, 0X54);
    // 0x800044B4: addiu       $t1, $t1, 0x1B0
    ctx->r9 = ADD32(ctx->r9, 0X1B0);
    // 0x800044B8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800044BC: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800044C0: bne         $v0, $zero, L_80004478
    if (ctx->r2 != 0) {
        // 0x800044C4: addiu       $t0, $t0, 0x2000
        ctx->r8 = ADD32(ctx->r8, 0X2000);
            goto L_80004478;
    }
    // 0x800044C4: addiu       $t0, $t0, 0x2000
    ctx->r8 = ADD32(ctx->r8, 0X2000);
    // 0x800044C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800044CC: addiu       $a0, $a0, 0x7798
    ctx->r4 = ADD32(ctx->r4, 0X7798);
    // 0x800044D0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800044D4: addiu       $a1, $a1, -0x3460
    ctx->r5 = ADD32(ctx->r5, -0X3460);
    // 0x800044D8: jal         0x80061740
    // 0x800044DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800044DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800044E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800044E4: jr          $ra
    // 0x800044E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800044E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800044EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800044F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800044F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800044F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800044FC: jal         0x80004800
    // 0x80004500: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80004800(rdram, ctx);
        goto after_0;
    // 0x80004500: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80004504: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004508: addiu       $v0, $v0, 0x4818
    ctx->r2 = ADD32(ctx->r2, 0X4818);
    // 0x8000450C: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80004510: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80004514: addiu       $s0, $v0, 0xFC
    ctx->r16 = ADD32(ctx->r2, 0XFC);
    // 0x80004518: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000451C: sw          $v0, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r2;
L_80004520:
    // 0x80004520: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80004524: lw          $a0, -0x3388($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3388);
    // 0x80004528: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8000452C: beq         $v0, $s2, L_80004544
    if (ctx->r2 == ctx->r18) {
        // 0x80004530: nop
    
            goto L_80004544;
    }
    // 0x80004530: nop

    // 0x80004534: bne         $v0, $s1, L_80004568
    if (ctx->r2 != ctx->r17) {
        // 0x80004538: nop
    
            goto L_80004568;
    }
    // 0x80004538: nop

    // 0x8000453C: jal         0x80004600
    // 0x80004540: nop

    func_80004600(rdram, ctx);
        goto after_1;
    // 0x80004540: nop

    after_1:
L_80004544:
    // 0x80004544: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80004548: lw          $v0, -0x3388($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3388);
    // 0x8000454C: jal         0x80061C60
    // 0x80004550: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80004550: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_2:
    // 0x80004554: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004558: addiu       $a0, $a0, 0x7798
    ctx->r4 = ADD32(ctx->r4, 0X7798);
    // 0x8000455C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80004560: jal         0x800619A0
    // 0x80004564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80004564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_80004568:
    // 0x80004568: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000456C: lw          $v0, -0x3388($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3388);
    // 0x80004570: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // 0x80004574: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80004578: sw          $v0, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r2;
    // 0x8000457C: sltu        $v0, $v0, $s0
    ctx->r2 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80004580: bne         $v0, $zero, L_80004520
    if (ctx->r2 != 0) {
        // 0x80004584: nop
    
            goto L_80004520;
    }
    // 0x80004584: nop

    // 0x80004588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000458C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004590: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004594: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80004598: jr          $ra
    // 0x8000459C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000459C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800045A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800045A4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800045A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800045AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800045B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800045B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800045B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800045BC: addiu       $v1, $v1, 0x4818
    ctx->r3 = ADD32(ctx->r3, 0X4818);
    // 0x800045C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800045C4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800045C8: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800045CC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800045D0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800045D4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800045D8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800045DC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800045E0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800045E4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800045E8: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x800045EC: jal         0x80061770
    // 0x800045F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800045F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x800045F4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800045F8: jr          $ra
    // 0x800045FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800045FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80004600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004604: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80004608: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000460C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80004610: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80004614: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80004618: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000461C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80004620: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80004624: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80004628: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x8000462C: lw          $a2, 0x30($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X30);
    // 0x80004630: jal         0x80061770
    // 0x80004634: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80004634: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80004638: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000463C: jr          $ra
    // 0x80004640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80004640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80004644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004648: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000464C: lw          $v1, -0x3388($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3388);
    // 0x80004650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80004658: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000465C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004660: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x80004664: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004668: addiu       $a0, $a0, 0x7798
    ctx->r4 = ADD32(ctx->r4, 0X7798);
    // 0x8000466C: jal         0x80061AD0
    // 0x80004670: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004670: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    after_0:
    // 0x80004674: jal         0x80061D80
    // 0x80004678: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80004678: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x8000467C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004680: jr          $ra
    // 0x80004684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004688: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000468C: lw          $v0, -0x3388($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3388);
    // 0x80004690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80004698: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000469C: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x800046A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800046A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800046A8: addiu       $v0, $v0, 0x7050
    ctx->r2 = ADD32(ctx->r2, 0X7050);
    // 0x800046AC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800046B0: addiu       $v1, $v1, -0x3E8
    ctx->r3 = ADD32(ctx->r3, -0X3E8);
    // 0x800046B4: sll         $v1, $v1, 13
    ctx->r3 = S32(ctx->r3 << 13);
    // 0x800046B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800046BC: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_800046C0:
    // 0x800046C0: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x800046C4: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800046C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800046CC: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800046D0: bne         $v0, $zero, L_800046C0
    if (ctx->r2 != 0) {
        // 0x800046D4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800046C0;
    }
    // 0x800046D4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800046D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800046DC: addiu       $a0, $a0, 0x7798
    ctx->r4 = ADD32(ctx->r4, 0X7798);
    // 0x800046E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800046E4: jal         0x80061AD0
    // 0x800046E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800046E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800046EC: jal         0x80061840
    // 0x800046F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800046F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800046F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800046F8: jr          $ra
    // 0x800046FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800046FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004704: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80004708: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000470C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004710: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80004714: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004718: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000471C: addiu       $v1, $v1, 0x4818
    ctx->r3 = ADD32(ctx->r3, 0X4818);
    // 0x80004720: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // 0x80004724: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004728: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x8000472C: beq         $v0, $zero, L_80004774
    if (ctx->r2 == 0) {
        // 0x80004730: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80004774;
    }
    // 0x80004730: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80004734: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80004738: sll         $v0, $a0, 13
    ctx->r2 = S32(ctx->r4 << 13);
    // 0x8000473C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80004740: addiu       $v1, $v1, 0x7050
    ctx->r3 = ADD32(ctx->r3, 0X7050);
    // 0x80004744: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80004748: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x8000474C: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80004750:
    // 0x80004750: sh          $zero, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = 0;
    // 0x80004754: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x80004758: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000475C: slti        $v0, $a2, 0x8
    ctx->r2 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x80004760: bne         $v0, $zero, L_80004750
    if (ctx->r2 != 0) {
        // 0x80004764: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80004750;
    }
    // 0x80004764: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80004768: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x8000476C: jal         0x80061840
    // 0x80004770: nop

    osDestroyThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80004770: nop

    after_0:
L_80004774:
    // 0x80004774: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004778: jr          $ra
    // 0x8000477C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000477C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004780: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80004784: lw          $v1, -0x3388($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3388);
    // 0x80004788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000478C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80004790: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004794: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80004798: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8000479C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800047A0: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x800047A4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800047A8: addiu       $v1, $v1, 0x7050
    ctx->r3 = ADD32(ctx->r3, 0X7050);
    // 0x800047AC: sw          $a0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r4;
    // 0x800047B0: addiu       $v0, $v0, -0x3E8
    ctx->r2 = ADD32(ctx->r2, -0X3E8);
    // 0x800047B4: sll         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2 << 13);
    // 0x800047B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800047BC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_800047C0:
    // 0x800047C0: sh          $zero, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = 0;
    // 0x800047C4: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800047C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800047CC: slti        $v0, $a2, 0x8
    ctx->r2 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x800047D0: bne         $v0, $zero, L_800047C0
    if (ctx->r2 != 0) {
        // 0x800047D4: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800047C0;
    }
    // 0x800047D4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800047D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800047DC: addiu       $a0, $a0, 0x7798
    ctx->r4 = ADD32(ctx->r4, 0X7798);
    // 0x800047E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800047E4: jal         0x80061AD0
    // 0x800047E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800047E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800047EC: jal         0x80061840
    // 0x800047F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800047F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800047F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800047F8: jr          $ra
    // 0x800047FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800047FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004800: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004804: addiu       $v0, $v0, 0x4818
    ctx->r2 = ADD32(ctx->r2, 0X4818);
    // 0x80004808: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000480C: sw          $v0, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r2;
    // 0x80004810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004814: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80004818: addiu       $a0, $v0, 0xFC
    ctx->r4 = ADD32(ctx->r2, 0XFC);
L_8000481C:
    // 0x8000481C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80004820: lw          $v1, -0x3388($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3388);
    // 0x80004824: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80004828: bne         $v0, $a2, L_80004848
    if (ctx->r2 != ctx->r6) {
        // 0x8000482C: nop
    
            goto L_80004848;
    }
    // 0x8000482C: nop

    // 0x80004830: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80004834: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004838: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x8000483C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80004840: beql        $v0, $zero, L_80004848
    if (ctx->r2 == 0) {
        // 0x80004844: sh          $a1, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r5;
            goto L_80004848;
    }
    goto skip_0;
    // 0x80004844: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    skip_0:
L_80004848:
    // 0x80004848: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8000484C: lw          $v0, -0x3388($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3388);
    // 0x80004850: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // 0x80004854: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80004858: sw          $v0, -0x3388($at)
    MEM_W(-0X3388, ctx->r1) = ctx->r2;
    // 0x8000485C: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80004860: bne         $v0, $zero, L_8000481C
    if (ctx->r2 != 0) {
        // 0x80004864: nop
    
            goto L_8000481C;
    }
    // 0x80004864: nop

    // 0x80004868: jr          $ra
    // 0x8000486C: nop

    return;
    // 0x8000486C: nop

;}
RECOMP_FUNC void func_80004870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004870: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004874: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80004878: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000487C: addiu       $s0, $s0, 0x49A0
    ctx->r16 = ADD32(ctx->r16, 0X49A0);
    // 0x80004880: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004884: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80004888: addiu       $a1, $a1, 0x49B8
    ctx->r5 = ADD32(ctx->r5, 0X49B8);
    // 0x8000488C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004890: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004894: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80004898: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8000489C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800048A0: jal         0x80061740
    // 0x800048A4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800048A4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800048A8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800048AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800048B0: jal         0x80061C00
    // 0x800048B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800048B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800048B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800048BC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800048C0: addiu       $s0, $s0, 0x2087
    ctx->r16 = ADD32(ctx->r16, 0X2087);
    // 0x800048C4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800048C8: addiu       $a2, $a2, 0x49C0
    ctx->r6 = ADD32(ctx->r6, 0X49C0);
    // 0x800048CC: jal         0x80066490
    // 0x800048D0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800048D0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800048D4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800048D8: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x800048DC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800048E0: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800048E4: addiu       $s2, $s2, 0x49F8
    ctx->r18 = ADD32(ctx->r18, 0X49F8);
    // 0x800048E8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800048EC:
    // 0x800048EC: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800048F0: srav        $v0, $v0, $s1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r17 & 31));
    // 0x800048F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800048F8: beql        $v0, $zero, L_80004974
    if (ctx->r2 == 0) {
        // 0x800048FC: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_80004974;
    }
    goto skip_0;
    // 0x800048FC: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_0:
    // 0x80004900: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80004904: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004908: lhu         $v0, 0x49C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X49C0);
    // 0x8000490C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80004910: beql        $v0, $zero, L_80004974
    if (ctx->r2 == 0) {
        // 0x80004914: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_80004974;
    }
    goto skip_1;
    // 0x80004914: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_1:
    // 0x80004918: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000491C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004920: lbu         $v0, 0x49C2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49C2);
    // 0x80004924: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80004928: beql        $v0, $zero, L_80004974
    if (ctx->r2 == 0) {
        // 0x8000492C: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_80004974;
    }
    goto skip_2;
    // 0x8000492C: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_2:
    // 0x80004930: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004934: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    // 0x80004938: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8000493C: jal         0x800672B4
    // 0x80004940: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80004940: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80004944: bnel        $v0, $zero, L_80004974
    if (ctx->r2 != 0) {
        // 0x80004948: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_80004974;
    }
    goto skip_3;
    // 0x80004948: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_3:
    // 0x8000494C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80004950: jal         0x80067170
    // 0x80004954: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_4;
    // 0x80004954: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80004958: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000495C: lbu         $v0, -0x211C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X211C);
    // 0x80004960: sllv        $v1, $s3, $s1
    ctx->r3 = S32(ctx->r19 << (ctx->r17 & 31));
    // 0x80004964: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80004968: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000496C: sb          $v0, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r2;
    // 0x80004970: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
L_80004974:
    // 0x80004974: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80004978: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8000497C: bne         $v0, $zero, L_800048EC
    if (ctx->r2 != 0) {
        // 0x80004980: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800048EC;
    }
    // 0x80004980: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80004984: jal         0x800049B4
    // 0x80004988: nop

    func_800049B4(rdram, ctx);
        goto after_5;
    // 0x80004988: nop

    after_5:
    // 0x8000498C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004990: lw          $v0, -0x2120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2120);
    // 0x80004994: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004998: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000499C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800049A0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800049A4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800049A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800049AC: jr          $ra
    // 0x800049B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800049B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800049B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049B4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800049B8: addiu       $v1, $v1, -0x2128
    ctx->r3 = ADD32(ctx->r3, -0X2128);
    // 0x800049BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800049C0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800049C4: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, 0X49F4);
L_800049C8:
    // 0x800049C8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800049CC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800049D0: bgez        $a1, L_800049C8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800049D4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800049C8;
    }
    // 0x800049D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800049D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800049DC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800049E0: addiu       $v0, $v0, 0x4BA4
    ctx->r2 = ADD32(ctx->r2, 0X4BA4);
L_800049E4:
    // 0x800049E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800049E8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800049EC: bgez        $a1, L_800049E4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800049F0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800049E4;
    }
    // 0x800049F0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800049F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800049F8: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x800049FC: addiu       $t6, $t6, 0x2087
    ctx->r14 = ADD32(ctx->r14, 0X2087);
    // 0x80004A00: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80004A04: lb          $t1, -0x211C($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X211C);
    // 0x80004A08: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80004A0C: addiu       $t5, $t5, 0x4B98
    ctx->r13 = ADD32(ctx->r13, 0X4B98);
    // 0x80004A10: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80004A14: addiu       $t4, $t4, -0x50F0
    ctx->r12 = ADD32(ctx->r12, -0X50F0);
    // 0x80004A18: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80004A1C: addiu       $t3, $t3, 0x49E8
    ctx->r11 = ADD32(ctx->r11, 0X49E8);
    // 0x80004A20: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80004A24: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80004A28: addiu       $t0, $t0, 0x49D0
    ctx->r8 = ADD32(ctx->r8, 0X49D0);
    // 0x80004A2C: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80004A30: addiu       $a3, $a3, 0x49F8
    ctx->r7 = ADD32(ctx->r7, 0X49F8);
    // 0x80004A34: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80004A38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004A3C: sw          $zero, -0x2120($at)
    MEM_W(-0X2120, ctx->r1) = 0;
L_80004A40:
    // 0x80004A40: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80004A44: srav        $v0, $v0, $a1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r5 & 31));
    // 0x80004A48: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80004A4C: beql        $v0, $zero, L_80004ABC
    if (ctx->r2 == 0) {
        // 0x80004A50: addiu       $t0, $t0, 0x6
        ctx->r8 = ADD32(ctx->r8, 0X6);
            goto L_80004ABC;
    }
    goto skip_0;
    // 0x80004A50: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    skip_0:
    // 0x80004A54: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80004A58: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80004A5C: lbu         $v0, 0x49C3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49C3);
    // 0x80004A60: bnel        $v0, $zero, L_80004ABC
    if (ctx->r2 != 0) {
        // 0x80004A64: addiu       $t0, $t0, 0x6
        ctx->r8 = ADD32(ctx->r8, 0X6);
            goto L_80004ABC;
    }
    goto skip_1;
    // 0x80004A64: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    skip_1:
    // 0x80004A68: srav        $v0, $t1, $a1
    ctx->r2 = S32(SIGNED(ctx->r9) >> (ctx->r5 & 31));
    // 0x80004A6C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80004A70: beq         $v0, $zero, L_80004A8C
    if (ctx->r2 == 0) {
        // 0x80004A74: nop
    
            goto L_80004A8C;
    }
    // 0x80004A74: nop

    // 0x80004A78: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004A7C: lw          $v0, -0x2120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2120);
    // 0x80004A80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004A84: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80004A88: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
L_80004A8C:
    // 0x80004A8C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80004A90: lw          $a0, -0x2120($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2120);
    // 0x80004A94: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80004A98: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
    // 0x80004A9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004AA0: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80004AA4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80004AA8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004AAC: sw          $a0, -0x2120($at)
    MEM_W(-0X2120, ctx->r1) = ctx->r4;
    // 0x80004AB0: beq         $a0, $t2, L_80004AD0
    if (ctx->r4 == ctx->r10) {
        // 0x80004AB4: sw          $t0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r8;
            goto L_80004AD0;
    }
    // 0x80004AB4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80004AB8: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
L_80004ABC:
    // 0x80004ABC: addiu       $a3, $a3, 0x68
    ctx->r7 = ADD32(ctx->r7, 0X68);
    // 0x80004AC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80004AC4: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80004AC8: bne         $v0, $zero, L_80004A40
    if (ctx->r2 != 0) {
        // 0x80004ACC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80004A40;
    }
    // 0x80004ACC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80004AD0:
    // 0x80004AD0: jr          $ra
    // 0x80004AD4: nop

    return;
    // 0x80004AD4: nop

;}
RECOMP_FUNC void func_80004AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004ADC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80004AE0: lbu         $v1, 0x2071($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2071);
    // 0x80004AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004AE8: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x80004AEC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80004AF0: beq         $v1, $zero, L_80004B20
    if (ctx->r3 == 0) {
        // 0x80004AF4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80004B20;
    }
    // 0x80004AF4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004AF8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004AFC: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x80004B00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80004B04: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80004B08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004B0C: sw          $a0, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = ctx->r4;
    // 0x80004B10: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004B14: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80004B18: jal         0x80061AD0
    // 0x80004B1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004B1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_80004B20:
    // 0x80004B20: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004B24: jr          $ra
    // 0x80004B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004B30: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80004B34: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004B38: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80004B3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80004B40: lw          $v1, 0x4B98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4B98);
    // 0x80004B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004B48: beq         $v1, $zero, L_80004B88
    if (ctx->r3 == 0) {
        // 0x80004B4C: sllv        $a1, $v0, $a0
        ctx->r5 = S32(ctx->r2 << (ctx->r4 & 31));
            goto L_80004B88;
    }
    // 0x80004B4C: sllv        $a1, $v0, $a0
    ctx->r5 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x80004B50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004B54: lbu         $v0, 0x2071($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2071);
    // 0x80004B58: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80004B5C: beq         $v0, $zero, L_80004B88
    if (ctx->r2 == 0) {
        // 0x80004B60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80004B88;
    }
    // 0x80004B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004B64: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004B68: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x80004B6C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80004B70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004B74: sw          $a0, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = ctx->r4;
    // 0x80004B78: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004B7C: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80004B80: jal         0x80061AD0
    // 0x80004B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_80004B88:
    // 0x80004B88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80004B8C: jr          $ra
    // 0x80004B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004B98: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80004B9C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80004BA0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80004BA4: sll         $s1, $s3, 2
    ctx->r17 = S32(ctx->r19 << 2);
    // 0x80004BA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004BAC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80004BB0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80004BB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80004BB8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80004BBC: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // 0x80004BC0: lw          $s0, -0x50F0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X50F0);
    // 0x80004BC4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004BC8: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    // 0x80004BCC: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80004BD0: addiu       $v1, $v1, 0x49F8
    ctx->r3 = ADD32(ctx->r3, 0X49F8);
    // 0x80004BD4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80004BD8: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80004BDC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004BE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004BE4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004BE8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004BEC: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x80004BF0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80004BF4: jal         0x800672B4
    // 0x80004BF8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80004BF8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80004BFC: bne         $v0, $zero, L_80004C30
    if (ctx->r2 != 0) {
        // 0x80004C00: sllv        $v0, $s4, $s0
        ctx->r2 = S32(ctx->r20 << (ctx->r16 & 31));
            goto L_80004C30;
    }
    // 0x80004C00: sllv        $v0, $s4, $s0
    ctx->r2 = S32(ctx->r20 << (ctx->r16 & 31));
    // 0x80004C04: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004C08: lbu         $v0, -0x211C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X211C);
    // 0x80004C0C: sllv        $v1, $s4, $s0
    ctx->r3 = S32(ctx->r20 << (ctx->r16 & 31));
    // 0x80004C10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80004C14: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80004C18: sw          $s2, 0x4B98($at)
    MEM_W(0X4B98, ctx->r1) = ctx->r18;
    // 0x80004C1C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80004C20: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004C24: sb          $v0, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r2;
    // 0x80004C28: j           L_80004C58
    // 0x80004C2C: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
        goto L_80004C58;
    // 0x80004C2C: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80004C30:
    // 0x80004C30: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80004C34: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x80004C38: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80004C3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80004C40: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80004C44: sw          $zero, 0x4B98($at)
    MEM_W(0X4B98, ctx->r1) = 0;
    // 0x80004C48: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80004C4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004C50: sb          $v1, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r3;
    // 0x80004C54: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80004C58:
    // 0x80004C58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80004C5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80004C60: lw          $v0, 0x4B98($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4B98);
    // 0x80004C64: beq         $v0, $zero, L_80004C90
    if (ctx->r2 == 0) {
        // 0x80004C68: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80004C90;
    }
    // 0x80004C68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80004C6C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004C70: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80004C74: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004C78: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x80004C7C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80004C80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004C84: sw          $s3, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = ctx->r19;
    // 0x80004C88: jal         0x80061AD0
    // 0x80004C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80004C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80004C90:
    // 0x80004C90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004C94: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80004C98: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80004C9C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004CA0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004CA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80004CA8: jr          $ra
    // 0x80004CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80004CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004CB0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80004CB4: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80004CB8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80004CBC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80004CC0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80004CC4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80004CC8: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80004CCC: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80004CD0: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80004CD4: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80004CD8: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80004CDC: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80004CE0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80004CE4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80004CE8: jal         0x80061740
    // 0x80004CEC: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80004CEC: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80004CF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004CF4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80004CF8: jal         0x80000708
    // 0x80004CFC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80000708(rdram, ctx);
        goto after_1;
    // 0x80004CFC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80004D00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004D04: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    // 0x80004D08: jal         0x80066F90
    // 0x80004D0C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    osContStartReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x80004D0C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    after_2:
    // 0x80004D10: lui         $fp, 0x800B
    ctx->r30 = S32(0X800B << 16);
    // 0x80004D14: addiu       $fp, $fp, 0x4B98
    ctx->r30 = ADD32(ctx->r30, 0X4B98);
    // 0x80004D18: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80004D1C:
    // 0x80004D1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80004D20: jal         0x800619A0
    // 0x80004D24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80004D24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80004D28: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004D2C: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    // 0x80004D30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80004D34: jal         0x800619A0
    // 0x80004D38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80004D38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80004D3C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004D40: addiu       $a0, $a0, 0x49D0
    ctx->r4 = ADD32(ctx->r4, 0X49D0);
    // 0x80004D44: jal         0x80067018
    // 0x80004D48: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    osContGetReadData_recomp(rdram, ctx);
        goto after_5;
    // 0x80004D48: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_5:
    // 0x80004D4C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004D50: lw          $v0, -0x2120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2120);
    // 0x80004D54: blez        $v0, L_80005030
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80004D58: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80005030;
    }
    // 0x80004D58: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80004D5C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80004D60: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80004D64: addiu       $s6, $s6, -0x3488
    ctx->r22 = ADD32(ctx->r22, -0X3488);
    // 0x80004D68: addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
L_80004D6C:
    // 0x80004D6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004D70: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004D74: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004D78: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x80004D7C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80004D80: bne         $v0, $v1, L_80004E14
    if (ctx->r2 != ctx->r3) {
        // 0x80004D84: nop
    
            goto L_80004E14;
    }
    // 0x80004D84: nop

    // 0x80004D88: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80004D8C: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x80004D90: lw          $s0, -0x50F0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X50F0);
    // 0x80004D94: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004D98: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    // 0x80004D9C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80004DA0: addiu       $v1, $v1, 0x49F8
    ctx->r3 = ADD32(ctx->r3, 0X49F8);
    // 0x80004DA4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80004DA8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004DAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004DB0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80004DB4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004DB8: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80004DBC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80004DC0: jal         0x800672B4
    // 0x80004DC4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_6;
    // 0x80004DC4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80004DC8: bne         $v0, $zero, L_80004DF4
    if (ctx->r2 != 0) {
        // 0x80004DCC: addu        $v0, $s4, $fp
        ctx->r2 = ADD32(ctx->r20, ctx->r30);
            goto L_80004DF4;
    }
    // 0x80004DCC: addu        $v0, $s4, $fp
    ctx->r2 = ADD32(ctx->r20, ctx->r30);
    // 0x80004DD0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004DD4: lbu         $v0, -0x211C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X211C);
    // 0x80004DD8: addu        $v1, $s4, $fp
    ctx->r3 = ADD32(ctx->r20, ctx->r30);
    // 0x80004DDC: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x80004DE0: sllv        $v1, $s7, $s0
    ctx->r3 = S32(ctx->r23 << (ctx->r16 & 31));
    // 0x80004DE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80004DE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004DEC: j           L_80004E14
    // 0x80004DF0: sb          $v0, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r2;
        goto L_80004E14;
    // 0x80004DF0: sb          $v0, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r2;
L_80004DF4:
    // 0x80004DF4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80004DF8: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x80004DFC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80004E00: sllv        $v0, $s7, $s0
    ctx->r2 = S32(ctx->r23 << (ctx->r16 & 31));
    // 0x80004E04: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80004E08: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80004E0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004E10: sb          $v1, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r3;
L_80004E14:
    // 0x80004E14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004E18: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004E1C: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004E20: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80004E24: beq         $v0, $zero, L_80004E90
    if (ctx->r2 == 0) {
        // 0x80004E28: nop
    
            goto L_80004E90;
    }
    // 0x80004E28: nop

    // 0x80004E2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004E30: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004E34: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004E38: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80004E3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80004E40: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80004E44: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    // 0x80004E48: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80004E4C: beq         $v0, $zero, L_80004E90
    if (ctx->r2 == 0) {
        // 0x80004E50: sllv        $v1, $s7, $s2
        ctx->r3 = S32(ctx->r23 << (ctx->r18 & 31));
            goto L_80004E90;
    }
    // 0x80004E50: sllv        $v1, $s7, $s2
    ctx->r3 = S32(ctx->r23 << (ctx->r18 & 31));
    // 0x80004E54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004E58: lbu         $v0, 0x2071($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2071);
    // 0x80004E5C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80004E60: beq         $v0, $zero, L_80004E90
    if (ctx->r2 == 0) {
        // 0x80004E64: nop
    
            goto L_80004E90;
    }
    // 0x80004E64: nop

    // 0x80004E68: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004E6C: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80004E70: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004E74: addiu       $a1, $a1, -0x2130
    ctx->r5 = ADD32(ctx->r5, -0X2130);
    // 0x80004E78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004E7C: sh          $s7, -0x2130($at)
    MEM_H(-0X2130, ctx->r1) = ctx->r23;
    // 0x80004E80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004E84: sw          $s2, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = ctx->r18;
    // 0x80004E88: jal         0x80061AD0
    // 0x80004E8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80004E8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_80004E90:
    // 0x80004E90: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004E94: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004E98: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004E9C: beq         $v0, $zero, L_80004EE0
    if (ctx->r2 == 0) {
        // 0x80004EA0: nop
    
            goto L_80004EE0;
    }
    // 0x80004EA0: nop

    // 0x80004EA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004EA8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004EAC: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004EB0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004EB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80004EB8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80004EBC: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    // 0x80004EC0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004EC4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80004EC8: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80004ECC: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80004ED0: beq         $v0, $zero, L_80004EE0
    if (ctx->r2 == 0) {
        // 0x80004ED4: nop
    
            goto L_80004EE0;
    }
    // 0x80004ED4: nop

    // 0x80004ED8: jal         0x80004B94
    // 0x80004EDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80004B94(rdram, ctx);
        goto after_8;
    // 0x80004EDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
L_80004EE0:
    // 0x80004EE0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80004EE4: addiu       $v1, $v1, -0x38A0
    ctx->r3 = ADD32(ctx->r3, -0X38A0);
    // 0x80004EE8: addu        $v1, $s3, $v1
    ctx->r3 = ADD32(ctx->r19, ctx->r3);
    // 0x80004EEC: lwl         $v0, 0x0($v1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r3, 0X0);
    // 0x80004EF0: lwr         $v0, 0x3($v1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r3, 0X3);
    // 0x80004EF4: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x80004EF8: swl         $v0, 0x0($s6)
    do_swl(rdram, 0X0, ctx->r22, ctx->r2);
    // 0x80004EFC: swr         $v0, 0x3($s6)
    do_swr(rdram, 0X3, ctx->r22, ctx->r2);
    // 0x80004F00: sh          $a0, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r4;
    // 0x80004F04: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80004F08: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80004F0C: lw          $v0, 0x49E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X49E8);
    // 0x80004F10: lwl         $a0, 0x0($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r2, 0X0);
    // 0x80004F14: lwr         $a0, 0x3($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r2, 0X3);
    // 0x80004F18: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80004F1C: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x80004F20: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x80004F24: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x80004F28: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80004F2C: lbu         $v0, 0x2086($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2086);
    // 0x80004F30: beq         $v0, $zero, L_80004FE0
    if (ctx->r2 == 0) {
        // 0x80004F34: addiu       $v0, $zero, 0xA00
        ctx->r2 = ADD32(0, 0XA00);
            goto L_80004FE0;
    }
    // 0x80004F34: addiu       $v0, $zero, 0xA00
    ctx->r2 = ADD32(0, 0XA00);
    // 0x80004F38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004F3C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80004F40: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
    // 0x80004F44: andi        $v1, $a0, 0xA00
    ctx->r3 = ctx->r4 & 0XA00;
    // 0x80004F48: bne         $v1, $v0, L_80004F70
    if (ctx->r3 != ctx->r2) {
        // 0x80004F4C: addiu       $v0, $zero, 0x900
        ctx->r2 = ADD32(0, 0X900);
            goto L_80004F70;
    }
    // 0x80004F4C: addiu       $v0, $zero, 0x900
    ctx->r2 = ADD32(0, 0X900);
    // 0x80004F50: andi        $v0, $a0, 0xF7FF
    ctx->r2 = ctx->r4 & 0XF7FF;
    // 0x80004F54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004F58: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80004F5C: sh          $v0, -0x38A0($at)
    MEM_H(-0X38A0, ctx->r1) = ctx->r2;
    // 0x80004F60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004F64: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80004F68: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
    // 0x80004F6C: addiu       $v0, $zero, 0x900
    ctx->r2 = ADD32(0, 0X900);
L_80004F70:
    // 0x80004F70: andi        $v1, $a0, 0x900
    ctx->r3 = ctx->r4 & 0X900;
    // 0x80004F74: bne         $v1, $v0, L_80004F88
    if (ctx->r3 != ctx->r2) {
        // 0x80004F78: andi        $v0, $a0, 0xF7FF
        ctx->r2 = ctx->r4 & 0XF7FF;
            goto L_80004F88;
    }
    // 0x80004F78: andi        $v0, $a0, 0xF7FF
    ctx->r2 = ctx->r4 & 0XF7FF;
    // 0x80004F7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004F80: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80004F84: sh          $v0, -0x38A0($at)
    MEM_H(-0X38A0, ctx->r1) = ctx->r2;
L_80004F88:
    // 0x80004F88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004F8C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80004F90: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
    // 0x80004F94: addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // 0x80004F98: andi        $v1, $a0, 0x600
    ctx->r3 = ctx->r4 & 0X600;
    // 0x80004F9C: bne         $v1, $v0, L_80004FC4
    if (ctx->r3 != ctx->r2) {
        // 0x80004FA0: addiu       $v0, $zero, 0x500
        ctx->r2 = ADD32(0, 0X500);
            goto L_80004FC4;
    }
    // 0x80004FA0: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x80004FA4: andi        $v0, $a0, 0xFBFF
    ctx->r2 = ctx->r4 & 0XFBFF;
    // 0x80004FA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004FAC: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80004FB0: sh          $v0, -0x38A0($at)
    MEM_H(-0X38A0, ctx->r1) = ctx->r2;
    // 0x80004FB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004FB8: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80004FBC: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
    // 0x80004FC0: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
L_80004FC4:
    // 0x80004FC4: andi        $v1, $a0, 0x500
    ctx->r3 = ctx->r4 & 0X500;
    // 0x80004FC8: bnel        $v1, $v0, L_80004FE4
    if (ctx->r3 != ctx->r2) {
        // 0x80004FCC: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80004FE4;
    }
    goto skip_0;
    // 0x80004FCC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_0:
    // 0x80004FD0: andi        $v0, $a0, 0xFBFF
    ctx->r2 = ctx->r4 & 0XFBFF;
    // 0x80004FD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004FD8: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80004FDC: sh          $v0, -0x38A0($at)
    MEM_H(-0X38A0, ctx->r1) = ctx->r2;
L_80004FE0:
    // 0x80004FE0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80004FE4:
    // 0x80004FE4: addiu       $s6, $s6, 0x6
    ctx->r22 = ADD32(ctx->r22, 0X6);
    // 0x80004FE8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80004FEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80004FF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80004FF4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80004FF8: lhu         $v0, -0x3488($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3488);
    // 0x80004FFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80005000: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80005004: lhu         $v1, -0x38A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X38A0);
    // 0x80005008: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000500C: lw          $a0, -0x2120($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2120);
    // 0x80005010: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80005014: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80005018: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000501C: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80005020: sh          $v1, -0x33C8($at)
    MEM_H(-0X33C8, ctx->r1) = ctx->r3;
    // 0x80005024: slt         $a0, $s2, $a0
    ctx->r4 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80005028: bne         $a0, $zero, L_80004D6C
    if (ctx->r4 != 0) {
        // 0x8000502C: addiu       $s3, $s3, 0x6
        ctx->r19 = ADD32(ctx->r19, 0X6);
            goto L_80004D6C;
    }
    // 0x8000502C: addiu       $s3, $s3, 0x6
    ctx->r19 = ADD32(ctx->r19, 0X6);
L_80005030:
    // 0x80005030: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005034: jal         0x80066F90
    // 0x80005038: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_9;
    // 0x80005038: addiu       $a0, $a0, 0x49A0
    ctx->r4 = ADD32(ctx->r4, 0X49A0);
    after_9:
    // 0x8000503C: j           L_80004D1C
    // 0x80005040: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80004D1C;
    // 0x80005040: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80005044: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80005048: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8000504C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80005050: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80005054: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80005058: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8000505C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80005060: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80005064: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80005068: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8000506C: jr          $ra
    // 0x80005070: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80005070: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80005074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005074: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005078: lw          $v0, -0x2120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2120);
    // 0x8000507C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80005080: blez        $v0, L_80005104
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80005084: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80005104;
    }
    // 0x80005084: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80005088: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8000508C:
    // 0x8000508C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80005090: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80005094: lbu         $v1, -0x389D($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X389D);
    // 0x80005098: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000509C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800050A0: lbu         $v0, -0x389E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X389E);
    // 0x800050A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800050A8: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800050AC: lhu         $a0, -0x33C8($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X33C8);
    // 0x800050B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050B4: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800050B8: sb          $v1, 0x2FB3($at)
    MEM_B(0X2FB3, ctx->r1) = ctx->r3;
    // 0x800050BC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800050C0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800050C4: lhu         $v1, -0x38A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X38A0);
    // 0x800050C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050CC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800050D0: sb          $v0, 0x2FB2($at)
    MEM_B(0X2FB2, ctx->r1) = ctx->r2;
    // 0x800050D4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800050D8: lw          $v0, -0x2120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2120);
    // 0x800050DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800050E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050E4: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800050E8: sh          $a0, -0x2B50($at)
    MEM_H(-0X2B50, ctx->r1) = ctx->r4;
    // 0x800050EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050F0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800050F4: sh          $v1, 0x2FB0($at)
    MEM_H(0X2FB0, ctx->r1) = ctx->r3;
    // 0x800050F8: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800050FC: bne         $v0, $zero, L_8000508C
    if (ctx->r2 != 0) {
        // 0x80005100: addiu       $a1, $a1, 0x6
        ctx->r5 = ADD32(ctx->r5, 0X6);
            goto L_8000508C;
    }
    // 0x80005100: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
L_80005104:
    // 0x80005104: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80005108: jr          $ra
    // 0x8000510C: nop

    return;
    // 0x8000510C: nop

;}
RECOMP_FUNC void func_80005110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005114: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80005118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000511C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80005120: addiu       $s0, $s0, 0x4BA8
    ctx->r16 = ADD32(ctx->r16, 0X4BA8);
    // 0x80005124: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005128: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000512C: addiu       $v0, $v0, 0x7F10
    ctx->r2 = ADD32(ctx->r2, 0X7F10);
    // 0x80005130: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80005134: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80005138: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000513C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80005140: addiu       $a2, $a2, 0x4CB0
    ctx->r6 = ADD32(ctx->r6, 0X4CB0);
    // 0x80005144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005148: jal         0x80061770
    // 0x8000514C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8000514C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80005150: jal         0x80061C60
    // 0x80005154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80005154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80005158: jal         0x80005170
    // 0x8000515C: nop

    func_80005170(rdram, ctx);
        goto after_2;
    // 0x8000515C: nop

    after_2:
    // 0x80005160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005168: jr          $ra
    // 0x8000516C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000516C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80005170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005174: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005178: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x8000517C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80005180: addiu       $a1, $a1, 0x17E8
    ctx->r5 = ADD32(ctx->r5, 0X17E8);
    // 0x80005184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000518C: jal         0x80061740
    // 0x80005190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80005190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80005194: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80005198: addiu       $s0, $s0, 0x17F0
    ctx->r16 = ADD32(ctx->r16, 0X17F0);
    // 0x8000519C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800051A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800051A4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800051A8: addiu       $a2, $a2, 0x51E0
    ctx->r6 = ADD32(ctx->r6, 0X51E0);
    // 0x800051AC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800051B0: addiu       $v0, $v0, 0x49A0
    ctx->r2 = ADD32(ctx->r2, 0X49A0);
    // 0x800051B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800051B8: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x800051BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800051C0: jal         0x80061770
    // 0x800051C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800051C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800051C8: jal         0x80061C60
    // 0x800051CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800051CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800051D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800051D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800051D8: jr          $ra
    // 0x800051DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800051DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800051E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800051E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800051E8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800051EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800051F0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800051F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800051F8: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800051FC: addiu       $s0, $s0, 0x4B98
    ctx->r16 = ADD32(ctx->r16, 0X4B98);
    // 0x80005200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80005204:
    // 0x80005204: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005208: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x8000520C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80005210: jal         0x800619A0
    // 0x80005214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80005214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80005218: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8000521C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80005220: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80005224: beq         $v1, $s2, L_8000523C
    if (ctx->r3 == ctx->r18) {
        // 0x80005228: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_8000523C;
    }
    // 0x80005228: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000522C: beq         $v1, $s1, L_80005254
    if (ctx->r3 == ctx->r17) {
        // 0x80005230: addu        $v0, $v0, $s0
        ctx->r2 = ADD32(ctx->r2, ctx->r16);
            goto L_80005254;
    }
    // 0x80005230: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80005234: j           L_80005204
    // 0x80005238: nop

        goto L_80005204;
    // 0x80005238: nop

L_8000523C:
    // 0x8000523C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80005240: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80005244: jal         0x80067170
    // 0x80005248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_1;
    // 0x80005248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8000524C: j           L_80005204
    // 0x80005250: nop

        goto L_80005204;
    // 0x80005250: nop

L_80005254:
    // 0x80005254: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80005258: jal         0x80067170
    // 0x8000525C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x8000525C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80005260: j           L_80005204
    // 0x80005264: nop

        goto L_80005204;
    // 0x80005264: nop

    // 0x80005268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000526C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005270: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005278: jr          $ra
    // 0x8000527C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000527C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005284: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80005288: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000528C: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x80005290: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x80005294: lui         $v1, 0x7
    ctx->r3 = S32(0X7 << 16);
    // 0x80005298: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8000529C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800052A0: ori         $v0, $zero, 0xAC44
    ctx->r2 = 0 | 0XAC44;
    // 0x800052A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800052A8: sw          $v0, -0x20F8($at)
    MEM_W(-0X20F8, ctx->r1) = ctx->r2;
    // 0x800052AC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800052B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800052B4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800052B8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800052BC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800052C0:
    // 0x800052C0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800052C4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800052C8: bne         $v1, $a1, L_800052C0
    if (ctx->r3 != ctx->r5) {
        // 0x800052CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800052C0;
    }
    // 0x800052CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800052D0: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x800052D4: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x800052D8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800052DC: addiu       $a2, $a2, -0x2110
    ctx->r6 = ADD32(ctx->r6, -0X2110);
    // 0x800052E0: jal         0x80005884
    // 0x800052E4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    func_80005884(rdram, ctx);
        goto after_0;
    // 0x800052E4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_0:
    // 0x800052E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800052EC: jal         0x8000540C
    // 0x800052F0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_8000540C(rdram, ctx);
        goto after_1;
    // 0x800052F0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_1:
    // 0x800052F4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800052F8: jal         0x80005310
    // 0x800052FC: addiu       $a0, $a0, 0x5348
    ctx->r4 = ADD32(ctx->r4, 0X5348);
    func_80005310(rdram, ctx);
        goto after_2;
    // 0x800052FC: addiu       $a0, $a0, 0x5348
    ctx->r4 = ADD32(ctx->r4, 0X5348);
    after_2:
    // 0x80005300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005304: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80005308: jr          $ra
    // 0x8000530C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000530C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005314: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80005318: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8000531C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005320: jal         0x80061620
    // 0x80005324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80005324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80005328: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000532C: sw          $s0, -0x20B0($at)
    MEM_W(-0X20B0, ctx->r1) = ctx->r16;
    // 0x80005330: jal         0x80061620
    // 0x80005334: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80005334: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80005338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000533C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80005340: jr          $ra
    // 0x80005344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005348: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8000534C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80005350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005354: bne         $a0, $v0, L_8000536C
    if (ctx->r4 != ctx->r2) {
        // 0x80005358: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_8000536C;
    }
    // 0x80005358: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8000535C: bne         $a1, $v0, L_8000536C
    if (ctx->r5 != ctx->r2) {
        // 0x80005360: nop
    
            goto L_8000536C;
    }
    // 0x80005360: nop

    // 0x80005364: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005368: sb          $zero, -0x20B4($at)
    MEM_B(-0X20B4, ctx->r1) = 0;
L_8000536C:
    // 0x8000536C: jr          $ra
    // 0x80005370: nop

    return;
    // 0x80005370: nop

;}
RECOMP_FUNC void func_80005374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005374: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005378: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000537C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80005380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005384: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80005388: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000538C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80005390: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005394: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005398: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8000539C: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x800053A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800053A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800053A8: jal         0x800655B0
    // 0x800053AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x800053AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800053B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800053B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800053B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800053BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053C0: sw          $a1, 0x5154($at)
    MEM_W(0X5154, ctx->r1) = ctx->r5;
    // 0x800053C4: jal         0x80006B0C
    // 0x800053C8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006B0C(rdram, ctx);
        goto after_1;
    // 0x800053C8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x800053CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800053D0: lw          $a0, 0x5154($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5154);
    // 0x800053D4: jal         0x8005AA3C
    // 0x800053D8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8005AA3C(rdram, ctx);
        goto after_2;
    // 0x800053D8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x800053DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800053E0: lw          $v0, 0x5154($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5154);
    // 0x800053E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053E8: sw          $v0, -0x3828($at)
    MEM_W(-0X3828, ctx->r1) = ctx->r2;
    // 0x800053EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800053F0: sw          $v0, 0x5150($at)
    MEM_W(0X5150, ctx->r1) = ctx->r2;
    // 0x800053F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800053F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800053FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005404: jr          $ra
    // 0x80005408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000540C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000540C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005410: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005418: jal         0x80059964
    // 0x8000541C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_80059964(rdram, ctx);
        goto after_0;
    // 0x8000541C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80005420: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005424: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005428: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8000542C: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x80005430: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005434: jal         0x800655B0
    // 0x80005438: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x80005438: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x8000543C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005440: sw          $v0, -0x4DCC($at)
    MEM_W(-0X4DCC, ctx->r1) = ctx->r2;
    // 0x80005444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000544C: jr          $ra
    // 0x80005450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80005454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005454: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80005458: lw          $a0, -0x4DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4DCC);
    // 0x8000545C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005460: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005464: jal         0x80059CA4
    // 0x80005468: nop

    func_80059CA4(rdram, ctx);
        goto after_0;
    // 0x80005468: nop

    after_0:
    // 0x8000546C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005470: jr          $ra
    // 0x80005474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005478: andi        $a2, $a1, 0x1
    ctx->r6 = ctx->r5 & 0X1;
    // 0x8000547C: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x80005480: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80005484: lw          $a1, -0x4DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4DCC);
    // 0x80005488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000548C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005490: jal         0x80006B0C
    // 0x80005494: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006B0C(rdram, ctx);
        goto after_0;
    // 0x80005494: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80005498: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000549C: jr          $ra
    // 0x800054A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800054A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800054A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800054A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800054A8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800054AC: jal         0x80059E98
    // 0x800054B0: nop

    func_80059E98(rdram, ctx);
        goto after_0;
    // 0x800054B0: nop

    after_0:
    // 0x800054B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800054B8: jr          $ra
    // 0x800054BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800054BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800054C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800054C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800054C4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800054C8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800054CC: jal         0x80059FF8
    // 0x800054D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80059FF8(rdram, ctx);
        goto after_0;
    // 0x800054D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800054D4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800054D8: jr          $ra
    // 0x800054DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800054DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800054E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800054E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800054E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800054E8: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x800054EC: lw          $s1, 0x38D4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X38D4);
    // 0x800054F0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800054F4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800054F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800054FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80005500: addu        $a0, $s3, $a1
    ctx->r4 = ADD32(ctx->r19, ctx->r5);
    // 0x80005504: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80005508: beq         $s1, $zero, L_80005538
    if (ctx->r17 == 0) {
        // 0x8000550C: sw          $s2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r18;
            goto L_80005538;
    }
    // 0x8000550C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
L_80005510:
    // 0x80005510: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80005514: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x80005518: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000551C: bne         $v0, $zero, L_80005538
    if (ctx->r2 != 0) {
        // 0x80005520: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80005538;
    }
    // 0x80005520: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80005524: beq         $v0, $zero, L_800055B0
    if (ctx->r2 == 0) {
        // 0x80005528: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_800055B0;
    }
    // 0x80005528: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x8000552C: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80005530: bne         $s1, $zero, L_80005510
    if (ctx->r17 != 0) {
        // 0x80005534: nop
    
            goto L_80005510;
    }
    // 0x80005534: nop

L_80005538:
    // 0x80005538: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000553C: addiu       $v1, $v1, 0x38D8
    ctx->r3 = ADD32(ctx->r3, 0X38D8);
    // 0x80005540: lw          $s1, 0x0($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X0);
    // 0x80005544: bne         $s1, $zero, L_80005564
    if (ctx->r17 != 0) {
        // 0x80005548: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80005564;
    }
    // 0x80005548: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000554C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005550: lw          $v0, 0x38D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38D4);
    // 0x80005554: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80005558: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000555C: j           L_80005664
    // 0x80005560: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
        goto L_80005664;
    // 0x80005560: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_80005564:
    // 0x80005564: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80005568: jal         0x8006553C
    // 0x8000556C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x8000556C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_0:
    // 0x80005570: beq         $s0, $zero, L_80005588
    if (ctx->r16 == 0) {
        // 0x80005574: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80005588;
    }
    // 0x80005574: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80005578: jal         0x8006551C
    // 0x8000557C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x8000557C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80005580: j           L_800055EC
    // 0x80005584: andi        $s0, $s3, 0x1
    ctx->r16 = ctx->r19 & 0X1;
        goto L_800055EC;
    // 0x80005584: andi        $s0, $s3, 0x1
    ctx->r16 = ctx->r19 & 0X1;
L_80005588:
    // 0x80005588: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000558C: lw          $a1, 0x38D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38D4);
    // 0x80005590: beq         $a1, $zero, L_800055D8
    if (ctx->r5 == 0) {
        // 0x80005594: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_800055D8;
    }
    // 0x80005594: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80005598: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000559C: sw          $s1, 0x38D4($at)
    MEM_W(0X38D4, ctx->r1) = ctx->r17;
    // 0x800055A0: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800055A4: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800055A8: j           L_800055E8
    // 0x800055AC: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
        goto L_800055E8;
    // 0x800055AC: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_800055B0:
    // 0x800055B0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x800055B4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800055B8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800055BC: lw          $v1, -0x20C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X20C0);
    // 0x800055C0: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x800055C4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800055C8: jal         0x80062180
    // 0x800055CC: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800055CC: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    after_2:
    // 0x800055D0: j           L_80005664
    // 0x800055D4: nop

        goto L_80005664;
    // 0x800055D4: nop

L_800055D8:
    // 0x800055D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800055DC: sw          $s1, 0x38D4($at)
    MEM_W(0X38D4, ctx->r1) = ctx->r17;
    // 0x800055E0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800055E4: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_800055E8:
    // 0x800055E8: andi        $s0, $s3, 0x1
    ctx->r16 = ctx->r19 & 0X1;
L_800055EC:
    // 0x800055EC: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x800055F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800055F4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800055F8: lw          $v1, 0x3DE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3DE0);
    // 0x800055FC: lw          $s2, 0x10($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X10);
    // 0x80005600: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80005604: lw          $a2, -0x20C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20C0);
    // 0x80005608: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000560C: addiu       $v0, $v0, 0x32D0
    ctx->r2 = ADD32(ctx->r2, 0X32D0);
    // 0x80005610: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x80005614: sw          $s3, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r19;
    // 0x80005618: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8000561C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80005620: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005624: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80005628: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000562C: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80005630: sw          $a2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r6;
    // 0x80005634: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80005638: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000563C: addiu       $v0, $v0, 0x31B8
    ctx->r2 = ADD32(ctx->r2, 0X31B8);
    // 0x80005640: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80005644: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005648: sw          $v1, 0x3DE0($at)
    MEM_W(0X3DE0, ctx->r1) = ctx->r3;
    // 0x8000564C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80005650: jal         0x800667A0
    // 0x80005654: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x80005654: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x80005658: jal         0x80062180
    // 0x8000565C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8000565C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80005660: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
L_80005664:
    // 0x80005664: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80005668: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000566C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80005670: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80005674: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80005678: jr          $ra
    // 0x8000567C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000567C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
