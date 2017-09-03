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
	enum direction { up, down, left, right};
	Map();
	~Map();

	void initialize(int fieldSize);
	void printMap();
	void shuffleMap();
	void move(direction dir);
	void locateSpace(int & iRow, int & iCol);
	void restart();


private:
	int correctPerc();

	bool mShuffling = false;

	// Default arrays
	std::vector<std::vector<int>> mField3x3 = {{{ 1, 2, 3 },
												{ 4, 5, 6 },
												{ 7, 8, 0 }}};

	std::vector<std::vector<int>> mField4x4 = {{{ 1,  2,  3,  4  },
												{ 5,  6,  7,  8  },
												{ 9,  10, 11, 12 },
												{ 13, 14, 15, 0  }}};

	std::vector<std::vector<int>> mPlayingField;

};

