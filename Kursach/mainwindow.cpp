#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminpanel.h"
#include "dispatcherpanel.h"
#include "supplierpanel.h"
#include <QString>
#include <QVector>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->pass->text();
    QMessageBox m;

    QFile file("C:/Kursach/logpas.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом авторизации", QMessageBox::Ok);
        QApplication::quit();
    }

    while (!file.atEnd())
    {
        QString line = file.readLine();
        QString temp;

        for (int i = 0; !line[i].isPunct(); i++)
            temp += line[i];
        line.remove(0, temp.size() + 1);


        if (login == temp)
        {
            temp.clear();
            for (int i = 0; !line[i].isPunct(); i++)
                temp += line[i];
            line.remove(0, temp.size() + 1);

            if (password == temp)
            {
                createPanel(line);
                break;
            }
            else
                ui->statusbar->showMessage("Неверный пароль...");
        } else
            ui->statusbar->showMessage("Неверный логин...");
    }

    file.close();
}

void MainWindow::createPanel(QString line)
{
    QString user, name;
    for (int i = 0; !line[i].isPunct(); i++)
        user += line[i];
    line.remove(0, user.size() + 1);

    name = line;

    if (user == "0")
    {
        adminPanel *window =new adminPanel;
        connect(window, SIGNAL(testTwo()), this, SLOT(closeChild()));
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->show();
        window->user = user;
        window->name = name;
        this->hide();
    }

    else if (user == "1")
    {
        dispatcherPanel *window =new dispatcherPanel;
        connect(window, SIGNAL(testTwo()), this, SLOT(closeChild()));
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->show();
        window->user = user;
        window->name = name;
        this->hide();
    }

    else if (user == "2")
    {
        supplierPanel *window =new supplierPanel;
        connect(window, SIGNAL(testTwo()), this, SLOT(closeChild()));
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->show();
        window->user = user;
        window->name = name;
        this->hide();

    }
}

void MainWindow::closeChild()
{
    this->show();
}

