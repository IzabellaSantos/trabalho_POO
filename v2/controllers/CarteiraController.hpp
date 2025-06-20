// CarteiraController.hpp
#ifndef CARTEIRA_CONTROLLER_HPP
#define CARTEIRA_CONTROLLER_HPP

#include <vector>
#include <memory>
#include <map>
#include "../model/Carteira.hpp"

class CarteiraController
{
private:
  std::map<int, Carteira> carteiras;
  int proximoId;

public:
  CarteiraController();

  int criarCarteira(const std::string &nomeTitular, const std::string &corretora);
  std::unique_ptr<Carteira> obterCarteira(int id) const;
  bool atualizarCarteira(const Carteira &carteiraAtualizada);
  bool removerCarteira(int id);
  std::vector<Carteira> listarTodasCarteiras() const;
};

#endif
