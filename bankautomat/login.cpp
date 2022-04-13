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

    QString site_url="http://localhost:3000/book/19";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QString credentials="admin:1234";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateBookSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());



}

void Login::loginSlot(QNetworkReply *reply)
{

}

