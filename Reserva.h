#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <iostream>
#include "Propietario.h"
#include "Huesped.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Reserva{
private:
    Propietario* pPropietario;
    Huesped* pHuesped;
    string fechaInic;
    string fechaFinal;

public:
    Reserva() = default;
    Reserva(Propietario* pPropietario, Huesped* pHuesped, string fechaInic, string fechaFinal);
    void mostrarInfo();
    Propietario* getPropietario();
    Huesped* getHuesped();


};
#endif