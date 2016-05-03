#include "startmain.h"
#include "ui_startmain.h"
#include "mainwindow.h"
StartMain::StartMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartMain),value(false)
{
    ui->setupUi(this);
}

StartMain::~StartMain()
{
    delete ui;
}
void StartMain::on_pushButton_clicked()
{
    value = true;
    this->close();
}
void StartMain::on_pushButton_2_clicked()
{
    this->close();
}
