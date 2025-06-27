// Carteira.hpp
#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <string>

class Carteira {
  private:
    int carteiraId;
    std::string nomeTitular;
    std::string corretora;

  public:
    Carteira() = default;  // construtor padrão
    Carteira(int carteiraId, 
             const std::string &nomeTitular, 
             const std::string &corretora);

    int getCarteiraId() const;
    std::string getNomeTitular() const;
    std::string getCorretora() const;

    void setNomeTitular(const std::string &nome);
    void setCorretora(const std::string &corretora);
};

#endif
