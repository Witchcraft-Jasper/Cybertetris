#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent)
{
    Q_UNUSED(parent)
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void MyTcpSocket::dataReceived()
{
    QByteArray array = readAll();
    QString msg = array;

//    qDebug() << msg;

    emit updateMainWindow(msg);
    emit updateClients(msg,socketDescriptor());

}

void MyTcpSocket::slotDisconnected()
{
    emit disconnected(socketDescriptor());
}
