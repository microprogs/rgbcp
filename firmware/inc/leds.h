#ifndef LEDS_H
#define LEDS_H

#include <types.h>
#include <config.h>

void init_leds(void);

void led_dbg_red_power_off(void);
void led_dbg_red_power_on(void);

void led_dbg_green_power_off(void);
void led_dbg_green_power_on(void);

void led_dbg_blue_power_off(void);
void led_dbg_blue_power_on(void);

void led_bat_0_power_off(void);
void led_bat_0_power_on(void);

void led_bat_1_power_off(void);
void led_bat_1_power_on(void);

void led_bat_2_power_off(void);
void led_bat_2_power_on(void);

void led_bat_3_power_off(void);
void led_bat_3_power_on(void);


void print_bat_leds(uint32_t val);  // val=0-15


void led_ann_cs_all_off(void);
void led_ann_cs_one_on(uint32_t num);  // num=0-9


// PIO1_0 - LED_ANN_1B
void led_ann_1b_off(void);
void led_ann_1b_on(void);

// PIO1_1 - LED_ANN_1G
void led_ann_1g_off(void);
void led_ann_1g_on(void);

// PIO1_2 - LED_ANN_1R
void led_ann_1r_off(void);
void led_ann_1r_on(void);

// PIO1_3 - LED_ANN_2B
void led_ann_2b_off(void);
void led_ann_2b_on(void);

// PIO1_4 - LED_ANN_2G
void led_ann_2g_off(void);
void led_ann_2g_on(void);

// PIO1_5 - LED_ANN_2R
void led_ann_2r_off(void);
void led_ann_2r_on(void);

// PIO1_6 - LED_ANN_3B
void led_ann_3b_off(void);
void led_ann_3b_on(void);

// PIO1_7 - LED_ANN_3G
void led_ann_3g_off(void);
void led_ann_3g_on(void);

// PIO1_8 - LED_ANN_3R
void led_ann_3r_off(void);
void led_ann_3r_on(void);





////////////////////////// LED FSM /////////////////////////////////
typedef void (*led_off_t)(void);
typedef void (*led_on_t)(void);

typedef struct _LED_CONTEXT
{
	int ledBrightMax;
	int ledBrightCur;
	int ledState;
	int ledTimeCnt;
	led_off_t led_off;
	led_on_t led_on;
} LED_CONTEXT;

void led_fsm_init(LED_CONTEXT *ctx, int brightMax, led_off_t led_off, led_on_t led_on);
void led_fsm_step(LED_CONTEXT *ctx);
void led_fsm_set_bright(LED_CONTEXT *ctx, int bright);  // 0..brightMax
int led_fsm_get_bright(LED_CONTEXT *ctx);


////////////////////// LED MATRIX FSM //////////////////////
void led_matrix_fsm_init(uint32_t maxBright, uint32_t maxGlobalBright);
void led_matrix_fsm_step();
void led_matrix_fsm_set_global_bright(uint32_t globalBright); //1..5
uint32_t led_matrix_fsm_get_global_bright();
void led_matrix_fsm_set_rgb_bright(uint32_t line0_9, uint32_t row0_2, uint8_t br_red, uint8_t br_green, uint8_t br_blue);
uint8_t led_matrix_fsm_get_red(uint32_t line0_9, uint32_t row0_2);
uint8_t led_matrix_fsm_get_green(uint32_t line0_9, uint32_t row0_2);
uint8_t led_matrix_fsm_get_blue(uint32_t line0_9, uint32_t row0_2);



//void led_red_power(uint32_t val);
//void led_red_power_off(void);
//void led_red_power_on(void);

//void led_green_power(uint32_t val);
//void led_green_power_off(void);
//void led_green_power_on(void);


#endif

