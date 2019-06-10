#ifndef DtFecha_H
#define DtFecha_H
#include <iostream>
#include <ctime>

class DateTime{
	private:
		int dia;
		int mes;
		int anio;
        int hora;
        int minuto;
	public:
		//Constructores
        DateTime();	// fecha actual
        DateTime(int, int, int, int, int);
        DateTime(const DateTime &);
        ~DateTime();
		
		//gets
		int getDia();
		int getMes();
		int getAnio();
        int getHora();
        int getMinuto();
		
		// sobrecarga de operadores
        friend bool operator <(const DateTime &, const DateTime &);
        friend std::ostream& operator <<(std::ostream &, const DateTime &);
        //friend DtFecha operator =(const DtFecha &f1, const DtFecha &f2);
};




#endif
