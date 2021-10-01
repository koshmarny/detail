#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void signOut();

private slots:
    void on_pushButton_clicked();
    void closeChild();

private:
    Ui::MainWindow *ui;
    void createPanel(QString user);
};

#endif // MAINWINDOW_H
