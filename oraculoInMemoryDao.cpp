#include "OraculoInMemoryDAO.hpp"

void OraculoInMemoryDAO::adicionar(const Cotacao& cotacao) {
    // Substitui se já existir cotação na mesma data
    for (auto& c : cotacoes) {
        if (c.getData() == cotacao.getData()) {
            c.setValor(cotacao.getValor());
            return;
        }
    }
    cotacoes.push_back(cotacao);
}

Cotacao* OraculoInMemoryDAO::buscarPorData(const std::string& data) {
    for (auto& c : cotacoes) {
        if (c.getData() == data) {
            return &c;
        }
    }
    return nullptr;
}

std::vector<Cotacao> OraculoInMemoryDAO::listarTodas() {
    return cotacoes;
}
