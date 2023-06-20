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


System::Void SPZKurs::Decrypt::���³���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("��� ���� ��� ����������� ���� ��� ���������:\n\
    1) ������ ����, ���� ������� �����������.\n\
    2) �������� ����������� ������� ����� ���������� �� ����������� �����.\n\
    3) ��������� ���� � ����� \"(����� �������� �����)key.txt\" � ���� � �������, �� � ������������ ����\n\
    4) ����������� ���� ������������ � ����������� \".txt\"\n\
    5) ϳ��� ������������� ��������� ����� �������� ������� ���� \"(����� �����)key.txt\" � ������. ", "Information");
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
        MessageBox::Show("��� ������� ������ ����", "OpenFile", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    else {
        try {
            std::filesystem::path filePath(pathFileD);
            hFileD = CreateFileA(pathFileD.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFileD == INVALID_HANDLE_VALUE)
            {
                MessageBox::Show("���� �� ������� �������!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
                        // ������� ��� �������� ������� ������ ���'��
                        MessageBox::Show("������� ��� �������� ������� ������ ���'��", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

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
        //��������� ���� ����� ���� ������������
        if (!DeleteFileA(pathKeyD.c_str())){
            MessageBox::Show("�� ������� �������� ���� �����", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        CloseHandle(hFileD);
        pathEncryptedFileD += std::string("\\") + fileNameD.substr(0, fileNameD.rfind(fileNameDec)) + std::string(".txt");

        if (MoveFileA(pathFileD.c_str(), pathEncryptedFileD.c_str())) {
            
            PathFile->Text = "";
            MessageBox::Show("���� ������ �����������", "Decrypt", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("���� �� �����������", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }
    UnmapViewOfFile(fmapD);
    CloseHandle(mhD);
}
