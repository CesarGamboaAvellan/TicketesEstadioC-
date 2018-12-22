#pragma once
#include <string>
class Tiquete {
private:
	std::string time;
	double costoImpresion;
	std::string tipoDeTiquete;
	// declarar variable global impuesto venta
	std::string status = "[_]";
	int identificador;
public:
	std::string getStatus();
	void setStatus(bool);
	Tiquete(int);
	bool verificarEstado();
	void asignarNumeroAsiento(int);
	Tiquete();
};