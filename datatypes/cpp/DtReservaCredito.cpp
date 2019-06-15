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


//Sobrecarga-------------
std::ostream& operator <<(std::ostream &salida, const DtReservaCredito &r){
    // casteo la direccion donde esta r a un tipo const DtReserva* y mando a mostrar lo que esta en esa direccion
    // osea, llama a la sobrecarga de la clase padre DtReserva
    cout << *(static_cast<const DtReserva*>(&r)) << endl;
    /*
     * // Es lo mismo que haber hecho esto pero en una linea...
     * const DtReserva *rr = &r;
     * cout << *rr << endl;
     */
    salida << "Financiera: " << r.financiera << endl;
    salida << "Descuento: " << r.descuento;

    return salida;
}
