#include <iostream>
#include "Menu.h";

int main() {
	int selectedOption = 0;
	int* selectedOptionPointer = &selectedOption;
	Menu newMenu;
	newMenu.loop(selectedOptionPointer);
	return 0;
}