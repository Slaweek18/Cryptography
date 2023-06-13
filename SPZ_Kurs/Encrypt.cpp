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

System::Void SPZKurs::Encrypt::openFileEnc_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	String^ FileName = "";
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialog1->FileName;
		pathFile->Text = FileName;

	}
}

