//
// Created by student on 25.11.2019.
//

//#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
//#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H

//#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
#pragma once
#include "Widget.h"

class ListKdeWidget : public Widget{
private:
    int KdeVersion;
public:
    ListKdeWidget(int KdeVersion);
    void draw();
};