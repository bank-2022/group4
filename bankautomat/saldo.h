#ifndef SALDO_H
#define SALDO_H

#include <QDialog>

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = nullptr);
    ~saldo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::saldo *ui;
};

#endif // SALDO_H
