#include "Node.h"



Node::Node(StateStruct::State state, Node* parent, int cost) :
	mState(state),
	mParent(parent),
	mCost(cost)
{
}


Node::~Node()
{
}

int Node::cost() {
	return mCost;
}

int Node::heuristic()
{
	int fieldSize = mState.size() * mState.size();

	// Search for targetValue and calc manhattan distance from target position
	int targetValue = 1;
	bool foundTarget = false;
	int totalCost = 0;

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
					int manhDis = std::abs(targetPosX - actualPosX) + std::abs(targetPosY - actualPosY);
					totalCost += manhDis;
					//std::cout << "TargetX: " << targetPosX << " actualX: " << actualPosX << std::endl;
					//std::cout << "TargetY: " << targetPosY << " actualY: " << actualPosY << std::endl;
					std::cout << "Calculated cost for value " << targetValue << ": " << manhDis << std::endl << std::endl;
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

	return totalCost;
}

