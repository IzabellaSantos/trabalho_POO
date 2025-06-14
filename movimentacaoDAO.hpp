#ifndef IMOVIMENTACAODAO_HPP
#define IMOVIMENTACAODAO_HPP

#include <vector>
#include "Movimentacao.hpp"

class IMovimentacaoDAO {
public:
    virtual void adicionar(const Movimentacao& mov) = 0;
    virtual std::vector<Movimentacao> buscarPorCarteira(int idCarteira) = 0;
    virtual ~IMovimentacaoDAO() = default;
};

#endif
