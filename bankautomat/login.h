#ifndef LOGIN_H
#define LOGIN_H

#include "accountmain.h"

#include <QDialog>


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    QString cardPIN;
    QString id;
    accountMain *objAccountmain;
};

#endif // LOGIN_H
