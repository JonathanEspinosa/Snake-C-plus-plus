#pragma once
#include "Nodo.h" 


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class ListaSimple
{
protected:
	Nodo^ primero;

	Nodo^ ListaSimple::ultimo()
	{
		Nodo^ p = primero;
		if (p == nullptr) throw "Error, lista vacía";
		while (p->enlaceNodo() != nullptr)
			p = p->enlaceNodo();
		return p;
	}
public:
	ListaSimple();
	ListaSimple(Dato entrada, Label^ pic);
	void ListaSimple::eliminarDato(Dato entrada);
	Nodo^ ListaSimple::buscarNodo(Dato destino);
	void  ListaSimple::insertarInicio(Dato entrada, Label^ pic);
	Label^ ListaSimple::ver(Dato i);


};
