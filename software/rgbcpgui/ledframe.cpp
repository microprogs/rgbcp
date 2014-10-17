#include "ledframe.h"
#include "common.h"


LedFrame::LedFrame()
    : frame_delay_(0)
{
    frame_matrix_.clear();
    for (int i = 0; i < rowCount(); ++i)
        frame_matrix_.append(QVector<FullNColor>(colCount()));

    clear();
}

LedFrame::~LedFrame()
{
}

int LedFrame::rowCount() const
{
    return pointConverter_.matrixRowCount();
}

int LedFrame::colCount() const
{
    return pointConverter_.matrixColCount();
}

void LedFrame::clear()
{
    frame_delay_ = 0;
    for (int i = 0; i < rowCount(); ++i)
    {
        for (int j = 0; j < colCount(); ++j)
        {
            Q_ASSERT(frame_matrix_.size() == rowCount());
            Q_ASSERT(frame_matrix_[i].size() == colCount());
            frame_matrix_[i][j] = FullNColor();
        }
    }
}

void LedFrame::setLedColor(int row, int col, const FullNColor &ledColor)
{
    if (frame_matrix_.size() == rowCount() && row >= 0 && row < rowCount())
    {
        if (frame_matrix_[row].size() == colCount() && col >= 0 && col < colCount())
        {
            frame_matrix_[row][col] = ledColor;
        }
    }
}

FullNColor LedFrame::getLedColor(int row, int col) const
{
    FullNColor res;

    if (frame_matrix_.size() == rowCount() && row >= 0 && row < rowCount())
    {
        if (frame_matrix_[row].size() == colCount() && col >= 0 && col < colCount())
        {
            res = frame_matrix_[row][col];
        }
    }

    return res;
}

quint16 LedFrame::getDelay() const
{
    return frame_delay_;
}

void LedFrame::setDelay(quint16 delay)
{
    frame_delay_ = delay;
}

QByteArray LedFrame::toBinaryFrame() const
{
    QByteArray bin;

    for (int i = 0; i < rowCount(); ++i)
    {
        for (int j = 0; j < colCount(); ++j)
        {
            bin.append(LedColorToByte(frame_matrix_[i][j]));
        }
    }

    Q_ASSERT(bin.size() == 30);

    bin.append(Common::serializeUINT16(frame_delay_));

    Q_ASSERT(bin.size() == 32);
    Q_ASSERT(bin.size() == binFrameSize());

    return bin;
}

bool LedFrame::fromBinaryFrame(const QByteArray &bin)
{
    bool res = false;

    if (bin.size() == binFrameSize())
    {
        Q_ASSERT(bin.size() == 32);
        Q_ASSERT(rowCount() == 10);
        Q_ASSERT(colCount() == 3);

        QByteArray data = bin;

        for (int i = 0; i < rowCount(); ++i)
        {
            for (int j = 0; j < colCount(); ++j)
            {
                quint8 byteColor = 0;

                if (data.size() > 0)
                {
                    byteColor = data[0];
                    data.remove(0, 1);
                }

                frame_matrix_[i][j] = LedColorFromByte(byteColor);
            }
        }

        Q_ASSERT(data.size() == 2);

        frame_delay_ = 0;
        if (data.size() == 2)
            frame_delay_ = Common::unserializeUINT16(data);

        res = true;
    }

    return res;
}

int LedFrame::binFrameSize() const
{
    return 32;
}

bool LedFrame::operator==(const LedFrame &lf) const
{
    return (this->toBinaryFrame()) == (lf.toBinaryFrame());
}

QString LedFrame::toText() const
{
    return QString(toBinaryFrame().toHex());
}

bool LedFrame::fromText(const QString &text)
{
    return fromBinaryFrame(QByteArray::fromHex(text.toLatin1()));
}

quint8 LedFrame::LedColorToByte(const FullNColor &ledColor) const
{
    // 8 bit RGB(3,3,2): RRR GGG BB

    quint8 binColor = 0;

    quint8 nred = (quint8)(ledColor.subColorRed.ncolor & 0x7);
    quint8 ngreen = (quint8)(ledColor.subColorGreen.ncolor & 0x7);
    quint8 nblue = (quint8)(ledColor.subColorBlue.ncolor & 0x3);

    binColor |= nred << 5;  // 000 000 00 | RRR 000 00 = RRR 000 00
    binColor |= ngreen << 2; // RRR 000 00 | GGG 00 = RRR GGG 00
    binColor |= nblue;  // RRR GGG 00 | BB = RRR GGG BB

    return binColor;
}

FullNColor LedFrame::LedColorFromByte(quint8 byteColor) const
{
    // 8 bit RGB(3,3,2): RRR GGG BB

    quint8 nred = (quint8)((byteColor >> 5) & 0x7);
    quint8 ngreen = (quint8)((byteColor >> 2) & 0x7);
    quint8 nblue = (quint8)(byteColor & 0x3);

    return FullNColor(nred, ngreen, nblue);
}
