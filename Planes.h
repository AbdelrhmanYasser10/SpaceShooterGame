#pragma once
#include<SFML\Graphics.hpp>
#define MaxPlanes 4
using namespace sf;

class planes
{
public:
	planes(float width, float high);
	void draw(RenderWindow& window);
	void moveRight();
	void moveLeft();
	int GetplanePressed() { return PlaneSelected; }
	~planes();
private:
	int PlaneSelected;
	Font font;
	Text fighter[MaxPlanes];
};