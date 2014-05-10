#ifndef MYDEVICE_H
#define MYDEVICE_H

#include <QObject>
#include "usbhid.h"


const unsigned short DEVUSB_VID = 0x1fc9;
const unsigned short DEVUSB_PID = 0xa1b2;
const unsigned int DEVUSB_OUT_BUF_SIZE = 64;
const unsigned int DEVUSB_IN_BUF_SIZE = 64;


class MyDevice : public QObject
{
    Q_OBJECT

private:
    UsbHidInfo usbHidInfo;
    UsbHid usbHid;

public:
    explicit MyDevice(QObject *parent = 0);
    virtual ~MyDevice();
    bool open();
    bool isOpen();
    void close();
    bool getInfo(UsbHidInfo &info);
    bool sendData(const QByteArray &outData);
    bool recvData(QByteArray &inData);
};

#endif // MYDEVICE_H
