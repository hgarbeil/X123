#ifndef X123_H
#define X123_H

//#include <QObject>
#include <QThread>
#include "ConsoleHelper.h"

class X123 : public QThread
{
    //Q_OBJECT
public:
    //explicit X123(QObject *parent = 0);
    explicit X123 () ;
    ~X123 () ;
    CConsoleHelper *chdpp ;
    bool ConnectUSB() ;
    void GetDppStatus () ;
    bool SendPresetAcquisitionTime(int) ;
    void DisconnectUSB() ;
    bool readConfigFile () ;
    void AcquireSpectrum () ;
    void run () ;
    bool ClearSpectrum () ;
    // Saving spectrum file
    void SaveSpectrumFile() ;
    void SetSpectrumFile (char *) ;

    bool ReadConfigFile(char *) ;
    void ReadDppConfigurationFromHardware(bool);
    void DisplayPresets () ;
    bool haveSpec ;
    int curSecs ;
    int nptsSpec ;
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
