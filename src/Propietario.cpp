#include "Propietario.h"

Propietario::Propietario(int id, string nombre, string sexo, string fechaNac, int puntaje, int recibirHuesped)
        : id(id), nombre(nombre), sexo(sexo), fechaNac(fechaNac), puntaje(puntaje), recibirHuesped(recibirHuesped){}

int Propietario::getId(){
    return this->id;
}

void Propietario::setHogar(Hogar* pHogar){
    this->pHogar = pHogar;
}

Hogar* Propietario::getHogar(){
    return this->pHogar;
}

string Propietario::getNombre(){
    return this->nombre;
}

void Propietario::mostrarInfo(){
    cout << "Propietario de nombre " << this->nombre << " e ID " << this->id << endl;
}

void Propietario::actualizarCal(int calificacion){
    int puntajeN = (this->puntaje + calificacion) / 2;
    this->puntaje = puntajeN;
}