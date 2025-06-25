#include "Menu.hpp"

Menu::Menu(CarteiraController* carteiraCtrl, 
           MovimentacaoController* movCtrl, 
           RelatorioController* relatorioCtrl)
    : carteiraController(carteiraCtrl), movimentacaoController(movCtrl), relatorioController(relatorioCtrl) {}


void Menu::exibirMenuPrincipalLoop() {
    int opcao = -1;

    while (true) {
        system("cls");
        
        printInfo("Menu Principal");
        std::cout << "1 - Carteira\n"
                  << "2 - Movimentacao\n"
                  << "3 - Relatorios\n"
                  << "4 - Ajuda\n"
                  << "0 - Sair\n";

        if (!lerOpcao(opcao)) {
            aguardarVoltar();
            continue;
        }

        switch (opcao) {
            case 1: 
                exibirMenuCarteira(); 
                break;
            case 2: 
                exibirMenuMovimentacao(); 
                break;
            case 3: 
                exibirMenuRelatorios(); 
                break;
            case 4: 
                exibirMenuAjuda(); 
                break;
            case 0: 
                std::cout << "Saindo do Programa...\n"; 
                return;
            default: 
                printError("Opcao invalida, por favor escolha entre 0 e 4."); 
                aguardarVoltar();
                break;
        }
    }
}
