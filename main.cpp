#include <iostream>
using namespace std;

#include "colecciones/collections/OrderedDictionary.h"
#include "colecciones/collections/List.h"
#include "colecciones/String.h"

#include "clases/h/Usuario.h"
#include "clases/h/ReservaCredito.h"
#include "clases/h/ReservaDebito.h"
#include "clases/h/Cine.h"
#include "clases/h/Comentario.h"

IDictionary *users;

void cargarDatosDePrueba();
void pruebaDeCinesYSalas();
void pruebaDeComentarios();


int main(){

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

