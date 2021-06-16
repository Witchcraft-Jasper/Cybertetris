#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QProcess>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
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

}

MainWindow::MainWindow(int arg1,int arg2,int arg3, QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("Cybertetris");
    setWindowIcon(QIcon(":/new/prefix1/resources/background/start.jpg"));
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/new/prefix1/resources/background/play.jpg")));
    setPalette(pal);

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../Cybertetris/UserDatas.db");
    if(!database.open()){
        cout <<"open failed!\n";
    }else{
        cout <<"open successfully!\n";
    }
    game = new Game(settings.glassWidth(), settings.glassHeight());
    eGlass = new char* [settings.glassHeight()];
    for(int i = 0; i < settings.glassHeight(); ++i) {
        eGlass[i] = new char[settings.glassWidth() + 1];
        memset(eGlass[i], '_', sizeof(char) * settings.glassWidth());//设置为空
        eGlass[i][settings.glassWidth()] = 0; //边缘为0
    }
    account = arg3;
    QSqlQuery query = QSqlQuery(database);
    QString sql = "select * from users";
    scores = 0;
    if(!query.exec(sql)){
        cout <<"exec failed!\n";
    }
    else {
        while (query.next()) {
            if(query.value(0).toInt() == account){
                scores = query.value(3).toInt();
                break;
            }
        }
    }
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

    if(mode == 3)
    {
        tcp = new MyTcpSocket;
        tcp->connectToHost("127.0.0.1",8888);
        connect(tcp,SIGNAL(updateMainWindow(QString)),this,SLOT(slotreceive(QString)));
        connect(game,SIGNAL(signal_send_to_server()),this,SLOT(slot_send_to_server()));
    }else{
        setFixedSize(510,560);
    }//是否为对战模式

    ui->item1->installEventFilter(this);
    ui->item2->installEventFilter(this);
    ui->item3->installEventFilter(this);
    ui->music->installEventFilter(this);

    game->timerInterval = 500;
    timer->start(game->timerInterval);
    gameTimer->start(1000);

    ui->item1->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/1.png")));
    ui->item2->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/2.png")));
    ui->item3->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/items/3.png")));
    ui->music->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/setting/music1.png")));
    QSize glassSize = ui->glass->maximumSize();
    int borders = 2 * ui->glass->lineWidth() + 4;
    glassSize.setWidth(game->width() * settings.cellSizeX() + borders);
    glassSize.setHeight(game->height() * settings.cellSizeX() + borders);
    ui->glass->setMinimumSize(glassSize);
    ui->glass->setMaximumSize(glassSize);

    player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile("./resources/music/background.wav"));
    player->setVolume(80);
    player->setLoopCount(QSoundEffect::Infinite);
    player->play();
    music = true;
    game->start();
    if(mode == 3){
        ui->pause->setText("等待");
        timer->stop();
        gameTimer->stop();
        game->paused = true;
    }
}

MainWindow::~MainWindow() {
    delete game;
    delete ui;
}

void MainWindow::showStore(){
    Store* store = new Store(account,this);
    store->show();
    connect(store,SIGNAL(face(int)),this,SLOT(faceChange(int)));
}

