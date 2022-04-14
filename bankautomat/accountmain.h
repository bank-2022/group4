#ifndef ACCOUNTMAIN_H
#define ACCOUNTMAIN_H

#include <QDialog>

namespace Ui {
class accountMain;
}

class accountMain : public QDialog
{
    Q_OBJECT

public:
    explicit accountMain(QString cardPIN,QString cardID, QWidget *parent = nullptr);
    ~accountMain();

private slots:
    void on_btnShowBalance_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::accountMain *ui;
    QString cardPIN;
    QString cardID;

};

#endif // ACCOUNTMAIN_H
