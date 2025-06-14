#include "RelatorioController.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

RelatorioController::RelatorioController(ICarteiraDAO* cDao, IMovimentacaoDAO* mDao, IOraculoDAO* oDao)
    : carteiraDAO(cDao), movimentacaoDAO(mDao), oraculoDAO(oDao) {}

void RelatorioController::listarCarteirasPorId() {
    auto lista = carteiraDAO->listarTodos();
    std::sort(lista.begin(), lista.end(), [](const Carteira& a, const Carteira& b) {
        return a.getId() < b.getId();
    });

    std::cout << "--- Carteiras (ordenadas por ID) ---\n";
    for (const auto& c : lista) {
        std::cout << "ID: " << c.getId()
                  << " | Titular: " << c.getNomeTitular()
                  << " | Corretora: " << c.getCorretora() << "\n";
    }
}

void RelatorioController::listarCarteirasPorNome() {
    auto lista = carteiraDAO->listarTodos();
    std::sort(lista.begin(), lista.end(), [](const Carteira& a, const Carteira& b) {
        return a.getNomeTitular() < b.getNomeTitular();
    });

    std::cout << "--- Carteiras (ordenadas por nome do titular) ---\n";
    for (const auto& c : lista) {
        std::cout << "ID: " << c.getId()
                  << " | Titular: " << c.getNomeTitular()
                  << " | Corretora: " << c.getCorretora() << "\n";
    }
}

void RelatorioController::exibirSaldoCarteira() {
    int id;
    std::cout << "Digite o ID da carteira: ";
    std::cin >> id;

    double saldo = 0.0;
    auto movs = movimentacaoDAO->buscarPorCarteira(id);
    for (const auto& m : movs) {
        saldo += (m.getTipoOperacao() == 'C' ? m.getQuantidade() : -m.getQuantidade());
    }

    std::cout << "Saldo atual da carteira " << id << ": " << saldo << " moedas virtuais\n";
}

void RelatorioController::exibirHistoricoCarteira() {
    int id;
    std::cout << "Digite o ID da carteira: ";
    std::cin >> id;

    auto movs = movimentacaoDAO->buscarPorCarteira(id);
    std::cout << "--- Histórico da carteira ---\n";
    for (const auto& m : movs) {
        std::cout << "[" << m.getDataOperacao() << "] "
                  << (m.getTipoOperacao() == 'C' ? "COMPRA " : "VENDA ")
                  << m.getQuantidade() << "\n";
    }
}

void RelatorioController::exibirGanhoPerdaCarteiras() {
    auto carteiras = carteiraDAO->listarTodos();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--- Ganho ou Perda por Carteira ---\n";

    for (const auto& c : carteiras) {
        double totalCompra = 0.0;
        double totalVenda = 0.0;

        auto movs = movimentacaoDAO->buscarPorCarteira(c.getId());
        for (const auto& m : movs) {
            auto cotacao = oraculoDAO->buscarCotacaoPorData(m.getDataOperacao());
            if (cotacao.has_value()) {
                double valor = m.getQuantidade() * cotacao->getValor();
                if (m.getTipoOperacao() == 'C')
                    totalCompra += valor;
                else
                    totalVenda += valor;
            }
        }

        double resultado = totalVenda - totalCompra;
        std::cout << "Carteira ID " << c.getId()
                  << " (" << c.getNomeTitular() << "): "
                  << (resultado >= 0 ? "Ganho: " : "Perda: ")
                  << std::abs(resultado) << " reais\n";
    }
}

