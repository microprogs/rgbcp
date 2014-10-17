#include "common.h"

Common::Common()
{
}

QByteArray Common::serializeUINT16(quint16 num)
{
    QByteArray bin;
    bin.append(((quint8*)&num)[0]);
    bin.append(((quint8*)&num)[1]);
    return bin;
}

quint16 Common::unserializeUINT16(const QByteArray &bin)
{
    quint16 res = 0;

    if (bin.size() == 2)
    {
        res |= (quint16)((quint8)bin[0]);
        res |= (quint16)(((quint8)bin[1]) << 8);
    }

    return res;
}
