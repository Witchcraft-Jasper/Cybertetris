#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <cstring>
#include <cassert>
#include "game.h"

using namespace std;

void Game::memAlloc() {
    glass = new char* [h];

    for(int i = 0; i < h; ++i) {
        glass[i] = new char[w + 1];
        memset(glass[i], '_', sizeof(char) * w);//设置为空
        glass[i][w] = 0; //边缘为0
    }
}

void Game::memFree() {
    for(int i = 0; i < h; ++i)
        delete[] glass[i];

    delete[] glass;
    glass = NULL;
}

Game::Game(int width, int height) : w(width), h(height),
    paused(false), level(1),live(true),setCir(true) {
    memAlloc();
}

Game::~Game() {
    memFree();
}

void Game::drawCell(int i, int j, char c) {

    //    如果坐标小于0或大于长宽，不绘制该棋子

    if(i < 0 || j < 0 || i >= h || j >= w)
        return;

    //  对照形状，重新绘制方格颜色
    glass[i][j] = c;
}

void Game::draw(const Shape& shape) {
    //绘制形状
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            if (shape.image[i][j] == '#')
                drawCell(i + shape.y, j + shape.x, shape.name);
}

void Game::erase(const Shape& shape) {
    //绘制空格子
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            if (shape.image[i][j] == '#')
                drawCell(i + shape.y, j + shape.x, '_');
}

//void Game::eraseCir(){
//    for(int i = 0;i < h;i++){
//        for(int j = 0;j < w;j++){
//            if(glass[i][j] == 'p')
//               drawCell(i,j,'_');
//        }
//    }
//}


bool Game::fit(const Shape& shape) {//方块是否越界
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            if (shape.image[i][j] == '#') {
                int y = i + shape.y;
                int x = j + shape.x;

                if(y < 0) continue; //正常情况，无需修正

                //如果向左或者向右越界
                if(x < 0 || x >= w) return false;

                //向下越界
                if(y >= h) return false;

                // 如果该处无空隙
                if(glass[y][x] != '_' && glass[y][x] != 'p')
                    return false;
            }

    return true;
}


void Game::drawCircle(){//绘制轮廓(未完成)
    setCir = true;
    Shape s = curShape;
    s.name = 'p';
    s.y += 4;
    for(int i = 0; i < h; i++){
        //清除当前图像
        //移动图像
        erase(circle);
        s.y += 1;
        circle = s;
        //判断能否移动
        if(!fit(s)){
            s.y -= 1;
            circle = s;
            for(int i = 0; i < SIZE; ++i){
                for(int j = 0; j < SIZE; ++j){
                    if (circle.image[i][j] == '#'){
                        drawCell(i + circle.y, j + circle.x, circle.name);
                    }
                }
            }
        }


    }
}

//保存到文件
void Game::save(QString fileName) {
    QFile f(fileName); //创建文件对象
    f.open(QIODevice::WriteOnly | QIODevice::Text);
    //保存数据
    //if(move(0,1)){
        //move(0,-1);
        erase(curShape);
    //}
    QTextStream out(&f);
    //界面宽度及高度
    out << w << " " << h << endl;

    //循环将所有块输出
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j)
            out << glass[i][j];

        out << endl;
    }

    f.close();
}

// 加载文件
void Game::load(QString fileName) {
    QFile f(fileName);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&f);

    memFree();

    //读取长、宽
    in >> w >> h;
    in.readLine();

    memAlloc();

    for(int i = 0; i < h; ++i) {
        in >> glass[i];
        in.readLine();
    }//读取每一行

    f.close();
}


void Game::hardDrop(){//硬降
    for(int i = 0; i < h; i++){
        if(move(0,1)){
            continue;
        }
    }
}

//控制方块的移动
bool Game::move(int dx, int dy) {
    erase(curShape);
    //清除当前图像
    Shape s = curShape;
    //移动图像
    s.x += dx;
    s.y += dy;
    //判断能否移动
    bool res = fit(s);

    if(res)
        curShape = s;

//    if(circle.y - curShape.y > 4){
//        drawCircle();

//    }else if(!setCir){
//        qDebug() << glass[h - 1];
//        eraseCir();
//        setCir = true;
//        //qDebug() << glass[h-1];
//    }

    draw(curShape);
    //qDebug() << glass[h-1];




    return res;
}

