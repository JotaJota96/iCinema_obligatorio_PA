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
        float costoEntrada;
        int idSala;
    public:
        DtFuncion();
        DtFuncion(int,DateTime*,float,int);
        ~DtFuncion();

        int getID();
        DateTime* getFechaYHora();
        int dtIDSala();
        float getCosto();

        friend std::ostream& operator <<(std::ostream &salida, const DtFuncion &f);
};

#endif // DTFUNCION_H
