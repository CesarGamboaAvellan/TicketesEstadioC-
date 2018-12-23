#include "Tiquete.h";
#include <iostream>

Tiquete::Tiquete(int ident): identificador(ident) {
	std::cout << "this is the ticket identifier" << identificador << std::endl;
}
Tiquete::Tiquete(){}
std::string Tiquete::getStatus() {
	return status;
}
void Tiquete::setStatus(bool isSold) {
	if (isSold) {
		status = "X";
	};
}
void Tiquete::setPrecio(double precio) {
	costoDelTiquete = precio;
}
bool Tiquete::verificarEstado() {
	return (status == "X");
}
// Asignar numero de asiento, para que el usuario
// pueda elegir cual comprar

void Tiquete::asignarNumeroAsiento(int numeroAsiento) {
	status = "["+std::to_string(numeroAsiento)+"]";
}
void Tiquete::mostrarInformacionDelTiquete() {
	std::cout << costoDelTiquete << std::endl;
	std::cout << costoDelTiquete<<std::endl;
	std::cout << tipoDeTiquete << std::endl;
	std::cout << status << std::endl;
}