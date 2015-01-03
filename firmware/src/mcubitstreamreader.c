#include "mcubitstreamreader.h"


void bit_reader_init(BIT_READER_CTX *ctx, uint8_t *buf, uint32_t bit_count)
{
    ctx->buf = buf;
    ctx->size_bytes = bit_count / 8;
    if (bit_count % 8 != 0)
        ctx->size_bytes++;
    ctx->bit_count = bit_count;
    ctx->cur_byte_pos = 0;
    ctx->remain_bits_in_byte = 8;
    ctx->used_bits = 0;
}


uint8_t bit_reader_read_bits(BIT_READER_CTX *ctx, uint8_t nbits, uint8_t *out_bits)
{
    *out_bits = 0;

    uint8_t cnt_bits = 0;

    if (nbits > 8)
        nbits = 8;

    if (nbits > 0 && ctx->used_bits < ctx->bit_count)
    {
        uint32_t rest_bits = ctx->bit_count - ctx->used_bits;

        if (nbits > rest_bits)
            nbits = rest_bits;

        if (ctx->remain_bits_in_byte == 0)
        {
            if ((ctx->cur_byte_pos+1) < ctx->size_bytes)
            {
                ctx->cur_byte_pos++;
                ctx->remain_bits_in_byte = 8;
            }
        }

        if (ctx->remain_bits_in_byte > 0)
        {
            uint8_t bits = 0;
            if (nbits > ctx->remain_bits_in_byte)
            {
                if (ctx->cur_byte_pos < ctx->size_bytes)
                {
                    bits = ctx->buf[ctx->cur_byte_pos];
                    bits <<= (8 - ctx->remain_bits_in_byte);
                    bits >>= (8 - nbits);

                    if ((ctx->cur_byte_pos+1) < ctx->size_bytes)
                    {
                        ctx->cur_byte_pos++;
                        ctx->remain_bits_in_byte += 8 - nbits;
                        bits |= ctx->buf[ctx->cur_byte_pos] >> ctx->remain_bits_in_byte;

                        cnt_bits += nbits;
                        ctx->used_bits += nbits;
                        *out_bits = bits;
                    }
                }
            }
            else
            {
                if (ctx->cur_byte_pos < ctx->size_bytes)
                {
                    bits = ctx->buf[ctx->cur_byte_pos];
                    bits <<= (8 - ctx->remain_bits_in_byte);
                    bits >>= (8 - nbits);
                    ctx->remain_bits_in_byte -= nbits;

                    cnt_bits += nbits;
                    ctx->used_bits += nbits;
                    *out_bits = bits;
                }
            }
        }
    }

    return cnt_bits;
}

uint32_t bit_reader_bit_count(BIT_READER_CTX *ctx)
{
    return ctx->bit_count;
}

uint32_t bit_reader_rest_bit_count(BIT_READER_CTX *ctx)
{
    return ctx->bit_count - ctx->used_bits;
}
