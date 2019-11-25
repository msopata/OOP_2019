//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
#pragma once
#include "Widget.h"

class CheckBoxGnomeWidget : public Widget{
private:
    int gnomeVersion;
public:
    CheckBoxGnomeWidget(int gnomeVersion);
    void draw();
};

