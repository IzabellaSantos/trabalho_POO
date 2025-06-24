#include "Menu.hpp"

Menu::Menu(CarteiraController* carteiraCtrl, 
           MovimentacaoController* movCtrl, 
           RelatorioController* relatorioCtrl)
    : carteiraController(carteiraCtrl), movimentacaoController(movCtrl), relatorioController(relatorioCtrl) {}

void Menu::aguardarVoltar() {
    std::cout << "\nPressione Enter para voltar ao menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::exibirMenuPrincipalLoop() {
    int opcao = -1;

    while (true) {
        system("cls");
        
        printTitulo("Menu Principal");
        std::cout << "1 - Carteira\n"
                  << "2 - Movimentacao\n"
                  << "3 - Relatorios\n"
                  << "4 - Ajuda\n"
                  << "0 - Sair\n"
                  << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            printErro("Entrada invalida, por favor digite apenas numeros.");
            std::cin.clear(); // limpa o recebimento de entradas
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora tudo que restou no buffer
            aguardarVoltar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
                printErro("Opcao invalida, por favor escolha entre 0 e 4."); 
                aguardarVoltar();
                break;
        }
    }
}
