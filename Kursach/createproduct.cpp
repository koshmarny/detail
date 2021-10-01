#include "createproduct.h"
#include "ui_createproduct.h"
#include <QFile>
#include <QString>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QVector>
#include <QMessageBox>
#include <QDebug>

createProduct::createProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createProduct)
{
    ui->setupUi(this);

    ui->comboBox->addItem(" ");
    ui->comboSt->addItem(" ");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->hide();

    QFile file;
    for (int i = 0; ;i++)
    {

    file.setFileName(tr("C:/Kursach/product%1.txt").arg(i));
    if (file.exists() && file.open(QFileDevice::ReadOnly))
    {
        ui->comboBox->addItem(file.readLine());
        file.close();
    } else
        break;
    }

    for (int i = 0; ;i++)
    {

    file.setFileName(tr("C:/Kursach/storage%1.txt").arg(i));
    if (file.exists() && file.open(QFileDevice::ReadOnly))
    {
        ui->comboSt->addItem(tr("%1 ----- ").arg(i) + file.readLine());
        file.close();
    } else
        break;
    }
}

createProduct::~createProduct()
{
    delete ui;
}

void createProduct::on_comboBox_activated(int index)
{
    ui->tableWidget->setRowCount(0);

    QFile file(tr("C:/Kursach/product%1.txt").arg(index - 1));
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом изделия", QMessageBox::Ok);
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

    ui->comboSt->setEnabled(true);
    ui->comboSt->setCurrentIndex(0);

}

QString createProduct::reader(QString *line)
{
    QString temp, st = *line;

    for (int i = 0; !st[i].isSpace() || st[i].isDigit(); i++)
        temp += st[i];

    line->remove(0, temp.size() + 1);

    return temp;
}

void createProduct::on_comboSt_activated(int index)
{
    ui->pushButton->setEnabled(true);
    storage = index - 1;
    QFile file(tr("C:/Kursach/storage%1.txt").arg(storage));
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом склада", QMessageBox::Ok);
        QApplication::quit();
    }



    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        file.seek(0);
        file.readLine();

        while (!file.atEnd())
        {
            QString line = file.readLine();
            QString code = reader(&line);

            if (ui->tableWidget->item(i, 0)->text() == code)
            {
                reader(&line);
                QTableWidgetItem *qual = new QTableWidgetItem(reader(&line));

                if (qual->text().toInt() < ui->tableWidget->item(i, 2)->text().toInt())
                {
                    qual->setBackground(Qt::red);
                    ui->pushButton->setEnabled(false);
                }

                ui->tableWidget->setItem(i, 3, qual);
                break;
            }
        }

    }

}

void createProduct::on_pushButton_clicked()
{
    QFile file;

    file.setFileName(tr("C:/Kursach/storage%1.txt").arg(storage));
    if (!file.open(QFileDevice::ReadOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом склада", QMessageBox::Ok);
        QApplication::quit();
    }

    QVector<QString> zip;
    zip.push_back(file.readLine());

    while (!file.atEnd())
    {
        zip.push_back(file.readLine());
        QString temp = zip.back();
        QString buf = reader(&temp);
        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            int count = ui->tableWidget->item(i, 3)->text().toInt() -
                    ui->tableWidget->item(i, 2)->text().toInt();

            if (buf == ui->tableWidget->item(i, 0)->text())
                zip.back() = buf + " " + reader(&temp) + " " + QString::number(count) + '\n';
        }
        QString name = reader(&temp);
        if (buf == cod)
            zip.back() = buf + " " + name + " " + QString::number(reader(&temp).toInt() + 1) + '\n';

    }


    file.close();

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox err;
        err.critical(this, "Ошибка", "Проблема с файлом склада", QMessageBox::Ok);
        QApplication::quit();
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    QString line;

    foreach (line, zip)
        stream << line;

    file.close();
    ui->tableWidget->setRowCount(0);

    QMessageBox h;
    h.setText(tr("Деталь изготовлена!"));
    h.exec();
}

void createProduct::on_comboBox_activated(const QString &arg1)
{
    cod = arg1;
    cod = reader(&cod);
}
