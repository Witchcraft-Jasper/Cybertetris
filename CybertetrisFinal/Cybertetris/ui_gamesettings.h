/********************************************************************************
** Form generated from reading UI file 'gamesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESETTINGS_H
#define UI_GAMESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameSettings
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *glassHeightLabel;
    QSpinBox *glassHeight;
    QSpinBox *glassWidth;
    QLabel *glassWidthLabel;
    QLabel *cellSizeLabel;
    QSpinBox *cellSize;
    QLabel *cellBorderLabel;
    QSpinBox *cellBorder;

    void setupUi(QDialog *GameSettings)
    {
        if (GameSettings->objectName().isEmpty())
            GameSettings->setObjectName(QString::fromUtf8("GameSettings"));
        GameSettings->resize(214, 231);
        buttonBox = new QDialogButtonBox(GameSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 181, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(GameSettings);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 181, 141));
        layoutWidget->setFont(font);
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        glassHeightLabel = new QLabel(layoutWidget);
        glassHeightLabel->setObjectName(QString::fromUtf8("glassHeightLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        font1.setPointSize(11);
        glassHeightLabel->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, glassHeightLabel);

        glassHeight = new QSpinBox(layoutWidget);
        glassHeight->setObjectName(QString::fromUtf8("glassHeight"));
        glassHeight->setFont(font);
        glassHeight->setLayoutDirection(Qt::LeftToRight);
        glassHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        glassHeight->setMinimum(18);
        glassHeight->setMaximum(22);

        formLayout->setWidget(0, QFormLayout::FieldRole, glassHeight);

        glassWidth = new QSpinBox(layoutWidget);
        glassWidth->setObjectName(QString::fromUtf8("glassWidth"));
        glassWidth->setFont(font);
        glassWidth->setLayoutDirection(Qt::LeftToRight);
        glassWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        glassWidth->setMinimum(8);
        glassWidth->setMaximum(12);

        formLayout->setWidget(1, QFormLayout::FieldRole, glassWidth);

        glassWidthLabel = new QLabel(layoutWidget);
        glassWidthLabel->setObjectName(QString::fromUtf8("glassWidthLabel"));
        glassWidthLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, glassWidthLabel);

        cellSizeLabel = new QLabel(layoutWidget);
        cellSizeLabel->setObjectName(QString::fromUtf8("cellSizeLabel"));
        cellSizeLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, cellSizeLabel);

        cellSize = new QSpinBox(layoutWidget);
        cellSize->setObjectName(QString::fromUtf8("cellSize"));
        cellSize->setFont(font);
        cellSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cellSize->setMinimum(15);
        cellSize->setMaximum(21);

        formLayout->setWidget(2, QFormLayout::FieldRole, cellSize);

        cellBorderLabel = new QLabel(layoutWidget);
        cellBorderLabel->setObjectName(QString::fromUtf8("cellBorderLabel"));
        cellBorderLabel->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, cellBorderLabel);

        cellBorder = new QSpinBox(layoutWidget);
        cellBorder->setObjectName(QString::fromUtf8("cellBorder"));
        cellBorder->setFont(font);
        cellBorder->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cellBorder->setMaximum(2);

        formLayout->setWidget(3, QFormLayout::FieldRole, cellBorder);


        retranslateUi(GameSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), GameSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GameSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(GameSettings);
    } // setupUi

    void retranslateUi(QDialog *GameSettings)
    {
        GameSettings->setWindowTitle(QApplication::translate("GameSettings", "Dialog", nullptr));
        glassHeightLabel->setText(QApplication::translate("GameSettings", "\347\225\214\351\235\242\351\253\230\345\272\246", nullptr));
        glassWidthLabel->setText(QApplication::translate("GameSettings", "\347\225\214\351\235\242\345\256\275\345\272\246", nullptr));
        cellSizeLabel->setText(QApplication::translate("GameSettings", "\346\226\271\345\235\227\345\244\247\345\260\217", nullptr));
        cellBorderLabel->setText(QApplication::translate("GameSettings", "\346\226\271\345\235\227\351\227\264\351\232\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameSettings: public Ui_GameSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESETTINGS_H
