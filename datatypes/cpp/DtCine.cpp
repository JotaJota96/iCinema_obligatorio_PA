#include "../h/DtCine.h"

DtCine::DtCine(){
}

DtCine::DtCine(int ID, Direccion Direccion){
    this->ID = ID;
    this->direccion=Direccion;
}

DtCine::~DtCine(){
}

int DtCine::getID(){
    return this->ID;
}

Direccion DtCine::getDireccion(){
    return this->direccion;
}
