#ifndef CINE_H
#define CINE_H
#include <iostream>
class Sala;
#include "../../colecciones/collections/List.h"
#include "../../datatypes/h/Direccion.h"
#include "../../datatypes/h/DtCine.h"
#include "../../colecciones/interfaces/ICollectible.h"
#include "../../colecciones/collections/OrderedDictionary.h"
#include "../../colecciones/Integer.h"
#include "../h/Sala.h"



class Cine: public ICollectible {
    private:
        int id;
        Direccion *Dir;
        IDictionary *misSalas;
        static int contadorDeCines;
    public:
        static int getNuevoID();
        // constructor y destructor
        Cine();
        Cine(int,Direccion *);
        ~Cine();

         // gets y sets
        DtCine getDataType();
        int getID();
        Direccion* getDireccion();
        void setID(int);
        void setDireccion(Direccion *);

        // operaciones
        Sala* obtenerSala(int);
        void agregarSala(int);
        bool esCine(int);
        ICollection* listarSalas();
        void eliminarSalas();
};

#endif // CINE_H
