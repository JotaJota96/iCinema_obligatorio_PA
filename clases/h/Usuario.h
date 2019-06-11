#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;

#include "../../colecciones/interfaces/ICollectible.h"
#include "../../colecciones/collections/OrderedDictionary.h"
#include "../../colecciones/String.h"
#include "Puntuacion.h"

class Usuario : public ICollectible{
private:
    string nickname;
    string contrasenia;
    string imagen;
    bool admin;
    IDictionary *puntuaciones;
public:
    // constructor y destructor
    Usuario();
    Usuario(string nickname, string contrasenia, string imagen, bool admin);
    ~Usuario();

    // gets y sets
    string getNickname();
    string getContrasenia();
    string getImagen();
    bool getAdmin();
    void setNickname(string nickname);
    void setContrasenia(string contrasenia);
    void setImagen(string imagen);
    void setAdmin(bool admin);

    // operaciones
    int obtenerPuntajeDado(string titulo);
    bool yaPuntuoPelicula(string titulo);
    void actualizarPuntuacion(string titulo, int puntaje);
    void vincularNuevaPuntuacion(Puntuacion *p);
    void eliminarLinkAPuntuacion(string titulo);
};

#endif // USUARIO_H
