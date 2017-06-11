#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
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
    x123->readConfigFile() ;



}

MainWindow::~MainWindow()
{
    if (haveSpec) {
        x123->DisconnectUSB() ;

    }
    delete ui;
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
    }


}


void MainWindow::setStatusLabel (QString s){
    QString status ("Status : "+s) ;
    ui->statusLabel->setText (status) ;
}
