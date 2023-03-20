#include "Reserva.h"

Reserva::Reserva(Propietario* pPropietario, Huesped* pHuesped, string fechaInic, string fechaFinal)
        : pPropietario(pPropietario), pHuesped(pHuesped), fechaInic(fechaInic), fechaFinal(fechaFinal){}

void Reserva::mostrarInfo(){
    cout << "La reserva del huesped " << pHuesped->getNombre() << " con el ID " << pHuesped->getId() << " es el hospedaje a nombre de " << pPropietario->getNombre() << " e identificación " << pPropietario->getId() << endl;
}

Propietario* Reserva::getPropietario(){
    return this->pPropietario;
}

Huesped* Reserva::getHuesped(){
    return this->pHuesped;
}