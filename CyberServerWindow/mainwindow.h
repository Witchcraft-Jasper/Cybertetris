#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "mytcpsocket.h"
#include "myserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MyServer *ser;
private slots:
    void slot_updata(QString);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
