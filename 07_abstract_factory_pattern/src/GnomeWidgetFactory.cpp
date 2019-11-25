//
// Created by student on 25.11.2019.
//

#include <ButtonGnomeWidget.h>
#include <ListGnomeWidget.h>
#include <CheckBoxGnomeWidget.h>
#include "GnomeWidgetFactory.h"

GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

std::shared_ptr<Widget> GnomeWidgetFactory::create(std::string type)
{
    if(type == "Button")
        return std::make_shared<ButtonGnomeWidget>(gnomeVersion);
    if( type == "List")
        return std::make_shared<ListGnomeWidget>(gnomeVersion);
    if(type == "CheckBox")
        return std::make_shared<CheckBoxGnomeWidget>(gnomeVersion);

}
