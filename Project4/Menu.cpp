#include <iostream>
#include <functional>  
#include "Menu.h"
#include "GestionTiquetes.h"
#include "Tiquete.h"
#include "Administracion.h"



void Menu::loadMenu(char* option) {
	/*system("CLS");*/
	std::cout << "Bienvenido al sistema de compra de tiquetes. "<<std::endl;
	std::cout << "Por favor seleccione una opcion: " << std::endl;
	std::cout << "1. Comprar tiquetes " << std::endl;
	std::cout << "2. Ver asientos disponibles " << std::endl;
	std::cout << "3. Cambiar precios(Admin Zone) " << std::endl;
	std::cout << "4. Salir " << std::endl;
	char seleccion;
	std::cin >> seleccion;
	// VALIDACION: validar que el dato ingresado sea tipo char
	// si no es char, setea el puntero con el valor generico
	if ((std::string)typeid(seleccion).name() == "char") {
		*option = seleccion;
	}
	else {
		*option = '0';
	}
}
bool Menu::maximoLimiteDeCompra(int* numero) {
	// si el numero de compra es mayor a 5, retorna valor false
	// y setea el valor en cero
	// para que el siguiente usuario pueda realizar una compra
	if (*numero > 5) {
		*numero = 0;
		return false;
	}
	else return true;
}
void Menu::loop(char* selectedOptionPointer) {
	Tiquete **ptrGimnasioA;
	Tiquete **ptrGimnasioB;
	Tiquete **ptrGimnasioC;
	// DEFINIMOS LAS FILAS  Y COLUMNAS PARA ESPACIOS EN EL GIMNASIO A 2000 espacios
	constexpr int FILAS_GIMNASIO_A = 50;
	constexpr int COLUMNAS_GIMNASIO_A = 40;
	// DEFINIMOS LAS FILAS  Y COLUMNAS PARA ESPACIOS EN EL GIMNASIO B 1000 espacios
	constexpr int FILAS_GIMNASIO_B = 40;
	constexpr int COLUMNAS_GIMNASIO_B = 25;
	// DEFINIMOS LAS FILAS  Y COLUMNAS PARA ESPACIOS EN EL GIMNASIO C 500 espacios
	constexpr int FILAS_GIMNASIO_C = 25;
	constexpr int COLUMNAS_GIMNASIO_C = 20;
	// Creacion de un array de punteros
	// se crean los tres distintos lugares
	// con sus respectivos tiquetes
	ptrGimnasioA = new Tiquete*[FILAS_GIMNASIO_A];
	ptrGimnasioB = new Tiquete*[FILAS_GIMNASIO_B];
	ptrGimnasioC = new Tiquete*[FILAS_GIMNASIO_C];

	// LLenamos las matrices con sus respectivos asientos
	for (int i = 0; i < FILAS_GIMNASIO_A; ++i)
		ptrGimnasioA[i] = new Tiquete[COLUMNAS_GIMNASIO_A];
	for (int i = 0; i < FILAS_GIMNASIO_B; ++i)
		ptrGimnasioB[i] = new Tiquete[COLUMNAS_GIMNASIO_B];
	for (int i = 0; i < FILAS_GIMNASIO_C; ++i)
		ptrGimnasioC[i] = new Tiquete[COLUMNAS_GIMNASIO_C];
	// creacion de un punteto que almacena la opcion seleccionada del menu
	// y llama la funcion loadMenu que setea el valor de la opcion seleccionada a travez del puntero
	// si el valor ingresado es distinto de 4, repite el ciclo
	while (*selectedOptionPointer != '4') {
		int compraNumero = 0;
		int* compraNumeroPointer = &compraNumero;
		loadMenu(selectedOptionPointer);
		bool validarLimiteDeCompra = maximoLimiteDeCompra(compraNumeroPointer);
		if (*selectedOptionPointer == '1' && validarLimiteDeCompra) {
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
			compraNumero++;
		}
		if (*selectedOptionPointer == '2') {
			int diaDelConcierto;
			std::cout << "Indique el dia que desea ver espacios disponibles" << std::endl;
			std::cout << "1. Dia 1. Gimnasio A\n";
			std::cout << "2. Dia 2. Gimnasio B \n";
			std::cout << "3. Dia 3. Gimnasio C";
			std::cin >> diaDelConcierto;
			if (diaDelConcierto == 1) {
				for (int i = 0; i < FILAS_GIMNASIO_A; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < COLUMNAS_GIMNASIO_A; ++j) {
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
				for (int i = 0; i < FILAS_GIMNASIO_B; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < COLUMNAS_GIMNASIO_B; ++j) {
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
				for (int i = 0; i < FILAS_GIMNASIO_C; ++i) {
					std::cout << "Fila: " << i << "  ";
					for (int j = 0; j < COLUMNAS_GIMNASIO_C; ++j) {
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
		if (*selectedOptionPointer == '3') {
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
					for (int i = 0; i < FILAS_GIMNASIO_A; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_A; ++j) {
							sesionAdministracion.cambiarPrecioTiquetes(&ptrGimnasioA[i][j], precio);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_B; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_B; ++j) {
							sesionAdministracion.cambiarPrecioTiquetes(&ptrGimnasioB[i][j], precio);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_C; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_C; ++j) {
							sesionAdministracion.cambiarPrecioTiquetes(&ptrGimnasioC[i][j], precio);
						}
					}
					std::cout << "El precio de los tiquetes ha sido cambiado, gracias." << std::endl;
				}
				if (opcion == 2) {
					std::string nuevaFecha;
					std::cout << "Por favor ingrese la fecha en que inician los conciertos" << std::endl;
					std::cin >> nuevaFecha;
					for (int i = 0; i < FILAS_GIMNASIO_A; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_A; ++j) {
							sesionAdministracion.cambiarFechadeLaFuncion(&ptrGimnasioA[i][j], nuevaFecha);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_B; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_B; ++j) {
							sesionAdministracion.cambiarFechadeLaFuncion(&ptrGimnasioB[i][j], nuevaFecha);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_C; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_C; ++j) {
							sesionAdministracion.cambiarFechadeLaFuncion(&ptrGimnasioC[i][j], nuevaFecha);
						}
					}
					std::cout << "Se ha cambiado la fecha en que inician los conciertos" << std::endl;
				}
				if (opcion == 3) {
					std::string nuevoLugar;
					std::cout << "Ingrese el lugar donde se llevaran a cabo los conciertos" << std::endl;
					std::cin >> nuevoLugar;
					for (int i = 0; i < FILAS_GIMNASIO_A; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_A; ++j) {
							sesionAdministracion.cambiarLugar(&ptrGimnasioA[i][j], nuevoLugar);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_C; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_C; ++j) {
							sesionAdministracion.cambiarLugar(&ptrGimnasioC[i][j], nuevoLugar);
						}
					}
					for (int i = 0; i < FILAS_GIMNASIO_B; ++i) {
						for (int j = 0; j < COLUMNAS_GIMNASIO_B; ++j) {
							sesionAdministracion.cambiarLugar(&ptrGimnasioB[i][j], nuevoLugar);
						}
					}
					std::cout << "Se ha cambiado la fecha en que inician los conciertos" << std::endl;
				}	
			}
		}
	}
}