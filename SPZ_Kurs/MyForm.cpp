#include "MyForm.h"
#include "Header.h"

using namespace System;
using namespace System::Windows::Forms;
int sizeFile;
[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SPZKurs::MyForm form;
	Application::Run(% form);
}

