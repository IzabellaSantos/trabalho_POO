#include "CarteiraInMemoryDAO.hpp"

void CarteiraInMemoryDAO::adicionar(const Carteira& carteira) {
    carteiras.push_back(carteira);
}

Carteira* CarteiraInMemoryDAO::buscarPorId(int id) {
    for (auto& carteira : carteiras) {
        if (carteira.getId() == id) {
            return &carteira;
        }
    }
    return nullptr;
}

bool CarteiraInMemoryDAO::editar(const Carteira& carteiraAtualizada) {
    for (auto& carteira : carteiras) {
        if (carteira.getId() == carteiraAtualizada.getId()) {
            carteira.setNomeTitular(carteiraAtualizada.getNomeTitular());
            carteira.setCorretora(carteiraAtualizada.getCorretora());
            return true;
        }
    }
    return false;
}

bool CarteiraInMemoryDAO::remover(int id) {
    for (auto it = carteiras.begin(); it != carteiras.end(); ++it) {
        if (it->getId() == id) {
            carteirasDeletadas.push_back(*it);  // salva antes de remover
            carteiras.erase(it);
            return true;
        }
    }
    return false;
}

bool CarteiraInMemoryDAO::recuperar(int id) {
    for (auto it = carteirasDeletadas.begin(); it != carteirasDeletadas.end(); ++it) {
        if (it->getId() == id) {
            carteiras.push_back(*it);
            carteirasDeletadas.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Carteira> CarteiraInMemoryDAO::listarTodos() {
    return carteiras;
}

const std::vector<Carteira>& CarteiraInMemoryDAO::getCarteirasDeletadas() const {
    return carteirasDeletadas;
}
