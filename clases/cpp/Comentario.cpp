#include "../h/Comentario.h"
#include <stdexcept>

int Comentario::contadorDeComentarios= 0;
int Comentario::getNuevoID(){
    return ++Comentario::contadorDeComentarios;
}

// constructor y destructor
Comentario::Comentario(){
    this->id = 0;
    this->texto = "";
    this->nivelSubComentario = 0;
    this->miUsuario = NULL;
    this->misSubComentarios = new OrderedDictionary();
}
Comentario::Comentario(int id, string texto, int nivelSubComentario, Usuario* usuario){

    //if(usuario == NULL){
    //    throw std::invalid_argument("El usuario es vacio");
    //}

    this->id = id;
    this->texto = texto;
    this->nivelSubComentario = nivelSubComentario;
    this->miUsuario = usuario;
    this->misSubComentarios = new OrderedDictionary();
}
Comentario::~Comentario(){
    // en realidad aca deberia ir el codigo que hay en eliminarComentarios() y eliminarComentarios() no existir, pero para no modificar los Diagramas de Comunicacion, lo parcheamos asi, y aca queda vacio
}

// gets y sets
int Comentario::getID(){
    return this->id;
}
string Comentario::getTexto(){
    return this->texto;
}
int Comentario::getNivelSubComentario(){
    return this->nivelSubComentario;
}
void Comentario::setID(int id){
    this->id = id;
}
void Comentario::setTexto(string texto){
    this->texto = texto;
}
void Comentario::setNivelSubComentario(int nivelSubComentario){
    this->nivelSubComentario = nivelSubComentario;
}

// operaciones
Comentario* Comentario::comentar(string texto, int id){
    if (id == this->id){
        int nuevoID = Comentario::getNuevoID();
        IKey* k = new Integer(nuevoID);
        Comentario* nc = new Comentario(nuevoID, texto, this->nivelSubComentario+1, NULL);
        this->misSubComentarios->add(k, nc);
        return nc;
    }else{
        Comentario* nc = NULL;
        IIterator* it = this->misSubComentarios->getIterator();
        while(nc == NULL && it->hasCurrent()){
            nc = static_cast<Comentario*>(it->getCurrent())->comentar(texto, id);
            it->next();
        }
        delete it;
        return nc;
    }
}


bool Comentario::esComentario(int id){
    return (this->id == id);
}


void Comentario::vincularUsuario(Usuario* usuario){

    if(usuario == NULL){
        throw std::invalid_argument("El usuario es vacio");
    }

    this->miUsuario = usuario;
}


DtComentario* Comentario::getDataType(){
    return new DtComentario(this->id,
                            this->texto,
                            this->nivelSubComentario,
                            this->miUsuario->getNickname()
                            );
}


ICollection* Comentario::obtenerSubComentarios(){ //set(DtComentario)
    // no me pregunten por que anda, porque lo hice a intuicion, y anduvo.

    // iterador para recorrer los comentarios del comentario actual
    IIterator* it = this->misSubComentarios->getIterator();
    // coleccion a retornar con mis comentarios y los comentarios de mis comentarios (recursivamente)
    ICollection* ret = new List();
    // itero sobre mis comentarios (si hay, sino retorno la coleccion vacia y el que me llamo que se maneje)
    while (it->hasCurrent()){
        // agrego a la coleccion de retorno los datos de uno de mis comentarios
        // para obtener el datatype en vez de hacer un puntero que apunte al it->getCurrent y luego a ese puntero hacerle un ->getDataType para despues hacerle add a la coleccion de retorno, mejor lo resumo todo en la siguiente linea: (que curiosamente es mucho mas corta que este comentario donde explico por que es mas corto hacerlo asi que de la manera que dije al principio de este comentario)
        ret->add(static_cast<Comentario*>(it->getCurrent())->getDataType());

        // a ese comentario le pido todos sus comentarios
        ICollection* colSC = static_cast<Comentario*>(it->getCurrent())->obtenerSubComentarios();
        // para iterar sobre la coleccion de comentarios de mi comentario
        IIterator* itColSC = colSC->getIterator();
        // para cada comentario de mi comentario, lo agrego a la coleccion a devolver
        while (itColSC->hasCurrent()) {
            ret->add(itColSC->getCurrent());
            itColSC->next();
        }
        // al llegar hasta aca en la coleccion ret esta uno de mis comentarios y todos sus comentarios
        delete colSC;
        it->next();
        // repito el proceso para cada uno de mis comentarios
    }
    // al final tengo una coleccion con todos los comentarios de manera recursiva
    delete it;
    return ret;
}


void Comentario::eliminarComentarios(){
    IIterator* it = this->misSubComentarios->getIterator();
    while (it->hasCurrent()){
        static_cast<Comentario*>(it->getCurrent())->eliminarComentarios();
        delete it->getCurrent();
        it->next();
    }
    delete it;
    delete this->misSubComentarios;
}



