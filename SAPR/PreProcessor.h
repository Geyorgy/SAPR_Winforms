#pragma once
//#include <exception>
//#include "stdAfx.h"


namespace SAPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	const int LPixel = 120;

	extern int NumberOfSticks = 0;
	extern double LengthOfConstr;
	extern double** MassOfSticks;
	extern double* MassOfHubLoads;
	extern double* MassOfStickLoads;

	bool flagTextChangedByNumeric = 0;
	bool flagTextChangedByMinus = 0;
	bool flagProgrammStarted = 1;





	/// <summary>
	/// Сводка для CAD
	/// </summary>
	public ref class PreProcessor : public System::Windows::Forms::Form
	{
	public:
		PreProcessor(void)
		{
			InitializeComponent();
			if (NumberOfSticks) {
				textBox1->Text = System::Convert::ToString(NumberOfSticks);
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PreProcessor()
		{
			if (components)
			{
				delete components;
			}
		}












	private: System::Windows::Forms::Button^ button1;




	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox1;





	private: System::Windows::Forms::Panel^ panel3;


	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ препроцессорToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ процессорToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ перейтиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ постпроцессорToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ перейтиToolStripMenuItem1;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label13;












	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PreProcessor::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->препроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->процессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перейтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->постпроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перейтиToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(279, 323);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(215, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Построить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PreProcessor::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(18, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(18, 96);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(116, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"L";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(39, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(97, 20);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 41);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Количество стержней";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(181, 69);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(91, 17);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Опора слева";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Enabled = false;
			this->checkBox2->Location = System::Drawing::Point(181, 93);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(97, 17);
			this->checkBox2->TabIndex = 14;
			this->checkBox2->Text = L"Опора справа";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(339, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 16);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Распределенные нагрузки";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(567, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(192, 16);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Направленные нагрузки";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Location = System::Drawing::Point(329, 37);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1, 265);
			this->panel1->TabIndex = 17;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel2->Location = System::Drawing::Point(555, 37);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1, 265);
			this->panel2->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Длина стержня";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(21, 150);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(277, 136);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры стержня";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(146, 99);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 13);
			this->label8->TabIndex = 24;
			this->label8->Text = L"E";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(172, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 26);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Допускаемое\r\n  напряжение";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(160, 96);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 22;
			this->textBox5->Text = L"0";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox5_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(160, 53);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 21;
			this->textBox4->Text = L"0";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox4_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->MinimumSize = System::Drawing::Size(680, 200);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(680, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->AutoScroll = true;
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Location = System::Drawing::Point(46, 352);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(680, 215);
			this->panel3->TabIndex = 22;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Location = System::Drawing::Point(384, 90);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 25;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &PreProcessor::numericUpDown1_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(401, 74);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Номер стержня";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(401, 123);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(84, 13);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Значение силы";
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(384, 139);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(120, 20);
			this->textBox6->TabIndex = 25;
			this->textBox6->Text = L"0";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(606, 139);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(120, 20);
			this->textBox7->TabIndex = 29;
			this->textBox7->Text = L"0";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &PreProcessor::textBox7_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(623, 123);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 13);
			this->label11->TabIndex = 32;
			this->label11->Text = L"Значение силы";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(632, 74);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(67, 13);
			this->label12->TabIndex = 31;
			this->label12->Text = L"Номер узла";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Enabled = false;
			this->numericUpDown2->Location = System::Drawing::Point(606, 90);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 30;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &PreProcessor::numericUpDown2_ValueChanged);
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
			this->menuStrip1->TabIndex = 33;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// препроцессорToolStripMenuItem
			// 
			this->препроцессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->открытьToolStripMenuItem,
					this->сохранитьToolStripMenuItem
			});
			this->препроцессорToolStripMenuItem->Name = L"препроцессорToolStripMenuItem";
			this->препроцессорToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->препроцессорToolStripMenuItem->Text = L"Препроцессор";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть файл";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &PreProcessor::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить файл";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &PreProcessor::сохранитьToolStripMenuItem_Click);
			// 
			// процессорToolStripMenuItem
			// 
			this->процессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->перейтиToolStripMenuItem });
			this->процессорToolStripMenuItem->Name = L"процессорToolStripMenuItem";
			this->процессорToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->процессорToolStripMenuItem->Text = L"Процессор";
			// 
			// перейтиToolStripMenuItem
			// 
			this->перейтиToolStripMenuItem->Name = L"перейтиToolStripMenuItem";
			this->перейтиToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->перейтиToolStripMenuItem->Text = L"Перейти";
			// 
			// постпроцессорToolStripMenuItem
			// 
			this->постпроцессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->перейтиToolStripMenuItem1 });
			this->постпроцессорToolStripMenuItem->Name = L"постпроцессорToolStripMenuItem";
			this->постпроцессорToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->постпроцессорToolStripMenuItem->Text = L"Постпроцессор";
			// 
			// перейтиToolStripMenuItem1
			// 
			this->перейтиToolStripMenuItem1->Name = L"перейтиToolStripMenuItem1";
			this->перейтиToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->перейтиToolStripMenuItem1->Text = L"Перейти";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"SAPRDataProcessor.txt";
			this->openFileDialog1->RestoreDirectory = true;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->RestoreDirectory = true;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Enabled = false;
			this->numericUpDown3->Location = System::Drawing::Point(39, 102);
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(97, 20);
			this->numericUpDown3->TabIndex = 34;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &PreProcessor::numericUpDown3_ValueChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(44, 86);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(87, 13);
			this->label13->TabIndex = 35;
			this->label13->Text = L"Номер стержня";
			// 
			// PreProcessor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(772, 597);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PreProcessor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"САПР";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (!checkBox1->Checked && !checkBox2->Checked) {
			MessageBox::Show("Укажите хотя бы одну опору", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		for (int i = 0; i < NumberOfSticks; i++) {
			if (MassOfSticks[i][2] == 0){
				MessageBox::Show("В стержне №" + (i + 1) + " длина L не задана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][3] == 0) {
				MessageBox::Show("В стержне №" + (i + 1) + " коэффициент А не задан", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][4] == 0) {
				MessageBox::Show("В стержне №" + (i + 1) + " допускаемое напряжение не задано", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][5] == 0) {
				MessageBox::Show("В стержне №" + (i + 1) + " модуль упругости Е не задан", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		for (int i = 0; i < NumberOfSticks; i++) {
			if (MassOfSticks[i][2] < 0) {
				MessageBox::Show("Длина L не может быть отрицательной (Стержень №" + (i + 1) + ")", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][3] < 0) {
				MessageBox::Show("Коэффициент А не может быть отрицательным (Стержень №" + (i + 1) + ")", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][4] < 0) {
				MessageBox::Show("Допускаемое напряжение не может быть отрицательным (Стержень №" + (i + 1) + ")", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (MassOfSticks[i][5] < 0) {
				MessageBox::Show("Модуль упругости Е не может быть отрицательным (Стержень №" + (i + 1) + ")", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		Bitmap^ bmp = gcnew Bitmap(LengthOfConstr + 120, 200);
		Graphics^ graph = Graphics::FromImage(bmp);

		Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ pillarPen = gcnew Pen(Color::Black, 1.0f);
		Pen^ RedLoadsPen = gcnew Pen(Color::Red, 1.0f);
		Pen^ BlueLoadsPen = gcnew Pen(Color::Blue, 1.0f);

		array<System::Drawing::Rectangle>^ MassRect = gcnew array<System::Drawing::Rectangle>(NumberOfSticks);
		for (int i = 0; i < NumberOfSticks; i++) {
			MassRect[i] = { System::Drawing::Rectangle(MassOfSticks[i][0], MassOfSticks[i][1], MassOfSticks[i][2] * LPixel, 24 + MassOfSticks[i][3] * 18) };
		}

		graph->DrawRectangles(blackPen, MassRect);

		if (checkBox1->Checked) {
			graph->DrawLine(pillarPen, 59, 61, 59, 141);
			for (int i = 0; i < 21; i++) {
				graph->DrawLine(pillarPen, 58, 61 + i*4, 53, 63 + i*4);
			}
		}

		if (checkBox2->Checked) {
			graph->DrawLine(pillarPen, 61 + LengthOfConstr, 61, 61 + LengthOfConstr, 141);
			for (int i = 0; i < 21; i++) {
				graph->DrawLine(pillarPen, 62 + System::Convert::ToInt32(LengthOfConstr), 61 + i * 4, 66 + System::Convert::ToInt32(LengthOfConstr), 59 + i * 4);
			}
		}
		//Отрисовка распределенных нагрузок
		for (int i = 0; i < NumberOfSticks; i++) {
			if (MassOfStickLoads[i] != 0) {
				if (MassOfStickLoads[i] > 0) {
					for (int j = 0; j < 6 * MassOfSticks[i][2]; j++) {
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 12 + j * 20, 96, MassOfSticks[i][0] + 13 + j * 20, 96);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 13 + j * 20, 97, MassOfSticks[i][0] + 15 + j * 20, 97);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 14 + j * 20, 98, MassOfSticks[i][0] + 17 + j * 20, 98);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 15 + j * 20, 99, MassOfSticks[i][0] + 19 + j * 20, 99);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + j * 20, 100, MassOfSticks[i][0] + 20 + j * 20, 100); // середина!
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 15 + j * 20, 101, MassOfSticks[i][0] + 19 + j * 20, 101);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 14 + j * 20, 102, MassOfSticks[i][0] + 17 + j * 20, 102);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 13 + j * 20, 103, MassOfSticks[i][0] + 15 + j * 20, 103);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + 12 + j * 20, 104, MassOfSticks[i][0] + 13 + j * 20, 104);
					}
				}
				else {
					for (int j = 5 * MassOfSticks[i][2]; j >= 0; j--)
					{
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 12 - j * 20, 96, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 13 - j * 20, 96);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 13 - j * 20, 97, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 15 - j * 20, 97);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 14 - j * 20, 98, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 17 - j * 20, 98);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 15 - j * 20, 99, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 19 - j * 20, 99);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - j * 20, 100, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 20 - j * 20, 100); // середина!
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 15 - j * 20, 101, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 19 - j * 20, 101);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 14 - j * 20, 102, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 17 - j * 20, 102);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 13 - j * 20, 103, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 15 - j * 20, 103);
						graph->DrawLine(BlueLoadsPen, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 12 - j * 20, 104, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel - 13 - j * 20, 104);
					}
				}
			}
		}

		//Отрисовка сосредоточенных нагрузок
		for (int i = 0; i < NumberOfSticks + 1; i++){
			if (MassOfHubLoads[i] != 0) {
				if (i != NumberOfSticks) {
					if (MassOfHubLoads[i] > 0) {
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 27, 88, MassOfSticks[i][0] + 28, 88);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 27, 89, MassOfSticks[i][0] + 30, 89);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 28, 90, MassOfSticks[i][0] + 32, 90);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 29, 91, MassOfSticks[i][0] + 34, 91);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 30, 92, MassOfSticks[i][0] + 36, 92);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 31, 93, MassOfSticks[i][0] + 38, 93);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 32, 94, MassOfSticks[i][0] + 40, 94);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 33, 95, MassOfSticks[i][0] + 42, 95);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 96, MassOfSticks[i][0] + 44, 96);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 97, MassOfSticks[i][0] + 46, 97);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 98, MassOfSticks[i][0] + 48, 98);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 99, MassOfSticks[i][0] + 50, 99);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 100, MassOfSticks[i][0] + 52, 100); // середина!
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 101, MassOfSticks[i][0] + 50, 101);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 102, MassOfSticks[i][0] + 48, 102);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 103, MassOfSticks[i][0] + 46, 103);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 104, MassOfSticks[i][0] + 44, 104);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 33, 105, MassOfSticks[i][0] + 42, 105);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 32, 106, MassOfSticks[i][0] + 40, 106);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 31, 107, MassOfSticks[i][0] + 38, 107);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 30, 108, MassOfSticks[i][0] + 36, 108);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 29, 109, MassOfSticks[i][0] + 34, 109);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 28, 110, MassOfSticks[i][0] + 32, 110);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 27, 111, MassOfSticks[i][0] + 30, 111);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] + 27, 112, MassOfSticks[i][0] + 28, 112);
					}
					else {
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 27, 88, MassOfSticks[i][0] - 28, 88);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 27, 89, MassOfSticks[i][0] - 30, 89);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 28, 90, MassOfSticks[i][0] - 32, 90);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 29, 91, MassOfSticks[i][0] - 34, 91);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 30, 92, MassOfSticks[i][0] - 36, 92);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 31, 93, MassOfSticks[i][0] - 38, 93);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 32, 94, MassOfSticks[i][0] - 40, 94);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 33, 95, MassOfSticks[i][0] - 42, 95);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 96, MassOfSticks[i][0] - 44, 96);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 97, MassOfSticks[i][0] - 46, 97);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 98, MassOfSticks[i][0] - 48, 98);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 99, MassOfSticks[i][0] - 50, 99);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 100, MassOfSticks[i][0] - 52, 100); // середина!
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 101, MassOfSticks[i][0] - 50, 101);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 102, MassOfSticks[i][0] - 48, 102);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 103, MassOfSticks[i][0] - 46, 103);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0], 104, MassOfSticks[i][0] - 44, 104);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 33, 105, MassOfSticks[i][0] - 42, 105);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 32, 106, MassOfSticks[i][0] - 40, 106);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 31, 107, MassOfSticks[i][0] - 38, 107);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 30, 108, MassOfSticks[i][0] - 36, 108);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 29, 109, MassOfSticks[i][0] - 34, 109);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 28, 110, MassOfSticks[i][0] - 32, 110);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 27, 111, MassOfSticks[i][0] - 30, 111);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i][0] - 27, 112, MassOfSticks[i][0] - 28, 112);
					}
				}
				else {
					if (MassOfHubLoads[i] > 0) {
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 27, 88, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 28, 88);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 27, 89, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 30, 89);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 28, 90, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 32, 90);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 29, 91, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 34, 91);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 30, 92, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 36, 92);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 31, 93, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 38, 93);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 32, 94, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 40, 94);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 33, 95, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 42, 95);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 96, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 44, 96);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 97, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 46, 97);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 98, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 48, 98);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 99, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 50, 99);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 100, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 52, 100); // середина!
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 101, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 50, 101);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 102, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 48, 102);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 103, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 46, 103);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 104, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 44, 104);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 33, 105, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 42, 105);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 32, 106, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 40, 106);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 31, 107, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 38, 107);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 30, 108, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 36, 108);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 29, 109, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 34, 109);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 28, 110, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 32, 110);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 27, 111, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 30, 111);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 27, 112, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel + 28, 112);
					}
					else {
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 27, 88, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 28, 88);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 27, 89, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 30, 89);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 28, 90, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 32, 90);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 29, 91, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 34, 91);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 30, 92, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 36, 92);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 31, 93, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 38, 93);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 32, 94, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 40, 94);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 33, 95, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 42, 95);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 96, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 44, 96);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 97, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 46, 97);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 98, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 48, 98);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 99, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 50, 99);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 100, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 52, 100); // середина!
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 101, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 50, 101);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 102, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 48, 102);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 103, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 46, 103);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel, 104, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 44, 104);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 33, 105, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 42, 105);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 32, 106, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 40, 106);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 31, 107, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 38, 107);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 30, 108, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 36, 108);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 29, 109, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 34, 109);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 28, 110, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 32, 110);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 27, 111, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 30, 111);
						graph->DrawLine(RedLoadsPen, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 27, 112, MassOfSticks[i - 1][0] + MassOfSticks[i - 1][2] * LPixel - 28, 112);
					}
				}
			}
		}

		/*Добавить подписи к конструкции!!*/

		pictureBox1->Image = bmp;
	}

	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox3->Text == "-") {
			MessageBox::Show("Значение длины стержня не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			flagTextChangedByMinus = 1;
			textBox3->Text = "0";
			return;
		}

		if (textBox3->Text == "0" &&  flagTextChangedByMinus != 1) {
			MessageBox::Show("Значение длины стержня не может быть нулевым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (textBox3->Text == "0") {
			flagTextChangedByMinus = 0;
			return;
		}
		
		if (textBox3->Text == System::String::Empty) {
			return;
		}

		checkBox1->Enabled = true;
		checkBox2->Enabled = true;
		numericUpDown1->Enabled = true;
		numericUpDown2->Enabled = true;
		numericUpDown3->Enabled = true;
		textBox1->Enabled = true;
		textBox2->Enabled = true;
		textBox4->Enabled = true;
		textBox5->Enabled = true;
		textBox6->Enabled = true;
		textBox7->Enabled = true;
		button1->Enabled = true;

		NumberOfSticks = System::Convert::ToInt32(textBox3->Text);

		numericUpDown3->Maximum = NumberOfSticks;

		MassOfSticks = new double* [NumberOfSticks];
		for (int i = 0; i < NumberOfSticks; i++) {
			MassOfSticks[i] = new double[6];
			for (int j = 0; j < 6; j++)
				MassOfSticks[i][j] = 0;
		}

		MassOfStickLoads = new double[NumberOfSticks];
		for (int i = 0; i < NumberOfSticks; i++)
			MassOfStickLoads[i] = 0;

		MassOfHubLoads = new double[NumberOfSticks + 1];
		for (int i = 0; i < NumberOfSticks + 1; i++)
			MassOfHubLoads[i] = 0;

		numericUpDown1->Maximum = NumberOfSticks;
		numericUpDown2->Maximum = NumberOfSticks + 1;

		flagTextChangedByNumeric = 1;
		textBox1->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][2]);
		textBox2->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][3]);
		textBox4->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][4]);
		textBox5->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][5]);
		textBox6->Text = System::Convert::ToString(MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1]);
		textBox7->Text = System::Convert::ToString(MassOfHubLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1]);
		numericUpDown1->Value = 1;
		numericUpDown2->Value = 1;
		numericUpDown3->Value = 1;

		
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox1->Text == "-") {
			MessageBox::Show("Значение длины стержня не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			flagTextChangedByMinus = 1;
			textBox1->Text = "0";
			return;
		}

		if (textBox1->Text == "0" && flagTextChangedByNumeric != 1 && flagTextChangedByMinus != 1) {
			MessageBox::Show("Значение длины стержня не может быть нулевым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (textBox1->Text == "0") {
			flagTextChangedByMinus = 0;
			return;
		}

		if (textBox1->Text == System::String::Empty) {
			return;
		}

		/*try
		{
			System::Convert::ToInt32(textBox1->Text);
		}
		catch (const std::exception& ex)
		{
			MessageBox::Show("Введите числовое значение", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox1->Text = "0";
			return;
		}

		if (!(textBox1->Text == "0" || textBox1->Text == "1" || textBox1->Text == "2" || textBox1->Text == "3" || textBox1->Text == "4" || textBox1->Text == "5" || textBox1->Text == "6" || textBox1->Text == "7" || textBox1->Text == "8" || textBox1->Text == "9")) {
			MessageBox::Show("Введите числовое значение", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox1->Text = "0";
			return;
		}*/

		double counterX = 0;
		double counterXPred = 0;
		for (int i = 0; i < System::Convert::ToInt32(numericUpDown3->Value) - 1; i++) {
			counterX += MassOfSticks[i][2] * LPixel;
		}
		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][0] = 60 + counterX;
		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][2] = System::Convert::ToDouble(textBox1->Text);
		for (int i = System::Convert::ToInt32(numericUpDown3->Value); i < NumberOfSticks; i++) {
			if (MassOfSticks[i][2] != 0) {
				counterXPred = 0;
				for (int j = 0; j < i; j++) {
					counterXPred += MassOfSticks[j][2] * LPixel;
				}
				MassOfSticks[i][0] = 60 + counterXPred;
			}
		}

		LengthOfConstr = 0;
		for (int i = 0; i < NumberOfSticks; i++)
			LengthOfConstr += MassOfSticks[i][2] * LPixel;
	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox2->Text == "-") {
			MessageBox::Show("Значение площади поперечного сечения не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			flagTextChangedByMinus = 1;
			textBox2->Text = "0";
			return;
		}

		if (textBox2->Text == "0" && flagTextChangedByNumeric != 1 && flagTextChangedByMinus != 1) {
			MessageBox::Show("Значение площади поперечного сечения не может быть нулевым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (textBox2->Text == "0") {
			flagTextChangedByMinus = 0;
			return;
		}

		if (textBox2->Text == System::String::Empty) {
			return;
		}

		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][1] = 100 - (12 + System::Convert::ToDouble(textBox2->Text) * 9);
		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][3] = System::Convert::ToDouble(textBox2->Text);
	}

	private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

		flagTextChangedByNumeric = 1;
		
		textBox1->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][2]);
		textBox2->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][3]);
		textBox4->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][4]);
		textBox5->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][5]);
	}

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox4->Text == "-") {
			MessageBox::Show("Значение допускаемого напряжения не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			flagTextChangedByMinus = 1;
			textBox4->Text = "0";
			return;
		}

		if (textBox4->Text == "0" && flagTextChangedByNumeric != 1 && flagTextChangedByMinus != 1) {
			MessageBox::Show("Значение допускаемого напряжения не может быть нулевым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (textBox4->Text == "0") {
			flagTextChangedByMinus = 0;
			return;
		}

		if (textBox4->Text == System::String::Empty) {
			return;
		}

		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][4] = System::Convert::ToDouble(textBox4->Text);
	}

	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox5->Text == "-") {
			MessageBox::Show("Значение модуля упругости не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			flagTextChangedByMinus = 1;
			textBox5->Text = "0";
			return;
		}

		if (textBox5->Text == "0" && flagTextChangedByNumeric != 1 && flagTextChangedByMinus != 1) {
			MessageBox::Show("Значение модуля упругости не может быть нулевым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (textBox5->Text == "0") {
			flagTextChangedByMinus = 0;
			flagTextChangedByNumeric = 0;
			return;
		}

		if (textBox5->Text == System::String::Empty) {
			return;
		}

		MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][5] = System::Convert::ToDouble(textBox5->Text);

		
	}

	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox6->Text == "-") {
			return;
		}

		MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1] = System::Convert::ToDouble(textBox6->Text);
	}

	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox7->Text == "-") {
			return;
		}

		MassOfHubLoads[System::Convert::ToInt32(numericUpDown2->Value) - 1] = System::Convert::ToDouble(textBox7->Text);
	}

	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		textBox6->Text = System::Convert::ToString(MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1]);
	}

	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		textBox7->Text = System::Convert::ToString(MassOfHubLoads[System::Convert::ToInt32(numericUpDown2->Value) - 1]);
	}
			
	private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Text Files|*.txt";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			if (openFileDialog1->FileName->Length > 0) {
				StreamReader^ openFile = gcnew StreamReader(openFileDialog1->FileName);

				textBox3->Text = openFile->ReadLine();
				checkBox1->Checked = System::Convert::ToInt32(openFile->ReadLine());
				checkBox2->Checked = System::Convert::ToInt32(openFile->ReadLine());
				for (int i = 0; i < NumberOfSticks; i++) {
					for (int j = 0; j < 6; j++) {
						MassOfSticks[i][j] = System::Convert::ToDouble(openFile->ReadLine());
					}
				}
				for (int i = 0; i < NumberOfSticks; i++) {
					MassOfStickLoads[i] = System::Convert::ToDouble(openFile->ReadLine());
				}
				for (int i = 0; i < NumberOfSticks + 1; i++) {
					MassOfHubLoads[i] = System::Convert::ToDouble(openFile->ReadLine());
				}

				openFile->Close();

				numericUpDown1->Value = 2;
				numericUpDown1->Value = 1;
				numericUpDown2->Value = 2;
				numericUpDown2->Value = 1;
				numericUpDown3->Value = 2;
				numericUpDown3->Value = 1;
			}
		}
	}

	private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//saveFileDialog1->InitialDirectory = "C:";
		saveFileDialog1->FileName = "SAPRDataProcessor";
		saveFileDialog1->Filter = "Text Files|*.txt";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (saveFileDialog1->FileName->Length > 0) {
				StreamWriter^ saveFile = gcnew StreamWriter(saveFileDialog1->FileName);

				saveFile->WriteLine(NumberOfSticks);
				saveFile->WriteLine(System::Convert::ToInt32(checkBox1->Checked));
				saveFile->WriteLine(System::Convert::ToInt32(checkBox2->Checked));
				for (int i = 0; i < NumberOfSticks; i++) {
					for (int j = 0; j < 6; j++)	{
						saveFile->WriteLine(MassOfSticks[i][j]);
					}
				}
				for (int i = 0; i < NumberOfSticks; i++) {
					saveFile->WriteLine(MassOfStickLoads[i]);
				}
				for (int i = 0; i < NumberOfSticks + 1; i++) {
					saveFile->WriteLine(MassOfHubLoads[i]);
				}
				
				saveFile->Close();
			}
		}

	}
	};
}
