# FTCoin

FTCoin is a wallet and financial transaction management system developed in C++ as part of an academic Object-Oriented Programming project. It allows users to create wallets, register transactions, generate reports, and view currency quotes.

## 📁 Project Structure

```text
├── Main.cpp
├── Menu/
│   ├── Menu.cpp
│   ├── MenuHelpers.cpp
│   ├── MenuWallet.cpp
│   ├── MenuTransaction.cpp
│   ├── MenuReports.cpp
│   ├── MenuHelp.cpp
│   └── MenuColors.cpp
├── Model/
│   ├── Wallet.cpp
│   └── Transaction.cpp
├── Controllers/
│   ├── WalletController.cpp
│   ├── TransactionController.cpp
│   ├── OracleController.cpp
│   └── ReportController.cpp
├── Tests/
│   ├── CatchMain.cpp
│   ├── UnitTests/
│   │   ├── WalletControllerTest.cpp
│   │   ├── TransactionControllerTest.cpp
│   │   └── ReportControllerTest.cpp
│   └── Mocks/
│       └── OracleControllerMock.cpp
├── build_ftcoin_linux.sh
├── build_ftcoin_windows.bat
└── README.md
```

## ⚙️ How to Compile
### 📦 Requisitos

- `g++` (version 5.0 or higher)
- Terminal (Linux/Windows/macOS)
- [Catch2](https://github.com/catchorg/Catch2) is already included in the project for unit testing

### 🔧 Compilation

In the terminal, run for linux:
chmod +x build_ftcoin_linux.sh

for windows:
build_ftcoin_windows.bat

This will compile:
./ftcoin → main executable of the project
./tests → unit test executable

## 🧪 Running the Tests
After compiling, run for linux:
./tests

for windows:
tests

## 🚀 How to Use
After compilation, run for linux:
./ftcoin

for windows:
ftcoin

