#include <iostream>
#include "controllers/CarteiraController.hpp"
#include "controllers/MovimentacaoController.hpp"
#include "controllers/RelatorioController.hpp"
#include "controllers/OraculoController.hpp"
#include "Menu.hpp"

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
