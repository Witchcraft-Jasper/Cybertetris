#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    initial();
    faces = 1;
    store = new Store(this);
    connect(store,
            SIGNAL(storeClosed()),
            this,
            SLOT(showLabel()));
    connect(store,SIGNAL(face1()),this,SLOT(faceChange1()));
    connect(store,SIGNAL(face2()),this,SLOT(faceChange2()));
    connect(store,SIGNAL(face3()),this,SLOT(faceChange3()));
}

void Start::faceChange1(){
    faces = 1;
}
void Start::faceChange2(){
    faces = 2;
}
void Start::faceChange3(){
    faces = 3;
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
    ui->Title->setGeometry(80,80,600,100);
    ui->LogIn->setGeometry(130, 230, 150, 50);
    ui->Normal->setGeometry(130, 300, 150, 50);
    ui->Timer->setGeometry(130, 370, 150, 50);
    ui->Clean->setGeometry(130, 440, 150, 50);
    ui->Store->setGeometry(130, 510, 150, 50);
    log = new login;
}

void Start::on_Normal_clicked()
{
    MainWindow* w =  new MainWindow(0,faces);
    w->show();
    account = log->account;
    w->account = account;
    setVisible(false);
}

void Start::on_Timer_clicked()
{
    MainWindow* w =  new MainWindow(1,faces);
    w->show();
    account = log->account;
    w->account = account;
    setVisible(false);
}

void Start::on_LogIn_clicked()
{

    log->show();
}

void Start::on_Clean_clicked()
{
    MainWindow* w =  new MainWindow(2,faces);
    w->show();
    account = log->account;
    w->account = account;
    setVisible(false);
}

void Start::on_Store_clicked()
{
    store->show();
    this->hide();
}

void Start::showLabel()
{
    this->show();
}
