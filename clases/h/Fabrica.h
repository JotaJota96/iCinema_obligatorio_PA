#ifndef CLASESHABRICA_H
#define CLASESHABRICA_H
#include "../h/Sistema.h"
#include "../h/ISistema.h"

//Clase Fabrica (Singleton)

class Fabrica{
public:
    static Fabrica * getInstancia(); //Devuelve la instancia de la fabrica(Singleton)
    static ISistema * crearSistema(); //Devuelve el controlador Sistema (Singleton)
    virtual ~Fabrica();
private:
    Fabrica();
    static Fabrica * instancia;
};

#endif // CLASESHABRICA_H

