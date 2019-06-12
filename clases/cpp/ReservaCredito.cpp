#include "../h/ReservaCredito.h"

ReservaCredito::ReservaCredito()
    :Reserva(){
    this->financiera = "";
    this->descuento = 0;
}

ReservaCredito::ReservaCredito(int id, int asientos, float costo, string financiera, int descuento)
    :Reserva(id, asientos, costo, reservaCredito){
    this->financiera = financiera;
    this->descuento = descuento;
}

ReservaCredito::~ReservaCredito(){} //Destructor

//Métodos Geter Y Seter
void ReservaCredito::setFinanciera(string _financiera){
    this->financiera = _financiera;
}
void ReservaCredito::setDescuento(int _descuento){
    this->descuento = _descuento;
}
string ReservaCredito::getFinanciera(){
    return this->financiera;
}
int ReservaCredito::getDescuento(){
    return this->descuento;
}
