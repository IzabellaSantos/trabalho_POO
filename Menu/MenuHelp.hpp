#pragma once

#ifndef HELP_MENU_HPP
#define HELP_MENU_HPP

#include "MenuBase.hpp"
#include "MenuUtil.hpp"

class MenuHelp : public MenuBase, public MenuUtil {
    public:
        MenuHelp();
        void display() override;
};

#endif
