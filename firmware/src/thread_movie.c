#include "thread_movie.h"
#include "types.h"

#include "movies.h"
#include "mcuframedecompressor.h"
#include "leds.h"
#include "scene.h"



static FRAME_DECOMPRESSOR_CTX ctx;
static uint8_t frame_buf[32];
static volatile int delay = 0;

static int auto_mode = 1;
static int auto_program_index = 0;
static int auto_delay = 0;



static void reset_program()
{
    frame_decompressor_init(&ctx, (uint8_t*)(array_bin_ptrs[scene_program_get_index()]));
    delay = 0;
}

static int program_next()
{
    return frame_decompressor_get_next_frame(&ctx, frame_buf);
}


static void auto_reset_program()
{
    frame_decompressor_init(&ctx, (uint8_t*)(array_bin_ptrs[auto_program_index]));
    auto_delay = 0;
}



void thread_movie_init()
{
    reset_program();
    auto_reset_program();
}

void thread_movie_tick()
{
    if (get_new_program_flag())
    {
        reset_new_program_flag();
        reset_program();

        if (auto_mode)
        {
            scene_program_down();
            auto_mode = 0;
            return;
        }
    }

    if (auto_mode)
    {
        if (auto_delay > 0)
        {
            auto_delay--;
            return;
        }

        if (program_next())
        {
            set_led_bright_from_frame(frame_buf);
            auto_delay = (uint32_t)load_delay_from_frame(frame_buf) * scene_speed_get_mult();
        }
        else
        {
            auto_program_index++;
            if (auto_program_index >= count_bin_files)
                auto_program_index = 0;

            auto_reset_program();
        }
    }
    else
    {
        if (delay > 0)
        {
            delay--;
            return;
        }

        if (program_next())
        {
            set_led_bright_from_frame(frame_buf);
            delay = (uint32_t)load_delay_from_frame(frame_buf) * scene_speed_get_mult();
        }
        else
        {
            reset_program();
        }
    }
}
