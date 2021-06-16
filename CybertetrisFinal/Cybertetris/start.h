#ifndef START_H
#define START_H

#include <QMainWindow>

#include "mainwindow.h"
#include "store.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();
    int account;
    void initial();

private slots:

    void on_Normal_clicked();

    void on_Timer_clicked();

    void on_Clean_clicked();

    void on_Store_clicked();

    void on_LogIn_clicked();

    void on_Online_clicked();

    void showLabel();

    void faceChange(int);


private:
    Ui::Start *ui;
    Store* store;
    int faces;
    login* log;
};

#endif // START_H
