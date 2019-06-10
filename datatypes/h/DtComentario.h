#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
using namespace std;

class DtComentario{
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
};

#endif // DTCOMENTARIO_H
