#include "Menu.hpp"

void Menu::exibirMenuCarteira() {
    int opcao = -1;

    while (true) {
        system("cls");

        printInfo("GERENCIAMENTO DE CARTEIRAS");
        std::cout << "1 - Incluir nova carteira\n"
                  << "2 - Recuperar carteira por ID\n"
                  << "3 - Editar carteira existente\n"
                  << "4 - Excluir carteira\n"
                  << "0 - Voltar\n"
                  << "Escolha uma opcao: ";

        
        if (!lerOpcao(opcao)) {
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
                printError("Opcao invalida, por favor escolha entre 0 e 4."); 
                break;
        }

        aguardarVoltar();
    }
}

void Menu::opcaoIncluirCarteira() {
    std::string nome, corretora;

    std::cout << "\n--- Criar de Nova Carteira ---\n"
              << "Informe o nome do titular: ";
    std::getline(std::cin, nome);

    std::cout << "Informe a corretora: ";
    std::getline(std::cin, corretora);

    int id = carteiraController->criarCarteira(nome, corretora);
    printSucess("Carteira criada com sucesso! ID gerado: " + std::to_string(id));
}

void Menu::opcaoRecuperarCarteira() {

    if (!verificarCarteirasDisponiveis()) return;

    std::cout << "\n--- Recuperar de Carteira ---\n";
    int idCarteira = lerIdCarteira();

    auto carteira = carteiraController->obterCarteira(idCarteira);

    if (carteira) {
        exibirCarteira(*carteira);
    } else {
        printError("Carteira nao encontrada.");
    }
}

void Menu::opcaoEditarCarteira() {

    if (!verificarCarteirasDisponiveis()) return;

    std::cout << "\n--- Editar de Carteira ---\n";
    int idCarteira = lerIdCarteira();

    auto carteira = carteiraController->obterCarteira(idCarteira);
    
    if (!carteira) {
        printError("Carteira nao encontrada.");
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
        printSucess("Carteira atualizada com sucesso.\n");
        exibirCarteira(*carteira);
    } else {
        printError("Falha ao atualizar carteira.");
    }
}

void Menu::opcaoExcluirCarteira() {

    if (!verificarCarteirasDisponiveis()) return;

    std::cout << "\n--- Excluir Carteira ---\n";
    int idCarteira = lerIdCarteira();

    if (carteiraController->removerCarteira(idCarteira)) {
        printSucess("Carteira excluida com sucesso.");
    } else {
        printError("Carteira nao encontrada.");
    }
}

