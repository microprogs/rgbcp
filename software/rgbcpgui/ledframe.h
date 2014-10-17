#ifndef LEDFRAME_H
#define LEDFRAME_H


#include <QVector>
#include <QPoint>
#include <QPair>
#include "colorconverter.h"
#include "pointconverter.h"


class LedFrame
{
public:
    explicit LedFrame();
    virtual ~LedFrame();

    int rowCount() const;
    int colCount() const;

    void clear();

    void setLedColor(int row, int col, const FullNColor &ledColor);
    FullNColor getLedColor(int row, int col) const;

    quint16 getDelay() const;
    void setDelay(quint16 delay);

    QByteArray toBinaryFrame() const;
    bool fromBinaryFrame(const QByteArray &bin);
    int binFrameSize() const;

    bool operator==(const LedFrame &lf) const;

    QString toText() const;
    bool fromText(const QString &text);


protected:
    quint8 LedColorToByte(const FullNColor &ledColor) const;
    FullNColor LedColorFromByte(quint8 byteColor) const;

private:
    quint16 frame_delay_;
    QVector<QVector<FullNColor> > frame_matrix_;
    PointConverter pointConverter_;
};


#endif // LEDFRAME_H
