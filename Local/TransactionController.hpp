// === File: TransactionController.hpp ===
#ifndef TRANSACTION_CONTROLLER_HPP
#define TRANSACTION_CONTROLLER_HPP

#include <unordered_map>
#include <vector>
#include "../Model/Transaction.hpp"

// TransactionController handles adding and retrieving transactions per wallet
class TransactionController {
  private:
    // Map walletId → list of Transaction
    std::unordered_map<int, std::vector<Transaction>> transactionsByWallet;
    int nextTransactionId = 0; // Next transaction ID to assign

  public:
    // Adds a transaction (purchase or sale) to a wallet
    void addTransaction(int walletId, const std::string &date, char operationType, double quantity, double unitPrice);

    // Retrieves all transactions for a given wallet ID
    std::vector<Transaction> getTransactions(int walletId) const;
};

#endif
