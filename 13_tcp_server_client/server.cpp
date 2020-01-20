#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    serv = new QTcpServer();

    connect(serv, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!serv->listen(QHostAddress::LocalHost, 8000))
            qDebug() << "Server could not start";
    qDebug() << "Server started";

    QTcpSocket *socket = serv->nextPendingConnection();

    emit newConnection( );
}


