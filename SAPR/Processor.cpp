#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"
#include <string>

using namespace SAPR;

extern int NumberOfSticks;
extern double LengthOfConstr;
extern double** MassOfSticks;
extern double* MassOfHubLoads;
extern double* MassOfStickLoads;
extern bool flagComeFromProcessor;
extern std::string FilePath;

System::Void SAPR::Processor::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void SAPR::Processor::îòêðûòüÔàéëToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	openFileDialog1->Filter = "Text Files|*.txt";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (openFileDialog1->FileName->Length > 0) {

			DataFileName = openFileDialog1->FileName;
			StreamReader^ openFile = gcnew StreamReader(DataFileName);

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
	return System::Void();
}

System::Void SAPR::Processor::ïåðåéòèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PreProcessor PreProcessor;
	PreProcessor.DataFileName = DataFileName;
	PreProcessor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::Processor::ïåðåéòèToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PostProcessor PostProcessor;
	PostProcessor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::Processor::button1_Click(System::Object^ sender, System::EventArgs^ e)
{	

	for (int i = 0; i < NumberOfSticks; i++) {
		for (int j = 2; j < 6; j++) {
			if (MassOfSticks[i][j] == 0) {
				if (MessageBox::Show("Êàê ìèíèìóì îäèí èç ïàðàìåòðîâ " + (i + 1) + "-ãî ñòåðæíÿ íå çàäàí.  Ïåðåéòè â ïðåïðîöåññîð äëÿ ðåäàêòèðîâàíèÿ?", "Îøèáêà", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {
					this->Hide();
					SAPR::PreProcessor PreProcessor;
					PreProcessor.DataFileName = DataFileName;
					PreProcessor.ShowDialog();
					this->Close();
					return System::Void();
				}
			}
		}
	}
	return System::Void();
}
