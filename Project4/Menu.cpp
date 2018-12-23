#include <iostream>
#include <functional>  
#include <iomanip>   
#include "Menu.h"
#include "GestionTiquetes.h"
#include "Tiquete.h"
#include "Administracion.h"



void Menu::loadMenu(char* option) {
	// Menu principal
	std::cout << std::setw(50)<< "_________________________________________________________"  <<std::endl;
	std::cout << std::setw(50)<< "|  Bienvenido al sistema de compra de tiquetes Navidenos |"<<std::endl;
	std::cout << std::setw(50) <<"_________________________________________________________" << std::endl;
	std::cout << std::setw(50) << "Por favor seleccione una opcion: " << std::endl;
	std::cout << std::setw(39) << "1. Comprar tiquetes " << std::endl;
	std::cout << std::setw(47) << "2. Ver asientos disponibles " << std::endl;
	std::cout << std::setw(44) << "3. Zona de administracion" << std::endl;
	std::cout << std::setw(28) << "4. Salir " << std::endl;
	char seleccion;
	std::cin >> seleccion;
	// VALIDACION: validar que el dato ingresado sea tipo char
	// si no es char, setea el puntero con el valor generico
	// se limpia la consola despues de que el usuario ingresa un valor
	system("CLS");
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
	GestionTiquetes nuevaGestion;
	while (*selectedOptionPointer != '4') {
		int compraNumero = 0;
		int* compraNumeroPointer = &compraNumero;
		loadMenu(selectedOptionPointer);
		bool validarLimiteDeCompra = maximoLimiteDeCompra(compraNumeroPointer);
		if (*selectedOptionPointer == '1' && validarLimiteDeCompra) {
			int numFila;
			int numAsiento;
			bool isCompleted = false;
			double precioTotal = 0;
			bool isVIP = false;
			char diaYLugarDelConcierto;
			std::cout << "Para que dia desea comprar el tiquete?" << std::endl;
			std::cout << "1. Dia 1. Gimnasio A\n";
			std::cout << "2. Dia 2. Gimnasio B \n";
			std::cout << "3. Dia 3. Gimnasio C";
			std::cin >> diaYLugarDelConcierto;
			std::cout << "En que numero de fila desea estar? " << std::endl;
			std::cin >> numFila;
			std::cout << "Digite el numero de asiento:  " << std::endl;
			std::cin >> numAsiento;
			// verifica si el asiento deseado es VIP
			// returna true si es el caso
			isVIP = nuevaGestion.esTiqueteVIP(numFila);
			if (diaYLugarDelConcierto == '1') {
				if (nuevaGestion.validacionFilasYColumnas(numAsiento, numAsiento, FILAS_GIMNASIO_A, COLUMNAS_GIMNASIO_A)) {
					// Esta funcion recibe el precio segun el gimnasio y si es VIP
					precioTotal = nuevaGestion.precioTotalDelTiquete(ptrGimnasioA[numFila][numAsiento].getPrecio(), isVIP);
					ptrGimnasioA[numFila][numAsiento].setStatus(true);
					std::cout << "El precio del tiquete es: " << precioTotal << std::endl;
					isCompleted = true;
				}
				// muestra en caso de error
				else {
					nuevaGestion.imprimirErrorDeCompra();
				}
			}
			if (diaYLugarDelConcierto == '2') {
				if (nuevaGestion.validacionFilasYColumnas(numAsiento, numAsiento, FILAS_GIMNASIO_B, COLUMNAS_GIMNASIO_B)) {
					precioTotal = nuevaGestion.precioTotalDelTiquete(ptrGimnasioB[numFila][numAsiento].getPrecio(), isVIP);
					ptrGimnasioB[numFila][numAsiento].setStatus(true);
					std::cout << "El precio del tiquete es: " << precioTotal << std::endl;
					isCompleted = true;
				}
				else {
					nuevaGestion.imprimirErrorDeCompra();
				}
			}
			if (diaYLugarDelConcierto == '3') {
				if (nuevaGestion.validacionFilasYColumnas(numAsiento, numAsiento, FILAS_GIMNASIO_C, COLUMNAS_GIMNASIO_C)) {
					precioTotal = nuevaGestion.precioTotalDelTiquete(ptrGimnasioC[numFila][numAsiento].getPrecio(), isVIP);
					ptrGimnasioC[numFila][numAsiento].setStatus(true);
					std::cout << "El precio del tiquete es: " << precioTotal << std::endl;
					isCompleted = true;
				}
				else {
					nuevaGestion.imprimirErrorDeCompra();
				}
			}
			// mostrar calculos de precio aca. 

			// si la compra se completto, se imprime mensaje de compra
			nuevaGestion.imprimirCompraCompletada(isCompleted);
			compraNumero++;
		}
		if (*selectedOptionPointer == '2') {
			char diaDelConcierto;
			std::cout << "Indique el dia que desea ver espacios disponibles" << std::endl;
			std::cout << "1. Dia 1. Gimnasio A\n";
			std::cout << "2. Dia 2. Gimnasio B \n";
			std::cout << "3. Dia 3. Gimnasio C";
			std::cin >> diaDelConcierto;
			// Validar que el valor ingresado sea de tipo char
			if ((std::string)typeid(diaDelConcierto).name() == "char") {
				if (diaDelConcierto == '1') {
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
				if (diaDelConcierto == '2') {
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
				if (diaDelConcierto == '3') {
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
				// mostrar error si la opcion ingresada no es 1,2,3
				else if((diaDelConcierto != '3')&&((diaDelConcierto != '2'))&&((diaDelConcierto != '1'))) {
					std::cout << "Opcion ingresada no valida" << std::endl;
				}
			}
			
		}
		// Si se entra a la zona de administracion, se puede setear el precio de los tiquetes
		// para ingresar, la contrase;a es admin
		if (*selectedOptionPointer == '3') {
			// creacion de la contrase;a por defecto
			std::string password = "admin";
			std::string tempPassword;
			std::cout << "Por favor ingrese la contrase;a de  administrador";
			std::cin >> tempPassword;
			if (tempPassword == password) {
				Administracion sesionAdministracion;
				char opcion;
				// clase administrativa, activacion del menu de administracion
				sesionAdministracion.adminMenu();
				std::cin >> opcion;
				// verificar que el valor ingresado es tipo char
				if ((std::string)typeid(opcion).name() == "char") {
					if (opcion == '1') {
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
					if (opcion == '2') {
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
					if (opcion == '3') {
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
}