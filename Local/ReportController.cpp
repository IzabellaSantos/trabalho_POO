#include "RelatorioController.hpp"
#include <iostream>

RelatorioController::RelatorioController(CarteiraController* cCtrl,
                                         MovimentacaoController* mCtrl,
                                         OraculoController* oCtrl)
    : carteiraController(cCtrl), movimentacaoController(mCtrl), oraculoController(oCtrl) {}

// Retorna o saldo em reais da carteira (vendas - compras)
double RelatorioController::calcularSaldo(int idCarteira) const {
    double saldo = 0.0;
    auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);

    for (const auto& mov : movimentacoes) {
        double valor = mov.getQuantidade() * mov.getValorUnitario();
        if (mov.getTipoOperacao() == 'C') {
            saldo -= valor; // Compra → dinheiro sai
        } else if (mov.getTipoOperacao() == 'V') {
            saldo += valor; // Venda → dinheiro entra
        }
    }

    return saldo;
}

// Retorna o histórico de movimentações da carteira
std::vector<Movimentacao> RelatorioController::obterHistoricoMovimentacao(int idCarteira) const {
    return movimentacaoController->obterMovimentacoes(idCarteira);
}

// Calcula ganho ou perda com base no valor de mercado atual dos ativos restantes
double RelatorioController::calcularGanhoPerda(int idCarteira) const {
    double totalInvestido = 0.0;
    double quantidadeEmCarteira = 0.0;

    auto movimentacoes = movimentacaoController->obterMovimentacoes(idCarteira);
    double cotacaoAtual = oraculoController->obterCotacao("hoje");

    for (const auto& mov : movimentacoes) {
        double qtd = mov.getQuantidade();
        double preco = mov.getValorUnitario();

        if (mov.getTipoOperacao() == 'C') {
            totalInvestido += qtd * preco;     // Dinheiro gasto
            quantidadeEmCarteira += qtd;       // Ativo entra
        } else if (mov.getTipoOperacao() == 'V') {
            totalInvestido -= qtd * preco;     // Dinheiro recuperado
            quantidadeEmCarteira -= qtd;       // Ativo sai
        }
    }

    double valorAtual = quantidadeEmCarteira * cotacaoAtual;
    return valorAtual - totalInvestido;
}
