#include "dialogledcolor.h"
#include "ui_dialogledcolor.h"
#include "colorconverter.h"
#include <QPainter>


DialogLedColor::DialogLedColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLedColor),
    nColorRed_(0), nColorGreen_(0), nColorBlue_(0)
{
    ui->setupUi(this);

    initComboBox(ui->comboBoxRed, Qt::red, ColorConverter::bitsPerRed());
    initComboBox(ui->comboBoxGreen, Qt::green, ColorConverter::bitsPerGreen());
    initComboBox(ui->comboBoxBlue, Qt::blue, ColorConverter::bitsPerBlue());

    setFixedSize(sizeHint());

    setLedColor(0, 0, 0);
}

DialogLedColor::~DialogLedColor()
{
    delete ui;
}

void DialogLedColor::setLedColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue)
{
    setNColors(ncolorRed, ncolorGreen, ncolorBlue);
    setComboBoxColors(nColorRed_, nColorGreen_, nColorBlue_);
    drawFullLedColor(nColorRed_, nColorGreen_, nColorBlue_);
}

void DialogLedColor::getLedColor(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue) const
{
    getNColors(ncolorRed, ncolorGreen, ncolorBlue);
}

void DialogLedColor::comboBoxRedCurrentIndexChanged(int index)
{
    Q_UNUSED(index);
    updateByComboBoxEvent();
}

void DialogLedColor::comboBoxGreenCurrentIndexChanged(int index)
{
    Q_UNUSED(index);
    updateByComboBoxEvent();
}

void DialogLedColor::comboBoxBlueCurrentIndexChanged(int index)
{
    Q_UNUSED(index);
    updateByComboBoxEvent();
}

void DialogLedColor::setNColors(uint ncolorRed, uint ncolorGreen, uint ncolorBlue)
{
    nColorRed_ = ColorConverter::fixSubColorBitsRed(ncolorRed);
    nColorGreen_ = ColorConverter::fixSubColorBitsGreen(ncolorGreen);
    nColorBlue_ = ColorConverter::fixSubColorBitsBlue(ncolorBlue);
}

void DialogLedColor::getNColors(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue) const
{
    ncolorRed = ColorConverter::fixSubColorBitsRed(nColorRed_);
    ncolorGreen = ColorConverter::fixSubColorBitsGreen(nColorGreen_);
    ncolorBlue = ColorConverter::fixSubColorBitsBlue(nColorBlue_);
}

void DialogLedColor::setComboBoxColors(uint ncolorRed, uint ncolorGreen, uint ncolorBlue)
{
    int redIndex = ui->comboBoxRed->findData(QVariant((uint)ncolorRed));
    int greenIndex = ui->comboBoxGreen->findData(QVariant((uint)ncolorGreen));
    int blueIndex = ui->comboBoxBlue->findData(QVariant((uint)ncolorBlue));

    if (redIndex < 0)
        redIndex = 0;

    if (greenIndex < 0)
        greenIndex = 0;

    if (blueIndex < 0)
        blueIndex = 0;

    ui->comboBoxRed->setCurrentIndex(redIndex);
    ui->comboBoxGreen->setCurrentIndex(greenIndex);
    ui->comboBoxBlue->setCurrentIndex(blueIndex);
}

void DialogLedColor::getComboBoxColors(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue)
{
    ncolorRed = 0;
    ncolorGreen = 0;
    ncolorBlue = 0;

    bool bRed = false, bGreen = false, bBlue = false;

    uint cred = ui->comboBoxRed->currentData().toUInt(&bRed);
    uint cgreen = ui->comboBoxGreen->currentData().toUInt(&bGreen);
    uint cblue = ui->comboBoxBlue->currentData().toUInt(&bBlue);

    if (bRed && bGreen && bBlue)
    {
        ncolorRed = cred;
        ncolorGreen = cgreen;
        ncolorBlue = cblue;
    }
}

void DialogLedColor::initComboBox(QComboBox *comboBox, Qt::GlobalColor targetColor, uint nbits)
{
    const uint maxNColor = ColorConverter::maxNColor(nbits);
    const QSize iconSize = comboBox->iconSize();

    for (uint subcolor = 0; subcolor <= maxNColor; ++subcolor)
    {
        QColor realSubColor = ColorConverter::convertSubColorToRealColor(subcolor, nbits, targetColor);
        comboBox->addItem(QIcon(makePixmap(iconSize, realSubColor)), QString::number(subcolor), (uint)subcolor);
    }
    comboBox->setCurrentIndex(0);
}

QPixmap DialogLedColor::makePixmap(const QSize &size, const QColor &color)
{
    QPixmap pixmap(size);
    pixmap.fill();

    QPainter painter(&pixmap);
    painter.setPen(QPen(QColor(Qt::black)));
    painter.setBrush(QBrush(color));
    painter.drawRect(QRect(0, 0, size.width() - 1, size.height() - 1));
    painter.end();

    return pixmap;
}

void DialogLedColor::drawFullLedColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue)
{
    ncolorRed = ColorConverter::fixSubColorBitsRed(ncolorRed);
    ncolorGreen = ColorConverter::fixSubColorBitsGreen(ncolorGreen);
    ncolorBlue = ColorConverter::fixSubColorBitsBlue(ncolorBlue);

    const QColor fullColor = ColorConverter::convertFullColorToRealColor(ncolorRed, ncolorGreen, ncolorBlue);
    QPixmap pixmap = makePixmap(ui->labelFullLedColor->size(), fullColor);
    ui->labelFullLedColor->setPixmap(pixmap);
}

void DialogLedColor::updateByComboBoxEvent()
{
    uint cred = 0, cgreen = 0, cblue = 0;
    getComboBoxColors(cred, cgreen, cblue);
    setNColors(cred, cgreen, cblue);
    drawFullLedColor(cred, cgreen, cblue);
}
