#include "Cotacao.hpp"

Cotacao::Cotacao(std::string moeda, double valor)
    : moeda(std::move(moeda)), valor(valor) {}

std::string Cotacao::getMoeda() const
{
  return moeda;
}

double Cotacao::getValor() const
{
  return valor;
}

void Cotacao::setValor(double novoValor)
{
  valor = novoValor;
}
