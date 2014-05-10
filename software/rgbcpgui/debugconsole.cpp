#include "debugconsole.h"
#include <QTime>

/*
class DebugConsole
{
private:
    bool devUsbOpen(MyDevice &mydev);
    void devUsbClose(MyDevice &mydev);

    void printHelp();
    CmdType readCmd(QStringList &params);
    CmdError runCmd(MyDeviceProto &mydevproto, CmdType cmdType, const QStringList &params);


public:
    int exec();
};

*/


DebugConsole::DebugConsole(QObject *parent) :
	QObject(parent),
	qin(stdin, QIODevice::ReadOnly),
	qout(stdout, QIODevice::WriteOnly),
	qerr(stderr, QIODevice::WriteOnly)
{
}

DebugConsole::~DebugConsole()
{
}

void DebugConsole::usage()
{
    qout << "Usage: rgbcpgui [option]" << endl;
	qout << "    option:" << endl;
    qout << "      -d, --debug  -  Run debug console for RGBCP" << endl;
	qout << "      -h, --help   -  Show this help" << endl;
    qout << "      no option    -  Run GUI for RGBCP" << endl;
}

bool DebugConsole::devUsbOpen(MyDevice &mydev)
{
    if (!mydev.open())
	{
        qout << "ERROR: RGBCP NOT FOUND!" << endl;
		return false;
	}
    qout << "RGBCP: Device opened" << endl;

	UsbHidInfo info;
    if (mydev.isOpen() && mydev.getInfo(info))
	{
        qout << "RGBCP: Device info:" << endl;
		qout << QString("    vendorId = 0x%1").arg(info.vendorId, 4, 16, QChar('0')) << endl;
		qout << QString("    productId = 0x%1").arg(info.productId, 4, 16, QChar('0')) << endl;
		qout << QString("    releaseNumber = 0x%1").arg(info.releaseNumber, 4, 16, QChar('0')) << endl;
		qout << QString("    manufacturerString = %1").arg(info.manufacturerString) << endl;
		qout << QString("    productString = %1").arg(info.productString) << endl;
		qout << QString("    serialNumberString = %1").arg(info.serialNumberString) << endl;
		qout << QString("    devicePath = %1").arg(info.devicePath) << endl;
	}
	else
	{
		qout << "ERROR: Can't get device info" << endl;
		return false;
	}

	return true;
}

void DebugConsole::devUsbClose(MyDevice &mydev)
{
    mydev.close();
    qout << "RGBCP: Device closed" << endl;
}

void DebugConsole::printHelp()
{
	qout << endl;
	qout << "Welcome to FM-USB debug console!" << endl;
	qout << "List of commands:" << endl;
	qout << "    test                                          -  Send test command and get test result" << endl;
	qout << "    testparam <[16] msg>                          -  Send test loopback-command and get result" << endl;
    //qout << "    swget                                         -  Get switch state" << endl;
    //qout << "    ledsoff                                       -  Power off all leds" << endl;
    //qout << "    ledsred                                       -  Power on red led" << endl;
    //qout << "    ledsgreen                                     -  Power on green led" << endl;
    //qout << "    getdebugbuf <[1] num>                         -  Get Debug Buffer <num> = 0..3" << endl;
    //qout << "    setdebugbuf <[1] num> <[32] data>             -  Set Debug Buffer <num> = 0..3 with <data>" << endl;
    //qout << "    fmsenddata <[1-8] data>                       -  Send data (1-8 bytes) to Si4705 via I2C bus" << endl;
    //qout << "    fmrecvdata <[1] size>                         -  Recv data (<size> = 1..16 bytes) from Si4705 via I2C bus" << endl;
    //qout << "    fmpowerupanalog                               -  Power Up Si4705 in Analog mode" << endl;
    //qout << "    fmpowerupdigital                              -  Power Up Si4705 in Digital mode" << endl;
    //qout << "    fmpowerupdigitalanalog                        -  Power Up Si4705 in Digital & Analog mode" << endl;
    //qout << "    fmpowerdown                                   -  Power Down Si4705" << endl;
    //qout << "    fmsetproperty <[2] addr> <[2] val>            -  Set Property on Si4705 (<addr>,<val> = 0x0000..0xFFFF)" << endl;
    //qout << "    fmgetproperty <[2] addr>                      -  Get Property on Si4705 (<addr> = 0x0000..0xFFFF)" << endl;
    //qout << "    fmgetrev                                      -  Get Info from Si4705" << endl;
    //qout << "    fmgetintstatus                                -  Get Interrupt Status from Si4705" << endl;
    //qout << "    fmtunefreq <[2] freq> <[1] antcap>            -  Set FM-receiver frequency in 10KHz units (<freq> = 0x222E..0x2A26, <antcap>=0x00..0xBF)" << endl;
    //qout << "    fmseekstart <up|down> <wrap|halt>             -  Begin searching valid channel on Si4705 (<up|down> - direction, <wrap|halt> - action on bound)" << endl;
    //qout << "    fmtunestatus <CancelSeek=y|n> <ClearSTC=y|n>  -  Return status of [fmtunefreq] or [fmseekstart] commands" << endl;
	qout << "    help                                          -  Show this help" << endl;
	qout << "    exit                                          -  Close FM-USB and exit from debug console" << endl;
	qout << endl;
}

