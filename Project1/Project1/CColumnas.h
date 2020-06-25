#pragma once
#include <string>

using namespace std;

class CColumnas {
private:
	string nombre;
	long DNI;
public:
	CColumnas(string nomb, long dni) {
		nombre = nomb;
		DNI = dni;
	}
	string get_nombre() { return nombre; }
	long get_DNI() { return DNI; }
};