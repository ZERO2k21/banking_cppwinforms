// main.cpp

#include <Windows.h>
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the main form
    Application::Run(gcnew BankingApp::MyForm());

    return 0;
}
