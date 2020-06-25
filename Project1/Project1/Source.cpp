#include <iostream>
#include <conio.h>
#include <iomanip>
#include "CArbolBusqueda.h"
#include "CColumnas.h"

using namespace System;

int main() {
	auto k1 = [](CColumnas* a) { return a->get_nombre(); };
	auto k2 = [](CColumnas* a) { return a->get_DNI(); };

	CArbolBusqueda<CColumnas*, string, nullptr>* idxNom = new CArbolBusqueda<CColumnas*, string, nullptr>(k1);
	CArbolBusqueda<CColumnas*, long long, nullptr>* idxDNI = new CArbolBusqueda<CColumnas*, long long, nullptr>(k2);

	auto print = [](CColumnas* a) {
		if (a == nullptr) return;
		cout << setw(6) << a->get_DNI() << setw(12) << a->get_nombre() << setw(12) << endl;
	};

	string nomb;
	long dni;
	bool c = true;
	while (c) {
		cout << "SELECCIONE UNA OPCION:" << endl;
		cout << "\n1. Agregar";
		cout << "\n2. Mostrar Tabla Completa";
		cout << "\n3. Buscar DNI";
		cout << "\n4. Guardar";
		cout << "\n5. Salir";
		char t = _getch();
		Console::Clear();
		switch (t) {
		case 49:
			cout << "Ingrese Nombre: ";
			cin.ignore();
			getline(cin, nomb);
			cout << "Ingrese DNI: ";
			cin >> dni;
			idxDNI->add(new CColumnas(nomb, dni));
			idxNom->add(new CColumnas(nomb, dni));
			break;
		case 50:
			cout << setw(6) << "DNI" << setw(12) << "Nombre\n";
			idxDNI->inOrder(print); cout << endl;
			_getch();
			break;
		case 51:
			cout << "Ingrese DNI a buscar: ";
			cin >> dni;
			cout << endl << setw(6) << "DNI" << setw(12) << "Nombre\n";
			print(idxDNI->find(dni));
			_getch();
			break;
		case 52:

			break;
		case 53:
			c = false;
			break;
		}
		Console::Clear();
	}

	return 0;
}