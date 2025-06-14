#ifndef MOVIMENTACAO_HPP
#define MOVIMENTACAO_HPP

#include <string>

class Movimentacao {
private:
    int idCarteira;
    int idMovimento;
    std::string dataOperacao; // formato: "YYYY-MM-DD"
    char tipoOperacao;        // 'C' = compra, 'V' = venda
    double quantidade;        // não negativo

public:
    Movimentacao(int idCarteira, int idMovimento, const std::string& data, char tipo, double quantidade);

    int getIdCarteira() const;
    int getIdMovimento() const;
    std::string getDataOperacao() const;
    char getTipoOperacao() const;
    double getQuantidade() const;

    void setDataOperacao(const std::string& data);
    void setTipoOperacao(char tipo);
    void setQuantidade(double quantidade);
};

#endif

