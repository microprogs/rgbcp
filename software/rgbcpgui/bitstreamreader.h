#ifndef BITSTREAMREADER_H
#define BITSTREAMREADER_H


#include <QByteArray>


class BitStreamReader
{
public:
    explicit BitStreamReader();
    virtual ~BitStreamReader();

    quint8 readBits(quint8 &out_bits, quint8 nbits);
    quint32 bitsCount() const;
    quint32 restBitsCount() const;

    bool fromByteArray(const QByteArray &ba, quint32 count_bits);

private:
    QByteArray byteStream_;
    quint32 nbitssize_;
    quint32 nusedbits_;
    quint8 remain_bits_in_byte_;
    int pos_;
};


#endif // BITSTREAMREADER_H
