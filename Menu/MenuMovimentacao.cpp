#include "Menu.hpp"

void Menu::exibirMenuMovimentacao() {
    int opcao = -1;

    while (true) {
        system("cls");

        printTitulo("MOVIMENTACOES");
        std::cout << "1 - Registrar compra\n"
                  << "2 - Registrar venda\n"
                  << "3 - Listar movimentacoes por carteira\n"
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
                printErro("Opcao invalida, por favor escolha entre 0 e 3."); 
                break;
        }

        aguardarVoltar();
    }
}

void Menu::opcaoRegistrarMovimentacao(char tipo) {
    int idCarteira;
    std::string data;
    double quantidade, valorUnitario;

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para realizar movimentacoes!");
        return;
    }

    std::cout << "ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    if(!carteiraController->obterCarteira(idCarteira)) {
        printErro("Id da carteira nao localizado, tente novamente!");
        return;
    }

    std::cout << "Data da operacao (YYYY-MM-DD): ";
    std::getline(std::cin, data);

    std::cout << "Quantidade: ";
    std::cin >> quantidade;

    std::cout << "Valor unitario: ";
    std::cin >> valorUnitario;
    std::cin.ignore();

    movimentacaoController->adicionarMovimentacao(idCarteira, data, tipo, quantidade, valorUnitario);

    printOpcao("Movimentacao registrada com sucesso.");
}

void Menu::opcaoListarMovimentacoes() {

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao existem carteiras para listar movimentacoes!");
        return;
    }

    int idCarteira;
    std::cout << "Informe o ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    auto movs = movimentacaoController->obterMovimentacoes(idCarteira);
    if (movs.empty()) {
        printErro("Nenhuma movimentacao encontrada.");
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

