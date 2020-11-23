#pragma once

namespace SAPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PostProcessor
	/// </summary>
	public ref class PostProcessor : public System::Windows::Forms::Form
	{
	public:
		PostProcessor(void)
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
		~PostProcessor()
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
	private: System::Windows::Forms::ToolStripMenuItem^ перейтиToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ постпроцессорToolStripMenuItem;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PostProcessor::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->препроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перейтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->процессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перейтиToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->постпроцессорToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->перейтиToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->перейтиToolStripMenuItem->Text = L"Перейти";
			this->перейтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &PostProcessor::перейтиToolStripMenuItem_Click);
			// 
			// процессорToolStripMenuItem
			// 
			this->процессорToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->перейтиToolStripMenuItem1 });
			this->процессорToolStripMenuItem->Name = L"процессорToolStripMenuItem";
			this->процессорToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->процессорToolStripMenuItem->Text = L"Процессор";
			// 
			// перейтиToolStripMenuItem1
			// 
			this->перейтиToolStripMenuItem1->Name = L"перейтиToolStripMenuItem1";
			this->перейтиToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->перейтиToolStripMenuItem1->Text = L"Перейти";
			this->перейтиToolStripMenuItem1->Click += gcnew System::EventHandler(this, &PostProcessor::перейтиToolStripMenuItem1_Click);
			// 
			// постпроцессорToolStripMenuItem
			// 
			this->постпроцессорToolStripMenuItem->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->постпроцессорToolStripMenuItem->Name = L"постпроцессорToolStripMenuItem";
			this->постпроцессорToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->постпроцессорToolStripMenuItem->Text = L"Постпроцессор";
			// 
			// PostProcessor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(772, 597);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PostProcessor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"САПР";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void перейтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void перейтиToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

};
}
