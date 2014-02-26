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



void led_ann_cs_all_off(void);
void led_ann_cs_one_on(uint32_t num);


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



//void led_red_power(uint32_t val);
//void led_red_power_off(void);
//void led_red_power_on(void);

//void led_green_power(uint32_t val);
//void led_green_power_off(void);
//void led_green_power_on(void);


#endif

