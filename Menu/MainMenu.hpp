#include "MenuUtil.hpp"
#include "MenuWallet.hpp"
#include "MenuTransaction.hpp"
#include "MenuReport.hpp"
#include "MenuHelp.hpp"

class MainMenu : public MenuUtil {
private:
    MenuWallet MenuWallet;
    MenuTransaction transactionMenu;
    MenuReport reportMenu;
    MenuHelp menuHelp;

public:
    MainMenu(WalletController* walletCtrl,
             TransactionController* transCtrl,
             ReportController* reportCtrl);

    void display();
};
