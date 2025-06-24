#include "../catch.hpp"

#include "../../Local/RelatorioController.hpp"
#include "../../Local/CarteiraController.hpp"
#include "../../Local/MovimentacaoController.hpp"
#include "../../Model/Movimentacao.hpp"
#include "../Mocks/OraculoControllerMock.cpp"

TEST_CASE("Calcular saldo de uma carteira", "[RelatorioController]") {
    CarteiraController carteiraCtrl;
    MovimentacaoController movimentacaoCtrl;
    OraculoControllerMock oraculoCtrl;

    int idCarteira = carteiraCtrl.criarCarteira("Joao", "Binance");

    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-01", 'C', 2.0, 100.0);  // +200
    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-02", 'V', 1.0, 150.0);  // -150

    RelatorioController relatorio(&carteiraCtrl, &movimentacaoCtrl, &oraculoCtrl);

    double saldo = relatorio.calcularSaldo(idCarteira);

    REQUIRE(saldo == Approx(50.0));  // 200 - 150 = 50
}

TEST_CASE("Obter historico de movimentacoes", "[RelatorioController]") {
    CarteiraController carteiraCtrl;
    MovimentacaoController movimentacaoCtrl;
    OraculoControllerMock oraculoCtrl;

    int idCarteira = carteiraCtrl.criarCarteira("Maria", "Coinbase");

    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-01", 'C', 1.0, 200.0);
    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-02", 'V', 0.5, 220.0);

    RelatorioController relatorio(&carteiraCtrl, &movimentacaoCtrl, &oraculoCtrl);

    auto historico = relatorio.obterHistoricoMovimentacao(idCarteira);

    REQUIRE(historico.size() == 2);
    REQUIRE(historico[0].getDataOperacao() == "2025-06-01");
    REQUIRE(historico[1].getTipoOperacao() == 'V');
}

TEST_CASE("Calcular ganho ou perda", "[RelatorioController]") {
    CarteiraController carteiraCtrl;
    MovimentacaoController movimentacaoCtrl;
    OraculoControllerMock oraculoCtrl;  // Cotação fixa = 10.0

    int idCarteira = carteiraCtrl.criarCarteira("Carlos", "Binance");

    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-01", 'C', 3.0, 5.0);   // Gasto: 15, Valor Atual: 30
    movimentacaoCtrl.adicionarMovimentacao(idCarteira, "2025-06-02", 'V', 1.0, 8.0);   // Gasto: -8, Valor Atual: -10

    RelatorioController relatorio(&carteiraCtrl, &movimentacaoCtrl, &oraculoCtrl);

    double ganhoPerda = relatorio.calcularGanhoPerda(idCarteira);

    // Total gasto: 15 - 8 = 7
    // Total atual: 30 - 10 = 20
    // Ganho/Perda = 20 - 7 = 13
    REQUIRE(ganhoPerda == Approx(13.0));
}
