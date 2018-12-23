#include <iostream>
#include "GestionTiquetes.h"
#include "Tiquete.h"

GestionTiquetes::GestionTiquetes() {}
void GestionTiquetes::cargarMenu() {
	char selectedOption = '0';
	char *selectedOptionPointer = &selectedOption;
	loop(selectedOptionPointer);
}
// valida si el asiento deseado, existe en el gimnasio en el que 
// se desea realizar el concierto
bool GestionTiquetes::validacionFilasYColumnas(int filaIngresada, int columnaIngresada, int filasMatriz, int columnasMatriz) {
	return ((filaIngresada <= filasMatriz) && (columnaIngresada <= columnasMatriz));
}
void GestionTiquetes::imprimirErrorDeCompra() {
	std::cout << "El asiento deseado, no se encuentra disponible, o no existe" << std::endl;
	std::cout << "Favora acceder a la opcion 2, del menu de compra, para ver asientos y filas disponibles" << std::endl;
}
void GestionTiquetes::imprimirCompraCompletada(bool isCompleted) {
	if (isCompleted) {
		std::cout << "Gracias por la compra, el campo ha sido asignado" << std::endl;
	}
}