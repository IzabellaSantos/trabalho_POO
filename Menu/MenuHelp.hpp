#pragma once
#ifndef MENU_HELP_HPP
#define MENU_HELP_HPP

#include "MenuBase.hpp"
#include "MenuUtil.hpp"

class MenuHelp : public MenuBase, public MenuUtil {
public:
    MenuHelp();
    void display() override;
};

#endif
