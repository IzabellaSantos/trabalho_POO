// Carteira.cpp
#include "Carteira.hpp"

Carteira::Carteira(int id, const std::string &nomeTitular, const std::string &corretora)
    : id(id), nomeTitular(nomeTitular), corretora(corretora) {}

int Carteira::getId() const
{
  return id;
}

std::string Carteira::getNomeTitular() const
{
  return nomeTitular;
}

std::string Carteira::getCorretora() const
{
  return corretora;
}

void Carteira::setNomeTitular(const std::string &nome)
{
  nomeTitular = nome;
}

void Carteira::setCorretora(const std::string &corretora)
{
  this->corretora = corretora;
}
