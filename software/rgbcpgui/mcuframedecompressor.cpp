#include "mcuframedecompressor.h"


/*
Compress Format: (DATA[size in bits])
"(total_bit_count[32]) (REPFRAME_COMPRESS[2])* (RLE_COMPRESS[2+(5+8)*(1..32)])* (INDEX_COMPRESS[2+5+(5+8)*(1..32)])* (PLAIN_COMPRESS[2+32*8])*"

(REPFRAME_COMPRESS[2]) = (bits"00"{magic: repeat last frame})

(RLE_COMPRESS[2+(5+8)*(1..32)]) = (bits"01"{magic: RLE}) (RLE_BLOCK[5+8])*(1..32)
(RLE_BLOCK[5+8]) = (bits"00000..11111"[5]{byte count (1..32) from (0..31)}) (byte"00..FF"[8]{repeatable byte})

(INDEX_COMPRESS[2+5+(5+8)*(1..32)]) = (bits"10"{magic: INDEX}) (bits"00000..11111"[5]{index count (1..32) from (0..31)}) (INDEX_BLOCK[5+8])*(1..32)
(INDEX_BLOCK[5+8]) = (bits"00000..11111"[5]{index in frame = 0..31}) (byte"00..FF"[8]{byte for index})

(PLAIN_COMPRESS[2+32*8]) = (bits"11"{magic: PLAIN}) (byte"00..FF"[8]{plain byte})*32
*/



void frame_decompressor_init(FRAME_DECOMPRESSOR_CTX *ctx, uint8_t *buf)
{
    uint32_t bit_count = 0;
    ((uint8_t*)&bit_count)[0] = buf[0];
    ((uint8_t*)&bit_count)[1] = buf[1];
    ((uint8_t*)&bit_count)[2] = buf[2];
    ((uint8_t*)&bit_count)[3] = buf[3];

    bit_reader_init(&(ctx->br_ctx), buf+4, bit_count);

    for (int i = 0; i < 32; ++i)
        ctx->last_frame[i] = 0;
}


static int decompress_rep_frame(BIT_READER_CTX *br_ctx, uint8_t diff_frame_buf[32])
{
    //(REPFRAME_COMPRESS[2]) = (bits"00"{magic: repeat last frame})
    (void)(br_ctx);
    for (int i = 0; i < 32; ++i)
        diff_frame_buf[i] = 0;
    return 1;
}

