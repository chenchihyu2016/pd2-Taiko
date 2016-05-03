#ifndef STARTMAIN_H
#define STARTMAIN_H

#include <QDialog>

namespace Ui {
class StartMain;
}

class StartMain : public QDialog
{
    Q_OBJECT

public:
    explicit StartMain(QWidget *parent = 0);
    ~StartMain();
    bool return_value(){ return value; }
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::StartMain *ui;
    bool value;
};

#endif // STARTMAIN_H
