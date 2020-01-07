#include "acceleration.h"
#include <QtDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::set(double v)
{
    currSpeed = v;
    qDebug() << "[ Acceleration ] value: " << v;
    acceleration = currSpeed - prevSpeed;
    prevSpeed = currSpeed;
}

double Acceleration::get() const
{
    return acceleration;
}

void Acceleration::onSpeedChange(double v)
{
    set(v);
    emit changed(this->get());
}
