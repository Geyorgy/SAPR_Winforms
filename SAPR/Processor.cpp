#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"
#include "cmath"

using namespace SAPR;

extern int NumberOfSticks;
extern double LengthOfConstr;
extern double** MassOfSticks;
extern double* MassOfHubLoads;
extern double* MassOfStickLoads;
extern int LeftPillar;
extern int RightPillar;
double** MatrixA;
double* MatrixB;
double* MatrixDelta;
double** MassOfU;

double** MassOfNx;
double** MassOfUx;
double** MassOfSigmax;

double* gauss(double** a, double* y, int n)
{
	double* x, max;
	int k, index;
	const double eps = 0.00001;  // точность
	x = new double[n];
	k = 0;
	while (k < n)
	{
		// Поиск строки с максимальным a[i][k]
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		// Перестановка строк
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			return 0;
		}
		for (int j = 0; j < n; j++)
		{
			double temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}
		double temp = y[k];
		y[k] = y[index];
		y[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < n; i++)
		{
			double temp = a[i][k];
			if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] / temp;
			y[i] = y[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j];
			y[i] = y[i] - y[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = y[k];
		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];
	}
	return x;
}

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

	RTBFile->AppendText("Характеристика стержней\n\n");
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
	if (LeftPillar == 0 && RightPillar == 0)
	{
		if (MessageBox::Show("Ни одна опора не задана.\nПерейти в препроцессор для редактирования?", "Ошибка", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {
			this->Hide();
			SAPR::PreProcessor PreProcessor;
			PreProcessor.DataFileName = DataFileName;
			PreProcessor.flagComeFromOutside = 1;
			PreProcessor.ShowDialog();
			this->Close();
			return System::Void();
		}
		else {
			return System::Void();
		}
	}

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
				else {
					return System::Void();
				}
			}
		}
	}

	MatrixA = new double* [NumberOfSticks + 1];
	for (int i = 0; i < NumberOfSticks + 1; i++) {
		MatrixA[i] = new double[NumberOfSticks + 1];
		for (int j = 0; j < NumberOfSticks + 1; j++) {
			MatrixA[i][j] = 0;
		}
	}

	for (int i = 0; i < NumberOfSticks; i++) {
		MatrixA[i][i] += MassOfSticks[i][5] * MassOfSticks[i][3] / MassOfSticks[i][2];
		MatrixA[i][i + 1] = -MassOfSticks[i][5] * MassOfSticks[i][3] / MassOfSticks[i][2];
		MatrixA[i + 1][i] = -MassOfSticks[i][5] * MassOfSticks[i][3] / MassOfSticks[i][2];
		MatrixA[i + 1][i + 1] = MassOfSticks[i][5] * MassOfSticks[i][3] / MassOfSticks[i][2];
	}

	MatrixB = new double[NumberOfSticks + 1];

	MatrixB[0] = MassOfHubLoads[0] + MassOfStickLoads[0] * MassOfSticks[0][2] / 2;
	for (int i = 1; i < NumberOfSticks; i++) {
		MatrixB[i] = MassOfStickLoads[i - 1] * MassOfSticks[i - 1][2] / 2 + MassOfHubLoads[i] + MassOfStickLoads[i] * MassOfSticks[i][2] / 2;
	}
	MatrixB[NumberOfSticks] = MassOfStickLoads[NumberOfSticks - 1] * MassOfSticks[NumberOfSticks - 1][2] / 2 + MassOfHubLoads[NumberOfSticks];

	if (LeftPillar) {
		MatrixA[0][0] = 1;
		MatrixA[1][0] = 0;
		MatrixA[0][1] = 0;
		MatrixB[0] = 0;
	}

	if (RightPillar) {
		MatrixA[NumberOfSticks][NumberOfSticks] = 1;
		MatrixA[NumberOfSticks - 1][NumberOfSticks] = 0;
		MatrixA[NumberOfSticks][NumberOfSticks - 1] = 0;
		MatrixB[NumberOfSticks] = 0;
	}

	/*RTBLogs->AppendText(System::Convert::ToString(MatrixA[0][0]) + " " + System::Convert::ToString(MatrixA[0][1]) + " " + System::Convert::ToString(MatrixA[0][2]) + " " + System::Convert::ToString(MatrixA[0][3]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixA[1][0]) + " " + System::Convert::ToString(MatrixA[1][1]) + " " + System::Convert::ToString(MatrixA[1][2]) + " " + System::Convert::ToString(MatrixA[1][3]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixA[2][0]) + " " + System::Convert::ToString(MatrixA[2][1]) + " " + System::Convert::ToString(MatrixA[2][2]) + " " + System::Convert::ToString(MatrixA[2][3]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixA[3][0]) + " " + System::Convert::ToString(MatrixA[3][1]) + " " + System::Convert::ToString(MatrixA[3][2]) + " " + System::Convert::ToString(MatrixA[3][3]) + "\n\n");

	RTBLogs->AppendText(System::Convert::ToString(MatrixB[0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixB[1]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixB[2]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixB[3]) + "\n\n");*/

	MatrixDelta = new double[NumberOfSticks + 1];
	MatrixDelta = gauss(MatrixA, MatrixB, NumberOfSticks + 1);

	/*RTBLogs->AppendText(System::Convert::ToString(MatrixDelta[0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixDelta[1]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixDelta[2]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MatrixDelta[3]) + "\n\n");*/

	MassOfU = new double* [NumberOfSticks];
	for (int i = 0; i < NumberOfSticks; i++) {
		MassOfU[i] = new double[2];
		MassOfU[i][0] = MatrixDelta[i];
		MassOfU[i][1] = MatrixDelta[i + 1];
	}

	for (int i = 0; i < NumberOfSticks + 1; i++){
		delete[] MatrixA[i];
	}
	delete[] MatrixA;
	delete[] MatrixB;
	delete[] MatrixDelta;

	MassOfNx = new double* [NumberOfSticks];
	for (int i = 0; i < NumberOfSticks; i++) {
		MassOfNx[i] = new double[MassOfSticks[i][2] * 100 + 1];
		for (int j = 0; j < MassOfSticks[i][2] * 100 + 1; j++){
			MassOfNx[i][j] = MassOfSticks[i][5] * MassOfSticks[i][3] * (MassOfU[i][1] - MassOfU[i][0]) / MassOfSticks[i][2] + MassOfStickLoads[i] * MassOfSticks[i][2] * (1 - 2 * j / (100 * MassOfSticks[i][2])) / 2;
		}
	}

	/*RTBLogs->AppendText(System::Convert::ToString(MassOfNx[0][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfNx[0][200]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfNx[1][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfNx[1][300]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfNx[2][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfNx[2][300]) + "\n");*/

	MassOfUx = new double* [NumberOfSticks];
	for (int i = 0; i < NumberOfSticks; i++) {
		MassOfUx[i] = new double[MassOfSticks[i][2] * 100 + 1];
		for (int j = 0; j < MassOfSticks[i][2] * 100 + 1; j++) {
			MassOfUx[i][j] = MassOfU[i][0] + j * (MassOfU[i][1] - MassOfU[i][0]) / (100 * MassOfSticks[i][2]) + MassOfStickLoads[i] * MassOfSticks[i][2] * MassOfSticks[i][2] * j * (1 - j / (100 * MassOfSticks[i][2])) / (100 * 2 * MassOfSticks[i][5] * MassOfSticks[i][3] * MassOfSticks[i][2]);
		}
	}

	/*RTBLogs->AppendText(System::Convert::ToString(MassOfUx[0][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfUx[0][200]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfUx[1][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfUx[1][300]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfUx[2][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfUx[2][300]) + "\n");*/

	MassOfSigmax = new double* [NumberOfSticks];
	for (int i = 0; i < NumberOfSticks; i++) {
		MassOfSigmax[i] = new double[MassOfSticks[i][2] * 100 + 1];
		for (int j = 0; j < MassOfSticks[i][2] * 100 + 1; j++) {
			MassOfSigmax[i][j] = MassOfNx[i][j] / MassOfSticks[i][3];
		}
	}

	/*RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[0][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[0][200]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[1][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[1][300]) + "\n\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[2][0]) + "\n");
	RTBLogs->AppendText(System::Convert::ToString(MassOfSigmax[2][300]) + "\n");*/

	RTBLogs->AppendText("Вычисление завершено\n\nПолученные значения:\n\n");
	for (int i = 0; i < NumberOfSticks; i++){
		RTBLogs->AppendText("Стержень №" + (i + 1) + "\n");
		RTBLogs->AppendText("Nx(0) = " + MassOfNx[i][0] + "; Nx(" + MassOfSticks[i][2] + "L) = " + MassOfNx[i][System::Convert::ToInt32(MassOfSticks[i][2]) * 100] + "\n");
		RTBLogs->AppendText("Ux(0) = " + MassOfUx[i][0] + "; Ux(" + MassOfSticks[i][2] + "L) = " + MassOfUx[i][System::Convert::ToInt32(MassOfSticks[i][2]) * 100] + "\n");
		RTBLogs->AppendText("Sigma(0) = " + MassOfSigmax[i][0] + "; Sigma(" + MassOfSticks[i][2] + "L) = " + MassOfSigmax[i][System::Convert::ToInt32(MassOfSticks[i][2]) * 100] + "\n\n");
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

		RTBFile->AppendText("Характеристика стержней\n\n");
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
