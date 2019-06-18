#include "../h/ReservaDebito.h"
#include <stdexcept>

ReservaDebito::ReservaDebito()
    :Reserva(){
    this->nombreBanco = "";
}

ReservaDebito::ReservaDebito(int id, int asientos, float costo, string nombreBanco)
    :Reserva(id, asientos, costo, reservaDebito){
    this->nombreBanco = nombreBanco;
}

ReservaDebito::~ReservaDebito(){}   //Destructor





//Métodos Geter Y Seter
string ReservaDebito::getNombreBanco(){
    return this->nombreBanco;
}

void ReservaDebito::setNombreBanco(string _nombreBanco){
    this->nombreBanco = _nombreBanco;
}
