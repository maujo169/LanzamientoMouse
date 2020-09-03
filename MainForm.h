#pragma once
#include "Controladora.h"

namespace LanzamientoConMouse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			abc = gcnew Controladora();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ espacioBuffer;
		BufferedGraphics^ buffer;
		Controladora^ abc;
		int i = 0;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 561);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		espacioBuffer = BufferedGraphicsManager::Current;
		buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		abc->Timer(buffer->Graphics);
		buffer->Render(g);
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		abc->MoverCuadrado(buffer->Graphics, e->KeyCode);
		if (e->KeyCode == Keys::S)
		{
			abc->FinJuegoEscritura();
			this->Close();
		}
	}
	private: System::Void MainForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		abc->Disparo(e->X, e->Y);
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	};
}
