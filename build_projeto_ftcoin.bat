@echo off
cd /d %~dp0

echo.
echo ========================================
echo Compilando todos os arquivos do projeto...
echo ========================================

g++ ^
Main.cpp ^
Menu\Menu.cpp Menu\MenuCarteira.cpp Menu\MenuMovimentacao.cpp Menu\MenuRelatorios.cpp Menu\MenuAjuda.cpp Menu\MenuCores.cpp ^
Model\Carteira.cpp Model\Movimentacao.cpp Model\Cotacao.cpp ^
Local\CarteiraController.cpp Local\MovimentacaoController.cpp Local\OraculoController.cpp Local\RelatorioController.cpp ^
DAO\CarteiraInMemoryDAO.cpp DAO\MovimentacaoInMemoryDAO.cpp DAO\OraculoInMemoryDAO.cpp ^
Model\simular_cotacoes.cpp ^
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
-I"C:\Users\bella\Programming\C\trabalho_POO\v2\Testes" ^
Testes\CatchMain.cpp ^
Testes\LocalTestes\CarteiraControllerTeste.cpp Testes\LocalTestes\MovimentacaoControllerTeste.cpp Testes\LocalTestes\RelatorioControllerTeste.cpp ^
Testes\Mocks\OraculoControllerMock.cpp ^
Model\Carteira.cpp Model\Movimentacao.cpp Model\Cotacao.cpp ^
Local\CarteiraController.cpp Local\MovimentacaoController.cpp Local\OraculoController.cpp Local\RelatorioController.cpp ^
-o testes.exe -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo Houve erros na compilacao dos testes!
) else (
    echo Testes compilados com sucesso! Executavel: testes.exe
)

:end
pause
