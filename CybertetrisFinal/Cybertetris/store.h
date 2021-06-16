#ifndef STORE_H
#define STORE_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include <QFrame>
#include <vector>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "game.h"
using namespace std;

namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

public:
    explicit Store(int account, QWidget *parent = nullptr);
    ~Store();
    void defaultShapesColors();
    void updateData(int);
    int account;

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
    QSqlDatabase database;
    int scores;


signals:
    void storeClosed();
    void face(int);
};

#endif // STORE_H
