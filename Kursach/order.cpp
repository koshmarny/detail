#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
}

order::~order()
{
    delete ui;
}

void order::on_pushButton_clicked()
{
    ui->textEdit->toPlainText();
}
