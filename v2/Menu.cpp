
#include "Menu.hpp"
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Códigos ANSI para cores
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";

Menu::Menu(CarteiraController* carteiraCtrl, MovimentacaoController* movCtrl, RelatorioController* relatorioCtrl)
    : carteiraController(carteiraCtrl), movimentacaoController(movCtrl), relatorioController(relatorioCtrl) {
}

void Menu::printTitulo(const std::string& titulo)
{
    std::cout << CYAN << "\n=== " << titulo << " ===" << RESET << std::endl;
}

void Menu::printOpcao(const std::string& texto)
{
    std::cout << GREEN << texto << RESET << std::endl;
}

void Menu::printErro(const std::string& texto)
{
    std::cout << RED << texto << RESET << std::endl;
}

void Menu::aguardarVoltar()
{
    std::cout << "\nPressione Enter para voltar ao menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::exibirMenuCarteira()
{
    while (true)
    {
        printTitulo("Menu Carteira");
        std::cout << "1 - Incluir nova carteira\n";
        std::cout << "2 - Recuperar carteira por ID\n";
        std::cout << "3 - Editar carteira existente\n";
        std::cout << "4 - Excluir carteira\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa buffer

        switch (opcao)
        {
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
            printErro("Opcao invalida. Tente novamente.");
            break;
        }
    }
}

void Menu::opcaoIncluirCarteira()
{
    std::string nome, corretora;
    std::cout << "Informe o nome do titular: ";
    std::getline(std::cin, nome);
    std::cout << "Informe a corretora: ";
    std::getline(std::cin, corretora);

    int id = carteiraController->criarCarteira(nome, corretora);
    printOpcao("Carteira criada com ID: " + std::to_string(id));
    aguardarVoltar();
}

void Menu::opcaoRecuperarCarteira()
{
    std::cout << "Informe o ID da carteira: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto carteira = carteiraController->obterCarteira(id);
    if (carteira)
    {
        std::cout << "ID: " << carteira->getId() << "\n";
        std::cout << "Nome do Titular: " << carteira->getNomeTitular() << "\n";
        std::cout << "Corretora: " << carteira->getCorretora() << "\n";
    }
    else
    {
        printErro("Carteira no encontrada.");
    }
    aguardarVoltar();
}

void Menu::opcaoEditarCarteira()
{
    std::cout << "Informe o ID da carteira a ser editada: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto carteira = carteiraController->obterCarteira(id);
    if (!carteira)
    {
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

    if (carteiraController->atualizarCarteira(*carteira))
    {
        printOpcao("Carteira atualizada com sucesso.");
    }
    else
    {
        printErro("Falha ao atualizar carteira.");
    }
    aguardarVoltar();
}

void Menu::opcaoExcluirCarteira()
{
    std::cout << "Informe o ID da carteira a ser excluida: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (carteiraController->removerCarteira(id))
    {
        printOpcao("Carteira excluida com sucesso.");
    }
    else
    {
        printErro("Carteira nao encontrada.");
    }
    aguardarVoltar();
}

void Menu::exibirMenuMovimentacao()
{
    while (true)
    {
        printTitulo("Menu Movimentacao");
        std::cout << "1 - Registrar compra\n";
        std::cout << "2 - Registrar venda\n";
        std::cout << "3 - Listar movimentacoes por carteira\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
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
            printErro("Opcao invalida.");
            break;
        }
    }
}

void Menu::opcaoRegistrarMovimentacao(char tipo)
{
    int idCarteira;
    std::string data;
    double quantidade, valorUnitario;

    std::cout << "ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    std::cout << "Data da operacao (YYYY-MM-DD): ";
    std::getline(std::cin, data);

    std::cout << "Quantidade: ";
    std::cin >> quantidade;

    std::cout << "Valor unitario: ";
    std::cin >> valorUnitario;
    std::cin.ignore();

    Movimentacao mov(0, idCarteira, data, tipo, quantidade, valorUnitario); //TODO - ID tem que ser dinamico
    movimentacaoController->adicionarMovimentacao(idCarteira, mov);

    printOpcao("Movimentacao registrada com sucesso.");
    aguardarVoltar();
}

void Menu::opcaoListarMovimentacoes()
{
    int idCarteira;
    std::cout << "Informe o ID da carteira: ";
    std::cin >> idCarteira;
    std::cin.ignore();

    auto movs = movimentacaoController->obterMovimentacoes(idCarteira);
    if (movs.empty())
    {
        printErro("Nenhuma movimentacao encontrada.");
    }
    else
    {
        for (const auto& m : movs)
        {
            std::cout << "ID: " << m.getIdMovimento()
                << " | Data: " << m.getDataOperacao()
                << " | Tipo: " << m.getTipoOperacao()
                << " | Quantidade: " << m.getQuantidade()
                << " | Valor unitario: " << m.getValorUnitario() << "\n";
        }
    }
    aguardarVoltar();
}

void Menu::exibirMenuRelatorios()
{
    while (true)
    {
        printTitulo("Menu Relatorios");
        std::cout << "1 - Exibir saldo atual da carteira\n";
        std::cout << "2 - Exibir histórico de movimentacoes\n";
        std::cout << "3 - Exibir ganho ou perda atual\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
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
            printErro("Opcao invalida.");
            break;
        }
    }
}

