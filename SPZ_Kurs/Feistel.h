#pragma once
#include"Header.h"
extern int sizeFile;
class Feistel
{
private:
	unsigned char key;

public:
	unsigned char getKey();

	// �������, ��� ������� ��������� ������ ����� �����
	unsigned char rotate(unsigned char x, int n);

	// �������, ��� ������ ���� ����� ����� ��������
	void feistel_round(unsigned char& a, unsigned char& b, unsigned char key);

	void generateKey();

	// �������, ��� ������ ���������� ����� �����
	void feistel_encrypt(unsigned char* data);

	// �������, ��� ������ ������������� ����� �����
	int feistel_decrypt(unsigned char* data, HANDLE hkey);
};

