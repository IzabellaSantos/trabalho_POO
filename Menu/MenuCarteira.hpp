#pragma once
#ifndef MENU_CARTEIRA_HPP
#define MENU_CARTEIRA_HPP

#include "MenuBase.hpp"
#include "MenuCarteiraUtil.hpp"
#include "../Local/CarteiraController.hpp"

class MenuCarteira: public MenuBase, public MenuCarteiraUtil {
    private:
        CarteiraController* carteiraController;

    public:
        MenuCarteira(CarteiraController* controller);
        void exibir() override;

        void opcaoIncluirCarteira();
        void opcaoRecuperarCarteira();
        void opcaoEditarCarteira();
        void opcaoExcluirCarteira();
};

#endif
