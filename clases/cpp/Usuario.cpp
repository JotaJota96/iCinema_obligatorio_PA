#include "../h/Usuario.h"
#include <stdexcept>

//----------------------------------------------------------------------------
// constructor y destructor
Usuario::Usuario(){
    this->nickname = "";
    this->contrasenia = "";
    this->imagen = "";
    this->admin = false;
    this->puntuaciones = new OrderedDictionary();
}

Usuario::Usuario(string nickname, string contrasenia, string imagen, bool admin){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->imagen = imagen;
    this->admin = admin;
    this->puntuaciones = new OrderedDictionary();
}

Usuario::~Usuario(){
    // elimina la coleccion, las instancias coleccionadas no se eliminan, NO deben ser eliminadas
    delete this->puntuaciones;
}

//----------------------------------------------------------------------------
// gets y sets
string Usuario::getNickname(){
    return this->nickname;
}
string Usuario::getContrasenia(){
    return this->contrasenia;
}
string Usuario::getImagen(){
    return this->imagen;
}
bool Usuario::getAdmin(){
    return this->admin;
}
void Usuario::setNickname(string nickname){
    this->nickname = nickname;
}
void Usuario::setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;
}
void Usuario::setImagen(string imagen){
    this->imagen = imagen;
}
void Usuario::setAdmin(bool admin){
    this->admin = admin;
}


//----------------------------------------------------------------------------
// operaciones
int Usuario::obtenerPuntajeDado(string titulo){
    int puntaje = -1;
    // crea el iterador que se usara para realizar la recorrida
    IIterator *it = puntuaciones->getIterator();
    // mientras no se haya encontrad el puntaje y hayan elementos
    while ( puntaje == -1 && it->hasCurrent()){
        // obtiene el puntaje del elemento actual
        puntaje = (dynamic_cast<Puntuacion*>(it->getCurrent()))->obtenerPuntuacion(titulo);
        it->next(); // avanza
    }
    delete it;
    return puntaje;
}


bool Usuario::yaPuntuoPelicula(string titulo){
    // crea una clave para realizar la consulta
    IKey *k = new String(titulo.c_str());
    bool ret = this->puntuaciones->member(k);
    // elimina la clave utilizada para la consulta
    delete k;
    return ret;

}


void Usuario::actualizarPuntuacion(string titulo, int puntaje){
    // crea una clave para realizar la consulta
    IKey *k = new String(titulo.c_str());
    // obtiene el elemento buscado
    Puntuacion *pt = dynamic_cast<Puntuacion*>(this->puntuaciones->find(k));

    if(pt == NULL){
        throw std::invalid_argument("No se a puntuado esta pelicula");
    }

    // elimina la clave de busqueda
    delete k;
    // actualiza el puntaje
    pt->setPuntaje(puntaje);
}


void Usuario::vincularNuevaPuntuacion(Puntuacion *p){

    if(p == NULL){
        throw std::invalid_argument("La puntuacion es vacia");
    }

    // crea una clave para el nuevo elemento coleccionado
    IKey *k = new String((p->getTitulo()).c_str());
    // agrega a la coleccion
    this->puntuaciones->add(k, p);
    // no se debe borrar la k, ya que es a esta instancia a la cual queda referenciando la coleccion
}

bool Usuario::validarContrasenia(string contrasenia){
    return this->contrasenia == contrasenia;
}

void Usuario::eliminarLinkAPuntuacion(string titulo){
    // crea la clave para identificar al elemento
    IKey *k = new String(titulo.c_str());
    // quita el elemento de la coleccion
    puntuaciones->remove(k);
    // elimina la clave utilizada para realizar la busqueda
    delete k;
}

