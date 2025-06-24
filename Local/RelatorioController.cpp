#include "RelatorioController.hpp"
#include <iostream>

RelatorioController::RelatorioController(CarteiraController *cCtrl, MovimentacaoController *mCtrl, OraculoController *oCtrl)
    : carteiraController(cCtrl), movimentacaoController(mCtrl), oraculoController(oCtrl) {}

double RelatorioController::calcularSaldo(int idCarteira) const {
  double saldo = 0.0;
  auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);
  

  for (const auto &mov : movimentacoes) {
    if (mov.getTipoOperacao() == 'C') {
      saldo += mov.getQuantidade() * mov.getValorUnitario(); 
    } else {
      saldo -= mov.getQuantidade() * mov.getValorUnitario(); 
    }
  }

  return saldo;
}

std::vector<Movimentacao> RelatorioController::obterHistoricoMovimentacao(int idCarteira) const {
  return movimentacaoController->obterMovimentacoes(idCarteira);
}

double RelatorioController::calcularGanhoPerda(int idCarteira) const {
  double totalGasto = 0.0;
  double totalAtual = 0.0;

  auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);
  double cotacaoAtual = oraculoController->obterCotacao("hoje");

  for (const auto &mov : movimentacoes)
  {
    if (mov.getTipoOperacao() == 'C') {  // Compra
        totalGasto += mov.getQuantidade() * mov.getValorUnitario();
        totalAtual += mov.getQuantidade() * cotacaoAtual;
    } else if (mov.getTipoOperacao() == 'V') {  // Venda
        totalGasto -= mov.getQuantidade() * mov.getValorUnitario();
        totalAtual -= mov.getQuantidade() * cotacaoAtual;
    }
  }

  return totalAtual - totalGasto;
}
