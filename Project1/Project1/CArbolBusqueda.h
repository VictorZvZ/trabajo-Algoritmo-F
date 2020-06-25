#pragma once
#include <functional>
#include "CFilas.h"

using namespace std;

template<typename T, typename R = T, T NONE = 0>
class CArbolBusqueda {
	CFilas<T, R, NONE> *root;
	function<R(T)>  key;
public:
	CArbolBusqueda(function<R(T)> key = [](T a) { return a; }) : key(key), root(nullptr) {}
	void add(T elem) { add(root, elem); }
	T find(R val) { return find(root, val); }
	void inOrder(function<void(T)> proc) { inOrder(root, proc); }
private:
	void add(CFilas<T, R, NONE>*& fila, T elem);
	T find(CFilas<T, R, NONE>* fila, R val);
	void inOrder(CFilas<T, R, NONE>* fila, function<void(T)> proc);
};

template<typename T, typename R, T NONE>
void CArbolBusqueda<T, R, NONE>::add(CFilas<T, R, NONE>*& fila, T elem) {
	if (fila == nullptr) {
		fila = new CFilas<T, R, NONE>(elem);
	}
	else {
		if (key(elem) < key(fila->elemento)) {
			add(fila->left, elem);
		}
		else {
			add(fila->right, elem);
		}
	}
}

template<typename T, typename R, T NONE>
T CArbolBusqueda<T, R, NONE>::find(CFilas<T, R, NONE>* fila, R val) {
	if (fila == nullptr) {
		return NONE;
	}
	else if (val == key(fila->elemento)) {
		return fila->elemento;
	}
	else if (val < key(fila->elemento)) {
		return find(fila->left, val);
	}
	else {
		return find(fila->right, val);
	}
}

template<typename T, typename R, T NONE>
void CArbolBusqueda<T, R, NONE>::inOrder(CFilas<T, R, NONE>* fila, function<void(T)> proc) {
	if (fila != nullptr) {
		inOrder(fila->left, proc);
		proc(fila->elemento);
		inOrder(fila->right, proc);
	}
}