void Menu::opcaoExibirSaldo()
{
    int id;
    std::cout << "ID da carteira: ";
    std::cin >> id;
    std::cin.ignore();

    double saldo = relatorioController->calcularSaldo(id);
    std::cout << "Saldo atual: " << saldo << "\n";
    aguardarVoltar();
}

void Menu::opcaoExibirHistorico()
{
    int id;
    std::cout << "ID da carteira: ";
    std::cin >> id;
    std::cin.ignore();

    auto historico = relatorioController->obterHistoricoMovimentacao(id);
    if (historico.empty())
    {
        printErro("Sem movimentacoes.");
    }
    else
    {
        for (const auto& m : historico)
        {
            std::cout << "Data: " << m.getDataOperacao()
                << " | Tipo: " << m.getTipoOperacao()
                << " | Qtde: " << m.getQuantidade()
                << " | Valor: " << m.getValorUnitario() << "\n";
        }
    }
    aguardarVoltar();
}

void Menu::opcaoExibirGanhoPerda()
{
    int id;
    std::cout << "ID da carteira: ";
    std::cin >> id;
    std::cin.ignore();

    double resultado = relatorioController->calcularGanhoPerda(id);
    std::cout << "Ganho/Perda total: " << resultado << "\n";
    aguardarVoltar();
}

void Menu::exibirMenuAjuda()
{
    while (true)
    {
        printTitulo("Menu Ajuda");
        std::cout << "1 - Sobre o sistema\n";
        std::cout << "2 - Creditos\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
        case 1:
            std::cout << "\nEste sistema permite gerenciar carteiras de moedas virtuais, "
                "registrar movimentacoes de compra e venda, e gerar relatorios financeiros "
                "com base em cotacoes simuladas por um oraculo local.\n";
            break;
        case 2:
            std::cout << "\nFT Coin - Sistema de Apuracao de Ganhos e Perdas\n"
                "Versao: 1.0\n"
                "Ano: 2025\n";
            break;
        case 0:
            return;
        default:
            printErro("Opcao invalida.");
            break;
        }

        aguardarVoltar();
    }
}

void Menu::exibirMenuPrincipalLoop()
{
    while (true)
    {
        printTitulo("Menu Principal");
        std::cout << "1 - Carteira\n";
        std::cout << "2 - Movimentacao\n";
        std::cout << "3 - Relatorios\n";
        std::cout << "4 - Ajuda\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
            exibirMenuCarteira();
            break;
        case 2:
            exibirMenuMovimentacao();
            break;
        case 3:
            exibirMenuRelatorios();
            break;
        case 4:
            exibirMenuAjuda();
            break;
        case 0:
            std::cout << "Saindo...\n";
            return;
        default:
            printErro("Opcao invalida.");
            break;
        }
    }
}