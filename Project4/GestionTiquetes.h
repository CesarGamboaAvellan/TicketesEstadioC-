#pragma once
#include "Menu.h"
class GestionTiquetes:Menu {
public:
	//metodo constructor
	GestionTiquetes();
	// metodo void, perteneciente a la clase menu, inicia el menu
	void cargarMenu();
	// nos aseguramos q se ingresen valores correctos
	bool validacionFilasYColumnas(int,int,int,int);
	void imprimirErrorDeCompra();
	void imprimirCompraCompletada(bool);
	// determina si VIP es true or false
	bool esTiqueteVIP(int);
	// calcula el precio del tiquete, si el bool es true, agrega el 50% extra
	double precioTotalDelTiquete(double, bool);
};