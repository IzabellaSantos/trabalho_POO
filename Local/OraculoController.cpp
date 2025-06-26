#include "OraculoController.hpp"
#include <ctime>
#include <cstdlib>

OraculoController::OraculoController() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

double OraculoController::obterCotacao(const std::string &data) const {
  if (data == "hoje") {
    return 5.50; 
  } else {
    unsigned int seed = 0;
    for (char c : data) {
      seed += static_cast<unsigned int>(c);
    }
    double cotacao = 90.0 + (seed % 21);

    return cotacao;
  }
}
