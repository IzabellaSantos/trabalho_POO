#include "MenuUtil.hpp"

// ANSI escape codes for colors
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN   = "\033[36m";

void MenuUtil::printInfo(const std::string& text) const {
    std::cout << CYAN << '\n' << text << RESET << std::endl;
}

void MenuUtil::printSuccess(const std::string& text) const {
    std::cout << GREEN << '\n' << text << RESET << std::endl;
}

void MenuUtil::printError(const std::string& text) const {
    std::cout << RED << '\n' << text << RESET << std::endl;
}

void MenuUtil::waitForReturn() const {
    std::cout << "\nPress Enter to return to the menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool MenuUtil::readOption(int& option) const {
    std::cout << "Choose an option: ";
    if (std::cin >> option) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    } else {
        printError("Invalid input, please enter numbers only.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
