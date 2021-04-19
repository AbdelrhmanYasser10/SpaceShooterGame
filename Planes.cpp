#include "planes.h"

using namespace sf;


planes::planes (float width, float high)
{
	if (font.loadFromFile("Data/Fonts/Azonix.otf")) {}

	//Level1
	fighter[0].setFont(font);
	fighter[0].setFillColor(Color::Blue);
	fighter[0].setString("Fighter1");
	fighter[0].setCharacterSize(30);
	fighter[0].setPosition(Vector2f(10, 350));
	//Level2
	fighter[1].setFont(font);
	fighter[1].setFillColor(Color::White);
	fighter[1].setString("Fighter2");
	fighter[1].setCharacterSize(30);
	fighter[1].setPosition(Vector2f(210, 350));
	//Level3
	fighter[2].setFont(font);
	fighter[2].setFillColor(Color::White);
	fighter[2].setString("Fighter3");
	fighter[2].setCharacterSize(30);
	fighter[2].setPosition(Vector2f(420, 350));

	fighter[3].setFont(font);
	fighter[3].setFillColor(Color::White);
	fighter[3].setString("Fighter4");
	fighter[3].setCharacterSize(30);
	fighter[3].setPosition(Vector2f(620, 350));

	PlaneSelected = 0;

}


planes::~planes()
{
}
void planes::draw(RenderWindow& window) {
	for (int i = 0; i < 4; i++) {
		window.draw(fighter[i]);
	}
}
void planes::moveRight()
{
	if (PlaneSelected + 1 <= MaxPlanes) {
		fighter[PlaneSelected].setFillColor(sf::Color::White);
		PlaneSelected++;
		if (PlaneSelected == 4) {
			PlaneSelected = 0;
		}
		fighter[PlaneSelected].setFillColor(sf::Color::Blue);
	}
}
void planes::moveLeft()
{
	if (PlaneSelected - 1 >= -1) {
		fighter[PlaneSelected].setFillColor(sf::Color::White);
		PlaneSelected--;
		if (PlaneSelected == -1) {
			PlaneSelected = 3;
		}
		fighter[PlaneSelected].setFillColor(sf::Color::Blue);
	}

}