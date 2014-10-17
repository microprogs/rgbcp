#ifndef LEDFRAMEDECOMPRESSOR_H
#define LEDFRAMEDECOMPRESSOR_H


#include <QByteArray>
#include "bitstreamreader.h"
#include <QList>
#include "ledframe.h"


class LedFrameDecompressor
{
public:
    explicit LedFrameDecompressor();
    virtual ~LedFrameDecompressor();

    bool loadCompressedBinary(const QByteArray &binary);

    int frameCount() const;
    QList<LedFrame> frameList() const;

protected:
    bool getNextFrame(BitStreamReader &bsr, const QByteArray &lastFrame, QByteArray &curFrame) const;
    int frameSizeBytes() const;
    QByteArray restoreDiff(const QByteArray &lastFrame, const QByteArray &diffFrame) const;
    bool extractDiffFrame(BitStreamReader &bsr, QByteArray &diffFrame) const;

    bool decompressRepFrame(BitStreamReader &bsr, QByteArray &diffFrame) const;
    bool decompressRLE(BitStreamReader &bsr, QByteArray &diffFrame) const;
    bool decompressIndex(BitStreamReader &bsr, QByteArray &diffFrame) const;
    bool decompressPlain(BitStreamReader &bsr, QByteArray &diffFrame) const;

private:
    QList<LedFrame> ledFrameList_;
};


#endif // LEDFRAMEDECOMPRESSOR_H
