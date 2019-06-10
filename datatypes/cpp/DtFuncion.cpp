#include "../h/DtFuncion.h"

DtFuncion::DtFuncion(){
}

DtFuncion::DtFuncion(int ID,DateTime FechaYHora,int IDSala){
    this->ID=ID;
    this->FechaYHora=FechaYHora;
    this->idSala=IDSala;
}

DtFuncion::~DtFuncion(){
}

int DtFuncion::getID(){
    return this->ID;
}
DateTime DtFuncion::getFechaYHora(){
    return this->FechaYHora;
}
int DtFuncion::dtIDSala(){
    return this->idSala;
}
