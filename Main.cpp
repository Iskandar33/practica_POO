#include <iostream>
#include "Sistema.h"
#include "Propietario.h"
#include "Huesped.h"
#include "Hogar.h"
#include "Reserva.h"
#include "Evaluacion.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;


void mostrarMenu(Sistema* sistemaBnb){
    int opc = 0;
    do
    {
        cout << "\n**** Bienvenidos a la aplicación Airbnb de Manizales ****\n";
        cout << "1. Agregar propietario\n";
        cout << "2. Mostrar la lista de personas inscritas en el sistema actualmente\n";
        cout << "3. Crear reserva\n";
        cout << "4. Liberar una reserva\n";
        cout << "5. Mostrar lista reservas\n";
        cout << "6. Mostrar lista evaluaciones\n";
        cout << "0. Salir\n" << endl;

        cin >> opc;

        switch(opc)
        {
            case 1:
                sistemaBnb->agregarPropietario();
                break;
            case 2:
                sistemaBnb->mostrarPersonasInscritas();
                break;
            case 3:
                sistemaBnb->crearReserva();
                break;
            case 4:
                sistemaBnb->liberarReserva();
                break;
            case 5:
                sistemaBnb->mostrarReservas();
                break;
            case 6: 
                sistemaBnb->mostrarEvaluaciones();
                break;
            default:
                break;
        }
    }while(opc != 0);
}

int main(){
    Sistema* pSistema = new Sistema();
    mostrarMenu(pSistema);

    // Debo usar el delete explicitamente cuando tengo objetos creados en el heap, ya que estos no se eliminan automáticamente.
    delete pSistema;
    return 0;
}