#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include "Propietario.h"
#include "Huesped.h"
#include "Reserva.h"
#include "Evaluacion.h"
#include <unordered_map>
 
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::make_pair;
using std::getline;


class Sistema{
private:
    int acumUsuarios;
    unordered_map<int, Propietario*> mapaProp;
    unordered_map<int, Huesped*> mapaHuesped;
    unordered_map<int, Reserva*> mapaReserva;
    unordered_map<int, Evaluacion*> mapaEvaluaciones;

public:
    Sistema() = default;
    void agregarPropietario();
    void mostrarPersonasInscritas();
    void agregarHogar(Propietario* pPropietario);
    Huesped* agregarHuesped();
    void agregarReserva(Propietario* pPropietario, Huesped* pHuesped);
    void mostrarInfoPropHogar();
    void mostrarInfoProp();
    void mostrarReservas();
    void mostrarEvaluaciones();
    void crearReserva();
    void liberarReserva();
    void agregarEvaluacion(Reserva* pReserva);


};
#endif