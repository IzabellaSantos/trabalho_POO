#!/bin/bash

echo
echo "========================================"
echo "Compilando todos os arquivos do projeto..."
echo "========================================"

g++ \
Main.cpp \
Menu/MenuPrincipal.cpp Menu/MenuCarteira.cpp Menu/MenuMovimentacao.cpp Menu/MenuRelatorio.cpp Menu/MenuAjuda.cpp Menu/MenuUtil.cpp Menu/MenuCarteiraUtil.cpp \
Model/Carteira.cpp Model/Movimentacao.cpp \
Local/CarteiraController.cpp Local/MovimentacaoController.cpp Local/OraculoController.cpp Local/RelatorioController.cpp \
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
Testes/CatchMain.cpp \
Testes/LocalTestes/CarteiraControllerTeste.cpp Testes/LocalTestes/MovimentacaoControllerTeste.cpp Testes/LocalTestes/RelatorioControllerTeste.cpp \
Testes/Mocks/OraculoControllerMock.cpp \
Model/Carteira.cpp Model/Movimentacao.cpp \
Local/CarteiraController.cpp Local/MovimentacaoController.cpp Local/OraculoController.cpp Local/RelatorioController.cpp \
-o testes2

if [ $? -ne 0 ]; then
    echo "Houve erros na compilação dos testes!"
else
    echo "Testes compilados com sucesso! Executável: ./testes"
fi

echo

