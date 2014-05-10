#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


/*
#ifndef WNDMAIN_H
#define WNDMAIN_H

#include <QMainWindow>
#include <QVector>
#include "fmusbterminal.h"
#include "fmusbhid.h"


namespace Ui {
    class wndMain;
}

class wndMain : public QMainWindow
{
    Q_OBJECT

private:
    Ui::wndMain *ui;
    FmUsbTerminal &fmTerm;
    bool isCancel;

private:
    void setUIValidChannel(bool isValid);
    void setUISNR(unsigned char snr);
    void blockUIControls(bool isBlock);
    void setUIRadioStationsList(const QVector<unsigned short> &allFreq);
    bool getUIRadioStationsListItem(unsigned short &freq);
    void setUICurrentFreq(unsigned short freq);
    unsigned short getUICurrentFreq();
    void showInfo(const QString &infoText);
    void showError(const QString &errorText);
    void showWarning(const QString &warningText);
    void autoSearch(bool isUp);
    void setUIProgress(unsigned short freq);
    void setUIBtnFindAllToCancel(bool isCancel);

public:
    explicit wndMain(FmUsbTerminal &fmterm);
    virtual ~wndMain();

private slots:
    void AutoSearchUp();
    void AutoSearchDown();
    void FindAllRadioStations();
    void SelectRadioStation();
    void ChangeFreq(double value);
    void CancelFindAll();
};

#endif // WNDMAIN_H
*/
