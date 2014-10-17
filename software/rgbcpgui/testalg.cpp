#include "testalg.h"
#include <QVector>
#include "mcubitstreamreader.h"
#include "bitstreamreader.h"
#include "bitstreamwriter.h"
#include "ledframecompressor.h"
#include "ledframedecompressor.h"
#include "mcuframedecompressor.h"


TestAlg::TestAlg()
{
}


void TestAlg::testAll()
{
    testBitStream();
    testCompressor();
}

void TestAlg::testBitStream()
{
    BitStreamWriter bswr;


    BitStreamReader bsrd;
    Q_ASSERT(bsrd.bitsCount() == 0);
    Q_ASSERT(bsrd.restBitsCount() == 0);
    quint8 out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 7) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 9) == 0);
    Q_ASSERT(out_bits == 0);
    Q_ASSERT(bsrd.bitsCount() == 0);
    Q_ASSERT(bsrd.restBitsCount() == 0);
    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex(""), 0) == false);

    BIT_READER_CTX ctx;
    memset(&ctx, '\xAA', sizeof(ctx));

    QByteArray buf;

    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 0);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 7, &out_bits) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 0);
    Q_ASSERT(out_bits == 0);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 9, &out_bits) == 0);
    Q_ASSERT(out_bits == 0);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    buf = QByteArray::fromHex("");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 0);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);


    //"" -> ""[0]
    Q_ASSERT(bswr.bitsCount() == 0);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex(""));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex(""), 0) == false);
    Q_ASSERT(bsrd.bitsCount() == 0);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 0);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"1" -> "1 0000000"[bits=1, bytes=1]
    bswr.appendBits(0x01, 1);
    Q_ASSERT(bswr.bitsCount() == 1);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("80"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("80"), 1) == true);
    Q_ASSERT(bsrd.bitsCount() == 1);
    Q_ASSERT(bsrd.restBitsCount() == 1);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 1);
    Q_ASSERT(bsrd.readBits(out_bits, 9) == 1);
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 0);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("80");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 1);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 1);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 1);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 1);
    Q_ASSERT(bit_reader_read_bits(&ctx, 9, &out_bits) == 1);
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"0" -> "1 0 000000"[bits=2, bytes=1]
    bswr.appendBits(0x00, 1);
    Q_ASSERT(bswr.bitsCount() == 2);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("80"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("80"), 2) == true);
    Q_ASSERT(bsrd.bitsCount() == 2);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 9) == 2);
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 0);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("80");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 2);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 9, &out_bits) == 2);
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"11" -> "10 11 0000"[bits=4, bytes=1]
    bswr.appendBits(0x03, 2);
    Q_ASSERT(bswr.bitsCount() == 4);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B0"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B0"), 4) == true);
    Q_ASSERT(bsrd.bitsCount() == 4);
    Q_ASSERT(bsrd.restBitsCount() == 4);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 4);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);
    Q_ASSERT(out_bits == 0x03);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B0");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 4);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 4);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 4);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 4);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);
    Q_ASSERT(out_bits == 0x03);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"00" -> "1011 00 00"[bits=6, bytes=1]
    bswr.appendBits(0x00, 2);
    Q_ASSERT(bswr.bitsCount() == 6);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B0"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B0"), 6) == true);
    Q_ASSERT(bsrd.bitsCount() == 6);
    Q_ASSERT(bsrd.restBitsCount() == 6);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 6);
    Q_ASSERT(bsrd.readBits(out_bits, 4) == 4);
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B0");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 6);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 6);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 6);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 6);
    Q_ASSERT(bit_reader_read_bits(&ctx, 4, &out_bits) == 4);
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"10" -> "101100 10"[bits=8, bytes=1]
    bswr.appendBits(0x02, 2);
    Q_ASSERT(bswr.bitsCount() == 8);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B2"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B2"), 8) == true);
    Q_ASSERT(bsrd.bitsCount() == 8);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B2");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 8);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"0" -> "10110010 0 0000000"[bits=9, bytes=2]
    bswr.appendBits(0x00, 1);
    Q_ASSERT(bswr.bitsCount() == 9);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B200"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B200"), 9) == true);
    Q_ASSERT(bsrd.bitsCount() == 9);
    Q_ASSERT(bsrd.restBitsCount() == 9);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 9);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //1    0110010 0 0000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0110 0100    0000000
    Q_ASSERT(out_bits == 0x64);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B200");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 9);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 9);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 9);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 9);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //1    0110010 0 0000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0110 0100    0000000
    Q_ASSERT(out_bits == 0x64);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"1" -> "10110010 0 1 000000"[bits=10, bytes=2]
    bswr.appendBits(0x01, 1);
    Q_ASSERT(bswr.bitsCount() == 10);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B240"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B240"), 10) == true);
    Q_ASSERT(bsrd.bitsCount() == 10);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //1011 0010  01000000
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 3) == 2);  //01 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B240");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 10);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //1011 0010  01000000
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 3, &out_bits) == 2);  //01 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"00" -> "10110010 01 00 0000"[bits=12, bytes=2]
    bswr.appendBits(0x00, 2);
    Q_ASSERT(bswr.bitsCount() == 12);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B240"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B240"), 12) == true);
    Q_ASSERT(bsrd.bitsCount() == 12);
    Q_ASSERT(bsrd.restBitsCount() == 12);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 12);
    Q_ASSERT(bsrd.readBits(out_bits, 4) == 4);  //1011    0010 01 00 0000
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0010 0100   0000
    Q_ASSERT(out_bits == 0x24);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B240");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 12);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 12);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 12);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 12);
    Q_ASSERT(bit_reader_read_bits(&ctx, 4, &out_bits) == 4);  //1011    0010 01 00 0000
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0010 0100   0000
    Q_ASSERT(out_bits == 0x24);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"01" -> "10110010 0100 01 00"[bits=14, bytes=2]
    bswr.appendBits(0x01, 2);
    Q_ASSERT(bswr.bitsCount() == 14);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B244"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B244"), 14) == true);
    Q_ASSERT(bsrd.bitsCount() == 14);
    Q_ASSERT(bsrd.restBitsCount() == 14);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 14);
    Q_ASSERT(bsrd.readBits(out_bits, 4) == 4);  //1011    0010 0100 01 00
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0010 0100    01 00
    Q_ASSERT(out_bits == 0x24);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //0    1 00
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bsrd.restBitsCount() == 1);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //1    00
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B244");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 14);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 14);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 14);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 14);
    Q_ASSERT(bit_reader_read_bits(&ctx, 4, &out_bits) == 4);  //1011    0010 0100 01 00
    Q_ASSERT(out_bits == 0x0B);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0010 0100    01 00
    Q_ASSERT(out_bits == 0x24);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //0    1 00
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 1);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //1    00
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"0" -> "10110010 010001 0 0"[bits=15, bytes=2]
    bswr.appendBits(0x00, 1);
    Q_ASSERT(bswr.bitsCount() == 15);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B244"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B244"), 15) == true);
    Q_ASSERT(bsrd.bitsCount() == 15);
    Q_ASSERT(bsrd.restBitsCount() == 15);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 15);
    Q_ASSERT(bsrd.readBits(out_bits, 5) == 5);  //1 0110    010 010001 0 0
    Q_ASSERT(out_bits == 0x16);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);  //01    0 010001 0 0
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 4) == 4);  //0010    001 0 0
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 4);
    Q_ASSERT(bsrd.readBits(out_bits, 4) == 4);  //0010   0
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B244");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 15);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 15);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 15);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 15);
    Q_ASSERT(bit_reader_read_bits(&ctx, 5, &out_bits) == 5);  //1 0110    010 010001 0 0
    Q_ASSERT(out_bits == 0x16);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);  //01    0 010001 0 0
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 4, &out_bits) == 4);  //0010    001 0 0
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 4);
    Q_ASSERT(bit_reader_read_bits(&ctx, 4, &out_bits) == 4);  //0010   0
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);


    //"10" -> "10110010  0100010 1  0 0000000"[bits=17, bytes=3]
    bswr.appendBits(0x02, 2);
    Q_ASSERT(bswr.bitsCount() == 17);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B24500"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B24500"), 17) == true);
    Q_ASSERT(bsrd.bitsCount() == 17);
    Q_ASSERT(bsrd.restBitsCount() == 17);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 17);
    Q_ASSERT(bsrd.readBits(out_bits, 7) == 7);  //101 1001     0  0100010 1  0 0000000
    Q_ASSERT(out_bits == 0x59);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0010 0010     1  0 0000000
    Q_ASSERT(out_bits == 0x22);
    Q_ASSERT(bsrd.restBitsCount() == 2);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);  //10  0000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B24500");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 17);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 17);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 17);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 17);
    Q_ASSERT(bit_reader_read_bits(&ctx, 7, &out_bits) == 7);  //101 1001     0  0100010 1  0 0000000
    Q_ASSERT(out_bits == 0x59);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0010 0010     1  0 0000000
    Q_ASSERT(out_bits == 0x22);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 2);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);  //10  0000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"1" -> "10110010  0100010 1  0 1 000000"[bits=18, bytes=3]
    bswr.appendBits(0x01, 1);
    Q_ASSERT(bswr.bitsCount() == 18);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B24540"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B24540"), 18) == true);
    Q_ASSERT(bsrd.bitsCount() == 18);
    Q_ASSERT(bsrd.restBitsCount() == 18);
    out_bits = 0xAA;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 18);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //1   0110010  0100010 1  0 1 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 17);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //0    110010  0100010 1  0 1 000000
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bsrd.restBitsCount() == 16);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //1100 1001    00010 1  0 1 000000
    Q_ASSERT(out_bits == 0xC9);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 5) == 5);  //0 0010     1  0 1 000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 3);
    Q_ASSERT(bsrd.readBits(out_bits, 3) == 3);  //101   000000
    Q_ASSERT(out_bits == 0x05);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B24540");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 18);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 18);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 18);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 18);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //1   0110010  0100010 1  0 1 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 17);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //0    110010  0100010 1  0 1 000000
    Q_ASSERT(out_bits == 0x00);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 16);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //1100 1001    00010 1  0 1 000000
    Q_ASSERT(out_bits == 0xC9);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 5, &out_bits) == 5);  //0 0010     1  0 1 000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 3);
    Q_ASSERT(bit_reader_read_bits(&ctx, 3, &out_bits) == 3);  //101   000000
    Q_ASSERT(out_bits == 0x05);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);


    //"10101010" -> "10110010  0100010 1  01 101010  10 000000"[bits=26, bytes=4]
    bswr.appendBits(0xAA, 8);
    Q_ASSERT(bswr.bitsCount() == 26);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B2456A80"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B2456A80"), 26) == true);
    Q_ASSERT(bsrd.bitsCount() == 26);
    Q_ASSERT(bsrd.restBitsCount() == 26);
    out_bits = 0xFF;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 26);
    Q_ASSERT(bsrd.readBits(out_bits, 6) == 6);  //10 1100    10  0100010 1  01 101010  10 000000
    Q_ASSERT(out_bits == 0x2C);
    Q_ASSERT(bsrd.restBitsCount() == 20);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);  //10    0100010 1  01 101010  10 000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bsrd.restBitsCount() == 18);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0100 0101     01 101010  10 000000
    Q_ASSERT(out_bits == 0x45);
    Q_ASSERT(bsrd.restBitsCount() == 10);
    Q_ASSERT(bsrd.readBits(out_bits, 2) == 2);  //01    101010  10 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 8);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //1010 1010   000000
    Q_ASSERT(out_bits == 0xAA);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B2456A80");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 26);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 26);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 26);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 26);
    Q_ASSERT(bit_reader_read_bits(&ctx, 6, &out_bits) == 6);  //10 1100    10  0100010 1  01 101010  10 000000
    Q_ASSERT(out_bits == 0x2C);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 20);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);  //10    0100010 1  01 101010  10 000000
    Q_ASSERT(out_bits == 0x02);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 18);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0100 0101     01 101010  10 000000
    Q_ASSERT(out_bits == 0x45);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 10);
    Q_ASSERT(bit_reader_read_bits(&ctx, 2, &out_bits) == 2);  //01    101010  10 000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 8);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //1010 1010   000000
    Q_ASSERT(out_bits == 0xAA);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);

    //"0000001" -> "10110010  0100010 1  01 101010  10 000000  1 0000000"[bits=33, bytes=5]
    bswr.appendBits(0x01, 7);
    Q_ASSERT(bswr.bitsCount() == 33);
    Q_ASSERT(bswr.toByteArray() == QByteArray::fromHex("B2456A8080"));

    Q_ASSERT(bsrd.fromByteArray(QByteArray::fromHex("B2456A8080"), 33) == true);
    Q_ASSERT(bsrd.bitsCount() == 33);
    Q_ASSERT(bsrd.restBitsCount() == 33);
    out_bits = 0x00;
    Q_ASSERT(bsrd.readBits(out_bits, 0) == 0);
    Q_ASSERT(bsrd.restBitsCount() == 33);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //1011 0010      0100010 1  01 101010  10 000000  1 0000000
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bsrd.restBitsCount() == 25);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0100 0101     01 101010  10 000000  1 0000000
    Q_ASSERT(out_bits == 0x45);
    Q_ASSERT(bsrd.restBitsCount() == 17);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //0110 1010     10 000000  1 0000000
    Q_ASSERT(out_bits == 0x6A);
    Q_ASSERT(bsrd.restBitsCount() == 9);
    Q_ASSERT(bsrd.readBits(out_bits, 8) == 8);  //1000 0000     1 0000000
    Q_ASSERT(out_bits == 0x80);
    Q_ASSERT(bsrd.restBitsCount() == 1);
    Q_ASSERT(bsrd.readBits(out_bits, 1) == 1);  //1   0000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bsrd.restBitsCount() == 0);

    buf = QByteArray::fromHex("B2456A8080");
    bit_reader_init(&ctx, (uint8_t*)(buf.data()), 33);
    Q_ASSERT(bit_reader_bit_count(&ctx) == 33);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 33);
    out_bits = 0xAA;
    Q_ASSERT(bit_reader_read_bits(&ctx, 0, &out_bits) == 0);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 33);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //1011 0010      0100010 1  01 101010  10 000000  1 0000000
    Q_ASSERT(out_bits == 0xB2);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 25);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0100 0101     01 101010  10 000000  1 0000000
    Q_ASSERT(out_bits == 0x45);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 17);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //0110 1010     10 000000  1 0000000
    Q_ASSERT(out_bits == 0x6A);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 9);
    Q_ASSERT(bit_reader_read_bits(&ctx, 8, &out_bits) == 8);  //1000 0000     1 0000000
    Q_ASSERT(out_bits == 0x80);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 1);
    Q_ASSERT(bit_reader_read_bits(&ctx, 1, &out_bits) == 1);  //1   0000000
    Q_ASSERT(out_bits == 0x01);
    Q_ASSERT(bit_reader_rest_bit_count(&ctx) == 0);
}

