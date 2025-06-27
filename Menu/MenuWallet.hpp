#pragma once
#ifndef WALLET_MENU_HPP
#define WALLET_MENU_HPP

#include "MenuBase.hpp"
#include "MenuWalletUtil.hpp"
#include "../Local/WalletController.hpp"

class MenuWallet : public MenuBase, public MenuWalletUtil {
private:
    WalletController* walletController;

public:
    MenuWallet(WalletController* controller);
    void display() override;

    void optionAddWallet();
    void optionRetrieveWallet();
    void optionEditWallet();
    void optionDeleteWallet();
};

#endif
