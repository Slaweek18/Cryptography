#pragma once
#include"Header.h"
extern int sizeFile;
class Feistel
{
private:
	unsigned char key;

public:
	unsigned char getKey();

	// Функція, яка повертає результат роботи блоку зсуву
	unsigned char rotate(unsigned char x, int n);

	// Функція, яка реалізує один раунд мережі Фейстеля
	void feistel_round(unsigned char& a, unsigned char& b, unsigned char key);

	void generateKey();

	// Функція, яка реалізує шифрування блоку даних
	void feistel_encrypt(unsigned char* data);

	// Функція, яка реалізує розшифрування блоку даних
	int feistel_decrypt(unsigned char* data, HANDLE hkey);
};

