#include "../catch.hpp"

#include "../../Local/CarteiraController.hpp"

TEST_CASE("Criar carteira", "[CarteiraController]") {
    CarteiraController controller;

    int id = controller.criarCarteira("Joao Silva", "Binance");
    auto carteira = controller.obterCarteira(id);

    REQUIRE(carteira != nullptr);
    REQUIRE(carteira->getId() == id);
    REQUIRE(carteira->getNomeTitular() == "Joao Silva");
    REQUIRE(carteira->getCorretora() == "Binance");
}

TEST_CASE("Atualizar carteira", "[CarteiraController]") {
    CarteiraController controller;

    int id = controller.criarCarteira("Maria", "Binance");
    auto carteira = controller.obterCarteira(id);
    REQUIRE(carteira != nullptr);

    // Alterar o nome e corretora
    carteira->setNomeTitular("Maria Souza");
    carteira->setCorretora("Coinbase");

    bool atualizado = controller.atualizarCarteira(*carteira);
    REQUIRE(atualizado == true);

    auto carteiraAtualizada = controller.obterCarteira(id);
    REQUIRE(carteiraAtualizada->getNomeTitular() == "Maria Souza");
    REQUIRE(carteiraAtualizada->getCorretora() == "Coinbase");
}

TEST_CASE("Remover carteira", "[CarteiraController]") {
    CarteiraController controller;

    int id = controller.criarCarteira("Carlos", "Binance");

    bool removido = controller.removerCarteira(id);
    REQUIRE(removido == true);

    auto carteira = controller.obterCarteira(id);
    REQUIRE(carteira == nullptr);
}

TEST_CASE("Listar todas as carteiras", "[CarteiraController]") {
    CarteiraController controller;

    int id1 = controller.criarCarteira("Alice", "Binance");
    int id2 = controller.criarCarteira("Bob", "Coinbase");

    auto lista = controller.listarTodasCarteiras();
    REQUIRE(lista.size() == 2);

    std::vector<int> ids;
    for (const auto& carteira : lista) {
        ids.push_back(carteira.getId());
    }

    REQUIRE(std::find(ids.begin(), ids.end(), id1) != ids.end());
    REQUIRE(std::find(ids.begin(), ids.end(), id2) != ids.end());
}
