#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
#include "wndmain.h"
#include "ui_wndmain.h"
#include <QMessageBox>

wndMain::wndMain(FmUsbTerminal &fmterm) :
    QMainWindow(0),
    ui(new Ui::wndMain),
    fmTerm(fmterm)
{
    ui->setupUi(this);
    isCancel = false;
    setUIValidChannel(false);
    setUISNR(0);
    setUICurrentFreq(10790);
    setUICurrentFreq(8751);
    setUICurrentFreq(8750);
    setUIBtnFindAllToCancel(false);
}

wndMain::~wndMain()
{
    delete ui;
}

void wndMain::setUIValidChannel(bool isValid)
{
    if (isValid)
    {
        ui->lblIsValidChannelIcon->setPixmap(QPixmap(":/iconValidChannel"));
        ui->lblIsValidChannelText->setText(trUtf8("Устойчивый приём"));
    }
    else
    {
        ui->lblIsValidChannelIcon->setPixmap(QPixmap(":/iconNotValidChannel"));
        ui->lblIsValidChannelText->setText(trUtf8("Неустойчивый приём"));
    }
}

void wndMain::blockUIControls(bool isBlock)
{
    if (isBlock)
    {
        ui->btnFindAllRadioStations->setEnabled(false);
        ui->btnSelectRadioStation->setEnabled(false);
        ui->btnAutoSearchUp->setEnabled(false);
        ui->btnAutoSearchDown->setEnabled(false);
        ui->lstAllRadioStations->setEnabled(false);
        ui->spnCurrentFreq->setEnabled(false);
    }
    else
    {
        ui->btnFindAllRadioStations->setEnabled(true);
        ui->btnSelectRadioStation->setEnabled(true);
        ui->btnAutoSearchUp->setEnabled(true);
        ui->btnAutoSearchDown->setEnabled(true);
        ui->lstAllRadioStations->setEnabled(true);
        ui->spnCurrentFreq->setEnabled(true);
    }
}

void wndMain::setUISNR(unsigned char snr)
{
    ui->edtSNR->setText(QString("%1 dB").arg((ushort)snr));
}

void wndMain::setUIRadioStationsList(const QVector<unsigned short> &allFreq)
{
    ui->lstAllRadioStations->clear();

    foreach (unsigned short freq, allFreq)
    {
        ui->lstAllRadioStations->addItem(QString("%1,%2 MHz").arg(freq / 100).arg(freq % 100, 2, 10, QChar('0')));
        ui->lstAllRadioStations->item(ui->lstAllRadioStations->count()-1)->setData(Qt::UserRole, (unsigned int)freq);
    }
}

bool wndMain::getUIRadioStationsListItem(unsigned short &freq)
{
    freq = 0;

    if (ui->lstAllRadioStations->currentRow() >= 0)
    {
        freq = (unsigned short)(ui->lstAllRadioStations->currentItem()->data(Qt::UserRole).toUInt());
        return true;
    }

    return false;
}

void wndMain::setUICurrentFreq(unsigned short freq)
{
    ui->spnCurrentFreq->setValue((double)freq / 100.00);
}

unsigned short wndMain::getUICurrentFreq()
{
    return (unsigned short)(ui->spnCurrentFreq->value() * 100 + 0.5);
}

void wndMain::showInfo(const QString &infoText)
{
    QMessageBox::information(this, "Information", infoText);
}

void wndMain::showError(const QString &errorText)
{
    QMessageBox::critical(this, "Error", errorText);
}

void wndMain::showWarning(const QString &warningText)
{
    QMessageBox::warning(this, "Warning", warningText);
}

void wndMain::setUIProgress(unsigned short freq)
{
    ui->pbrRadio->setValue(freq);
    if (freq <= 8750)
        ui->pbrRadio->setEnabled(false);
    else
        ui->pbrRadio->setEnabled(true);
}

