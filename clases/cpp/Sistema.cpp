#include "clases/h/Sistema.h"
#include "clases/h/ISistema.h"

Sistema * Sistema::instancia = 0;

Sistema::Sistema(){ //Constructor por defecto
    this->financieras["CREDITEL"] = 10.0;
    this->financieras["OCA"] = 15.0;
    this->financieras["FUCAC"] = 8.5;
    this->financieras["CREDITO DE LA CASA"] = 12.0;
    this->financieras["CASH"] = 12.0;
    this->financieras["PRONTO"] = 11.0;
    this->financieras["ANDA"] = 10.0;
    this->financieras["COPAC"] = 12.0;
    this->financieras["MARCRE"] = 5.0;


    //================= Colecciones =======================
    this->DicCines = new OrderedDictionary();
    this->DicUsuarios = new OrderedDictionary();
    this->DicPeliculas = new OrderedDictionary();

    ///////////////////////
    cargarDatosDePrueba();
    ///////////////////////

    //=============== Datos Actuales =======-=============
    this->rolActual = INVITADO;
    this->usuarioActual = NULL;
    this->peliculaActual = NULL;
    this->cineActual = NULL;
    this->peliculaActual = NULL;
    this->idSalaActual = 0;
    this->idFuncionActual = 0;
    this->idComentarioActual = 0;
    this->DtNuevaReserva = NULL;
}

Sistema * Sistema::getInstancia() {
    if (instancia == 0) {
        instancia = new Sistema();
    }
    return instancia;
}

//==================== Geter Y Seter =============================
Cine * Sistema::getCineActual(){
    return this->cineActual;
}
Usuario * Sistema::getUsuarioActual(){
    return this->usuarioActual;
}
Pelicula * Sistema::getPeliculaActual(){
    return this->peliculaActual;
}
int Sistema::getIdComentarioActual(){
    return this->idComentarioActual;
}
int Sistema::getIdFuncionActual(){
    return this->idFuncionActual;
}
int Sistema::getIdSalaActual(){
    return this->idSalaActual;
}
void Sistema::setCineActual(Cine * _cineActual){
    if(_cineActual == NULL){
        throw std::invalid_argument("El nuevo cine actual es vacio");
    }
    this->cineActual = _cineActual;
}
void Sistema::setUsuarioActual(Usuario * _usuarioActual){
    if(_usuarioActual == NULL){
        throw std::invalid_argument("El nuevo usuario actual es vacio");
    }
    this->usuarioActual = _usuarioActual;
}
void Sistema::setPeliculaActual(Pelicula * _peliculaActual){
    if(_peliculaActual == NULL){
        throw std::invalid_argument("La nueva pelicula actual es vacio");
    }
    this->peliculaActual = _peliculaActual;
}
void Sistema::setIdComentarioActual(int _idComentarioActual){
    this->idComentarioActual = _idComentarioActual;
}
void Sistema::setIdFuncionActual(int _idFuncionActual){
    this->idFuncionActual = _idFuncionActual;
}
void Sistema::setIdSalaActual(int _idSalaActual){
    this->idSalaActual = _idSalaActual;
}

//======================= OPERACIONES DEL CONTROLADOR SISTEMA ===========================================
void Sistema::cerrarSesion(){
    this->rolActual = INVITADO;
    this->usuarioActual = NULL;
    this->peliculaActual = NULL;
    this->cineActual = NULL;
    this->peliculaActual = NULL;
    this->idSalaActual = 0;
    this->idFuncionActual = 0;
    this->idComentarioActual = 0;
    this->DtNuevaReserva = NULL;
}

