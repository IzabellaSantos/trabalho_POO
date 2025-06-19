// Movimentacao.cpp
#include "Movimentacao.hpp"

Movimentacao::Movimentacao(int idMovimento, int idCarteira, const std::string &dataOperacao, char tipoOperacao, double quantidade, double valorUnitario)
    : idMovimento(idMovimento), idCarteira(idCarteira), dataOperacao(dataOperacao), tipoOperacao(tipoOperacao), quantidade(quantidade), valorUnitario(valorUnitario) {}

int Movimentacao::getIdMovimento() const
{
    return idMovimento;
}

int Movimentacao::getIdCarteira() const
{
    return idCarteira;
}

const std::string &Movimentacao::getDataOperacao() const
{
    return dataOperacao;
}

char Movimentacao::getTipoOperacao() const
{
    return tipoOperacao;
}

double Movimentacao::getQuantidade() const
{
    return quantidade;
}

double Movimentacao::getValorUnitario() const
{
    return valorUnitario;
}
