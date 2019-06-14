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

    ICollection *colCines = new List;

    Cine *c1 = new Cine(Cine::getNuevoID(), NULL);
    Cine *c2 = new Cine(Cine::getNuevoID(), NULL);
    Cine *c3 = new Cine(Cine::getNuevoID(), NULL);
    c1->agregarSala(10);
    c1->agregarSala(20);
    c1->agregarSala(30);
    c2->agregarSala(40);
    c2->agregarSala(50);
    c2->agregarSala(60);
    c3->agregarSala(70);
    c3->agregarSala(80);
    c3->agregarSala(90);
    colCines->add(c1);
    colCines->add(c2);
    colCines->add(c3);

    IIterator *it = colCines->getIterator();
    while (it->hasCurrent()){
        Cine* cineIT = (Cine*) it->getCurrent();
        cout << "El cine con ID " << cineIT->getID() << " tiene las salas:" << endl;
        ICollection *colSalas = cineIT->listarSalas();
        IIterator *salasIT = colSalas->getIterator();
        while (salasIT->hasCurrent()) {
            Sala* s = (Sala*) salasIT->getCurrent();
            cout << s->getNumero()<< endl;
            salasIT->next();
        }
        it->next();
    }

}

void pruebaDeComentarios(){
    Usuario *u = new Usuario("usuario-1","", "", false);
    Comentario* c1 = new Comentario(Comentario::getNuevoID(), "hola 1", 0, u);

    (c1->comentar("hola 2", 1))->vincularUsuario(u);
    (c1->comentar("hola 3", 1))->vincularUsuario(u);
    (c1->comentar("hola 4", 1))->vincularUsuario(u);
    (c1->comentar("hola 5", 1))->vincularUsuario(u);
    (c1->comentar("hola 6", 2))->vincularUsuario(u);
    (c1->comentar("hola 7", 2))->vincularUsuario(u);
    (c1->comentar("hola 8", 3))->vincularUsuario(u);
    (c1->comentar("hola 9", 3))->vincularUsuario(u);
    (c1->comentar("hola 10", 3))->vincularUsuario(u);
    (c1->comentar("hola 11", 8))->vincularUsuario(u);
    (c1->comentar("hola 12", 8))->vincularUsuario(u);


    ICollection* colCom = c1->obtenerSubComentarios();
    IIterator* it = colCom->getIterator();
    while (it->hasCurrent()) {
        DtComentario *dtc = (DtComentario*) it->getCurrent();
        for (int i = 0; i < dtc->getNivelSubComentario(); i++){
            printf("\t");
        }
        cout << "id: " << dtc->getID() << ", texto: " << dtc->getTexto() << endl;
        it->next();
    }

    // Haga aqui los testeamientos necesarios

    c1->eliminarComentarios();
    delete  c1;

}

