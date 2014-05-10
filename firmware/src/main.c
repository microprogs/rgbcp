#include <boardinit.h>
#include "threads.h"

int main()
{
	board_init();

	init_threads();

	loop_main_thread();

	// This never return
	return 0;
} 

