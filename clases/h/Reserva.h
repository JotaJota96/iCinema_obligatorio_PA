#ifndef CLASESHESERVA_H
#define CLASESHESERVA_H
#include "../../colecciones/interfaces/ICollectible.h"
#include "../../datatypes/h/DtReserva.h"

class Reserva:public ICollectible{
public:
    Reserva(); // constructor
    Reserva(int, int, float, tipoReserva);
    virtual ~Reserva() = 0; // destructor

    // Geters y Seters
    int getID();
    int getAsientos();
    float getCosto();
    tipoReserva getTipo();
    void setID(int);
    void setAsientos(int);
    void setCosto(float);
    void setTipo(tipoReserva);

private:
    int id;
    int asientos;
    float costo;
    tipoReserva tipo;
};

#endif // CLASESHESERVA_H
