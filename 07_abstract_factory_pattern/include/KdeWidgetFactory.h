//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
#pragma once
#include "WidgetFactory.h"

class KdeWidgetFactory : public WidgetFactory{
private:
    int KdeVersion;
public:
    KdeWidgetFactory(int KdeVersion);
    std::shared_ptr<Widget> create(std::string type);
};