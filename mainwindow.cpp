#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <stdlib.h>
#include<QKeyEvent>
int  cnt =30;
int score = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),locker(false)
{
    ui->setupUi(this);
    time_count();
    smallRedOne();
    smallBlueOne();
    smallRedTwo();
    smallBlueTwo();
    bigRedOne();
    bigBlueOne();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::smallRedOne(){
    x = (rand()%9+10)*100;
    while( x== u|| x ==x1|| x == u1||x == x2 ||x == u2)
        x= (rand()%9+10)*100;
    y = 150;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movesmallRedOne()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::smallRedTwo(){
    x1 = (rand()%7+11)*100;
    y1 = 150;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movesmallRedTwo()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::bigRedOne(){
    x2 = (rand()%6+9)*100;
    y2 = 145;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movebigRedOne()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::bigBlueOne(){
    u2 = (rand()%9+13)*100;
    v2 = 145;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movebigBlueOne()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::movesmallRedOne(){
    x = x -10;
    ui->smallRedOne->move( QPoint(x,y) );
    srand(time(NULL));
    if( x <= 100 && locker == false) {
        x= (rand()%7+8)*100;
       while( x == u|| x ==x1|| x == u1||x == x2 ||x == u2)
           x= x+300;
    }
}

void MainWindow::movesmallRedTwo(){
    x1 = x1-10;
    ui->smallRedTwo->move( QPoint(x1,y1) );
    srand(time(NULL));
    if( x1 <= 100 && locker == false) {
        x1= (rand()%9+7)*100;
       while( x1 == x || x1 ==u || x1 == u1 || x1 == x2 ||x1 == u2)
            x1= (rand()%11+7)*100;
    }
}
void MainWindow::movebigRedOne(){
    x2 = x2 -10;
    ui->bigRedOne->move( QPoint(x2,y2) );
    srand(time(NULL));
    if( x2 <= 100&& locker == false) {
        x2= (rand()%7+9)*100;
       while( x2 == u || x2 ==x1 || x2 == u1 || x2 == x ||x2 == u2)
            x2= (rand()%7+9)*100;
     }
}
void MainWindow::movebigBlueOne(){
    u2 = u2 -10;
    ui->bigBlueOne->move( QPoint(u2,v2) );
    srand(time(NULL));
    if( u2 <= 100&& locker == false) {
        u2= (rand()%8+9)*100;
       while( u2 == u || u2 ==x1 || u2 == u1 || u2 == x || u2 == x2)
            u2= (rand()%8+11)*100;
     }
}
void MainWindow::smallBlueOne(){
    u = (rand()%9+7)*100;
    v = 155;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movesmallBlueOne()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::smallBlueTwo(){
    u1 = (rand()%6+10)*100;
    v1 = 155;
   QTimer *timer  = new QTimer (this);
   connect (timer,SIGNAL(timeout()),this,SLOT(movesmallBlueTwo()));
   timer->start(40);
   ui->setupUi(this);
}
void MainWindow::movesmallBlueOne(){
    u = u -10;
    ui->smallBlueOne->move( QPoint(u,v) );
    srand(time(NULL));
    if( u <= 100&& locker == false) {
        u= (rand()%8+7)*100;
        while( u == x || u ==x1 || u == u1|| u == x2||u == u2)
           u= (rand()%6+7)*100;
    }
}
void MainWindow::movesmallBlueTwo(){
    u1 = u1 -10;
    ui->smallBlueTwo->move( QPoint(u1,v1) );
    srand(time(NULL));
    if( u1 <= 100&& locker == false) {
        u1= (rand()%7+8)*100;
        while( u1 == x || u1 ==x1 || u1== u || u1 ==x2 ||u1==u2 )
            u1= (rand()%9+11)*100;
     }
}
void MainWindow::timer_timeout(){
    cnt--;
    ui->timers->setText(QString::number(cnt));
    if (cnt ==0){
        locker = true;
        x = x1= x2= u= u1= u2= 100;
        Dialog showUp(score);
        showUp.setModal(true);
        showUp.exec();
        bool taker = showUp.ret();
        if( taker == true ) {
            cnt = 30;
            ui->timers->setText(QString::number(cnt));
            score = 0;
            ui->scores->setText(QString::number(score));
            locker = false;
        }
        else this->close();
    }
}
void MainWindow::time_count(){
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect (timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    timer->start();
}
void MainWindow::keyPressEvent(QKeyEvent* event){
    if((event->key() == Qt::Key_D)||(event->key() == Qt::Key_F)){
        if(x>100&&x<180 && locker == false){
            score++;
            x= (rand()%9+11)*100;
            while( x == u||x ==x1||x == u1||x == x2||x==u2 )
                x= (rand()%7+12)*100;
            ui->scores->setText(QString::number(score));
        }
        else if(x1>100&&x1<180&& locker == false){
            score++;
            x1= (rand()%10+10)*100;
            while( x1 == x || x1 ==u || x1 == u1  || x1 == x2||x1==u2)
                x1= (rand()%7+13)*100;
            ui->scores->setText(QString::number(score));
         }
        else if(x2>100&&x2<180&& locker == false){
            score = score+2;
            x2= (rand()%7+10)*100;
            while( x2 == u || x2 ==x1 || x2 == u1|| x2 == x ||x2==u2)
                x2= x2+300;
            ui->scores->setText(QString::number(score));
         }
   }
    else if((event->key() == Qt::Key_K)||(event->key() == Qt::Key_L)){
        if(u>100&&u<180&& locker == false){
            score++;
            u= (rand()%7+9)*100;
            while( u == x || u == x1 || u == u1 || u == x2 ||u == u2 )
                u= (rand()%7+8)*100;
            ui->scores->setText(QString::number(score));
         }
         else if(u1>100&&u1<180&& locker == false){
            score++;
            u1= (rand()%11+10)*100;
            while( u1 == x || u1 == x1  || u1 == u ||u1 == x2 ||u1==u2)
                u1= (rand()%7+13)*100;
            ui->scores->setText(QString::number(score));
         }
        else if(u2>100&&u2<180&& locker == false){
           score=score+2;
           u2= (rand()%8+11)*100;
           while( u2 == x || u2 == x1  || u2 == u ||u2 == x2||u2 ==u1 )
               u2= u2 + 200;
           ui->scores->setText(QString::number(score));
        }
    }
}
