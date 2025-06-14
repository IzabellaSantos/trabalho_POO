#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <string>

class Carteira {
private:
    int id;
    std::string nomeTitular;
    std::string corretora;

public:
    Carteira(int id, const std::string& nomeTitular, const std::string& corretora);

    int getId() const;
    std::string getNomeTitular() const;
    std::string getCorretora() const;        // ✅ esta linha deve estar presente

    void setNomeTitular(const std::string& nomeTitular);
    void setCorretora(const std::string& corretora);
};

#endif
