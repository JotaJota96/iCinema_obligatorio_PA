#ifndef RESERVACREDITO_H
#define RESERVACREDITO_H
#include <iostream>
#include "Reserva.h"
#include "../../datatypes/h/DtReservaCredito.h"
using namespace std;

class ReservaCredito:public Reserva{
public:
    ReservaCredito();   //Constructor
    ReservaCredito(int, int, float, string, int);
    ~ReservaCredito(); //Destructor

    // Geters y Seters
    void setFinanciera(string);
    void setDescuento(int);
    string getFinanciera();
    int getDescuento();

private:
    string financiera;
    int descuento;
};

#endif // RESERVACREDITO_H
