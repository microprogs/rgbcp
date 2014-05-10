#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QObject>
#include <QStringList>
#include <QTextStream>
#include "usbhid.h"
#include "fmusbhid.h"
#include "fmusbterminal.h"


enum CmdType {ctUnknown, ctHelp, ctExit,
			  ctTest, ctTestParam, ctSwGet, ctLedsOff, ctLedsRed, ctLedsGreen,
			  ctGetDebugBuf, ctSetDebugBuf,
			  ctFmSendData, ctFmRecvData,
			  ctFmPowerUpAnalog, ctFmPowerUpDigital, ctFmPowerUpDigitalAnalog, ctFmPowerDown,
			  ctFmSetProperty, ctFmGetProperty,
			  ctFmGetRev, ctFmGetIntStatus, ctFmTuneFreq, ctFmSeekStart, ctFmTuneStatus};
enum CmdError {ceOk, ceParams, ceRun};


class DebugConsole : public QObject
{
    Q_OBJECT

private:
	QTextStream qin;
	QTextStream qout;
	QTextStream qerr;

	bool fmUsbOpen(FmUsbHid &fm);
	void fmUsbClose(FmUsbHid &fm);

	void printHelp();
	CmdType readCmd(QStringList &params);
	CmdError runCmd(FmUsbTerminal &fmterm, CmdType cmdType, const QStringList &params);


public:
    explicit DebugConsole(QObject *parent = 0);
	virtual ~DebugConsole();

	void usage();
	int exec();
};

#endif // DEBUGCONSOLE_H
