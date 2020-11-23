#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"
#include <Windows.h>

using namespace SAPR;


const int LPixel = 120;

extern int NumberOfSticks;
extern double LengthOfConstr;
extern double** MassOfSticks;
extern double* MassOfHubLoads;
extern double* MassOfStickLoads;

bool flagTextChangedByNumeric = 0;
bool flagTextChangedByMinus = 0;
bool flagProgrammStarted = 1;

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew PreProcessor);
    return 0;
}

/*Добавить подписи к конструкции!!*/
System::Void SAPR::PreProcessor::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!checkBox1->Checked && !checkBox2->Checked) {
		MessageBox::Show("Укажите хотя бы одну опору", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	for (int i = 0; i < NumberOfSticks; i++) {
		if (MassOfSticks[i][2] == 0) {
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
			graph->DrawLine(pillarPen, 58, 61 + i * 4, 53, 63 + i * 4);
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

	/*Добавить подписи к конструкции!!*/

	pictureBox1->Image = bmp;
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox3->Text == "-") {
		MessageBox::Show("Значение длины стержня не может быть отрицательным", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		flagTextChangedByMinus = 1;
		textBox3->Text = "0";
		return;
	}

	if (textBox3->Text == "0" && flagTextChangedByMinus != 1) {
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
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
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
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
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
	return System::Void();
}

System::Void SAPR::PreProcessor::numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	flagTextChangedByNumeric = 1;

	textBox1->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][2]);
	textBox2->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][3]);
	textBox4->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][4]);
	textBox5->Text = System::Convert::ToString(MassOfSticks[System::Convert::ToInt32(numericUpDown3->Value) - 1][5]);
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
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
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
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
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox6->Text == "-") {
		return;
	}

	MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1] = System::Convert::ToDouble(textBox6->Text);
	return System::Void();
}

System::Void SAPR::PreProcessor::textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox7->Text == "-") {
		return;
	}

	MassOfHubLoads[System::Convert::ToInt32(numericUpDown2->Value) - 1] = System::Convert::ToDouble(textBox7->Text);
	return System::Void();
}

System::Void SAPR::PreProcessor::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBox6->Text = System::Convert::ToString(MassOfStickLoads[System::Convert::ToInt32(numericUpDown1->Value) - 1]);
	return System::Void();
}

System::Void SAPR::PreProcessor::numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    textBox7->Text = System::Convert::ToString(MassOfHubLoads[System::Convert::ToInt32(numericUpDown2->Value) - 1]);
    return System::Void();
}

System::Void SAPR::PreProcessor::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	openFileDialog1->Filter = "Text Files|*.txt";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
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

    return System::Void();
}

System::Void SAPR::PreProcessor::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveFileDialog1->FileName = "SAPRDataProcessor";
	saveFileDialog1->Filter = "Text Files|*.txt";

	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (saveFileDialog1->FileName->Length > 0) {
			StreamWriter^ saveFile = gcnew StreamWriter(saveFileDialog1->FileName);

			saveFile->WriteLine(NumberOfSticks);
			saveFile->WriteLine(System::Convert::ToInt32(checkBox1->Checked));
			saveFile->WriteLine(System::Convert::ToInt32(checkBox2->Checked));
			for (int i = 0; i < NumberOfSticks; i++) {
				for (int j = 0; j < 6; j++) {
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
	return System::Void();
}

System::Void SAPR::PreProcessor::перейтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::Processor Processor;
	Processor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::PreProcessor::перейтиToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PostProcessor PostProcessor;
	PostProcessor.ShowDialog();
	this->Close();
	return System::Void();
}
