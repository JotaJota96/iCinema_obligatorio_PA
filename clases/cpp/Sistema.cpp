#include "clases/h/Sistema.h"
#include "clases/h/ISistema.h"


Sistema::Sistema(){} //Constructor por defecto

Sistema::Sistema(Usuario * _usuarioActual){  //Constructor con sobrecargado
    this->usuarioActual = _usuarioActual;
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

void Sistema::cancelarEliminarPelicula(){

}

void Sistema::cancelarNuevaReserva(){

}
void Sistema::cancelarNuevoCine(){

}
void Sistema::cancelarVerComentariosYPuntajes(){

}
void Sistema::cancelarVerInformacionDePelicula(){

}
void Sistema::comentarComentario(string){

}
void Sistema::comentarPelicula(string){

}
void Sistema::confirmarEliminarPelicula(){

}
void Sistema::confirmarNuevaReserva(){

}
void Sistema::confirmarNuevoCine(){

}
bool Sistema::iniciarSesion(string nickname, string password){
    //Falta el Codigo
    bool valor = true;
    return valor;
}

List * Sistema::listarCines(){ //Retorna una lista con DtCines
    List * cines = new List();
    //Falta el codigo
    return cines;
}

List * Sistema::listarComentarios(){ //Retorna una lista con DtComentario
    List * comentarios = new List();
    //Falta el codigo
    return comentarios;
}

List * Sistema::listarFunciones(DateTime* fechaActual){ //Retorna una lista con DTFuncion
    List * funciones = new List();
    //Falta el codigo
    return funciones;
}

List * Sistema::listarPeliculas(){ //Retorna una lista con DtPelicula
    List * peliculas = new List();
    //Falta el codigo
    return peliculas;
}
List * Sistema::listarSalas(){ //Retorna un lista con DtSala
    List * salas = new List();
    //Falta el codigo
    return salas;
}

List * Sistema::listarSalasOcupadas(DateTime * fechaActual){ //Retrona una lista con DtFuncion
    List * funciones = new List();
    //Falta el codigo
    return funciones;
}

List * Sistema::listarTodosLosCines(){ //Retrona una lista con DtCine
    List * cines = new List();
    //Falta el codigo
    return cines;
}
void Sistema::nuevaFuncion(DateTime* fechaYHora, float costoEntrada){

}
void Sistema::nuevaReserva(int cantAsientos){

}
void Sistema::nuevaSala(int capacidad){

}
void Sistema::nuevoCine(Direccion* direccion){

}

int Sistema::obtenerPuntajeDadoPorUsuario(){
    //Falta el codigo
    return 0;
}

float Sistema::pagoCredito(string nombreFinanciera){
    float costo = 1.0;
    //Falta el codigo
    return costo;
}
void Sistema::pagoDebito(string nombreBanco){

}

void Sistema::puntuarPelicula(int puntaje){

}
DtCine * Sistema::seleccionarCine(int idCine){
    DtCine * cine = new DtCine();
    //Falta el codigo
    return  cine;
}

void Sistema::seleccionarComentario(int id){

}

DtFuncion * Sistema::seleccionarFuncion(int id){
    DtFuncion * funcion = new DtFuncion();
    //Falta el codigo
    return funcion;
}
DtPelicula * Sistema::seleccionarPelicula(string titulo){
    DtPelicula * pelicula = new DtPelicula();
    //Falta el codigo
    return pelicula;
}
void Sistema::seleccionarSala(int idSala){

}

DtReserva * Sistema::vistaPreviaDeReserva(){
    DtReserva * reserva = new DtReservaCredito();
    return reserva;
}

Sistema::~Sistema(){ //Destructor

}
