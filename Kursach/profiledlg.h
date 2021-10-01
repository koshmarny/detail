#ifndef PROFILEDLG_H
#define PROFILEDLG_H

#include <QDialog>

namespace Ui {
class profileDlg;
}

class profileDlg : public QDialog
{
    Q_OBJECT

public:
    explicit profileDlg(QWidget *parent = nullptr);
    ~profileDlg();
    void setUser(QString user, QString name);

signals:
    void testOne();
    void close();

private slots:;


    void on_exitPr_clicked();

private:
    Ui::profileDlg *ui;
};

#endif // PROFILEDLG_H
