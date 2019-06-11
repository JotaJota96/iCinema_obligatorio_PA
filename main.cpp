#include <iostream>
using namespace std;

#include "colecciones/collections/OrderedDictionary.h"
#include "colecciones/String.h"
#include "clases/h/Usuario.h"
#include "colecciones/collections/List.h"

IDictionary *users;

void cargarDatosDePrueba();


int main(){
    cargarDatosDePrueba();



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



