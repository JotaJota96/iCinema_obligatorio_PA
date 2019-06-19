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

            if (ok){
                // consultar al sistema que tipo de usuario acaba de iniciar sesion
                // por ahora pongo esto...
                cout << ">>> Esto esta provisorio... <<<" << endl;
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
        bool seguirAgregando = true;
        bool agregarsala = true;
        bool confirmar = false;

        while (seguirAgregando) {
            limpiarPantalla();
            mostrarTitulo("Alta de cine");

            // pide los datos de la direccion del nuevo cine
            cout << "Direccion del cine: " << endl;
            string departamento = ingresarString("Ingrese departamento: ");
            string ciudad = ingresarString("Ingrese ciudad: ");
            string calle = ingresarString("Ingrese calle: ");
            string numero = ingresarString("Ingrese numero: ");

            Direccion *dir = new Direccion(departamento, ciudad, calle, numero);
            sis->nuevoCine(dir);

            // agrega las salas
            do {
                int capacidad = ingresarInt("Ingrese la capacidad de la sala: ");
                sis->nuevaSala(capacidad);
                agregarsala = ingresarBool("Desea agregar mas salas? ");
            } while (agregarsala);

            // confirmar o cancelar
            confirmar = ingresarBool("Confirmar el nuevo cine? ");
            if (confirmar){
                sis->confirmarNuevoCine();
            }else{
                sis->cancelarNuevoCine();

            }

            // seguir agregando
            seguirAgregando = ingresarBool("Desea agregar mas cines? ");
        }

    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void altaFuncion(){
    try {
        limpiarPantalla();
        mostrarTitulo("Alta Funcion");
        mostrarTitulo("Lista de peliculas");

        // lista peliculas
        ICollection *colPeliculas = sis->listarPeliculas();
        IIterator *it = colPeliculas->getIterator();
        while(it->hasCurrent()){
            cout << dynamic_cast<DtPelicula *>(it->getCurrent()) -> getTitulo() << endl;
        }
        delete it;
        delete colPeliculas;

        string tituloPelicula = ingresarString("Seleccione una pelicula: ");
        sis->seleccionarPelicula(tituloPelicula);

        bool cancelar = false;
        while (!cancelar){
            limpiarPantalla();
            mostrarTitulo("Alta Funcion");
            mostrarTitulo("Lista de cines");

            //listar cines
            ICollection *colCines = sis->listarCines();
            it = colCines->getIterator();
            while(it->hasCurrent()){
                cout << *(dynamic_cast<DtCine*>(it->getCurrent())) << endl << endl;
            }
            delete it;
            delete colCines;

            //seleccionar cine
            int idCine = ingresarInt("Seleccione un cine: ");
            sis->seleccionarCine(idCine);

            limpiarPantalla();
            mostrarTitulo("Alta Funcion");
            mostrarTitulo("Lista de salas ocupadas");

            //listar salas
            ICollection *colSalas = sis->listarSalas();
            it = colSalas->getIterator();
            while(it->hasCurrent()){
                cout << *(dynamic_cast<DtSala*>(it->getCurrent())) << endl << endl;
            }
            delete it;
            delete colSalas;

            //listar salas ocupadas
            ICollection *colSalasOcupadas = sis->listarSalasOcupadas(new DateTime());
            it = colSalasOcupadas->getIterator();
            while(it->hasCurrent()){
                cout << *(dynamic_cast<DtFuncion*>(it->getCurrent())) << endl << endl;
            }
            delete it;
            delete colSalasOcupadas;

            //seleccionar sala
            int idSala = ingresarInt("Seleccione una sala: ");
            sis->seleccionarSala(idSala);

            limpiarPantalla();
            mostrarTitulo("Alta Funcion");

            float costo = ingresarFloat("Ingrese el costo: ");
            DateTime *fechaYHoraFuncion = new DateTime(ingresarInt("Dia: "),
                                                       ingresarInt("Mes: "),
                                                       ingresarInt("Anioo: "),
                                                       ingresarInt("Hora: "),
                                                       ingresarInt("Minuto: "));
            sis->nuevaFuncion(fechaYHoraFuncion, costo);

            cancelar = ! ingresarBool("Desea agregar otra funcion para la pelicula? ");
        }
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void crearReserva(){
    try {
        bool cancelar = false;
        bool seleccionoPelicula = false;
        bool seleccionoVerInfo= false;
        bool seleccionoCine= false;
        bool seleccionoFuncion = false;
        ICollection* col;
        IIterator* it;

        do {
            cancelar = seleccionoPelicula = seleccionoVerInfo= seleccionoCine= seleccionoFuncion = false;

            limpiarPantalla();
            mostrarTitulo("Crear reserva");
            mostrarTitulo("Lista de peliculas");

            // listado de peliculas
            DtPelicula* dtP;
            col = sis->listarPeliculas();
            it = col->getIterator();
            while(it->hasCurrent()){
                dtP = static_cast<DtPelicula*>(it->getCurrent());
                cout << dtP->getTitulo() << endl;
                it->next();
            }
            delete col;
            delete it;

            seleccionoPelicula = ingresarBool("Desea seleccionar una pelicula? ");
            if ( seleccionoPelicula){
                string titulo = ingresarString("Ingrese el titulo de la pelicula: ");
                dtP = sis->seleccionarPelicula(titulo);
                limpiarPantalla();
                mostrarTitulo("Crear reserva");
                cout << *dtP << endl;

                seleccionoVerInfo = ingresarBool("Desea ver informacion adicional? ");
                if (seleccionoVerInfo){
                    limpiarPantalla();
                    mostrarTitulo("Crear reserva");
                    mostrarTitulo("Lista de cines");

                    // Listado de cines
                    DtCine* dtC;
                    col = sis->listarCines();
                    it = col->getIterator();
                    while(it->hasCurrent()){
                        dtC = static_cast<DtCine*>(it->getCurrent());
                        cout << *dtC << endl << endl;
                        it->next();
                    }
                    delete col;
                    delete it;

                    seleccionoCine = ingresarBool("Desea seleccionar un cine?");
                    if (seleccionoCine){
                        int idCine = ingresarInt("Ingrese el ID del cine para seleccionarlo: ");
                        sis->seleccionarCine(idCine);
                        limpiarPantalla();
                        mostrarTitulo("Crear reserva");
                        mostrarTitulo("Lista de funciones");

                        // listado de funciones
                        DtFuncion* dtF;
                        col = sis->listarFunciones(new DateTime()); // por defecto tiene la fecha y hora actual
                        it = col->getIterator();
                        while(it->hasCurrent()){
                            dtF = static_cast<DtFuncion*>(it->getCurrent());
                            cout << *dtF << endl << endl;
                            it->next();
                        }
                        delete col;
                        delete it;

                        seleccionoFuncion = ingresarBool("Desea seleccionar una funcion? ");
                        if(seleccionoFuncion){
                            int idFuncion =ingresarInt("Ingrese el ID de la funcion para seleccionarla: ");
                            sis->seleccionarFuncion(idFuncion);
                        }else{
                            sis->cancelarNuevaReserva();
                        }
                    }else{
                        sis->cancelarNuevaReserva();
                    }
                }else{
                    sis->cancelarNuevaReserva();
                }
            }else{
                sis->cancelarNuevaReserva();
                return;
            }

            if (! seleccionoFuncion){
                cancelar = ! ingresarBool("Desea seleccionar otra pelicula? ");
            }
        }while (!cancelar && !seleccionoFuncion);
        if (cancelar) return;
        limpiarPantalla();
        mostrarTitulo("Crear reserva");

        int cantidadAsientos = ingresarInt("Ingrese la cantidad de asientos: ");
        sis->nuevaReserva(cantidadAsientos);

        // la reserva puede ser de Credito o Debito
        while (true){
            string opcion = ingresarString("Ingrese el medio de pago [credito/debito]: ");
            if (opcion == "debito"){
                string nombreBanco = ingresarString("Ingrese el nombre del banco: ");
                sis->pagoDebito(nombreBanco);
                break;
            }else if (opcion == "credito") {
                string nombreFinanciera = ingresarString("Ingrese el nombre de la financiera: ");
                float descuento = sis->pagoCredito(nombreFinanciera);
                if (descuento == 0) cout << "No tenemos descuentos para esa financiera" << endl;
                else cout << "Su reserva tendra un " << descuento << "% de descuento" << endl;
                break;
            }
        }

        // muestra los datos de la reserva
        DtReserva *dtR = sis->vistaPreviaDeReserva();
        if (dynamic_cast<DtReservaDebito*>(dtR)){
            cout << *(dynamic_cast<DtReservaDebito*>(dtR)) << endl;
        }else{
            cout << *(dynamic_cast<DtReservaCredito*>(dtR)) << endl;
        }

        // solicita confirmar la operacion
        bool confirmar =ingresarBool("Desea confirmar la reserva? ");
        if (confirmar){
            sis->confirmarNuevoCine();
        }else {
            sis->cancelarNuevaReserva();
        }
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void puntuarPelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Puntuar pelicula");
        mostrarTitulo("Lista de peliculas");

        // listado de peliculas
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

        limpiarPantalla();
        mostrarTitulo("Puntuar pelicula");

        // si el puntaje dado es -1, signiica que el usuario no ha puntuado la pelicula
        // si es diferente a -1, ya ha puntuado y el valor es el puntaje dado
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
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void comentarPelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Comentar pelicula");
        mostrarTitulo("Lista de peliculas");

        // listado de peliculas
        ICollection *colPeliculas = sis->listarPeliculas();
        IIterator *it = colPeliculas->getIterator();
        while(it->hasCurrent()){
            cout << dynamic_cast<DtPelicula *>(it->getCurrent()) -> getTitulo() << endl;
        }
        delete it;
        delete colPeliculas;

        //seleccionar
        string tituloPelicula = ingresarString("Seleccione una pelicula: ");
        sis->seleccionarPelicula(tituloPelicula);

        limpiarPantalla();
        mostrarTitulo("Puntuar pelicula");
        mostrarTitulo("Lista de comentarios");

        //listar comentarios
        ICollection *colComentarios = sis->listarComentarios();
        it = colComentarios ->getIterator();
        while(it->hasCurrent()){
            cout << *(dynamic_cast<DtComentario*>(it->getCurrent())) << endl;
        }
        delete it;
        delete colComentarios;

        // el usuario debe elegir si quiere comentar la pelicula o comentar un comentario
        while (true){
            string opcion = ingresarString("Que desea comentar? [pelicula/comentario]: ");
            if (opcion == "pelicula"){
                string comentario = ingresarString("Ingrese su comentario: ");
                sis->comentarPelicula(comentario);
                break;
            }else if (opcion == "comentario") {
                int idComentario = ingresarInt("Ingrese el ID del comentario a comentar: ");
                sis->seleccionarComentario(idComentario);
                string comentario = ingresarString("Ingrese su comentario: ");
                sis->comentarComentario(comentario);
                break;
            }
        }
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void eliminarPelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Eliminar pelicula");
        mostrarTitulo("Lista de peliculas");

        // listado de peliculas
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
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void verInfoDePelicula(){
    try {
        bool cancelar = false;
        bool seleccionoPelicula = false;
        bool seleccionoVerInfo= false;
        bool seleccionoCine= false;
        bool seleccionoFuncion = false;
        ICollection* col;
        IIterator* it;

        do {
            cancelar = seleccionoPelicula = seleccionoVerInfo= seleccionoCine= seleccionoFuncion = false;

            limpiarPantalla();
            mostrarTitulo("Ver informacion de pelicula");
            mostrarTitulo("Lista de peliculas");

            // listado de peliculas
            DtPelicula* dtP;
            col = sis->listarPeliculas();
            it = col->getIterator();
            while(it->hasCurrent()){
                dtP = static_cast<DtPelicula*>(it->getCurrent());
                cout << dtP->getTitulo() << endl;
                it->next();
            }
            delete col;
            delete it;

            seleccionoPelicula = ingresarBool("Desea seleccionar una pelicula? ");
            if ( seleccionoPelicula){
                string titulo = ingresarString("Ingrese el titulo de la pelicula: ");
                dtP = sis->seleccionarPelicula(titulo);

                limpiarPantalla();
                mostrarTitulo("Ver informacion de pelicula");
                cout << *dtP << endl;

                seleccionoVerInfo = ingresarBool("Desea ver informacion adicional? ");
                if (seleccionoVerInfo){
                    limpiarPantalla();
                    mostrarTitulo("Ver informacion de pelicula");
                    mostrarTitulo("Lista de cines");

                    // listado de cines
                    DtCine* dtC;
                    col = sis->listarCines();
                    it = col->getIterator();
                    while(it->hasCurrent()){
                        dtC = static_cast<DtCine*>(it->getCurrent());
                        cout << *dtC << endl << endl;
                        it->next();
                    }
                    delete col;
                    delete it;

                    seleccionoCine = ingresarBool("Desea seleccionar un cine?");
                    if (seleccionoCine){
                        int idCine = ingresarInt("Ingrese el ID del cine para seleccionarlo: ");
                        sis->seleccionarCine(idCine);

                        limpiarPantalla();
                        mostrarTitulo("Ver informacion de pelicula");
                        mostrarTitulo("Lista de funciones");

                        DtFuncion* dtF;
                        col = sis->listarFunciones(new DateTime()); // por defecto tiene la fecha y hora actual
                        it = col->getIterator();
                        while(it->hasCurrent()){
                            dtF = static_cast<DtFuncion*>(it->getCurrent());
                            cout << *dtF << endl << endl;
                            it->next();
                        }
                        delete col;
                        delete it;

                        // aca no pongo pausa porque mas abajo hay un ingreso de datos
                        sis->cancelarVerInformacionDePelicula();
                    }else{
                        sis->cancelarVerInformacionDePelicula();
                    }
                }else{
                    sis->cancelarVerInformacionDePelicula();
                }
            }else{
                sis->cancelarVerInformacionDePelicula();
                return;
            }

            cancelar = ! ingresarBool("Desea seleccionar otra pelicula? ");
        }while (!cancelar && !seleccionoFuncion);
    } catch (invalid_argument &ia) {
        mostrarError(ia.what());
    }
}
void verComentariosYPuntajeDePelicula(){
    try {
        limpiarPantalla();
        mostrarTitulo("Ver comentarios y puntaje");
        mostrarTitulo("Lista de peliculas");

        // listado de peliculas
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
        delete it;

        string titulo = ingresarString("Ingrese el titulo de la pelicula: ");
        dtP = sis->seleccionarPelicula(titulo);


        limpiarPantalla();
        mostrarTitulo("Ver comentarios y puntaje");

        cout << *dtP << endl;

        ICollection* colC = sis->listarComentarios();
        it = colC->getIterator();
        while(it->hasCurrent()){
            DtComentario* dtC = static_cast<DtComentario*>(it->getCurrent());
            cout << *dtC << endl;
            it->next();
        }
        delete colC;
        pausa();

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
