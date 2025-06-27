#include "MainMenu.hpp"
#include <iostream>

// Constructor initializes controllers used by the menu
MainMenu::MainMenu(WalletController *wCtrl, TransactionController *tCtrl, ReportController *rCtrl)
    : walletController(wCtrl), transactionController(tCtrl), reportController(rCtrl) {}

void MainMenu::showWalletMenu() {
  std::cout << "Wallet Menu\n";
  // TODO: implement wallet management menu options here
}

void MainMenu::showTransactionMenu() {
  std::cout << "Transaction Menu\n";
  // TODO: implement transaction management menu options here
}

void MainMenu::showReportMenu() {
  std::cout << "Report Menu\n";
  // TODO: implement report display menu options here
}

void MainMenu::display() {
  int option = 0;
  do {
    std::cout << "\nMain Menu:\n";
    std::cout << "1 - Wallet Management\n";
    std::cout << "2 - Transaction Management\n";
    std::cout << "3 - Report\n";
    std::cout << "0 - Exit\n";
    std::cout << "Select option: ";
    std::cin >> option;

    switch (option) {
      case 1:
        showWalletMenu();
        break;
      case 2:
        showTransactionMenu();
        break;
      case 3:
        showReportMenu();
        break;
      case 0:
        std::cout << "Exiting...\n";
        break;
      default:
        std::cout << "Invalid option.\n";
    }
  } while (option != 0);
}
