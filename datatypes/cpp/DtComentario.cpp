#include "../h/DtComentario.h"

DtComentario::DtComentario(){
    this->ID= 0;
    this->texto = "";
    this->nivelSubComentario = 0;
    this->nickNameUsuario = "";
}

DtComentario::DtComentario(int ID, string Texto, int NivelSubComentario, string NickNameUsuario){
    this->ID=ID;
    this->texto=Texto;
    this->nivelSubComentario= NivelSubComentario;
    this->nickNameUsuario=NickNameUsuario;
}

DtComentario::~DtComentario(){
}

int DtComentario::getID(){
    return  this->ID;
}
string DtComentario::getTexto(){
    return this->texto;
}
int DtComentario::getNivelSubComentario(){
    return this->nivelSubComentario;
}
string DtComentario::getNickNameUsuario(){
    return this->nickNameUsuario;
}
