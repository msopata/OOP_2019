//
// Created by student on 18.11.2019.
//

#include "../include/Speed.h"

float Speed::get() {
    if(this->hasFirstValue && this->hasSecondValue)
        return this->secondValue - this->firstValue;
}
