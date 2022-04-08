#pragma once

#include <iostream>
//#include <stdio.h>
#include <string>
//#include "TextBox.h"

using namespace std;

/*
*	Encryption and Decryption
*	Caesar cipher, Vernam cipher, Hill cipher, Vigenere cipher, Gronsfeld cipher, RSA
*/

class ENCRYPTION
{
	wstring text{}, newtext{}, key{};
	string choice{};

public:
	ENCRYPTION(wstring* text, string choice)
	{
		this->text = *text;
		this->choice = choice;
	}

	void inputKey()
	{

		key = L"0";
	}


	wstring Caesar(bool i)
	{

		return text;
	}

	wstring Vernam(bool i)
	{

		return text;
	}


	wstring Hill(bool i)
	{
		return text;
	}


	wstring Vigenere(bool i)
	{
		return text;
	}


	wstring Gronsfeld(bool i)
	{
		return text;
	}

	wstring RSA(bool i)
	{
		return text;
	}

	
	wstring* Distributor(bool i)
	{
		if (choice == "Caesar cipher")
		{
			return &ENCRYPTION::Caesar(i);
		}

		if (choice == "Vernam cipher")
		{
			{
				return &ENCRYPTION::Vernam(i);
			}
		}

		if (choice == "Hill cipher")
		{
			{
				return &ENCRYPTION::Hill(i);
			}
		}

		if (choice == "Vigenere cipher")
		{
			{
				return &ENCRYPTION::Vigenere(i);
			}
		}

		if (choice == "Gronsfeld cipher")
		{
			{
				return &ENCRYPTION::Gronsfeld(i);
			}
		}

		if (choice == "RSA")
		{
			{
				return &ENCRYPTION::RSA(i);
			}
		}
	}
};