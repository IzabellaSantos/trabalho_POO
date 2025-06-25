#include "OraculoController.hpp"
#include <ctime>
#include <cstdlib>

OraculoController::OraculoController()
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

double OraculoController::obterCotacao(const std::string &data) const
{
  // Retorna uma cotação simulada entre 90 e 110
  // Se data == "hoje", cotação é gerada com base no horário atual
  // Caso contrário, pode ser gerado com base no hash da string da data

  if (data == "hoje") {
    return 5.50; 
  } else {
    unsigned int seed = 0;
    for (char c : data) {
      seed += static_cast<unsigned int>(c);
    }
    double cotacao = 90.0 + (seed % 21); // Simples hashing

    return cotacao;
  }
}