static int decompress_rle(BIT_READER_CTX *br_ctx, uint8_t diff_frame_buf[32])
{
    //(RLE_COMPRESS[2+(5+8)*(1..32)]) = (bits"01"{magic: RLE}) (RLE_BLOCK[5+8])*(1..32)
    //(RLE_BLOCK[5+8]) = (bits"00000..11111"[5]{byte count (1..32) from (0..31)}) (byte"00..FF"[8]{repeatable byte})
    for (int i = 0; i < 32; ++i)
        diff_frame_buf[i] = 0;

    int res = 0;

    if (bit_reader_rest_bit_count(br_ctx) >= (5+8))
    {
        int pos = 0;

        for (int i = 0; i < 32 && pos < 32; ++i)
        {
            if (bit_reader_rest_bit_count(br_ctx) >= (5+8))
            {
                uint8_t byte_count = 0;
                if (bit_reader_read_bits(br_ctx, 5, &byte_count) == 5)  //0..31
                {
                    ++byte_count;  //1..32
                    uint8_t byte_pattern = 0;
                    if (bit_reader_read_bits(br_ctx, 8, &byte_pattern) == 8)
                    {
                        for (int k = 0; k < byte_count; ++k)
                        {
                            if (pos < 32)
                            {
                                diff_frame_buf[pos] = byte_pattern;
                                ++pos;
                            }
                        }
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else
                break;
        }

        if (pos == 32)
        {
            ++res;
        }
    }

    return res;
}

static int decompress_index(BIT_READER_CTX *br_ctx, uint8_t diff_frame_buf[32])
{
    //(INDEX_COMPRESS[2+5+(5+8)*(1..32)]) = (bits"10"{magic: INDEX}) (bits"00000..11111"[5]{index count (1..32) from (0..31)}) (INDEX_BLOCK[5+8])*(1..32)
    //(INDEX_BLOCK[5+8]) = (bits"00000..11111"[5]{index in frame = 0..31}) (byte"00..FF"[8]{byte for index})
    for (int i = 0; i < 32; ++i)
        diff_frame_buf[i] = 0;

    int res = 0;

    if (bit_reader_rest_bit_count(br_ctx) >= (5+(5+8)))
    {
        uint8_t icnt = 0;
        if (bit_reader_read_bits(br_ctx, 5, &icnt) == 5)
        {
            uint32_t index_count = (uint32_t)icnt + 1;

            int is_ok = 1;
            for (uint32_t i = 0; i < index_count && is_ok; ++i)
            {
                uint8_t index_pos = 0;
                uint8_t index_val = 0;

                if (bit_reader_read_bits(br_ctx, 5, &index_pos) == 5)
                {
                    if (bit_reader_read_bits(br_ctx, 8, &index_val) == 8)
                    {
                        if (index_pos < 32)
                        {
                            diff_frame_buf[index_pos] = index_val;
                        }
                        else
                            is_ok = false;
                    }
                    else
                        is_ok = false;
                }
                else
                    is_ok = false;
            }

            if (is_ok)
            {
                ++res;
            }
        }
    }

    return res;
}

static int decompress_plain(BIT_READER_CTX *br_ctx, uint8_t diff_frame_buf[32])
{
    //(PLAIN_COMPRESS[2+32*8]) = (bits"11"{magic: PLAIN}) (byte"00..FF"[8]{plain byte})*32
    for (int i = 0; i < 32; ++i)
        diff_frame_buf[i] = 0;

    int res = 0;

    if (bit_reader_rest_bit_count(br_ctx) >= (32*8))
    {
        int pos = 0;
        for (int i = 0; i < 32; ++i)
        {
            uint8_t b = 0;
            if (bit_reader_read_bits(br_ctx, 8, &b) == 8)
            {
                diff_frame_buf[pos] = b;
                ++pos;
            }
        }

        if (pos == 32)
        {
            ++res;
        }
    }

    return res;
}


static int extract_diff_frame(BIT_READER_CTX *br_ctx, uint8_t diff_frame_buf[32])
{
    /*
    "(REPFRAME_COMPRESS[2])* (RLE_COMPRESS[2+(5+8)*(1..32)])* (INDEX_COMPRESS[2+5+(5+8)*(1..32)])* (PLAIN_COMPRESS[2+32*8])*"

    (REPFRAME_COMPRESS[2]) = (bits"00"{magic: repeat last frame})

    (RLE_COMPRESS[2+(5+8)*(1..32)]) = (bits"01"{magic: RLE}) (RLE_BLOCK[5+8])*(1..32)
    (RLE_BLOCK[5+8]) = (bits"00000..11111"[5]{byte count (1..32) from (0..31)}) (byte"00..FF"[8]{repeatable byte})

    (INDEX_COMPRESS[2+5+(5+8)*(1..32)]) = (bits"10"{magic: INDEX}) (bits"00000..11111"[5]{index count (1..32) from (0..31)}) (INDEX_BLOCK[5+8])*(1..32)
    (INDEX_BLOCK[5+8]) = (bits"00000..11111"[5]{index in frame = 0..31}) (byte"00..FF"[8]{byte for index})

    (PLAIN_COMPRESS[2+32*8]) = (bits"11"{magic: PLAIN}) (byte"00..FF"[8]{plain byte})*32
    */
    int res = 0;

    for (int i = 0; i < 32; ++i)
        diff_frame_buf[i] = 0;

    if (bit_reader_rest_bit_count(br_ctx) >= 2)
    {
        uint8_t compress_type = 0;
        if (bit_reader_read_bits(br_ctx, 2, &compress_type) == 2)
        {
            switch (compress_type)
            {
            case 0x00:  //bin"00"
                if (decompress_rep_frame(br_ctx, diff_frame_buf))
                    ++res;
                break;

            case 0x01:  //bin"01"
                if (decompress_rle(br_ctx, diff_frame_buf))
                    ++res;
                break;

            case 0x02:  //bin"10"
                if (decompress_index(br_ctx, diff_frame_buf))
                    ++res;
                break;

            case 0x03:  //bin"11"
                if (decompress_plain(br_ctx, diff_frame_buf))
                    ++res;
                break;

            default:
                break;
            }
        }
    }

    return res;
}

static void restore_diff(const uint8_t last_frame_buf[32], const uint8_t diff_frame_buf[32], uint8_t cur_frame_buf[32])
{
    for (int i = 0; i < 32; ++i)
    {
        cur_frame_buf[i] = (uint8_t)diff_frame_buf[i] + (uint8_t)last_frame_buf[i];
    }
}

int frame_decompressor_get_next_frame(FRAME_DECOMPRESSOR_CTX *ctx, uint8_t frame_buf[32])
{
    int res = 0;

    for (int i = 0; i < 32; ++i)
        frame_buf[i] = 0;

    uint8_t diff_buf[32];
    if (extract_diff_frame(&(ctx->br_ctx), diff_buf))
    {
        restore_diff(ctx->last_frame, diff_buf, frame_buf);
        for (int i = 0; i < 32; ++i)
            ctx->last_frame[i] = frame_buf[i];

        ++res;
    }

    return res;
}
