#ifndef FUNCION_H
#define FUNCION_H
#include "../../colecciones/interfaces/IDictionary.h"
#include "../../colecciones/collections/OrderedDictionary.h"
#include "../../datatypes/h/DtFuncion.h"
#include "../../datatypes/h/DtReserva.h"
#include "../../clases/h/ReservaCredito.h"
#include "../../clases/h/ReservaDebito.h"
#include "../../clases/h/Reserva.h"
#include "Sala.h"



class Funcion : public ICollectible{
    private:
        int id;
        DateTime *fechaYHora;
        float costoEntrada;
        Sala *s;
        IDictionary *misReservas;
        static int contadorFunciones;
    public:

        //gets y sets
        int getId();
        DateTime *getFechaYHora();
        float getCostoEntrada();

        void setId(int);
        void setFechaYHora(DateTime *);
        void setCostoEntrada(float);



        static int getNuevoID();
        Funcion();
        Funcion(int, DateTime *, float);
        ~Funcion();
        void asignarSala(Sala *s);
        bool esPosterior(DateTime *fechaActual);
        bool esEnCine(int idCineActual);
        DtFuncion * getDataType();
        void eliminarReservas();
        void agregarReserva(DtReserva *dtNuevaReserva);
};

#endif // FUNCION_H
