#ifndef ORACULO_CONTROLLER_HPP
#define ORACULO_CONTROLLER_HPP

#include "IOraculoDAO.hpp"

class OraculoController {
private:
    IOraculoDAO* dao;

public:
    OraculoController(IOraculoDAO* dao);

    void adicionarCotacao();
    void consultarCotacaoPorData();
    void listarCotacoes();
};

#endif
