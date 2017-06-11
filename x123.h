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
    void DisconnectUSB() ;
    bool readConfigFile () ;
    void startAcquisition () ;
    bool haveSpec ;
signals:
    
public slots:
    
};

#endif // X123_H
