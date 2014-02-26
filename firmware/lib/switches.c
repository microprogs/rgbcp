#include <switches.h>
#include <gpio.h>


void init_switches(void)
{
	// PIO3_0 - DBG_FLAG	
	gpio_set_dir_in(3, 0);
}


uint32_t switch_dbg_is_set(void)
{
	// PIO3_0 - DBG_FLAG
	return gpio_get_data_bit(3, 0) ? 0 : 1;
}

