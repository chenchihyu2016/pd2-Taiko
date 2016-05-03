#include "mainwindow.h"
#include <QApplication>
#include "startmain.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartMain r;
    r.setModal(true);
    r.exec();
    bool air = r.return_value();
    if(air){
        MainWindow w;
        w.show();
        return a.exec();
    }
}
