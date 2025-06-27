// === File: WalletController.cpp ===
#include "WalletController.hpp"

// Constructor initializes wallet ID counter
WalletController::WalletController() : nextWalletId(1) {}

// Creates a new wallet and stores it
int WalletController::createWallet(const std::string &holderName, const std::string &broker) {
    int id = nextWalletId++;
    Wallet wallet(id, holderName, broker);
    wallets[id] = wallet;
    return id;
}

// Retrieves a wallet by its ID. Returns nullptr if not found.
std::unique_ptr<Wallet> WalletController::getWallet(int id) const {
    auto it = wallets.find(id);
    if (it != wallets.end()) {
        return std::make_unique<Wallet>(it->second);
    }
    return nullptr;
}

// Updates an existing wallet, returns true if successful
bool WalletController::updateWallet(const Wallet &updatedWallet) {
    auto it = wallets.find(updatedWallet.getWalletId());
    if (it != wallets.end()) {
        it->second = updatedWallet;
        return true;
    }
    return false;
}

// Removes a wallet by its ID, returns true if successful
bool WalletController::removeWallet(int id) {
    return wallets.erase(id) > 0;
}

// Returns all stored wallets
std::vector<Wallet> WalletController::listAllWallets() const {
    std::vector<Wallet> list;
    for (const auto &pair : wallets) {
        list.push_back(pair.second);
    }
    return list;
}

// Checks if any wallets exist
bool WalletController::hasAnyWallets() const {
    return !wallets.empty();
}

// Helper function to lowercase strings
std::string toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// Returns wallets sorted by holder name (case insensitive)
std::vector<Wallet> WalletController::listWalletsSortedByName() const {
    std::vector<Wallet> list;
    for (const auto &pair : wallets) {
        list.push_back(pair.second);
    }

    std::sort(list.begin(), list.end(), [](const Wallet &a, const Wallet &b) {
        return toLower(a.getHolderName()) < toLower(b.getHolderName());
    });

    return list;
}
