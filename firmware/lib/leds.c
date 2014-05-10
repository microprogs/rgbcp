#include <leds.h>
#include <gpio.h>
#include <bits.h>

void init_leds(void)
{
//	gpio_set_dir_out(LED_RED_PORT, LED_RED_BIT);
//	gpio_set_data_bit_zero(LED_RED_PORT, LED_RED_BIT);

//	gpio_set_dir_out(LED_GREEN_PORT, LED_GREEN_BIT);
//	gpio_set_data_bit_zero(LED_GREEN_PORT, LED_GREEN_BIT);
	led_dbg_red_power_off();
	led_dbg_green_power_off();
	led_dbg_blue_power_off();

	led_bat_0_power_off();
	led_bat_1_power_off();
	led_bat_2_power_off();
	led_bat_3_power_off();


	gpio_set_dir_out(2, 0);
	gpio_set_data_bit_zero(2, 0);

	gpio_set_dir_out(2, 1);
	gpio_set_data_bit_zero(2, 1);

	gpio_set_dir_out(2, 2);
	gpio_set_data_bit_zero(2, 2);

	gpio_set_dir_out(2, 3);
	gpio_set_data_bit_zero(2, 3);

	gpio_set_dir_out(2, 4);
	gpio_set_data_bit_zero(2, 4);

	gpio_set_dir_out(2, 5);
	gpio_set_data_bit_zero(2, 5);

	gpio_set_dir_out(2, 6);
	gpio_set_data_bit_zero(2, 6);

	gpio_set_dir_out(2, 7);
	gpio_set_data_bit_zero(2, 7);

	gpio_set_dir_out(2, 8);
	gpio_set_data_bit_zero(2, 8);

	gpio_set_dir_out(2, 9);
	gpio_set_data_bit_zero(2, 9);



	// PIO1_0 - LED_ANN_1B
	led_ann_1b_off();
	// PIO1_1 - LED_ANN_1G
	led_ann_1g_off();
	// PIO1_2 - LED_ANN_1R
	led_ann_1r_off();

	// PIO1_3 - LED_ANN_2B
	led_ann_2b_off();
	// PIO1_4 - LED_ANN_2G
	led_ann_2g_off();
	// PIO1_5 - LED_ANN_2R
	led_ann_2r_off();

	// PIO1_6 - LED_ANN_3B
	led_ann_3b_off();
	// PIO1_7 - LED_ANN_3G
	led_ann_3g_off();
	// PIO1_8 - LED_ANN_3R
	led_ann_3r_off();
}

void led_dbg_red_power_off(void)
{
	gpio_set_dir_in(3, 1);
}

void led_dbg_red_power_on(void)
{
	gpio_set_dir_out(3, 1);
	gpio_set_data_bit_zero(3, 1);
}

void led_dbg_green_power_off(void)
{
	gpio_set_dir_in(3, 2);
}

void led_dbg_green_power_on(void)
{
	gpio_set_dir_out(3, 2);
	gpio_set_data_bit_zero(3, 2);
}

void led_dbg_blue_power_off(void)
{
	gpio_set_dir_in(3, 3);
}

void led_dbg_blue_power_on(void)
{
	gpio_set_dir_out(3, 3);
	gpio_set_data_bit_zero(3, 3);
}



void led_bat_0_power_off(void)
{
	gpio_set_dir_in(0, 10);
}

void led_bat_0_power_on(void)
{
	gpio_set_dir_out(0, 10);
	gpio_set_data_bit_zero(0, 10);
}


void led_bat_1_power_off(void)
{
	gpio_set_dir_in(1, 9);
}

void led_bat_1_power_on(void)
{
	gpio_set_dir_out(1, 9);
	gpio_set_data_bit_zero(1, 9);
}


void led_bat_2_power_off(void)
{
	gpio_set_dir_in(1, 10);
}

void led_bat_2_power_on(void)
{
	gpio_set_dir_out(1, 10);
	gpio_set_data_bit_zero(1, 10);
}


void led_bat_3_power_off(void)
{
	gpio_set_dir_in(1, 11);
}

void led_bat_3_power_on(void)
{
	gpio_set_dir_out(1, 11);
	gpio_set_data_bit_zero(1, 11);
}


