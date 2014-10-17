#include "bitstreamreader.h"
#include "common.h"


BitStreamReader::BitStreamReader()
    : nbitssize_(0), nusedbits_(0), remain_bits_in_byte_(0), pos_(-1)
{
}

BitStreamReader::~BitStreamReader()
{
}

quint8 BitStreamReader::readBits(quint8 &out_bits, quint8 nbits)
{
    out_bits = 0;

    quint8 cnt_bits = 0;

    if (nbits > 8)
        nbits = 8;

    if (nbits > 0 && nusedbits_ < nbitssize_)
    {
        quint32 rest_bits = nbitssize_ - nusedbits_;
        if (nbits > rest_bits)
            nbits = rest_bits;

        if (remain_bits_in_byte_ == 0)
        {
            if ((pos_+1) < byteStream_.size())
            {
                ++pos_;
                remain_bits_in_byte_ = 8;
            }
        }

        if (remain_bits_in_byte_ > 0)
        {
            quint8 bits = 0;
            if (nbits > remain_bits_in_byte_)
            {
                if (pos_ >= 0 && pos_ < byteStream_.size())
                {
                    bits = byteStream_[pos_];
                    bits <<= (8 - remain_bits_in_byte_);
                    bits >>= (8 - nbits);

                    if ((pos_+1) < byteStream_.size())
                    {
                        ++pos_;
                        remain_bits_in_byte_ += 8 - nbits;
                        bits |= (quint8)byteStream_[pos_] >> remain_bits_in_byte_;

                        cnt_bits += nbits;
                        nusedbits_ += nbits;
                        out_bits = bits;
                    }
                }
            }
            else
            {
                if (pos_ >= 0 && pos_ < byteStream_.size())
                {
                    bits = byteStream_[pos_];
                    bits <<= (8 - remain_bits_in_byte_);
                    bits >>= (8 - nbits);
                    remain_bits_in_byte_ -= nbits;

                    cnt_bits += nbits;
                    nusedbits_ += nbits;
                    out_bits = bits;
                }
            }
        }
    }

    return cnt_bits;
}

quint32 BitStreamReader::bitsCount() const
{
    return nbitssize_;
}

quint32 BitStreamReader::restBitsCount() const
{
    return nbitssize_ - nusedbits_;
}

bool BitStreamReader::fromByteArray(const QByteArray &ba, quint32 count_bits)
{
    nusedbits_ = 0;
    remain_bits_in_byte_ = 0;
    pos_ = -1;

    byteStream_.clear();
    nbitssize_ = 0;

    if (ba.size() > 0 && count_bits > 0)
    {
        int sz_bytes = count_bits / 8;
        if (count_bits % 8 != 0)
            ++sz_bytes;

        if (sz_bytes == ba.size())
        {
            byteStream_ = ba;
            nbitssize_ = count_bits;
            return true;
        }
    }

    return false;
}
