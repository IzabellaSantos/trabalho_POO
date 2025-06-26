// Carteira.cpp
#include "Carteira.hpp"

Carteira::Carteira(int carteiraId, const std::string &nomeTitular, const std::string &corretora)
    : carteiraId(carteiraId), nomeTitular(nomeTitular), corretora(corretora) {}

int Carteira::getCarteiraId() const {
  return carteiraId;
}

std::string Carteira::getNomeTitular() const {
  return nomeTitular;
}

std::string Carteira::getCorretora() const {
  return corretora;
}

void Carteira::setNomeTitular(const std::string &nome) {
  nomeTitular = nome;
}

void Carteira::setCorretora(const std::string &corretora) {
  this->corretora = corretora;
}
