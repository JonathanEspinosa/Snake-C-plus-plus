#pragma once
#include "Gusano.h";
#include"frmPuntaje.h";
#include"ListaSimple.h";


namespace PruebaModoGrafico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Inicio
	/// </summary>
	public ref class Inicio : public System::Windows::Forms::Form
	{
		ListaSimple lista;
	public:
		Inicio(void)
		{
			InitializeComponent(); 
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnPuntaje;

	protected:

	private: System::Windows::Forms::Button^  button3;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnPuntaje = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(502, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 111);
			this->button1->TabIndex = 0;
			this->button1->Text = L"INICIO";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Inicio::button1_Click_1);
			// 
			// btnPuntaje
			// 
			this->btnPuntaje->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuntaje.BackgroundImage")));
			this->btnPuntaje->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPuntaje->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnPuntaje->Location = System::Drawing::Point(502, 210);
			this->btnPuntaje->Name = L"btnPuntaje";
			this->btnPuntaje->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btnPuntaje->Size = System::Drawing::Size(208, 111);
			this->btnPuntaje->TabIndex = 1;
			this->btnPuntaje->Text = L"PUNTAJE";
			this->btnPuntaje->UseVisualStyleBackColor = true;
			this->btnPuntaje->Click += gcnew System::EventHandler(this, &Inicio::button2_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(502, 364);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(208, 111);
			this->button3->TabIndex = 2;
			this->button3->Text = L"SALIR";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Inicio::button3_Click);
			// 
			// Inicio
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(874, 561);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnPuntaje);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::SystemColors::Highlight;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Inicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SNAKE";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
  
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		Gusano().ShowDialog();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		frmPuntaje().ShowDialog(); 
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void Inicio_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
