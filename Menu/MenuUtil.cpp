#include "MenuUtil.hpp"

// Códigos ANSI para cores
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN   = "\033[36m";

void MenuUtil::printInfo(const std::string& texto) const {
    std::cout << CYAN << texto << RESET << std::endl;
}

void MenuUtil::printSucess(const std::string& texto) const {
    std::cout << GREEN << texto << RESET << std::endl;
}

void MenuUtil::printError(const std::string& texto) const {
    std::cout << RED << texto << RESET << std::endl;
}

void MenuUtil::aguardarVoltar() const {
    std::cout << "\nPressione Enter para voltar ao menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool MenuUtil::lerOpcao(int& opcao) const {
    std::cout << "Escolha uma opcao: ";
    if (std::cin >> opcao) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    } else {
        printError("Entrada invalida, por favor digite apenas numeros.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}