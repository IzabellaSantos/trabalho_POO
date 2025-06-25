#include "../catch.hpp"
#include "../../Local/RelatorioController.hpp"

class OraculoControllerMock: public OraculoController {
    public:
        double obterCotacao(const std::string& data) const override {
            return 10.0;  
        }
};