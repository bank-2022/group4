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
    cardNumber=ui->leCardnumber->text();


    QJsonObject jsonObj;
    jsonObj.insert("cardPIN",cardPIN);
    jsonObj.insert("cardNumber",cardNumber);

   qDebug () << cardPIN + "cardNumber:"+ cardNumber;
    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Login::loginSlot(QNetworkReply *reply)
{
    QByteArray data=reply->readAll();
    qDebug() << data;
    if(data != "false"){
    token="Bearer "+data;
    objAccountmain = new accountMain(cardPIN, cardNumber, token);
    objAccountmain->show();
    close();
    }
    else{
        ui->leCardnumber->setText("");
        ui->lePIN->setText("");
    }
}




