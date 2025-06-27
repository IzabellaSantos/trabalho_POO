#include "../catch.hpp"
#include "../../Local/WalletController.hpp"

TEST_CASE("Create wallet", "[WalletController]") {
    WalletController controller;

    int id = controller.createWallet("John Smith", "Binance");
    auto wallet = controller.getWallet(id);

    REQUIRE(wallet != nullptr);
    REQUIRE(wallet->getWalletId() == id);
    REQUIRE(wallet->getOwnerName() == "John Smith");
    REQUIRE(wallet->getBroker() == "Binance");
}

TEST_CASE("Update wallet", "[WalletController]") {
    WalletController controller;

    int id = controller.createWallet("Mary", "Binance");
    auto wallet = controller.getWallet(id);
    REQUIRE(wallet != nullptr);

    wallet->setOwnerName("Mary Johnson");
    wallet->setBroker("Coinbase");

    bool updated = controller.updateWallet(*wallet);
    REQUIRE(updated == true);

    auto updatedWallet = controller.getWallet(id);
    REQUIRE(updatedWallet->getOwnerName() == "Mary Johnson");
    REQUIRE(updatedWallet->getBroker() == "Coinbase");
}

TEST_CASE("Remove wallet", "[WalletController]") {
    WalletController controller;

    int id = controller.createWallet("Carlos", "Binance");

    bool removed = controller.deleteWallet(id);
    REQUIRE(removed == true);

    auto wallet = controller.getWallet(id);
    REQUIRE(wallet == nullptr);
}

TEST_CASE("List all wallets", "[WalletController]") {
    WalletController controller;

    int id1 = controller.createWallet("Alice", "Binance");
    int id2 = controller.createWallet("Bob", "Coinbase");

    auto list = controller.listAllWallets();
    REQUIRE(list.size() == 2);

    std::vector<int> ids;
    for (const auto& wallet : list) {
        ids.push_back(wallet.getWalletId());
    }

    REQUIRE(std::find(ids.begin(), ids.end(), id1) != ids.end());
    REQUIRE(std::find(ids.begin(), ids.end(), id2) != ids.end());
}
