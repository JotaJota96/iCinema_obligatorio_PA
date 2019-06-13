#ifndef SALA_H
#define SALA_H
#include <iostream>
class Cine;
#include "../../colecciones/interfaces/ICollectible.h"
#include "../../datatypes/h/DtSala.h"
#include "Cine.h"


class Sala: public ICollectible{
    private:
        int numero;
        int capacidad;
        Cine* miCine;
    public:
        // constructor y destructor
        static int contadorDeSalas;
        Sala();
        Sala(int,int, Cine *);
        ~Sala();
        // gets y sets
        int getNumero();
        int getCapacidad();
        DtSala* getDataType();
        void setNumero(int);
        void setCapacidad(int);
        // operaciones
        bool perteneceACine(int idCineActual);
};
#endif // SALA_H
