#ifndef DtReservaDebito_h
#define DtReservaDebito_h
#include "DtReserva.h"

class DtReservaDebito: public DtReserva{
    private:
        std::string nombreBanco;
    public:
        DtReservaDebito();
        DtReservaDebito(int id, int asientos, float costo, tipoReserva tipo, std::string nombreBanco);
        ~DtReservaDebito();
        //---Getters ---------------
        std::string getNombreBanco();

        //Sobrecarga-------------
        friend std::ostream& operator <<(std::ostream &salida, const DtReservaDebito &r);
		
};
#endif
