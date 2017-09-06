#include "Node.h"



Node::Node(StateStruct::State state, Node* parent, int cost) :
	mState(state),
	mParent(parent),
	pathCost(cost)
{
}


Node::~Node()
{
}

void Node::expandChildren()
{
	Map map;
	// Iterate through the four possible directions
	for (int i = 0; i < 4; i++)
	{
		// If the move is valid, add it to the child nodes

		// IS MOVE VALID=?=???
		std::cout << "Move to be made: " << static_cast<Map::direction>(i) << std::endl;
		StateStruct::State newState = map.move(static_cast<Map::direction>(i), mState);
		
		std::cout << "New State: \n";
		Map::printMap(newState);

		if (!StateStruct::compare(newState, mState))
		{
			std::cout << "Added child to neighbours" << std::endl;
			mChildren.push_back(new Node(newState, this, pathCost));
		}
	}

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
					//std::cout << "Calculated cost for value " << targetValue << ": " << manhDis << std::endl << std::endl;
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


