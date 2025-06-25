#ifndef MOVIMENTACAOCONTROLLER_HPP
#define MOVIMENTACAOCONTROLLER_HPP

#include <unordered_map>
#include <vector>
#include "../Model/Movimentacao.hpp"

class MovimentacaoController {
  private:
      std::unordered_map<int, std::vector<Movimentacao>> movimentacoesPorCarteira; // Dicionario [idMovimentacao: data, tipo, quantidade, valorUnitario]
      int proximoIdMovimentacao = 0;

  public:
      void adicionarMovimentacao(int idCarteira, const std::string& data, char tipo, double quantidade, double valorUnitario);
      std::vector<Movimentacao> obterMovimentacoes(int idCarteira) const;
};

#endif
