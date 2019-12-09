#include "speed.h"
#include <QtDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    qDebug() << "[ Speed ] changed to: " << v;
    emit changed(v);
}
