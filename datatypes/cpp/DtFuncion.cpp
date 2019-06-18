#include "../h/DtFuncion.h"

DtFuncion::DtFuncion(){
}

DtFuncion::DtFuncion(int ID,DateTime* FechaYHora, float costo, int IDSala){
    this->ID=ID;
    this->FechaYHora=FechaYHora;
    this->costoEntrada = costo;
    this->idSala=IDSala;
}

DtFuncion::~DtFuncion(){
}

int DtFuncion::getID(){
    return this->ID;
}
DateTime* DtFuncion::getFechaYHora(){
    return this->FechaYHora;
}
int DtFuncion::dtIDSala(){
    return this->idSala;
}
float DtFuncion::getCosto(){
    return this->costoEntrada;
}

std::ostream& operator <<(std::ostream &salida, const DtFuncion &f){
    salida << "ID: " << f.ID << endl;
    salida << "Fecha: " << f.FechaYHora << endl;
    salida << "Costo: $" << f.costoEntrada<< endl;
    salida << "Sala: " << f.idSala;
    return salida;
}
