#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QProcess>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "start.h"
#include "store.h"


void MainWindow::defaultShapesColors() {
    pixmap.insert('_', QPixmap()); //无颜色
    pixmap.insert('I', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/I.png"));//青色
    pixmap.insert('J', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/J.png"));//蓝色
    pixmap.insert('L', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/L.png"));//橙色
    pixmap.insert('O', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/O.png"));//黄色
    pixmap.insert('S', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/S.png"));//绿色
    pixmap.insert('T', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/T.png"));//紫色
    pixmap.insert('Z', QPixmap("../Cybertetris/resources/Glasses/" + QString::number(faces) +"/Z.png")); //红色
//    brush.insert('I', QBrush(Qt::cyan));//青色
//    brush.insert('J', QBrush(Qt::blue));//蓝色
//    brush.insert('L', QBrush(QColor("#FF8C00")));//橙色
//    brush.insert('O', QBrush(Qt::yellow));//黄色
//    brush.insert('S', QBrush(Qt::green));//绿色
//    brush.insert('T', QBrush(QColor("#FF00FF")));//紫色
//    brush.insert('Z', QBrush(Qt::red)); //红色
//    brush.insert('p', QBrush(Qt::NoBrush));

}

MainWindow::MainWindow(int arg1,int arg2,QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../Cybertetris/UserDatas.db");
    if(!database.open()){
        cout <<"open failed!\n";
    }else{
        cout <<"open successfully!\n";
    }
    game = new Game(settings.glassWidth(), settings.glassHeight());


    mode = arg1;
    count = 0;
    faces = arg2;
    timer = new QTimer(this);
    gameTimer = new QTimer(this);
    defaultShapesColors();
    //随时间推移执行gamestep
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(gameStep()));
    connect(gameTimer,
            SIGNAL(timeout()),
            this,
            SLOT(resetTimeLabel()));
    connect(ui->saveGame,SIGNAL(triggered()),this,SLOT(saveGames()));
    connect(ui->loadGame,SIGNAL(triggered()),this,SLOT(loadGames()));
    connect(ui->setting,SIGNAL(triggered()),this,SLOT(gameSettingsStart()));
    connect(ui->backMenu,SIGNAL(triggered()),this,SLOT(gameExit()));
    connect(ui->storeMenu,SIGNAL(triggered()),this,SLOT(showStore()));
    ui->item1->installEventFilter(this);
    ui->item2->installEventFilter(this);
    ui->item3->installEventFilter(this);

    game->timerInterval = 500;
    timer->start(game->timerInterval);
    gameTimer->start(1000);

    ui->item1->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/1.png")));
    ui->item2->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/2.png")));
    ui->item3->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/3.png")));
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

void MainWindow::showStore(){
    Store* store = new Store;
    store->show();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->item1)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "Item1";
            for(int i = 0;i < game->width();i++){
                game->glass[game->height() - 1][i] = 'T';
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->item2)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "Item2";
            game->nextShapes.pop();
            //若下个方块列为空则重新生成
            if(game->nextShapes.empty()){
                game->genNextShapes();
            }
            game->nextShape = game->nextShapes.top();
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->item3)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug() << "Item3";
            for(int i = 0;i < game->height();i++)
            for(int j = 0;j < game->width();j++){
                game->glass[i][j] = '_';
            }
            game->genNextShape();
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


void MainWindow::gameExit(){
    if (!(QMessageBox::information(this,tr("提示"),
                                   tr("确定要返回主菜单吗?\n(游戏进度不会被保存)")
                                   ,tr("是"),tr("否"))))
    {
        Start* menu = new Start;
        menu->show();
        setVisible(false);
        //this->close();
    }


}

void MainWindow::saveGames() {
    ui->pause->setText("暂停");
    timer->stop();
    gameTimer->stop();
    game->paused = true;
    QString filename = QFileDialog::getSaveFileName(
                this, "保存存档", "",
                "Save_1 (*.tetris)");

    if(filename.isEmpty())
        return;

    try {
        game->save(filename);
    } catch(QString error) {
        // critical(QWidget * parent, const QString & title,
        // const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)
        QMessageBox::critical(this, "存档失败", error);
    }
    qDebug() << "Game pause";
    ui->pause->setText("");
    timer->start();
    gameTimer->start();
    game->paused = false;
}

void MainWindow::loadGames() {
    ui->pause->setText("暂停");
    timer->stop();
    gameTimer->stop();
    game->paused = true;
    QString filename = QFileDialog::getOpenFileName(
                this, "选择存档", "",
                "Save_1 (*.tetris)");

    try {
        game->load(filename);
    } catch(QString error) {
        QMessageBox::critical(this, "读取存档失败", error);
    }
    qDebug() << "Game pause";
    ui->pause->setText("");
    timer->start();
    gameTimer->start();
    game->paused = false;
    //updateWindow();
}

void MainWindow::gameSettingsStart() {
    GameSettings form(this, settings);
    form.exec();
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
        if(gameTimer->isActive())
            gameTimer->stop();
        else
            gameTimer->start();
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
    updateData();
    if(mode == 1 && ui->TimerShow->intValue() >= 120)
    {
        game->live = false;
    }
    else if(mode == 2 && ui->Lines->text().toInt() >= 3)
    {
        game->live = false;
    }
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

void MainWindow::resetTimeLabel()
{
    count ++;
    if(mode == 1)
        ui->TimerShow->display(120 - count);
    else
        ui->TimerShow->display(count);
}

void MainWindow::gameOver()//游戏结束提示信息
{
    timer->stop();
    //delete timer;
    gameTimer->stop();
    //delete gameTimer;
    if(!(QMessageBox::information(this,
        tr("提示"),
        tr("   游戏结束   "),
        tr("返回主菜单"),tr("重新开始游戏")))){
        Start* menu = new Start;
        menu->show();
        setVisible(false);
        //this->close();
    }else{
        game = new Game(settings.glassWidth(), settings.glassHeight());
        timer = new QTimer(this);
        //随时间推移执行gamestep
        connect(timer,
                SIGNAL(timeout()),
                this,
                SLOT(gameStep()));
        game->timerInterval = 500;
        timer->start(game->timerInterval);
        game->start();
    }
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

//            if(game->glass[i][j] == 'p'){
//                //game->glass[i][j] = '_';
//                color.setAlpha(255);
//            }
//            else if(game->glass[i][j] != '_'){
//                color.setAlpha(255);
//            }else{
//                color.setAlpha(0);
//            }
            if(game->glass[i][j] != '_'){
                p.drawPixmap(QRect(xLeft + j * cellSizeX + cellBorder,yTop + i * cellSizeX + cellBorder,
                             cellSize, cellSize),pixmap[game->glass[i][j]]);
            }

//            p.drawRoundedRect(
//                        QRect(xLeft + j * cellSizeX + cellBorder,
//                              yTop + i * cellSizeX + cellBorder,
//                              cellSize, cellSize), 2, 2);
            //      p.drawRect(
            //        QRect(xLeft + j * cellSizeX + cellBorder,
            //              yTop + i * cellSizeX + cellBorder,
            //              cellSize, cellSize));
        }//绘制每一格子
    QRect g3 = ui->nextShapeGlass->geometry();
    const int xLeftNext = g1.left() + g3.left() + ui->glass->lineWidth() + 1;
    const int yTopNext = g1.top() + g3.top() + ui->glass->lineWidth() + 1;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) {
            //p.setBrush(brush[game->nextShape.name]);
            if(game->nextShape.image[i][j]=='#'){
//                p.drawRoundedRect(
//                            QRect(xLeftNext + j * cellSizeX + cellBorder,
//                                  yTopNext + i * cellSizeX + cellBorder,
//                                  cellSize, cellSize), 2, 2);
                p.drawPixmap(QRect(xLeftNext + j * cellSizeX + cellBorder,yTopNext + i * cellSizeX + cellBorder,
                             cellSize, cellSize),pixmap[game->nextShape.name]);
            }//绘制每一格子
        }
}

void MainWindow::updateData(){
    QSqlQuery query = QSqlQuery(database);
    QString sql = "select * from users";
    if(!query.exec(sql)){
        cout <<"exec failed!\n";
    }
    else {
        while (query.next()) {
            if(query.value(0).toInt() == account){
                ui->name->setText(query.value(2).toString());
                ui->coins->setText(query.value(3).toString());
            }
        }
    }
}


