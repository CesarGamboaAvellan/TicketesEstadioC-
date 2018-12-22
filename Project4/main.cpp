#include <iostream>
#include "Menu.h";

int main() {
	/*int selectedOption = 0;
	int* selectedOptionPointer = &selectedOption;
	Menu newMenu;
	newMenu.loop(selectedOptionPointer);*/
	int **ptrM;
	int fil = 50;
	int col = 40;
	ptrM = new int*[fil];

	// Para cada apuntador del arreglo de filas, asignamos un vector de elementos
	// enteros
	for (int i = 0; i < fil; ++i)
		ptrM[i] = new int[col];

	// Llenamos la matriz con valores aleatorios del 1 al 100
	for (int i = 0; i < fil; ++i)
		for (int j = 0; j < col; ++j)
			ptrM[i][j] = 0;

	for (int i = 0; i < fil; ++i) {
		for (int j = 0; j < col; ++j)
			std::cout << ptrM[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	return 0;
}