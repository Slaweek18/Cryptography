#include "Encrypt.h"
#include"Functions.h"
#include "Header.h"

Feistel feistel;
Transposition trans;
HANDLE hFile, hkey, mh;
unsigned char keyFeist = unsigned char("");
std::string  pathFile,
             pathEncryptedFile,
             pathKey,
             fileName,
             fileExtension,
             fileNameEnc = "_encrypted";
std::stringstream ssKeyToFile;
std::string strKeyToFile;
unsigned char* fmap;

System::Void SPZKurs::Encrypt::toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm^ form = gcnew MyForm;
    this->Hide();
    form->Show();

}

System::Void SPZKurs::Encrypt::toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void SPZKurs::Encrypt::���³���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("��� ���� ��� ����������� ���� ��� ���������:\n \
    1) ������ ����, ���� ������� �����������.\n \
    2) ������ ����� ���������� : �������� ��� ������������.\n\n \
���� ������� ����� - ��������, ���������� ���������� ����(����������� ������), \
���� ���������� � ���� \"(����� �����)key.txt\" � ���� � �������, �� � ���������� ����. ���� � ���������� ������� ���������� � ����������� \".fei\"\
\n\n���� ������� ����� - ������������, ���������� ���������� ����(����������� ����� �����), \
���� ���������� � ���� \"(����� �����)key.txt\" � ���� � �������, �� � ���������� ����. ���� � ���������� ������� ���������� � ����������� \".tra\" ", 
"Information");
}

System::Void SPZKurs::Encrypt::openFileEnc_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    SetConsoleOutputCP(1251);
	String^ FileName = "";
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialog1->FileName;
		PathFile->Text = FileName;
        Convert_String_to_string(FileName,pathFile);
        textBoxKey->Text = "";
	}
}

System::Void SPZKurs::Encrypt::buttonKey_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (radioFeist->Checked==true) {
        if (PathFile->Text == "") {
            MessageBox::Show("��� ������� ������ ����", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
        else {
            std::cout << feistel.getKey()<<std::endl;
            trans.resetKey(); //������� ���� ������������ ������
            feistel.generateKey();
            textBoxKey->Text = Convert_char_to_String(feistel.getKey());
            keyFeist = feistel.getKey();
            std::cout << feistel.getKey() << std::endl;

        }
    }
    
    if (radioTrans->Checked == true) {
        if (PathFile->Text == "") {
            MessageBox::Show("��� ������� ������ ����", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Warning);

        } else {

            feistel.setKey('\0'); //������� ���� ������������ ������
            hFile = CreateFileA(pathFile.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            sizeFile = GetFileSize(hFile, NULL);
            CloseHandle(hFile);
            std::stringstream ssKey;
            std::string str;
            String^ str1;
            srand(time(NULL));
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
        MessageBox::Show("��� ������� ������ ����", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Warning);

    } else if (textBoxKey->Text == "") {
        MessageBox::Show("������� �������� �� ���������� ����", "Key generation", MessageBoxButtons::OK, MessageBoxIcon::Warning);

    }
    else {
        try {
            std::filesystem::path filePath(pathFile);
            hFile = CreateFileA(pathFile.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFile == INVALID_HANDLE_VALUE)
            {
                MessageBox::Show("���� �� ������� �������!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                CloseHandle(hFile);
            }
            pathKey = filePath.parent_path().string();
            fileExtension = filePath.extension().string();
            pathEncryptedFile = pathKey;
            fileName = filePath.stem().string();

            pathKey += std::string("\\") + fileName + std::string("key.txt");
            sizeFile = GetFileSize(hFile, NULL);

            try {
                mh = CreateFileMapping(hFile, 0, PAGE_READWRITE, 0, sizeFile, NULL);
                fmap = (unsigned char*)MapViewOfFile(mh, FILE_MAP_WRITE, 0, 0, sizeFile);
                hkey = createFileKey(pathKey.c_str());
            }
            catch (const std::exception& e) {
                std::string errorMessage = e.what();
                MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error1", MessageBoxButtons::OK, MessageBoxIcon::Error);
                CloseHandle(hkey);
                CloseHandle(hFile);
                CloseHandle(mh);
            }
        }
        catch (const std::exception& e) {

            std::string errorMessage = e.what();
            MessageBox::Show(gcnew System::String(errorMessage.c_str()), "Error2", MessageBoxButtons::OK, MessageBoxIcon::Error);
            CloseHandle(hFile);
        }

        if (radioFeist->Checked == true) {
            if (feistel.getKey() == '\0') {
                MessageBox::Show("�� ����������� ���� ��� ������������ ���������", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            else {
                std::cout << feistel.getKey() << std::endl;

                WriteFile(hkey, &keyFeist, sizeof(keyFeist), &bytes_written, 0);
                feistel.feistel_encrypt(fmap);
                pathEncryptedFile += std::string("\\") + fileName + fileNameEnc + std::string(".fei");
                keyFeist = '\0';
                feistel.setKey('\0');

                std::cout << feistel.getKey() << std::endl;

            }
        }

        if (radioTrans->Checked == true) {
            if (trans.getKey().size()==0) {
                MessageBox::Show("�� ����������� ���� ��� ������������ ���������", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            else {
                for (int i = 0; i < strKeyToFile.size(); i++) {
                    WriteFile(hkey, &strKeyToFile[i], 1, &bytes_written, 0);
                }
                trans.Encrypt(fmap, hFile);
                pathEncryptedFile += std::string("\\") + fileName + fileNameEnc + std::string(".tra");
                strKeyToFile = "";
                trans.resetKey();
            }
        }

        CloseHandle(hFile);

        if (MoveFileA(pathFile.c_str(), pathEncryptedFile.c_str())) {

            PathFile->Text = "";
            textBoxKey->Text = "";
            MessageBox::Show("���� ������ �����������", "Encrypt", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        else {
            PathFile->Text = "";
            textBoxKey->Text = "";
            MessageBox::Show("���� �� �����������!", "Encrypt", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        CloseHandle(hkey);
        UnmapViewOfFile(fmap);
        CloseHandle(mh);
    }
}

