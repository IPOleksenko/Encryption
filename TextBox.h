#pragma once

#include <string>
#include "window.h"

using namespace std;
using namespace sf;

/*
*	TextBox modele 
*/

#define lensize 168

class TextBox
{
	int x, y;
	Font font{};
	Text textbox{};
	wstring input{};
public:
	TextBox(int x = 0, int y = 0, string font = "font/font.ttf")
	{
		this->x = x;
		this->y = y;
		this->font.loadFromFile(font);

		textbox.setFont(this->font);
		textbox.setFillColor(Color::Black);
		textbox.setPosition(x, y);
		textbox.setCharacterSize(24);
	}

	wstring* getText() { return &input; }

	wstring textEditor()
	{
		wstring str = *TextBox::getText();
		str.insert(0, L"\n");

		if (str.size() > lensize)
		{
			reverse(str.begin(), str.end());

			for (int i = 0; i < (lensize - str.size()); i++)
			{
				str.pop_back();
			}

			reverse(str.begin(), str.end());
			str.insert(0, L"\n");
		}

		int size = str.size() / 29;
		for (int i = 1; i <= size; i++) // input L"\n" befor 28 
		{
			size = str.size() / 29;
			str.insert(29 * i, L"\n");
		}

		return str;
	}

	void setString() { textbox.setString(TextBox::textEditor()); }
	void setString(wstring str) { textbox.setString(str); }

	void inputText(wchar_t i)
	{
		if (i != '\b')
		{
			input = input + i;
		}
		else if (input != "")
		{
			input.pop_back();
		}

		setString();

		return;
	}

	Text drawtextbox() { return textbox; }

};