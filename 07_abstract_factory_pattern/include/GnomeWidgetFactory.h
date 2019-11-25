//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
#pragma once
#include "WidgetFactory.h"

class GnomeWidgetFactory : public WidgetFactory{
private:
    int gnomeVersion;
public:
    GnomeWidgetFactory(int gnomeVersion);
    std::shared_ptr<Widget> create(std::string type);
};