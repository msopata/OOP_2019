//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#include "Observer.h"
#include <set>

class Observable : public Observer{
private:
        std::set<Observer*> observers;
public:
        void registerObserver(Observer* observer);
        void unregisterObserver(Observer* observer);

protected:
    void notifyObservers(float value);
};