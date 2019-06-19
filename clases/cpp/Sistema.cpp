#include "clases/h/Sistema.h"
#include "clases/h/ISistema.h"


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
}

Sistema::Sistema(Usuario * _usuarioActual){  //Constructor con sobrecargado
    this->usuarioActual = _usuarioActual;
    this->financieras["CREDITEL"] = 10.0;
    this->financieras["OCA"] = 15.0;
    this->financieras["FUCAC"] = 8.5;
    this->financieras["CREDITO DE LA CASA"] = 12.0;
    this->financieras["CASH"] = 12.0;
    this->financieras["PRONTO"] = 11.0;
    this->financieras["ANDA"] = 10.0;
    this->financieras["COPAC"] = 12.0;
    this->financieras["MARCRE"] = 5.0;
}

Sistema * Sistema::instancia = 0;

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
    this->cineActual = _cineActual;
}

void Sistema::setUsuarioActual(Usuario * _usuarioActual){
    this->usuarioActual = _usuarioActual;
}

void Sistema::setPeliculaActual(Pelicula * _peliculaActual){
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
void Sistema::comentarComentario(string){

}
void Sistema::comentarPelicula(string){

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
    delete peliculaActual;
    DicPeliculas->remove(k);
    delete k;
    peliculaActual = NULL;
}
void Sistema::confirmarNuevaReserva(){

}
void Sistema::confirmarNuevoCine(){

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
    ICollection * comentarios = new List();
    comentarios = this->peliculaActual->obtenerComentarios();
    return comentarios;
}

ICollection * Sistema::listarFunciones(DateTime* fechaActual){ // Terminada Verificar
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
    IIterator * it2;
    IIterator * it = DicPeliculas->getIterator();
    while (it->hasCurrent()) {
       Pelicula* p = dynamic_cast<Pelicula*>(it->getCurrent());
       it2 = p->obtenerFunciones(fechaActual,idCineActual)->getIterator();
       while (it2->hasCurrent()) {
           ret->add(it2->getCurrent());
           it2->next();
       }
       delete it2;
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
    Funcion * f = this->peliculaActual->crearFuncion(fechaYHora,costoEntrada,this->cineActual);
    Sala * s = this->cineActual->obtenerSala(this->idSalaActual);
    f->asignarSala(s);
}

void Sistema::nuevaReserva(int _cantAsientos){          //Terminada Verificar
    this->cantAsientos = _cantAsientos;
}

void Sistema::nuevaSala(int _capacidad){                //Terminada Verificar
    this->cineActual->agregarSala(_capacidad);
}

void Sistema::nuevoCine(Direccion* _direccion){         //Terminada Verificar
    int id = Cine::getNuevoID();
    Cine * nuevoCine = new Cine(id , _direccion);
    cineActual = nuevoCine;      //Crea el link a cineActual
    IKey * k = new Integer(id);
    DicCines->add(k,nuevoCine); //Agregar el nuevo cine al Diccionario
}

int Sistema::obtenerPuntajeDadoPorUsuario(){            //Termianda Verificar
    string titulo = this->peliculaActual->getTitulo();
    int puntaje = usuarioActual->obtenerPuntajeDado(titulo);
    return puntaje;
}

float Sistema::pagoCredito(string nombreFinanciera){   //Terminada Falta verificar el descuento
    float costoFuncion = this->peliculaActual->getCostoDeFuncion(this->idFuncionActual);
    float costo = float(cantAsientos * costoFuncion);
    this->DtNuevaReserva = new DtReservaCredito(this->idFuncionActual, cantAsientos , costo,reservaCredito, nombreFinanciera, 10 );
    return financieras[nombreFinanciera];
}
void Sistema::pagoDebito(string nombreBanco){
    float costoFuncion = this->peliculaActual->getCostoDeFuncion(this->idFuncionActual);
    float costo = float(cantAsientos * costoFuncion);
    this->DtNuevaReserva = new DtReservaDebito(this->idFuncionActual, cantAsientos, costo, reservaDebito, nombreBanco);   //Terminada verificar
}

void Sistema::puntuarPelicula(int puntaje){             //Terminada Verificar
    string titulo = this->peliculaActual->getTitulo();
    bool ok = this->usuarioActual->yaPuntuoPelicula(titulo);
    if(ok)
        this->usuarioActual->actualizarPuntuacion(titulo, puntaje);
    else {
        Puntuacion * nuevaPuntuacion = new Puntuacion(titulo,puntaje);
        this->usuarioActual->vincularNuevaPuntuacion(nuevaPuntuacion);
    }
}

DtCine * Sistema::seleccionarCine(int idCine){     //Terminada Verificar
    DtCine * cine = new DtCine();
    IKey * k = new Integer(idCine);
    Cine * c = dynamic_cast<Cine*>(DicCines->find(k));
    cine = c->getDataType();
    delete k;
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
    this->peliculaActual = p;
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

