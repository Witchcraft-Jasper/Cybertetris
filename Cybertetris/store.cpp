#include "store.h"
#include "ui_store.h"
#include "game.h"
#include <QDebug>
#include <QPainter>

Store::Store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    ui->Faces1->installEventFilter(this);
    ui->Faces2->installEventFilter(this);
    ui->Faces3->installEventFilter(this);
    ui->price1->installEventFilter(this);
    ui->price2->installEventFilter(this);
    ui->price3->installEventFilter(this);
    ui->itemGlass1->installEventFilter(this);
    ui->itemGlass2->installEventFilter(this);
    ui->itemGlass3->installEventFilter(this);
    timer = new QTimer(this);
    timer->start(2000);
    game = new Game(0,0);
    game->genNextShape();
    defaultShapesColors();
    frames.push_back(ui->itemGlass1);
    frames.push_back(ui->itemGlass2);
    frames.push_back(ui->itemGlass3);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(faceShow()));

}

Store::~Store()
{
    delete ui;
}

void Store::defaultShapesColors() {
    //pixmap.insert('_', QPixmap()); //无颜色
    for(int i = 1; i <= 3; i++){
        pixmap.insert("I" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/I.png"));//青色
        pixmap.insert("J" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/J.png"));//蓝色
        pixmap.insert("L" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/L.png"));//橙色
        pixmap.insert("O" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/O.png"));//黄色
        pixmap.insert("S" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/S.png"));//绿色
        pixmap.insert("T" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/T.png"));//紫色
        pixmap.insert("Z" + QString::number(i), QPixmap("../Cybertetris/resources/Glasses/" + QString::number(i) +"/Z.png")); //红色
    }
}

void Store::faceShow(){
    timer->setInterval(2000);
    game->genNextShape();
    update();
}


bool Store::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->Faces1 || obj == ui ->itemGlass1 || obj == ui->price1)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "change to face:1";
            emit face1();
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->Faces2 || obj == ui ->itemGlass2 || obj == ui->price2)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "change to face:2";
            emit face2();
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->Faces3 || obj == ui ->itemGlass3 || obj == ui->price3)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "change to face:3";
            emit face3();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}

void Store::paintEvent(QPaintEvent*) {
    QPainter p(this);
    QRect g;
    int xLeftNext;
    int yTopNext;
    for(int k = 1; k <=3; ++k){
        g = frames[k-1]->geometry();
        xLeftNext = g.left() + 4;
        yTopNext = g.top() + 4;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j) {
                //p.setBrush(brush[game->nextShape.name]);
                if(game->curShape.image[i][j]=='#'){
                    p.drawPixmap(QRect(xLeftNext + j * 20 + 1,yTopNext + i * 20 + 1,
                                       20, 20),pixmap[game->nextShape.name + QString::number(k)]);
                }//绘制每一格子
            }
    }
    g = ui->itemGlass4->geometry();
    p.drawPixmap(g,QPixmap("../Cybertetris/resources/items/1.png"));
    g = ui->itemGlass5->geometry();
    p.drawPixmap(g,QPixmap("../Cybertetris/resources/items/2.png"));
    g = ui->itemGlass6->geometry();
    p.drawPixmap(g,QPixmap("../Cybertetris/resources/items/3.png"));
}

void Store::closeEvent(QCloseEvent* event){
    Q_UNUSED(event)
    emit storeClosed();

}
