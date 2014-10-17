#ifndef DIALOGLEDCOLOR_H
#define DIALOGLEDCOLOR_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QColor>


namespace Ui
{
class DialogLedColor;
}


class DialogLedColor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLedColor(QWidget *parent = 0);
    virtual ~DialogLedColor();

    void setLedColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue);
    void getLedColor(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue) const;


private slots:
    void comboBoxRedCurrentIndexChanged(int index);
    void comboBoxGreenCurrentIndexChanged(int index);
    void comboBoxBlueCurrentIndexChanged(int index);

private:
    Ui::DialogLedColor *ui;

    uint nColorRed_;
    uint nColorGreen_;
    uint nColorBlue_;

    void setNColors(uint ncolorRed, uint ncolorGreen, uint ncolorBlue);
    void getNColors(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue) const;

    void setComboBoxColors(uint ncolorRed, uint ncolorGreen, uint ncolorBlue);
    void getComboBoxColors(uint &ncolorRed, uint &ncolorGreen, uint &ncolorBlue);

    void initComboBox(QComboBox *comboBox, Qt::GlobalColor targetColor, uint nbits);
    QPixmap makePixmap(const QSize &size, const QColor &color);
    void drawFullLedColor(uint ncolorRed, uint ncolorGreen, uint ncolorBlue);
    void updateByComboBoxEvent();
};


#endif // DIALOGLEDCOLOR_H
