#include <iostream>
#include "Menu.h";
#include "Tiquete.h"
#include "GestionTiquetes.h"

int main() {
	// Se inicia el proceso de venta
	// Se carga el menu, que mostrara las opciones para el usuario
	GestionTiquetes nuevaVentaDeTiquetes;
	nuevaVentaDeTiquetes.cargarMenu();
	return 0;
}