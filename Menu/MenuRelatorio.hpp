#pragma once
#ifndef MENU_RELATORIO_HPP
#define MENU_RELATORIO_HPP

#include "MenuBase.hpp"
#include "MenuCarteiraUtil.hpp"
#include "../Local/CarteiraController.hpp"
#include "../Local/RelatorioController.hpp"

class MenuRelatorio: public MenuBase, public MenuCarteiraUtil {
    private:
        CarteiraController* carteiraController;
        RelatorioController* relatorioController;

    public:
        MenuRelatorio(CarteiraController* carteiraCtrl,
                      RelatorioController* relatorioCtrl);
        void exibir() override;

        void opcaoExibirSaldo();
        void opcaoExibirHistorico();
        void opcaoExibirGanhoPerda();
        void opcaoListarCarteirasID();
        void opcaoListarCarteirasPorNome();
};

#endif
