// === File: TransactionController.cpp ===
#include "TransactionController.hpp"

// Adds a new transaction to the specified wallet
void TransactionController::addTransaction(int walletId, const std::string &date, char operationType, double quantity, double unitPrice) {
    Transaction tx(nextTransactionId++, date, operationType, quantity, unitPrice);
    transactionsByWallet[walletId].push_back(tx);
}

// Returns the list of transactions for a given wallet, or an empty list if not found
std::vector<Transaction> TransactionController::getTransactions(int walletId) const {
    auto it = transactionsByWallet.find(walletId);
    if (it != transactionsByWallet.end()) {
        return it->second;
    }
    return {};
}