CmdType DebugConsole::readCmd(QStringList &params)
{
	params.clear();
	qout << "fm-usb# ";
	qout.flush();
	QString line = qin.readLine().trimmed();
	QStringList splitList = line.split(" ", QString::SkipEmptyParts);

	if (splitList.isEmpty())
		return ctUnknown;

	QString cmdName = splitList[0];
	splitList.removeFirst();
	params = splitList;

	if (cmdName == QString("help"))
		return ctHelp;
	else if (cmdName == QString("exit"))
		return ctExit;
	else if (cmdName == QString("test"))
		return ctTest;
	else if (cmdName == QString("testparam"))
		return ctTestParam;
    //else if (cmdName == QString("swget"))
    //	return ctSwGet;
    //else if (cmdName == QString("ledsoff"))
    //	return ctLedsOff;
    //else if (cmdName == QString("ledsred"))
    //	return ctLedsRed;
    //else if (cmdName == QString("ledsgreen"))
    //	return ctLedsGreen;
    //else if (cmdName == QString("getdebugbuf"))
    //	return ctGetDebugBuf;
    //else if (cmdName == QString("setdebugbuf"))
    //	return ctSetDebugBuf;
    //else if (cmdName == QString("fmsenddata"))
    //	return ctFmSendData;
    //else if (cmdName == QString("fmrecvdata"))
    //	return ctFmRecvData;
    //else if (cmdName == QString("fmpowerupanalog"))
    //	return ctFmPowerUpAnalog;
    //else if (cmdName == QString("fmpowerupdigital"))
    //	return ctFmPowerUpDigital;
    //else if (cmdName == QString("fmpowerupdigitalanalog"))
    //	return ctFmPowerUpDigitalAnalog;
    //else if (cmdName == QString("fmpowerdown"))
    //	return ctFmPowerDown;
    //else if (cmdName == QString("fmsetproperty"))
    //	return ctFmSetProperty;
    //else if (cmdName == QString("fmgetproperty"))
    //	return ctFmGetProperty;
    //else if (cmdName == QString("fmgetrev"))
    //	return ctFmGetRev;
    //else if (cmdName == QString("fmgetintstatus"))
    //	return ctFmGetIntStatus;
    //else if (cmdName == QString("fmtunefreq"))
    //	return ctFmTuneFreq;
    //else if (cmdName == QString("fmseekstart"))
    //	return ctFmSeekStart;
    //else if (cmdName == QString("fmtunestatus"))
    //	return ctFmTuneStatus;

	return ctUnknown;
}

