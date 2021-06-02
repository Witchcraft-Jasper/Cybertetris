#ifndef STORE_H
#define STORE_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include <QFrame>
#include <vector>
#include <iostream>
#include "game.h"
using namespace std;

namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
    void defaultShapesColors();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void closeEvent(QCloseEvent* event);
    void paintEvent(QPaintEvent*);

private slots:
    void faceShow();

private:
    vector<QFrame*> frames;
    Ui::Store *ui;
    QTimer* timer;
    QMap<QString, QPixmap> pixmap;
    Game* game;
signals:
    void storeClosed();
    void face1();
    void face2();
    void face3();
};

#endif // STORE_H
