#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    value = v;
    //notify
    emit changed(v); //wysyla na zewnatrz sygnal o zmianie + wartosc

}
