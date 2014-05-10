#ifndef MYDEVICEPROTO_H
#define MYDEVICEPROTO_H

#include <QObject>
#include <QByteArray>
#include "mydevice.h"


class MyDeviceProto : public QObject
{
    Q_OBJECT

private:
    MyDevice &m_mydev;
    unsigned int reqNum;

protected:
    bool processCommand(unsigned int cmdCode, const QByteArray &params, QByteArray &ret);

public:
    explicit MyDeviceProto(MyDevice &mydev, QObject *parent = 0);
    virtual ~MyDeviceProto();

    bool cmdTest(QByteArray &retTest);
    bool cmdTestParam(const QByteArray &inTest, QByteArray &outTest);
};

#endif // MYDEVICEPROTO_H

/*
class FmUsbTerminal
{
public:
    bool cmdSwGet(bool &isSw);
    bool cmdLedsOff();
    bool cmdLedsRed();
    bool cmdLedsGreen();
    bool cmdGetDebugBuf(unsigned char bufNum, QByteArray &outBuf);
    bool cmdSetDebugBuf(unsigned char bufNum, const QByteArray &inBuf);
    bool cmdFmSendData(const QByteArray &inData);
    bool cmdFmRecvData(unsigned char dataSize, QByteArray &outData);
    bool cmdFmPowerUpAnalog();
    bool cmdFmPowerUpDigital();
    bool cmdFmPowerUpDigitalAnalog();
    bool cmdFmPowerDown();
    bool cmdFmSetProperty(unsigned short paddr, unsigned short pval);
    bool cmdFmGetProperty(unsigned short paddr, unsigned short &pval);
    bool cmdFmGetRev(QByteArray &partNumber, QString &firmwareRev, QByteArray &patchID,
        QString &componentRev, QString &chipRev, QByteArray &cid);
    bool cmdFmGetIntStatus(unsigned char &intStatus);
    bool cmdFmTuneFreq(unsigned short freq10KHz, unsigned char antCap);
    bool cmdFmSeekStart(bool isUp, bool isWrap);
    bool cmdFmTuneStatus(bool isCancelSeek, bool isClearSTC,
                         bool &isBandLimit, bool &isAFCRails, bool &isValidChannel,
                         unsigned short &freq10KHz, unsigned char &rssi,
                         unsigned char &snr, unsigned char &antcap);
};
*/
