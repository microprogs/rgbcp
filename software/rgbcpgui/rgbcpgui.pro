#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T02:08:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rgbcpgui
TEMPLATE = app

INCLUDEPATH += hidapi

QMAKE_CFLAGS_DEBUG += `pkg-config libusb-1.0 --cflags`
QMAKE_CFLAGS_RELEASE += `pkg-config libusb-1.0 --cflags`
QMAKE_CXXFLAGS += `pkg-config libusb-1.0 --cflags`
LIBS += `pkg-config libusb-1.0 --libs`


SOURCES += main.cpp\
        mainwindow.cpp \
    hidapi/hid-libusb.c \
    usbhid.cpp \
    mydevice.cpp \
    debugconsole.cpp \
    mydeviceproto.cpp \
    widgetleds.cpp \
    pointconverter.cpp \
    colorconverter.cpp \
    dialogledcolor.cpp \
    ledframe.cpp \
    dialogdelay.cpp \
    common.cpp \
    bitstreamwriter.cpp \
    bitstreamreader.cpp \
    mcubitstreamreader.cpp \
    testalg.cpp \
    ledframecompressor.cpp \
    ledframedecompressor.cpp \
    mcuframedecompressor.cpp \
    modelmovie.cpp \
    widgettimeline.cpp

HEADERS  += mainwindow.h \
    hidapi/hidapi.h \
    usbhid.h \
    mydevice.h \
    debugconsole.h \
    mydeviceproto.h \
    widgetleds.h \
    pointconverter.h \
    colorconverter.h \
    dialogledcolor.h \
    ledframe.h \
    dialogdelay.h \
    common.h \
    bitstreamwriter.h \
    bitstreamreader.h \
    mcubitstreamreader.h \
    testalg.h \
    ledframecompressor.h \
    ledframedecompressor.h \
    mcuframedecompressor.h \
    modelmovie.h \
    widgettimeline.h

FORMS    += mainwindow.ui \
    dialogledcolor.ui \
    dialogdelay.ui
