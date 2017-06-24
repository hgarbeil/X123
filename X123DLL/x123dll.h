#ifndef X123DLL_H
#define X123DLL_H

//#include "X123DLL_global.h"
#include "ConsoleHelper.h"

class X123DLL
{
public:
    X123DLL();
    ~X123DLL() ;
    CConsoleHelper *chdpp ;
    bool ConnectUSB() ;
       void GetDppStatus () ;
       bool SendPresetAcquisitionTime(int) ;
       void DisconnectUSB() ;
       bool readConfigFile () ;
       void AcquireSpectrum () ;
       void StartAcquisition() ;
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



};

#endif // X123DLL_H
