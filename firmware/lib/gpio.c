#include <gpio.h>
#include <bits.h>
#include <mmap.h>



static volatile struct memio_gpio_port *gpio_port_num_to_addr(uint32_t nport)
{
	switch (nport)
	{
	case 0:	return &mmap->ahb_gpio_port0;
	case 1:	return &mmap->ahb_gpio_port1;
	case 2:	return &mmap->ahb_gpio_port2;
	case 3:	return &mmap->ahb_gpio_port3;
	}
	return NULL;
}


void gpio_set_dir_in(uint32_t nport, uint32_t nbit)
{
	gpio_set_dir(nport, nbit, 0);
}

void gpio_set_dir_out(uint32_t nport, uint32_t nbit)
{
	gpio_set_dir(nport, nbit, 1);
}

void gpio_set_dir(uint32_t nport, uint32_t nbit, uint32_t val)
{
	volatile struct memio_gpio_port *port = gpio_port_num_to_addr(nport);
	set_bit(&port->dir, nbit, val);
}

void gpio_set_data_bit_zero(uint32_t nport, uint32_t nbit)
{
	gpio_set_data_bit(nport, nbit, 0);
}

void gpio_set_data_bit_one(uint32_t nport, uint32_t nbit)
{
	gpio_set_data_bit(nport, nbit, 1);
}

void gpio_set_data_bit(uint32_t nport, uint32_t nbit, uint32_t val)
{
	volatile struct memio_gpio_port *port = gpio_port_num_to_addr(nport);
	set_bit(&port->mask_data[bit_mask(nbit)], nbit, val);
}

uint32_t gpio_get_data_bit(uint32_t nport, uint32_t nbit)
{
	volatile struct memio_gpio_port *port = gpio_port_num_to_addr(nport);
	return bit_is_set(&port->mask_data[bit_mask(nbit)], nbit);
}

