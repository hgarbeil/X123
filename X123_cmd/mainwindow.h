#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ConsoleHelper.h"
#include "x123.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool getSpectrometer () ;
    void getOutputSpectrumFile () ;

    CConsoleHelper *chdpp ;
    X123 *x123 ;
    float *xvals, *yvals ;
    int totalSecs, curTime ;
    int nptsSpec ;


protected:
    void changeEvent(QEvent *e);
    bool haveSpec ;
private slots:
    void on_acquireButton_clicked();
    void newdata() ;
    void newdata(int secs) ;
    void endAcquire() ;
    void setStatusLabel (QString s) ;


    void on_PrefixBrowseButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
