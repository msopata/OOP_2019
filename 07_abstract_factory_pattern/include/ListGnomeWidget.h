//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
#pragma once
#include "Widget.h"

class ListGnomeWidget : public Widget{
private:
    int gnomeVersion;
public:
    ListGnomeWidget(int gnomeVersion);
    void draw();
};