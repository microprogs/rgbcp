#include <bits.h>

uint32_t bit_mask(uint32_t nbit)
{
	return (1 << nbit);
}

void set_bit_zero(volatile uint32_t *word, uint32_t nbit)
{
	*word &= ~(bit_mask(nbit));
}

void set_bit_one(volatile uint32_t *word, uint32_t nbit)
{
	*word |= bit_mask(nbit);
}

void set_bit(volatile uint32_t *word, uint32_t nbit, uint32_t val)
{
	if (val)
		set_bit_one(word, nbit);
	else
		set_bit_zero(word, nbit);
}

uint32_t bit_is_set(volatile uint32_t *word, uint32_t nbit)
{
	return ((*word) & bit_mask(nbit)) ? 1 : 0;
}

void set_all_bits_zero(volatile uint32_t *word, uint32_t nbits)
{
	*word &= ~nbits;
}

void set_all_bits_one(volatile uint32_t *word, uint32_t nbits)
{
	*word |= nbits;
}

