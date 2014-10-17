#ifndef COMMON_H
#define COMMON_H


#include <QByteArray>


class Common
{
public:
    Common();

    static QByteArray serializeUINT16(quint16 num);
    static quint16 unserializeUINT16(const QByteArray &bin);
};


#endif // COMMON_H
