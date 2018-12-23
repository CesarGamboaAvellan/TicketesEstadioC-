#include "Administracion.h"
#include "Tiquete.h";
#include <iostream>

void Administracion::cambiarPrecioTiquetes(Tiquete* tiquete, double precio) {
	tiquete->setPrecio(precio);
}
void Administracion::cambiarFechadeLaFuncion(Tiquete* tiquete, std::string fechaDeLosConciertos) {
	tiquete->setFecha(fechaDeLosConciertos);
}
void Administracion::cambiarLugar(Tiquete* tiquete, std::string lugarConcierto) {
	tiquete->setLugar(lugarConcierto);
}
void Administracion::adminMenu() {
	std::cout << "Bienvenido a la zona de administracion de tiquetes" << std::endl;
	std::cout << "Que desea hacer?" << std::endl;
	std::cout << "1. Cambiar precio de los tiquetes" << std::endl;
	std::cout << "2. Cambiar hora de la funcion" << std::endl;
	std::cout << "3. Cambiar lugar de la funcion" << std::endl;
	std::cout << "4. Salir" << std::endl;
}