CmdError DebugConsole::runCmd(MyDeviceProto &mydevproto, CmdType cmdType, const QStringList &params)
{
	switch (cmdType)
	{
	case ctTest:
		if (params.isEmpty())
		{
			QByteArray retTest;
            if (mydevproto.cmdTest(retTest))
			{
				qout << QString("test: [%1]{%2} == \"%3\"\n")
					.arg(retTest.size())
					.arg(QString(retTest.toHex()))
					.arg(QString(retTest));
				return ceOk;
			}
			else
				return ceRun;
		}
		break;

	case ctTestParam:
		if (params.size() == 1)
		{
            QByteArray inTest = QByteArray::fromHex(params[0].toLatin1());
			if (inTest.size() == 16)
			{
				QByteArray outTest;
                if (mydevproto.cmdTestParam(inTest, outTest))
				{
					qout << QString("testparam [%1]{%2}: [%3]{%4} == \"%5\"[%6]{%7}\n")
						.arg(inTest.size())
						.arg(QString(inTest.toHex()))
						.arg(outTest.size())
						.arg(QString(outTest.toHex()))
						.arg(QString(outTest.left(11)))
						.arg(outTest.right(16).size())
						.arg(QString(outTest.right(16).toHex()));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
		break;

    /*case ctSwGet:
		if (params.isEmpty())
		{
			bool isSw;
			if (fmterm.cmdSwGet(isSw))
			{
				qout << QString("swget: Switch state: %1").arg(isSw ? QString("on") : QString("off")) << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctLedsOff:
		if (params.isEmpty())
		{
			if (fmterm.cmdLedsOff())
			{
				qout << "ledsoff: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctLedsRed:
		if (params.isEmpty())
		{
			if (fmterm.cmdLedsRed())
			{
				qout << "ledsred: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctLedsGreen:
		if (params.isEmpty())
		{
			if (fmterm.cmdLedsGreen())
			{
				qout << "ledsgreen: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctGetDebugBuf:
		if (params.size() == 1)
		{
			unsigned char bufNum = static_cast<unsigned char>(params[0].toUInt());
			if (bufNum <= 3)
			{
				QByteArray out;
				if (fmterm.cmdGetDebugBuf(bufNum, out))
				{
					qout << QString("getdebugbuf [1]{%1}: [%2]{%3}\n")
						.arg(bufNum, 2, 16, QChar('0'))
						.arg(out.size())
						.arg(QString(out.toHex()));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctSetDebugBuf:
		if (params.size() == 2)
		{
			unsigned char bufNum = static_cast<unsigned char>(params[0].toUInt());
			QByteArray in = QByteArray::fromHex(params[1].toAscii());
			if (bufNum <= 3 && in.size() == 32)
			{
				if (fmterm.cmdSetDebugBuf(bufNum, in))
				{
					qout << QString("setdebugbuf [1]{%1} [%2]{%3}: OK\n")
							.arg(bufNum, 2, 16, QChar('0'))
							.arg(in.size())
							.arg(QString(in.toHex()));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmSendData:
		if (params.size() == 1)
		{
			QByteArray inData = QByteArray::fromHex(params[0].toAscii());
			if (inData.size() >= 1 && inData.size() <= 8)
			{
				if (fmterm.cmdFmSendData(inData))
				{
					qout << QString("fmsenddata [%1]{%2}: OK\n")
							.arg(inData.size())
							.arg(QString(inData.toHex()));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmRecvData:
		if (params.size() == 1)
		{
			unsigned char dataSize = static_cast<unsigned char>(params[0].toUInt());
			if (dataSize >= 1 && dataSize <= 16)
			{
				QByteArray outData;
				if (fmterm.cmdFmRecvData(dataSize, outData))
				{
					qout << QString("fmrecvdata [1]{%1}: [%2]{%3}\n")
							.arg(dataSize, 2, 16, QChar('0'))
							.arg(outData.size())
							.arg(QString(outData.toHex()));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmPowerUpAnalog:
		if (params.isEmpty())
		{
			if (fmterm.cmdFmPowerUpAnalog())
			{
				qout << "fmpowerupanalog: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmPowerUpDigital:
		if (params.isEmpty())
		{
			if (fmterm.cmdFmPowerUpDigital())
			{
				qout << "fmpowerupdigital: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmPowerUpDigitalAnalog:
		if (params.isEmpty())
		{
			if (fmterm.cmdFmPowerUpDigitalAnalog())
			{
				qout << "fmpowerupdigitalanalog: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmPowerDown:
		if (params.isEmpty())
		{
			if (fmterm.cmdFmPowerDown())
			{
				qout << "fmpowerdown: OK" << endl;
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmSetProperty:
		if (params.size() == 2)
		{
			QByteArray paddr = QByteArray::fromHex(params[0].toAscii());
			QByteArray pval = QByteArray::fromHex(params[1].toAscii());
			if (paddr.size() == 2 && pval.size() == 2)
			{
				QDataStream ds_addr(&paddr, QIODevice::ReadOnly);
				ds_addr.setByteOrder(QDataStream::BigEndian);
				unsigned short addr;
				ds_addr >> addr;
				ds_addr.setDevice(0);

				QDataStream ds_val(&pval, QIODevice::ReadOnly);
				ds_val.setByteOrder(QDataStream::BigEndian);
				unsigned short val;
				ds_val >> val;
				ds_val.setDevice(0);

				if (fmterm.cmdFmSetProperty(addr, val))
				{
					qout << QString("fmsetproperty [2]{%1} [2]{%2}: OK\n")
							.arg(addr, 4, 16, QChar('0'))
							.arg(val, 4, 16, QChar('0'));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmGetProperty:
		if (params.size() == 1)
		{
			QByteArray paddr = QByteArray::fromHex(params[0].toAscii());
			if (paddr.size() == 2)
			{
				QDataStream ds_addr(&paddr, QIODevice::ReadOnly);
				ds_addr.setByteOrder(QDataStream::BigEndian);
				unsigned short addr;
				ds_addr >> addr;
				ds_addr.setDevice(0);

				unsigned short val = 0;
				if (fmterm.cmdFmGetProperty(addr, val))
				{
					qout << QString("fmgetproperty [2]{%1}: [2]{%2}\n")
							.arg(addr, 4, 16, QChar('0'))
							.arg(val, 4, 16, QChar('0'));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmGetRev:
		if (params.isEmpty())
		{
			QByteArray partNumber;
			QString firmwareRev;
			QByteArray patchID;
			QString componentRev;
			QString chipRev;
			QByteArray cid;

			if (fmterm.cmdFmGetRev(partNumber, firmwareRev, patchID, componentRev, chipRev, cid))
			{
				qout << QString("fmgetrev:\n"
								"    partNumber   = %1\n"
								"    firmwareRev  = \"%2\"\n"
								"    patchID      = %3\n"
								"    componentRev = \"%4\"\n"
								"    chipRev      = \"%5\"\n"
								"    cid          = %6\n"
								)
					.arg(QString(partNumber.toHex()))
					.arg(firmwareRev)
					.arg(QString(patchID.toHex()))
					.arg(componentRev)
					.arg(chipRev)
					.arg(QString(cid.toHex()));
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmGetIntStatus:
		if (params.isEmpty())
		{
			unsigned char status;

			if (fmterm.cmdFmGetIntStatus(status))
			{
				qout << QString("fmgetintstatus: [1]{%1}\n")
					.arg(status, 2, 16, QChar('0'));
				return ceOk;
			}
			else
				return ceRun;
		}
        break;*/

    /*case ctFmTuneFreq:
		if (params.size() == 2)
		{
			QByteArray pfreq = QByteArray::fromHex(params[0].toAscii());
			QByteArray pantcap = QByteArray::fromHex(params[1].toAscii());
			if (pfreq.size() == 2 && pantcap.size() == 1)
			{
				QDataStream ds_freq(&pfreq, QIODevice::ReadOnly);
				ds_freq.setByteOrder(QDataStream::BigEndian);
				unsigned short freq;
				ds_freq >> freq;
				ds_freq.setDevice(0);

				QDataStream ds_antcap(&pantcap, QIODevice::ReadOnly);
				ds_antcap.setByteOrder(QDataStream::BigEndian);
				unsigned char antcap;
				ds_antcap >> antcap;
				ds_antcap.setDevice(0);

				if (fmterm.cmdFmTuneFreq(freq, antcap))
				{
					qout << QString("fmtunefreq [2]{%1} [1]{%2}: OK\n")
							.arg(freq, 4, 16, QChar('0'))
							.arg(antcap, 2, 16, QChar('0'));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmSeekStart:
		if (params.size() == 2)
		{
			bool valid = true;
			bool isUp = false;
			bool isWrap = false;

			if (!params[0].compare("up", Qt::CaseInsensitive))
				isUp = true;
			else if (!params[0].compare("down", Qt::CaseInsensitive))
				isUp = false;
			else
				valid = false;

			if (!params[1].compare("wrap", Qt::CaseInsensitive))
				isWrap = true;
			else if (!params[1].compare("halt", Qt::CaseInsensitive))
				isWrap = false;
			else
				valid = false;

			if (valid)
			{
				if (fmterm.cmdFmSeekStart(isUp, isWrap))
				{
					qout << QString("fmseekstart <%1> <%2>: OK\n")
							.arg(isUp ? QString("up") : QString("down"))
							.arg(isWrap ? QString("wrap") : QString("halt"));
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

    /*case ctFmTuneStatus:
		if (params.size() == 2)
		{
			bool valid = true;
			bool isCancelSeek = false;
			bool isClearSTC = false;

			if (!params[0].compare("y", Qt::CaseInsensitive))
				isCancelSeek = true;
			else if (!params[0].compare("n", Qt::CaseInsensitive))
				isCancelSeek = false;
			else
				valid = false;

			if (!params[1].compare("y", Qt::CaseInsensitive))
				isClearSTC = true;
			else if (!params[1].compare("n", Qt::CaseInsensitive))
				isClearSTC = false;
			else
				valid = false;

			if (valid)
			{
				bool isBandLimit;
				bool isAFCRails;
				bool isValidChannel;
				unsigned short freq10KHz;
				unsigned char rssi;
				unsigned char snr;
				unsigned char antcap;

				if (fmterm.cmdFmTuneStatus(isCancelSeek, isClearSTC,
										   isBandLimit, isAFCRails, isValidChannel,
										   freq10KHz, rssi, snr, antcap))
				{
					qout << QString("fmtunestatus <%1> <%2>:\n"
									"    isBandLimit     =  %3\n"
									"    isAFCRails      =  %4\n"
									"    isValidChannel  =  %5\n"
									"    freq10KHz       =  %6 (0x%7)\n"
									"    rssi            =  %8\n"
									"    snr             =  %9\n"
									"    antcap          =  %10\n")
							.arg(isCancelSeek ? QString("y") : QString("n"))
							.arg(isClearSTC ? QString("y") : QString("n"))
							.arg(isBandLimit ? QString("yes") : QString("no"))
							.arg(isAFCRails ? QString("yes") : QString("no"))
							.arg(isValidChannel ? QString("yes") : QString("no"))
							.arg(freq10KHz, 0, 10)
							.arg(freq10KHz, 4, 16, QChar('0'))
							.arg((ushort)rssi, 0, 10)
							.arg((ushort)snr, 0, 10)
							.arg((ushort)antcap, 0, 10);
					return ceOk;
				}
				else
					return ceRun;
			}
		}
        break;*/

	default:
		break;
	}

	return ceParams;
}

int DebugConsole::exec()
{
    MyDevice mydev;

    if (!devUsbOpen(mydev))
		return 1;


    MyDeviceProto mydevproto(mydev);

	printHelp();
	bool go = true;
	while (go)
	{
		QStringList params;
		CmdType ct = readCmd(params);
		if (ct == ctUnknown)
		{
			qout << "ERROR: Unknown command" << endl;
		}
		else if (ct == ctHelp)
		{
			printHelp();
		}
		else if (ct == ctExit)
		{
			go = false;
		}
		else
		{
            CmdError ce = runCmd(mydevproto, ct, params);
			if (ce == ceParams)
			{
				qout << "ERROR: Incorrect parameters" << endl;
			}
			else if (ce == ceRun)
			{
				qout << "ERROR: Can't run the command! The device may be unplugged..." << endl;
			}
		}
	}


    devUsbClose(mydev);

	return 0;
}
