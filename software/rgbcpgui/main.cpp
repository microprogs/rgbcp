#include "mainwindow.h"
#include <QApplication>
#include "debugconsole.h"
#include "testalg.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Params: Console: Debug Mode and Usage
    QStringList args = app.arguments();
    args.removeFirst();

    if (args.contains("-d") || args.contains("--debug"))
    {
        DebugConsole dc;
        return dc.exec();
    }
    else if (args.contains("-h") || args.contains("--help"))
    {
        DebugConsole dc;
        dc.usage();
        return 0;
    }
    else if (!args.isEmpty())
    {
        DebugConsole dc;
        dc.usage();
        return 1;
    }

    // No Params: GUI

    //////////////////////////////////////
    TestAlg testAlg;
    testAlg.testAll();
    //////////////////////////////////////

    MainWindow w;
    w.show();
    return app.exec();
}

/*
#include <QMessageBox>

#include "fmusbhid.h"
#include "fmusbterminal.h"

int main(int argc, char *argv[])
{

    FmUsbHid fmUsbHid;
    if (fmUsbHid.open())
    {
        FmUsbTerminal fmterm(fmUsbHid);
        wndMain w(fmterm);
        w.show();
        int res = app.exec();
        fmUsbHid.close();
        return res;
    }
    else
    {
        QMessageBox::critical(0, "FM-USB Error",
                              QObject::trUtf8("Не найден FM-USB. \n"
                                              "Возможно приёмник выдернут из USB-порта."));
        return 1;
    }

    return 0;
}
*/
