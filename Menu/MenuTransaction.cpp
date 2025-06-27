#include "MenuTransaction.hpp"

MenuTransaction::MenuTransaction(WalletController* walletCtrl,
                                 TransactionController* transactionCtrl)
    : walletController(walletCtrl), transactionController(transactionCtrl) {}

void MenuTransaction::display() {
    int option = -1;

    while (true) {
        system("cls");

        printInfo("\n=== TRANSACTION MANAGEMENT ===");
        std::cout << "1 - Register purchase\n"
                  << "2 - Register sale\n"
                  << "3 - List transactions by wallet\n"
                  << "0 - Return\n";

        if (!readOption(option)) {
            waitForReturn();
            continue;
        }

        switch (option) {
            case 1:
                optionRegisterTransaction('C');
                break;
            case 2:
                optionRegisterTransaction('V');
                break;
            case 3:
                optionListTransactions();
                break;
            case 0:
                return;
            default:
                printError("Invalid option, please choose between 0 and 3.");
                break;
        }

        waitForReturn();
    }
}

void MenuTransaction::optionRegisterTransaction(char type) {
    std::string date;
    double quantity, unitPrice;

    if (!checkWalletsAvailable(walletController)) return;

    printInfo("\nRegister Transaction");
    int walletID = readWalletId();

    if (walletID == -1) return;

    if (!walletController->getWallet(walletID)) {
        printError("Wallet ID not found, please try again!");
        return;
    }

    std::cout << "Transaction date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Quantity: ";
    std::cin >> quantity;
    std::cin.ignore();

    if (quantity < 0) {
        printError("Quantity cannot be negative!");
        return;
    }

    std::cout << "Unit price: ";
    std::cin >> unitPrice;
    std::cin.ignore();

    if (unitPrice < 0) {
        printError("Unit price cannot be negative!");
        return;
    }

    transactionController->addTransaction(walletID, date, type, quantity, unitPrice);

    printSuccess("Transaction registered successfully.");
}

void MenuTransaction::optionListTransactions() {
    if (!checkWalletsAvailable(walletController)) return;

    printInfo("\nList Transactions by Wallet ID");
    int walletID = readWalletId();

    if (walletID == -1) return;

    auto transactions = transactionController->getTransactions(walletID);
    if (transactions.empty()) {
        printError("No transactions found.");
    } else {
        for (const auto& t : transactions) {
            std::cout << "ID: " << t.getTransactionId()
                      << " | Date: " << t.getTransactionDate()
                      << " | Type: " << t.getTransactionType()
                      << " | Quantity: " << t.getQuantity()
                      << " | Unit price: " << t.getUnitPrice() << "\n";
        }
    }
}
