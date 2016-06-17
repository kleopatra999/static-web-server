/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QPushButton *start_button;
    QPushButton *stop_button;
    QPushButton *restart_button;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(326, 355);
        MainWindow->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0.252809 rgba(30, 30, 30, 255), stop:0.837079 rgba(100, 100, 100, 255), stop:0.988764 rgba(4, 4, 4, 255));"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"border-color: rgb(122, 122, 122);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 191, 31));
        QFont font;
        font.setFamily(QStringLiteral("ADMUI3Lg"));
        font.setPointSize(16);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 100, 191, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 160, 191, 31));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 54, 12));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 54, 12));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 54, 12));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 54, 12));
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 220, 291, 101));
        textBrowser->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(240, 40, 61, 31));
        start_button->setStyleSheet(QLatin1String("background-color: rgb(16, 16, 16);\n"
"color: rgb(255, 255, 255);"));
        stop_button = new QPushButton(centralWidget);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(240, 160, 61, 31));
        stop_button->setStyleSheet(QLatin1String("background-color: rgb(16, 16, 16);\n"
"color: rgb(255, 255, 255);"));
        restart_button = new QPushButton(centralWidget);
        restart_button->setObjectName(QStringLiteral("restart_button"));
        restart_button->setGeometry(QRect(240, 100, 61, 31));
        restart_button->setStyleSheet(QLatin1String("background-color: rgb(16, 16, 16);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 326, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WebServer-Kompasim", 0));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "enter an ip", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "enter a port", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "enter a dir", 0));
        label->setText(QApplication::translate("MainWindow", "IP", 0));
        label_2->setText(QApplication::translate("MainWindow", "PORT", 0));
        label_3->setText(QApplication::translate("MainWindow", "DIR", 0));
        label_4->setText(QApplication::translate("MainWindow", "STATUS", 0));
        start_button->setText(QApplication::translate("MainWindow", "STARAT", 0));
        stop_button->setText(QApplication::translate("MainWindow", "STOP", 0));
        restart_button->setText(QApplication::translate("MainWindow", "RESTART", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
