#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objMyurl = new myurl;
    base_url=objMyurl->getBase_url();
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
    qDebug() << "base_url=" + base_url;
    cardPIN=ui->lePIN->text();
    id="2";
    objAccountmain= new accountMain(cardPIN, id);
    objAccountmain->show();

    QJsonObject jsonObj;
    jsonObj.insert("cardPIN",cardPIN);
    jsonObj.insert("cardID",id);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());



}

void Login::loginSlot(QNetworkReply *reply)
{
    QByteArray data=reply->readAll();
}

