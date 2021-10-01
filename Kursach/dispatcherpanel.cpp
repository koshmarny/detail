#include "dispatcherpanel.h"
#include "ui_dispatcherpanel.h"
#include "profiledlg.h"
#include "storage.h"
#include "createproduct.h"
#include <QString>

dispatcherPanel::dispatcherPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dispatcherPanel)
{
    ui->setupUi(this);
}

dispatcherPanel::~dispatcherPanel()
{
    delete ui;
}

void dispatcherPanel::on_pushButton_clicked()
{
    profileDlg *profile = new profileDlg();
    connect(profile, SIGNAL(testOne()), this, SIGNAL(testTwo()));
    connect(profile, SIGNAL(testOne()), this, SLOT(exit()));
    profile->setUser(user, name);
    profile->show();
}

void dispatcherPanel::exit()
{
    this->~dispatcherPanel();
}

void dispatcherPanel::on_storageBut_clicked()
{
    storage *st = new storage();
    st->setModal(true);
    st->show();
}

void dispatcherPanel::on_manBut_clicked()
{
    createProduct *wh = new createProduct();
    wh->setModal(true);
    wh->show();
}
