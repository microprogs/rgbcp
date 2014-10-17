#include "bitstreamwriter.h"
#include "common.h"


BitStreamWriter::BitStreamWriter()
    : nbits_(0), remain_bits_(0)
{
}

BitStreamWriter::~BitStreamWriter()
{
}

void BitStreamWriter::appendBits(quint8 bits, quint8 bits_count)
{
    if (bits_count > 8)
        bits_count = 8;

    if (bits_count > 0)
    {
        bits &= (quint8)(0xFF) >> (8 - bits_count);

        if (remain_bits_ == 0)
        {
            byteStream_.append((char)0);
            remain_bits_ = 8;
        }

        if (remain_bits_ > 0)
        {
            if (bits_count > remain_bits_)
            {
                quint8 over = bits_count - remain_bits_;
                byteStream_[byteStream_.size()-1] = (quint8)(byteStream_[byteStream_.size()-1]) | (quint8)((quint8)bits >> (quint8)over);

                byteStream_.append((char)0);
                remain_bits_ = 8 - over;
                byteStream_[byteStream_.size()-1] = (quint8)((quint8)bits << (quint8)remain_bits_);
            }
            else  // bits_count <= remain_bits_
            {
                remain_bits_ -= bits_count;
                byteStream_[byteStream_.size()-1] = (quint8)(byteStream_[byteStream_.size()-1]) | (quint8)((quint8)bits << (quint8)remain_bits_);
            }

            nbits_ += bits_count;
        }
    }
}

quint32 BitStreamWriter::bitsCount() const
{
    return nbits_;
}

QByteArray BitStreamWriter::toByteArray() const
{
    return byteStream_;
}
