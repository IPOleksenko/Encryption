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


	wstring& Caesar(bool i) // Число- ключ сдвига
	{
		wcout << key;

		return text;
	}

	wstring& Vernam(bool i) // Ключ- текст
	{

		return text;
	}

	wstring& Hill(bool i) // Ключ- матрица
	{

		return text;
	}

	wstring& Vigenere(bool i) // Ключ- придложение в котором каждое каждая буква соотносится к буквам из ввиденого текста
	{

		return text;
	}

	wstring& Gronsfeld(bool i) // Ключ- Длина ключа (K) должна быть равной длине исходного текста. Для этого циклически записывают ключ до тех пор, пока его длина не будет соответствовать длине исходного текста.
	{

		return text;
	}

	wstring& RSA(bool i) // Ключ- четырехзначное число
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