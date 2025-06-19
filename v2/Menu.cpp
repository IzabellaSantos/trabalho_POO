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

// Construtor atualizado
Menu::Menu(CarteiraController *carteiraCtrl, MovimentacaoController *movCtrl, RelatorioController *relatorioCtrl)
    : carteiraController(carteiraCtrl), movimentacaoController(movCtrl), relatorioController(relatorioCtrl) {}

void Menu::printTitulo(const std::string &titulo)
{
  std::cout << CYAN << "\n=== " << titulo << " ===" << RESET << std::endl;
}

void Menu::printOpcao(const std::string &texto)
{
  std::cout << GREEN << texto << RESET << std::endl;
}

void Menu::printErro(const std::string &texto)
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
    std::cout << "Escolha uma opção: ";

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
      printErro("Opção inválida. Tente novamente.");
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
    printErro("Carteira não encontrada.");
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
    printErro("Carteira não encontrada.");
    aguardarVoltar();
    return;
  }

  std::string novoNome, novaCorretora;
  std::cout << "Nome atual: " << carteira->getNomeTitular() << "\n";
  std::cout << "Informe o novo nome do titular (ou deixe em branco para não alterar): ";
  std::getline(std::cin, novoNome);
  if (!novoNome.empty())
    carteira->setNomeTitular(novoNome);

  std::cout << "Corretora atual: " << carteira->getCorretora() << "\n";
  std::cout << "Informe a nova corretora (ou deixe em branco para não alterar): ";
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
  std::cout << "Informe o ID da carteira a ser excluída: ";
  int id;
  std::cin >> id;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (carteiraController->removerCarteira(id))
  {
    printOpcao("Carteira excluída com sucesso.");
  }
  else
  {
    printErro("Carteira não encontrada.");
  }
  aguardarVoltar();
}

void Menu::exibirMenuPrincipalLoop()
{
  while (true)
  {
    printTitulo("Menu Principal");
    std::cout << "1 - Carteira\n";
    std::cout << "0 - Sair\n";
    std::cout << "Escolha uma opção: ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opcao)
    {
    case 1:
      exibirMenuCarteira();
      break;
    case 0:
      std::cout << "Saindo...\n";
      return;
    default:
      printErro("Opção inválida.");
      break;
    }
  }
}
