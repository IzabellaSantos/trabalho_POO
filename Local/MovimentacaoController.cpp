#include "MovimentacaoController.hpp"
#include <vector>

void MovimentacaoController::adicionarMovimentacao(int idCarteira, const std::string& data, char tipo, double quantidade, double valorUnitario) {
  Movimentacao mov(proximoIdMovimentacao++, idCarteira, data, tipo, quantidade, valorUnitario);
  movimentacoesPorCarteira[idCarteira].push_back(mov);
}

std::vector<Movimentacao> MovimentacaoController::obterMovimentacoes(int idCarteira) const {
  auto it = movimentacoesPorCarteira.find(idCarteira);
  if (it != movimentacoesPorCarteira.end()) {
    return it->second;
  }
  return std::vector<Movimentacao>(); // ou return {}; se estiver usando C++11 ou superior
}
