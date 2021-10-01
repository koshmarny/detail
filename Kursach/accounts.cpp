#include "accounts.h"
#include "ui_accounts.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <QMessageBox>
#include <QDebug>

accounts::accounts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accounts)
{
    ui->setupUi(this);
}

accounts::~accounts()
{
    delete ui;
}

void accounts::on_pushButton_clicked()
{
    QVector<QString> line;
    QString temp;

    QFile file("C:/Kursach/logpas.txt");
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом пользователей", QMessageBox::Ok);
        QApplication::quit();
    }

    while (!file.atEnd())
        line.push_back(file.readLine());


    file.close();
    foreach (temp, line)
    {
        QString buf;

        for (int i = 0; !temp[i].isPunct();i++)
            buf += temp[i];
        if(buf == ui->login->text())
        {
            QMessageBox err;
            err.critical(this, "Ошибка", "Пользователь с таким логином уже существует", QMessageBox::Ok);
            return;
        }
    }

    line.push_back(ui->login->text() + "," + ui->pass->text() + "," + QString::number(ui->comboBox->currentIndex()) + "," + ui->fio->text() + '\n');

    if (!file.open(QFileDevice::WriteOnly))
        {
            QMessageBox err;
            err.critical(this, "Ошибка", "Проблема с файлом пользователей", QMessageBox::Ok);
            QApplication::quit();
        }

     QTextStream stream(&file);
     stream.setCodec("UTF-8");

     foreach (temp, line)
         stream << temp;

     file.close();

     QMessageBox y;
     y.setText("Пользователь добавлен!");
     y.exec();
}

void accounts::on_pushButton_2_clicked()
{
    QVector<QString> line;
    QString temp;
    bool b = 0;;

    QFile file("C:/Kursach/logpas.txt");
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом пользователей", QMessageBox::Ok);
        QApplication::quit();
    }

    while (!file.atEnd())
    {
        temp = file.readLine();
        QString login;

        for (int i = 0; !temp[i].isPunct();i++)
            login += temp[i];

        if (login != ui->logdel->text())
            line.push_back(temp);
        else
            b = 1;
    }

    if (!b)
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Пользователя с таким логином не существует", QMessageBox::Ok);
        return;
    }

    file.close();

    if (!file.open(QFileDevice::WriteOnly))
        {
            QMessageBox err;
            err.critical(this, "Ошибка", "Проблема с файлом пользователей", QMessageBox::Ok);
            QApplication::quit();
        }

     QTextStream stream(&file);
     stream.setCodec("UTF-8");

     foreach (temp, line)
         stream << temp;

     file.close();

     QMessageBox y;
     y.setText("Пользователь удалён!");
     y.exec();
}
