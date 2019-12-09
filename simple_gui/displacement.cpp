#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    values[0] = values[1];
    values[1] = values[2];
    values[2] = v;
    //notify
    emit changed(v); //wysyla na zewnatrz sygnal o zmianie + wartosc

}
