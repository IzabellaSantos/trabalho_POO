#include "Menu.hpp"

// Códigos ANSI para cores
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";

void Menu::printTitulo(const std::string& titulo) {
    std::cout << CYAN << "\n=== " << titulo << " ===" << RESET << std::endl;
}

void Menu::printOpcao(const std::string& texto) {
    std::cout << GREEN << texto << RESET << std::endl;
}

void Menu::printErro(const std::string& texto) {
    std::cout << RED << texto << RESET << std::endl;
}
