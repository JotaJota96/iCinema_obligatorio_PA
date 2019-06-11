#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <iostream>
using namespace std;

#include "../../colecciones/interfaces/ICollectible.h"

class Puntuacion : public ICollectible{
    private:
        string titulo;
        int puntaje;
    public:
      // constructor y destructor
      Puntuacion();
      Puntuacion(string,int);
      ~Puntuacion();

      // gets y sets
      string getTitulo();
      int getPuntaje();
      void setTitulo(string);
      void setPuntaje(int);

      // operaciones
      int obtenerPuntuacion(string);
};

#endif // PUNTUACION_H
