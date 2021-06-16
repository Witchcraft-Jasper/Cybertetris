/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signUp
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *label_4;
    QLineEdit *password2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *log;
    QPushButton *cancel;
    QLabel *sign;

    void setupUi(QWidget *signUp)
    {
        if (signUp->objectName().isEmpty())
            signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->resize(400, 300);
        formLayoutWidget = new QWidget(signUp);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 50, 281, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        name = new QLineEdit(formLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);
        name->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        account = new QLineEdit(formLayoutWidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, account);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setFont(font);
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, password);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        password2 = new QLineEdit(formLayoutWidget);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setFont(font);
        password2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, password2);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        horizontalLayoutWidget = new QWidget(signUp);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(76, 190, 241, 80));
        horizontalLayoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        log = new QPushButton(horizontalLayoutWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setMinimumSize(QSize(0, 50));
        log->setFont(font);

        horizontalLayout->addWidget(log);

        cancel = new QPushButton(horizontalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMinimumSize(QSize(0, 50));
        cancel->setFont(font);

        horizontalLayout->addWidget(cancel);

        sign = new QLabel(signUp);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(130, 20, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        font1.setPointSize(12);
        sign->setFont(font1);

        retranslateUi(signUp);

        QMetaObject::connectSlotsByName(signUp);
    } // setupUi

    void retranslateUi(QWidget *signUp)
    {
        signUp->setWindowTitle(QApplication::translate("signUp", "Form", nullptr));
        label_3->setText(QApplication::translate("signUp", "\346\230\265\347\247\260", nullptr));
        label->setText(QApplication::translate("signUp", "\350\264\246\345\217\267", nullptr));
        label_4->setText(QApplication::translate("signUp", "\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("signUp", "\345\257\206\347\240\201", nullptr));
        log->setText(QApplication::translate("signUp", "\346\263\250\345\206\214", nullptr));
        cancel->setText(QApplication::translate("signUp", "\350\277\224\345\233\236", nullptr));
        sign->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signUp: public Ui_signUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
