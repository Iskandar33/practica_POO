#include "Sistema.h"

void Sistema::agregarPropietario(){
    int puntaje = 0, recibirHuesped = 0;
    string nombre, sexo, fechaNac;
    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese el sexo: " << endl;
    cin.ignore();
    getline(cin, sexo, '\n');
    cout << "Ingrese la fecha de nacimiento: " << endl;
    cin.ignore();
    getline(cin, fechaNac, '\n');
    Propietario* pPropTemp = new Propietario(this->acumUsuarios, nombre, sexo, fechaNac, puntaje, recibirHuesped);
    this->agregarHogar(pPropTemp);
    this->mapaProp.insert(make_pair(this->acumUsuarios, pPropTemp));
    this->acumUsuarios++;
}

void Sistema::agregarHogar(Propietario* pPropietario){
    int numCamas, alojarBebes;
    string descHogar, direccion;
    cout << "Ingrese la descripción del hogar" << endl;
    cin.ignore();
    getline(cin, descHogar, '\n');
    cout << "Ingrese la dirección del hogar" << endl;
    cin.ignore();
    getline(cin, direccion, '\n');
    cout << "Ingrese el número de camas " << endl;
    cin >> numCamas;
    cout << "Permite alojar bebes? (1: Si / 2: No) " << endl;
    cin >> alojarBebes;
    Hogar* pHogarTemp = new Hogar(numCamas, alojarBebes, descHogar, direccion);
    pPropietario->setHogar(pHogarTemp);
}

Huesped* Sistema::agregarHuesped(){
    int puntaje = 0;
    string nombre, sexo, fechaNac, ubicFamiliar, lugarNac;
    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese el sexo: " << endl;
    cin.ignore();
    getline(cin, sexo, '\n');
    cout << "Ingrese la fecha de nacimiento: " << endl;
    cin.ignore();
    getline(cin, fechaNac, '\n');
    cout << "Ingrese la ubicación del familiar: " << endl;
    cin.ignore();
    getline(cin, ubicFamiliar, '\n');
    cout << "Ingrese el lugar de nacimiento: " << endl;
    cin.ignore();
    getline(cin, lugarNac, '\n');
    Huesped* pHuespedTemp = new Huesped(this->acumUsuarios, nombre, sexo, fechaNac, puntaje, ubicFamiliar, lugarNac);
    this->mapaHuesped.insert(make_pair(this->acumUsuarios, pHuespedTemp));
    this->acumUsuarios++;
}

void Sistema::mostrarPersonasInscritas(){
    unordered_map<int, Propietario*>::iterator itMap1;
    unordered_map<int, Huesped*>::iterator itMap2;
    cout << "Propietarios: " << endl;
    for(itMap1 = this->mapaProp.begin(); itMap1 != this->mapaProp.end(); ++itMap1){
        itMap1->second->mostrarInfo();
    }

    cout << "Huespedes: " << endl;
    for(itMap2 = this->mapaHuesped.begin(); itMap2 != this->mapaHuesped.end(); ++itMap2){
        itMap2->second->mostrarInfo();
    }
}


void Sistema::mostrarInfoPropHogar(){
    unordered_map<int, Propietario*>::iterator itMap;
    cout << "La lista de los propietarios con sus hospedajes se va a mostrar para su elección \n" << endl;
    for(itMap = this->mapaProp.begin(); itMap != this->mapaProp.end(); ++itMap){
        if(itMap->second->recibirHuesped == 1){
            cout << "La ID del propietario es: " << itMap->first << "\n El hospedaje a su nombre es: " << endl;
            itMap->second->getHogar()->mostrarInfoHogar();
        }
    }
}

void Sistema::agregarReserva(Propietario* pPropietario, Huesped* pHuesped){
    string fechaInic, fechaFinal;
    cout << "Ingrese la fecha de inicio del hospedaje: " << endl;
    cin.ignore();
    getline(cin, fechaInic, '\n');
    cout << "Ingrese la fecha del fin del hospedaje: " << endl;
    cin.ignore();
    getline(cin, fechaFinal, '\n');
    Reserva* pReservaTemp = new Reserva(pPropietario, pHuesped, fechaInic, fechaFinal);
    this->mapaReserva.insert(make_pair(pPropietario->getId(), pReservaTemp));
}

