#pragma once
#include "Tiquete.h"
class Administracion: Tiquete {
public:
	void cambiarPrecioTiquetes(Tiquete* tiquete, double precio);
	void adminMenu();
	void cambiarFechadeLaFuncion(Tiquete* tiquete, std::string);
	void cambiarLugar(Tiquete* tiquete, std::string);
};