#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "menuu.h"
#include "Levels.h"
#include "planes.h"
#include <time.h>
#include <vector>


using namespace sf;

using namespace std;

int About(bool, int);  //Used

int Play(bool, int);   //Used

int PlanesF(bool, int);  //Used

int options(bool); //Used

void credits(bool, int); //Used

void Win_Lose(bool, int); //used 

void LevelsF(int, int);  //Used

int check(int);



int main() {
	//window of game setup
	RenderWindow window(VideoMode(800, 600), "Space shooter");
	menuu menu(800, 600);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);


	//Stats
	bool Boptions = false;
	bool BAbout = false;
	bool BPlay = false;

	//variables
	int test = 1;

	// Sound
	SoundBuffer introduction;
	if (introduction.loadFromFile("Data/Sounds/end.wav") == 0)
	{
		return 1;
	}
	Sound Back;
	Back.setBuffer(introduction);
	Back.play();
	Back.setLoop(true);
	if (test == 2) {
		Back.stop();
	}

	//Images
	Texture intro;
	Texture fighter1, fighter2, fighter3, fighter4;
	if (intro.loadFromFile("Data/Texture/intro.png") == -1)
	{
		return 1;
	}
	if (fighter1.loadFromFile("Data/Texture/fighter1.png") == -1)
	{
		return 1;
	}
	if (fighter2.loadFromFile("Data/Texture/fighter2.png") == -1)
	{
		return 1;
	}
	if (fighter3.loadFromFile("Data/Texture/fighter3.png") == -1)
	{
		return 1;
	}
	if (fighter4.loadFromFile("Data/Texture/fighter4.png") == -1)
	{
		return 1;
	}

	//shaps
	RectangleShape rect1;

	rect1.setSize(Vector2f(800, 600));
	rect1.setPosition(Vector2f(0, 0));
	rect1.setFillColor(Color::White);
	rect1.setTexture(&intro);


	//Window Display Main Menu
	while (window.isOpen())
	{

		//Events
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case::sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.moveUp();
					break;
				case::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.Getpresseditem())
					{
					case 0:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							cout << "Play Pressed" << endl;
							BPlay = true;
							Back.stop();
							bool result = Play(BPlay, test);
							if (test == 2) {
								Back.stop();
							}
							if (test == 1) {
								Back.play();
							}
						}
						break;
					case 1:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							cout << "Options Pressed" << endl;
							Boptions = true;
							test = options(Boptions);
							if (test == 2) {
								Back.stop();
							}
							if (test == 1) {
								Back.play();
							}
						}
						break;
					case 2:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							cout << "Credits Pressed" << endl;
							Back.stop();
							credits(true, test);
							if (test == 2) {
								Back.stop();
							}
							if (test == 1) {
								Back.play();
							}
						}
							
						break;
					case 3:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							cout << "About Pressed" << endl;
							BAbout = true;
							Back.stop();
							bool result = About(BAbout, test);
							if (test == 2) {
								Back.stop();
							}
							if (test == 1) {
								Back.play();
							}
						}
						break;
					case 4:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter)
							window.close();
						break;
					}
				}
				break;
			case::sf::Event::Closed:
				window.close();
				break;
			}

		}


		//Drawing
		window.clear();
		window.draw(rect1);
		menu.draw(window);
		window.display();
	}
	window.close();
	return 0;
}



int About(bool a, int b) {
	//window of game setup
	RenderWindow window(VideoMode(800, 600), "Space shooter");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	// Sound
	SoundBuffer introduction;
	if (introduction.loadFromFile("Data/Sounds/end.wav")) {}
	Sound Back;
	Back.setBuffer(introduction);
	Back.play();
	if (b == 2) {
		Back.stop();
	}

	//pic
	Texture AboutW;
	if (AboutW.loadFromFile("Data/Texture/AboutWindow.png") == -1) {
		return 1;
	}


	//window shape
	RectangleShape AboutWindow;

	AboutWindow.setSize(Vector2f(800, 600));
	AboutWindow.setPosition(Vector2f(0, 0));
	AboutWindow.setFillColor(Color::White);
	AboutWindow.setTexture(&AboutW);




	//window
	while (window.isOpen())
	{

		//Events
		Event event;

		while (window.pollEvent(event))

		{
			switch (event.type)
			{

			case::sf::Event::KeyPressed:

				switch (event.key.code)
				{

				case Keyboard::Escape:

					window.close();

					break;
				}
			}
		}
		window.clear();
		window.draw(AboutWindow);
		window.display();
	}

	return 0;
}


int options(bool a) {
	RenderWindow window(VideoMode(800, 600), "Options Window");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	bool SoundYes = true;
	bool SoundNo = false;

	Texture OptionW;
	OptionW.loadFromFile("Data/Texture/optionswindow.png");

	RectangleShape OptionWindow;
	OptionWindow.setPosition(0, 0);
	OptionWindow.setSize(Vector2f(800, 600));
	OptionWindow.setTexture(&OptionW);

	//Sound question
	Font question;
	if (question.loadFromFile("Data/Fonts/Audiowide-Regular.ttf")) {}
	Text YesRec, NoRec;
	YesRec.setFont(question);
	YesRec.setFillColor(Color::Red);
	YesRec.setString("ON");
	YesRec.setCharacterSize(40);
	YesRec.setPosition(Vector2f(350, 137));

	NoRec.setFont(question);
	NoRec.setFillColor(Color::White);
	NoRec.setString("OFF");
	NoRec.setCharacterSize(40);
	NoRec.setPosition(Vector2f(600, 137));

	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case::Event::KeyPressed:
				switch (event.key.code)
				{
				case::Keyboard::Escape:
					window.close();
					break;
				case::Keyboard::Right:
					YesRec.setFillColor(Color::White);
					NoRec.setFillColor(Color::Red);
					SoundYes = false;
					SoundNo = true;
					break;
				case::Keyboard::Left:
					YesRec.setFillColor(Color::Red);
					NoRec.setFillColor(Color::White);
					SoundYes = true;
					SoundNo = false;
					break;
				case::Keyboard::Enter:
					if (SoundYes == true) {
						return 1;
					}
					if (SoundNo == true) {
						return 2;
					}
				}
				break;
			}
		}
		window.clear();
		window.draw(OptionWindow);
		window.draw(YesRec);
		window.draw(NoRec);
		window.display();
	}

	return 0;
}


void credits(bool a, int b) {
	RenderWindow window(VideoMode(750, 750), "Credits Window");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Texture CreditsW;
	CreditsW.loadFromFile("Data/Texture/Credits Window.png");

	RectangleShape CreditsWindow;
	CreditsWindow.setPosition(0, 0);
	CreditsWindow.setSize(Vector2f(750, 750));
	CreditsWindow.setTexture(&CreditsW);

	// Sound
	SoundBuffer introduction;
	if (introduction.loadFromFile("Data/Sounds/intro.wav")) {}
	Sound Back;
	Back.setBuffer(introduction);
	Back.play();
	if (b == 2) {
		Back.stop();
	}


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case::Event::KeyPressed:
				switch (event.key.code)
				{
				case::Keyboard::Escape:
					window.close();
					break;

				}
				break;
			}
		}
		window.clear();
		window.draw(CreditsWindow);
		window.display();
	}

}