void Sistema::crearReserva(){
    Huesped* pHuespedTemp = agregarHuesped();
    unordered_map<int, Propietario*>::iterator itMap;
    int id, flag = 0, bFlag = 0;
    Propietario* pPropEscogido;
    
    while(bFlag == 0){
        this->mostrarInfoPropHogar();
        cout << "Para escoger un hospedaje, escribe la ID del propietario \n" << endl;
        cin >> id;
        
        itMap = this->mapaProp.begin();
        while((itMap != this->mapaProp.end()) && (flag != 1)){
            if(id == itMap->first){
                flag = 1;
                pPropEscogido = itMap->second;
            }
            else{
                itMap++;
            }
        }
        if(pPropEscogido->recibirHuesped == 0){
            cout << "Este propietario no se puede escoger pues ya tiene un huesped a su nombre\n" << endl;
        }
        else{
            bFlag = 1;
        }
    }
    this->agregarReserva(pPropEscogido, pHuespedTemp);
    pPropEscogido->recibirHuesped = 0;

}

void Sistema::mostrarReservas(){
    unordered_map<int, Reserva*>::iterator itMap;
    cout << "La lista de las reservas que hay en el sistema actualmente es: \n" << endl;
    for(itMap = this->mapaReserva.begin(); itMap != this->mapaReserva.end(); ++itMap){
        cout << "La ID de la reserva es: " << itMap->first << endl;
        itMap->second->mostrarInfo();
    }
}

void Sistema::mostrarEvaluaciones(){
    unordered_map<int, Evaluacion*>::iterator itMap;
    cout << "La lista de las evaluaciones que hay en el sistema actualmente es: \n" << endl;
    for(itMap = this->mapaEvaluaciones.begin(); itMap != this->mapaEvaluaciones.end(); ++itMap){
        itMap->second->mostrarInfo();
    }
}

void Sistema::agregarEvaluacion(Reserva* pReserva){
    string fecha, comentarios, personaDirigidaH = "Huesped", personaDirigidaP = "Propietario";
    int calificacion;
    cout << "El huesped evaluará al propietario y viceversa" << endl;
    cout << "Evaluación del huesped al propietario: " << endl;
    cout << "Ingrese la fecha: " << endl;
    cin.ignore();
    getline(cin, fecha, '\n');
    cout << "Ingrese la calificación del propietario: " << endl;
    cin >> calificacion;
    cout << "Ingrese los comentarios: " << endl;
    cin.ignore();
    getline(cin, comentarios, '\n'); 
    Evaluacion* pEvaluacionHP = new Evaluacion(fecha, calificacion, comentarios, personaDirigidaP, pReserva->getPropietario(), pReserva->getHuesped());
    this->mapaEvaluaciones.insert(make_pair(pReserva->getHuesped()->getId(), pEvaluacionHP));

    cout << "Evaluación del propietario al huesped: " << endl;
    cout << "Ingrese la fecha: " << endl;
    cin.ignore();
    getline(cin, fecha, '\n');
    cout << "Ingrese la calificación del huesped: " << endl;
    cin >> calificacion;
    cout << "Ingrese los comentarios: " << endl;
    cin.ignore();
    getline(cin, comentarios, '\n'); 
    Evaluacion* pEvaluacionPH = new Evaluacion(fecha, calificacion, comentarios, personaDirigidaH, pReserva->getPropietario(), pReserva->getHuesped());
    this->mapaEvaluaciones.insert(make_pair(pReserva->getPropietario()->getId(), pEvaluacionPH));
}

void Sistema::liberarReserva(){
    int opc;
    mostrarReservas();
    cout << "Ingrese el ID de la reserva a liberar: " << endl;
    cin >> opc;
    if(this->mapaReserva.find(opc) != this->mapaReserva.end()){
        cout << "La reserva fue encontrada, se liberará del sistema a continuación." << endl;
        cout << "Para eliminarla, antes es necesario evaluar al huesped y al propietario" << endl;
        agregarEvaluacion(this->mapaReserva.find(opc)->second);
        this->mapaReserva.find(opc)->second->getPropietario()->recibirHuesped = 1;
        this->mapaReserva.erase(opc);
        cout << "La reserva fue liberada con exito." << endl;
    }
    else{
        cout << "No se encontró la reserva buscada, ingrese un valor correcto." << endl;
    }
}