#pragma once

#ifndef MENU_AJUDA_HPP
#define MENU_AJUDA_HPP

#include "MenuBase.hpp"
#include "MenuUtil.hpp"

class MenuAjuda: public MenuBase, public MenuUtil {
    public:
        MenuAjuda();
        void exibir() override;
};

#endif
