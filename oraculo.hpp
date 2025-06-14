#ifndef COTACAO_HPP
#define COTACAO_HPP

#include <string>

class Cotacao {
private:
    std::string data; // formato: YYYY-MM-DD
    double valor;

public:
    Cotacao(const std::string& data, double valor);

    std::string getData() const;
    double getValor() const;

    void setValor(double valor);
};

#endif