void print_bat_leds(uint32_t val)
{
	val = val % 16;
	if (val >= 0 && val <= 15)
	{
		if (bit_is_set(&val, 0))
			led_bat_0_power_on();
		else
			led_bat_0_power_off();

		if (bit_is_set(&val, 1))
			led_bat_1_power_on();
		else
			led_bat_1_power_off();

		if (bit_is_set(&val, 2))
			led_bat_2_power_on();
		else
			led_bat_2_power_off();

		if (bit_is_set(&val, 3))
			led_bat_3_power_on();
		else
			led_bat_3_power_off();
	}
}




void led_ann_cs_all_off(void)
{
	gpio_set_data_bit_zero(2, 0);
	gpio_set_data_bit_zero(2, 1);
	gpio_set_data_bit_zero(2, 2);
	gpio_set_data_bit_zero(2, 3);
	gpio_set_data_bit_zero(2, 4);
	gpio_set_data_bit_zero(2, 5);
	gpio_set_data_bit_zero(2, 6);
	gpio_set_data_bit_zero(2, 7);
	gpio_set_data_bit_zero(2, 8);
	gpio_set_data_bit_zero(2, 9);
}

void led_ann_cs_one_on(uint32_t num)
{
	led_ann_cs_all_off();
	if ((num >= 0) && (num <= 9))
		gpio_set_data_bit_one(2, num);
}



// PIO1_0 - LED_ANN_1B
void led_ann_1g_off(void)
{
	gpio_set_dir_in(1, 0);
}

void led_ann_1g_on(void)
{
	gpio_set_dir_out(1, 0);
	gpio_set_data_bit_zero(1, 0);
}

// PIO1_1 - LED_ANN_1G
void led_ann_1b_off(void)
{
	gpio_set_dir_in(1, 1);
}

void led_ann_1b_on(void)
{
	gpio_set_dir_out(1, 1);
	gpio_set_data_bit_zero(1, 1);
}

// PIO1_2 - LED_ANN_1R
void led_ann_1r_off(void)
{
	gpio_set_dir_in(1, 2);
}

void led_ann_1r_on(void)
{
	gpio_set_dir_out(1, 2);
	gpio_set_data_bit_zero(1, 2);
}

// PIO1_3 - LED_ANN_2B
void led_ann_2g_off(void)
{
	gpio_set_dir_in(1, 3);
}

void led_ann_2g_on(void)
{
	gpio_set_dir_out(1, 3);
	gpio_set_data_bit_zero(1, 3);
}

// PIO1_4 - LED_ANN_2G
void led_ann_2b_off(void)
{
	gpio_set_dir_in(1, 4);
}

void led_ann_2b_on(void)
{
	gpio_set_dir_out(1, 4);
	gpio_set_data_bit_zero(1, 4);
}

// PIO1_5 - LED_ANN_2R
void led_ann_2r_off(void)
{
	gpio_set_dir_in(1, 5);
}

void led_ann_2r_on(void)
{
	gpio_set_dir_out(1, 5);
	gpio_set_data_bit_zero(1, 5);
}

// PIO1_6 - LED_ANN_3B
void led_ann_3g_off(void)
{
	gpio_set_dir_in(1, 6);
}

void led_ann_3g_on(void)
{
	gpio_set_dir_out(1, 6);
	gpio_set_data_bit_zero(1, 6);
}

// PIO1_7 - LED_ANN_3G
void led_ann_3b_off(void)
{
	gpio_set_dir_in(1, 7);
}

void led_ann_3b_on(void)
{
	gpio_set_dir_out(1, 7);
	gpio_set_data_bit_zero(1, 7);
}

// PIO1_8 - LED_ANN_3R
void led_ann_3r_off(void)
{
	gpio_set_dir_in(1, 8);
}

void led_ann_3r_on(void)
{
	gpio_set_dir_out(1, 8);
	gpio_set_data_bit_zero(1, 8);
}




////////////////////////// LED FSM /////////////////////////////////
#define LED_STATE_OFF	0
#define LED_STATE_ON	1

