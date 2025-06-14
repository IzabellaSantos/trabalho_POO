#include "Cotacao.hpp"

Cotacao::Cotacao(const std::string& data, double valor)
    : data(data), valor(valor) {

    }

std::string Cotacao::getData() const { 
    return data; 
}
double Cotacao::getValor() const { 
    return valor; 
}
void Cotacao::setValor(double val) { 
    valor = val; 
}
