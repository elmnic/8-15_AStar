#include "Map.h"


Map::Map()
{
}


Map::~Map()
{
}

void Map::initialize(int fieldSize)
{
	mStartState.clear();

	mStartState.resize(fieldSize, std::vector<int>(fieldSize, 0));

	int blankTile = fieldSize * fieldSize;
	int fieldValue = 0;

	/* Fill the matrix with 1, 2, 3, ... depending on fieldSize
							3, 4, 5, ...
							6, 7, 0, ...
	*/

	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j < fieldSize; j++)
		{
			if (blankTile != (i + 1) * (j + 1))
				mStartState[i][j] = ++fieldValue;
		}
	}
	mCurrentState = mStartState;
}

void Map::restart()
{
	initialize(mCurrentState.size());
}

StateStruct::State Map::getGoalState()
{
	return mStartState;
}

StateStruct::State Map::getCurrentState()
{
	return mCurrentState;
}

void Map::updateCurrentState(StateStruct::State newState)
{
	if (newState != StateStruct::State(NULL))
		mCurrentState = newState;
}

// Usch
int Map::correctPercentage()
{
	int correctTiles = 0;

	if (mCurrentState.size() == 3)
	{
		for (int row = 0; row < mCurrentState.size(); row++)
		{
			for (int col = 0; col < mCurrentState[0].size(); col++)
			{
				if (mCurrentState[row][col] == mField3x3[row][col])
				{
					correctTiles++;
				}
			}
		}
	}
	else if (mCurrentState.size() == 4)
	{
		for (int row = 0; row < mCurrentState.size(); row++)
		{
			for (int col = 0; col < mCurrentState[0].size(); col++)
			{
				if (mCurrentState[row][col] == mField4x4[row][col])
				{
					correctTiles++;
				}
			}
		}
	}

	int percentage = (double)correctTiles / (double)(mCurrentState.size() * mCurrentState.size()) * 100;
	std::cout << percentage << "% correct" << std::endl;
	return percentage;
}

void Map::printMap()
{
	for (int row = 0; row < mCurrentState.size(); row++)
	{
		for (int col = 0; col < mCurrentState[0].size(); col++)
		{
			std::cout << mCurrentState[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Map::shuffleMap()
{
	mShuffling = true;
	int seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() / 100;
	srand(seed);
	StateStruct::State state;
	for (int i = 0; i < 50; i++)
	{
		int randomVal = rand();
		switch (randomVal % 4)
		{
		case 0:
			updateCurrentState(move(Map::up));
			break;
		case 1:
			updateCurrentState(move(Map::down));
			break;
		case 2:
			updateCurrentState(move(Map::left));
			break;
		case 3:
			updateCurrentState(move(Map::right));
			break;
		default:
			break;
		}
	}

	mShuffling = false;
}

StateStruct::State Map::move(direction dir)
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

	// If tile is on the map
	if (tileCol >= 0 && tileCol < mCurrentState.size() &&
		tileRow >= 0 && tileRow < mCurrentState.size())
	{
		StateStruct::State returnState;
		returnState = mCurrentState;

		// Move the tile into the empty block
		returnState[spaceRow][spaceCol] = returnState[tileRow][tileCol];
		returnState[tileRow][tileCol] = 0;
		return returnState;
	}

	return StateStruct::State(NULL);


	//if (!mShuffling)
	//	correctPercentage();

}

void Map::locateSpace(int & iRow, int & iCol)
{

	for (int row = 0; row < mCurrentState.size(); row++)
	{
		for (int col = 0; col < mCurrentState[0].size(); col++)
		{
			if (mCurrentState[row][col] == 0)
			{
				iRow = row;
				iCol = col;
			}
		}
	}

	//std::cout << "Space is at: " << iRow << ", " << iCol << std::endl;

}
