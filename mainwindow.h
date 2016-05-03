#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets/QApplication>
#include <QMainWindow>
#include<QTimer>
#include<QLabel>
#include<QMessageBox>
#include"dialog.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Dialog;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void smallRedOne();
    void smallBlueOne();
    void smallRedTwo();
    void smallBlueTwo();
    void bigRedOne();
    void bigBlueOne();
    void counter();
    void time_count();
private:
    Ui::MainWindow * ui;
    int x,y,u,v,x1,y1,u1,v1,x2,y2,u2,v2;
    QTimer *timer;
    void keyPressEvent(QKeyEvent*  event);
    bool locker;
public slots :
    void movesmallRedOne();
    void movesmallBlueOne();
    void movesmallRedTwo();
    void movesmallBlueTwo();
    void movebigRedOne();
    void movebigBlueOne();
    void timer_timeout();
};

#endif // MAINWINDOW_H
