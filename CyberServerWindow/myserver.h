#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include "mytcpsocket.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = 0);
    QList<MyTcpSocket *> tcpSocketList;
signals:
    void updateServer(QString);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // MYSERVER_H
