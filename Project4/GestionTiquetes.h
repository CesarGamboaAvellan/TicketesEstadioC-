#pragma once
#include "Menu.h"
class GestionTiquetes:Menu {
public:
	//metodo constructor
	GestionTiquetes();
	// metodo void, perteneciente a la clase menu, inicia el menu
	void cargarMenu();
	bool validacionFilasYColumnas(int,int,int,int);
	void imprimirErrorDeCompra();
	void imprimirCompraCompletada(bool);
};