#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include "Cine.h"
#include "Usuario.h"
#include "Pelicula.h"

//Controlador Sistema (Singleton)

class Sistema:public ISistema{
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
    void cancelarEliminarPelicula();
    void cancelarNuevaReserva() ;
    void cancelarNuevoCine() ;
    void cancelarVerComentariosYPuntajes() ;
    void cancelarVerInformacionDePelicula() ;
    void comentarComentario(string) ;
    void comentarPelicula(string) ;
    void confirmarEliminarPelicula() ;
    void confirmarNuevaReserva() ;
    void confirmarNuevoCine() ;
    bool iniciarSesion(string nickname, string password);
    List* listarCines() ;                            //Retorna una lista con DtCines
    List* listarComentarios() ;                      //Retorna una lista con DtComentario
    List* listarFunciones(DateTime* fechaActual) ;    //Retorna una lista con DTFuncion
    List* listarPeliculas() ;                        //Retorna una lista con DtPelicula
    List* listarSalas() ;                            //Retorna un lista con DtSala
    List* listarSalasOcupadas(DateTime* fechaActual) ;//Retrona una lista con DtFuncion
    List* listarTodosLosCines() ;                    //Retrona una lista con DtCine
    void nuevaFuncion(DateTime* fechaYHora, float costoEntrada) ;
    void nuevaReserva(int cantAsientos) ;
    void nuevaSala(int capacidad) ;
    void nuevoCine(Direccion* direccion) ;
    int obtenerPuntajeDadoPorUsuario()  ;
    float pagoCredito(string nombreFinanciera)  ;
    void pagoDebito(string nombreBanco)  ;
    void puntuarPelicula(int puntaje)  ;
    DtCine* seleccionarCine(int idCine) ;
    void seleccionarComentario(int id) ;
    DtFuncion* seleccionarFuncion(int id) ;
    DtPelicula* seleccionarPelicula(string titulo) ;
    void seleccionarSala(int idSala) ;
    DtReserva* vistaPreviaDeReserva() ;

private:
    Sistema();
    Sistema(Usuario * _usuarioActual);
    static Sistema * instancia;

    Cine * cineActual;
    Pelicula * peliculaActual;
    Usuario * usuarioActual;
    int idComentarioActual;
    int idFuncionActual;
    int idSalaActual;
};

#endif // SISTEMA_H
