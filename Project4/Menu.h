#pragma once
#include "Tiquete.h"

class Menu {
public:
	// carga el menu
	void loadMenu(char* option);
	// mientras que opcion != 4, entrra en un ciclo
	void loop(char * option);
	// retorna false si el numero es mayor que 5
	bool maximoLimiteDeCompra(int*);
	// metodo para limpiar los arrays multidimensionales
	void limpiarMemoria(Tiquete** tiquete, int);
};