#pragma once
#include "MenuUtil.hpp"
#include "../Model/Carteira.hpp"
#include "../Local/CarteiraController.hpp"

class MenuCarteiraUtil: public MenuUtil {
    protected:
        bool verificarCarteirasDisponiveis(CarteiraController* controller);
        int lerIdCarteira();
        void exibirCarteira(const Carteira& carteira);
};
