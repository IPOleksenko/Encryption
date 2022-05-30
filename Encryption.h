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
	wstring text{}, key{};
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
		unsigned int integer{};
		if (key != L"")
			return stoi(x);

		return 0;
	}

	wstring& Caesar(bool mode) // �����- ���� ������
	{
		unsigned int k = toInteger(key);

		wstring result{};

		if (mode)
			for (int i = 0; i < text.length(); i++)
			{
				{
					if ((!(96 < text[i]) && !(text[i] > 122)) && (!(64 < text[i]) && !(text[i] > 90)))
						result += text[i];
					else if (isupper(text[i]))
						result += char(int(text[i] + k - 65) % 26 + 65);
					else
						result += char(int(text[i] + k - 97) % 26 + 97);
				}
			}
		else
		{
			for (int i = 0; i < text.length(); i++)
			{
				if ((!(96 < text[i]) && !(text[i] > 122)) && (!(64 < text[i]) && !(text[i] > 90)))
					result += text[i];
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
		int i, j = 0, sum = 0;
		wstring ans = L"";

		if (key == L"")
			return text;

		int mod = key.size();
		for (i = key.size(); i < text.size(); i++) {
			key += key[j % mod];
			j++;
		}
		for (i = 0; i < text.size(); i++) {
			if (mode) { ans += (key[i] - L'A' + text[i] - L'A') % 26 + L'A'; }
			else { ans += (text[i] - key[i] + 26) % 26 + L'A'; }
		}

		return ans;
	}

	wstring& Hill(bool mode) // ����- ������� // �����������
	{

		return text;
	} 

	wstring& Vigenere(bool mode) // ����- ����������� � ������� ������ ������ ����� ����������� � ������ �� ��������� ������
	{
		wstring ct = L"";
		for (int i = 0; i < text.size(); i++)
			if (mode) { ct += (char)(((int)text[i] - L'A' + (int)key[i] - L'A') % 26) + L'A'; }
			else { ct += (char)((((int)text[i] - L'A' - (key[i] - L'A')) + 26) % 26) + L'A'; }

		return ct;
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

//Author: IPOleksenko