void Sistema::cancelarEliminarPelicula(){  //Terminada Verificar
    this->peliculaActual = NULL;
}
void Sistema::cancelarNuevaReserva(){     //Terminada Verificar
    delete this->DtNuevaReserva;
    this->idFuncionActual = 0;
    this->peliculaActual = NULL;
    this->cineActual = NULL;
}
void Sistema::cancelarNuevoCine(){        //Terminada Verificar
    this->cineActual->eliminarSalas();
    delete cineActual;
}
void Sistema::cancelarVerComentariosYPuntajes(){   //Terminada Verificar
    this->peliculaActual = NULL;
}
void Sistema::cancelarVerInformacionDePelicula(){  //Terminada Verificar
    this->peliculaActual = NULL;
    this->cineActual = NULL;
}
void Sistema::comentarComentario(string _texto){
    Comentario* res = this->peliculaActual->comentarComentario(_texto, this->idComentarioActual);

    if(res == NULL){
        throw std::invalid_argument("No se encontro el comentario");
    }
    res->vincularUsuario(this->usuarioActual);
}
void Sistema::comentarPelicula(string _texto){     //Terminada Verificar
    Comentario * res = this->peliculaActual->comentar(_texto);

    if(res == NULL){
        throw std::invalid_argument("No se pudo comentar la pelicula");
    }
    res->vincularUsuario(this->usuarioActual);
}
void Sistema::confirmarEliminarPelicula(){           // Terminada Verificar
    string titulo = peliculaActual->getTitulo();

    IIterator * it = DicUsuarios->getIterator();
    while (it->hasCurrent()) {
        dynamic_cast<Usuario *>(it->getCurrent())->eliminarLinkAPuntuacion(titulo);
        it->next();
    }
    delete it;

    this->peliculaActual->eiminarLinks();
    IKey * k = new String(titulo.c_str());
    DicPeliculas->remove(k);
    delete peliculaActual;
    delete k;
    peliculaActual = NULL;
}

void Sistema::confirmarNuevaReserva(){
    this->peliculaActual->agregarReservaAFuncion(DtNuevaReserva, idFuncionActual);
    peliculaActual = NULL;
    cineActual = NULL;
    idFuncionActual = 0;
    delete DtNuevaReserva;
    DtNuevaReserva = NULL;
}

void Sistema::confirmarNuevoCine(){                     //Terminada Verificar
    IKey * k = new Integer(this->cineActual->getID());
    this->DicCines->add(k,this->cineActual);
    this->cineActual = NULL;
}

bool Sistema::iniciarSesion(string nickname, string password){ //Terminada Verificar
    bool res; //Respuesta booleana
    //Crea una clave para realizar la busqueda
    IKey * k = new String(nickname.c_str());
    //Obtiene el usuario si existe
    Usuario * u = dynamic_cast<Usuario *>(this->DicUsuarios->find(k));
    delete k;
    if(u != NULL ){
        if(u->validarContrasenia(password)){
            this->usuarioActual = u;
            if (this->usuarioActual->getAdmin()){
                rolActual = ADMINISTRADOR;
            }else{
                rolActual = USUARIO;
            }
            res = true;
        }else {
            res = false;
        }
    }else {
        res = false;
    }
    return res;
}

ICollection* Sistema::listarCines(){        // Terminada Verificar
    return this->peliculaActual->obtenerCines();
}

ICollection * Sistema::listarComentarios(){ // Terminada Verificar
    ICollection * comentarios = this->peliculaActual->obtenerComentarios();
    return comentarios;
}

ICollection * Sistema::listarFunciones(DateTime* fechaActual){ // Terminada Verificar

    if(fechaActual == NULL){
        throw std::invalid_argument("La fecha y horaes vacia");
    }
    int idCineActual = this->cineActual->getID();
    return this->peliculaActual->obtenerFunciones(fechaActual, idCineActual);
}

ICollection* Sistema::listarPeliculas(){     // Terminada Verificar
    ICollection * res = new List();
    IIterator * it = DicPeliculas->getIterator();
    while (it->hasCurrent()) {
        DtPelicula * p = dynamic_cast<Pelicula *>(it->getCurrent())->getDataType();
        res->add(p);
        it->next();
    }
    delete it;
    return res;
}
ICollection * Sistema::listarSalas(){ //Terminada Verificar
    return this->cineActual->listarSalas();
}

ICollection * Sistema::listarSalasOcupadas(DateTime * fechaActual){ //Terminada Verifiar
    int idCineActual = cineActual->getID();
    ICollection * ret = new List();

    IIterator * it = DicPeliculas->getIterator();
    ICollection * aux;
    IIterator * it2;

    while (it->hasCurrent()) {
       Pelicula* p = dynamic_cast<Pelicula*>(it->getCurrent());
       aux = p->obtenerFunciones(fechaActual,idCineActual);
       it2 = aux->getIterator();
       while (it2->hasCurrent()) {
           ret->add(it2->getCurrent());
           it2->next();
       }
       delete it2;
       delete aux;
       it->next();
    }
    delete it;
    return ret;
}

