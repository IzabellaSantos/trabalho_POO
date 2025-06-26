// Movimentacao.hpp
#ifndef MOVIMENTACAO_HPP
#define MOVIMENTACAO_HPP

#include <string>

class Movimentacao {
  private:
    int idMovimento;
    std::string dataOperacao;
    char tipoOperacao;
    double quantidade;
    double valorUnitario; // ✅ necessário para RelatorioController

  public:
    Movimentacao() = default;
    Movimentacao(int idMovimento,
                 const std::string &dataOperacao, 
                 char tipoOperacao, 
                 double quantidade, 
                 double valorUnitario);

    int getIdMovimento() const;
    const std::string &getDataOperacao() const;
    char getTipoOperacao() const;
    double getQuantidade() const;
    double getValorUnitario() const;
};

#endif
