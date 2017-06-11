#include "x123.h"
#include <iostream>
using namespace std ;

X123::X123(QObject *parent) :
    QObject(parent)
{
    chdpp = new CConsoleHelper () ;
    haveSpec = false ;

}

X123::~X123 (){
    DisconnectUSB() ;
}

bool X123::ConnectUSB () {
    cout << endl;
    cout << "Running DPP LibUsb tests from console..." << endl;
    cout << endl;
    cout << "\tConnecting to default LibUsb device..." << endl;
    if (chdpp->LibUsb_Connect_Default_DPP()) {
                    cout << "\t\tLibUsb DPP device connected." << endl;
                    cout << "\t\tLibUsb DPP devices present: "  << chdpp->LibUsb_NumDevices << endl;
                    haveSpec = true ;

    } else {
                    cout << "\t\tLibUsb DPP device not connected." << endl;
                    cout << "\t\tNo LibUsb DPP device present." << endl;
                    haveSpec = false ;

    }

    return (haveSpec) ;
}

void X123::DisconnectUSB () {

    if (chdpp->LibUsb_isConnected) { // send and receive status
            cout << endl;
            cout << "\tClosing connection to default LibUsb device..." << endl;
            chdpp->LibUsb_Close_Connection();
            cout << "\t\tDPP device connection closed." << endl;
    }

    return ;
}

bool X123::clearSpectrum () {


    cout << "\tRunning spectrum test..." << endl;
    cout << "\t\tDisabling MCA for spectrum data/status clear." << endl;
    chdpp->LibUsb_SendCommand(XMTPT_DISABLE_MCA_MCS);
    Sleep(1000);
    cout << "\t\tClearing spectrum data/status." << endl;
    chdpp->LibUsb_SendCommand(XMTPT_SEND_CLEAR_SPECTRUM_STATUS);
    Sleep(1000);
    cout << "\t\tEnabling MCA for spectrum data acquisition with status ." << endl;
    return (true) ;
}
