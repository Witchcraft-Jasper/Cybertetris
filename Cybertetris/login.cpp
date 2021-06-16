#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../Cybertetris/UserDatas.db");
    if(!database.open()){
        cout <<"open failed!\n";
    }else{
        cout <<"open successfully!\n";
    }

}

login::~login()
{
    delete ui;
}

void login::on_cancel_clicked()
{
    this->close();
}

void login::on_log_clicked()
{
    QSqlQuery query = QSqlQuery(database);
    QString sql = "select * from users";
    if(!query.exec(sql)){
        cout <<"exec failed!\n";
    }
    else {
        while (query.next()) {
            if(query.value(0).toInt() == ui->account->text().toInt()){
                if(query.value(1).toString().toStdString() == ui->password->text().toStdString()){
                    cout << "Log in successfully!\n";
                    account = ui->account->text().toInt();
                    this->close();
                }
            }
        }
        ui->sign->setText("账号或密码错误");
    }
}