void wndMain::setUIBtnFindAllToCancel(bool isCancel)
{
    if (isCancel)
    {
        ui->btnFindAllRadioStations->setVisible(false);
        ui->btnCancelFindAll->setVisible(true);
    }
    else
    {
        ui->btnCancelFindAll->setVisible(false);
        ui->btnFindAllRadioStations->setVisible(true);
    }

    this->isCancel = false;
}

void wndMain::autoSearch(bool isUp)
{
    unsigned short old_freq = getUICurrentFreq();

    bool isBandLimit = false;
    bool isValidChannel = false;
    unsigned short freq = 0;
    unsigned char snr = 0;

    if (fmTerm.autoSearchNext(isUp, isBandLimit, isValidChannel, freq, snr))
    {
        if (isValidChannel)
        {
            setUIValidChannel(isValidChannel);
            setUISNR(snr);
            setUICurrentFreq(freq);
        }
        else
        {
            setUICurrentFreq(freq);
            setUICurrentFreq(old_freq);
        }
    }
    else
    {
        showError(trUtf8("Ошибка связи с FM-USB. \n"
                         "Возможно приёмник выдернут из USB-порта."));
        close();
        return;
    }
}

void wndMain::AutoSearchUp()
{
    blockUIControls(true);
    autoSearch(true);
    blockUIControls(false);
}

void wndMain::AutoSearchDown()
{
    blockUIControls(true);
    autoSearch(false);
    blockUIControls(false);
}

void wndMain::FindAllRadioStations()
{
    blockUIControls(true);
    setUIBtnFindAllToCancel(true);

    QVector<unsigned short> allf;

    unsigned short old_freq = getUICurrentFreq();

    setUICurrentFreq(8750);
    setUIProgress(8750);

    bool isBandLimit = false;
    bool isValidChannel = false;
    unsigned short freq = 0;
    unsigned char snr = 0;

    if (fmTerm.autoSearchNext(false, isBandLimit, isValidChannel, freq, snr))
    {
        if (isValidChannel)
        {
            allf.append(freq);
        }
    }
    else
    {
        showError(trUtf8("Ошибка связи с FM-USB. \n"
                         "Возможно приёмник выдернут из USB-порта."));
        close();
        return;
    }
    setUIRadioStationsList(allf);
    setUIProgress(freq);
    QApplication::processEvents();

    do
    {
        if (isCancel)
        {
            break;
        }

        if (fmTerm.autoSearchNext(true, isBandLimit, isValidChannel, freq, snr))
        {
            if (isValidChannel)
            {
                allf.append(freq);
            }
        }
        else
        {
            showError(trUtf8("Ошибка связи с FM-USB. \n"
                             "Возможно приёмник выдернут из USB-порта."));
            close();
            return;
        }
        setUIRadioStationsList(allf);
        setUIProgress(freq);
        QApplication::processEvents();
    } while (!isBandLimit);

    setUICurrentFreq(old_freq + 1);
    setUICurrentFreq(old_freq);

    setUIProgress(8750);

    setUIBtnFindAllToCancel(false);
    blockUIControls(false);
}

void wndMain::SelectRadioStation()
{
    unsigned short freq;
    if (getUIRadioStationsListItem(freq))
    {
        setUICurrentFreq(freq + 1);
        setUICurrentFreq(freq);
    }
    else
    {
        showWarning(trUtf8("Не выбрана радиостанция"));
    }
}

void wndMain::ChangeFreq(double value)
{
    unsigned short freq = (unsigned short)(value * 100 + 0.5);
    bool isBandLimit = false;
    bool isValidChannel = false;
    unsigned char snr = 0;

    if (fmTerm.changeFreq(freq, isBandLimit, isValidChannel, snr))
    {
        setUIValidChannel(isValidChannel);
        setUISNR(snr);
    }
    else
    {
        showError(trUtf8("Ошибка связи с FM-USB. \n"
                         "Возможно приёмник выдернут из USB-порта."));
        close();
        return;
    }
}

void wndMain::CancelFindAll()
{
    isCancel = true;
}
*/
