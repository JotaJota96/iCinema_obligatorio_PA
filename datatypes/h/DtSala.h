#ifndef DTSALA_H
#define DTSALA_H
#include <iostream>
using namespace std;

#include "../../colecciones/interfaces/ICollectible.h"

class DtSala : public ICollectible{
    private:
        int numero;
        int capasidad;
        int idCine;
    public:
		DtSala();
		DtSala(int,int,int);
        ~DtSala();

        int getNumero();
        int getCapasidad();
        int getIDCine();
};

#endif // DTSALA_H
