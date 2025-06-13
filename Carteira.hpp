#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <string>
using namespace std;

class Carteira {
private:
    int id;
    string nome_titular;
    string corretora;
    double saldo;

public:
    // Construtores
    Carteira();
    Carteira(int id, const string& nomeTitular, const string& corretora);
};

#endif