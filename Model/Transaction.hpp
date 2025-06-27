#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

// Represents a single transaction: buy ('C') or sell ('V')
class Transaction {
  private:
      int transactionId;
      std::string transactionDate;  // format YYYY-MM-DD
      char transactionType;         // 'C' = Buy, 'V' = Sell
      double quantity;
      double unitPrice;

  public:
      Transaction();
      Transaction(int id, const std::string &date, char type, double qty, double price);

      int getTransactionId() const;
      std::string getTransactionDate() const;
      char getTransactionType() const;
      double getQuantity() const;
      double getUnitPrice() const;

      void setTransactionDate(const std::string &date);
      void setTransactionType(char type);
      void setQuantity(double qty);
      void setUnitPrice(double price);
};

#endif
