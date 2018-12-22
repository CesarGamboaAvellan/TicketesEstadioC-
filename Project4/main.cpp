#include <iostream>
#include "Menu.h";

int main() {
	int selectedOption = 0;
	int* selectedOptionPointer = &selectedOption;
	Menu newMenu;
	while (selectedOption != 4) {
		newMenu.loadMenu(selectedOptionPointer);
	}
	return 0;
}