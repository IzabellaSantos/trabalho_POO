#include "Movimentacao.hpp"

Movimentacao::Movimentacao(int idCarteira, int idMovimento,
                           const std::string& data, char tipo, double quantidade)
    : idCarteira(idCarteira),
      idMovimento(idMovimento),
      dataOperacao(data),
      tipoOperacao(tipo),
      quantidade(quantidade) {}

int Movimentacao::getIdCarteira() const { return idCarteira; }
int Movimentacao::getIdMovimento() const { return idMovimento; }
std::string Movimentacao::getDataOperacao() const { return dataOperacao; }
char Movimentacao::getTipoOperacao() const { return tipoOperacao; }
double Movimentacao::getQuantidade() const { return quantidade; }

void Movimentacao::setDataOperacao(const std::string& data) {
    dataOperacao = data;
}
void Movimentacao::setTipoOperacao(char tipo) {
    tipoOperacao = tipo;
}
void Movimentacao::setQuantidade(double qtd) {
    quantidade = qtd;
}
