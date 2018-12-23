#include <iostream>
#include "Menu.h";
#include "Tiquete.h"
#include "GestionTiquetes.h"

// Nota: cuando un campo sea ocupado, se vera una X al imprimir la matriz de campos
int main() {
	// Se inicia el proceso de venta
	// Se carga el menu, que mostrara las opciones para el usuario
	GestionTiquetes nuevaVentaDeTiquetes;
	nuevaVentaDeTiquetes.cargarMenu();
	return 0;
}