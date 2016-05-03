#include "dialog.h"
#include "ui_dialog.h"
Dialog::Dialog(int& number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),retValue(false),displayer(number)
{
    ui->setupUi(this);
    display();
}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_pushButton_clicked()
{
    retValue = true;
    this->close();
}
void Dialog::on_pushButton_2_clicked()
{
    retValue = false;
    this->close();
}
void Dialog::display(){
    ui->labor->setText(QString::number(displayer));
}

