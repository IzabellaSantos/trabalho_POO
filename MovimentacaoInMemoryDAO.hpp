#ifndef MOVIMENTACAO_IN_MEMORY_DAO_HPP
#define MOVIMENTACAO_IN_MEMORY_DAO_HPP

#include "IMovimentacaoDAO.hpp"
#include <vector>

class MovimentacaoInMemoryDAO : public IMovimentacaoDAO {
private:
    std::vector<Movimentacao> movimentacoes;

public:
    void adicionar(const Movimentacao& mov) override;
    std::vector<Movimentacao> buscarPorCarteira(int idCarteira) override;
    std::vector<Movimentacao> listarTodos() override;
};

#endif
