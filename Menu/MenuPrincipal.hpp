#include "MenuUtil.hpp"
#include "MenuCarteira.hpp"
#include "MenuMovimentacao.hpp"
#include "MenuRelatorio.hpp"
#include "MenuAjuda.hpp"

class MenuPrincipal : public MenuUtil {
private:
    MenuCarteira menuCarteira;
    MenuMovimentacao menuMovimentacao;
    MenuRelatorio menuRelatorio;
    MenuAjuda menuAjuda;

public:
    MenuPrincipal(CarteiraController* carteiraCtrl,
                  MovimentacaoController* movCtrl,
                  RelatorioController* relatorioCtrl);

    void exibir();
};
