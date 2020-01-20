#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "connection.h"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);

signals:
    void newConnection();

public slots:

private:
    QTcpServer *serv;


};

#endif // SERVER_H
