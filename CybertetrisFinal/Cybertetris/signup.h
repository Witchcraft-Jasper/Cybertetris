#ifndef SIGNUP_H
#define SIGNUP_H
#include "login.h"

#include <QWidget>

namespace Ui {
class signUp;
}

class signUp : public QWidget
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

private slots:

    void on_cancel_clicked();

    void on_log_clicked();

private:
    Ui::signUp *ui;
    QSqlDatabase database;
};

#endif // SIGNUP_H
