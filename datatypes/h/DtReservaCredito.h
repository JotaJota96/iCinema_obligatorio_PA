#ifndef DtReservaCredito_h
#define DtReservaCredito_h
#include "DtReserva.h"

class DtReservaCredito: public DtReserva{
    private:
        std::string financiera;
        int descuento;
    public:
        DtReservaCredito();
        DtReservaCredito(int id, int asientos, float costo, tipoReserva tipo, std::string financiera, int descuento);
        ~DtReservaCredito();
        //---Getters ---------------
        std::string getFinanciera();
        int getDescuento();
};
#endif
