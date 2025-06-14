#include "OraculoController.hpp"
#include <iostream>

OraculoController::OraculoController(IOraculoDAO* dao) : dao(dao) {}

void OraculoController::adicionarCotacao() {
    std::string data;
    double valor;

    std::cout << "Enter Date (YYYY-MM-DD): ";
    std::cin.ignore();
    std::getline(std::cin, data);

    std::cout << "Enter Quotation Value: ";
    std::cin >> valor;

    Cotacao c(data, valor);
    dao->adicionar(c);
    std::cout << "Quotation added.\n";
}

void OraculoController::consultarCotacaoPorData() {
    std::string data;
    std::cout << "Enter Date (YYYY-MM-DD): ";
    std::cin.ignore();
    std::getline(std::cin, data);

    Cotacao* c = dao->buscarPorData(data);
    if (c) {
        std::cout << "Quotation on " << c->getData() << ": " << c->getValor() << "\n";
    } else {
        std::cout << "No quotation found for this date.\n";
    }
}

void OraculoController::listarCotacoes() {
    auto lista = dao->listarTodas();
    std::cout << "--- Daily Quotations ---\n";
    for (const auto& c : lista) {
        std::cout << c.getData() << ": " << c.getValor() << "\n";
    }
}
