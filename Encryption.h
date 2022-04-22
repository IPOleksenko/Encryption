#pragma once

#include <string>
#include <iostream>


using namespace std;

extern class TextBox;

/*
*	Encryption and Decryption
*	Caesar cipher, Vernam cipher, Hill cipher, Vigenere cipher, Gronsfeld cipher, RSA
*/

class ENCRYPTION
{
	wstring text{}, newtext{}, key{};
	string choice{};

	TextBox InputKeyBox();

public:
	ENCRYPTION(wstring* text, string choice, wstring key)
	{
		this->text = *text;
		this->key = key;
		this->choice = choice;
	}


	wstring& Caesar(bool i) // �����- ���� ������
	{
		wcout << key;

		return text;
	}

	wstring& Vernam(bool i) // ����- �����
	{

		return text;
	}

	wstring& Hill(bool i) // ����- �������
	{

		return text;
	}

	wstring& Vigenere(bool i) // ����- ����������� � ������� ������ ������ ����� ����������� � ������ �� ��������� ������
	{

		return text;
	}

	wstring& Gronsfeld(bool i) // ����- ����� ����� (K) ������ ���� ������ ����� ��������� ������. ��� ����� ���������� ���������� ���� �� ��� ���, ���� ��� ����� �� ����� ��������������� ����� ��������� ������.
	{

		return text;
	}

	wstring& RSA(bool i) // ����- �������������� �����
	{

		return text;
	}


	wstring& Distributor(bool i)
	{
		if (choice == "Caesar cipher") { return ENCRYPTION::Caesar(i); }

		if (choice == "Vernam cipher") { return ENCRYPTION::Vernam(i); }

		if (choice == "Hill cipher") { return ENCRYPTION::Hill(i); }

		if (choice == "Vigenere cipher") { return ENCRYPTION::Vigenere(i); }

		if (choice == "Gronsfeld cipher") { return ENCRYPTION::Gronsfeld(i); }

		if (choice == "RSA") { return ENCRYPTION::RSA(i); }
	}
};