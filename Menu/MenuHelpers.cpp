#include "Menu.hpp"

void Menu::aguardarVoltar() {
    std::cout << "\nPressione Enter para voltar ao menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Menu::lerOpcao(int& opcao) {
    std::cout << "Escolha uma opcao: ";
    if (std::cin >> opcao) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    } else {
        printError("\nEntrada invalida, por favor digite apenas numeros.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}

bool Menu::verificarCarteirasDisponiveis() {
    if (carteiraController->verificarExistenciaCarteiras()) {
        printError("Nao foram encontradas carteiras para realizar a acao");
        return false;
    }
    return true;
}

int Menu::lerIdCarteira() {
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

void Menu::exibirCarteira(const Carteira& carteira) {
    std::cout << "ID: " << carteira.getId() << "\n";
    std::cout << "Nome do Titular: " << carteira.getNomeTitular() << "\n";
    std::cout << "Corretora: " << carteira.getCorretora() << "\n";
}
