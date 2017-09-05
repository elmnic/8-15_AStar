#include "Game.h"



Game::Game() :
	mWindow()
{
}

Game::~Game()
{
}

void Game::run()
{
	mWindow.create(sf::VideoMode(900, 900), "8/15", sf::Style::Close);
	mWindow.setVerticalSyncEnabled(true);

	Map map;
	Solver solver;
	//map.initialize(4);

	// Main loop
	while (mWindow.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		// Events
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mWindow.close();
				break;
			case sf::Event::KeyPressed:

				if (event.key.code > 26 && event.key.code < 36)
					map.initialize(event.key.code - 26);

				if (event.key.code == sf::Keyboard::R)
					map.restart();
				if (event.key.code == sf::Keyboard::T)
					map.shuffleMap();

				if (event.key.code == sf::Keyboard::W)
					map.move(Map::up);
				if (event.key.code == sf::Keyboard::S)
					map.move(Map::down);
				if (event.key.code == sf::Keyboard::A)
					map.move(Map::left);
				if (event.key.code == sf::Keyboard::D)
					map.move(Map::right);
				
				if (event.key.code == sf::Keyboard::Space)
					solver.h(map.getStartState());

				map.printMap();
			case sf::Event::MouseButtonPressed:

				break;
			}

		}

		render();

	}
}

void Game::render()
{
	mWindow.clear();

	mWindow.display();
}