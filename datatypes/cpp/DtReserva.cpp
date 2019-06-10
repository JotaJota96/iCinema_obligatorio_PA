#include "..\h\DtReserva.h"

DtReserva::DtReserva(){
}


DtReserva::DtReserva(int _id, int _asientos, float _costo, tipoReserva _tipo){
    id = _id;
    asientos = _asientos;
    costo = _costo;
    tipo = _tipo;
}

DtReserva::~DtReserva(){
	
}

//--- Getters -------
int DtReserva:: getId(){
    return id;
}

int DtReserva:: getAsientos(){
    return asientos;
}

float DtReserva::getCosto(){
    return costo;
}

tipoReserva DtReserva:: getTipo(){
	return tipo;
}

