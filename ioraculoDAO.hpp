#ifndef IORACULODAO_HPP
#define IORACULODAO_HPP

#include <optional>
#include "Cotacao.hpp"

class IOraculoDAO {
public:
    virtual void adicionarCotacao(const Cotacao& cotacao) = 0;
    virtual std::optional<Cotacao> buscarCotacaoPorData(const std::string& data) = 0;
    virtual ~IOraculoDAO() = default;
};

#endif
