#include "clases\h\Reserva.h"


Reserva::Reserva(){
    this->id = 0;
    this->asientos = 0;
    this->costo = 0;
    this->tipo = reservaCredito; // por poner algo....
}

Reserva::Reserva(int id, int asientos, float costo, tipoReserva tipo){
    this->id = id;
    this->asientos = asientos;
    this->costo = costo;
    this->tipo = tipo;
}

Reserva::~Reserva(){}


//Métodos Geter Y Seter
int Reserva::getID(){
    return this->id;
}
int Reserva::getAsientos(){
    return this->asientos;
}
float Reserva::getCosto(){
    return this->costo;
}
tipoReserva Reserva::getTipo(){
    return this->tipo;
}
void Reserva::setID(int id){
    this->id = id;
}
void Reserva::setAsientos(int asientos){
    this->asientos = asientos;
}
void Reserva::setCosto(float costo){
    this->costo = costo;
}
void Reserva::setTipo(tipoReserva tipo){
    this->tipo = tipo;
}





