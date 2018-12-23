#include <iostream>
#include <functional>  
#include "Menu.h"
#include "GestionTiquetes.h"
#include "Tiquete.h"
#include "Administracion.h"


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
	Tiquete **ptrGimnasioA;
	Tiquete **ptrGimnasioB;
	Tiquete **ptrGimnasioC;
	int fil = 50;
	int col = 40;
	// Creacion de un array de punteros
	// se crean los tres distintos lugares
	// con sus respectivos tiquetes
	ptrGimnasioA = new Tiquete*[fil];
	ptrGimnasioB = new Tiquete*[fil];
	ptrGimnasioC = new Tiquete*[fil];

	for (int i = 0; i < fil; ++i)
		ptrGimnasioA[i] = new Tiquete[col];

	while (*selectedOptionPointer != 4) {
		loadMenu(selectedOptionPointer);
		if (*selectedOptionPointer == 1) {
			int numFila;
			int numAsiento;
			int diaYLugarDelConcierto;
			std::cout << "Para que dia desea comprar el tiquete?" << std::endl;
			std::cout << "1. Dia 1. Gimnasio A\n";
			std::cout << "2. Dia 2. Gimnasio B \n";
			std::cout << "3. Dia 3. Gimnasio C";
			std::cin >> diaYLugarDelConcierto;
			std::cout << "En que numero de fila desea estar? " << std::endl;
			std::cin >> numFila;
			std::cout << "Digite el numero de asiento:  " << std::endl;
			std::cin >> numAsiento;
			if (diaYLugarDelConcierto == 1) {
				ptrGimnasioA[numFila][numAsiento].setStatus(true);
			}
			if (diaYLugarDelConcierto == 2) {
				ptrGimnasioB[numFila][numAsiento].setStatus(true);
			}
			if (diaYLugarDelConcierto == 3) {
				ptrGimnasioC[numFila][numAsiento].setStatus(true);
			}
			// mostrar calculos de precio aca. 
			std::cout << "Gracias por la compra, el campo ha sido asignado" << std::endl;
		}
		if (*selectedOptionPointer == 2) {
			int diaDelConcierto;
			std::cout << "Indique el dia que desea ver espacios disponibles" << std::endl;
			std::cout << "1. Dia 1. Gimnasio A\n";
			std::cout << "2. Dia 2. Gimnasio B \n";
			std::cout << "3. Dia 3. Gimnasio C";
			std::cin >> diaDelConcierto;
			if (diaDelConcierto == 1) {
				for (int i = 0; i < fil; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < col; ++j) {
						bool checkIfSold = ptrGimnasioA[i][j].verificarEstado();
						if (!checkIfSold) {
							ptrGimnasioA[i][j].asignarNumeroAsiento(j);
						}
						std::cout << ptrGimnasioA[i][j].getStatus() << " ";
					}
					std::cout << std::endl << std::endl;
				}
			}
			if (diaDelConcierto == 2) {
				for (int i = 0; i < fil; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < col; ++j) {
						bool checkIfSold = ptrGimnasioB[i][j].verificarEstado();
						if (!checkIfSold) {
							ptrGimnasioB[i][j].asignarNumeroAsiento(j);
						}
						std::cout << ptrGimnasioB[i][j].getStatus() << " ";
					}
					std::cout << std::endl << std::endl;
				}
			}
			if (diaDelConcierto == 3) {
				for (int i = 0; i < fil; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < col; ++j) {
						bool checkIfSold = ptrGimnasioC[i][j].verificarEstado();
						if (!checkIfSold) {
							ptrGimnasioC[i][j].asignarNumeroAsiento(j);
						}
						std::cout << ptrGimnasioC[i][j].getStatus() << " ";
					}
					std::cout << std::endl << std::endl;
				}
			}
		}
		// Si se entra a la zona de administracion, se puede setear el precio de los tiquetes
		// para ingresar, la contrase;a es admin
		if (*selectedOptionPointer == 3) {
			std::string password = "admin";
			std::string tempPassword;
			std::cout << "Por favor ingrese la contrase;a de  administrador";
			std::cin >> tempPassword;
			if (tempPassword == password) {
				Administracion sesionAdministracion;
				int opcion;
				sesionAdministracion.adminMenu();
				std::cin >> opcion;
				if (opcion == 1) {
					double precio;
					std::cout << "Por favor, ingrese el nuevo precio de los tiquetes" << std::endl;
					std::cin >> precio;
					for (int i = 0; i < fil; ++i) {
						for (int j = 0; j < col; ++j) {
							sesionAdministracion.cambiarPrecioTiquetes(&ptrGimnasioA[i][j], precio);
						}
					}
					std::cout << "El precio de los tiquetes ha sido cambiado, gracias." << std::endl;
				}
				if (opcion == 2) {
					std::string nuevaFecha;
					std::cout << "Por favor ingrese la fecha en que inician los conciertos" << std::endl;
					std::cin >> nuevaFecha;
					for (int i = 0; i < fil; ++i) {
						for (int j = 0; j < col; ++j) {
							sesionAdministracion.cambiarFechadeLaFuncion(&ptrGimnasioA[i][j], nuevaFecha);
						}
					}
					std::cout << "Se ha cambiado la fecha en que inician los conciertos" << std::endl;
				}
				if (opcion == 3) {
					std::string nuevoLugar;
					std::cout << "Ingrese el lugar donde se llevaran a cabo los conciertos" << std::endl;
					std::cin >> nuevoLugar;
					for (int i = 0; i < fil; ++i) {
						for (int j = 0; j < col; ++j) {
							sesionAdministracion.cambiarLugar(&ptrGimnasioA[i][j], nuevoLugar);
						}
					}
					std::cout << "Se ha cambiado la fecha en que inician los conciertos" << std::endl;
				}	
			}
		}
	}
}