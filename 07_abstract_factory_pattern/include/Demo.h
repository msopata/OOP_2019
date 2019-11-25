//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
#pragma once
#include "WidgetFactory.h"

class Demo{
private:
    std::shared_ptr<WidgetFactory> factory;
public:
    Demo(std::shared_ptr<WidgetFactory> factory);
    void run(std::string type);
};