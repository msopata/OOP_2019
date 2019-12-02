//
// Created by student on 02.12.2019.
//

#pragma once

#include "Point.h"
#include "Space.h"

#include <vector>

class SpaceImpl: public Space {
public:
    void create(unsigned int dimensions);
    unsigned int dimensions() const;

private:
    unsigned int dimensionsCount;
    std::vector<Point> points;
};