void led_fsm_init(LED_CONTEXT *ctx, int brightMax, led_off_t led_off, led_on_t led_on)
{
	ctx->ledBrightMax = brightMax;
	ctx->ledBrightCur = 0;
	ctx->ledState = LED_STATE_OFF;
	ctx->ledTimeCnt = 0;
	ctx->led_off = led_off;
	ctx->led_on = led_on;
}

void led_fsm_step(LED_CONTEXT *ctx)
{
	ctx->ledTimeCnt++;

	if (ctx->ledState == LED_STATE_OFF)
	{
		if (ctx->ledTimeCnt >= (ctx->ledBrightMax - ctx->ledBrightCur))
		{
			ctx->ledTimeCnt = 0;
			if (ctx->ledBrightCur >= 1)
			{
				ctx->led_on();
				ctx->ledState = LED_STATE_ON;
			}
		}			
	}
	else  // LED_STATE_ON
	{
		if (ctx->ledTimeCnt >= ctx->ledBrightCur)
		{
			ctx->ledTimeCnt = 0;
			if ((ctx->ledBrightMax - ctx->ledBrightCur) >= 1)
			{
				ctx->led_off();
				ctx->ledState = LED_STATE_OFF;
			}
		}
	}
}

void led_fsm_set_bright(LED_CONTEXT *ctx, int bright)  // 0..brightMax
{
	if (bright <= 0)
		bright = 0;
	if (bright >= ctx->ledBrightMax)
		bright = ctx->ledBrightMax;

	ctx->ledBrightCur = bright;
}

int led_fsm_get_bright(LED_CONTEXT *ctx)
{
	return ctx->ledBrightCur;
}



////////////////////// LED MATRIX FSM //////////////////////

#define RGB_TO_UINT32(RED,GREEN,BLUE) ((uint32_t)((uint32_t)((uint32_t)RED & (uint32_t)0xFF) | (uint32_t)(((uint32_t)GREEN & (uint32_t)0xFF) << 8) | (uint32_t)(((uint32_t)BLUE & (uint32_t)0xFF) << 16)))
#define UINT32_TO_RED(RGB) ((uint32_t)RGB & (uint32_t)0xFF)
#define UINT32_TO_GREEN(RGB) (((uint32_t)RGB >> (uint32_t)8) & (uint32_t)0xFF)
#define UINT32_TO_BLUE(RGB) (((uint32_t)RGB >> (uint32_t)16) & (uint32_t)0xFF)


static led_off_t matrix_led_off[3][3] = {
    {led_ann_1r_off, led_ann_1g_off, led_ann_1b_off},
    {led_ann_2r_off, led_ann_2g_off, led_ann_2b_off},
    {led_ann_3r_off, led_ann_3g_off, led_ann_3b_off}
};

static led_off_t matrix_led_on[3][3] = {
    {led_ann_1r_on, led_ann_1g_on, led_ann_1b_on},
    {led_ann_2r_on, led_ann_2g_on, led_ann_2b_on},
    {led_ann_3r_on, led_ann_3g_on, led_ann_3b_on}
};

static uint32_t matrix_max_global_bright = 0; // 5
static uint32_t matrix_max_bright = 0; // 7

static uint32_t max_total_bright = 0;  // 7*5

static uint32_t matrix_global_bright = 0;  //1..5

static uint8_t matrix_bright_cur_rgb[10][3][3];

static uint8_t matrix_led_line_state[3][3];
static uint8_t matrix_led_line_timecnt[3][3];

static uint32_t matrix_cur_line = 0;
static uint32_t matrix_cur_cnt = 0;

void led_matrix_fsm_init(uint32_t maxBright, uint32_t maxGlobalBright)
{
    matrix_max_bright = maxBright;
    matrix_max_global_bright = maxGlobalBright;
    max_total_bright = (maxBright * maxGlobalBright);

    matrix_global_bright = 1;

    int i = 0, j = 0;
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            matrix_bright_cur_rgb[i][j][0] = 0;
            matrix_bright_cur_rgb[i][j][1] = 0;
            matrix_bright_cur_rgb[i][j][2] = 0;
        }
    }

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            matrix_led_line_state[i][j] = LED_STATE_OFF;
            matrix_led_line_timecnt[i][j] = 0;
        }
    }

    led_ann_cs_all_off();
    led_ann_cs_one_on(0);

    matrix_cur_line = 0;
    matrix_cur_cnt = 0;
}

