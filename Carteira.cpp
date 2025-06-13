#include "Carteira.hpp"

// Construtor padrão
Carteira::Carteira() {}

// Construtor com parâmetros
Carteira::Carteira(int id, const string& nomeTitular, const string& corretora) {
    this->id = id;
    this->nome_titular = nomeTitular;
    this->corretora = corretora;
}

