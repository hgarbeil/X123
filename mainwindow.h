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
    void setStatusLabel (QString s) ;
    CConsoleHelper *chdpp ;
    X123 *x123 ;

protected:
    void changeEvent(QEvent *e);
    bool haveSpec ;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
