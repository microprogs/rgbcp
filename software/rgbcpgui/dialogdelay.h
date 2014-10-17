#ifndef DIALOGDELAY_H
#define DIALOGDELAY_H

#include <QDialog>
#include <QtGlobal>


namespace Ui
{
    class DialogDelay;
}

class DialogDelay : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelay(QWidget *parent = 0);
    virtual ~DialogDelay();

    quint16 getFrameDelay() const;
    void setFrameDelay(quint16 delayValue);

protected:
    quint16 getSpinBoxDelay();
    void setSpinBoxDelay(quint16 val);

private slots:
    void spinBoxDelayChanged(int val);

private:
    Ui::DialogDelay *ui;

    quint16 delay_;
};

#endif // DIALOGDELAY_H
