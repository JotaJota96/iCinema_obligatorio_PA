#include "../h/Sala.h"
#include <stdexcept>

int Sala::contadorDeSalas= 0;
int Sala::getNuevoID(){
    return ++Sala::contadorDeSalas;
}



Sala::Sala(){
    this->numero = 0;
    this->capacidad = 0;
    this->miCine = NULL; //new Cine();
}

Sala::Sala(int Numero,int Capacidad, Cine *miCine){

    if(miCine == NULL){
        throw std::invalid_argument("El cine es vacio");
    }

    this->numero = Numero;
    this->capacidad = Capacidad;
    this->miCine = miCine;
}

Sala::~Sala(){
}

int Sala::getNumero(){
    return this->numero;
}

int Sala::getCapacidad(){
    return this->capacidad;
}

DtSala * Sala::getDataType(){
    DtSala * DTS = new DtSala(this->numero,this->capacidad,this->miCine->getID());
    return DTS;
}

void Sala::setNumero(int Numero){
    this->numero=Numero;
}


void Sala::setCapacidad(int Capacidad){
    this->capacidad=Capacidad;
}

bool Sala::perteneceACine(int idCineActual){
    if (this->miCine->getID() == idCineActual) {
        return true;
    }else {
        return false;
    }
}