int PlanesF(bool a, int b)
{
	RenderWindow window(VideoMode(800, 600), "Choose Your Plane");
	planes plane(800, 600);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	//sound
	SoundBuffer Select;
	if (Select.loadFromFile("Data/Sounds/SelectSound.wav") == 0)
	{
		return 1;
	}
	Sound SelectSound;
	SelectSound.setBuffer(Select);

	//window Texture

	Texture Tplane;
	if (Tplane.loadFromFile("Data/Texture/Planswindow.png") == -1)
	{
		return 1;
	}
	//Background of window set up
	RectangleShape Rplan;
	Rplan.setSize(Vector2f(800, 600));
	Rplan.setPosition(Vector2f(0, 0));
	Rplan.setFillColor(Color::White);
	Rplan.setTexture(&Tplane);

	//Images of planes

	Texture fighter1, fighter2, fighter3, fighter4;
	if (fighter1.loadFromFile("Data/Texture/fighter1.png") == -1) {
		return 1;
	}
	if (fighter2.loadFromFile("Data/Texture/fighter2.png") == -1) {
		return 1;
	}
	if (fighter3.loadFromFile("Data/Texture/fighter3.png") == -1) {
		return 1;
	}
	if (fighter4.loadFromFile("Data/Texture/fighter4.png") == -1) {
		return 1;
	}

	//shaps of planes

	RectangleShape plane1, plane2, plane3, plane4;

	plane1.setSize(Vector2f(100, 100));
	plane1.setPosition(Vector2f(40, 250));
	plane1.setFillColor(Color::White);
	plane1.setTexture(&fighter1);

	plane2.setSize(Vector2f(100, 100));
	plane2.setPosition(Vector2f(243, 250));
	plane2.setFillColor(Color::White);
	plane2.setTexture(&fighter2);

	plane3.setSize(Vector2f(100, 100));
	plane3.setPosition(Vector2f(452, 250));
	plane3.setFillColor(Color::White);
	plane3.setTexture(&fighter3);

	plane4.setSize(Vector2f(100, 100));
	plane4.setPosition(Vector2f(652, 250));
	plane4.setFillColor(Color::White);
	plane4.setTexture(&fighter4);

	//stats
	bool Bfigher1 = false;
	bool Bfigher2 = false;
	bool Bfigher3 = false;
	bool Bfigher4 = false;

	while (window.isOpen())
	{

		//Events
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case::sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Right:
					plane.moveRight();
					SelectSound.play();
					if (b == 2) {
						SelectSound.stop();
					}
					break;
				case::Keyboard::Left:
					plane.moveLeft();
					SelectSound.play();
					if (b == 2) {
						SelectSound.stop();
					}
					break;
				case Keyboard::Escape:
					return -1;
					window.close();
					break;

				case sf::Keyboard::Return:
					switch (plane.GetplanePressed())
					{
					case 0:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							return 1;
							Bfigher1 = true;
							window.close();
						}
						break;
					case 1:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							Bfigher2 = true;
							return 2;
							window.close();
						}
						break;
					case 2:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							Bfigher3 = true;
							return 3;
							window.close();
						}

						break;
					case 3:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							Bfigher4 = true;
							return 4;
							window.close();
						}
						break;
					}
					break;
				}
				break;
			}
		}

		window.clear();
		window.draw(Rplan);
		plane.draw(window);
		window.draw(plane1);
		window.draw(plane2);
		window.draw(plane3);
		window.draw(plane4);
		window.display();
	}
}


int Play(bool a, int b)
{
	//Window of levels
	RenderWindow window(VideoMode(800, 600), "Space shooter");
	Levels Level(800, 600);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	int result = 0;


	Texture TPlay;
	if (TPlay.loadFromFile("Data/Texture/LevelsWindow.png") == -1)
	{
		return 1;
	}



	SoundBuffer SPlay;
	if (SPlay.loadFromFile("Data/Sounds/back.wav") == 0)
	{
		return 1;
	}
	//sound
	SoundBuffer Select;
	if (Select.loadFromFile("Data/Sounds/SelectSound.wav") == 0)
	{
		return 1;
	}
	Sound SelectSound;
	SelectSound.setBuffer(Select);

	Sound BackPlay;
	BackPlay.setBuffer(SPlay);
	BackPlay.setLoop(true);
	if (b == 1) {
		BackPlay.play();
	}
	if (b == 2) {
		BackPlay.stop();
	}


	RectangleShape PlayWindow;
	PlayWindow.setSize(Vector2f(800, 600));
	PlayWindow.setPosition(Vector2f(0, 0));
	PlayWindow.setFillColor(Color::White);
	PlayWindow.setTexture(&TPlay);


	while (window.isOpen()) {


		//Events in GameLoop
		Event event;
		while (window.pollEvent(event))

		{
			switch (event.type)
			{
			case::sf::Event::KeyPressed:

				switch (event.key.code)
				{
				case Keyboard::Up:
					Level.moveUp();
					if (b == 1) {
						SelectSound.play();
					}
					if (b == 2) {
						SelectSound.stop();
					}
					break;
				case::Keyboard::Down:
					Level.moveDown();
					if (b == 1) {
						SelectSound.play();
					}
					if (b == 2) {
						SelectSound.stop();
					}
					break;
				case Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Return:
					switch (Level.GetLevelPressed())
					{
					case 0:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							window.close();
							BackPlay.stop();
							LevelsF(1, b);
							break;
						}

						break;
					case 1:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {

							window.close();
							BackPlay.stop();
							LevelsF(2, b);

							break;
						}

						break;
					case 2:
						if (Event::KeyPressed && event.key.code == Keyboard::Enter) {
							window.close();
							BackPlay.stop();
							LevelsF(3, b);

							break;
						}
					}
				}
			}
		}
		//Rendring
		window.clear();
		window.draw(PlayWindow);
		Level.draw(window);
		window.display();
	}

	return 0;
}


