#include "MenuReport.hpp"

MenuReport::MenuReport(WalletController* walletCtrl,
                       ReportController* reportCtrl)
    : walletController(walletCtrl), reportController(reportCtrl) {}

void MenuReport::display() {
    int option = -1;

    while (true) {
        system("cls");

        printInfo("\n=== REPORTS ===");
        std::cout << "1 - Show current wallet balance\n"
                  << "2 - Show transaction history by ID\n"
                  << "3 - Show current gain or loss of wallets\n"
                  << "4 - List wallets ordered by ID\n"
                  << "5 - List wallets ordered by owner name\n"
                  << "0 - Return\n";

        if (!readOption(option)) {
            waitForReturn();
            continue;
        }

        switch (option) {
            case 1:
                optionShowBalance();
                break;
            case 2:
                optionShowHistory();
                break;
            case 3:
                optionShowGainLoss();
                break;
            case 4:
                optionListWalletsByID();
                break;
            case 5:
                optionListWalletsByName();
                break;
            case 0:
                return;
            default:
                printError("Invalid option, please choose between 0 and 5.");
                break;
        }

        waitForReturn();
    }
}

void MenuReport::optionShowBalance() {
    if (!checkWalletsAvailable(walletController)) return;

    int walletID = readWalletId();

    if (walletID == -1) return;

    if(!walletController->getWallet(walletID)) {
        printError("Wallet ID not found, please try again!");
        return;
    }

    double balance = reportController->calculateBalance(walletID);
    std::cout << "Current balance: " << balance << "\n";
}

void MenuReport::optionShowHistory() {
    if (!checkWalletsAvailable(walletController)) return;

    int walletID = readWalletId();

    if (walletID == -1) return;

    if(!walletController->getWallet(walletID)) {
        printError("Wallet ID not found, please try again!");
        return;
    }

    auto history = reportController->getTransactionHistory(walletID);
    if (history.empty()) {
        printError("No transactions found.");
    } else {
        for (const auto& t : history) {
            std::cout << "Date: " << t.getTransactionDate()
                      << " | Type: " << t.getTransactionType()
                      << " | Qty: " << t.getQuantity()
                      << " | Price: " << t.getUnitPrice() << "\n";
        }
    }
}

void MenuReport::optionShowGainLoss() {
    if (!checkWalletsAvailable(walletController)) return;

    int walletID = readWalletId();

    if (walletID == -1) return;

    if(!walletController->getWallet(walletID)) {
        printError("Wallet ID not found, please try again!");
        return;
    }

    double result = reportController->calculateGainLoss(walletID);
    printInfo("\nTotal Gain/Loss");
    std::cout << result;
}

void MenuReport::optionListWalletsByID() {
    std::vector<Wallet> wallets = walletController->listAllWallets();

    if (wallets.empty()) {
        printError("No wallets found.");
        return;
    }

    printInfo("\nRegistered wallets (ordered by ID)");
    for (const Wallet& wallet : wallets) {
        displayWallet(wallet);
        std::cout << "\n";
    }
}

void MenuReport::optionListWalletsByName() {
    std::vector<Wallet> wallets = WalletController->listWalletsSortedByName();

    if (wallets.empty()) {
        printError("No wallets found.");
        return;
    }

    printInfo("\nRegistered wallets (ordered by owner name)");
    for (const Wallet& wallet : wallets) {
        displayWallet(wallet);
        std::cout << "\n";
    }
}
