#include "ledframecompressor.h"

LedFrameCompressor::LedFrameCompressor()
{
}

LedFrameCompressor::~LedFrameCompressor()
{
}

void LedFrameCompressor::append(const LedFrame &frame)
{
    ledFrameList_.append(frame);
}

void LedFrameCompressor::append(const QList<LedFrame> &frame_list)
{
    ledFrameList_.append(frame_list);
}

void LedFrameCompressor::append(const QByteArray &binaryFrame)
{
    LedFrame lf;
    if (lf.fromBinaryFrame(binaryFrame))
        ledFrameList_.append(lf);
    else
        ledFrameList_.append(LedFrame());
}

int LedFrameCompressor::frameCount() const
{
    return ledFrameList_.size();
}

int LedFrameCompressor::frameSizeBytes() const
{
    return 32;
}

QByteArray LedFrameCompressor::getDiff(const QByteArray &last, const QByteArray &cur) const
{
    QByteArray res(frameSizeBytes(), '\x00');

    if (last.size() == frameSizeBytes() && cur.size() == frameSizeBytes())
    {
        Q_ASSERT(last.size() == cur.size());
        for (int i = 0; i < last.size(); ++i)
        {
            res[i] = (quint8)((quint8)cur[i] - (quint8)last[i]);
        }
    }

    return res;
}

bool LedFrameCompressor::compressRepFrame(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const
{
    //(REPFRAME_COMPRESS[2]) = (bits"00"{magic: repeat last frame})

    bool res = false;

    if (plainFrame.size() == frameSizeBytes())
    {
        if (countNonZeros(plainFrame) == 0)
        {
            bit_writer.appendBits(0x00, 2);
            res = true;
        }
    }

    return res;
}

bool LedFrameCompressor::compressRle(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const
{
    //(RLE_COMPRESS[2+(5+8)*(1..32)]) = (bits"01"{magic: RLE}) (RLE_BLOCK[5+8])*(1..32)
    //(RLE_BLOCK[5+8]) = (bits"00000..11111"[5]{byte count (1..32) from (0..31)}) (byte"00..FF"[8]{repeatable byte})

    bool res = false;

    if (plainFrame.size() == frameSizeBytes())
    {
        if (countNonZeros(plainFrame) > 0 && plainFrame.size() > 0)
        {
            res = true;

            bit_writer.appendBits(0x01, 2);

            quint8 cur_cnt = 0;
            quint8 cur_byte = plainFrame[0];
            for (int i = 0; i < plainFrame.size(); ++i)
            {
                if (plainFrame[i] == cur_byte)
                {
                    ++cur_cnt;
                }
                else
                {
                    bit_writer.appendBits(cur_cnt-1, 5);
                    bit_writer.appendBits(cur_byte, 8);

                    cur_byte = plainFrame[i];
                    cur_cnt = 1;
                }
            }

            if (cur_cnt > 0)
            {
                bit_writer.appendBits(cur_cnt-1, 5);
                bit_writer.appendBits(cur_byte, 8);
            }
        }
    }

    return res;
}

bool LedFrameCompressor::compressIndex(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const
{
    //(INDEX_COMPRESS[2+5+(5+8)*(1..32)]) = (bits"10"{magic: INDEX}) (bits"00000..11111"[5]{index count (1..32) from (0..31)}) (INDEX_BLOCK[5+8])*(1..32)
    //(INDEX_BLOCK[5+8]) = (bits"00000..11111"[5]{index in frame = 0..31}) (byte"00..FF"[8]{byte for index})

    bool res = false;

    if (plainFrame.size() == frameSizeBytes())
    {
        quint8 index_cnt = countNonZeros(plainFrame);

        if (index_cnt > 0)
        {
            --index_cnt;
            res = true;

            bit_writer.appendBits(0x2, 2);
            bit_writer.appendBits(index_cnt, 5);

            for (int i = 0; i < plainFrame.size(); ++i)
            {
                if (plainFrame[i] != '\x00')
                {
                    const quint8 index = i;
                    const quint8 index_val = plainFrame[i];

                    bit_writer.appendBits(index, 5);
                    bit_writer.appendBits(index_val, 8);
                }
            }
        }
    }

    return res;
}

bool LedFrameCompressor::compressPlain(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const
{
    //(PLAIN_COMPRESS[2+32*8]) = (bits"11"{magic: PLAIN}) (byte"00..FF"[8]{plain byte})*32
    bool res = false;

    if (plainFrame.size() == frameSizeBytes())
    {
        bit_writer.appendBits(0x3, 2);
        for (int i = 0; i < plainFrame.size(); ++i)
            bit_writer.appendBits(plainFrame[i], 8);
        res = true;
    }

    return res;
}

bool LedFrameCompressor::bestCompress(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const
{
    bool res = false;

    BitStreamWriter bsw_rep;

    if (compressRepFrame(plainFrame, bsw_rep))
    {
        compressRepFrame(plainFrame, bit_writer);
        res = true;
    }
    else
    {
        BitStreamWriter bsw_plain;
        if (compressPlain(plainFrame, bsw_plain))
        {
            const int size_plain = bsw_plain.bitsCount();
            int size_rle = size_plain;
            int size_index = size_plain;

            BitStreamWriter bsw_rle;
            bool is_rle = false;
            if (compressRle(plainFrame, bsw_rle))
            {
                size_rle = bsw_rle.bitsCount();
                is_rle = true;
            }

            BitStreamWriter bsw_index;
            bool is_index = false;
            if (compressIndex(plainFrame, bsw_index))
            {
                size_index = bsw_index.bitsCount();
                is_index = true;
            }

            if (is_rle && size_rle < size_plain && size_rle < size_index)
            {
                compressRle(plainFrame, bit_writer);
                res = true;
            }
            else if (is_index && size_index < size_plain && size_index < size_rle)
            {
                compressIndex(plainFrame, bit_writer);
                res = true;
            }
            else
            {
                compressPlain(plainFrame, bit_writer);
                res = true;
            }

        }
    }

    return res;
}

int LedFrameCompressor::countNonZeros(const QByteArray &plainFrame) const
{
    int res = 0;

    for (int i = 0; i < plainFrame.size(); ++i)
    {
        if (plainFrame[i] != '\x00')
            ++res;
    }

    return res;
}

QByteArray LedFrameCompressor::toCompressedBinary() const
{
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

    BitStreamWriter bsw;

    const QByteArray nullFrame(frameSizeBytes(), '\x00');
    QByteArray lastFrame = nullFrame;
    foreach (const LedFrame &lf, ledFrameList_)
    {
        const QByteArray curFrame = lf.toBinaryFrame();
        if (curFrame.size() == frameSizeBytes())
        {
            const QByteArray curDiff = getDiff(lastFrame, curFrame);
            if (bestCompress(curDiff, bsw))
            {
                lastFrame = curFrame;
            }
        }
    }

    const quint32 total_bit_count = bsw.bitsCount();
    QByteArray res;

    res.append(((quint8*)&total_bit_count)[0]);
    res.append(((quint8*)&total_bit_count)[1]);
    res.append(((quint8*)&total_bit_count)[2]);
    res.append(((quint8*)&total_bit_count)[3]);

    res.append(bsw.toByteArray());

    return res;
}
