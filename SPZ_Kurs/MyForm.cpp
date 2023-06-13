#include "MyForm.h"
#include "Header.h"
#include"Encrypt.h"
#include"Decrypt.h"

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

System::Void SPZKurs::MyForm::âèõ³äToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void SPZKurs::MyForm::ïðîÏðîãðàìóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Öÿ ïðîãðàìà íàäàº ôóíêö³¿ øèôðóâàííÿ òà äåøèôðóâàííÿ ôàéë³â ôîðìàòó .txt","Information");
}

System::Void SPZKurs::MyForm::encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	Encrypt^ form = gcnew Encrypt();
	this->Hide();
	form->Show();
	
}

System::Void SPZKurs::MyForm::decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	Decrypt^ form = gcnew Decrypt();
	this->Hide();
	form->Show();
}
