#include <iostream>
#include "GestionTiquetes.h"
#include "Tiquete.h"

GestionTiquetes::GestionTiquetes() {}
void GestionTiquetes::cargarMenu() {
	char selectedOption = '0';
	// se envia el puntero como parametro, asi, segun el valor ingresado por el usuario
	// detiene el ciclo
	char *selectedOptionPointer = &selectedOption;
	loop(selectedOptionPointer);
}
// valida si el asiento deseado, existe en el gimnasio en el que 
// se desea realizar el concierto
bool GestionTiquetes::validacionFilasYColumnas(int filaIngresada, int columnaIngresada, int filasMatriz, int columnasMatriz) {
	return ((filaIngresada <= filasMatriz) && (columnaIngresada <= columnasMatriz));
}
// este metodo sera llamado, si el usuario ingresa un asiento que no existe
void GestionTiquetes::imprimirErrorDeCompra() {
	std::cout << "El asiento deseado, no se encuentra disponible, o no existe" << std::endl;
	std::cout << "Favora acceder a la opcion 2, del menu de compra, para ver asientos y filas disponibles" << std::endl;
}
void GestionTiquetes::imprimirCompraCompletada(bool isCompleted) {
	if (isCompleted) {
		std::cout << "Gracias por la compra, el campo ha sido asignado" << std::endl;
	}
}
// Verifica si el tiquete es VIP, basado en la posicion de la fila
bool GestionTiquetes::esTiqueteVIP(int numFila) {
	return numFila >= 20;
}
// Calcular el precio total del tiquete
// si el bool pasado es true, se agrega el 50% extra del costo
// para los tiquetes VIP
double GestionTiquetes::precioTotalDelTiquete(double precio, bool isVIP) {
	double precioTotal = 0;
	if (isVIP) {
		// 50% mas si es VIP
		precioTotal = precioTotal + (precio*(0.5));
		std::cout << "Este tiquete es VIP, cuesta un 50% mas" << std::endl;
	}
	// Impuesto de venta del 13%
	precioTotal = precioTotal + precio + (precio*0.13);
	return precioTotal;
}
