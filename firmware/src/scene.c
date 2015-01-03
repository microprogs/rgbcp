#include "scene.h"
#include "leds.h"
#include "movies.h"


// BRIGHT SELECT

void scene_bright_up()
{
    led_matrix_fsm_set_global_bright(led_matrix_fsm_get_global_bright() + 1); //1..5
}

void scene_bright_down()
{
    led_matrix_fsm_set_global_bright(led_matrix_fsm_get_global_bright() - 1); //1..5
}



// SPEED SELECT

volatile static int speed_mult = 10;

int scene_speed_get_mult()
{
    return speed_mult;
}

void scene_speed_up()
{
    speed_mult--;

    if (speed_mult < 1)
        speed_mult = 1;
}

void scene_speed_down()
{
    speed_mult++;

    if (speed_mult > 20)
        speed_mult = 20;
}



// PROGRAM SELECT
volatile static int program_index = 0;
volatile static int is_new_program = 0;

static void set_new_program_flag()
{
    is_new_program = 1;
}

int get_new_program_flag()
{
    return is_new_program;
}

void reset_new_program_flag()
{
    is_new_program = 0;
}

int scene_program_get_index()
{
    return program_index;
}

void scene_program_up()
{
    program_index++;

    if (program_index >= (count_bin_files - 1))
        program_index = (count_bin_files - 1);

    set_new_program_flag();
}

void scene_program_down()
{
    program_index--;

    if (program_index <= 0)
        program_index = 0;

    set_new_program_flag();
}








// FRAME UTILS

uint16_t load_delay_from_frame(uint8_t frame_buf[32])
{
    uint16_t res = 0;
    res = (uint16_t)((uint16_t)frame_buf[31] << (uint16_t)8) | (uint16_t)(frame_buf[30]);
    return res;
}

static void load_rgb333_from_byte(uint8_t byte, uint8_t *r3, uint8_t *g3, uint8_t *b3)
{
    // RRR GGG BB
    *r3 = (byte >> 5) & 0x7;
    *g3 = (byte >> 2) & 0x7;

    uint8_t b2 = (byte) & 0x3;

    switch (b2)
    {
    default:
    case 0:
        *b3 = 0;
        break;

    case 1:
        *b3 = 1;
        break;

    case 2:
        *b3 = 4;
        break;

    case 3:
        *b3 = 7;
        break;
    }
}

void set_led_bright_from_frame(uint8_t frame_buf[32])
{
#define ROW_COUNT   10
#define COL_COUNT   3

    for (int i = 0; i < ROW_COUNT; ++i)
    {
        for (int j = 0; j < COL_COUNT; ++j)
        {
            //[i][j]
            uint8_t byte_color = frame_buf[i * COL_COUNT + j];

            uint8_t r3 = 0;
            uint8_t g3 = 0;
            uint8_t b3 = 0;

            load_rgb333_from_byte(byte_color, &r3, &g3, &b3);

            led_matrix_fsm_set_rgb_bright(i, j, r3, g3, b3);
        }
    }
}


