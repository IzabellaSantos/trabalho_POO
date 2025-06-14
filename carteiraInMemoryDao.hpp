#ifndef CARTEIRAINMEMORYDAO_HPP
#define CARTEIRAINMEMORYDAO_HPP

#include "ICarteiraDAO.hpp"
#include <vector>

class CarteiraInMemoryDAO : public ICarteiraDAO {
private:
    std::vector<Carteira> carteiras;
    std::vector<Carteira> carteirasDeletadas;

public:
    void adicionar(const Carteira& carteira) override;
    Carteira* buscarPorId(int id) override;
    bool editar(const Carteira& carteira) override;
    bool remover(int id) override;
    std::vector<Carteira> listarTodos() override;

    bool recuperar(int id); // novo método

    const std::vector<Carteira>& getCarteirasDeletadas() const; // se quiser acessar para debug
};

#endif
