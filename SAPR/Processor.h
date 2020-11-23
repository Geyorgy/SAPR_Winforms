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
	/// Ñâîäêà äëÿ Processor
	/// </summary>
	public ref class Processor : public System::Windows::Forms::Form
	{
	public:
		Processor(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ïğåïğîöåññîğToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïåğåéòèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïğîöåññîğToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îòêğûòüÔàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîñòïğîöåññîğToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ ïåğåéòèToolStripMenuItem1;


	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Processor::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ïğåïğîöåññîğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïåğåéòèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğîöåññîğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîñòïğîöåññîğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ïåğåéòèToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ïğåïğîöåññîğToolStripMenuItem,
					this->ïğîöåññîğToolStripMenuItem, this->ïîñòïğîöåññîğToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(772, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ïğåïğîöåññîğToolStripMenuItem
			// 
			this->ïğåïğîöåññîğToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ïåğåéòèToolStripMenuItem });
			this->ïğåïğîöåññîğToolStripMenuItem->Name = L"ïğåïğîöåññîğToolStripMenuItem";
			this->ïğåïğîöåññîğToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->ïğåïğîöåññîğToolStripMenuItem->Text = L"Ïğåïğîöåññîğ";
			// 
			// ïåğåéòèToolStripMenuItem
			// 
			this->ïåğåéòèToolStripMenuItem->Name = L"ïåğåéòèToolStripMenuItem";
			this->ïåğåéòèToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ïåğåéòèToolStripMenuItem->Text = L"Ïåğåéòè";
			this->ïåğåéòèToolStripMenuItem->Click += gcnew System::EventHandler(this, &Processor::ïåğåéòèToolStripMenuItem_Click);
			// 
			// ïğîöåññîğToolStripMenuItem
			// 
			this->ïğîöåññîğToolStripMenuItem->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ïğîöåññîğToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->îòêğûòüÔàéëToolStripMenuItem });
			this->ïğîöåññîğToolStripMenuItem->Name = L"ïğîöåññîğToolStripMenuItem";
			this->ïğîöåññîğToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->ïğîöåññîğToolStripMenuItem->Text = L"Ïğîöåññîğ";
			// 
			// îòêğûòüÔàéëToolStripMenuItem
			// 
			this->îòêğûòüÔàéëToolStripMenuItem->Name = L"îòêğûòüÔàéëToolStripMenuItem";
			this->îòêğûòüÔàéëToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->îòêğûòüÔàéëToolStripMenuItem->Text = L"Îòêğûòü ôàéë";
			this->îòêğûòüÔàéëToolStripMenuItem->Click += gcnew System::EventHandler(this, &Processor::îòêğûòüÔàéëToolStripMenuItem_Click);
			// 
			// ïîñòïğîöåññîğToolStripMenuItem
			// 
			this->ïîñòïğîöåññîğToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ïåğåéòèToolStripMenuItem1 });
			this->ïîñòïğîöåññîğToolStripMenuItem->Name = L"ïîñòïğîöåññîğToolStripMenuItem";
			this->ïîñòïğîöåññîğToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->ïîñòïğîöåññîğToolStripMenuItem->Text = L"Ïîñòïğîöåññîğ";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ïåğåéòèToolStripMenuItem1
			// 
			this->ïåğåéòèToolStripMenuItem1->Name = L"ïåğåéòèToolStripMenuItem1";
			this->ïåğåéòèToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->ïåğåéòèToolStripMenuItem1->Text = L"Ïåğåéòè";
			this->ïåğåéòèToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Processor::ïåğåéòèToolStripMenuItem1_Click);
			// 
			// Processor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(772, 597);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Processor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ÑÀÏĞ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void îòêğûòüÔàéëToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void ïåğåéòèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void ïåğåéòèToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
