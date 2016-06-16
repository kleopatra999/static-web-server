#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>

#include <regex>

#include <iostream>

#include <string>
#include <server.h>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_button_clicked()
{
    //start
    qDebug()<<"start button ..........................................................................................";
    //是否是合法的ip
    QString pattern("^(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$");
    QRegExp rx(pattern);
    bool match = rx.exactMatch(QString::fromStdString(ip_str));
    if(match){
        qDebug()<<"ip is legal...";
    }else{
        QMessageBox message(QMessageBox::Warning,"Information","ip is illegal",QMessageBox::Yes,NULL);
        message.exec();
        qDebug()<<"ip is illegal...";
        return ;

    }
    //是否是合法的端口
    if(port_int>=1&&port_int<65536){

        qDebug()<<"port is legal...";
    }else{
        QMessageBox message(QMessageBox::Warning,"Information","port is illegal..",QMessageBox::Yes,NULL);
        message.exec();
        qDebug()<<"port is illegal...";
        return ;
    }
    //是否是合法的目录
    //QFileInfo fi("C:/123");
    QFileInfo fi(QString::fromStdString(dir_str));
    if(fi.isDir()){
        qDebug()<<"dir is legal...";
    }else{
        QMessageBox message(QMessageBox::Warning,"Information","dir is illegal..",QMessageBox::Yes,NULL);
        message.exec();
        qDebug()<<"dir is illegal...";
        return ;
    }
    //实例化server
    Server::start(ip_str,port_int,dir_str);
    //test qmessage box
    QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
    }
    else
    {
        qDebug()<<"clicked no\n";
    }
    //
    qDebug()<<"ip is :"<<QString::fromStdString(ip_str)<<",port is :"<<QString::fromStdString(port_str)<<",dir is :"<<QString::fromStdString(dir_str);

}

void MainWindow::on_stop_button_clicked()
{
    //stop
    QMessageBox message(QMessageBox::Warning,"stop the server","really to stop the web server ?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
        // stop server
        Server::stop();
    }
    else
    {
        qDebug()<<"clicked no\n";
        // do not stop
    }
}

void MainWindow::on_restart_button_clicked()
{
    //restart
    QMessageBox message(QMessageBox::Warning,"stop the server","really to restart the web server ?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
        // restart server
        Server::restart();
    }
    else
    {
        qDebug()<<"clicked no\n";
        // do not restart
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ip_str = arg1.toStdString();
    //ip_str = "11.11.11.11";
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    port_str = arg1.toStdString();
    port_int = atoi(arg1.toStdString().c_str());
    //port_str = "11";
    //port_int = 11;
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    dir_str = arg1.toStdString();
    //dir_str = "E://test";
}
