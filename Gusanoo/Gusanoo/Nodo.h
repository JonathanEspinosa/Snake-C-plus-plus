#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

typedef int Dato;
ref class Nodo
{

public:
	Nodo();
	Nodo(Dato t);
	Nodo(Label^ as, Dato p, Nodo^ n);

	Dato datoNodo();
	Nodo^ enlaceNodo();
	void ponerEnlace(Nodo^ sgte);
	void datoNodo(Dato d);
	Label^ label();
	void label(Label^ aux);

protected:
	Label^ pic;
	Dato dato;
	Nodo^ enlace;
};