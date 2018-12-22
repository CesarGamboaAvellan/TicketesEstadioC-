#include "Tiquete.h";
#include <iostream>

Tiquete::Tiquete(int ident): identificador(ident) {
	std::cout << "this is the ticket identifier" << identificador << std::endl;
}
Tiquete::Tiquete(){}
std::string Tiquete::getStatus() {
	return status;
}
void Tiquete::setStatus(bool isSold) {
	if (isSold) {
		status = "X";
	};
}