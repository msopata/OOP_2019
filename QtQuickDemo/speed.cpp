#include "speed.h"
#include <QtDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{
    prevDisplacement = 0;
    currDisplacement = 0;
    speed = 0;
}

void Speed::set(double v)
{
    currDisplacement = v;
    double time = 1.0;
    speed = (currDisplacement - prevDisplacement) / time;
    prevDisplacement = currDisplacement;
    qDebug() << "[ Speed ] changed to: " << speed;
}

double Speed::get() const
{
    return speed;
}

void Speed::onDisplacementChange(double v)
{
    set(v);
    emit changed(this->get());
}