void LevelsF(int a, int b)
{
	float Xposition = 880, Yposition = 950;

	//Level 1
	if (a == 1) {
		RenderWindow FrLevel(VideoMode(1920, 1080), "First Level", Style::Fullscreen);
		FrLevel.setFramerateLimit(60);
		FrLevel.setKeyRepeatEnabled(false);


		//Shoottime
		int shoottimer = 0;

		//Drop time
		int droptime = 0;

		//Enemy Move
		float enemymove = 2;
		bool border1 = false, border2 = false;

		//Score
		int score = 0;


		//Planes
		Texture fighter1, fighter2, fighter3, fighter4, Level1window;
		fighter1.loadFromFile("Data/Texture/fighter1.png");


		fighter2.loadFromFile("Data/Texture/fighter2.png");


		fighter3.loadFromFile("Data/Texture/fighter3.png");


		fighter4.loadFromFile("Data/Texture/fighter4.png");


		Level1window.loadFromFile("Data/Texture/Level1Window.png");


		//sounds
		SoundBuffer  fire;

		fire.loadFromFile("Data/Sounds/move.wav");

		Sound  shootsound;
		shootsound.setBuffer(fire);

		//Background
		RectangleShape Level0;
		Level0.setSize(Vector2f(1920, 1080));
		Level0.setPosition(Vector2f(0, 0));
		Level0.setFillColor(Color::White);
		Level0.setTexture(&Level1window);

		//images
		Texture Enemy1, Enemy2;
		Enemy1.loadFromFile("Data/Texture/Enemy.png");

		Enemy2.loadFromFile("Data/Texture/Enemy2.png");


		//weapons
		//1
		Texture Bullet1;
		Bullet1.loadFromFile("Data/Texture/shoot1.png");


		//2
		Texture Bullet2;
		Bullet2.loadFromFile("Data/Texture/shoot2.png");


		//3
		Texture Bullet3;
		Bullet3.loadFromFile("Data/Texture/shoot3.png");

		//4
		Texture Bullet4;
		Bullet4.loadFromFile("Data/Texture/shoot4.png");

		//Enemy Rows
		float xenemy = 450;
		Sprite EnemiesR1[12];
		Sprite EnemiesR2[12];
		Sprite EnemiesR3[12];
		Sprite EnemiesR4[12];
		for (int i = 0; i < 12; i++) {
			//1
			EnemiesR1[i].setTexture(Enemy1);
			EnemiesR1[i].setPosition(xenemy, 50);
			EnemiesR1[i].setScale(0.65, 0.55);
			//2
			EnemiesR2[i].setTexture(Enemy1);
			EnemiesR2[i].setPosition(xenemy, 150);
			EnemiesR2[i].setScale(0.65, 0.55);
			//3
			EnemiesR3[i].setTexture(Enemy2);
			EnemiesR3[i].setPosition(xenemy, 250);
			EnemiesR3[i].setScale(0.65, 0.55);
			//4
			EnemiesR4[i].setTexture(Enemy2);
			EnemiesR4[i].setPosition(xenemy, 350);
			EnemiesR4[i].setScale(0.65, 0.55);
			xenemy = xenemy + 130;
		}

		// Bullets && Weapons
		CircleShape bullet;
		bullet.setRadius(10);
		vector <CircleShape> Fire;
		Fire.push_back(CircleShape(bullet));

		// Objects Shape
		Texture Object;
		Object.loadFromFile("Data/Texture/object1.png");


		CircleShape objectR1, objectR2, objectR3, objectR4;
		//1
		objectR1.setRadius(12.5);
		objectR1.setTexture(&Object);
		vector <CircleShape> dropR1;
		dropR1.push_back(CircleShape(objectR1));
		//2
		objectR2.setRadius(12.5);
		objectR2.setTexture(&Object);
		vector <CircleShape> dropR2;
		dropR2.push_back(CircleShape(objectR2));
		//3
		objectR3.setRadius(12.5);
		objectR3.setTexture(&Object);
		vector <CircleShape> dropR3;
		dropR3.push_back(CircleShape(objectR3));
		//4
		objectR4.setRadius(12.5);
		objectR4.setTexture(&Object);
		vector <CircleShape> dropR4;
		dropR4.push_back(CircleShape(objectR4));


		bool Bright = false, Bleft = false, Bup = false, Bdown = false, space = false;
		Sprite fighter;

		//Set up planes
		int result = PlanesF(true, b);

		if (result == 1) {
			fighter.setTexture(fighter1);
			fighter.setPosition(Xposition, Yposition);

			//Weapon Shape
			bullet.setTexture(&Bullet1);

		}
		else if (result == 2) {
			fighter.setTexture(fighter2);
			fighter.setPosition(Xposition, Yposition);

			//Weapon Shape
			bullet.setTexture(&Bullet2);
		}
		else if (result == 3) {
			fighter.setTexture(fighter3);
			fighter.setPosition(Xposition, Yposition);

			//Weapon Shape
			bullet.setTexture(&Bullet3);
		}
		else if (result == 4) {
			fighter.setTexture(fighter4);
			fighter.setPosition(Xposition, Yposition);

			//Weapon Shape
			bullet.setTexture(&Bullet4);
		}
		else if (result == -1) {
			FrLevel.close();
		}


		while (FrLevel.isOpen())
		{
			//Logics Per Movement
			Event event1;
			while (FrLevel.pollEvent(event1))
			{
				//Events Cases
				switch (event1.type)
				{
				case::Event::KeyPressed:
				{
					switch (event1.key.code)
					{
					case Keyboard::Right:
						Bright = true;
						break;

					case Keyboard::Left:
						Bleft = true;
						break;

					case Keyboard::Up:
						Bup = true;
						break;

					case Keyboard::Down:
						Bdown = true;
						break;
					case Keyboard::Space:
						if (shoottimer >= 3) {
							bullet.setPosition(fighter.getPosition().x + 43, fighter.getPosition().y + 15);
							Fire.push_back(CircleShape(bullet));
							shoottimer = 0;
							shootsound.play();
							if (b == 2) {
								shootsound.stop();
							}
						}
						break;

					case::Keyboard::Escape:
						FrLevel.close();
						break;
					}
					break;

				}
				case::Event::KeyReleased:
				{
					switch (event1.key.code)
					{
					case::Keyboard::Right:
						Bright = false;
					case::Keyboard::Left:
						Bleft = false;
					case::Keyboard::Up:
						Bup = false;
					case::Keyboard::Down:
						Bdown = false;
					}
				}
				}

			}
			//Logic
			if (Bright == true) {
				if (Xposition < 1800) {
					fighter.move(10, 0);
					Xposition = Xposition + 10;
				}
			}

			if (Bleft == true) {
				if (Xposition > 5) {
					fighter.move(-10, 0);
					Xposition = Xposition - 10;
				}
			}
			if (Bup == true) {
				if (Yposition > 750) {
					fighter.move(0, -10);
					Yposition = Yposition - 10;
				}
			}
			if (Bdown == true) {
				if (Yposition < 950) {
					fighter.move(0, 10);
					Yposition = Yposition + 10;
				}
			}


			//Shoot Updates
			if (shoottimer < 10) {
				shoottimer++;
			}

			for (int i = 0; i < Fire.size(); i++) {
				Fire[i].move(0, -5);
				if (Fire[i].getPosition().y < 0)
					Fire.erase(Fire.begin() + i);

			}

			for (int i = 0; i < 12; i++)
			{
				//Move
				EnemiesR1[i].move(enemymove, 0);
				EnemiesR2[i].move(enemymove, 0);
				EnemiesR3[i].move(enemymove, 0);
				EnemiesR4[i].move(enemymove, 0);


				//To solve The bug problem
				EnemiesR1[0].setPosition(EnemiesR1[11].getPosition().x - 1500, EnemiesR1[11].getPosition().y);
				EnemiesR2[0].setPosition(EnemiesR2[11].getPosition().x - 1500, EnemiesR2[11].getPosition().y);
				EnemiesR3[0].setPosition(EnemiesR3[11].getPosition().x - 1500, EnemiesR3[11].getPosition().y);
				EnemiesR4[0].setPosition(EnemiesR4[11].getPosition().x - 1500, EnemiesR4[11].getPosition().y);


				//Condition to Change the move from right to left
				if (EnemiesR1[11].getPosition().x >= 1900 && EnemiesR2[11].getPosition().x >= 1900 && EnemiesR3[11].getPosition().x >= 1900) {
					border1 = true;
					border2 = false;
				}

				else if (EnemiesR1[0].getPosition().x == -190 && EnemiesR2[0].getPosition().x == -190 && EnemiesR3[0].getPosition().x == -190) {
					border2 = true;
					border1 = false;
				}

				//Conditions To Change the direction of motion
				if (border1 == true)
					enemymove = -2;
				if (border2 == true)
					enemymove = 2;

			}


			//Objects Collision
			for (int j = 1; j < dropR1.size(); j++) {
				if (dropR1[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}

			for (int j = 1; j < dropR2.size(); j++) {
				if (dropR2[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}
			for (int j = 1; j < dropR3.size(); j++) {
				if (dropR3[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {

					FrLevel.close();
					Win_Lose(false, b);
				}
			}
			for (int j = 1; j < dropR4.size(); j++) {
				if (dropR4[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}

			//Drop Updates
			if (droptime < 100) {
				droptime++;
			}

			if (droptime >= 100) {
				//RANDOM LOCATION FOR EVERY ROW
				int Random1 = rand() % 10 + 1;
				int Random2 = rand() % 10 + 1;
				int Random3 = rand() % 10 + 1;
				int Random4 = rand() % 10 + 1;

				//POSITIONS OF OBJECTS
				objectR1.setPosition(EnemiesR1[Random1].getPosition().x + 50, EnemiesR1[Random1].getPosition().y + 75);
				objectR2.setPosition(EnemiesR2[Random2].getPosition().x + 50, EnemiesR2[Random2].getPosition().y + 75);
				objectR3.setPosition(EnemiesR3[Random3].getPosition().x + 50, EnemiesR3[Random3].getPosition().y + 75);
				objectR4.setPosition(EnemiesR4[Random4].getPosition().x + 50, EnemiesR4[Random4].getPosition().y + 75);

				//PUSH BACK OF OBJECTS
				dropR1.push_back(CircleShape(objectR1));
				dropR2.push_back(CircleShape(objectR2));
				dropR3.push_back(CircleShape(objectR3));
				dropR4.push_back(CircleShape(objectR4));

				droptime = 0;
			}
			//MOVE OF OBJECTS IN EVERY ROW
			for (int j = 1; j < dropR1.size(); j++) {
				dropR1[j].move(0, 5);
				if (dropR1[j].getPosition().y > 1080 && dropR1[j].getPosition().y < 0)
					dropR1.erase(dropR1.begin());
			}
			for (int j = 1; j < dropR2.size(); j++) {
				dropR2[j].move(0, 5);
				if (dropR2[j].getPosition().y > 1080 && dropR2[j].getPosition().y < 0)
					dropR2.erase(dropR2.begin());
			}
			for (int j = 1; j < dropR3.size(); j++) {
				dropR3[j].move(0, 5);
				if (dropR3[j].getPosition().y > 1080 && dropR3[j].getPosition().y < 0)
					dropR3.erase(dropR3.begin());
			}
			for (int j = 1; j < dropR4.size(); j++) {
				dropR4[j].move(0, 5);
				if (dropR4[j].getPosition().y > 1080 && dropR4[j].getPosition().y < 0)
					dropR4.erase(dropR4.begin());
			}

			//collision with enemy

			bool kenemy = false;
			for (int i = 1; i < 11; i++)
			{
				for (int j = 0; j < Fire.size(); j++)
				{
					if (EnemiesR4[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR4[i].setPosition(xenemy, -45500);

					}

					if (EnemiesR3[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR3[i].setPosition(xenemy, -45500);
					}
					if (EnemiesR2[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, 500);

						EnemiesR2[i].setPosition(xenemy, -45500);

					}
					if (EnemiesR1[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR1[i].setPosition(xenemy, -45500);
					}
					if (kenemy == true)
					{

						score += 5;
						kenemy = false;
					}
				}
			}

			//Objects Collision
			for (int j = 1; j < dropR1.size(); j++) {
				if (dropR1[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}
			for (int j = 1; j < dropR2.size(); j++) {
				if (dropR2[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}
			for (int j = 1; j < dropR3.size(); j++) {
				if (dropR3[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {

					FrLevel.close();
					Win_Lose(false, b);
				}
			}
			for (int j = 1; j < dropR4.size(); j++) {
				if (dropR4[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					FrLevel.close();
					Win_Lose(false, b);
				}
			}


			//score
			Font Score;
			if (Score.loadFromFile("Data/Fonts/starcraft.ttf") == 0);


			string sscore = to_string(score);
			Text fscore;
			fscore.setFont(Score);
			fscore.setFillColor(Color::White);
			fscore.setString("Score");
			fscore.setCharacterSize(18);
			fscore.setPosition(Vector2f(10, 10));

			Text fsscore;
			fsscore.setFont(Score);
			fsscore.setFillColor(Color::Red);
			fsscore.setString(sscore);
			fsscore.setCharacterSize(16);
			fsscore.setPosition(Vector2f(15, 28));

			Text lsscore;
			lsscore.setFont(Score);
			lsscore.setFillColor(Color::White);
			lsscore.setString("/200");
			lsscore.setCharacterSize(16);
			lsscore.setPosition(Vector2f(40, 28));

			if (200 == score)
			{
				FrLevel.close();
				Win_Lose(true, b);

				score = 0;
			}


			//Drawing
			FrLevel.clear();
			FrLevel.draw(Level0);
			FrLevel.draw(fighter);
			for (int i = 1; i < 11; i++) {
				FrLevel.draw(EnemiesR1[i]);
				FrLevel.draw(EnemiesR2[i]);
				FrLevel.draw(EnemiesR3[i]);
				FrLevel.draw(EnemiesR4[i]);

			}
			for (int i = 0; i < Fire.size(); i++) {
				FrLevel.draw(Fire[i]);
			}
			for (int j = 1; j < dropR1.size(); j++) {
				FrLevel.draw(dropR1[j]);
			}
			for (int j = 1; j < dropR2.size(); j++) {
				FrLevel.draw(dropR2[j]);
			}
			for (int j = 1; j < dropR3.size(); j++) {
				FrLevel.draw(dropR3[j]);
			}
			for (int j = 1; j < dropR4.size(); j++) {
				FrLevel.draw(dropR4[j]);
			}
			FrLevel.draw(fscore);
			FrLevel.draw(fsscore);
			FrLevel.draw(lsscore);
			FrLevel.display();
		}
	}

	//Level 2
	if (a == 2) {

		//Window Setup
		RenderWindow ScLevel(VideoMode(1920, 1080), "Second Level", Style::Fullscreen);
		ScLevel.setFramerateLimit(60);
		ScLevel.setKeyRepeatEnabled(false);

		//Shoottime
		int shoottimer = 0;

		//Drop time
		int droptime = 0;

		//Enemy Move
		float enemymove = 2;
		bool border1 = false, border2 = false;
		float bombmove = 2;

		//Score
		int score = 0;
		int chance = 0;
		int Explosion = 0;

		//Position of rect of chances
		float xchance = 1790;

		//Position of bomb warning
		float xbombWarning = 230;

		//Photo of level 2
		Texture Level2window;

		Level2window.loadFromFile("Data/Texture/Level2Window.png");


		//Background
		RectangleShape Level2;
		Level2.setSize(Vector2f(1920, 1080));
		Level2.setPosition(Vector2f(0, 0));
		Level2.setFillColor(Color::White);
		Level2.setTexture(&Level2window);

		//Bomb image
		Texture Bomb;
		Bomb.loadFromFile("Data/Texture/Boss.png");

		//BombWarningShape
		Texture BombWarning,BombWarning1;
		BombWarning.loadFromFile("Data/Texture/bomb1.png");
		BombWarning1.loadFromFile("Data/Texture/bomb2.png");




		//Boss Position
		float xbomb = 700;
		RectangleShape bomb;
		bomb.setPosition(xbomb, 550);
		bomb.setSize(Vector2f(0, 0));


		//Planes
		Texture fighter1, fighter2, fighter3, fighter4;

		fighter1.loadFromFile("Data/Texture/fighter1.png");

		fighter2.loadFromFile("Data/Texture/fighter2.png");


		fighter3.loadFromFile("Data/Texture/fighter3.png");


		fighter4.loadFromFile("Data/Texture/fighter4.png");



		//sounds
		SoundBuffer  fire;

		fire.loadFromFile("Data/Sounds/shoot1.wav");

		Sound shootsound;
		shootsound.setBuffer(fire);

		//images
		Texture Enemy1, Enemy2;
		Enemy1.loadFromFile("Data/Texture/Enemy.png");

		Enemy2.loadFromFile("Data/Texture/Enemy2.png");


		//weapons
		//1
		Texture Bullet1;
		Bullet1.loadFromFile("Data/Texture/shoot1.png");


		//2
		Texture Bullet2;
		Bullet2.loadFromFile("Data/Texture/shoot2.png");


		//3
		Texture Bullet3;
		Bullet3.loadFromFile("Data/Texture/shoot3.png");

		//4
		Texture Bullet4;
		Bullet4.loadFromFile("Data/Texture/shoot4.png");

		//Enemy Rows
		float xenemy = 450;
		Sprite EnemiesR1[12];
		Sprite EnemiesR2[12];
		Sprite EnemiesR3[12];
		Sprite EnemiesR4[12];
		for (int i = 0; i < 12; i++) {
			//1
			EnemiesR1[i].setTexture(Enemy1);
			EnemiesR1[i].setPosition(xenemy, 50);
			EnemiesR1[i].setScale(0.65, 0.55);
			//2
			EnemiesR2[i].setTexture(Enemy1);
			EnemiesR2[i].setPosition(xenemy, 150);
			EnemiesR2[i].setScale(0.65, 0.55);
			//3
			EnemiesR3[i].setTexture(Enemy2);
			EnemiesR3[i].setPosition(xenemy, 250);
			EnemiesR3[i].setScale(0.65, 0.55);
			//4
			EnemiesR4[i].setTexture(Enemy2);
			EnemiesR4[i].setPosition(xenemy, 350);
			EnemiesR4[i].setScale(0.65, 0.55);
			xenemy = xenemy + 130;
		}

		// Bullets && Weapons
		CircleShape bullet;
		bullet.setRadius(10);
		vector <CircleShape> Fire;
		Fire.push_back(CircleShape(bullet));

		// Objects Shape
		Texture Object;
		Object.loadFromFile("Data/Texture/object1.png");


		CircleShape objectR1, objectR2, objectR3, objectR4;
		//1
		objectR1.setRadius(12.5);
		objectR1.setTexture(&Object);
		vector <CircleShape> dropR1;
		dropR1.push_back(CircleShape(objectR1));
		//2
		objectR2.setRadius(12.5);
		objectR2.setTexture(&Object);
		vector <CircleShape> dropR2;
		dropR2.push_back(CircleShape(objectR2));
		//3
		objectR3.setRadius(12.5);
		objectR3.setTexture(&Object);
		vector <CircleShape> dropR3;
		dropR3.push_back(CircleShape(objectR3));
		//4
		objectR4.setRadius(12.5);
		objectR4.setTexture(&Object);
		vector <CircleShape> dropR4;
		dropR4.push_back(CircleShape(objectR4));


		bool Bright = false, Bleft = false, Bup = false, Bdown = false, space = false;
		Sprite fighter;
		RectangleShape Chances[3];
		RectangleShape bombWarning[4];


		//Set up planes
		int result = PlanesF(true, b);
		if (result == 1) {
			fighter.setTexture(fighter1);
			fighter.setPosition(Xposition, Yposition);


			//Weapon Shape
			bullet.setTexture(&Bullet1);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter1);

		}
		else if (result == 2) {
			fighter.setTexture(fighter2);
			fighter.setPosition(Xposition, Yposition);



			//Weapon Shape
			bullet.setTexture(&Bullet2);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++) {
				Chances[i].setTexture(&fighter2);
			}
		}
		else if (result == 3) {
			fighter.setTexture(fighter3);
			fighter.setPosition(Xposition, Yposition);



			//Weapon Shape
			bullet.setTexture(&Bullet3);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter3);
		}
		else if (result == 4) {
			fighter.setTexture(fighter4);
			fighter.setPosition(Xposition, Yposition);



			//Weapon Shape
			bullet.setTexture(&Bullet4);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter4);
		}
		else if (result == -1) {
			ScLevel.close();
		}
		//chances position
		for (int i = 0; i < 3; i++) {
			Chances[i].setSize(Vector2f(25, 25));
			Chances[i].setPosition(xchance, 10);
			xchance = xchance + 25;
		}

		//BombWarning position
		for (int i = 0; i < 4; i++) {
			bombWarning[i].setSize(Vector2f(25, 25));
			bombWarning[i].setPosition(xbombWarning, 5);
			bombWarning[i].setTexture(&BombWarning);
			xbombWarning = xbombWarning + 25;
		}

		while (ScLevel.isOpen()) {

			Event event2;
			while (ScLevel.pollEvent(event2))
			{
				switch (event2.type)
				{
				case::Event::KeyPressed:
				{
					switch (event2.key.code)
					{
					case Keyboard::Right:
						Bright = true;
						break;

					case Keyboard::Left:
						Bleft = true;
						break;

					case Keyboard::Up:
						Bup = true;
						break;

					case Keyboard::Down:
						Bdown = true;
						break;
					case Keyboard::Space:
						if (shoottimer >= 3) {
							bullet.setPosition(fighter.getPosition().x + 43, fighter.getPosition().y + 15);
							Fire.push_back(CircleShape(bullet));
							shoottimer = 0;
							shootsound.play();
							if (b == 2) {
								shootsound.stop();
							}
						}
						break;
					case::Keyboard::Escape:
						ScLevel.close();
						break;
					}
					break;

				}
				case::Event::KeyReleased:
				{
					switch (event2.key.code)
					{
					case::Keyboard::Right:
						Bright = false;
					case::Keyboard::Left:
						Bleft = false;
					case::Keyboard::Up:
						Bup = false;
					case::Keyboard::Down:
						Bdown = false;
					}
				}
				}

			}
			//Logic
			if (Bright == true) {
				if (Xposition < 1800) {
					fighter.move(10, 0);
					Xposition = Xposition + 10;
				}
			}

			if (Bleft == true) {
				if (Xposition > 5) {
					fighter.move(-10, 0);
					Xposition = Xposition - 10;
				}
			}
			if (Bup == true) {
				if (Yposition > 750) {
					fighter.move(0, -10);
					Yposition = Yposition - 10;
				}
			}
			if (Bdown == true) {
				if (Yposition < 950) {
					fighter.move(0, 10);
					Yposition = Yposition + 10;
				}
			}


			//Shoot Updates
			if (shoottimer < 10) {
				shoottimer++;
			}

			for (int i = 0; i < Fire.size(); i++) {
				Fire[i].move(0, -5);
				if (Fire[i].getPosition().y < 0)
					Fire.erase(Fire.begin() + i);

			}

			if (score == 200) {
				float xenemy = 450;
				for (int i = 0; i < 12; i++) {
					EnemiesR1[i].setPosition(xenemy, 50);
					EnemiesR2[i].setPosition(xenemy, 150);
					EnemiesR3[i].setPosition(xenemy, 250);
					EnemiesR4[i].setPosition(xenemy, 350);

					xenemy = xenemy + 130;
				}
				score = score + 5;
			}
			if (score == 405) {
				float xenemy = 450;
				for (int i = 0; i < 12; i++) {
					EnemiesR1[i].setPosition(xenemy, 50);
					EnemiesR2[i].setPosition(xenemy, 150);
					EnemiesR3[i].setPosition(xenemy, 250);
					EnemiesR4[i].setPosition(xenemy, 350);

					xenemy = xenemy + 130;
				}
				score = score + 5;
			}
			if (score == 610)
			{
				float xenemy = 450;
				for (int i = 0; i < 12; i++) {
					EnemiesR1[i].setPosition(xenemy, 50);
					EnemiesR2[i].setPosition(xenemy, 150);
					EnemiesR3[i].setPosition(xenemy, 250);
					EnemiesR4[i].setPosition(xenemy, 350);

					xenemy = xenemy + 130;
				}
				score = score + 5;

			}

			if (score >= 610 && score < 815) {
				bomb.setSize(Vector2f(200, 200));
				bomb.setTexture(&Bomb);
				bomb.move(bombmove, 0);
				if (bomb.getPosition().x >= 1850) {
					bombmove = -4;
				}
				if (bomb.getPosition().x <= 5) {
					bombmove = 4;
				}
			}

			//MOVE
			if (score >= 0 && score <= 815) {
				for (int i = 0; i < 12; i++) {

					EnemiesR1[i].move(enemymove, 0);
					EnemiesR2[i].move(enemymove, 0);
					EnemiesR3[i].move(enemymove, 0);
					EnemiesR4[i].move(enemymove, 0);


					//To solve The bug problem
					EnemiesR1[0].setPosition(EnemiesR1[11].getPosition().x - 1500, EnemiesR1[11].getPosition().y);
					EnemiesR2[0].setPosition(EnemiesR2[11].getPosition().x - 1500, EnemiesR2[11].getPosition().y);
					EnemiesR3[0].setPosition(EnemiesR3[11].getPosition().x - 1500, EnemiesR3[11].getPosition().y);
					EnemiesR4[0].setPosition(EnemiesR4[11].getPosition().x - 1500, EnemiesR4[11].getPosition().y);


					//Condition to Change the move from right to left
					if (EnemiesR1[11].getPosition().x >= 1900 && EnemiesR2[11].getPosition().x >= 1900 && EnemiesR3[11].getPosition().x >= 1900) {
						border1 = true;
						border2 = false;
					}

					else if (EnemiesR1[0].getPosition().x == -190 && EnemiesR2[0].getPosition().x == -190 && EnemiesR3[0].getPosition().x == -190) {
						border2 = true;
						border1 = false;
					}
					//Conditions To Change the direction of motion
					if (border1 == true)
						enemymove = -2;
					if (border2 == true)
						enemymove = 2;


				}
			}





			//Objects

			//Drop Updates
			if (droptime < 100) {
				droptime++;
			}

			if (droptime >= 100) {
				//RANDOM LOCATION FOR EVERY ROW
				int Random1 = rand() % 10 + 1;
				int Random2 = rand() % 10 + 1;
				int Random3 = rand() % 10 + 1;
				int Random4 = rand() % 10 + 1;

				//POSITIONS OF OBJECTS
				objectR1.setPosition(EnemiesR1[Random1].getPosition().x + 50, EnemiesR1[Random1].getPosition().y + 75);
				objectR2.setPosition(EnemiesR2[Random2].getPosition().x + 50, EnemiesR2[Random2].getPosition().y + 75);
				objectR3.setPosition(EnemiesR3[Random3].getPosition().x + 50, EnemiesR3[Random3].getPosition().y + 75);
				objectR4.setPosition(EnemiesR4[Random4].getPosition().x + 50, EnemiesR4[Random4].getPosition().y + 75);

				//PUSH BACK OF OBJECTS
				dropR1.push_back(CircleShape(objectR1));
				dropR2.push_back(CircleShape(objectR2));
				dropR3.push_back(CircleShape(objectR3));
				dropR4.push_back(CircleShape(objectR4));

				droptime = 0;
			}
			//MOVE OF OBJECTS IN EVERY ROW

			for (int j = 1; j < dropR1.size(); j++) {
				dropR1[j].move(0, 5);
				if (dropR1[j].getPosition().y > 1080 && dropR1[j].getPosition().y < 0)
					dropR1.erase(dropR1.begin());
			}
			for (int j = 1; j < dropR2.size(); j++) {
				dropR2[j].move(0, 5);
				if (dropR2[j].getPosition().y > 1080 && dropR2[j].getPosition().y < 0)
					dropR2.erase(dropR2.begin());
			}
			for (int j = 1; j < dropR3.size(); j++) {
				dropR3[j].move(0, 5);
				if (dropR3[j].getPosition().y > 1080 && dropR3[j].getPosition().y < 0)
					dropR3.erase(dropR3.begin());
			}
			for (int j = 1; j < dropR4.size(); j++) {
				dropR4[j].move(0, 5);
				if (dropR4[j].getPosition().y > 1080 && dropR4[j].getPosition().y < 0)
					dropR4.erase(dropR4.begin());
			}


			//collision with enemy
			bool kenemy = false;
			for (int i = 1; i < 11; i++)
			{
				for (int j = 0; j < Fire.size(); j++)
				{
					if (EnemiesR4[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR4[i].setPosition(xenemy, -45500);
					}

					if (EnemiesR3[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR3[i].setPosition(xenemy, -45500);
					}
					if (EnemiesR2[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, 500);

						EnemiesR2[i].setPosition(xenemy, -45500);

					}
					if (EnemiesR1[i].getGlobalBounds().intersects(Fire[j].getGlobalBounds()) == true)
					{
						kenemy = true;
						Fire[j].setPosition(xenemy, -50);

						EnemiesR1[i].setPosition(xenemy, -45500);
					}
					if (kenemy == true)
					{
						score += 5;

						kenemy = false;
					}
				}
			}

			//Objects Collision
			bool bchances = false;
			for (int j = 1; j < dropR1.size(); j++) {
				if (dropR1[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					dropR1[j].setPosition(100000, 5000000);
					bchances = true;

				}
			}
			for (int j = 1; j < dropR2.size(); j++) {
				if (dropR2[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					dropR2[j].setPosition(100000, 5000000);
					bchances = true;
				}
			}
			for (int j = 1; j < dropR3.size(); j++) {
				if (dropR3[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					dropR3[j].setPosition(100000, 5000000);
					bchances = true;
				}
			}
			for (int j = 1; j < dropR4.size(); j++) {
				if (dropR4[j].getGlobalBounds().intersects(fighter.getGlobalBounds())) {
					dropR4[j].setPosition(100000, 5000000);
					bchances = true;
				}
			}


			if (bchances == true) {
				chance = chance + 1;
				bchances = false;
			}

			if (chance == 1) {
				Chances[2].setSize(Vector2f(0, 0));
			}

			if (chance == 2) {
				Chances[1].setSize(Vector2f(0, 0));
			}

			if (chance == 3) {
				Chances[0].setSize(Vector2f(0, 0));
			}
			if (chance == 3) {
				ScLevel.close();
				Win_Lose(false, b);
			}

			//bomb collision
			bool bombC = false;
			for (int i = 0; i < Fire.size(); i++) {
				if (Fire[i].getGlobalBounds().intersects(bomb.getGlobalBounds()) == true) {
					bombC = true;
					Fire[i].setPosition(100000, -50);
				}

			}
			if (bombC == true) {
				Explosion = Explosion + 1;
				bombC = false;
			}
			if (Explosion == 1) {
				bombWarning[0].setTexture(&BombWarning1);
			}
			if (Explosion == 2) {
				bombWarning[1].setTexture(&BombWarning1);
			}
			if (Explosion == 3) {
				bombWarning[2].setTexture(&BombWarning1);
			}
			if (Explosion == 4 ) {
				ScLevel.close();
				Win_Lose(false, b);
			}

			if (score == 815) {
				ScLevel.close();
				Win_Lose(true, b);
			}


			//score
			Font Score;
			if (Score.loadFromFile("Data/Fonts/starcraft.ttf") == 0);

			//chane
			Font LimitofC;
			LimitofC.loadFromFile("Data/Fonts/starcraft.ttf");


			string sscore = to_string(score);
			Text fscore;
			fscore.setFont(Score);
			fscore.setFillColor(Color::White);
			fscore.setString("Score");
			fscore.setCharacterSize(18);
			fscore.setPosition(Vector2f(10, 10));
			
			Text fsscore;
			fsscore.setFont(Score);
			fsscore.setFillColor(Color::Red);
			fsscore.setString(sscore);
			fsscore.setCharacterSize(16);
			fsscore.setPosition(Vector2f(15, 28));

			Text lsscore;
			lsscore.setFont(Score);
			lsscore.setFillColor(Color::White);
			lsscore.setString("  / 815");
			lsscore.setCharacterSize(16);
			lsscore.setPosition(Vector2f(40, 28));

			Text numofc;
			numofc.setFont(LimitofC);
			numofc.setFillColor(Color::White);
			numofc.setString("Chances:");
			numofc.setCharacterSize(16);
			numofc.setPosition(Vector2f(1690, 10));

			Text Warning;
			Warning.setFont(Score);
			Warning.setFillColor(Color::Red);
			Warning.setString("Explosion: ");
			Warning.setCharacterSize(16);
			Warning.setPosition(Vector2f(115, 7));



			//Drawing
			ScLevel.clear();
			ScLevel.draw(Level2);
			ScLevel.draw(fighter);
			for (int i = 1; i < 11; i++) {
				ScLevel.draw(EnemiesR1[i]);
				ScLevel.draw(EnemiesR2[i]);
				ScLevel.draw(EnemiesR3[i]);
				ScLevel.draw(EnemiesR4[i]);
			}
			ScLevel.draw(bomb);
			for (int i = 0; i < Fire.size(); i++) {
				ScLevel.draw(Fire[i]);
			}
			for (int j = 1; j < dropR1.size(); j++) {
				ScLevel.draw(dropR1[j]);
			}
			for (int j = 1; j < dropR2.size(); j++) {
				ScLevel.draw(dropR2[j]);
			}
			for (int j = 1; j < dropR3.size(); j++) {
				ScLevel.draw(dropR3[j]);
			}
			for (int j = 1; j < dropR4.size(); j++) {
				ScLevel.draw(dropR4[j]);
			}
			for (int i = 0; i < 3; i++) {
				ScLevel.draw(Chances[i]);
			}
			for (int i = 0; i < 4; i++) {
				ScLevel.draw(bombWarning[i]);
			}
		
			ScLevel.draw(fscore);
			ScLevel.draw(fsscore);
			ScLevel.draw(lsscore);
			ScLevel.draw(numofc);
			ScLevel.draw(Warning);
			ScLevel.display();
		}

	}

	//Level 3
	if (a == 3) {
		RenderWindow ThLevel(VideoMode(1920, 1080), "Third Level", Style::Fullscreen);
		ThLevel.setFramerateLimit(60);
		ThLevel.setKeyRepeatEnabled(false);

		//Shoottime
		int shoottimer = 0;

		//Drop time
		int droptime = 0;

		//Enemy Move
		float XmoveBoss = -2;
		float YmoveBoss = -2;

		//Score
		int score = 0;
		int chance = 0;

		//Position of rect of chances
		float xchance = 1790;


		//Planes
		Texture fighter1, fighter2, fighter3, fighter4, Prisoner1, Prisoner2, Prisoner3, Prisoner4, Level3window;

		fighter1.loadFromFile("Data/Texture/fighter1.png");
		Prisoner1.loadFromFile("Data/Texture/Prison1.png");

		fighter2.loadFromFile("Data/Texture/fighter2.png");
		Prisoner2.loadFromFile("Data/Texture/Prison2.png");


		fighter3.loadFromFile("Data/Texture/fighter3.png");
		Prisoner3.loadFromFile("Data/Texture/Prison3.png");


		fighter4.loadFromFile("Data/Texture/fighter4.png");
		Prisoner4.loadFromFile("Data/Texture/Prison4.png");


		Level3window.loadFromFile("Data/Texture/Level3Window.png");

		//planes after set free
		Texture fighter10, fighter12, fighter13, fighter14;

		fighter10.loadFromFile("Data/Texture/fighter10.png");

		fighter12.loadFromFile("Data/Texture/fighter8.png");

		fighter13.loadFromFile("Data/Texture/fighter7.png");

		fighter14.loadFromFile("Data/Texture/fighter9.png");

		//boss shapes
		Texture Boss1, Boss2, Boss3, Boss4;
		Boss1.loadFromFile("Data/Texture/BossShape1.png");

		Boss2.loadFromFile("Data/Texture/BossShape2.png");

		Boss3.loadFromFile("Data/Texture/BossShape3.png");

		Boss4.loadFromFile("Data/Texture/BossShape4.png");



		//Background
		RectangleShape Level3;
		Level3.setSize(Vector2f(1920, 1080));
		Level3.setPosition(Vector2f(0, 0));
		Level3.setFillColor(Color::White);
		Level3.setTexture(&Level3window);

		//images
		Texture Boss;
		Boss.loadFromFile("Data/Texture/Boss.png");


		//weapons
		//1
		Texture Bullet1;
		Bullet1.loadFromFile("Data/Texture/shoot1.png");


		//2
		Texture Bullet2;
		Bullet2.loadFromFile("Data/Texture/shoot2.png");


		//3
		Texture Bullet3;
		Bullet3.loadFromFile("Data/Texture/shoot3.png");

		//4
		Texture Bullet4;
		Bullet4.loadFromFile("Data/Texture/shoot4.png");


		//Boss Position
		float xboss = 700;
		CircleShape boss;
		boss.setRadius(200);
		boss.setTexture(&Boss);
		boss.setPosition(xboss, 150);
		boss.setOrigin(200, 200);



		// Bullets && Weapons
		CircleShape bullet;
		bullet.setRadius(10);
		vector <CircleShape> Fire;
		Fire.push_back(CircleShape(bullet));

		// Objects Shape
		Texture Object;
		Object.loadFromFile("Data/Texture/object1.png");


		CircleShape objects;
		objects.setRadius(12.5);
		objects.setTexture(&Object);
		vector <CircleShape> drop;
		drop.push_back(CircleShape(objects)); 


		bool Bright = false, Bleft = false, Bup = false, Bdown = false;
		Sprite fighter;
		CircleShape Pr1, Pr2, Pr3;
		RectangleShape Chances[3];

		//Set up planes
		int result = PlanesF(true, b);
		if (result == 1) {
			fighter.setTexture(fighter1);
			fighter.setPosition(Xposition, Yposition);

			//fighters cage
			Pr1.setTexture(&Prisoner2);
			Pr1.setRadius(50);
			Pr1.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr1.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr2.setTexture(&Prisoner3);
			Pr2.setRadius(50);
			Pr2.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr2.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr3.setTexture(&Prisoner4);
			Pr3.setRadius(50);
			Pr3.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr3.setPosition(boss.getPosition().x, boss.getPosition().y);


			//Weapon Shape
			bullet.setTexture(&Bullet1);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter1);
		}
		else if (result == 2) {
			fighter.setTexture(fighter2);
			fighter.setPosition(Xposition, Yposition);

			//fighters cage
			Pr1.setTexture(&Prisoner1);
			Pr1.setRadius(50);
			Pr1.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr1.setPosition(boss.getPosition().x, boss.getPosition().y);


			Pr2.setTexture(&Prisoner3);
			Pr2.setRadius(50);
			Pr2.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr2.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr3.setTexture(&Prisoner4);
			Pr3.setRadius(50);
			Pr3.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr3.setPosition(boss.getPosition().x, boss.getPosition().y);

			//Weapon Shape
			bullet.setTexture(&Bullet2);
			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter2);
		}
		else if (result == 3) {
			fighter.setTexture(fighter3);
			fighter.setPosition(Xposition, Yposition);

			//fighters cage
			Pr1.setTexture(&Prisoner1);
			Pr1.setRadius(50);
			Pr1.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr1.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr2.setTexture(&Prisoner2);
			Pr2.setRadius(50);
			Pr2.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr2.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr3.setTexture(&Prisoner4);
			Pr3.setRadius(50);
			Pr3.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr3.setPosition(boss.getPosition().x, boss.getPosition().y);

			//Weapon Shape
			bullet.setTexture(&Bullet3);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter3);
		}
		else if (result == 4) {
			fighter.setTexture(fighter4);
			fighter.setPosition(Xposition, Yposition);

			//fighters cage
			Pr1.setTexture(&Prisoner1);
			Pr1.setRadius(50);
			Pr1.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr1.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr2.setTexture(&Prisoner2);
			Pr2.setRadius(50);
			Pr2.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr2.setPosition(boss.getPosition().x, boss.getPosition().y);

			Pr3.setTexture(&Prisoner3);
			Pr3.setRadius(50);
			Pr3.setOrigin(boss.getPosition().x - 400, boss.getPosition().y + 50);
			Pr3.setPosition(boss.getPosition().x, boss.getPosition().y);

			//Weapon Shape
			bullet.setTexture(&Bullet4);

			//Shape Of chances rectangle
			for (int i = 0; i < 3; i++)
				Chances[i].setTexture(&fighter4);
		}
		else if (result == -1) {
			ThLevel.close();
		}

		//chances position
		for (int i = 0; i < 3; i++) {
			Chances[i].setSize(Vector2f(25, 25));
			Chances[i].setPosition(xchance, 10);
			xchance = xchance + 25;
		}

		//sounds
		SoundBuffer  fire;

		fire.loadFromFile("Data/Sounds/shoot1.wav");

		Sound shootsound;
		shootsound.setBuffer(fire);

		while (ThLevel.isOpen()) {

			Event event3;
			while (ThLevel.pollEvent(event3))
			{
				switch (event3.type)
				{
				case::Event::KeyPressed:
				{
					switch (event3.key.code)
					{
					case Keyboard::Right:
						Bright = true;
						break;

					case Keyboard::Left:
						Bleft = true;
						break;

					case Keyboard::Up:
						Bup = true;
						break;

					case Keyboard::Down:
						Bdown = true;
						break;
					case Keyboard::Space:
						if (shoottimer >= 3) {
							bullet.setPosition(fighter.getPosition().x + 43, fighter.getPosition().y + 15);
							Fire.push_back(CircleShape(bullet));
							shoottimer = 0;
							shootsound.play();
							if (b == 2) {
								shootsound.stop();
							}
						}
						break;
					case::Keyboard::Escape:
						ThLevel.close();
						break;
					}
					break;

				}
				case::Event::KeyReleased:
				{
					switch (event3.key.code)
					{
					case::Keyboard::Right:
						Bright = false;
					case::Keyboard::Left:
						Bleft = false;
					case::Keyboard::Up:
						Bup = false;
					case::Keyboard::Down:
						Bdown = false;
					}
				}
				}

			}
			//Logic
			if (Bright == true) {
				if (Xposition < 1800) {
					fighter.move(10, 0);
					Xposition = Xposition + 10;
				}
			}

			if (Bleft == true) {
				if (Xposition > 5) {
					fighter.move(-10, 0);
					Xposition = Xposition - 10;
				}
			}
			if (Bup == true) {
				if (Yposition > 750) {
					fighter.move(0, -10);
					Yposition = Yposition - 10;
				}
			}
			if (Bdown == true) {
				if (Yposition < 950) {
					fighter.move(0, 10);
					Yposition = Yposition + 10;
				}
			}

			//Shoots Update
			if (shoottimer < 10) {
				shoottimer++;
			}

			if (Xposition <= 5) {
				fighter.setPosition(5, Yposition);
			}

			if (Xposition == 1900) {
				fighter.setPosition(1900, Yposition);
			}

			if (Yposition <= 750) {
				fighter.setPosition(Xposition, 750);
			}

			if (Yposition >= 950) {
				fighter.setPosition(Xposition, 950);
			}
			//VideoMode(1920, 1080)

			if (boss.getPosition().y < 150) {
				YmoveBoss = YmoveBoss * -1;
			}
			if (boss.getPosition().x > 1500) {
				XmoveBoss = XmoveBoss * -1;
			}
			if (boss.getPosition().x < 250) {
				XmoveBoss = XmoveBoss * -1;
			}
			if (boss.getPosition().y > 700) {
				YmoveBoss = YmoveBoss * -1;
			}

			// boss move
			boss.move(XmoveBoss, YmoveBoss); //Down
			boss.rotate(3);

			Pr1.move(XmoveBoss, YmoveBoss); //Right
			Pr1.rotate(2.1);

			Pr2.move(XmoveBoss, YmoveBoss); //Left
			Pr2.rotate(2.2);

			Pr3.move(XmoveBoss, YmoveBoss); //Top
			Pr3.rotate(2);

			for (int i = 0; i < Fire.size(); i++) {
				Fire[i].move(0, -5);
				if (Fire[i].getPosition().y < 0)
					Fire.erase(Fire.begin() + i);

			}
			//Drop Updates
			if (droptime < 100) {
				droptime++;
			}

			if (droptime >= 50) {


				//POSITIONS OF OBJECTS
				objects.setPosition(boss.getPosition().x + 150, boss.getPosition().y + 100);

				//PUSH BACK OF OBJECTS
				drop.push_back(CircleShape(objects));


				droptime = 0;
			}
			//MOVE OF OBJECTS IN EVERY ROW
			for (int j = 1; j < drop.size(); j++) {
				drop[j].move(0, 5);
				if (drop[j].getPosition().y > 1080 && drop[j].getPosition().y < 0)
					drop.erase(drop.begin());
			}

			//Collision of objects and boss
			bool bchances = false;
			if (fighter.getGlobalBounds().intersects(boss.getGlobalBounds()) == true) {
				ThLevel.close();
				Win_Lose(false, b);

			}
			for (int i = 1; i < drop.size(); i++) {
				if (drop[i].getGlobalBounds().intersects(fighter.getGlobalBounds()) == true) {
					bchances = true;
					drop[i].setPosition(100000, -124550);
				}
			}
			if (bchances == true) {
				chance = chance + 1;
				bchances = false;
			}

			if (chance == 1) {
				Chances[2].setSize(Vector2f(0, 0));
			}

			if (chance == 2) {
				Chances[1].setSize(Vector2f(0, 0));
			}

			if (chance == 3) {
				Chances[0].setSize(Vector2f(0, 0));
			}
			if (chance == 3) {
				ThLevel.close();
				Win_Lose(false, b);
			}

			//collision of bullets
			bool Killboss = false;
			for (int i = 0; i < Fire.size(); i++) {
				if (Fire[i].getGlobalBounds().intersects(boss.getGlobalBounds())) {
					Killboss = true;
					Fire[i].setPosition(454121, -45454218);
				}
			}
			if (Killboss == true) {
				score = score + 5;
				Killboss == false;
			}

			//animation of that level
			if (score == 500) {
				if (result == 1) {
					Pr1.setRadius(50);
					Pr1.setTexture(&fighter12);
				}
				if (result == 2) {
					Pr1.setRadius(50);
					Pr1.setTexture(&fighter10);
				}
				if (result == 3) {
					Pr1.setRadius(50);
					Pr1.setTexture(&fighter10);
				}
				if (result == 4) {
					Pr1.setRadius(50);
					Pr1.setTexture(&fighter10);
				}
			}

			if (score == 1000) {
				if (result == 1) {
					Pr2.setRadius(50);
					Pr2.setTexture(&fighter13);
				}
				if (result == 2) {
					Pr2.setRadius(50);
					Pr2.setTexture(&fighter13);
				}
				if (result == 3) {
					Pr2.setRadius(50);
					Pr2.setTexture(&fighter12);
				}
				if (result == 4) {
					Pr2.setRadius(50);
					Pr2.setTexture(&fighter12);
				}
			}
			if (score == 2000) {
				if (result == 1) {
					Pr3.setRadius(50);
					Pr3.setTexture(&fighter14);
				}
				if (result == 2) {
					Pr3.setRadius(50);
					Pr3.setTexture(&fighter14);
				}
				if (result == 3) {
					Pr3.setRadius(50);
					Pr3.setTexture(&fighter14);
				}
				if (result == 4) {
					Pr3.setRadius(50);
					Pr3.setTexture(&fighter13);
				}
			}

			//move
			if (score >= 500 && score < 3000) {
				Pr1.move(0, -5);
			}
			//move
			if (score >= 1000 && score < 3000) {
				Pr2.move(0, -5);
			}

			if (score >= 2000 && score < 3000) {
				Pr3.move(0, -5);
			}


			//boss cahnging color
			if (score >= 200 && score <= 400) {
				boss.setTexture(&Boss1);
			}

			if (score >= 410 && score <= 500) {
				boss.setTexture(&Boss);
			}

			if (score > 500 && score <= 700) {
				boss.setTexture(&Boss2);
			}

			if (score > 700 && score <= 1400) {
				boss.setTexture(&Boss3);
			}

			if (score > 1400 && score <= 2200) {
				boss.setTexture(&Boss4);
			}

			if (score > 2200 && score <= 3000) {
				boss.setTexture(&Boss);
			}

			//condition of win
			if (score == 3000) {
				ThLevel.close();
				Win_Lose(true, b);
			}



			//score
			Font Score;
			if (Score.loadFromFile("Data/Fonts/starcraft.ttf") == 0);
			//chane
			Font LimitofC;
			LimitofC.loadFromFile("Data/Fonts/starcraft.ttf");


			string sscore = to_string(score);
			Text fscore;
			fscore.setFont(Score);
			fscore.setFillColor(Color::White);
			fscore.setString("Score");
			fscore.setCharacterSize(18);
			fscore.setPosition(Vector2f(10, 10));

			Text fsscore;
			fsscore.setFont(Score);
			fsscore.setFillColor(Color::Green);
			fsscore.setString(sscore);
			fsscore.setCharacterSize(16);
			fsscore.setPosition(Vector2f(15, 28));

			Text lsscore;
			lsscore.setFont(Score);
			lsscore.setFillColor(Color::White);
			lsscore.setString("  /  3000");
			lsscore.setCharacterSize(16);
			lsscore.setPosition(Vector2f(40, 28));

			Text numofc;
			numofc.setFont(LimitofC);
			numofc.setFillColor(Color::White);
			numofc.setString("Chances:");
			numofc.setCharacterSize(16);
			numofc.setPosition(Vector2f(1690, 10));


			ThLevel.clear();
			ThLevel.draw(Level3);
			for (int i = 1; i < drop.size(); i++) {
				ThLevel.draw(drop[i]);
			}
			for (int i = 0; i < 3; i++) {
				ThLevel.draw(Chances[i]);
			}
			ThLevel.draw(fighter);
			ThLevel.draw(boss);
			ThLevel.draw(Pr1);
			ThLevel.draw(Pr2);
			ThLevel.draw(Pr3);
			for (int i = 0; i < Fire.size(); i++) {
				ThLevel.draw(Fire[i]);
			}
			ThLevel.draw(fscore);
			ThLevel.draw(fsscore);
			ThLevel.draw(lsscore);
			ThLevel.draw(numofc);
			ThLevel.display();
		}



	}
}


void Win_Lose(bool a, int b) {

	if (a == false) {

		RenderWindow window(VideoMode(800, 600), "You Lose!");
		window.setFramerateLimit(60);
		window.setKeyRepeatEnabled(false);


		Texture YouLose;
		YouLose.loadFromFile("Data/Texture/YouLoseWindow.png");


		RectangleShape LoseWindow;
		LoseWindow.setSize(Vector2f(800, 600));
		LoseWindow.setPosition(Vector2f(0, 0));
		LoseWindow.setFillColor(Color::White);
		LoseWindow.setTexture(&YouLose);

		//sounds
		SoundBuffer die;

		die.loadFromFile("Data/Sounds/die.wav");

		Sound diesound;
		diesound.setBuffer(die);
		diesound.play();
		if (b == 2) {
			diesound.stop();
		}

		while (window.isOpen()) {

			Event event;
			while (window.pollEvent(event))
			{

				//logics
				switch (event.type)
				{
				case::Event::KeyPressed:
				{
					switch (event.key.code)
					{
					case::Keyboard::Escape:
						window.close();
						break;
					}
				}
				break;
				case::Event::Closed:
					window.close();
					break;
				}
				break;
			}
			window.clear();
			window.draw(LoseWindow);
			window.display();
		}
	}
	if (a == true) {
		RenderWindow window(VideoMode(800, 600), "You Win!");
		window.setFramerateLimit(60);
		window.setKeyRepeatEnabled(false);

		Texture YouWin;
		YouWin.loadFromFile("Data/Texture/YouWinWindow.png");


		RectangleShape WinWindow;
		WinWindow.setSize(Vector2f(800, 600));
		WinWindow.setPosition(Vector2f(0, 0));
		WinWindow.setFillColor(Color::White);
		WinWindow.setTexture(&YouWin);

		//sounds
		SoundBuffer live;

		live.loadFromFile("Data/Sounds/win.wav");

		Sound diesound;
		diesound.setBuffer(live);
		diesound.play();
		if (b == 2) {
			diesound.stop();
		}

		while (window.isOpen()) {

			Event event;
			while (window.pollEvent(event))
			{

				//logics
				switch (event.type)
				{
				case::Event::KeyPressed:
				{
					switch (event.key.code)
					{
					case::Keyboard::Escape:
						window.close();
						break;
					}
				}
				break;
				case::Event::Closed:
					window.close();
					break;
				}
				break;
			}
			window.clear();
			window.draw(WinWindow);
			window.display();
		}
	}

}
