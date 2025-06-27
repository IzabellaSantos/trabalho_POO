#ifndef RELATORIO_CONTROLLER_HPP
#define RELATORIO_CONTROLLER_HPP

#include <vector>
#include "../Model/Carteira.hpp"
#include "../Model/Movimentacao.hpp"
#include "CarteiraController.hpp"
#include "MovimentacaoController.hpp"
#include "OraculoController.hpp"

class RelatorioController {
  private:
      CarteiraController *carteiraController;
      MovimentacaoController *movimentacaoController;
      OraculoController *oraculoController;

  public:
      RelatorioController(CarteiraController *cCtrl, MovimentacaoController *mCtrl, OraculoController *oCtrl);

      // Retorna o saldo líquido da carteira (R$), considerando compras e vendas
      double calcularSaldo(int idCarteira) const;

      // Retorna todas as movimentações associadas a uma carteira
      std::vector<Movimentacao> obterHistoricoMovimentacao(int idCarteira) const;

      // Calcula o ganho ou perda total da carteira com base na cotação atual
      double calcularGanhoPerda(int idCarteira) const;
};

#endif
