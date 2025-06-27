// WalletController.cpp
#include "WalletController.hpp"

WalletController::WalletController() : nextWalletId(1) {}

int WalletController::createWallet(const std::string &holderName, const std::string &broker) {
    int id = nextWalletId++;
    Wallet wallet(id, holderName, broker);
    wallets[id] = wallet;
    return id;
}

std::unique_ptr<Wallet> WalletController::getWallet(int id) const {
    auto it = wallets.find(id);
    if (it != wallets.end()) {
        return std::unique_ptr<Wallet>(new Wallet(it->second));
    }
    return nullptr;
}

bool WalletController::updateWallet(const Wallet &updatedWallet) {
    auto it = wallets.find(updatedWallet.getWalletId());
    if (it != wallets.end()) {
        it->second = updatedWallet;
        return true;
    }
    return false;
}

bool WalletController::deleteWallet(int id) {
    return wallets.erase(id) > 0;
}

std::vector<Wallet> WalletController::listAllWallets() const {
    std::vector<Wallet> list;
    for (const auto &pair : wallets) {
        list.push_back(pair.second);
    }
    return list;
}

bool WalletController::hasNoWallets() {
    return wallets.empty();
}

std::string toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::vector<Wallet> WalletController::listWalletsSortedByName() const {
    std::vector<Wallet> list;
    for (const auto &pair : wallets) {
        list.push_back(pair.second);
    }

    std::sort(list.begin(), list.end(), [](const Wallet &a, const Wallet &b) {
        return toLower(a.getOwnerName()) < toLower(b.getOwnerName());
    });

    return list;
}
