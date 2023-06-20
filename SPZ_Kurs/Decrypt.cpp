#include "Decrypt.h"
#include"Functions.h"

Feistel feistelD;
Transposition transD;
HANDLE hFileD, hkeyD, mhD;
std::string  pathFileD,
			 pathEncryptedFileD,
		     pathKeyD,
			 fileNameD,
			 fileExtensionD,
			 fileNameDec = "_encrypted";
std::stringstream ssKeyToFileD;
std::string strKeyToFileD;
unsigned char* fmapD;


System::Void SPZKurs::Decrypt::проВікноToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Для того щоб дешифрувати файл вам достатньо:\n\
    1) Обрати файл, який потрібно дешифрувати.\n\
    2) Програма автоматично визначає метод шифрування за розширенням файлу.\n\
    3) Зчитується ключ з файлу \"(Назва обраного файлу)key.txt\" у тому ж каталозі, що й зашифрований файл\n\
    4) Оригінальний файл відновлюється з розширенням \".txt\"\n\
    5) Після розшифрування вихідного файлу програма видаляє файл \"(Назва файлу)key.txt\" з ключем. ", "Information");
}

System::Void SPZKurs::Decrypt::toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm^ form = gcnew MyForm;
    this->Hide();
    form->Show();
}

System::Void SPZKurs::Decrypt::toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void SPZKurs::Decrypt::openFileDec_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ FileName = "";
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialog1->FileName;
		PathFile->Text = FileName;
		Convert_String_to_string(FileName, pathFileD);
	}

}

System::Void SPZKurs::Decrypt::buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (PathFile->Text == "") {
        MessageBox::Show("Для початку оберіть файл", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    else {
        try {
            std::filesystem::path filePath(pathFileD);
            hFileD = CreateFileA(pathFileD.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFileD == INVALID_HANDLE_VALUE)
            {
                MessageBox::Show("Файл не вдалося відкрити!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                CloseHandle(hFileD);
            }
            else {
                pathKeyD = filePath.parent_path().string();
                fileExtensionD = filePath.extension().string();
                pathEncryptedFileD = pathKeyD;
                fileNameD = filePath.stem().string();

                pathKeyD += std::string("\\") + fileNameD.substr(0, fileNameD.rfind(fileNameDec)) + std::string("key.txt");
                sizeFile = GetFileSize(hFileD, NULL);

                try {
                    mhD = CreateFileMapping(hFileD, 0, PAGE_READWRITE, 0, sizeFile, NULL);
                    fmapD = (unsigned char*)MapViewOfFile(mhD, FILE_MAP_WRITE, 0, 0, sizeFile);
                    if (fmapD == nullptr) {
                        // Помилка при отриманні виділеної області пам'яті
                        MessageBox::Show("Помилка при отриманні виділеної області пам'яті", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

                    }
                }
                catch (const std::exception& e) {
                    std::string errorMessage = e.what();
                    MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    CloseHandle(mhD);
                    CloseHandle(hFileD);

                }
            }
        }
        catch (const std::exception& e) {

            std::string errorMessage = e.what();
            MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            CloseHandle(hFileD);
        }
        if (fileExtensionD == std::string(".fei")) {
            hkeyD = createFileKey(pathKeyD.c_str());
            feistelD.feistel_decrypt(fmapD, hkeyD);
        }
        else if (fileExtensionD == std::string(".tra")) {
            hkeyD = createFileKey(pathKeyD.c_str());
            transD.Decrypt(fmapD, hkeyD, hFileD);
        }

        CloseHandle(hkeyD);
        //видаляємо файл ключа після дешифрування
        if (!DeleteFileA(pathKeyD.c_str())){
            MessageBox::Show("Не вдалося видалити файл ключа", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        CloseHandle(hFileD);
        pathEncryptedFileD += std::string("\\") + fileNameD.substr(0, fileNameD.rfind(fileNameDec)) + std::string(".txt");

        if (MoveFileA(pathFileD.c_str(), pathEncryptedFileD.c_str())) {
            
            PathFile->Text = "";
            MessageBox::Show("Файл успішно дешифровано", "Decrypt", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("Файл не дешифровано", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }
    UnmapViewOfFile(fmapD);
    CloseHandle(mhD);
}
