#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class adminPanel;
}

class adminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminPanel(QWidget *parent = nullptr);
    ~adminPanel();
    QString name, user;
signals:
    void testTwo();

private slots:
    void on_pushButton_clicked();
    void exit();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::adminPanel *ui;
};

#endif // ADMINPANEL_H
