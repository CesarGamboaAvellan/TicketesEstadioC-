#include <iostream>
#include "Menu.h";
#include "Tiquete.h"

int main() {
	// Instanciar el puntero de tipo Tiquete
	Tiquete **ptrM;
	int fil = 50;
	int col = 40;
	// Creacion de un array de punteros
	ptrM = new Tiquete*[fil];

	for (int i = 0; i < fil; ++i)
		ptrM[i] = new Tiquete[col];
	// this is a test to change the status of the matriz
	ptrM[0][1].setStatus(true);
	// this is to show the columns of the matrix
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
		

	return 0;
}