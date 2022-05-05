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
	ENCRYPTION(wstring* text, string choice, wstring* key)
	{
		this->text = *text;
		this->key = *key;
		this->choice = choice;
	}

	inline unsigned int toInteger(wstring x)
	{
		unsigned integer{};
		for (unsigned int i : x)
		{
			integer = i - 48;
		}
		return integer;
	}

	wstring& Caesar(bool mode) // �����- ���� ������
	{
		unsigned int k = toInteger(key);

		wstring result{};

		if (mode)
		{
			for (int i = 0; i < text.length(); i++)
			{
				if (isupper(text[i]))
					result += char(int(text[i] + k - 65) % 26 + 65);
				else
					result += char(int(text[i] + k - 97) % 26 + 97);
			}
		}
		else 
		{
			for (int i = 0; i < text.length(); i++)
			{
				if (isupper(text[i]))
					result += char(int(text[i] - k - 65) % 26 + 65);
				else
					result += char(int(text[i] - k - 97) % 26 + 97);
			}
		}

		return result;
	}

	wstring& Vernam(bool mode) // ����- �����
	{

		return text;
	}

	wstring& Hill(bool mode) // ����- �������
	{

		return text;
	}

	wstring& Vigenere(bool mode) // ����- ����������� � ������� ������ ������ ����� ����������� � ������ �� ��������� ������
	{

		return text;
	}

	wstring& Gronsfeld(bool mode) // ����- ����� ����� (K) ������ ���� ������ ����� ��������� ������. ��� ����� ���������� ���������� ���� �� ��� ���, ���� ��� ����� �� ����� ��������������� ����� ��������� ������.
	{

		return text;
	}

	wstring& RSA(bool mode) // ����- �������������� �����
	{

		return text;
	}


	wstring& Distributor(bool mode)
	{
		if (choice == "Caesar cipher") { return ENCRYPTION::Caesar(mode); }

		if (choice == "Vernam cipher") { return ENCRYPTION::Vernam(mode); }

		if (choice == "Hill cipher") { return ENCRYPTION::Hill(mode); }

		if (choice == "Vigenere cipher") { return ENCRYPTION::Vigenere(mode); }

		if (choice == "Gronsfeld cipher") { return ENCRYPTION::Gronsfeld(mode); }

		if (choice == "RSA") { return ENCRYPTION::RSA(mode); }
	}
};