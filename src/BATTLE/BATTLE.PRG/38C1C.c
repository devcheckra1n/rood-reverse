#include "common.h"
#include "3A1A0.h"
#include <libgpu.h>

void func_8009DF3C(int, int);
void func_800AA850(int, int, int);
int func_800A6EE8(SVECTOR*, int, int, int);
u_int* func_800A8D64(SVECTOR*, int);
void func_800AC690(int, D_800F4538_t*);
int func_800A152C(int, int, int);
int func_800A17BC(int, int, MATRIX*, int*);
MATRIX* func_800A1DE8(int, int, MATRIX*);
extern MATRIX D_800F49B8;
int func_800A1C10(int arg0, int arg1, u_short* arg2, int arg3);
void func_800A9EB4(int, int, int);

int func_800A141C(int arg0, int arg1, int arg2, int arg3)
{
    SVECTOR sp0;
    MATRIX* v0;
    D_800F4538_unk68* temp_v1;
    D_800F4538_t* var_v1 = D_800F4538[arg0];

    if (var_v1 == NULL) {
        var_v1 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v1 == NULL) {
            return -1;
        }
    }

    v0 = &var_v1->bones[arg1];
    temp_v1 = var_v1->unk0.unk68;

    __asm__ volatile("lw $t4,0(%0);"
                     "lw $t5,4(%0);"
                     "ctc2 $t4, $0;"
                     "ctc2 $t5, $1;"
                     "lw $t4,8(%0);"
                     "lw $t5,0xc(%0);"
                     "lw $t6,0x10(%0);"
                     "ctc2 $t4, $2;"
                     "ctc2 $t5, $3;"
                     "ctc2 $t6, $4;"
                     "lw $t4,0x14(%0);"
                     "lw $t5,0x18(%0);"
                     "ctc2 $t4, $5;"
                     "lw $t6,0x1c(%0);"
                     "ctc2 $t5, $6;"
                     "ctc2 $t6, $7"
                     :
                     : "r"(v0));

    if (arg3 == 0) {
        sp0.vx = 0;
    } else {
        if (arg3 == 1) {
            sp0.vx = -(u_short)temp_v1->armatures[arg1].unk0;
        } else {
            sp0.vx = -temp_v1->armatures[arg1].unk0 / 2;
        }
    }

    sp0.vy = 0;
    sp0.vz = 0;
    sp0.pad = 0;

    __asm__ volatile("lwc2	$0,0(%0);"
                     "lwc2	$1,4(%0);"
                     "nop;"
                     "nop;"
                     "rtps;"
                     "swc2 $14,0x0($a2);"
                     "addu $v0,$a2,4;"
                     "swc2 $19,0x0($v0);"
                     :
                     : "r"(&sp0));

    return 0;
}

int func_800A152C(int arg0, int arg1, int arg2)
{
    D_800F4538_t* var_v0_2;
    D_800F4538_unk68* var_v1;
    int i;
    int nBones;
    int new_var;

    var_v0_2 = D_800F4538[arg0];

    if (var_v0_2 == NULL) {
        var_v0_2 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v0_2 == NULL) {
            return -1;
        }
    }

    nBones = var_v0_2->unk0.nBones;
    var_v1 = var_v0_2->unk0.unk68;

    do {
        if (arg1 == 0xFF) {
            return 0;
        }
    } while (0);

    for (i = 0; i < nBones; ++i) {
        switch (arg2) {
        case 0:
            if (var_v1->armatures[i].unk6 == (arg1 & 0xFF)) {
                return i;
            }
            break;

        case 1:
            new_var = (var_v1->armatures[i].unk7 >> 4) == ((arg1 & 0xFF) + 1);
            if (new_var) {
                return i;
            }
            break;

        case 2:
            if ((var_v1->armatures[i].unk7 & 0xF) == ((arg1 & 0xFF) + 1)) {
                return i;
            }
            break;

        case 3:
            if (var_v1->armatures[i].unk8 == (arg1 & 0xFF)) {
                return i;
            }
            break;
        }
    }

    return -4;
}

// https://decomp.me/scratch/N9nFn
int func_800A1648(int arg0, int arg1, int arg2)
{
    D_800F4538_unk68* temp_a0;
    int val;
    D_800F4538_t* var_v0 = D_800F4538[arg0];

    if (var_v0 == NULL) {
        var_v0 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v0 == NULL) {
            return -1;
        }
    }

    temp_a0 = var_v0->unk0.unk68;

    switch (arg2) {
    case 0:
        val = temp_a0->armatures[arg1].unk6;
        break;

    case 1:
        val = temp_a0->armatures[arg1].unk7 >> 4;
        if (val == 0) {
            return -3;
        }
        break;

    case 2:
        val = temp_a0->armatures[arg1].unk7 & 0xF;
        if (val == 0) {
            return -3;
        }
        break;
    }

    return val;
}

