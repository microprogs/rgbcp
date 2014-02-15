#include <armv7m.h>
#include <debug.h>
#include <gpio.h>
#include <timer16.h>
#include <boardinit.h>
#include <leds.h>
#include <switches.h>
#include <gpio.h>
#include <ioconfig.h>
#include <sysctrl.h>
#include <delay.h>
#include <debug.h>
#include <string.h>



int main() 
{
	// Init Board
	board_init();

	// LED ....


	// Process Deffered Procedure Calls
	while (1)  // Forever
	{
		extern void DPCDispatch(void);
		DPCDispatch();
	}

	// This never return
	return 0;
} 

