#include "../h/Funcion.h"
#include <stdexcept>

int Funcion::contadorFunciones=0;

int Funcion::getNuevoID(){
    return ++contadorFunciones;
}

Funcion::Funcion()
{
    this->id=0;
    this->fechaYHora=new DateTime();
    this->costoEntrada=0;
    this->s=NULL;
    this->misReservas = new OrderedDictionary();
}
Funcion::Funcion(int id,DateTime *FechaYHora,float CostoEntrada){
    this->id = id;
    this->fechaYHora = FechaYHora;
    this->costoEntrada = CostoEntrada;
    this->misReservas = new OrderedDictionary();
    this->s = NULL;
}

Funcion::~Funcion(){
    delete fechaYHora;
}


int Funcion::getId(){
    return this->id;
}

DateTime *Funcion::getFechaYHora(){
    return this->fechaYHora;
}

float Funcion::getCostoEntrada(){
    return this->costoEntrada;
}

void Funcion::setId(int Id){
    this->id=Id;
}

void Funcion::setFechaYHora(DateTime *FechaYHora){

    if(FechaYHora == NULL){
        throw std::invalid_argument("La fecha y hora es vacia");
    }

    this->fechaYHora=FechaYHora;
}


DtFuncion * Funcion::getDataType(){
    DtFuncion * DTF = new DtFuncion(this->id,this->fechaYHora,this->costoEntrada, this->s->getNumero());
    return DTF;
}


void Funcion::agregarReserva(DtReserva *dtNuevaReserva){

    if(dtNuevaReserva == NULL){
        throw std::invalid_argument("El dtNuevaReserva es vacio");
    }

    if(dtNuevaReserva->getTipo()==reservaCredito){
        int id=Reserva::getNuevoID();
        IKey *k = new Integer(id);
        Reserva *r = new ReservaCredito(
                                        id,
                                        dynamic_cast<DtReservaCredito*>(dtNuevaReserva)->getAsientos(),
                                        dynamic_cast<DtReservaCredito*>(dtNuevaReserva)->getCosto(),
                                        dynamic_cast<DtReservaCredito*>(dtNuevaReserva)->getFinanciera(),
                                        dynamic_cast<DtReservaCredito*>(dtNuevaReserva)->getDescuento()
                                        );

        this->misReservas->add(k, r);
    }

    if(dtNuevaReserva->getTipo()==reservaDebito){
        int id=Reserva::getNuevoID();
        IKey *k = new Integer(id);
        Reserva *r = new ReservaDebito(
                                        id,
                                        dynamic_cast<DtReservaDebito*>(dtNuevaReserva)->getAsientos(),
                                        dynamic_cast<DtReservaDebito*>(dtNuevaReserva)->getCosto(),
                                        dynamic_cast<DtReservaDebito*>(dtNuevaReserva)->getNombreBanco()
                                        );

        this->misReservas->add(k, r);
    }
}


void Funcion::eliminarReservas(){
    IIterator *it = this->misReservas->getIterator();
    while(it->hasCurrent()){
        Reserva *Borrar = dynamic_cast<Reserva *> (it->getCurrent());
        delete Borrar;
        it->next();
    }
    delete it;
    delete misReservas;
}

void Funcion::asignarSala(Sala *salita){

    if(salita == NULL){
        throw std::invalid_argument("La salita es vacia");
    }

    this->s = salita;
}

bool Funcion::esEnCine(int idCineActual){
    return this->s->perteneceACine(idCineActual);
}


bool Funcion::esPosterior(DateTime *fechaActual){

    if(fechaActual == NULL){
        throw std::invalid_argument("La fechaActual es vacia");
    }

   return *fechaActual < *(this->fechaYHora);
}
