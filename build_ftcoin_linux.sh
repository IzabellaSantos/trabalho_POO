#!/bin/bash

echo
echo "========================================"
echo "Compilando todos os arquivos do projeto..."
echo "========================================"

g++ \
Main.cpp \
Menu/MainMenu.cpp Menu/MenuWallet.cpp Menu/MenuWalletUtil.cpp \
Menu/MenuTransaction.cpp Menu/MenuReport.cpp Menu/MenuHelp.cpp \
Menu/MenuUtil.cpp \
Model/Wallet.cpp Model/Transaction.cpp \
Local/WalletController.cpp Local/TransactionController.cpp Local/oracleController.cpp Local/reportController.cpp \
-o ftcoin -std=c++11

if [ $? -ne 0 ]; then
    echo "Houve erros na compilação do projeto!"
else
    echo "Projeto compilado com sucesso! Executável: ./ftcoin"
fi

echo
echo "========================================"
echo "Compilando os testes com Catch2..."
echo "========================================"

g++ -std=c++11 \
-I./Testes \
Testes/catchMain.cpp \
Testes/LocalTestes/WalletControllerTests.cpp \
Testes/LocalTestes/TransactionControllerTests.cpp \
Testes/LocalTestes/reportControllerTests.cpp \
Testes/Mocks/OracleControllerMock.cpp \
Model/Wallet.cpp Model/Transaction.cpp \
Local/WalletController.cpp Local/TransactionController.cpp Local/oracleController.cpp Local/reportController.cpp \
-o testes2

if [ $? -ne 0 ]; then
    echo "Houve erros na compilação dos testes!"
else
    echo "Testes compilados com sucesso! Executável: ./testes"
fi

echo
