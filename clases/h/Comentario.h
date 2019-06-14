#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
using namespace std;

#include "../../colecciones/interfaces/ICollectible.h"
#include "../../colecciones/collections/OrderedDictionary.h"
#include "../../colecciones/collections/List.h"
#include "../../colecciones/Integer.h"
#include "../../datatypes/h/DtComentario.h"
#include "Usuario.h"


class Comentario : public ICollectible{
private:
    int id;
    string texto;
    int nivelSubComentario;
    Usuario* miUsuario;
    IDictionary* misSubComentarios;
    static int contadorDeComentarios;
public:
    static int getNuevoID();
    // constructor y destructor
    Comentario();
    Comentario(int id, string texto, int nivelSubComentario, Usuario* usuario);
    ~Comentario();

    // gets y sets
    int getID();
    string getTexto();
    int getNivelSubComentario();
    void setID(int id);
    void setTexto(string texto);
    void setNivelSubComentario(int nivelSubComentario);

    // operaciones
    Comentario* comentar(string texto, int id);
    bool esComentario(int id);
    void vincularUsuario(Usuario* usario);
    DtComentario* getDataType();
    ICollection* obtenerSubComentarios(); //set(DtComentario)
    void eliminarComentarios();
};

#endif // COMENTARIO_H
