#include "Tiquete.h";
#include <iostream>

Tiquete::Tiquete(){}
// retorna el estado de cada tiquete
std::string Tiquete::getStatus() {
	return status;
}
// cuando un tiquete esta vendido, le asigna un X
void Tiquete::setStatus(bool isSold) {
	if (isSold) {
		status = "X";
	};
}
// usando la opcion de administracion, se puede cambiar el precio base de los tiquetes
void Tiquete::setPrecio(double precio) {
	costoDelTiquete = precio;
}
bool Tiquete::verificarEstado() {
	return (status == "X");
}
// Asignar numero de asiento, para que el usuario
// pueda elegir cual comprar

// asigna el numero de asiento a cada fila
void Tiquete::asignarNumeroAsiento(int numeroAsiento) {
	status = "["+std::to_string(numeroAsiento)+"]";
}
// se puede cambiar la fecha del concierto con las opciones de administracion
void Tiquete::setFecha(std::string fecha) {
	time = fecha;
}
// opcion de administracion para cambiar el lugar del concierto
void Tiquete::setLugar(std::string lugarConcierto) {
	lugar = lugarConcierto;
}

// metodo para mostrar la informacion del tiquete
void Tiquete::mostrarInformacionDelTiquete() {
	std::cout << costoDelTiquete << std::endl;
	std::cout << costoDelTiquete<<std::endl;
	std::cout << tipoDeTiquete << std::endl;
	std::cout << status << std::endl;
}
double Tiquete::getPrecio() {
	return costoDelTiquete;
}