#include "accountmain.h"
#include "ui_accountmain.h"

accountMain::accountMain(QString cardPIN, QString cardID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountMain)
{
    ui->setupUi(this);
    ui->labelPIN->setText(cardPIN);
    ui->labelCardId->setText(cardID);
}


accountMain::~accountMain()
{
    delete ui;
    ui=nullptr;
}

void accountMain::on_btnShowBalance_clicked()
{

}


void accountMain::on_pushButton_2_clicked()
{
    close();
}

