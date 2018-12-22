#include <iostream>
#include <functional>  
#include "Menu.h"


void Menu::loadMenu(int* option) {
	/*system("CLS");*/
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
void Menu::loop(int * selectedOptionPointer) {
	while (*selectedOptionPointer != 4) {
		loadMenu(selectedOptionPointer);
		if (*selectedOptionPointer == 1) {
			std::cout << "Dale loco vamos a comprar tiquetes!" << std::endl;
		}
		if (*selectedOptionPointer == 2) {
			std::cout << "queres ver los asientos loco" << std::endl;
		}
		if (*selectedOptionPointer == 3) {
			std::cout << "vos sos admin?" << std::endl;
		}
	}
}