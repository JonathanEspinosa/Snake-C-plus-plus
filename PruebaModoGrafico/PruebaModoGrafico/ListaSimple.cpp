#include "ListaSimple.h"




ListaSimple::ListaSimple()
{
	primero = nullptr;
}

ListaSimple::ListaSimple(Dato entrada, Label^ pic)
{
	insertarInicio(entrada, pic);
}

Label^ ListaSimple::ver(Dato i) {
	Nodo^ indice = buscarNodo(i);
	return indice->label();

}

Nodo^ ListaSimple::buscarNodo(Dato destino)
{
	Nodo^ indice;
	for (indice = primero; indice != nullptr; indice = indice->enlaceNodo())
		if (destino == indice->datoNodo())
		{
			return indice;
		}
	return nullptr;
}


void  ListaSimple::insertarInicio(Dato entrada, Label^ pic)
{
	Nodo^ nuevo;
	nuevo = gcnew Nodo(pic, entrada, primero);
	primero = nuevo;
}



void ListaSimple::eliminarDato(Dato entrada)
{
	Nodo ^actual, ^anterior;
	bool encontrado;
	actual = primero;
	anterior = nullptr;
	encontrado = false;
	while ((actual != nullptr) && !encontrado)
	{
		encontrado = (actual->datoNodo() == entrada);
		if (!encontrado)
		{
			anterior = actual;
			actual = actual->enlaceNodo();
		}
	}
	if (actual != nullptr)
	{
		if (actual == primero)
		{
			primero = actual->enlaceNodo();
		}
		else
		{
			anterior->ponerEnlace(actual->enlaceNodo());
		}
		delete actual;
	}

}