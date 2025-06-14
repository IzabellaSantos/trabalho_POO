#ifndef ICARTEIRADAO_HPP
#define ICARTEIRADAO_HPP

#include <vector>
#include "Carteira.hpp"

class ICarteiraDAO {
public:
    virtual void adicionar(const Carteira& carteira) = 0;
    virtual Carteira* buscarPorId(int id) = 0;
    virtual bool editar(const Carteira& carteira) = 0;
    virtual bool remover(int id) = 0;
    virtual std::vector<Carteira> listarTodos() = 0;
    virtual ~ICarteiraDAO() = default;
};

#endif
