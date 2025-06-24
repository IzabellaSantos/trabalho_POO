#include "Menu.hpp"

void Menu::exibirMenuAjuda() {
    int opcao = -1;

    while (true) {

        system("cls");

        printTitulo("AJUDA AO USUARIO");
        std::cout << "1 - Sobre o sistema\n"
                  << "2 - Creditos\n"
                  << "0 - Voltar\n"
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
                std::cout << "\nEste sistema permite gerenciar carteiras de moedas virtuais, "
                          << "registrar movimentacoes de compra e venda, e gerar relatorios financeiros.\n";
                break;
            case 2:
                std::cout << "\nFT Coin - Sistema de Apuracao de Ganhos e Perdas\n"
                          << "Autores: Izabella, Leticia e Vitor"
                          << "Copyright: Catch2"
                          << "Versao: 1.0\n"
                          << "Ano: 2025\n";
                break;
            case 0:
                return;
            default:
                printErro("Opcao invalida, por favor escolha entre 0 e 2."); 
                
                break;
        }
        aguardarVoltar();
    }
}
