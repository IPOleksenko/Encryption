#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
*	Encryption and Decryption
*	Caesar cipher, Vernam cipher, Hill cipher, Vigenere cipher, Gronsfeld cipher, RSA
*/

class ENCRYPTION
{
	wstring text{}, newtext{};
	string choice{};
public:
	ENCRYPTION(wstring* text, string choice)
	{
		this->text = *text;
		this->choice = choice;
	}

	wstring ECaesr()
	{

		return text;
	}
	wstring DCaesr()
	{

		return text;
	}

	wstring* Distributor(bool i)
	{
		if (choice == "Caesar cipher")
		{
			if (i) return &ENCRYPTION::ECaesr();
			else return &ENCRYPTION::DCaesr();
		}

		if (choice == "Vernam cipher")
		{
			{
				if (i) return 0;
				else return 0;
			}
		}

		if (choice == "Hill cipher")
		{
			{
				if (i) return 0;
				else return 0;
			}
		}

		if (choice == "Vigenere cipher")
		{
			{
				if (i) return 0;
				else return 0;
			}
		}

		if (choice == "Gronsfeld cipher")
		{
			{
				if (i) return 0;
				else return 0;
			}
		}

		if (choice == "RSA")
		{
			{
				if (i) return 0;
				else return 0;
			}
		}
	}
};