#pragma once

#ifndef HELP_MENU_HPP
#define HELP_MENU_HPP

#include "MenuBase.hpp"
#include "MenuUtil.hpp"

class HelpMenu : public MenuBase, public MenuUtil {
    public:
        HelpMenu();
        void display() override;
};

#endif
