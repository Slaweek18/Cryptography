#pragma once
#include "Header.h"
using namespace System;
using namespace System::Windows::Forms;

HANDLE createFileKey(LPCSTR pathKey);
std::string& Convert_String_to_string(String^ s, std::string& os); //������������ System::string^ � std::string
String^ Convert_string_to_String(std::string& os, String^ s); //������������ std::string � System::string^
std::string& Convert_String_to_string(String^ s); //������������ System::string^ � std::string
String^ Convert_string_to_String(std::string& os); //������������ std::string � System::string^
System::String^ Convert_char_to_String(unsigned char ch); //������������ char* � System::string^
char* Convert_String_to_char(System::String^ string); //������������ System::string^ � char*