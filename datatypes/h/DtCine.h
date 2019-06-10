#ifndef DTCINE_H
#define DTCINE_H
#include "Direccion.h"
#include <iostream>
using namespace std;

class DtCine{
    private:
        int ID;
        Direccion direccion;
    public:
        DtCine();
        DtCine(int, Direccion);
        ~DtCine();

        int getID();
        Direccion getDireccion();
};

#endif // DTCINE_H
