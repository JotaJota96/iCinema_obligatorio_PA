#include <iostream>
using namespace std;

#include "colecciones/collections/OrderedDictionary.h"
#include "colecciones/collections/List.h"
#include "colecciones/String.h"

#include "clases/h/Cine.h"
#include "clases/h/Comentario.h"
#include "clases/h/Pelicula.h"
#include "clases/h/ReservaCredito.h"
#include "clases/h/ReservaDebito.h"
#include "clases/h/Usuario.h"

IDictionary *users;

void cargarDatosDePrueba();
void pruebaDeCinesYSalas();
void pruebaDeComentarios();
void pruebaDePelicula();

#include "interfazGrafica.h"


int main(){
    try {
        interfazGrafica();
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }

    // Haga aqui los testeamientos necesarios

    return 0;
}

void cargarDatosDePrueba(){
    // crea el diccionario de usuarios
    users = new OrderedDictionary();
    // crea tres usuarios
    Usuario *u1 = new Usuario("usuario_1","", "", false);
    Usuario *u2 = new Usuario("usuario_2","", "", false);
    Usuario *u3 = new Usuario("usuario_3","", "", false);
    // agrega los usuarios al diccionario
    users->add(new String((u1->getNickname()).c_str()), u1);
    users->add(new String((u2->getNickname()).c_str()), u2);
    users->add(new String((u3->getNickname()).c_str()), u3);

    // crea puntuaciones
    Puntuacion *p1 = new Puntuacion("pelicula_1", 1);
    Puntuacion *p2 = new Puntuacion("pelicula_2", 2);
    Puntuacion *p3 = new Puntuacion("pelicula_3", 3);
    Puntuacion *p4 = new Puntuacion("pelicula_4", 4);
    Puntuacion *p5 = new Puntuacion("pelicula_5", 5);

    // asigno algunas puntuaciones a algunos usuarios
    u2->vincularNuevaPuntuacion(p1);
    u2->vincularNuevaPuntuacion(p2);
    u3->vincularNuevaPuntuacion(p3);
    u3->vincularNuevaPuntuacion(p4);
    u3->vincularNuevaPuntuacion(p5);
}
void pruebaDeCinesYSalas(){

    IDictionary *colCines = new OrderedDictionary;

    Cine *c1 = new Cine(Cine::getNuevoID(), new Direccion("dep1", "ciu1", "cal1", "num1"));
    Cine *c2 = new Cine(Cine::getNuevoID(), new Direccion("dep2", "ciu2", "cal2", "num2"));
    Cine *c3 = new Cine(Cine::getNuevoID(), new Direccion("dep3", "ciu3", "cal3", "num3"));
    c1->agregarSala(10);
    c1->agregarSala(20);
    c1->agregarSala(30);
    c2->agregarSala(40);
    c2->agregarSala(50);
    c2->agregarSala(60);
    c3->agregarSala(70);
    c3->agregarSala(80);
    c3->agregarSala(90);

    colCines->add(new Integer(c1->getID()), c1);
    colCines->add(new Integer(c2->getID()), c2);
    colCines->add(new Integer(c3->getID()), c3);

    IIterator *it = colCines->getIterator();
    while (it->hasCurrent()){
        Cine* cineIT = (Cine*) it->getCurrent();
        DtCine* dtC = cineIT->getDataType();

        cout << "+++++++++++++++" << endl;
        cout << *dtC << endl;

        ICollection *colSalas = cineIT->listarSalas();
        IIterator *salasIT = colSalas->getIterator();
        while (salasIT->hasCurrent()) {
            DtSala* s = (DtSala*) salasIT->getCurrent();
            cout << "------" << endl;
            cout << *s << endl;
            salasIT->next();
        }
        it->next();
    }
}
void pruebaDeComentarios(){
    Usuario *u = new Usuario("usuario-1","", "", false);
    Comentario* c1 = new Comentario(Comentario::getNuevoID(), "hola 1", 0, u);

    (c1->comentar("comentario 2", 1))->vincularUsuario(u);
    (c1->comentar("comentario 3", 1))->vincularUsuario(u);
    (c1->comentar("comentario 4", 1))->vincularUsuario(u);
    (c1->comentar("comentario 5", 1))->vincularUsuario(u);
    (c1->comentar("respuesta 1 al comentario 2", 2))->vincularUsuario(u);
    (c1->comentar("respuesta 2 al comentario 2", 2))->vincularUsuario(u);
    (c1->comentar("respuesta 1 al comentario 3", 3))->vincularUsuario(u);
    (c1->comentar("respuesta 2 al comentario 3", 3))->vincularUsuario(u);
    (c1->comentar("respuesta 3 al comentario 3", 3))->vincularUsuario(u);
    (c1->comentar("respuesta 1 al comentario 8", 8))->vincularUsuario(u);
    (c1->comentar("respuesta 2 al comentario 8", 8))->vincularUsuario(u);


    ICollection* colCom = c1->obtenerSubComentarios();
    IIterator* it = colCom->getIterator();
    while (it->hasCurrent()) {
        DtComentario *dtc = (DtComentario*) it->getCurrent();
        cout << *dtc << endl;
        /*
        for (int i = 0; i < dtc->getNivelSubComentario(); i++){
            printf("\t");
        }
        cout << "id: " << dtc->getID() << ", texto: " << dtc->getTexto() << endl;
        */
        it->next();
    }

    // Haga aqui los testeamientos necesarios

    c1->eliminarComentarios();
    delete  c1;

}
void pruebaDePelicula(){
    cout << "#### creando peliculas y agregando a diccionario" << endl;
    IDictionary *colP = new OrderedDictionary();
    Pelicula* p1 = new Pelicula("peli_1", "poster_1", "sinopsis_1");
    Pelicula* p2 = new Pelicula("peli_2", "poster_2", "sinopsis_2");
    Pelicula* p3 = new Pelicula("peli_3", "poster_3", "sinopsis_3");
    colP->add(new String(p1->getTitulo().c_str()), p1);
    colP->add(new String(p2->getTitulo().c_str()), p2);
    colP->add(new String(p3->getTitulo().c_str()), p3);


    cout << "#### creando usuarios" << endl;
    Usuario *u1 = new Usuario("usuario_1","", "", false);
    Usuario *u2 = new Usuario("usuario_2","", "", false);
    Usuario *u3 = new Usuario("usuario_3","", "", false);

    cout << "#### Comentando pelicula y comentarios" << endl;
    (p1->comentar("comentario 1"))->vincularUsuario(u1);
    (p1->comentar("comentario 2"))->vincularUsuario(u1);
    (p1->comentar("comentario 3"))->vincularUsuario(u1);
    (p1->comentarComentario("respuesta 1 al comentario 1", 1))->vincularUsuario(u1);
    (p1->comentarComentario("respuesta 2 al comentario 1", 1))->vincularUsuario(u2);
    (p1->comentarComentario("respuesta 1 al comentario 3", 3))->vincularUsuario(u3);
    (p1->comentarComentario("respuesta 2 al comentario 3", 3))->vincularUsuario(u3);
    (p1->comentarComentario("respuesta 3 al comentario 3", 3))->vincularUsuario(u2);
    (p1->comentarComentario("respuesta 1 al comentario 8", 8))->vincularUsuario(u1);
    (p1->comentarComentario("respuesta 2 al comentario 8", 8))->vincularUsuario(u2);

    cout << "#### Listando comentarios" << endl;
    ICollection *IC = p1->obtenerComentarios();
    IIterator *it = IC->getIterator();
    while(it->hasCurrent()){
        DtComentario *dtCom = static_cast<DtComentario *>(it->getCurrent());
        cout << *dtCom <<endl;
        it->next();
    }
    cout <<"-+++++++++++++++++++"<< endl;

    cout << "#### Listando peliculas" << endl;
    delete it;
    it = colP->getIterator();
    while(it->hasCurrent()){
        cout << *(static_cast<Pelicula*>(it->getCurrent())->getDataType())<<endl<<endl;
        it->next();
    }
    delete it;

    cout << "#### Puntuando peliculas y vinculando a usuarios" << endl;
    u1->vincularNuevaPuntuacion(p1->nuevaPuntuacion(1));
    u2->vincularNuevaPuntuacion(p2->nuevaPuntuacion(2));
    u3->vincularNuevaPuntuacion(p3->nuevaPuntuacion(3));
    u2->vincularNuevaPuntuacion(p2->nuevaPuntuacion(2));
    u3->vincularNuevaPuntuacion(p3->nuevaPuntuacion(5));
    u1->vincularNuevaPuntuacion(p2->nuevaPuntuacion(4));
    u2->vincularNuevaPuntuacion(p1->nuevaPuntuacion(2));
    u1->vincularNuevaPuntuacion(p1->nuevaPuntuacion(4));

    cout << "#### Listando peliculas otra vez" << endl;
    it = colP->getIterator();
    while(it->hasCurrent()){
        cout << *(static_cast<Pelicula*>(it->getCurrent())->getDataType())<<endl<<endl;
        it->next();
    }
    delete it;
    cout << "################################" << endl;

    cout << "#### Creando cines y salas" << endl;
    Cine *c1 = new Cine(Cine::getNuevoID(), new Direccion("dep1", "ciu1", "cal1", "num1"));
    Cine *c2 = new Cine(Cine::getNuevoID(), new Direccion("dep2", "ciu2", "cal2", "num2"));
    Cine *c3 = new Cine(Cine::getNuevoID(), new Direccion("dep3", "ciu3", "cal3", "num3"));
    c1->agregarSala(10);
    c1->agregarSala(20);
    c1->agregarSala(30);
    c2->agregarSala(40);
    c2->agregarSala(50);
    c2->agregarSala(60);
    c3->agregarSala(70);
    c3->agregarSala(80);
    c3->agregarSala(90);


    cout << "#### Creando funciones" << endl;
    Funcion *f1 = p1->crearFuncion(new DateTime(1,2,2003,4,5),100,c1);
    Funcion *f2 = p1->crearFuncion(new DateTime(2,2,2003,4,5),100,c2);
    Funcion *f3 = p1->crearFuncion(new DateTime(3,2,2003,4,5),100,c1);
    Funcion *f4 = p2->crearFuncion(new DateTime(4,2,2003,4,5),100,c1);
    Funcion *f5 = p2->crearFuncion(new DateTime(5,2,2003,4,5),100,c2);
    Funcion *f6 = p3->crearFuncion(new DateTime(6,2,2003,4,5),100,c3);

    /*
    ICollection *colSalas = c3->listarSalas();
    IIterator *salasIT = colSalas->getIterator();
    while (salasIT->hasCurrent()) {
        DtSala* s = (DtSala*) salasIT->getCurrent();
        cout << "------" << endl;
        cout << *s << endl;
        salasIT->next();
    }
    */




    cout << endl << endl;
    cout << *c1->obtenerSala(1)->getDataType() << endl;
    cout << *c1->obtenerSala(2)->getDataType() << endl;
    cout << *c1->obtenerSala(3)->getDataType() << endl;
    cout << endl << endl;

    cout << "#### Asignando funciones a salas" << endl;
    f1->asignarSala(c1->obtenerSala(1));
    f2->asignarSala(c2->obtenerSala(4));
    f3->asignarSala(c1->obtenerSala(2));
    f4->asignarSala(c1->obtenerSala(2));
    f5->asignarSala(c2->obtenerSala(5));
    f6->asignarSala(c3->obtenerSala(7));

    cout << "#### Obteniendo cines de la pelicula p1" << endl;
    ICollection* ObtenerCines = p1->obtenerCines();
    it = ObtenerCines->getIterator();
    while(it->hasCurrent()){
        cout << *(dynamic_cast<DtCine *>(it->getCurrent()))<< endl<<endl;
        it->next();
    }
    delete it;
    cout << "#### Obteniendo cines de la pelicula p2" << endl;
    ObtenerCines = p2->obtenerCines();
    it = ObtenerCines->getIterator();
    while(it->hasCurrent()){
        cout << *(dynamic_cast<DtCine *>(it->getCurrent()))<< endl<<endl;
        it->next();
    }
    delete it;
    cout << "#### Obteniendo cines de la pelicula p3" << endl;
    ObtenerCines = p3->obtenerCines();
    it = ObtenerCines->getIterator();
    while(it->hasCurrent()){
        cout << *(dynamic_cast<DtCine *>(it->getCurrent()))<< endl<<endl;
        it->next();
    }
    delete it;

    cout << "#### Obteniendo Funcion" << endl;
    cout << *(p1->obtenerDtFuncion(1))<< endl;

    cout << "#### Agregando reservas a Funcion" << endl;
    p1->agregarReservaAFuncion(new DtReservaDebito(1,1,1,reservaDebito,"b"),f1->getId());
    p1->agregarReservaAFuncion(new DtReservaCredito(2,1,1,reservaCredito,"f",1),f2->getId());
    p1->agregarReservaAFuncion(new DtReservaDebito(3,1,1,reservaDebito,"b"),f2->getId());
    p1->agregarReservaAFuncion(new DtReservaCredito(4,1,1,reservaCredito,"f",1),f3->getId());
    p1->agregarReservaAFuncion(new DtReservaCredito(5,1,1,reservaCredito,"f",1),f3->getId());
    p1->agregarReservaAFuncion(new DtReservaCredito(6,1,1,reservaCredito,"f",1),f3->getId());
    p1->agregarReservaAFuncion(new DtReservaDebito(7,1,1,reservaDebito,"b"),f1->getId());
    p1->agregarReservaAFuncion(new DtReservaDebito(8,1,1,reservaDebito,"b"),f1->getId());


    cout << "#### obteniendo Funciones despues de fecha 1,1,1,1,1" << endl;
    ICollection *icFun = p1->obtenerFunciones(new DateTime(1,1,1,1,1),c1->getID());
    it = icFun->getIterator();
    while(it->hasCurrent()){
        cout << *(dynamic_cast<DtFuncion *>(it->getCurrent()))<< endl;
        it->next();
    }
    delete it;
    p1->eiminarLinks();

}

