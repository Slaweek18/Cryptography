#include"Functions.h"

HANDLE createFileKey(LPCSTR pathKey) {
	HANDLE hkey = CreateFileA(pathKey, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hkey == INVALID_HANDLE_VALUE)
	{
		MessageBox::Show("���� ����� �� ������� �������", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
	return hkey;

}

//������������ System::string^ � std::string
std::string& Convert_String_to_string(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os, String^ s) {
	s = gcnew System::String(os.c_str());

	return s;
}

//������������ System::string^ � std::string
std::string& Convert_String_to_string(String^ s) {
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}

//������������ char � System::string^
System::String^ Convert_char_to_String(unsigned char ch) {

	System::String^ str;
		str += wchar_t(ch);
	return str;
}

//������������ System::string^ � char*
char* Convert_String_to_char(System::String^ string) {
	using namespace System::Runtime::InteropServices;
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

//������������ char* � System::string^
System::String^ Convert_char_to_String(char* ch) {
	char* chr = new char();
	chr = ch;
	System::String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch[i]);
	return str;
}