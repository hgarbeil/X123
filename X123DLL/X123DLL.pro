#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T17:12:54
#
#-------------------------------------------------

QT       -=

TARGET = X123DLL
TEMPLATE = lib

DEFINES += X123DLL_LIBRARY

#CONFIG += c++

SOURCES += x123dll.cpp \
    ../DeviceIO/SendCommand.cpp \
    ../DeviceIO/ParsePacket.cpp \
    ../DeviceIO/DppUtilities.cpp \
    ../DeviceIO/DppLibUsb.cpp \
    ../DeviceIO/DP5Status.cpp \
    ../DeviceIO/DP5Protocol.cpp \
    stringex.cpp \
    ConsoleHelper.cpp

HEADERS += x123dll.h\
        #X123DLL_global.h \
    ../DeviceIO/SendCommand.h \
    ../DeviceIO/ParsePacket.h \
    ../DeviceIO/libusb.h \
    ../DeviceIO/DppUtilities.h \
    ../DeviceIO/DppLibUsb.h \
    ../DeviceIO/DppConst.h \
    ../DeviceIO/DP5Status.h \
    ../DeviceIO/DP5Protocol.h \
    stringSplit.h \
    stringex.h \
    ConsoleHelper.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


INCLUDEPATH += .\ ..\DeviceIO C:\hg\workdir\libusb\include
LIBS +=  -L..\DeviceIO -llibusb
OTHER_FILES += \
    DP5Protocol.o \
    ConsoleHelper.o
