#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <string>
#include <iostream>
#include "Hogar.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Propietario{
private:
    int id;
    string nombre;
    string sexo;
    string fechaNac;
    int puntaje;
    Hogar* pHogar;
    
public:
    int recibirHuesped;
    Propietario() = default;
    Propietario(int id, string nombre, string sexo, string fechaNac, int puntaje, int recibirHuesped);
    int getId();
    void setHogar(Hogar* pHogar);
    Hogar* getHogar();
    string getNombre();
    void mostrarInfo();
    void actualizarCal(int calificacion);
    
};
#endif