int func_800A1720(int arg0, int arg1, MATRIX* arg2, int* arg3)
{
    int var_v0 = arg1;

    if (arg1 == 0xFD) {
        var_v0 = 0;
    }

    var_v0 = func_800A17BC(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    if (arg1 == 0xFD) {
        arg2->t[1] = D_800F4538[arg0]->unk0.position.vy;
    }

    return 0;
}

int func_800A17BC(int arg0, int arg1, MATRIX* arg2, int* arg3)
{
    int _[22] __attribute__((unused));
    vs_battle_wepModels_t* model;
    D_800F4538_t* var_a0;

    *arg2 = *func_800A1DE8(arg0, arg1, &D_800F49B8);

    var_a0 = D_800F4538[arg0];
    if (var_a0 == NULL) {
        D_800F4538_t* var_v0 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v0 != NULL) {
            *arg3 = var_v0->unk0.unk68->armatures[arg1].unk0;
        }
    } else if (arg1 == 0xFF) {
        *arg3 = 0;
    } else if ((arg1 & 0xF0) == 0x40) {
        model = vs_battle_wepModels[arg0 * 2];
        if (model == NULL) {
            return 0;
        }
        *arg3 = model->offsets->armatures[arg1 - 0x3F].unk0;
    } else {
        *arg3 = var_a0->unk0.unk68->armatures[arg1].unk0;
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A190C);

int func_800A1AF8(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A1C10(arg0, arg1, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B28(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 1);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

int func_800A1B9C(int arg0, int arg1, u_short* arg2, int arg3)
{
    int var_v0 = func_800A152C(arg0, arg1, 2);

    if (var_v0 < 0) {
        return var_v0;
    }

    var_v0 = func_800A1C10(arg0, var_v0, arg2, arg3);

    if (var_v0 < 0) {
        return var_v0;
    }

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1C10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A1DE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/38C1C", func_800A208C);

void func_800A0204(int, int, int, int);

void func_800A249C(int arg0, int arg1)
{
    int var_a2;
    int var_a1;
    int v1;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3->unk0.unkA_5) {
        return;
    }

    var_a1 = arg1 - temp_a3->unk0.facing;

    if (var_a1 > 0x800) {
        var_a1 -= 0x1000;
    }

    if (var_a1 < -0x800) {
        var_a1 += 0x1000;
    }

    if (var_a1 == 0) {
        return;
    }

    temp_a3->unk1848.unk0 = 6;

    v1 = temp_a3->animationId;

    if ((v1 == 0x76) || (temp_a3->animationId == 0x75) || temp_a3->unk0.unkC_0) {
        return;
    }

    var_a2 = 0x1F;

    if (!(temp_a3->unk0.unkA_6)) {

        var_a2 = 0x11;

        if (var_a1 < 0) {
            var_a2 = 0x12;
        }
    }

    func_800A0204(arg0, var_a2, 0, 0xA);
}

void func_800A2574(int arg0, short arg1)
{
    D_800F4538_t* temp_s1 = D_800F4538[arg0];
    func_800A9EB4(arg0, arg1, 8);
    func_8009DF3C(arg0, 3);
    temp_s1->unk0.unkB_4 = 6;
}

void func_800A25EC(D_800F4538_t* arg0)
{
    SVECTOR sp10;

    arg0->unk0.unkA_5 = 0;

    sp10.vx = arg0->unk1848.unk10.vx;
    sp10.vy = 0;
    sp10.vz = arg0->unk1848.unk10.vz;

    sp10.vy = func_800A6EE8(&arg0->unk0.position, sp10.vx, sp10.vz, 1);
    if (sp10.vy == -0xBB8) {
        return;
    }

    sp10.vx += arg0->unk0.position.vx;
    sp10.vz += arg0->unk0.position.vz;

    if (func_800A8D64(&sp10, 0) == NULL) {
        return;
    }

    arg0->unk0.position.vx = sp10.vx;
    arg0->unk0.position.vz = sp10.vz;

    if (arg0->unk0.unkA_0) {
        func_800AC690(arg0->unk0.unkF, arg0);
    } else if (sp10.vy > arg0->unk0.position.vy) {
        if ((sp10.vy - arg0->unk0.position.vy) >= 0x40) {
            arg0->unk0.unk34.vx = 0;
            arg0->unk0.unk34.vy = 0;
            arg0->unk0.unk34.vz = 0;
            func_800A0204(arg0->unk0.unkF, 0x2F, 0, 4);
            arg0->unk181A = 0;
            arg0->unk0.unkA_3 = 0;
            arg0->unk0.unk9_6 = 0;
            arg0->unk0.unkA_0 = 3;
        } else {
            arg0->unk0.position.vy = sp10.vy;
        }
    } else {
        arg0->unk0.position.vy = sp10.vy;
    }

    arg0->unk0.currentTileX = arg0->unk0.position.vx / 128;
    arg0->unk0.currentTileZ = arg0->unk0.position.vz / 128;
    arg0->unk0.unk5D = 0;
}

void func_800A2790(D_800F4538_t* arg0)
{
    VECTOR step;
    int anim;
    int speed = arg0->unk1848.unk8;

    step.vx = (arg0->unk1848.unk10.vx * speed) / 0x1000000;
    step.vy = (arg0->unk1848.unk10.vy * speed) / 0x1000000;
    step.vz = (arg0->unk1848.unk10.vz * speed) / 0x1000000;

    arg0->unk0.position.vx += step.vx;
    arg0->unk0.position.vy += step.vy;
    arg0->unk0.position.vz += step.vz;

    arg0->unk0.currentTileX = arg0->unk0.position.vx / 128;
    arg0->unk0.currentTileZ = arg0->unk0.position.vz / 128;
    arg0->unk0.unkA_5 = 1;

    func_800AA850(arg0->unk0.unkF, arg0->unk1848.unk6, 12);

    anim = 1;
    if (speed > 0) {
        if (step.vy < -2) {
            anim = 0x20;
        } else if (step.vy >= 3) {
            anim = 0x22;
        } else {
            anim = 0x1F;
        }
        if (speed >= 12) {
            anim += 6;
        }
    }

    if (arg0->animationId != anim) {
        func_800A0204(arg0->unk0.unkF, anim, 0, 4);
    }
}


void func_800A291C(D_800F4538_t* arg0)
{
    addVector(&arg0->unk0.position, &arg0->unk1848.unk10);

    arg0->unk0.currentTileX = arg0->unk0.position.vx / 128;
    arg0->unk0.currentTileZ = arg0->unk0.position.vz / 128;

    func_800AA850(arg0->unk0.unkF, arg0->unk1848.unk6, 12);
}
