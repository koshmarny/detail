#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QDialog>

namespace Ui {
class accounts;
}

class accounts : public QDialog
{
    Q_OBJECT

public:
    explicit accounts(QWidget *parent = nullptr);
    ~accounts();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::accounts *ui;
};

#endif // ACCOUNTS_H
