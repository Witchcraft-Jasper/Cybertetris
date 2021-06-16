#include "myserver.h"

MyServer::MyServer(QObject *parent)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,8888);
}

//出现一个新的连接时触发
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    MyTcpSocket *tcpClientSocket = new MyTcpSocket(this);

    connect(tcpClientSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));
    connect(tcpClientSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpSocketList.append(tcpClientSocket);
    if (tcpSocketList.count() == 2){
        emit updateServer("START");
        QTcpSocket *socket = tcpSocketList.at(0);
        socket->write("START");
        socket = tcpSocketList.at(1);
        socket->write("START");
    }

    qDebug() << "成功连接";
}

//将任意客户端发来的信息进行广播
void MyServer::updateClients(QString msg,int descriptor)
{
    if (tcpSocketList.count() == 1){
        emit updateServer("WAIT");
        QTcpSocket *socket = tcpSocketList.at(0);
        socket->write("WAIT");
    }
    else {
        emit updateServer(msg);

        for(int i = 0; i < tcpSocketList.count() ; i ++)
        {
            QTcpSocket *socket = tcpSocketList.at(i);

            if(socket->socketDescriptor() != descriptor)
            {
                socket->write(msg.toStdString().c_str());
            }
            //        socket->write(msg.toStdString().c_str());
            //        qDebug() << "已经写出";
        }
    }

    //    qDebug() << msg;
}

//将断开连接的TcpSocket对象删除
void MyServer::slotDisconnected(int descriptor)
{
    for(int i = 0 ; i < tcpSocketList.count();i++)
    {
        QTcpSocket *socket = tcpSocketList.at(i);
        if(socket->socketDescriptor() == descriptor)
        {
            tcpSocketList.removeAt(i);
            return;
        }
    }
    return;
}
