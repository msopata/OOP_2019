//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
#pragma once
#include "Widget.h"

class CheckBoxKdeWidget : public Widget{
private:
    int KdeVersion;
public:
    CheckBoxKdeWidget(int KdeVersion);
    void draw();
};