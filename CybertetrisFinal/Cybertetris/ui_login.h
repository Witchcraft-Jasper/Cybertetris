/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *sign;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *log;
    QPushButton *signUp;
    QPushButton *cancel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *account;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *label;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(400, 300);
        sign = new QLabel(login);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(130, 20, 151, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        font.setPointSize(12);
        sign->setFont(font);
        horizontalLayoutWidget = new QWidget(login);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 180, 291, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        horizontalLayoutWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        log = new QPushButton(horizontalLayoutWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setMinimumSize(QSize(0, 50));
        log->setFont(font1);

        horizontalLayout->addWidget(log);

        signUp = new QPushButton(horizontalLayoutWidget);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setMinimumSize(QSize(0, 50));
        signUp->setFont(font1);

        horizontalLayout->addWidget(signUp);

        cancel = new QPushButton(horizontalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMinimumSize(QSize(0, 50));
        cancel->setFont(font1);

        horizontalLayout->addWidget(cancel);

        formLayoutWidget = new QWidget(login);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 90, 261, 61));
        formLayoutWidget->setFont(font1);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        account = new QLineEdit(formLayoutWidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, account);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setFont(font1);
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, password);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", nullptr));
        sign->setText(QString());
        log->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        signUp->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        cancel->setText(QApplication::translate("login", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QApplication::translate("login", "\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("login", "\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
