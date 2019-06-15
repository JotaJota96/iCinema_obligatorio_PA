#include "../h/DtFuncion.h"

DtFuncion::DtFuncion(){
}

DtFuncion::DtFuncion(int ID,DateTime* FechaYHora,int IDSala){
    this->ID=ID;
    this->FechaYHora=FechaYHora;
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


std::ostream& operator <<(std::ostream &salida, const DtFuncion &f){
    salida << "ID: " << f.ID << endl;
    salida << "Fecha: " << f.FechaYHora << endl;
    salida << "Sala: " << f.idSala;
    return salida;
}
