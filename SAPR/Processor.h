#pragma once

namespace SAPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	int NumberOfSticks = 0;
	double LengthOfConstr;
	double** MassOfSticks;
	double* MassOfHubLoads;
	double* MassOfStickLoads;

	/// <summary>
	/// Сводка для Processor
	/// </summary>
	public ref class Processor : public System::Windows::Forms::Form
	{
	public:
		Processor(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Processor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ препроцессорToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ перейтиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ процессорToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьФайлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ постпроцессорToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->препроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перейтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->процессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->постпроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->препроцессорToolStripMenuItem,
					this->процессорToolStripMenuItem, this->постпроцессорToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(772, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// препроцессорToolStripMenuItem
			// 
			this->препроцессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->перейтиToolStripMenuItem });
			this->препроцессорToolStripMenuItem->Name = L"препроцессорToolStripMenuItem";
			this->препроцессорToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->препроцессорToolStripMenuItem->Text = L"Препроцессор";
			// 
			// перейтиToolStripMenuItem
			// 
			this->перейтиToolStripMenuItem->Name = L"перейтиToolStripMenuItem";
			this->перейтиToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->перейтиToolStripMenuItem->Text = L"Перейти";
			// 
			// процессорToolStripMenuItem
			// 
			this->процессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->открытьФайлToolStripMenuItem });
			this->процессорToolStripMenuItem->Name = L"процессорToolStripMenuItem";
			this->процессорToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->процессорToolStripMenuItem->Text = L"Процессор";
			// 
			// открытьФайлToolStripMenuItem
			// 
			this->открытьФайлToolStripMenuItem->Name = L"открытьФайлToolStripMenuItem";
			this->открытьФайлToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->открытьФайлToolStripMenuItem->Text = L"Открыть файл";
			this->открытьФайлToolStripMenuItem->Click += gcnew System::EventHandler(this, &Processor::открытьФайлToolStripMenuItem_Click);
			// 
			// постпроцессорToolStripMenuItem
			// 
			this->постпроцессорToolStripMenuItem->Name = L"постпроцессорToolStripMenuItem";
			this->постпроцессорToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->постпроцессорToolStripMenuItem->Text = L"Постпроцессор";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Processor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 597);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Processor";
			this->Text = L"Processor";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void открытьФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Text Files|*.txt";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog1->FileName->Length > 0) {
				StreamReader^ openFile = gcnew StreamReader(openFileDialog1->FileName);

				NumberOfSticks = System::Convert::ToInt32(openFile->ReadLine());
				openFile->ReadLine();
				openFile->ReadLine();

				MassOfSticks = new double* [NumberOfSticks];
				for (int i = 0; i < NumberOfSticks; i++) {
					MassOfSticks[i] = new double[6];
					for (int j = 0; j < 6; j++) {
						MassOfSticks[i][j] = System::Convert::ToDouble(openFile->ReadLine());
					}
				}

				MassOfStickLoads = new double[NumberOfSticks];
				for (int i = 0; i < NumberOfSticks; i++) {
					MassOfStickLoads[i] = System::Convert::ToDouble(openFile->ReadLine());
				}

				MassOfHubLoads = new double[NumberOfSticks + 1];
				for (int i = 0; i < NumberOfSticks + 1; i++) {
					MassOfHubLoads[i] = System::Convert::ToDouble(openFile->ReadLine());
				}

				openFile->Close();
			}
		}
	}
};
}
