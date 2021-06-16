#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QStack>
#include <vector>
#include <random>

const int SIZE = 4;//俄罗斯方块为4x4

//储存俄罗斯方块的形状
struct Shape {
    char name; //名称
    char image[SIZE][SIZE + 1]; //用于储存当前的形状
    int y, x; //坐标

    void rotate() {
        //获取当前形状
        Shape old = *this;

        for(int i = 0; i < SIZE; ++i)
            for(int j = 0; j < SIZE; ++j) {
                // * (0,2) <- (1,0)
                // # (1,1) <- (2,1)
                image[j][SIZE - i - 1] = old.image[i][j];
            }
    }//进行旋转操作
    void couRotate() {
        //获取当前形状
        Shape old = *this;

        for(int i = 0; i < SIZE; ++i)

            for(int j = 0; j < SIZE; ++j) {
                // * (0,2) <- (1,0)
                // # (1,1) <- (2,1)
                image[SIZE - 1 - j][i] = old.image[i][j];
            }
    }//进行反向旋转
};

const int SHAPES_NUM = 7;

const Shape shapes[SHAPES_NUM] = {
    {
        'Z',// Z 型方块
        {
            "    ",
            "##  ",
            " ## ",
            "    ",
        }, 0, 0
    },
    {
        'S',// S 型方块
        {
            "    ",
            " ## ",
            "##  ",
            "    ",
        }, 0, 0
    },
    {
        'L',// L 型方块
        {
            " #  ",
            " #  ",
            " ## ",
            "    ",
        }, 0, 0
    },
    {
        'J',// J 型方块
        {
            "  # ",
            "  # ",
            " ## ",
            "    ",
        }, 0, 0
    },
    {
        'O',// O 型方块
        {
            "    ",
            " ## ",
            " ## ",
            "    ",
        }, 0, 0
    },
    {
        'I',// I 型方块
        {
            " #  ",
            " #  ",
            " #  ",
            " #  ",
        }, 0, 0
    },
    {
        'T',// T 型方块
        {
            "    ",
            "### ",
            " #  ",
            "    ",
        }, 0, 0
    }
};

//当前游戏状态
class Game : public QObject{
    Q_OBJECT

    int h, w; //高度和宽度
    int mode;
    void memAlloc(); //数据转移到堆中
    void memFree(); //当游戏结束时清除记录
    //绘制图形
    void drawCell(int i, int j, char c);

    //检测竖直方向是否形成完整的一列
    void checkFullRows();
    //检测是否形成完整的一行
    void checkFullLines();
    //消除完整的一行

public:
    //获取高度
    int height() {
        return h;
    }
    //获取宽度
    int width() {
        return w;
    }
    bool paused; //游戏是否处于暂停状态
    bool live; // 检测游戏是否结束
    bool setCir;// 检测轮廓是否清除
    int score; //游戏分数
    int lines; //消除的行数
    int level; //游戏的等级
    int timerInterval; //游戏速度
    bool removed;//判断是否消除该块

    char** glass; //内容
    Shape curShape; // 当前形状
    Shape circle;//下降形状
    Shape nextShape;//下一个方块形状
    QStack<Shape> nextShapes;//储存下一组序列
    Game(int width, int height);
    ~Game();


    void removeFullLines(int fromRow, int toRow);
    //绘制图像
    void draw(const Shape& shape);
    // 清除图像
    void erase(const Shape& shape);
    //void eraseCir();
    //形状是否符合
    bool fit(const Shape& shape);

    //能否移动方块
    bool move(int dx, int dy);

    //选择保存游戏时
    void save(QString fileName);
    //选择读取游戏时
    void load(QString fileName);

    void hardDrop();//硬降
    bool getCircle(Shape& shape);
    void drawCircle();//绘制轮廓

    //进行逆时针旋转
    void couRotate();
    //进行顺时针旋转
    void rotate();

    //开始游戏
    void start();
    //进行游戏的每一步
    void step();

    //获取新形状并生成下一个的预告
    void genNextShape();
    void genNextShapes();
signals:
    void signal_send_to_server();
};

#endif // GAME_H
