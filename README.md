# FTCoin

FTCoin é um sistema de gerenciamento de carteiras e movimentações financeiras desenvolvido em C++ como parte de um projeto acadêmico de Programação Orientada a Objetos. Ele permite criar carteiras, registrar movimentações, gerar relatórios e visualizar cotações.

## 📁 Estrutura do Projeto

├── Main.cpp
├── Menu/
│ ├── Menu.cpp
│ ├── MenuHelpers.cpp
│ ├── MenuCarteira.cpp
│ ├── MenuMovimentacao.cpp
│ ├── MenuRelatorios.cpp
│ ├── MenuAjuda.cpp
│ └── MenuCores.cpp
├── Model/
│ ├── Carteira.cpp
│ ├── Movimentacao.cpp
├── Local/
│ ├── CarteiraController.cpp
│ ├── MovimentacaoController.cpp
│ ├── OraculoController.cpp
│ └── RelatorioController.cpp
├── Testes/
│ ├── CatchMain.cpp
│ ├── LocalTestes/
│ │ ├── CarteiraControllerTeste.cpp
│ │ ├── MovimentacaoControllerTeste.cpp
│ │ └── RelatorioControllerTeste.cpp
│ └── Mocks/
│ └── OraculoControllerMock.cpp
├── build.sh
└── README.md

## ⚙️ Como Compilar

### 📦 Requisitos

- `g++` (versão 5.0 ou superior)
- Terminal Linux/Windows/MacOS
- [Catch2](https://github.com/catchorg/Catch2) já incluído no projeto para testes

### 🔧 Compilação

No terminal, execute:
chmod +x build.sh
./build.sh

Isso irá compilar:
./ftcoin → executável principal do projeto
./testes → executável dos testes unitários

## 🧪 Executando os Testes
Após compilar, execute:
./testes

## 🚀 Como Usar
Após a compilação, rode o sistema com:
./ftcoin


