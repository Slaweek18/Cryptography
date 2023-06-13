#include "Encrypt.h"
#include "MyForm.h"

System::Void SPZKurs::Encrypt::âèéòèÇÏðîãðàìèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void SPZKurs::Encrypt::ïîâåðíóòèñÿÂÃîëîâíåÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm;
	this->Hide();
	form->Show();
}
