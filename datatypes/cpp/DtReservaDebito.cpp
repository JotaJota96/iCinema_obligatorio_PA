#include "..\h\DtReservaDebito.h"

DtReservaDebito::DtReservaDebito(){
}

DtReservaDebito::DtReservaDebito(int _id, int _asientos, float _costo, tipoReserva _tipo, std::string _nombreBanco):DtReserva (_id, _asientos, _costo, _tipo){
    nombreBanco = _nombreBanco;
}


DtReservaDebito::~DtReservaDebito(){
	
}


//Getters ---------------
std::string DtReservaDebito::getNombreBanco(){
    return nombreBanco;
}


