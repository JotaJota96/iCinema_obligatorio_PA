#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <iostream>
using namespace std;

class DtPelicula{
    private:
        string titulo;
        string poster;
        string sinopsis;
        int puntaje;
    public:
        DtPelicula();
        DtPelicula(string,string,string,int);
        ~DtPelicula();

        string getTitulo();
        string getPoster();
        string getSinopsis();
        int getPuntaje();

};

#endif // DTPELICULA_H
