#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(int& number,QWidget *parent = 0);
    ~Dialog();
    bool ret() { return retValue;}
    int displayer;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::Dialog *ui;
    bool retValue;
    void display();
};

#endif // DIALOG_H
