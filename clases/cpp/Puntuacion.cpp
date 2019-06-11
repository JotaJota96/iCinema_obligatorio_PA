#include "../h/Puntuacion.h"

Puntuacion::Puntuacion(){
    this->titulo = "";
    this->puntaje = 0;
}

Puntuacion::Puntuacion(string titulo,int puntaje){
    this->titulo = titulo;
    this->puntaje = puntaje;
}

Puntuacion::~Puntuacion(){
}

string Puntuacion::getTitulo(){
    return this->titulo;
}

int Puntuacion::getPuntaje(){
    return this->puntaje;
}

void Puntuacion::setTitulo(string titulo){
    this->titulo=titulo;
}

void Puntuacion::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}

int Puntuacion::obtenerPuntuacion(string titulo){
    if (this->titulo == titulo){
        return this->puntaje;
    }
    else {
        return -1;
    }
}
