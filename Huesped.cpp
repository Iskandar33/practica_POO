#include "Huesped.h"

Huesped::Huesped(int id, string nombre, string sexo, string fechaNac, int puntaje, string ubicFamiliar, string lugarNac)
        : id(id), nombre(nombre), sexo(sexo), fechaNac(fechaNac), puntaje(puntaje), ubicFamiliar(ubicFamiliar), lugarNac(lugarNac){}

int Huesped::getId(){
        return this->id;
}

string Huesped::getNombre(){
        return this->nombre;
}

void Huesped::mostrarInfo(){
    cout << "Huesped de nombre " << this->nombre << "e ID " << this->id << endl;
}