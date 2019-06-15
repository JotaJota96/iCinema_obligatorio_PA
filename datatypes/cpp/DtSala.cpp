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



std::ostream& operator <<(std::ostream &salida, const DtSala &s){
    salida << "Numero: " << s.numero << endl;
    salida << "Capacidad: " << s.capasidad << endl;
    salida << "ID del cine: " << s.idCine;

    return salida;
}

