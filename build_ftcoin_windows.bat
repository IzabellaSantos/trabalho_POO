@echo off
cd /d %~dp0

echo.
echo ========================================
echo Compilando todos os arquivos do projeto...
echo ========================================

g++ ^
Main.cpp ^
Menu/MainMenu.cpp Menu/MenuWallet.cpp Menu/MenuWalletUtil.cpp ^
Menu/MenuTransaction.cpp Menu/MenuReport.cpp Menu/MenuHelp.cpp ^
Menu/MenuUtil.cpp ^
Model/Wallet.cpp Model/Transaction.cpp ^
Local/WalletController.cpp Local/TransactionController.cpp Local/oracleController.cpp Local/reportController.cpp ^
-o ftcoin.exe -std=c++11 -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo Houve erros na compilacao do projeto!
    goto end
) else (
    echo Projeto compilado com sucesso! Executavel: ftcoin.exe
)

echo.
echo ========================================
echo Compilando os testes com Catch2...
echo ========================================

g++ -std=c++11 ^
-I./Testes ^
Testes/catchMain.cpp ^
Testes/LocalTestes/WalletControllerTests.cpp ^
Testes/LocalTestes/TransactionControllerTests.cpp ^
Testes/LocalTestes/reportControllerTests.cpp ^
Testes/Mocks/OracleControllerMock.cpp ^
Model/Wallet.cpp Model/Transaction.cpp ^
Local/WalletController.cpp Local/TransactionController.cpp Local/oracleController.cpp Local/reportController.cpp ^
-o testes.exe -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo Houve erros na compilacao dos testes!
) else (
    echo Testes compilados com sucesso! Executavel: testes.exe
)

:end
pause
