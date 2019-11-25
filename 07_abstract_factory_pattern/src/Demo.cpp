//
// Created by student on 25.11.2019.
//

#include "Demo.h"

Demo::Demo(std::shared_ptr<WidgetFactory> factory)
{
    this->factory = factory;
}

void Demo::run(std::string type)
{
    auto widget = this->factory->create(type);
    widget->draw();
}
