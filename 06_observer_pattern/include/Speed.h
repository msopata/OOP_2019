//
// Created by student on 18.11.2019.
//
#include "Observer.h"
#ifndef INC_06_OBSERVER_PATTERN_SPEED_H
#define INC_06_OBSERVER_PATTERN_SPEED_H

#endif //INC_06_OBSERVER_PATTERN_SPEED_H

class Speed: public Observer{
private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
public:
    float get();
};