void TestAlg::testCompressor()
{
    QList<LedFrame> list;
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.frameCount() == 0);
        Q_ASSERT(lfd.frameList() == list);
    }

    LedFrameCompressor lfc;
    Q_ASSERT(lfc.frameCount() == 0);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("00 00 00 00"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 0);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame0(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame0.data()) == 0);
    }

    lfc.append(QByteArray(32, '\x00')); //REPFRAME
    {
        LedFrame lf;
        lf.fromBinaryFrame(QByteArray(32, '\x00'));
        list.append(lf);
    }
    Q_ASSERT(lfc.frameCount() == 1);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("02 00 00 00  00"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 1);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame1(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame1.data()) != 0);
        Q_ASSERT(frame1 == list[0].toBinaryFrame());
        QByteArray frame2(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame2.data()) == 0);
    }

    lfc.append(QByteArray(16, '\x11') + QByteArray(16, '\x22')); //RLE
    {
        LedFrame lf;
        lf.fromBinaryFrame(QByteArray(16, '\x11') + QByteArray(16, '\x22'));
        list.append(lf);
    }
    Q_ASSERT(lfc.frameCount() == 2);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("1E 00 00 00  17 88 BC 88"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 2);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame1(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame1.data()) != 0);
        Q_ASSERT(frame1 == list[0].toBinaryFrame());
        QByteArray frame2(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame2.data()) != 0);
        Q_ASSERT(frame2 == list[1].toBinaryFrame());
        QByteArray frame3(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame3.data()) == 0);
    }

    lfc.append(QByteArray(16, '\x11') + QByteArray(15, '\x22') + QByteArray(1, '\xFF')); //INDEX
    {
        LedFrame lf;
        lf.fromBinaryFrame(QByteArray(16, '\x11') + QByteArray(15, '\x22') + QByteArray(1, '\xFF'));
        list.append(lf);
    }
    Q_ASSERT(lfc.frameCount() == 3);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("32 00 00 00  17 88 BC 8A 07 F7 40"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 3);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame1(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame1.data()) != 0);
        Q_ASSERT(frame1 == list[0].toBinaryFrame());
        QByteArray frame2(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame2.data()) != 0);
        Q_ASSERT(frame2 == list[1].toBinaryFrame());
        QByteArray frame3(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame3.data()) != 0);
        Q_ASSERT(frame3 == list[2].toBinaryFrame());
        QByteArray frame4(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame4.data()) == 0);
    }

    lfc.append(QByteArray::fromHex("00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f")); //PLAIN
    {
        LedFrame lf;
        lf.fromBinaryFrame(QByteArray::fromHex("00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f"));
        list.append(lf);
    }
    Q_ASSERT(lfc.frameCount() == 4);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("34 01 00 00  17 88 BC 8A 07 F7 7E FF 0F 1F 2F 3F 4F 5F 6F 7F 8F 9F AF BF CF DF EE EE FF 0F 1F 2F 3F 4F 5F 6F 7F 8F 9F AF BF C2 00"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 4);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame1(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame1.data()) != 0);
        Q_ASSERT(frame1 == list[0].toBinaryFrame());
        QByteArray frame2(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame2.data()) != 0);
        Q_ASSERT(frame2 == list[1].toBinaryFrame());
        QByteArray frame3(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame3.data()) != 0);
        Q_ASSERT(frame3 == list[2].toBinaryFrame());
        QByteArray frame4(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame4.data()) != 0);
        Q_ASSERT(frame4 == list[3].toBinaryFrame());
        QByteArray frame5(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame5.data()) == 0);
    }

    lfc.append(QByteArray::fromHex("00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f")); //REPFRAME
    {
        LedFrame lf;
        lf.fromBinaryFrame(QByteArray::fromHex("00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f"));
        list.append(lf);
    }
    Q_ASSERT(lfc.frameCount() == 5);
    Q_ASSERT(lfc.toCompressedBinary() == QByteArray::fromHex("36 01 00 00  17 88 BC 8A 07 F7 7E FF 0F 1F 2F 3F 4F 5F 6F 7F 8F 9F AF BF CF DF EE EE FF 0F 1F 2F 3F 4F 5F 6F 7F 8F 9F AF BF C2 00"));
    {
        LedFrameDecompressor lfd;
        Q_ASSERT(lfd.loadCompressedBinary(lfc.toCompressedBinary()) == true);
        Q_ASSERT(lfd.frameCount() == 5);
        Q_ASSERT(lfd.frameList() == list);

        FRAME_DECOMPRESSOR_CTX ctx;
        QByteArray data = lfc.toCompressedBinary();
        frame_decompressor_init(&ctx, (uint8_t*)data.data());  //min buf size = 4
        QByteArray frame1(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame1.data()) != 0);
        Q_ASSERT(frame1 == list[0].toBinaryFrame());
        QByteArray frame2(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame2.data()) != 0);
        Q_ASSERT(frame2 == list[1].toBinaryFrame());
        QByteArray frame3(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame3.data()) != 0);
        Q_ASSERT(frame3 == list[2].toBinaryFrame());
        QByteArray frame4(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame4.data()) != 0);
        Q_ASSERT(frame4 == list[3].toBinaryFrame());
        QByteArray frame5(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame5.data()) != 0);
        Q_ASSERT(frame5 == list[4].toBinaryFrame());
        QByteArray frame6(32, 0);
        Q_ASSERT(frame_decompressor_get_next_frame(&ctx, (uint8_t*)frame6.data()) == 0);
    }
}
