#include "../h/Cine.h"

// constructor y destructor
Cine::Cine(){
    this->id = 0;
    this->misSalas = new OrderedDictionary();
    this->contadorDeSalas = 0;
}

Cine::Cine(int ID, Direccion *Dir){
    this->id = ID;
    this->Dir = Dir;
    this->misSalas = new OrderedDictionary();
    this->contadorDeSalas = 0;
}

Cine::~Cine(){
    // esto no se si va vacio, lo puse para que compile
}

// gets y sets
int Cine::getID(){
    return this->id;
}

Direccion* Cine::getDireccion(){
    return this->Dir;
}

void Cine::setID(int ID){
    this->id=ID;
}

void Cine::setDireccion(Direccion *Dir){
    this->Dir=Dir;
}

DtCine Cine::getDataType(){
    DtCine * DTC = new DtCine(this->id,*this->Dir);
    return * DTC;
}

// operaciones
Sala* Cine::obtenerSala(int id){
    IKey *k = new Integer(id);
    Sala *s = (Sala*) this->misSalas->find(k);
    delete k;
    return s;
}

void Cine::agregarSala(int capacidad){
    int idSala = contadorDeSalas++;
    IKey *k = new Integer(idSala);
    Sala *s = new Sala(idSala, capacidad, this);
    this->misSalas->add(k, s);
}

bool Cine::esCine(int ID){
    if (this->id == ID){
        return true;
    }else{
        return false;
    }
}

ICollection* Cine::listarSalas(){
    IIterator *it = misSalas->getIterator();
    ICollection *res = new List();

    while(it->hasCurrent()){
        Sala *Salas = static_cast<Sala *> (it->getCurrent());
        DtSala * SalaDT = Salas->getDataType();
        res->add(SalaDT);
        it->next();
    }
    delete it;
    return res;
}

void Cine::eliminarSala(){

    IIterator *it = misSalas->getIterator();
    while(it->hasCurrent()){
        Sala *Borrar = static_cast<Sala *> (it->getCurrent());
        delete Borrar;
        it->next();
    }

    delete it;
}
