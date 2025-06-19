#ifndef CARTEIRA_INMEMORYDAO_HPP
#define CARTEIRA_INMEMORYDAO_HPP

#include <vector>
#include <memory>
#include "../model/Carteira.hpp"

class CarteiraInMemoryDAO
{
private:
  std::vector<Carteira> carteiras;
  int nextId;

public:
  CarteiraInMemoryDAO();
  int incluir(const std::string &nomeTitular, const std::string &corretora);
  std::unique_ptr<Carteira> recuperar(int id) const;
  bool atualizar(const Carteira &carteiraAtualizada);
  bool remover(int id);
  std::vector<Carteira> listarTodas() const;
};

#endif
