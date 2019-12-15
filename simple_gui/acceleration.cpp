#include "acceleration.h"
#include <QtDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onSpeedChange(double v)
{
    currSpeed = v;
    qDebug() << "[ Acceleration ] value: " << v;
    acceleration = currSpeed - prevSpeed;
    prevSpeed = currSpeed;
    emit changed(acceleration);
}
