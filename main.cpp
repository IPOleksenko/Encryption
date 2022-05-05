#include "window.h"
#include "TextBox.h"
#include "Encryption.h"

using namespace std;
using namespace sf;

#define NumberButton 12
#define NumberFrame 3

Texture backgroundTexture; Sprite backgroundSprite;
Texture frameTexture[NumberFrame]; Sprite frameSprite[NumberFrame];
Image icon; Font font;

Text text[NumberButton];
const string* TEXT = new string[NumberButton]
				{"Input: ", "Output: ", "Key: ",
				"Encryption", "Decryption", 
				"Caesar cipher", "Vernam cipher", "Hill cipher", 
				"Vigenere cipher", "Gronsfeld cipher", "RSA" };

struct MyChoice
{
	string MyChoice; 
}MyChoice;

int main()
{
	window.setFramerateLimit(30);

	TextBox InputBox(50, 90); //TextBox.h for input text
	TextBox OutputBox(50, 305);
	TextBox KeyInput(500.f, 400.f, 14);//заменить

	backgroundTexture.loadFromFile("texture/background.jpg"); //set background
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(
		window.getSize().x / backgroundSprite.getGlobalBounds().width,
		window.getSize().y / backgroundSprite.getGlobalBounds().height);

	for (int i = 0; i < NumberFrame; i++)
	{
		frameTexture[i].loadFromFile("texture/frame_" + to_string(i) + ".png"); //set frame
		frameSprite[i].setTexture(frameTexture[i]);
		if (i < NumberFrame - 1)
		{
			frameSprite[i].setScale(
				460 / frameSprite[i].getGlobalBounds().width,
				175 / frameSprite[i].getGlobalBounds().height);
		}
		else
		{
			frameSprite[i].setScale(
				200 / frameSprite[i].getGlobalBounds().width,
				40 / frameSprite[i].getGlobalBounds().height);
		}
	}

	frameSprite[0].setPosition(0.f, 110.f);
	frameSprite[1].setPosition(0.f, 325.f);
	frameSprite[2].setPosition(500.f, 425.f);

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

		if (i > 4) text[i].setPosition(500, 75 + ((i - 5) * 50));
	}

	text[0].setPosition(50.f, 75.f); //Input
	text[1].setPosition(50.f, 290.f); //Output
	text[2].setPosition(500.f, 390.f); //Key


	text[3].setPosition(400.f, 500.f); //Encryption
	text[4].setPosition(600.f, 500.f); //Decryption

	MyChoice.MyChoice = TEXT[5];
	text[NumberButton - 1].setPosition(10, 10);

	int time[2] = { 3 , 3 };
	bool WhichFrame = 0;

	while (window.isOpen()) //drow sprite
	{
		if (time[0] <= 4 || time[1] <= 4)
			time[0]++; time[1]++;

		text[NumberButton - 1].setString("Cipher: " + MyChoice.MyChoice);

		ENCRYPTION ENCRYPTION(InputBox.getText(), MyChoice.MyChoice, KeyInput.getText());

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

		for (int i = 0; i < NumberFrame; i++) window.draw(frameSprite[i]);

		window.draw(InputBox.drawtextbox());
		window.draw(OutputBox.drawtextbox());
		window.draw(KeyInput.drawtextbox());

		for (int i = 0; i < NumberButton; i++) { window.draw(text[i]); }

		for (int i = 3; i < NumberButton - 1; i++)text[i].setStyle(Text::Regular);


		if (time[0] > 4)
		{
			if (event.type == Event::TextEntered) // input text
			{
				unsigned int symbolText = event.text.unicode;

				if (WhichFrame == 0)
					if ((symbolText < 128)) //  || (1072 >= event.text.unicode <= 1103)			-		for RUS and UKR language
					{
						{
							InputBox.inputText(static_cast<wchar_t>(symbolText));
						}
						time[0] = 0;
					}

				if (WhichFrame == 1) // input key
				{
					if (MyChoice.MyChoice == "Caesar cipher")
					{
						if ((48 <= symbolText) && (symbolText <= 57) || symbolText == 8) {
							KeyInput.inputText(static_cast<wchar_t>(symbolText));
						}
					}

					else if (MyChoice.MyChoice == "Vernam cipher")
					{
						KeyInput.inputText(static_cast<wchar_t>(symbolText));
					}

					else if (MyChoice.MyChoice == "Hill cipher")	//	breake this
					{
						KeyInput.inputText(static_cast<wchar_t>(symbolText));
					}

					else if (MyChoice.MyChoice == "Vigenere cipher")
					{
						KeyInput.inputText(static_cast<wchar_t>(symbolText));
					}

					else if (MyChoice.MyChoice == "Gronsfeld cipher")
					{
						KeyInput.inputText(static_cast<wchar_t>(symbolText));
					}

					else if (MyChoice.MyChoice == "RSA")
					{
						KeyInput.inputText(static_cast<wchar_t>(symbolText));
					}

					time[0] = 0;
				}
			}
		}

		if (event.type == Event::MouseButtonPressed) // add TEXT[i] in struct MyChoice
		{
			for (int i = 5; i < NumberButton - 1; i++)
			{
				if (IntRect(text[i].getGlobalBounds()).contains(Mouse::getPosition(window)))
				{
					MyChoice.MyChoice = TEXT[i]; 
					text[i].setStyle(Text::Bold);
					KeyInput.setText(L""); 
					KeyInput.setString();
				}
			}		
		}

		if (Mouse::isButtonPressed(Mouse::Left)) // frameSprite[0]
		{
			if (frameSprite[0].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) WhichFrame = 0;
			else if (frameSprite[2].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) WhichFrame = 1;
		}

		if (time[1] >= 4)
			if (event.type == Event::MouseButtonPressed)
			{
				if (IntRect(text[3].getGlobalBounds()).contains(Mouse::getPosition(window)))// Encryption
				{
					OutputBox.setText(ENCRYPTION.Distributor(true));
					OutputBox.setString();
					text[3].setStyle(Text::Bold);
					time[1] = 0;
				}

				if (IntRect(text[4].getGlobalBounds()).contains(Mouse::getPosition(window)))// Decryption
				{
					OutputBox.setText(ENCRYPTION.Distributor(false));
					OutputBox.setString();
					text[4].setStyle(Text::Bold);
					time[1] = 0;
				}
			}
		
		window.display();
	}
	return 0;
}