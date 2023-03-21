#ifndef HOGAR_H
#define HOGAR_H

#include <string>
#include <iostream>
#include "Hogar.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Hogar{
private:
    int numCamas;
    int alojarBebes;
    string descHogar;
    string direccion;

public:
    Hogar() = default;
    Hogar(int numCamas, int alojarBebes, string descHogar, string direccion);
    void mostrarInfoHogar();


};
#endif