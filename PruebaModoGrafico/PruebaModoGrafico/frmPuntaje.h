#pragma once

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
	/// Summary for frmPuntaje
	/// </summary>
	public ref class frmPuntaje : public System::Windows::Forms::Form
	{
	public:
		frmPuntaje(void)
		{
			InitializeComponent(); 
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPuntaje()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnSalir;
	protected:
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPuntaje::typeid));
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSalir
			// 
			this->btnSalir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.BackgroundImage")));
			this->btnSalir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSalir->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(207, 264);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(100, 42);
			this->btnSalir->TabIndex = 5;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &frmPuntaje::btnSalir_Click);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(52, 46);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(401, 166);
			this->listBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Location = System::Drawing::Point(24, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 26);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Puntajes";
			// 
			// frmPuntaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(489, 311);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmPuntaje";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmPuntaje";
			this->Load += gcnew System::EventHandler(this, &frmPuntaje::frmPuntaje_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmPuntaje_Load(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		listBox1->Items->Add("\t\tNOMBRES\t\tPUNTAJES\t\t");

		if (File::Exists("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/Datos SNAKE.txt")) {
			StreamReader^ sr = File::OpenText("C:/Users/Home/Desktop/ESPE MATERIAS/CUARTO NIVEL/ESTRUCTURA DE DATOS/PROYECTO PARCIAL 1/Datos SNAKE.txt");
			try {
				String^ s = "";
				while (!(sr->EndOfStream)) {
					s = sr->ReadLine();
					listBox1->Items->Add(s); //Imprime la línea completa del Notepad, es decir un registro completo. 
				}
			}
			finally{
				if (sr)
					delete (IDisposable^)sr;
			}
			sr->Close();
		}
	}
	private: System::Void btnSalir_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
};
}
