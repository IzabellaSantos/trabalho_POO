#ifndef COTACAO_HPP
#define COTACAO_HPP

#include <string>

class Cotacao
{
private:
  std::string moeda;
  double valor;

public:
  Cotacao(std::string moeda, double valor);
  std::string getMoeda() const;
  double getValor() const;
  void setValor(double novoValor);
};

#endif
