#ifndef DTSALA_H
#define DTSALA_H
#include <iostream>
using namespace std;

class DtSala{
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