#include "Inicio.h" 
#include "Gusano.h" 
#include "Puntaje.h" 
#include "ListaSimple.h"
 

using namespace System;
using namespace System::Windows::Forms;

[STAThread] // Pode Ser int main Ou void main
int main(array<String^>^ arg) {
	

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Gusanoo::Inicio form;
	Application::Run(%form);
}