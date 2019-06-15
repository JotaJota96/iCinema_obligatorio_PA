#ifndef DTFUNCION_H
#define DTFUNCION_H
#include "DateTime.h"
#include <iostream>
#include "../../colecciones/interfaces/ICollectible.h"
using namespace std;

class DtFuncion : public ICollectible{
    private:
        int ID;
        DateTime* FechaYHora;
        int idSala;
    public:
        DtFuncion();
        DtFuncion(int,DateTime*,int);
        ~DtFuncion();

        int getID();
        DateTime* getFechaYHora();
        int dtIDSala();

        friend std::ostream& operator <<(std::ostream &salida, const DtFuncion &f);
};

#endif // DTFUNCION_H
