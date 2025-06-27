#pragma once
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
    virtual void display() = 0; // pure virtual method, must be implemented
    virtual ~MenuBase() = default;
};

#endif
