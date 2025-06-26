#include "Menu.hpp"

void Menu::exibirMenuMovimentacao() {
    int opcao = -1;

    while (true) {
        system("cls");

        printInfo("\n=== GERENCIAMENTO DE MOVIMENTACOES ===");
        std::cout << "1 - Registrar compra\n"
                  << "2 - Registrar venda\n"
                  << "3 - Listar movimentacoes por carteira\n"
                  << "0 - Voltar\n";

        if (!lerOpcao(opcao)) {
            aguardarVoltar();
            continue;
        }

        switch (opcao) { 
            case 1: 
                opcaoRegistrarMovimentacao('C'); 
                break;
            case 2: 
                opcaoRegistrarMovimentacao('V'); 
                break;
            case 3: 
                opcaoListarMovimentacoes(); 
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

void Menu::opcaoRegistrarMovimentacao(char tipo) {
    std::string data;
    double quantidade, valorUnitario;

    if (!verificarCarteirasDisponiveis()) return;

    printInfo("\nRegistrar Movimentacao");
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if(!carteiraController->obterCarteira(idCarteira)) {
        printError("Id da carteira nao localizado, tente novamente!");
        return;
    }

    std::cout << "Data da operacao (YYYY-MM-DD): ";
    std::getline(std::cin, data);

    std::cout << "Quantidade: ";
    std::cin >> quantidade;
    std::cin.ignore();

    if(quantidade < 0) {
        printError("Quantidade nao pode ser negativa!");
        return;
    }

    std::cout << "Valor unitario: ";
    std::cin >> valorUnitario;
    std::cin.ignore();

    if(valorUnitario < 0) {
        printError("Valor Unitario nao pode ser negativo!");
        return;
    }

    movimentacaoController->adicionarMovimentacao(idCarteira, data, tipo, quantidade, valorUnitario);

    printSucess("Movimentacao registrada com sucesso.");
}

void Menu::opcaoListarMovimentacoes() {

    if (!verificarCarteirasDisponiveis()) return;

    printInfo("\nListar Movimentacoes por ID");
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    auto movs = movimentacaoController->obterMovimentacoes(idCarteira);
    if (movs.empty()) {
        printError("Nenhuma movimentacao encontrada.");
    } else {
        for (const auto& m : movs) {
            std::cout << "ID: " << m.getIdMovimento()
                << " | Data: " << m.getDataOperacao()
                << " | Tipo: " << m.getTipoOperacao()
                << " | Quantidade: " << m.getQuantidade()
                << " | Valor unitario: " << m.getValorUnitario() << "\n";
        }
    }
}

