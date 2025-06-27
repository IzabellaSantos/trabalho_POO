#pragma once
#include "MenuUtil.hpp"
#include "../Model/Wallet.hpp"
#include "../Local/WalletController.hpp"

class MenuWalletUtil : public MenuUtil {
protected:
    bool checkWalletsAvailable(WalletController* controller);
    int readWalletId();
    void displayWallet(const Wallet& wallet);
};
