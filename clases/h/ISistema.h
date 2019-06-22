#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <iostream>
#include "../../datatypes/h/DtCine.h"
#include "../../datatypes/h/DtReserva.h"
#include "../../datatypes/h/DtFuncion.h"
#include "../../datatypes/h/DtReservaCredito.h"
#include "../../datatypes/h/DtReservaDebito.h"
#include "../../datatypes/h/DtPelicula.h"
#include "../../datatypes/h/DateTime.h"
#include "../../datatypes/h/Direccion.h"
#include "../../colecciones/interfaces/ICollection.h"
#include "../../colecciones/interfaces/IDictionary.h"

using namespace std;

enum RolDeUsuario {INVITADO, USUARIO, ADMINISTRADOR};

class ISistema{
public:
    virtual ~ISistema(); //Destructor

    //=============== Operaciones =====================
    virtual void cerrarSesion() = 0;
    virtual void cancelarEliminarPelicula() = 0 ;
    virtual void cancelarNuevaReserva() = 0;
    virtual void cancelarNuevoCine() = 0;
    virtual void cancelarVerComentariosYPuntajes() = 0;
    virtual void cancelarVerInformacionDePelicula() = 0;
    virtual void comentarComentario(string) = 0;
    virtual void comentarPelicula(string) = 0;
    virtual void confirmarEliminarPelicula() = 0;
    virtual void confirmarNuevaReserva() = 0;
    virtual void confirmarNuevoCine() = 0;
    virtual bool iniciarSesion(string nickname, string password) = 0;
    virtual ICollection * listarCines() = 0;                        //Retorna una lista con DtCines
    virtual ICollection * listarComentarios() = 0;                  //Retorna una lista con DtComentario
    virtual ICollection * listarFunciones(DateTime* fechaActual) = 0; //Retorna una lista con DTFuncion
    virtual ICollection * listarPeliculas() = 0;                        //Retorna una lista con DtPelicula
    virtual ICollection * listarSalas() = 0;                            //Retorna un lista con DtSala
    virtual ICollection * listarSalasOcupadas(DateTime* fechaActual) = 0; //Retrona una lista con DtFuncion
    virtual ICollection * listarTodosLosCines() = 0;                    //Retrona una lista con DtCine
    virtual void nuevaFuncion(DateTime* fechaYHora, float costoEntrada) = 0;
    virtual void nuevaReserva(int cantAsientos) = 0;
    virtual void nuevaSala(int capacidad) = 0;
    virtual void nuevoCine(Direccion* direccion) = 0;
    virtual int obtenerPuntajeDadoPorUsuario() = 0 ;
    virtual RolDeUsuario obtenerRolDeUsuarioActual() = 0;
    virtual float pagoCredito(string nombreFinanciera) = 0 ;
    virtual void pagoDebito(string nombreBanco) = 0 ;
    virtual void puntuarPelicula(int puntaje) = 0 ;
    virtual DtCine * seleccionarCine(int idCine) = 0;
    virtual void seleccionarComentario(int id) = 0;
    virtual DtFuncion * seleccionarFuncion(int id) = 0;
    virtual DtPelicula * seleccionarPelicula(string titulo) = 0;
    virtual void seleccionarSala(int idSala) = 0;
    virtual DtReserva * vistaPreviaDeReserva() = 0;

};

#endif // ISISTEMA_H
