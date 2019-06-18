#ifndef PELICULA_H
#define PELICULA_H
#include "../../clases/h/Cine.h"
#include "../../clases/h/Comentario.h"
//- #include "../../clases/h/Funcion.h"
#include "../../datatypes/h/DtPelicula.h"
#include "../../datatypes/h/DtFuncion.h"
#include "../../datatypes/h/DateTime.h"
#include "../../datatypes/h/DtReserva.h"
#include "../../colecciones/interfaces/ICollection.h"
#include "../../colecciones/interfaces/IDictionary.h"

class Pelicula : public ICollectible{
private:
    string titulo;
    string poster;
    string sinopsis;
    ICollection* puntuaciones;
    IDictionary* comentarios;
    IDictionary* funciones;
    IDictionary* cines;

public:
    // constructor y destructor
    Pelicula();
    Pelicula(string titulo, string poster, string sinopsis);
    ~Pelicula();

    // gets y sets
    string getTitulo();
    string getPoster();
    string getSinopsis();
    int getPuntuacion(); // calcula el promedio de las puntuaciones recibidas
    void setTitulo(string titulo);
    void setPoster(string poster);
    void setSinopsis(string sinopsis);

    // operaciones
    Comentario* comentarComentario(string texto, int idComentarioActual);
    Comentario* comentar(string texto);
//- Funcion* crearFuncion(DateTime fechaYHora, float costoEntrada, Cine *cineActual);
//- float getCostoDeFuncion(int idFuncionActual);
    Puntuacion* nuevaPuntuacion(int puntos);
    ICollection* obtenerCines(); // set(DtCine)
    ICollection* obtenerComentarios(); //set(DtComentario)
//- ICollection* obtenerFunciones(DateTime fechaActual, int idCineActual); //Set(DtFuncion)
    DtPelicula* getDataType();
//- DtFuncion* obtenerDtFuncion(int idFuncion);
//- void eiminarLinks();
//- void agregarReservaAFuncion(DtReserva* dtNuevaReserva, int idFuncionActual);
};

#endif // PELICULA_H
