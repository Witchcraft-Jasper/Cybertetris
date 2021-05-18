#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::defaultShapesColors() {
    brush.insert('_', QBrush(Qt::NoBrush)); //无颜色
    brush.insert('I', QBrush(Qt::cyan));//青色
    brush.insert('J', QBrush(Qt::blue));//蓝色
    brush.insert('L', QBrush(QColor("#FF8C00")));//橙色
    brush.insert('O', QBrush(Qt::yellow));//黄色
    brush.insert('S', QBrush(Qt::green));//绿色
    brush.insert('T', QBrush(QColor("#FF00FF")));//紫色
    brush.insert('Z', QBrush(Qt::red)); //红色
    brush.insert('p', QBrush(Qt::NoBrush));
}

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    game = new Game(settings.glassWidth(), settings.glassHeight());

    defaultShapesColors();

    timer = new QTimer(this);
    //随时间推移执行gamestep
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(gameStep()));
    game->timerInterval = 500;
    timer->start(game->timerInterval);

    QSize glassSize = ui->glass->maximumSize();
    int borders = 2 * ui->glass->lineWidth() + 4;
    glassSize.setWidth(game->width() * settings.cellSizeX() + borders);
    glassSize.setHeight(game->height() * settings.cellSizeX() + borders);
    ui->glass->setMinimumSize(glassSize);
    ui->glass->setMaximumSize(glassSize);

    game->start();
}

MainWindow::~MainWindow() {
    delete game;
    delete ui;
}


//键盘监听
void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left: //向左移动
        qDebug() << "Left";
        game->move(-1, 0);
        update();
        break;

    case Qt::Key_Right: //向右移动
        qDebug() << "Right";
        game->move(+1, 0);
        update();
        break;

    case Qt::Key_Down: //软降
        qDebug() << "Down - landed figure";
        game->move(0, +1);
        update();
        break;

    case Qt::Key_Up: //硬降
        qDebug() << "Up - hardDrop";
        game->hardDrop();
        update();
        break;

    case Qt::Key_C: //旋转
        qDebug() << "C - clockwiseRotate";
        game->rotate();
        update();
        break;

    case Qt::Key_Z: //旋转
        qDebug() << "Z - counterclockwiseRotate";
        game->couRotate();
        update();
        break;

    case Qt::Key_Space: //游戏暂停
        if(game->paused) {
            qDebug() << "Resume the game";
            ui->pause->setText("");
            timer->start();
            game->paused = false;
        } else {
            qDebug() << "Game pause";
            ui->pause->setText("暂停");
            timer->stop();
            game->paused = true;
        }

        break;
    }

    //循环调用
    QMainWindow::keyPressEvent(event);
}

void MainWindow::gameStep() {
    //每当有块落地时执行的函数
    //进行碰撞检测
    //将完全连成的行消除
    //生成新形状
    if(game->live == false){
        qDebug() << "Game Over";
        gameOver();
    }//判断游戏是否结束
    game->step();

    //更新游戏统计：计数，行数
    ui->Score->setText(QString("%1").arg(game->score));
    ui->Lines->setText(QString("%1").arg(game->lines));
    ui->Level->setText(QString("%1").arg(game->level));
    ui->TimerInterval->setText(QString("%1").arg((1000 - game->timerInterval)/10));
    //更新计时器周期
    timer->setInterval(game->timerInterval);

    //重新绘制
    update();
}

void MainWindow::gameOver()//游戏结束提示信息
{
    timer->stop();
    delete timer;
    QMessageBox::information(this,
        tr("提示"),
        tr("游戏结束"),
        QMessageBox::Ok | QMessageBox::Cancel
        );
}

//绘制场地
void MainWindow::paintEvent(QPaintEvent*) {
    QPainter p(this);

    const int cellBorder = settings.cellBorder();
    const int cellSize = settings.cellSize();
    const int cellSizeX = settings.cellSizeX();

    QRect g1 = ui->centralwidget->geometry();
    QRect g2 = ui->glass->geometry();
    const int xLeft = g1.left() + g2.left() + ui->glass->lineWidth() + 1;
    const int yTop = g1.top() + g2.top() + ui->glass->lineWidth() + 1;

    //绘制框架
    p.drawRect(QRect(xLeft, yTop,
                     game->width() * cellSizeX,
                     game->height() * cellSizeX));
    QColor color(Qt::black);
    color.setAlpha(0);

    for(int i = 0; i < game->height(); ++i)
        for(int j = 0; j < game->width(); ++j) {

            if(game->glass[i][j] == 'p'){
                //game->glass[i][j] = '_';
                color.setAlpha(255);
            }
            else if(game->glass[i][j] != '_'){
                color.setAlpha(255);
            }else{
                color.setAlpha(0);
            }
            QPen pen;
            pen.setColor(color);
            p.setPen(pen);

            p.setBrush(brush[game->glass[i][j]]);
            p.drawRoundedRect(
                        QRect(xLeft + j * cellSizeX + cellBorder,
                              yTop + i * cellSizeX + cellBorder,
                              cellSize, cellSize), 2, 2);
            //      p.drawRect(
            //        QRect(xLeft + j * cellSizeX + cellBorder,
            //              yTop + i * cellSizeX + cellBorder,
            //              cellSize, cellSize));
        }//绘制每一格子
    QRect g3 = ui->nextShapeGlass->geometry();
    const int xLeftNext = g1.left() + g3.left() + ui->glass->lineWidth() + 1;
    const int yTopNext = g1.top() + g3.top() + ui->glass->lineWidth() + 1;
    color.setAlpha(255);
    QPen pen;
    pen.setColor(color);
    p.setPen(pen);
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) {
            p.setBrush(brush[game->nextShape.name]);
            if(game->nextShape.image[i][j]=='#'){
                p.drawRoundedRect(
                            QRect(xLeftNext + j * cellSizeX + cellBorder,
                                  yTopNext + i * cellSizeX + cellBorder,
                                  cellSize, cellSize), 2, 2);
            }//绘制每一格子
        }
}


