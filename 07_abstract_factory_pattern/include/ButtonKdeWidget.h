//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
#pragma once
#include "Widget.h"

class ButtonKdeWidget : public Widget{
private:
    int KdeVersion;
public:
    ButtonKdeWidget(int KdeVersion);
    void draw();
};

