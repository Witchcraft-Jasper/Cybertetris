#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>

using namespace std;

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    int account; //账号
    QSqlDatabase getDatabase(){
        return database;
    }

private slots:

    void on_cancel_clicked();

    void on_log_clicked();

private:
    Ui::login *ui;
    QSqlDatabase database;

};

#endif // LOGIN_H
