#include "MenuHelp.hpp"

MenuHelp::MenuHelp() {}

void MenuHelp::display() {
    int option = -1;

    while (true) {
        system("cls");

        printInfo("\n=== USER HELP ===");
        std::cout << "1 - About the system\n"
                  << "2 - Credits\n"
                  << "0 - Back\n"
                  << "Choose an option: ";

        if (!readOption(option)) {
            waitForReturn();
            continue;
        }

        switch (option) {
        case 1:
            std::cout << "\nThis system allows you to manage virtual currency wallets, "
                      << "register buy and sell transactions, and generate financial reports.\n";
            break;
        case 2:
            std::cout << "\nFT Coin - Capital Gains and Losses Reporting System\n"
                      << "Authors:\n"
                      << "  - Izabella Julia dos Santos – RA 169048\n"
                      << "  - Leticia Lauriano de Oliveira – RA 173008\n"
                      << "  - Vitor C. Borela – RA 260934\n"
                      << "Copyright: Catch2\n"
                      << "Version: 1.0\n"
                      << "Year: 2025\n";
            break;
        case 0:
            return;
        default:
            printError("Invalid option, please choose between 0 and 2.");
            break;
        }

        waitForReturn();
    }
}
