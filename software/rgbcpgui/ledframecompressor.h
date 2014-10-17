#ifndef LEDFRAMECOMPRESSOR_H
#define LEDFRAMECOMPRESSOR_H

#include "ledframe.h"
#include "bitstreamwriter.h"
#include <QList>
#include <QByteArray>


class LedFrameCompressor
{
public:
    explicit LedFrameCompressor();
    virtual ~LedFrameCompressor();

    void append(const LedFrame &frame);
    void append(const QList<LedFrame> &frame_list);
    void append(const QByteArray &binaryFrame);

    int frameCount() const;

    QByteArray toCompressedBinary() const;

protected:
    int frameSizeBytes() const;
    QByteArray getDiff(const QByteArray &last, const QByteArray &cur) const;

    bool compressRepFrame(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const;
    bool compressRle(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const;
    bool compressIndex(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const;
    bool compressPlain(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const;

    bool bestCompress(const QByteArray &plainFrame, BitStreamWriter &bit_writer) const;

    int countNonZeros(const QByteArray &plainFrame) const;

private:
    QList<LedFrame> ledFrameList_;
};


#endif // LEDFRAMECOMPRESSOR_H
