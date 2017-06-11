#-------------------------------------------------
#
# Project created by QtCreator 2017-06-08T11:26:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = X123
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DeviceIO/SendCommand.cpp \
    DeviceIO/ParsePacket.cpp \
    DeviceIO/DppUtilities.cpp \
    DeviceIO/DppLibUsb.cpp \
    DeviceIO/DP5Status.cpp \
    DeviceIO/DP5Protocol.cpp \
    stringex.cpp \
    ConsoleHelper.cpp \
    x123.cpp

HEADERS  += mainwindow.h \
    DeviceIO/SendCommand.h \
    DeviceIO/ParsePacket.h \
    DeviceIO/DppUtilities.h \
    DeviceIO/DppLibUsb.h \
    DeviceIO/DppConst.h \
    DeviceIO/DP5Status.h \
    DeviceIO/DP5Protocol.h \
    stringSplit.h \
    stringex.h \
    ConsoleHelper.h \
    x123.h

FORMS    += mainwindow.ui

INCLUDEPATH += ../X123/DeviceIO

LIBS += -L../X123/DeviceIO -lstdc++ -lm -llibusb