void MainWindow::faceChange(int a){
    faces = a;
    pixmap.clear();
    defaultShapesColors();
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
            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->item1,"geometry");
            animation1->setDuration(100);
            animation1->setKeyValueAt(0, QRect(300,470,41,41));
            animation1->setKeyValueAt(0.5, QRect(297,447,50,50));
            animation1->setKeyValueAt(1, QRect(300,470,41,41));
            animation1->setEasingCurve(QEasingCurve::InOutCirc);

            animation1->start();
            bounce();
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

            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->item2,"geometry");
            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->nextShapeGlass,"geometry");
            animation1->setDuration(100);
            animation1->setKeyValueAt(0, QRect(360,470,41,41));
            animation1->setKeyValueAt(0.5, QRect(357,447,50,50));
            animation1->setKeyValueAt(1, QRect(360,470,41,41));
            animation1->setEasingCurve(QEasingCurve::InOutCirc);
            animation2->setDuration(200);
            animation2->setKeyValueAt(0, QRect(270,60,92,92));
            animation2->setKeyValueAt(0.5, QRect(270,70,92,92));
            animation2->setKeyValueAt(1, QRect(270,60,92,92));
            animation2->setEasingCurve(QEasingCurve::InOutCirc);

            QParallelAnimationGroup *group = new QParallelAnimationGroup;
            group->addAnimation(animation1);
            group->addAnimation(animation2);

            group->start();

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
            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->item3,"geometry");
            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->glass,"geometry");
            animation1->setDuration(100);
            animation1->setKeyValueAt(0, QRect(420,470,41,41));
            animation1->setKeyValueAt(0.5, QRect(417,447,50,50));
            animation1->setKeyValueAt(1, QRect(420,470,41,41));
            animation1->setEasingCurve(QEasingCurve::InOutCirc);
            animation2->setDuration(200);
            animation2->setKeyValueAt(0, QRect(43,45,200,300));
            animation2->setKeyValueAt(0.5, QRect(43,35,200,300));
            animation2->setKeyValueAt(1, QRect(43,45,200,300));
            animation2->setEasingCurve(QEasingCurve::InOutCirc);

            QParallelAnimationGroup *group = new QParallelAnimationGroup;
            group->addAnimation(animation1);
            group->addAnimation(animation2);

            group->start();
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->music)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            if(music){
                player->setVolume(0);
                ui->music->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/setting/music2.png")));
                music = false;
                qDebug() << "music-off";
            }else{
                player->setVolume(80);
                ui->music->setPixmap(QPixmap(QString::fromUtf8("../Cybertetris/resources/setting/music1.png")));
                music = true;
                qDebug() << "music-on";
            }
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
        this->close();
    }


}

void MainWindow::saveGames() {
    ui->pause->setText("暂停");
    timer->stop();
    gameTimer->stop();
    game->paused = true;
    player->setVolume(0);
    music = false;
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
    player->setVolume(80);
    music = true;
}

void MainWindow::loadGames() {
    ui->pause->setText("暂停");
    timer->stop();
    gameTimer->stop();
    game->paused = true;
    player->setVolume(0);
    music = false;
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
    player->setVolume(80);
    music = true;
    //updateWindow();
}

void MainWindow::gameSettingsStart() {
    GameSettings form(this, settings);
    form.exec();
}

void MainWindow::bounce(){//游戏动画
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->glass,"geometry");
    animation1->setDuration(300);
    animation1->setKeyValueAt(0, QRect(43, 45, 161, 81));
    animation1->setKeyValueAt(0.5, QRect(43, 50, 161, 81));
    animation1->setKeyValueAt(1, QRect(43, 45, 161, 81));
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    animation1->start();
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
        bounce();
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
            player->setVolume(80);
            music = true;
        } else {
            qDebug() << "Game pause";
            ui->pause->setText("暂停");
            timer->stop();
            game->paused = true;
            player->setVolume(0);
            music = false;
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

QString MainWindow::glassToString(){
    QString datas = "";
    for(int i = 0; i < game->height(); ++i) {
        for(int j = 0; j < game->width(); ++j)
            datas.append(game->glass[i][j]);
    }
    return datas;
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
        if(mode != 3){
            gameOver(0);
        }else gameOver(2);
        player->setVolume(0);
    }//判断游戏是否结束
    game->step();

    if(game->removed){
        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->Score,"size");
        QPropertyAnimation *animation2 = new QPropertyAnimation(ui->Lines,"size");
        animation1->setDuration(300);
        animation1->setKeyValueAt(0, QSize(134, 24));
        animation1->setKeyValueAt(0.5, QSize(134, 70));
        animation1->setKeyValueAt(1, QSize(134, 24));
        animation1->setEasingCurve(QEasingCurve::OutBounce);
        animation2->setDuration(300);
        animation2->setKeyValueAt(0, QSize(134, 24));
        animation2->setKeyValueAt(0.5, QSize(134, 70));
        animation2->setKeyValueAt(1, QSize(134, 24));
        animation2->setEasingCurve(QEasingCurve::OutBounce);

        QParallelAnimationGroup *group = new QParallelAnimationGroup;
        group->addAnimation(animation1);
        group->addAnimation(animation2);

        group->start();
    }//播放动画

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

