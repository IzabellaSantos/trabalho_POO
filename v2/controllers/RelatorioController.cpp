#include "RelatorioController.hpp"
#include <iostream>

RelatorioController::RelatorioController(CarteiraController *cCtrl, MovimentacaoController *mCtrl, OraculoController *oCtrl)
    : carteiraController(cCtrl), movimentacaoController(mCtrl), oraculoController(oCtrl) {}

double RelatorioController::calcularSaldo(int idCarteira) const
{
  double saldo = 0.0;
  auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);

  for (const auto &mov : movimentacoes)
  {
    saldo += mov.getQuantidade() * mov.getValorUnitario();
  }

  return saldo;
}

std::vector<Movimentacao> RelatorioController::obterHistoricoMovimentacao(int idCarteira) const
{
  return movimentacaoController->obterMovimentacoes(idCarteira);
}

double RelatorioController::calcularGanhoPerda(int idCarteira) const
{
  double totalGasto = 0.0;
  double totalAtual = 0.0;

  auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);
  for (const auto &mov : movimentacoes)
  {
    double valorCompra = mov.getQuantidade() * mov.getValorUnitario();
    totalGasto += valorCompra;

    double cotacaoAtual = oraculoController->obterCotacao("hoje");
    double valorAtual = mov.getQuantidade() * cotacaoAtual;
    totalAtual += valorAtual;
  }

  return totalAtual - totalGasto;
}
