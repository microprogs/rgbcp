#include "colorconverter.h"

ColorConverter::ColorConverter()
{
}

ColorConverter::~ColorConverter()
{
}

uint ColorConverter::fixSubColorBits(uint subcolor, uint nbits)
{
    const uint maxColor = (1 << nbits) - 1;
    uint res = subcolor;
    if (res > maxColor)
        res = maxColor;
    return res;
}

uint ColorConverter::fixSubColorBitsRed(uint subcolor)
{
    return fixSubColorBits(subcolor, bitsPerRed());
}

uint ColorConverter::fixSubColorBitsGreen(uint subcolor)
{
    return fixSubColorBits(subcolor, bitsPerGreen());
}

uint ColorConverter::fixSubColorBitsBlue(uint subcolor)
{
    return fixSubColorBits(subcolor, bitsPerBlue());
}

QColor ColorConverter::convertSubColorToRealColor(uint subcolor, uint nbits, Qt::GlobalColor targetColor)
{
    subcolor = fixSubColorBits(subcolor, nbits);
    const uint maxColor = (1 << nbits) - 1;

    int targetI = ((int)255 / (int)maxColor) * (int)(maxColor - subcolor);

    QColor res = QColor(0, 0, 0);
    switch (targetColor)
    {
    case Qt::red:
        res = QColor(255, targetI, targetI);
        break;

    case Qt::green:
        res = QColor(targetI, 255, targetI);
        break;

    case Qt::blue:
        res = QColor(targetI, targetI, 255);
        break;

    default:
        break;
    }

    return res;
}

QColor ColorConverter::convertFullColorToRealColor(SubPixelNColor colorRed, SubPixelNColor colorGreen, SubPixelNColor colorBlue)
{
    const int targetIRed = getColorIntensity(colorRed);
    const int targetIGreen = getColorIntensity(colorGreen);
    const int targetIBlue = getColorIntensity(colorBlue);

    return QColor(targetIRed, targetIGreen, targetIBlue);
}

QColor ColorConverter::convertFullColorToRealColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue)
{
    return ColorConverter::convertFullColorToRealColor(SubPixelNColor(ncolorRed, bitsPerRed()),
                                                       SubPixelNColor(ncolorGreen, bitsPerGreen()),
                                                       SubPixelNColor(ncolorBlue, bitsPerBlue()));
}

int ColorConverter::getColorIntensity(SubPixelNColor color)
{
    const uint subcolor = fixSubColorBits(color.ncolor, color.nbits);
    const uint maxColor = maxNColor(color.nbits);
    const int targetI = ((int)255 / (int)maxColor) * (int)(subcolor);
    return targetI;
}

uint ColorConverter::bitsPerRed()
{
    return 3;
}

uint ColorConverter::bitsPerGreen()
{
    return 3;
}

uint ColorConverter::bitsPerBlue()
{
    return 2;
}

uint ColorConverter::maxNColor(uint nbits)
{
    return (uint)((1u << nbits) - 1u);
}


FullNColor::FullNColor()
    : subColorRed(0, ColorConverter::bitsPerRed()),
      subColorGreen(0, ColorConverter::bitsPerGreen()),
      subColorBlue(0, ColorConverter::bitsPerBlue())
{
}

FullNColor::FullNColor(uint nred, uint ngreen, uint nblue)
    : subColorRed(nred, ColorConverter::bitsPerRed()),
      subColorGreen(ngreen, ColorConverter::bitsPerGreen()),
      subColorBlue(nblue, ColorConverter::bitsPerBlue())
{
}
