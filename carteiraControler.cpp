#include "CarteiraController.hpp"
#include <iostream>

CarteiraController::CarteiraController(ICarteiraDAO* dao) : dao(dao) {}

void CarteiraController::adicionarCarteira() {
    int id;
    std::string nome, corretora;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Holder Name: ";
    std::getline(std::cin, nome);

    std::cout << "Broker: ";
    std::getline(std::cin, corretora);

    Carteira carteira(id, nome, corretora);
    dao->adicionar(carteira);
    std::cout << "Carteira added successfully.\n";
}

void CarteiraController::listarCarteiras() {
    auto lista = dao->listarTodos();
    std::cout << "--- Carteiras ---\n";
    for (const auto& c : lista) {
        std::cout << "ID: " << c.getId()
                  << " | Holder: " << c.getNomeTitular()
                  << " | Broker: " << c.getCorretora() << "\n";
    }
}

void CarteiraController::editarCarteira() {
    int id;
    std::string nome, corretora;

    std::cout << "Enter ID to edit: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "New Holder Name: ";
    std::getline(std::cin, nome);

    std::cout << "New Broker: ";
    std::getline(std::cin, corretora);

    Carteira c(id, nome, corretora);
    if (dao->editar(c)) {
        std::cout << "Updated successfully.\n";
    } else {
        std::cout << "Carteira not found.\n";
    }
}

void CarteiraController::removerCarteira() {
    int id;
    std::cout << "Enter ID to remove: ";
    std::cin >> id;

    if (dao->remover(id)) {
        std::cout << "Removed successfully.\n";
    } else {
        std::cout << "Carteira not found.\n";
    }
}

void CarteiraController::recuperarCarteira() {
    int id;
    std::cout << "Digite o ID da carteira que deseja recuperar: ";
    std::cin >> id;

    // Tenta fazer cast para acessar método específico
    auto daoReal = dynamic_cast<CarteiraInMemoryDAO*>(dao);
    if (daoReal && daoReal->recuperar(id)) {
        std::cout << "Carteira recuperada com sucesso.\n";
    } else {
        std::cout << "Carteira não encontrada ou não foi deletada.\n";
    }
}

