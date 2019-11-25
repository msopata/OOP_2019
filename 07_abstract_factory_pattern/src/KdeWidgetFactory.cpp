//
// Created by student on 25.11.2019.
//

#include <ButtonKdeWidget.h>
#include <ListKdeWidget.h>
#include <CheckBoxKdeWidget.h>
#include "KdeWidgetFactory.h"

KdeWidgetFactory::KdeWidgetFactory(int KdeVersion)
{
    this->KdeVersion = KdeVersion;
}

std::shared_ptr<Widget> KdeWidgetFactory::create(std::string type)
{
   if( type == "Button")
       return std::make_shared<ButtonKdeWidget>(KdeVersion);
   if( type == "List")
       return std::make_shared<ListKdeWidget>(KdeVersion);
   if(type == "CheckBox")
       return std::make_shared<CheckBoxKdeWidget>(KdeVersion);

   //return widget;
}
