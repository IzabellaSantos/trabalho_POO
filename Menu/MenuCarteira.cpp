#include "Menu.hpp"

void Menu::exibirMenuCarteira() {
    int opcao = -1;

    while (true) {
        system("cls");

        printTitulo("GERENCIAMENTO DE CARTEIRAS");
        std::cout << "1 - Incluir nova carteira\n"
                  << "2 - Recuperar carteira por ID\n"
                  << "3 - Editar carteira existente\n"
                  << "4 - Excluir carteira\n"
                  << "0 - Voltar\n"
                  << "Escolha uma opcao: ";

        
        if (!(std::cin >> opcao)) {
            printErro("Entrada invalida! Por favor, digite apenas numeros.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            aguardarVoltar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: 
                opcaoIncluirCarteira(); 
                break;
            case 2: 
                opcaoRecuperarCarteira(); 
                break;
            case 3: 
                opcaoEditarCarteira(); 
                break;
            case 4: 
                opcaoExcluirCarteira(); 
                break;
            case 0: 
                return;
            default: 
                printErro("Opcao invalida, por favor escolha entre 0 e 4."); 
                break;
        }

        aguardarVoltar();
    }
}

void Menu::opcaoIncluirCarteira() {
    std::string nome, corretora;

    std::cout << "\n--- Criacao de Nova Carteira ---\n"
              << "Informe o nome do titular: ";
    std::getline(std::cin, nome);

    std::cout << "Informe a corretora: ";
    std::getline(std::cin, corretora);

    int id = carteiraController->criarCarteira(nome, corretora);
    printOpcao("Carteira criada com sucesso! ID gerado: " + std::to_string(id));
}

void Menu::opcaoRecuperarCarteira() {

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para realizar a acao");
        return;
    }

    int id;

    std::cout << "\n--- Recuperacao de Carteira ---\n"
              << "Informe o ID da carteira: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto carteira = carteiraController->obterCarteira(id);
    if (carteira) {
        std::cout << "ID: " << carteira->getId() << "\n";
        std::cout << "Nome do Titular: " << carteira->getNomeTitular() << "\n";
        std::cout << "Corretora: " << carteira->getCorretora() << "\n";
    } else {
        printErro("Carteira nao encontrada.");
    }
}

void Menu::opcaoEditarCarteira() {

    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para realizar a acao");
        return;
    }

    std::cout << "\n--- Edicao de Carteira ---\n"
              << "Informe o ID da carteira a ser editada: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto carteira = carteiraController->obterCarteira(id);
    if (!carteira) {
        printErro("Carteira nao encontrada.");
        aguardarVoltar();
        return;
    }

    std::string novoNome, novaCorretora;
    std::cout << "Nome atual: " << carteira->getNomeTitular() << "\n";
    std::cout << "Informe o novo nome do titular (ou deixe em branco para nao alterar): ";
    std::getline(std::cin, novoNome);
    if (!novoNome.empty())
        carteira->setNomeTitular(novoNome);

    std::cout << "Corretora atual: " << carteira->getCorretora() << "\n";
    std::cout << "Informe a nova corretora (ou deixe em branco para nao alterar): ";
    std::getline(std::cin, novaCorretora);
    if (!novaCorretora.empty())
        carteira->setCorretora(novaCorretora);

    if (carteiraController->atualizarCarteira(*carteira)) {
        printOpcao("Carteira atualizada com sucesso.");
    } else {
        printErro("Falha ao atualizar carteira.");
    }
}

void Menu::opcaoExcluirCarteira() {
    if(carteiraController->verificarExistenciaCarteiras()){
        printErro("Nao foram encontradas carteiras para realizar a acao");
        return;
    }

    std::cout << "\n--- Excluir Carteira ---\n"
              << "Informe o ID da carteira a ser excluida: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (carteiraController->removerCarteira(id)) {
        printOpcao("Carteira excluida com sucesso.");
    } else {
        printErro("Carteira nao encontrada.");
    }
}

