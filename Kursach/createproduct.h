#ifndef CREATEPRODUCT_H
#define CREATEPRODUCT_H

#include <QDialog>

namespace Ui {
class createProduct;
}

class createProduct : public QDialog
{
    Q_OBJECT

public:
    explicit createProduct(QWidget *parent = nullptr);
    ~createProduct();

private slots:
    void on_comboBox_activated(int index);

    void on_comboSt_activated(int index);

    void on_comboSt_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::createProduct *ui;
    QString reader(QString *line);
    int storage;
    QString cod;
};

#endif // CREATEPRODUCT_H
