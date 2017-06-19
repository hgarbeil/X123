#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <time.h>
using namespace std ;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    haveSpec = false ;
    // create the x123 instance
    x123 = new X123 () ;
    // get the spectrometer
    getSpectrometer() ;
    x123->ReadConfigFile("PX5_Console_Test.txt") ;
    x123->ClearSpectrum () ;

    xvals = new float [4096] ;
    yvals = new float [4096] ;
    for (int i=0; i<4096; i++){
        xvals [i]=i;
        yvals [i]=0;
    }
    ui->SpectrumPlot->setXYData (xvals, yvals, 4096) ;

    ui->acquireButton->setStyleSheet("color:yellow;background-color:green") ;
    totalSecs = 0 ;
    curTime = 20 ;
    x123->SendPresetAcquisitionTime(curTime) ;
    connect (x123, SIGNAL(updData(int)), this, SLOT(newdata(int))) ;
    connect (x123, SIGNAL(endAcquire()), this, SLOT(endAcquire())) ;
    connect (x123, SIGNAL(sendStatus(QString)), this, SLOT(setStatusLabel(QString))) ;
}

MainWindow::~MainWindow()
{
    if (haveSpec) {
        x123->DisconnectUSB() ;

    }
    delete ui;
    delete [] xvals ;
    delete [] yvals ;

}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }


}


bool MainWindow::getSpectrometer() {

    haveSpec = x123->ConnectUSB() ;
    if (haveSpec){
        setStatusLabel ("Spectrometer connected") ;

    } else {
        setStatusLabel ("No spectrometer connected") ;
        return false ;
    }
    x123->GetDppStatus() ;
    return true ;
}


void MainWindow::setStatusLabel (QString s){
    QString status ("Status : "+s) ;
    ui->statusLabel->setText (status) ;
}

// user interface event handler for acquire button
void MainWindow::on_acquireButton_clicked()
{
    int timeSecs = ui->accumTimeLE->text().toInt() ;
    this->getOutputSpectrumFile () ;
    if (timeSecs != curTime){
        x123->SendPresetAcquisitionTime(timeSecs) ;
        curTime = timeSecs ;

    }

    ui->acquireButton->setStyleSheet("color:black;background-color:yellow") ;
    totalSecs = 0 ;
    x123->StartAcquisition() ;

}


// get timestamped ouput file
void MainWindow::getOutputSpectrumFile() {
    time_t curtime ;
    struct tm *loctime ;
    char timestring[80] ;
    curtime = time(NULL) ;
    loctime = localtime (&curtime) ;


    QString str = ui->PrefixLE->text() ;
    sprintf (timestring,"_%04d%02d%02d%02d%02d%02d.mca", loctime->tm_year, loctime->tm_mon,
             loctime->tm_mday, loctime->tm_hour, loctime->tm_min, loctime->tm_sec);
    QString str1 = QString("%1%2").arg(str).arg(timestring);
    x123->SetSpectrumFile (str1.toLatin1().data()) ;

}

void MainWindow::newdata() {
    int i ;
    for (i=0;i<4096;i++)yvals[i] = x123->specData[i];
    ui->SpectrumPlot->setXYData (xvals, yvals, 4096) ;
    setStatusLabel ("Updating spectrum") ;

}

void MainWindow::newdata(int secs) {
    int i ;
    QString statstring = QString ("Updating spectrum : %1 secs").arg (secs);

    for (i=0;i<4096;i++)yvals[i] = x123->specData[i];
    ui->SpectrumPlot->setXYData (xvals, yvals, 4096) ;
    setStatusLabel (statstring) ;

}

void MainWindow::endAcquire() {
    int i ;
    for (i=0;i<4096;i++)yvals[i] = x123->specData[i];
    ui->SpectrumPlot->setXYData (xvals, yvals, 4096) ;
    setStatusLabel ("Acquisition Complete") ;
    ui->acquireButton->setStyleSheet("color:yellow;background-color:green") ;
}
