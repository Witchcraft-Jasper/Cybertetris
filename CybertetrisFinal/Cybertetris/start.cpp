#include "start.h"
#include "ui_start.h"


Start::Start( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    initial();
    faces = 1;
}

void Start::faceChange(int a){
    faces = a;
}


Start::~Start()
{
    delete ui;
}

void Start::initial()//初始化
{
    setWindowTitle("Cybertetris");
    setWindowIcon(QIcon(":/new/prefix1/resources/background/start.jpg"));
    setFixedSize(1300, 732);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/new/prefix1/resources/background/start.jpg")));
    setPalette(pal);


//        ui->LogIn->setGeometry(130, 230, 150, 50);
//        ui->Normal->setGeometry(130, 300, 150, 50);
//        ui->Timer->setGeometry(130, 370, 150, 50);
//        ui->Clean->setGeometry(130, 440, 150, 50);
//        ui->Online->setGeometry(130, 510, 150, 50);
//        ui->Store->setGeometry(130, 580, 150, 50);

    QIcon ico1(":/new/prefix1/resources/background/login.png");
    ui->LogIn->setIcon(ico1);
    ui->LogIn->setText("");
    ui->LogIn->setFlat(true);
    ui->LogIn->setIconSize(QSize(50,156));
    ui->LogIn->setGeometry(800,320,50,156);

    QIcon ico2(":/new/prefix1/resources/background/normal.png");
    ui->Normal->setIcon(ico2);
    ui->Normal->setText("");
    ui->Normal->setFlat(true);
    ui->Normal->setIconSize(QSize(50,298));
    ui->Normal->setGeometry(870,320,50,298);
    //ui->Normal->setGeometry(130, 300, 150, 50);

    QIcon ico3(":/new/prefix1/resources/background/time.png");
    ui->Timer->setIcon(ico3);
    ui->Timer->setText("");
    ui->Timer->setFlat(true);
    ui->Timer->setIconSize(QSize(50,298));
    ui->Timer->setGeometry(940,320,50,298);

    QIcon ico4(":/new/prefix1/resources/background/clean.png");
    ui->Clean->setIcon(ico4);
    ui->Clean->setText("");
    ui->Clean->setFlat(true);
    ui->Clean->setIconSize(QSize(50,298));
    ui->Clean->setGeometry(1010,320,50,298);
    //ui->Clean->setGeometry(130, 440, 150, 50);

    QIcon ico5(":/new/prefix1/resources/background/lianji.png");
    ui->Online->setIcon(ico5);
    ui->Online->setText("");
    ui->Online->setFlat(true);
    ui->Online->setIconSize(QSize(50,300));
    ui->Online->setGeometry(1080,320,50,300);

    QIcon ico6(":/new/prefix1/resources/background/store.png");
    ui->Store->setIcon(ico6);
    ui->Store->setText("");
    ui->Store->setFlat(true);
    ui->Store->setIconSize(QSize(50,174));
    ui->Store->setGeometry(1150,320,50,174);

    log = new login;
}

void Start::on_Normal_clicked()
{
    account = log->account;
    MainWindow* w =  new MainWindow(0,faces,account);
    w->show();
    connect(w,
            SIGNAL(windowClosed()),
            this,
            SLOT(showLabel()));
    this->hide();
}

void Start::on_Online_clicked()
{
    account = log->account;
    MainWindow* w =  new MainWindow(3,faces,account);
    w->show();
    connect(w,
            SIGNAL(windowClosed()),
            this,
            SLOT(showLabel()));
    this->hide();
}

void Start::on_Timer_clicked()
{
    account = log->account;
    MainWindow* w =  new MainWindow(1,faces,account);
    w->show();
    connect(w,
            SIGNAL(windowClosed()),
            this,
            SLOT(showLabel()));
    this->hide();
}

void Start::on_LogIn_clicked()
{

    log->show();
}

void Start::on_Clean_clicked()
{
    account = log->account;
    MainWindow* w =  new MainWindow(2,faces,account);
    w->show();
    connect(w,
            SIGNAL(windowClosed()),
            this,
            SLOT(showLabel()));
    this->hide();
}

void Start::on_Store_clicked()
{
    account = log->account;
    store = new Store(account,this);

    connect(store,
            SIGNAL(storeClosed()),
            this,
            SLOT(showLabel()));
    connect(store,SIGNAL(face(int)),this,SLOT(faceChange(int)));
    store->show();
    this->hide();
}

void Start::showLabel()
{
    this->show();
}
