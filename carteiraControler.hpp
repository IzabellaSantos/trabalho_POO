#ifndef CARTEIRACONTROLLER_HPP
#define CARTEIRACONTROLLER_HPP

#include "ICarteiraDAO.hpp"

class CarteiraController {
private:
    ICarteiraDAO* dao;

public:
    CarteiraController(ICarteiraDAO* dao);

    void adicionarCarteira();
    void listarCarteiras();
    void editarCarteira();
    void removerCarteira();
    void recuperarCarteira();

};

#endif