void MainWindow::gameOver(int kind)//游戏结束提示信息
{
    timer->stop();
    gameTimer->stop();
    QSoundEffect *player= new QSoundEffect;
    player->setSource(QUrl::fromLocalFile("./resources/music/gameover.wav"));
    player->setVolume(50);
    player->play();
    if(kind == 0){
        if(!(QMessageBox::information(this,
                                      tr("提示"),
                                      tr("   游戏结束   "),
                                      tr("返回主菜单"),tr("重新开始游戏")))){
            player->stop();
            emit windowClosed();
            timer->stop();
            this->close();
        }else{
            count = 0;
            delete game;
            game = new Game(settings.glassWidth(), settings.glassHeight());
            timer = new QTimer(this);
            gameTimer = new QTimer(this);
            //随时间推移执行gamestep
            connect(timer,
                    SIGNAL(timeout()),
                    this,
                    SLOT(gameStep()));
            connect(gameTimer,
                    SIGNAL(timeout()),
                    this,
                    SLOT(resetTimeLabel()));
            game->timerInterval = 500;
            timer->start(game->timerInterval);
            gameTimer->start(1000);
            game->start();
        }
    }else if(kind == 1){
        if(!(QMessageBox::information(this,
                                      tr("提示"),
                                      tr(" YOU   WIN "),
                                      tr("返回主菜单")))){
            this->close();
        }
    }else{
        if(!(QMessageBox::information(this,
                                      tr("提示"),
                                      tr(" YOU   LOSE "),
                                      tr("返回主菜单")))){
            this->close();
        }
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
    ui->glass->setFixedSize(game->width() * cellSizeX + 4,game->height() * cellSizeX + 4);
    for(int i = 0; i < game->height(); ++i)
        for(int j = 0; j < game->width(); ++j) {
            if(game->glass[i][j] != '_'){
                p.drawPixmap(QRect(xLeft + j * cellSizeX + cellBorder,yTop + i * cellSizeX + cellBorder,
                             cellSize, cellSize),pixmap[game->glass[i][j]]);
            }
        }//绘制每一格子
    QRect g3 = ui->nextShapeGlass->geometry();
    const int xLeftNext = g1.left() + g3.left() + ui->glass->lineWidth() + 1;
    const int yTopNext = g1.top() + g3.top() + ui->glass->lineWidth() + 1;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) {
            if(game->nextShape.image[i][j]=='#'){

                p.drawPixmap(QRect(xLeftNext + j * cellSizeX + cellBorder,yTopNext + i * cellSizeX + cellBorder,
                             cellSize, cellSize),pixmap[game->nextShape.name]);
            }//绘制每一格子
        }
    ui->enemyGlass->setFixedSize(game->width() * cellSizeX + 4,game->height() * cellSizeX + 4);
    QRect g4 = ui->enemyGlass->geometry();
    const int a = g1.left() + g4.left() + ui->glass->lineWidth() + 1;
    const int b = g1.top() + g4.top() + ui->glass->lineWidth() + 1;
    p.drawRect(QRect(a, b,
                     game->width() * cellSizeX,
                     game->height() * cellSizeX));
    for(int i = 0; i < game->height(); ++i)
        for(int j = 0; j < game->width(); ++j) {
            if(eGlass[i][j] != '_'){
                p.drawPixmap(QRect(a + j * cellSizeX + cellBorder,b + i * cellSizeX + cellBorder,
                             cellSize, cellSize),pixmap[eGlass[i][j]]);
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
                sql = QString("UPDATE `users` SET `coins` = '%1' WHERE (`name` = '%2')")
                        .arg(QString::number(scores + game->score) ,ui->name->text());
                ui->name->setText(query.value(2).toString());
                ui->coins->setText(query.value(3).toString());
                query.clear();
                query.exec(sql);
                break;
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent* event){
    Q_UNUSED(event)
    player->stop();
    emit windowClosed();
    timer->stop();

}

void MainWindow::slotreceive(QString glass)
{
    qDebug() << "glass";
    qDebug() << glass;
    if(glass == "EXIT"){
        gameOver(1);
        game->live = false;
        player->setVolume(0);
        qDebug() << "HHHHHHHOOOOOOOOO";
    }else if(glass == "START"){
        ui->pause->setText("");
        timer->start();
        gameTimer->start();
        game->paused = false;
        return;
    }else if(glass == "WAIT"){
        return;
    }
    char*  ch;
    QByteArray ba = glass.toLatin1();
    ch=ba.data();
    int k = 0;
    for(int i = 0; i < game->height(); ++i)
        for(int j = 0; j < game->width(); ++j) {

            eGlass[i][j] = ch[k];
            k++;
        }
}

void MainWindow::slot_send_to_server()
{
    if(game->live == false){
        tcp->write("EXIT");
    }
    else tcp->write(glassToString().toStdString().c_str());
}


