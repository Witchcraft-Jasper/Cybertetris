#ifndef START_H
#define START_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();
    void initial();

private slots:
    void on_startgame_clicked();

private:
    Ui::Start *ui;
};

#endif // START_H
