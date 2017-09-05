#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include <iostream>
#include <time.h>
#include <chrono>

class Map
{
public:
	typedef std::vector<std::vector<int>> State;
	enum direction { up, down, left, right};
	Map();
	~Map();

	void initialize(int fieldSize);
	void printMap();
	void shuffleMap();
	void move(direction dir);
	void locateSpace(int & iRow, int & iCol);
	void restart();

	State getStartState();


private:
	int correctPercentage();

	bool mShuffling = false;

	// Default arrays
	State mField3x3 = {{{ 1, 2, 3 },
						{ 4, 5, 6 },
						{ 7, 8, 0 }}};

	State mField4x4 = {{{ 1,  2,  3,  4  },
						{ 5,  6,  7,  8  },
						{ 9,  10, 11, 12 },
						{ 13, 14, 15, 0  }}};

	State mPlayingField;

};

