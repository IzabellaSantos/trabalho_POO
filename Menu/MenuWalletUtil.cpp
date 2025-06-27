#include "MenuWalletUtil.hpp"

bool MenuWalletUtil::checkWalletsAvailable(WalletController* controller) {
    if (!controller->hasWallets()) {
        printError("No wallets found to perform the action.");
        return false;
    }
    return true;
}

int MenuWalletUtil::readWalletId() {
    int id;
    std::cout << "Wallet ID: ";
    
    if (std::cin >> id) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return id;
    } else {
        printError("\nInvalid input, please enter numbers only.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
}

void MenuWalletUtil::displayWallet(const Wallet& wallet) {
    std::cout << "ID: " << wallet.getWalletId() << "\n";
    std::cout << "Holder Name: " << wallet.getOwnerName() << "\n";
    std::cout << "Broker: " << wallet.getBroker() << "\n";
}
