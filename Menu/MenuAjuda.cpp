#include "MenuAjuda.hpp"

MenuAjuda::MenuAjuda() {}

void MenuAjuda::exibir() {
    int opcao = -1;

    while (true) {

        system("cls");

        printInfo("\n=== AJUDA AO USUARIO ===");
        std::cout << "1 - Sobre o sistema\n"
                  << "2 - Creditos\n"
                  << "0 - Voltar\n"
                  << "Escolha uma opcao: ";
        
        if (!lerOpcao(opcao)) {
            aguardarVoltar();
            continue;
        }

        switch (opcao) {
            case 1:
                std::cout << "\nEste sistema permite gerenciar carteiras de moedas virtuais, "
                          << "registrar movimentacoes de compra e venda, e gerar relatorios financeiros.\n";
                break;
            case 2:
                std::cout << "\nFT Coin - Sistema de Apuracao de Ganhos e Perdas\n"
                          << "Autores: Izabella, Leticia e Vitor\n"
                          << "Copyright: Catch2\n"
                          << "Versao: 1.0\n"
                          << "Ano: 2025\n";
                break;
            case 0:
                return;
            default:
                printError("Opcao invalida, por favor escolha entre 0 e 2."); 
                
                break;
        }
        aguardarVoltar();
    }
}
