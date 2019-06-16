#include <stdlib.h>
#include <iostream>
using namespace std;

#include "clases/h/ISistema.h"
#include "clases/h/Fabrica.h"
#include "datatypes/h/DtComentario.h"
//#include "datatypes/h/Direccion.h"
//#include "datatypes/h/DateTime.h"

enum tipoUsuario {INVITADO, USUARIO, ADMINISTRADOR};
tipoUsuario tipoUsuarioActual = INVITADO;
ISistema* sis;

// entrada de datos con validacion
float ingresarFloat(string msj);
int ingresarInt(string msj);
string ingresarString(string msj);
bool ingresarBool(string msj);
void pausa();
void limpiarPantalla();
void mostrarTitulo(string titulo);
void mostrarError(string err);


// menus segun rol
bool cargarMenuInvitado();
bool cargarMenuUsuario();
bool cargarMenuAdministrador();

// operaciones casos de uso
void iniciarSesion();
void altaCine();
void altaFuncion();
void crearReserva();
void puntuarPelicula();
void comentarPelicula();
void eliminarPelicula();
void verInfoDePelicula();
void verComentariosYPuntajeDePelicula();

void interfazGrafica(){
    bool salir = false;
    sis = Fabrica::crearSistema();

    while (!salir){
        switch (tipoUsuarioActual) {
        case INVITADO:
            salir = cargarMenuInvitado();
            break;
        case USUARIO:
            salir = cargarMenuUsuario();
            break;
        case ADMINISTRADOR:
            salir = cargarMenuAdministrador();
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
bool cargarMenuInvitado(){
    int opcion = -1;
    while (opcion != 0){
        limpiarPantalla();
        mostrarTitulo("Bienvenido a iCinema");
        cout << "1- Iniciar sesion" << endl;
        cout << "2- Ver Info de Pelicula" << endl;
        cout << "3- Ver comentarios y puntaje de pelicula" << endl;
        cout << "0- Salir..." << endl;
        opcion = ingresarInt("Ingrese una opcion: ");

        switch (opcion) {
        case 1: // Iniciar sesion
            iniciarSesion();
            return false;
        case 2: // Ver Info de Pelicula
            verInfoDePelicula();
            break;
        case 3: // Ver comentarios y puntaje de pelicula
            verComentariosYPuntajeDePelicula();
            break;
        }
    }
    return true;
}
bool cargarMenuUsuario(){
    int opcion = -1;
    while (opcion != 0){
        limpiarPantalla();
        mostrarTitulo("Bienvenido a iCinema");
        cout << "1- Crear reserva" << endl;
        cout << "2- Puntuar pelicula" << endl;
        cout << "3- Comentar pelicula" << endl;
        cout << "4- Ver Info de Pelicula" << endl;
        cout << "5- Ver comentarios y puntaje de pelicula" << endl;
        cout << "0- Salir..." << endl;
        opcion = ingresarInt("Ingrese una opcion: ");

        switch (opcion) {
        case 1: // Crear reserva
            crearReserva();
            break;
        case 2: // Puntuar pelicula
            puntuarPelicula();
            break;
        case 3: // Comentar pelicula
            comentarPelicula();
            break;
        case 4: // Ver Info de Pelicula
            verInfoDePelicula();
            break;
        case 5: // Ver comentarios y puntaje de pelicula
            verComentariosYPuntajeDePelicula();
            break;
        }
    }
    return true;
}
bool cargarMenuAdministrador(){
    int opcion = -1;
    while (opcion != 0){
        limpiarPantalla();
        mostrarTitulo("Bienvenido a iCinema");
        cout << "1- Alta cine" << endl;
        cout << "2- Alta funcion" << endl;
        cout << "3- Eliminar pelicula" << endl;
        cout << "0- Salir..." << endl;
        opcion = ingresarInt("Ingrese una opcion: ");

        switch (opcion) {
        case 1: // Alta cine
            altaCine();
            break;
        case 2: // Alta funcion
            altaFuncion();
            break;
        case 3: // Eliminar pelicula
            eliminarPelicula();
            break;
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////
void iniciarSesion(){
    try {
        bool cancelar = false;
        while (!cancelar){
            limpiarPantalla();
            mostrarTitulo("Iniciar sesion");
            string usu = ingresarString("Ingrese su nickname: ");
            string pass = ingresarString("Ingrese su contrasenia: ");

            bool ok = sis->iniciarSesion(usu, pass);
            cout << ok << endl;
            if (ok){
                // consultar al sistema que tipo de usuario acaba de iniciar sesion
                // por ahora pongo esto...
                cout << "Esto esta provisorio..." << endl;
                cout << "Como que rol queres ingresar?..." << endl;
                switch (ingresarInt("0- invitado\n1-usuario\n2-admin: ")) {
                case 1:
                    tipoUsuarioActual = USUARIO;
                    break;
                case 2:
                    tipoUsuarioActual = ADMINISTRADOR;
                    break;
                default:
                    tipoUsuarioActual = INVITADO;
                }
                return;
            }else{
                cout << "El nickname o la contrasenia son incorrectos" << endl;
                cancelar = ! ingresarBool("Desea reintentar? ");
            }
        }
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void altaCine(){
    try {
        /*
        bool seguirAgregando = true;
        bool agregarsala = true;
        bool confirmar = false;

        while (seguirAgregando) {
        limpiarPantalla();
       mostrarTitulo("Alta de cine");

        string departamento = ingresarString("Ingrese departamento: ");
        string ciudad = ingresarString("Ingrese ciudad: ");
        string calle = ingresarString("Ingrese calle: ");
        string numero = ingresarString("Ingrese numero: ");

        Direccion *dir = new Direccion(departamento, ciudad, calle, numero);
        sis->nuevoCine(dir);

        do {
            int capacidad = ingresarInt("Ingrese la capacidad de la sala: ");
            sis->nuevaSala(capacidad);
            agregarsala = ingresarBool("Desea agregar mas salas? ");
        } while (agregarsala);

        confirmar = ingresarBool("Confirmar el nuevo cine? ");
        if (confirmar){
            sis->confirmarNuevoCine();
        }else{
            sis->cancelarNuevoCine();

        }

        seguirAgregando = ingresarBool("Desea agregar mas cines? ");
    }
    */
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void altaFuncion(){
    try {

    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void crearReserva(){
    try {

    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void puntuarPelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Puntuar pelicula");
        /*
        DtPelicula* dtP;
        ICollection* colP = sis->listarPeliculas();
        IIterator* it = colP->getIterator();
        while(it->hasCurrent()){
            dtP = static_cast<DtPelicula*>(it->getCurrent());
            cout << *dtP << endl << endl;
            it->next();
        }
        delete colP;

        string titulo = ingresarString("Ingrese el titulo de la pelicula: ");

        sis->seleccionarPelicula(titulo);
        int puntajeDado = sis->obtenerPuntajeDadoPorUsuario();
        if (puntajeDado != -1){
            cout << "El puntaje que le has dado a esta pelicula es: " << puntajeDado << endl;
            bool modificar = ingresarBool("Deseas modificarlo? ");
            if (modificar){
                puntajeDado = ingresarInt("Ingrese el nuevo puntaje: ");
                sis->puntuarPelicula(puntajeDado);
            }
        }else{
            puntajeDado = ingresarInt("Ingrese el puntaje: ");
            sis->puntuarPelicula(puntajeDado);
        }
        */
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void comentarPelicula(){
    try {

    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void eliminarPelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Eliminar pelicula");
        /*
        DtPelicula* dtP;
        ICollection* colP = sis->listarPeliculas();
        IIterator* it = colP->getIterator();
        while(it->hasCurrent()){
            dtP = static_cast<DtPelicula*>(it->getCurrent());
            cout << dtP->getTitulo() << endl;
            it->next();
        }
        delete colP;

        string titulo = ingresarString("Ingrese el titulo de la pelicula: ");
        sis->seleccionarPelicula(titulo);

        bool confirmar = ingresarBool("Confirmar eliminar pelicula? ");
        if (confirmar){
            sis->confirmarEliminarPelicula();
        }else{
            sis->cancelarEliminarPelicula();
        }
        */
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void verInfoDePelicula(){
    try {
        // esta conviene hacerla despues de crerReserva() asi es solo copiar y pegar una parte
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }

}
void verComentariosYPuntajeDePelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Ver comentarios y puntaje");
        /*
        DtPelicula* dtP;
        ICollection* colP = sis->listarPeliculas();
        IIterator* it = colP->getIterator();
        while(it->hasCurrent()){
            dtP = static_cast<DtPelicula*>(it->getCurrent());
            cout << "Titulo: " << dtP->getTitulo() << endl;
            cout << "Poster: " << dtP->getPoster() << endl;
            cout << endl;
            it->next();
        }
        delete colP;

        string titulo = ingresarString("Ingrese el titulo de la pelicula: ");

        dtP = sis->seleccionarPelicula(titulo);
        cout << "----- Pelicula ------ "<< endl;
        cout << *dtP << endl;
        cout << "---- Comentarios ---- "<< endl;

        ICollection* colC = sis->listarComentarios();
        it = colC->getIterator();
        while(it->hasCurrent()){
            DtComentario* dtC = static_cast<DtComentario*>(it->getCurrent());
            cout << *dtC << endl;
            it->next();
        }
        delete colC;
        cout << "--------------------- "<< endl;
        pausa();
        */
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}

///////////////////////////////////////////////////////////////////////////////////
float ingresarFloat(string msj){
    string entrada = "";
    while (true){
        cout << msj;
        getline(cin, entrada);

        if (entrada.length() == 0){
            continue;
        }
        bool ingresoCorrecto = true;
        bool tieneComa = false;
        for (unsigned int i = 0; i < entrada.length(); i++){
            if ((entrada[i] < '0') || (entrada[i] > '9')){
                if (entrada[i] == ',' || entrada[i] == '.'){
                    if(tieneComa){
                        ingresoCorrecto = false;
                        break;
                    }else{
                        entrada[i] = '.';
                        tieneComa = true;
                    }
                }else{
                    ingresoCorrecto = false;
                    break;
                }
            }
        }
        if (ingresoCorrecto){
            break;
        }
    }
    return static_cast<float>(atof(entrada.c_str()));
}
int ingresarInt(string msj){
    string entrada = "";
    while (true){
        cout << msj;
        getline(cin, entrada);

        if (entrada.length() == 0){
            continue;
        }
        bool ingresoCorrecto = true;
        for (unsigned int i = 0; i < entrada.length(); i++){
            if ((entrada[i] < '0') || (entrada[i] > '9')){
                ingresoCorrecto = false;
                break;
            }
        }
        if (ingresoCorrecto){
            break;
        }
    }
    return static_cast<int>(atoi(entrada.c_str()));
}
string ingresarString(string msj){
    string entrada = "";
    cout << msj;
    getline(cin, entrada);

    int inicio = 0;
    int fin = entrada.length()-1;
    for (; inicio < fin+1 && entrada[inicio] == ' '; inicio++);
    for (; fin >= 0 && entrada[fin] == ' '; fin--);

    return entrada.substr(inicio, fin-inicio+1);
}
bool ingresarBool(string msj){
    string afirmaciones[4] = {"s", "S", "si", "SI"};
    string negaciones[4] = {"n", "N", "no", "NO"};
    string entrada = "";

    while (true) {
        cout << msj << "[s/n]: ";
        getline(cin, entrada);
        for (int i=0; i < 4; i++){
            if (afirmaciones[i] == entrada) return true;
        }
        for (int i=0; i < 4; i++){
            if (negaciones[i] == entrada) return false;
        }
    }
}
void pausa(){
    system("PAUSE");
}
void limpiarPantalla(){
    system("CLS");
}
void mostrarTitulo(string titulo){
    int ancho = 50;
    ancho -= titulo.length();
    for (int i = 1; i < ancho/2; i++) printf("-");
    printf(" %s ", titulo.c_str());
    for (int i = 1; i < ancho/2; i++) printf("-");
    printf("\n");
}
void mostrarError(string err){
    cout << "ERROR: " << err << endl;
    pausa();
}

///////////////////////////////////////////////////////////////////////////////////


