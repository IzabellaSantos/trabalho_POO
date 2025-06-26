#include "MenuCarteira.hpp"

MenuCarteira::MenuCarteira(CarteiraController* controller)
    : carteiraController(controller) {}

void MenuCarteira::exibir() {
    int opcao = -1;

    while (true) {
        system("cls");

        printInfo("\n=== GERENCIAMENTO DE CARTEIRAS === ");
        std::cout << "1 - Incluir nova carteira\n"
                  << "2 - Recuperar carteira por ID\n"
                  << "3 - Editar carteira existente\n"
                  << "4 - Excluir carteira\n"
                  << "0 - Voltar\n";
        
        if (!lerOpcao(opcao)) {
            aguardarVoltar();
            continue;
        }

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

void MenuCarteira::opcaoIncluirCarteira() {
    std::string nome, corretora;

    printInfo("\nCriar Carteira");
            
    std::cout<< "Informe o nome do titular: ";
    std::getline(std::cin, nome);

    std::cout << "Informe a corretora: ";
    std::getline(std::cin, corretora);

    int id = carteiraController->criarCarteira(nome, corretora);
    printSucess("Carteira criada com sucesso! ID gerado: " + std::to_string(id));
}

void MenuCarteira::opcaoRecuperarCarteira() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;

    printInfo("\nRecuperar de Carteira");
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;
    
    auto carteira = carteiraController->obterCarteira(idCarteira);

    if (carteira) {
        exibirCarteira(*carteira);
    } else {
        printError("Carteira nao encontrada.");
    }
}

void MenuCarteira::opcaoEditarCarteira() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;

    printInfo("\nEditar Carteira");
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

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
        printSucess("\nCarteira atualizada com sucesso.");
        exibirCarteira(*carteira);
    } else {
        printError("Falha ao atualizar carteira.");
    }
}

void MenuCarteira::opcaoExcluirCarteira() {

    if (!verificarCarteirasDisponiveis(carteiraController)) return;

    printInfo("\nExcluir Carteira");
    int idCarteira = lerIdCarteira();

    if (idCarteira == -1) return;

    if (carteiraController->removerCarteira(idCarteira)) {
        printSucess("Carteira excluida com sucesso.");
    } else {
        printError("Carteira nao encontrada.");
    }
}

