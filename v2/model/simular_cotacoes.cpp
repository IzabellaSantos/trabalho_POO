#include "simular_cotacoes.hpp"

void simularCotacoes(OraculoInMemoryDAO &oraculo)
{
  oraculo.adicionarCotacao("BTC", 250000.0);
  oraculo.adicionarCotacao("ETH", 11000.0);
  oraculo.adicionarCotacao("SOL", 350.0);
  oraculo.adicionarCotacao("ADA", 2.3);
}
