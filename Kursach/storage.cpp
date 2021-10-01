#include "storage.h"
#include "ui_storage.h"
#include <QFile>
#include <QString>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>

storage::storage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::storage)
{
    ui->setupUi(this);
    ui->changeSt->addItem(" ");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->hide();

    QFile file;
    for (int i = 0; ;i++)
    {

    file.setFileName(tr("C:/Kursach/storage%1.txt").arg(i));
    if (file.exists() && file.open(QFileDevice::ReadOnly))
    {
        ui->changeSt->addItem(tr("%1 ----- ").arg(i) + file.readLine());
        file.close();
    } else
        break;
    }
}

storage::~storage()
{
    delete ui;
}

void storage::on_changeSt_activated(const QString &arg1)
{
    ui->tableWidget->setRowCount(0);
    for (int i = 0; arg1[i].isDigit(); i++)
        num += arg1[i];


    QFile file(tr("C:/Kursach/storage%1.txt").arg(num));
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом склада", QMessageBox::Ok);
        QApplication::quit();
    }

    int row = 0;
    file.readLine();

    while (!file.atEnd())
    {
        QString line = file.readLine();

        ui->tableWidget->insertRow(row);

        QTableWidgetItem *code = new QTableWidgetItem(reader(&line));
        QTableWidgetItem *name = new QTableWidgetItem(reader(&line));
        QTableWidgetItem *count = new QTableWidgetItem(reader(&line));

        ui->tableWidget->setItem(row, 0, code);
        ui->tableWidget->setItem(row, 1, name);
        ui->tableWidget->setItem(row, 2, count);

        row++;
    }

}

QString storage::reader(QString *line)
{
    QString temp, st = *line;

    for (int i = 0; !st[i].isSpace() || st[i].isDigit(); i++)
        temp += st[i];

    line->remove(0, temp.size() + 1);

    return temp;
}


void storage::on_pushButton_clicked()
{
    int cur = ui->tableWidget->currentRow();
    QVector<QString> orders;
    QString order;
    int quantity = QInputDialog::getInt(0, "Заказ", "Введите количество: ", QLineEdit::Normal);
    order += ui->tableWidget->item(cur, 0)->text() + " " + ui->tableWidget->item(cur, 1)->text() + " " + QString::number(quantity) + " " + num + '\n';

    QFile file("C:/Kursach/supplier.txt");
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом склада", QMessageBox::Ok);
        QApplication::quit();
    }

    while (!file.atEnd())
        orders.push_back(file.readLine());

    file.close();

    orders.push_back(order);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом поставщика", QMessageBox::Ok);
        QApplication::quit();
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    foreach (order, orders)
        stream << order;

    file.close();
}

void storage::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->pushButton->setEnabled(false);
    if (ui->tableWidget->item(index.row(), 0)->text().toInt() <= 100)
        ui->pushButton->setEnabled(true);
}
