#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

int sizeFile=0;
[STAThreadAttribute]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SPZKurs::MyForm form;
	Application::Run(% form);
}

System::Void SPZKurs::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void SPZKurs::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("�������� ������ ���������� �� ������������� �����(������� txt)\
 �� ��������� ���� ������ - ������ �������� (Feistel) �� ������ ������������ (Transposition).","Information");
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
