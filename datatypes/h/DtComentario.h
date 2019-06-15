#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
#include "../../colecciones/interfaces/ICollectible.h"
using namespace std;

class DtComentario : public ICollectible{
    private:
        int ID;
        string texto;
        int nivelSubComentario;
        string nickNameUsuario;
    public:
        DtComentario();
        DtComentario(int,string,int,string);
        ~DtComentario();

        int getID();
        string getTexto();
        int getNivelSubComentario();
        string getNickNameUsuario();

        friend std::ostream& operator <<(std::ostream &salida, const DtComentario &c);
};

#endif // DTCOMENTARIO_H
