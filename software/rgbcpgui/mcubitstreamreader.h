#ifndef MCUBITSTREAMREADER_H
#define MCUBITSTREAMREADER_H


#include <stdint.h>


typedef struct _BIT_READER_CTX
{
    uint8_t *buf;
    uint32_t size_bytes;
    uint32_t bit_count;
    uint32_t cur_byte_pos;
    uint32_t used_bits;
    uint8_t remain_bits_in_byte;
} BIT_READER_CTX;


void bit_reader_init(BIT_READER_CTX *ctx, uint8_t *buf, uint32_t bit_count);
uint8_t bit_reader_read_bits(BIT_READER_CTX *ctx, uint8_t nbits, uint8_t *out_bits);
uint32_t bit_reader_bit_count(BIT_READER_CTX *ctx);
uint32_t bit_reader_rest_bit_count(BIT_READER_CTX *ctx);


#endif // MCUBITSTREAMREADER_H
