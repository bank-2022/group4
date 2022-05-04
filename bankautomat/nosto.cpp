#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QString cardNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
    cardNumber=cNumber;

}

nosto::~nosto()
{
    delete ui;


}

const QByteArray &nosto::getWebtoken() const
{
    return webtoken;
}

void nosto::setWebtoken(const QByteArray &newWebtoken)
{
    webtoken=newWebtoken;
}

void nosto::on_closebtn_clicked()
{
    close();
}

void nosto::on_btn10nosto_clicked()
{

    QJsonObject jsonObj;
    amount = 10;
    qDebug()<<amount;
    jsonObj.insert("amount", amount);
    QString site_url="http://localhost:3000/account/balance/8";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

    reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
    ui->nostettuLabel->setText("10€ nostettu.");


}
void nosto::nostoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
}

void nosto::on_btnNosta20_clicked()
{
    QJsonObject jsonObj;
    amount = 20;
    qDebug()<<amount;
    jsonObj.insert("amount", amount);
    QString site_url="http://localhost:3000/account/balance/8";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

    reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
    ui->nostettuLabel->setText("20€ nostettu.");
}


void nosto::on_btnNosta50_clicked()
{
    QJsonObject jsonObj;
    amount = 50;
    qDebug()<<amount;
    jsonObj.insert("amount", amount);
    QString site_url="http://localhost:3000/account/balance/8";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

    reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
    ui->nostettuLabel->setText("50€ nostettu.");
}


void nosto::on_btnNostaMuu_clicked()
{
    QJsonObject jsonObj;
    amountMuu = ui->leMuuSumma->text();
    qDebug()<<amount;
    jsonObj.insert("amount", amountMuu);
    QString site_url="http://localhost:3000/account/balance/8";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

    reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
    ui->nostettuLabel->setText(amountMuu+"€"+" "+ "nostettu.");
}

