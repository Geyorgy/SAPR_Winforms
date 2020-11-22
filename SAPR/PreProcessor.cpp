#include "PreProcessor.h"
#include <Windows.h>

using namespace SAPR;

[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew PreProcessor);
    return 0;
}