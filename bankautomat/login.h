#ifndef LOGIN_H
#define LOGIN_H

#include "accountmain.h"
#include "myurl.h"
#include <QDebug>
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>

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
    void loginSlot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QString cardPIN;
    QString id;
    accountMain *objAccountmain;
    myurl * objMyurl;
    QString base_url;

    QNetworkAccessManager * loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // LOGIN_H
