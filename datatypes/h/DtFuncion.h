#ifndef DTFUNCION_H
#define DTFUNCION_H
#include "DateTime.h"
#include <iostream>
using namespace std;

class DtFuncion{
    private:
        int ID;
        DateTime FechaYHora;
        int idSala;
    public:
        DtFuncion();
        DtFuncion(int,DateTime,int);
        ~DtFuncion();

        int getID();
        DateTime getFechaYHora();
        int dtIDSala();
};

#endif // DTFUNCION_H
