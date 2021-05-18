#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QBrush>
#include "game.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void defaultShapesColors();
 protected:
  //获取键盘操作
  void keyPressEvent(QKeyEvent* event);

  //进行绘制
  void paintEvent(QPaintEvent*);

 private slots:

  //游戏中的一步(棋子向下移动)
  // +碰撞检查
  //删除满行
  //新形象的出现
  void gameStep();
  void gameOver();

 private:
  Ui::MainWindow* ui;
  Game* game; //游戏状态
  Settings settings; // 设置
  QMap<char, QBrush> brush; //图形颜色
  QTimer* timer; //图形移动计时器
};

#endif // MAINWINDOW_H
