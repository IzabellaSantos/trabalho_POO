#pragma once
#ifndef WALLET_MENU_HPP
#define WALLET_MENU_HPP

#include "MenuBase.hpp"
#include "WalletMenuUtil.hpp"
#include "../Local/WalletController.hpp"

class WalletMenu: public MenuBase, public WalletMenuUtil {
    private:
        WalletController* walletController;

    public:
        WalletMenu(WalletController* controller);
        void show() override;

        void optionAddWallet();
        void optionRetrieveWallet();
        void optionEditWallet();
        void optionDeleteWallet();
};

#endif
