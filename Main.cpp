#include <iostream>
#include "Local/CarteiraController.hpp"
#include "Local/MovimentacaoController.hpp"
#include "Local/RelatorioController.hpp"
#include "Local/OraculoController.hpp"
#include "Menu/MenuPrincipal.hpp"

int main() {
  CarteiraController carteiraController;
  MovimentacaoController movimentacaoController;
  OraculoController oraculoController;

  RelatorioController relatorioController(&carteiraController, &movimentacaoController, &oraculoController);

  MenuPrincipal menuPrincipal(&carteiraController, &movimentacaoController, &relatorioController);
  menuPrincipal.exibir();

  return 0;
}
