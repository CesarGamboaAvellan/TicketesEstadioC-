#include <iostream>
#include "GestionTiquetes.h"
#include "Tiquete.h"

GestionTiquetes::GestionTiquetes() {}
void GestionTiquetes::cargarMenu() {
	int selectedOption = 0;
	int *selectedOptionPointer = &selectedOption;
	loop(selectedOptionPointer);
}