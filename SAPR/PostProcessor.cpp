#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"
#include <cmath>

extern int LPixel;
extern int NumberOfSticks;
extern double** MassOfSticks;
extern double* MassOfHubLoads;
extern double* MassOfStickLoads;
extern int LeftPillar;
extern int RightPillar;
extern double LengthOfConstr;
extern double** MassOfU;

System::Void SAPR::PostProcessor::перейтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PreProcessor PreProcessor;
	PreProcessor.DataFileName = DataFileName;
	PreProcessor.flagComeFromOutside = 1;
	PreProcessor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::PostProcessor::перейтиToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::Processor Processor;
	Processor.DataFileName = DataFileName;
	Processor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::PostProcessor::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MassOfNx != nullptr && MassOfUx != nullptr && MassOfSigmax != nullptr) {
		saveFileDialog1->FileName = "SAPRResults";
		saveFileDialog1->Filter = "Text Files|*.txt";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (saveFileDialog1->FileName->Length > 0) {
				StreamWriter^ saveFile = gcnew StreamWriter(saveFileDialog1->FileName);
				saveFile->WriteLine("Nx");
				for (int i = 0; i < NumberOfSticks; i++) {
					for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
						saveFile->WriteLine(MassOfNx[i][j]);
					}
					saveFile->WriteLine("");
				}
				saveFile->WriteLine("Ux");
				for (int i = 0; i < NumberOfSticks; i++) {
					for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
						saveFile->WriteLine(MassOfUx[i][j]);
					}
					saveFile->WriteLine("");
				}
				saveFile->WriteLine("Sigmax");
				for (int i = 0; i < NumberOfSticks; i++) {
					for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
						saveFile->WriteLine(MassOfSigmax[i][j]);
					}
					saveFile->WriteLine("");
				}
				saveFile->Close();
			}
		}
	}
	else {
		MessageBox::Show("Расчеты не проведены", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	return System::Void();
}

System::Void SAPR::PostProcessor::PostProcessor_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (MassOfNx != nullptr && MassOfUx != nullptr && MassOfSigmax != nullptr) {
		dataGridView1->RowCount = 0;
		int counter = 0;
		double MaxN(0), MinN(0), MaxU(0), MinU(0), MaxSigma(0), MinSigma(0), MinYConstr(100);
		for (int i = 0; i < NumberOfSticks; i++)
		{
			dataGridView1->RowCount += 10 * MassOfSticks[i][2] + 3;
		}
		dataGridView1->RowCount--;
		dataGridView1->ColumnCount = 4;

		for (int i = 0; i < NumberOfSticks; i++)
		{

			dataGridView1->Rows[counter]->Cells[0]->Value = System::Convert::ToString("Стержень №" + (i + 1));
			dataGridView1->Rows[counter]->Cells[1]->Value = "N";
			dataGridView1->Rows[counter]->Cells[2]->Value = "U";
			dataGridView1->Rows[counter]->Cells[3]->Value = "Sigma";

			for (int j = 0; j < 10 * MassOfSticks[i][2] + 1; j++)
			{
				dataGridView1->Rows[counter + j + 1]->Cells[0]->Value = j;
				dataGridView1->Rows[counter + j + 1]->Cells[1]->Value = MassOfNx[i][j * 12];
				dataGridView1->Rows[counter + j + 1]->Cells[2]->Value = MassOfUx[i][j * 12];
				dataGridView1->Rows[counter + j + 1]->Cells[3]->Value = MassOfSigmax[i][j * 12];

				if (j % 10 == 0 && j != 0)
				{
					dataGridView1->Rows[counter + j + 1]->Cells[0]->Value = j / 10 + "L";
				}

				if (abs(MassOfSigmax[i][j * 12]) > MassOfSticks[i][4]) {
					dataGridView1->Rows[counter + j + 1]->Cells[3]->Style->BackColor = System::Drawing::Color::Red;
				}
			}

			counter += 10 * MassOfSticks[i][2] + 3;
		}


		numericUpDown1->Maximum = NumberOfSticks;

		LengthOfConstr = 0;
		for (int i = 0; i < NumberOfSticks; i++)
			LengthOfConstr += MassOfSticks[i][2] * LPixel;

		for (int i = 0; i < NumberOfSticks; i++)
		{
			if (MassOfSticks[i][1] < MinYConstr) {
				MinYConstr = MassOfSticks[i][1];
			}

			for (int j = 0; j < MassOfSticks[i][2] * 120; j++)
			{
				if (MassOfNx[i][j] > MaxN) {
					MaxN = MassOfNx[i][j];
				}
				if (MassOfNx[i][j] < MinN) {
					MinN = MassOfNx[i][j];
				}

				if (MassOfUx[i][j] > MaxU) {
					MaxU = MassOfUx[i][j];
				}
				if (MassOfUx[i][j] < MinU) {
					MinU = MassOfUx[i][j];
				}

				if (MassOfSigmax[i][j] > MaxSigma) {
					MaxSigma = MassOfSigmax[i][j];
				}
				if (MassOfSigmax[i][j] < MinSigma) {
					MinSigma = MassOfSigmax[i][j];
				}
			}
		}
		MaxN = System::Convert::ToInt32(20 * abs(MaxN));
		MinN = System::Convert::ToInt32(20 * abs(MinN));
		MaxU = System::Convert::ToInt32(20 * abs(MaxU));
		MinU = System::Convert::ToInt32(20 * abs(MinU));
		MaxSigma = System::Convert::ToInt32(20 * abs(MaxSigma));
		MinSigma = System::Convert::ToInt32(20 * abs(MinSigma));

		int LHeight = 100 + (100 - MinYConstr) + 40;
		int NHeight = 40 + MaxN + LHeight;
		int UHeight = NHeight + MinN + 40 + MaxU;
		int SigmaHeight = UHeight + MinU + 40 + MaxSigma;
		int EpuraHeight = SigmaHeight + MinSigma;
		pictureBox1->Height = EpuraHeight + 10;
		panel2->Height = EpuraHeight + 10 + 35;


		Bitmap^ bmp = gcnew Bitmap(LengthOfConstr + 120, EpuraHeight + 10);
		Graphics^ graph = Graphics::FromImage(bmp);

		Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ EpuraPen = gcnew Pen(Color::Black, 2.0f);
		Pen^ pillarPen = gcnew Pen(Color::Black, 1.0f);
		Pen^ RedLoadsPen = gcnew Pen(Color::Red, 1.0f);
		Pen^ BlueLoadsPen = gcnew Pen(Color::Blue, 1.0f);

		System::Drawing::Font^ LFont = gcnew System::Drawing::Font("Arial", 18, System::Drawing::GraphicsUnit::Pixel);
		System::Drawing::Font^ NUSFont = gcnew System::Drawing::Font("Arial", 22, System::Drawing::GraphicsUnit::Pixel);


		array<System::Drawing::Rectangle>^ MassRect = gcnew array<System::Drawing::Rectangle>(NumberOfSticks);
		for (int i = 0; i < NumberOfSticks; i++) {
			MassRect[i] = { System::Drawing::Rectangle(MassOfSticks[i][0], MassOfSticks[i][1], MassOfSticks[i][2] * LPixel, 24 + MassOfSticks[i][3] * 18) };
		}

		graph->DrawRectangles(blackPen, MassRect);

		if (LeftPillar) {
			graph->DrawLine(pillarPen, 59, 61, 59, 141);
			for (int i = 0; i < 21; i++) {
				graph->DrawLine(pillarPen, 58, 61 + i * 4, 53, 63 + i * 4);
			}
		}

		if (RightPillar) {
			graph->DrawLine(pillarPen, 61 + LengthOfConstr, 61, 61 + LengthOfConstr, 141);
			for (int i = 0; i < 21; i++) {
				graph->DrawLine(pillarPen, 62 + System::Convert::ToInt32(LengthOfConstr), 61 + i * 4, 67 + System::Convert::ToInt32(LengthOfConstr), 59 + i * 4);
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
					for (int j = 0; j < 6 * MassOfSticks[i][2]; j++)
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
		for (int i = 0; i < NumberOfSticks + 1; i++) {
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

		//Вертикальные линии эпюры
		for (int i = 0; i < NumberOfSticks; i++)
		{
		graph->DrawLine(EpuraPen, MassOfSticks[i][0], 90, MassOfSticks[i][0], EpuraHeight + 10);
		}
		graph->DrawLine(EpuraPen, MassOfSticks[0][0] + LengthOfConstr, 100, MassOfSticks[0][0] + LengthOfConstr, EpuraHeight + 10);

		//Линия L
		graph->DrawLine(EpuraPen, MassOfSticks[0][0], LHeight, MassOfSticks[0][0] + LengthOfConstr, LHeight);
		for (int i = 0; i < NumberOfSticks; i++)
		{
			graph->DrawString(MassOfSticks[i][2] + "L", LFont, System::Drawing::Brushes::Black, MassOfSticks[i][0] + MassOfSticks[i][2] * LPixel / 2 - 15, LHeight - 25);
		}

		counter = 0;
		//Линия N
		graph->DrawLine(EpuraPen, MassOfSticks[0][0], NHeight, MassOfSticks[0][0] + LengthOfConstr, NHeight);
		graph->DrawString("Nx", NUSFont, System::Drawing::Brushes::Black, MassOfSticks[0][0] - 40, NHeight - 15);
		for (int i = 0; i < NumberOfSticks; i++) {
			for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
				graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(NHeight - MassOfNx[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(NHeight - MassOfNx[i][j]*20 - 1));
				if (j%8 == 0) {
					graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(NHeight - MassOfNx[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), NHeight);
				}
			}
			counter += MassOfSticks[i][2] * 120;
		}

		//Линия U
		counter = 0;
		graph->DrawLine(EpuraPen, MassOfSticks[0][0], UHeight, MassOfSticks[0][0] + LengthOfConstr, UHeight);
		graph->DrawString("Ux", NUSFont, System::Drawing::Brushes::Black, MassOfSticks[0][0] - 40, UHeight - 15);
		for (int i = 0; i < NumberOfSticks; i++) {
			for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
				graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(UHeight - MassOfUx[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(UHeight - MassOfUx[i][j] * 20 - 1));
				if (j % 8 == 0) {
					graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(UHeight - MassOfUx[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), UHeight);
				}
			}
			counter += MassOfSticks[i][2] * 120;
		}

		//Линия Sigma
		counter = 0;
		graph->DrawLine(EpuraPen, MassOfSticks[0][0], SigmaHeight, MassOfSticks[0][0] + LengthOfConstr, SigmaHeight);
		graph->DrawString("Sx", NUSFont, System::Drawing::Brushes::Black, MassOfSticks[0][0] - 40, SigmaHeight - 15);
		for (int i = 0; i < NumberOfSticks; i++) {
			for (int j = 0; j < MassOfSticks[i][2] * LPixel + 1; j++) {
				graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(SigmaHeight - MassOfSigmax[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(SigmaHeight - MassOfSigmax[i][j] * 20 - 1));
				if (j % 8 == 0) {
					graph->DrawLine(pillarPen, System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), System::Convert::ToInt32(SigmaHeight - MassOfSigmax[i][j] * 20), System::Convert::ToInt32(MassOfSticks[0][0] + j + counter), SigmaHeight);
				}
			}
			counter += MassOfSticks[i][2] * 120;
		}

		pictureBox1->Image = bmp;

	}
	return System::Void();
}

System::Void SAPR::PostProcessor::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == System::String::Empty) {
		return System::Void();
	}
	if (textBox1->Text[0] == '-') {
		MessageBox::Show("Значение сечения не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		textBox1->Text = "0";
		return System::Void();
	}

	textBox2->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][5] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][3] * (MassOfU[System::Convert::ToInt32(numericUpDown1->Value) - 1][1] - MassOfU[System::Convert::ToInt32(numericUpDown1->Value) - 1][0]) / MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2] + MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2] * (1 - 2 * System::Convert::ToDouble(textBox1->Text) / (MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2])) / 2);
	textBox3->Text = System::Convert::ToString(MassOfU[System::Convert::ToInt32(numericUpDown1->Value) - 1][0] + System::Convert::ToDouble(textBox1->Text) * (MassOfU[System::Convert::ToInt32(numericUpDown1->Value) - 1][1] - MassOfU[System::Convert::ToInt32(numericUpDown1->Value) - 1][0]) / (MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2]) + MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2] * System::Convert::ToDouble(textBox1->Text) * (1 - System::Convert::ToDouble(textBox1->Text) / (MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2])) / (2 * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][5] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][3] * MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][2]));
	textBox4->Text = System::Convert::ToString(System::Convert::ToDouble(textBox2->Text) / MassOfSticks[System::Convert::ToInt32(numericUpDown1->Value) - 1][3]);


	return System::Void();
}