static void led_line_fsm_clear()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            matrix_led_line_state[i][j] = LED_STATE_OFF;
            matrix_led_line_timecnt[i][j] = 0;
            matrix_led_off[i][j]();
        }
    }
}

static void led_line_fsm_step()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            const uint32_t cur_bright = (matrix_global_bright * matrix_bright_cur_rgb[matrix_cur_line][i][j]);

            matrix_led_line_timecnt[i][j]++;

            if (matrix_led_line_state[i][j] == LED_STATE_OFF)
            {
                if (matrix_led_line_timecnt[i][j] >= (max_total_bright - cur_bright))
                {
                    matrix_led_line_timecnt[i][j] = 0;
                    if (cur_bright >= 1)
                    {
                        matrix_led_on[i][j]();
                        matrix_led_line_state[i][j] = LED_STATE_ON;
                    }
                }
            }
            else  // LED_STATE_ON
            {
                if (matrix_led_line_timecnt[i][j] >= cur_bright)
                {
                    matrix_led_line_timecnt[i][j] = 0;
                    if ((max_total_bright - cur_bright) >= 1)
                    {
                        matrix_led_off[i][j]();
                        matrix_led_line_state[i][j] = LED_STATE_OFF;
                    }
                }
            }
        }
    }
}

void led_matrix_fsm_step()
{
    ++matrix_cur_cnt;

    if (matrix_cur_cnt > max_total_bright)  // Select New Line
    {
        matrix_cur_cnt = 0;
        matrix_cur_line++;
        if (matrix_cur_line > 9)
            matrix_cur_line = 0;
        led_line_fsm_clear();
        led_ann_cs_one_on(matrix_cur_line);
    }

    led_line_fsm_step();
}

void led_matrix_fsm_set_global_bright(uint32_t globalBright) //1..5
{
    if (globalBright <= 1)
        globalBright = 1;
    if (globalBright >= matrix_max_global_bright)
        globalBright = matrix_max_global_bright;
    matrix_global_bright = globalBright;
}

uint32_t led_matrix_fsm_get_global_bright()
{
    return matrix_global_bright;
}

void led_matrix_fsm_set_rgb_bright(uint32_t line0_9, uint32_t row0_2, uint8_t br_red, uint8_t br_green, uint8_t br_blue)
{
    if (br_red > matrix_max_bright)
        br_red = matrix_max_bright;

    if (br_green > matrix_max_bright)
        br_green = matrix_max_bright;

    if (br_blue > matrix_max_bright)
        br_blue = matrix_max_bright;

    matrix_bright_cur_rgb[line0_9][row0_2][0] = br_red;
    matrix_bright_cur_rgb[line0_9][row0_2][1] = br_green;
    matrix_bright_cur_rgb[line0_9][row0_2][2] = br_blue;
}



uint8_t led_matrix_fsm_get_red(uint32_t line0_9, uint32_t row0_2)
{
    return matrix_bright_cur_rgb[line0_9][row0_2][0];
}

uint8_t led_matrix_fsm_get_green(uint32_t line0_9, uint32_t row0_2)
{
    return matrix_bright_cur_rgb[line0_9][row0_2][1];
}

uint8_t led_matrix_fsm_get_blue(uint32_t line0_9, uint32_t row0_2)
{
    return matrix_bright_cur_rgb[line0_9][row0_2][2];
}



/*
void led_red_power(uint32_t val)
{
	if (val)
		led_red_power_on();
	else
		led_red_power_off();
}

void led_red_power_off(void)
{
	gpio_set_data_bit_zero(LED_RED_PORT, LED_RED_BIT);
}

void led_red_power_on(void)
{
	gpio_set_data_bit_one(LED_RED_PORT, LED_RED_BIT);
}

void led_green_power(uint32_t val)
{
	if (val)
		led_green_power_on();
	else
		led_green_power_off();
}

void led_green_power_off(void)
{
	gpio_set_data_bit_zero(LED_GREEN_PORT, LED_GREEN_BIT);
}

void led_green_power_on(void)
{
	gpio_set_data_bit_one(LED_GREEN_PORT, LED_GREEN_BIT);
}
*/
