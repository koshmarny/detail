#ifndef DISPATCHERPANEL_H
#define DISPATCHERPANEL_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class dispatcherPanel;
}

class dispatcherPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit dispatcherPanel(QWidget *parent = nullptr);
    ~dispatcherPanel();
    QString name, user;
signals:
    void testTwo();

private slots:
    void on_pushButton_clicked();
        void exit();

        void on_storageBut_clicked();

        void on_manBut_clicked();

private:
    Ui::dispatcherPanel *ui;
};

#endif // DISPATCHERPANEL_H
