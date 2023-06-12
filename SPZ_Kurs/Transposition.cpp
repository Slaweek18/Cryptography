#include "Transposition.h"

std::vector<int> Transposition::getKey()
{
    return key;
}

void Transposition::generateKey()
{
    // генеруємо ключ мін - 2, макс - 30
    srand(time(NULL));
    int keyLength = (rand() % 29 + 2);
    keyLength = (keyLength > sizeFile) ? ((keyLength % sizeFile) == 0 ? sizeFile : keyLength % sizeFile) : keyLength;

    key.resize(keyLength);
    for (int i = 0; i < keyLength; i++) {
        this->key[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(this->key.begin(), this->key.end(), g);
}

void Transposition::Encrypt(unsigned char* input, HANDLE hFile)
{
    int keyLength = key.size();
    unsigned char space = ' ';
    DWORD bytes_written = 0;

    //Довжина ключа має націло ділитися на кількість символів в тексті
    SetFilePointer(hFile, 0, NULL, FILE_END);
    for (int i = 0; sizeFile % keyLength != 0; i++) {
        WriteFile(hFile, &space, 1, &bytes_written, 0);
        sizeFile++;
    }

    for (int i = 0; i < sizeFile; i += keyLength) {
        std::vector<unsigned char> transposition(keyLength);

        for (int j = 0; j < keyLength; j++) {
            transposition[key[j] - 1] = input[i + j];

        }

        for (int j = 0; j < keyLength; j++) {
            input[i + j] = transposition[j];
        }
    }
    this->key.clear();
}

int Transposition::Decrypt(unsigned char* input, HANDLE hkey, HANDLE hFile)
{

    DWORD bytes_read = 0;
    int fileSizeKey = GetFileSize(hkey, NULL);
    std::string keyCopy(fileSizeKey, '\0');

    if (!ReadFile(hkey, &keyCopy[0], fileSizeKey, &bytes_read, 0)) {
        //cerr << "Failed to read file. Error code: " << GetLastError() << std::endl;
        CloseHandle(hkey);
        return 12;
    }

    std::istringstream iss(keyCopy);
    int number = 0;
    while (iss >> number) {
        key.push_back(number);
    }
    iss.clear();
    iss.seekg(0, std::ios::beg);
    int keyLength = key.size();

    for (int i = 0; i < sizeFile; i += keyLength) {
        std::vector<unsigned char> transposition(keyLength);

        for (int j = 0; j < keyLength; j++) {
            transposition[j] = input[i + key[j] - 1];

        }

        for (int j = 0; j < keyLength; j++) {
            input[i + j] = transposition[j];
        }
    }
    this->key.clear();
}
