#include "Node.h"



Node::Node(State state) :
	mState(state)
{
	heuristic(0);
}


Node::~Node()
{
}

int Node::heuristic(int cost)
{
	int fieldSize = mState.size() * mState.size();
	int targetValue = 1;
	bool foundTarget = false;
	// Manhattan distance
	while (targetValue < fieldSize)
	{
		int targetPosX = (targetValue - 1) / (int)mState.size();
		int targetPosY = (targetValue - 1) % (int)mState.size();
		int actualPosX;
		int actualPosY;
		for (int i = 0; i < mState.size(); i++)
		{
			for (int j = 0; j < mState.size(); j++)
			{
				if (mState[i][j] == targetValue)
				{
					actualPosX = i;
					actualPosY = j;
					int calcedCost = std::abs(targetPosX - actualPosX) + std::abs(targetPosY - actualPosY);
					//std::cout << "TargetX: " << targetPosX << " actualX: " << actualPosX << std::endl;
					//std::cout << "TargetY: " << targetPosY << " actualY: " << actualPosY << std::endl;
					std::cout << "Calculated cost for value " << targetValue << ": " << calcedCost << std::endl << std::endl;
					targetValue++;
					foundTarget = true;
					break;
				}
			}
			if (foundTarget)
				break;
		}
		foundTarget = false;
	}

	return cost;
}

