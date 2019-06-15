#include "../h/DtPelicula.h"

DtPelicula::DtPelicula(){
    this->titulo = "";
    this->poster = "";
    this->sinopsis = "";
    this->puntaje = 0;
}

DtPelicula::DtPelicula(string Titulo,string Poster,string Sinopsis,int Puntaje){
    this->titulo=Titulo;
    this->poster=Poster;
    this->sinopsis=Sinopsis;
    this->puntaje=Puntaje;

}

DtPelicula::~DtPelicula(){
}

string DtPelicula::getTitulo(){
    return this->titulo;
}
string DtPelicula::getPoster(){
    return this->poster;
}
string DtPelicula::getSinopsis(){
    return this->sinopsis;
}
int DtPelicula::getPuntaje(){
    return this->puntaje;
}


std::ostream& operator <<(std::ostream &salida, const DtPelicula &p){
    salida << "Titulo: " << p.titulo << endl;
    salida << "Poster: " << p.poster << endl;
    salida << "Sinopsis: " << p.sinopsis << endl;
    salida << "Punaje: " <<  p.puntaje;
    return salida;
}




