#include "OraculoInMemoryDAO.hpp"
#include <stdexcept>

void OraculoInMemoryDAO::adicionarCotacao(const std::string &moeda, double valor)
{
  cotacoes[moeda] = Cotacao(moeda, valor);
}

double OraculoInMemoryDAO::consultarCotacao(const std::string &moeda) const
{
  auto it = cotacoes.find(moeda);
  if (it != cotacoes.end())
  {
    return it->second.getValor();
  }
  throw std::runtime_error("Moeda nao encontrada no oraculo.");
}

void OraculoInMemoryDAO::atualizarCotacao(const std::string &moeda, double novoValor)
{
  auto it = cotacoes.find(moeda);
  if (it != cotacoes.end())
  {
    it->second.setValor(novoValor);
  }
  else
  {
    throw std::runtime_error("Moeda nao encontrada para atualizacao.");
  }
}
