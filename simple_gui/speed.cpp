#include "speed.h"
#include <QtDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{
    prevDisplacement = 0;
    currDisplacement = 0;
    speed = 0;
}

void Speed::onDisplacementChange(double v)
{
    currDisplacement = v;
    qDebug() << "[ Speed ] changed to: " << v;
    double time = 1.0;
    speed = (currDisplacement - prevDisplacement) / time;
    prevDisplacement = currDisplacement;
    emit changed(speed);
}
