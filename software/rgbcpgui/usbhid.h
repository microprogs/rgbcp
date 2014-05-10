#ifndef USBHID_H
#define USBHID_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QByteArray>
#include <hidapi.h>


class UsbHidInfo
{
public:
	unsigned short vendorId;				// Device Vendor ID
	unsigned short productId;				// Device Product ID
	unsigned short releaseNumber;			// Device Release (Version) Number in binary-coded decimal
	QString        manufacturerString;		// Manufacturer String
	QString        productString;			// Product String
	QString        serialNumberString;		// Serial Number String
	QString        devicePath;				// Platform-specific device path
};

typedef QVector<UsbHidInfo> UsbHidInfoList;


class UsbHid : public QObject
{
    Q_OBJECT

private:
	hid_device *hidDevice;

public:
    explicit UsbHid(QObject *parent = 0);
	virtual ~UsbHid();

	static UsbHidInfoList enumerateAll();
	static UsbHidInfoList enumerateVidPid(unsigned short vendorId, unsigned short productId);

	bool open(QString devicePath);
	bool open(unsigned short vendorId, unsigned short productId);
	bool open(unsigned short vendorId, unsigned short productId, QString serialNumberString);

	bool isOpen();
	void close();

	bool setNonBlockingRead();
	bool setBlockingRead();

	int sendRawOutReport(const QByteArray &outData);
	int recvRawInReport(QByteArray &inData);

	int sendRawFeatureReport(const QByteArray &outData);
	int recvRawFeatureReport(QByteArray &inData);
};


#endif // USBHID_H
