#include "..\h\DtReservaCredito.h"

DtReservaCredito::DtReservaCredito(){
}

DtReservaCredito::DtReservaCredito(int _id, int _asientos, float _costo, tipoReserva _tipo, std::string _financiera, int _descuento): DtReserva (_id, _asientos, _costo, _tipo){
    financiera = _financiera;
    descuento = _descuento;
}


DtReservaCredito::~DtReservaCredito(){
	
}


//Getters ---------------
std::string DtReservaCredito::getFinanciera(){
    return financiera;
}


int DtReservaCredito::getDescuento(){
    return descuento;
}

