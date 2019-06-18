#include "../h/Cine.h"
#include <stdexcept>

int Cine::contadorDeCines = 0;
int Cine::getNuevoID(){
    return ++Cine::contadorDeCines;
}

// constructor y destructor
Cine::Cine(){
    this->id = 0;
    this->misSalas = new OrderedDictionary();
}

Cine::Cine(int ID, Direccion *Dir){

    if(Dir == NULL){
        throw std::invalid_argument("La direccion es vacia");
    }

    this->id = ID;
    this->Dir = Dir;
    this->misSalas = new OrderedDictionary();
}

Cine::~Cine(){
    // esto no se si va vacio, lo puse para que compile
    // en realidad aca deberia ir el codigo que hay en eliminarSalas() y eliminarSalas() no existir, pero para no modificar los Diagramas de Comunicacion, lo parcheamos asi, y aca queda vacio
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

    if(Dir == NULL){
        throw std::invalid_argument("La direccion es vacia");
    }

    this->Dir=Dir;
}

DtCine *Cine::getDataType(){
   DtCine * DTC = new DtCine(this->id, this->Dir);
    return DTC;
}

// operaciones
Sala* Cine::obtenerSala(int id){
    IKey *k = new Integer(id);
    Sala *s = (Sala*) this->misSalas->find(k);

    if(s == NULL){
        throw std::invalid_argument("Esa sala no se encuentra");
    }

    delete k;
    return s;
}

void Cine::agregarSala(int capacidad){
    int idSala = Sala::getNuevoID();
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

void Cine::eliminarSalas(){
    IIterator *it = misSalas->getIterator();
    while(it->hasCurrent()){
        Sala *Borrar = static_cast<Sala *> (it->getCurrent());
        delete Borrar;
        it->next();
    }
    delete it;
    delete misSalas;
}
