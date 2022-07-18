#pragma once

#include <iostream>
#include <string>

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
	
	inline int GetLen(wstring s) {
		int l = 0;
		for (int i = 0; s[i] != L'\0'; i++) {
			l++;
		}
		return l;
	}

	wstring& Caesar(bool mode) // Число- ключ сдвига
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

	wstring& Vernam(bool mode) // Ключ- текст
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

	wstring& Hill(bool mode) // Ключ- матрица // РЕАЛИЗОВАТЬ
	{
		if (mode) { return text; }
		else { return text; }
	}

	wstring& Vigenere(bool mode) // Ключ- придложение в котором каждое каждая буква соотносится к буквам из ввиденого текста
	{
		wstring ct = L"";
		for (int i = 0; i < text.size(); i++) {
			if (mode) { ct += (char)(((int)text[i] - L'A' + (int)key[i] - L'A') % 26) + L'A'; }
			else { ct += (char)((((int)text[i] - L'A' - ((int)key[i] - L'A')) + 26) % 26) + L'A'; }
		}
		return ct;
	}

	wstring& Gronsfeld(bool mode) // Ключ- Длина ключа (K) должна быть равной длине исходного текста. Для этого циклически записывают ключ до тех пор, пока его длина не будет соответствовать длине исходного текста.
	{
		int m_len = GetLen(text);

		if (GetLen(key) < 1)
		{
			key = L"0";
		}

		int ind = 0;
		while (m_len > GetLen(key)) {
			key += key[ind];
			ind++;
		}
		wstring encrypted;
		for (int i = 0; i < m_len; i++) {
			char ch = text[i];
			ch -= 97;
			ch += key[i] - L'0';
			ch %= 26;
			ch += 97;
			encrypted += ch;
		}

		//Decryption
		wstring decrypted;
		for (int i = 0; i < m_len; i++) {
			char ch = encrypted[i];
			ch -= 97;
			ch -= key[i] - L'0';
			while (ch < 0) {
				ch += 25;
			}
			ch += 97;
			decrypted += ch;
		}
		if (mode)
		{
			return encrypted;
		}
		else if(!mode) 
		{
			return decrypted;
		}
	}

	wstring& RSA(bool mode) // Ключ- четырехзначное число
	{
		if (mode) { return text; }
		else { return text; }
	}


	wstring* Distributor(bool mode)
	{
		if (choice == "Caesar cipher") { return &ENCRYPTION::Caesar(mode); }

		if (choice == "Vernam cipher") { return &ENCRYPTION::Vernam(mode); }

		if (choice == "Hill cipher") { return &ENCRYPTION::Hill(mode); }

		if (choice == "Vigenere cipher") { return &ENCRYPTION::Vigenere(mode); }

		if (choice == "Gronsfeld cipher") { return &ENCRYPTION::Gronsfeld(mode); }

		if (choice == "RSA") { return &ENCRYPTION::RSA(mode); }
	}
};

//Author: IPOleksenko