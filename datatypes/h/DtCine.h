#ifndef DTCINE_H
#define DTCINE_H
#include "Direccion.h"
#include <iostream>
#include "../../colecciones/interfaces/ICollectible.h"
using namespace std;

class DtCine : public ICollectible{
    private:
        int ID;
        Direccion* direccion;
    public:
        DtCine();
        DtCine(int, Direccion*);
        ~DtCine();

        int getID();
        Direccion* getDireccion();

        friend std::ostream& operator <<(std::ostream &, const DtCine &);
};

#endif // DTCINE_H
