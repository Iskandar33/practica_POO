#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include <iostream>
#include "Hogar.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Huesped{
private:
    int id;
    string nombre;
    string sexo;
    string fechaNac;
    int puntaje;
    string ubicFamiliar;
    string lugarNac;

public:
    Huesped() = default;
    Huesped(int id, string nombre, string sexo, string fechaNac, int puntaje, string ubicFamiliar, string lugarNac);
    int getId();
    string getNombre();
    void mostrarInfo();
    void actualizarCal(int calificacion);
    
};
#endif
