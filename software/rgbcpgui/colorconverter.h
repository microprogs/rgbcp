#ifndef COLORCONVERTER_H
#define COLORCONVERTER_H

#include <QColor>

class ColorConverter;

struct SubPixelNColor
{
    uint ncolor;
    uint nbits;
    SubPixelNColor()
     : ncolor(0), nbits(0) {}
    SubPixelNColor(uint in_ncolor, uint in_nbits)
     : ncolor(in_ncolor), nbits(in_nbits) {}
};

struct FullNColor
{
    SubPixelNColor subColorRed;
    SubPixelNColor subColorGreen;
    SubPixelNColor subColorBlue;

    FullNColor();
    FullNColor(uint nred, uint ngreen, uint nblue);
};


class ColorConverter
{
public:
    static uint bitsPerRed();
    static uint bitsPerGreen();
    static uint bitsPerBlue();

    static uint maxNColor(uint nbits);

    static uint fixSubColorBits(uint subcolor, uint nbits);

    static uint fixSubColorBitsRed(uint subcolor);
    static uint fixSubColorBitsGreen(uint subcolor);
    static uint fixSubColorBitsBlue(uint subcolor);

    static QColor convertSubColorToRealColor(uint subcolor, uint nbits, Qt::GlobalColor targetColor);

    static QColor convertFullColorToRealColor(SubPixelNColor colorRed, SubPixelNColor colorGreen, SubPixelNColor colorBlue);
    static QColor convertFullColorToRealColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue);

protected:
    explicit ColorConverter();
    virtual ~ColorConverter();

    static int getColorIntensity(SubPixelNColor color);
};

#endif // COLORCONVERTER_H
