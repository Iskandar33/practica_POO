#include "Hogar.h"


Hogar::Hogar(int numCamas, int alojarBebes, string descHogar, string direccion)
        : numCamas(numCamas), alojarBebes(alojarBebes), descHogar(descHogar), direccion(direccion){}


void Hogar::mostrarInfoHogar(){
    string alojarB;
    if(alojarBebes == 1){
        alojarB = "Si";
    }
    else{
        alojarB = "No";
    }
    cout << "Hogar: Número de camas disponible: " << numCamas << "Alojamiento de bebes: " << alojarB << "Dirección del hogar: " << direccion << "Descripción del hogar: " << descHogar << endl; 
}