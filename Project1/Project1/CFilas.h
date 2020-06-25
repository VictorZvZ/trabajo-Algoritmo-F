#pragma once

template<typename T, typename R, T NONE>
class CFilas {
public:
	T elemento;
	CFilas *left;
	CFilas *right;
	CFilas(T e, CFilas<T, R, NONE> *le = NULL, CFilas<T, R, NONE> *ri = NULL) {
		elemento = e;
		left = le;
		right = ri;
	}
};