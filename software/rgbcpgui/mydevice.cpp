#include "mydevice.h"


MyDevice::MyDevice(QObject *parent) :
    QObject(parent), usbHid(this)
{
    usbHidInfo.vendorId = 0;
    usbHidInfo.productId = 0;
    usbHidInfo.releaseNumber = 0;
}

MyDevice::~MyDevice()
{
    usbHid.close();
}

bool MyDevice::open()
{
    close();

    bool res = false;

    UsbHidInfoList uhiList = UsbHid::enumerateVidPid(DEVUSB_VID, DEVUSB_PID);
    if (!uhiList.isEmpty() && usbHid.open(DEVUSB_VID, DEVUSB_PID) && usbHid.setNonBlockingRead())
    {
        usbHidInfo = uhiList[0];
        res = true;
    }

    return res;
}

bool MyDevice::isOpen()
{
    return usbHid.isOpen();
}

void MyDevice::close()
{
    usbHid.close();
}

bool MyDevice::getInfo(UsbHidInfo &info)
{
    bool res = false;

    if (usbHid.isOpen())
    {
        info = usbHidInfo;
        res = true;
    }

    return res;
}

bool MyDevice::sendData(const QByteArray &outData)
{
    QByteArray buf(1, '\0');
    buf.append(outData);

    return outData.size() <= static_cast<int>(DEVUSB_OUT_BUF_SIZE) && isOpen() && usbHid.sendRawOutReport(buf) == buf.size();
}

bool MyDevice::recvData(QByteArray &inData)
{
    bool res = false;
    QByteArray buf(DEVUSB_IN_BUF_SIZE + 1, '\0');

    if (isOpen() && usbHid.recvRawInReport(buf) == static_cast<int>(DEVUSB_IN_BUF_SIZE))
    {
        inData = buf.left(DEVUSB_IN_BUF_SIZE);
        res = true;
    }

    return res;
}
