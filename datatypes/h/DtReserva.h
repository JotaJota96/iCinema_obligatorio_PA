#ifndef DtReserva_h
#define DtReserva_h
#include <iostream>
using namespace std;

enum tipoReserva {reservaCredito, reservaDebito};

class DtReserva{
	private:
		int id;
		int asientos;
		float costo;
		tipoReserva tipo;
	public:
		DtReserva();
        DtReserva(int id, int asientos, float costo, tipoReserva tipo);
        virtual ~DtReserva() = 0;
        //---Getters ------------
		int getId();
		int getAsientos();
		float getCosto();
		tipoReserva getTipo();

        //Sobrecarga-------------
        friend std::ostream& operator <<(std::ostream &salida, const DtReserva &r);
};
#endif
