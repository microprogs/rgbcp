#include "thread_leds.h"
#include "leds.h"


LED_CONTEXT led_bat_0_ctx;
LED_CONTEXT led_bat_1_ctx;
LED_CONTEXT led_bat_2_ctx;
LED_CONTEXT led_bat_3_ctx;



void thread_leds_init()
{
    led_ann_cs_all_off();


    // LED FSM INIT
    led_fsm_init(&led_bat_0_ctx, 25*6, led_bat_0_power_off, led_bat_0_power_on);
    led_fsm_init(&led_bat_1_ctx, 25*6, led_bat_1_power_off, led_bat_1_power_on);
    led_fsm_init(&led_bat_2_ctx, 25*6, led_bat_2_power_off, led_bat_2_power_on);
    led_fsm_init(&led_bat_3_ctx, 25*6, led_bat_3_power_off, led_bat_3_power_on);


    led_fsm_set_bright(&led_bat_0_ctx, 0);  // 0..brightMax
    led_fsm_set_bright(&led_bat_1_ctx, 0);  // 0..brightMax
    led_fsm_set_bright(&led_bat_2_ctx, 0);  // 0..brightMax
    led_fsm_set_bright(&led_bat_3_ctx, 0);  // 0..brightMax


#define LED_GLOBAL_BRIGHT_MAX 5
#define LED_BRIGHT_MAX 7


    led_matrix_fsm_init(LED_BRIGHT_MAX, LED_GLOBAL_BRIGHT_MAX);



}

void thread_leds_tick()
{
    led_fsm_step(&led_bat_0_ctx);
    led_fsm_step(&led_bat_1_ctx);
    led_fsm_step(&led_bat_2_ctx);
    led_fsm_step(&led_bat_3_ctx);

    led_matrix_fsm_step();
}

void thread_leds_set_bat_level(uint32_t bat_val)
{
#define BAT_VAL_LOW     336
#define BAT_VAL_HIGH	644
#define BAT_VAL_LEN     (BAT_VAL_HIGH - BAT_VAL_LOW)

    if (bat_val >= BAT_VAL_HIGH)
        bat_val = BAT_VAL_HIGH;
    if (bat_val <= BAT_VAL_LOW)
        bat_val = BAT_VAL_LOW;

    // bat_val = 336..644
    bat_val -= BAT_VAL_LOW;

    // bat_val = 0..308

    bat_val = (bat_val * 100) / BAT_VAL_LEN;  //((0..308) * 100) / 308 == (0..100)

    // bat_val = 0%..100%

    led_fsm_set_bright(&led_bat_0_ctx, 0);  // 0..25
    led_fsm_set_bright(&led_bat_1_ctx, 0);  // 0..25
    led_fsm_set_bright(&led_bat_2_ctx, 0);  // 0..25
    led_fsm_set_bright(&led_bat_3_ctx, 0);  // 0..25

    if (bat_val >= 0 && bat_val <= 24)
    {
        led_fsm_set_bright(&led_bat_3_ctx, bat_val);
    }
    else if (bat_val >= 25 && bat_val <= 49)
    {
        led_fsm_set_bright(&led_bat_3_ctx, 25);
        led_fsm_set_bright(&led_bat_2_ctx, bat_val % 25);
    }
    else if (bat_val >= 50 && bat_val <= 74)
    {
        led_fsm_set_bright(&led_bat_3_ctx, 25);
        led_fsm_set_bright(&led_bat_2_ctx, 25);
        led_fsm_set_bright(&led_bat_1_ctx, bat_val % 25);
    }
    else if (bat_val >= 75 && bat_val <= 99)
    {
        led_fsm_set_bright(&led_bat_3_ctx, 25);
        led_fsm_set_bright(&led_bat_2_ctx, 25);
        led_fsm_set_bright(&led_bat_1_ctx, 25);
        led_fsm_set_bright(&led_bat_0_ctx, bat_val % 25);
    }
    else
    {
        led_fsm_set_bright(&led_bat_3_ctx, 25);
        led_fsm_set_bright(&led_bat_2_ctx, 25);
        led_fsm_set_bright(&led_bat_1_ctx, 25);
        led_fsm_set_bright(&led_bat_0_ctx, 25);
    }
}

/*

////////////////////////// LED FSM /////////////////////////////////
typedef void (*led_off_t)(void);
typedef void (*led_on_t)(void);

void led_fsm_init(LED_CONTEXT *ctx, int brightMax, led_off_t led_off, led_on_t led_on);
void led_fsm_step(LED_CONTEXT *ctx);
void led_fsm_set_bright(LED_CONTEXT *ctx, int bright);  // 0..brightMax


////////////////////// LED MATRIX FSM //////////////////////
void led_matrix_fsm_init(uint32_t maxBright, uint32_t maxGlobalBright);
void led_matrix_fsm_step();
void led_matrix_fsm_set_global_bright(uint32_t globalBright); //1..5
uint32_t led_matrix_fsm_get_global_bright();
void led_matrix_fsm_set_rgb_bright(uint32_t line0_9, uint32_t row0_2, uint8_t br_red, uint8_t br_green, uint8_t br_blue);
uint8_t led_matrix_fsm_get_red(uint32_t line0_9, uint32_t row0_2);
uint8_t led_matrix_fsm_get_green(uint32_t line0_9, uint32_t row0_2);
uint8_t led_matrix_fsm_get_blue(uint32_t line0_9, uint32_t row0_2);

*/
