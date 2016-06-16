#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <server.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static void updateTextBrowser(QString Qtxt);
    ~MainWindow();
    string ip_str;
    string port_str;
    int port_int;
    string dir_str;

private slots:
    void on_stop_button_clicked();

    void on_restart_button_clicked();

    void on_start_button_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
