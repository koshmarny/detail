#ifndef ORDER_H
#define ORDER_H

#include <QDialog>

namespace Ui {
class order;
}

class order : public QDialog
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
    ~order();

private slots:
    void on_pushButton_clicked();

private:
    Ui::order *ui;
};

#endif // ORDER_H
