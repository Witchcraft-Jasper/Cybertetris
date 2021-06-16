/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_H
#define UI_STORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Store
{
public:
    QWidget *centralwidget;
    QFrame *itemGlass1;
    QFrame *itemGlass2;
    QFrame *itemGlass3;
    QFrame *itemGlass4;
    QFrame *itemGlass5;
    QFrame *itemGlass6;
    QLabel *Faces1;
    QLabel *price1;
    QLabel *Faces2;
    QLabel *price2;
    QLabel *Faces3;
    QLabel *price3;
    QLabel *item1;
    QLabel *price4;
    QLabel *label_13;
    QLabel *item2;
    QLabel *price5;
    QLabel *label_16;
    QLabel *item3;
    QLabel *label_18;
    QLabel *price6;
    QLabel *label_9;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *name;
    QLabel *label_3;
    QLabel *coins;

    void setupUi(QMainWindow *Store)
    {
        if (Store->objectName().isEmpty())
            Store->setObjectName(QString::fromUtf8("Store"));
        Store->resize(595, 465);
        centralwidget = new QWidget(Store);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        itemGlass1 = new QFrame(centralwidget);
        itemGlass1->setObjectName(QString::fromUtf8("itemGlass1"));
        itemGlass1->setGeometry(QRect(80, 110, 90, 90));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(itemGlass1->sizePolicy().hasHeightForWidth());
        itemGlass1->setSizePolicy(sizePolicy);
        itemGlass1->setMinimumSize(QSize(90, 90));
        itemGlass1->setMaximumSize(QSize(90, 90));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        itemGlass1->setFont(font);
        itemGlass1->setFrameShape(QFrame::Box);
        itemGlass1->setFrameShadow(QFrame::Raised);
        itemGlass2 = new QFrame(centralwidget);
        itemGlass2->setObjectName(QString::fromUtf8("itemGlass2"));
        itemGlass2->setGeometry(QRect(270, 110, 90, 90));
        sizePolicy.setHeightForWidth(itemGlass2->sizePolicy().hasHeightForWidth());
        itemGlass2->setSizePolicy(sizePolicy);
        itemGlass2->setMinimumSize(QSize(90, 90));
        itemGlass2->setMaximumSize(QSize(90, 90));
        itemGlass2->setFont(font);
        itemGlass2->setFrameShape(QFrame::Box);
        itemGlass2->setFrameShadow(QFrame::Raised);
        itemGlass3 = new QFrame(centralwidget);
        itemGlass3->setObjectName(QString::fromUtf8("itemGlass3"));
        itemGlass3->setGeometry(QRect(450, 110, 90, 90));
        sizePolicy.setHeightForWidth(itemGlass3->sizePolicy().hasHeightForWidth());
        itemGlass3->setSizePolicy(sizePolicy);
        itemGlass3->setMinimumSize(QSize(90, 90));
        itemGlass3->setMaximumSize(QSize(90, 90));
        itemGlass3->setFont(font);
        itemGlass3->setFrameShape(QFrame::Box);
        itemGlass3->setFrameShadow(QFrame::Raised);
        itemGlass4 = new QFrame(centralwidget);
        itemGlass4->setObjectName(QString::fromUtf8("itemGlass4"));
        itemGlass4->setGeometry(QRect(80, 270, 90, 90));
        sizePolicy.setHeightForWidth(itemGlass4->sizePolicy().hasHeightForWidth());
        itemGlass4->setSizePolicy(sizePolicy);
        itemGlass4->setMinimumSize(QSize(90, 90));
        itemGlass4->setMaximumSize(QSize(90, 90));
        itemGlass4->setFont(font);
        itemGlass4->setFrameShape(QFrame::Box);
        itemGlass4->setFrameShadow(QFrame::Raised);
        itemGlass5 = new QFrame(centralwidget);
        itemGlass5->setObjectName(QString::fromUtf8("itemGlass5"));
        itemGlass5->setGeometry(QRect(270, 270, 90, 90));
        sizePolicy.setHeightForWidth(itemGlass5->sizePolicy().hasHeightForWidth());
        itemGlass5->setSizePolicy(sizePolicy);
        itemGlass5->setMinimumSize(QSize(90, 90));
        itemGlass5->setMaximumSize(QSize(90, 90));
        itemGlass5->setFont(font);
        itemGlass5->setFrameShape(QFrame::Box);
        itemGlass5->setFrameShadow(QFrame::Raised);
        itemGlass6 = new QFrame(centralwidget);
        itemGlass6->setObjectName(QString::fromUtf8("itemGlass6"));
        itemGlass6->setGeometry(QRect(450, 270, 90, 90));
        sizePolicy.setHeightForWidth(itemGlass6->sizePolicy().hasHeightForWidth());
        itemGlass6->setSizePolicy(sizePolicy);
        itemGlass6->setMinimumSize(QSize(90, 90));
        itemGlass6->setMaximumSize(QSize(90, 90));
        itemGlass6->setFont(font);
        itemGlass6->setFrameShape(QFrame::Box);
        itemGlass6->setFrameShadow(QFrame::Raised);
        Faces1 = new QLabel(centralwidget);
        Faces1->setObjectName(QString::fromUtf8("Faces1"));
        Faces1->setGeometry(QRect(60, 210, 121, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        font1.setPointSize(11);
        Faces1->setFont(font1);
        Faces1->setAlignment(Qt::AlignCenter);
        price1 = new QLabel(centralwidget);
        price1->setObjectName(QString::fromUtf8("price1"));
        price1->setGeometry(QRect(90, 230, 72, 21));
        price1->setFont(font);
        price1->setAlignment(Qt::AlignCenter);
        Faces2 = new QLabel(centralwidget);
        Faces2->setObjectName(QString::fromUtf8("Faces2"));
        Faces2->setGeometry(QRect(270, 210, 91, 20));
        Faces2->setFont(font1);
        Faces2->setAlignment(Qt::AlignCenter);
        price2 = new QLabel(centralwidget);
        price2->setObjectName(QString::fromUtf8("price2"));
        price2->setGeometry(QRect(280, 230, 72, 21));
        price2->setFont(font);
        price2->setAlignment(Qt::AlignCenter);
        Faces3 = new QLabel(centralwidget);
        Faces3->setObjectName(QString::fromUtf8("Faces3"));
        Faces3->setGeometry(QRect(450, 210, 101, 20));
        Faces3->setFont(font1);
        Faces3->setAlignment(Qt::AlignCenter);
        price3 = new QLabel(centralwidget);
        price3->setObjectName(QString::fromUtf8("price3"));
        price3->setGeometry(QRect(460, 230, 72, 21));
        price3->setFont(font);
        price3->setAlignment(Qt::AlignCenter);
        item1 = new QLabel(centralwidget);
        item1->setObjectName(QString::fromUtf8("item1"));
        item1->setGeometry(QRect(90, 370, 71, 20));
        item1->setFont(font1);
        item1->setAlignment(Qt::AlignCenter);
        price4 = new QLabel(centralwidget);
        price4->setObjectName(QString::fromUtf8("price4"));
        price4->setGeometry(QRect(90, 404, 72, 21));
        price4->setFont(font);
        price4->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(90, 390, 72, 15));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Tetris"));
        font2.setPointSize(8);
        label_13->setFont(font2);
        item2 = new QLabel(centralwidget);
        item2->setObjectName(QString::fromUtf8("item2"));
        item2->setGeometry(QRect(280, 370, 71, 20));
        item2->setFont(font1);
        item2->setAlignment(Qt::AlignCenter);
        price5 = new QLabel(centralwidget);
        price5->setObjectName(QString::fromUtf8("price5"));
        price5->setGeometry(QRect(280, 404, 72, 21));
        price5->setFont(font);
        price5->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(270, 390, 91, 16));
        label_16->setFont(font2);
        item3 = new QLabel(centralwidget);
        item3->setObjectName(QString::fromUtf8("item3"));
        item3->setGeometry(QRect(460, 370, 71, 20));
        item3->setFont(font1);
        item3->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(450, 390, 91, 16));
        label_18->setFont(font2);
        price6 = new QLabel(centralwidget);
        price6->setObjectName(QString::fromUtf8("price6"));
        price6->setGeometry(QRect(460, 404, 72, 21));
        price6->setFont(font);
        price6->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 30, 61, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Tetris"));
        font3.setPointSize(15);
        label_9->setFont(font3);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 111, 46));
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        name = new QLabel(formLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        coins = new QLabel(formLayoutWidget);
        coins->setObjectName(QString::fromUtf8("coins"));
        coins->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, coins);

        Store->setCentralWidget(centralwidget);

        retranslateUi(Store);

        QMetaObject::connectSlotsByName(Store);
    } // setupUi

    void retranslateUi(QMainWindow *Store)
    {
        Store->setWindowTitle(QApplication::translate("Store", "MainWindow", nullptr));
        Faces1->setText(QApplication::translate("Store", "\347\232\256\350\202\244-\345\244\217\346\227\245\347\213\202\346\254\242", nullptr));
        price1->setText(QApplication::translate("Store", "100g", nullptr));
        Faces2->setText(QApplication::translate("Store", "\347\232\256\350\202\244-\347\273\217\345\205\270", nullptr));
        price2->setText(QApplication::translate("Store", "100g", nullptr));
        Faces3->setText(QApplication::translate("Store", "\347\232\256\350\202\244-\346\227\240\346\225\214\346\230\237", nullptr));
        price3->setText(QApplication::translate("Store", "100g", nullptr));
        item1->setText(QApplication::translate("Store", "\351\223\276\345\274\217\345\217\215\345\272\224", nullptr));
        price4->setText(QApplication::translate("Store", "100g", nullptr));
        label_13->setText(QApplication::translate("Store", "(\346\266\210\351\231\244\344\270\200\350\241\214)", nullptr));
        item2->setText(QApplication::translate("Store", "\345\271\270\350\277\220\351\252\260\345\255\220", nullptr));
        price5->setText(QApplication::translate("Store", "100g", nullptr));
        label_16->setText(QApplication::translate("Store", "(\347\224\237\346\210\220\351\232\217\346\234\272\345\275\242\347\212\266)", nullptr));
        item3->setText(QApplication::translate("Store", "\345\205\250\351\235\242\346\211\223\345\207\273", nullptr));
        label_18->setText(QApplication::translate("Store", "(\346\270\205\351\231\244\346\211\200\346\234\211\346\226\271\345\235\227)", nullptr));
        price6->setText(QApplication::translate("Store", "100g", nullptr));
        label_9->setText(QApplication::translate("Store", "\345\225\206\345\237\216", nullptr));
        label->setText(QApplication::translate("Store", "\346\254\242\350\277\216\346\202\250\357\274\214", nullptr));
        name->setText(QApplication::translate("Store", "\346\270\270\345\256\242", nullptr));
        label_3->setText(QApplication::translate("Store", "\351\207\221\345\270\201", nullptr));
        coins->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Store: public Ui_Store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H
