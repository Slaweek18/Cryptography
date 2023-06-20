#pragma once
#include"Header.h"
extern int sizeFile;

class Transposition
{
private:
	std::vector<int> key;

public:

	void resetKey();

	std::vector<int> getKey();

	void generateKey();

	void Encrypt(unsigned char* input, HANDLE hFile);

	int Decrypt(unsigned char* input, HANDLE hkey, HANDLE hFile);

};
