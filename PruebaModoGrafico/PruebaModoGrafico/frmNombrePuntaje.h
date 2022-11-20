#pragma once
#include"ListaSimple.h"
#include"frmPuntaje.h"
//#include "Principall.h"
namespace PruebaModoGrafico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for frmNombrePuntaje
	/// </summary>
	public ref class frmNombrePuntaje : public System::Windows::Forms::Form
	{
		int puntos;
	public:
		frmNombrePuntaje(int val)
		{
			puntos = val;
			InitializeComponent(); 
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmNombrePuntaje()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOk;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtString;



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
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtString = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnOk
			// 
			this->btnOk->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOk->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOk->ForeColor = System::Drawing::Color::Navy;
			this->btnOk->Location = System::Drawing::Point(183, 111);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(112, 56);
			this->btnOk->TabIndex = 5;
			this->btnOk->Text = L"Aceptar";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &frmNombrePuntaje::btnOk_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Navy;
			this->label1->Location = System::Drawing::Point(91, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(312, 28);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ingrese el Nombre del Jugador:";
			// 
			// txtString
			// 
			this->txtString->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtString->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtString->Location = System::Drawing::Point(149, 58);
			this->txtString->MaxLength = 15;
			this->txtString->Name = L"txtString";
			this->txtString->Size = System::Drawing::Size(182, 35);
			this->txtString->TabIndex = 3;
			// 
			// frmNombrePuntaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 179);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtString);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmNombrePuntaje";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmNombrePuntaje";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion  
	private: String^ punt;
	private: System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e) {
		punt = puntos.ToString();
		StreamWriter^ sw = File::AppendText("Datos SNAKE.txt");
	 
				sw->WriteLine(String::Concat("=>", "\t\t", txtString->Text, "\t\t\t", punt));
		   
		txtString->Text = "";
		sw->Close();
		Close();
	}
 
};
}
