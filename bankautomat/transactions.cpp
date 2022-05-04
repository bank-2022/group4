#include "transactions.h"
#include "ui_transactions.h"

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
}

transactions::~transactions()
{
    delete ui;

}

void transactions::on_pushButton_clicked()
{
    close();
}

