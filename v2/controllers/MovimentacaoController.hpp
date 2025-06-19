#ifndef MOVIMENTACAOCONTROLLER_HPP
#define MOVIMENTACAOCONTROLLER_HPP

#include <unordered_map>
#include <vector>
#include "../model/Movimentacao.hpp"

class MovimentacaoController
{
private:
  std::unordered_map<int, std::vector<Movimentacao>> movimentacoesPorCarteira;

public:
  void adicionarMovimentacao(int idCarteira, const Movimentacao &mov);
  std::vector<Movimentacao> obterMovimentacoes(int idCarteira) const;
};

#endif
