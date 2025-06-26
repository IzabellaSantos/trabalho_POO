#include "MenuCarteiraUtil.hpp"

bool MenuCarteiraUtil::verificarCarteirasDisponiveis(CarteiraController* controller) {
    if (controller->verificarExistenciaCarteiras()) {
        printError("Nao foram encontradas carteiras para realizar a acao");
        return false;
    }
    return true;
}

int MenuCarteiraUtil::lerIdCarteira() {
    int id;
    std::cout << "ID da carteira: ";
    
    if (std::cin >> id) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return id;
    } else {
        printError("\nEntrada invalida, por favor digite apenas numeros.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1; 
    }
}

void MenuCarteiraUtil::exibirCarteira(const Carteira& carteira) {
    std::cout << "ID: " << carteira.getCarteiraId() << "\n";
    std::cout << "Nome do Titular: " << carteira.getNomeTitular() << "\n";
    std::cout << "Corretora: " << carteira.getCorretora() << "\n";
}