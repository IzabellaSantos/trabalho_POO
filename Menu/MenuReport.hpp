#pragma once
#ifndef MENU_REPORT_HPP
#define MENU_REPORT_HPP

#include "MenuBase.hpp"
#include "MenuWalletUtil.hpp"
#include "../Local/WalletController.hpp"
#include "../Local/ReportController.hpp"

// Report menu class derived from MenuBase and Wallet utilities
class MenuReport : public MenuBase, public MenuWalletUtil {
private:
    WalletController* walletController;
    ReportController* reportController;

public:
    MenuReport(WalletController* walletCtrl,
               ReportController* reportCtrl);
    void display() override ;

    void optionShowBalance();
    void optionShowHistory();
    void optionShowGainLoss();
    void optionListWalletsByID();
    void optionListWalletsByName();
};

#endif
