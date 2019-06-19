#include "../../clases/h/Pelicula.h"
#include <stdexcept>

Pelicula::Pelicula(){
    this->titulo = "";
    this->poster = "";
    this->sinopsis = "";
    this->puntuaciones = new List();
    this->comentarios = new OrderedDictionary();
    this->cines = new OrderedDictionary();
    this->funciones = new OrderedDictionary();
}
Pelicula::Pelicula(string titulo, string poster, string sinopsis){
    this->titulo = titulo;
    this->poster = poster;
    this->sinopsis = sinopsis;
    this->puntuaciones = new List();
    this->comentarios = new OrderedDictionary();
    this->cines = new OrderedDictionary();
    this->funciones = new OrderedDictionary();
}

Pelicula::~Pelicula(){
}

// gets y sets
string Pelicula::getTitulo(){
    return this->titulo;
}
string Pelicula::getPoster(){
    return this->poster;
}
string Pelicula::getSinopsis(){
    return this->sinopsis;
}
int Pelicula::getPuntuacion(){

    if(puntuaciones->isEmpty()){
        return 0;
    }

    int res = 0, contador =0;
    IIterator *it = this->puntuaciones->getIterator();

    while(it->hasCurrent()){
        Puntuacion *puntuacionActual = dynamic_cast<Puntuacion*>(it->getCurrent());
        res = res + puntuacionActual->getPuntaje();
        contador++;
        it->next();
    }
    res = res/contador;
    return res;

}

void Pelicula::setTitulo(string titulo){
    this->titulo = titulo;
}
void Pelicula::setPoster(string poster){
    this->poster = poster;
}
void Pelicula::setSinopsis(string sinopsis){
    this->sinopsis = sinopsis;
}

Comentario* Pelicula::comentarComentario(string texto, int idComentarioActual){
    IIterator *it = this->comentarios->getIterator();
    Comentario *ret = NULL;
     while (ret == NULL && it->hasCurrent()) {
        ret = dynamic_cast<Comentario *> (it->getCurrent())->comentar(texto,idComentarioActual);
        it->next();
     }
     delete it;
     return ret;
}

Comentario* Pelicula::comentar(string texto){
    int nuevoID = Comentario::getNuevoID();
    IKey *k = new Integer(nuevoID);
    Comentario *c = new Comentario(nuevoID,texto,0,NULL);
    this->comentarios->add(k,c);
    return c;
}

Puntuacion* Pelicula::nuevaPuntuacion(int puntos){
    Puntuacion *p = new Puntuacion(this->titulo,puntos);
    this->puntuaciones->add(p);
    return p;
}

ICollection* Pelicula::obtenerCines(){
    IIterator *it = cines->getIterator();
    ICollection *res = new List();

    while (it->hasCurrent()){
        Cine *cineActual = static_cast<Cine *>(it->getCurrent());
        DtCine *dtCine = cineActual->getDataType();
        res->add(dtCine);
        it->next();
    }
    delete it;
    return res;
}

ICollection* Pelicula::obtenerComentarios(){

    IIterator* it = this->comentarios->getIterator();
    ICollection* ret = new List();

    while (it->hasCurrent()){
        ret->add(static_cast<Comentario*>(it->getCurrent())->getDataType());
        ICollection* colSC = static_cast<Comentario*>(it->getCurrent())->obtenerSubComentarios();
        IIterator* itColSC = colSC->getIterator();
        while (itColSC->hasCurrent()) {
            ret->add(itColSC->getCurrent());
            itColSC->next();
        }
        delete colSC;
        it->next();
    }
    delete it;
    return ret;
}

DtPelicula* Pelicula::getDataType(){
    DtPelicula *dtRes = new DtPelicula(this->titulo,this->poster,this->sinopsis,this->getPuntuacion());
    return dtRes;
}

Funcion* Pelicula::crearFuncion(DateTime* fechaYHora, float costoEntrada, Cine *cineActual){

    if(fechaYHora == NULL){
        throw std::invalid_argument("La fecha y hora es vacia");
    }
    if(cineActual == NULL){
        throw std::invalid_argument("El cine es vacio");
    }


    int IDFuncion = Funcion::getNuevoID();
    Funcion *f = new Funcion(IDFuncion,fechaYHora,costoEntrada);
    IKey *kf = new Integer(IDFuncion);
    this->funciones->add(kf,f);

    int IDCine = cineActual->getID();
    IKey *kc = new Integer(IDCine);
    if(!(this->cines->member(kc))){
        this->cines->add(kc,cineActual);
    }
    return f;
}

float Pelicula::getCostoDeFuncion(int idFuncionActual){
    IKey *k = new Integer(idFuncionActual);
    Funcion *f = dynamic_cast<Funcion *>(this->funciones->find(k));

    if(f == NULL){
        throw std::invalid_argument("No existe funcion con ese ID");
    }

    delete k;
    return f->getCostoEntrada();
}

ICollection* Pelicula::obtenerFunciones(DateTime *fechaActual, int idCineActual){

    if(fechaActual == NULL){
        throw std::invalid_argument("La fecha es vacia");
    }

    IIterator *it = funciones->getIterator();
    ICollection *ret = new List();
    while(it->hasCurrent()){
        Funcion *f = dynamic_cast<Funcion *>(it->getCurrent());
        if (f->esPosterior(fechaActual)) {
            if (f->esEnCine(idCineActual)){
                ret->add(f->getDataType());
            }
        }
        it->next();
    }
    delete it;
    return ret;
}

DtFuncion* Pelicula::obtenerDtFuncion(int idFuncion){

    IKey *k = new Integer(idFuncion);
    Funcion *f = dynamic_cast<Funcion *>(this->funciones->find(k));

    if(f == NULL){
        throw std::invalid_argument("No existe funcion con ese ID");
    }

    delete k;
    return f->getDataType();
}

void Pelicula::eiminarLinks(){
    IIterator *it = funciones->getIterator();
    while (it->hasCurrent()) {
        Funcion *f = dynamic_cast<Funcion *>(it->getCurrent());
        f->eliminarReservas();
        delete f;
        it->next();
    }
    delete it;
    delete funciones;

    it = comentarios->getIterator();
    while (it->hasCurrent()) {
        Comentario *c = dynamic_cast<Comentario *>(it->getCurrent());
        c->eliminarComentarios();
        delete c;
        it->next();
    }
    delete it;
    delete comentarios;
}

void Pelicula::agregarReservaAFuncion(DtReserva *dtNuevaReserva, int idFuncionActual){
    IKey *k = new Integer(idFuncionActual);
    Funcion *f = dynamic_cast<Funcion *>(funciones->find(k));

    if(f == NULL){
        throw std::invalid_argument("No existe funcion con ese ID");
    }

    delete k;
    f->agregarReserva(dtNuevaReserva);
}

