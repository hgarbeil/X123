#ifndef X123_H
#define X123_H

#include <QObject>
#include "ConsoleHelper.h"

class X123 : public QObject
{
    Q_OBJECT
public:
    explicit X123(QObject *parent = 0);
    ~X123 () ;
    CConsoleHelper *chdpp ;
    bool ConnectUSB() ;
    void GetDppStatus () ;
    bool SendPresetAcquisitionTime(int) ;
    void DisconnectUSB() ;
    bool readConfigFile () ;
    void AcquireSpectrum () ;
    void StartAcquisition() ;
    bool ClearSpectrum () ;
    bool ReadConfigFile(char *) ;
    void ReadDppConfigurationFromHardware(bool);
    void DisplayPresets () ;
    bool haveSpec ;
    int curSecs ;
    long *specData ;

protected :
    bool bRunSpectrumTest, bRunConfigurationTest ;
    bool bHaveStatusResponse, bHaveConfigFromHW ;
signals:
    void updData(int) ;
    void endAcquire() ;
    void sendStatus (QString) ;
    
public slots:
    
};

#endif // X123_H
