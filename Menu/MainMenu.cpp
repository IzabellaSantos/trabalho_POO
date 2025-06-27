#include "MenuPrincipal.hpp"

MenuPrincipal::MenuPrincipal(CarteiraController* carteiraCtrl,
                             MovimentacaoController* movCtrl,
                             RelatorioController* relatorioCtrl)
    : menuCarteira(carteiraCtrl),
      menuMovimentacao(carteiraCtrl, movCtrl),
      menuRelatorio(carteiraCtrl, relatorioCtrl),
      menuAjuda() {}


void MenuPrincipal::exibir() {
    int opcao = -1;

    while (true) {
        system("cls");
        
        printInfo("\n=== MENU PRINCIPAL ===");
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
                menuCarteira.exibir(); 
                break;
            case 2: 
                menuMovimentacao.exibir(); 
                break;
            case 3: 
                menuRelatorio.exibir(); 
                break;
            case 4: 
                menuAjuda.exibir(); 
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
