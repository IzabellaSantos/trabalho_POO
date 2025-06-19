#include "../dao/MovimentacaoInMemoryDAO.hpp"
#include <stdexcept>
#include <vector>

MovimentacaoInMemoryDAO::MovimentacaoInMemoryDAO() : nextIdMovimento(1) {}

int MovimentacaoInMemoryDAO::incluir(int idCarteira, const std::string &dataOperacao, char tipoOperacao, double quantidade)
{
  if (tipoOperacao != 'C' && tipoOperacao != 'V')
  {
    throw std::invalid_argument("Tipo de operação inválido. Use 'C' para compra ou 'V' para venda.");
  }
  if (quantidade < 0)
  {
    throw std::invalid_argument("Quantidade não pode ser negativa.");
  }

  Movimentacao novaMov(nextIdMovimento, idCarteira, dataOperacao, tipoOperacao, quantidade);
  movimentacoes.push_back(novaMov);
  return nextIdMovimento++;
}

std::unique_ptr<Movimentacao> MovimentacaoInMemoryDAO::recuperar(int idMovimento) const
{
  for (const auto &m : movimentacoes)
  {
    if (m.getIdMovimento() == idMovimento)
    {
      return std::unique_ptr<Movimentacao>(new Movimentacao(m));
    }
  }
  return nullptr;
}

std::vector<Movimentacao> MovimentacaoInMemoryDAO::listarPorCarteira(int idCarteira) const
{
  std::vector<Movimentacao> resultado;
  for (const auto &m : movimentacoes)
  {
    if (m.getIdCarteira() == idCarteira)
    {
      resultado.push_back(m);
    }
  }
  return resultado;
}

bool MovimentacaoInMemoryDAO::remover(int idMovimento)
{
  for (auto it = movimentacoes.begin(); it != movimentacoes.end(); ++it)
  {
    if (it->getIdMovimento() == idMovimento)
    {
      movimentacoes.erase(it);
      return true;
    }
  }
  return false;
}