//顺时针旋转方块
void Game::rotate() {
    erase(curShape);
    //获取并清除图像
    Shape s = curShape;
    //旋转图像
    s.rotate();

    //如果旋转后图像上升
    if(fit(s))
        curShape = s;
    //drawCircle();
    draw(curShape);

}

//逆时针旋转方块
void Game::couRotate() {
    erase(curShape);
    //获取并清除图像
    Shape s = curShape;
    //旋转图像
    s.couRotate();

    //如果旋转后图像上升
    if(fit(s))
        curShape = s;
    //drawCircle();
    draw(curShape);

}

void Game::genNextShape() {
    //若下个方块列为空则重新生成
    if(nextShapes.empty()){
        genNextShapes();
        //qDebug() << "Gen new shapes";
    }
    //选择一个随机的形状
    curShape = nextShapes.top();
    nextShapes.pop();
    //若下个方块列为空则重新生成
    if(nextShapes.empty()){
        genNextShapes();
        //qDebug() << "Gen new shapes";
    }
    nextShape = nextShapes.top();
    //qDebug() << nextShape.name;
    //放在中间
    curShape.y = -SIZE;
    curShape.x = w / 2 - SIZE / 2;
    //随机旋转
    int rotations = rand() % 4;

    for(int i = 0; i < rotations; ++i)
        curShape.rotate();

}

void Game::genNextShapes() {
    //生成一个1-7随机排列
    vector<int>a;  //储存所有可能的随机数
    int* randnum = new int[SHAPES_NUM]; //结果序列
    for (int i = 0; i < SHAPES_NUM; i++)
        a.push_back(i); //生成所有可能随机数
    for (int i = 0; i < SHAPES_NUM; i++) {
        int choice = rand() % a.size(); //随机产生下标
        randnum[i] = a[choice];
        swap(a[choice], a[a.size()-1]); //交换已经生成的随机数和数组最后一个数
        a.pop_back();  //删除已经生成的随机数
    }
    //生成下一个tetris序列
    for(int i=0;i<SHAPES_NUM;i++){
        nextShapes.push(shapes[randnum[i]]);
    }
}

// 开始游戏
void Game::start() {
    score = 0;
    lines = 0;
    //生成新形状
    genNextShape();
    //drawCircle();
}

// 游戏的每一步
void Game::step() {
    checkFullRows();
    if(!move(0, +1)) {
        genNextShape();        
        checkFullLines();
        //drawCircle();
    }
}

//消除完整填满的一行
void Game::removeFullLines(int from, int to) {
    assert(to <= from); //断言开始坐标大于结束坐标
    int block = from - to + 1;
    qDebug() << "block:" << block;

    lines += block;
    score += block * level;//加分

    //将剩余行数下移block行
    for(int r = to - 1; r >= 0; r--)
        for(int y = 0; y < w; ++y)
            glass[r + block][y] = glass[r][y];

    //将消除块的那一行清空
    for(int r = block - 1; r >= 0; r--)
        for(int y = 0; y < w; ++y)
            glass[r][y] = '_';

    //设置动态难度
    if(lines%5==0 && lines/5!=0 && level<=6){
        level++;
        timerInterval -= 100;
    }
}

void Game::checkFullRows() {
    int cnt = 0;// cnt记录一行中被填充的个数
    for(int r = 0; r < h; r++) {
      for(int x = 0; x < w; x++)
        if(glass[r][x] != '_')
        {
            cnt++;
            break;
        }
    }
    if(cnt == h)
        live = false;
}

void Game::checkFullLines() {
    int fromRow = -1, toRow = -1; //定义开始行和结束行

    // 从最底部向上看
    for(int r = h - 1; r >= 0; --r) {
        // cnt记录一行中被填充的个数
        int cnt = 0;

        for(int x = 0; x < w; ++x)
            if(glass[r][x] != '_')
                cnt++;

        //如果一行全部被填满
        if(cnt == w) {
            //如果是遍历的第一次
            if(fromRow == -1)
                fromRow = r;

            toRow = r; //将结束行设定为该行行数
        } else {//如果该行无法填满，将之前判断过可以填满的行消除
            if(fromRow != -1 && toRow != -1) {
                removeFullLines(fromRow, toRow);
                return;
            }
        }
    }
}
