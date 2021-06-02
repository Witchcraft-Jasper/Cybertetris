#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QBrush>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "game.h"
#include "settings.h"
#include "gamesettings.h"
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(int arg1,int arg2,QWidget* parent = 0);
  ~MainWindow();

  int account;
  void defaultShapesColors();
 protected:
  //获取键盘操作
  void keyPressEvent(QKeyEvent* event);

  //进行绘制
  void paintEvent(QPaintEvent*);

  bool eventFilter(QObject *obj, QEvent *event);

 private slots:

  //游戏中的一步(棋子向下移动)
  // +碰撞检查
  //删除满行
  //新形象的出现
  void saveGames();
  void loadGames();
  void gameSettingsStart();
  void gameStep();
  void gameOver();
  void gameExit();
  void showStore();
  void resetTimeLabel();
  void updateData();

 private:
  Ui::MainWindow* ui;
  Game* game; //游戏状态
  Settings settings; // 设置
  QMap<char, QPixmap> pixmap; //图形颜色
  QTimer* timer; //图形移动计时器
  QTimer* gameTimer;//用于显示游戏时长
  QSqlDatabase database;//数据库
  int mode;
  int count;
  int faces;
};

#endif // MAINWINDOW_H
