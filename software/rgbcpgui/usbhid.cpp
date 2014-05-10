#include "usbhid.h"


UsbHid::UsbHid(QObject *parent) :
    QObject(parent)
{
	hidDevice = 0;
}

UsbHid::~UsbHid()
{
	close();
}

UsbHidInfoList UsbHid::enumerateAll()
{
	return enumerateVidPid(0, 0);
}

UsbHidInfoList UsbHid::enumerateVidPid(unsigned short vendorId, unsigned short productId)
{
	UsbHidInfoList res;

	struct hid_device_info *devs, *cur_dev;
	devs = hid_enumerate(vendorId, productId);
	cur_dev = devs;
	while (cur_dev)
	{
		UsbHidInfo hidInfo;
		hidInfo.vendorId = cur_dev->vendor_id;
		hidInfo.productId = cur_dev->product_id;
		hidInfo.releaseNumber = cur_dev->release_number;
		hidInfo.manufacturerString = QString::fromWCharArray(cur_dev->manufacturer_string);
		hidInfo.productString = QString::fromWCharArray(cur_dev->product_string);
		hidInfo.serialNumberString = QString::fromWCharArray(cur_dev->serial_number);
		hidInfo.devicePath = QString::fromAscii(cur_dev->path);
		res.append(hidInfo);

		cur_dev = cur_dev->next;
	}
	hid_free_enumeration(devs);

	return res;
}

bool UsbHid::open(QString devicePath)
{
	close();

	bool res = false;
	hid_device *h;

	if ((h = hid_open_path(devicePath.toAscii().data())) != 0)
	{
		hidDevice = h;
		res = true;
	}

	return res;
}

bool UsbHid::open(unsigned short vendorId, unsigned short productId)
{
	return open(vendorId, productId, QString(""));
}

bool UsbHid::open(unsigned short vendorId, unsigned short productId, QString serialNumberString)
{
	close();

	bool res = false;
	hid_device *h;
	wchar_t *serial = (serialNumberString.size() > 0) ? const_cast<wchar_t*>(serialNumberString.toStdWString().c_str()) : 0;

	if ((h = hid_open(vendorId, productId, serial)) != 0)
	{
		hidDevice = h;
		res = true;
	}

	return res;
}

bool UsbHid::isOpen()
{
	return hidDevice != 0;
}

void UsbHid::close()
{
	if (hidDevice != 0)
	{
		hid_close(hidDevice);
		hidDevice = 0;
	}
}

bool UsbHid::setNonBlockingRead()
{
	return hidDevice != 0 && hid_set_nonblocking(hidDevice, 1) == 0;
}

bool UsbHid::setBlockingRead()
{
	return hidDevice != 0 && hid_set_nonblocking(hidDevice, 0) == 0;
}

/** @brief Write an Output report to a HID device.

	The first byte of @p data[] must contain the Report ID. For
	devices which only support a single report, this must be set
	to 0x0. The remaining bytes contain the report data. Since
	the Report ID is mandatory, calls to hid_write() will always
	contain one more byte than the report contains. For example,
	if a hid report is 16 bytes long, 17 bytes must be passed to
	hid_write(), the Report ID (or 0x0, for devices with a
	single report), followed by the report data (16 bytes). In
	this example, the length passed in would be 17.

	hid_write() will send the data on the first OUT endpoint, if
	one exists. If it does not, it will send the data through
	the Control Endpoint (Endpoint 0).

	@ingroup API
	@param device A device handle returned from hid_open().
	@param data The data to send, including the report number as
		the first byte.
	@param length The length in bytes of the data to send.

	@returns
		This function returns the actual number of bytes written and
		-1 on error.
*/
int UsbHid::sendRawOutReport(const QByteArray &outData)
{
	if (hidDevice != 0)
		return hid_write(hidDevice, (const unsigned char*)outData.data(), outData.size());
	return -1;
}

/** @brief Read an Input report from a HID device.

	Input reports are returned
	to the host through the INTERRUPT IN endpoint. The first byte will
	contain the Report number if the device uses numbered reports.

	@ingroup API
	@param device A device handle returned from hid_open().
	@param data A buffer to put the read data into.
	@param length The number of bytes to read. For devices with
		multiple reports, make sure to read an extra byte for
		the report number.

	@returns
		This function returns the actual number of bytes read and
		-1 on error.
*/
int UsbHid::recvRawInReport(QByteArray &inData)
{
	int res = -1;
	if (hidDevice != 0)
	{
		do
		{
			res = hid_read(hidDevice, (unsigned char*)inData.data(), inData.size());
			if (!res)
				usleep(1);
		} while (!res);
	}
	return res;
}

/** @brief Send a Feature report to the device.

	Feature reports are sent over the Control endpoint as a
	Set_Report transfer.  The first byte of @p data[] must
	contain the Report ID. For devices which only support a
	single report, this must be set to 0x0. The remaining bytes
	contain the report data. Since the Report ID is mandatory,
	calls to hid_send_feature_report() will always contain one
	more byte than the report contains. For example, if a hid
	report is 16 bytes long, 17 bytes must be passed to
	hid_send_feature_report(): the Report ID (or 0x0, for
	devices which do not use numbered reports), followed by the
	report data (16 bytes). In this example, the length passed
	in would be 17.

	@ingroup API
	@param device A device handle returned from hid_open().
	@param data The data to send, including the report number as
		the first byte.
	@param length The length in bytes of the data to send, including
		the report number.

	@returns
		This function returns the actual number of bytes written and
		-1 on error.
*/
int UsbHid::sendRawFeatureReport(const QByteArray &outData)
{
	if (hidDevice != 0)
		return hid_send_feature_report(hidDevice, (const unsigned char*)outData.data(), outData.size());
	return -1;
}

/** @brief Get a feature report from a HID device.

	Make sure to set the first byte of @p data[] to the Report
	ID of the report to be read.  Make sure to allow space for
	this extra byte in @p data[].

	@ingroup API
	@param device A device handle returned from hid_open().
	@param data A buffer to put the read data into, including
		the Report ID. Set the first byte of @p data[] to the
		Report ID of the report to be read.
	@param length The number of bytes to read, including an
		extra byte for the report ID. The buffer can be longer
		than the actual report.

	@returns
		This function returns the number of bytes read and
		-1 on error.
*/
int UsbHid::recvRawFeatureReport(QByteArray &inData)
{
	if (hidDevice != 0)
		return hid_get_feature_report(hidDevice, (unsigned char*)inData.data(), inData.size());
	return -1;
}
