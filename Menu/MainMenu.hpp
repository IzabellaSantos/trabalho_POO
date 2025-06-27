#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "../Local/WalletController.hpp"
#include "../Local/TransactionController.hpp"
#include "../Local/ReportController.hpp"

class MainMenu {
  private:
      WalletController *walletController;
      TransactionController *transactionController;
      ReportController *reportController;

      void showWalletMenu();
      void showTransactionMenu();
      void showReportMenu();

  public:
      MainMenu(WalletController *wCtrl, TransactionController *tCtrl, ReportController *rCtrl);
      void display();
};

#endif
