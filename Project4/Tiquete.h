#pragma once
#include <string>
class Tiquete {
private:
	std::string time;
	std::string lugar;
	double costoImpresion;
	// tipo de tiquete basico, si es fila VIP, se le mostrara un mensaje al usuario
	std::string tipoDeTiquete = "basico";
	// Este es el precio base, el admin puede modificar este precio
	double costoDelTiquete = 2000;
	// simbolo para asiento disponible, en vez del _, se mostrara el numero de asiento
	std::string status = "[_]";
public:
	std::string getStatus();
	void setStatus(bool);
	bool verificarEstado();
	void asignarNumeroAsiento(int);
	void setPrecio(double);
	void setFecha(std::string);
	double getPrecio();
	void setLugar(std::string);
	void mostrarInformacionDelTiquete();
	Tiquete();
};