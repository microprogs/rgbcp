#ifndef SCENE_H
#define SCENE_H


#include "types.h"



void scene_bright_up();
void scene_bright_down();

void scene_speed_up();
void scene_speed_down();
int scene_speed_get_mult();

void scene_program_up();
void scene_program_down();
int scene_program_get_index();
int get_new_program_flag();
void reset_new_program_flag();


uint16_t load_delay_from_frame(uint8_t frame_buf[32]);
void set_led_bright_from_frame(uint8_t frame_buf[32]);


#endif
