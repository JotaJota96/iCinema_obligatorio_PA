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


//Sobrecarga-------------
std::ostream& operator <<(std::ostream &salida, const DtReservaDebito &r){
    // casteo la direccion donde esta r a un tipo const DtReserva* y mando a mostrar lo que esta en esa direccion
    // osea, llama a la sobrecarga de la clase padre DtReserva
    cout << *(static_cast<const DtReserva*>(&r)) << endl;
    /*
     * // Es lo mismo que haber hecho esto pero en una linea...
     * const DtReserva *rr = &r;
     * cout << *rr << endl;
     */

    salida << "Banco: " << r.nombreBanco;

    return salida;
}
