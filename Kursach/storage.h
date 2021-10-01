#ifndef STORAGE_H
#define STORAGE_H

#include <QDialog>
#include <QString>

namespace Ui {
class storage;
}

class storage : public QDialog
{
    Q_OBJECT

public:
    explicit storage(QWidget *parent = nullptr);
    ~storage();

private slots:
    void on_changeSt_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::storage *ui;
    QString reader(QString *line);
    QString num;
};

#endif // STORAGE_H
