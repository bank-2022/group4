#ifndef ACCOUNTMAIN_H
#define ACCOUNTMAIN_H

#include "nosto.h"
#include "transactions.h"
#include <myurl.h>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class accountMain;
}

class accountMain : public QDialog
{
    Q_OBJECT

public:
    explicit accountMain(QString cardPIN,QString cardNumber, QByteArray token, QWidget *parent = nullptr);
    ~accountMain();

private slots:
    void on_btnShowBalance_clicked();

    void on_btnClose_clicked();
    void balanceSlot(QNetworkReply *reply);

    void on_btnWithdrawal_clicked();

    void on_btnShowTransactions_clicked();

private:
    Ui::accountMain *ui;
    QString cardPIN;
    QString cardNumber;
    myurl *objMyUrl;
    QString id_account;
    QNetworkAccessManager *balanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray webtoken;
    transactions *objTransactions;
    nosto *objNosto;



};

#endif // ACCOUNTMAIN_H
