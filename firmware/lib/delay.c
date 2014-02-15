#include <delay.h>
#include <armv7m.h>
#include <timer16.h>


void delay_ticks(uint32_t nticks)
{
	int i;
	for (i = 0; i < nticks; i++)
		no_operation();
}

// us=1..1000
void delay_us(uint32_t us)
{
	delay_microseconds(1, us);
}

void delay_ms(uint32_t ms)
{
	uint32_t i;
	for (i = 0; i < ms; i++)
		delay_us(1000);
}

