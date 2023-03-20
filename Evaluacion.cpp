#include "Evaluacion.h"

Evaluacion::Evaluacion(string fecha, int calificacion, string comentarios, string personaDirigida, Propietario* pPropietario, Huesped* pHuesped)
        : fecha(fecha), calificacion(calificacion), comentarios(comentarios), personaDirigida(personaDirigida), pPropietario(pPropietario), pHuesped(pHuesped){}

void Evaluacion::setHuesped(Huesped* pHuesped){
    this->pHuesped = pHuesped;
}

void Evaluacion::setPropietario(Propietario* pPropietario){
    this->pPropietario = pPropietario;
}

void Evaluacion::mostrarInfo(){
    if(this->personaDirigida == "Propietario"){
        cout << "La evaluación del huesped" << this->pHuesped->getNombre() << " al propietario " << this->pPropietario->getNombre() << " tiene una calificación de " << this->calificacion << "y de comentario " << this->comentarios << endl;
    }
    if(this->personaDirigida == "Huesped"){
        cout << "La evaluación del propietario" << this->pPropietario->getNombre() << " al propietario " << this->pHuesped->getNombre() << " tiene una calificación de " << this->calificacion << "y de comentario " << this->comentarios << endl;
    }
}