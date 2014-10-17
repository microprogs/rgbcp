#include "modelmovie.h"
#include <QFile>
#include "ledframedecompressor.h"
#include "ledframecompressor.h"


ModelMovie::ModelMovie(QObject *parent) :
    QObject(parent)
{
}

ModelMovie::~ModelMovie()
{
}

bool ModelMovie::LoadFromFile(const QString &fileName)
{
    bool res = false;

    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly))
    {
        const QByteArray packedBinary = file.readAll();
        file.close();

        LedFrameDecompressor decomp;
        if (decomp.loadCompressedBinary(packedBinary))
        {
            ledFrameList_.clear();
            ledFrameList_.append(decomp.frameList());
            res = true;
        }
    }

    return res;
}

bool ModelMovie::SaveToFile(const QString &fileName) const
{
    bool res = false;

    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly))
    {
        LedFrameCompressor comp;
        comp.append(ledFrameList_);
        const QByteArray packedBinary = comp.toCompressedBinary();
        if (file.write(packedBinary) == packedBinary.size())
        {
            res = true;
        }
        file.close();
    }

    return res;
}

void ModelMovie::clearAll()
{
    ledFrameList_.clear();
}

int ModelMovie::frameCount() const
{
    return ledFrameList_.size();
}

void ModelMovie::insertFrameBefore(int index)
{
    if (index >= 0 && index < ledFrameList_.size())
        ledFrameList_.insert(index, LedFrame());
    else
        ledFrameList_.prepend(LedFrame());
}

void ModelMovie::insertFrameAfter(int index)
{
    if (index < 0)
        index = 0;

    index++;
    if (index >= 0 && index < ledFrameList_.size())
        ledFrameList_.insert(index, LedFrame());
    else
        ledFrameList_.append(LedFrame());
}

void ModelMovie::deleteFrame(int index)
{
    if (index >= 0 && index < ledFrameList_.size())
    {
        ledFrameList_.removeAt(index);
    }
}

void ModelMovie::setFrame(int index, const LedFrame &ledFrame)
{
    if (index >= 0 && index < ledFrameList_.size())
    {
        ledFrameList_[index] = ledFrame;
    }
}

LedFrame ModelMovie::getFrame(int index) const
{
    LedFrame res;
    if (index >= 0 && index < ledFrameList_.size())
    {
        res = ledFrameList_[index];
    }
    return res;
}

void ModelMovie::clearFrame(int index)
{
    if (index >= 0 && index < ledFrameList_.size())
    {
        setFrame(index, LedFrame());
    }
}
