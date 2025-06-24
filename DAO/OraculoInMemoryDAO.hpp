#ifndef ORACULO_IN_MEMORY_DAO_HPP
#define ORACULO_IN_MEMORY_DAO_HPP

#include "../Model/Cotacao.hpp"
#include <map>
#include <string>

class OraculoInMemoryDAO
{
private:
  std::map<std::string, Cotacao> cotacoes;

public:
  void adicionarCotacao(const std::string &moeda, double valor);
  double consultarCotacao(const std::string &moeda) const;
  void atualizarCotacao(const std::string &moeda, double novoValor);
};

#endif
