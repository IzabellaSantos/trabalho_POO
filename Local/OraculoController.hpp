#ifndef ORACULO_CONTROLLER_HPP
#define ORACULO_CONTROLLER_HPP

#include <string>

class OraculoController {
  public:
      OraculoController();
      virtual double obterCotacao(const std::string &data) const; // data no formato YYYY-MM-DD ou "hoje"
};

#endif
