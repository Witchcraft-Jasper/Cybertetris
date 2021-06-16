/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QWidget *centralwidget;
    QPushButton *Clean;
    QPushButton *Normal;
    QPushButton *Timer;
    QPushButton *Store;
    QPushButton *LogIn;
    QPushButton *Online;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QString::fromUtf8("Start"));
        Start->resize(560, 600);
        centralwidget = new QWidget(Start);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Clean = new QPushButton(centralwidget);
        Clean->setObjectName(QString::fromUtf8("Clean"));
        Clean->setGeometry(QRect(420, 280, 91, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        Clean->setFont(font);
        Normal = new QPushButton(centralwidget);
        Normal->setObjectName(QString::fromUtf8("Normal"));
        Normal->setGeometry(QRect(170, 280, 111, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        font1.setPointSize(9);
        Normal->setFont(font1);
        Timer = new QPushButton(centralwidget);
        Timer->setObjectName(QString::fromUtf8("Timer"));
        Timer->setGeometry(QRect(300, 280, 91, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Tetris"));
        font3.setPointSize(10);
        Timer->setFont(font3);
        Store = new QPushButton(centralwidget);
        Store->setObjectName(QString::fromUtf8("Store"));
        Store->setGeometry(QRect(30, 280, 111, 41));
        Store->setFont(font1);
        LogIn = new QPushButton(centralwidget);
        LogIn->setObjectName(QString::fromUtf8("LogIn"));
        LogIn->setGeometry(QRect(30, 220, 111, 41));
        LogIn->setFont(font1);
        Online = new QPushButton(centralwidget);
        Online->setObjectName(QString::fromUtf8("Online"));
        Online->setGeometry(QRect(40, 350, 91, 41));
        Online->setFont(font);
        Start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Start);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 560, 25));
        Start->setMenuBar(menubar);
        statusbar = new QStatusBar(Start);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Start->setStatusBar(statusbar);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QMainWindow *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "MainWindow", nullptr));
        Clean->setText(QApplication::translate("Start", "Clean mode", nullptr));
        Normal->setText(QApplication::translate("Start", "Normal mode", nullptr));
        Timer->setText(QApplication::translate("Start", "Timer mode", nullptr));
        Store->setText(QApplication::translate("Start", "Store", nullptr));
        LogIn->setText(QApplication::translate("Start", "Log in", nullptr));
        Online->setText(QApplication::translate("Start", "Online mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
