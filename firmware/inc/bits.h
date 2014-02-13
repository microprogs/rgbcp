#ifndef BITS_H
#define BITS_H

#include <types.h>


uint32_t bit_mask(uint32_t nbit);
void set_bit_zero(volatile uint32_t *word, uint32_t nbit);
void set_bit_one(volatile uint32_t *word, uint32_t nbit);
void set_bit(volatile uint32_t *word, uint32_t nbit, uint32_t val);
uint32_t bit_is_set(volatile uint32_t *word, uint32_t nbit);
void set_all_bits_zero(volatile uint32_t *word, uint32_t nbits);
void set_all_bits_one(volatile uint32_t *word, uint32_t nbits);


#endif

