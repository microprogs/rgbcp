#ifndef BUTTONS_H
#define BUTTONS_H

#include <types.h>
#include <config.h>


void init_buttons(void);


// PIO2_10 - BTN_0
uint32_t btn_0_is_set(void);

// PIO0_5 - BTN_1
uint32_t btn_1_is_set(void);

// PIO2_11 - BTN_2
uint32_t btn_2_is_set(void);

// PIO0_7 - BTN_3
uint32_t btn_3_is_set(void);

// PIO0_8 - BTN_4
uint32_t btn_4_is_set(void);

// PIO0_9 - BTN_5
uint32_t btn_5_is_set(void);


#endif

