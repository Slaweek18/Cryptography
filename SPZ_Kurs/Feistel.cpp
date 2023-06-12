#include "Feistel.h"

unsigned char Feistel::getKey()
{
    return key;
}

unsigned char Feistel::rotate(unsigned char x, int n)
{
    return ((x << n) | (x >> (8 - n)));
}

void Feistel::feistel_round(unsigned char& a, unsigned char& b, unsigned char key)
{
    unsigned char temp = a;
    a = b ^ rotate(a ^ key, 3);
    b = temp;
}

void Feistel::generateKey()
{
    srand(time(NULL));
    this->key = static_cast<char>(rand() % 256);
}

void Feistel::feistel_encrypt(unsigned char* data)
{
    for (int i = 0; i < sizeFile - 1; i++)
    {
        feistel_round(data[i], data[i + 1], this->key);
    }
    key = (unsigned char)"";
}

int Feistel::feistel_decrypt(unsigned char* data, HANDLE hkey)
{
    int fileSizeKey = GetFileSize(hkey, NULL);
    DWORD bytes_read = 0;
    if (!ReadFile(hkey, &key, fileSizeKey, &bytes_read, 0)) {
        //cerr << "Failed to read file. Error code: " << GetLastError() << endl;
        CloseHandle(hkey);
        return 20;
    }
    for (int i = sizeFile - 1; i > 0; i--)
    {
        feistel_round(data[i - 0], data[i - 1], key);
    }
    key = (unsigned char)"";
}
