#include <iostream>
#include "GestionTiquetes.h"
#include "Tiquete.h"

GestionTiquetes::GestionTiquetes() {}
void GestionTiquetes::cargarMenu() {
	char selectedOption = '0';
	char *selectedOptionPointer = &selectedOption;
	loop(selectedOptionPointer);
}