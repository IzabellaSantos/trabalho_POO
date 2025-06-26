#ifndef MENUBASE_HPP
#define MENUBASE_HPP
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class MenuBase {
public:
    virtual void exibir() = 0; // método puro, obriga herdeiros a implementar
    virtual ~MenuBase() = default;
};

#endif
