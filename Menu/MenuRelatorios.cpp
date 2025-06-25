#include "Menu.hpp"

void Menu::exibirMenuRelatorios() {
    int opcao = -1;

    while (true) {
        system("cls");

        printInfo("\n=== RELATORIOS ===");
        std::cout << "1 - Exibir saldo atual da carteira\n"
                  << "2 - Exibir historico de movimentacoes\n"
                  << "3 - Exibir ganho ou perda atual\n"
                  << "0 - Voltar\n";
        
        if (!lerOpcao(opcao)) {
            aguardarVoltar();
            continue;
        }

        switch (opcao) {
            case 1: 
                opcaoExibirSaldo(); 
                break;
            case 2: 
                opcaoExibirHistorico(); 
                break;
            case 3: 
                opcaoExibirGanhoPerda(); 
                break;
            case 0: 
                return;
            default: 
                printError("Opcao invalida, por favor escolha entre 0 e 3."); 
                break;
        }

        aguardarVoltar();
    }
}

void Menu::opcaoExibirSaldo() {

    if (!verificarCarteirasDisponiveis()) return;

    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double saldo = relatorioController->calcularSaldo(idCarteira);
    std::cout << "Saldo atual: " << saldo << "\n";
}

void Menu::opcaoExibirHistorico() {

    if (!verificarCarteirasDisponiveis()) return;

    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    auto historico = relatorioController->obterHistoricoMovimentacao(idCarteira);
    if (historico.empty()) {
        printError("Sem movimentacoes.");
    } else {
        for (const auto& m : historico){
            std::cout << "Data: " << m.getDataOperacao()
                      << " | Tipo: " << m.getTipoOperacao()
                      << " | Qtde: " << m.getQuantidade()
                      << " | Valor: " << m.getValorUnitario() << "\n";
        }
    }
}

void Menu::opcaoExibirGanhoPerda() {

    if (!verificarCarteirasDisponiveis()) return;
    
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double resultado = relatorioController->calcularGanhoPerda(idCarteira);
    std::cout << "Ganho/Perda total: " << resultado << "\n";
}