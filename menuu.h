#pragma once
#include<SFML\Graphics.hpp>
#define MaxMainMenu 5
using namespace sf;
class menuu
{
public:
	menuu(float width, float high);
	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();
	int Getpresseditem() { return mainMenuselected; }
	~menuu();
private:
	int mainMenuselected;
	Font font;
	Text mainMenu[MaxMainMenu];
};