#pragma once

#include <QObject>
#include "server.h"

class connection : public QObject
{
    Q_OBJECT
public:
    explicit connection(QObject *parent = nullptr);

signals:

public slots:
    void nextPendingConnection();
};
