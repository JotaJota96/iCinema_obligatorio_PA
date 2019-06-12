#ifndef RESERVADEBITO_H
#define RESERVADEBITO_H

#include "Reserva.h"
#include <iostream>
#include "../../datatypes/h/DtReservaDebito.h"

using namespace std;

class ReservaDebito:public Reserva{
public:
    ReservaDebito();    //Constructor
    ReservaDebito(int, int, float, string);
    ~ReservaDebito();   //Destructor

    //Geter Y Seter
    string getNombreBanco();
    void setNombreBanco(string);
private:
    string nombreBanco;
};

#endif // RESERVADEBITO_H
