#pragma once
#include <iostream>
#include <string>
#include <limits>

class MenuUtil {
    protected:
        void printInfo(const std::string& texto) const;
        void printSucess(const std::string& texto) const;
        void printError(const std::string& texto) const;
        void aguardarVoltar() const;
        bool lerOpcao(int& opcao) const;
};
