#include "../catch.hpp"
#include "../../Local/TransactionController.hpp"
#include "../../Model/Transaction.hpp"

TEST_CASE("Add transaction", "[TransactionController]") {
    TransactionController controller;
    int mockId = 1;

    controller.addTransaction(mockId, "2025-06-24", 'B', 2.5, 100.0);
    controller.addTransaction(mockId, "2025-06-23", 'S', 1.0, 110.0);

    auto transactions = controller.getTransactions(mockId);

    REQUIRE(transactions.size() == 2);

    REQUIRE(transactions[0].getDate() == "2025-06-24");
    REQUIRE(transactions[0].getOperationType() == 'B');
    REQUIRE(transactions[0].getQuantity() == Approx(2.5));
    REQUIRE(transactions[0].getUnitPrice() == Approx(100.0));

    REQUIRE(transactions[1].getOperationType() == 'S');
    REQUIRE(transactions[1].getQuantity() == Approx(1.0));
    REQUIRE(transactions[1].getUnitPrice() == Approx(110.0));
}

TEST_CASE("Get non-existent transactions", "[TransactionController]") {
    TransactionController controller;

    auto transactions = controller.getTransactions(99); // non-existent id
    REQUIRE(transactions.empty()); // should return empty vector
}
