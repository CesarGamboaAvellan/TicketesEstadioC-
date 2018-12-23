#pragma once
#include <string>
class Tiquete {
private:
	std::string time;
	std::string lugar;
	double costoImpresion;
	std::string tipoDeTiquete;
	double costoDelTiquete;
	// declarar variable global impuesto venta
	std::string status = "[_]";
	int identificador;
public:
	std::string getStatus();
	void setStatus(bool);
	Tiquete(int);
	bool verificarEstado();
	void asignarNumeroAsiento(int);
	void setPrecio(double);
	void setFecha(std::string);
	void setLugar(std::string);
	void mostrarInformacionDelTiquete();
	Tiquete();
};