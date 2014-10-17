#include "ledframedecompressor.h"


LedFrameDecompressor::LedFrameDecompressor()
{
}

LedFrameDecompressor::~LedFrameDecompressor()
{
}

bool LedFrameDecompressor::loadCompressedBinary(const QByteArray &binary)
{
    ledFrameList_.clear();

    bool res = false;

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

    if (binary.size() >= 4)
    {
        quint32 total_bit_count = 0;
        ((quint8*)&total_bit_count)[0] = binary[0];
        ((quint8*)&total_bit_count)[1] = binary[1];
        ((quint8*)&total_bit_count)[2] = binary[2];
        ((quint8*)&total_bit_count)[3] = binary[3];

        if (total_bit_count == 0)
        {
            res = true;
        }
        else
        {
            const QByteArray bin_stream = binary.mid(4);

            BitStreamReader bsr;

            if (bsr.fromByteArray(bin_stream, total_bit_count))
            {
                const QByteArray nullFrame(frameSizeBytes(), '\x00');
                QByteArray lastFrame = nullFrame;
                QByteArray curFrame = nullFrame;

                while (getNextFrame(bsr, lastFrame, curFrame))
                {
                    LedFrame lf;
                    if (lf.fromBinaryFrame(curFrame))
                    {
                        ledFrameList_.append(lf);
                        lastFrame = curFrame;
                    }
                }

                res = true;
            }
        }
    }

    return res;
}

int LedFrameDecompressor::frameCount() const
{
    return ledFrameList_.size();
}

QList<LedFrame> LedFrameDecompressor::frameList() const
{
    return ledFrameList_;
}

bool LedFrameDecompressor::getNextFrame(BitStreamReader &bsr, const QByteArray &lastFrame, QByteArray &curFrame) const
{
    curFrame.clear();
    bool res = false;

    QByteArray diffFrame;
    if (extractDiffFrame(bsr, diffFrame))
    {
        curFrame = restoreDiff(lastFrame, diffFrame);
        res = true;
    }

    return res;
}

int LedFrameDecompressor::frameSizeBytes() const
{
    return 32;
}

QByteArray LedFrameDecompressor::restoreDiff(const QByteArray &lastFrame, const QByteArray &diffFrame) const
{
    QByteArray res(frameSizeBytes(), '\x00');

    if (lastFrame.size() == frameSizeBytes() && diffFrame.size() == frameSizeBytes())
    {
        Q_ASSERT(lastFrame.size() == diffFrame.size());
        for (int i = 0; i < lastFrame.size(); ++i)
        {
            res[i] = (quint8)((quint8)diffFrame[i] + (quint8)lastFrame[i]);
        }
    }

    return res;
}

bool LedFrameDecompressor::extractDiffFrame(BitStreamReader &bsr, QByteArray &diffFrame) const
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

    diffFrame.clear();

    bool res = false;

    if (bsr.restBitsCount() >= 2)
    {
        quint8 compress_type = 0;
        if (bsr.readBits(compress_type, 2) == 2)
        {
            QByteArray df;
            bool is_ok = false;

            switch (compress_type)
            {
            case 0x00:  //bin"00"
                is_ok = decompressRepFrame(bsr, df);
                break;

            case 0x01:  //bin"01"
                is_ok = decompressRLE(bsr, df);
                break;

            case 0x02:  //bin"10"
                is_ok = decompressIndex(bsr, df);
                break;

            case 0x03:  //bin"11"
                is_ok = decompressPlain(bsr, df);
                break;

            default:
                break;
            }

            if (is_ok)
            {
                diffFrame = df;
                res = true;
            }
        }
    }

    return res;
}

bool LedFrameDecompressor::decompressRepFrame(BitStreamReader &bsr, QByteArray &diffFrame) const
{
    //(REPFRAME_COMPRESS[2]) = (bits"00"{magic: repeat last frame})
    Q_UNUSED(bsr);
    diffFrame = QByteArray(frameSizeBytes(), '\x00');
    return true;
}

bool LedFrameDecompressor::decompressRLE(BitStreamReader &bsr, QByteArray &diffFrame) const
{
    //(RLE_COMPRESS[2+(5+8)*(1..32)]) = (bits"01"{magic: RLE}) (RLE_BLOCK[5+8])*(1..32)
    //(RLE_BLOCK[5+8]) = (bits"00000..11111"[5]{byte count (1..32) from (0..31)}) (byte"00..FF"[8]{repeatable byte})
    diffFrame.clear();

    bool res = false;

    if (bsr.restBitsCount() >= (5+8))
    {
        QByteArray df;

        for (int i = 0; i < frameSizeBytes() && df.size() < frameSizeBytes(); ++i)
        {
            if (bsr.restBitsCount() >= (5+8))
            {
                quint8 byte_count = 0;
                if (bsr.readBits(byte_count, 5) == 5)  //0..31
                {
                    ++byte_count;  //1..32
                    quint8 byte_pattern = 0;
                    if (bsr.readBits(byte_pattern, 8) == 8)
                    {
                        df.append(QByteArray((uint)byte_count, byte_pattern));
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

        if (df.size() == frameSizeBytes())
        {
            diffFrame = df;
            res = true;
        }
    }

    return res;
}

bool LedFrameDecompressor::decompressIndex(BitStreamReader &bsr, QByteArray &diffFrame) const
{
    //(INDEX_COMPRESS[2+5+(5+8)*(1..32)]) = (bits"10"{magic: INDEX}) (bits"00000..11111"[5]{index count (1..32) from (0..31)}) (INDEX_BLOCK[5+8])*(1..32)
    //(INDEX_BLOCK[5+8]) = (bits"00000..11111"[5]{index in frame = 0..31}) (byte"00..FF"[8]{byte for index})
    diffFrame.clear();

    bool res = false;

    if (bsr.restBitsCount() >= (5+(5+8)))
    {
        quint8 icnt = 0;
        if (bsr.readBits(icnt, 5) == 5)
        {
            const quint32 index_count = (quint32)icnt + 1;

            QByteArray df = QByteArray(frameSizeBytes(), '\x00');
            bool is_ok = true;
            for (quint32 i = 0; i < index_count && is_ok; ++i)
            {
                quint8 index_pos = 0;
                quint8 index_val = 0;

                if (bsr.readBits(index_pos, 5) == 5)
                {
                    if (bsr.readBits(index_val, 8) == 8)
                    {
                        if (index_pos < df.size())
                        {
                            df[index_pos] = index_val;
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
                diffFrame = df;
                res = true;
            }
        }
    }

    return res;
}

bool LedFrameDecompressor::decompressPlain(BitStreamReader &bsr, QByteArray &diffFrame) const
{
    //(PLAIN_COMPRESS[2+32*8]) = (bits"11"{magic: PLAIN}) (byte"00..FF"[8]{plain byte})*32
    diffFrame.clear();
    bool res = false;

    if ((uint)bsr.restBitsCount() >= (uint)(frameSizeBytes()*8))
    {
        QByteArray frame;
        for (int i = 0; i < frameSizeBytes(); ++i)
        {
            quint8 b = 0;
            if (bsr.readBits(b, 8) == 8)
            {
                frame.append(b);
            }
        }

        if (frame.size() == frameSizeBytes())
        {
            diffFrame = frame;
            res = true;
        }
    }

    return res;
}
