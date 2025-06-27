#ifndef REPORT_CONTROLLER_HPP
#define REPORT_CONTROLLER_HPP

#include <vector>
#include "../Model/Wallet.hpp"
#include "../Model/Transaction.hpp"
#include "WalletController.hpp"
#include "TransactionController.hpp"
#include "OracleController.hpp"

class ReportController {
private:
    WalletController *walletController;
    TransactionController *transactionController;
    OracleController *oracleController;

public:
    ReportController(WalletController *wCtrl, TransactionController *tCtrl, OracleController *oCtrl);

    // Returns the net balance of the wallet (in currency), considering buys and sells
    double calculateBalance(int walletId) const;

    // Returns all transactions associated with a wallet
    std::vector<Transaction> getTransactionHistory(int walletId) const;

    // Calculates total gain or loss of the wallet based on current price
    double calculateGainLoss(int walletId) const;
};

#endif
