#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ser = new MyServer();

    connect(ser,SIGNAL(updateServer(QString)),this,SLOT(slot_updata(QString)));
}

void MainWindow::slot_updata(QString str)
{
    ui->textBrowser->append(str);
}


MainWindow::~MainWindow()
{
    delete ui;
}

