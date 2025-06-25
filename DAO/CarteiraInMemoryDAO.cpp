#include "../dao/CarteiraInMemoryDAO.hpp"

CarteiraInMemoryDAO::CarteiraInMemoryDAO() : nextId(1) {}

int CarteiraInMemoryDAO::incluir(const std::string &nomeTitular, const std::string &corretora)
{
  Carteira novaCarteira(nextId, nomeTitular, corretora);
  carteiras.push_back(novaCarteira);
  return nextId++;
}

std::unique_ptr<Carteira> CarteiraInMemoryDAO::recuperar(int id) const
{
  for (const auto &c : carteiras)
  {
    if (c.getId() == id)
    {
      return std::unique_ptr<Carteira>(new Carteira(c));
    }
  }
  return nullptr;
}

bool CarteiraInMemoryDAO::atualizar(const Carteira &carteiraAtualizada)
{
  for (auto &c : carteiras)
  {
    if (c.getId() == carteiraAtualizada.getId())
    {
      c.setNomeTitular(carteiraAtualizada.getNomeTitular());
      c.setCorretora(carteiraAtualizada.getCorretora());
      return true;
    }
  }
  return false;
}

bool CarteiraInMemoryDAO::remover(int id)
{
  for (auto it = carteiras.begin(); it != carteiras.end(); ++it)
  {
    if (it->getId() == id)
    {
      carteiras.erase(it);
      return true;
    }
  }
  return false;
}

std::vector<Carteira> CarteiraInMemoryDAO::listarTodas() const
{
  return carteiras;
}
