// Movimentacao.hpp
#ifndef MOVIMENTACAO_HPP
#define MOVIMENTACAO_HPP

#include <string>

class Movimentacao
{
private:
  int idMovimento;
  int idCarteira;
  std::string dataOperacao;
  char tipoOperacao;
  double quantidade;
  double valorUnitario; // ✅ necessário para RelatorioController

public:
  Movimentacao() = default;
  Movimentacao(int idMovimento, int idCarteira, const std::string &dataOperacao, char tipoOperacao, double quantidade, double valorUnitario);

  int getIdMovimento() const;
  int getIdCarteira() const;
  const std::string &getDataOperacao() const;
  char getTipoOperacao() const;
  double getQuantidade() const;
  double getValorUnitario() const;
};

#endif
