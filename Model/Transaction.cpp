#include "Transaction.hpp"

// Default constructor
Transaction::Transaction() 
    : transactionId(0), transactionDate(""), transactionType('C'), quantity(0.0), unitPrice(0.0) {}

// Parameterized constructor
Transaction::Transaction(int id, const std::string &date, char type, double qty, double price)
    : transactionId(id), transactionDate(date), transactionType(type), quantity(qty), unitPrice(price) {}

int Transaction::getTransactionId() const {
  return transactionId;
}

std::string Transaction::getTransactionDate() const {
  return transactionDate;
}

char Transaction::getTransactionType() const {
  return transactionType;
}

double Transaction::getQuantity() const {
  return quantity;
}

double Transaction::getUnitPrice() const {
  return unitPrice;
}

void Transaction::setTransactionDate(const std::string &date) {
  transactionDate = date;
}

void Transaction::setTransactionType(char type) {
  transactionType = type;
}

void Transaction::setQuantity(double qty) {
  quantity = qty;
}

void Transaction::setUnitPrice(double price) {
  unitPrice = price;
}
