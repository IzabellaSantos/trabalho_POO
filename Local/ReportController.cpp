#include "ReportController.hpp"

// Constructor initializes the controllers used for data retrieval and price querying
ReportController::ReportController(WalletController* wCtrl,
                                   TransactionController* tCtrl,
                                   OracleController* oCtrl)
    : walletController(wCtrl), transactionController(tCtrl), oracleController(oCtrl) {}

// Calculates the net balance in currency for the wallet (sells - buys)
double ReportController::calculateBalance(int walletId) const {
    double balance = 0.0;
    auto transactions = transactionController->getTransactions(walletId);

    for (const auto& transaction : transactions) {
        double value = transaction.getQuantity() * transaction.getUnitPrice();
        if (transaction.getTransactionType() == 'B') { // Buy
            balance -= value; // Money spent
        } else if (transaction.getTransactionType() == 'S') { // Sell
            balance += value; // Money received
        }
    }

    return balance;
}

// Returns all transactions of a wallet
std::vector<Transaction> ReportController::getTransactionHistory(int walletId) const {
    return transactionController->getTransactions(walletId);
}

// Calculates gain or loss based on the current market value of remaining assets
double ReportController::calculateGainLoss(int walletId) const {
    double totalInvested = 0.0;
    double quantityInWallet = 0.0;

    auto transactions = transactionController->getTransactions(walletId);
    double currentPrice = oracleController->getPrice("today");

    for (const auto& transaction : transactions) {
        double qty = transaction.getQuantity();
        double price = transaction.getUnitPrice();

        if (transaction.getTransactionType() == 'B') { // Buy
            totalInvested += qty * price;
            quantityInWallet += qty;
        } else if (transaction.getTransactionType() == 'S') { // Sell
            totalInvested -= qty * price;
            quantityInWallet -= qty;
        }
    }

    double currentValue = quantityInWallet * currentPrice;
    return currentValue - totalInvested;
}
