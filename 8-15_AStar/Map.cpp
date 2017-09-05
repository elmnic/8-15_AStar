#include "Map.h"


Map::Map()
{
}


Map::~Map()
{
}

void Map::initialize(int fieldSize)
{
	mPlayingField.clear();

	mPlayingField.resize(fieldSize, std::vector<int>(fieldSize, 0));

	int blankTile = fieldSize * fieldSize;
	int fieldValue = 0;

	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
		{
			if (blankTile != (i + 1) * (j + 1))
				mPlayingField[i][j] = ++fieldValue;
		}
	}
}

void Map::restart()
{
	initialize(mPlayingField.size());
}

Map::State Map::getStartState()
{
	return mPlayingField;
}

int Map::correctPercentage()
{
	int correctTiles = 0;

	if (mPlayingField.size() == 3)
	{
		for (int row = 0; row < mPlayingField.size(); row++)
		{
			for (int col = 0; col < mPlayingField[0].size(); col++)
			{
				if (mPlayingField[row][col] == mField3x3[row][col])
				{
					correctTiles++;
				}
			}
		}
	}
	else if (mPlayingField.size() == 4)
	{
		for (int row = 0; row < mPlayingField.size(); row++)
		{
			for (int col = 0; col < mPlayingField[0].size(); col++)
			{
				if (mPlayingField[row][col] == mField4x4[row][col])
				{
					correctTiles++;
				}
			}
		}
	}

	int percentage = (double)correctTiles / (double)(mPlayingField.size() * mPlayingField.size()) * 100;
	std::cout << percentage << "% correct" << std::endl;
	return percentage;
}

void Map::printMap()
{
	for (int row = 0; row < mPlayingField.size(); row++)
	{
		for (int col = 0; col < mPlayingField[0].size(); col++)
		{
			std::cout << mPlayingField[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Map::shuffleMap()
{
	mShuffling = true;
	for (int i = 0; i < 50; i++)
	{

		int seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
		srand(seed);
		switch (seed % 4)
		{
		case 0:
			move(Map::up);
			break;
		case 1:
			move(Map::down);
			break;
		case 2:
			move(Map::left);
			break;
		case 3:
			move(Map::right);
			break;
		default:
			break;
		}
	}
	mShuffling = false;
}

void Map::move(direction dir)
{
	int spaceRow, spaceCol;
	locateSpace(spaceRow, spaceCol);
	int tileRow = spaceRow;
	int tileCol = spaceCol;
	// Determine which tile is to be moved 
	switch (dir)
	{
	case Map::up:
		tileRow = tileRow + 1;
		break;
	case Map::down:
		tileRow = tileRow - 1;
		break;
	case Map::left:
		tileCol = tileCol + 1;
		break;
	case Map::right:
		tileCol = tileCol - 1;
		break;
	default:
		break;
	}

	if (tileCol >= 0 && tileCol < mPlayingField.size() &&
		tileRow >= 0 && tileRow < mPlayingField[0].size())
	{
		// Moves the tile into the empty block
		mPlayingField[spaceRow][spaceCol] = mPlayingField[tileRow][tileCol];
		mPlayingField[tileRow][tileCol] = 0;
	}


	if (!mShuffling)
		correctPercentage();

}

void Map::locateSpace(int & iRow, int & iCol)
{

	for (int row = 0; row < mPlayingField.size(); row++)
	{
		for (int col = 0; col < mPlayingField[0].size(); col++)
		{
			if (mPlayingField[row][col] == 0)
			{
				iRow = row;
				iCol = col;
			}
		}
	}

	//std::cout << "Space is at: " << iRow << ", " << iCol << std::endl;

}
