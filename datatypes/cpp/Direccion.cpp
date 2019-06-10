#include "../h/Direccion.h"


Direccion::Direccion(){
    this->departamento = "";
    this->ciudad = "";
    this->calle = "";
    this->numero = "";
}
Direccion::Direccion(string departamento, string ciudad, string calle, string numero){
    this->departamento = departamento;
    this->ciudad = ciudad;
    this->calle = calle;
    this->numero = numero;
}

string Direccion::getDepartamento(){
    return this->departamento;
}
string Direccion::getCiudad(){
    return this->ciudad;
}
string Direccion::getCalle(){
    return this->calle;
}
string Direccion::getNumero(){
    return this->numero;
}


std::ostream& operator <<(std::ostream &salida, const Direccion &d){
    salida << d.departamento << ", ";
    salida << d.ciudad << ", ";
    salida << d.calle << " ";
    salida << d.numero;
    return salida;
}
