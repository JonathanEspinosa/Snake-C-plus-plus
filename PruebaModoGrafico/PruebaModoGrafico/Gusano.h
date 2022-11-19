#pragma once 
#include <stdlib.h>     /* srand, rand */
#include <time.h>      
#include "ListaSimple.h"
#include "frmNombrePuntaje.h"

namespace PruebaModoGrafico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Gusano
	/// </summary>
	public ref class Gusano : public System::Windows::Forms::Form
	{

		ListaSimple lista;

		char Direccion = 'R';// direccion o lugar para las imagenes 
		int TamanoPrincipal = 40, tiempo;
		Label^ comida = (gcnew System::Windows::Forms::Label());// labels con imagenes cargadas en este va a contebner comida
		
	private: System::Windows::Forms::Label^  lblpuntos;

			 int i = 0;
	public:
		void iniciarJuego() {
			tiempo = 0;
			timer1->Interval = 211;
			lblpuntos->Text = i.ToString();
			//Piezas iniciales
			for (int q = 2; 0 <= q; q--) {
				crearGusano((q*TamanoPrincipal) + 80, 80);// cuerpos pegados segun las posiciones

			}
			crearComida();
		}
		
		///FUNCION QUE CREA AL GUSANO 
		void crearGusano(int posx, int posy) {
			Label^ pb = (gcnew System::Windows::Forms::Label());
			pb->BackgroundImage = Image::FromFile("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/circulo.png");
			pb->BackColor = System::Drawing::Color::Transparent;
			pb->Width = 40;
			pb->Height = 40;
			pb->Location = System::Drawing::Point(posx, posy);
			pb->BackgroundImageLayout = ImageLayout::Zoom;
			lista.insertarInicio(i, pb);// la i es el numero de cuesrpos o tambien pocision 
			this->Controls->Add(lista.ver(i));//es como una lista de cosas graficas que se anaden a la ventana
			i++;
		}

		//FUNCION QUE POONE LA COMIDA
		void crearComida() {
			int X = rand() % (this->Width - TamanoPrincipal - 10) + 1;
			int Y = rand() % (this->Height - TamanoPrincipal - 40) + 1;
			Label^ repollo = (gcnew System::Windows::Forms::Label());
			repollo->BackgroundImage = Image::FromFile("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/sdlg.png");
			repollo->BackColor = System::Drawing::Color::Transparent;
			repollo->Width = 40;
			repollo->Height = 40;
			repollo->Location = System::Drawing::Point(X, Y);
			repollo->BackgroundImageLayout = ImageLayout::Zoom;
			comida = repollo;
			this->Controls->Add(repollo);
		} 
		void perderJuego() {
			for (int c = i - 1; c >= 0; c--)
			{
				this->Controls->Remove(lista.ver(c));
				lista.eliminarDato(c);
			}
			this->Controls->Remove(comida);
			timer1->Enabled = false;
			i = i * 173;
			frmNombrePuntaje(i).ShowDialog();
			frmPuntaje().ShowDialog();
			this->Close(); 
		}
		Gusano(void)
		{
			srand(time(NULL)); 
			InitializeComponent();
			iniciarJuego(); 
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Gusano()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		 

		void InitializeComponent()
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Gusano::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblpuntos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Gusano::timer1_Tick);
			// 
			// lblpuntos
			// 
			this->lblpuntos->BackColor = System::Drawing::Color::Transparent;
			this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblpuntos->ForeColor = System::Drawing::Color::DarkRed;
			this->lblpuntos->Location = System::Drawing::Point(762, 529);
			this->lblpuntos->Name = L"lblpuntos";
			this->lblpuntos->Size = System::Drawing::Size(100, 23);
			this->lblpuntos->TabIndex = 0;
			// 
			// Gusano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(874, 561);
			this->Controls->Add(this->lblpuntos);
			this->ForeColor = System::Drawing::Color::Black;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Gusano";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Gusano::Gusano_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Gusano::mover);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		lblpuntos->Text = i.ToString();
		int nx = lista.ver(0)->Location.X;
		int ny = lista.ver(0)->Location.Y;
		lista.ver(0)->BackgroundImage = Image::FromFile("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/pacman" + Direccion + ".png");

		for (int t = i - 1; t >= 0; t--) {
			if (t == 0) {

				if (Direccion == 'R') nx = nx + TamanoPrincipal;
				else if (Direccion == 'L') nx = nx - TamanoPrincipal;
				else if (Direccion == 'U') ny = ny - TamanoPrincipal;
				else if (Direccion == 'D') ny = ny + TamanoPrincipal;
				lista.ver(0)->BackgroundImage = Image::FromFile("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/pacman" + Direccion + ".png");
				lista.ver(0)->Location = System::Drawing::Point(nx, ny);
			}
			else {
				//asigna pos x anterior
				lista.ver(t)->Location = System::Drawing::Point((lista.ver(t - 1)->Location.X), (lista.ver(t)->Location.Y));
				//asigna pos y anterior
				lista.ver(t)->Location = System::Drawing::Point((lista.ver(t)->Location.X), (lista.ver(t - 1)->Location.Y));
			}
		} 
		//CHOQUES CUANDO COME
		for (int cont = 0; cont < i; cont++) {


			if (lista.ver(cont)->Bounds.IntersectsWith(comida->Bounds)) {

				this->Controls->Remove(comida);
				tiempo = timer1->Interval;
				if (tiempo > 1) { timer1->Interval = tiempo - 30; }
				crearComida();
				crearGusano(lista.ver(i - 1)->Location.X*TamanoPrincipal, lista.ver(i - 1)->Location.Y);
			}
		} 
		//choque con cola
		for (int cont = 1; cont < i; cont++) { 
			if ((lista.ver(0)->Location.X == lista.ver(cont)->Location.X) && (lista.ver(0)->Location.Y == lista.ver(cont)->Location.Y)) {
 
				for (int x = cont; x < i; x++) {
					this->Controls->Remove(lista.ver(x));
					lista.eliminarDato(x);
				}
				i = cont; 
			}
		}
		//Coque con paredes
		if (lista.ver(0)->Location.X >= this->Width - 40 || lista.ver(0)->Location.X < -10 || lista.ver(0)->Location.Y >= this->Height - 40 || lista.ver(0)->Location.Y < -10)
		{
			perderJuego(); 
		}
	}
	private: System::Void mover(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		Direccion = ((e->KeyChar == 119 || e->KeyChar == 87) && Direccion != 'D') ? 'U' : Direccion;
		Direccion = ((e->KeyChar == 115 || e->KeyChar == 83) && Direccion != 'U') ? 'D' : Direccion;
		Direccion = ((e->KeyChar == 100 || e->KeyChar == 68) && Direccion != 'L') ? 'R' : Direccion;
		Direccion = ((e->KeyChar == 97 || e->KeyChar == 65) && Direccion != 'R') ? 'L' : Direccion;

	} 
	private: System::Void Gusano_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
