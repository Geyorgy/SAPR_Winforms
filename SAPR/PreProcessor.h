#pragma once

namespace SAPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	/// <summary>
	/// Сводка для CAD
	/// </summary>
	public ref class PreProcessor : public System::Windows::Forms::Form
	{
	public:
		String^ DataFileName;
		bool flagComeFromOutside = 0;
	public:
		PreProcessor(void)
		{
			InitializeComponent();
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
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &PreProcessor::checkBox1_CheckedChanged);
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
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &PreProcessor::checkBox2_CheckedChanged);
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
			this->label5->Location = System::Drawing::Point(556, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(216, 16);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Сосредоточенные нагрузки";
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
			this->препроцессорToolStripMenuItem->BackColor = System::Drawing::SystemColors::InactiveCaption;
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
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть файл";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &PreProcessor::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(165, 22);
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
			this->перейтиToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->перейтиToolStripMenuItem->Text = L"Перейти";
			this->перейтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &PreProcessor::перейтиToolStripMenuItem_Click);
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
			this->перейтиToolStripMenuItem1->Size = System::Drawing::Size(121, 22);
			this->перейтиToolStripMenuItem1->Text = L"Перейти";
			this->перейтиToolStripMenuItem1->Click += gcnew System::EventHandler(this, &PreProcessor::перейтиToolStripMenuItem1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"SAPRDataPreProcessor.txt";
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
			this->Load += gcnew System::EventHandler(this, &PreProcessor::PreProcessor_Load);
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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e);
			
	private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e, String^ DataFileName);

	private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void перейтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void перейтиToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PreProcessor_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	};
}
