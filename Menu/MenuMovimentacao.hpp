#pragma once
#ifndef MENU_MOVIMENTACAO_HPP
#define MENU_MOVIMENTACAO_HPP

#include "MenuBase.hpp"
#include "MenuCarteiraUtil.hpp"
#include "../Local/CarteiraController.hpp"
#include "../Local/MovimentacaoController.hpp"

class MenuMovimentacao: public MenuBase, public MenuCarteiraUtil {
    private:
        CarteiraController* carteiraController;
        MovimentacaoController* movimentacaoController;

    public:
        MenuMovimentacao(CarteiraController* carteiraCtrl,
                         MovimentacaoController* movimentacaoCtrl);
        void exibir() override;

        void opcaoRegistrarMovimentacao(char tipo);
        void opcaoListarMovimentacoes();
};

#endif
