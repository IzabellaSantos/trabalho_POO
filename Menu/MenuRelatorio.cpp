#include "MenuRelatorio.hpp"

MenuRelatorio::MenuRelatorio(CarteiraController* carteiraCtrl,
                             RelatorioController* relatorioCtrl)
    : carteiraController(carteiraCtrl), relatorioController(relatorioCtrl) {}
    
void MenuRelatorio::exibir() {
    int opcao = -1;

    while (true) {
        system("cls");

        printInfo("\n=== RELATORIOS ===");
        std::cout << "1 - Exibir saldo atual da carteira\n"
                  << "2 - Exibir historico de movimentacao por ID\n"
                  << "3 - Exibir ganho ou perda atual das carteiras\n"
                  << "4 - Listar carteiras ordenadas por ID\n"
                  << "5 - Listar carteiras ordenadas por nome do titular\n"
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
            case 4:
                opcaoListarCarteirasID();
                break;
            case 5:
                opcaoListarCarteirasPorNome();
                break;
            case 0: 
                return;
            default: 
                printError("Opcao invalida, por favor escolha entre 0 e 5."); 
                break;
        }

        aguardarVoltar();
    }
}

void MenuRelatorio::opcaoExibirSaldo() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;

    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double saldo = relatorioController->calcularSaldo(idCarteira);
    std::cout << "Saldo atual: " << saldo << "\n";
}

void MenuRelatorio::opcaoExibirHistorico() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;

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

void MenuRelatorio::opcaoExibirGanhoPerda() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;
    
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double resultado = relatorioController->calcularGanhoPerda(idCarteira);
    printInfo("\nGanho/Perda total");
    std::cout << resultado;
}

void MenuRelatorio::opcaoListarCarteirasID() {
    std::vector<Carteira> carteiras = carteiraController->listarTodasCarteiras();

    if (carteiras.empty()) {
        printError("Nenhuma carteira encontrada.");
        return;
    }

    printInfo("\nCarteiras cadastradas (ordenadas por ID)");
    for (const Carteira& carteira : carteiras) {
        exibirCarteira(carteira);
        std::cout << "\n";
    }
}

void MenuRelatorio::opcaoListarCarteirasPorNome() {
    std::vector<Carteira> carteiras = carteiraController->listarCarteirasOrdenadasPorNome();

    if (carteiras.empty()) {
        printError("Nenhuma carteira encontrada.");
        return;
    }

    printInfo("\nCarteiras cadastradas (ordenadas por nome do titular)");
    for (const Carteira& carteira : carteiras) {
        exibirCarteira(carteira);
        std::cout << "\n";
    }
}

