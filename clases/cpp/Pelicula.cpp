#include "../../clases/h/Pelicula.h"

Pelicula::Pelicula(){
    this->titulo = "";
    this->poster = "";
    this->sinopsis = "";
    this->puntuaciones = new List();
    this->comentarios = new OrderedDictionary();
    this->cines = new OrderedDictionary();
}
Pelicula::Pelicula(string titulo, string poster, string sinopsis){
    this->titulo = titulo;
    this->poster = poster;
    this->sinopsis = sinopsis;
    this->puntuaciones = new List();
    this->comentarios = new OrderedDictionary();
    this->cines = new OrderedDictionary();
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
    //Genero el nuevo id
    int nuevoID = Comentario::getNuevoID();
    //Creo la Key con ese id
    IKey *k = new Integer(nuevoID);
    //Creo el comentario
    Comentario *c = new Comentario(nuevoID,texto,0,NULL);
    //lo agrego a la coleccion
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


    /*
    IIterator *it = comentarios->getIterator();
    ICollection *res = new List();

    while(it->hasCurrent()){
        Comentario *co = static_cast<Comentario*>(it->getCurrent());
        DtComentario *dtComentario = co->getDataType();
        res->add(dtComentario);

        IIterator *it2 = co->obtenerSubComentarios()->getIterator();
        while (it2->hasCurrent()) {
            res->add(it2->getCurrent());
            it2->next();
        }
        delete it2;
        it->next();
    }

    delete it;
    return res;
*/
}

DtPelicula* Pelicula::getDataType(){
    DtPelicula *dtRes = new DtPelicula(this->titulo,this->poster,this->sinopsis,this->getPuntuacion());
    return dtRes;
}

