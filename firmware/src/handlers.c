#include <types.h>
#include <string.h>
#include <usbdrvrom.h>


void reset_handler(void)
{
	// Init .data section (with .usb_drv_ram)
	extern int _etext;
	extern int _data;
	extern int _edata;

	char* data_phys_start = (char*)(&_etext);  // .data in FLASH
	char* data_virt_start = (char*)(&_data);   // .data in RAM
	char* data_virt_end   = (char*)(&_edata);
	size_t data_size = data_virt_end - data_virt_start;
	
	memcpy(data_virt_start, data_phys_start, data_size);


	// Init .bss section
	extern int _bss;
	extern int _ebss;

	char* bss_start = (char*)(&_bss);
	char* bss_end   = (char*)(&_ebss);
	size_t bss_size = bss_end - bss_start;

	memset(bss_start, 0, bss_size);	
	
	// Call main function
	extern void main(void);

	main();

	while (1);
}

void nmi_handler(void)
{
}

void hard_fault_handler(void)
{
}

void mem_manager_handler(void)
{
}

void bus_fault_handler(void)
{
}

void usage_fault_handler(void)
{
}

void sv_call_handler(void)
{
}

void debug_mon_handler(void)
{
}

void pend_sv_handler(void)
{
}

void sys_tick_handler(void)
{
} 

void wakeup_irq_handler(void)
{
}

void i2c_irq_handler(void)
{
}

void timer16_0_irq_handler(void)
{
	extern void timer16_0_irqhandler(void);
	timer16_0_irqhandler();
}

void timer16_1_irq_handler(void)
{
}

void timer32_0_irq_handler(void)
{
}

void timer32_1_irq_handler(void)
{
}

void ssp_irq_handler(void)
{
}

void uart_irq_handler(void)
{
}

void usb_irq_handler(void)
{
	usbdrvrom_isr();
}

void usb_fiq_handler(void)
{
}

void adc_irq_handler(void)
{
} 

void wdt_irq_handler(void)
{
}

void bod_irq_handler(void)
{
}

void fmc_irq_handler(void)
{
}

void pio_int3_irq_handler(void)
{
} 

void pio_int2_irq_handler(void)
{
}

void pio_int1_irq_handler(void)
{
}

void pio_int0_irq_handler(void)
{
}

