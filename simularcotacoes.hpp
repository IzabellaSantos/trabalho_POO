#pragma once
#include "IOraculoDAO.hpp"
#include "Cotacao.hpp"

inline void simularCotacoes(IOraculoDAO* dao) {
    dao->adicionarCotacao(Cotacao("2024-01-01", 4.5));
    dao->adicionarCotacao(Cotacao("2024-01-02", 4.6));
    dao->adicionarCotacao(Cotacao("2024-01-03", 4.4));
    dao->adicionarCotacao(Cotacao("2024-01-04", 4.55));
}
