#ifndef RELATORIO_CONTROLLER_HPP
#define RELATORIO_CONTROLLER_HPP

#include "ICarteiraDAO.hpp"
#include "IMovimentacaoDAO.hpp"
#include "IOraculoDAO.hpp"

class RelatorioController {
private:
    ICarteiraDAO* carteiraDAO;
    IMovimentacaoDAO* movimentacaoDAO;
    IOraculoDAO* oraculoDAO;

public:
    RelatorioController(ICarteiraDAO* cDao, IMovimentacaoDAO* mDao, IOraculoDAO* oDao);

    void listarCarteirasPorId();
    void listarCarteirasPorNome();
    void exibirSaldoCarteira();
    void exibirHistoricoCarteira();
    void exibirGanhoPerdaCarteiras();
};

#endif
