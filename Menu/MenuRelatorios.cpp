#include "Menu.hpp"

void Menu::exibirMenuRelatorios() {
    int opcao = -1;

    while (true) {
        system("cls");

        printTitulo("RELATORIOS");
        std::cout << "1 - Exibir saldo atual da carteira\n"
                  << "2 - Exibir historico de movimentacoes\n"
                  << "3 - Exibir ganho ou perda atual\n"
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
                printErro("Opcao invalida, por favor escolha entre 0 e 3."); 
                break;
        }

        aguardarVoltar();
    }
}

void Menu::opcaoExibirSaldo() {

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para gerar o relatorio!");
        return;
    }

    int idCarteira;
    std::cout << "ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    if(!carteiraController->obterCarteira(idCarteira)) {
        printErro("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double saldo = relatorioController->calcularSaldo(idCarteira);
    std::cout << "Saldo atual: " << saldo << "\n";
}

void Menu::opcaoExibirHistorico() {

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para gerar o relatorio!");
        return;
    }

    int idCarteira;
    std::cout << "ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    if(!carteiraController->obterCarteira(idCarteira)) {
        printErro("Id da carteira nao localizado, tente novamente!");
        return;
    }

    auto historico = relatorioController->obterHistoricoMovimentacao(idCarteira);
    if (historico.empty()) {
        printErro("Sem movimentacoes.");
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

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para gerar o relatorio!");
        return;
    }
    
    int idCarteira;
    std::cout << "ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    if(!carteiraController->obterCarteira(idCarteira)) {
        printErro("Id da carteira nao localizado, tente novamente!");
        return;
    }

    double resultado = relatorioController->calcularGanhoPerda(idCarteira);
    std::cout << "Ganho/Perda total: " << resultado << "\n";
}