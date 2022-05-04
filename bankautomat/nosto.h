#ifndef NOSTO_H
#define NOSTO_H


#include "myurl.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QString cardNumber, QWidget *parent = nullptr);
    ~nosto();

    const QByteArray &getWebtoken() const;
    void setWebtoken(const QByteArray &newWebtoken);

private slots:
    void on_closebtn_clicked();
    void nostoSlot(QNetworkReply *reply);
    void on_btn10nosto_clicked();

    void on_btnNosta20_clicked();

    void on_btnNosta50_clicked();

    void on_btnNostaMuu_clicked();

private:
    Ui::nosto *ui;
    QString cardNumber;
    QNetworkAccessManager *nostoManager;
    double balance;
    QNetworkReply *reply;
    double amount;
    QString id_account;
    QByteArray webtoken;
    myurl *objmyurl;
    QString cNumber;
    QString amountMuu;


};

#endif // NOSTO_H
