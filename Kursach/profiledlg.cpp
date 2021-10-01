#include "profiledlg.h"
#include "ui_profiledlg.h"
#include "mainwindow.h"
#include <QMessageBox>

profileDlg::profileDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profileDlg)
{
    ui->setupUi(this);
    connect(this, SIGNAL(close()), this, SIGNAL(testOne()));
}

profileDlg::~profileDlg()
{
    delete ui;
}

void profileDlg::setUser(QString user, QString name)
{
    if (user == "0")
        ui->userGr->setText("Администратор");
    else if (user == "1")
        ui->userGr->setText("Деспетчер");
    else if (user == "2")
        ui->userGr->setText("Поставщик");

    ui->nameUser->setText(name);
}

void profileDlg::on_exitPr_clicked()
{
    emit close();
    this->~profileDlg();

}
