#include "MainMenu.hpp"

MainMenu::MainMenu(WalletController* walletCtrl,
                   TransactionController* transCtrl,
                   ReportController* reportCtrl)
    : MenuWallet(walletCtrl),
      transactionMenu(walletCtrl, transCtrl),
      reportMenu(walletCtrl, reportCtrl),
      menuHelp() {}


void MainMenu::display() {
    int option = -1;

    while (true) {
        system("cls");
        
        printInfo("\n=== MAIN MENU ===");
        std::cout << "1 - Wallet\n"
                  << "2 - Transaction\n"
                  << "3 - Reports\n"
                  << "4 - Help\n"
                  << "0 - Exit\n";

        if (!readOption(option)) {
            waitForReturn();
            continue;
        }

        switch (option) {
            case 1: 
                MenuWallet.display(); 
                break;
            case 2: 
                transactionMenu.display(); 
                break;
            case 3: 
                reportMenu.display(); 
                break;
            case 4: 
                menuHelp.display(); 
                break;
            case 0: 
                std::cout << "Exiting Program...\n"; 
                return;
            default: 
                printError("Invalid option, please choose between 0 and 4."); 
                waitForReturn();
                break;
        }
    }
}
