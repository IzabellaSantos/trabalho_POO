// CarteiraController.cpp
#include "CarteiraController.hpp"

CarteiraController::CarteiraController() : proximoId(1) {}

int CarteiraController::criarCarteira(const std::string &nomeTitular, const std::string &corretora)
{
  int id = proximoId++;
  Carteira carteira(id, nomeTitular, corretora);
  carteiras[id] = carteira;
  return id;
}

std::unique_ptr<Carteira> CarteiraController::obterCarteira(int id) const
{
  auto it = carteiras.find(id);
  if (it != carteiras.end())
  {

    return std::unique_ptr<Carteira>(new Carteira(it->second));
  }
  return nullptr;
}

bool CarteiraController::atualizarCarteira(const Carteira &carteiraAtualizada)
{
  auto it = carteiras.find(carteiraAtualizada.getId());
  if (it != carteiras.end())
  {
    it->second = carteiraAtualizada;
    return true;
  }
  return false;
}

bool CarteiraController::removerCarteira(int id)
{
  return carteiras.erase(id) > 0;
}

std::vector<Carteira> CarteiraController::listarTodasCarteiras() const
{
  std::vector<Carteira> lista;
  for (const auto &pair : carteiras)
  {
    lista.push_back(pair.second);
  }
  return lista;
}
