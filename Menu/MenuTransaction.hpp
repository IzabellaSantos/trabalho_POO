#pragma once
#ifndef MENU_TRANSACTION_HPP
#define MENU_TRANSACTION_HPP

#include "MenuBase.hpp"
#include "MenuWalletUtil.hpp"
#include "../Local/WalletController.hpp"
#include "../Local/TransactionController.hpp"

class MenuTransaction : public MenuBase, public MenuWalletUtil {
private:
    WalletController* walletController;
    TransactionController* transactionController;

public:
    MenuTransaction(WalletController* walletCtrl,
                    TransactionController* transactionCtrl);
    void display() override ;

    void optionRegisterTransaction(char type);
    void optionListTransactions();
};

#endif
