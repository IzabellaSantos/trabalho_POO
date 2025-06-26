// Movimentacao.cpp
#include "Movimentacao.hpp"
#include <stdexcept> // necessário para std::invalid_argument

Movimentacao::Movimentacao(int idMovimento, const std::string &dataOperacao, char tipoOperacao, double quantidade, double valorUnitario)
: idMovimento(idMovimento), dataOperacao(dataOperacao), tipoOperacao(tipoOperacao), quantidade(quantidade), valorUnitario(valorUnitario) {}

int Movimentacao::getIdMovimento() const {
    return idMovimento;
}


const std::string &Movimentacao::getDataOperacao() const {
    return dataOperacao;
}

char Movimentacao::getTipoOperacao() const {
    return tipoOperacao;
}

double Movimentacao::getQuantidade() const {
    return quantidade;
}

double Movimentacao::getValorUnitario() const {
    return valorUnitario;
}
