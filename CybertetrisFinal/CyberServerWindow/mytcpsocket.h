#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>

class MyTcpSocket : public QTcpSocket
{

    Q_OBJECT
public:
    MyTcpSocket(QObject *parent=0);
signals:
    void updateMainWindow(QString);
    void updateClients(QString,int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // MYTCPSOCKET_H
