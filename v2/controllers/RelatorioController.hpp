#ifndef RELATORIO_CONTROLLER_HPP
#define RELATORIO_CONTROLLER_HPP

#include <vector>
#include "../model/Carteira.hpp"
#include "../model/Movimentacao.hpp"
#include "CarteiraController.hpp"
#include "MovimentacaoController.hpp"
#include "OraculoController.hpp"

class RelatorioController
{
private:
  CarteiraController *carteiraController;
  MovimentacaoController *movimentacaoController;
  OraculoController *oraculoController;

public:
  RelatorioController(CarteiraController *cCtrl, MovimentacaoController *mCtrl, OraculoController *oCtrl);

  double calcularSaldo(int idCarteira) const;
  std::vector<Movimentacao> obterHistoricoMovimentacao(int idCarteira) const;
  double calcularGanhoPerda(int idCarteira) const;
};

#endif
