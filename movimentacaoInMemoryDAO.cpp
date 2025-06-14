#include "MovimentacaoInMemoryDAO.hpp"

void MovimentacaoInMemoryDAO::adicionar(const Movimentacao& mov) {
    movimentacoes.push_back(mov);
}

std::vector<Movimentacao> MovimentacaoInMemoryDAO::buscarPorCarteira(int idCarteira) {
    std::vector<Movimentacao> resultado;
    for (const auto& mov : movimentacoes) {
        if (mov.getIdCarteira() == idCarteira) {
            resultado.push_back(mov);
        }
    }
    return resultado;
}

std::vector<Movimentacao> MovimentacaoInMemoryDAO::listarTodos() {
    return movimentacoes;
}
