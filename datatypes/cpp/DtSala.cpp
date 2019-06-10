#include "../h/DtSala.h"

DtSala::DtSala(){
}

DtSala::DtSala(int Numero,int Capasidad, int IDCine){
    this->numero = Numero;
    this->capasidad = Capasidad;
    this->idCine = IDCine;
}

DtSala::~DtSala(){
}

int DtSala::getNumero(){
    return this->numero;
}

int DtSala::getCapasidad(){
    return this->capasidad;
}

int DtSala::getIDCine(){
    return this->idCine;
}

