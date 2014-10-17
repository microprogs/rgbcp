#ifndef MCUFRAMEDECOMPRESSOR_H
#define MCUFRAMEDECOMPRESSOR_H


#include <stdint.h>
#include "mcubitstreamreader.h"


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


typedef struct _FRAME_DECOMPRESSOR_CTX
{
    BIT_READER_CTX br_ctx;
    uint8_t last_frame[32];
} FRAME_DECOMPRESSOR_CTX;



void frame_decompressor_init(FRAME_DECOMPRESSOR_CTX *ctx, uint8_t *buf);  //min buf size = 4
int frame_decompressor_get_next_frame(FRAME_DECOMPRESSOR_CTX *ctx, uint8_t frame_buf[32]);



#endif // MCUFRAMEDECOMPRESSOR_H
