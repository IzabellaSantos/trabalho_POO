#include <iostream>
#include "Local/WalletController.hpp"
#include "Local/TransactionController.hpp"
#include "Local/ReportController.hpp"
#include "Local/OracleController.hpp"
#include "Menu/MainMenu.hpp"

int main() {
    int option;
    std::cout << "Choose mode:\n";
    std::cout << "1 - local memory \n";
    std::cout << "2 - database mode \n";
    std::cout << "Option: ";
    std::cin >> option;

    WalletController walletController;
    TransactionController transactionController;
    OracleController oracleController;
    ReportController reportController(&walletController, &transactionController, &oracleController);
    MainMenu mainMenu(&walletController, &transactionController, &reportController);

    switch (option) {
        case 1:
            mainMenu.display();
            break;
        case 2:
            mainMenu.display();
            break;
        default:
            std::cout << "Invalid option.\n";
            break;
    }

    return 0;
}
