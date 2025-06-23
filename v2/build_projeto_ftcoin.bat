@echo off
cd /d %~dp0

echo Compilando todos os arquivos do projeto...

g++ ^
Main.cpp Menu.cpp ^
model\Carteira.cpp model\Movimentacao.cpp model\Cotacao.cpp ^
controllers\CarteiraController.cpp controllers\MovimentacaoController.cpp controllers\OraculoController.cpp controllers\RelatorioController.cpp ^
dao\CarteiraInMemoryDAO.cpp dao\MovimentacaoInMemoryDAO.cpp dao\OraculoInMemoryDAO.cpp ^
model\simular_cotacoes.cpp ^
-o ftcoin.exe -std=c++11 -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo.
    echo Houve erros na compilacao!
) else (
    echo.
    echo Compilado com sucesso! Executável: ftcoin.exe
)

pause
