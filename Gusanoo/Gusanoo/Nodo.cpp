#include "Nodo.h"


Nodo::Nodo() {}
Nodo::Nodo(Dato t)
{
	dato = t;
	enlace = nullptr;
}
Nodo::Nodo(Label^ as, Dato p, Nodo^ n)
{
	pic = as;
	dato = p;
	enlace = n;
}
Dato Nodo::datoNodo()
{
	return dato;
}
void Nodo::datoNodo(Dato d)
{
	dato = d;
}
Nodo^ Nodo::enlaceNodo()
{
	return enlace;
}
void Nodo::ponerEnlace(Nodo^ sgte)
{
	enlace = sgte;
}

Label^ Nodo::label() {
	return pic;
}

void Nodo::label(Label^ aux) {
	pic = aux;
}


