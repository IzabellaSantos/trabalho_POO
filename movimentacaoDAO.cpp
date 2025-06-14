#include "MovimentacaoDAO.hpp"

void MovimentacaoDAO::adicionarMovimentacao(const Movimentacao& mov) {
    movimentacoes.push_back(mov);
}

std::vector<Movimentacao> MovimentacaoDAO::listarPorCarteira(int idCarteira) const {
    std::vector<Movimentacao> resultado;
    for (const auto& mov : movimentacoes) {
        if (mov.getIdCarteira() == idCarteira) {
            resultado.push_back(mov);
        }
    }
    return resultado;
}

int MovimentacaoDAO::gerarNovoId() {
    return proximoId++;
}
