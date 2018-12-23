#include <iostream>
#include <functional>  
#include "Menu.h"
#include "GestionTiquetes.h"
#include "Tiquete.h"


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
	Tiquete **ptrM;
	int fil = 50;
	int col = 40;
	// Creacion de un array de punteros
	ptrM = new Tiquete*[fil];

	for (int i = 0; i < fil; ++i)
		ptrM[i] = new Tiquete[col];

	while (*selectedOptionPointer != 4) {
		loadMenu(selectedOptionPointer);
		if (*selectedOptionPointer == 1) {
			int numFila;
			int numAsiento;
			std::cout << "En que numero de fila desea estar? " << std::endl;
			std::cin >> numFila;
			std::cout << "Digite el numero de asiento:  " << std::endl;
			std::cin >> numAsiento;
			ptrM[numFila][numAsiento].setStatus(true);
			// mostrar calculos de precio aca. 
			std::cout << "Gracias por la compra, el campo ha sido asignado" << std::endl;
		}
		if (*selectedOptionPointer == 2) {
			for (int i = 0; i < fil; ++i) {
				std::cout << "Fila: " << i << "  ";
				for (int j = 0; j < col; ++j) {
					bool checkIfSold = ptrM[i][j].verificarEstado();
					if (!checkIfSold) {
						ptrM[i][j].asignarNumeroAsiento(j);
					}
					std::cout << ptrM[i][j].getStatus() << " ";
				}
				std::cout << std::endl << std::endl;
			}
		}
		if (*selectedOptionPointer == 3) {
			std::cout << "vos sos admin?" << std::endl;
		}
	}
}