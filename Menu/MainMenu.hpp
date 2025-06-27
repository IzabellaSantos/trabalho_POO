#include "MenuUtil.hpp"
#include "WalletMenu.hpp"
#include "MenuTransaction.hpp"
#include "MenuReport.hpp"
#include "MenuHelp.hpp"

class MainMenu : public MenuUtil {
private:
    WalletMenu walletMenu;
    TransactionMenu transactionMenu;
    ReportMenu reportMenu;
    HelpMenu helpMenu;

public:
    MainMenu(WalletController* walletCtrl,
             TransactionController* transCtrl,
             ReportController* reportCtrl);

    void display();
};
