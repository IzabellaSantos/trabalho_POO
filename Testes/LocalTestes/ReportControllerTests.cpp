#include "../catch.hpp"
#include "../../Local/ReportController.hpp"
#include "../../Local/WalletController.hpp"
#include "../../Local/TransactionController.hpp"
#include "../../Model/Transaction.hpp"
#include "../Mocks/OracleControllerMock.cpp"

TEST_CASE("Calculate wallet balance", "[ReportController]") {
    WalletController walletCtrl;
    TransactionController transactionCtrl;
    OracleControllerMock oracleCtrl;

    int walletId = walletCtrl.createWallet("John", "Binance");

    transactionCtrl.addTransaction(walletId, "2025-06-01", 'B', 2.0, 100.0);  // +200
    transactionCtrl.addTransaction(walletId, "2025-06-02", 'S', 1.0, 150.0);  // -150

    ReportController report(&walletCtrl, &transactionCtrl, &oracleCtrl);

    double balance = report.calculateBalance(walletId);

    REQUIRE(balance == Approx(50.0));  // 200 - 150 = 50
}

TEST_CASE("Get transaction history", "[ReportController]") {
    WalletController walletCtrl;
    TransactionController transactionCtrl;
    OracleControllerMock oracleCtrl;

    int walletId = walletCtrl.createWallet("Mary", "Coinbase");

    transactionCtrl.addTransaction(walletId, "2025-06-01", 'B', 1.0, 200.0);
    transactionCtrl.addTransaction(walletId, "2025-06-02", 'S', 0.5, 220.0);

    ReportController report(&walletCtrl, &transactionCtrl, &oracleCtrl);

    auto history = report.getTransactionHistory(walletId);

    REQUIRE(history.size() == 2);
    REQUIRE(history[0].getDate() == "2025-06-01");
    REQUIRE(history[1].getOperationType() == 'S');
}

TEST_CASE("Calculate gain or loss", "[ReportController]") {
    WalletController walletCtrl;
    TransactionController transactionCtrl;
    OracleControllerMock oracleCtrl;  // Fixed price = 10.0

    int walletId = walletCtrl.createWallet("Carlos", "Binance");

    transactionCtrl.addTransaction(walletId, "2025-06-01", 'B', 3.0, 5.0);   // Spent: 15, Current value: 30
    transactionCtrl.addTransaction(walletId, "2025-06-02", 'S', 1.0, 8.0);   // Spent: -8, Current value: -10

    ReportController report(&walletCtrl, &transactionCtrl, &oracleCtrl);

    double gainLoss = report.calculateGainLoss(walletId);

    // Total spent: 15 - 8 = 7
    // Current total: 30 - 10 = 20
    // Gain/Loss = 20 - 7 = 13
    REQUIRE(gainLoss == Approx(13.0));
}
