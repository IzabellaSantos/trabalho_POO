#ifndef MOVIMENTACAO_INMEMORYDAO_HPP
#define MOVIMENTACAO_INMEMORYDAO_HPP

#include <vector>
#include <memory>
#include "../model/Movimentacao.hpp"

class MovimentacaoInMemoryDAO
{
private:
  std::vector<Movimentacao> movimentacoes;
  int nextIdMovimento;

public:
  MovimentacaoInMemoryDAO();
  int incluir(int idCarteira, const std::string &dataOperacao, char tipoOperacao, double quantidade);
  std::unique_ptr<Movimentacao> recuperar(int idMovimento) const;
  std::vector<Movimentacao> listarPorCarteira(int idCarteira) const;
  bool remover(int idMovimento);
  // Atualização não usual em movimentações financeiras, omitido
};

#endif
