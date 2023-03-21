#ifndef EVALUACION_H
#define EVALUACION_H

#include <string>
#include <iostream>
#include "Propietario.h"
#include "Huesped.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Evaluacion{
private:
    string fecha;
    int calificacion;
    string comentarios;
    string personaDirigida;
    Propietario* pPropietario;
    Huesped* pHuesped;

public:
    Evaluacion() = default;
    Evaluacion(string fecha, int calificacion, string comentarios, string personaDirigida, Propietario* pPropietario, Huesped* pHuesped);
    void setPropietario(Propietario* pPropietario);
    void setHuesped(Huesped* pHuesped);
    void mostrarInfo();


};
#endif