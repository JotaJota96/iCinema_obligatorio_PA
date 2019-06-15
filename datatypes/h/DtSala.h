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

        friend std::ostream& operator <<(std::ostream &salida, const DtSala &s);
};

#endif // DTSALA_H
