#ifndef WALLET_HPP
#define WALLET_HPP

#include <string>

// Class representing an investment wallet
class Wallet {
  private:
      int walletId;
      std::string ownerName;
      std::string broker;

  public:
      Wallet();
      Wallet(int id, const std::string &owner, const std::string &brokerName);

      int getWalletId() const;
      std::string getOwnerName() const;
      std::string getBroker() const;

      void setOwnerName(const std::string &owner);
      void setBroker(const std::string &brokerName);
};

#endif
