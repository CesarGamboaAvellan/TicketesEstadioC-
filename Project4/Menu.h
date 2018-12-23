#pragma once
#include "Tiquete.h"

class Menu {
public:
	void loadMenu(char* option);
	void loop(char * option);
	bool maximoLimiteDeCompra(int*);
	void limpiarMemoria(Tiquete** tiquete, int);
};