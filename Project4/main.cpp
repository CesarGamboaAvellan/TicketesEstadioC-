#include <iostream>
#include "Menu.h";
#include "Tiquete.h"

int main() {
	Tiquete **ptrM;
	int fil = 50;
	int col = 40;
	ptrM = new Tiquete*[fil];

	for (int i = 0; i < fil; ++i)
		ptrM[i] = new Tiquete[col];

	for (int i = 0; i < fil; ++i) {
		for (int j = 0; j < col; ++j) {
			std::cout << ptrM[i][j].getStatus() << " ";
		}
			std::cout << std::endl << std::endl;
	}
		


	return 0;
}