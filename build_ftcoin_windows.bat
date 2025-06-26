@echo off
cd /d %~dp0

echo.
echo ========================================
echo Compilando todos os arquivos do projeto...
echo ========================================

g++ ^
Main.cpp ^
Menu\MenuPrincipal.cpp Menu\MenuCarteira.cpp Menu\MenuMovimentacao.cpp Menu\MenuRelatorio.cpp Menu\MenuAjuda.cpp Menu\MenuUtil.cpp Menu\MenuCarteiraUtil.cpp ^
Model\Carteira.cpp Model\Movimentacao.cpp ^
Local\CarteiraController.cpp Local\MovimentacaoController.cpp Local\OraculoController.cpp Local\RelatorioController.cpp ^
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
-I"Testes" ^
Testes\CatchMain.cpp ^
Testes\LocalTestes\CarteiraControllerTeste.cpp Testes\LocalTestes\MovimentacaoControllerTeste.cpp Testes\LocalTestes\RelatorioControllerTeste.cpp ^
Testes\Mocks\OraculoControllerMock.cpp ^
Model\Carteira.cpp Model\Movimentacao.cpp ^
Local\CarteiraController.cpp Local\MovimentacaoController.cpp Local\OraculoController.cpp Local\RelatorioController.cpp ^
-o testes.exe -static-libstdc++ -static-libgcc

if %errorlevel% neq 0 (
    echo Houve erros na compilacao dos testes!
) else (
    echo Testes compilados com sucesso! Executavel: testes.exe
)

:end
pause
