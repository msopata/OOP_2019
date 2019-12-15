#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

signals:
    void changed(double acc);

public slots:
    void onSpeedChange(double v);
private:
    double currSpeed;
    double prevSpeed;
    double acceleration;
};

#endif // ACCELERATION_H
