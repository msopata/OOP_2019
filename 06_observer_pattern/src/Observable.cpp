//
// Created by student on 18.11.2019.
//

#include "../include/Observable.h"

void Observable::registerObserver(Observer * observer) {
    observers.insert(observer);
}

void Observable::unregisterObserver(Observer * observer) {
    observers.erase(observer);
}

void Observable::notifyObservers(float value ) {
    for(Observer* observer : observers)
        observer->notify( value );
}
