//
// Created by student on 18.11.2019.
//
#include "Observer.h"
#ifndef INC_06_OBSERVER_PATTERN_ACCELERATION_H
#define INC_06_OBSERVER_PATTERN_ACCELERATION_H

#endif //INC_06_OBSERVER_PATTERN_ACCELERATION_H

class Acceleration : public Observer{
private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
public:
    float get();
};