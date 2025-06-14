#include "MovimentacaoController.hpp"
#include <iostream>

MovimentacaoController::MovimentacaoController(IMovimentacaoDAO* dao) : dao(dao) {}

void MovimentacaoController::registrarCompra() {
    int idCarteira, idMov;
    std::string data;
    double qtd;

    std::cout << "Enter Wallet ID: ";
    std::cin >> idCarteira;
    std::cout << "Enter Movement ID: ";
    std::cin >> idMov;
    std::cin.ignore();
    std::cout << "Enter Date: ";
    std::getline(std::cin, data);
    std::cout << "Enter Quantity: ";
    std::cin >> qtd;

    Movimentacao m(idCarteira, idMov, data, 'C', qtd);
    dao->adicionar(m);
    std::cout << "Purchase registered.\n";
}

void MovimentacaoController::registrarVenda() {
    int idCarteira, idMov;
    std::string data;
    double qtd;

    std::cout << "Enter Wallet ID: ";
    std::cin >> idCarteira;
    std::cout << "Enter Movement ID: ";
    std::cin >> idMov;
    std::cin.ignore();
    std::cout << "Enter Date (YYYY-MM-DD): ";
    std::getline(std::cin, data);
    std::cout << "Enter Quantity: ";
    std::cin >> qtd;

    Movimentacao m(idCarteira, idMov, data, 'V', qtd);
    dao->adicionar(m);
    std::cout << "Sale registered.\n";
}

void MovimentacaoController::listarPorCarteira() {
    int idCarteira;
    std::cout << "Enter Wallet ID: ";
    std::cin >> idCarteira;

    auto list = dao->buscarPorCarteira(idCarteira);
    std::cout << "--- Movements ---\n";
    for (const auto& m : list) {
        std::cout << "[" << m.getDataOperacao() << "] "
                  << (m.getTipoOperacao() == 'C' ? "BUY " : "SELL ")
                  << m.getQuantidade() << "\n";
    }
}
