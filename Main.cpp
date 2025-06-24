#include <iostream>
#include "Local/CarteiraController.hpp"
#include "Local/MovimentacaoController.hpp"
#include "Local/RelatorioController.hpp"
#include "Local/OraculoController.hpp"
#include "Menu/Menu.hpp"

int main()
{
  CarteiraController carteiraController;
  MovimentacaoController movimentacaoController;
  OraculoController oraculoController;

  RelatorioController relatorioController(&carteiraController, &movimentacaoController, &oraculoController);

  Menu menu(&carteiraController, &movimentacaoController, &relatorioController);
  menu.exibirMenuPrincipalLoop();

  return 0;
}
