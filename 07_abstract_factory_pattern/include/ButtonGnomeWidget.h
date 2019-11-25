//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
#pragma once

#include "Widget.h"

class ButtonGnomeWidget : public Widget{
private:
    int gnomeVersion;
public:
    ButtonGnomeWidget(int gnomeVersion);
    void draw();
};

