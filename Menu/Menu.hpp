// Menu.hpp
#ifndef MENU_HPP
#define MENU_HPP

#include "../Local/CarteiraController.hpp"
#include "../Local/MovimentacaoController.hpp"
#include "../Local/RelatorioController.hpp"
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class Menu {
private:
	CarteiraController* carteiraController;
	MovimentacaoController* movimentacaoController;
	RelatorioController* relatorioController;

	void exibirMenuCarteira();
	void exibirMenuPrincipal(); 
	void opcaoIncluirCarteira();
	void opcaoRecuperarCarteira();
	void opcaoEditarCarteira();
	void opcaoExcluirCarteira();
	void aguardarVoltar();

	void exibirMenuMovimentacao();
	void opcaoRegistrarMovimentacao(char tipo);
	void opcaoListarMovimentacoes();

	void exibirMenuRelatorios();
	void opcaoExibirSaldo();
	void opcaoExibirHistorico();
	void opcaoExibirGanhoPerda();
	void listarCarteirasID();
	void listarCarteirasPorNome();

	void exibirMenuAjuda();

	void printInfo(const std::string& texto);
	void printSucess(const std::string& texto);
	void printError(const std::string& texto);

	bool lerOpcao(int& opcao);
	bool verificarCarteirasDisponiveis();
	int lerIdCarteira();
	void exibirCarteira(const Carteira& carteira);

public:
	Menu(CarteiraController* carteiraCtrl, MovimentacaoController* movCtrl, RelatorioController* relatorioCtrl);
	void exibirMenuPrincipalLoop();
};

#endif
