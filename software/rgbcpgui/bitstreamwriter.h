#ifndef BITSTREAMWRITER_H
#define BITSTREAMWRITER_H


#include <QByteArray>


class BitStreamWriter
{
public:
    explicit BitStreamWriter();
    virtual ~BitStreamWriter();

    void appendBits(quint8 bits, quint8 bits_count);
    quint32 bitsCount() const;
    QByteArray toByteArray() const;

private:
    QByteArray byteStream_;
    quint32 nbits_;
    quint8 remain_bits_;
};


#endif // BITSTREAMWRITER_H
