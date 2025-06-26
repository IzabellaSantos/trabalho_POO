#include "../catch.hpp"

#include "../../Local/MovimentacaoController.hpp"
#include "../../Model/Movimentacao.hpp"

TEST_CASE("Adicionar movimentação", "[MovimentacaoController]") {
    MovimentacaoController controller;
    int idMock = 1;

    controller.adicionarMovimentacao(idMock, "2025-06-24", 'C', 2.5, 100.0);
    controller.adicionarMovimentacao(idMock, "2025-06-23", 'V', 1.0, 110.0);

    auto movimentacoes = controller.obterMovimentacoes(idMock);

    REQUIRE(movimentacoes.size() == 2);

    REQUIRE(movimentacoes[0].getDataOperacao() == "2025-06-24");
    REQUIRE(movimentacoes[0].getTipoOperacao() == 'C');
    REQUIRE(movimentacoes[0].getQuantidade() == Approx(2.5));
    REQUIRE(movimentacoes[0].getValorUnitario() == Approx(100.0));

    REQUIRE(movimentacoes[1].getTipoOperacao() == 'V');
    REQUIRE(movimentacoes[1].getQuantidade() == Approx(1.0));
    REQUIRE(movimentacoes[1].getValorUnitario() == Approx(110.0));
}

TEST_CASE("Obter movimentações inexistentes", "[MovimentacaoController]") {
    MovimentacaoController controller;

    auto movimentacoes = controller.obterMovimentacoes(99); // id inexistente
    REQUIRE(movimentacoes.empty()); // deve retornar vetor vazio
}