ICollection* Sistema::listarTodosLosCines(){ // Terminada Verificar
    ICollection * ret = new List();
    IIterator * it = DicCines->getIterator();
    while (it->hasCurrent()) {
        ret->add(dynamic_cast<Cine *>(it->getCurrent())->getDataType());
        it->next();
    }
    delete it;
    return ret;
}
void Sistema::nuevaFuncion(DateTime* fechaYHora, float costoEntrada){ // Terminada Verificar

    if(fechaYHora == NULL){
        throw std::invalid_argument("La fecha y hora es vacia");
    }

    Funcion * f = this->peliculaActual->crearFuncion(fechaYHora,costoEntrada,this->cineActual);
    Sala * s = this->cineActual->obtenerSala(this->idSalaActual);
    f->asignarSala(s);
}

void Sistema::nuevaReserva(int _cantAsientos){          //Terminada Verificar

    if(_cantAsientos <= NULL){
        throw std::invalid_argument("La cantidad de asientos es menor a 1");
    }
    this->cantAsientos = _cantAsientos;
}

void Sistema::nuevaSala(int _capacidad){                //Terminada Verificar

    if(_capacidad == NULL){
        throw std::invalid_argument("Capacidad menor a 1");
    }
    this->cineActual->agregarSala(_capacidad);
}

void Sistema::nuevoCine(Direccion* _direccion){         //Terminada Verificar
    if(_direccion == NULL){
        throw std::invalid_argument("La direcion es vacia");
    }

    int id = Cine::getNuevoID();
    Cine * nuevoCine = new Cine(id , _direccion);
    cineActual = nuevoCine;      //Crea el link a cineActual
}

int Sistema::obtenerPuntajeDadoPorUsuario(){            //Termianda Verificar
    string titulo = this->peliculaActual->getTitulo();
    int puntaje = usuarioActual->obtenerPuntajeDado(titulo);
    return puntaje;
}

RolDeUsuario Sistema::obtenerRolDeUsuarioActual(){
    return rolActual;
}

float Sistema::pagoCredito(string nombreFinanciera){   //Terminada Falta verificar el descuento
    float costoFuncion = this->peliculaActual->getCostoDeFuncion(this->idFuncionActual);
    float costo = float(cantAsientos * costoFuncion);
    this->DtNuevaReserva = new DtReservaCredito(this->idFuncionActual, cantAsientos , costo,reservaCredito, nombreFinanciera, (int) financieras[nombreFinanciera]);
    return financieras[nombreFinanciera];
}
void Sistema::pagoDebito(string nombreBanco){
    float costoFuncion = this->peliculaActual->getCostoDeFuncion(this->idFuncionActual);
    float costo = float(cantAsientos * costoFuncion);
    this->DtNuevaReserva = new DtReservaDebito(this->idFuncionActual, cantAsientos, costo, reservaDebito, nombreBanco);   //Terminada verificar
}

void Sistema::puntuarPelicula(int puntaje){             //Terminada Verificar
    if(puntaje < 1 || puntaje > 5){
        throw std::invalid_argument("Puntaje fuera de rango 1 a 5");
    }

    string titulo = this->peliculaActual->getTitulo();
    bool ok = this->usuarioActual->yaPuntuoPelicula(titulo);
    if(ok)
        this->usuarioActual->actualizarPuntuacion(titulo, puntaje);
    else {
        Puntuacion * nuevaPuntuacion = this->peliculaActual->nuevaPuntuacion(puntaje);
        usuarioActual->vincularNuevaPuntuacion(nuevaPuntuacion);
    }
}

DtCine * Sistema::seleccionarCine(int idCine){     //Terminada Verificar
    IKey * k = new Integer(idCine);
    cineActual = dynamic_cast<Cine*>(DicCines->find(k));
    delete k;

    if(cineActual == NULL){
        throw std::invalid_argument("No existe el cine");
    }
    DtCine * cine = cineActual->getDataType();
    return  cine;
}

void Sistema::seleccionarComentario(int id){          //Terminada Verificar
    this->idComentarioActual = id;
}

DtFuncion * Sistema::seleccionarFuncion(int id){        //Terminada Verificar
    this->idFuncionActual = id;
    return this->peliculaActual->obtenerDtFuncion(id);
}
DtPelicula * Sistema::seleccionarPelicula(string titulo){  //Terminada Verificar
    IKey * k = new String(titulo.c_str());
    Pelicula * p = dynamic_cast<Pelicula*>(DicPeliculas->find(k));
    delete k;
    this->peliculaActual = p;

    if(p == NULL){
        throw std::invalid_argument("No existe la pelicula");
    }
    return p->getDataType();
}

