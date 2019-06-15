#include "..\h\DateTime.h"


// Constructores
DateTime::DateTime(){
	//Funcion que obtiene la fecha y hora actual del sistema
	// La funcion time_t time(time_t *time)
    time_t fechaHoraActual = time(0);
	
	//Convierte fecha y hora a estructura tipo UTC
	tm * strcFechaHora = gmtime(&fechaHoraActual);
	//	struct tm{
	//		int tm_sec; 	//Segundos 0-61
	//		int tm_min; 	//Minutos del 0-59
	//		int tm_hour; 	//Horas del 0-24
	//		int tm_mday; 	//Dias del 1-31
	//		int tm_mon; 	//Meses de 0-11
	//		int tm_year; 	//Anios desde 1900
	//		int tm_wday; 	//Dias desde el domingo
	//		int tm_yday; 	//Dias desde el primero de enero
	//		int tm_isdst; 	//Manejo del horario de verano
	//	};
	
	//Asigna los datos necesarios
	this->dia = strcFechaHora->tm_mday;
    this->mes = strcFechaHora->tm_mon + 1;
	this->anio = strcFechaHora->tm_year - 100 + 2000;
    this->hora = strcFechaHora->tm_hour -3;
    // la hora obtenida es la UTC, pero si se quiere la UTC -3 hay que hacer cuentas...
    if (this->hora < 0){
        this->hora += 24;
    }
    this->minuto = strcFechaHora->tm_min;
}


DateTime::DateTime(int dia, int mes, int anio, int hora, int minuto){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}


DateTime::DateTime(const DateTime &fecha){
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
    this->hora = fecha.hora;
    this->minuto = fecha.minuto;
}


DateTime::~DateTime(){
	
}

int DateTime::getDia(){
	return this->dia;
}
int DateTime::getMes(){
	return this->mes;
}
int DateTime::getAnio(){
	return this->anio;
}
int DateTime::getHora(){
    return this->hora;
}
int DateTime::getMinuto(){
    return this->minuto;
}

bool operator <(const DateTime &f1, const DateTime &f2){
	if (f1.anio < f2.anio)	return true;
	if (f1.anio > f2.anio)	return false;
	// si llega hasta aca, son el mismo anio y hay que verificar el mes
	if (f1.mes < f2.mes)	return true;
	if (f1.mes > f2.mes)	return false;
	// si llega hasta aca, son el mismo anio y el mismo mes, hay que verificar el dia
	if (f1.dia < f2.dia)	return true;
	if (f1.dia > f2.dia)	return false;

    if (f1.hora < f2.hora)	return true;
    if (f1.hora > f2.hora)	return false;

    if (f1.minuto < f2.minuto)	return true;
    if (f1.minuto > f2.minuto)	return false;

	// si llega hasta aca, es la misma fecha, y retorna false
	return false;
}


std::ostream& operator <<(std::ostream &salida, const DateTime &f){
    salida << f.dia << "/" << f.mes << "/" << f.anio << " ";
    salida << f.hora << ":";
    // pongo este if porque sino cuando son por ejemplo, las 15 y 5, muestra 15:5 y queda feo
    if (f.minuto < 10) salida << "0";
    salida << f.minuto;
	return salida;
}










