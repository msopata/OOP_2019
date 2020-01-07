#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>



class Acceleration : public QObject
{

    Q_PROPERTY(double acceleration
               READ get
               WRITE set
               NOTIFY changed
               )

    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE void set( double v);
    double get() const;

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
