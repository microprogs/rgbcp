#include "dialogdelay.h"
#include "ui_dialogdelay.h"

DialogDelay::DialogDelay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelay),
    delay_(0)
{
    ui->setupUi(this);

    setFixedSize(sizeHint());

    ui->spinBoxDelay->setRange(0, 0xFFFF);
    ui->spinBoxDelay->setValue(0);

    setFrameDelay(0);
}

DialogDelay::~DialogDelay()
{
    delete ui;
}

quint16 DialogDelay::getFrameDelay() const
{
    return delay_;
}

void DialogDelay::setFrameDelay(quint16 delayValue)
{
    delay_ = delayValue;
    setSpinBoxDelay(delayValue);
}

quint16 DialogDelay::getSpinBoxDelay()
{
    int val = ui->spinBoxDelay->value();
    if (val < 0)
        val = 0;
    if (val > 0xFFFF)
        val = 0xFFFF;
    return (quint16)((uint)val);
}

void DialogDelay::setSpinBoxDelay(quint16 val)
{
    ui->spinBoxDelay->setValue((uint)val);
}

void DialogDelay::spinBoxDelayChanged(int val)
{
    Q_UNUSED(val);
    delay_ = getSpinBoxDelay();
}
