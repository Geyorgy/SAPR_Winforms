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
	/// ������ ��� Processor
	/// </summary>
	public ref class Processor : public System::Windows::Forms::Form
	{
	public:
		Processor(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->������������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(772, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�������ToolStripMenuItem });
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->������������ToolStripMenuItem->Text = L"������������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�����������ToolStripMenuItem });
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�����������ToolStripMenuItem->Text = L"������� ����";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Processor::�����������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->�������������ToolStripMenuItem->Text = L"�������������";
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
	private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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
