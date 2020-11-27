#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"

using namespace SAPR;

extern int NumberOfSticks;
extern double LengthOfConstr;
extern double** MassOfSticks;
extern double* MassOfHubLoads;
extern double* MassOfStickLoads;
extern int LeftPillar;
extern int RightPillar;

System::Void SAPR::Processor::открытьФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	RTBFile->Clear();
	RTBLogs->Clear();

	openFileDialog1->Filter = "Text Files|*.txt";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (openFileDialog1->FileName->Length > 0) {

			DataFileName = openFileDialog1->FileName;
			StreamReader^ openFile = gcnew StreamReader(DataFileName);

			NumberOfSticks = System::Convert::ToInt32(openFile->ReadLine());
			LeftPillar = System::Convert::ToInt32(openFile->ReadLine());
			RightPillar = System::Convert::ToInt32(openFile->ReadLine());

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

	RTBLogs->AppendText("Данные введены\n");
	RTBFile->AppendText("Количество стержней: " + System::Convert::ToString(NumberOfSticks) + "\n\n");

	if (LeftPillar)
	{
		RTBFile->AppendText("Опора слева\n");
	}

	if (RightPillar)
	{
		RTBFile->AppendText("Опора справа\n");
	}

	RTBFile->AppendText("\n");

	RTBFile->AppendText("Характеристика стержней\n");
	for (int i = 0; i < NumberOfSticks; i++) {
		RTBFile->AppendText("Стержень №" + (i + 1) + "\n");
		RTBFile->AppendText("Длина стержня: " + MassOfSticks[i][2] + " L\n");
		RTBFile->AppendText("Площадь поперечного сечения: " + MassOfSticks[i][3] + " A\n");
		RTBFile->AppendText("Допускаемое напряжение: " + MassOfSticks[i][4] + " МПа\n");
		RTBFile->AppendText("Модуль успругости: " + MassOfSticks[i][5] + " МПа\n\n");
	}

	RTBFile->AppendText("Распределенные нагрузки\n");
	for (int i = 0; i < NumberOfSticks; i++) {
		if (MassOfStickLoads[i])
			RTBFile->AppendText("Стержень №" + (i + 1) + ": " + MassOfStickLoads[i] + " q\n");
	}
	RTBFile->AppendText("\n");

	RTBFile->AppendText("Сосредоточенные нагрузки\n");
	for (int i = 0; i < NumberOfSticks + 1; i++) {
		if (MassOfHubLoads[i])
			RTBFile->AppendText("Глобальный узел №" + (i + 1) + ": " + MassOfHubLoads[i] + " qL\n");
	}

	for (int i = 0; i < NumberOfSticks; i++) {
		for (int j = 0; j < 6; j++)
		{
			if (MassOfSticks[i][j] == 0) {
				RTBLogs->AppendText("Обнаружены некорректные данные\nПожалуйста, устраните ошибки, прежде чем продолжить расчет\n");
				return System::Void();
			}
		}
	}
	RTBLogs->AppendText("Ошибок не найдено\nОжидание дальнейшей команды...\n\n");

	return System::Void();
}

System::Void SAPR::Processor::перейтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PreProcessor PreProcessor;
	PreProcessor.DataFileName = DataFileName;
	PreProcessor.flagComeFromOutside = 1;
	PreProcessor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::Processor::перейтиToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
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
				if (MessageBox::Show("Как минимум один из параметров " + (i + 1) + "-го стержня не задан.  Перейти в препроцессор для редактирования?", "Ошибка", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {
					this->Hide();
					SAPR::PreProcessor PreProcessor;
					PreProcessor.DataFileName = DataFileName;
					PreProcessor.flagComeFromOutside = 1;
					PreProcessor.ShowDialog();
					this->Close();
					return System::Void();
				}
			}
		}
	}
	return System::Void();
}

System::Void SAPR::Processor::Processor_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberOfSticks == 0){
		RTBLogs->AppendText("Ожидание ввода данных...\n");
	}
	else{
		RTBLogs->AppendText("Данные введены\n");
		RTBFile->AppendText("Количество стержней: " + System::Convert::ToString(NumberOfSticks) + "\n\n");

		if (LeftPillar)
		{
			RTBFile->AppendText("Опора слева\n");
		}

		if (RightPillar)
		{
			RTBFile->AppendText("Опора справа\n");
		}

		RTBFile->AppendText("\n");

		RTBFile->AppendText("Характеристика стержней\n");
		for (int i = 0; i < NumberOfSticks; i++) {
			RTBFile->AppendText("Стержень №" + (i + 1) + "\n");
			RTBFile->AppendText("Длина стержня: " + MassOfSticks[i][2] + " L\n");
			RTBFile->AppendText("Площадь поперечного сечения: " + MassOfSticks[i][3] + " A\n");
			RTBFile->AppendText("Допускаемое напряжение: " + MassOfSticks[i][4] + " МПа\n");
			RTBFile->AppendText("Модуль успругости: " + MassOfSticks[i][5] + " МПа\n\n");
		}

		RTBFile->AppendText("Распределенные нагрузки\n");
		for (int i = 0; i < NumberOfSticks; i++) {
			if (MassOfStickLoads[i])
				RTBFile->AppendText("Стержень №" + (i + 1) + ": " + MassOfStickLoads[i] + " q\n");
		}
		RTBFile->AppendText("\n");

		RTBFile->AppendText("Сосредоточенные нагрузки\n");
		for (int i = 0; i < NumberOfSticks + 1; i++) {
			if (MassOfHubLoads[i])
				RTBFile->AppendText("Глобальный узел №" + (i + 1) + ": " + MassOfHubLoads[i] + " qL\n");
		}

		for (int i = 0; i < NumberOfSticks; i++){
			for (int j = 0; j < 6; j++)
			{
				if (MassOfSticks[i][j] == 0) {
					RTBLogs->AppendText("Обнаружены некорректные данные\nПожалуйста, устраните ошибки, прежде чем продолжить расчет\n");
					return System::Void();
				}
			}
		}
		RTBLogs->AppendText("Ошибок не найдено\nОжидание дальнейшей команды...\n\n");
	}
	return System::Void();
}
