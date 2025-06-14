#include <iostream>
#include <vector>
#include "CarteiraInMemoryDAO.hpp"
#include "MovimentacaoInMemoryDAO.hpp"
#include "OraculoInMemoryDAO.hpp"
#include "CarteiraController.hpp"
#include "MovimentacaoController.hpp"
#include "RelatorioController.hpp"
#include "simular_cotacoes.hpp"
#include "Menu.h"

int main() {
    // DAOs
    CarteiraInMemoryDAO carteiraDAO;
    MovimentacaoInMemoryDAO movimentacaoDAO;
    OraculoInMemoryDAO oraculoDAO;

    // Simular cotações no oráculo
    simularCotacoes(&oraculoDAO);

    // Controllers
    CarteiraController carteiraController(&carteiraDAO);
    MovimentacaoController movimentacaoController(&movimentacaoDAO);
    RelatorioController relatorioController(&carteiraDAO, &movimentacaoDAO, &oraculoDAO);

    bool executando = true;

    while (executando) {
        std::vector<std::string> opcoesMenuPrincipal = {
            "Carteira",
            "Movimentação",
            "Relatórios",
            "Ajuda",
            "Sair"
        };
        Menu menuPrincipal(opcoesMenuPrincipal, "Menu Principal", "Escolha uma opção:");
        int escolha = menuPrincipal.getChoice();

        switch (escolha) {
            case 0: // Sair
                std::cout << "\nEncerrando o programa. Até logo!\n";
                executando = false;
                break;

            case 1: { // Carteira
                std::vector<std::string> opcoes = {
                    "Incluir um novo registro de carteira",
                    "Recuperar uma carteira deletada por ID",
                    "Editar um registro de carteira existente",
                    "Excluir um registro de carteira"
                };
                Menu menuCarteira(opcoes, "Menu - Carteira", "Escolha uma opção:");
                int opc = menuCarteira.getChoice();
                switch (opc) {
                    case 1: carteiraController.adicionarCarteira(); break;
                    case 2: carteiraController.recuperarCarteira(); break;
                    case 3: carteiraController.editarCarteira(); break;
                    case 4: carteiraController.removerCarteira(); break;
                }
                break;
            }

            case 2: { // Movimentação
                std::vector<std::string> opcoes = {
                    "Registrar compra de moeda virtual em uma carteira",
                    "Registrar venda de moeda virtual de uma carteira"
                };
                Menu menuMov(opcoes, "Menu - Movimentação", "Escolha uma opção:");
                int opc = menuMov.getChoice();
                switch (opc) {
                    case 1: movimentacaoController.registrarCompra(); break;
                    case 2: movimentacaoController.registrarVenda(); break;
                }
                break;
            }

            case 3: { // Relatórios
                std::vector<std::string> opcoes = {
                    "Listar carteiras ordenadas por identificador",
                    "Listar carteiras ordenadas por nome do titular",
                    "Exibir saldo atual de uma carteira específica",
                    "Exibir histórico de movimentação de uma carteira específica",
                    "Apresentar ganho ou perda total de cada carteira, calculado com base nas cotações do oráculo"
                };
                Menu menuRel(opcoes, "Menu - Relatórios", "Escolha uma opção:");
                int opc = menuRel.getChoice();
                switch (opc) {
                    case 1: relatorioController.listarCarteirasPorId(); break;
                    case 2: relatorioController.listarCarteirasPorNome(); break;
                    case 3: relatorioController.exibirSaldoCarteira(); break;
                    case 4: relatorioController.exibirHistoricoCarteira(); break;
                    case 5: relatorioController.exibirGanhoPerdaCarteiras(); break;
                }
                break;
            }

            case 4: { // Ajuda
                std::cout << "\nAjuda do Programa:\n";
                std::cout << "Este sistema permite acompanhar carteiras de moedas virtuais,\n";
                std::cout << "registrar movimentações de compra e venda e emitir relatórios.\n";
                std::cout << "\nCréditos:\n";
                std::cout << "Autores: Beatriz Lauriano de Oliveira\n";
                std::cout << "Versão: 1.0\n";
                std::cout << "Data: Junho/2025\n\n";
                break;
            }

            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    }

    return 0;
}
