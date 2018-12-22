#include <iostream>
#include <functional>  
#include "Menu.h"


void Menu::loadMenu(int* option) {
	system("CLS");
	std::cout << "Bienvenido al sistema de compra de tiquetes. "<<std::endl;
	std::cout << "Por favor seleccione una opcion: " << std::endl;
	std::cout << "1. Comprar tiquetes " << std::endl;
	std::cout << "2. Ver asientos disponibles " << std::endl;
	std::cout << "3. Cambiar precios(Admin Zone) " << std::endl;
	std::cout << "4. Salir " << std::endl;
	int seleccion;
	std::cin>>seleccion;
	*option = seleccion;
}