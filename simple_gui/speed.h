#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);

signals:
    void changed(double v);

public slots:
    //obsluga sygnalu
    void onDisplacementChanged(double v);
};

#endif // SPEED_H
