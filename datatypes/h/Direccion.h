#ifndef DIRECCION_H
#define DIRECCION_H
#include <iostream>
using namespace std;

class Direccion{
private:
    string departamento;
    string ciudad;
    string calle;
    string numero;
public:
    Direccion();
    Direccion(string, string, string, string);
    string getDepartamento();
    string getCiudad();
    string getCalle();
    string getNumero();

    friend std::ostream& operator <<(std::ostream &, const Direccion &);
};

#endif // DIRECCION_H
