#include "Encrypt.h"
#include"Functions.h"
#include "Header.h"

Feistel feistel;
Transposition trans;
HANDLE hFile, hkey, mh;
unsigned char keyFeist;
std::vector<int> keyTrans;
std::string  pathFile,
             pathEncryptedFile,
             pathKey,
             fileName,
             fileExtension,
             fileNameEnc = "_encrypted";
std::stringstream ssKeyToFile;
std::string strKeyToFile;
unsigned char* fmap;

System::Void SPZKurs::Encrypt::вийтиЗПрограмиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void SPZKurs::Encrypt::повернутисяВГоловнеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm;
	this->Hide();
	form->Show();
}

System::Void SPZKurs::Encrypt::openFileEnc_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    SetConsoleOutputCP(1251);

	String^ FileName = "";
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialog1->FileName;
		PathFile->Text = FileName;
        Convert_String_to_string(FileName,pathFile);
        std::cout << pathFile;
	}

    try {
        std::filesystem::path filePath(pathFile);
        hFile = CreateFileA(pathFile.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        pathKey = filePath.parent_path().string();
        fileExtension = filePath.extension().string();
        pathEncryptedFile = pathKey;
        fileName = filePath.stem().string();

        pathKey += std::string("\\") + fileName + std::string("key.txt");
        sizeFile = GetFileSize(hFile, NULL);
        std::cout << sizeFile;

        try {
            mh = CreateFileMapping(hFile, 0, PAGE_READWRITE, 0, sizeFile, NULL);
            fmap = (unsigned char*)MapViewOfFile(mh, FILE_MAP_WRITE, 0, 0, sizeFile);
            hkey = createFileKey(pathKey.c_str());
        }
        catch (const std::exception& e) {
            std::string errorMessage = e.what();
            MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            CloseHandle(hkey);
            CloseHandle(hFile);
            CloseHandle(mh);
        }
    }
    catch (const std::exception& e) {

        std::string errorMessage = e.what();
        MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        CloseHandle(hFile);
    }
}

System::Void SPZKurs::Encrypt::buttonKey_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (radioFeist->Checked==true) {
        if (PathFile->Text == "") {
            MessageBox::Show("Для початку оберіть файл", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            feistel.generateKey();
            textBoxKey->Text = Convert_char_to_String(feistel.getKey());
            keyFeist = feistel.getKey();
        }
    }
    
    if (radioTrans->Checked == true) {
        if (PathFile->Text == "") {
            MessageBox::Show("Для початку оберіть файл", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Information);

        } else {
            std::stringstream ssKey;
            std::string str;
            String^ str1;
            trans.generateKey();

            for (const int& num : trans.getKey()) {
                ssKey << num;
                ssKeyToFile << num << " ";
            }
            str = ssKey.str();
            strKeyToFile = ssKeyToFile.str();
            ssKey.str("");
            ssKeyToFile.str("");
            ssKey.clear();
            ssKeyToFile.clear();
            textBoxKey->Text = Convert_string_to_String(str, str1);
        }
    }
    
}

System::Void SPZKurs::Encrypt::buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
    DWORD bytes = 0, bytes_written = 0;
    if (PathFile->Text == "") {
        MessageBox::Show("Для початку оберіть файл", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Information);
    } else if (textBoxKey->Text == "") {
        MessageBox::Show("Виберіть алгоритм та згенеруйте ключ", "Key generation", MessageBoxButtons::OK, MessageBoxIcon::Information);

    }
    else {

        if (radioFeist->Checked == true) {
            WriteFile(hkey, &keyFeist, sizeof(keyFeist), &bytes_written, 0);
            feistel.feistel_encrypt(fmap);
            pathEncryptedFile += std::string("\\") + fileName + fileNameEnc + std::string(".fei");

        }

        if (radioTrans->Checked == true) {
            if (textBoxKey->Text == "") {
                MessageBox::Show("Виберіть алгоритм та згенеруйте ключ", "Key generation", MessageBoxButtons::OK, MessageBoxIcon::Information);

            }
            else {
                for (int i = 0; i < strKeyToFile.size(); i++) {
                    WriteFile(hkey, &strKeyToFile[i], 1, &bytes_written, 0);
                }
                trans.Encrypt(fmap, hFile);
                pathEncryptedFile += std::string("\\") + fileName + fileNameEnc + std::string(".tra");
            }
        }

        CloseHandle(hFile);

        if (MoveFileA(pathFile.c_str(), pathEncryptedFile.c_str())) {

            PathFile->Text = "";
            textBoxKey->Text = "";
            MessageBox::Show("Файл успішно зашифровано", "Encrypt", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        else {
            MessageBox::Show("Файл не зашифровано!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            PathFile->Text = "";

        }
        CloseHandle(hkey);
        UnmapViewOfFile(fmap);
        CloseHandle(mh);
    }
}

