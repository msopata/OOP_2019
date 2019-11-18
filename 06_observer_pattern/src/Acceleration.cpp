//
// Created by student on 18.11.2019.
//

#include "../include/Acceleration.h"

float Acceleration::get() {
    if( this->hasFirstValue && this->hasSecondValue && this->hasThirdValue)
        return this->thirdValue - this->secondValue;
}

