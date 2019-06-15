#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <iostream>
#include "../../colecciones/interfaces/ICollectible.h"
using namespace std;

class DtPelicula : public ICollectible{
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

        friend std::ostream& operator <<(std::ostream &salida, const DtPelicula &p);
};

#endif // DTPELICULA_H
