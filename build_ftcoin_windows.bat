@echo off
cd /d %~dp0

echo.
echo ========================================
echo Compiling all project files...
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
    echo There were errors during project compilation!
    goto end
) else (
    echo Project compiled successfully! Executable: ftcoin.exe
)

echo.
echo ========================================
echo Compiling tests with Catch2...
echo ========================================

g++ -std=c++11 ^
-I./Testes ^
Testes/catchMain.cpp ^
Testes/LocalTests/WalletControllerTests.cpp ^
Testes/LocalTests/TransactionControllerTests.cpp ^
Testes/LocalTests/reportControllerTests.cpp ^
Testes/Mocks/OracleControllerMock.cpp ^
Model/Wallet.cpp Model/Transaction.cpp ^
Local/WalletController.cpp Local/TransactionController.cpp Local/oracleController.cpp Local/reportController.cpp ^
-o tests.exe -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo There were errors during test compilation!
) else (
    echo Tests compiled successfully! Executable: tests.exe
)

:end
pause
