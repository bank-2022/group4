#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objAccountmain;
    objAccountmain=nullptr;
}

void Login::on_btnLogin_clicked()
{
    cardPIN=ui->lePIN->text();
    id="2";
    objAccountmain= new accountMain(cardPIN, id);
    objAccountmain->show();
    close();
}

