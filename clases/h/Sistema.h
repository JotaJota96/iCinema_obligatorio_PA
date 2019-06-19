#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include "Cine.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Sala.h"
#include "colecciones/collections/OrderedDictionary.h"
#include "colecciones/collections/List.h"

#include <map>
class Pelicula;
class Cine;
class Usuario;

//Controlador Sistema (Singleton)
class Sistema:public ISistema{
private:
    // constructor
    Sistema();
    static Sistema * instancia;

    //=============== Datos Actuales =======-=============
    RolDeUsuario rolActual;
    Cine * cineActual;
    Pelicula * peliculaActual;
    Usuario * usuarioActual;
    int idComentarioActual;
    int idFuncionActual;
    int idSalaActual;
    int cantAsientos;
    DtReserva * DtNuevaReserva;

    //================= Colecciones =======================
    IDictionary * DicUsuarios;
    IDictionary * DicPeliculas;
    IDictionary * DicCines;
    map<string,float> financieras;

    void cargarDatosDePrueba();
public:

    virtual ~Sistema();              //Destructor
    static Sistema * getInstancia(); //Devuelve el controlador Sistema (Singleton)

    //==================== Geter Y Seter =============================
    Cine * getCineActual();
    Usuario * getUsuarioActual();
    Pelicula * getPeliculaActual();
    int getIdComentarioActual();
    int getIdFuncionActual();
    int getIdSalaActual();
    void setCineActual(Cine* _cineActual);
    void setUsuarioActual(Usuario* _usuarioActual);
    void setPeliculaActual(Pelicula* _peliculaActual);
    void setIdComentarioActual(int _idComentarioActual);
    void setIdFuncionActual(int _idFuncionActual);
    void setIdSalaActual(int _idSalaActual);

    //==================== OPERACIONES ==========================
    void cerrarSesion();
    void cancelarEliminarPelicula();
    void cancelarNuevaReserva() ;
    void cancelarNuevoCine() ;
    void cancelarVerComentariosYPuntajes() ;
    void cancelarVerInformacionDePelicula() ;
    void comentarComentario(string _texto) ;
    void comentarPelicula(string _texto) ;
    void confirmarEliminarPelicula() ;
    void confirmarNuevaReserva() ;
    void confirmarNuevoCine() ;
    bool iniciarSesion(string nickname, string password);
    ICollection* listarCines() ;                            //Retorna una lista con DtCines
    ICollection* listarComentarios() ;                      //Retorna una lista con DtComentario
    ICollection* listarFunciones(DateTime* fechaActual) ;    //Retorna una lista con DTFuncion
    ICollection* listarPeliculas() ;                        //Retorna una lista con DtPelicula
    ICollection* listarSalas() ;                            //Retorna un lista con DtSala
    ICollection* listarSalasOcupadas(DateTime* fechaActual) ;//Retrona una lista con DtFuncion
    ICollection* listarTodosLosCines() ;                    //Retrona una lista con DtCine
    void nuevaFuncion(DateTime* fechaYHora, float costoEntrada) ;
    void nuevaReserva(int cantAsientos) ;
    void nuevaSala(int capacidad) ;
    void nuevoCine(Direccion* direccion) ;
    int obtenerPuntajeDadoPorUsuario()  ;
    RolDeUsuario obtenerRolDeUsuarioActual();
    float pagoCredito(string nombreFinanciera)  ;
    void pagoDebito(string nombreBanco)  ;
    void puntuarPelicula(int puntaje)  ;
    DtCine* seleccionarCine(int idCine) ;
    void seleccionarComentario(int id) ;
    DtFuncion* seleccionarFuncion(int id) ;
    DtPelicula* seleccionarPelicula(string titulo) ;
    void seleccionarSala(int idSala) ;
    DtReserva* vistaPreviaDeReserva() ;
};

#endif // SISTEMA_H