void Sistema::seleccionarSala(int idSala){          //Terminada Verificiar
    this->idSalaActual = idSala;
}

DtReserva * Sistema::vistaPreviaDeReserva(){         //Terminada Verificar
        return this->DtNuevaReserva;
}

Sistema::~Sistema(){ //Destructor

}

void Sistema::cargarDatosDePrueba(){
    /*

    Crear usuarios y agregarlos a diccionario
    Crear cines y salas y agregar los cines a diccionario
    Crear peliculas y agregarlas a diccionario
    Puntuar peliculas y asociar puntuaciones a usuarios
    Comentar peliculas y vincularlos al usuario
    comentar comentarios y vincularlos al usuario
    Crear Funciones a peliculas y asociar a salas
    */

    //Usuario *user# = new Usuario('usuario_#','usuario_#','imagen_#',false);
    Usuario *admin = new Usuario("admin","admin","imagen_0",true);
    Usuario *user1 = new Usuario("user","user","imagen_1",false);
    Usuario *user2 = new Usuario("usuario_2","usuario_2","imagen_2",false);
    Usuario *user3 = new Usuario("usuario_3","usuario_3","imagen_3",false);
    Usuario *user4 = new Usuario("usuario_4","usuario_4","imagen_4",false);
    Usuario *user5 = new Usuario("usuario_5","usuario_5","imagen_5",false);
    Usuario *user6 = new Usuario("usuario_6","usuario_6","imagen_6",false);
    Usuario *user7 = new Usuario("usuario_7","usuario_7","imagen_7",false);
    Usuario *user8 = new Usuario("usuario_8","usuario_8","imagen_8",false);
    Usuario *user9 = new Usuario("usuario_9","usuario_9","imagen_9",false);

    //this->DicUsuarios->add(new String(user#->getNickname().c_str()), user#);
    this->DicUsuarios->add(new String(admin->getNickname().c_str()), admin);
    this->DicUsuarios->add(new String(user1->getNickname().c_str()), user1);
    this->DicUsuarios->add(new String(user2->getNickname().c_str()), user2);
    this->DicUsuarios->add(new String(user3->getNickname().c_str()), user3);
    this->DicUsuarios->add(new String(user4->getNickname().c_str()), user4);
    this->DicUsuarios->add(new String(user5->getNickname().c_str()), user5);
    this->DicUsuarios->add(new String(user6->getNickname().c_str()), user6);
    this->DicUsuarios->add(new String(user7->getNickname().c_str()), user7);
    this->DicUsuarios->add(new String(user8->getNickname().c_str()), user8);
    this->DicUsuarios->add(new String(user9->getNickname().c_str()), user9);

    // agregando cines y salas
    Cine *c1 = new Cine(Cine::getNuevoID(), new Direccion("dep1", "ciu1", "cal1", "num1"));
    Cine *c2 = new Cine(Cine::getNuevoID(), new Direccion("dep2", "ciu2", "cal2", "num2"));
    Cine *c3 = new Cine(Cine::getNuevoID(), new Direccion("dep3", "ciu3", "cal3", "num3"));
    c1->agregarSala(10);
    c1->agregarSala(20);
    c1->agregarSala(30);
    c2->agregarSala(40);
    c2->agregarSala(50);
    c2->agregarSala(60);
    c3->agregarSala(70);
    c3->agregarSala(80);
    c3->agregarSala(90);
    this->DicCines->add(new Integer(c1->getID()), c1);
    this->DicCines->add(new Integer(c2->getID()), c2);
    this->DicCines->add(new Integer(c3->getID()), c3);


    // Pelicula *peli# = new Pelicula('pelicula_#?', 'poster_#?', 'sinopsis_#?');
    Pelicula *peli1 = new Pelicula("pelicula_1", "poster_1", "sinopsis_1");
    Pelicula *peli2 = new Pelicula("pelicula_2", "poster_2", "sinopsis_2");
    Pelicula *peli3 = new Pelicula("pelicula_3", "poster_3", "sinopsis_3");
    Pelicula *peli4 = new Pelicula("pelicula_4", "poster_4", "sinopsis_4");
    Pelicula *peli5 = new Pelicula("pelicula_5", "poster_5", "sinopsis_5");
    Pelicula *peli6 = new Pelicula("pelicula_6", "poster_6", "sinopsis_6");
    Pelicula *peli7 = new Pelicula("pelicula_7", "poster_7", "sinopsis_7");
    Pelicula *peli8 = new Pelicula("pelicula_8", "poster_8", "sinopsis_8");
    Pelicula *peli9 = new Pelicula("pelicula_9", "poster_9", "sinopsis_9");


    // this->DicPeliculas->add(new String(peli#->getTitulo().c_str()), peli#);
    this->DicPeliculas->add(new String(peli1->getTitulo().c_str()), peli1);
    this->DicPeliculas->add(new String(peli2->getTitulo().c_str()), peli2);
    this->DicPeliculas->add(new String(peli3->getTitulo().c_str()), peli3);
    this->DicPeliculas->add(new String(peli4->getTitulo().c_str()), peli4);
    this->DicPeliculas->add(new String(peli5->getTitulo().c_str()), peli5);
    this->DicPeliculas->add(new String(peli6->getTitulo().c_str()), peli6);
    this->DicPeliculas->add(new String(peli7->getTitulo().c_str()), peli7);
    this->DicPeliculas->add(new String(peli8->getTitulo().c_str()), peli8);
    this->DicPeliculas->add(new String(peli9->getTitulo().c_str()), peli9);


    // user#->vincularNuevaPuntuacion(peli|->nuevaPuntuacion(@));
    user1->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user1->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user1->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user1->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user1->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user1->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user1->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user1->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user2->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user2->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user2->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user2->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user2->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user2->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user2->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user2->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user3->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user3->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user3->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user3->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user3->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user3->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user3->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user3->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user4->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user4->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user4->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user4->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user4->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user4->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user4->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user4->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user5->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user5->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user5->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user5->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user5->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user5->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user5->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user5->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user6->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user6->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user6->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user6->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user6->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user6->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user6->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user7->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user7->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user7->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user7->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user7->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user7->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user7->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user7->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user8->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user8->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user8->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user8->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user8->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user8->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user8->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user8->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));
    user9->vincularNuevaPuntuacion(peli1->nuevaPuntuacion(5));
    user9->vincularNuevaPuntuacion(peli2->nuevaPuntuacion(3));
    user9->vincularNuevaPuntuacion(peli3->nuevaPuntuacion(5));
    user9->vincularNuevaPuntuacion(peli4->nuevaPuntuacion(1));
    user9->vincularNuevaPuntuacion(peli5->nuevaPuntuacion(5));
    user9->vincularNuevaPuntuacion(peli6->nuevaPuntuacion(4));
    user9->vincularNuevaPuntuacion(peli7->nuevaPuntuacion(4));
    user9->vincularNuevaPuntuacion(peli8->nuevaPuntuacion(1));

    // peli|->comentar('texto de comentario @')->vincularUsuario(user#);
    peli1->comentar("texto de comentario 1")->vincularUsuario(user1);
    peli2->comentar("texto de comentario 2")->vincularUsuario(user1);
    peli3->comentar("texto de comentario 3")->vincularUsuario(user1);
    peli4->comentar("texto de comentario 4")->vincularUsuario(user1);
    peli5->comentar("texto de comentario 5")->vincularUsuario(user1);
    peli1->comentar("texto de comentario 6")->vincularUsuario(user2);
    peli2->comentar("texto de comentario 7")->vincularUsuario(user2);
    peli3->comentar("texto de comentario 8")->vincularUsuario(user2);
    peli4->comentar("texto de comentario 9")->vincularUsuario(user2);
    peli5->comentar("texto de comentario 10")->vincularUsuario(user2);
    peli1->comentar("texto de comentario 11")->vincularUsuario(user3);
    peli2->comentar("texto de comentario 12")->vincularUsuario(user3);
    peli3->comentar("texto de comentario 13")->vincularUsuario(user3);
    peli4->comentar("texto de comentario 14")->vincularUsuario(user3);
    peli5->comentar("texto de comentario 15")->vincularUsuario(user3);
    peli1->comentar("texto de comentario 16")->vincularUsuario(user4);
    peli2->comentar("texto de comentario 17")->vincularUsuario(user4);
    peli3->comentar("texto de comentario 18")->vincularUsuario(user4);
    peli4->comentar("texto de comentario 19")->vincularUsuario(user4);
    peli5->comentar("texto de comentario 20")->vincularUsuario(user4);
    peli1->comentar("texto de comentario 21")->vincularUsuario(user5);
    peli2->comentar("texto de comentario 22")->vincularUsuario(user5);
    peli3->comentar("texto de comentario 23")->vincularUsuario(user5);
    peli4->comentar("texto de comentario 24")->vincularUsuario(user5);
    peli5->comentar("texto de comentario 25")->vincularUsuario(user5);
    peli1->comentar("texto de comentario 26")->vincularUsuario(user6);
    peli2->comentar("texto de comentario 27")->vincularUsuario(user6);
    peli3->comentar("texto de comentario 28")->vincularUsuario(user6);
    peli4->comentar("texto de comentario 29")->vincularUsuario(user6);
    peli5->comentar("texto de comentario 30")->vincularUsuario(user6);
    peli1->comentar("texto de comentario 31")->vincularUsuario(user7);
    peli2->comentar("texto de comentario 32")->vincularUsuario(user7);
    peli3->comentar("texto de comentario 33")->vincularUsuario(user7);
    peli4->comentar("texto de comentario 34")->vincularUsuario(user7);
    peli5->comentar("texto de comentario 35")->vincularUsuario(user7);
    peli1->comentar("texto de comentario 36")->vincularUsuario(user8);
    peli2->comentar("texto de comentario 37")->vincularUsuario(user8);
    peli3->comentar("texto de comentario 38")->vincularUsuario(user8);
    peli4->comentar("texto de comentario 39")->vincularUsuario(user8);
    peli5->comentar("texto de comentario 40")->vincularUsuario(user8);
    peli1->comentar("texto de comentario 41")->vincularUsuario(user9);
    peli2->comentar("texto de comentario 42")->vincularUsuario(user9);
    peli3->comentar("texto de comentario 43")->vincularUsuario(user9);
    peli4->comentar("texto de comentario 44")->vincularUsuario(user9);
    peli5->comentar("texto de comentario 45")->vincularUsuario(user9);

    peli1->comentarComentario("texto de comentario 46", 1)->vincularUsuario(user1);
    peli1->comentarComentario("texto de comentario 47", 1)->vincularUsuario(user2);
    peli1->comentarComentario("texto de comentario 48", 1)->vincularUsuario(user3);
    peli1->comentarComentario("texto de comentario 49", 6)->vincularUsuario(user4);
    peli1->comentarComentario("texto de comentario 50", 6)->vincularUsuario(user5);
    peli1->comentarComentario("texto de comentario 51", 11)->vincularUsuario(user6);
    peli1->comentarComentario("texto de comentario 52", 11)->vincularUsuario(user7);
    peli1->comentarComentario("texto de comentario 53", 11)->vincularUsuario(user6);
    peli1->comentarComentario("texto de comentario 54", 16)->vincularUsuario(user5);
    peli1->comentarComentario("texto de comentario 55", 16)->vincularUsuario(user4);
    peli1->comentarComentario("texto de comentario 56", 47)->vincularUsuario(user3);
    peli1->comentarComentario("texto de comentario 57", 47)->vincularUsuario(user2);
    peli1->comentarComentario("texto de comentario 58", 47)->vincularUsuario(user3);
    peli1->comentarComentario("texto de comentario 59", 57)->vincularUsuario(user4);
    peli1->comentarComentario("texto de comentario 60", 56)->vincularUsuario(user5);
    peli1->comentarComentario("texto de comentario 61", 56)->vincularUsuario(user2);
    peli1->comentarComentario("texto de comentario 62", 61)->vincularUsuario(user9);

    // creando funciones
    peli1->crearFuncion(new DateTime(1,3,2019,10,30), 110, c1)->asignarSala(c1->obtenerSala(1));
    peli1->crearFuncion(new DateTime(2,4,2019,12,00), 120, c1)->asignarSala(c1->obtenerSala(2));
    peli1->crearFuncion(new DateTime(3,7,2019,14,30), 132, c1)->asignarSala(c1->obtenerSala(1));
    peli1->crearFuncion(new DateTime(4,8,2019,16,00), 143, c1)->asignarSala(c1->obtenerSala(2));
    peli1->crearFuncion(new DateTime(5,2,2019,18,30), 150, c2)->asignarSala(c2->obtenerSala(4));
    peli1->crearFuncion(new DateTime(6,8,2019,12,00), 160, c2)->asignarSala(c2->obtenerSala(4));
    peli1->crearFuncion(new DateTime(7,5,2019,15,30), 170, c2)->asignarSala(c2->obtenerSala(6));
    peli1->crearFuncion(new DateTime(8,7,2019,17,00), 180, c3)->asignarSala(c3->obtenerSala(8));

}
