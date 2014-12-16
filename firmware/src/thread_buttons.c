#include "thread_buttons.h"

#include "buttons.h"
#include "scene.h"


BTN_CONTEXT btn_ctx_0;
BTN_CONTEXT btn_ctx_1;

BTN_CONTEXT btn_ctx_2;
BTN_CONTEXT btn_ctx_3;

BTN_CONTEXT btn_ctx_4;
BTN_CONTEXT btn_ctx_5;


void btn_act_0(void);
void btn_act_1(void);
void btn_act_2(void);
void btn_act_3(void);
void btn_act_4(void);
void btn_act_5(void);


void thread_buttons_init()
{
#define N1_TIME 100
#define N2_TIME 50

    btn_fsm_init(&btn_ctx_0, btn_0_is_set, btn_act_0, N1_TIME, N2_TIME);
    btn_fsm_init(&btn_ctx_1, btn_1_is_set, btn_act_1, N1_TIME, N2_TIME);

    btn_fsm_init(&btn_ctx_2, btn_2_is_set, btn_act_2, N1_TIME, N2_TIME);
    btn_fsm_init(&btn_ctx_3, btn_3_is_set, btn_act_3, N1_TIME, N2_TIME);

    btn_fsm_init(&btn_ctx_4, btn_4_is_set, btn_act_4, N1_TIME, N2_TIME);
    btn_fsm_init(&btn_ctx_5, btn_5_is_set, btn_act_5, N1_TIME, N2_TIME);
}


void thread_buttons_tick()
{
    btn_fsm_step(&btn_ctx_0);
    btn_fsm_step(&btn_ctx_1);

    btn_fsm_step(&btn_ctx_2);
    btn_fsm_step(&btn_ctx_3);

    btn_fsm_step(&btn_ctx_4);
    btn_fsm_step(&btn_ctx_5);
}


void btn_act_0(void)
{
    scene_bright_down();
}

void btn_act_1(void)
{
    scene_bright_up();
}

void btn_act_2(void)
{
    scene_speed_down();
}

void btn_act_3(void)
{
    scene_speed_up();
}

void btn_act_4(void)
{
    scene_program_down();
}

void btn_act_5(void)
{
    scene_program_up();
}
