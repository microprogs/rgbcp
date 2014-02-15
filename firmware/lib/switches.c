#include <switches.h>
#include <gpio.h>

void init_switches(void)
{
//	gpio_set_dir_in(SWITCH_DBG_PORT, SWITCH_DBG_BIT);
}

uint32_t switch_dbg_is_set(void)
{
//	return gpio_get_data_bit(SWITCH_DBG_PORT, SWITCH_DBG_BIT) ? 0 : 1;
}

