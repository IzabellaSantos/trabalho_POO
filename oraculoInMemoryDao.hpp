#ifndef ORACULOINMEMORYDAO_HPP
#define ORACULOINMEMORYDAO_HPP

#include "IOraculoDAO.hpp"
#include <vector>

class OraculoInMemoryDAO : public IOraculoDAO {
private:
    std::vector<Cotacao> cotacoes;

public:
    void adicionar(const Cotacao& cotacao) override;
    Cotacao* buscarPorData(const std::string& data) override;
    std::vector<Cotacao> listarTodas() override;
};

#endif
