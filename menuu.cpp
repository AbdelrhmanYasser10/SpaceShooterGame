#include "menuu.h"
using namespace sf;



menuu::menuu(float width, float high)
{
	if (font.loadFromFile("Data/Fonts/Moondance.otf")) {}
	// play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("play");
	mainMenu[0].setCharacterSize(30);
	mainMenu[0].setPosition(Vector2f(350, 200));
	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString(" Sounds and Instructions");
	mainMenu[1].setCharacterSize(30);
	mainMenu[1].setPosition(Vector2f(175, 250));
	//Credits
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Credits");
	mainMenu[2].setCharacterSize(30);
	mainMenu[2].setPosition(Vector2f(328, 300));

	//about
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("About");
	mainMenu[3].setCharacterSize(30);
	mainMenu[3].setPosition(Vector2f(335, 350));
	//Exit
	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(Color::White);
	mainMenu[4].setString("Exit");
	mainMenu[4].setCharacterSize(30);
	mainMenu[4].setPosition(Vector2f(355, 400));

	mainMenuselected = 0;

}


menuu::~menuu()
{
}
void menuu::draw(RenderWindow& window) {
	for (int i = 0; i <= 4; i++) {
		window.draw(mainMenu[i]);
	}
}
void menuu::moveDown()
{
	if (mainMenuselected + 1 <= MaxMainMenu) {
		mainMenu[mainMenuselected].setFillColor(sf::Color::White);
		mainMenuselected++;
		if (mainMenuselected == 5) {
			mainMenuselected = 0;
		}
		mainMenu[mainMenuselected].setFillColor(sf::Color::Blue);
		
	}
}
void menuu::moveUp()
{
	if (mainMenuselected - 1 >= -1) {
		mainMenu[mainMenuselected].setFillColor(sf::Color::White);
		mainMenuselected--;
		if (mainMenuselected == -1) {
			mainMenuselected = 4;
		}
		mainMenu[mainMenuselected].setFillColor(sf::Color::Blue);
	}
}