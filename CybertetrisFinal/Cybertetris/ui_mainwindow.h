/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *saveGame;
    QAction *loadGame;
    QAction *setting;
    QAction *backMenu;
    QAction *storeMenu;
    QWidget *centralwidget;
    QFrame *glass;
    QLabel *pause;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *ScoreLabel;
    QLabel *Score;
    QLabel *LinesLabel;
    QLabel *Lines;
    QLabel *LevelLabel;
    QLabel *Level;
    QLabel *TimerIntervalLabel;
    QLabel *TimerInterval;
    QFrame *nextShapeGlass;
    QLabel *nextShape;
    QLabel *TimerShowLabel;
    QLCDNumber *TimerShow;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *name;
    QLabel *label_3;
    QLabel *coins;
    QLabel *item1;
    QLabel *item2;
    QLabel *item3;
    QFrame *enemyGlass;
    QLabel *pause_2;
    QLabel *music;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *set;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(781, 560);
        saveGame = new QAction(MainWindow);
        saveGame->setObjectName(QString::fromUtf8("saveGame"));
        loadGame = new QAction(MainWindow);
        loadGame->setObjectName(QString::fromUtf8("loadGame"));
        setting = new QAction(MainWindow);
        setting->setObjectName(QString::fromUtf8("setting"));
        backMenu = new QAction(MainWindow);
        backMenu->setObjectName(QString::fromUtf8("backMenu"));
        storeMenu = new QAction(MainWindow);
        storeMenu->setObjectName(QString::fromUtf8("storeMenu"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        glass = new QFrame(centralwidget);
        glass->setObjectName(QString::fromUtf8("glass"));
        glass->setGeometry(QRect(43, 45, 200, 300));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glass->sizePolicy().hasHeightForWidth());
        glass->setSizePolicy(sizePolicy);
        glass->setMinimumSize(QSize(200, 300));
        glass->setMaximumSize(QSize(100, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Tetris"));
        glass->setFont(font);
        glass->setFrameShape(QFrame::Box);
        glass->setFrameShadow(QFrame::Raised);
        pause = new QLabel(glass);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(80, 100, 161, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tetris"));
        font1.setPointSize(24);
        pause->setFont(font1);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(300, 210, 160, 250));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Tetris"));
        font2.setPointSize(16);
        frame->setFont(font2);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(11, -1, -1, -1);
        ScoreLabel = new QLabel(frame);
        ScoreLabel->setObjectName(QString::fromUtf8("ScoreLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Tetris"));
        font3.setPointSize(12);
        ScoreLabel->setFont(font3);
        ScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ScoreLabel);

        Score = new QLabel(frame);
        Score->setObjectName(QString::fromUtf8("Score"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Tetris"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        Score->setFont(font4);
        Score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Score);

        LinesLabel = new QLabel(frame);
        LinesLabel->setObjectName(QString::fromUtf8("LinesLabel"));
        LinesLabel->setFont(font3);
        LinesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LinesLabel);

        Lines = new QLabel(frame);
        Lines->setObjectName(QString::fromUtf8("Lines"));
        Lines->setFont(font4);
        Lines->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Lines);

        LevelLabel = new QLabel(frame);
        LevelLabel->setObjectName(QString::fromUtf8("LevelLabel"));
        LevelLabel->setFont(font3);
        LevelLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LevelLabel);

        Level = new QLabel(frame);
        Level->setObjectName(QString::fromUtf8("Level"));
        Level->setFont(font4);
        Level->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Level);

        TimerIntervalLabel = new QLabel(frame);
        TimerIntervalLabel->setObjectName(QString::fromUtf8("TimerIntervalLabel"));
        TimerIntervalLabel->setFont(font3);
        TimerIntervalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(TimerIntervalLabel);

        TimerInterval = new QLabel(frame);
        TimerInterval->setObjectName(QString::fromUtf8("TimerInterval"));
        TimerInterval->setFont(font4);
        TimerInterval->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(TimerInterval);

        nextShapeGlass = new QFrame(centralwidget);
        nextShapeGlass->setObjectName(QString::fromUtf8("nextShapeGlass"));
        nextShapeGlass->setGeometry(QRect(270, 60, 92, 92));
        sizePolicy.setHeightForWidth(nextShapeGlass->sizePolicy().hasHeightForWidth());
        nextShapeGlass->setSizePolicy(sizePolicy);
        nextShapeGlass->setMinimumSize(QSize(92, 92));
        nextShapeGlass->setMaximumSize(QSize(90, 90));
        nextShapeGlass->setFont(font);
        nextShapeGlass->setFrameShape(QFrame::Box);
        nextShapeGlass->setFrameShadow(QFrame::Raised);
        nextShape = new QLabel(centralwidget);
        nextShape->setObjectName(QString::fromUtf8("nextShape"));
        nextShape->setGeometry(QRect(270, 10, 81, 51));
        nextShape->setFont(font2);
        TimerShowLabel = new QLabel(centralwidget);
        TimerShowLabel->setObjectName(QString::fromUtf8("TimerShowLabel"));
        TimerShowLabel->setGeometry(QRect(390, 20, 91, 32));
        TimerShowLabel->setFont(font2);
        TimerShowLabel->setAlignment(Qt::AlignCenter);
        TimerShow = new QLCDNumber(centralwidget);
        TimerShow->setObjectName(QString::fromUtf8("TimerShow"));
        TimerShow->setGeometry(QRect(380, 60, 101, 91));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Tetris"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        TimerShow->setFont(font5);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(270, 160, 111, 46));
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

        item1 = new QLabel(centralwidget);
        item1->setObjectName(QString::fromUtf8("item1"));
        item1->setGeometry(QRect(300, 470, 41, 41));
        item1->setFont(font);
        item1->setPixmap(QPixmap(QString::fromUtf8("../build-Cybertetris-Desktop_Qt_5_12_MinGW_64_bit-Debug/resources/items/1.png")));
        item1->setScaledContents(true);
        item2 = new QLabel(centralwidget);
        item2->setObjectName(QString::fromUtf8("item2"));
        item2->setGeometry(QRect(360, 470, 41, 41));
        item2->setFont(font);
        item2->setPixmap(QPixmap(QString::fromUtf8("../build-Cybertetris-Desktop_Qt_5_12_MinGW_64_bit-Debug/resources/items/2.png")));
        item2->setScaledContents(true);
        item3 = new QLabel(centralwidget);
        item3->setObjectName(QString::fromUtf8("item3"));
        item3->setGeometry(QRect(420, 470, 41, 41));
        item3->setFont(font);
        item3->setPixmap(QPixmap(QString::fromUtf8("../build-Cybertetris-Desktop_Qt_5_12_MinGW_64_bit-Debug/resources/items/3.png")));
        item3->setScaledContents(true);
        enemyGlass = new QFrame(centralwidget);
        enemyGlass->setObjectName(QString::fromUtf8("enemyGlass"));
        enemyGlass->setGeometry(QRect(540, 40, 200, 300));
        sizePolicy.setHeightForWidth(enemyGlass->sizePolicy().hasHeightForWidth());
        enemyGlass->setSizePolicy(sizePolicy);
        enemyGlass->setMinimumSize(QSize(200, 300));
        enemyGlass->setMaximumSize(QSize(100, 300));
        enemyGlass->setFont(font);
        enemyGlass->setFrameShape(QFrame::Box);
        enemyGlass->setFrameShadow(QFrame::Raised);
        pause_2 = new QLabel(enemyGlass);
        pause_2->setObjectName(QString::fromUtf8("pause_2"));
        pause_2->setGeometry(QRect(80, 100, 161, 81));
        pause_2->setFont(font1);
        music = new QLabel(centralwidget);
        music->setObjectName(QString::fromUtf8("music"));
        music->setGeometry(QRect(410, 160, 41, 41));
        music->setPixmap(QPixmap(QString::fromUtf8("../build-Cybertetris-Desktop_Qt_5_12_MinGW_64_bit-Debug/resources/setting/music1.png")));
        music->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 781, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        set = new QMenu(menubar);
        set->setObjectName(QString::fromUtf8("set"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(set->menuAction());
        menu->addAction(saveGame);
        menu->addAction(loadGame);
        set->addAction(storeMenu);
        set->addAction(setting);
        set->addAction(backMenu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cybertetris", nullptr));
        saveGame->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        loadGame->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", nullptr));
        setting->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\350\256\276\347\275\256", nullptr));
        backMenu->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        storeMenu->setText(QApplication::translate("MainWindow", "\345\225\206\345\237\216", nullptr));
        pause->setText(QString());
        ScoreLabel->setText(QApplication::translate("MainWindow", "\345\210\206\346\225\260", nullptr));
        Score->setText(QApplication::translate("MainWindow", "0", nullptr));
        LinesLabel->setText(QApplication::translate("MainWindow", "\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        Lines->setText(QApplication::translate("MainWindow", "0", nullptr));
        LevelLabel->setText(QApplication::translate("MainWindow", "\347\255\211\347\272\247", nullptr));
        Level->setText(QApplication::translate("MainWindow", "0", nullptr));
        TimerIntervalLabel->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\351\200\237\345\272\246", nullptr));
        TimerInterval->setText(QApplication::translate("MainWindow", "0", nullptr));
        nextShape->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        TimerShowLabel->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\346\202\250\357\274\214", nullptr));
        name->setText(QApplication::translate("MainWindow", "\346\270\270\345\256\242", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\207\221\345\270\201", nullptr));
        coins->setText(QString());
        item1->setText(QString());
        item2->setText(QString());
        item3->setText(QString());
        pause_2->setText(QString());
        music->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        set->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
