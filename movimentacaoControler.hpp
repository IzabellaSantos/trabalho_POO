#ifndef MOVIMENTACAO_CONTROLLER_HPP
#define MOVIMENTACAO_CONTROLLER_HPP

#include "IMovimentacaoDAO.hpp"

class MovimentacaoController {
private:
    IMovimentacaoDAO* dao;

public:
    MovimentacaoController(IMovimentacaoDAO* dao);

    void registrarCompra();
    void registrarVenda();
    void listarPorCarteira();
};

#endif
