#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "profiledlg.h"
#include "storage.h"
#include "accounts.h"
#include "createproduct.h"
#include <QString>

adminPanel::adminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminPanel)
{
    ui->setupUi(this);

}

adminPanel::~adminPanel()
{
    delete ui;
}

void adminPanel::on_pushButton_clicked()
{
    profileDlg *profile = new profileDlg();
    connect(profile, SIGNAL(testOne()), this, SIGNAL(testTwo()));
    connect(profile, SIGNAL(testOne()), this, SLOT(exit()));
    profile->setUser(user, name);
    profile->show();

}

void adminPanel::exit()
{
    this->~adminPanel();
}

void adminPanel::on_pushButton_3_clicked()
{
    storage *st = new storage();
    st->setModal(true);
    st->show();
}

void adminPanel::on_pushButton_2_clicked()
{
    accounts *acc = new accounts();
    acc->setModal(true);
    acc->show();
}

void adminPanel::on_pushButton_4_clicked()
{
    createProduct *wh = new createProduct();
    wh->setModal(true);
    wh->show();
}
