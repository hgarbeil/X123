#-------------------------------------------------
#
# Project created by QtCreator 2017-06-08T11:26:49
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = X123
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../DeviceIO/SendCommand.cpp \
    ../DeviceIO/ParsePacket.cpp \
    ../DeviceIO/DppUtilities.cpp \
    ../DeviceIO/DppLibUsb.cpp \
    ../DeviceIO/DP5Status.cpp \
    ../DeviceIO/DP5Protocol.cpp \
    stringex.cpp \
    ConsoleHelper.cpp \
    x123.cpp \
    qcustomplot.cpp \
    myprofileplot.cpp \
    plotscaledialog.cpp

HEADERS  += mainwindow.h \
    ../DeviceIO/SendCommand.h \
    ../DeviceIO/ParsePacket.h \
    ../DeviceIO/DppUtilities.h \
    ../DeviceIO/DppLibUsb.h \
    ../DeviceIO/DppConst.h \
    ../DeviceIO/DP5Status.h \
    ../DeviceIO/DP5Protocol.h \
    stringSplit.h \
    stringex.h \
    ConsoleHelper.h \
    x123.h \
    qcustomplot.h \
    myprofileplot.h \
    plotscaledialog.h

FORMS    += mainwindow.ui \
    plotscaledialog.ui

INCLUDEPATH += ../DeviceIO C:/Users/przem/workdir/libusb/

LIBS += -L../DeviceIO -LC:/Users/przem/workdir/libusb/MinGW32/dll -lstdc++ -lm -lusb
