#include <iostream>
#include "window.h"
#include "TextBox.h"
#include "Encryption.cpp"

using namespace std;
using namespace sf;

#define NumberButton 11

Texture backgroundTexture; Sprite backgroundSprite;
Texture frameTexture[2]; Sprite frameSprite[2];
Image icon; Font font;

Text text[NumberButton];
const string* TEXT = new string[NumberButton]
				{"Input: ", "Output: ",
				"Encryption", "Decryption", 
				"Caesar cipher", "Vernam cipher", "Hill cipher", 
				"Vigenere cipher", "Gronsfeld cipher", "RSA" };

struct MyChoice { string MyChoice; }MyChoice;

int main()
{
	window.setFramerateLimit(30);

	TextBox InputBox(50, 90); //TextBox.h for input text
	TextBox OutputBox(50, 305);
	
	backgroundTexture.loadFromFile("texture/background.jpg"); //set background
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(
		window.getSize().x / backgroundSprite.getGlobalBounds().width,
		window.getSize().y / backgroundSprite.getGlobalBounds().height);

	for (int i = 0; i < 2; i++)
	{
		frameTexture[i].loadFromFile("texture/frame_" + to_string(i) + ".png"); //set frame
		frameSprite[i].setTexture(frameTexture[i]);
		frameSprite[i].setScale(
			460 / frameSprite[i].getGlobalBounds().width,
			175 / frameSprite[i].getGlobalBounds().height);
	}

	frameSprite[0].setPosition(0, 110.f);
	frameSprite[1].setPosition(0, 325.f);

	if (!icon.loadFromFile("texture/icon.png")) return EXIT_FAILURE; //load icon for window
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);

	if (!font.loadFromFile("font/font.ttf")) return EXIT_FAILURE; //load font

	for (int i = 0; i < NumberButton; i++) //set textures and sprites
	{
		if (i < NumberButton - 1) text[i].setString(TEXT[i]);
		text[i].setFont(font);
		text[i].setCharacterSize(24);
		text[i].setFillColor(Color::Red);

		if (i > 3 || i < NumberButton - 1) text[i].setPosition(500, 75 + ((i - 4) * 50));
	}

	text[0].setPosition(50, 75); //Input
	text[1].setPosition(50, 290); //Output

	text[2].setPosition(400, 500); //Encryption
	text[3].setPosition(600, 500); //Decryption

	MyChoice.MyChoice = TEXT[4];
	text[NumberButton - 1].setPosition(10, 10);

	int time[2] = { 3 , 3 };

	while (window.isOpen()) //drow sprite
	{
		time[0]++; time[1]++;

		text[NumberButton - 1].setString("Cipher: " + MyChoice.MyChoice);

		ENCRYPTION ENCRYPTION(InputBox.getText(), MyChoice.MyChoice);

		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
			{
				delete[]TEXT; TEXT = nullptr;
				window.close();
			}
		}

		window.clear();
		window.draw(backgroundSprite);

		for (int i = 0; i < 2; i++) window.draw(frameSprite[i]);

		window.draw(InputBox.drawtextbox()); 
		window.draw(OutputBox.drawtextbox());

		for (int i = 0; i < NumberButton; i++) { window.draw(text[i]); }

		for (int i = 2; i < NumberButton - 1; i++)text[i].setStyle(Text::Regular);


		if (time[0] > 4)
		{
			if (event.type == Event::TextEntered) // input text
			{
				if ((event.text.unicode < 128) || (1072 >= event.text.unicode <= 1103))
				{
					InputBox.inputText(static_cast<wchar_t>(event.text.unicode));
					time[0] = 0;
				}
			}
		}


		for (int i = 4; i < NumberButton - 1; i++)
		{
			if (event.type == Event::MouseButtonPressed) // add TEXT[i] in struct MyChoice
			{
				if (IntRect(text[i].getGlobalBounds()).contains(Mouse::getPosition(window)))
				{
					MyChoice.MyChoice = TEXT[i]; text[i].setStyle(Text::Bold);
				}
			}
		}


		if (time[1] >= 4)
			if (event.type == Event::MouseButtonPressed)
			{
				if (IntRect(text[2].getGlobalBounds()).contains(Mouse::getPosition(window)))// Encryption
				{
					OutputBox.setText(*ENCRYPTION.Distributor(true)); OutputBox.setString();
					//OutputBox.setString(*ENCRYPTION.Distributor(true));
					text[2].setStyle(Text::Bold);
					time[1] = 0;
				}

				if (IntRect(text[3].getGlobalBounds()).contains(Mouse::getPosition(window)))// Decryption
				{
					OutputBox.setText(*ENCRYPTION.Distributor(false)); OutputBox.setString();
					//OutputBox.setString(*ENCRYPTION.Distributor(false));
					text[3].setStyle(Text::Bold);
					time[1] = 0;
				}

			} 
		window.display();
	}
	return 0;
}