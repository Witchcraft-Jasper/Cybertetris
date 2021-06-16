#include "signup.h"
#include "ui_signup.h"
#include<QDebug>


signUp::signUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUp)
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

signUp::~signUp()
{
    delete ui;
}

void signUp::on_cancel_clicked()
{
    database.close();
    database.removeDatabase("QSQLITE");
    this->close();
    login* log = new login;
    log->show();
}

void signUp::on_log_clicked()
{
    QSqlQuery query = QSqlQuery(database);
    QString sql = "select * from users";
    bool right = true;
    if(!query.exec(sql)){
        cout <<"exec failed!\n";
    }
    else {
        if(ui->password->text() != ui->password2->text()){
            ui->sign->setText("两次密码不一致");
            right = false;
        }
        while (query.next()) {
            if(query.value(0) == ui->account->text()){
                ui->sign->setText("该账号已被注册");
                right = false;
            }
        }
        if(right){
            query.clear();
            sql = QString("INSERT INTO 'users' "
                          "('account', 'password', 'name', 'coins') "
                          "VALUES ('%1','%2','%3','0')").arg(ui->account->text(),ui->password->text(),ui->name->text());
            qDebug() << sql;
            if(query.exec(sql))
                ui->sign->setText("注册成功");
            else ui->sign->setText("注册失败");
        }

    }
}
