#ifndef GPIO_H
#define GPIO_H

#include <types.h>


void gpio_set_dir_in(uint32_t nport, uint32_t nbit);
void gpio_set_dir_out(uint32_t nport, uint32_t nbit);
void gpio_set_dir(uint32_t nport, uint32_t nbit, uint32_t val);
void gpio_set_data_bit_zero(uint32_t nport, uint32_t nbit);
void gpio_set_data_bit_one(uint32_t nport, uint32_t nbit);
void gpio_set_data_bit(uint32_t nport, uint32_t nbit, uint32_t val);
uint32_t gpio_get_data_bit(uint32_t nport, uint32_t nbit);


#endif

