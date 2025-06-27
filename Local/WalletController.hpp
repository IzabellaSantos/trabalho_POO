// === File: WalletController.hpp ===
#ifndef WALLET_CONTROLLER_HPP
#define WALLET_CONTROLLER_HPP

#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include "../Model/Wallet.hpp"

// WalletController manages wallets, including creation, update, deletion and listing
class WalletController {
  private:
      std::map<int, Wallet> wallets; // Map of wallet IDs to Wallet objects
      int nextWalletId; // ID to assign to the next created wallet

  public:
      WalletController();

      // Creates a new wallet and returns its ID
      int createWallet(const std::string &ownerName, const std::string &broker);

      // Retrieves a wallet by ID
      std::unique_ptr<Wallet> getWallet(int id) const;

      // Updates an existing wallet
      bool updateWallet(const Wallet &updatedWallet);

      // Deletes a wallet by ID
      bool deleteWallet(int id);

      // Lists all wallets
      std::vector<Wallet> listAllWallets() const;

      // Returns true if there are any wallets
      bool hasWallets();

      // Lists all wallets ordered by owner's name
      std::vector<Wallet> listWalletsSortedByName() const;
};

#endif
