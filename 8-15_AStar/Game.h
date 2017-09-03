#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Map.h"

class Game
{
public:
	Game();
	~Game();

	// Starting point
	void run();


private:
	
	
	void render();


	sf::RenderWindow mWindow;
};

