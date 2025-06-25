#!/bin/bash

clear

echo
echo "========================================"
echo "Compilando todos os arquivos do projeto..."
echo "========================================"

g++ \
Main.cpp \
Menu/Menu.cpp Menu\MenuHelpers.cpp  Menu/MenuCarteira.cpp Menu/MenuMovimentacao.cpp Menu/MenuRelatorios.cpp Menu/MenuAjuda.cpp Menu/MenuCores.cpp \
Model/Carteira.cpp Model/Movimentacao.cpp Model/Cotacao.cpp \
Local/CarteiraController.cpp Local/MovimentacaoController.cpp Local/OraculoController.cpp Local/RelatorioController.cpp \
DAO/CarteiraInMemoryDAO.cpp DAO/MovimentacaoInMemoryDAO.cpp DAO/OraculoInMemoryDAO.cpp \
Model/simular_cotacoes.cpp \
-o ftcoin -std=c++11 -static-libstdc++ -static-libgcc

if [ $? -ne 0 ]; then
    echo "Houve erros na compilação do projeto!"
    exit 1
else
    echo "Projeto compilado com sucesso! Executável: ./ftcoin"
fi

echo
echo "========================================"
echo "Compilando os testes com Catch2..."
echo "========================================"

g++ -std=c++11 \
-I"./Testes" \
Testes/CatchMain.cpp \
Testes/LocalTestes/CarteiraControllerTeste.cpp Testes/LocalTestes/MovimentacaoControllerTeste.cpp Testes/LocalTestes/RelatorioControllerTeste.cpp \
Testes/Mocks/OraculoControllerMock.cpp \
Model/Carteira.cpp Model/Movimentacao.cpp Model/Cotacao.cpp \
Local/CarteiraController.cpp Local/MovimentacaoController.cpp Local/OraculoController.cpp Local/RelatorioController.cpp \
-o testes -static-libstdc++ -static-libgcc

if [ $? -ne 0 ]; then
    echo "Houve erros na compilação dos testes!"
    echo
    exit 1
else
    echo "Testes compilados com sucesso! Executável: ./testes"
    echo
fi
