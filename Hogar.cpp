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
    cout << "Número de camas disponible: " << numCamas << "\nAlojamiento de bebes: " << alojarB << "\nDirección del hogar: " << direccion << "\nDescripción del hogar: " << descHogar << endl; 
}