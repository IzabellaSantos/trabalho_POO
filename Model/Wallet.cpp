#include "Wallet.hpp"

// Default constructor
Wallet::Wallet() : walletId(0), ownerName(""), broker("") {}

// Parameterized constructor
Wallet::Wallet(int id, const std::string &owner, const std::string &brokerName)
    : walletId(id), ownerName(owner), broker(brokerName) {}

int Wallet::getWalletId() const {
  return walletId;
}

std::string Wallet::getOwnerName() const {
  return ownerName;
}

std::string Wallet::getBroker() const {
  return broker;
}

void Wallet::setOwnerName(const std::string &owner) {
  ownerName = owner;
}

void Wallet::setBroker(const std::string &brokerName) {
  broker = brokerName;
}
