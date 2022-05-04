#include "accountmain.h"
#include "ui_accountmain.h"

accountMain::accountMain(QString cardPIN, QString cNumber, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountMain)
{
      ui->setupUi(this);
    webtoken=token;
    cardNumber=cNumber;
    objMyUrl=new myurl;
    objTransactions = new transactions;
    ui->labelPIN->setText(cNumber);

   // ui->labelCardId->setText(cardNumber);
   // ui->labelCardId->setText(token);



}


accountMain::~accountMain()
{
    delete ui;
    ui=nullptr;


}

void accountMain::on_btnShowBalance_clicked()
{
    qDebug()<< "balance clicked";
    QString site_url=objMyUrl->getBase_url()+"/account/balance/"+cardNumber;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(webtoken));

    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished (QNetworkReply*)),this,SLOT(balanceSlot(QNetworkReply*)));
    reply = balanceManager->get(request);

}


void accountMain::on_btnClose_clicked()
{
    close();


}

void accountMain::balanceSlot(QNetworkReply *reply)
{
       response_data=reply->readAll();
       qDebug()<< response_data;
       QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
       QJsonArray json_array = json_doc.array();
       QString balance;
       foreach (const QJsonValue &value, json_array) {
           QJsonObject json_obj = value.toObject();
           balance+=json_obj["id_account"].toString()+json_obj["accountNumber"].toString()+QString::number(json_obj["balance"].toDouble())+"\r";
       }

       qDebug()<<balance;

       ui->labelBalance->setText(balance+"€");

}


void accountMain::on_btnWithdrawal_clicked()
{
    cardNumber=ui->labelPIN->text();
    objNosto = new nosto(cardNumber);
    objNosto->setWebtoken(webtoken);
    objNosto->exec();
}


void accountMain::on_btnShowTransactions_clicked()
{

    objTransactions->exec();
}

