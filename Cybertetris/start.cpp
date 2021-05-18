#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    initial();
}

Start::~Start()
{
    delete ui;
}

void Start::initial()//初始化
{
    setFixedSize(400, 600);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Background, QColor(255,250,240));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    ui->label->setGeometry(80,80,600,100);
    ui->startgame->setGeometry(130, 300, 150, 50);
    ui->pushButton->setGeometry(130, 370, 150, 50);
    ui->pushButton_2->setGeometry(130, 440, 150, 50);
}

void Start::on_startgame_clicked()
{
    setVisible(false);
    MainWindow* w =  new MainWindow;
    w->show();
}
